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
 *  SIMProvAgentMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SPA Main: primitive handlers / memory management / init / deinit
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifdef __SPA_SUPPORT__

/**************************************************************/
/**********************  Header Files *************************/
/**************************************************************/
    #include "SIMProvAgentDefs.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "MMI_inet_app_trc.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "mmi_inet_app_trc.h"
    #include "string.h"
    #include "stdlib.h"

#include "CcaSrvGprot.h"
#include "SIMProvAgentConfig.h"
#include "SIMProvAgentConst.h"
#include "SIMProvAgentProt.h"

/*****************************************************************/
/******* Constants / Structure / Variables Declaration ***********/
/*****************************************************************/
#define MMI_SPA_TAG_BYTE_LEN            (1)
#define MMI_SPA_PARAM_BYTE_LEN          (1)
#define MMI_SPA_INT_PARAM_CONTENT_LEN   (1)
#define MMI_SPA_INT_PARAM_TOTAL_LEN     (MMI_SPA_PARAM_BYTE_LEN + MMI_SPA_INT_PARAM_CONTENT_LEN)
#define MMI_SPA_MMS_IMPL_LEN            3
#define MMI_SPA_IPV4_MAX_NUM_VAL        255
#define MMI_SPA_IPV4_MAX_NUM_COUNT      4
#define MMI_SPA_IPV4_MAX_TOTAL_LEN      15
#define MMI_SPA_MMSICP_APP_NODE_NAME_STR       "SIM MMS Profile"
#define MMI_SPA_MMSICP_APP_NODE_NAME_MAX_LEN    32
#define MMI_SPA_MMSICP_NODE_BUF_COUNT           5
#define MMI_SPA_MMSICP_BYTE_PARAM_VALUE_CHECKER 0x80

static const mmi_spa_value_conv_struct mmi_spa_cca_value_authtype[] = 
{
    {MMI_SPA_VALUE_AUTHTYPE_HTTP_BASIC, CCA_NS_VAL_HTTP_BASIC},
    {MMI_SPA_VALUE_AUTHTYPE_HTTP_DIGEST, CCA_NS_VAL_HTTP_DIGEST},
    {MMI_SPA_VALUE_AUTHTYPE_PAP, CCA_NS_VAL_PAP},
    {MMI_SPA_VALUE_AUTHTYPE_CHAP, CCA_NS_VAL_CHAP},
    {MMI_SPA_VALUE_AUTHTYPE_WTLS_SS, CCA_NS_VAL_WTLS_SS},
    {MMI_SPA_VALUE_AUTHTYPE_MD5, CCA_NS_VAL_MD5}
};

static const mmi_spa_value_conv_struct mmi_spa_cca_value_addrtype[] = 
{
    {MMI_SPA_VALUE_ADDTYPE_IPV4, CCA_NS_VAL_IPV4},
    {MMI_SPA_VALUE_ADDTYPE_IPV6, CCA_NS_VAL_IPV6},
    {MMI_SPA_VALUE_ADDTYPE_E164, CCA_NS_VAL_E164},
    {MMI_SPA_VALUE_ADDTYPE_ALPHA, CCA_NS_VAL_ALPHA},
    {MMI_SPA_VALUE_ADDTYPE_APN, CCA_NS_VAL_APN},
    {MMI_SPA_VALUE_ADDTYPE_SCODE, CCA_NS_VAL_SCODE},
    {MMI_SPA_VALUE_ADDTYPE_TETRA_ITSI, CCA_NS_VAL_TETRA_ITSI},
    {MMI_SPA_VALUE_ADDTYPE_MAN, CCA_NS_VAL_MAN}
};

static const mmi_spa_value_conv_struct mmi_spa_cca_value_bearer[] = 
{
    {MMI_SPA_VALUE_BEARER_GSM_CSD, CCA_NS_VAL_GSM_CSD},
    {MMI_SPA_VALUE_BEARER_GSM_GPRS, CCA_NS_VAL_GSM_GPRS},
    {MMI_SPA_VALUE_BEARER_GSM_USSD, CCA_NS_VAL_GSM_USSD},
    {MMI_SPA_VALUE_BEARER_GSM_SMS, CCA_NS_VAL_GSM_SMS},
    {MMI_SPA_VALUE_BEARER_IS_95_CDMA_SMS, CCA_NS_VAL_CDMA_SMS},
    {MMI_SPA_VALUE_BEARER_IS_95_CDMA_CSD, CCA_NS_VAL_CDMA_CSD},
    {MMI_SPA_VALUE_BEARER_IS_95_CDMA_PACKET, CCA_NS_VAL_CDMA_PACKET},
    {MMI_SPA_VALUE_BEARER_ANSI_136_GUTS, CCA_NS_VAL_ANSI_136_GUTS},
    {MMI_SPA_VALUE_BEARER_ANSI_136_CSD, CCA_NS_VAL_ANSI_136_CSD},
    {MMI_SPA_VALUE_BEARER_ANSI_136_GPRS, CCA_NS_VAL_ANSI_136_GPRS},
    {MMI_SPA_VALUE_BEARER_ANSI_136_GHOST, CCA_NS_VAL_ANSI_136_GHOST},
    {MMI_SPA_VALUE_BEARER_AMPS_CDPD, CCA_NS_VAL_AMPS_CDPD},
    {MMI_SPA_VALUE_BEARER_PDC_CSD, CCA_NS_VAL_PDC_CSD},
    {MMI_SPA_VALUE_BEARER_PDC_PACKET, CCA_NS_VAL_PDC_PACKET},
    {MMI_SPA_VALUE_BEARER_IDEN_SMS, CCA_NS_VAL_IDEN_SMS},
    {MMI_SPA_VALUE_BEARER_IDEN_CSD, CCA_NS_VAL_IDEN_CSD},
    {MMI_SPA_VALUE_BEARER_IDEN_PACKET, CCA_NS_VAL_IDEN_PACKET},
    {MMI_SPA_VALUE_BEARER_FLEX_REFLEX, CCA_NS_VAL_FLEX_REFLEX},
    {MMI_SPA_VALUE_BEARER_PHS_SMS, CCA_NS_VAL_PHS_SMS},
    {MMI_SPA_VALUE_BEARER_PHS_CSD, CCA_NS_VAL_PHS_CSD},
    {MMI_SPA_VALUE_BEARER_TETRA_SDS, CCA_NS_VAL_TETRA_SDS},
    {MMI_SPA_VALUE_BEARER_TETRA_PACKET, CCA_NS_VAL_TETRA_PACKET},
    {MMI_SPA_VALUE_BEARER_MOBITEX_MPAK, CCA_NS_VAL_MOBITEX_MPAK},
    {MMI_SPA_VALUE_BEARER_CDMA2000_1X_SIMPLE_IP, CCA_NS_VAL_CDMA2000_1X_SIMPLE_IP},
    {MMI_SPA_VALUE_BEARER_CDMA2000_1X_MOBILE_IP, CCA_NS_VAL_CDMA2000_1X_MOBILE_IP}
};

static const mmi_spa_value_conv_struct mmi_spa_cca_value_speed[] = 
{
    {MMI_SPA_VALUE_SPEED_AUTOBAUDING, CCA_NS_VAL_AUTOBAUDING}
};

static const mmi_spa_value_conv_struct mmi_spa_cca_value_calltype[] = 
{
    {MMI_SPA_VALUE_CALLTYPE_ANALOG_MODEM, CCA_NS_VAL_ANALOG_MODEM},
    {MMI_SPA_VALUE_CALLTYPE_V120, CCA_NS_VAL_V120},
    {MMI_SPA_VALUE_CALLTYPE_V110, CCA_NS_VAL_V110},
    {MMI_SPA_VALUE_CALLTYPE_X31, CCA_NS_VAL_X31},
    {MMI_SPA_VALUE_CALLTYPE_BIT_TRANSPARENT, CCA_NS_VAL_BIT_TRANSPARENT},
    {MMI_SPA_VALUE_CALLTYPE_DIRECT_ASYNCHRONOUS_DATA_SERVICE, CCA_NS_VAL_DIRECT_ASYNC_DATA_SERVICE}
};

static const mmi_spa_value_conv_struct mmi_spa_cca_value_service[] = 
{
    {MMI_SPA_VALUE_SERVICE_CL_WSP, CCA_NS_VAL_CL_WSP},
    {MMI_SPA_VALUE_SERVICE_CO_WSP, CCA_NS_VAL_CO_WSP},
    {MMI_SPA_VALUE_SERVICE_CL_SEC_WSP, CCA_NS_VAL_CL_SEC_WSP},
    {MMI_SPA_VALUE_SERVICE_CO_SEC_WSP, CCA_NS_VAL_CO_SEC_WSP},
    {MMI_SPA_VALUE_SERVICE_CL_SEC_WTA, CCA_NS_VAL_CL_SEC_WTA},
    {MMI_SPA_VALUE_SERVICE_CO_SEC_WTA, CCA_NS_VAL_CO_SEC_WTA},
    {MMI_SPA_VALUE_SERVICE_OTA_HTTP_TO, CCA_NS_VAL_OTA_HTTP_TO},
    {MMI_SPA_VALUE_SERVICE_OTA_HTTP_TLS_TO, CCA_NS_VAL_OTA_HTTP_TLS_TO},
    {MMI_SPA_VALUE_SERVICE_OTA_HTTP_PO, CCA_NS_VAL_OTA_HTTP_PO},
    {MMI_SPA_VALUE_SERVICE_OTA_HTTP_TLS_PO, CCA_NS_VAL_OTA_HTTP_TLS_PO}
};

