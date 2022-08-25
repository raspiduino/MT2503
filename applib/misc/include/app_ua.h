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
 * app_ua.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains user agent function prototypes.
 *
 * Author:
 * -------
 *  
 *   Tim Chang (mtk02176)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _APP_UA_H
#define _APP_UA_H

#include "MMI_features.h"
#include "custom_wap_config.h"


#ifndef __OPTR_NONE__
#include "op_nvram_common_config.h"
#endif


#ifdef CUSTOM_INET_USER_AGENT_STRING_DEFAULT
#define APPLIB_DEFAULT_UA_STRING      CUSTOM_INET_USER_AGENT_STRING_DEFAULT
#elif defined(OPERA_V10_BROWSER)
#define APPLIB_DEFAULT_UA_STRING      "Opera/9.80 (MTK; U; en) Presto/2.4.15 Version/10.00"
#elif defined(OPERA_V11_BROWSER)
#define APPLIB_DEFAULT_UA_STRING      "Opera/9.80 (MTK; U; en) Presto/2.4.15 Version/10.00"
#else
#define APPLIB_DEFAULT_UA_STRING      "Maui Browser"
#endif

#ifdef CUSTOM_INET_USER_AGENT_PROFILE_DEFAULT
#define APPLIB_DEFAULT_UA_PROFILE     CUSTOM_INET_USER_AGENT_PROFILE_DEFAULT
#else
#define APPLIB_DEFAULT_UA_PROFILE     ""
#endif

#define APPLIB_INET_DEFAULT_USER_AGENT_INDEX     (0)
#define APPLIB_INET_DEFAULT_ACCEPT_HEADER_INDEX  WAP_CUSTOM_DEFAULT_ACCEPT_HEADER_INDEX
#define APPLIB_INET_DEFAULT_MMS_VERSION_INDEX    WAP_CUSTOM_DEFAULT_MMS_VERSION_INDEX

/****************************************************************************** 
 * ENUM
 ******************************************************************************/
/* This enum is for user to specify the interested type of setting */
typedef enum{
    APPLIB_INET_UA_STRING_OPT = 0,      /* user agent string */
    APPLIB_INET_UA_PROFILE_OPT,         /* user agent profile */
    APPLIB_INET_ACCEPT_HEADER_OPT,      /* accept header */
    APPLIB_INET_MMS_VERSION_OPT,        /* mms version */
    APPLIB_INET_OPT_TOTAL               /* total number of setting */
} applib_inet_option_enum;


/* This enum is to specify the type of accept header */
typedef enum{
    APPLIB_INET_ACCEPT_HEADER_WAP_1_2_1 = 0,  /* WAP 1.2.1 */
    APPLIB_INET_ACCEPT_HEADER_WAP_2_0,        /* WAP 2.0 */
    APPLIB_INET_ACCEPT_HEADER_WML,            /* WML */
    APPLIB_INET_ACCEPT_HEADER_XHTML,          /* WHTML */
    APPLIB_INET_ACCEPT_HEADER_HTML,           /* HTML */
    APPLIB_INET_ACCEPT_HEADER_TOTAL           /* total number of setting */
} applib_inet_accept_header_enum;


/* This enum is to specify MMS version */
typedef enum{
    APPLIB_INET_MMS_VERSION_10 = 0,     /* MMS 1.0 */
    APPLIB_INET_MMS_VERSION_11,         /* MMS 1.1 */
    APPLIB_INET_MMS_VERSION_12,         /* MMS 1.2 */
    APPLIB_INET_MMS_VERSION_TOTAL       /* total number of MMS version */
} applib_inet_mms_version_enum;


/****************************************************************************** 
 * Typedef
 ******************************************************************************/

/* This structure is to record the setting value passed by the registered event handler */
typedef struct{
    kal_uint32  value_int;      /* The type of value is integer, including accept header and MMS version. */
    const char  *value_str;     /* The type of value is constant character, including user agent string and user agent profile. */
} applib_inet_setting_struct;   

typedef void (*applib_inet_event_func_ptr) (applib_inet_option_enum opt, applib_inet_setting_struct *val);

#if defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_INET_APP_SLIM__)

