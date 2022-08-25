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
 *  DataAccountXml.c
 *
 * Project:
 * -------- 
 *  
 *
 * Description:
 * ------------
 *  Parse Data Account Configuration.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__TCPIP__) && defined(__XML_SUPPORT__)
#if defined(__DA_SMART_SELECTION_SUPPORT__)
/***************************************************************************** 
 * Include
 *****************************************************************************/
#if defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "mmi_ap_dcm_config.h" 
#endif
#include <stdlib.h>
#include <string.h>
#include "conversions.h"
#include "fs_type.h"
#include "xml_def.h"
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "kal_general_types.h"
#include "DataAccountStruct.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "DataAccountProt.h"
#include "DataAccountEnum.h"
#include "MMIDataType.h"
#include "DataAccountGProt.h"
#include "Unicodexdcl.h"
#include "DataAccountDef.h"
//#include "stack_config.h"
//#include "stack_msgs.h"
//#include "stack_ltlcom.h"
//#include "app_ltlcom.h"
#include "mmi_frm_events_gprot.h"
#include "fs_func.h"
#include "kal_public_api.h"
#include "mmi_frm_queue_gprot.h"


#ifndef __MMI_DTCNT_XML_SLIM__
#ifdef __MMI_AP_DCM_DTCNT__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define DTCNT_MAX_PARSE_ITEM    20

#define NODE_LEVEL_3    3
#define NODE_LEVEL_4    4
#define NODE_LEVEL_5    5

#define DTCNT_TYPE_DATA 1
#define DTCNT_TYPE_ATTR 2

#define DTCNT_VERS_NAME          "AcntVer"
#define DTCNT_VERS_VALUE         "1.0"
#define DTCNT_NODE_SIM           "SIM"
#define DTCNT_NODE_ITEM          "Item"
#define DTCNT_ATTR_OPTR          "Operator"
#define DTCNT_ATTR_CODE          "Code"
#define DTCNT_ATTR_BEARER_GPRS   "GPRS"
#define DTCNT_ATTR_BEARER_CSD    "CSD"
#define DTCNT_ATTR_ENABLE        "Enable"
#define DTCNT_ATTR_ADDRESS       "ProxyAddress"
#define DTCNT_ATTR_PORT          "ProxyPort"
#define DTCNT_ATTR_USERNAME      "ProxyUsername"
#define DTCNT_ATTR_PASSWORD      "ProxyPassword"

#define DTCNT_ATTR_VAL_YES       "Yes"
#define DTCNT_ATTR_VAL_NO        "No"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef kal_int32 (*dtcnt_call)(const kal_char *, const kal_char **, const kal_char *, kal_int32);

typedef struct 
{
    kal_char *name;
    kal_uint16 deep;
    kal_uint16 type;
    dtcnt_call call_back;
} mmi_dtcnt_node_struct;


typedef struct 
{
    XML_PARSER_STRUCT xml_parser;
    kal_uint8 save;
    kal_uint8 bearer;
    kal_uint8 stack;
    kal_uint8 count;
    srv_dtcnt_prof_common_header_struct *comm_dtcnt_data;
    U8 *acct_name;
    U8 *addr; // apn or dial number
    srv_dtcnt_prof_csd_dial_type_enum *dialType;
    srv_dtcnt_prof_csd_rate_enum *dataRate;
} mmi_dtcnt_parser_struct;


/***************************************************************************** 
 * Variable
 *****************************************************************************/

static mmi_dtcnt_parser_struct g_mmi_dtcnt_parser;
static XML_PARSER_STRUCT *g_dtcnt_xml_parser = &g_mmi_dtcnt_parser.xml_parser;

/***************************************************************************** 
 * Static function
 *****************************************************************************/

