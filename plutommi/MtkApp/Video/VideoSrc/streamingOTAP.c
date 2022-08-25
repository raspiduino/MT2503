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
 *   StreamingOTAP.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   RTSP OTAP for video streaming profiles.
 *
 * Author:
 * -------
 * -------
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 * $Log$
 *
 * 12 25 2012 sushil.sagar
 * removed!
 * pluto slim check in.
 *
 * 05 14 2012 sushil.sagar
 * removed!
 * Parse Ip adrress and if found invalid don't use it.
 *
 * 04 18 2012 qiang.zhang
 * removed!
 * .
 *
 * 01 18 2012 qiang.zhang
 * removed!
 * .
 *
 * 12 14 2011 qiang.zhang
 * removed!
 * .
 *
 * 12 08 2011 qiang.zhang
 * removed!
 * .
 *
 * 08 31 2011 qiang.zhang
 * removed!
 * .
 *
 * 08 30 2011 qiang.zhang
 * removed!
 * .
 *
 * 08 12 2011 qiang.zhang
 * removed!
 * .
 *
 * 07 28 2011 qiang.zhang
 * removed!
 * .
 *
 * 05 26 2011 qiang.zhang
 * removed!
 * .
 *
 * 05 03 2011 qiang.zhang
 * removed!
 * .
 *
 * 04 13 2011 qiang.zhang
 * removed!
 * .
 *
 * 03 01 2011 qiang.zhang
 * removed!
 * .
 *
 * 02 22 2011 qiang.zhang
 * removed!
 * .
 *
 * 12 23 2010 qiang.zhang
 * removed!
 * .
 *
 * 12 14 2010 qiang.zhang
 * removed!
 * .
 *
 * 11 10 2010 qiang.zhang
 * removed!
 * .
 *
 * 11 04 2010 qiang.zhang
 * removed!
 * .
 *
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_STREAMING_OTAP__

#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"
#ifdef __MMI_CCA_SUPPORT__
#include "CentralConfigAgentGProt.h"
#include "mmi_rp_app_cca_def.h"
#endif
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_streaming_def.h"

#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "wgui_categories_list.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "kal_general_types.h"
#include "DataAccountGProt.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "kal_public_api.h"
#include "MediaPlayerGProt.h"
#include "wgui_categories_text_viewer.h"
#include "Unicodexdcl.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "CustDataRes.h"
#include "cbm_api.h"
#include "cbm_consts.h"
#include "gui_fixed_menuitems.h"

#include "mmi_frm_utility_gprot.h"

#include "StreamingOTAP.h"

#include "CommonScreens.h"
#include "Conversions.h"

#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#endif 

#include "dtcntsrvgprot.h"
#include "app_str.h"

#ifdef SYNCML_DM_SUPPORT
#include "DtcntSrvIprot.h"
#endif

 /*
  *STREAMING DM SUPPORT
  */
#ifdef SYNCML_DM_SUPPORT
#define MMI_STREAMING_DM_SUPPORT
#endif

typedef enum
{
    MMI_STREAMING_NS_OMA_BOOTSTRAP, 
    MMI_STREAMING_NS_OMA_PROXY,     
    MMI_STREAMING_NS_OMA_APP,      
    MMI_STREAMING_NS_OMA_PORT,      
    MMI_STREAMING_NS_OMA_TOTAL
} mmi_streaming_ns_oma_enum;

typedef struct
{
    U8   provurl[CCA_HASH_VALUE_MAX_BYTES];
    U8   proxy_id[CCA_HASH_VALUE_MAX_BYTES];
    U8   prof_name[MAX_STREAMING_PROFILE_NAME_SIZE];
} mmi_streaming_profile_unique_id;


typedef struct
{
    streaming_profile_nvram_struct  profile[MAX_STREAMING_PROFILE_NUM];
    mmi_streaming_profile_unique_id old_unique[MAX_STREAMING_PROFILE_NUM];
    S32         hConfig;
    U16         sim_id;             /* SIM1 or SIM2 */
    U16         config_id;          /* id of configure application */   
    U8          provurl[CCA_HASH_VALUE_MAX_BYTES];
    U8          is_used[MAX_STREAMING_PROFILE_NUM];  /* is profile[i] has content or not */
    U8          is_done[MAX_STREAMING_PROFILE_NUM];
    U8          is_empty[MAX_STREAMING_PROFILE_NUM]; /* is old profile empty or not */
    U8          update_index[MAX_STREAMING_PROFILE_NUM];
    U8          cur_index;           /* index of current profile */
    U8          highlight_index;     /* when replace, record the choose profile */
    U8          is_updated;
    U8          is_skipped;
    U8          is_installed;
    U8          need_send_abort;
} mmi_streaming_otap_context;

/*
 * Get profile_name, proxyID, data_account, proxy_addr from  MMI_STREAMING_NS_OMA_PROXY;
 * Get proxy port from MMI_STREAMING_NS_OMA_PORT;
 * Get min_udp_port and max_udp_port from MMI_STREAMING_NS_OMA_APP;
 * Get bootstrap from MMI_STREAMING_NS_OMA_BOOTSTRAP
 */
static const U16 cca_mapping_streaming[] = 
{
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY,      MMI_STREAMING_NS_OMA_PROXY,     0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY,      CCA_NS_OMA_PORT,                MMI_STREAMING_NS_OMA_PORT, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION,MMI_STREAMING_NS_OMA_APP,       0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_BOOTSTRAP,  MMI_STREAMING_NS_OMA_BOOTSTRAP, 0xFFFF,
};

static mmi_streaming_otap_context *g_streaming_p = NULL;


/*  
  *STREAMING DM related
  */
#ifdef MMI_STREAMING_DM_SUPPORT

typedef enum{
    MMI_STREAMING_DM_GET,
	MMI_STREAMING_DM_UPDATE
}mmi_streaming_massage_type;

typedef struct
{
    streaming_profile_nvram_struct profile;
	S32 prof_id;
    S32 hConfig;
	U16 sim_id;
    U16 app_id; 
    U8 cbm_app_id;
    cca_status_enum result;
}mmi_streaming_dm_content;
static mmi_streaming_dm_content   *g_streaming_dm_ptr   = NULL;
#endif


/* mmi streaming parsing data related */
static void mmi_streaming_ota_send_cca_conf_rsp(cca_status_enum status);
static void mmi_streaming_ota_send_cca_detail_rsp(cca_status_enum status, U16 config_id, S32 hConfig, U16 sim_id);
static void mmi_streaming_ota_create_context(mmi_cca_app_configure_ind_struct *msg);
static void mmi_streaming_ota_init_context(void);
static void mmi_streaming_ota_free_context(void);
static void mmi_streaming_ota_handle_doc(mmi_cca_app_configure_ind_struct *msg);
static void mmi_streaming_ota_profile_validation(void);
static void mmi_streaming_ota_mapping_profile(void);
static cca_status_enum mmi_streaming_ota_process_callback_nodes(
                        S32 hConfig,
                        S32 hNode,
                        U16 node_symbol,
                        cca_iterator_struct *iter_datalist,
                        void *user_data);
static cca_status_enum mmi_streaming_ota_parse_bootstrap(cca_iterator_struct *iter_datalist, void *user_data);
static cca_status_enum mmi_streaming_ota_parse_proxy(cca_iterator_struct *iter_datalist, void *user_data);
static cca_status_enum mmi_streaming_ota_parse_app(cca_iterator_struct *iter_datalist, void *user_data);
static cca_status_enum mmi_streaming_ota_parse_port(S32 hNode, void *user_data);
static void mmi_streaming_ota_handle_app_by_toproxy(
                CHAR *px_id,
                cca_iterator_struct *iter_datalist,
                void *user_data);
static cca_status_enum mmi_streaming_ota_handle_proxy_params(cca_core_data_struct *data, void *user_data);
static cca_status_enum mmi_streaming_ota_handle_app_param(cca_core_data_struct *data, void *user_data);
static cca_status_enum mmi_streaming_ota_check_port(const CHAR *port_str, S32 *port_p);

/* mmi streaming OTA screen related */
static void mmi_streaming_ota_install_profile(void);
static void mmi_streaming_ota_pre_enter_installation(void);
static void mmi_streaming_ota_enter_installation(void);
static void mmi_streaming_ota_create_cur_display_string(CHAR *buffer);
static void mmi_streaming_ota_hilite_prof_list(S32 index);
static void mmi_streaming_ota_enter_prof_list(void);
static void mmi_streaming_ota_install_yes(void);
static void mmi_streaming_ota_prof_use(void);
static void mmi_streaming_ota_install(void);
static MMI_BOOL mmi_streaming_ota_get_next(U8 index);
static void mmi_streaming_ota_skip_confirm(void);
static void mmi_streaming_ota_skip_yes(void);
static U8 mmi_streaming_ota_abort(void *dummy);
static void mmi_streaming_ota_install_done(cca_status_enum status);

static void mmi_streaming_ota_install_result(void);

/* mmi streaming OTA util */
static U8 mmi_streaming_ota_get_empty_profile(void);
static void mmi_streaming_ota_set_profile_status(U8 index, U8 status);
static S32 mmi_streaming_ota_get_proxy_index(U8 *px_id);
static MMI_BOOL mmi_streaming_ota_is_profile_valid(U8 index);
static MMI_BOOL mmi_streaming_ota_is_use_proxy(U8 *ip);
static U8 mmi_streaming_ota_get_total_num(void);

/* mmi streaming util */
static MMI_BOOL mmi_streaming_is_ascii_string(const U8 *utf8_str);
static MMI_BOOL mmi_streaming_compare_hash_value(const U8 *p1, const U8 *p2);
static MMI_BOOL mmi_streaming_ota_is_empty_hash(const CHAR *data);
static MMI_BOOL mmi_streaming_parse_ip(U8 *ip, CHAR *data, S32 len);
static void mmi_streaming_simid_to_simtype(U32 sim_id, srv_dtcnt_sim_type_enum* sim_type);
static void mmi_streaming_simid_to_cbmid(U32 sim_id, srv_dtcnt_sim_type_enum* cbm_sim_id);


//10A
static MMI_ID mmi_streaming_ota_enter_grp_installation(void);
static MMI_ID mmi_streaming_ota_enter_grp_replace_list(void);
static mmi_ret mmi_streaming_ota_installation_proc(mmi_event_struct *evt);
static mmi_ret mmi_streaming_ota_replace_list_proc(mmi_event_struct *evt);
static void mmi_streaming_ota_display_popup(MMI_ID parent_id, UI_string_type str_ptr, mmi_event_notify_enum type);

//Streaming DM
#ifdef MMI_STREAMING_DM_SUPPORT
static void mmi_streaming_dm_create_content(void *msg, mmi_streaming_massage_type msg_type);
static void mmi_streaming_dm_construct_cca_doc();
static void mmi_streaming_dm_parse_cca_doc();
static void mmi_streaming_dm_send_response(mmi_streaming_massage_type msg_type);
static cca_status_enum mmi_streaming_dm_process_callback_nodes(
                        S32 hConfig,
                        S32 hNode,
                        U16 node_symbol,
                        cca_iterator_struct *iter_datalist,
                        void *user_data);

static cca_status_enum mmi_streaming_dm_parse_proxy(cca_iterator_struct *iter_datalist, void *user_data);
static cca_status_enum mmi_streaming_dm_handle_proxy_params(cca_core_data_struct *data, void *user_data);
static cca_status_enum mmi_streaming_dm_parse_port(S32 hNode, void *user_data);
static cca_status_enum mmi_streaming_dm_parse_app(cca_iterator_struct *iter_datalist, void *user_data);
static cca_status_enum mmi_streaming_dm_handle_app_param(cca_core_data_struct *data, void *user_data);

static void mmi_streaming_dm_profile_validation(void);

static void mmi_streaming_dm_reg_temp_app_id(void);
static void mmi_streaming_dm_dereg_temp_app_id(void);

static void mmi_streaming_general_ip(CHAR* ip, CHAR* ip_str);
static void mmi_streaming_general_port(U32 port, CHAR* port_str, U32 len);

#endif /* MMI_STREAMING_DM_SUPPORT */


#define MMI_STREAMING_OTAP_10A
/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_enter_grp_installation
 * DESCRIPTION
 *   entry streaming OTAP installation sceen group
 * PARAMETERS
 *  void    
 * RETURNS
 *  MMI_ID   group id
 *****************************************************************************/
