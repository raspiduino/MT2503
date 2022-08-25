/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*  dmuiOTAP.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This file for DM provisioning.
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*
*****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_SYNCML_DM_OTAP__
#include "mmi_rp_app_dmui_def.h"

#include "DMGprot.h"

#include "dmuiappdef.h"
#include "dmuiprot.h"
/* Data Account type define header file */
#include "DataAccountGprot.h"
#include "DtcntSrvGprot.h"
#include "CommonScreens.h"

/* URL check function head file */
#include "app_url.h"
#include "CentralConfigAgentGProt.h"    /* CCA header */
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "DMTypeDef.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMI_conn_app_trc.h"
#include "mmi_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "stdlib.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "mmi_rp_app_cca_def.h"
#include "stdio.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "gui_data_types.h"
#include "gui.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "cbm_api.h"
#include "mmi_conn_app_trc.h"
/***************************************************************************** 
* Global Variable
*****************************************************************************/
syncml_dm_ota_context_struct syncml_dm_ota_context;
syncml_dm_ota_context_struct *g_syncml_dm_ota_context = &syncml_dm_ota_context;

/* the bool variable identifies whether there has profile which has been updated */ 
MMI_BOOL b_profile_updated = MMI_FALSE; 

static U8 gui_valid_flag = 0;

static U32 prov_flag = 0; /* the variable records the provisioning flag of the profile */

static U8 g_provurl[DM_MD5_HASH_LENGTH];/* the provurl of the provisioning document */
/***************************************************************************** 
* External Variable
*****************************************************************************/
extern dmui_context_struct *ptr_dmui_context;
extern U8 g_mmi_dmui_cbm_id;

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* External Function
*****************************************************************************/
extern void mmi_dm_print_info(dm_account_struct *ptr_dm_account);
extern int applib_url_check_ip(const char *addr, int len);
/*****************************************************************************
* Local Function 
*****************************************************************************/

mmi_ret mmi_dmui_ota_screen_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_EXIT:
            mmi_frm_scrn_set_leave_proc(
                GRP_ID_DMAPP_OTA,
                SCR_ID_DM_OTA_PROVISIONING_INFO,
                NULL);
            mmi_frm_scrn_set_leave_proc(
                GRP_ID_DMAPP_OTA,
                SCR_ID_DM_OTA_SERVERID_LIST,
                NULL);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_handle_app_configure
 * DESCRIPTION
 *  This function is responsible for processing a CCA document
 *  relevant to SYNCML DM
 * PARAMETERS
 *  newConfigDoc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/*
 * CCA Change 
 * void mmi_syncml_dm_proc_cca_doc(U16 conf_id, S32 doc_hdl)
 */
void mmi_syncml_dm_handle_app_configure(mmi_cca_app_configure_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*
     * Mapping table used to extract the SYNCML settings for each profile.
     */
    const U16 proc_tbl[] = 
    {
        CCA_NS_TRIGNODE, CCA_NS_OMA_BOOTSTRAP,
        CCA_NS_SYNCML_DM_BOOTSTRAP, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY,
        CCA_NS_SYNCML_DM_PROXY, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PORT,
        CCA_NS_SYNCML_DM_PORT, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PXAUTHINFO,
        CCA_NS_SYNCML_DM_PXAUTHINFO, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION,
        CCA_NS_SYNCML_DM_APPLICATION, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPADDR,
        CCA_NS_SYNCML_DM_APPADDR, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_PORT,
        CCA_NS_SYNCML_DM_APPPORT, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPAUTH,
        CCA_NS_SYNCML_DM_APPAUTH, 0xFFFF
    };

    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_DM_PROC_CCA_DOC, newConfigDoc->config_id, newConfigDoc->hConfig);

    if (g_syncml_dm_ota_context == NULL)
    {
        MMI_ASSERT(0);
        return;
    }

    memset(g_provurl, 0x00, DM_MD5_HASH_LENGTH);

    memset(g_syncml_dm_ota_context, 0x00, sizeof(syncml_dm_ota_context_struct));

    g_syncml_dm_ota_context->conf_id = newConfigDoc->config_id;
    g_syncml_dm_ota_context->doc_hdl = newConfigDoc->hConfig;

    /* Extract data SYNCML DM settings from CCA configuration document, and store 
       settings in the temporary storage. */
    status = mmi_cca_doc_process(
                newConfigDoc->hConfig,
                proc_tbl,
                sizeof(proc_tbl) / sizeof(U16),
                NULL,
                (CCA_FP_NODE_PROC)mmi_syncml_dm_proc_cca_nodes,
                g_syncml_dm_ota_context);

    g_syncml_dm_ota_context->total_valid_profiles = mmi_syncml_dm_get_valid_profile_num();
    
    /* If there is no correct SYNCML profile, send a INVALID_SETTING response message back to CCA. */
    if (0 == g_syncml_dm_ota_context->total_valid_profiles)
    {
        /* Now, terminate the SYNCML OTA provisioning application. */
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_CCA_INVALID_SETTING);
        
        b_profile_updated = MMI_FALSE;
        
        memset(g_provurl, 0x00, DM_MD5_HASH_LENGTH);

        mmi_dmui_send_cca_app_configure_rsp(
            g_syncml_dm_ota_context->conf_id,
            g_syncml_dm_ota_context->doc_hdl,
            CCA_STATUS_INVALID_SETTING);
        return;
    }

    
    /* provisioning information screen GUI is NULL */
    gui_valid_flag = 0;

    prov_flag = newConfigDoc->prov_flag;

    b_profile_updated = MMI_FALSE;
    mmi_syncml_dm_entry_installation_pre();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_free_otap_proxy
 * DESCRIPTION
 *  The function frees memory of the control block, and clears the proxy ptr.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_free_otap_proxy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_FREE_SYNCML_OTA_CNTX);

    /* Nothing to do. Return. */
    if (g_syncml_dm_ota_context == NULL)
    {
        MMI_ASSERT(0);
    }

    /* Free all proxy. */
    for (i = 0; i < MAX_SYNCML_DM_PROFILES; i++)
    {
        if (g_syncml_dm_ota_context->proxy[i] != NULL)
        {
            OslMfree(g_syncml_dm_ota_context->proxy[i]);
            g_syncml_dm_ota_context->proxy[i] = NULL;
        }
    }
    /* Free the control block. */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_new_otap_proxy
 * DESCRIPTION
 *  This function allocates a temporary storage for SYNC profile. And it will
 *  turn on the flag such that we can process subsequent nodes/parameters
 *  again.
 * PARAMETERS
 *  cntx        [IN]        Control block for SYNC OTA provisioning
 * RETURNS
 *  On success, return the index of the newly allocated profile. Otherwise,
 *  return -1, i.e., an invalid index.
 *****************************************************************************/
