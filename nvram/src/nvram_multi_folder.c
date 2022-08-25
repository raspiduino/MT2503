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
 * nvram_multi_folder.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   NVRAM feature: support multi folders
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "nvram_main.h"

/***********************************************************
 * Static Variable
 ***********************************************************/

/* marco to form absolute path and filename */
/* File System with wide character interface */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __NVRAM_MULTI_FOLDERS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
#ifdef __NVRAM_BACKUP_DISK_FAT__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif


/***********************************************************
 * Global Variable
 **********************************************************/

/***********************************************************
 * Local Function
 **********************************************************/

/***********************************************************
 * Global Function
 **********************************************************/


#define FOLDER_PATH
/*****************************************************************************
 * FUNCTION
 *  nvram_query_folder_index
 * DESCRIPTION
 *  Get the index of folder
 * PARAMETERS
 *  category
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
nvram_folder_enum nvram_query_folder_index(nvram_category_enum category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_folder_enum folder_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_MULTI_FOLDERS__
    if (NVRAM_IS_CATEGORY_INTERNAL(category))
    {
        folder_index = NVRAM_NVD_CORE;
    }
    else if (NVRAM_IS_CATEGORY_CALIBRAT(category))
    {
        folder_index = NVRAM_NVD_CALI;
    }
    else if (NVRAM_IS_CATEGORY_IMPORTANT(category))
    {
        folder_index = NVRAM_NVD_IMEI;
    }
#ifdef __SMART_PHONE_MODEM__
    else if (NVRAM_IS_CATEGORY_IMPORTANT_L4(category))
    {
        folder_index = NVRAM_NVD_IMPNT;
    }
#endif
    #ifdef __NVRAM_CUSTOM_SENSITIVE__
    else if (NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(category))
    {
        folder_index = NVRAM_NVD_CUST;
    }
    #endif
    else
#endif /* __NVRAM_MULTI_FOLDERS__ */
    {
        folder_index = NVRAM_NVD_DATA;
    }

    return folder_index;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_query_work_path
 * DESCRIPTION
 *  Get the path of nvram folder
 * PARAMETERS
 *  folder_idx
 * RETURNS
 *  Success or Fail
 *****************************************************************************/

const kal_char *nvram_work_path[] =
{
    NVRAM_FS_DATAITEM_PATH,          // NVRAM_NVD_DATA = NVRAM_FOLDER_BEGIN,
#ifdef __NVRAM_MULTI_FOLDERS__
    NVRAM_FS_COREITEM_PATH,          // NVRAM_NVD_CORE,
    NVRAM_FS_CALIBRAT_DATAITEM_PATH, // NVRAM_NVD_CALI,
    NVRAM_FS_IMEI_DATAITEM_PATH,     // NVRAM_NVD_IMEI,
#ifdef __SMART_PHONE_MODEM__
    NVRAM_FS_IMPORTNT_DATAITEM_PATH, // NVRAM_NVD_IMPNT,
#endif
#ifdef __NVRAM_CUSTOM_SENSITIVE__
    NVRAM_FS_CUST_DATAITEM_PATH      // NVRAM_NVD_CUST,
#endif
#endif
};

kal_char * nvram_query_work_path(nvram_folder_enum folder_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (folder_idx >= NVRAM_FOLDER_TOTAL) ASSERT(0);

    return (kal_char *)nvram_work_path[folder_idx];

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __NVRAM_MULTI_FOLDERS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __SMART_PHONE_MODEM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        #ifdef __NVRAM_CUSTOM_SENSITIVE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
#endif /* __NVRAM_MULTI_FOLDERS__ */
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
}


/*****************************************************************************
 * FUNCTION
 *  nvram_query_file_name
 * DESCRIPTION
 *  Get file full name
 * PARAMETERS
 *  folder_idx  :
 *  nvramname   : nvram file
 *  filename    : full name of nvram file
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
kal_wchar * nvram_query_file_name(nvram_folder_enum folder_idx, kal_char *nvramname, kal_wchar *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wsprintf( filename, "%s\\%s", nvram_query_work_path(folder_idx), nvramname);


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __NVRAM_MULTI_FOLDERS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __SMART_PHONE_MODEM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        #ifdef __NVRAM_CUSTOM_SENSITIVE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    #endif /* __NVRAM_MULTI_FOLDERS__ */
    #ifdef __NVRAM_BACKUP_DISK_FAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return filename;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_query_ex_file_name
 * DESCRIPTION
 *  Get file full name
 * PARAMETERS
 *  folder_idx  :
 *  nvramname   : nvram file
 *  filename    : full name of nvram file
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