MMI_ID mmi_streaming_ota_enter_grp_installation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID      parent_grp_id;
    MMI_ID      ret_mmi_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_STREAMING_OTA_INSTALLATION))
    {
        mmi_frm_group_close(GRP_ID_STREAMING_OTA_INSTALLATION);        
    }
    
    parent_grp_id = mmi_cca_get_root_group();      
    ret_mmi_id = mmi_frm_group_create(
                    parent_grp_id, 
                    GRP_ID_STREAMING_OTA_INSTALLATION, 
                    mmi_streaming_ota_installation_proc,
                    NULL);
                    
    if (GRP_ID_INVALID == ret_mmi_id)  
    {
        mmi_streaming_ota_display_popup(parent_grp_id, (U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);
        return ret_mmi_id;
    }

    ret_mmi_id = mmi_frm_group_enter(ret_mmi_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (GRP_ID_INVALID == ret_mmi_id)  
    {
        mmi_streaming_ota_display_popup(parent_grp_id, (U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);
        return ret_mmi_id;
    }
    
    return ret_mmi_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_enter_grp_replace_list
 * DESCRIPTION
 *   entry replace list screen group
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_streaming_ota_enter_grp_replace_list(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
    MMI_ID      parent_grp_id;
    MMI_ID      ret_mmi_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_STREAMING_OTA_REPLACE_LIST))
    {
        mmi_frm_group_close(GRP_ID_STREAMING_OTA_REPLACE_LIST);        
    }
    
    parent_grp_id = mmi_cca_get_root_group();  
    ret_mmi_id = mmi_frm_group_create(
                    parent_grp_id, 
                    GRP_ID_STREAMING_OTA_REPLACE_LIST, 
                    mmi_streaming_ota_replace_list_proc,
                    NULL);
                    
    if (GRP_ID_INVALID == ret_mmi_id)  
    {
        mmi_streaming_ota_display_popup(parent_grp_id, (U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);
        return ret_mmi_id;
    }

    ret_mmi_id = mmi_frm_group_enter(ret_mmi_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (GRP_ID_INVALID == ret_mmi_id)  
    {
        mmi_streaming_ota_display_popup(parent_grp_id, (U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);
        return ret_mmi_id;
    }
    
    return ret_mmi_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_installation_proc
 * DESCRIPTION
 *   installation screen group proc
 * PARAMETERS
 *  evt     [in]   event struct  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_streaming_ota_installation_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_streaming_p == NULL)
	{
	    return MMI_RET_OK;
	}
	
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            if (g_streaming_p->need_send_abort)
            {
                mmi_streaming_ota_abort(NULL);    
            }
            
            break;
        }
        
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *confirm = (mmi_alert_result_evt_struct *)evt;
            switch (confirm->result)
            {
                case MMI_POPUP_INTERRUPT_EXIT:
                case MMI_ALERT_NORMAL_EXIT:
                {
                    break;
                }
                case MMI_ALERT_CNFM_OK:  
                case MMI_ALERT_CNFM_YES:         
                {
                    ((FuncPtr)confirm->user_tag)();
                    break;
                }
                case MMI_ALERT_CNFM_NO:         
                case MMI_ALERT_CNFM_CANCEL:      
                {
                    mmi_alert_dismiss(confirm->alert_id);
                    break;
                }
                default:
                    break;
            }
            break;
        }         
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_replace_list_proc
 * DESCRIPTION
 *   replace list screen group proc
 * PARAMETERS
 *  evt     [in]   event struct   
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_streaming_ota_replace_list_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_streaming_p == NULL)
	{
	    return MMI_RET_OK;
	}

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            
            break;
        }
        
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *confirm = (mmi_alert_result_evt_struct *)evt;
            switch (confirm->result)
            {
                case MMI_POPUP_INTERRUPT_EXIT:
                case MMI_ALERT_NORMAL_EXIT:
                {
                    break;
                }
                case MMI_ALERT_CNFM_OK:  
                case MMI_ALERT_CNFM_YES:         
                {
                    ((FuncPtr)confirm->user_tag)();
                    break;
                }
                case MMI_ALERT_CNFM_NO:         
                case MMI_ALERT_CNFM_CANCEL:      
                {
                    mmi_alert_dismiss(confirm->alert_id);
                    break;
                }
                default:
                    break;
            }
            break;
        }         
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_display_popup
 * DESCRIPTION
 *   display popup
 * PARAMETERS
 *  parent_id     [IN] parent id 
 *  str_ptr       [IN] popup string
 *  type          [IN] popup type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_streaming_ota_display_popup(MMI_ID parent_id, UI_string_type str_ptr, mmi_event_notify_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple(                   
        str_ptr,                                
        type,                                   
        parent_id,                                 
        NULL);    
}


#define MMI_STREAMING_OTA_PARSE_DATA_RELATED
/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_proc_cca_doc
 * DESCRIPTION
 *   process cca doc
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_streaming_proc_cca_doc(srv_cca_app_configure_ind_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if(MMI_SIM_TOTAL > 1)
    MMI_BOOL is_sim_valid;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg == NULL)
    {
        return;
    }

    if (msg->prov_type != MMI_CCA_PROV_TYPE_OTA_PROV)
    {
        mmi_streaming_ota_send_cca_detail_rsp(CCA_STATUS_INVALID_SETTING, msg->config_id, msg->hConfig, msg->sim_id);
        return;
    }
#if(MMI_SIM_TOTAL > 1)
    is_sim_valid=MMI_FALSE;
#endif

#if(MMI_SIM_TOTAL > 3)
    if (msg->sim_id == MMI_SIM4)
    {
       is_sim_valid = MMI_TRUE;
    }
#endif

#if(MMI_SIM_TOTAL > 2)
    if (msg->sim_id == MMI_SIM3)
    {
       is_sim_valid = MMI_TRUE;
    }
#endif

#if(MMI_SIM_TOTAL > 1)
    if (msg->sim_id == MMI_SIM2 || msg->sim_id == MMI_SIM1)
    {
       is_sim_valid = MMI_TRUE;
    }

    if (is_sim_valid == MMI_FALSE)
    {
        mmi_streaming_ota_send_cca_detail_rsp(CCA_STATUS_INVALID_SETTING, msg->config_id, msg->hConfig, msg->sim_id);
        return;
    }
#endif

    mmi_streaming_ota_create_context(msg);
    mmi_streaming_ota_handle_doc(msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_init
 * DESCRIPTION
 *   create context, get mem from control buffer
 * PARAMETERS
 *  ind     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_create_context(mmi_cca_app_configure_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_CREATE_CONTEXT);
    if (g_streaming_p != NULL)
    {
        mmi_streaming_ota_free_context();
    }
    g_streaming_p = (mmi_streaming_otap_context*) OslMalloc(sizeof(mmi_streaming_otap_context));
    if (g_streaming_p == NULL)
    {
        mmi_streaming_ota_send_cca_detail_rsp(CCA_STATUS_FAIL, ind->config_id, ind->hConfig, ind->sim_id);
        return;
    }
    memset(g_streaming_p, 0, sizeof(mmi_streaming_otap_context));

    g_streaming_p ->config_id = ind->config_id;
    g_streaming_p ->hConfig = ind->hConfig;
    g_streaming_p ->sim_id = ind->sim_id;

    mmi_streaming_ota_init_context();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_init_context
 * DESCRIPTION
 *    init context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_dtcnt_sim_type_enum sim_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init old unique id and is_empty */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_INT_CONTEXT);
    for (i = 0; i < MAX_STREAMING_PROFILE_NUM; i++)
    {
        mmi_media_load_profile((U8) i, &g_streaming_p ->profile[i]);
        if (mmi_streaming_ota_is_empty_hash((CHAR*)g_streaming_p ->profile[i].proxy_id))
        {
            g_streaming_p ->is_empty[i] = MMI_TRUE;
        }
        else
        {
            g_streaming_p ->is_empty[i] = MMI_FALSE;
            memcpy(g_streaming_p ->old_unique[i].provurl, g_streaming_p ->profile[i].provurl, CCA_HASH_VALUE_MAX_BYTES);
            memcpy(g_streaming_p ->old_unique[i].proxy_id, g_streaming_p ->profile[i].proxy_id, CCA_HASH_VALUE_MAX_BYTES);            
        }
        memcpy(g_streaming_p ->old_unique[i].prof_name, g_streaming_p ->profile[i].profile_name, MAX_STREAMING_PROFILE_NAME_SIZE);
    }
    memset(&g_streaming_p ->profile, 0, MAX_STREAMING_PROFILE_NUM * sizeof(streaming_profile_nvram_struct));

    /* init is_used and update index */
    mmi_streaming_simid_to_simtype(g_streaming_p->sim_id, &sim_type);
    for (i = 0; i < MAX_STREAMING_PROFILE_NUM; i++)
    {
        g_streaming_p ->is_used[i] = MMI_FALSE;
        g_streaming_p ->is_done[i] = MMI_FALSE;
        g_streaming_p ->update_index[i] = INVALID_STREAMING_PROFILE_INDEX;
        g_streaming_p ->profile[i].data_account_id[sim_type - SRV_DTCNT_SIM_TYPE_1] = MMI_DTCNT_INVALID_ID;
        g_streaming_p ->profile[i].proxy_port = -1;
    }

    g_streaming_p ->cur_index = INVALID_STREAMING_PROFILE_INDEX;
    g_streaming_p ->highlight_index = INVALID_STREAMING_PROFILE_INDEX;
    g_streaming_p->need_send_abort = 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_handle_doc
 * DESCRIPTION
 *   handle doc 
 * PARAMETERS
 *  ind     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_handle_doc(mmi_cca_app_configure_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_HANDLE_DOC);
    mmi_cca_doc_process(
        ind->hConfig,
        cca_mapping_streaming,
        sizeof(cca_mapping_streaming) / sizeof(U16),
        NULL,
        mmi_streaming_ota_process_callback_nodes,
        NULL);

    mmi_streaming_ota_profile_validation();
    mmi_streaming_ota_mapping_profile();
    mmi_streaming_ota_install_profile();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_send_cca_detail_rsp
 * DESCRIPTION
 *   send cca response for detail
 * PARAMETERS
 *  status          [IN]        
 *  config_id       [IN]        
 *  hConfig         [IN] 
 *  sim_id          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_send_cca_detail_rsp(cca_status_enum status, U16 config_id, S32 hConfig, U16 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_configure_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_DETAIL_RSP);
    data = OslAllocDataPtr(mmi_cca_app_configure_rsp_struct);

    data->config_id = config_id;
    data->hConfig = hConfig;
    data->status = status;
    data->sim_id = sim_id;

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_CONFIGURE_RSP, (oslParaType*)data, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_send_cca_conf_rsp
 * DESCRIPTION
 *  send cca response with status
 * PARAMETERS
 *  status          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_send_cca_conf_rsp(cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_configure_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_STATUS_RSP);
    data = OslAllocDataPtr(mmi_cca_app_configure_rsp_struct);

    data->config_id = g_streaming_p ->config_id;
    data->hConfig = g_streaming_p ->hConfig;
    data->status = status;

	mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_CONFIGURE_RSP, (oslParaType*)data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_process_callback_nodes
 * DESCRIPTION
 *    doc process callback
 * PARAMETERS
 *  hConfig             [IN]        
 *  hNode               [IN]        
 *  node_symbol         [IN]        
 *  iter_datalist       [?]         
 *  user_data           [?]         
 * RETURNS
 *  
 *****************************************************************************/