S16 mmi_syncml_dm_new_otap_proxy(syncml_dm_ota_context_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* No more temporary profile storage. */
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_NEW_OTAP_PROXY);

    if (cntx->num_proxy == MAX_SYNCML_DM_PROFILES)
    {
        return -1;
    }

    /* Obtain the index. */
    index = cntx->num_proxy;

    /* Allocate memory for the profile. */
    cntx->proxy[index] = (mmi_dm_ota_conn_setting_struct*) OslMalloc(sizeof(mmi_dm_ota_conn_setting_struct));
    if (cntx->proxy[index] == NULL)
    {
        return -1;
    }

    memset(cntx->proxy[index], 0x00, sizeof(mmi_dm_ota_conn_setting_struct));

    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_proc_cca_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]        Configuration document handle
 *  node_hdl        [IN]        The node handle
 *  symbol          [IN]        The converted node symbol
 *  param_list      [IN]        List of parameters in the node
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum mmi_syncml_dm_proc_cca_nodes(
                        S32 doc_hdl,
                        S32 node_hdl,
                        U16 symbol,
                        cca_iterator_struct *param_list,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    syncml_dm_ota_context_struct *cntx;
    cca_status_enum status = 0;
    cca_core_data_struct *param;
    S16 index_profile, index_proxy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (syncml_dm_ota_context_struct*) user_data;
    index_profile = cntx->num_profiles;
    index_proxy = cntx->num_proxy;

    switch (symbol)
    {
        case CCA_NS_SYNCML_DM_BOOTSTRAP:
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case CCA_NS_OMA_PROVURL:
                    {
                        if (param->values.s[0])
                        {
                            if (Is_ANSII_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                mmi_cca_generate_hash_value(
                                    (S8*) param->values.s[0],
                                    g_provurl,
                                    DM_MD5_HASH_LENGTH
                                    );
                            }
                        }
                        break;
                    }
                    
                    case CCA_NS_OMA_NAME:
                    {
                        if (param->values.s[0])
                        {
                        }
                        break;
                    }
                    
                    default:
                        break;
                }
            }
            
            status = CCA_STATUS_OK;
            break;
        }
        
        case CCA_NS_SYNCML_DM_PROXY:    /* 0 */
        {
            index_proxy = mmi_syncml_dm_new_otap_proxy(cntx);

            ASSERT(index_proxy != -1);

            cntx->num_proxy++;

            if (cntx->num_proxy > MAX_SYNCML_DM_PROFILES)
            {
                return CCA_STATUS_OK;
            }

            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case CCA_NS_OMA_PROXY_ID:   /* 0x0c02 */
                        if (param->values.s[0])
                        {
                            if (Is_ANSII_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                mmi_cca_generate_hash_value(
                                        (S8*) param->values.s[0],
                                    cntx->proxy[index_proxy]->proxy_id, 
                                    DM_MD5_HASH_LENGTH);

                            }
                        }
                        break;

                    case CCA_NS_OMA_PROXY_PW:   /* 0x0c03 */
                        if (param->values.s[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_PPGAUTH_TYPE:   /* 0x0c04 */
                        if (param->values.i[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_PROXY_PROVIDER_ID:  /* 0x0c05 */
                        if (param->values.s[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_NAME:   /* 0x0c06 */
                        if (param->values.s[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_STARTPAGE:  /* 0x0c0a */
                        if (param->values.s[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_BASAUTH_ID: /* 0x0c0b */
                        if (param->values.s[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_BASAUTH_PW: /* 0x0c0c */
                        if (param->values.s[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_PHYSICAL_PROXY_ID:  /* 0x0c17 */
                        if (param->values.s[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_PXADDR: /* 0x0c18 */
                        break;

                    case CCA_NS_OMA_PXADDRTYPE: /* 0x0c19 */
                        break;

                    case CCA_NS_OMA_PXADDR_FQDN:    /* 0x0c1a */
                        if (param->values.s[0])
                        {

                        }
                        break;

                    case CCA_NS_DATAACCTID: /* 0x0403 */
                    {
                        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_DATA_ACCT_ID, param->values.i[0]);

                        cntx->proxy[index_proxy]->data_account_id = param->values.i[0];
                    }
                        break;

                    default:
                        break;

                }
            }
            /* End of while */

            status = CCA_STATUS_OK;
            break;
        }
            /* END of case CCA_NS_SYNCML_DM_PROXY: */

        case CCA_NS_SYNCML_DM_PORT: /* 2 */
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case CCA_NS_OMA_PORTNBR:    /* 0x0c15 */
                        if (param->values.s[0])
                        {
                            if (Is_ANSII_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_PROXY_PORT, param->values.s[0]);

                                cntx->proxy[index_proxy - 1]->proxy_port = atoi(param->values.s[0]);
                            }
                        }
                        break;

                    case CCA_NS_OMA_SERVICE:
                        /* If data isn't whether CCA_NS_VAL_CL_WSP nor CCA_NS_VAL_OTA_HTTP_TO,
                           we pass this node */
                        if (param->values.i[0] != CCA_NS_VAL_OTA_HTTP_TO)
                        {
                            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_OMA_SERVICE, param->values.i[0]);
                        }
                        break;

                    default:
                        break;

                }
            }
            status = CCA_STATUS_OK;
            break;
        }
            /* END of case CCA_NS_SYNCML_DM_PORT: */

        case CCA_NS_SYNCML_DM_PXAUTHINFO:   /* 3 */
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case CCA_NS_OMA_PXAUTH_TYPE:
                        break;

                    case CCA_NS_OMA_PXAUTH_ID:
                        if (param->values.s[0])
                        {
                            if (Is_ANSII_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*) param->values.s[0]);

                                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_PROXY_USER_NAME, param->values.s[0]);

                                if (str_length * 2 < DM_MAX_PROXY_LEN)
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) cntx->proxy[index_proxy - 1]->proxy_user_name,
                                        (S8*) param->values.s[0],
                                        str_length);
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) cntx->proxy[index_proxy - 1]->proxy_user_name,
                                        (S8*) param->values.s[0],
                                        (DM_MAX_PROXY_LEN / 2 - 1));
                                }

                            }
                        }
                        break;

                    case CCA_NS_OMA_PXAUTH_PW:
                        if (param->values.s[0])
                        {
                            if (Is_ANSII_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*) param->values.s[0]);

                                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_PROXY_USER_PW, param->values.s[0]);

                                if (str_length * 2 < DM_MAX_PROXY_LEN)
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) cntx->proxy[index_proxy - 1]->proxy_user_pw,
                                        (S8*) param->values.s[0],
                                        str_length);
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) cntx->proxy[index_proxy - 1]->proxy_user_pw,
                                        (S8*) param->values.s[0],
                                        (DM_MAX_PROXY_LEN / 2 - 1));
                                }

                            }
                        }
                        break;

                    default:
                        break;

                }
            }
            status = CCA_STATUS_OK;
            break;
        }
            /* END of case CCA_NS_SYNCML_DM_PXAUTHINFO: */

        case CCA_NS_SYNCML_DM_APPLICATION:  /* 1 */
        {
            /* When start process this node,we predefine all the node proxy have already been processed */
            /* Prepare a storage for the new profile. And get the new index. */
            if (cntx->num_profiles == MAX_SYNCML_DM_PROFILES)
                return CCA_STATUS_FAIL;

            index_profile = cntx->num_profiles;
            cntx->num_profiles++;

            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case CCA_NS_OMA_APPID:  /* 0c4c *//* syncml dm appid is "w7" */
                        if (param->values.s[0])
                        {
                            if (strcmp((S8*) param->values.s[0], (S8*) "w7") != 0)
                            {
                                return CCA_STATUS_FAIL;
                            }
                            
                            cntx->isvalidprof[index_profile] = MMI_TRUE;
                        }
                        break;

                    case CCA_NS_OMA_NAME:   /* 0c06 *//* acct name & unused */
                        if (strlen(param->values.s[0]))
                        {
                        }
                        break;

                    case CCA_NS_OMA_PROVIDER_ID:    /* provide id */
                        if (param->values.s[0])
                        {
                            if (Is_ANSII_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*) param->values.s[0]);

                                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_SERVER_ID, param->values.s[0]);

                                if (str_length == 0)
                                {
                                    cntx->isvalidprof[index_profile] = MMI_FALSE;
                                    break;
                                }

                                if (str_length * 2 < DM_MAX_ID_STR)
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) cntx->profile[index_profile].server_id,
                                        (S8*) param->values.s[0],
                                        str_length);
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) cntx->profile[index_profile].server_id,
                                        (S8*) param->values.s[0],
                                        (DM_MAX_ID_STR / 2 - 1));

                                    cntx->isvalidprof[index_profile] = MMI_FALSE;
                                }

                            }
                        }
                        break;

                    case CCA_NS_OMA_INIT:
                        if (param->values.s[0])
                        {
                        }
                        break;

                    case CCA_NS_OMA_TO_PROXY:   /* 0x0c50 */
                        if (param->values.s[0])
                        {
                            if (Is_ANSII_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                mmi_cca_generate_hash_value(
                                        (S8*) param->values.s[0],
                                    cntx->profile[index_profile].proxy_id,
                                    DM_MD5_HASH_LENGTH);

                            }
                        }
                        break;

                    case CCA_NS_OMA_ADDR:   /* server address */
                        if (param->values.s[0])
                        {
                            if (Is_ANSII_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*) param->values.s[0]);

                                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_SERVER_ADDR, param->values.s[0]);

                                if (str_length * 2 < DM_MAX_URI_SIZE)
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) cntx->profile[index_profile].server_addr,
                                        (S8*) param->values.s[0],
                                        str_length);
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) cntx->profile[index_profile].server_addr,
                                        (S8*) param->values.s[0],
                                        (DM_MAX_URI_SIZE / 2 - 1));

                                    cntx->isvalidprof[index_profile] = MMI_FALSE;
                                }

                            }
                        }
                        break;

                    case CCA_NS_OMA_ADDRTYPE:   /* must be IPV4 */
                        if (param->values.i[0] != CCA_NS_VAL_IPV4)
                        {
                            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_OMA_ADDRTYPE, param->values.i[0]);

                            return CCA_STATUS_FAIL;
                        }
                        break;

                    default:
                        break;

                }
            }   /* END of while loop */

            status = CCA_STATUS_OK;
            break;
        }
            /* END of case CCA_NS_SYNCML_DM_APPLICATION: */

        case CCA_NS_SYNCML_DM_APPPORT:  /* 2 */
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case CCA_NS_OMA_PORTNBR:    /* 0x0c15 */
                        if (param->values.s[0])
                        {
                            if (Is_ANSII_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_PORT_NUMBER, param->values.s[0]);

                                cntx->profile[index_profile - 1].port_num = atoi(param->values.s[0]);
                            }
                        }
                        break;

                    case CCA_NS_OMA_SERVICE:
                        /* If data isn't whether CCA_NS_VAL_CL_WSP nor CCA_NS_VAL_OTA_HTTP_TO,
                           we pass this node */
                        if (param->values.i[0] != CCA_NS_VAL_OTA_HTTP_TO)
                        {
                            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_OMA_SERVICE, param->values.i[0]);
                        }
                        break;

                    default:
                        break;

                }
            }
            status = CCA_STATUS_OK;
            break;
        }
            /* END of case CCA_NS_SYNCML_DM_APPPORT: */

        case CCA_NS_SYNCML_DM_APPADDR:  /* 4 */
        {
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case CCA_NS_OMA_ADDR:   /* server address */
                        if (param->values.s[0])
                        {
                            if (Is_ANSII_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*) param->values.s[0]);

                                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_SERVER_ADDR, param->values.s[0]);

                                if (str_length * 2 < DM_MAX_URI_SIZE)
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) cntx->profile[index_profile - 1].server_addr,
                                        (S8*) param->values.s[0],
                                        str_length);
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) cntx->profile[index_profile - 1].server_addr,
                                        (S8*) param->values.s[0],
                                        (DM_MAX_URI_SIZE / 2 - 1));

                                    cntx->isvalidprof[index_profile - 1] = MMI_FALSE;

                                    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_OVERFLOW_NODE_INFO);
                                }
                            }
                        }
                        break;

                    case CCA_NS_OMA_ADDRTYPE:   /* must be IPV4 */
                        if (param->values.i[0] != CCA_NS_VAL_IPV4)
                        {
                            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_OMA_ADDRTYPE, param->values.i[0]);
                            return CCA_STATUS_FAIL;
                        }
                        break;

                    default:
                        break;

                }
            }

            status = CCA_STATUS_OK;
            break;
        }
            /* END of case CCA_NS_SYNCML_DM_APPADDR: */

        case CCA_NS_SYNCML_DM_APPAUTH:  /* 6 */
        {
            mmi_dm_ota_appauth_struct auth_data;

            memset(&auth_data, 0x00, sizeof(mmi_dm_ota_appauth_struct));

            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK)
            {
                switch (param->id)
                {
                    case CCA_NS_OMA_AAUTHLEVEL:
                        /* Predefine this param is received earlier than any other params of this node.
                           If authlevel is not CCA_NS_VAL_CLIENT,we pass this node */
                        switch (param->values.i[0])
                        {
                            case CCA_NS_VAL_APPSRV: /* save AAUTHNAME AAUTHSECRET as username userpassword */
                                auth_data.auth_level = CCA_NS_VAL_APPSRV;
                                break;

                            case CCA_NS_VAL_OBEX:
                                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_CCA_OBEX);
                                return CCA_STATUS_FAIL;
                                break;

                            case CCA_NS_VAL_CLIENT:
                                auth_data.auth_level = CCA_NS_VAL_CLIENT;
                                break;

                            default:
                                return CCA_STATUS_FAIL;
                                break;
                        }
                        break;

                    case CCA_NS_OMA_AAUTHTYPE:
                    {
                        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_AUTH_PREF, param->values.i[0]);

                        switch (param->values.i[0])
                        {
                            case CCA_NS_VAL_BASIC:  /* BASIC auth Type */
                                auth_data.auth_pref = DM_AUTH_TYPE_BASIC;
                                break;

                            case CCA_NS_VAL_DIGEST: /* MD5 auth type */
                                auth_data.auth_pref = DM_AUTH_TYPE_MD5;
                                break;

                            case CCA_NS_VAL_HMAC:   /* HMAC auth type */
                                auth_data.auth_pref = DM_AUTH_TYPE_HMAC;
                                break;

                            case CCA_NS_VAL_HTTP_BASIC:
                            case CCA_NS_VAL_HTTP_DIGEST:
                            case CCA_NS_VAL_WTLS_SS:
                            case CCA_NS_VAL_X509:
                            case CCA_NS_VAL_SECURID:
                            case CCA_NS_VAL_SAFEWORD:
                            case CCA_NS_VAL_DIGIPASS:
                                return CCA_STATUS_FAIL;
                                break;

                            default:    /* None auth type */
                                auth_data.auth_pref = DM_AUTH_TYPE_NONE;
                                break;

                        }
                    }
                        break;

                    case CCA_NS_OMA_AAUTHNAME:  /* user name */
                        if (param->values.s[0])
                        {
                            if (Is_ANSII_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*) param->values.s[0]);

                                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_AUTH_NAME, param->values.s[0]);

                                if (str_length * 2 < DM_MAX_ID_STR)
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) auth_data.auth_name,
                                        (S8*) param->values.s[0],
                                        str_length);
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) auth_data.auth_name,
                                        (S8*) param->values.s[0],
                                        (DM_MAX_ID_STR / 2 - 1));

                                    cntx->isvalidprof[index_profile - 1] = MMI_FALSE;

                                    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_OVERFLOW_NODE_INFO);
                                }
                            }
                            break;

                        }
                        break;

                    case CCA_NS_OMA_AAUTHSECRET:    /* user password */
                        if (param->values.s[0])
                        {
                            if (Is_ANSII_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*) param->values.s[0]);

                                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_AUTH_PW, param->values.s[0]);

                                if (str_length * 2 < DM_MAX_ID_STR)
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) auth_data.auth_pw,
                                        (S8*) param->values.s[0],
                                        str_length);
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) auth_data.auth_pw,
                                        (S8*) param->values.s[0],
                                        (DM_MAX_ID_STR / 2 - 1));

                                    cntx->isvalidprof[index_profile - 1] = MMI_FALSE;

                                    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_OVERFLOW_NODE_INFO);
                                }
                            }
                        }
                        break;

                    case CCA_NS_OMA_AAUTHDATA:  /* nonce name */
                        if (param->values.s[0])
                        {
                            if (Is_ANSII_format((S8*) param->values.s[0]) == MMI_TRUE)
                            {
                                U8 str_length = strlen((S8*) param->values.s[0]);

                                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_PROC_AUTH_NONCE, param->values.s[0]);

                                if (str_length * 2 < DM_MAX_NAME_STR)
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) auth_data.auth_nonce,
                                        (S8*) param->values.s[0],
                                        str_length);
                                }
                                else
                                {
                                    mmi_syncml_dm_ansii2unicode(
                                        (S8*) auth_data.auth_nonce,
                                        (S8*) param->values.s[0],
                                        (DM_MAX_NAME_STR / 2 - 1));

                                    cntx->isvalidprof[index_profile - 1] = MMI_FALSE;

                                    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_OVERFLOW_NODE_INFO);
                                }
                            }
                        }
                        break;

                    default:
                        break;

                }
            }

            switch (auth_data.auth_level)
            {
                case CCA_NS_VAL_APPSRV:
                {
                    mmi_ucs2cpy((S8*) cntx->profile[index_profile - 1].server_pw, (S8*) auth_data.auth_pw);

                    mmi_ucs2cpy((S8*) cntx->profile[index_profile - 1].server_nonce, (S8*) auth_data.auth_nonce);
                }
                    break;

                case CCA_NS_VAL_CLIENT:
                {
                    mmi_ucs2cpy((S8*) cntx->profile[index_profile - 1].user_name, (S8*) auth_data.auth_name);

                    mmi_ucs2cpy((S8*) cntx->profile[index_profile - 1].user_pw, (S8*) auth_data.auth_pw);

                    mmi_ucs2cpy((S8*) cntx->profile[index_profile - 1].client_nonce, (S8*) auth_data.auth_nonce);

                    cntx->profile[index_profile - 1].auth_pref = auth_data.auth_pref;
                }
                    break;

                default:
                    break;
            }

            status = CCA_STATUS_OK;
            break;
        }

        default:
            return CCA_STATUS_OK;
            break;

    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_get_valid_profile_num
 * DESCRIPTION
 *  This function checks if there is any valid profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
