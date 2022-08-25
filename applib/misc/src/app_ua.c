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
 * app_ua.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains user agent functions.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#if defined(PLUTO_MMI)
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
//#include "op_nvram_common_config.h"
#include "MMI_include.h"
#include "kal_release.h"
#include "mmi_features.h"
#include "app_ua.h"
#include "EngineerModeInetAppGprot.h"
#include "common_nvram_editor_data_item.h"
#include "j2me_custom.h"
#ifdef __MMI_ENGINEER_MODE__
#include "mmi_rp_app_engineermode1_def.h"
#endif
#include "mmi_frm_mem_gprot.h"

extern char* release_verno();
extern char* release_hw_ver();
extern char* build_date_time();



#if defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_INET_APP_SLIM__)
static void applib_inet_read_custpack(nvram_em_inet_custpack_struct* c_p);
static void applib_inet_notify_app(applib_inet_option_enum opt, const char *str_val, kal_uint32 int_val);


static applib_inet_cntx_struct g_applib_inet_cntx;
static applib_inet_cntx_struct *const g_applib_inet_cntx_p = &g_applib_inet_cntx;

/* user agent name list */
const static char * const g_applib_inet_user_agent_list[] = APPLIB_INET_USER_AGENT_LIST;

/* user agent data */
const static applib_inet_user_agent_struct g_applib_inet_user_agent_table[] = APPLIB_INET_USER_AGENT_DATA;

const static applib_inet_event_handler_struct g_applib_inet_event_hdlr_tbl[] = {
        #ifdef OBIGO_Q05A_MMS
        {APPLIB_INET_MMS_VERSION_OPT, mms_em_change_setting},
        #endif
        #ifdef __MMI_BROWSER_2__
        {APPLIB_INET_UA_STRING_OPT, bam_registry_em_setting_changed_callback},
        {APPLIB_INET_UA_PROFILE_OPT, bam_registry_em_setting_changed_callback},
        {APPLIB_INET_ACCEPT_HEADER_OPT, bam_registry_em_setting_changed_callback},
        #endif
        #ifdef OBIGO_Q03C_MMS_V01
        {APPLIB_INET_MMS_VERSION_OPT, mms_em_change_setting},
        {APPLIB_INET_UA_STRING_OPT, mms_em_change_setting},
        #endif
        #ifdef OBIGO_Q03C_MMS_V02
        {APPLIB_INET_MMS_VERSION_OPT, mms_em_change_setting},
        {APPLIB_INET_UA_STRING_OPT, mms_em_change_setting},
        #endif

        /* add new item above this line */     
        {APPLIB_INET_OPT_TOTAL, NULL}};

 
/***************************************************************************** 
 * Global Function
 *****************************************************************************/



U32 applib_inet_get_active_user_agent_index()
{
    applib_inet_cntx_struct *cntx_p = g_applib_inet_cntx_p;
    return cntx_p->active_user_agent_index;
}


const char* applib_inet_get_user_agent_from_list(U32 index)
{
    return g_applib_inet_user_agent_list[index];
}


/*****************************************************************************
 * FUNCTION
 *  applib_inet_activate_ua
 * DESCRIPTION
 *  This function is called to activate user agent
 * PARAMETERS
 *  [IN] active_ua_idx
 * RETURNS
 *  void
 *****************************************************************************/
void applib_inet_activate_ua(U32 active_ua_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;    
    nvram_em_inet_custpack_struct *custpack_p = NULL;
    applib_inet_cntx_struct *cntx_p = g_applib_inet_cntx_p;
    applib_inet_user_agent_struct *active_user_agent_p = &cntx_p->active_user_agent;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    /* if original active user agent is from custpack, we need to free its memory. */
    if(cntx_p->active_user_agent_index == 0)
    {
        if(active_user_agent_p->string != NULL)
        {
            OslMfree(active_user_agent_p->string);
        }
        if(active_user_agent_p->profile != NULL)
        {
            OslMfree(active_user_agent_p->profile);
        }                       
    }

    /* update active user agent index and write value to nvram */
    cntx_p->active_user_agent_index = active_ua_idx;   
    WriteValue(NVRAM_EM_INET_ACTIVE_USER_AGENT, &active_ua_idx, DS_BYTE, &error);

    /* read new active user agent from nvram if necessary */
    if(active_ua_idx == 0)
    {
        /* allocate memory for reading user agent NVRAM */
        custpack_p = (nvram_em_inet_custpack_struct*) OslMalloc(sizeof(nvram_em_inet_custpack_struct));
        /* read user agent from NVRAM */
        applib_inet_read_custpack(custpack_p);

        /* allocate memory for storing the active user agent, will be freed when other user agent is activated. */
        active_user_agent_p->string = (char *) OslMalloc(sizeof(char) * (APPLIB_INET_MAX_UA_STRING_LEN + 1));   /* 1 for null terminator */
        active_user_agent_p->profile = (char *) OslMalloc(sizeof(char) * (APPLIB_INET_MAX_UA_PROFILE_LEN + 1)); /* 1 for null terminator */

        /* copy user agent to g_applib_inet_cntx_p->active_user_agent */
        strcpy((char *)active_user_agent_p->string, (const char *)custpack_p->user_agent_string);
        strcpy((char *)active_user_agent_p->profile, (const char *)custpack_p->user_agent_profile);

        /* free memory */
        OslMfree(custpack_p);        
    }
    /* if the activated setting is not from NVRAM, we simply update the pointer. */
    else
    {
        /* notice that the index needs to minus one for g_applib_inet_user_agent_table does not include custpack setting */
        active_user_agent_p->string = g_applib_inet_user_agent_table[active_ua_idx - 1].string;
        active_user_agent_p->profile = g_applib_inet_user_agent_table[active_ua_idx - 1].profile;        
    }
        
    /* set new setting value and notify applications */
    applib_inet_notify_app(APPLIB_INET_UA_STRING_OPT, (const char*)active_user_agent_p->string, 0);    
    applib_inet_notify_app(APPLIB_INET_UA_PROFILE_OPT, (const char*)active_user_agent_p->profile, 0);        
  
}