static cca_status_enum mmi_streaming_ota_process_callback_nodes(
                        S32 hConfig,
                        S32 hNode,
                        U16 node_symbol,
                        cca_iterator_struct *iter_datalist,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_streaming_p == NULL)
	{
	    return SRV_CCA_STATUS_OK;
	}
	
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_CALLBACK_NODE);
    switch (node_symbol)
    {
        case MMI_STREAMING_NS_OMA_BOOTSTRAP:
            mmi_streaming_ota_parse_bootstrap(iter_datalist, user_data);
            break;

        case MMI_STREAMING_NS_OMA_PROXY:
            mmi_streaming_ota_parse_proxy(iter_datalist, user_data);
            break;

        case MMI_STREAMING_NS_OMA_PORT:
            mmi_streaming_ota_parse_port(hNode, user_data);
            break;

        case MMI_STREAMING_NS_OMA_APP:
            mmi_streaming_ota_parse_app(iter_datalist, user_data);
            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_parse_bootstrap
 * DESCRIPTION
 *   parse bootstrap node
 * PARAMETERS
 *  iter_datalist       [?]     
 *  user_data           [?]     
 * RETURNS
 *  
 *****************************************************************************/
static cca_status_enum mmi_streaming_ota_parse_bootstrap(cca_iterator_struct *iter_datalist, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    cca_status_enum status = CCA_STATUS_OK;
    CHAR **provurl;
    S32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_PARSE_BOOTSTRAP);
    status = mmi_cca_doc_get_nodedata_strs(iter_datalist, CCA_NS_OMA_PROVURL, &provurl, &size);

    /* one bootstap should only include one provurl or no provurl */
    if (status != CCA_STATUS_OK || size > 1)
    {
        return CCA_STATUS_FAIL;
    }

    mmi_cca_generate_hash_value((CHAR*) provurl[0], g_streaming_p ->provurl, CCA_HASH_VALUE_MAX_BYTES);

    mmi_cca_iterator_restart(iter_datalist);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */ 
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_parse_proxy
 * DESCRIPTION
 *   parse proxy node
 * PARAMETERS
 *  iter_datalist       [?]     
 *  user_data           [?]     
 * RETURNS
 *  
 *****************************************************************************/
static cca_status_enum mmi_streaming_ota_parse_proxy(cca_iterator_struct *iter_datalist, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data;
    cca_status_enum status = CCA_STATUS_OK;
    CHAR **px_id;
    S32 size;
    U8 profile_index;
    U8 proxy_id[CCA_HASH_VALUE_MAX_BYTES];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_PARSE_PROXY);
    MMI_ASSERT(g_streaming_p ->cur_index == INVALID_STREAMING_PROFILE_INDEX);

    profile_index = mmi_streaming_ota_get_empty_profile();
    if (profile_index >= MAX_STREAMING_PROFILE_NUM)
    {
        return CCA_STATUS_FAIL;
    }

    g_streaming_p ->cur_index = profile_index;

    status = mmi_cca_doc_get_nodedata_strs(iter_datalist, CCA_NS_OMA_PROXY_ID, &px_id, &size);
    /* one proxy should has only one prxoy id */
    if (status != CCA_STATUS_OK || size != 1)
    {
        g_streaming_p ->cur_index = INVALID_STREAMING_PROFILE_INDEX;
        return CCA_STATUS_FAIL;
    }
    mmi_cca_generate_hash_value((CHAR*) px_id[0], proxy_id, CCA_HASH_VALUE_MAX_BYTES);
    /* judge whether this proxy has existed for we only support the first valid proxy for same proxy id */
    if (mmi_streaming_ota_get_proxy_index(proxy_id) != INVALID_STREAMING_PROFILE_INDEX)
    {
        g_streaming_p ->cur_index = INVALID_STREAMING_PROFILE_INDEX;
        return CCA_STATUS_FAIL;
    }

    mmi_cca_iterator_restart(iter_datalist);
    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {
        status = mmi_streaming_ota_handle_proxy_params(data, user_data);
        if (status != CCA_STATUS_OK)
        {
            return status;
        }
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_handle_proxy_params
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]     
 *  user_data       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static cca_status_enum mmi_streaming_ota_handle_proxy_params(cca_core_data_struct *data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    U8 dataacct_type;
    streaming_profile_nvram_struct *prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_HANDLE_PROXY_PARA, g_streaming_p ->cur_index);
    MMI_ASSERT(g_streaming_p ->cur_index != INVALID_STREAMING_PROFILE_INDEX);
    prof = &g_streaming_p ->profile[g_streaming_p ->cur_index];

    switch (data->id)
    {
        case CCA_NS_OMA_PROXY_ID:
            /* Whether the value is presented and the type is legal. */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                MMI_STREAM_OTAP_ERROR_TRACE(data->size);
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (!mmi_streaming_is_ascii_string((U8*) data->values.s[0]))
            {
                MMI_STREAM_OTAP_ERROR_TRACE(99);
                return CCA_STATUS_FAIL;
            }

            /* Check whether the length of the proxy id is legal. */
            mmi_cca_generate_hash_value((CHAR*) data->values.s[0], (U8*) prof->proxy_id, CCA_HASH_VALUE_MAX_BYTES);

            break;

        case CCA_NS_OMA_PXADDR:
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                MMI_STREAM_OTAP_ERROR_TRACE(data->size);
                return CCA_STATUS_FAIL;
            }

            kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: proxy_id: %s, line:%d", data->values.s[0], __LINE__);

            /* Whether this is a ASCII string. */
            if (!mmi_streaming_is_ascii_string((U8*) data->values.s[0]))
            {
                MMI_STREAM_OTAP_ERROR_TRACE(99);
                return CCA_STATUS_FAIL;
            }

            str_len = strlen(data->values.s[0]);
            MMI_STREAM_OTAP_MASSAGE_TRACE(str_len);
            if (!mmi_streaming_parse_ip((U8*) & prof->proxy_addr[0], data->values.s[0], str_len))
            {
                MMI_STREAM_OTAP_ERROR_TRACE(98);
                return CCA_STATUS_FAIL;
            }

            if (mmi_streaming_ota_is_use_proxy((U8*) & prof->proxy_addr[0]))
            {
                prof->proxy_on_off = MMI_TRUE;
            }
            else
            {
                prof->proxy_on_off = MMI_FALSE;
            }
            break;

        case CCA_NS_DATAACCTID:
            if (data->size <= 0 || data->type != CCA_DT_INT)
            {
                MMI_STREAM_OTAP_ERROR_TRACE(data->size);
                return CCA_STATUS_FAIL;
            }

            dataacct_type = srv_dtcnt_get_bearer_type((U32) data->values.i[0], SRV_DTCNT_ACCOUNT_PRIMARY);
            if (data->values.i[0] == MMI_DTCNT_INVALID_ID)
            {
                MMI_STREAM_OTAP_ERROR_TRACE(97);
                return CCA_STATUS_FAIL;
            }

            if ((dataacct_type & STREAMING_DATA_ACCOUNT_TYPE) == 0)
            {
                MMI_STREAM_OTAP_ERROR_TRACE(96);
                return CCA_STATUS_FAIL;
            }
            {                
                U16 string_id;
                U16 icon_id;
                srv_dtcnt_sim_type_enum sim_type;
                mmi_media_get_string_id_and_icon_id(&string_id, &icon_id);
                mmi_streaming_simid_to_simtype(g_streaming_p->sim_id, &sim_type);
                mmi_dtcnt_subscribe_account(prof->data_account_id[sim_type - SRV_DTCNT_SIM_TYPE_1], data->values.i[0], string_id, icon_id);
                prof->data_account_id[sim_type - SRV_DTCNT_SIM_TYPE_1] = data->values.i[0];
            } 
            
            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_check_port
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port_str        [IN]        
 *  port_p          [?]         
 * RETURNS
 *  
 *****************************************************************************/
static cca_status_enum mmi_streaming_ota_check_port(const CHAR *port_str, S32 *port_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status = CCA_STATUS_OK;
    S32 port;
    S32 str_len;
    S32 i;
    CHAR temp[STREAMING_PROFILE_PORT_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_CHECK_PORT);
    kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: port: %s, line:%d", port_str, __LINE__);
    if (!mmi_streaming_is_ascii_string((U8*) port_str))
    {
        MMI_STREAM_OTAP_ERROR_TRACE(97);
        return CCA_STATUS_FAIL;
    }

    str_len = mmi_ucs2strlen(port_str);
    /* we deal with port string "65535  " as legal, but skip blank */
    if (str_len + 1 > STREAMING_PROFILE_PORT_LEN)
    {
        str_len = STREAMING_PROFILE_PORT_LEN - 1;
		app_strlcpy(temp, port_str, str_len);
        temp[str_len] = 0;

    }
    else
    {
        mmi_ucs2cpy(temp, port_str);
    }

    for (i = 0; i < str_len; i++)
    {
        /* Whether data is decimal number. */
        if (port_str[i] < '0' || port_str[i] > '9')
        {
            MMI_STREAM_OTAP_ERROR_TRACE(i);
            return CCA_STATUS_FAIL;
        }
    }

    port = atoi(temp);
    MMI_STREAM_OTAP_MASSAGE_TRACE(i);

    /* Check whether value of port is legal. */
    if (port < 0 || port > 65535)
    {
        MMI_STREAM_OTAP_ERROR_TRACE(port);
        return CCA_STATUS_FAIL;
    }

    *port_p = port;

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_parse_port
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hNode           [IN]        
 *  user_data       [?]         
 * RETURNS
 *  
 *****************************************************************************/
static cca_status_enum mmi_streaming_ota_parse_port(S32 hNode, void *user_data)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status = CCA_STATUS_OK;
    CHAR *str_port = NULL;
    streaming_profile_nvram_struct *prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* port node should be included in proxy node, if assert, port node is illegal */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_PORT_PARSING, g_streaming_p ->cur_index);
    if (g_streaming_p ->cur_index == INVALID_STREAMING_PROFILE_INDEX)
    {
        MMI_STREAM_OTAP_ERROR_TRACE(g_streaming_p ->cur_index);
    		return CCA_STATUS_FAIL;
    }
    prof = &g_streaming_p ->profile[g_streaming_p ->cur_index];

    status = mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_PORTNBR, &str_port);
    if (status != CCA_STATUS_OK)
    {
        MMI_STREAM_OTAP_ERROR_TRACE(status);
    	g_streaming_p ->cur_index = INVALID_STREAMING_PROFILE_INDEX;
        return CCA_STATUS_FAIL;
    }
    if (str_port == NULL)
    {
        MMI_STREAM_OTAP_ERROR_TRACE(str_port);
    	g_streaming_p ->cur_index = INVALID_STREAMING_PROFILE_INDEX;
        return CCA_STATUS_FAIL;
    }
    status = mmi_streaming_ota_check_port(str_port, &prof->proxy_port);
    if (status != CCA_STATUS_OK)
    {
        MMI_STREAM_OTAP_ERROR_TRACE(status);
    	g_streaming_p ->cur_index = INVALID_STREAMING_PROFILE_INDEX;
        return CCA_STATUS_FAIL;
    }
	if (mmi_streaming_ota_is_profile_valid(g_streaming_p ->cur_index))
    {
        mmi_streaming_ota_set_profile_status(g_streaming_p ->cur_index, STREAMING_PROFILE_USED);
    }
    g_streaming_p ->cur_index = INVALID_STREAMING_PROFILE_INDEX;
    MMI_STREAM_OTAP_MASSAGE_TRACE(status);
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_parse_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  iter_datalist       [?]     
 *  user_data           [?]     
 * RETURNS
 *  
 *****************************************************************************/