U8 mmi_syncml_dm_get_valid_profile_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, num = 0;
    U8 temp_url_addr[DM_MAX_URI_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_GET_VALID_PROFILE_NUM);

    for (i = 0; i < g_syncml_dm_ota_context->num_profiles; i++)
    {
    
        memcpy(
            g_syncml_dm_ota_context->profile[i].provurl,
            g_provurl,
            DM_MD5_HASH_LENGTH);
        
        if (mmi_ucs2strlen((S8*) g_syncml_dm_ota_context->profile[i].server_id) == 0)
        {
            g_syncml_dm_ota_context->isvalidprof[i] = MMI_FALSE;
        }

        if (&g_syncml_dm_ota_context->profile[i])   /* only to judge the profiles exist in buffer. */
        {
            if (g_syncml_dm_ota_context->isvalidprof[i] == MMI_TRUE)    /* only to judge the profiles mapped already */
            {
                /*************************************************************************************
                *                               Check params of DM setting                           *
                *************************************************************************************/
                /* check server address valid or not */
                memset(temp_url_addr, 0x00, DM_MAX_URI_SIZE);
                mmi_ucs2_to_asc((S8*) temp_url_addr, (S8*) g_syncml_dm_ota_context->profile[i].server_addr);
                if (applib_url_is_valid((const char*)temp_url_addr) != 0)
                {
                    g_syncml_dm_ota_context->isvalidprof[i] = MMI_FALSE;
                }

                /* check address type */
                /* when address not ipv4 return fail to CCA */

                /* check server password when */
                if (mmi_ucs2strlen((S8*) g_syncml_dm_ota_context->profile[i].server_pw) == 0)
                {
                    g_syncml_dm_ota_context->isvalidprof[i] = MMI_FALSE;
                }

                /* check server nonce */
                if (mmi_ucs2strlen((S8*) g_syncml_dm_ota_context->profile[i].server_nonce) == 0)
                {
                    g_syncml_dm_ota_context->isvalidprof[i] = MMI_FALSE;
                }

                /* check user name */
                if (mmi_ucs2strlen((S8*) g_syncml_dm_ota_context->profile[i].user_name) == 0)
                {
                    g_syncml_dm_ota_context->isvalidprof[i] = MMI_FALSE;
                }

                /* check data account id(not support CSD mode) */
                for (j = 0; j < g_syncml_dm_ota_context->num_proxy; j++)
                {
                    if (!memcmp(g_syncml_dm_ota_context->proxy[j]->proxy_id,
                                g_syncml_dm_ota_context->profile[i].proxy_id,
                                DM_MD5_HASH_LENGTH))
                    {
                        if (srv_dtcnt_get_bearer_type((U32)g_syncml_dm_ota_context->proxy[j]->data_account_id, SRV_DTCNT_ACCOUNT_PRIMARY) == 
                                DATA_ACCOUNT_BEARER_CSD)
                        {
                            g_syncml_dm_ota_context->isvalidprof[i] = MMI_FALSE;
                        }
                    }
                }

                /*************************************************************************************
                *                       Check params of Connection setting                           *
                *************************************************************************************/
                /* need compare proxy id and valid or invalid proxy id and data account id */
                {
                    U8 j = 0;

                    for (j = 0; j < g_syncml_dm_ota_context->num_proxy; j++)
                    {
                        U8 proxy_usr_flag = 1;
                        srv_dtcnt_prof_proxy_info_struct proxy_info = {0};

                        if (mmi_ucs2cmp(
                                (S8*) g_syncml_dm_ota_context->profile[i].proxy_id,
                                (S8*) g_syncml_dm_ota_context->proxy[j]->proxy_id) == 0)
                        {
                            memset(
                                &g_syncml_dm_ota_context->profile[i].conn_setting,
                                0x00,
                                sizeof(mmi_dm_ota_conn_setting_struct));

                            /* add data account id */
                            g_syncml_dm_ota_context->profile[i].conn_setting.data_account_id =
                                g_syncml_dm_ota_context->proxy[j]->data_account_id;

                            /* add proxy IP */
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
                            #endif
                            break;
                        }
                    }

                    /* match proxy ID failed */
                    if (j == g_syncml_dm_ota_context->num_proxy)
                    {
                        memset(
                            &g_syncml_dm_ota_context->profile[i].conn_setting,
                            0x00,
                            sizeof(mmi_dm_ota_conn_setting_struct));

                        g_syncml_dm_ota_context->profile[i].conn_setting.data_account_id = CBM_DEFAULT_ACCT_ID;

                        g_syncml_dm_ota_context->profile[i].conn_setting.proxy_port = (U32) 0;

                        mmi_ucs2cpy(
                            (S8*) g_syncml_dm_ota_context->profile[i].conn_setting.proxy_addr,
                            (S8*) L"0.0.0.0");

                        g_syncml_dm_ota_context->profile[i].conn_setting.proxy_used = MMI_FALSE;
                    }
                }
            }
        }

        if (g_syncml_dm_ota_context->isvalidprof[i] == MMI_TRUE)
        {
            num++;
        }
    }

    mmi_syncml_dm_free_otap_proxy();

    return num;

}