/*****************************************************************************
 * FUNCTION
 *  applib_inet_activate_accept_header
 * DESCRIPTION
 *  This function is called to activate accept header
 * PARAMETERS
 *  index: [IN]
 * RETURNS
 *  void
 *****************************************************************************/
 void applib_inet_activate_accept_header(applib_inet_accept_header_enum index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     S16 error;    
     applib_inet_cntx_struct *cntx_p = g_applib_inet_cntx_p;
     

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    /* update active accept header if neccessary */
    if(cntx_p->active_accept_header != index)
    {
        /* update active accept header index */
        cntx_p->active_accept_header = index;

        /* write new setting into NVRAM */
        WriteValue(NVRAM_EM_INET_ACTIVE_ACCEPT_HEADER, &cntx_p->active_accept_header, DS_BYTE, &error);

        /* notify application of new setting */          
        applib_inet_notify_app(APPLIB_INET_ACCEPT_HEADER_OPT, NULL, cntx_p->active_accept_header);
    }           

}

/*****************************************************************************
 * FUNCTION
 *  applib_inet_activate_mms_version
 * DESCRIPTION
 *  This function is used to activate mms version
 * PARAMETERS
 *  index: [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void applib_inet_activate_mms_version(applib_inet_mms_version_enum index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     S16 error;    
     applib_inet_cntx_struct *cntx_p = g_applib_inet_cntx_p;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    /* update active mms version if neccessary */
    if(cntx_p->active_mms_version != index)
    {
        /* update active MMS version index */
        cntx_p->active_mms_version = index;

        /* write new setting into NVRAM */        
        WriteValue(NVRAM_EM_INET_ACTIVE_MMS_VERSION, &cntx_p->active_mms_version, DS_BYTE, &error);

        /* notify application of new setting */
        applib_inet_notify_app(APPLIB_INET_MMS_VERSION_OPT, NULL, cntx_p->active_mms_version);
    }           

}
/*****************************************************************************
 * FUNCTION
 *  applib_inet_ua_edit_save_changes
 * DESCRIPTION
 *  This function is called when user wants to save change after editing ua
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void applib_inet_set_ua_edited(WCHAR* string,WCHAR* profile)
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_em_inet_custpack_struct *new_custpack_p = NULL;
    applib_inet_cntx_struct *cntx_p = g_applib_inet_cntx_p;
    applib_inet_user_agent_struct *active_user_agent_p = &cntx_p->active_user_agent;
    S16 error;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allocate memory for new user agent */
    new_custpack_p = (nvram_em_inet_custpack_struct*) OslMalloc(sizeof(nvram_em_inet_custpack_struct));

    /* transform edit_user_agent_p from UCS2 to ASC */
    mmi_wcs_to_asc((CHAR*)new_custpack_p->user_agent_string, (WCHAR*)string);
    mmi_wcs_to_asc((CHAR*)new_custpack_p->user_agent_profile, (WCHAR*)profile);

    /* write edit data to nvram */
    WriteRecord(NVRAM_EF_INET_CUSTPACK_LID, 1, new_custpack_p, sizeof(nvram_em_inet_custpack_struct), &error);

    /* if the edit item is the active one */    
    if(cntx_p->active_user_agent_index == 0)
    {        
        /* if ua string has been modified */
        if(strcmp((S8*)new_custpack_p->user_agent_string, (S8*)active_user_agent_p->string) != 0)
        {
            strcpy((S8*)active_user_agent_p->string, (S8*)new_custpack_p->user_agent_string);
            applib_inet_notify_app(APPLIB_INET_UA_STRING_OPT, (const char*)active_user_agent_p->string, 0);
        }
        /* if ua profile has been modified */
        if(strcmp((S8*)new_custpack_p->user_agent_profile, (S8*)active_user_agent_p->profile) != 0)
        {
            strcpy((S8*)active_user_agent_p->profile, (S8*)new_custpack_p->user_agent_profile);
            applib_inet_notify_app(APPLIB_INET_UA_PROFILE_OPT, (const char*)active_user_agent_p->profile, 0);        
         }
    }

    /* free memory */
    OslMfree(new_custpack_p);

}