static cca_status_enum mmi_streaming_ota_parse_app(cca_iterator_struct *iter_datalist, void *user_data)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR **px_id;
    S32 size;
    cca_status_enum status = CCA_STATUS_OK;
    U8 proxy_id[CCA_HASH_VALUE_MAX_BYTES];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_PARSE_APP);
    status = mmi_cca_doc_get_nodedata_strs(iter_datalist, CCA_NS_OMA_TO_PROXY, &px_id, &size);
    if (status != CCA_STATUS_OK)
    {
        return CCA_STATUS_FAIL;
    }
    
    if (size < 1)
    {
        return CCA_STATUS_FAIL;
    }

    for (i = 0; i < size; i++)
    {
        if (!mmi_streaming_is_ascii_string((U8*) px_id[i]))
        {
            continue;
        }
        mmi_cca_generate_hash_value((CHAR*) px_id[i], proxy_id, CCA_HASH_VALUE_MAX_BYTES);
        if (mmi_streaming_ota_get_proxy_index( proxy_id) == INVALID_STREAMING_PROFILE_INDEX)
        {
            continue;
        }
        mmi_streaming_ota_handle_app_by_toproxy((CHAR*)proxy_id, iter_datalist, user_data);

    }
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_handle_app_by_toproxy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  px_id               [IN]        
 *  iter_datalist       [?]         
 *  user_data           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_handle_app_by_toproxy(
                CHAR *px_id,
                cca_iterator_struct *iter_datalist,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data;
    cca_status_enum status = CCA_STATUS_OK;
    S32             index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_streaming_p ->cur_index == INVALID_STREAMING_PROFILE_INDEX);

    index = mmi_streaming_ota_get_proxy_index(px_id);
    MMI_ASSERT(index != INVALID_STREAMING_PROFILE_INDEX);
    if (g_streaming_p ->is_done[index] == MMI_TRUE)
    {
        return;    
    }
    g_streaming_p ->cur_index = index;
    
    mmi_cca_iterator_restart(iter_datalist);
    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {
        status = mmi_streaming_ota_handle_app_param(data, user_data);
        if (status != CCA_STATUS_OK)
        {
            break;
        }
    }
    g_streaming_p ->is_done[g_streaming_p ->cur_index] = MMI_TRUE;
    g_streaming_p ->cur_index = INVALID_STREAMING_PROFILE_INDEX;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_handle_app_param
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]     
 *  user_data       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static cca_status_enum mmi_streaming_ota_handle_app_param(cca_core_data_struct *data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    streaming_profile_nvram_struct *prof;
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_streaming_p ->cur_index != INVALID_STREAMING_PROFILE_INDEX);
    prof = &g_streaming_p ->profile[g_streaming_p ->cur_index];

    switch (data->id)
    {
        case CCA_NS_OMA_NAME:
            /* Whether the value is presented and the type is legal. If it's
               illegal, default name will be used. Still return OK. */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_OK;   /* Error-tolerant for profile's name */
            }

            /* Extract the profile's name. If the name is too long, it will be
               truncated by the function. */
            mmi_chset_utf8_to_ucs2_string(
                (U8*) prof->profile_name,
                MAX_STREAMING_PROFILE_NAME_SIZE,
                (U8*) data->values.s[0]);
            break;

        case CCA_NS_OMA_MIN_UDP_PORT:
            /* only consider the first value, skip the other value */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_OK;   /* Error-tolerant for UDP port */
            }

            status = mmi_streaming_ota_check_port(data->values.s[0], &prof->lowest_udp_port);
            if (status != CCA_STATUS_OK)
            {
                return CCA_STATUS_OK;   /* Error-tolerant for UDP port */
            }
            break;

        case CCA_NS_OMA_MAX_UDP_PORT:
            /* only consider the first value, skip the other value */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_OK;   /* Error-tolerant for UDP port */
            }

            status = mmi_streaming_ota_check_port(data->values.s[0], &prof->highest_udp_port);
            if (status != CCA_STATUS_OK)
            {
                return CCA_STATUS_OK;   /* Error-tolerant for UDP port */
            }
            break;

        default:
            break;
    }

    return status;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_profile_validation
 * DESCRIPTION
 *  at this case, all profiles are valid but some param (such as udp port) 
 *    is not valid.
 *  This function is to make udp port valid by using default value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_profile_validation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    streaming_profile_nvram_struct *prof = &g_streaming_p ->profile[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_VALIDATION);
    for (i = 0; i < MAX_STREAMING_PROFILE_NUM; i++)
    {
        if (g_streaming_p ->is_done[i] == MMI_FALSE)
        {
            continue;
        }

        if (prof[i].lowest_udp_port < DEFAULT_MIN_UDP_PORT
            || prof[i].lowest_udp_port > DEFAULT_MAX_UDP_PORT - UDP_PORT_DELTA)
        {
            prof[i].lowest_udp_port = DEFAULT_MIN_UDP_PORT;
        }

        if (prof[i].highest_udp_port < DEFAULT_MIN_UDP_PORT + UDP_PORT_DELTA
            || prof[i].highest_udp_port > DEFAULT_MAX_UDP_PORT)
        {
            prof[i].highest_udp_port = DEFAULT_MAX_UDP_PORT;
        }

        if (prof[i].highest_udp_port - prof[i].lowest_udp_port < 3)
        {
            prof[i].highest_udp_port = DEFAULT_MAX_UDP_PORT;
            prof[i].lowest_udp_port = DEFAULT_MIN_UDP_PORT;
        }

    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_mapping_profile
 * DESCRIPTION
 *    This function is to find the provURL_ID and proxy_ID in old profiles.
 *    If should be replaced, will update the update id. For boot strap  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_mapping_profile(void)
{
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    streaming_profile_nvram_struct *new_p = &g_streaming_p ->profile[0];
    mmi_streaming_profile_unique_id *old_p = &g_streaming_p ->old_unique[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_MAPPTING_PROF);
    if (mmi_streaming_ota_is_empty_hash((CHAR *)g_streaming_p ->provurl))
    {
        return;
    }
    
    for (i = 0; i < MAX_STREAMING_PROFILE_NUM; i++)
    {
        if (mmi_streaming_ota_is_empty_hash((CHAR *)old_p[i].provurl)) 
        {
            continue;
        }
        if (!mmi_streaming_compare_hash_value((U8 *)old_p[i].provurl, (U8 *)g_streaming_p ->provurl))
        {
            continue;
        }

        for (j = 0; j < MAX_STREAMING_PROFILE_NUM; j++)
        {
            if (g_streaming_p ->is_done[j] == MMI_FALSE)
            {
                continue;
            }

            if (!mmi_streaming_compare_hash_value((U8 *)old_p[i].proxy_id, (U8 *)new_p[j].proxy_id))
            {
                continue;
            }

            g_streaming_p ->update_index[j] = (U8) i;

        }
    }
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */ 
}

#define MMI_STREAMING_OTA_SCREEN_RELATED

/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_install_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_install_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    total = mmi_streaming_ota_get_total_num();
    if (total == 0)
    {
        mmi_streaming_ota_send_cca_conf_rsp(CCA_STATUS_INVALID_SETTING);
        mmi_streaming_ota_free_context();
        return;
    }
    #ifdef __DM_LAWMO_SUPPORT__
    if (TRUE == mmi_dmui_is_phone_lock())
    {
        mmi_streaming_ota_send_cca_conf_rsp(CCA_STATUS_ABORT);
        mmi_streaming_ota_free_context();
        return;
    }
    #endif    
    mmi_streaming_ota_get_next(INVALID_STREAMING_PROFILE_INDEX);

    mmi_media_del_all_app_screen();

    g_streaming_p->need_send_abort = 0;
    if (mmi_frm_group_is_present(GRP_ID_STREAMING_OTA_INSTALLATION))
    {
        mmi_frm_group_close(GRP_ID_STREAMING_OTA_INSTALLATION);    
    }
    if (mmi_frm_group_is_present(GRP_ID_STREAMING_OTA_REPLACE_LIST))
    {
        mmi_frm_group_close(GRP_ID_STREAMING_OTA_REPLACE_LIST);    
    }   
    g_streaming_p->need_send_abort = 1;  
    mmi_streaming_ota_pre_enter_installation();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_pre_enter_installation
 * DESCRIPTION
 *      before enter installation screen, there must be a background call screen; 
 *      at this case, need to insert  installation screen. After the background call screen
 *      is gone, the installation screen will pop from history stack. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_pre_enter_installation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID ret_mmi_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_mmi_id = mmi_streaming_ota_enter_grp_installation();
    if (!ret_mmi_id)
    {
        // screen group problem, so response ABORT
        mmi_streaming_ota_send_cca_conf_rsp(CCA_STATUS_ABORT);
        mmi_streaming_ota_free_context();
        return;
    }
    mmi_streaming_ota_enter_installation();
}