void mmi_syncml_dm_entry_installation_pre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        mmi_cca_get_root_group(),
        GRP_ID_DMAPP_OTA,
        mmi_dmui_ota_screen_group_proc,
        (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_OTA, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_syncml_dm_entry_installation();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_entry_installation
 * DESCRIPTION
 *  This function shows information about a incoming profile. And ask users
 *  whether they want to install the profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_entry_installation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *info;
    U8 *gui_buffer = NULL;
    U8 i = 0;
    U8 current_valid = 0;
    U8 tmp[DM_MAX_URI_SIZE * ENCODING_LENGTH];
    S8 tmpnum[4 * ENCODING_LENGTH];
    mmi_dm_ota_account_struct *prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Obtain the current interesting profile. */
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_ENTRY_INSTALLATION);

    while ((g_syncml_dm_ota_context->isvalidprof[g_syncml_dm_ota_context->iter] == MMI_FALSE) && 
           (g_syncml_dm_ota_context->iter < MAX_SYNCML_DM_PROFILES))
    {
        /* current profile index */
        g_syncml_dm_ota_context->iter++;
        g_syncml_dm_ota_context->setting_status = CCA_STATUS_ENDKEY_INVALID_SETTING;
    }

    if (g_syncml_dm_ota_context->iter == MAX_SYNCML_DM_PROFILES)
    {
        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_OTA,
            SCR_ID_DM_OTA_PROVISIONING_INFO,
            NULL);
        return;
    }

    mmi_syncmal_dm_justify_profile_update(&g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter]);
    
    /* Obtain a temporary buffer to show messages. */
    info = (S8*) subMenuData;

    for (i = 0; i < g_syncml_dm_ota_context->iter + 1; i++)
    {
        if (g_syncml_dm_ota_context->isvalidprof[i])
        {
            /* current profile number index */
            current_valid++;
        }
    }

    prof = (mmi_dm_ota_account_struct*) (&g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter]);

#ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    /* Profile name */
    mmi_ucs2cpy(info, GetString(STR_ID_CCA_SYNCMLDM));
    mmi_ucs2cat(info, (S8*) L": ");
    mmi_ucs2cat(info, (S8*) prof->server_id);
    mmi_ucs2cat(info, (S8*) L"\n\n");

    /* Current profile num */
    mmi_ucs2cat(info, (S8*) GetString(STR_ID_DM_OTA_PROFILE));
    sprintf((S8*) & tmpnum, "%d", current_valid);
    memset(tmp, 0, sizeof(tmp));
    mmi_syncml_dm_ansii2unicode((S8*) tmp, (S8*) tmpnum, strlen((S8*) & tmpnum));
    mmi_ucs2cat(info, (S8*) tmp);
    mmi_ucs2cat(info, (S8*) L"/");
    sprintf((S8*) & tmpnum, "%d", g_syncml_dm_ota_context->total_valid_profiles);
    memset(tmp, 0, sizeof(tmp));
    mmi_syncml_dm_ansii2unicode((S8*) tmp, (S8*) tmpnum, strlen((S8*) & tmpnum));
    mmi_ucs2cat(info, (S8*) tmp);
    mmi_ucs2cat(info, (S8*) L"\n\n");

    /* Server address */
    mmi_ucs2cat(info, (S8*) GetString(STR_ID_DM_OTA_SERVER_ADDRESS));
    mmi_ucs2cat(info, (S8*) prof->server_addr);
    mmi_ucs2cat(info, (S8*) L"\n\n");