/* This structrue is for active user agent. */
typedef struct{
    char *string;
    char *profile;
} applib_inet_user_agent_struct;

typedef struct
{
    applib_inet_option_enum opt;
    applib_inet_event_func_ptr event_hdlr;
} applib_inet_event_handler_struct;

/* This is the context structure of EMIA. */
typedef struct {
    applib_inet_user_agent_struct       active_user_agent;      /* active user agent setting */
    applib_inet_accept_header_enum      active_accept_header;   /* active accept header index */
    applib_inet_mms_version_enum        active_mms_version;     /* active MMS version */
    unsigned short active_user_agent_index;         /* the index of active user agent */
} applib_inet_cntx_struct;









/* Max. length of user agent string, defined in nvram_common_defs.h */
#define APPLIB_INET_MAX_UA_STRING_LEN    NVRAM_EF_INET_MAX_UA_STRING_LEN 

/* Max. length of user agent profile, defined in nvram_common_defs.h */
#define APPLIB_INET_MAX_UA_PROFILE_LEN   NVRAM_EF_INET_MAX_UA_PROFILE_LEN

#if (defined(__SLIM_PROJECT_32_32__) || defined(__SLIM_PROJECT_64_32__) || defined(__MMI_EM_INET_APP_SLIM__))  /* #ifdef __MMI_SLIM_ENGINEER_MODE__ */

/* This is to define the total number of user agent setting. */
#define APPLIB_INET_USER_AGENT_TOTAL                (1)
    
#define APPLIB_INET_USER_AGENT_LIST                 {"Default"}
#define APPLIB_INET_USER_AGENT_DATA                 {"", ""}

#else /* __SLIM_PROJECT_32_32__ || __SLIM_PROJECT_64_32__ || __MMI_EM_INET_APP_SLIM__)*/

/* This is to define the total number of user agent setting. */
#define APPLIB_INET_USER_AGENT_TOTAL     (18)


#define APPLIB_INET_USER_AGENT_LIST {\
    "Default", \
    "LG KD876", \
    "Nokia N72", \
    "Nokia E70", \
    "Nokia N93", \
    "Nokia 6680", \
    "Nokia 6280", \
    "Nokia 3230", \
    "Nokia 6230", \
    "SonyEricsson W900i", \
    "SonyEricsson W800i", \
    "SonyEricsson K700i", \
    "SonyEricsson Z800", \
    "Samsung D608", \
    "Motorola E1070", \
    "CMCC PIM", \
	"SonyEricssonW908c", \
    "CMCC TD LAB TEST"}

/* user agent string and profile 
   There are 15 settings here, excluding the editable setting. */