static void mmi_streaming_ota_enter_installation_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;    
    CHAR *display_info = (CHAR*) subMenuData;
    MMI_BOOL is_back;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_back = mmi_frm_is_in_backward_scenario();
    if (mmi_frm_scrn_enter(
        GRP_ID_STREAMING_OTA_INSTALLATION,
        SCR_ID_STREAMING_OTA_INSTALLATION,
        NULL,
        mmi_streaming_ota_enter_installation_ex,
        MMI_FRM_UNKNOW_SCRN
        ))
    {
        if (is_back)
        {
            guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        }

        SetParentHandler(0);

        mmi_streaming_ota_create_cur_display_string(display_info);

        ShowCategory78Screen(
            STR_ID_CCA_INSTALL_SETTING,
            GetRootTitleIcon(MENU_ID_STREAMING_OTA),
            STR_GLOBAL_INSTALL,
            IMG_GLOBAL_OK,
            STR_ID_CCA_SKIP,
            IMG_GLOBAL_BACK,
            NULL,
            (U8*) display_info,
            mmi_ucs2strlen(display_info),
            guiBuffer);

        if (mmi_frm_kbd_is_key_supported(KEY_CSK))
        {
            SetCenterSoftkeyFunction(mmi_streaming_ota_install, KEY_EVENT_UP);
            SetKeyHandler(mmi_streaming_ota_install, KEY_ENTER, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        }
        SetLeftSoftkeyFunction(mmi_streaming_ota_install, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_streaming_ota_skip_confirm, KEY_EVENT_UP);

        if (mmi_frm_scrn_is_present(GRP_ID_STREAMING_OTA_INSTALLATION, SCR_ID_STREAMING_OTA_INSTALLATION, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_frm_scrn_close(GRP_ID_STREAMING_OTA_INSTALLATION, SCR_ID_STREAMING_OTA_INSTALLATION);
        }        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_enter_installation
 * DESCRIPTION
 *   profile installation info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_enter_installation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;    
    CHAR *display_info = (CHAR*) subMenuData;
    MMI_BOOL is_back;
    MMI_ID scrn_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_back = mmi_frm_is_in_backward_scenario();
    scrn_id = mmi_frm_scrn_get_active_id();
    if(scrn_id == SCR_ID_STREAMING_OTA_INSTALLATION && !is_back)
    {
        mmi_frm_scrn_enter(GRP_ID_STREAMING_OTA_INSTALLATION, SCR_ID_GLOBAL_DUMMY, NULL, mmi_streaming_ota_enter_installation, MMI_FRM_FG_ONLY_SCRN);  
        mmi_frm_scrn_close(GRP_ID_STREAMING_OTA_INSTALLATION, SCR_ID_STREAMING_OTA_INSTALLATION);
    }

    if (mmi_frm_scrn_enter(
        GRP_ID_STREAMING_OTA_INSTALLATION,
        SCR_ID_STREAMING_OTA_INSTALLATION,
        NULL,
        mmi_streaming_ota_enter_installation_ex,
        MMI_FRM_UNKNOW_SCRN))
    { 
        if (is_back)
        {
            guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        }

        SetParentHandler(0);

        mmi_streaming_ota_create_cur_display_string(display_info);

        ShowCategory78Screen(
            STR_ID_CCA_INSTALL_SETTING,
            GetRootTitleIcon(MENU_ID_STREAMING_OTA),
            STR_GLOBAL_INSTALL,
            IMG_GLOBAL_OK,
            STR_ID_CCA_SKIP,
            IMG_GLOBAL_BACK,
            NULL,
            (U8*) display_info,
            mmi_ucs2strlen(display_info),
            guiBuffer);

        if (mmi_frm_kbd_is_key_supported(KEY_CSK))
        {
            SetCenterSoftkeyFunction(mmi_streaming_ota_install, KEY_EVENT_UP);
            SetKeyHandler(mmi_streaming_ota_install, KEY_ENTER, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        }
        SetLeftSoftkeyFunction(mmi_streaming_ota_install, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_streaming_ota_skip_confirm, KEY_EVENT_UP);

        if (mmi_frm_scrn_is_present(GRP_ID_STREAMING_OTA_INSTALLATION, SCR_ID_STREAMING_OTA_INSTALLATION, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_frm_scrn_close(GRP_ID_STREAMING_OTA_INSTALLATION, SCR_ID_STREAMING_OTA_INSTALLATION);
        }        
    } 
    else
    {
        mmi_streaming_ota_display_popup(
            GRP_ID_STREAMING_OTA_INSTALLATION, 
            (U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),
            MMI_EVENT_FAILURE);
    }  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_create_cur_display_string
 * DESCRIPTION
 *  Compose OTA information string
 * PARAMETERS
 *  buffer      [IN/OUT]        Store string of OTA information
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_create_cur_display_string(CHAR *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cur_profile_num = 0;
    U8 total = 0;
    CHAR temp[20];
    CHAR ucs2_temp[MAX_STREAMING_PROXY_ADDR_BUF_SIZE];
    S32 i;
    U8 cbm_app_id;
    srv_dtcnt_sim_type_enum sim_type;
	cbm_sim_id_enum cbm_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_STRING);
    /* instant message */
    mmi_ucs2cpy(buffer, GetString(STR_ID_STREAMING));
    mmi_ucs2cat(buffer, (CHAR*) L"\n");
    mmi_ucs2cat(buffer, GetString(STR_ID_CCA_PROFILE));
    mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_COLON));
    mmi_ucs2cat(buffer, (CHAR*) L" ");

    /* profile index */
    for (i = 0; i < MAX_STREAMING_PROFILE_NUM; i++)
    {
        if (g_streaming_p ->is_done[i] == MMI_FALSE)
        {
            continue;
        }
        if (i == g_streaming_p ->cur_index)
        {
            cur_profile_num = total + 1;
        }
        total++;
    }
    kal_sprintf(temp, "%d/%d", cur_profile_num, total);
    mmi_asc_to_ucs2(ucs2_temp, temp);
    mmi_ucs2cat(buffer, ucs2_temp);
    mmi_ucs2cat(buffer, (CHAR*) L"\n");

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if (g_streaming_p ->update_index[g_streaming_p ->cur_index] != INVALID_STREAMING_PROFILE_INDEX)
    {
        mmi_ucs2cat(buffer, GetString(STR_ID_CCA_UPDATE_PROFILE));
        mmi_ucs2cat(buffer, (CHAR*) L"\n");
    }

#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    /* show empty line */
    mmi_ucs2cat(buffer, (CHAR*) L"\n");
    
    /* profile name */
    if (mmi_ucs2strlen((CHAR*) g_streaming_p ->profile[g_streaming_p ->cur_index].profile_name) == 0)
    {
        mmi_ucs2cpy((CHAR*) g_streaming_p ->profile[g_streaming_p ->cur_index].profile_name, 
                    (CHAR*) GetString(STR_ID_STREAMING_PROFILE_DEFAULT_NAME));        
    }
    mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_PROF_NAME));
    mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_COLON));
    mmi_ucs2cat(buffer, (CHAR*) L" ");
    mmi_ucs2cat(buffer, (CHAR*) (g_streaming_p ->profile[g_streaming_p ->cur_index].profile_name));
    mmi_ucs2cat(buffer, (CHAR*) L"\n");

    /* encode data account id */
    cbm_app_id = (U8) mmi_media_get_cbm_app_id();

    mmi_streaming_simid_to_simtype(g_streaming_p->sim_id, &sim_type);
	mmi_streaming_simid_to_cbmid(g_streaming_p->sim_id, &cbm_sim_id);
	g_streaming_p ->profile[g_streaming_p ->cur_index].data_account_id[sim_type - SRV_DTCNT_SIM_TYPE_1] = cbm_encode_data_account_id(
                                                                        (U32) g_streaming_p ->profile[g_streaming_p ->cur_index].data_account_id[sim_type - SRV_DTCNT_SIM_TYPE_1],
                                                                        cbm_sim_id,
                                                                        cbm_app_id,
                                                                        MMI_FALSE);
    
    mmi_dtcnt_get_full_account_name(g_streaming_p ->profile[g_streaming_p ->cur_index].data_account_id[sim_type - SRV_DTCNT_SIM_TYPE_1],
                    (CHAR*)ucs2_temp,
                    MAX_DATA_ACCOUNT_NAME_LEN, MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);  
    mmi_ucs2cat(buffer, GetString(STR_GLOBAL_DATA_ACCOUNT));
    mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_COLON));
    mmi_ucs2cat(buffer, (CHAR*) L" ");
    mmi_ucs2cat(buffer, ucs2_temp);
    mmi_ucs2cat(buffer, (CHAR*) L"\n");
    
    /* proxy on or off */
    mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_IS_USE_PROXY));
    mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_COLON));
    mmi_ucs2cat(buffer, (CHAR*) L" ");
    if (g_streaming_p ->profile[g_streaming_p ->cur_index].proxy_on_off == MMI_TRUE)
    {
        mmi_ucs2cat(buffer, GetString(STR_GLOBAL_YES));
        mmi_ucs2cat(buffer, (CHAR*) L"\n");

        /* proxy addr */
        mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_PROXY_ADDR));
        mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_COLON));
        mmi_ucs2cat(buffer, (CHAR*) L" ");
        kal_wsprintf((WCHAR*)ucs2_temp, "%s", g_streaming_p ->profile[g_streaming_p ->cur_index].proxy_addr);
        mmi_ucs2cat(buffer, ucs2_temp);
        mmi_ucs2cat(buffer, (CHAR*) L"\n");

        /* proxy port */
        mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_PROXY_PORT));
        mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_COLON));
        mmi_ucs2cat(buffer, (CHAR*) L" ");
        sprintf(temp, "%d", g_streaming_p ->profile[g_streaming_p ->cur_index].proxy_port);
        mmi_asc_to_ucs2(ucs2_temp, temp);
        mmi_ucs2cat(buffer, ucs2_temp);
        mmi_ucs2cat(buffer, (CHAR*) L"\n");
    }
    else
    {
        mmi_ucs2cat(buffer, GetString(STR_GLOBAL_NO));
        mmi_ucs2cat(buffer, (CHAR*) L"\n");
    }

    /* min udp port */
    mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_MIN_UDP_PORT));
    mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_COLON));
    mmi_ucs2cat(buffer, (CHAR*) L" ");
    kal_sprintf(temp, "%d", g_streaming_p ->profile[g_streaming_p ->cur_index].lowest_udp_port);
    mmi_asc_to_ucs2(ucs2_temp, temp);
    mmi_ucs2cat(buffer, ucs2_temp);
    mmi_ucs2cat(buffer, (CHAR*) L"\n");

    /* max udp port */
    mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_MAX_UDP_PORT));
    mmi_ucs2cat(buffer, GetString(STR_ID_STREAMING_COLON));
    mmi_ucs2cat(buffer, (CHAR*) L" ");
    kal_sprintf(temp, "%d", g_streaming_p ->profile[g_streaming_p ->cur_index].highest_udp_port);
    mmi_asc_to_ucs2(ucs2_temp, temp);
    mmi_ucs2cat(buffer, ucs2_temp);
    mmi_ucs2cat(buffer, (CHAR*) L"\n");

}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_hilite_prof_list
 * DESCRIPTION
 *  Highlight handler for OTA profile list.
 * PARAMETERS
 *  index       [IN]        Profile index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_hilite_prof_list(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_streaming_p ->highlight_index = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_enter_prof_list
 * DESCRIPTION
 *  Entry screen for list profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_enter_prof_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 *nStrItemList[MAX_STREAMING_PROFILE_NUM];
    U16 icon_item_list[MAX_STREAMING_PROFILE_NUM];
    U8 *guiBuffer;
    S32 curr_hilite = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
        GRP_ID_STREAMING_OTA_REPLACE_LIST,
        SCR_ID_STREAMING_OTA_REPLACE_LIST,
        NULL,
        mmi_streaming_ota_enter_prof_list,
        MMI_FRM_UNKNOW_SCRN))
    {
        //EntryNewScreen(SCR_ID_STREAMING_OTA_REPLACE_LIST, NULL, mmi_streaming_ota_enter_prof_list, NULL);

        //guiBuffer = GetCurrGuiBuffer(SCR_ID_STREAMING_OTA_REPLACE_LIST);
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();
        for (i = 0; i < MAX_STREAMING_PROFILE_NUM; i++)
        {       
            nStrItemList[i] = (U8*) g_streaming_p ->old_unique[i].prof_name;
            icon_item_list[i] = 0;    
        }

     

        RegisterHighlightHandler(mmi_streaming_ota_hilite_prof_list);

        ShowCategory73Screen(
            STR_ID_CCA_REPLACE_SETTING,
            GetRootTitleIcon(MENU_ID_STREAMING_OTA),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            MAX_STREAMING_PROFILE_NUM,
            nStrItemList,
            icon_item_list,
            (U16*) gIndexIconsImageList,
            curr_hilite,
            guiBuffer,
            ICON_ICON_TEXT);

        if (mmi_frm_kbd_is_key_supported(KEY_CSK))
        {
            SetCenterSoftkeyFunction(mmi_streaming_ota_install_yes, KEY_EVENT_UP);
            SetKeyHandler(mmi_streaming_ota_install_yes, KEY_ENTER, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        }
        SetLeftSoftkeyFunction(mmi_streaming_ota_install_yes, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
    }
    else
    {
        mmi_streaming_ota_display_popup(
            GRP_ID_STREAMING_OTA_REPLACE_LIST, 
            (U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),
            MMI_EVENT_FAILURE);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_install_yes
 * DESCRIPTION
 *  Select overwrite one existing profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_install_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 install_index = g_streaming_p ->highlight_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_INSTALL_YES);
    if (mmi_media_is_profile_in_use(install_index))
    {
        //mmi_display_popup((UI_string_type) GetString(STR_ID_CCA_PROFILE_IN_USE), MMI_EVENT_FAILURE);
            mmi_streaming_ota_display_popup(
                SCR_ID_STREAMING_OTA_REPLACE_LIST, 
                (UI_string_type) GetString(STR_ID_CCA_PROFILE_IN_USE), 
                MMI_EVENT_FAILURE
            );
        return;
    }

    memcpy(g_streaming_p ->profile[g_streaming_p ->cur_index].provurl, g_streaming_p ->provurl, CCA_HASH_VALUE_MAX_BYTES);
    mmi_ucs2cpy((CHAR*) g_streaming_p ->old_unique[install_index].prof_name, 
                (CHAR*) g_streaming_p ->profile[g_streaming_p ->cur_index].profile_name);
    
    mmi_media_store_profile(install_index, &g_streaming_p ->profile[g_streaming_p ->cur_index]);
    if (!g_streaming_p ->is_installed && !g_streaming_p ->is_updated)
    {
        mmi_media_set_active_profile(install_index);        
    }
    g_streaming_p ->is_installed = MMI_TRUE;
    
    if (mmi_streaming_ota_get_next(g_streaming_p ->cur_index))
    {
        mmi_streaming_ota_enter_installation();
        if (mmi_frm_group_is_present(GRP_ID_STREAMING_OTA_REPLACE_LIST))
        {
            mmi_frm_group_close(GRP_ID_STREAMING_OTA_REPLACE_LIST);   
        }
        //DeleteScreenIfPresent(SCR_ID_STREAMING_OTA_REPLACE_LIST);
    }
    else
    {
        mmi_streaming_ota_install_result();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_prof_use
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_prof_use(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_PROF_IN_USE);
    if (mmi_streaming_ota_get_next(g_streaming_p ->cur_index))
    {
        mmi_streaming_ota_enter_installation();
    }
    else
    {
        mmi_streaming_ota_install_done(CCA_STATUS_SETTING_SKIPPED);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_install
 * DESCRIPTION
 *  Install OTA setting, first we need to judge whether OTA parameters are valid.
 *  If there is free proflie slot, we install automatically, otherwise come to
 *  profile select screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 install_index = -1;
    MMI_ID ret_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_INSTALL);
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    MMI_ASSERT(g_streaming_p ->cur_index < INVALID_STREAMING_PROFILE_INDEX);
    install_index = g_streaming_p ->update_index[g_streaming_p ->cur_index];
    if (install_index != INVALID_STREAMING_PROFILE_INDEX)
    {
        if (mmi_media_is_profile_in_use(install_index))
        {
            //mmi_display_popup((UI_string_type) GetString(STR_ID_CCA_PROFILE_IN_USE), MMI_EVENT_FAILURE);            
            mmi_streaming_ota_display_popup(
                GRP_ID_STREAMING_OTA_INSTALLATION, 
                (UI_string_type) GetString(STR_ID_CCA_PROFILE_IN_USE), 
                MMI_EVENT_FAILURE
            );
            mmi_streaming_ota_prof_use();
            return;
        }
        memcpy(g_streaming_p ->profile[g_streaming_p ->cur_index].provurl, g_streaming_p ->provurl, CCA_HASH_VALUE_MAX_BYTES);
        mmi_ucs2cpy((CHAR*) g_streaming_p ->old_unique[install_index].prof_name, 
                (CHAR*) g_streaming_p ->profile[g_streaming_p ->cur_index].profile_name);        
        
        mmi_media_store_profile(install_index, &g_streaming_p ->profile[g_streaming_p ->cur_index]);
        if (!g_streaming_p ->is_installed && !g_streaming_p ->is_updated)
        {            
            mmi_media_set_active_profile(install_index);            
        }
        g_streaming_p ->is_updated = MMI_TRUE;
        if (mmi_streaming_ota_get_next(g_streaming_p ->cur_index))
        {
            mmi_streaming_ota_enter_installation();
        }
        else
        {
            mmi_streaming_ota_install_result();
        }
        return;
    }
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */ 

    for (i = 0; i < MAX_STREAMING_PROFILE_NUM; i++)
    {
        if (g_streaming_p ->is_empty[i] == MMI_TRUE)
        {
            install_index = i;
            g_streaming_p ->is_empty[i] = MMI_FALSE;
            break;
        }
    }

    if (i == MAX_STREAMING_PROFILE_NUM)
    {
        ret_id = mmi_streaming_ota_enter_grp_replace_list();
        if (!ret_id)
        {
            return;
        }
        mmi_streaming_ota_enter_prof_list();
        return;
    }
    memcpy(g_streaming_p ->profile[g_streaming_p ->cur_index].provurl, g_streaming_p ->provurl, CCA_HASH_VALUE_MAX_BYTES);
    mmi_ucs2cpy((CHAR*) g_streaming_p ->old_unique[install_index].prof_name, 
                (CHAR*) g_streaming_p ->profile[g_streaming_p ->cur_index].profile_name);    
    
    mmi_media_store_profile(install_index, &g_streaming_p ->profile[g_streaming_p ->cur_index]);
    if (!g_streaming_p ->is_installed && !g_streaming_p ->is_updated)
    {        
        mmi_media_set_active_profile(install_index);        
    } 
    g_streaming_p ->is_installed = MMI_TRUE;
    if (mmi_streaming_ota_get_next(g_streaming_p ->cur_index))
    {
        mmi_streaming_ota_enter_installation();
    }
    else
    {
        mmi_streaming_ota_install_result();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_get_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_streaming_ota_get_next(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_GET_NEXT);
    MMI_ASSERT(index <= INVALID_STREAMING_PROFILE_INDEX);

    if (index == INVALID_STREAMING_PROFILE_INDEX)
    {
        index = 0;
    }
    else
    {
        index++;
    }
    while (index < MAX_STREAMING_PROFILE_NUM)
    {
        if (g_streaming_p ->is_done[index] == MMI_TRUE)
        {
            g_streaming_p ->cur_index = index;
            return MMI_TRUE;
        }

        index++;
    }

    g_streaming_p ->cur_index = INVALID_STREAMING_PROFILE_INDEX;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_skip_confirm
 * DESCRIPTION
 *  Call CCA function to show whether skip installing current OTA profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_skip_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_common_cancel_with_sg(GRP_ID_STREAMING_OTA_INSTALLATION, (U16) STR_ID_CCA_SKIP_PROFILE, mmi_streaming_ota_skip_yes);
    //mmi_cca_ui_common_cancel((U16) STR_ID_CCA_SKIP_PROFILE, mmi_streaming_ota_skip_yes);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_skip_yes
 * DESCRIPTION
 *  Skip installing current OTA profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_skip_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_streaming_p ->is_skipped = MMI_TRUE;
    if (mmi_streaming_ota_get_next(g_streaming_p ->cur_index))
    {
        mmi_streaming_ota_enter_installation();
    }
    else
    {
        if (g_streaming_p ->is_updated)
        {
            mmi_streaming_ota_install_done(CCA_STATUS_SETTING_UPDATED);
        }
        else if (g_streaming_p ->is_installed)
        {
            mmi_streaming_ota_install_done(CCA_STATUS_OK);
        }
        else
        {
            mmi_streaming_ota_install_done(CCA_STATUS_SETTING_SKIPPED);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_free_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_free_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_FREE_CONTEXT);
    MMI_ASSERT(g_streaming_p != NULL);

    OslMfree(g_streaming_p);
    g_streaming_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_streaming_ota_abort(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_ABORT);
    if (g_streaming_p == NULL)
    {
        return MMI_TRUE;
    }        
    
    /* Terminated. Send a response back to CCA and free memory. */
	if (g_streaming_p ->is_updated)
    {
        mmi_streaming_ota_send_cca_conf_rsp(CCA_STATUS_ENDKEY_SETTING_UPDATED);
    }
    else if (g_streaming_p ->is_installed)
    {
        mmi_streaming_ota_send_cca_conf_rsp(CCA_STATUS_ENDKEY_SETTING_INSTALLED);
    }
    else if (g_streaming_p ->is_skipped)
    {
        mmi_streaming_ota_send_cca_conf_rsp(CCA_STATUS_ENDKEY_SETTING_SKIPPED);
    }
	else
    {
        mmi_streaming_ota_send_cca_conf_rsp(CCA_STATUS_ENDKEY_PRESSED);
	}

    mmi_streaming_ota_free_context();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_install_done
 * DESCRIPTION
 *  This function used to judge which status will be send to CCA.
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_install_done(cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 curr_scr = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_STREAMING_OTA_INSTALL_DONE);


    g_streaming_p->need_send_abort = 0;
    mmi_frm_group_close(GRP_ID_STREAMING_OTA_REPLACE_LIST);    
    mmi_frm_group_close(GRP_ID_STREAMING_OTA_INSTALLATION);

    mmi_streaming_ota_send_cca_conf_rsp(status);
    mmi_streaming_ota_free_context();    
    //ClearDelScrnIDCallbackHandler(SCR_ID_STREAMING_OTA_INSTALLATION, NULL);
    //DeleteScreenIfPresent(SCR_ID_STREAMING_OTA_INSTALLATION);
    //DeleteScreenIfPresent(SCR_ID_STREAMING_OTA_REPLACE_LIST);

#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_install_result
 * DESCRIPTION
 *  This function used to judge which status will be send to CCA.
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_install_result(void)
{
        if (g_streaming_p ->is_updated)
        {
            mmi_streaming_ota_install_done(CCA_STATUS_SETTING_UPDATED);
        }
        else if (g_streaming_p ->is_installed)
        {
            mmi_streaming_ota_install_done(CCA_STATUS_OK);
        }
        else
        {
            mmi_streaming_ota_install_done(CCA_STATUS_SETTING_SKIPPED);
        }
}

#define MMI_STREAMING_OTA_UTIL


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_is_profile_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_streaming_ota_is_profile_valid(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    streaming_profile_nvram_struct *prof = &g_streaming_p ->profile[index];
    srv_dtcnt_sim_type_enum sim_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     mmi_streaming_simid_to_simtype(g_streaming_p->sim_id, &sim_type);
    if (prof->data_account_id[sim_type - SRV_DTCNT_SIM_TYPE_1] == MMI_DTCNT_INVALID_ID)
    {
        return MMI_FALSE;
    }
    if (mmi_streaming_ota_is_use_proxy(&prof->proxy_addr[0]))
    {
        prof->proxy_on_off = MMI_TRUE;
        if (prof->proxy_port < 0 || prof->proxy_port > DEFAULT_MAX_UDP_PORT)
        {
            return MMI_FALSE;
        }
    }
    else
    {
        prof->proxy_on_off = MMI_FALSE;
        prof->proxy_port = 0;
        prof->lowest_udp_port = DEFAULT_MIN_UDP_PORT;
        prof->highest_udp_port = DEFAULT_MAX_UDP_PORT;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_get_total_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_streaming_ota_get_total_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 total;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total = 0;
    for (i = 0; i < MAX_STREAMING_PROFILE_NUM; i++)
    {
        if (g_streaming_p ->is_done[i] == MMI_TRUE)
        {
            total++;
        }
    }

    return total;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_get_proxy_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  px_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_streaming_ota_get_proxy_index(U8 *px_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_STREAMING_PROFILE_NUM; i++)
    {
        if (g_streaming_p ->is_used[i] == STREAMING_PROFILE_EMPTY)
        {
            continue;
        }

        if (mmi_streaming_compare_hash_value((U8 *)g_streaming_p ->profile[i].proxy_id, (U8 *)px_id))
        {
            return i;
        }
    }

    return INVALID_STREAMING_PROFILE_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_get_empty_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_streaming_ota_get_empty_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_STREAMING_PROFILE_NUM; i++)
    {
        if (g_streaming_p ->is_used[i] == STREAMING_PROFILE_EMPTY)
        {
            return (U8) i;
        }
    }

    return INVALID_STREAMING_PROFILE_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_set_profile_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_ota_set_profile_status(U8 index, U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_streaming_p ->is_used[index] = status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_is_use_proxy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ip      [?]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_streaming_ota_is_use_proxy(U8 *ip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    CHAR temp[] = "0.0.0.0"; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: proxy on off: %s, line: %d", (CHAR*)ip, __LINE__);
    if (!strcmp(ip, temp))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

#define MMI_STREAMING_UTIL


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_is_ascii_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  utf8_str        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_streaming_is_ascii_string(const U8 *utf8_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*utf8_str != '\0')
    {
        if (*utf8_str > 0x7F)
        {
            return MMI_FALSE;
        }
        ++utf8_str;
    }

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_compare_hash_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p1      [IN]        
 *  p2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_streaming_compare_hash_value(const U8 *p1, const U8 *p2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(p1 != NULL && p2 != NULL);

    for (i = 0; i < CCA_HASH_VALUE_MAX_BYTES; i++)
    {
        if (p1[i] != 0 || p2[i] != 0)
        {
            break;
        }
    }

    /* p1 and p2 has empty hash value, do not update */
    if (i == CCA_HASH_VALUE_MAX_BYTES)
    {
        return MMI_FALSE;
    }

    if (memcmp(p1, p2, CCA_HASH_VALUE_MAX_BYTES) == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_steaming_ota_is_empty_hash
 * DESCRIPTION
 *  Judge whether it is valid hash
 * PARAMETERS
 *  data        [IN]        Source data
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_streaming_ota_is_empty_hash(const CHAR *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CCA_HASH_VALUE_MAX_BYTES; i++)
    {
        if (data[i] != 0)
        {
            break;
        }
    }

    if (i == CCA_HASH_VALUE_MAX_BYTES)
    {
        return MMI_TRUE;
    }

	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_parse_ip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ip          [?]         
 *  data        [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/

static MMI_BOOL mmi_streaming_validate_ip(U8 *ip, CHAR *data, S32 len)
{
	    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dot_no = 0;
     S32 i = 0;

	 /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (data == NULL || len < 7 || len > 15) /* min size: 0.0.0.0  max size: 255.255.255.255*/
    {
        return MMI_FALSE;
    }

    if (data[0] == '.' || data[len - 1] == '.')
    {
        return MMI_FALSE;
    }
 
    for (i = 0; i < len; i++)
    {
        if (data[i] == '.')
        {
            dot_no++;
 
            if ((i < len - 1) && (data[i + 1] == '.'))
            {
                return MMI_FALSE;
            }
        }
        else
        {
            if (data[i] < '0' || data[i] > '9')
            { 
		return MMI_FALSE;
            }
        }
    }
    if (dot_no != 3)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_parse_ip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ip          [?]         
 *  data        [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_streaming_parse_ip(U8 *ip, CHAR *data, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_streaming_validate_ip(ip,data,len))
    {
        strcpy((CHAR*)ip, data);
    }
    else
    {
        kal_sprintf((CHAR*)ip,  "0.0.0.0");
    }
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_dm_get_profile
 * DESCRIPTION
 *  dm get profile message handling function
 * PARAMETERS
 * msg          [in]msg struct   point      
 *        
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_streaming_simid_to_simtype(U32 sim_id, srv_dtcnt_sim_type_enum* sim_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(sim_id)
    {
    #if MMI_MAX_SIM_NUM > 3
        case MMI_SIM4:
            *sim_type = SRV_DTCNT_SIM_TYPE_4;
            break;
    #endif
    #if MMI_MAX_SIM_NUM > 2
        case MMI_SIM3:
            *sim_type = SRV_DTCNT_SIM_TYPE_3;
            break;
    #endif
    #if MMI_MAX_SIM_NUM > 1
        case MMI_SIM2:
            *sim_type = SRV_DTCNT_SIM_TYPE_2;
            break;
    #endif
        default:
            *sim_type = SRV_DTCNT_SIM_TYPE_1;
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_simid_to_cbmid
 * DESCRIPTION
 *  dm get profile message handling function
 * PARAMETERS
 * msg          [in]msg struct   point      
 *        
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_streaming_simid_to_cbmid(U32 sim_id, srv_dtcnt_sim_type_enum* cbm_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(sim_id)
    {
    #if(MMI_SIM_TOTAL > 3)
        case MMI_SIM4:
            *cbm_sim_id = CBM_SIM_ID_SIM4;
            break;
    #endif

    #if(MMI_SIM_TOTAL > 2)
        case MMI_SIM3:
            *cbm_sim_id = CBM_SIM_ID_SIM3;
            break;
    #endif

    #if(MMI_SIM_TOTAL > 1)
        case MMI_SIM2:
            *cbm_sim_id = CBM_SIM_ID_SIM2;
            break;
    #endif

        default:
            *cbm_sim_id = CBM_SIM_ID_SIM1;
            break;
    }
}



#ifdef MMI_STREAMING_DM_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_dm_get_profile
 * DESCRIPTION
 *  dm get profile message handling function
 * PARAMETERS
 * msg          [in]msg struct   point      
 *        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_streaming_dm_get_profile(srv_cca_app_get_prof_ind_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_streaming_dm_create_content(msg, MMI_STREAMING_DM_GET);
	mmi_media_load_profile((U8)g_streaming_dm_ptr->prof_id, &g_streaming_dm_ptr ->profile);
	mmi_streaming_dm_construct_cca_doc();
	mmi_streaming_dm_send_response(MMI_STREAMING_DM_GET);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_dm_update_profile
 * DESCRIPTION
 *  dm update profile message handling function
 * PARAMETERS
 * msg          [in]msg struct   point      
 *        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_streaming_dm_update_profile(srv_cca_app_update_prof_ind_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_streaming_dm_create_content(msg, MMI_STREAMING_DM_UPDATE);

	mmi_media_load_profile((U8)g_streaming_dm_ptr->prof_id, &g_streaming_dm_ptr ->profile);
	
	mmi_streaming_dm_parse_cca_doc();
	if(g_streaming_dm_ptr->result == CCA_STATUS_OK)
	{
	    mmi_media_store_profile((U8)g_streaming_dm_ptr->prof_id, &g_streaming_dm_ptr ->profile);
	}
	else
	{
	    MMI_STREAM_OTAP_ERROR_TRACE(g_streaming_dm_ptr->result);
	}

    mmi_media_set_active_profile((U8)g_streaming_dm_ptr->prof_id);
	mmi_streaming_dm_send_response(MMI_STREAMING_DM_UPDATE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_dm_create_content
 * DESCRIPTION
 *  create context for streaming dm
 * PARAMETERS
 * msg               [in]msg struct   point      
 * msg_type     [in]msg type 
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_streaming_dm_create_content(void *msg, mmi_streaming_massage_type msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_get_prof_ind_struct* get_data;
	mmi_cca_app_update_prof_ind_struct* update_data;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_streaming_dm_ptr = (mmi_streaming_dm_content*)OslMalloc(sizeof(mmi_streaming_dm_content));
	MMI_ASSERT( g_streaming_dm_ptr != NULL);
	
    switch(msg_type)
    {
        case MMI_STREAMING_DM_GET:
		{
			get_data = (mmi_cca_app_get_prof_ind_struct*)msg;
			g_streaming_dm_ptr->app_id  = get_data->app_id;
			g_streaming_dm_ptr->prof_id = mmi_media_get_active_profile();
			g_streaming_dm_ptr->sim_id  = get_data->sim_id;
			g_streaming_dm_ptr->result  = CCA_STATUS_OK;
			break;
		}
		case MMI_STREAMING_DM_UPDATE:
		{
			update_data = (mmi_cca_app_update_prof_ind_struct*)msg;
			g_streaming_dm_ptr->app_id  = update_data->app_id;
			g_streaming_dm_ptr->prof_id = 0;
			g_streaming_dm_ptr->sim_id  = update_data->sim_id;
			g_streaming_dm_ptr->hConfig = update_data->hConfig;
			g_streaming_dm_ptr->result  = CCA_STATUS_OK;
			break;
		}
		default:
		{
			MMI_ASSERT(0);
		}
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_dm_construct_cca_doc
 * DESCRIPTION
 *  contruct cca doc
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_streaming_dm_construct_cca_doc()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hroot, hnode, tempnode;
	CHAR ip_addr_str[MMI_STREAMING_PROFILE_IP_LEN];
	CHAR port_str[STREAMING_PROFILE_PORT_LEN];
	CHAR temp[MAX_STREAMING_PROFILE_NAME_SIZE * ENCODING_LENGTH];
	CHAR apn_ucs[SRV_DTCNT_PROF_MAX_APN_LEN * 2]; 
	CHAR apn_char[SRV_DTCNT_PROF_MAX_APN_LEN * 2];
    cca_status_enum ret;
	srv_dtcnt_prof_str_info_qry_struct acct_data;
    U32 acc_id;
	srv_dtcnt_sim_type_enum sim_type;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
	
    mmi_streaming_general_ip(g_streaming_dm_ptr->profile.proxy_addr, ip_addr_str);
    kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: ip_addr_str: %s, line:%d", ip_addr_str, __LINE__);
	ret = mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PXADDR, (CHAR*)ip_addr_str);
	MMI_STREAM_OTAP_MASSAGE_TRACE(ret);
	
	ret = mmi_cca_doc_add_nodedata_int (hnode, CCA_NS_OMA_PXADDRTYPE, CCA_NS_VAL_IPV4);
	MMI_STREAM_OTAP_MASSAGE_TRACE(ret);

    mmi_streaming_dm_reg_temp_app_id();
	mmi_streaming_simid_to_simtype(g_streaming_dm_ptr->sim_id, &sim_type);
	
    acc_id = cbm_set_app_id(g_streaming_dm_ptr->profile.data_account_id[sim_type - SRV_DTCNT_SIM_TYPE_1],g_streaming_dm_ptr->cbm_app_id);
    kal_mem_set(apn_ucs, 0, SRV_DTCNT_PROF_MAX_APN_LEN * 2);
    acct_data.dest = (CHAR*)apn_ucs;
    acct_data.dest_len = MAX_GPRS_MMI_APN_LEN * 2;
    acct_data.req_len = MAX_GPRS_MMI_APN_LEN * 2;
    MMI_STREAM_OTAP_MASSAGE_TRACE(acc_id);
    srv_dtcnt_get_apn(acc_id, &acct_data, SRV_DTCNT_ACCOUNT_PRIMARY);
	mmi_ucs2_to_asc(apn_char, apn_ucs);
    kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: apn_char: %s, line:%d", apn_char, __LINE__);
	ret = mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_NAPID, apn_char);
    mmi_streaming_dm_dereg_temp_app_id();
    MMI_STREAM_OTAP_MASSAGE_TRACE(ret);
	
	tempnode = hnode;
    hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_PORT, tempnode);

	mmi_streaming_general_port(g_streaming_dm_ptr->profile.proxy_port, port_str,STREAMING_PROFILE_PORT_LEN);
	kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: port_str: %s, line:%d", port_str, __LINE__);
	ret = mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_PORTNBR, (CHAR*)port_str);
	MMI_STREAM_OTAP_MASSAGE_TRACE(ret);

	hnode = mmi_cca_doc_new_node_and_attach (CCA_NS_OMA_APPLICATION, hroot);
    if (!hnode)
    {
        mmi_cca_docroot_release (hroot); 
        MMI_ASSERT(0);
    }

    mmi_chset_ucs2_to_utf8_string((U8*) temp,                        
		MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH, 
		(U8*)g_streaming_dm_ptr->profile.profile_name);
	
	mmi_cca_doc_add_nodedata_str (hnode,CCA_NS_OMA_NAME ,(CHAR*)temp);
	
    mmi_streaming_general_port(g_streaming_dm_ptr->profile.lowest_udp_port, port_str,STREAMING_PROFILE_PORT_LEN);
    kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: lowest_udp_port: %s, line:%d", port_str, __LINE__);
	ret = mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_MIN_UDP_PORT, (CHAR*)port_str);
	MMI_STREAM_OTAP_MASSAGE_TRACE(ret);

    mmi_streaming_general_port(g_streaming_dm_ptr->profile.highest_udp_port, port_str,STREAMING_PROFILE_PORT_LEN);
    kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: highest_udp_port: %s, line:%d", port_str, __LINE__);
	ret = mmi_cca_doc_add_nodedata_str (hnode, CCA_NS_OMA_MAX_UDP_PORT, (CHAR*)port_str);	
	MMI_STREAM_OTAP_MASSAGE_TRACE(ret);

	g_streaming_dm_ptr->hConfig = mmi_cca_doc_new (hroot);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_dm_parse_cca_doc
 * DESCRIPTION
 *  parse cca doc
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_streaming_dm_parse_cca_doc()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_doc_process(
        g_streaming_dm_ptr->hConfig,
        cca_mapping_streaming,
        sizeof(cca_mapping_streaming) / sizeof(U16),
        NULL,
        mmi_streaming_dm_process_callback_nodes,
        NULL);

    mmi_streaming_dm_profile_validation();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_dm_send_response
 * DESCRIPTION
 *  send response message to cca
 * PARAMETERS
 * msg_type       [IN] massage type
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_streaming_dm_send_response(mmi_streaming_massage_type msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_get_prof_rsp_struct* get_data;
	mmi_cca_app_update_prof_rsp_struct* update_data;
	MYQUEUE ilm;
    
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_STREAM_OTAP_MASSAGE_TRACE(g_streaming_dm_ptr->result);
    switch(msg_type)
    {
        case MMI_STREAMING_DM_GET:
		{	
            get_data = (mmi_cca_app_get_prof_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_get_prof_rsp_struct));
            MMI_ASSERT(get_data != NULL);
				
            get_data->sim_id    = g_streaming_dm_ptr->sim_id;
			get_data->app_id    = g_streaming_dm_ptr->app_id;
			get_data->prof_id   = g_streaming_dm_ptr->prof_id;
            get_data->hConfig   = g_streaming_dm_ptr->hConfig;
            get_data->result    = g_streaming_dm_ptr->result;

	        ilm.oslSrcId        = MOD_MMI;
            ilm.oslDestId       = MOD_MMI;
            ilm.oslMsgId        = MSG_ID_MMI_CCA_APP_GET_PROF_RSP;
            ilm.oslDataPtr      = (oslParaType*)get_data;
            ilm.oslPeerBuffPtr  = NULL;
            OslMsgSendExtQueue(&ilm);	
			break;
		}
		case MMI_STREAMING_DM_UPDATE:
		{	
            update_data = (mmi_cca_app_update_prof_rsp_struct*)OslConstructDataPtr(sizeof(mmi_cca_app_update_prof_rsp_struct));
			MMI_ASSERT(update_data != NULL);

            update_data->sim_id    = g_streaming_dm_ptr->sim_id;
			update_data->app_id    = g_streaming_dm_ptr->app_id;
			update_data->prof_id   = g_streaming_dm_ptr->prof_id;
            update_data->hConfig   = g_streaming_dm_ptr->hConfig;
            update_data->result    = g_streaming_dm_ptr->result;

            ilm.oslSrcId         = MOD_MMI;
            ilm.oslDestId        = MOD_MMI;
            ilm.oslMsgId         = MSG_ID_MMI_CCA_APP_UPDATE_PROF_RSP;
            ilm.oslDataPtr       = (oslParaType*)update_data;
            ilm.oslPeerBuffPtr   = NULL;
            OslMsgSendExtQueue(&ilm);	        
			break;
		}
		default:
		{
			MMI_ASSERT(0);
			break;
		}			
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_dm_process_callback_nodes
 * DESCRIPTION
 *    doc process callback
 * PARAMETERS
 *  hConfig             [IN]        
 *  hNode               [IN]        
 *  node_symbol         [IN]        
 *  iter_datalist       [?]         
 *  user_data           [?]         
 * RETURNS
 *  
 *****************************************************************************/
static cca_status_enum mmi_streaming_dm_process_callback_nodes(
                        S32 hConfig,
                        S32 hNode,
                        U16 node_symbol,
                        cca_iterator_struct *iter_datalist,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_streaming_dm_ptr == NULL)
    {
        return CCA_STATUS_OK;
    }
    
    switch (node_symbol)
    {
         case MMI_STREAMING_NS_OMA_PROXY:
		 	MMI_STREAM_OTAP_MASSAGE_TRACE(g_streaming_dm_ptr->result);
            g_streaming_dm_ptr->result = mmi_streaming_dm_parse_proxy(iter_datalist, user_data);
            break;

        case MMI_STREAMING_NS_OMA_PORT:
			MMI_STREAM_OTAP_MASSAGE_TRACE(g_streaming_dm_ptr->result);
            g_streaming_dm_ptr->result = mmi_streaming_dm_parse_port(hNode, user_data);
            break;

        case MMI_STREAMING_NS_OMA_APP:
			MMI_STREAM_OTAP_MASSAGE_TRACE(g_streaming_dm_ptr->result);
            g_streaming_dm_ptr->result = mmi_streaming_dm_parse_app(iter_datalist, user_data);
            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_parse_proxy
 * DESCRIPTION
 *   parse proxy node
 * PARAMETERS
 *  iter_datalist       [IN]     
 *  user_data           [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static cca_status_enum mmi_streaming_dm_parse_proxy(cca_iterator_struct *iter_datalist, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data;
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_streaming_dm_ptr->result != CCA_STATUS_OK)
    {
        return g_streaming_dm_ptr->result;
    }
	
    mmi_cca_iterator_restart(iter_datalist);
    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {
        status = mmi_streaming_dm_handle_proxy_params(data, user_data);
        if (status != CCA_STATUS_OK)
        {
            return status;
        }
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_dm_handle_proxy_params
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [IN]     
 *  user_data       [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static cca_status_enum mmi_streaming_dm_handle_proxy_params(cca_core_data_struct *data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    streaming_profile_nvram_struct *prof;
	srv_dtcnt_prof_gprs_struct ProfSrv;
    srv_dtcnt_store_prof_data_struct profInfo;
	srv_dtcnt_bearer_enum bear;
    srv_dtcnt_result_enum result;
    cbm_account_info_struct acct_info;
    cbm_sim_id_enum sim_id;
    U32 acc_id;
	srv_dtcnt_sim_type_enum sim_type;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof = &g_streaming_dm_ptr ->profile;

    switch (data->id)
    {
        case CCA_NS_OMA_PROXY_ID:
            /* Whether the value is presented and the type is legal. */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                MMI_STREAM_OTAP_ERROR_TRACE(data->type);
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (!mmi_streaming_is_ascii_string((U8*) data->values.s[0]))
            {
                MMI_STREAM_OTAP_ERROR_TRACE(0);
                return CCA_STATUS_FAIL;
            }
			
			kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: proxy_id: %s, line:%d", data->values.s[0], __LINE__);
            mmi_cca_generate_hash_value((CHAR*) data->values.s[0], (U8*) prof->proxy_id, CCA_HASH_VALUE_MAX_BYTES);
            
            break;

        case CCA_NS_OMA_PXADDR:
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                MMI_STREAM_OTAP_ERROR_TRACE(data->type);
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (!mmi_streaming_is_ascii_string((U8*) data->values.s[0]))
            {
                MMI_STREAM_OTAP_ERROR_TRACE(0);
                return CCA_STATUS_FAIL;
            }

            str_len = strlen(data->values.s[0]);
			kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: proxy_addr: %s, line:%d", data->values.s[0], __LINE__);
            if (!mmi_streaming_parse_ip((U8*) & prof->proxy_addr[0], data->values.s[0], str_len))
            {
                MMI_STREAM_OTAP_ERROR_TRACE(str_len);
                return CCA_STATUS_FAIL;
            }
			
            MMI_STREAM_OTAP_MASSAGE_TRACE(prof->proxy_addr[0]);
            if (mmi_streaming_ota_is_use_proxy((U8*) & prof->proxy_addr[0]))
            {
                prof->proxy_on_off = MMI_TRUE;
            }
            else
            {
                prof->proxy_on_off = MMI_FALSE;
            }
            break;

        case CCA_NS_OMA_NAPID:
            kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]parse napid begin, line:%d", __LINE__);
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                MMI_STREAM_OTAP_ERROR_TRACE(data->size);
                MMI_STREAM_OTAP_ERROR_TRACE(data->type);
                return CCA_STATUS_FAIL;
            }

            if (!mmi_streaming_is_ascii_string((U8*) data->values.s[0]))
            {
                MMI_STREAM_OTAP_ERROR_TRACE(2);
                return CCA_STATUS_FAIL;
            }

            mmi_streaming_dm_reg_temp_app_id();
            mmi_streaming_simid_to_simtype(g_streaming_dm_ptr->sim_id, &sim_type);
            
            mmi_streaming_simid_to_cbmid(g_streaming_dm_ptr->sim_id, &sim_id);
            
            prof->data_account_id[sim_type - SRV_DTCNT_SIM_TYPE_1] = cbm_encode_data_account_id(
                                        CBM_DEFAULT_ACCT_ID,
                                        sim_id,
                                        0,
                                        KAL_FALSE);
            acc_id = cbm_set_app_id(prof->data_account_id[sim_type - SRV_DTCNT_SIM_TYPE_1], g_streaming_dm_ptr->cbm_app_id);
            srv_dtcnt_get_auto_acc_id(acc_id, &acc_id);
			cbm_decode_data_account_id_ext(acc_id, &acct_info);
			kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: napid: %s, line:%d", data->values.s[0], __LINE__);
			bear = srv_dtcnt_get_bearer_type(acc_id, SRV_DTCNT_ACCOUNT_PRIMARY);
			if(SRV_DTCNT_BEARER_GPRS != bear)
			{
			    MMI_STREAM_OTAP_ERROR_TRACE(bear);
			    return CCA_STATUS_FAIL;
			}
			
			profInfo.prof_type = SRV_DTCNT_BEARER_GPRS;
            profInfo.prof_data = &ProfSrv;
            profInfo.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
    
            result = srv_dtcnt_store_qry_prof(acct_info.account[0].account_id, &profInfo);

			ProfSrv.APN = (CHAR*) data->values.s[0];
            profInfo.prof_fields |= SRV_DTCNT_PROF_FIELD_READONLY;
			
            result = srv_dtcnt_store_update_prof(acct_info.account[0].account_id, &profInfo);
            if(SRV_DTCNT_RESULT_SUCCESS != result)
            {
                MMI_STREAM_OTAP_ERROR_TRACE(result);
                return CCA_STATUS_FAIL;
            }
			MMI_STREAM_OTAP_MASSAGE_TRACE(prof->data_account_id[sim_type - SRV_DTCNT_SIM_TYPE_1]);
            mmi_streaming_dm_dereg_temp_app_id();
            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_dm_parse_port
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hNode           [IN]        
 *  user_data       [IN]         
 * RETURNS
 *  
 *****************************************************************************/
static cca_status_enum mmi_streaming_dm_parse_port(S32 hNode, void *user_data)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status = CCA_STATUS_OK;
    CHAR *str_port = NULL;
    streaming_profile_nvram_struct *prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_streaming_dm_ptr->result != CCA_STATUS_OK)
    {
        return g_streaming_dm_ptr->result;
    }
	
    prof = &g_streaming_dm_ptr ->profile;

    status = mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_PORTNBR, &str_port);
    if (status != CCA_STATUS_OK)
    {
        return CCA_STATUS_FAIL;
    }
    if (str_port == NULL)
    {
        return CCA_STATUS_FAIL;
    }
	kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: str_port: %s, line:%d", str_port, __LINE__);
    status = mmi_streaming_ota_check_port(str_port, &prof->proxy_port);
	MMI_STREAM_OTAP_MASSAGE_TRACE(prof->proxy_port);
    if (status != CCA_STATUS_OK)
    {
        return CCA_STATUS_FAIL;
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_handle_app_by_toproxy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  px_id               [IN]        
 *  iter_datalist       [IN]         
 *  user_data           [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static cca_status_enum mmi_streaming_dm_parse_app(cca_iterator_struct *iter_datalist, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data;
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_STREAM_OTAP_MASSAGE_TRACE(status);
    mmi_cca_iterator_restart(iter_datalist);
    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {
        status = mmi_streaming_dm_handle_app_param(data, user_data);
        if (status != CCA_STATUS_OK)
        {
            return status;
        }
    }
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_handle_app_param
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [IN]     
 *  user_data       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static cca_status_enum mmi_streaming_dm_handle_app_param(cca_core_data_struct *data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    streaming_profile_nvram_struct *prof;
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof = &g_streaming_dm_ptr ->profile;

    switch (data->id)
    {
        case CCA_NS_OMA_NAME:
            /* Whether the value is presented and the type is legal. If it's
               illegal, default name will be used. Still return OK. */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_OK;   /* Error-tolerant for profile's name */
            }

            /* Extract the profile's name. If the name is too long, it will be
               truncated by the function. */
            kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: appname: %s, line:%d", data->values.s[0], __LINE__);
            mmi_chset_utf8_to_ucs2_string(
                (U8*) prof->profile_name,
                MAX_STREAMING_PROFILE_NAME_SIZE,
                (U8*) data->values.s[0]);
            break;

        case CCA_NS_OMA_MIN_UDP_PORT:
            /* only consider the first value, skip the other value */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_OK;   /* Error-tolerant for UDP port */
            }
			
			kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: min_udp_port: %s, line:%d", data->values.s[0], __LINE__);
            status = mmi_streaming_ota_check_port(data->values.s[0], &prof->lowest_udp_port);
			MMI_STREAM_OTAP_MASSAGE_TRACE(prof->lowest_udp_port);
            if (status != CCA_STATUS_OK)
            {
                MMI_STREAM_OTAP_ERROR_TRACE(status);
                return CCA_STATUS_OK;   /* Error-tolerant for UDP port */
            }
            break;

        case CCA_NS_OMA_MAX_UDP_PORT:
            /* only consider the first value, skip the other value */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_OK;   /* Error-tolerant for UDP port */
            }

            kal_print_string_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Streaming][OTAP]: max_udp_port: %s, line:%d", data->values.s[0], __LINE__);
            status = mmi_streaming_ota_check_port(data->values.s[0], &prof->highest_udp_port);
			MMI_STREAM_OTAP_MASSAGE_TRACE(prof->highest_udp_port);
            if (status != CCA_STATUS_OK)
            {
                MMI_STREAM_OTAP_ERROR_TRACE(status);
                return CCA_STATUS_OK;   /* Error-tolerant for UDP port */
            }
            break;

        default:
            break;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_ota_profile_validation
 * DESCRIPTION
 *  at this case, all profiles are valid but some param (such as udp port) 
 *    is not valid.
 *  This function is to make udp port valid by using default value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_dm_profile_validation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    streaming_profile_nvram_struct *prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof = &g_streaming_dm_ptr ->profile;
    if (prof->lowest_udp_port < DEFAULT_MIN_UDP_PORT
        || prof->lowest_udp_port > DEFAULT_MAX_UDP_PORT - MMI_STREAMING_DM_UDP_PORT_DELTA)
    {
        prof->lowest_udp_port = DEFAULT_MIN_UDP_PORT;
    }

    if (prof->highest_udp_port < DEFAULT_MIN_UDP_PORT + MMI_STREAMING_DM_UDP_PORT_DELTA
        || prof->highest_udp_port > DEFAULT_MAX_UDP_PORT)
    {
        prof->highest_udp_port = DEFAULT_MAX_UDP_PORT;
    }

    if (prof->highest_udp_port - prof->lowest_udp_port < MMI_STREAMING_DM_UDP_PORT_DELTA)
    {
        prof->highest_udp_port = DEFAULT_MAX_UDP_PORT;
        prof->lowest_udp_port = DEFAULT_MIN_UDP_PORT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_dm_reg_temp_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_dm_reg_temp_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_app_info_struct app_info;
    kal_int8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&app_info, 0, sizeof(app_info));
    app_info.app_icon_id = 0;
    app_info.app_str_id = STR_ID_STREAMING;
    app_info.app_type = DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_SPECIFIC_PROFILE;
    ret = cbm_register_app_id_with_app_info(&app_info, &(g_streaming_dm_ptr->cbm_app_id));
    MMI_STREAM_OTAP_MASSAGE_TRACE(g_streaming_dm_ptr->cbm_app_id);
    MMI_STREAM_OTAP_MASSAGE_TRACE(ret);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_dm_reg_temp_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_streaming_dm_dereg_temp_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = cbm_deregister_app_id(g_streaming_dm_ptr->cbm_app_id);
    MMI_STREAM_OTAP_MASSAGE_TRACE(g_streaming_dm_ptr->cbm_app_id);
    MMI_STREAM_OTAP_MASSAGE_TRACE(ret);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_general_ip
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_streaming_general_ip(CHAR* ip, CHAR* ip_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(ip_str, ip);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_streaming_general_port
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_streaming_general_port(U32 port, CHAR* port_str, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(len<=STREAMING_PROFILE_PORT_LEN);
	kal_sprintf((char*)port_str,"%d", port);
}
#endif /* MMI_STREAMING_DM */
#endif /* __MMI_STREAMING_OTAP__ */ 