#else /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    mmi_ucs2cpy(info, GetString(STR_ID_CCA_SYNCMLDM));
    mmi_ucs2cat(info, (S8*) L"\n");

    /* Current profile num */
    mmi_ucs2cat(info, (S8*) GetString(STR_ID_DM_OTA_PROFILE));
    sprintf((S8*) & tmpnum, "%d", current_valid);
    memset(tmp, 0, sizeof(tmp));
    mmi_syncml_dm_ansii2unicode((S8*) tmp, (S8*) tmpnum, strlen((S8*) & tmpnum));
    mmi_ucs2cat(info, (S8*) tmp);
    mmi_ucs2cat(info, (S8*) L"/");
    sprintf((S8*) & tmpnum, "%d", g_syncml_dm_ota_context->total_valid_profiles);
    memset(tmp, 0, sizeof(tmp));
    mmi_syncml_dm_ansii2unicode((S8*) tmp, (S8*) tmpnum, strlen((S8*) & tmpnum));
    mmi_ucs2cat(info, (S8*) tmp);
    mmi_ucs2cat(info, (S8*) L"\n");

    /* Update info */
    if (g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].match_upadte)
    {
        mmi_ucs2cat(info, GetString(STR_ID_CCA_UPDATE_PROFILE));
        mmi_ucs2cat(info, (S8*) L"\n");
    }
    mmi_ucs2cat(info, (S8*) L"\n");

    /* Profile name */
    mmi_ucs2cat(info, (S8*) GetString(STR_ID_DM_OTA_SERVERID));
    mmi_ucs2cat(info, (S8*) prof->server_id);
    mmi_ucs2cat(info, (S8*) L"\n");

    /* Server address */
    mmi_ucs2cat(info, (S8*) GetString(STR_ID_DM_OTA_SERVER_ADDRESS));
    mmi_ucs2cat(info, (S8*) prof->server_addr);
    mmi_ucs2cat(info, (S8*) L"\n");
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_OTA,
                        SCR_ID_DM_OTA_PROVISIONING_INFO,
                        NULL,
                        (FuncPtr)mmi_syncml_dm_entry_installation, 
                        MMI_FRM_FULL_SCRN))
    {
        if (gui_valid_flag != current_valid)    /* first in this screen or entry this screen with a new profile */
        {
            gui_valid_flag = current_valid;
            gui_buffer = NULL;
        }
        else if (gui_valid_flag == current_valid)
        {
            gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        }

        ShowCategory74Screen(
            STR_ID_CCA_INSTALL_SETTING,
            GetRootTitleIcon(MENU_ID_DMUI_MAIN),
            STR_GLOBAL_INSTALL,
            0,
            STR_ID_CCA_SKIP,
            0,
            (U8*) info,
            MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_syncml_dm_find_empty_profile, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_syncml_dm_display_skip_confirm, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_syncml_dm_find_empty_profile, KEY_EVENT_UP);
        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_OTA,
            SCR_ID_DM_OTA_PROVISIONING_INFO,
            mmi_dmui_ota_install_leave_proc);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_find_empty_profile
 * DESCRIPTION
 *  find a empty profile or a exist profile has a same server id to replace
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_find_empty_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
#ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    mmi_confirm_property_struct arg;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Find an empty profile. */
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_FIND_EMPTY_PROFILE);
    /* For provisioning inbox, when incoming call interrupt the edit, user can install provisioning at this time */
    mmi_frm_group_close(GRP_ID_DMAPP_SETTING);

#ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    for (i = 0; i < MAX_SYNCML_DM_PROFILES; i++)
    {
        /* if the server id is exist */
        if (mmi_ucs2cmp(
                (S8*) ptr_dmui_context->dmui_profile_array[i].server_id,
                (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id) == 0)
        {
            /* Pop up exist server id screen and wait user select */
            mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
            arg.parent_id = GRP_ID_DMAPP_OTA;
            arg.callback = mmi_dmui_ota_exist_replace_cnf_cb;
            mmi_confirm_display(
                (WCHAR*)GetString(STR_ID_DM_OTA_SERVERID_EXIST_REPLACE),
                MMI_EVENT_QUERY,
                &arg);

            g_syncml_dm_ota_context->edit_serverid_index = i;

            return;
        }
    }
#else /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    if (g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].match_upadte)
    {
        mmi_syncml_dm_install_profile();
        return ;
    }
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    for (i = 0; i < MAX_SYNCML_DM_PROFILES; i++)
    {
        if (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_profile_array[i].server_id) == 0)
        {
            /* add this profile to DM PS and save to NVRAM */
            mmi_syncml_dm_install_profile();

            return;
        }
    }

#ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    /* Can not find a empty profile. Enter profile replacement. */
    mmi_syncml_dm_entry_replacement();
#else /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    mmi_syncml_dm_server_id_list();
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
}


mmi_ret mmi_dmui_ota_exist_replace_cnf_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_syncml_dm_install_profile();
            break;

        case MMI_ALERT_CNFM_NO:
            mmi_syncml_dm_display_skip_confirm();
            break;

        default:
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_display_skip_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_display_skip_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_common_cancel_with_sg(GRP_ID_DMAPP_OTA, STR_ID_CCA_SKIP_PROFILE, mmi_syncml_dm_next_profile);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_ota_install_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dmui_ota_install_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_EXIT_INSTALL);
    if (evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_CCA_ENDKEY_PRESSED);
    if (b_profile_updated)
    {
        g_syncml_dm_ota_context->setting_status = CCA_STATUS_ENDKEY_SETTING_UPDATED;
    }
	else if (g_syncml_dm_ota_context->setting_status == CCA_STATUS_OK)
	{
		g_syncml_dm_ota_context->setting_status = CCA_STATUS_ENDKEY_PRESSED;
	}

    mmi_dmui_send_cca_app_configure_rsp(
        g_syncml_dm_ota_context->conf_id,
        g_syncml_dm_ota_context->doc_hdl,
        g_syncml_dm_ota_context->setting_status);
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_next_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_next_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_NEXT_PROFILE);
    mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_OTA, SCR_ID_DM_OTA_PROVISIONING_INFO);
    mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_OTA, SCR_ID_DM_OTA_SERVERID_LIST);
    if (g_syncml_dm_ota_context->num_installed == 0)
    {
        g_syncml_dm_ota_context->setting_status = CCA_STATUS_ENDKEY_SETTING_SKIPPED;
    }
    else
    {
        g_syncml_dm_ota_context->setting_status = CCA_STATUS_ENDKEY_SETTING_INSTALLED;
    }

    /* Increase the index of the iterator to process next profile. */
    g_syncml_dm_ota_context->iter++;

    /* Whether there is another profile needed to be installed. */
    if (g_syncml_dm_ota_context->iter < g_syncml_dm_ota_context->num_profiles)
    {
        if (g_syncml_dm_ota_context->isvalidprof[g_syncml_dm_ota_context->iter])
        {
            /* Try to install next profile */
            mmi_syncml_dm_entry_installation_pre();
        }
        else
        {
            mmi_syncml_dm_next_profile();
        }
    }
    else
    {
        /* Send a response back to CCA and free memory. */
        if (g_syncml_dm_ota_context->num_installed == 0)
        {
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_CCA_SETTING_SKIPPED);
            
            mmi_dmui_send_cca_app_configure_rsp(
                g_syncml_dm_ota_context->conf_id,
                g_syncml_dm_ota_context->doc_hdl,
                CCA_STATUS_SETTING_SKIPPED);
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_CCA_OK_STATUS);
#ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
            mmi_dmui_send_cca_app_configure_rsp(
                g_syncml_dm_ota_context->conf_id,
                g_syncml_dm_ota_context->doc_hdl,
                CCA_STATUS_OK);
#else /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
            if (b_profile_updated)
            {
                b_profile_updated = MMI_FALSE;
                
                mmi_dmui_send_cca_app_configure_rsp(
                    g_syncml_dm_ota_context->conf_id,
                    g_syncml_dm_ota_context->doc_hdl,
                    CCA_STATUS_SETTING_UPDATED);
            }
            else
            {
                mmi_dmui_send_cca_app_configure_rsp(
                    g_syncml_dm_ota_context->conf_id,
                    g_syncml_dm_ota_context->doc_hdl,
                    CCA_STATUS_OK);
            }
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
        }
    }
}


#ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_entry_replacement
 * DESCRIPTION
 *  display replace screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_entry_replacement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_ENTRY_REPLACEMENT);
    mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
    arg.parent_id = GRP_ID_DMAPP_OTA;
    arg.callback = mmi_dmui_ota_full_replace_cnf_cb;
    arg.softkey[0].str = (WCHAR*)GetString(STR_GLOBAL_YES);
    arg.softkey[0].img = GetImage(IMG_GLOBAL_YES);
    arg.softkey[1].img = GetImage(IMG_GLOBAL_COMMON_CSK);
    arg.softkey[2].str = (WCHAR*)GetString(STR_ID_CCA_SKIP);
    arg.softkey[2].img = GetImage(IMG_GLOBAL_NO);
    mmi_confirm_display(
        (WCHAR*)GetString(STR_ID_DM_OTA_SERVERID_FULL_REPLACE),
        MMI_EVENT_QUERY,
        &arg);
}

mmi_ret mmi_dmui_ota_full_replace_cnf_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
        case MMI_ALERT_CNFM_1:
        case MMI_ALERT_CNFM_2:
            mmi_syncml_dm_server_id_list();
            break;

        case MMI_ALERT_CNFM_3:
            mmi_syncml_dm_display_skip_confirm();
            break;

        default:
            break;
        }
    }
    return MMI_RET_OK;
}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_install_profile
 * DESCRIPTION
 *  entry install profile process and save profile to DM PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_install_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U8 temp_nodename[DM_MAX_ID_STR];
    dm_add_account_struct *dm_ota_add_account = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_INSTALL_PROFILE);

    dm_ota_add_account = OslAllocDataPtr(dm_add_account_struct);

    memset(temp_nodename, 0x00, DM_MAX_ID_STR);

#ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    /* search the same server id */
    for (i = 0; i < MAX_SYNCML_DM_PROFILES; i++)
    {
        if (mmi_ucs2cmp(
                (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id,
                (S8*) ptr_dmui_context->dmui_profile_array[i].server_id) == 0)
        {
            gui_itoa((U32) i, (UI_string_type) temp_nodename, 10);
            break;
        }
    }

    /* find same server id and get the node name */
    if (mmi_ucs2strlen((S8*) temp_nodename) == 0)
    {
        for (i = 0; i < MAX_SYNCML_DM_PROFILES; i++)
        {
            if (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_profile_array[i].server_id) == 0)
            {
                gui_itoa((U32) i, (UI_string_type) temp_nodename, 10);
                break;
            }
        }
    }
#else /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    if (g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].match_upadte)
    {
        for (i = 0; i < MAX_SYNCML_DM_PROFILES; i++)
        {
            if (mmi_ucs2cmp(
                    (S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].server_id,
                    (S8*) ptr_dmui_context->dmui_profile_array[i].server_id) == 0)
            {
                gui_itoa((U32) i, (UI_string_type) temp_nodename, 10);
                break;
            }
        }
    }

    if (mmi_ucs2strlen((S8*) temp_nodename) == 0)
    {
        for (i = 0; i < MAX_SYNCML_DM_PROFILES; i++)
        {
            if (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_profile_array[i].server_id) == 0)
            {
                gui_itoa((U32) i, (UI_string_type) temp_nodename, 10);
                break;
            }
        }
    }
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    
    g_syncml_dm_ota_context->edit_serverid_index = i;
    /* set current node name string to profile */
    mmi_ucs2cpy((S8*) g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter].node_name, (S8*) temp_nodename);

    /* set value to dm_ota_add_account struct */
    mmi_syncml_dm_set_value(
        &dm_ota_add_account->dm_account,
        &g_syncml_dm_ota_context->profile[g_syncml_dm_ota_context->iter]);

    ptr_dmui_context->dmui_status = MMI_DM_OTA_ADD_ACCOUNT_STATUS;

    mmi_dm_print_info(&dm_ota_add_account->dm_account);

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_ADD_ACCOUNT_REQ, dm_ota_add_account);
    mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_OTA, SCR_ID_DM_OTA_PROVISIONING_INFO);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_set_value
 * DESCRIPTION
 *  set value of dm_account_struct
 * PARAMETERS
 *  ptr_dm_account      [IN]        
 *  ptr_dm_ota          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_set_value(dm_account_struct *ptr_dm_account, mmi_dm_ota_account_struct *ptr_dm_ota)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_SET_VALUE);
    MMI_ASSERT(ptr_dm_account != NULL);
    MMI_ASSERT(ptr_dm_ota != NULL);

    /* ------------------   application ---------------------- */
    /* app port number */
    ptr_dm_account->port_num = ptr_dm_ota->port_num;

    /* app auth type */
    ptr_dm_account->auth_pref = ptr_dm_ota->auth_pref;

    /* app address type (only support ipV4 now) */
    ptr_dm_account->addr_type = ptr_dm_ota->addr_type;

    /* app node name string */
    mmi_ucs2cpy((S8*) ptr_dm_account->node_name, (S8*) ptr_dm_ota->node_name);

    /* app server address */
    mmi_ucs2cpy((S8*) ptr_dm_account->server_addr, (S8*) ptr_dm_ota->server_addr);

    /* app server id */
    mmi_ucs2cpy((S8*) ptr_dm_account->server_id, (S8*) ptr_dm_ota->server_id);

    /* app server password */
    mmi_ucs2cpy((S8*) ptr_dm_account->server_pw, (S8*) ptr_dm_ota->server_pw);

    /* app server nonce */
    mmi_ucs2cpy((S8*) ptr_dm_account->server_nonce, (S8*) ptr_dm_ota->server_nonce);

    /* app user name */
    mmi_ucs2cpy((S8*) ptr_dm_account->user_name, (S8*) ptr_dm_ota->user_name);

    /* app user password */
    mmi_ucs2cpy((S8*) ptr_dm_account->user_pw, (S8*) ptr_dm_ota->user_pw);

    /* app client nonce */
    mmi_ucs2cpy((S8*) ptr_dm_account->client_nonce, (S8*) ptr_dm_ota->client_nonce);

    /* app acct name */
    mmi_ucs2cpy((S8*) ptr_dm_account->acct_name, (S8*) ptr_dm_ota->acct_name);

    /* app provurl */
    memcpy(ptr_dm_account->provurl, ptr_dm_ota->provurl, DM_MD5_HASH_LENGTH);

    /* app proxy id */
    memcpy(ptr_dm_account->proxy_id, ptr_dm_ota->proxy_id, DM_MD5_HASH_LENGTH);

    /* app read only flag */
    ptr_dm_account->read_only = ptr_dm_ota->read_only;

    /* app profile type */
    ptr_dm_account->profile_type = ptr_dm_ota->profile_type;
    
    /* ---------------------    connection setting -------------------- */
    /* connection setting type */
    mmi_ucs2cpy((S8*) ptr_dm_account->conn_setting.conn_ref, (S8*) ptr_dm_ota->conn_setting.conn_ref);

    /* connection setting proxy address */
    mmi_ucs2cpy((S8*) ptr_dm_account->conn_setting.proxy_addr, (S8*) ptr_dm_ota->conn_setting.proxy_addr);

    /* connection setting proxy user name */
    mmi_ucs2cpy((S8*) ptr_dm_account->conn_setting.proxy_user_name, (S8*) ptr_dm_ota->conn_setting.proxy_user_name);

    /* connection setting proxy user password */
    mmi_ucs2cpy((S8*) ptr_dm_account->conn_setting.proxy_user_pw, (S8*) ptr_dm_ota->conn_setting.proxy_user_pw);

    /* connection setting proxy port number */
    ptr_dm_account->conn_setting.proxy_port = ptr_dm_ota->conn_setting.proxy_port;

    /* connection setting data account id */
    ptr_dm_account->conn_setting.data_account_id = 
        cbm_encode_data_account_id(ptr_dm_ota->conn_setting.data_account_id, 0, g_mmi_dmui_cbm_id, 0);

    /* connection setting proxy used or not */
    ptr_dm_account->conn_setting.proxy_used = ptr_dm_ota->conn_setting.proxy_used;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_send_cca_app_configure_rsp
 * DESCRIPTION
 *  send MSG_ID_MMI_CCA_APP_CONFIGURE_RSP
 * PARAMETERS
 *  conf_id     [IN]        
 *  doc_hdl     [IN]        
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_send_cca_app_configure_rsp(U16 conf_id, S32 doc_hdl, cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_configure_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_configure_rsp_struct*) OslConstructDataPtr(sizeof(mmi_cca_app_configure_rsp_struct));
    data->config_id = conf_id;
    data->hConfig = doc_hdl;
    data->status = status;

    /* Send the response message. */
    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_CCA_APP_CONFIGURE_RSP;
    message.oslDataPtr = (oslParaType*) data;
    message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_server_id_list
 * DESCRIPTION
 *  entry server id list screen and wait user select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_server_id_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 *gui_buffer = NULL;
    PU8 sub_menu_data_ptrs[DMUI_MAX_SERVERID];
    U16 serverid_states_icon[DMUI_MAX_SERVERID];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_ENTRY_SERVERID_LIST);
    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_OTA, 
                        SCR_ID_DM_OTA_SERVERID_LIST,
                        NULL,
                        (FuncPtr)mmi_syncml_dm_server_id_list, 
                        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        RegisterHighlightHandler(mmi_syncml_dm_server_id_list_select);

        for (i = 0; i < DMUI_MAX_SERVERID; i++)
        {
            if ((*ptr_dmui_context->dmui_profile_array[i].server_id== 0) && (*(ptr_dmui_context->dmui_profile_array[i].server_id + 1) == 0))
            {
                sub_menu_data_ptrs[i] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);

                serverid_states_icon[i] = IMG_ID_DMUI_NO_IMAGE;
            }
            else
            {
                sub_menu_data_ptrs[i] = (U8*) ptr_dmui_context->dmui_profile_array[i].server_id;

                if ((mmi_ucs2cmp((S8*) sub_menu_data_ptrs[i], (S8*) ptr_dmui_context->dmui_primary_serverid) == 0)
                    && (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_primary_serverid) != 0))
                {
                    serverid_states_icon[i] = IMG_ID_DMUI_SEL_IMAGE;
                }
                else
                {
                    serverid_states_icon[i] = IMG_ID_DMUI_NO_IMAGE;
                }
            }
        }

#ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        ShowCategory73Screen(
            STR_ID_DMUI_MAIN,
            GetRootTitleIcon(MENU_ID_DMUI_MAIN),
            STR_GLOBAL_SELECT,
            0,
            STR_ID_CCA_SKIP,
            0,
            DMUI_MAX_SERVERID,
            sub_menu_data_ptrs,
            serverid_states_icon,
            (U16*) gIndexIconsImageList,
            0,
            gui_buffer,
            1);
#else /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
        ShowCategory73Screen(
            STR_ID_CCA_REPLACE_SETTING,
            GetRootTitleIcon(MENU_ID_DMUI_MAIN),
            STR_GLOBAL_INSTALL,
            0,
            STR_GLOBAL_BACK,
            0,
            DMUI_MAX_SERVERID,
            sub_menu_data_ptrs,
            serverid_states_icon,
            (U16*) gIndexIconsImageList,
            0,
            gui_buffer,
            1);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_OTA,
            SCR_ID_DM_OTA_PROVISIONING_INFO,
            NULL);
        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_OTA,
            SCR_ID_DM_OTA_SERVERID_LIST,
            mmi_dmui_ota_install_leave_proc);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_server_id_list_select
 * DESCRIPTION
 *  entry server id list screen and wait user select
 * PARAMETERS
 *  index       [OUT]       Current index of high light
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_server_id_list_select(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_dm_ota_context->edit_serverid_index = (U32) index;

    SetLeftSoftkeyFunction(mmi_syncml_dm_replace_profile, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_syncml_dm_replace_profile, KEY_EVENT_UP);

#ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    SetRightSoftkeyFunction(mmi_syncml_dm_display_skip_confirm, KEY_EVENT_UP);
#else /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    SetRightSoftkeyFunction(mmi_syncml_dm_back_from_serverid_list, KEY_EVENT_UP);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_replace_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_replace_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_server_id_struct *ptr_dm_ota_del = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_dm_ota_del = OslAllocDataPtr(dm_server_id_struct);

    mmi_ucs2cpy(
        (S8*) ptr_dm_ota_del->server_id,
        (S8*) ptr_dmui_context->dmui_profile_array[g_syncml_dm_ota_context->edit_serverid_index].server_id);

    ptr_dmui_context->dmui_status = MMI_DM_OTA_REPACE_ACTIVATED_DEL_ACCOUNT_STATUS;

    DMUI_SEND_MSG_TO_DMPS(MSG_ID_DM_DEL_ACCOUNT_REQ, ptr_dm_ota_del);
    mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_OTA, SCR_ID_DM_OTA_PROVISIONING_INFO);
    mmi_dmui_remove_non_del_screen(GRP_ID_DMAPP_OTA, SCR_ID_DM_OTA_SERVERID_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_ansii2unicode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pOutBuffer      [IN]        
 *  pInBuffer       [IN]        
 *  len             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_ansii2unicode(S8 *pOutBuffer, S8 *pInBuffer, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2((S8*) pOutBuffer, (S8*) pInBuffer, (U32) len);
}


/*****************************************************************************
 * FUNCTION
 *  Is_ANSII_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [IN]        
 * RETURNS
 *  MMI_TRUE    Input buffer is ANSII
 *  MMI_FALSE   Input buffer not ANSII
 *****************************************************************************/
MMI_BOOL Is_ANSII_format(S8 *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *p = dest;
    U8 ansii_max_value = 127;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dest == NULL)
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_NULL_ASCII_POINT);

    while (*p != '\0')
    {
        if (*p < ansii_max_value)
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

/***************************************************************************
*                       
***************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_send_cca_dm_get_profile
 * DESCRIPTION
 *  This function to send profile information to CCA
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_send_cca_dm_get_profile(cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_get_prof_rsp_struct *data;

    S32 hconfig, hroot, hnode, temnode, connect_type;
    dm_account_struct dm_profile;
    U8 temp_str[DM_MAX_ID_STR * ENCODING_LENGTH];
    S8 tempint[10];
    S8 temp_ip_addr[4][DMUI_MAX_IPADDRES_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_SEND_CCA_DM_GET_PROFILE);

    memset(&dm_profile, 0x00, sizeof(dm_account_struct));

    memcpy(&dm_profile, &ptr_dmui_context->dmui_cur_edit_account, sizeof(dm_account_struct));

    hroot = mmi_cca_doc_new_rootnode();

    if (!hroot)
    {
        MMI_ASSERT(0);
    }

    /* add proxy node */
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PROXY, hroot);
    if (!hnode)
    {
        mmi_cca_docroot_release(hroot);
        MMI_ASSERT(0);
    }

    /* add node ID */
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_NODEID, "PROXY_1");

    /* add proxy ID */
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_PROXY_ID, "PROXY_1");

    /* translate and add IP address */
    mmi_ucs2_to_asc((S8*) temp_ip_addr, (S8*) dm_profile.conn_setting.proxy_addr);
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_PXADDR, (S8*) temp_ip_addr);

    /* add proxy address type */
    mmi_cca_doc_add_nodedata_int(hnode, CCA_NS_OMA_PXADDRTYPE, CCA_NS_VAL_IPV4);

    /* add data account id */
    mmi_cca_doc_add_nodedata_int(hnode, CCA_NS_DATAACCTID, (S32) dm_profile.conn_setting.data_account_id);

    /* add proxy port node */
    temnode = hnode;
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PORT, temnode);

    /* add proxy port */
    sprintf((S8*) tempint, "%d", (U32) dm_profile.conn_setting.proxy_port);
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_PORTNBR, (S8*) tempint);

    /* add connect type */
    /*
     * connect_type = (dm_profile.conn_type == SYNCML_TRANS_HTTP) ? CCA_NS_VAL_OTA_HTTP_TO : CCA_NS_VAL_CL_WSP;
     */
    /* NOW DM only support HTTP */
    connect_type = CCA_NS_VAL_OTA_HTTP_TO;
    mmi_cca_doc_add_nodedata_int(hnode, CCA_NS_OMA_SERVICE, (S32) connect_type);

    /* add proxy auth info node */
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PXAUTHINFO, temnode);

    /* add proxy user name */
    mmi_ucs2_to_asc((S8*) temp_str, (S8*) dm_profile.conn_setting.proxy_user_name);
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_PXAUTH_ID, (S8*) temp_str);

    mmi_ucs2_to_asc((S8*) temp_str, (S8*) dm_profile.conn_setting.proxy_user_pw);
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_PXAUTH_PW, (S8*) temp_str);

    /* add application node */
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPLICATION, hroot);
    if (!hnode)
    {
        mmi_cca_docroot_release(hroot);
        MMI_ASSERT(0);
    }
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_NODEID, "APPLICATION_1");
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_APPID, "w7");

    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_TO_PROXY, "PROXY_1");

    mmi_ucs2_to_asc((S8*) temp_str, (S8*) dm_profile.server_id);
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_PROVIDER_ID, (S8*) temp_str);

    /* add app address node */
    temnode = hnode;
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPADDR, temnode);

    mmi_ucs2_to_asc((S8*) temp_ip_addr, (S8*) dm_profile.server_addr);
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_ADDR, (S8*) temp_ip_addr);

    /* add app auth node */
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPAUTH, temnode);

    mmi_cca_doc_add_nodedata_int(hnode, CCA_NS_OMA_AAUTHLEVEL, CCA_NS_VAL_APPSRV);

    mmi_ucs2_to_asc((S8*) temp_str, (S8*) dm_profile.server_id);
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_AAUTHNAME, (S8*) temp_str);

    mmi_ucs2_to_asc((S8*) temp_str, (S8*) dm_profile.server_pw);
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_AAUTHSECRET, (S8*) temp_str);

    mmi_ucs2_to_asc((S8*) temp_str, (S8*) dm_profile.server_nonce);
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_AAUTHDATA, (S8*) temp_str);

    /* add app auth node 2 */
    hnode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPAUTH, temnode);

    mmi_cca_doc_add_nodedata_int(hnode, CCA_NS_OMA_AAUTHLEVEL, CCA_NS_VAL_CLIENT);

    mmi_ucs2_to_asc((S8*) temp_str, (S8*) dm_profile.user_name);
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_AAUTHNAME, (S8*) temp_str);

    mmi_ucs2_to_asc((S8*) temp_str, (S8*) dm_profile.user_pw);
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_AAUTHSECRET, (S8*) temp_str);

    mmi_ucs2_to_asc((S8*) temp_str, (S8*) dm_profile.client_nonce);
    mmi_cca_doc_add_nodedata_str(hnode, CCA_NS_OMA_AAUTHDATA, (S8*) temp_str);

    switch (dm_profile.auth_pref)
    {
        case DM_AUTH_TYPE_BASIC:
            mmi_cca_doc_add_nodedata_int(hnode, CCA_NS_OMA_AAUTHTYPE, (S32) CCA_NS_VAL_BASIC);
            break;

        case DM_AUTH_TYPE_MD5:
            mmi_cca_doc_add_nodedata_int(hnode, CCA_NS_OMA_AAUTHTYPE, (S32) CCA_NS_VAL_DIGEST);
            break;

        case DM_AUTH_TYPE_HMAC:
            mmi_cca_doc_add_nodedata_int(hnode, CCA_NS_OMA_AAUTHTYPE, (S32) CCA_NS_VAL_HMAC);
            break;

        default:
            mmi_cca_doc_add_nodedata_int(hnode, CCA_NS_OMA_AAUTHTYPE, (S32) 0);
            break;

    }

    hconfig = mmi_cca_doc_new(hroot);

    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_get_prof_rsp_struct*) OslConstructDataPtr(sizeof(mmi_cca_app_get_prof_rsp_struct));
    data->app_id = ptr_dmui_context->app_id;
    data->prof_id = ptr_dmui_context->prof_id;
    data->hConfig = hconfig;
    data->result = status;

    /* Send the response message. */
    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_CCA_APP_GET_PROF_RSP;
    message.oslDataPtr = (oslParaType*) data;
    message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_handle_get_profile
 * DESCRIPTION
 *  This function to send profile information from DM PS
 * PARAMETERS
 *  newConfigDoc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/*
 * CCA Change 
 * void mmi_syncml_dm_send_cca_get_prof_rsp(U16 app_id, S32 prof_id)
 */
