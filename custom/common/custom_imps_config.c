/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   custom_imps_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains IMPS configuration default value. 
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------*/

#ifdef __IMPS__

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "fs_func.h"
#include "stdio.h"

#include "custom_imps_config.h"
#include "mmi2imps_struct.h"



kal_uint8 imps_directory[10]; 
kal_uint8 imps_client_id[IMPS_MAX_URL_LEN]= {"http://www.mtk.com/impsapp"};

const imps_accepted_content_type_struct imps_content_type[] =
{
        /*Note:Per SPEC,mime type must not be text/plain here*/
    {"image/*", 204800/*must less than max_push_len*/, 0, 0},
    {"audio/*", 204800, 0, 0},
    {"video/*", 204800, 0, 0},
    {"text/x-vcard", 2048, 0, 0},
    {"text/x-vcalendar", 2048, 0, 0},
    /*Don't remove this line! Add elements before it */        
    {"",0,0,0}
};

const imps_my_client_info_struct imps_pa_client_info =
{
    KAL_FALSE,/*any_content*/
    "eng",/*lang:Three-letter language code as specified in[ISO639-2].*/
    512,/*accepted_text_len:must be less than 1024,because the max ctrl_buff size is 2K (utf8->UCS2)*/
    307200,/*max_push_len*/        
    (imps_accepted_content_type_struct*)imps_content_type     
};

static imps_version_option_struct imps_version_option[] = 
{
    /* if server support 1.3, then log in server with 1.3 namespace */
    //{IMPS_CSP_VERSION_13, 0},
    /* if server support 1.2, then log in server with 1.2 namespace */
    {IMPS_CSP_VERSION_12, 0},
     /* if server do not support 1.3 and 1.2 or VersionDiscovery primtive,
        then use 1.1 name space to log in server. set @force to 1
     */
    {IMPS_CSP_VERSION_11, 1},
    /* end flag of version option */
    {0, 0}
};

const imps_custom_client_capability_struct imps_client_capability =
{
   307200,
   0x06,//IMPS_SUPPORTED_BEARER_WSP|IMPS_SUPPORTED_BEARER_HTTP
   307200,
   0x0b,//IMPS_CIR_METHOD_WAPSMS|IMPS_CIR_METHOD_WAPUDP|IMPS_CIR_METHOD_STCP
   IMPS_CLIENT_ID_TYPE_URL_RANDOM,//IMPS_CLIENT_ID_TYPE_URL_RANDOM
   (kal_uint8*)imps_client_id,
   (kal_uint8*)IMPS_DEFAULT_HEADER,
   (kal_uint8*)IMPS_OBJECT_HEADER,
   (imps_my_client_info_struct*)&imps_pa_client_info,
   30*KAL_TICKS_1_SEC,      /* 30s: default timeout period defined in WV CSP V1.2 */

#if defined(__OP11__)
   7 * 60,                 /* puzzling Orange spec. order this */
#else
   240,                    /* Default Time-To-Live value, count by second */
#endif

#ifdef IMPS_WV13_ENHANCEMENT
   IMPS_DELIVERY_METHOD_PUSH,
   IMPS_DIGEST_SCHEMA_MD5,   /* IMPS_DIGEST_SCHEMA_MD5|IMPS_DIGEST_SCHEMA_SHA|IMPS_DIGEST_SCHEMA_ALL */
#endif
   2,                       /* retry times in login */
   imps_version_option,
   5                       /* bear fallback timer, second */
};

const imps_custom_client_capability_struct * imps_client_capability_p = &imps_client_capability;


void imps_custom_work_directory(void)
{

    kal_int32 fd;
    kal_wchar ucs2_folder[IMPS_MAX_FILE_PATH_LEN];

    /*Create folders(@imps,@imps\image) in system drive*/
    kal_wsprintf(ucs2_folder, "%s", "Z:\\@imps\\");
    fd = FS_Open(ucs2_folder, FS_OPEN_DIR | FS_READ_ONLY);
    if (fd < 0)
    {
        fd = FS_CreateDir(ucs2_folder);
    }
    else
   	 {
        FS_Close(fd);
        }   	 	

    /*image*/
    kal_wsprintf(ucs2_folder,"%s%s","Z:\\@imps\\",IMPS_STATUS_CONTENT_FOLDER);
    fd = FS_Open(ucs2_folder, FS_OPEN_DIR | FS_READ_ONLY);
    if (fd < 0)
    {
        FS_CreateDir(ucs2_folder);
    }
    else
    {
        FS_Close(fd);
    }

    
#ifdef IMPS_IN_LARGE_STORAGE
    /*Create folders(imps) in user drive*/
    sprintf((char*)imps_directory, "%c%s",IMPS_APP_DISK,":\\imps\\");
    kal_wsprintf(ucs2_folder, "%s", imps_directory);
    
    fd = FS_Open(ucs2_folder, FS_OPEN_DIR | FS_READ_ONLY);
    if (fd < 0)
    {
        fd = FS_CreateDir(ucs2_folder);
        FS_SetAttributes((unsigned short*)ucs2_folder,FS_ATTR_DIR|FS_ATTR_HIDDEN);	    
    }
    else
    {
        FS_Close(fd);
    }
#else
    strcpy((char*)imps_directory,"Z:\\@imps\\");
#endif

    /*reply*/
    kal_wsprintf(ucs2_folder, "%s%s", imps_directory, IMPS_HTTP_REPLY_FOLDER);
    fd = FS_Open(ucs2_folder, FS_OPEN_DIR | FS_READ_ONLY);
    if (fd < 0)
    {
        FS_CreateDir(ucs2_folder);
    }
    else
    {
        FS_Close(fd);
    }

    /*user*/
    kal_wsprintf(ucs2_folder, "%s%s", imps_directory, IMPS_USER_CONTENT_FOLDER);
    fd = FS_Open(ucs2_folder, FS_OPEN_DIR | FS_READ_ONLY);
    if (fd < 0)
    {
        FS_CreateDir(ucs2_folder);
    }
    else
    {
        FS_Close(fd);
    }    

    /*Received*/
    kal_wsprintf(ucs2_folder, "%c:\\%w", IMPS_PUBLIC_DRV, IMPS_DEFAULT_FILE_PATH);
    fd = FS_Open(ucs2_folder, FS_OPEN_DIR | FS_READ_ONLY);
    if (fd < 0)
    {
        FS_CreateDir(ucs2_folder);
    }
    else
    {
        FS_Close(fd);
    }      
}

/*****************************************************************************
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *****************************************************************************/
void imps_custom_get_session_cookie(const char* user_id, char* session_cookie, int session_cookie_len)
{
    kal_uint32 now = 0;
    int j, i;

    kal_get_time(&now);
    j = sprintf(session_cookie, "MTK%d", now);
    for (i = 0; user_id[i] && j < session_cookie_len - 1; i++, j++)
    {
        session_cookie[j] = user_id[i];
    }
    session_cookie[j] = 0;
}

#endif
