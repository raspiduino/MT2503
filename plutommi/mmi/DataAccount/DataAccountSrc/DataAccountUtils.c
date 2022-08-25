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
 * DataAccountUtils.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Utility functions for Data Account.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __TCPIP__
#include "MMI_features.h"
#include "UcmSrvGprot.h"
#include "MMIDataType.h"
#include "string.h"
#include "DtcntSrvIprot.h"
#include "DataAccountEnum.h"
#include "DataAccountStruct.h"
#include "Conversions.h"

/***************************************************************************** 
 * Global variable
 *****************************************************************************/
#ifdef __MMI_WLAN_FEATURES__
extern srv_dtcnt_prof_wlan_struct g_wlan_info_prof;
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_hash_value_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash_value
 *  length
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtcnt_util_hash_value_is_empty(U8* hash_value, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < length; i++)
    {
        if(hash_value[i])
        {
            return MMI_FALSE;
        } 
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_hash_value_is_equal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash_value
 *  length
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dtcnt_util_hash_value_is_equal(U8* hash_value1, U8* hash_value2, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < length; i++)
    {
        if(hash_value1[i] != hash_value2[i])
        {
            return MMI_FALSE;
        } 
    }
    return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_util_is_call_interrupt_allow
 * DESCRIPTION
 *  To determine if interrupt from call is allowed
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE if screen can be displayed; otherwise, FALSE.
 *****************************************************************************/
U8 mmi_dtcnt_util_is_call_interrupt_allow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM__
#ifdef __MMI_BACKGROUND_CALL__
		if (srv_ucm_is_background_call())
		{
			if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_DATA_CSD_ALL, NULL) > 0 ||
				srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
			{
				return FALSE;
			}
			else
			{
				return TRUE;
			}
		}
		else
#endif
        {
            if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) > 0)
            {
                return FALSE;
            }
            else
            {
                return TRUE;
			}
        }
#else /* __MMI_UCM__ */
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) <= 0)
        {
            return TRUE;
        }
        else if (((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0) && srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CSD_CALL_TYPE_ALL, NULL) > 0) &&
                 (GetTotalCallCount() <= 1) && srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) <= 0)
        {
            return TRUE;
        }
		return FALSE;
#endif /* __MMI_UCM__ */

}

