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
 * ImpsAppOTA.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements chat history functions for IMPS application.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_IMPS_OTA__

#include "stdlib.h"
#include "string.h"

#include "stack_config.h"
#include "stack_msgs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "nvram_common_defs.h"
#include "app_url.h"
#include "app_ltlcom.h"

#include "GlobalConstants.h"
#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_rp_app_cca_def.h"
#include "wgui_categories_util.h"
#include "wgui_categories_text_viewer.h"

#include "CentralConfigAgentGProt.h"

#ifdef __MMI_BACKGROUND_CALL__
#include "UCMGprot.h"
#endif

#include "cbm_api.h"
#include "cbm_consts.h"
#include "DataAccountGProt.h"
#include "DtcntSrvGprot.h"
#include "Unicodexdcl.h"
#include "DebugInitDef_Int.h"
#include "CustDataRes.h"
#include "custom_data_account.h"
#include "CommonScreens.h"
#include "gui_fixed_menuitems.h"

#include "DtcntSrvIprot.h"


#include "mmi2imps_struct.h"
#include "ImpsSrvGprot.h"
#include "ImpsAppGprot.h"
#include "ImpsAppProt.h"
#include "mmi_rp_app_imps_def.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define IMPS_MAX_OTA_INFO_LEN       (512)  /* length of buffer for compose ota info */


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static const U16 cca_mapping_imps[] = 
{
    CCA_NS_TRIGNODE, CCA_NS_OMA_BOOTSTRAP, MMI_IMPS_NS_OMA_BOOTSTRAP, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, MMI_IMPS_NS_OMA_PROXY, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, MMI_IMPS_NS_OMA_APP, 0xFFFF,

    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPAUTH, MMI_IMPS_NS_OMA_APPAUTH, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPADDR, MMI_IMPS_NS_OMA_APPADDR, 0xFFFF,
};



/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_process_callback_nodes(
                        S32 hConfig,
                        S32 hNode,
                        U16 node_symbol,
                        cca_iterator_struct *iter_datalist,
                        void *user_data);
static cca_status_enum mmi_imps_ota_parse_proxy(cca_iterator_struct *data, void *user_data);
static cca_status_enum mmi_imps_ota_parse_app(cca_iterator_struct *data, void *user_data);

static cca_status_enum mmi_imps_ota_handle_proxy_params(cca_core_data_struct *data, void *user_data);
static cca_status_enum mmi_imps_ota_handle_app_params(cca_core_data_struct *iter_datalist, void *user_data);
static cca_status_enum mmi_imps_ota_handle_appaddr_params(S32 hNode, void *user_data);
static cca_status_enum mmi_imps_ota_handle_appauth_params(S32 hNode, void *user_data);

static MMI_ID mmi_imps_enter_ota_group(void);
static mmi_ret mmi_imps_ota_group_proc(mmi_event_struct *evt);
static void mmi_imps_entry_ota_setting(void);
static void mmi_imps_ota_install(void);
static void mmi_imps_ota_skip_confirm(void);
static void mmi_imps_ota_skip_yes(void);

static void mmi_imps_ota_create_app_info(MMI_BOOL is_proxy);
static void mmi_imps_ota_free_app_info(void);

#ifdef __MMI_OP11_IMPS__
/* under construction !*/
/* under construction !*/
#else 
static void mmi_imps_ota_free_prof(U8 index);
static void mmi_imps_ota_install_status(void);
#endif

static void mmi_imps_ota_is_valid_info(void);
static MMI_BOOL mmi_imps_is_ascii_string(const U8 *utf8_str);


static cca_status_enum mmi_imps_ota_parse_bootstrap(
                    cca_iterator_struct *iter_datalist,
                    void *user_data);
static MMI_BOOL mmi_imps_ota_is_empty_hash(const CHAR *data);


#ifndef __MMI_OP11_IMPS__
static S16 mmi_imps_ota_get_proxy_index(const CHAR *px_id);
static MMI_BOOL mmi_imps_ota_create_prof(MMI_BOOL is_proxy);
static MMI_BOOL mmi_imps_ota_is_valid_proxy(mmi_imps_ota_prof_struct *prof);
static void mmi_imps_pre_entry_ota_setting(void);
static void mmi_imps_ota_install_yes(void);
static MMI_BOOL mmi_imps_ota_get_next(void);
static U8 mmi_imps_ota_install_finished(void);
static mmi_ret mmi_imps_ota_abort_install(mmi_event_struct *evt);
#endif /* #ifndef __MMI_OP11_IMPS__ */


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_send_cca_conf_rsp
 * DESCRIPTION
 *  This function sends the response message back to CCA for the result of
 *  configuration. Once application sends this primitive, no further access
 *  to the configuration document should be made.
 * PARAMETERS
 *  status      [IN]        Configuration result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_send_cca_conf_rsp(cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_configure_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = OslConstructDataPtr(sizeof(mmi_cca_app_configure_rsp_struct));
    
    data->config_id = imps_p->ota_prof->config_id;
    data->hConfig = imps_p->ota_prof->hConfig;
    data->status = status;
    
    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_CONFIGURE_RSP, (oslParaType*)data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_handle_ota
 * DESCRIPTION
 *  handle CCA document
 * PARAMETERS
 *  config_id       [IN]        CCA configuration ID
 *  hConfig         [IN]        Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_handle_ota(U16 config_id, S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_doc_process(
        hConfig,
        cca_mapping_imps,
        sizeof(cca_mapping_imps) / sizeof(U16),
        NULL,
        mmi_imps_ota_process_callback_nodes,
        NULL);

    mmi_imps_ota_is_valid_info();
}


/*****************************************************************************
* FUNCTION
*  mmi_imps_enter_ota_group
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_ID mmi_imps_enter_ota_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    MMI_ID parent_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_IMPS_OTA))
    {
        mmi_frm_group_close(GRP_ID_IMPS_OTA);
    }

    parent_id = mmi_cca_get_root_group();
    
    return mmi_frm_group_create_ex(
        parent_id, 
        GRP_ID_IMPS_OTA, 
        mmi_imps_ota_group_proc, 
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
}


/*****************************************************************************
* FUNCTION
*  mmi_imps_ota_group_proc
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_imps_ota_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            break;   
 
        default:
            break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_init
 * DESCRIPTION
 *  Initialize OTA structure
 * PARAMETERS
 *  newConfigDoc       [IN]        CCA configure doc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ota_init(mmi_cca_app_configure_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 	
    MMI_ASSERT (imps_p->ota_prof == NULL);

    imps_p->ota_prof = (mmi_imps_ota_info_struct*) OslMalloc(sizeof(mmi_imps_ota_info_struct));
    memset(imps_p->ota_prof, 0, sizeof(mmi_imps_ota_info_struct));
    imps_p->ota_prof->config_id = newConfigDoc->config_id;
    imps_p->ota_prof->hConfig = newConfigDoc->hConfig;
    imps_p->ota_prof->sim_id = newConfigDoc->sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_abort_install
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_imps_ota_abort_install(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        {
            if (imps_p->ota_prof == NULL)
            {
                return MMI_RET_OK;
            }
#ifdef __MMI_OP11_IMPS__
/* under construction !*/
#else
            mmi_imps_ota_install_finished();
#endif
            return MMI_RET_ALLOW_CLOSE;
        }          
            
        default:
            break;
    }
    return MMI_RET_OK;
}