static const mmi_spa_cca_conversion_struct spa_cca_conv_proxy_table[] = 
{
    {MMI_SPA_PARAM_PROXY_ID, CCA_NS_OMA_PROXY_ID, MMI_SPA_CONVERT_TYPE_STR, 0, 0},
    {MMI_SPA_PARAM_PROXY_PROVIDE_ID, CCA_NS_OMA_PROXY_PROVIDER_ID, MMI_SPA_CONVERT_TYPE_STR, 0, 0},
    {MMI_SPA_PARAM_PXAUTH_TYPE, CCA_NS_OMA_PXAUTH_TYPE, MMI_SPA_CONVERT_TYPE_ENUM,
     (mmi_spa_value_conv_struct *) mmi_spa_cca_value_authtype,
     (U16) (sizeof(mmi_spa_cca_value_authtype) / sizeof(mmi_spa_value_conv_struct))}
    ,
    {MMI_SPA_PARAM_PXAUTH_IDM, CCA_NS_OMA_PXAUTH_ID, MMI_SPA_CONVERT_TYPE_STR, 0, 0}
    ,
    {MMI_SPA_PARAM_PXAUTH_PW, CCA_NS_OMA_PXAUTH_PW, MMI_SPA_CONVERT_TYPE_STR, 0, 0}
    ,
    {MMI_SPA_PARAM_PXADDR, CCA_NS_OMA_PXADDR, MMI_SPA_CONVERT_TYPE_STR, 0, 0}
    ,
    {MMI_SPA_PARAM_PXADDRTYPE, CCA_NS_OMA_PXADDRTYPE, MMI_SPA_CONVERT_TYPE_ENUM,
     (mmi_spa_value_conv_struct *) mmi_spa_cca_value_addrtype,
     (U16) (sizeof(mmi_spa_cca_value_addrtype) / sizeof(mmi_spa_value_conv_struct))}
    ,
    {MMI_SPA_PARAM_PORTNBR, CCA_NS_OMA_PORTNBR, MMI_SPA_CONVERT_TYPE_STR, 0, 0}
    ,
    {MMI_SPA_PARAM_SERVICE, CCA_NS_OMA_SERVICE, MMI_SPA_CONVERT_TYPE_ENUM,
     (mmi_spa_value_conv_struct *) mmi_spa_cca_value_service,
     (U16) (sizeof(mmi_spa_cca_value_service) / sizeof(mmi_spa_value_conv_struct))}
    ,
};

static const mmi_spa_cca_conversion_struct spa_cca_conv_nap_table[] = 
{
    {MMI_SPA_PARAM_BEARER, CCA_NS_OMA_BEARER, MMI_SPA_CONVERT_TYPE_ENUM,
     (mmi_spa_value_conv_struct *) mmi_spa_cca_value_bearer,
     (U16) (sizeof(mmi_spa_cca_value_bearer) / sizeof(mmi_spa_value_conv_struct))}
    ,
    {MMI_SPA_PARAM_NAPADDRESS, CCA_NS_OMA_NAP_ADDRESS, MMI_SPA_CONVERT_TYPE_STR, 0, 0}
    ,
    {MMI_SPA_PARAM_NAPADDRTYPE, CCA_NS_OMA_NAP_ADDRTYPE, MMI_SPA_CONVERT_TYPE_ENUM,
     (mmi_spa_value_conv_struct *) mmi_spa_cca_value_addrtype,
     (U16) (sizeof(mmi_spa_cca_value_addrtype) / sizeof(mmi_spa_value_conv_struct))}
    ,
    {MMI_SPA_PARAM_LINKSPEED, CCA_NS_OMA_LINKSPEED, MMI_SPA_CONVERT_TYPE_ENUM,
     (mmi_spa_value_conv_struct *) mmi_spa_cca_value_speed,
     (U16) (sizeof(mmi_spa_cca_value_speed) / sizeof(mmi_spa_value_conv_struct))}
    ,
    {MMI_SPA_PARAM_CALLTYPE, CCA_NS_OMA_CALLTYPE, MMI_SPA_CONVERT_TYPE_ENUM,
     (mmi_spa_value_conv_struct *) mmi_spa_cca_value_calltype,
     (U16) (sizeof(mmi_spa_cca_value_calltype) / sizeof(mmi_spa_value_conv_struct))}
    ,
};

static const mmi_spa_cca_conversion_struct spa_cca_conv_napauth_table[] = 
{
    {MMI_SPA_PARAM_AUTHTYPE, CCA_NS_OMA_AUTHTYPE, MMI_SPA_CONVERT_TYPE_ENUM,
     (mmi_spa_value_conv_struct *) mmi_spa_cca_value_authtype,
     (U16) (sizeof(mmi_spa_cca_value_authtype) / sizeof(mmi_spa_value_conv_struct))}
    ,
    {MMI_SPA_PARAM_AUTHNAME, CCA_NS_OMA_AUTHNAME, MMI_SPA_CONVERT_TYPE_STR, 0, 0}
    ,
    {MMI_SPA_PARAM_AUTHSECRET, CCA_NS_OMA_AUTHSECRET, MMI_SPA_CONVERT_TYPE_STR, 0, 0}
    ,
};

static mmi_spa_parser_context_struct g_spa_ef_parser_context;

//static U32 g_node_id_idx = 0;
//static U8 g_node_buf[32];

/*****************************************************************/
/************************ Functions ******************************/
/*****************************************************************/
static void mmi_spa_clear_parser_context(void);
static U8 mmi_spa_mmsicp_parser_find_next_tag(const U8 *data, S32 len, S32 *tag_len);
static mmi_spa_result_enum mmi_spa_mmsicp_conn_parser(const U8 *data, S32 data_len, S32 *parsed_len);
static S32 mmi_spa_mmsicp_add_app_node(mmi_spa_parser_mmsicp_data_struct *app_data);
static S32 mmi_spa_mmsicp_add_nap_node(mmi_spa_parser_mmsicp_data_struct *app_data);
static void mmi_spa_mmsicp_delete_nap_node(mmi_spa_parser_mmsicp_data_struct *app_data, S32 hNap);
static mmi_spa_result_enum mmi_spa_mmsicp_add_tonap_to_proxy(S32 hProxy, S32 hNap);
static S32 mmi_spa_mmsicp_add_proxy_node(mmi_spa_parser_mmsicp_data_struct *app_data);
static void mmi_spa_mmsicp_delete_proxy_node(mmi_spa_parser_mmsicp_data_struct *app_data, S32 hProxy);
static MMI_BOOL mmi_spa_mmsicp_get_tag_len(const U8 *p, S32 len, S32 *value, S32 *parsed_len);
static mmi_spa_result_enum mmi_spa_mmsicp_impl_parser(const U8 *p, S32 data_len, S32 *parsed_len);
static mmi_spa_result_enum mmi_spa_mmsicp_mms_relay_parser(U8 *p, S32 data_len, S32 *parsed_len);
static mmi_spa_result_enum mmi_spa_mmsicp_network_parser(const U8 *p, S32 data_len, S32 *parsed_len);
static mmi_spa_result_enum mmi_spa_mmsicp_gateway_parser(const U8 *p, S32 data_len, S32 *parsed_len);
static MMI_BOOL mmi_spa_validate_proxy_addr(S8 *addr, S32 addr_type);
static mmi_spa_result_enum mmi_spa_mmsicp_process_param(
                            S32 node,
                            U8 param,
                            U8 *p,
                            S32 data_len,
                            const mmi_spa_cca_conversion_struct *table,
                            U16 table_len,
                            S32 *len);
static mmi_spa_result_enum mmi_spa_mmsicp_process_string_param(
                            U8 *p,
                            S32 data_len,
                            S32 node,
                            const mmi_spa_cca_conversion_struct *item,
                            S32 *param_len);
