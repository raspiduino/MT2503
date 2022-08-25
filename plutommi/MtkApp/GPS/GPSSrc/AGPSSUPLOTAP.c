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
 * AGPSSUPLOTAP.c
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_AGPS_OTAP__
#include "GlobalConstants.h"
#include "custom_events_notify.h"
#include "DataAccountGProt.h"
#include "CommonScreens.h"
#include "Conversions.h"
#include "DataAccountGProt.h"
#include "UcmSrvGprot.h"
#include "CentralConfigAgentGProt.h"
#include "GlobalResDef.h"
#include "wgui_categories_text_viewer.h"

#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
#include "supl2mmi_enums.h"
#include "supl2mmi_struct.h"
#endif

#include "mdi_datatype.h"
#include "Mdi_gps.h"

#include "GPSResDef.h"
#include "GPSGProt.h"

#include "gpssetting.h"
#include "AGPSSUPLOTAP.h"
#include "Mmi_rp_app_cca_def.h"
#include "wgui_categories_util.h"
#include "cbm_api.h"
#include "mmi_rp_srv_gps_def.h"

static const U16 cca_mapping_supl[] =
{
    CCA_NS_TRIGNODE, CCA_NS_OMA_BOOTSTRAP, MMI_SUPL_NS_OMA_BOOTSTRAP, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, MMI_SUPL_NS_OMA_PROXY, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, MMI_SUPL_NS_OMA_APP, 0xFFFF,
    CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPADDR, MMI_SUPL_NS_OMA_APPADDR, 0xFFFF,
};


static mmi_supl_ota_context_struct g_mmi_supl_ota_context;
U16 g_profile_name[NVRAM_EF_AGPS_PROFILE_TOTAL][AGPS_MAX_PROFILE_NAME_LEN];

static void mmi_supl_ota_init(mmi_cca_app_configure_ind_struct *ind);
static void mmi_supl_ota_handle_ota(mmi_cca_app_configure_ind_struct *ind);
static cca_status_enum mmi_supl_ota_process_callback_nodes(
                    S32 hConfig,
                    S32 hNode,
                    U16 node_symbol,
                    cca_iterator_struct *iter_datalist,
                    void *user_data);
static cca_status_enum mmi_supl_ota_parse_bootstrap(
                    cca_iterator_struct *iter_datalist,
                    void *user_data);
static cca_status_enum mmi_supl_ota_parse_proxy(
                    cca_iterator_struct *iter_datalist,
                    void *user_data);
static cca_status_enum mmi_supl_ota_handle_proxy_params(cca_core_data_struct *data, void *user_data);
static cca_status_enum mmi_supl_ota_parse_app(
                    cca_iterator_struct *iter_datalist,
                    void *user_data);
static cca_status_enum mmi_supl_ota_handle_app_params(cca_core_data_struct *data, void *user_data);
static cca_status_enum mmi_supl_ota_parse_appaddr(
                    cca_iterator_struct *iter_datalist,
                    void *user_data);
static cca_status_enum mmi_supl_ota_handle_appaddr_params(cca_core_data_struct *data, void *user_data);

static void mmi_supl_ota_is_valid_info(void);
static MMI_BOOL mmi_supl_ota_check_one_profile(U8 index);
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
static MMI_BOOL mmi_supl_ota_match_profile(U8 index);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
static void mmi_supl_ota_entry_ota_setting(void);
static mmi_ret mmi_supl_ota_abort(mmi_event_struct dummy);
static void mmi_supl_ota_string(CHAR* buffer);
static void mmi_supl_ota_skip_confirm(void);
static void mmi_supl_ota_skip_yes(void);
static void mmi_supl_ota_install(void);
static void mmi_supl_ota_save_a_profile(U8 index);
static void mmi_supl_entry_ota_prof_list(void);
static void mmi_supl_ota_prof_list_highlight_hdlr(S32 index);
void mmi_supl_ota_select(void);

static S16 mmi_supl_ota_get_empty_item_index(void);
static S16 mmi_supl_ota_get_proxy_index(const CHAR *px_id);

static void mmi_supl_send_cca_conf_rsp(cca_status_enum status);

static MMI_BOOL mmi_supl_is_ascii_string(const U8 *utf8_str);
static MMI_BOOL mmi_supl_check_white_spaces(CHAR *string);

void mmi_supl_ota_install_status(void);
void mmi_supl_ota_check_next_profile(void);

#if (MMI_SIM_TOTAL > 1)
    static U8 get_log2(U16 sim_id);
#endif