static kal_int32 dtcnt_node_version(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_sim(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_item(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_apptype(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_title(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_number(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_linetype(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_speed(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_homepage(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_proxy(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_username(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_password(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_primarydns(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_seconddns(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_apn(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_authentication(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_ipaddress(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_subnet(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
/* static kal_int32 dtcnt_node_gateway(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);*/
static kal_int32 dtcnt_node_conntype(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 dtcnt_node_readonly(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static void mmi_dtcnt_elem_start_hdlr(void *data, const kal_char *el, const kal_char **attr, kal_int32 error);
static void mmi_dtcnt_elem_end_hdlr(void *data, const kal_char *el, kal_int32 error);
static void mmi_dtcnt_data_hdlr(void *resv, const kal_char *el, const kal_char *data, kal_int32 len, kal_int32 error);
static void mmi_dtcnt_resume_parse_hdlr(void *msg);

static mmi_dtcnt_node_struct mmi_dtcnt_node[] = 
{
    {"AcntVer",         NODE_LEVEL_3,  DTCNT_TYPE_DATA, dtcnt_node_version},
    {"SIM",             NODE_LEVEL_3,  DTCNT_TYPE_ATTR, dtcnt_node_sim},
    {"Item",            NODE_LEVEL_4,  DTCNT_TYPE_ATTR, dtcnt_node_item},
    {"AppType",         NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_apptype},
    {"Title",           NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_title},
    {"Number",          NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_number},
    {"LineType",        NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_linetype},
    {"Speed",           NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_speed},
    {"Homepage",        NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_homepage},
    {"Proxy",           NODE_LEVEL_5,  DTCNT_TYPE_ATTR, dtcnt_node_proxy},
    {"Username",        NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_username},
    {"Password",        NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_password},
    {"PrimaryDNS",      NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_primarydns},
    {"SecondDNS",       NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_seconddns},
    {"APN",             NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_apn},
    {"Authentication",  NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_authentication},
    {"IPAddress",       NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_ipaddress},
    {"Subnet",          NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_subnet},
    /*{"Gateway",         NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_gateway},*/
    {"ConnectionType",  NODE_LEVEL_5,  DTCNT_TYPE_DATA, dtcnt_node_conntype},
    {"Readonly",        NODE_LEVEL_5,  DTCNT_TYPE_ATTR, dtcnt_node_readonly},
};


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_version
 * DESCRIPTION
 *  Parser data account version.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_version(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_VERSION, len);
    if (data == NULL || len == 0)
    {
        return KAL_FALSE;
    }

    if (strncmp(data, DTCNT_VERS_VALUE, len) != 0)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_sim
 * DESCRIPTION
 *  Parser data account sim.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_sim(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_char *optr = NULL;
    const kal_char *sim_code = NULL;
    kal_int32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((attr[i] != NULL) && (attr[i+1] != NULL))
    {
        if (strcmp(attr[i], DTCNT_ATTR_OPTR) == 0)
        {
            optr = attr[i+1];
        }
        else if (strcmp(attr[i], DTCNT_ATTR_CODE) == 0)
        {
            sim_code = attr[i+1];
        }

        i+=2;
    }
    
    g_mmi_dtcnt_parser.save = mmi_dtcnt_sim_match(optr, sim_code);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_SIM, g_mmi_dtcnt_parser.save);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_item
 * DESCRIPTION
 *  Parser data account node.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
kal_int32 dtcnt_node_item(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 bearer = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (attr[0] == NULL || attr[1] == NULL)
    {
        #ifdef __MMI_GPRS_FEATURES__
        bearer = SRV_DTCNT_BEARER_GPRS;
        #endif
    }
    else if (strcmp(attr[1], DTCNT_ATTR_BEARER_GPRS) == 0)
    {
        #ifdef __MMI_GPRS_FEATURES__
        bearer = SRV_DTCNT_BEARER_GPRS;
        #endif
    }
    else if (strcmp(attr[1], DTCNT_ATTR_BEARER_CSD) == 0)
    {
        #ifdef __TCPIP_OVER_CSD__
        bearer = SRV_DTCNT_BEARER_CSD;
        #endif
    }

    g_mmi_dtcnt_parser.bearer = bearer;
    mmi_dtcnt_account_item_start(
        bearer, 
        &g_mmi_dtcnt_parser.comm_dtcnt_data,
        &g_mmi_dtcnt_parser.acct_name,
        &g_mmi_dtcnt_parser.addr,
        &g_mmi_dtcnt_parser.dialType,
        &g_mmi_dtcnt_parser.dataRate);
    g_mmi_dtcnt_parser.count++;
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_ITEM, g_mmi_dtcnt_parser.bearer);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_apptype
 * DESCRIPTION
 *  Parser data account application type.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_apptype(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:
    case SRV_DTCNT_BEARER_CSD:
    #if defined (__MMI_GPRS_FEATURES__) || defined (__TCPIP_OVER_CSD__)
        g_mmi_dtcnt_parser.comm_dtcnt_data->AppType = (U64)mmi_dtcnt_get_type(MMI_DTCNT_APP_TYPE, data);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_APPTYPE, len, g_mmi_dtcnt_parser.comm_dtcnt_data->AppType);
    #endif
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_title
 * DESCRIPTION
 *  Parser data account title.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_title(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 tmp_str[SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1];
    S32 utf8_len = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_TITLE, len); 
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:
    case SRV_DTCNT_BEARER_CSD:
        #if defined (__MMI_GPRS_FEATURES__) || defined (__TCPIP_OVER_CSD__)
        if (len <= SRV_DTCNT_PROF_MAX_ACC_NAME_LEN)
        {
            utf8_len = len;
            memcpy(tmp_str, data, len);
            tmp_str[len] = 0;
        }
        else
        {
            utf8_len = SRV_DTCNT_PROF_MAX_ACC_NAME_LEN;
            memcpy(tmp_str, data, SRV_DTCNT_PROF_MAX_ACC_NAME_LEN);
            tmp_str[SRV_DTCNT_PROF_MAX_ACC_NAME_LEN] = 0;
        }
        //mmi_asc_to_ucs2((CHAR*)bearer_gprs->data_account_name, (CHAR*)tmp_str);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8 *)g_mmi_dtcnt_parser.acct_name, 
            (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1)* ENCODING_LENGTH, 
            (kal_uint8 *)tmp_str);
    
        if (mmi_wcslen((WCHAR*)g_mmi_dtcnt_parser.acct_name) != utf8_len) /*check is ascii encode or not */
        {
            mmi_chset_convert(
                CHSET_UTF8, 
                CHSET_UCS2, 
                (char*)data, 
                (char*)g_mmi_dtcnt_parser.acct_name, 
                (kal_int32)(SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1));
        }
        #endif
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_number
 * DESCRIPTION
 *  Parser data account number.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_number(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *dialNumber;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_NUMBER, len);  
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:        
        break;

    case SRV_DTCNT_BEARER_CSD:
        #ifdef __TCPIP_OVER_CSD__
        dialNumber = g_mmi_dtcnt_parser.addr;
        if (len <= SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN)
        {
            memcpy(dialNumber, data, len);
            dialNumber[len] = 0;
        }
        else
        {
            memcpy(dialNumber, data, SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN);
            dialNumber[SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN] = 0;
        }
        
        if(g_mmi_dtcnt_parser.save)
        {
            g_mmi_dtcnt_parser.comm_dtcnt_data->sim_info = (srv_dtcnt_sim_type_enum)g_mmi_dtcnt_parser.save; /* add sim_info here because dial number needed */
        }
        #endif
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_linetype
 * DESCRIPTION
 *  Parser data account line type.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
kal_int32 dtcnt_node_linetype(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:        
        break;

    case SRV_DTCNT_BEARER_CSD:
        #ifdef __TCPIP_OVER_CSD__        
        *g_mmi_dtcnt_parser.dialType = (srv_dtcnt_prof_csd_dial_type_enum)mmi_dtcnt_get_type(MMI_DTCNT_DIAL_TYPE, data);
        #endif
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_speed
 * DESCRIPTION
 *  Parser data account speed.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_speed(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:        
        break;

    case SRV_DTCNT_BEARER_CSD:
        #ifdef __TCPIP_OVER_CSD__
        *g_mmi_dtcnt_parser.dataRate = (srv_dtcnt_prof_csd_rate_enum)mmi_dtcnt_get_type(MMI_DTCNT_DATA_RATE_TYPE, data);
        #endif
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_homepage
 * DESCRIPTION
 *  Parser data account homepage.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_homepage(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_HOMEPAGE, len);
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:
    case SRV_DTCNT_BEARER_CSD:
        #if defined (__MMI_GPRS_FEATURES__) || defined (__TCPIP_OVER_CSD__)
        if (len < SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN)
        {
            memcpy(g_mmi_dtcnt_parser.comm_dtcnt_data->HomePage, data, len);
            g_mmi_dtcnt_parser.comm_dtcnt_data->HomePage[len] = 0;
        }
        else
        {
            memcpy(g_mmi_dtcnt_parser.comm_dtcnt_data->HomePage, data, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN - 1);
            g_mmi_dtcnt_parser.comm_dtcnt_data->HomePage[SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN - 1] = 0;
        }
        #endif
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_proxy
 * DESCRIPTION
 *  Parser data account proxy.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_proxy(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 proxy = KAL_FALSE;
    const kal_char *address = NULL, *port = NULL, *username = NULL, *password = NULL;
    kal_int32 i = 0, str_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((attr[i] != NULL) && (attr[i+1] != NULL))
    {
        if (strcmp(attr[i], DTCNT_ATTR_ENABLE) == 0)
        {
            if (strcmp(attr[i+1], DTCNT_ATTR_VAL_YES) == 0)
            {
                proxy = KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
        }
        else if (strcmp(attr[i], DTCNT_ATTR_ADDRESS) == 0)
        {
            address = attr[i+1];
        }
        else if (strcmp(attr[i], DTCNT_ATTR_PORT) == 0)
        {
            port = attr[i+1];
        }
        else if (strcmp(attr[i], DTCNT_ATTR_USERNAME) == 0)
        {
            username = attr[i+1];
        }
        else if (strcmp(attr[i], DTCNT_ATTR_PASSWORD) == 0)
        {
            password = attr[i+1];
        }
        
        i+=2;
    }

    if (!proxy)
    {
        switch (g_mmi_dtcnt_parser.bearer)
        {
        case SRV_DTCNT_BEARER_GPRS:
        case SRV_DTCNT_BEARER_CSD:
            #if defined (__MMI_GPRS_FEATURES__) || defined (__TCPIP_OVER_CSD__)
            g_mmi_dtcnt_parser.comm_dtcnt_data->use_proxy = 0;
            #endif
            break;            
        default:
            break;
        }
        return KAL_TRUE;
    }

    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:
    case SRV_DTCNT_BEARER_CSD:
        #if defined (__MMI_GPRS_FEATURES__) || defined (__TCPIP_OVER_CSD__)
        g_mmi_dtcnt_parser.comm_dtcnt_data->use_proxy = 1;
        if (address)
        {
            str_len = strlen(address);
            if (str_len <= MMI_DTCNT_MAX_PROXY_URL_LEN)
            {
                memcpy(g_mmi_dtcnt_parser.comm_dtcnt_data->px_addr, address, str_len);
                g_mmi_dtcnt_parser.comm_dtcnt_data->px_addr[str_len] = 0;
            }
            else
            {
                memcpy(g_mmi_dtcnt_parser.comm_dtcnt_data->px_addr, address, MMI_DTCNT_MAX_PROXY_URL_LEN);
                g_mmi_dtcnt_parser.comm_dtcnt_data->px_addr[MMI_DTCNT_MAX_PROXY_URL_LEN] = 0;
            }
        }

        if (port)
        {
            U32 portVal = atoi(port);
            if (portVal > MMI_DTCNT_MAX_PORT_NUM)
            {
                g_mmi_dtcnt_parser.comm_dtcnt_data->px_port = 0;
            }
            else
            {
                g_mmi_dtcnt_parser.comm_dtcnt_data->px_port = (U16)portVal;
            }
        }
        if (username)
        {
            str_len = strlen(username);
            if (str_len <= SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN)
            {
                memcpy(g_mmi_dtcnt_parser.comm_dtcnt_data->px_authid, username, str_len);
                g_mmi_dtcnt_parser.comm_dtcnt_data->px_authid[str_len] = 0;
            }
            else
            {
                memcpy(g_mmi_dtcnt_parser.comm_dtcnt_data->px_authid, username, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN);
                g_mmi_dtcnt_parser.comm_dtcnt_data->px_authid[SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN] = 0;
            }
        }
        if (password)
        {
            str_len = strlen(password);
            if (str_len <= SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN)
            {
                memcpy(g_mmi_dtcnt_parser.comm_dtcnt_data->px_authpw, password, str_len);
                g_mmi_dtcnt_parser.comm_dtcnt_data->px_authpw[str_len] = 0;
            }
            else
            {
                memcpy(g_mmi_dtcnt_parser.comm_dtcnt_data->px_authpw, password, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN);
                g_mmi_dtcnt_parser.comm_dtcnt_data->px_authpw[SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN] = 0;
            }
        }
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_PROXY, g_mmi_dtcnt_parser.comm_dtcnt_data->use_proxy);
        #endif
        break;
    }   
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_username
 * DESCRIPTION
 *  Parser data account user name.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_username(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_USERNAME, len);
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:
    case SRV_DTCNT_BEARER_CSD:
        #if defined (__MMI_GPRS_FEATURES__) || defined (__TCPIP_OVER_CSD__)
        if (len <= SRV_DTCNT_PROF_MAX_USER_LEN)
        {
            memcpy(g_mmi_dtcnt_parser.comm_dtcnt_data->Auth_info.UserName, data, len);
            g_mmi_dtcnt_parser.comm_dtcnt_data->Auth_info.UserName[len] = 0;
        }
        else
        {
            memcpy(g_mmi_dtcnt_parser.comm_dtcnt_data->Auth_info.UserName, data, SRV_DTCNT_PROF_MAX_USER_LEN);
            g_mmi_dtcnt_parser.comm_dtcnt_data->Auth_info.UserName[SRV_DTCNT_PROF_MAX_USER_LEN] = 0;
        }
        #endif
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_password
 * DESCRIPTION
 *  Parser data account pass word.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_password(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_PASSWORD, len);
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:
    case SRV_DTCNT_BEARER_CSD:
        #if defined (__MMI_GPRS_FEATURES__) || defined (__TCPIP_OVER_CSD__)
        if (len <= SRV_DTCNT_PROF_MAX_PW_LEN)
        {
            memcpy(g_mmi_dtcnt_parser.comm_dtcnt_data->Auth_info.Passwd, data, len);
            g_mmi_dtcnt_parser.comm_dtcnt_data->Auth_info.Passwd[len] = 0;
        }
        else
        {
            memcpy(g_mmi_dtcnt_parser.comm_dtcnt_data->Auth_info.Passwd, data, SRV_DTCNT_PROF_MAX_PW_LEN);
            g_mmi_dtcnt_parser.comm_dtcnt_data->Auth_info.Passwd[SRV_DTCNT_PROF_MAX_PW_LEN] = 0;
        }
        #endif
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_primarydns
 * DESCRIPTION
 *  Parser data account primary DNS.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_primarydns(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_PRIMARYDNS, len);
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:    
    case SRV_DTCNT_BEARER_CSD:
        #if defined (__MMI_GPRS_FEATURES__) || defined (__TCPIP_OVER_CSD__)        
        if (len < (MAX_PART_IP_ADDRESS * 4))
        {
            mmi_dtcnt_get_address(g_mmi_dtcnt_parser.comm_dtcnt_data->PrimaryAddr, data);
        }
        #endif
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_seconddns
 * DESCRIPTION
 *  Parser data account second DNS.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_seconddns(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_SECONDDNS, len);
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:
    case SRV_DTCNT_BEARER_CSD:
        #if defined (__MMI_GPRS_FEATURES__) || defined (__TCPIP_OVER_CSD__)        
        if (len < (MAX_PART_IP_ADDRESS * 4))
        {
            mmi_dtcnt_get_address(g_mmi_dtcnt_parser.comm_dtcnt_data->SecondaryAddr, data);
        }
        #endif
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_apn
 * DESCRIPTION
 *  Parser data account APN.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_apn(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *apn;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_APN, len);
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:
        #ifdef __MMI_GPRS_FEATURES__
        apn = g_mmi_dtcnt_parser.addr;
        if (len <= SRV_DTCNT_PROF_MAX_APN_LEN)
        {
            memcpy(apn, data, len);
            apn[len] = 0;
        }
        else
        {
            memcpy(apn, data, SRV_DTCNT_PROF_MAX_APN_LEN);
            apn[SRV_DTCNT_PROF_MAX_APN_LEN] = 0;
        }
        if(g_mmi_dtcnt_parser.save)
        {
            g_mmi_dtcnt_parser.comm_dtcnt_data->sim_info = (srv_dtcnt_sim_type_enum)g_mmi_dtcnt_parser.save; /* add sim_info here because apn needed */
        }
        #endif
        break;

    default:
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_authentication
 * DESCRIPTION
 *  Parser data account authentication.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_authentication(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_AUTH, len);
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:
        #ifdef __MMI_GPRS_FEATURES__
        g_mmi_dtcnt_parser.comm_dtcnt_data->Auth_info.AuthType = 
            (srv_dtcnt_prof_gprs_auth_type_enum)mmi_dtcnt_get_type(MMI_DTCNT_AUTH_TYPE, data);
        #endif
        break;
        
    default:
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_ipaddress
 * DESCRIPTION
 *  Parser data account phone ip address.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_ipaddress(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_IPADDRESS, len);
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:
    case SRV_DTCNT_BEARER_CSD:
        #if defined (__MMI_GPRS_FEATURES__) || defined (__TCPIP_OVER_CSD__)        
        if (len < (MAX_PART_IP_ADDRESS * 4))
        {
            mmi_dtcnt_get_address(g_mmi_dtcnt_parser.comm_dtcnt_data->StaicIPAddr, data);
        }
        #endif
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_subnet
 * DESCRIPTION
 *  Parser data account subnet.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_subnet(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_SUBNET, len);
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:
    case SRV_DTCNT_BEARER_CSD:
        #if defined (__MMI_GPRS_FEATURES__) || defined (__TCPIP_OVER_CSD__)
        if (len < (MAX_PART_IP_ADDRESS * 4))
        {
            mmi_dtcnt_get_address(g_mmi_dtcnt_parser.comm_dtcnt_data->NetMask, data);
        }
        #endif
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_conntype
 * DESCRIPTION
 *  Parser data account connection type.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_conntype(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_NODE_CONNTYPE, len);
    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:
    case SRV_DTCNT_BEARER_CSD:
        #if defined (__MMI_GPRS_FEATURES__) || defined (__TCPIP_OVER_CSD__)
        g_mmi_dtcnt_parser.comm_dtcnt_data->px_service = 
            (srv_dtcnt_prof_px_srv_enum)mmi_dtcnt_get_type(MMI_DTCNT_CONN_TYPE, data);
        #endif
        break;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dtcnt_node_readonly
 * DESCRIPTION
 *  Parser data account is readonly?.
 * PARAMETERS
 *  elem  [IN]      element name.
 *  attr  [IN]      attribute list.
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 * RETURNS
 *  Return KAL_TRUE on success, otherwise return error code.
 *****************************************************************************/
static kal_int32 dtcnt_node_readonly(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 read_only = 0;
    kal_int32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((attr[i] != NULL) && (attr[i+1] != NULL))
    {
        if (strcmp(attr[i], DTCNT_ATTR_ENABLE) == 0)
        {
            if (strcmp(attr[i+1], DTCNT_ATTR_VAL_YES) == 0)
            {
                read_only = 1;
            }
        }
        i += 2;
    }

    switch (g_mmi_dtcnt_parser.bearer)
    {
    case SRV_DTCNT_BEARER_GPRS:
    case SRV_DTCNT_BEARER_CSD:
        #if defined (__MMI_GPRS_FEATURES__) || defined (__TCPIP_OVER_CSD__)
        g_mmi_dtcnt_parser.comm_dtcnt_data->read_only = read_only;
        #endif
        break;
    }   
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_elem_start_hdlr
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  data  [IN]      data.
 *  el    [IN]      element.
 *  attr  [IN]      element attribute.
 *  error [IN]      error code.
 * RETURNS
 *  void.
 *****************************************************************************/
static void mmi_dtcnt_elem_start_hdlr(void *data, const kal_char *el, const kal_char **attr, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i=0, tab_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_ELEM_START_HDLR, error);
    tab_num = sizeof(mmi_dtcnt_node) / sizeof(mmi_dtcnt_node[0]);

    g_mmi_dtcnt_parser.stack++;

    for (i = 0; i < tab_num; i++)
    {
        if (mmi_dtcnt_node[i].type != DTCNT_TYPE_ATTR)
        {
            continue;
        }

        if (strcmp(el, mmi_dtcnt_node[i].name) != 0)
        {
            continue;
        }

        if (mmi_dtcnt_node[i].deep != g_mmi_dtcnt_parser.stack)
        {
            continue;
        }

        if (!g_mmi_dtcnt_parser.save && (mmi_dtcnt_node[i].call_back != dtcnt_node_sim))
        {
            return;
        }

        mmi_dtcnt_node[i].call_back(el, attr, NULL, 0);

        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_elem_end_hdlr
 * DESCRIPTION
 *  Process element end.
 * PARAMETERS
 *  data  [IN]      data.
 *  el    [IN]      element. 
 *  error [IN]      error code.
 * RETURNS
 *  void.
 *****************************************************************************/
static void mmi_dtcnt_elem_end_hdlr(void *data, const kal_char *el, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_ELEM_END_HDLR, error);
    if (g_mmi_dtcnt_parser.stack > 0)
    {
        g_mmi_dtcnt_parser.stack--;
    }

    if (!g_mmi_dtcnt_parser.save)
    {
        return;
    }

    if (strcmp(el, DTCNT_NODE_SIM) == 0)
    {
        g_mmi_dtcnt_parser.save = 0;        
    }
    else if (strcmp(el, DTCNT_NODE_ITEM) == 0)
    {
        mmi_dtcnt_account_item_end(
            g_mmi_dtcnt_parser.bearer, 
            g_mmi_dtcnt_parser.comm_dtcnt_data,
            g_mmi_dtcnt_parser.acct_name,
            g_mmi_dtcnt_parser.addr);

        if (g_mmi_dtcnt_parser.count == DTCNT_MAX_PARSE_ITEM)
        {
            xml_pause_parse(g_dtcnt_xml_parser);
            mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_DTCNT_RESUME_PARSE_IND, NULL, NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_data_hdlr
 * DESCRIPTION
 *  Process element data.
 * PARAMETERS
 *  resv  [IN]      xml data.
 *  el    [IN]      element name. 
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 *  error [IN]      error code.    
 * RETURNS
 *  void.
 *****************************************************************************/
static void mmi_dtcnt_data_hdlr(void *resv, const kal_char *el, const kal_char *data, kal_int32 len, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_int32 i, tab_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_DATA_HDLR, error);
    tab_num = sizeof(mmi_dtcnt_node) / sizeof(mmi_dtcnt_node[0]);

    if (error)
    {
        xml_stop_parse((XML_PARSER_STRUCT*)resv);
        return;
    }
    
    if (strcmp(DTCNT_VERS_NAME, el) != 0 && !g_mmi_dtcnt_parser.save)
    {
        return;
    }

    for (i = 0; i < tab_num; i++)
    {
        if (mmi_dtcnt_node[i].type != DTCNT_TYPE_DATA)
        {
            continue;
        }

        if (strcmp(el, mmi_dtcnt_node[i].name) != 0)
        {
            continue;
        }
        
        if (mmi_dtcnt_node[i].deep != g_mmi_dtcnt_parser.stack)
        {
            continue;
        }
        
        mmi_dtcnt_node[i].call_back(el, NULL, data, len);

        break;
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_xml_parse
 * DESCRIPTION
 *  Parser data account configuration file to pre-install account.
 * PARAMETERS
 *  kal_wchar *  [IN]        file_name.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_xml_parse(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_XML_PARSE);
    ret = xml_new_parser(g_dtcnt_xml_parser);
    
    if (ret < 0)
    {   
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_ACCOUNT_PARSE_END, ret);
        mmi_dtcnt_account_parse_end(ret);
        return;
    }
    SetProtocolEventHandler(mmi_dtcnt_resume_parse_hdlr, MSG_ID_MMI_DTCNT_RESUME_PARSE_IND);
    xml_register_element_handler(g_dtcnt_xml_parser, mmi_dtcnt_elem_start_hdlr, mmi_dtcnt_elem_end_hdlr);
    xml_register_data_handler(g_dtcnt_xml_parser, mmi_dtcnt_data_hdlr);
        
    ret = xml_parse(g_dtcnt_xml_parser, file_name);
    if (g_mmi_dtcnt_parser.count < DTCNT_MAX_PARSE_ITEM)
    {
        xml_close_parser(g_dtcnt_xml_parser);
        memset(&g_mmi_dtcnt_parser, 0, sizeof(g_mmi_dtcnt_parser));
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_ACCOUNT_PARSE_END, ret);
        mmi_dtcnt_account_parse_end(ret);
    }
    //return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_resume_parse_hdlr
 * DESCRIPTION
 *  Resume to parser data account configuration file to pre-install account.
 * PARAMETERS
 *  void *  [IN]        msg.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dtcnt_resume_parse_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_RESUME_PARSE_HDLR);
    g_mmi_dtcnt_parser.count = 0;
    ret = xml_resume_parse(g_dtcnt_xml_parser);
    if (g_mmi_dtcnt_parser.count < DTCNT_MAX_PARSE_ITEM)
    {
        xml_close_parser(g_dtcnt_xml_parser);
        memset(&g_mmi_dtcnt_parser, 0, sizeof(g_mmi_dtcnt_parser));
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DXML_ACCOUNT_PARSE_END, ret);
        mmi_dtcnt_account_parse_end(ret);
    }
}


void mmi_dtcnt_xml_parse_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 driver;
    kal_wchar test_name[128];
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
    kal_wsprintf(test_name, "%c:\\AccountConfigure.xml",driver);

    mmi_dtcnt_xml_parse(test_name);
}

#ifdef __MMI_AP_DCM_DTCNT__
#pragma arm section rodata , code
#endif

#endif /* #ifndef __MMI_DTCNT_XML_SLIM__ */
#endif /* __DA_SMART_SELECTION_SUPPORT__ */
#endif