static MMI_BOOL mmi_spa_mmsicp_check_app_node(S32 hNode);
static MMI_BOOL mmi_spa_check_proxy_node(S32 hNode);
static mmi_spa_result_enum mmi_spa_mmsicp_add_toproxy_to_app(S32 hApp, S32 hProxy);
static mmi_spa_result_enum mmi_spa_mmsicp_proxy_check_in_conn(mmi_spa_parser_mmsicp_data_struct *app_data, S32 hProxy);
static S32 mmi_spa_mmsicp_node_buf_add_node(mmi_spa_parser_mmsicp_data_struct *app_data, S32 node);
static void mmi_spa_mmsicp_node_buf_release(mmi_spa_parser_mmsicp_data_struct *app_data);
static void mmi_spa_mmsicp_node_buf_delete_all_nodes(mmi_spa_parser_mmsicp_data_struct *app_data);
static void mmi_spa_mmsicp_node_buf_delete_node(mmi_spa_parser_mmsicp_data_struct *app_data, S32 node);
static void mmi_spa_mmsicp_clear_parser_context(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_parser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param           [IN]        
 *  callback        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_spa_result_enum mmi_spa_mmsicp_parser(void *param, spa_sim_ef_parse_callback_fn callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag;
    S32 len;
    S32 tag_length;
    S32 tag_length_len;
    S32 parsed_len;
    S32 hApp;
    MMI_BOOL valid_content_parsed = MMI_FALSE;
    MMI_BOOL len_ret;
    mmi_spa_result_enum ret = MMI_SPA_RESULT_PARSE_INVALID_DATA;
    mmi_spa_sim_mmsicp_parse_param_struct *data = NULL;
    mmi_spa_parser_mmsicp_data_struct *app_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER, param);

    if (!param)
    {
        return MMI_SPA_RESULT_PARSE_ERROR_PARAM;
    }

    data = (mmi_spa_sim_mmsicp_parse_param_struct*) param;
    memset(&g_spa_ef_parser_context, 0, sizeof(mmi_spa_parser_context_struct));

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_PARAM_VAULES, data->len, data->hRoot);

    /* Set app data */
    app_data = mmi_spa_malloc(sizeof(mmi_spa_parser_mmsicp_data_struct));
    if (!app_data)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_SPA_MEM_FAIL);
        return MMI_SPA_RESULT_MEM_FULL;
    }
    memset(app_data, 0, sizeof(mmi_spa_parser_mmsicp_data_struct));

    /* Set init info */
    g_spa_ef_parser_context.data = data->buf;
    g_spa_ef_parser_context.app_data = (void*)app_data;
    g_spa_ef_parser_context.file_size = data->len;
    g_spa_ef_parser_context.hRoot = data->hRoot;
    g_spa_ef_parser_context.file_type = MMI_SPA_EF_TYPE_TRANSPARENT;

    /* Process content */
    while (g_spa_ef_parser_context.file_pos < g_spa_ef_parser_context.file_size)
    {
        ret = MMI_SPA_RESULT_OK;

        /* Find tag */
        tag = mmi_spa_mmsicp_parser_find_next_tag(
                (const U8*)(g_spa_ef_parser_context.data + g_spa_ef_parser_context.file_pos),
                (S32) (g_spa_ef_parser_context.file_size - g_spa_ef_parser_context.file_pos),
                &len);

        /* MMS conn tag not found */
        if (tag != (U8) MMI_SPA_TAG_MMICP_MMS_CONN_PARAM)
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_ADD_GET_UNKNOWN_TAG, tag);

            /* Find length of this tag content */
            len_ret = mmi_spa_mmsicp_get_tag_len(
                        (const U8*)(g_spa_ef_parser_context.data + g_spa_ef_parser_context.file_pos + len),
                        (S32) (g_spa_ef_parser_context.file_size - g_spa_ef_parser_context.file_pos - len),
                        &tag_length,
                        &tag_length_len);

            /* Can't get length, this parse process finish */
            if (!len_ret)
            {
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_ADD_GET_TAG_LEN_ERR);

                if (!valid_content_parsed)
                {
                    /* nothing parsed */
                    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_ADD_GET_TAG_LEN_ERR_NOTHING_PARSED);
                    mmi_spa_mmsicp_clear_parser_context();
                    return MMI_SPA_RESULT_PARSE_ERROR_LENGTH;
                }
                else
                {
                    /* no more data to parse */
                    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_ADD_GET_TAG_LEN_ERR_HAVE_PARSED);
                    mmi_spa_mmsicp_clear_parser_context();
                    return MMI_SPA_RESULT_OK;
                }
            }

            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_ADD_GET_TAG_LEN_OK);

            /* Jump over this tag content */
            g_spa_ef_parser_context.file_pos += tag_length + len + tag_length_len;
            continue;
        }
        else    /* MMS conn tag found */
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_NEXT_CONN);

            /* add app node */
            hApp = mmi_spa_mmsicp_add_app_node(app_data);
            if (!hApp)
            {
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_ADD_APP_ERR);
                mmi_spa_mmsicp_clear_parser_context();
                return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
            }
            app_data->hApp = hApp;

            ret = mmi_spa_mmsicp_conn_parser(
                    (const U8*)(g_spa_ef_parser_context.data + g_spa_ef_parser_context.file_pos),
                    (S32) (g_spa_ef_parser_context.file_size - g_spa_ef_parser_context.file_pos),
                    &parsed_len);

            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_ADD_CONN_PARSER_RET, ret, parsed_len);

            /* This conn parse ok */
            if (ret == MMI_SPA_RESULT_OK)
            {
                valid_content_parsed = MMI_TRUE;

                /* Check this app node */
                if (!mmi_spa_mmsicp_check_app_node(hApp))
                {
                    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_INVALID_APP);

                    mmi_cca_doc_node_detach(hApp);
                    mmi_cca_doc_node_release_all(hApp);
                    mmi_spa_mmsicp_node_buf_delete_all_nodes(app_data);
                    mmi_spa_mmsicp_node_buf_release(app_data);

                    hApp = 0;
                }
            }
            else
            {
                /* Release this */
                if (ret != MMI_SPA_RESULT_PARSE_CCA_MEM_FULL && hApp)
                {
                    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_NOT_MEM_FULL_ERR);

                    mmi_cca_doc_node_detach(hApp);
                    mmi_cca_doc_node_release_all(hApp);
                    mmi_spa_mmsicp_node_buf_delete_all_nodes(app_data);
                    mmi_spa_mmsicp_node_buf_release(app_data);

                    hApp = 0;
                }
                else if (hApp)
                {
                    /* Reserve this app node only if it is useful */
                    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_MEM_FULL_ERR);

                    if (!mmi_spa_mmsicp_check_app_node(hApp))
                    {
                        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_MEM_FULL_ERR_CHECK_APP_FAIL);
                        mmi_cca_doc_node_detach(hApp);
                        mmi_cca_doc_node_release_all(hApp);
                        mmi_spa_mmsicp_node_buf_delete_all_nodes(app_data);
                        mmi_spa_mmsicp_node_buf_release(app_data);

                        hApp = 0;
                    }
                }

                /* If length error, can't continue to next, end process */
                if (ret == MMI_SPA_RESULT_PARSE_ERROR_LENGTH || ret == MMI_SPA_RESULT_PARSE_CCA_MEM_FULL)
                {
                    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_BREAK_PARSE);
                    break;
                }
            }

            g_spa_ef_parser_context.file_pos += parsed_len;
        }
    }

    MMI_TRACE(
        SPA_TRACE_INFO,
        TRC_MMI_SPA_MMSICP_PARSER_OUT_WHILE_LOOP,
        g_spa_ef_parser_context.file_pos,
        g_spa_ef_parser_context.file_size);

    /* nothing parsed */
    if (ret != MMI_SPA_RESULT_OK && !valid_content_parsed)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_NO_PARSED_CONTENT);
        mmi_spa_mmsicp_clear_parser_context();
        return ret;
    }
    else
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_OK);
        mmi_spa_mmsicp_clear_parser_context();
        return MMI_SPA_RESULT_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_parser_find_next_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]        
 *  len         [IN]        
 *  tag_len     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_spa_mmsicp_parser_find_next_tag(const U8 *data, S32 len, S32 *tag_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_FIND_NEXT_TAG, len);

    if (!data || !tag_len || len < 1)
    {
        return MMI_SPA_TAG_MMICP_MMS_UNKNOWN;
    }

    val = *data;
    *tag_len = MMI_SPA_TAG_BYTE_LEN;

    if (val == MMI_SPA_TAG_MMICP_MMS_CONN_PARAM ||
        val == MMI_SPA_TAG_MMICP_MMS_IMPL ||
        val == MMI_SPA_TAG_MMICP_MMS_RELAY || val == MMI_SPA_TAG_MMICP_NETWORK_INFO || val == MMI_SPA_TAG_MMICP_GATEWAY)
    {
        return val;
    }

    return MMI_SPA_TAG_MMICP_MMS_UNKNOWN;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_conn_parser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [IN]        
 *  data_len        [IN]        
 *  parsed_len      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_mmsicp_conn_parser(const U8 *data, S32 data_len, S32 *parsed_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U8 *p = NULL;
    U8 tag;
    S32 pos = 0;
    S32 len;
    S32 tag_len;
    S32 sub_tag_len;
    S32 tag_length_len;
    S32 tag_total_len;
    S32 hProxy;
    MMI_BOOL ret;
    MMI_BOOL have_parsed_tag = MMI_FALSE;
    mmi_spa_result_enum result;
    mmi_spa_result_enum check_result;
    mmi_spa_parser_mmsicp_data_struct *app_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CONN_PARSER, data_len);

    if (!data || data_len == 0 || !parsed_len)
    {
        return MMI_SPA_RESULT_PARSE_ERROR_LENGTH;
    }

    p = data;
    if (*p != MMI_SPA_TAG_MMICP_MMS_CONN_PARAM)
    {
        return MMI_SPA_RESULT_PARSE_ERROR_LENGTH;
    }

    app_data = (mmi_spa_parser_mmsicp_data_struct*) g_spa_ef_parser_context.app_data;

    /* Point to len */
    p++;
    pos++;

    /* Get tag len */
    ret = mmi_spa_mmsicp_get_tag_len(p, (S32) (data_len - pos), &tag_len, &tag_length_len);
    if (!ret)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_ADD_GET_TAG_LEN_ERR);
        return MMI_SPA_RESULT_PARSE_ERROR_LENGTH;
    }

    /* */
    if (tag_len > data_len - pos)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CONN_PARSER_TOO_LONG_LEN);
        return MMI_SPA_RESULT_PARSE_ERROR_LENGTH;
    }

    /* Add proxy node for this conn */
    hProxy = mmi_spa_mmsicp_add_proxy_node(app_data);
    if (hProxy == 0)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CONN_PARSER_ADD_PROXY_ERR);
        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
    }
    /* g_spa_ef_parser_context.hProxy only used in this function */
    app_data->hProxy = hProxy;

    /* Point to tag content */
    p += tag_length_len;
    pos += tag_length_len;

    *parsed_len = tag_len + tag_length_len + MMI_SPA_TAG_BYTE_LEN;
    tag_total_len = *parsed_len;

    /* Process content */
    while (pos < tag_total_len)
    {
        /* Find sub-tag */
        tag = mmi_spa_mmsicp_parser_find_next_tag(p, (S32) (tag_len - pos), &len);
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CONN_PARSER_PROCESS_TAG, tag);

        switch (tag)
        {
            case MMI_SPA_TAG_MMICP_MMS_IMPL:
                result = mmi_spa_mmsicp_impl_parser(p, (S32) (tag_total_len - pos), &sub_tag_len);
                break;
            case MMI_SPA_TAG_MMICP_MMS_RELAY:
                result = mmi_spa_mmsicp_mms_relay_parser((U8*) p, (S32) (tag_total_len - pos), &sub_tag_len);
                break;
            case MMI_SPA_TAG_MMICP_NETWORK_INFO:
                result = mmi_spa_mmsicp_network_parser(p, (S32) (tag_total_len - pos), &sub_tag_len);
                break;
            case MMI_SPA_TAG_MMICP_GATEWAY:
                result = mmi_spa_mmsicp_gateway_parser(p, (S32) (tag_total_len - pos), &sub_tag_len);
                break;
            default:
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CONN_PARSER_DEFAULT_TAG);

                ret = mmi_spa_mmsicp_get_tag_len(p + 1, (S32) (tag_len - pos), &len, &tag_length_len);
                if (!ret || len > tag_len - pos)
                {
                    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PARSER_ADD_GET_TAG_LEN_ERR);
                    mmi_spa_mmsicp_delete_proxy_node(app_data, hProxy);

                    return MMI_SPA_RESULT_PARSE_INVALID_DATA;
                }
                /* Can't parse it, just jump over it in below lines */
                sub_tag_len = tag_length_len + len + MMI_SPA_TAG_BYTE_LEN;
                result = MMI_SPA_RESULT_OK;
                break;
        }

        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CONN_PARSER_SUB_PARSER_RET, result);

        /* ok, jump over it */
        if (result == MMI_SPA_RESULT_OK)
        {
            p += sub_tag_len;
            pos += sub_tag_len;
            have_parsed_tag = MMI_TRUE;
        }
        else    /* This conn parse error */
        {
            /* Can't continue, return */
            if (result == MMI_SPA_RESULT_FAIL ||
                result == MMI_SPA_RESULT_PARSE_ERROR_PARAM ||
                result == MMI_SPA_RESULT_PARSE_INVALID_DATA ||
                result == MMI_SPA_RESULT_PARSE_ERROR_LENGTH || result == MMI_SPA_RESULT_PARSE_CCA_MEM_FULL)
            {
                if (have_parsed_tag == MMI_TRUE)
                {
                    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CONN_PARSER_HAVE_PARSED);

                    check_result = mmi_spa_mmsicp_proxy_check_in_conn(app_data, hProxy);
                    app_data->hProxy = 0;

                    if (check_result != MMI_SPA_RESULT_OK)
                    {
                        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CONN_PARSER_HAVE_PARSED_CHECK_PROXY_FAIL);
                        return check_result;
                    }

                    return result;  /* OK or MEM_FULL */
                }
                else
                {
                    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CONN_PARSER_NO_PARSED);
                    app_data->hProxy = 0;
                    return result;
                }
            }
            else    /* Go to next tag */
            {
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CONN_PARSER_CONTINUE_NEXT_TAG);
                p += sub_tag_len;
                pos += sub_tag_len;
            }
        }
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CONN_PARSER_OUT_WHILE_LOOP);

    result = mmi_spa_mmsicp_proxy_check_in_conn(app_data, hProxy);
    app_data->hProxy = 0;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_proxy_check_in_conn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_data        [?]         [?]         [?]         [?]
 *  hProxy          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_mmsicp_proxy_check_in_conn(mmi_spa_parser_mmsicp_data_struct *app_data, S32 hProxy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PROXY_CHECK_IN_CONN);

    if (!mmi_spa_check_proxy_node(hProxy))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CONN_PARSER_INVALIDE_PROXY);
        mmi_spa_mmsicp_delete_proxy_node(app_data, hProxy);
    }
    else
    {
        if (MMI_SPA_RESULT_OK != mmi_spa_mmsicp_add_toproxy_to_app(app_data->hApp, hProxy))
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CONN_PARSER_ADD_TOPROXY_ERR);
            return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
        }
    }

    return MMI_SPA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_add_app_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_data        [?]     [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_spa_mmsicp_add_app_node(mmi_spa_parser_mmsicp_data_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hApp;
    S8 *node_id = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_ADD_APP_NODE);

    mmi_spa_mmsicp_node_buf_release(app_data);

    hApp = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPLICATION, g_spa_ef_parser_context.hRoot);
    if (!hApp)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_ADD_APP_NODE_HAPP_FAIL);
        return 0;
    }

    node_id = mmi_cca_oma_make_new_node_id();
    if (!node_id)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_ADD_APP_NODE_NODE_ID_FAIL);
        mmi_cca_doc_node_detach(hApp);
        mmi_cca_doc_node_release_all(hApp);
        return 0;
    }

    mmi_cca_doc_add_nodedata_str(hApp, CCA_NS_NODEID, (S8*) node_id);
    mmi_cca_doc_add_nodedata_str(hApp, CCA_NS_OMA_APPID, (S8*) MMI_SPA_VALUE_APP_ID_MMS);
    mmi_cca_doc_add_nodedata_str(hApp, CCA_NS_OMA_NAME, (S8*) MMI_SPA_MMSICP_APP_NODE_NAME_STR);

    mmi_cca_oma_free_id(node_id);

    return hApp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_add_nap_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_data        [?]     [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_spa_mmsicp_add_nap_node(mmi_spa_parser_mmsicp_data_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hNap;
    S8 *node_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hNap = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_NAPDEF, g_spa_ef_parser_context.hRoot);
    if (hNap == 0)
    {
        return 0;
    }

    node_id = mmi_cca_oma_make_new_node_id();
    if (!node_id)
    {
        mmi_cca_doc_node_detach(hNap);
        mmi_cca_doc_node_release_all(hNap);
        return 0;
    }

    if (MMI_SPA_RESULT_OK != mmi_spa_mmsicp_node_buf_add_node(app_data, hNap))
    {
        mmi_cca_doc_node_detach(hNap);
        mmi_cca_doc_node_release_all(hNap);
        mmi_cca_oma_free_id(node_id);
        return 0;
    }

    mmi_cca_doc_add_nodedata_str(hNap, CCA_NS_NODEID, node_id);
    /* mmi_cca_doc_add_nodedata_str(hNap, CCA_NS_OMA_NAME, node_id); */
    mmi_cca_doc_add_nodedata_str(hNap, CCA_NS_OMA_NAPID, node_id);

    /* mmi_cca_doc_add_nodedata_str(g_spa_ef_parser_context.hProxy, CCA_NS_OMA_TO_NAPID, node_id); */

    mmi_cca_oma_free_id(node_id);

    return hNap;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_delete_nap_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_data        [?]         [?]         [?]         [?]
 *  hNap            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_mmsicp_delete_nap_node(mmi_spa_parser_mmsicp_data_struct *app_data, S32 hNap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_spa_mmsicp_node_buf_delete_node(app_data, hNap);
    mmi_cca_doc_node_detach(hNap);
    mmi_cca_doc_node_release_all(hNap);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_add_tonap_to_proxy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hProxy      [IN]        
 *  hNap        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_mmsicp_add_tonap_to_proxy(S32 hProxy, S32 hNap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *node_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_ADD_TONAP_TO_PROXY);

    if (CCA_STATUS_OK != mmi_cca_doc_nodedata_str_first(hNap, CCA_NS_OMA_NAPID, &node_id))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_ADD_TONAP_TO_PROXY_GET_NAPID_FAIL);
        return MMI_SPA_RESULT_PARSE_CCA_ERROR;
    }

    if (CCA_STATUS_OK != mmi_cca_doc_add_nodedata_str(hProxy, CCA_NS_OMA_TO_NAPID, node_id))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_ADD_TONAP_TO_PROXY_ADD_TONAPID_FAIL);
        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
    }

    return MMI_SPA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_add_toproxy_to_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hApp        [IN]        
 *  hProxy      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_mmsicp_add_toproxy_to_app(S32 hApp, S32 hProxy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *node_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_ADD_TOPROXY_TO_APP);

    if (CCA_STATUS_OK != mmi_cca_doc_nodedata_str_first(hProxy, CCA_NS_NODEID, &node_id))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_ADD_TOPROXY_TO_APP_GET_PROXY_NODE_ID_FAIL);
        return MMI_SPA_RESULT_PARSE_CCA_ERROR;
    }

    if (CCA_STATUS_OK != mmi_cca_doc_add_nodedata_str(hApp, CCA_NS_OMA_TO_PROXY, node_id))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_ADD_TOPROXY_TO_APP_ADD_TOPROXY_FAIL);
        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
    }

    return MMI_SPA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_check_nap_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hNode       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_mmsicp_check_nap_node(S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 intVal = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* bearer */
    if (CCA_STATUS_OK != mmi_cca_doc_nodedata_int_first(hNode, CCA_NS_OMA_BEARER, &intVal))
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_check_app_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hNode       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_mmsicp_check_app_node(S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *strVal = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CHECK_APP_NODE);

    if (CCA_STATUS_OK != mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_ADDR, &strVal))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CHECK_APP_NODE_GET_MMSC_FAIL);
        return MMI_FALSE;
    }
    else if (!strVal)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CHECK_APP_NODE_GET_MMSC_FAIL);
        return MMI_FALSE;
    }

    if (CCA_STATUS_OK != mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_TO_PROXY, &strVal))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CHECK_APP_NODE_GET_PROXY_FAIL);
        return MMI_FALSE;
    }
    else if (!strVal)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_CHECK_APP_NODE_NO_PROXY);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_add_proxy_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_data        [?]     [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_spa_mmsicp_add_proxy_node(mmi_spa_parser_mmsicp_data_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hProxy;
    S8 *node_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_ADD_PROXY_NODE);

    hProxy = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PROXY, g_spa_ef_parser_context.hRoot);
    if (hProxy == 0)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_ADD_PROXY_NODE_NEW_HPROXY_FAIL);
        return 0;
    }

    node_id = mmi_cca_oma_make_new_node_id();
    if (!node_id)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_ADD_PROXY_NODE_NODE_ID_FAIL);
        mmi_cca_doc_node_detach(hProxy);
        mmi_cca_doc_node_release_all(hProxy);
        return 0;
    }

    if (MMI_SPA_RESULT_OK != mmi_spa_mmsicp_node_buf_add_node(app_data, hProxy))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_ADD_PROXY_NODE_ADD_BUF_NODE_FAIL);
        mmi_cca_doc_node_detach(hProxy);
        mmi_cca_doc_node_release_all(hProxy);
        mmi_cca_oma_free_id(node_id);
        return 0;
    }

    mmi_cca_doc_add_nodedata_str(hProxy, CCA_NS_NODEID, node_id);
    mmi_cca_doc_add_nodedata_str(hProxy, CCA_NS_OMA_PROXY_ID, node_id);

    /* mmi_cca_doc_add_nodedata_str(g_spa_ef_parser_context.hApp, CCA_NS_OMA_TO_PROXY, node_id); */

    mmi_cca_oma_free_id(node_id);

    return hProxy;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_delete_proxy_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_data        [?]         [?]         [?]         [?]
 *  hProxy          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_mmsicp_delete_proxy_node(mmi_spa_parser_mmsicp_data_struct *app_data, S32 hProxy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_spa_mmsicp_node_buf_delete_node(app_data, hProxy);
    mmi_cca_doc_node_detach(hProxy);
    mmi_cca_doc_node_release_all(hProxy);
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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_get_tag_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p               [IN]        
 *  len             [IN]        
 *  value           [?]         [?]         [?]         [?]         [?]
 *  parsed_len      [?]         [?]         [?]         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_mmsicp_get_tag_len(const U8 *p, S32 len, S32 *value, S32 *parsed_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    U8 num_of_bytes;
    S32 val = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len < 1)
    {
        return MMI_FALSE;
    }
    if (*p == 0xff)
    {
        return MMI_FALSE;
    }

    /* */
    if (*p <= MMI_SPA_VALUE_MAX_ONE_BYTE_LEN)
    {
        *value = (S32) (*p);
        *parsed_len = 1;
        return MMI_TRUE;
    }
    else
    {
        num_of_bytes = (*p) & 0x7f;
        /* No enough bytes */
        if (num_of_bytes > (len - 1))
        {
            return MMI_FALSE;
        }
        /* Currently we only support length up to 2 bytes,
           because SIM access interface parameter use U16 as file length.
           So assert if meet a length longer than 2 bytes. */
        if (num_of_bytes > 2)
        {
            return MMI_FALSE;
        }

        *parsed_len = num_of_bytes + 1;
        p++;

        for (i = (num_of_bytes - 1); i >= 0; i--)
        {
            val = val | ((*(p + i)) << (num_of_bytes - i - 1) * 8);
        }

        *value = val;

        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_impl_parser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p               [IN]        
 *  data_len        [IN]        
 *  parsed_len      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_mmsicp_impl_parser(const U8 *p, S32 data_len, S32 *parsed_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 impl;
    cca_status_enum ret;
    mmi_spa_parser_mmsicp_data_struct *app_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_IMPL_PARSER, data_len);

    if (!p || data_len < MMI_SPA_MMS_IMPL_LEN || !parsed_len)
    {
        return MMI_SPA_RESULT_PARSE_ERROR_PARAM;
    }

    if (*(p + 1) != MMI_SPA_INT_PARAM_CONTENT_LEN)
    {
        return MMI_SPA_RESULT_PARSE_INVALID_DATA;
    }

    app_data = (mmi_spa_parser_mmsicp_data_struct*) g_spa_ef_parser_context.app_data;
    *parsed_len = MMI_SPA_MMS_IMPL_LEN;

    if (CCA_STATUS_OK == mmi_cca_doc_nodedata_int_first(app_data->hApp, CCA_NS_OMA_IMPL, &impl))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_IMPL_PARSER_GET_IMPL_FAIL);
        return MMI_SPA_RESULT_OK;
    }

    /* Jump over tag and length bytes */
    p += MMI_SPA_MMS_IMPL_LEN - 1;

    /* Only support 0x01->WAP */
    if (*p == 0x01)
    {
        /* Add version node to app node */
        ret = mmi_cca_doc_add_nodedata_int(app_data->hApp, CCA_NS_OMA_IMPL, (S32) CCA_NS_VAL_IMPL_WAP);
    }
    else
    {
        /* Add version node to app node */
        ret = mmi_cca_doc_add_nodedata_int(app_data->hApp, CCA_NS_OMA_IMPL, (S32) CCA_NS_VAL_IMPL_UNKNOWN);
    }

    if (ret != CCA_STATUS_OK)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_IMPL_PARSER_ADD_IMPL_FAIL);
        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
    }
    return MMI_SPA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_mms_relay_parser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p               [IN]        
 *  data_len        [IN]        
 *  parsed_len      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_mmsicp_mms_relay_parser(U8 *p, S32 data_len, S32 *parsed_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 relay_len;
    S32 len;
    U8 temp;
    MMI_BOOL ret;
    cca_status_enum cca_ret;
    mmi_spa_parser_mmsicp_data_struct *app_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_MMS_RELAY_PARSER, data_len);

    if (!p || !parsed_len)
    {
        return MMI_SPA_RESULT_PARSE_ERROR_PARAM;
    }

    app_data = (mmi_spa_parser_mmsicp_data_struct*) g_spa_ef_parser_context.app_data;

    /* Check tag */
    /* jump over tag */
    p++;

    /* Get length */
    ret = mmi_spa_mmsicp_get_tag_len(p, data_len, &relay_len, &len);
    if (ret == FALSE)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_MMS_RELAY_PARSER_GET_LEN_FAIL);
        return MMI_SPA_RESULT_PARSE_ERROR_LENGTH;
    }

    *parsed_len = relay_len + len + MMI_SPA_TAG_BYTE_LEN;
    if (*parsed_len > data_len)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_MMS_RELAY_PARSER_TOO_LONG_LEN);
        return MMI_SPA_RESULT_PARSE_INVALID_DATA;
    }

    /* jump over length bytes */
    p += len;

    /* Get data */
    temp = *(p + relay_len);
    *(p + relay_len) = 0;

    /* Add addr to app node */
    cca_ret = mmi_cca_doc_add_nodedata_str(app_data->hApp, CCA_NS_OMA_ADDR, (S8*) p);

    *(p + relay_len) = temp;

    if (cca_ret != CCA_STATUS_OK)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_MMS_RELAY_PARSER_ADD_APP_ADDR_FAIL);
        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
    }
    return MMI_SPA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_network_parser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p               [IN]        
 *  data_len        [IN]        
 *  parsed_len      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_mmsicp_network_parser(const U8 *p, S32 data_len, S32 *parsed_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 param;
    MMI_BOOL ret;
    S32 i;
    S32 content_len;
    S32 len;
    S32 param_len;
    S32 hNap = 0;
    S32 hAuth = 0;
    mmi_spa_result_enum result;
    mmi_spa_result_enum add_to_prxy_result;
    mmi_spa_parser_mmsicp_data_struct *app_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER, data_len);

    if (!p || !parsed_len)
    {
        return MMI_SPA_RESULT_PARSE_ERROR_PARAM;
    }

    app_data = (mmi_spa_parser_mmsicp_data_struct*) g_spa_ef_parser_context.app_data;

    /* get tag length */
    p++;

    ret = mmi_spa_mmsicp_get_tag_len(p, data_len, &content_len, &len);
    if (ret == FALSE)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER_GET_LEN_FAIL);
        return MMI_SPA_RESULT_PARSE_ERROR_LENGTH;
    }

    *parsed_len = content_len + len + MMI_SPA_TAG_BYTE_LEN;

    if (*parsed_len > data_len)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER_TOO_LONG_LEN);
        return MMI_SPA_RESULT_PARSE_INVALID_DATA;
    }

    /* jump over length bytes */
    p += len;

    /* process content */
    /* Add one nap node */
    hNap = mmi_spa_mmsicp_add_nap_node(app_data);
    if (!hNap)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER_ADD_NAP_NODE_FAIL);
        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
    }

    i = 0;
    /* content_len = *parsed_len; */
    while (i < content_len)
    {
        param = *p;

        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER_PARAM_VALUE, param);

        switch (param)
        {
            case MMI_SPA_PARAM_BEARER:
            case MMI_SPA_PARAM_NAPADDRESS:
            case MMI_SPA_PARAM_NAPADDRTYPE:
            case MMI_SPA_PARAM_LINKSPEED:
            case MMI_SPA_PARAM_CALLTYPE:
                result = mmi_spa_mmsicp_process_param(
                            hNap,
                            param,
                            (U8*) p,
                            (content_len - i),
                            spa_cca_conv_nap_table,
                            sizeof(spa_cca_conv_nap_table) / sizeof(mmi_spa_cca_conversion_struct),
                            &param_len);

                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER_PROCESS_PARAM_RET, result);

                if (MMI_SPA_RESULT_OK != result)
                {
                    if (result == MMI_SPA_RESULT_PARSE_CCA_MEM_FULL)
                    {
                        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
                    }
                    switch (param)
                    {
                        case MMI_SPA_PARAM_BEARER:
                        case MMI_SPA_PARAM_NAPADDRTYPE:
                        case MMI_SPA_PARAM_LINKSPEED:
                        case MMI_SPA_PARAM_CALLTYPE:
                            param_len = MMI_SPA_INT_PARAM_CONTENT_LEN;
                            break;
                        case MMI_SPA_PARAM_NAPADDRESS:
                            param_len = strlen((char*)(p + MMI_SPA_PARAM_BYTE_LEN)) + 1;
                            break;
                        default:
                            param_len = MMI_SPA_INT_PARAM_CONTENT_LEN;
                            break;
                    }
                    p += param_len + MMI_SPA_PARAM_BYTE_LEN;
                    i += param_len + MMI_SPA_PARAM_BYTE_LEN;
                    break;
                }
                p += param_len;
                i += param_len;
                break;
            case MMI_SPA_PARAM_AUTHTYPE:
            case MMI_SPA_PARAM_AUTHNAME:
            case MMI_SPA_PARAM_AUTHSECRET:
                /* Add auth node at first */
                if (hAuth == 0)
                {
                    hAuth = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_NAPAUTHINFO, hNap);
                    if (hAuth == 0)
                    {
                        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER_ADD_AUTH_FAIL);
                        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
                    }
                }

                result = mmi_spa_mmsicp_process_param(
                            hAuth,
                            param,
                            (U8*) p,
                            (content_len - i),
                            spa_cca_conv_napauth_table,
                            (U16) sizeof(spa_cca_conv_napauth_table) / sizeof(mmi_spa_cca_conversion_struct),
                            &param_len);

                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER_PROCESS_PARAM_RET, result);

                /* Add this param fail, jump over it */
                if (MMI_SPA_RESULT_OK != result)
                {
                    if (result == MMI_SPA_RESULT_PARSE_CCA_MEM_FULL)
                    {
                        //mmi_cca_doc_node_detach(hNap);
                        //mmi_cca_doc_node_release_all(hNap);
                        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
                    }

                    switch (param)
                    {
                        case MMI_SPA_PARAM_AUTHTYPE:
                            param_len = MMI_SPA_INT_PARAM_CONTENT_LEN;
                            break;
                        case MMI_SPA_PARAM_AUTHNAME:
                        case MMI_SPA_PARAM_AUTHSECRET:
                            param_len = strlen((char*)(p + MMI_SPA_PARAM_BYTE_LEN)) + 1;
                            break;
                        default:
                            param_len = MMI_SPA_INT_PARAM_CONTENT_LEN;
                            break;
                    }
                    p += param_len + MMI_SPA_PARAM_BYTE_LEN;
                    i += param_len + MMI_SPA_PARAM_BYTE_LEN;
                    break;
                }
                p += param_len;
                i += param_len;
                break;
            default:
                /* ASSERT(!"unknown tag"); */
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER_UNKNOWN_TAG, param);
                return MMI_SPA_RESULT_PARSE_INVALID_DATA;
        }
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER_OUT_WHILE_LOOP);

    /*
     * if (hAuth && mmi_spa_mmsicp_check_auth_node(hAuth))
     * {
     * MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER_INVALID_AUTH);
     * mmi_cca_doc_node_detach(hAuth);
     * mmi_cca_doc_node_release_all(hAuth);
     * }
     */
    if (hNap && !mmi_spa_mmsicp_check_nap_node(hNap))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER_INVALID_NAP);
        mmi_spa_mmsicp_delete_nap_node(app_data, hNap);
        hNap = 0;
    }

    if (hNap)
    {
        add_to_prxy_result = mmi_spa_mmsicp_add_tonap_to_proxy(app_data->hProxy, hNap);

        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER_ADD_TONAP_RESULT, add_to_prxy_result);

        if (MMI_SPA_RESULT_OK != add_to_prxy_result)
        {
            return add_to_prxy_result;
        }
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_NETWORK_PARSER_END);
    return MMI_SPA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_gateway_parser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p               [IN]        
 *  data_len        [IN]        
 *  parsed_len      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_mmsicp_gateway_parser(const U8 *p, S32 data_len, S32 *parsed_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 param;
    MMI_BOOL ret;
    U16 i;
    S32 content_len;
    S32 len;
    S32 param_len;
    S32 hProxy = 0;
    S32 hAuth = 0;
    S32 hPort = 0;
    mmi_spa_result_enum result;
    mmi_spa_parser_mmsicp_data_struct *app_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GATEWAY_PARSER, data_len);

    if (!p || !parsed_len)
    {
        return MMI_SPA_RESULT_PARSE_ERROR_PARAM;
    }

    app_data = (mmi_spa_parser_mmsicp_data_struct*) g_spa_ef_parser_context.app_data;

    /* get tag length */
    p++;

    ret = mmi_spa_mmsicp_get_tag_len(p, data_len, &content_len, &len);
    if (ret == FALSE)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GATEWAY_PARSER_GET_LEN_FAIL);
        return MMI_SPA_RESULT_PARSE_ERROR_LENGTH;
    }

    *parsed_len = content_len + len + MMI_SPA_TAG_BYTE_LEN;

    if (*parsed_len > data_len)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GATEWAY_PARSER_TOO_LONG_LEN);
        return MMI_SPA_RESULT_PARSE_INVALID_DATA;
    }

    /* jump over length bytes */
    p += len;

    /* process content */
    i = 0;
    /* content_len = *parsed_len; */
    hProxy = app_data->hProxy;

    while (i < content_len)
    {
        param = *p;

        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GATEWAY_PARSER_PARAM_VALUE, param);

        switch (param)
        {
            case MMI_SPA_PARAM_PROXY_ID:
            case MMI_SPA_PARAM_PROXY_PROVIDE_ID:
                result = mmi_spa_mmsicp_process_param(
                            hProxy,
                            param,
                            (U8*) p,
                            (content_len - i),
                            spa_cca_conv_proxy_table,
                            sizeof(spa_cca_conv_proxy_table) / sizeof(mmi_spa_cca_conversion_struct),
                            &param_len);

                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GATEWAY_PARSER_PROCESS_PARAM_RESULT, result);

                if (MMI_SPA_RESULT_OK != result)
                {
                    if (result == MMI_SPA_RESULT_PARSE_CCA_MEM_FULL)
                    {
                        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
                    }
                    switch (param)
                    {
                        case MMI_SPA_PARAM_PROXY_ID:
                        case MMI_SPA_PARAM_PROXY_PROVIDE_ID:
                            param_len = strlen((char*)(p + MMI_SPA_PARAM_BYTE_LEN)) + 1;
                            break;
                        default:
                            param_len = MMI_SPA_INT_PARAM_CONTENT_LEN;
                            break;
                    }
                    p += param_len + MMI_SPA_PARAM_BYTE_LEN;
                    i += param_len + MMI_SPA_PARAM_BYTE_LEN;
                    break;
                }
                p += param_len;
                i += param_len;
                break;
            case MMI_SPA_PARAM_PXAUTH_TYPE:
            case MMI_SPA_PARAM_PXAUTH_IDM:
            case MMI_SPA_PARAM_PXAUTH_PW:
                /* Add auth node at first */
                if (hAuth == 0)
                {
                    hAuth = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PXAUTHINFO, hProxy);
                    if (hAuth == 0)
                    {
                        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GATEWAY_PARSER_ADD_AUTH_FAIL);
                        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
                    }
                }

                result = mmi_spa_mmsicp_process_param(
                            hAuth,
                            param,
                            (U8*) p,
                            (content_len - i),
                            spa_cca_conv_proxy_table,
                            (U16) sizeof(spa_cca_conv_proxy_table) / sizeof(mmi_spa_cca_conversion_struct),
                            &param_len);

                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GATEWAY_PARSER_PROCESS_PARAM_RESULT, result);

                if (MMI_SPA_RESULT_OK != result)
                {
                    if (result == MMI_SPA_RESULT_PARSE_CCA_MEM_FULL)
                    {
                        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
                    }
                    switch (param)
                    {
                        case MMI_SPA_PARAM_PXAUTH_TYPE:
                            param_len = MMI_SPA_INT_PARAM_CONTENT_LEN;
                            break;
                        case MMI_SPA_PARAM_PXAUTH_IDM:
                        case MMI_SPA_PARAM_PXAUTH_PW:
                            param_len = strlen((char*)(p + MMI_SPA_PARAM_BYTE_LEN)) + 1;
                            break;
                        default:
                            param_len = MMI_SPA_INT_PARAM_CONTENT_LEN;
                            break;
                    }
                    p += param_len + MMI_SPA_PARAM_BYTE_LEN;
                    i += param_len + MMI_SPA_PARAM_BYTE_LEN;
                    break;
                }
                p += param_len;
                i += param_len;
                break;
            case MMI_SPA_PARAM_PXADDR:
            case MMI_SPA_PARAM_PXADDRTYPE:
                result = mmi_spa_mmsicp_process_param(
                            hProxy,
                            param,
                            (U8*) p,
                            (content_len - i),
                            spa_cca_conv_proxy_table,
                            (U16) sizeof(spa_cca_conv_proxy_table) / sizeof(mmi_spa_cca_conversion_struct),
                            &param_len);

                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GATEWAY_PARSER_PROCESS_PARAM_RESULT, result);

                if (MMI_SPA_RESULT_OK != result)
                {
                    if (result == MMI_SPA_RESULT_PARSE_CCA_MEM_FULL)
                    {
                        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
                    }
                    switch (param)
                    {
                        case MMI_SPA_PARAM_PXADDR:
                            param_len = strlen((char*)(p + MMI_SPA_PARAM_BYTE_LEN)) + 1;
                            break;
                        case MMI_SPA_PARAM_PXADDRTYPE:
                            param_len = MMI_SPA_INT_PARAM_CONTENT_LEN;
                            break;
                        default:
                            param_len = MMI_SPA_INT_PARAM_CONTENT_LEN;
                            break;
                    }
                    p += param_len + MMI_SPA_PARAM_BYTE_LEN;
                    i += param_len + MMI_SPA_PARAM_BYTE_LEN;
                    break;
                }
                p += param_len;
                i += param_len;
                break;

            case MMI_SPA_PARAM_PORTNBR:
            case MMI_SPA_PARAM_SERVICE:
                /* Add port node at first */
                if (hPort == 0)
                {
                    hPort = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PORT, hProxy);
                    if (hPort == 0)
                    {
                        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GATEWAY_PARSER_ADD_PORT_FAIL);
                        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
                    }
                }

                result = mmi_spa_mmsicp_process_param(
                            hPort,
                            param,
                            (U8*) p,
                            (content_len - i),
                            spa_cca_conv_proxy_table,
                            (U16) sizeof(spa_cca_conv_proxy_table) / sizeof(mmi_spa_cca_conversion_struct),
                            &param_len);

                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GATEWAY_PARSER_PROCESS_PARAM_RESULT, result);

                if (MMI_SPA_RESULT_OK != result)
                {
                    if (result == MMI_SPA_RESULT_PARSE_CCA_MEM_FULL)
                    {
                        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
                    }
                    switch (param)
                    {
                        case MMI_SPA_PARAM_PORTNBR:
                            param_len = strlen((char*)(p + MMI_SPA_PARAM_BYTE_LEN)) + 1;
                            break;
                        case MMI_SPA_PARAM_SERVICE:
                            param_len = MMI_SPA_INT_PARAM_CONTENT_LEN;
                            break;
                        default:
                            param_len = MMI_SPA_INT_PARAM_CONTENT_LEN;
                            break;
                    }
                    p += param_len + MMI_SPA_PARAM_BYTE_LEN;
                    i += param_len + MMI_SPA_PARAM_BYTE_LEN;
                    break;
                }
                p += param_len;
                i += param_len;
                break;
            default:
                /* ASSERT(!"error gateway tag"); */
                MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GATEWAY_PARSER_UNKNOWN_TAG, param);
                return MMI_SPA_RESULT_PARSE_INVALID_DATA;
        }
    }

    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_GATEWAY_PARSER_END);

    return MMI_SPA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_check_proxy_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hNode       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_check_proxy_node(S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *addr;
    S8 *toNap;
    S32 addr_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CHECK_PROXY_NODE);

    if (!hNode)
    {
        return MMI_FALSE;
    }

    /* get addr */
    if (CCA_STATUS_OK != mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_PXADDR, &addr))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CHECK_PROXY_NODE_GET_PXADDR_FAIL);
        return MMI_FALSE;
    }

    /* get addr type */
    if (CCA_STATUS_OK != mmi_cca_doc_nodedata_int_first(hNode, CCA_NS_OMA_PXADDRTYPE, &addr_type))
    {
        /* IPV4 is default */
        addr_type = CCA_NS_VAL_IPV4;
    }

    /* validate addr */
    if (!mmi_spa_validate_proxy_addr(addr, addr_type))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CHECK_PROXY_NODE_INVALID_ADDR);
        return MMI_FALSE;
    }

    if (CCA_STATUS_OK != mmi_cca_doc_nodedata_str_first(hNode, CCA_NS_OMA_TO_NAPID, &toNap))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CHECK_PROXY_NODE_NO_TONAPID);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_validate_proxy_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  addr            [?]         [?]         [?]         [?]         [?]
 *  addr_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_spa_validate_proxy_addr(S8 *addr, S32 addr_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 len;
    S16 count = 0;
    S8 *p = NULL;
    S8 *val = NULL;
    S8 temp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (addr_type)
    {
        case CCA_NS_VAL_IPV4:
            len = strlen(addr);
            if (len > MMI_SPA_IPV4_MAX_TOTAL_LEN)
            {
                return MMI_FALSE;
            }

            p = addr;
            val = addr;
            while (1)
            {
                if (*p != '.' && *p != 0)
                {
                    p++;
                    continue;
                }

                count++;
                if (count > MMI_SPA_IPV4_MAX_NUM_COUNT)
                {
                    return MMI_FALSE;
                }

                if (*p == '.')
                {
                    temp = *p;
                    *p = 0;
                }

                if (atoi(val) > MMI_SPA_IPV4_MAX_NUM_VAL)
                {
                    if (temp)
                    {
                        *p = temp;
                    }
                    return MMI_FALSE;
                }

                if (temp)
                {
                    *p = temp;
                    temp = 0;
                }

                if (*p == 0)    /* end */
                {
                    break;
                }
                else    /* goto next value */
                {
                    p++;
                    val = p;
                }
            }

            if (count < MMI_SPA_IPV4_MAX_NUM_COUNT)
            {
                return MMI_FALSE;
            }

            return MMI_TRUE;
        case CCA_NS_VAL_IPV6:
        case CCA_NS_VAL_E164:
        case CCA_NS_VAL_ALPHA:
        case CCA_NS_VAL_APN:
        case CCA_NS_VAL_SCODE:
        case CCA_NS_VAL_TETRA_ITSI:
        case CCA_NS_VAL_MAN:
        default:
            return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_process_param
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node            [IN]        
 *  param           [IN]        
 *  p               [?]         [?]         [?]         [?]         [?]
 *  data_len        [IN]        
 *  table           [IN]        
 *  table_len       [IN]        
 *  len             [?]         [?]         [?]         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_mmsicp_process_param(
                            S32 node,
                            U8 param,
                            U8 *p,
                            S32 data_len,
                            const mmi_spa_cca_conversion_struct *table,
                            U16 table_len,
                            S32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 val = 0;
    U8 tmp = 0;
    U16 i = 0;
    U16 val_table_len = 0;
    S32 param_len = 0;
    S32 str_len = 0;
    mmi_spa_value_conv_struct *val_table_item = NULL;
    const mmi_spa_cca_conversion_struct *item = NULL;
    mmi_spa_result_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PROCESS_PARAM, param);

    for (i = 0; i < table_len; i++)
    {
        item = table + i;
        if (item->simpSymbol == param)
        {
            break;
        }
    }

    if (i == table_len)
    {
        return MMI_SPA_RESULT_PARSE_UNSUPPORT_PARAM;
    }

    if (item->type == MMI_SPA_CONVERT_TYPE_STR)
    {
        str_len = strlen((char*)(p + 1)) + 1;
        if (str_len > (data_len - MMI_SPA_PARAM_BYTE_LEN))
        {
            tmp = *(p + data_len);
            *(p + data_len) = 0;
            str_len = data_len - MMI_SPA_PARAM_BYTE_LEN;
        }
        if (mmi_cca_doc_add_nodedata_str(node, item->ccaSymbol, (S8*) (p + 1)))
        {
            if (tmp)
            {
                *(p + data_len) = tmp;
            }
            return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
        }
        if (tmp)
        {
            *(p + data_len) = tmp;
        }

        param_len = str_len + MMI_SPA_PARAM_BYTE_LEN;
    }
    else if (item->type == MMI_SPA_CONVERT_TYPE_INT)
    {
        val = *(p + 1);
        if (mmi_cca_doc_add_nodedata_int(node, item->ccaSymbol, (S32) val))
        {
            return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
        }
        param_len = MMI_SPA_INT_PARAM_TOTAL_LEN;
    }
    else if (item->type == MMI_SPA_CONVERT_TYPE_ENUM)
    {
        param_len = MMI_SPA_INT_PARAM_TOTAL_LEN;

        val = *(p + 1);
        val_table_len = item->enumTableSize;
        for (i = 0; i < val_table_len; i++)
        {
            val_table_item = item->enumTable + i;
            if (val_table_item->value == val)
            {
                break;
            }
        }
        /* Item not found, it is a string value */
        if (i == val_table_len)
        {
            MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_MMSICP_PROCESS_PARAM_NO_THIS_ENUM_VALUE, param, val);

            /* Not ASCII char, can't process as string */
            if (val & MMI_SPA_MMSICP_BYTE_PARAM_VALUE_CHECKER)
            {
                return MMI_SPA_RESULT_PARSE_UNSUPPORT_PARAM;
            }
            /* It is a string value */
            ret = mmi_spa_mmsicp_process_string_param(p, data_len, node, item, &param_len);
            if (ret != MMI_SPA_RESULT_OK)
            {
                return ret;
            }
        }
        else if (mmi_cca_doc_add_nodedata_int(node, item->ccaSymbol, val_table_item->ccaValSymbol))
        {
            return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
        }
    }

    *len = param_len;

    return MMI_SPA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_process_string_param
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p               [?]         [?]         [?]
 *  data_len        [IN]        
 *  node            [IN]        
 *  item            [IN]        
 *  param_len       [?]         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
static mmi_spa_result_enum mmi_spa_mmsicp_process_string_param(
                            U8 *p,
                            S32 data_len,
                            S32 node,
                            const mmi_spa_cca_conversion_struct *item,
                            S32 *param_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 value;
    S32 str_len = 0;
    U8 tmp = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_len = strlen((char*)(p + 1)) + 1;
    if (str_len > (data_len - MMI_SPA_PARAM_BYTE_LEN))
    {
        tmp = *(p + data_len);
        *(p + data_len) = 0;
        str_len = data_len - MMI_SPA_PARAM_BYTE_LEN;
    }

    if (item->simpSymbol == MMI_SPA_PARAM_LINKSPEED)
    {
        value = atoi((S8*) (p + 1));
        if (CCA_STATUS_OK != mmi_cca_doc_add_nodedata_int(node, item->ccaSymbol, value))
        {
            if (tmp)
            {
                *(p + data_len) = tmp;
            }
            return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
        }
    }
    else if (CCA_STATUS_OK != mmi_cca_doc_add_nodedata_str(node, item->ccaSymbol, (S8*) (p + 1)))
    {
        if (tmp)
        {
            *(p + data_len) = tmp;
        }
        return MMI_SPA_RESULT_PARSE_CCA_MEM_FULL;
    }
    if (tmp)
    {
        *(p + data_len) = tmp;
    }

    *param_len = str_len + MMI_SPA_PARAM_BYTE_LEN;

    return MMI_SPA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_ef_release_cca_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hConfig     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_spa_ef_release_cca_config(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hConfig)
    {
        return;
    }

    mmi_cca_doc_release(hConfig);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_check_hconfig
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hConfig     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_spa_check_hconfig(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_iterator_struct *iter_nodelist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CHECK_HCONFIG);

    if (mmi_cca_doc_get_nodes(hConfig, CCA_NS_OMA_APPLICATION, &iter_nodelist, 0))
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CHECK_HCONFIG_GET_APP_FAIL);
        return MMI_FALSE;
    }

    if (mmi_cca_iterator_next(iter_nodelist) == NULL)
    {
        MMI_TRACE(SPA_TRACE_INFO, TRC_MMI_SPA_CHECK_HCONFIG_NO_APP);
        mmi_cca_iterator_release(iter_nodelist);
        return MMI_FALSE;
    }

    mmi_cca_iterator_release(iter_nodelist);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_clear_parser_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_clear_parser_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_spa_ef_parser_context.app_data)
    {
        mmi_spa_free(g_spa_ef_parser_context.app_data);
    }
    memset(&g_spa_ef_parser_context, 0, sizeof(g_spa_ef_parser_context));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_clear_parser_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_mmsicp_clear_parser_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_spa_parser_mmsicp_data_struct *app_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_data = (mmi_spa_parser_mmsicp_data_struct*) g_spa_ef_parser_context.app_data;
    mmi_spa_mmsicp_node_buf_release(app_data);

    mmi_spa_clear_parser_context();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_node_buf_add_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_data        [?]         [?]         [?]         [?]
 *  node            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_spa_mmsicp_node_buf_add_node(mmi_spa_parser_mmsicp_data_struct *app_data, S32 node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *new_buf = NULL;
    S32 new_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!app_data->node_buf)    /* Create new buffer */
    {
        app_data->node_buf = mmi_spa_malloc(sizeof(S32) * MMI_SPA_MMSICP_NODE_BUF_COUNT);
        if (!app_data->node_buf)
        {
            return MMI_SPA_RESULT_MEM_FULL;
        }

        memset(app_data->node_buf, 0, sizeof(S32) * MMI_SPA_MMSICP_NODE_BUF_COUNT);

        app_data->node_buf_max_count = MMI_SPA_MMSICP_NODE_BUF_COUNT;
        app_data->node_buf_used_count = 0;
    }
    else
    {
        if (app_data->node_buf_used_count == app_data->node_buf_max_count)
        {
            new_len = sizeof(S32) * app_data->node_buf_max_count + MMI_SPA_MMSICP_NODE_BUF_COUNT;
            new_buf = mmi_spa_malloc(new_len);

            if (!new_buf)
            {
                return MMI_SPA_RESULT_MEM_FULL;
            }

            memset(new_buf, 0, new_len);
            memcpy(new_buf, app_data->node_buf, app_data->node_buf_max_count * sizeof(S32));
            mmi_spa_free(app_data->node_buf);

            app_data->node_buf = new_buf;
            app_data->node_buf_max_count = app_data->node_buf_max_count + MMI_SPA_MMSICP_NODE_BUF_COUNT;
        }
    }

    app_data->node_buf[app_data->node_buf_used_count] = node;
    app_data->node_buf_used_count++;

    return MMI_SPA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_node_buf_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_data        [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_mmsicp_node_buf_release(mmi_spa_parser_mmsicp_data_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!app_data)
    {
        return;
    }

    if (app_data->node_buf)
    {
        mmi_spa_free(app_data->node_buf);
    }
    app_data->node_buf_max_count = 0;
    app_data->node_buf_used_count = 0;
    app_data->node_buf = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_node_buf_delete_all_nodes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_data        [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_mmsicp_node_buf_delete_all_nodes(mmi_spa_parser_mmsicp_data_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < app_data->node_buf_max_count; i++)
    {
        if (app_data->node_buf[i])
        {
            mmi_cca_doc_node_detach(app_data->node_buf[i]);
            mmi_cca_doc_node_release_all(app_data->node_buf[i]);
            app_data->node_buf[i] = 0;
        }
    }
    app_data->node_buf_used_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spa_mmsicp_node_buf_delete_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_data        [?]         [?]         [?]         [?]
 *  node            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_spa_mmsicp_node_buf_delete_node(mmi_spa_parser_mmsicp_data_struct *app_data, S32 node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!app_data || !app_data->node_buf)
    {
        return;
    }

    for (i = 0; i < app_data->node_buf_max_count; i++)
    {
        if (app_data->node_buf[i] == node)
        {
            app_data->node_buf[i] = 0;
            app_data->node_buf_used_count--;
        }
    }
}

#endif /* __SPA_SUPPORT__ */ 