void mmi_syncml_dm_handle_get_profile(mmi_cca_app_get_prof_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_SEND_CCA_DM_GET_PROF_RSP, newConfigDoc->app_id, newConfigDoc->prof_id);

    ptr_dmui_context->app_id = newConfigDoc->app_id;
    ptr_dmui_context->prof_id = newConfigDoc->prof_id;

    /* if server id array not init */
    if (mmi_ucs2strlen((S8*) ptr_dmui_context->dmui_profile_array[DM_DEFAULT_PROFILE_INDEX].server_id) == 0)
    {
        mmi_syncml_send_cca_dm_get_profile(CCA_STATUS_FAIL);
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_INVALID_DEFAULT_PROFILE);
        return ;
    }

    if (dm_get_account(
            ptr_dmui_context->dmui_profile_array[DM_DEFAULT_PROFILE_INDEX].server_id,
            &ptr_dmui_context->dmui_cur_edit_account) == KAL_TRUE)
    {
        mmi_dm_print_info(&ptr_dmui_context->dmui_cur_edit_account);

        mmi_syncml_send_cca_dm_get_profile(CCA_STATUS_OK);
    }
    else
    {
        mmi_syncml_send_cca_dm_get_profile(CCA_STATUS_FAIL);
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_OTA_GET_DM_ACCOUNT_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_handle_update_profile
 * DESCRIPTION
 *  This function to receive update request from CCA
 * PARAMETERS
 *  newConfigDoc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/*
 * CCA Change
 * void mmi_syncml_dm_send_cca_update_prof_rsp(U16 app_id, S32 prof_id, S32 hConfig)
 */
void mmi_syncml_dm_handle_update_profile(mmi_cca_app_update_prof_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_nodename[DM_MAX_ID_STR];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    const U16 proc_tbl[] = 
    {
        CCA_NS_TRIGNODE, CCA_NS_OMA_BOOTSTRAP,
        CCA_NS_SYNCML_DM_BOOTSTRAP, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY,
        CCA_NS_SYNCML_DM_PROXY, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PORT,
        CCA_NS_SYNCML_DM_PORT, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PXAUTHINFO,
        CCA_NS_SYNCML_DM_PXAUTHINFO, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION,
        CCA_NS_SYNCML_DM_APPLICATION, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPADDR,
        CCA_NS_SYNCML_DM_APPADDR, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_PORT,
        CCA_NS_SYNCML_DM_APPPORT, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPAUTH,
        CCA_NS_SYNCML_DM_APPAUTH, 0xFFFF
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_SEND_CCA_UPDATE_PROF_RSP, newConfigDoc->app_id, newConfigDoc->prof_id);

    if (g_syncml_dm_ota_context == NULL)
    {
        MMI_ASSERT(0);
    }

    memset(g_syncml_dm_ota_context, 0x00, sizeof(syncml_dm_ota_context_struct));

    ptr_dmui_context->app_id = newConfigDoc->app_id;

    ptr_dmui_context->prof_id = newConfigDoc->prof_id;

    ptr_dmui_context->hConfig = newConfigDoc->hConfig;

    memset(temp_nodename, 0x00, DM_MAX_ID_STR);

    mmi_cca_doc_process(
        newConfigDoc->hConfig,
        proc_tbl,
        sizeof(proc_tbl) / sizeof(U16),
        NULL,
        mmi_syncml_dm_proc_cca_nodes,
        g_syncml_dm_ota_context);

    /* If there is no correct SYNCML profile, send a INVALID_SETTING response message back to CCA. */
    if (mmi_syncml_dm_get_valid_profile_num() == 0)
    {
        /* Now, terminate the SYNCML OTA provisioning application. */
        mmi_syncml_dm_send_cca_update_prof_end(CCA_STATUS_FAIL);
        return;
    }

    gui_itoa((U32) DM_DEFAULT_PROFILE_INDEX, (UI_string_type) temp_nodename, 10);

    mmi_ucs2cpy((S8*) g_syncml_dm_ota_context->profile[0].node_name, (S8*) temp_nodename);

    mmi_syncml_dm_set_value(&ptr_dmui_context->dmui_cur_edit_account, &g_syncml_dm_ota_context->profile[0]);

    mmi_dm_print_info(&ptr_dmui_context->dmui_cur_edit_account);

    /* add account struct to DM PS */
    if (dm_add_account(&ptr_dmui_context->dmui_cur_edit_account) == KAL_TRUE)
    {
        mmi_ucs2cpy(
            (S8*) ptr_dmui_context->dmui_profile_array[DM_DEFAULT_PROFILE_INDEX].server_id,
            (S8*) ptr_dmui_context->dmui_cur_edit_account.server_id);

        if (dm_set_pid((U8*) ptr_dmui_context->dmui_cur_edit_account.server_id) == KAL_TRUE)
        {
            mmi_ucs2cpy(
                (S8*) ptr_dmui_context->dmui_primary_serverid,
                (S8*) ptr_dmui_context->dmui_cur_edit_account.server_id);

            mmi_syncml_dm_send_cca_update_prof_end(CCA_STATUS_OK);
        }
        else
        {
            mmi_syncml_dm_send_cca_update_prof_end(CCA_STATUS_FAIL);
        }

        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

    }
    else
    {
        ptr_dmui_context->dmui_status = MMI_DMUI_IDLE_STATUS;

        mmi_syncml_dm_send_cca_update_prof_end(CCA_STATUS_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_send_cca_update_prof_end
 * DESCRIPTION
 *  This function to send update result to CCA
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_send_cca_update_prof_end(cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_update_prof_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_SEND_CCA_UPDATE_PROF_END, status);

    data = (mmi_cca_app_update_prof_rsp_struct*) OslConstructDataPtr(sizeof(mmi_cca_app_update_prof_rsp_struct));
    data->app_id = ptr_dmui_context->app_id;
    data->prof_id = ptr_dmui_context->prof_id;
    data->hConfig = ptr_dmui_context->hConfig;
    data->result = status;

    /* Send the response message. */
    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_MMI;
    message.oslMsgId = MSG_ID_MMI_CCA_APP_UPDATE_PROF_RSP;
    message.oslDataPtr = (oslParaType*) data;
    message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncmal_dm_justify_profile_update
 * DESCRIPTION
 *  This function justifies whether the new provisioning profile matches the 
 *  update rule
 * PARAMETERS
 *  pAccount     [IN]   the new received provisioning DM profile     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncmal_dm_justify_profile_update(mmi_dm_ota_account_struct *pAccount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DMOTAP_JUSTIFY_PROFILE_UPDATE, pAccount); 
    
    for (i = 0; i < MAX_SYNCML_DM_PROFILES; i++)
    {
        if (0 == mmi_ucs2cmp(
                    (S8*) ptr_dmui_context->dmui_profile_array[i].server_id,
                    (S8*) pAccount->server_id))
        {
            pAccount->match_upadte = MMI_TRUE;
            return;
        }
    }

    pAccount->match_upadte = MMI_FALSE;
    return ;
}


#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dm_back_from_serverid_list
 * DESCRIPTION
 *  This function goes back the former screen  
 * PARAMETERS
 *  pAccount     [IN]   the new received provisioning DM profile     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dm_back_from_serverid_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_set_leave_proc(
        GRP_ID_DMAPP_OTA,
        SCR_ID_DM_OTA_SERVERID_LIST,
        NULL);
    mmi_frm_scrn_close_active_id();

    return;
}
#endif
#endif /* __MMI_SYNCML_DM_OTAP__ */ 