extern kal_bool applib_is_valid_url_wchar(kal_wchar ch);
extern int applib_url_is_valid(const CHAR *url);


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_otap_group_install_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  param  [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_supl_otap_group_install_proc(mmi_event_struct * param)
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
            break;
        }
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        {
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rtsp_handle_app_configure
 * DESCRIPTION
 *
 * PARAMETERS
 *  newconfigdoc   [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_supl_handle_app_configure(mmi_cca_app_configure_ind_struct *newconfigdoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // MMI_ASSERT (g_mmi_supl_ota_context_p == NULL);
    mmi_supl_ota_init(newconfigdoc);

	if (mmi_frm_group_is_present(g_mmi_supl_ota_context.cur_gid))
    {
        mmi_frm_group_close(g_mmi_supl_ota_context.cur_gid);
    }
    g_mmi_supl_ota_context.cur_gid = mmi_frm_group_create(mmi_cca_get_root_group(), GRP_ID_AUTO_GEN, mmi_supl_otap_group_install_proc, NULL);
    mmi_frm_group_enter(g_mmi_supl_ota_context.cur_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_supl_ota_handle_ota(newconfigdoc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_init
 * DESCRIPTION
 *  Initialize OTA structure
 * PARAMETERS
 *  ind         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_supl_ota_init(mmi_cca_app_configure_ind_struct *ind)
{
/*  if (mmi_frm_scrn_is_present(SCR_ID_GPS_SETTING_MAIN))
    {
        //mmi_dtcnt_delete_select_screen();
        mmi_ime_delete_editor_common_scr(SCR_ID_GPS_SETTING_INPUT_EDITOR_OPTION);
        mmi_ime_delete_editor_common_scr(SCR_ID_GPS_SETTING_INPUT_EDITOR);
    }

    for (i = SCR_ID_GPS_SETTING_MAIN; i <= SCR_ID_GPS_SETTING_DUMMY; i++)
    {
        mmi_delete_scrn_if_present(i);
    }*/

/*  MMI_ASSERT (g_mmi_supl_ota_context_p == NULL);
    g_mmi_supl_ota_context_p = (mmi_supl_ota_context_struct*) OslMalloc(sizeof(mmi_supl_ota_context_struct));
    kal_mem_set(g_mmi_supl_ota_context_p, 0, sizeof(mmi_supl_ota_context_struct));
*/
    g_mmi_supl_ota_context.config_id = ind->config_id;
    g_mmi_supl_ota_context.config_handle = ind->hConfig;
#if(MMI_SIM_TOTAL > 1)
		g_mmi_supl_ota_context.sim_id = ind->sim_id;
		g_mmi_supl_ota_context.sim_profile_id = get_log2(g_mmi_supl_ota_context.sim_id);
#else
		g_mmi_supl_ota_context.sim_id = 1;
		g_mmi_supl_ota_context.sim_profile_id = 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_handle_ota
 * DESCRIPTION
 *  handle CCA document
 * PARAMETERS
 *  ind         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_supl_ota_handle_ota(mmi_cca_app_configure_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_SIM_TOTAL > 1)
    MMI_BOOL is_sim_card_valid = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind == NULL)
    {
        return;
    }

    if (ind->prov_type != MMI_CCA_PROV_TYPE_OTA_PROV)
    {
        mmi_supl_send_cca_conf_rsp(CCA_STATUS_INVALID_SETTING);
        return;
    }

#if(MMI_SIM_TOTAL > 3)
    if (g_mmi_supl_ota_context.sim_id == MMI_SIM4)
    {
       is_sim_card_valid = MMI_TRUE;
    }
#endif

#if(MMI_SIM_TOTAL > 2)
    if (g_mmi_supl_ota_context.sim_id == MMI_SIM3)
    {
       is_sim_card_valid = MMI_TRUE;
    }
#endif
#if(MMI_SIM_TOTAL > 1)
    if (g_mmi_supl_ota_context.sim_id == MMI_SIM2 || g_mmi_supl_ota_context.sim_id == MMI_SIM1)
    {
       is_sim_card_valid = MMI_TRUE;
    }

    if (is_sim_card_valid == MMI_FALSE)
    {
        mmi_supl_send_cca_conf_rsp(CCA_STATUS_INVALID_SETTING);
		return;
    }
#endif

    mmi_cca_doc_process(
        ind->hConfig,
        cca_mapping_supl,
        sizeof(cca_mapping_supl) / sizeof(U16),
        NULL,
        mmi_supl_ota_process_callback_nodes,
        NULL);

    mmi_supl_ota_is_valid_info();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_process_callback_nodes
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
static cca_status_enum mmi_supl_ota_process_callback_nodes(
                    S32 hConfig,
                    S32 hNode,
                    U16 node_symbol,
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (node_symbol)
    {
        case MMI_SUPL_NS_OMA_BOOTSTRAP:
            mmi_supl_ota_parse_bootstrap(iter_datalist, user_data);
            break;

        case MMI_SUPL_NS_OMA_PROXY:
            mmi_supl_ota_parse_proxy(iter_datalist, user_data);
            break;

        case MMI_SUPL_NS_OMA_APP:
            mmi_supl_ota_parse_app(iter_datalist, user_data);
            break;

        case MMI_SUPL_NS_OMA_APPADDR:
            mmi_supl_ota_parse_appaddr(iter_datalist, user_data);
            break;

        default:
            break;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_parse_bootstrap
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
static cca_status_enum mmi_supl_ota_parse_bootstrap(
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
    if (status != CCA_STATUS_OK || size > 1)
    {
        return CCA_STATUS_FAIL;
    }

    mmi_cca_generate_hash_value(provurl[0], g_mmi_supl_ota_context.provurl,
        CCA_HASH_VALUE_MAX_BYTES);

    mmi_cca_iterator_restart(iter_datalist);
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_parse_proxy
 * DESCRIPTION
 *  The function used to parse proxy node.
 *  fill proxy_id(hash) or sap_id(hash) or data_account
 * PARAMETERS
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  result of processing CCA nodes.
 *  On success, return CCA_STATUS_OK;
 *  Otherwise, return CCA_STATUS_FAIL.
 *****************************************************************************/
static cca_status_enum mmi_supl_ota_parse_proxy(
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
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_supl_ota_get_empty_item_index();
    if (index == NVRAM_EF_AGPS_PROFILE_TOTAL * (g_mmi_supl_ota_context.sim_profile_id+1))
    {
        return CCA_STATUS_FAIL;
    }
    g_mmi_supl_ota_context.curr_index = index;

    status = mmi_cca_doc_get_nodedata_strs(iter_datalist, CCA_NS_OMA_PROXY_ID, &px_id, &size);

    /* one proxy should has only one prxoy id */
    if (status != CCA_STATUS_OK || size != 1)
    {
        return CCA_STATUS_FAIL;
    }
    /* judghe whether this proxy has existed for we only support the first valid proxy for same proxy id */
    if (mmi_supl_ota_get_proxy_index(px_id[0]) != NVRAM_EF_AGPS_PROFILE_TOTAL * (g_mmi_supl_ota_context.sim_profile_id+1))
    {
        return CCA_STATUS_FAIL;
    }

    mmi_cca_iterator_restart(iter_datalist);

    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {/* get proxy_id(hash),nap_id(hash) or data_account */
        status = mmi_supl_ota_handle_proxy_params(data, user_data);
        if (status != CCA_STATUS_OK)
        {
            break;
        }
    }

    if (status != CCA_STATUS_OK)
    {
        return status;
    }

    g_mmi_supl_ota_context.profile_list[index].is_used = MMI_TRUE;
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_handle_proxy_params
 * DESCRIPTION
 *  Handle CCA PROXY node parameters
 * PARAMETERS
 *  data            [IN]        CCA proxy data
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_supl_ota_handle_proxy_params(cca_core_data_struct *data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dataacct_type;
    U8 cbm_reg_ret;
    U8 cbm_app_id;
    mmi_supl_profile_struct *prof = &g_mmi_supl_ota_context.profile_list[g_mmi_supl_ota_context.curr_index];

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
            if (!mmi_supl_is_ascii_string((U8*)data->values.s[0]))
            {
                return CCA_STATUS_FAIL;
            }

            /* Check whether the length of the proxy id is legal. */
            mmi_cca_generate_hash_value(data->values.s[0],
                (U8*)prof->proxy_id,
                CCA_HASH_VALUE_MAX_BYTES);
            break;

        case CCA_NS_OMA_TO_NAPID:
            /* Whether the value is presented and the type is legal. */
            if (data->size <= 0 || data->type != CCA_DT_STR)
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (!mmi_supl_is_ascii_string((U8*)data->values.s[0]))
            {
                return CCA_STATUS_FAIL;
            }

            /* Check whether the length of the proxy id is legal. */
            mmi_cca_generate_hash_value(data->values.s[0],
                (U8*)prof->nap_id,
                CCA_HASH_VALUE_MAX_BYTES);
            break;

        case CCA_NS_DATAACCTID:
            if (data->size <= 0 || data->type != CCA_DT_INT)
            {
                return CCA_STATUS_FAIL;
            }

            dataacct_type = 0;//mmi_dtcnt_get_bearer_type((U8)data->values.i[0]);
            if (dataacct_type & DATA_ACCOUNT_INVALID_ID)
            {
                return CCA_STATUS_FAIL;
            }

            //prof->account_id = data->values.i[0];
            /*prof->account_id= cbm_encode_data_account_id(
                data->values.i[0],
                CBM_SIM_ID_SIM1,
                imps_p->gen_info.cbm_app_id,
                FALSE);*/
			cbm_reg_ret = cbm_register_app_id(&cbm_app_id);
			if(cbm_reg_ret == CBM_OK){
    			switch (g_mmi_supl_ota_context.sim_id)
    			{
                #if(MMI_SIM_TOTAL > 3)
                    case MMI_SIM4:
        				prof->account_id = cbm_encode_data_account_id(
                			(U32)data->values.i[0],
                            CBM_SIM_ID_SIM4,
                			cbm_app_id,
                			MMI_FALSE);
					break;
				#endif
				#if(MMI_SIM_TOTAL > 2)
					case MMI_SIM3:
        				prof->account_id = cbm_encode_data_account_id(
                			(U32)data->values.i[0],
                			CBM_SIM_ID_SIM3,
                			cbm_app_id,
                			MMI_FALSE);
					break;
				#endif
				#if(MMI_SIM_TOTAL > 1)
					case MMI_SIM2:
        				prof->account_id = cbm_encode_data_account_id(
                			(U32)data->values.i[0],
                			CBM_SIM_ID_SIM2,
                			cbm_app_id,
                			MMI_FALSE);
					break;
				#endif
					default:
        				prof->account_id = cbm_encode_data_account_id(
                			(U32)data->values.i[0],
                			CBM_SIM_ID_SIM1,
                			cbm_app_id,
                			MMI_FALSE);
					break;
    			}
			}
            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_parse_app
 * DESCRIPTION
 *  The function used to parse app node.
 *  search usable proxy_id(both in profile and node) and fill name
 * PARAMETERS
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  result of processing CCA nodes.
 *  On success, return CCA_STATUS_OK;
 *  Otherwise, return CCA_STATUS_FAIL.
 *****************************************************************************/
static cca_status_enum mmi_supl_ota_parse_app(
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
    U8 i;
    U8 j;
    MMI_BOOL same_proxy = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = mmi_cca_doc_get_nodedata_strs(iter_datalist, CCA_NS_OMA_TO_PROXY, &px_id, &size);

    /* exist related proxy */
    if (status != CCA_STATUS_OK)
    {
        return CCA_STATUS_FAIL;
    }

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

        index = mmi_supl_ota_get_proxy_index(px_id[i]);
        if (index == NVRAM_EF_AGPS_PROFILE_TOTAL * (g_mmi_supl_ota_context.sim_profile_id+1))
        {
            continue;
        }
        g_mmi_supl_ota_context.curr_index = index;

        mmi_cca_iterator_restart(iter_datalist);

        while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
        {
            status = mmi_supl_ota_handle_app_params(data, user_data);
            if (status != CCA_STATUS_OK)
            {
                break;
            }
        }

        g_mmi_supl_ota_context.profile_list[index].wait_fill_addr = MMI_TRUE;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_handle_app_params
 * DESCRIPTION
 *  Handle CCA application node parameters
 * PARAMETERS
 *  data            [IN]        CCA proxy data
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_supl_ota_handle_app_params(cca_core_data_struct *data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

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
                return CCA_STATUS_FAIL;   /* Error-tolerant for profile's name */
            }

            /* Extract the profile's name. If the name is too long, it will be
               truncated by the function. */
            mmi_chset_utf8_to_ucs2_string(
                (U8*)g_mmi_supl_ota_context.profile_list[g_mmi_supl_ota_context.curr_index].name,
                AGPS_MAX_PROFILE_NAME_LEN * ENCODING_LENGTH,
                (U8*)data->values.s[0]);
            break;

        default:
            break;
    }
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_parse_appaddr
 * DESCRIPTION
 *  The function used to parse app addr node.
 *  fill profile->addr
 * PARAMETERS
 *  iter_datalist       [IN]        List of parameters in the node
 *  user_data           [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_supl_ota_parse_appaddr(
                    cca_iterator_struct *iter_datalist,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data;
    cca_status_enum status = CCA_STATUS_OK;
    U8 i;
    U8 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * g_mmi_supl_ota_context.sim_profile_id;
    for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
//    for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        if (g_mmi_supl_ota_context.profile_list[i].wait_fill_addr)
        {
            g_mmi_supl_ota_context.profile_list[i].addr_type_valid = MMI_FALSE;
        }
    }
    mmi_cca_iterator_restart(iter_datalist);

    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {
        status = mmi_supl_ota_handle_appaddr_params(data, user_data);
        if (status != CCA_STATUS_OK)
        {
            break;
        }
    }

    for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
   // for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        if (g_mmi_supl_ota_context.profile_list[i].wait_fill_addr)
        {
            if (!g_mmi_supl_ota_context.profile_list[i].addr_type_valid)
            {
                g_mmi_supl_ota_context.profile_list[i].is_used = MMI_FALSE;
            }
            else
            {
                g_mmi_supl_ota_context.profile_list[i].wait_fill_addr = MMI_FALSE;
            }
        }
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_handle_appaddr_params
 * DESCRIPTION
 *  Handle CCA application address node parameters
 * PARAMETERS
 *  data            [IN]        CCA proxy data
 *  user_data       [IN]        User data
 * RETURNS
 *  On success, return CCA_STATUS_OK, otherwise return CCA_STATUS_FAIL
 *****************************************************************************/
static cca_status_enum mmi_supl_ota_handle_appaddr_params(cca_core_data_struct *data, void *user_data)
{
    U8 i;
    U8 pos;

    switch (data->id)
    {
        case CCA_NS_OMA_ADDR:
            /* Whether this is a ASCII string. */
            if (!mmi_supl_is_ascii_string((U8*)data->values.s[0]))
            {
                return CCA_STATUS_FAIL;
            }

            if (/*applib_url_is_valid((const CHAR *)value) != 0 ||*/
               mmi_supl_check_white_spaces((CHAR*)data->values.s[0]))
            {
                return CCA_STATUS_FAIL;
            }

	    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * g_mmi_supl_ota_context.sim_profile_id;
	     for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
            //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
            {
                if (g_mmi_supl_ota_context.profile_list[i].wait_fill_addr)
                {
                    kal_wsprintf((WCHAR*)g_mmi_supl_ota_context.profile_list[i].addr, "%s", data->values.s[0]);
                }
            }
            break;

        case CCA_NS_OMA_ADDRTYPE:
	    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * g_mmi_supl_ota_context.sim_profile_id;
	    for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
            //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
            {
                if (g_mmi_supl_ota_context.profile_list[i].wait_fill_addr)
                {
                    g_mmi_supl_ota_context.profile_list[i].addr_type_valid = MMI_TRUE;
                }
            }
            break;

        default:
            break;
    }
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_is_valid_info
 * DESCRIPTION
 *  This function used to judge whether profile is valid.
 *  For OTA, prompt user IMPS_PROF_COUNT profile that may be invalid.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_supl_ota_is_valid_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 pos;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_supl_ota_context.count = 0;

    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * g_mmi_supl_ota_context.sim_profile_id;
    for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
    //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        if (mmi_supl_ota_check_one_profile(i))
        {
            g_mmi_supl_ota_context.count++;
        }
    }

    if (0 == g_mmi_supl_ota_context.count)
    {
        mmi_supl_send_cca_conf_rsp(CCA_STATUS_INVALID_SETTING);
/*        if (g_mmi_supl_ota_context_p == NULL)
        {
            return;
        }

        OslMfree(g_mmi_supl_ota_context_p);
        g_mmi_supl_ota_context_p = NULL;
*/      return;
    }

    for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
    //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        if (g_mmi_supl_ota_context.profile_list[i].is_used)
        {
            g_mmi_supl_ota_context.curr_index = i;
            break;
        }
    }

    mmi_supl_ota_entry_ota_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_check_one_profile
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_supl_ota_check_one_profile(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 pos;
    S32 len;
    U8 is_em_setting_on;
//    S16 error;
    MMI_BOOL is_null;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * g_mmi_supl_ota_context.sim_profile_id;
    if (g_mmi_supl_ota_context.profile_list[index].is_used)
    {
        /*if (g_mmi_supl_ota_context.profile_list[index].account_id < 0)
        {
            g_mmi_supl_ota_context.profile_list[index].is_used = MMI_FALSE;
            return MMI_FALSE;
        }*/

        len = mmi_ucs2strlen((CHAR *)g_mmi_supl_ota_context.profile_list[index].addr);
        if (len <= 0)
        {
            g_mmi_supl_ota_context.profile_list[index].is_used = MMI_FALSE;
            return MMI_FALSE;
        }
        for (i = 0; i < len; i++)
        {
            if (!applib_is_valid_url_wchar(g_mmi_supl_ota_context.profile_list[index].addr[i]))
            {
                g_mmi_supl_ota_context.profile_list[index].is_used = MMI_FALSE;
                return MMI_FALSE;
            }
        }

        g_mmi_supl_ota_context.profile_list[index].match_index = 0xff;
        g_mmi_supl_ota_context.curr_index = index;

    #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        is_null = MMI_TRUE;
        for (i = 0; i < MMI_SUPL_OTA_HASH_LEN; i++)
        {
            if (g_mmi_supl_ota_context.provurl[i] != 0)
            {
                is_null = MMI_FALSE;
                break;
            }
        }
    #endif

	is_em_setting_on = mmi_gps_setting_get_em_on_off();
        if (is_em_setting_on)
        {
        #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
            if (!is_null)
            {
		        for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
                //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
                {
                    if (mmi_supl_ota_match_profile(i))
                    {
                        break;
                    }
                }

                if (i != NVRAM_EF_AGPS_PROFILE_TOTAL * (g_mmi_supl_ota_context.sim_profile_id+1))
                {
                    g_mmi_supl_ota_context.profile_list[index].match_index = i;
                }
            }
        #endif
            return MMI_TRUE;
        }

    #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	if (is_null || !mmi_supl_ota_match_profile(0 + pos))
        //if (is_null || !mmi_supl_ota_match_profile(0))
        {
    #endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
            g_mmi_supl_ota_context.profile_list[index].is_used = MMI_FALSE;
            return MMI_FALSE;
    #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        }
        else
        {
          //  g_mmi_supl_ota_context.profile_list[index].match_index = 0;
	    g_mmi_supl_ota_context.profile_list[index].match_index = 0 + pos;
            return MMI_TRUE;
        }
    #endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    }
    else
    {
        return MMI_FALSE;
    }
}


#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_match_profile
 * DESCRIPTION
 *  whether provurl or nap_id are the same(if null check the name)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_supl_ota_match_profile(U8 index)
{
    nvram_ef_agps_profile_struct nvram_profile;
    U8 i;
    MMI_BOOL is_null;
    MMI_BOOL ret = MMI_FALSE;

    mmi_gps_setting_get_profile(&nvram_profile);
    is_null = MMI_TRUE;
    for (i = 0; i < MMI_SUPL_OTA_HASH_LEN; i++)
    {
        if (nvram_profile.provurl[i] != 0 || nvram_profile.nap_id[i] != 0)
        {
            is_null = MMI_FALSE;
            break;
        }
    }

    if (is_null)
    {
        if (!mmi_ucs2cmp((CHAR*)nvram_profile.name, (CHAR*)g_mmi_supl_ota_context.profile_list[g_mmi_supl_ota_context.curr_index].name))
        {
            ret = MMI_TRUE;
        }
    }
    else
    {
        ret = MMI_TRUE;
        for (i = 0; i < MMI_SUPL_OTA_HASH_LEN; i++)
        {
            if (nvram_profile.provurl[i] != g_mmi_supl_ota_context.provurl[i] ||
                nvram_profile.nap_id[i] != g_mmi_supl_ota_context.profile_list[g_mmi_supl_ota_context.curr_index].nap_id[i])
            {
                ret = MMI_FALSE;
                break;
            }
        }
    }

    return ret;
}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_entry_ota_setting
 * DESCRIPTION
 *  Entry function for screen that display OTA information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_supl_ota_entry_ota_setting(void)
{
    U8 *guiBuffer = NULL;

    mmi_frm_scrn_enter(g_mmi_supl_ota_context.cur_gid, SCR_ID_AGPS_SUPL_OTAP_PROF_INFO, NULL, mmi_supl_ota_entry_ota_setting, MMI_FRM_FULL_SCRN);
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_mmi_supl_ota_context.cur_gid,SCR_ID_AGPS_SUPL_OTAP_PROF_INFO);

    SetParentHandler(0);

    mmi_supl_ota_string((CHAR*)subMenuData);

    ShowCategory78Screen(
        STR_ID_CCA_INSTALL_SETTING,
        GetRootTitleIcon(MENU_ID_GPS_SETTING),
        STR_GLOBAL_INSTALL,
        IMG_GLOBAL_OK,
        STR_ID_CCA_SKIP,
        IMG_GLOBAL_BACK,
        NULL,
        (U8*)subMenuData,
        mmi_ucs2strlen((CHAR*)subMenuData),
        guiBuffer);

    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_supl_ota_install, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(mmi_supl_ota_install, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_supl_ota_skip_confirm, KEY_EVENT_UP);
    mmi_frm_scrn_set_leave_proc(g_mmi_supl_ota_context.cur_gid, SCR_ID_AGPS_SUPL_OTAP_PROF_INFO, mmi_supl_ota_abort);

    /* delete PROF LIST when enter another screen */
    if (mmi_frm_scrn_is_present(g_mmi_supl_ota_context.cur_gid, SCR_ID_AGPS_SUPL_OTAP_PROF_LIST, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(g_mmi_supl_ota_context.cur_gid, SCR_ID_AGPS_SUPL_OTAP_PROF_LIST);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_abort
 * DESCRIPTION
 *  This function should be called to exit the IMPS OTA application. it can
 *  be called when END key is pressed to return to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  When END key is pressed to return to idle screen, return TRUE to stop(?)(?)
 *  delete other nodes in history stack. Here, always return FALSE.(?)(?)
 *****************************************************************************/
static mmi_ret mmi_supl_ota_abort(mmi_event_struct dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //if (g_mmi_supl_ota_context_p== NULL)
  //    return MMI_TRUE;

    /* Terminated. Send a response back to CCA and free memory. */
    mmi_supl_send_cca_conf_rsp(CCA_STATUS_ENDKEY_PRESSED);
  //  OslMfree(g_mmi_supl_ota_context_p);
  //  g_mmi_supl_ota_context_p = NULL;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_string
 * DESCRIPTION
 *  Compose OTA information string
 * PARAMETERS
 *  buffer      [IN/OUT]        Store string of OTA information
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_supl_ota_string(CHAR *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR uc2_temp[200];
    U8 i;
    U8 pos;
    U8 index ;

    mmi_supl_profile_struct *prof = &g_mmi_supl_ota_context.profile_list[g_mmi_supl_ota_context.curr_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* instant message */
    mmi_ucs2cpy(buffer, GetString(STR_ID_CCA_SUPL));
    mmi_ucs2cat(buffer, (CHAR*)L"\n");

    /* profile index */
    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * g_mmi_supl_ota_context.sim_profile_id;
    index = g_mmi_supl_ota_context.curr_index - pos;
    for (i = 0 + pos; i < g_mmi_supl_ota_context.curr_index; i++)
    {
        if (g_mmi_supl_ota_context.profile_list[i].is_used)
        {
            continue;
        }

        index--;
    }
    kal_wsprintf((WCHAR *)uc2_temp, "%d/%d", index + 1, g_mmi_supl_ota_context.count);

    mmi_ucs2cat(buffer, GetString(STR_ID_GPS_SETTING_AGPS_PROFILE));
    mmi_ucs2cat(buffer, GetString(STR_ID_GPS_SETTING_COLON));
    mmi_ucs2cat(buffer, (CHAR*) L" ");
    mmi_ucs2cat(buffer, uc2_temp);
    mmi_ucs2cat(buffer, (CHAR*)L"\n");

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if (g_mmi_supl_ota_context.profile_list[index].match_index != 0xFF)
    {
        mmi_ucs2cat(buffer, GetString(STR_ID_CCA_UPDATE_PROFILE));
        mmi_ucs2cat(buffer, (CHAR*)L"\n");
    }
#endif

    mmi_ucs2cat(buffer, (CHAR*)L"\n");

    /* profile name */
    if (prof->name[0])
    {
        mmi_ucs2cat(buffer, GetString(STR_ID_GPS_SETTING_AGPS_PROFILE_NAME));
        mmi_ucs2cat(buffer, GetString(STR_ID_GPS_SETTING_COLON));
        mmi_ucs2cat(buffer, (CHAR*) L" ");
        mmi_ucs2cat(buffer, (CHAR*)(prof->name));
        mmi_ucs2cat(buffer, (CHAR*)L"\n");
    }

    /* profile addr */
    if (prof->addr[0])
    {
        mmi_ucs2cat(buffer, GetString(STR_GLOBAL_ADDRESS));
        mmi_ucs2cat(buffer, GetString(STR_ID_GPS_SETTING_COLON));
        mmi_ucs2cat(buffer, (CHAR*) L" ");
        mmi_ucs2cat(buffer, (CHAR*)(prof->addr));
        mmi_ucs2cat(buffer, (CHAR*)L"\n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_skip_confirm
 * DESCRIPTION
 *  Call CCA function to show whether skip installing current OTA profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_supl_ota_skip_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_common_cancel_with_sg(g_mmi_supl_ota_context.cur_gid, (U16)STR_ID_CCA_SKIP_PROFILE, mmi_supl_ota_skip_yes);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_skip_yes
 * DESCRIPTION
 *  Skip installing current OTA profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_supl_ota_skip_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_supl_ota_check_next_profile();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_install
 * DESCRIPTION
 *  Install OTA setting, first we need to judge whether OTA parameters are valid.
 *  If there is free proflie slot, we install automatically, otherwise come to
 *  profile select screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_supl_ota_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 is_em_setting_on;
    //S16 error;
    U8 match_index;

    is_em_setting_on = mmi_gps_setting_get_em_on_off();

    if (!is_em_setting_on)
    {
        /* CMCC Version */
        mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_CCA_PROFILE_IN_USE)), MMI_EVENT_FAILURE, NULL);

        return;
    }
    else
    {
    #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        match_index = g_mmi_supl_ota_context.profile_list[g_mmi_supl_ota_context.curr_index].match_index;

        if (match_index == 0)
        {
            mmi_supl_ota_save_a_profile(0);
            g_mmi_supl_ota_context.is_install= MMI_TRUE;
            mmi_supl_ota_check_next_profile();

            return;
        }
        else
        {
            mmi_popup_display((WCHAR*)((UI_string_type)GetString(STR_ID_CCA_PROFILE_IN_USE)), MMI_EVENT_FAILURE, NULL);

            return;
        }
    #endif

        mmi_supl_ota_save_a_profile(0);
        g_mmi_supl_ota_context.is_install= MMI_TRUE;
        mmi_supl_ota_check_next_profile();

        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_save_a_profile
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_supl_ota_save_a_profile(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_agps_profile_struct temp_profile;
    nvram_ef_gps_mmi_sim_struct  temp_sim_setting;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_gps_setting_get_profile(&temp_profile);
    mmi_gps_setting_get_sim_setting(g_mmi_supl_ota_context.sim_id, &temp_sim_setting);

    mmi_ucs2cpy((CHAR*)temp_profile.name, (CHAR*)g_mmi_supl_ota_context.profile_list[g_mmi_supl_ota_context.curr_index].name);
    if (mmi_ucs2strlen((CHAR*)temp_profile.name)== 0)
    {
        kal_wsprintf(temp_profile.name, "Profile %d", index + 1);
    }

    mmi_ucs2cpy((CHAR*)temp_profile.addr, (CHAR*)g_mmi_supl_ota_context.profile_list[g_mmi_supl_ota_context.curr_index].addr);
    temp_sim_setting.data_account = g_mmi_supl_ota_context.profile_list[g_mmi_supl_ota_context.curr_index].account_id;
    temp_profile.port = 7275;
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    memcpy(
        temp_profile.provurl,
        g_mmi_supl_ota_context.provurl,
        sizeof(U8) * MMI_SUPL_OTA_HASH_LEN);
    memcpy(
        temp_profile.nap_id,
        g_mmi_supl_ota_context.profile_list[g_mmi_supl_ota_context.curr_index].nap_id,
        sizeof(U8) * MMI_SUPL_OTA_HASH_LEN);
#endif
    mmi_gps_setting_set_profile(&temp_profile);
    mmi_gps_setting_set_sim_setting(g_mmi_supl_ota_context.sim_id, &temp_sim_setting);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_entry_ota_prof_list
 * DESCRIPTION
 *  Entry screen for list profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_supl_entry_ota_prof_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    nvram_ef_agps_profile_struct temp_profile;
    U8 *nStrItemList[NVRAM_EF_AGPS_PROFILE_TOTAL];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_enter(g_mmi_supl_ota_context.cur_gid, SCR_ID_AGPS_SUPL_OTAP_PROF_LIST, NULL, mmi_supl_entry_ota_prof_list, MMI_FRM_FULL_SCRN);
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_mmi_supl_ota_context.cur_gid,SCR_ID_AGPS_SUPL_OTAP_PROF_LIST);

    for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        mmi_gps_setting_get_profile(&temp_profile);
        mmi_ucs2cpy((CHAR*)g_profile_name[i], (CHAR*)temp_profile.name);

        nStrItemList[i] = (U8*)g_profile_name[i];
    }

    RegisterHighlightHandler(mmi_supl_ota_prof_list_highlight_hdlr);

    ShowCategory353Screen(
        (U8*)GetString(STR_ID_CCA_REPLACE_SETTING),
        GetRootTitleIcon(MENU_ID_GPS_SETTING),     /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NVRAM_EF_AGPS_PROFILE_TOTAL,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);
    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_supl_ota_select, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(mmi_supl_ota_select, KEY_EVENT_UP);
    SetKeyHandler(mmi_supl_ota_select, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* delete PROF INFO when enter another screen */
    if (mmi_frm_scrn_is_present(g_mmi_supl_ota_context.cur_gid, SCR_ID_AGPS_SUPL_OTAP_PROF_INFO, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(g_mmi_supl_ota_context.cur_gid, SCR_ID_AGPS_SUPL_OTAP_PROF_INFO);
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_supl_ota_prof_list_highlight_hdlr
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_supl_ota_prof_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_supl_ota_context.sel_profile_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_select
 * DESCRIPTION
 *  Select overwrite one existing profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_supl_ota_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = (U8)g_mmi_supl_ota_context.sel_profile_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	index += NVRAM_EF_AGPS_PROFILE_TOTAL * (g_mmi_supl_ota_context.sim_profile_id);
    {
        mmi_supl_ota_save_a_profile(index);
        g_mmi_supl_ota_context.is_install= MMI_TRUE;
        mmi_supl_ota_check_next_profile();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_get_empty_item_index
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
static S16 mmi_supl_ota_get_empty_item_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 pos;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos = NVRAM_EF_AGPS_PROFILE_TOTAL * g_mmi_supl_ota_context.sim_profile_id;
    for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
    //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        if (g_mmi_supl_ota_context.profile_list[i].is_used == MMI_FALSE)
        {
            break;
        }
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_get_proxy_index
 * DESCRIPTION
 *  Find relevant profile according proxy_id that relate proxy with application.
 * PARAMETERS
 *  px_id       [IN]        ID used to relate proxy with application
 * RETURNS
 *  If find related profile succesfully, return index of profile.
 *  otherwise return 0xFF.
 *****************************************************************************/
static S16 mmi_supl_ota_get_proxy_index(const CHAR *px_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    U8 temp_id[MMI_SUPL_OTA_HASH_LEN] = {0};
    S16 pos;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(g_mmi_supl_ota_context_p != NULL);

    mmi_cca_generate_hash_value(px_id, (U8*)temp_id, CCA_HASH_VALUE_MAX_BYTES);

	pos = NVRAM_EF_AGPS_PROFILE_TOTAL * g_mmi_supl_ota_context.sim_profile_id;
    for (i = pos; i < NVRAM_EF_AGPS_PROFILE_TOTAL + pos; i++)
    //for (i = 0; i < NVRAM_EF_AGPS_PROFILE_TOTAL; i++)
    {
        if (g_mmi_supl_ota_context.profile_list[i].is_used)
        {
            if (memcmp(g_mmi_supl_ota_context.profile_list[i].proxy_id, temp_id,
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
 *  mmi_supl_send_cca_conf_rsp
 * DESCRIPTION
 *  This function sends the response message back to CCA for the result of
 *  configuration. Once application sends this primitive, no further access
 *  to the configuration document should be made.
 * PARAMETERS
 *  status      [IN]        Configuration result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_supl_send_cca_conf_rsp(cca_status_enum status)
{
    mmi_cca_app_configure_rsp_struct *data;

    data = (mmi_cca_app_configure_rsp_struct*) OslConstructDataPtr(
                                                sizeof(mmi_cca_app_configure_rsp_struct));

    data = OslAllocDataPtr(mmi_cca_app_configure_rsp_struct);

    data->config_id = g_mmi_supl_ota_context.config_id;
    data->hConfig = g_mmi_supl_ota_context.config_handle;
    data->status = status;
    data->sim_id = g_mmi_supl_ota_context.sim_id;

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_CONFIGURE_RSP, (oslParaType*)data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_is_ascii_string
 * DESCRIPTION
 *  This function checks whether the input UTF-8 encoded string is an ASCII
 *  string.
 * PARAMETERS
 *  utf8_str        [IN]        Input UTF-8 encoded string
 * RETURNS
 *  If input string is ASCII string, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_supl_is_ascii_string(const U8 *utf8_str)
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
 *  mmi_supl_check_white_spaces
 * DESCRIPTION
 *  This function is used for checking whether the given string contains any
 *  white spaces or not
 * PARAMETERS
 *  string      [OUT]       String in asscii
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_supl_check_white_spaces(CHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(string);

    if (!strlen(string))
    {
        return MMI_FALSE;
    }

    for (index = 0; index < strlen(string); index ++)
    {
        if ((string[index] == 9) ||
            (string[index] == 10) ||
            (string[index] == 13 ) ||
            (string[index] == 32 ))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_install_status
 * DESCRIPTION
 *  This function used to judge which status will be send to CCA.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_supl_ota_install_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 curr_scr = GetActiveScreenId();
    //mmi_id cur_gid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //cur_gid = g_mmi_supl_ota_context.cui_id;
    if (g_mmi_supl_ota_context.is_update)
    {
        mmi_supl_send_cca_conf_rsp(CCA_STATUS_SETTING_UPDATED);
    }
    else if (g_mmi_supl_ota_context.is_install)
    {
        mmi_supl_send_cca_conf_rsp(CCA_STATUS_OK);
    }
    else
    {
        mmi_supl_send_cca_conf_rsp(CCA_STATUS_SETTING_SKIPPED);
    }

 /*   if (g_mmi_supl_ota_context_p == NULL)
    {
        return;
    }

    OslMfree(g_mmi_supl_ota_context_p);
    g_mmi_supl_ota_context_p = NULL;
*/

    mmi_frm_scrn_set_leave_proc(g_mmi_supl_ota_context.cur_gid,SCR_ID_AGPS_SUPL_OTAP_PROF_INFO, NULL);

    mmi_frm_group_close(g_mmi_supl_ota_context.cur_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_supl_ota_check_next_profile
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_supl_ota_check_next_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_supl_ota_context.curr_index >= NVRAM_EF_AGPS_PROFILE_TOTAL * (g_mmi_supl_ota_context.sim_profile_id+1) - 1)
    {
        mmi_supl_ota_install_status();
    }
    else
    {
        for (i = g_mmi_supl_ota_context.curr_index + 1; i < NVRAM_EF_AGPS_PROFILE_TOTAL * (g_mmi_supl_ota_context.sim_profile_id+1); i++)
        {
            if (g_mmi_supl_ota_context.profile_list[i].is_used)
            {
                break;
            }
        }

        if (i != NVRAM_EF_AGPS_PROFILE_TOTAL* (g_mmi_supl_ota_context.sim_profile_id+1))
        {
            g_mmi_supl_ota_context.curr_index = i;
            mmi_supl_ota_entry_ota_setting();
        }
        else
        {
            mmi_supl_ota_install_status();
        }
    }
}

#if (MMI_SIM_TOTAL > 1)
/*****************************************************************************
 * FUNCTION
 *  get_log2
 * DESCRIPTION
 *  Find the log base 2 of an integer. The log base 2 of an integer is
 *  the same as the position of the highest bit set.
 * PARAMETERS
 *  i            [IN]
 * RETURNS
 *  the log base 2 of an integer
 *****************************************************************************/
static U8 get_log2(U16 sim_id)
{
    U8 r = 0;

    while (sim_id >>= 1)
        r++;
    return r;
}
#endif // #if(MMI_SIM_TOTAL > 1)

#endif /* __MMI_SUPL_OTA__ */