#ifdef __MMI_WLAN_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_hex_to_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [?]         
 *  src         [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_wlan_hex_to_string(U8 *dest, U8 *src, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len % 2 != 0)
    {
        return FALSE;
    }

    memset(dest, 0, len / 2 + 1);

    for (i = 0, j = 0; i < len; i++)
    {
        j = (i - i % 2) / 2;
        if (src[i] >= '0' && src[i] <= '9')
        {
            dest[j] += (src[i] - '0') << 4 * ((i + 1) % 2);
        }
        else if (src[i] >= 'A' && src[i] <= 'F')
        {
            dest[j] += (src[i] - 'A' + 0x0A) << 4 * ((i + 1) % 2);
        }
        else if (src[i] >= 'a' && src[i] <= 'f')
        {
            dest[j] += (src[i] - 'a' + 0x0A) << 4 * ((i + 1) % 2);
        }
        else
        {
            return FALSE;
        }
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  is_valid_hexstring
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [?]         
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL is_valid_hexstring(U8 *src, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i++)
    {
        if (src[i] >= '0' && src[i] <= '9')
        {
            continue;
        }
        else if (src[i] >= 'A' && src[i] <= 'F')
        {
            continue;
        }
        else if (src[i] >= 'a' && src[i] <= 'f')
        {
            continue;
        }
        else
        {
            return FALSE;
        }
    }
    return TRUE;
}

BOOL is_valid_ascii_string(U8 *src, U8 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 hexValue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(length)
    {
        hexValue = (U16)(*((kal_uint8 *)src));
        if(hexValue < 0x7f && hexValue > 0x1f)
        {
            length--;
            src++;
        }
        else
        {
            return FALSE;
        }
    }

    return TRUE;
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
#endif

void mmi_wlan_convert_ucs_to_utf8(const char* pInBuffer, char* pOutBuffer, const kal_int32 length)
{
    mmi_chset_convert(
        MMI_CHSET_UCS2,
        MMI_CHSET_UTF8,
        (char *)pInBuffer,
        (char *)pOutBuffer,
        length);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_srv2app_profile_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_prof      [IN]   wlan service profile   
 *  app_prof      [IN]   wlan app profile   
 *  to_app        [IN]   if it is converted to app profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_srv2app_profile_convert(srv_dtcnt_prof_wlan_struct *srv_prof, mmi_wlan_profile_struct *app_prof, U32 to_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (to_app)
    {
        app_prof->ssid_len = srv_prof->ssid_len;
        strncpy((CHAR*)app_prof->ssid, (CHAR*)srv_prof->ssid, SRV_DTCNT_PROF_MAX_SSID_LEN + 1);
        mmi_ucs2cpy((CHAR*)app_prof->name, (CHAR*)srv_prof->ProfName);
        app_prof->priority = srv_prof->priority;
        app_prof->profile_id = srv_prof->profile_id;
        app_prof->channel = srv_prof->channel;
        
        app_prof->network_type = srv_prof->network_type;
        app_prof->auth_mode = srv_prof->auth_mode;
        app_prof->encrypt_mode = srv_prof->encrypt_mode;
        
#ifdef __CERTMAN_SUPPORT__
        app_prof->root_ca_id = srv_prof->root_ca_id;
        app_prof->client_ca_id = srv_prof->client_ca_id;
#else
        // mmi_asc_n_to_ucs2((CHAR*)app_prof->root_ca_path, (CHAR*)srv_prof->root_ca_path, (SRV_FMGR_PATH_MAX_LEN+1));
        // mmi_asc_n_to_ucs2((CHAR*)app_prof->client_ca_path, (CHAR*)srv_prof->client_ca_path, (SRV_FMGR_PATH_MAX_LEN+1));
        // mmi_asc_n_to_ucs2((CHAR*)app_prof->private_key_path, (CHAR*)srv_prof->private_key_path, (SRV_FMGR_PATH_MAX_LEN+1));
#endif

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        app_prof->wapi_ase_id = srv_prof->wapi_ase_id;
        app_prof->wapi_client_id = srv_prof->wapi_client_id;
        app_prof->wapi_psk_format = srv_prof->wapi_psk_format;
        strncpy((CHAR*)app_prof->wapi_psk_str, (CHAR*)srv_prof->wapi_psk_str, MAX_WAPI_PSK_LEN);
        strncpy((CHAR*)app_prof->wapi_private_key_passwd_str, (CHAR*)srv_prof->wapi_private_key_passwd_str, MAX_PASSWORD_LEN);
#endif /* __MMI_HIDE_WAPI__ */
#endif

        strncpy((CHAR*)app_prof->passphrase, (CHAR*)srv_prof->passphrase, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN);
        memcpy((CHAR*)app_prof->psk, (CHAR*)srv_prof->psk, SRV_DTCNT_PROF_MAX_PSK_LEN);
        app_prof->peap_version = srv_prof->peap_version;
        strncpy((CHAR*)app_prof->username, (CHAR*)srv_prof->username, MAX_USERNAME_LEN - 1);
        strncpy((CHAR*)app_prof->password, (CHAR*)srv_prof->password, MAX_PASSWORD_LEN - 1);
        strncpy((CHAR*)app_prof->private_key_passwd, (CHAR*)srv_prof->private_key_passwd, MAX_PASSWORD_LEN - 1);
        
	app_prof->ap_type = srv_prof->ap_type;
        app_prof->wep_key_index = srv_prof->wep_key_index;
        app_prof->wep_key_len = srv_prof->wep_key_len;
        app_prof->wep_key_format = srv_prof->wep_key_format;
        strncpy((CHAR*)app_prof->wep_key, (CHAR*)srv_prof->wep_key, MAX_WEP_KEYSTR_LEN - 1);

        app_prof->auth_type1 = srv_prof->eap_auth_type;
        app_prof->eap_peap_auth_type = srv_prof->eap_peap_auth_type;
        app_prof->eap_ttls_auth_type = srv_prof->eap_ttls_auth_type;

        memcpy((CHAR*)app_prof->ip_addr, (CHAR*)srv_prof->ip_addr, MAX_IPADDRES_LEN);
        memcpy((CHAR*)app_prof->netmask, (CHAR*)srv_prof->netmask, MAX_IPADDRES_LEN);
        memcpy((CHAR*)app_prof->gateway, (CHAR*)srv_prof->gateway, MAX_IPADDRES_LEN);
        memcpy((CHAR*)app_prof->dns1, (CHAR*)srv_prof->dns1, MAX_IPADDRES_LEN);
        memcpy((CHAR*)app_prof->dns2, (CHAR*)srv_prof->dns2, MAX_IPADDRES_LEN);
        app_prof->use_dhcp = srv_prof->use_dhcp;
        app_prof->always_ask_connect_flag = srv_prof->always_ask_connect_flag;
        app_prof->always_ask_before_connect_flag = srv_prof->always_ask_before_connect_flag;

        g_wlan_info_prof.use_proxy = srv_prof->use_proxy;
        g_wlan_info_prof.px_port = srv_prof->px_port;
        strcpy((char*)g_wlan_info_prof.HomePage, (char*)srv_prof->HomePage);
        strcpy((char*)g_wlan_info_prof.px_authid, (char*)srv_prof->px_authid);
        strcpy((char*)g_wlan_info_prof.px_authpw, (char*)srv_prof->px_authpw);
        memcpy(g_wlan_info_prof.px_addr, srv_prof->px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN);
    }
    else
    {
        srv_prof->ssid_len = app_prof->ssid_len;
        strncpy((char*)srv_prof->ssid, (char*)app_prof->ssid, SRV_DTCNT_PROF_MAX_SSID_LEN);
        mmi_ucs2cpy((char*)srv_prof->ProfName, (char*)app_prof->name);
        srv_prof->priority = app_prof->priority;
        srv_prof->profile_id = app_prof->profile_id;
        srv_prof->channel = app_prof->channel;
        
        srv_prof->network_type = (srv_dtcnt_wlan_network_type_enum)app_prof->network_type;
        srv_prof->auth_mode = (srv_dtcnt_wlan_auth_mode_enum)app_prof->auth_mode;
        srv_prof->encrypt_mode = (srv_dtcnt_wlan_encrypt_mode_enum)app_prof->encrypt_mode;
        
#ifdef __CERTMAN_SUPPORT__
        srv_prof->root_ca_id = app_prof->root_ca_id;
        srv_prof->client_ca_id = app_prof->client_ca_id;
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SRV2APP_PROFILE_CONVERT_CA, srv_prof->root_ca_id);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SRV2APP_PROFILE_CONVERT_USER, srv_prof->client_ca_id);
#else
        // retn = mmi_ucs2_n_to_asc((PS8)srv_prof->root_ca_path, (PS8)app_prof->root_ca_path, (SRV_FMGR_PATH_MAX_LEN+1));
        // srv_prof->root_ca_path[retn] = 0;
        // retn = mmi_ucs2_n_to_asc((PS8)srv_prof->client_ca_path, (PS8)app_prof->client_ca_path, (SRV_FMGR_PATH_MAX_LEN+1));
        // srv_prof->client_ca_path[retn] = 0;
        // retn = mmi_ucs2_n_to_asc((PS8)srv_prof->private_key_path, (PS8)app_prof->private_key_path, (SRV_FMGR_PATH_MAX_LEN+1));
        // srv_prof->private_key_path[retn] = 0;
#endif

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        srv_prof->wapi_ase_id = app_prof->wapi_ase_id;
        srv_prof->wapi_client_id = app_prof->wapi_client_id;
        srv_prof->wapi_psk_format = app_prof->wapi_psk_format;
        strncpy((CHAR*)srv_prof->wapi_psk_str, (CHAR*)app_prof->wapi_psk_str, SRV_DTCNT_WAPI_PSK_STR_LEN);
        strncpy((CHAR*)srv_prof->wapi_private_key_passwd_str, (CHAR*)app_prof->wapi_private_key_passwd_str, SRV_DTCNT_PROF_MAX_PW_LEN);
#endif /* __MMI_HIDE_WAPI__ */
#endif
        memcpy (srv_prof->psk, app_prof->psk, SRV_DTCNT_PROF_MAX_PSK_LEN);
        memcpy (srv_prof->passphrase, app_prof->passphrase, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);
        memcpy (srv_prof->username, app_prof->username, SRV_DTCNT_PROF_MAX_USER_LEN + 1);
        memcpy (srv_prof->password, app_prof->password, SRV_DTCNT_PROF_MAX_PW_LEN + 1);
        memcpy (srv_prof->private_key_passwd, app_prof->private_key_passwd, SRV_DTCNT_PROF_MAX_PW_LEN + 1);
        
	srv_prof->ap_type = app_prof->ap_type;
        srv_prof->wep_key_index = app_prof->wep_key_index;
        srv_prof->wep_key_len = app_prof->wep_key_len;
        srv_prof->wep_key_format = (srv_dtcnt_wlan_wep_key_format_enum)app_prof->wep_key_format;
        memcpy (srv_prof->wep_key, app_prof->wep_key, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1);
        
        srv_prof->eap_auth_type = app_prof->auth_type1;
        srv_prof->eap_peap_auth_type = app_prof->eap_peap_auth_type;
        srv_prof->eap_ttls_auth_type = app_prof->eap_ttls_auth_type;
        srv_prof->peap_version = app_prof->peap_version;
        
        memcpy((CHAR*)srv_prof->ip_addr, (CHAR*)app_prof->ip_addr, MAX_IPADDRES_LEN);
        memcpy((CHAR*)srv_prof->netmask, (CHAR*)app_prof->netmask, MAX_IPADDRES_LEN);
        memcpy((CHAR*)srv_prof->gateway, (CHAR*)app_prof->gateway, MAX_IPADDRES_LEN);
        memcpy((CHAR*)srv_prof->dns1, (CHAR*)app_prof->dns1, MAX_IPADDRES_LEN);
        memcpy((CHAR*)srv_prof->dns2, (CHAR*)app_prof->dns2, MAX_IPADDRES_LEN);
        
        if(app_prof->use_dhcp)
        {
            srv_prof->use_dhcp = MMI_TRUE;
        }
        else
        {
            srv_prof->use_dhcp = MMI_FALSE;
        }
        srv_prof->always_ask_connect_flag = app_prof->always_ask_connect_flag;
        srv_prof->always_ask_before_connect_flag = app_prof->always_ask_before_connect_flag;

        srv_prof->use_proxy = g_wlan_info_prof.use_proxy;
        srv_prof->px_port = g_wlan_info_prof.px_port;
        strcpy((char*)srv_prof->HomePage, (char*)g_wlan_info_prof.HomePage);
        strcpy((char*)srv_prof->px_authid, (char*)g_wlan_info_prof.px_authid);
        strcpy((char*)srv_prof->px_authpw, (char*)g_wlan_info_prof.px_authpw);
        memcpy(srv_prof->px_addr, g_wlan_info_prof.px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN);
    }
}
#endif /* __MMI_WLAN_FEATURES__ */ 
#endif