#ifdef __MMI_OP11_IMPS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP11_IMPS__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_process_callback_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  hConfig             [IN]        Configuration document handle
 *  hNode               [IN]        The node handle
 *  node_symbol         [IN]        The converted node symbol
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  result of processing CCA nodes.
 *  On success, return CCA_STATUS_OK;
 *  If there is no empty ota profile return CCA_STATUS_FAIL;
 *  Otherwise, return CCA_STATUS_FAIL.
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_process_callback_nodes(
                    S32 hConfig,
                    S32 hNode,
                    U16 node_symbol,
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i;
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (node_symbol)
    {
        case MMI_IMPS_NS_OMA_BOOTSTRAP:
            mmi_imps_ota_parse_bootstrap(iter_datalist, user_data);
            break;

        case MMI_IMPS_NS_OMA_PROXY:
            mmi_imps_ota_parse_proxy(iter_datalist, user_data);
            break;

        case MMI_IMPS_NS_OMA_APP:
            mmi_imps_ota_parse_app(iter_datalist, user_data);
            break;

        case MMI_IMPS_NS_OMA_APPADDR:
            status = mmi_imps_ota_handle_appaddr_params(hNode, user_data);
			if (status != CCA_STATUS_OK)
			{
				for (i = 0; i < IMPS_PROF_COUNT * 2; i++)
				{
					if (imps_p->ota_prof->app_prof_index[i])
					{
						imps_p->ota_prof->info[i]->is_valid = MMI_FALSE;
					}
				}
			}
            break;

        case MMI_IMPS_NS_OMA_APPAUTH:
            mmi_imps_ota_handle_appauth_params(hNode, user_data);			
            break;

        default: 
            break;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_parse_bootstrap
 * DESCRIPTION
 *  The function used to parse bootstrap node.
 * PARAMETERS
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  result of processing CCA nodes.
 *  On success, return CCA_STATUS_OK;
 *  Otherwise, return CCA_STATUS_FAIL.
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_parse_bootstrap(
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    cca_status_enum status = CCA_STATUS_OK;
    CHAR **provurl;
    S32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_cca_doc_get_nodedata_strs(iter_datalist, CCA_NS_OMA_PROVURL, &provurl, &size);

    /* one bootstap should only include one provurl or no provurl */
    if (status != CCA_STATUS_OK || size > 1 || provurl == NULL)
    {        
        return CCA_STATUS_FAIL;
    }

    mmi_cca_generate_hash_value((CHAR*)provurl[0], imps_p->ota_prof->provurl, 
        CCA_HASH_VALUE_MAX_BYTES);

    mmi_cca_iterator_restart(iter_datalist);
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_parse_proxy
 * DESCRIPTION
 *  The function used to parse proxy node.
 * PARAMETERS
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  result of processing CCA nodes.
 *  On success, return CCA_STATUS_OK;
 *  Otherwise, return CCA_STATUS_FAIL.
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_parse_proxy(
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data;
    cca_status_enum status = CCA_STATUS_OK;
    CHAR **px_id;
    S32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->ota_prof->is_curr_store = MMI_TRUE;

    status = mmi_cca_doc_get_nodedata_strs(iter_datalist, CCA_NS_OMA_PROXY_ID, &px_id, &size);

    /* one proxy should has only one prxoy id */
    if (status != CCA_STATUS_OK || size != 1 || px_id == NULL)
    {
        imps_p->ota_prof->is_curr_store = MMI_FALSE;
        return CCA_STATUS_FAIL;
    }
    /* judghe whether this proxy has existed for we only support the first valid proxy for same proxy id */
    if (mmi_imps_ota_get_proxy_index(px_id[0]) != IMPS_PROF_COUNT) 
    {
        imps_p->ota_prof->is_curr_store = MMI_FALSE;
        return CCA_STATUS_FAIL;
    }

    mmi_cca_iterator_restart(iter_datalist);

    if (mmi_imps_ota_create_prof(MMI_TRUE))
    {
        while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
        {
            if (data == NULL)
            {
                status = CCA_STATUS_FAIL;
                break;
            }
            status = mmi_imps_ota_handle_proxy_params(data, user_data);
            if (status != CCA_STATUS_OK)
            {
                break;
            }
        }

		if (status != CCA_STATUS_OK)
		{
			/* if current proxy node is invalid, set flag to not store its child node */
            imps_p->ota_prof->is_curr_store = MMI_FALSE;
            mmi_imps_ota_free_prof(imps_p->ota_prof->curr_index);
            return status;
		}

        /* it mainly used to judge proxy-id, if proxy-id is not ascii string, it is regard as */
        /* invalid proxy-id */
        if (!mmi_imps_ota_is_valid_proxy(imps_p->ota_prof->info[imps_p->ota_prof->curr_index]))
        {
            /* if current proxy node is invalid, set flag to not store its child node */
            imps_p->ota_prof->is_curr_store = MMI_FALSE;
            mmi_imps_ota_free_prof(imps_p->ota_prof->curr_index);
            return status;
        }
    }
    else
    {
        status = CCA_STATUS_MEMFULL;

        /* if profile memory full, set flag to not store its child node */
        imps_p->ota_prof->is_curr_store = MMI_FALSE;
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_handle_proxy_params
 * DESCRIPTION
 *  Handle CCA PROXY node parameters
 * PARAMETERS
 *  data            [IN]        CCA proxy data
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_handle_proxy_params(cca_core_data_struct *data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
	U8 dataacct_type;
    mmi_imps_ota_prof_struct *prof = imps_p->ota_prof->info[imps_p->ota_prof->curr_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->id)
    {
        case CCA_NS_OMA_PROXY_ID:
            /* Whether the value is presented and the type is legal. */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_FAIL;
            }

	        /* Whether this is a ASCII string. */
            if (!mmi_imps_is_ascii_string((U8*)data->values.s[0]))
            {
                return CCA_STATUS_FAIL;
            }
			
            /* Check whether the length of the proxy id is legal. */
            mmi_cca_generate_hash_value((CHAR*)data->values.s[0],
                (U8*)prof->prof_info.proxy_id,
                CCA_HASH_VALUE_MAX_BYTES);            
            break;

        case CCA_NS_DATAACCTID:
            {
                U32 i;    
                srv_dtcnt_sim_type_enum sim_type;                
                
                if (data->size <= 0 || data->type != CCA_DT_INT)
                {
                    return CCA_STATUS_FAIL;
                }    			
            	dataacct_type = srv_dtcnt_get_bearer_type((U8)data->values.i[0], SRV_DTCNT_ACCOUNT_PRIMARY);
    			if ((dataacct_type & IMPS_DATA_ACCOUNT_TYPE) == 0)
    			{
    				return CCA_STATUS_FAIL;
    			}

                srv_dtcnt_get_sim_info((U32) data->values.i[0], &sim_type);
                prof->prof_info.curr_dt_acct[sim_type - SRV_DTCNT_SIM_TYPE_1] = 
                                 cbm_encode_data_account_id((U32)data->values.i[0],
                                                    CBM_SIM_ID_SIM1 + sim_type - SRV_DTCNT_SIM_TYPE_1,
                                                    imps_p->gen_info.cbm_app_id,
                                                     KAL_FALSE);              
                break;
            }

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_parse_app
 * DESCRIPTION
 *  The function used to parse app node.
 * PARAMETERS
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  result of processing CCA nodes.
 *  On success, return CCA_STATUS_OK;
 *  Otherwise, return CCA_STATUS_FAIL.
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_parse_app(
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data;
    CHAR **px_id;
    S32 size;
    cca_status_enum status = CCA_STATUS_OK;
    S16 index = -1;
    U8 i, j;
    MMI_BOOL same_proxy = MMI_FALSE;
    mmi_imps_ota_prof_struct *prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 2 * IMPS_PROF_COUNT; i++)
    {
        prof = imps_p->ota_prof->info[i];

        imps_p->ota_prof->app_prof_index[i] = MMI_FALSE;

        if (prof != NULL && prof->is_used && 
            (!prof->is_valid || prof->prof_info.server[0] == '\0'))
        {
            prof->is_used = MMI_FALSE;
            prof->is_valid = MMI_TRUE;

            if (prof->is_proxy)
            {
                memset(&prof->prof_info.prof_name, 0, IMPS_PROF_NAME_LEN * sizeof(UI_character_type));
                memset(&prof->prof_info.server, 0, IMPS_MAX_SERVER_ADDRESS_LEN);
                memset(&prof->prof_info.username, 0, IMPS_MAX_USERID_LEN);
                memset(&prof->prof_info.passwd, 0, IMPS_MAX_PASSWORD_LEN);
                
                prof->is_app_addr = MMI_FALSE;
                prof->is_app_auth = MMI_FALSE;
            }
            else
            {
                OslMfree(imps_p->ota_prof->info[i]);
                imps_p->ota_prof->info[i] = NULL;
                imps_p->ota_prof->total--;
            }
        }
    }

    status = mmi_cca_doc_get_nodedata_strs(iter_datalist, CCA_NS_OMA_TO_PROXY, &px_id, &size);

    /* exist related proxy */
    if (status == CCA_STATUS_OK && px_id != NULL)
    {
        for (i = 0; i < size; i++)
        {
            /* judge whether this app include same proxy id */
            for (j = 0; j < i; j++)
            {
                if (strcmp(px_id[j], px_id[i]) == 0)
                {
                    same_proxy = MMI_TRUE;
                    break;
                }
            }
            /* the app node has include this proxy node */
            if (same_proxy)
            {
                continue;
            }

            if (px_id[i] == NULL)
                break;

            index = mmi_imps_ota_get_proxy_index((CHAR*)px_id[i]);

            /* find related proxy */
            if (index >= 0  && index < IMPS_PROF_COUNT)
            {
                /* this proxy has been used, that happened when one proxy used for mulitple app */
                if (imps_p->ota_prof->info[index]->is_used)
                {
                    /* create a new profile to store information */
                    if (mmi_imps_ota_create_prof(MMI_FALSE))
                    {
                        /* set flag for app child node can be store in this profile */
                        imps_p->ota_prof->app_prof_index[imps_p->ota_prof->curr_index] = MMI_TRUE;

                        imps_p->ota_prof->info[imps_p->ota_prof->curr_index]->is_used = MMI_TRUE;
                    }
                }
                else
                {
                    /* set flag for app child node can be store in this profile */
                    imps_p->ota_prof->app_prof_index[index] = MMI_TRUE;
                    imps_p->ota_prof->info[index]->is_used = MMI_TRUE;
                }
            }
            else
            {
                return CCA_STATUS_FAIL;
            }
        }
    }
    else
    {
        if (mmi_imps_ota_create_prof(MMI_FALSE))
        {
            /* set flag for app child node can be store in this profile */
            imps_p->ota_prof->app_prof_index[imps_p->ota_prof->curr_index] = MMI_TRUE;
            imps_p->ota_prof->info[imps_p->ota_prof->curr_index]->is_used = MMI_TRUE;
        }
        else
        {
            return CCA_STATUS_MEMFULL;

        }
    }

    mmi_cca_iterator_restart(iter_datalist);

    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {
        if (data == NULL)
            return CCA_STATUS_FAIL;

        status = mmi_imps_ota_handle_app_params(data, user_data);
        if (status != CCA_STATUS_OK)
        {
            break;
        }
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_handle_app_params
 * DESCRIPTION
 *  Handle CCA application node parameters
 * PARAMETERS
 *  data            [IN]        CCA proxy data
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_handle_app_params(cca_core_data_struct *data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;
    S32 str_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
            for (i = 0; i < IMPS_PROF_COUNT * 2; i++)
            {
                if (imps_p->ota_prof->app_prof_index[i])
                {
                    mmi_chset_utf8_to_ucs2_string(
                        (U8*)imps_p->ota_prof->info[i]->prof_info.prof_name,
                        IMPS_PROF_NAME_LEN * ENCODING_LENGTH,
                        (U8*)data->values.s[0]);
                }
            }
            break;

        case CCA_NS_OMA_ADDR:
			/* regard the first valid addr as profile server address */
            for (i = 0; i < data->size; i++)
            {
                if (data->type != CCA_DT_STR)
                    continue;

				/* Whether this is a ASCII string. */
                if (!mmi_imps_is_ascii_string((U8*)data->values.s[i]))
                {
                    continue;
                }

                if (applib_url_is_valid((const char *) data->values.s[i]) != 0 ||
                   mmi_imps_check_white_spaces((CHAR*)data->values.s[i]))
                {                    
                    continue;
                }

                /* Check whether the length of the server is legal. */
                str_len = strlen(data->values.s[i]);                               

                for (j = 0; j < IMPS_PROF_COUNT * 2; j++)
                {
                    if (imps_p->ota_prof->app_prof_index[j])
                    {
						if (str_len + 1 > IMPS_MAX_SERVER_ADDRESS_LEN)
						{
							strncpy((CHAR*)imps_p->ota_prof->info[j]->prof_info.server, data->values.s[i], 
								IMPS_MAX_SERVER_ADDRESS_LEN - 1);
						}
						else
						{
							strcpy((CHAR*)imps_p->ota_prof->info[j]->prof_info.server, data->values.s[i]);
						}

                        imps_p->ota_prof->info[j]->is_app_addr = MMI_TRUE;
                    }
                }

                break;
            }
            break;

        default:
            break;
    }
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_handle_appaddr_params
 * DESCRIPTION
 *  Handle CCA application address node parameters
 * PARAMETERS
 *  hNode           [IN]        CCA handler
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_handle_appaddr_params(S32 hNode, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    cca_status_enum result;
    CHAR *value = NULL;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_ADDR, &value);
    if (result == CCA_STATUS_OK && value != NULL)
    {
        /* Whether this is a ASCII string. */
        if (!mmi_imps_is_ascii_string((U8*)value))
        {
            return CCA_STATUS_FAIL;
        }
        if (applib_url_is_valid((const char *) value) != 0 ||
            mmi_imps_check_white_spaces((CHAR*)value))
        {
            return CCA_STATUS_FAIL;
        }

        str_len = strlen(value);
		
        for (i = 0; i < IMPS_PROF_COUNT * 2; i++)
        {
            if (imps_p->ota_prof->app_prof_index[i])
            {
				/* regard the first valid addr as profile server address */
                if (!imps_p->ota_prof->info[i]->is_app_addr)
                {                                     
					if (str_len + 1 > IMPS_MAX_SERVER_ADDRESS_LEN)
					{
						strncpy((CHAR*)imps_p->ota_prof->info[i]->prof_info.server, value, 
							IMPS_MAX_SERVER_ADDRESS_LEN - 1);
					}
					else
					{
       					strcpy((CHAR*)imps_p->ota_prof->info[i]->prof_info.server, value);
					}
                    
                    imps_p->ota_prof->info[i]->is_app_addr = MMI_TRUE;
                }
            }
        }
    }
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_handle_appauth_params
 * DESCRIPTION
 *  Handle CCA application authorization parameters
 * PARAMETERS
 *  hNode           [IN]        CCA handler
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_imps_ota_handle_appauth_params(S32 hNode, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    cca_status_enum result;
    CHAR *value = NULL;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_AAUTHNAME, &value);

    if (result != CCA_STATUS_OK || value == NULL)
    {
        return CCA_STATUS_OK;
    }
		/* Whether this is a ASCII string. */
        if (!mmi_imps_is_ascii_string((U8*)value))
        {
            return CCA_STATUS_FAIL;
        }

        /* Check whether the length of the proxy id is legal. */
        str_len = strlen(value);        

        /* Obtain the username. Zero-terminate username. */
        for (i = 0; i < IMPS_PROF_COUNT * 2; i++)
        {
            if (imps_p->ota_prof->app_prof_index[i])
            {
                if (!imps_p->ota_prof->info[i]->is_app_auth)
                {
                    if (str_len + 1 > IMPS_MAX_USERID_LEN)
					{
						strncpy((CHAR*)imps_p->ota_prof->info[i]->prof_info.username, value, 
							IMPS_MAX_USERID_LEN - 1);
					}
					else
					{
						strcpy((CHAR*)imps_p->ota_prof->info[i]->prof_info.username, value);
					}

                    imps_p->ota_prof->info[i]->is_app_auth = MMI_TRUE;
                }
            }
        }
    

    result = mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_AAUTHSECRET, &value);
    if (result != CCA_STATUS_OK || value == NULL)
    {
        return CCA_STATUS_OK;
    }
		/* Whether this is a ASCII string. */
        if (!mmi_imps_is_ascii_string((U8*)value))
        {
            return CCA_STATUS_FAIL;
        }

        /* Check whether the length of the proxy password is legal. */
        str_len = strlen(value);        

        /* Obtain the password. Zero-terminate password. */
        for (i = 0; i < IMPS_PROF_COUNT * 2; i++)
        {
            if (imps_p->ota_prof->app_prof_index[i])
            {
				if (str_len + 1 > IMPS_MAX_PASSWORD_LEN)
				{
					strncpy((CHAR*)imps_p->ota_prof->info[i]->prof_info.passwd, value, 
						IMPS_MAX_PASSWORD_LEN - 1);
				}
				else
				{
					strcpy((CHAR*)imps_p->ota_prof->info[i]->prof_info.passwd, value);
				}
            }
        }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_create_prof
 * DESCRIPTION
 *  Find free OTA profile slot and allocate memory.
 * PARAMETERS
 *  is_proxy        [IN]        Whether there is proxy
 * RETURNS
 *  If there is free OTA profile slot, return MMI_TRUE,
 *  Otherwise return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_imps_ota_create_prof(MMI_BOOL is_proxy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    U32 used = 0;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < IMPS_PROF_COUNT; i++)
    {
        if (imps_p->ota_prof->info[i] == NULL)
        {
            break;
        }
    }

    index = i;

    if (i == IMPS_PROF_COUNT)
    {
        for (j = 0; j < IMPS_PROF_COUNT * 2; j++)
        {
            if (imps_p->ota_prof->info[j] && imps_p->ota_prof->info[j]->is_used)
            {
                used++;
            }
        }
        /* this process some profile has only proxy and no app, we just save app to 
        new profile, then matching it later */
        if (used < IMPS_PROF_COUNT && !is_proxy)
        {
            for (j = IMPS_PROF_COUNT; j < 2 * IMPS_PROF_COUNT; j++)
            {
                if (imps_p->ota_prof->info[j] == NULL)
                {
                    break;
                }
            }

             if (j == 2 * IMPS_PROF_COUNT)
             {
        return MMI_FALSE;
             }
             else
             {
                 index = j;
             }
        }
        else
        {
            return MMI_FALSE;
        }
    }

    imps_p->ota_prof->total++;
    imps_p->ota_prof->curr_index = index;

    imps_p->ota_prof->info[index] = (mmi_imps_ota_prof_struct*) OslMalloc(sizeof(mmi_imps_ota_prof_struct));
    memset(imps_p->ota_prof->info[index], 0, sizeof(mmi_imps_ota_prof_struct));

    imps_p->ota_prof->info[index]->is_proxy = is_proxy;
	imps_p->ota_prof->info[index]->is_valid = MMI_TRUE;

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        imps_p->ota_prof->info[index]->prof_info.curr_dt_acct[i] = 
        cbm_encode_data_account_id(
        CUSTOM_DEFAULT_IMPS_DTCNT_ID,
        CBM_SIM_ID_SIM1 + i,
        imps_p->gen_info.cbm_app_id,
        FALSE);    
    }

    imps_p->ota_prof->info[index]->update_index = 0xFF;
    imps_p->ota_prof->info[index]->prof_info.prov_flag = MMI_IMPS_PROF_TYPE_OTA;

    memcpy((CHAR*)imps_p->ota_prof->info[index]->prof_info.provurl, 
        (CHAR*)imps_p->ota_prof->provurl,
        CCA_HASH_VALUE_MAX_BYTES);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_free_info
 * DESCRIPTION
 *  Free OTA memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_free_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->ota_prof == NULL)
    {
        return;
    }

    for (i = 0; i < IMPS_PROF_COUNT; i++)
    {
        if (imps_p->ota_prof->info[i])
        {
            OslMfree(imps_p->ota_prof->info[i]);
            imps_p->ota_prof->info[i] = NULL;
        }
    }

    OslMfree(imps_p->ota_prof);
    imps_p->ota_prof = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_free_prof
 * DESCRIPTION
 *  Free OTA memory
 * PARAMETERS
 *  index       [IN]        Profile index to be free
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_free_prof(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->ota_prof == NULL)
    {
        return;
    }

    if (imps_p->ota_prof->info[index])
    {
        OslMfree(imps_p->ota_prof->info[index]);
        imps_p->ota_prof->info[index] = NULL;
        imps_p->ota_prof->total--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_get_proxy_index
 * DESCRIPTION
 *  Find relevant profile according proxy_id that relate proxy with application.
 * PARAMETERS
 *  px_id       [IN]        ID used to relate proxy with application
 * RETURNS
 *  If find related profile succesfully, return index of profile.
 *  otherwise return 0xFF.
 *****************************************************************************/
static S16 mmi_imps_ota_get_proxy_index(const CHAR *px_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    U8 temp_id[MMI_IMPS_OTA_HASH_LEN] = {0};     

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->ota_prof == NULL || px_id == NULL)
    {
        MMI_ASSERT(0);
        return IMPS_PROF_COUNT;
    }
        
    mmi_cca_generate_hash_value((CHAR*)px_id, (U8*)temp_id, CCA_HASH_VALUE_MAX_BYTES);
    
    for (i = 0; i < IMPS_PROF_COUNT; i++)
    {
        if (imps_p->ota_prof->info[i] && imps_p->ota_prof->info[i]->is_proxy)
        {
            if (memcmp(imps_p->ota_prof->info[i]->prof_info.proxy_id, temp_id, 
                CCA_HASH_VALUE_MAX_BYTES) == 0)
            {
                break;
            }
        }
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_install_finished
 * DESCRIPTION
 *  This function should be called to exit the IMPS OTA application. it can
 *  be called when END key is pressed to return to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  When END key is pressed to return to idle screen, return TRUE to stop(?)(?)
 *  delete other nodes in history stack. Here, always return FALSE.(?)(?)
 *****************************************************************************/
static U8 mmi_imps_ota_install_finished(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_ota_info_struct *prof = imps_p->ota_prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->ota_prof == NULL)
        return MMI_TRUE;

    /* Terminated. Send a response back to CCA and free memory. */
	if (prof->is_update)
    {
        mmi_imps_send_cca_conf_rsp(CCA_STATUS_ENDKEY_SETTING_UPDATED);
    }
    else if (prof->is_install)
    {
        mmi_imps_send_cca_conf_rsp(CCA_STATUS_ENDKEY_SETTING_INSTALLED);
    }
    else if (prof->is_skip)
    {
        mmi_imps_send_cca_conf_rsp(CCA_STATUS_ENDKEY_SETTING_SKIPPED);
    }
	else
    {
        mmi_imps_send_cca_conf_rsp(CCA_STATUS_ENDKEY_PRESSED);
	}

    mmi_imps_ota_free_info();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_install_status
 * DESCRIPTION
 *  This function used to judge which status will be send to CCA.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_install_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_ota_info_struct *prof = imps_p->ota_prof;
    U16 curr_scr = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prof->is_update)
    {
        mmi_imps_send_cca_conf_rsp(CCA_STATUS_SETTING_UPDATED);
    }
    else if (prof->is_install)
    {
        mmi_imps_send_cca_conf_rsp(CCA_STATUS_OK);
    }
    else
    {
        mmi_imps_send_cca_conf_rsp(CCA_STATUS_SETTING_SKIPPED);
    }

    mmi_imps_ota_free_info();

    mmi_frm_group_close(GRP_ID_IMPS_OTA);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_is_valid_proxy
 * DESCRIPTION
 *  This function used to judge whether profile proxy is valid.
 * PARAMETERS
 *  prof        [IN]        Profile need to be check
 * RETURNS
 *  if profile proxy is valid, return MMI_TRUE, otherwise return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_imps_ota_is_valid_proxy(mmi_imps_ota_prof_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prof == NULL)
    {
        MMI_ASSERT(0);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

#ifdef    __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_match_prof
 * DESCRIPTION
 *  This function used to find match profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_match_prof(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_nvram_struct *prof_buff;    
    U8 i, j;
    mmi_imps_ota_info_struct *data = imps_p->ota_prof;
    MMI_BOOL provurl[IMPS_PROF_COUNT];    
    MMI_BOOL same_proxy_id = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* if there is no provurl, it will not update */
    if (mmi_imps_ota_is_empty_hash((CHAR*)data->provurl))
    {
        return;
    }

    prof_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);
    mmi_imps_util_read_nvram(prof_buff);
    
    /* find provurl match profile */
    for (i = 0; i < IMPS_PROF_COUNT; i++)
    {
        provurl[i] = MMI_FALSE; 

        if (memcmp(data->provurl, prof_buff->prof[i].provurl, CCA_HASH_VALUE_MAX_BYTES) == 0)
        {
            provurl[i] = MMI_TRUE;
        }
    }
        
    /* find proxy id match profile, if there is no proxy id, profile name should match */
    for (j = 0; j < data->total; j++)
    {
        same_proxy_id = MMI_FALSE;

        if (!data->info[j]->is_valid)
        {
            j++;
            continue;
        }

        for (i = 0; i < IMPS_PROF_COUNT; i++)
        {
            /* it must provurl match first */
            if (!provurl[i])
            {
                continue;
            }
       
            /* if old proxy id is empty, and new proxy id is not empty, it must match server */
            if (mmi_imps_ota_is_empty_hash((CHAR*)prof_buff->prof[i].proxy_id))
            {
                /* if proxy id is empty, server address must match */
                if (srv_imps_stricmp((CHAR*)prof_buff->prof[i].server, (CHAR*)data->info[j]->prof_info.server) == 0)
                {
                    same_proxy_id = MMI_TRUE;
                }
            }
            else if (memcmp(prof_buff->prof[i].proxy_id, data->info[j]->prof_info.proxy_id,
                CCA_HASH_VALUE_MAX_BYTES) == 0) 
            {
                same_proxy_id = MMI_TRUE;
            }            

            if (same_proxy_id)
            {
                /* if profile is factory pre-defined, need to judge whether it is updatable */
                if (prof_buff->prof[i].prov_flag == MMI_IMPS_PROF_TYPE_FACTORY)
                {
                    /* if can not be updatable, discard this profile */
                    if (data->prov_flag && MMI_CCA_PROV_FLAG_FACTORY_PROFILE_UPDATABLE == 0)
                    {
                        data->info[i]->is_valid = MMI_FALSE;
                    }
                    else
                    {
                        data->info[j]->update_index = i;
                    }
                }
                else
                {
                    data->info[j]->update_index = i;
                }
                break;
            }            
        }//end of ota prof count
    } //end of nvram prof count
    OslMfree(prof_buff);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_is_valid_info
 * DESCRIPTION
 *  This function used to judge whether profile is valid.
 *  For OTA, prompt user IMPS_PROF_COUNT profile that may be invalid.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_is_valid_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = imps_p->ota_prof->total;
    U8 i, j;
    U8 invalid_no = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* move profile has only app to un-used profile */
    if (count > IMPS_PROF_COUNT)
    {
        for (i = 0; i < IMPS_PROF_COUNT; i++)
        {
            /* this profile only has proxy, no app server */
            if (!imps_p->ota_prof->info[i]->is_used)
            {
                 mmi_imps_ota_free_prof(i);
                 for (j = IMPS_PROF_COUNT; j < IMPS_PROF_COUNT * 2; j++)
                 {
                     if (imps_p->ota_prof->info[j] != NULL)
                     {
                         imps_p->ota_prof->info[i] = imps_p->ota_prof->info[j];
                         imps_p->ota_prof->info[j] = NULL; 
                         imps_p->ota_prof->info[i]->is_used = MMI_TRUE;
                         break;
                     }
                 }
            }
        }
    }

    /* over IMPS_PROF_COUNT number profile, delete it */
    count = imps_p->ota_prof->total;
    if (count > IMPS_PROF_COUNT)
    {
        count = IMPS_PROF_COUNT;
        imps_p->ota_prof->total = IMPS_PROF_COUNT;

        for (i = IMPS_PROF_COUNT; i < 2 * IMPS_PROF_COUNT; i++)
        {
            if (imps_p->ota_prof->info[i] != NULL)
            {
                OslMfree(imps_p->ota_prof->info[i]);
                imps_p->ota_prof->info[i] = NULL;
            }
        }
    }

#ifdef    __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    /* find match profile, if match profile is factory predefine and can not
       updatable, take it as invalid profile */
    mmi_imps_ota_match_prof();
#endif

    for (i = 0; i < count; i++)
    {
        if (imps_p->ota_prof->info[i]->prof_info.server[0] == '\0')
        {
            imps_p->ota_prof->info[i]->is_valid = MMI_FALSE;
        }
        if (!imps_p->ota_prof->info[i]->is_valid)
        {
            invalid_no++;
        }
    }
    /* all profiles are invalid */
    if (invalid_no == count)
    {
        mmi_imps_send_cca_conf_rsp(CCA_STATUS_INVALID_SETTING);
        mmi_imps_ota_free_info();
        return;
    }

    imps_p->ota_prof->valid_no = imps_p->ota_prof->total - invalid_no;


    mmi_imps_pre_entry_ota_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_string
 * DESCRIPTION
 *  Compose OTA information string
 * PARAMETERS
 *  buffer      [IN/OUT]        Store string of OTA information
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_string(CHAR *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR temp[100];
    CHAR uc2_temp[200];
    U8 i;
    U8 index = imps_p->ota_prof->curr_index;

    mmi_imps_ota_prof_struct *prof = imps_p->ota_prof->info[imps_p->ota_prof->curr_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* instant message */
    mmi_ucs2cpy(buffer, GetString(STR_ID_CCA_IMPS));
    mmi_ucs2cat(buffer, (CHAR*)L"\n");

    /* profile index */
    for (i = 0; i < imps_p->ota_prof->curr_index; i++)
    {
        if (imps_p->ota_prof->info[i]->is_valid)
        {
            continue;
        }

        index--;
    }
    sprintf(temp, "%d/%d", index + 1, imps_p->ota_prof->valid_no);

    mmi_asc_to_ucs2(uc2_temp, temp);
    mmi_ucs2cat(buffer, GetString(STR_GLOBAL_ACCOUNTS));
    mmi_ucs2cat(buffer, GetString(STR_ID_IMPS_COLON));
	mmi_ucs2cat(buffer, (CHAR*) L" ");
    mmi_ucs2cat(buffer, uc2_temp);
    mmi_ucs2cat(buffer, (CHAR*)L"\n");

#ifdef    __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if (prof->update_index != 0xFF)
    {
        mmi_ucs2cat(buffer, GetString(STR_ID_CCA_UPDATE_PROFILE));
        mmi_ucs2cat(buffer, (CHAR*)L"\n");
    }
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */    

    mmi_ucs2cat(buffer, (CHAR*)L"\n");

	/* profile name */
	mmi_ucs2cat(buffer, GetString(STR_ID_IMPS_PROF_NAME));
    mmi_ucs2cat(buffer, GetString(STR_ID_IMPS_COLON));
	mmi_ucs2cat(buffer, (CHAR*) L" ");      
    if (prof->prof_info.prof_name[0])
    {
        mmi_ucs2cat(buffer, (CHAR*)(prof->prof_info.prof_name));        
    }
	mmi_ucs2cat(buffer, (CHAR*)L"\n");

    /* server address */
    if (prof->prof_info.server[0])
    {
        mmi_ucs2cat(buffer, GetString(STR_ID_IMPS_SERVER));
        mmi_ucs2cat(buffer, GetString(STR_ID_IMPS_COLON));
		mmi_ucs2cat(buffer, (CHAR*) L" ");
        mmi_asc_to_ucs2(uc2_temp, (CHAR*)prof->prof_info.server);
        mmi_ucs2cat(buffer, uc2_temp);
        mmi_ucs2cat(buffer, (CHAR*)L"\n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_ota_setting
 * DESCRIPTION
 *  Pre-entry function for screen that display OTA information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_pre_entry_ota_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->ota_prof->curr_index = 0;

    while (!imps_p->ota_prof->info[imps_p->ota_prof->curr_index]->is_valid &&
           imps_p->ota_prof->curr_index < imps_p->ota_prof->total)
    {
        imps_p->ota_prof->curr_index++;
    }

    mmi_imps_enter_ota_group();
    mmi_imps_entry_ota_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_ota_setting
 * DESCRIPTION
 *  Entry function for screen that display OTA information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_entry_ota_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
             GRP_ID_IMPS_OTA, 
             SCR_ID_IMPS_OTA_SETTING, 
             NULL, 
             mmi_imps_entry_ota_setting, 
             MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    SetParentHandler(0);

    mmi_imps_ota_string((CHAR*)subMenuData);

    ShowCategory78Screen(
        STR_ID_CCA_INSTALL_SETTING,
        mmi_imps_get_root_title_icon(),
        STR_GLOBAL_INSTALL,
        IMG_GLOBAL_OK,
        STR_ID_CCA_SKIP,       
        IMG_GLOBAL_BACK,
        NULL, 
        (U8*)subMenuData,
        mmi_ucs2strlen((CHAR*)subMenuData),
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_imps_ota_install, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_imps_ota_skip_confirm, KEY_EVENT_UP);  

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_imps_ota_install, KEY_EVENT_UP);

    mmi_frm_scrn_set_leave_proc(GRP_ID_IMPS_OTA, SCR_ID_IMPS_OTA_SETTING, mmi_imps_ota_abort_install);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_hilite_prof_list
 * DESCRIPTION
 *  Highlight handler for OTA profile list.
 * PARAMETERS
 *  index       [IN]        Profile index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_hilite_prof_list(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->ota_prof->hilite_prof = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_ota_prof_list
 * DESCRIPTION
 *  Entry screen for list profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_entry_ota_prof_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 *nStrItemList[IMPS_PROF_COUNT];
    U16 nIconItemList[IMPS_PROF_COUNT] = {0, 0, 0};
    U8 *guiBuffer;
    S32 curr_hilite = 0;
    mmi_imps_nvram_struct *prof_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);
    mmi_imps_util_read_nvram(prof_buff);

    if (!mmi_frm_scrn_enter(
             GRP_ID_IMPS_OTA, 
             SCR_ID_IMPS_OTA_PROF_LIST, 
             NULL, 
             mmi_imps_entry_ota_prof_list, 
             MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    for (i = 0; i < IMPS_PROF_COUNT; i++)
    {
        if (mmi_ucs2strlen((CHAR*)prof_buff->prof[i].prof_name) == 0)
        {
            mmi_ucs2cpy((CHAR*)imps_p->ota_prof->prof_name[i], (CHAR*)GetString((U16)(STR_ID_IMPS_PROFILE1 + i)));
        }
        else
        {
        mmi_ucs2cpy((CHAR*)imps_p->ota_prof->prof_name[i], (CHAR*)prof_buff->prof[i].prof_name);
        }
        nStrItemList[i] = (U8*)imps_p->ota_prof->prof_name[i];
    }

    if (prof_buff->act_prof_indx <= IMPS_PROF_COUNT && prof_buff->act_prof_indx > 0)
    {
        nIconItemList[prof_buff->act_prof_indx - 1] = IMG_VICON;
    }

    OslMfree(prof_buff);

    RegisterHighlightHandler(mmi_imps_ota_hilite_prof_list);

    ShowCategory73Screen(
        STR_ID_CCA_REPLACE_SETTING,
        mmi_imps_get_root_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMPS_PROF_COUNT,
        nStrItemList,
        (U16*) nIconItemList,
        (U16*) gIndexIconsImageList,
        curr_hilite,
        guiBuffer,
        ICON_ICON_TEXT);

    SetLeftSoftkeyFunction(mmi_imps_ota_install_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    mmi_frm_scrn_set_leave_proc(GRP_ID_IMPS_OTA, SCR_ID_IMPS_OTA_PROF_LIST, mmi_imps_ota_abort_install);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_install_yes
 * DESCRIPTION
 *  Select overwrite one existing profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_install_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_nvram_struct *prof_buff;
    U8 index = imps_p->ota_prof->hilite_prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);
    mmi_imps_util_read_nvram(prof_buff);

    /* if selected profile is in use */
    if ((index == prof_buff->act_prof_indx - 1) &&
        (IMPS_STATUS_LOGIN ||
        IMPS_STATUS_LOGGING_IN))
    {
        mmi_imps_util_disp_fail_popup(STR_ID_CCA_PROFILE_IN_USE);
        OslMfree(prof_buff);
        return;
    }
    
    memcpy(
        &prof_buff->prof[index],
        &imps_p->ota_prof->info[imps_p->ota_prof->curr_index]->prof_info,
        sizeof(mmi_imps_prof_struct));

    /* no valid activated profile */
    if (!imps_p->ota_prof->is_act &&
        !IMPS_STATUS_LOGIN &&
        !IMPS_STATUS_LOGGING_IN)
    {
        prof_buff->act_prof_indx = (imps_p->ota_prof->hilite_prof + 1);
		imps_p->ota_prof->is_act = MMI_TRUE;
        memcpy(&imps_p->nvram_info, &prof_buff->prof[index], sizeof(mmi_imps_prof_struct));
        mmi_imps_set_srv_data_acct();
        mmi_imps_util_reset_presence(prof_buff);
    }
   
    mmi_imps_util_write_nvram(prof_buff);

    OslMfree(prof_buff);

    imps_p->ota_prof->is_install = MMI_TRUE;

    if (mmi_imps_ota_get_next())
    {		
        mmi_imps_entry_ota_setting();
        mmi_frm_scrn_close(GRP_ID_IMPS_OTA, SCR_ID_IMPS_OTA_PROF_LIST);
    }	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_prof_use
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_prof_use(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imps_ota_get_next())
    {
        mmi_imps_entry_ota_setting();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_install
 * DESCRIPTION
 *  Install OTA setting, first we need to judge whether OTA parameters are valid.
 *  If there is free proflie slot, we install automatically, otherwise come to
 *  profile select screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_ota_prof_struct *ota_prof = imps_p->ota_prof->info[imps_p->ota_prof->curr_index];
    mmi_imps_nvram_struct *prof_buff;
    U16 i = 0;
    S32 install_index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);
    mmi_imps_util_read_nvram(prof_buff);

    /* install matched prof */
    if (ota_prof->update_index != 0xFF && 
        ota_prof->update_index >= 0 && 
        ota_prof->update_index < IMPS_PROF_COUNT)
    {        
        /* this matched profile is in use, display popup and handle next prof */
        if ((ota_prof->update_index == prof_buff->act_prof_indx - 1) &&
            (IMPS_STATUS_LOGIN ||
            IMPS_STATUS_LOGGING_IN))
        {       
            mmi_imps_util_disp_fail_popup(STR_ID_CCA_PROFILE_IN_USE);
            OslMfree(prof_buff);
            
            return;
        }

        install_index = ota_prof->update_index;
        imps_p->ota_prof->is_update = MMI_TRUE;
    }
    else
    {
    /* check whether have not configured profile */
    for (i = 0; i < IMPS_PROF_COUNT; i++)
    {
        if (mmi_ucs2strlen((CHAR*)prof_buff->prof[i].server) == 0)
        {
            install_index = i;
            break;
        }
    }
    /* all profiles configured */
    if (i == IMPS_PROF_COUNT)
    {
        mmi_imps_entry_ota_prof_list();
        OslMfree(prof_buff);
        return;
    }
    }

    MMI_ASSERT(install_index >= 0 && install_index < IMPS_PROF_COUNT);
    /* save OTA setting to NVRAM */
    memcpy(
        &prof_buff->prof[install_index],
        &imps_p->ota_prof->info[imps_p->ota_prof->curr_index]->prof_info,
        sizeof(mmi_imps_prof_struct));

    /* no valid activated profile */
    if (!imps_p->ota_prof->is_act && 
        !IMPS_STATUS_LOGIN &&
        !IMPS_STATUS_LOGGING_IN)
    {
        prof_buff->act_prof_indx = (install_index + 1);
		imps_p->ota_prof->is_act = MMI_TRUE;
        memcpy(&imps_p->nvram_info, prof_buff, sizeof(mmi_imps_nvram_struct));
        mmi_imps_set_srv_data_acct();
        mmi_imps_util_reset_presence(prof_buff);
    }

    mmi_imps_util_write_nvram(prof_buff);

    OslMfree(prof_buff);

    imps_p->ota_prof->is_install = MMI_TRUE;
    if (mmi_imps_ota_get_next())
    {
        mmi_imps_entry_ota_setting();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_get_next
 * DESCRIPTION
 *  Get next OTA setting, if no more OTA setting, response to CCA.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_imps_ota_get_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_ota_info_struct *prof = imps_p->ota_prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prof->curr_index >= prof->total - 1)
    {
        mmi_imps_ota_install_status();
        return MMI_FALSE;
    }
    else
    {
        imps_p->ota_prof->curr_index++;
        
        if (imps_p->ota_prof->curr_index >= IMPS_PROF_COUNT * 2)
        {
            MMI_ASSERT(0);
            return MMI_FALSE;
        }
        
        while (imps_p->ota_prof->info[imps_p->ota_prof->curr_index]->is_valid != MMI_TRUE &&
               imps_p->ota_prof->curr_index < imps_p->ota_prof->total)
        {
            imps_p->ota_prof->curr_index++;
 
            if (prof->curr_index >= prof->total)
            {
                mmi_imps_ota_install_status();
                return MMI_FALSE;
            }
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_skip_confirm
 * DESCRIPTION
 *  Call CCA function to show whether skip installing current OTA profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_skip_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_common_cancel_with_sg(
        GRP_ID_IMPS_OTA, 
        (U16)STR_ID_CCA_SKIP_PROFILE, 
        mmi_imps_ota_skip_yes);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_skip_yes
 * DESCRIPTION
 *  Skip installing current OTA profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_ota_skip_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	imps_p->ota_prof->is_skip = MMI_TRUE;

    if (mmi_imps_ota_get_next())
    {
        mmi_imps_entry_ota_setting();
    }
    else
    {
        mmi_imps_ota_install_finished();
        mmi_frm_group_close(GRP_ID_IMPS_OTA);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_is_ascii_string
 * DESCRIPTION
 *  This function checks whether the input UTF-8 encoded string is an ASCII
 *  string.
 * PARAMETERS
 *  utf8_str        [IN]        Input UTF-8 encoded string
 * RETURNS
 *  If input string is ASCII string, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_imps_is_ascii_string(const U8 *utf8_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If this is an ASCII string, each octet should be an ASCII character. */
    for (; *utf8_str != '\0'; ++utf8_str)
    {
        if (*utf8_str > 0x7F)
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_check_ip
 * DESCRIPTION
 *  parse string to 4 number
 * PARAMETERS
 *  ip          [OUT]       Store parsed data
 *  data        [IN]        Source data
 *  len         [IN]        Length of source data
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_imps_check_ip(U8 *ip, CHAR *data, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dot_no = 0;
    S32 i = 0, j = 0, k = 0;
    CHAR temp[4][4];  /* eg: 255.255.255.255 */
    S16 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL || len < 7 || len > 15)    /* 0.0.0.0 */
    {
        return MMI_FALSE;
    }

    memset(temp, 0, 4 * 4);

    if (data[0] == '.' || data[len - 1] == '.')
    {
        return MMI_FALSE;
    }

    for (i = 0; i < len; i++)
    {
        if (data[i] == '.')
        {
            dot_no++;
            j++;
            k = 0;

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
            temp[j][k] = data[i];

            k++;
        }
    }
    if (dot_no != 3)
    {
        return MMI_FALSE;
    }

    for (i = 0; i < 4; i++)
    {
        value = (S16)atoi(temp[i]);
        if (value > 255)
            return MMI_FALSE;

        ip[i] = (U8)value;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_is_use_proxy
 * DESCRIPTION
 *  Judge whether use proxy
 * PARAMETERS
 *  data        [IN]        Source data
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_imps_ota_is_use_proxy(const U8 *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
	MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	for (i = 0; i < 4; i++)
	{
		if (data[i] != 0)
		{
			result = MMI_TRUE;
			break;
		}
	}
	return result;
}
#endif /* #ifdef __MMI_OP11_IMPS__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ota_is_empty_hash
 * DESCRIPTION
 *  Judge whether it is valid hash
 * PARAMETERS
 *  data        [IN]        Source data
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_imps_ota_is_empty_hash(const CHAR *data)
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

#endif /* __MMI_IMPS_OTA__ */