kal_wchar * nvram_query_ex_file_name(nvram_folder_enum folder_idx, kal_wchar *nvramname, kal_wchar *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wsprintf( filename, "%s\\%w", nvram_query_work_path(folder_idx), nvramname);

#if 0
/* under construction !*/
#ifdef __NVRAM_MULTI_FOLDERS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __SMART_PHONE_MODEM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #ifdef __NVRAM_CUSTOM_SENSITIVE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
#endif /* __NVRAM_MULTI_FOLDERS__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return filename;
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


/*****************************************************************************
 * FUNCTION
 *  nvram_delete_certain_folder
 * DESCRIPTION
 *  Delete all files in certain folder
 * PARAMETERS
 *  folder_idx : [in]
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static nvram_errno_enum nvram_create_certain_folder(nvram_folder_enum folder_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    kal_int32 Ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(filename, "%s", nvram_query_work_path(folder_idx));

    Ret = FS_GetAttributes(filename);
    if (Ret < FS_NO_ERROR)
    {
        /* Return value should be FS_FILE_NOT_FOUND (-9) only, others treat as fatal error */
        Ret = FS_CreateDir((const kal_wchar*)filename);
//        EXT_ASSERT(Ret == FS_NO_ERROR, (kal_uint32) Ret, 0, 0);
        if (Ret == FS_NO_ERROR)
            return NVRAM_ERRNO_SUCCESS;
    }

    nvram_trace(TRACE_FUNC, FUNC_NVRAM_CREATE_ALL_FOLDER, Ret, __LINE__);
    return NVRAM_ERRNO_FOLDER_EXIST;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_create_all_folder
 * DESCRIPTION
 *  create all the folders
 * PARAMETERS
 *  void
 * RETURNS
 *  status
 *****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

nvram_errno_enum nvram_create_all_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 loop_idx;
    nvram_errno_enum result = NVRAM_ERRNO_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (loop_idx = NVRAM_FOLDER_TOTAL - 1; loop_idx >= NVRAM_FOLDER_BEGIN; loop_idx--)    
    {
        if (nvram_create_certain_folder((nvram_folder_enum)loop_idx) == NVRAM_ERRNO_FOLDER_EXIST)
        {
            result = NVRAM_ERRNO_FOLDER_EXIST;
        }

        nvram_trace(TRACE_FUNC, FUNC_NVRAM_CREATE_ALL_FOLDER, loop_idx);
    }

    return result;
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


/*****************************************************************************
 * FUNCTION
 *  nvram_delete_certain_folder
 * DESCRIPTION
 *  Delete all files in certain folder
 * PARAMETERS
 *  folder_idx : [in]
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

static kal_bool nvram_delete_certain_folder(nvram_folder_enum folder_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    FS_HANDLE handle;
//    FS_DOSDirEntry fileinfo;
    WCHAR namepattern[32];
//    WCHAR filename[NVRAM_FILE_LEN + 1];
//    WCHAR fullfilename[NVRAM_MAX_PATH_LEN];
//    kal_uint32 retval;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * FS_XDelete will cut the folder, here we can't call it.
     */
    nvram_query_file_name(folder_idx, "", namepattern);
    FS_XDelete(namepattern, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_CreateDir(namepattern);

#if 0
/* under construction !*/
/* under construction !*/
 #ifndef __LOW_COST_SUPPORT_ULC__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __LOW_COST_SUPPORT_ULC__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __LOW_COST_SUPPORT_ULC__ */
#endif
    return KAL_TRUE;
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


/*****************************************************************************
 * FUNCTION
 *  nvram_delete_all_nvram_files
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif
kal_bool nvram_delete_all_nvram_files(nvram_bootup_enum bootup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 loop_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_trace(TRACE_FUNC, FUNC_NVRAM_DELETE_ALL_NVRAM_FILES, bootup_type);
    switch (bootup_type)
    {
        case NVRAM_FIRST_BOOTUP:
        {
            for (loop_idx = NVRAM_FOLDER_TOTAL - 1; loop_idx >= NVRAM_FOLDER_BEGIN; loop_idx--)                
            {
                nvram_delete_certain_folder((nvram_folder_enum)loop_idx);
            }
            break;
        }

        case NVRAM_NORMAL_BOOTUP:
        {
            nvram_delete_certain_folder(NVRAM_NVD_DATA);
        #ifndef __SMART_PHONE_MODEM__
        #ifdef __NVRAM_MULTI_FOLDERS__
            nvram_delete_certain_folder(NVRAM_NVD_CALI);
        #endif /* __NVRAM_MULTI_FOLDERS__ */
        #endif /* __SMART_PHONE_MODEM__ */
            break;
        }
    }

    return KAL_TRUE;
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