/*****************************************************************************
 * FUNCTION
 *  applib_inet_init
 * DESCRIPTION
 *  This is the hilight handler for MENU_ID_EM_MISC_INET_MAIN
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void applib_inet_init()
{


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    applib_inet_cntx_struct *cntx_p = g_applib_inet_cntx_p;
    applib_inet_user_agent_struct *active_user_agent_p = &g_applib_inet_cntx_p->active_user_agent;
    nvram_em_inet_custpack_struct *custpack_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read default value from MMI Cache */
    ReadValue(NVRAM_EM_INET_ACTIVE_USER_AGENT, &cntx_p->active_user_agent_index, DS_BYTE, &error);  
    if(cntx_p->active_user_agent_index >= APPLIB_INET_USER_AGENT_TOTAL)
    {
        cntx_p->active_user_agent_index = APPLIB_INET_DEFAULT_USER_AGENT_INDEX;
    }

    ReadValue(NVRAM_EM_INET_ACTIVE_ACCEPT_HEADER, &cntx_p->active_accept_header, DS_BYTE, &error);
    if(cntx_p->active_accept_header >= APPLIB_INET_ACCEPT_HEADER_TOTAL)
    {
        cntx_p->active_accept_header = APPLIB_INET_DEFAULT_ACCEPT_HEADER_INDEX;
    }

    ReadValue(NVRAM_EM_INET_ACTIVE_MMS_VERSION, &cntx_p->active_mms_version, DS_BYTE, &error);
    if(cntx_p->active_mms_version >= APPLIB_INET_MMS_VERSION_TOTAL)
    {
        cntx_p->active_mms_version = APPLIB_INET_DEFAULT_MMS_VERSION_INDEX;
    }
    
    if(cntx_p->active_user_agent_index == 0)
    {
        /* if default setting is from custpack, we need read it from NVRAM.*/
        /* allocate memory for reading custpack data from NVRAM, will be freed soon */
        custpack_p = (nvram_em_inet_custpack_struct *)OslMalloc(sizeof(nvram_em_inet_custpack_struct));

        /*read custpack setting from NVRAM */
        applib_inet_read_custpack(custpack_p);

        /* allocate memory for active user agent, will be freed when other user agent setting is activated */
        active_user_agent_p->string = (char *)OslMalloc(sizeof(char) * (APPLIB_INET_MAX_UA_STRING_LEN + 1));   /* 1 for null terminator */
        active_user_agent_p->profile = (char *)OslMalloc(sizeof(char) * (APPLIB_INET_MAX_UA_PROFILE_LEN + 1)); /* 1 for null terminator */               

        /* copy the data */
        strcpy((char *)active_user_agent_p->string,(const char *)custpack_p->user_agent_string);
        strcpy((char *)active_user_agent_p->profile,(const char *)custpack_p->user_agent_profile);

        /* free custpack_p */
        OslMfree(custpack_p);
    }
    else
    {
        /* if default setting is not from custpack, we simply set pointer */
        active_user_agent_p->string = g_applib_inet_user_agent_table[cntx_p->active_user_agent_index - 1].string;
        active_user_agent_p->profile = g_applib_inet_user_agent_table[cntx_p->active_user_agent_index - 1].profile;
    }

}

/*****************************************************************************
 * FUNCTION
 *  APPLIB_inet_notify_app
 * DESCRIPTION
 *  This function is to notify application of new setting
 * PARAMETERS
 *  opt     [IN]  specify the type of setting
 *  str_val [IN]  string value
 *  int_val [IN]  integer value
 * RETURNS
 *  void
 *****************************************************************************/
static void applib_inet_notify_app(applib_inet_option_enum opt, const char *str_val, kal_uint32 int_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const applib_inet_event_handler_struct *event_hdlr_tbl_p = g_applib_inet_event_hdlr_tbl;
    U32 event_hdlr_num = sizeof(g_applib_inet_event_hdlr_tbl) / sizeof(applib_inet_event_handler_struct) - 1; /* excluding the last one */
    U32 i = 0;
    applib_inet_setting_struct val;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    /* assign value */
    val.value_str = str_val;
    val.value_int = int_val;

    /* call related event handler to notify application */
    for(i = 0; i < event_hdlr_num; i++)
    {
        if(event_hdlr_tbl_p[i].opt == opt)
        {
            event_hdlr_tbl_p[i].event_hdlr(opt, &val);
        }
    }
 
}