#define APPLIB_INET_USER_AGENT_DATA {\
    {"LG-KD876/v1.0 Arena/L2.3.3 Release/5.2.2008 Browser/Teleca/QLine Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://gsm.lge.com/html/gsm/LG-KD876.xml"},\
    {"NokiaN72/2.0617.1.0.3 Series60/2.8 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://nds.nokia.com/uaprof/NN72r100.xml"},\
    {"NokiaE70-1/3.0 (1.0610.05.06) SymbianOS/9.1 Series60/3.0 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://nds.nokia.com/uaprof/NE70-1r100.xml"},\
    {"NokiaN93-1/20.0.041 SymbianOS/9.1 Series60/3.0 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://nds.nokia.com/uaprof/NN93r100.xml"},\
    {"Nokia6680/1.0 (4.04.07) SymbianOS/8.0 Series60/2.6 Profile/MIDP-2.0Configuration/CLDC-1.1", "http://nds.nokia.com/uaprof/N6680r100.xml"},\
    {"Nokia6280/2.0 (03.60) Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://nds.nokia.com/uaprof/N6280r100.xml"},\
    {"Nokia3230/2.0 (5.0614.0) SymbianOS/7.0s Series60/2.1 Profile/MIDP-2.0Configuration/CLDC-1.0", "http://nds.nokia.com/uaprof/N3230r100.xml"},\
    {"Nokia6230/2.0 (03.15) Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://nds.nokia.com/uaprof/N6230r100.xml"},\
    {"SonyEricssonW900i/R1L Browser/NetFront/3.3 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://wap.sonyericsson.com/UAprof/W900iR101-3G.xml"},\
    {"SonyEricssonW800i/R1L Browser/SEMC-Browser/4.2 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://wap.sonyericsson.com/UAprof/W800iR101.xml"},\
    {"SonyEricssonK700i/R2AG SEMC-Browser/4.0.3 Profile/MIDP-1.0 MIDP-2.0 Configuration/CLDC-1.1", "http://wap.sonyericsson.com/UAprof/K700iR201.xml"},\
    {"SonyEricssonZ800/R1X Browser/SEMC-Browser/4.1 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://wap.sonyericsson.com/UAprof/Z800R101.xml"},\
    {"SAMSUNG-SGH-D608/1.0/WAP2.0 Profile/MIDP-2.0 Configuration/CL", "http://wap.samsungmobile.com/uaprof/SGH-D608.xml"},\
    {"MOT-E1070/85.83.50R MIB/BER2.2 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://motorola.handango.com/phoneconfig/E1070/Profile/E1070.rdf"},\
    {"MTK_MAUI_01/07 Release/22.11.2007 Browser/wap2.0 Sync/SyncClient1.1 Profile/MIDP-2.0 Configuration/CLDC-1.1", ""},\
    {"SonyEricssonW908c/R1x Browser/NetFront/3.4 Profile/MIDP-2.0 Configuration/CLDC-1.1 ", ""},\
    {"MTK_MAUI_TD_01/07 Release/22.11.2007 Browser/wap2.0 Sync/SyncClient1.1 Profile/MIDP-2.0 Configuration/CLDC-1.1", ""}}


#endif  /* __SLIM_PROJECT_32_32__ || __SLIM_PROJECT_64_32__ || __MMI_EM_INET_APP_SLIM__ */

    

/* accept header list */
#define APPLIB_INET_ACCEPT_HEADER_LIST {\
    "WAP 1.2.1", \
    "WAP 2.0", \
    "WML", \
    "XHTML", \
    "HTML"}

/* MMS version list */
#define APPLIB_INET_MMS_VERSION_LIST {\
    "MMS1.0", \
    "MMS1.1", \
    "MMS1.2" }


#ifdef OBIGO_Q05A_MMS
extern void mms_em_change_setting(applib_inet_option_enum opt, applib_inet_setting_struct *val);
#endif

 
#ifdef __MMI_BROWSER_2__
extern void bam_registry_em_setting_changed_callback(applib_inet_option_enum opt, applib_inet_setting_struct *new_setting);
#endif

#ifdef OBIGO_Q03C_MMS_V02
extern void mms_em_change_setting(applib_inet_option_enum opt, applib_inet_setting_struct *val);
#endif

#ifdef OBIGO_Q03C_MMS_V01
extern void mms_em_change_setting(applib_inet_option_enum opt, applib_inet_setting_struct *val);
#endif



extern void applib_inet_activate_ua(unsigned int active_ua_idx);

extern void applib_inet_activate_mms_version(applib_inet_mms_version_enum index);

extern void applib_inet_activate_accept_header(applib_inet_accept_header_enum index);

extern void applib_inet_notify_app(applib_inet_option_enum opt, const char *str_val, kal_uint32 int_val);

extern void applib_inet_set_ua_edited(WCHAR* string, WCHAR* profile);

extern void applib_inet_init(void);

#endif //#if defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_INET_APP_SLIM__)
/****************************************************************************** 
 * External Function
 ******************************************************************************/
/* This function is to get active user agent string. Notice that the return type is const char */
extern const char* applib_inet_get_user_agent_string(void);

/* This function is to get active user agent profile. Notice that the return type is const char */
extern const char* applib_inet_get_user_agent_profile(void);

#ifdef __MMI_BROWSER_2__
extern void applib_get_dynamic_ua(char *ua);
#endif


extern unsigned int applib_inet_get_active_user_agent_index(void);

extern const char* applib_inet_get_user_agent_from_list(unsigned int index);

extern applib_inet_accept_header_enum applib_inet_get_active_accept_header(void);

extern applib_inet_mms_version_enum applib_inet_get_active_mms_version(void);





#endif /* _APP_CRC_H */ 

