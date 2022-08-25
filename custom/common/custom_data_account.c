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
 *
 * Filename:
 * ---------
 * customer_data_account.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the Data Account context / functions.
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


#include "custom_data_account.h"
#include "cbm_consts.h"


#ifdef __DCD_SUPPORT__
#include "custom_dcd.h"
#endif


#ifdef __TCPIP__

#ifdef __APP_STATIC_QOS_PROFILE_SUPPORT__
nvram_ef_abm_ps_qos_profile_struct abm_ps_qos_profile[CUSTOM_QOS_PROFILE_ID_TOTAL];
#endif

#ifdef __MTK_TARGET__

#include "in_pcb.h"

#define TCPIP_MAX_PROFILE_NUMBER		CBM_ALL_NWK_ACCT_ID//64
struct ifnet    global_ifp[TCPIP_MAX_PROFILE_NUMBER];

#endif /* __MTK_TARGET__ */
#endif /*__TCPIP__*/

#include "string.h"
#include "kal_general_types.h"

const char* dtcnt_apptype_table[] = 
{
    "NONE",                   /* DTCNT_APPTYPE_NONE */
    "DEFAULT",                /* DTCNT_APPTYPE_DEFAULT */
    "WAP",                    /* DTCNT_APPTYPE_BRW_WAP */
    "HTTP",                   /* DTCNT_APPTYPE_BRW_HTTP */
    "MMS",                    /* DTCNT_APPTYPE_MMS */
    "EMAIL",                  /* DTCNT_APPTYPE_EMAIL */
    "IMPS",                   /* DTCNT_APPTYPE_IMPS */
    "DM",                     /* DTCNT_APPTYPE_DM */
    "SYNCML",                 /* DTCNT_APPTYPE_SYNCML */
    "JAVA",                   /* DTCNT_APPTYPE_JAVA */
    "STREAMING",              /* DTCNT_APPTYPE_PLAYER */
    "MRE WAP",                /* DTCNT_APPTYPE_MRE_WAP */
    "MRE NET",                /* DTCNT_APPTYPE_MRE_NET */
    "TETHERING",              /* DTCNT_APPTYPE_TETHERING */
    "WIFI TETHERING",         /* DTCNT_APPTYPE_WIFI_TETHERING */
    "USB TETHERING",          /* DTCNT_APPTYPE_USB_TETHERING */
    "NTP",                    /* DTCNT_APPTYPE_NTP */           
    "GPS",                    /* DTCNT_APPTYPE_GPS */
    "WIDGET",                 /* DTCNT_APPTYPE_WIDGET */
};


/*****************************************************************************
* FUNCTION
*  mmi_custom_account_get_apptype
* DESCRIPTION
*   This function is used to get app type
* 
* PARAMETERS
*
* RETURNS
*  void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
int mmi_custom_account_get_apptype(const char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, size = sizeof(dtcnt_apptype_table) / sizeof(dtcnt_apptype_table[0]);
    int app_type = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (name == NULL)
    {
        return DTCNT_APPTYPE_NONE;
    }
    
    for (i = 0; i < size; i++)
    {
        if (strstr(name, dtcnt_apptype_table[i]))
        {
            if (i == 0)
            {
                app_type += 0;
            }
            else
            {
                app_type += (1 << ( i - 1));
            }
        }
    }
    
    return app_type;
}


/*****************************************************************************
* FUNCTION
*  custom_get_dcd_default_apn_and_name
* DESCRIPTION
*   This function is used to get the default DCD APN and name
* 
* PARAMETERS
*
* RETURNS
*  void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void custom_get_dcd_default_apn_and_name(kal_uint8 *apn, kal_uint32 max_apn_len, 
                                         kal_uint8 *name, kal_uint32 max_name_len, 
                                         kal_uint32 *apn_len, kal_uint32 *name_len)
{
#ifdef __DCD_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 tmp_apn_len, tmp_name_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (apn)
    {    
        kal_int8  *dcd_apn = (kal_int8  *)dcd_custom_get_apn();
        tmp_apn_len = strlen((char*)dcd_apn); /* DCD_DEFAULT_APN */
        if (tmp_apn_len > max_apn_len)
        {
            tmp_apn_len = max_apn_len;
        }
        
        strncpy((char*)apn, (char*)dcd_apn, tmp_apn_len); /* DCD_DEFAULT_APN */
        apn[tmp_apn_len] = '\0';
        
        if (apn_len)
        {
            *apn_len = tmp_apn_len;
        }
    }

    if (name)
    {
        kal_int8  *apn_name = (kal_int8  *)dcd_custom_get_apn_name();
        tmp_name_len = strlen((char*)apn_name); /* DCD_DEFAULT_NAME */
        if (tmp_name_len > max_name_len)
        {
            tmp_name_len = max_name_len;
        }
        strncpy((char*)name, (char*)apn_name, tmp_name_len); /* DCD_DEFAULT_NAME */
        name[tmp_name_len] = '\0';
        if (name_len)
        {
            *name_len = tmp_name_len;
        }
    }

    return;
#else /* __DCD_SUPPORT__ */
    return;
#endif /* !__DCD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  custom_get_ext_modem_profile_num
 * DESCRIPTION
 *  This function is used to get the G+C profile number.
 *  This is a special CSD account id used to activate the another SIM card's bearer. 
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 custom_get_ext_modem_profile_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CBM_EXT_MODEM_ACCT_ID;
}


/*****************************************************************************
 * FUNCTION
 *  custom_get_ext_modem_profile_id
 * DESCRIPTION
 *  This function is used to get the G+C (external modern) profile id.
 *  special account id for G+C project. send packet through another company's card.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 custom_get_ext_modem_profile_id(void)
{
#ifdef __EXT_MODEM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __EXT_MODEM__ */
    return 0;
#endif /* !__EXT_MODEM__ */
}


/*****************************************************************************
 * FUNCTION
 *  custom_get_loopback_profile_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 custom_get_loopback_profile_id(void)
{
#ifdef __TCPIP_LOOP_BACK__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CBM_LOOPBACK_ACCT_ID;
#else /* __TCPIP_LOOP_BACK__ */
    return 0;
#endif /* !__TCPIP_LOOP_BACK__ */
}

/*****************************************************************************
* FUNCTION
*  custom_get_ps_qos_profile_num 
* DESCRIPTION
*   This function is used to get the PS QoS profile number.
* 
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint8 custom_get_ps_qos_profile_num(void)
{
   return CUSTOM_QOS_PROFILE_ID_TOTAL;
}

kal_uint32 custom_get_keepalive_switch()
{
	//return always_keepalive

	return 0;
}

kal_uint32 custom_get_keepalive_idle_value()
{
	//return TCPTV_KEEP_IDLE

	return 2*60*KAL_TICKS_1_MIN;
}

kal_uint32 custom_get_keepalive_interval_value()
{
	//return TCPTV_KEEPINTVL
	return KAL_TICKS_1_MIN + 3*KAL_TICKS_5_SEC;
}