/*****************************************************************************
 * FUNCTION
 *  applib_inet_read_custpack
 * DESCRIPTION
 *  This function is used to read user agent from nvram
 * PARAMETERS
 *  c_p     [IN/OUT] used to read NVRAM 
 * RETURNS
 *  void
 *****************************************************************************/
static void applib_inet_read_custpack(nvram_em_inet_custpack_struct* c_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read custpack setting from NVRAM */
    ReadRecord(NVRAM_EF_INET_CUSTPACK_LID, 1, c_p, sizeof(nvram_em_inet_custpack_struct), &error);
    MMI_ASSERT(error == NVRAM_READ_SUCCESS);

}
#endif //#if defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_INET_APP_SLIM__)


applib_inet_accept_header_enum applib_inet_get_active_accept_header()
{
	 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_INET_APP_SLIM__)
    return g_applib_inet_cntx_p->active_accept_header;
#else
    return (applib_inet_accept_header_enum)APPLIB_INET_DEFAULT_ACCEPT_HEADER_INDEX;
#endif
}

applib_inet_mms_version_enum applib_inet_get_active_mms_version()
{
#if defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_INET_APP_SLIM__)
	applib_inet_cntx_struct *cntx_p = g_applib_inet_cntx_p; 
    return cntx_p->active_mms_version;
#endif
	return APPLIB_INET_MMS_VERSION_11;
}

/*****************************************************************************
 * FUNCTION
 *  applib_inet_get_user_agent_string
 * DESCRIPTION
 *  This function is called to get active user agent string 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
const char* applib_inet_get_user_agent_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_EM_INET_APP_SLIM__) || !defined(__MMI_ENGINEER_MODE__)
    return APPLIB_DEFAULT_UA_STRING;
#else
 return (const char*)g_applib_inet_cntx_p->active_user_agent.string;
#endif
}

#ifdef __MMI_BROWSER_2__
extern char* srv_brw_get_verno(void);
void applib_get_dynamic_ua(char *uaString)
{
#if defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_INET_APP_SLIM__)
	if ( g_applib_inet_cntx_p->active_user_agent_index==0)
    {
		//char uaString[applib_INET_MAX_UA_STRING_LEN+1];
		char uaDate[11];
		char *p_uaDate;
		int i=0;
		memset((void *)uaDate,0x00,11);
		memset((void *)uaString,0x00,APPLIB_INET_MAX_UA_STRING_LEN+1);
		strcat((void *)uaString,release_hw_ver());
		strcat((void *)uaString," ");
		strcat((void *)uaString,release_verno());
		strcat((void *)uaString," ");
		strcat((void *)uaString,"Release/");
		strncat((void *)uaDate,build_date_time(),10);
		p_uaDate=uaDate;
		for(i=0;i<strlen(uaDate);i++)
		{
		if(*p_uaDate=='/')
		{
			uaDate[i]='.';
			
		}
		p_uaDate++;
		}

		strncat((void *)uaString,uaDate,10);
		strcat((void *)uaString," ");
		strcat((void *)uaString,"WAP Browser/MAUI ");
#ifdef __J2ME__
		strcat((void *)uaString,"Profile/");

		strcat((void *)uaString,j2me_get_midp_version());

		strcat((void *)uaString," ");
#endif
#ifdef __J2ME__
		strcat((void *)uaString,j2me_get_cldc_version() );

		strcat((void *)uaString," ");
#endif
	//	strcat((void *)uaString,"Browser/Obigo");
	//	strncat((void *)uaString,srv_brw_get_verno(),4);
		strcat((void *)uaString,srv_brw_get_verno());
		strcat((void *)uaString," ");
		strcat((void *)uaString,Get_Current_Lang_CountryCode());
	}
	else
{
		memset((void *)uaString,0x00,APPLIB_INET_MAX_UA_STRING_LEN+1);
		strcpy((char *)uaString, (const char*)g_applib_inet_cntx_p->active_user_agent.string);
         
    }
 #endif
}
#endif
/*****************************************************************************
 * FUNCTION
 *  applib_inet_get_user_agent_profile
 * DESCRIPTION
 *  This function is called to get active user agent profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
const char* applib_inet_get_user_agent_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    

#if defined(__MMI_EM_INET_APP_SLIM__) || !defined(__MMI_ENGINEER_MODE__)
    return APPLIB_DEFAULT_UA_PROFILE;
#else
	return (const char*)g_applib_inet_cntx_p->active_user_agent.profile;
  //  return mmi_em_inet_get_user_agent_profile();
#endif
}

#endif /* defined(PLUTO_MMI) */
