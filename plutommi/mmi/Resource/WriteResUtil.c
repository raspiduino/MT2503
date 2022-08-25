#include "mmi_features.h"
#include "MMIDataType.h"
#include "CustDataRes.h"
#include "CustDataProts.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#define WIN32_LEAN_AND_MEAN
#include "windows.h"

#include "CustResDef.h"
#include "gui_resource_type.h"
#include "ABMLoader.h"
#include "CmidiGen.h"
#include "WriteResUtil.h"


const RESOURCE_INFO audio_resource_info[] = {
    {"MP3", AUDIO_TYPE_MP3},
    {"IMY", AUDIO_TYPE_IMY},
    {"MID", AUDIO_TYPE_MID},
    {"WAV", AUDIO_TYPE_WAV},
    {"MMF", AUDIO_TYPE_MMF},
    {"PCM", AUDIO_TYPE_PCM},
    {"DVI", AUDIO_TYPE_DVI},
    {"AMR", AUDIO_TYPE_AMR},
    {"AAC", AUDIO_TYPE_AAC},
    {"WMA", AUDIO_TYPE_WMA},
    {"M4A", AUDIO_TYPE_M4A}
};

const S8 *support_media_ext[SUPPORT_N_MEDIA_TYPE] = { "AVI", "3GP", "MP4", "RV", "RM", "RMVB" };

const RESOURCE_INFO sequential_image[SUPPORT_N_SEQUENTIAL_IMAGE_TYPE] = {
    {"BMP", IMAGE_TYPE_BMP_SEQUENCE},
    {"JPG", IMAGE_TYPE_JPG_SEQUENCE},
#if defined(__MMI_ALPHA_BLENDING__) && !defined(GDI_USING_HW_PNG)
    {"PNG", IMAGE_TYPE_ABM_SEQUENCE}
#else /* defined(__MMI_ALPHA_BLENDING__) && !defined(GDI_USING_HW_PNG) */
    {"PNG", IMAGE_TYPE_PNG_SEQUENCE}
#endif /* defined(__MMI_ALPHA_BLENDING__) && !defined(GDI_USING_HW_PNG) */
};


static MMI_BOOL g_mtk_resgen_error_flag = MMI_FALSE;

MMI_BOOL mtk_resgen_has_error()
{
    return g_mtk_resgen_error_flag;
}

MMI_BOOL mtk_resgen_set_error()
{
    g_mtk_resgen_error_flag = MMI_TRUE;
}

MMI_BOOL mtk_resgen_reset_error()
{
    g_mtk_resgen_error_flag = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  file_exist
 * DESCRIPTION
 *  test whether the file exists
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL		MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL file_exist(S8* filename)
{
    DWORD fileAttr;

    fileAttr = GetFileAttributes(filename);
    if (0xFFFFFFFF == fileAttr || ( (fileAttr & FILE_ATTRIBUTE_DIRECTORY) != 0) )
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


MMI_BOOL is_directory(S8* filename)
{
    DWORD fileAttr;

    fileAttr = GetFileAttributes(filename);
    if (0xFFFFFFFF == fileAttr)
    {
        return MMI_FALSE;
    }
    if ( (fileAttr & FILE_ATTRIBUTE_DIRECTORY) != 0)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


U32 resgen_compare_file_time(S8* file1, S8* file2)
{
    WIN32_FIND_DATA data1;
    WIN32_FIND_DATA data2;
    HANDLE search = NULL;
    search = FindFirstFile(file1, &data1);
    if (search != INVALID_HANDLE_VALUE)
    {
        FindClose(search);
        search = NULL;

        search = FindFirstFile(file2, &data2);
        if (search != INVALID_HANDLE_VALUE)
        {
            FindClose(search);
            search = NULL;

            return CompareFileTime(&(data2.ftLastWriteTime), &(data1.ftLastWriteTime));
        }
    }
    return 1;
}

/*****************************************************************************
 * FUNCTION
 *  ExtractExtension
 * DESCRIPTION
 *  Function Extracting the extension
 * PARAMETERS
 *  src             [?]         
 *  res_type        [IN]        -> resource type
 *  string(?)       [IN]        -> string containing file name
 * RETURNS
 *  U8
 *****************************************************************************/
U8 ExtractExtension(S8 *src, U32 res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 type_number;
    U8 ret = 0;
    S8 *arr;
    RESOURCE_INFO *pResource_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = strlen(src) - 1;
    arr = src+i;

    for (j = 0; j < 5 ; j++)
    {
        if(*arr == '.')
        {
            arr++;
            break;
        }
        else
    {
            arr--;
        }
    }

    if(j >= 5)
    {
        return ret;
    }

    switch (res_type)
    {
        case RES_IMAGE:
        case RES_MEDIA:
        case RES_FONT:
            ret = IMAGE_TYPE_INVALID;
            pResource_info = image_resource_info;
            type_number = sizeof(image_resource_info) / sizeof(RESOURCE_INFO);
            break;

        case RES_AUDIO:
            ret = AUDIO_TYPE_INVALID;
            pResource_info = audio_resource_info;
            type_number = sizeof(audio_resource_info) / sizeof(RESOURCE_INFO);
            break;

        default:
            RES_PRINT_INFO("res_type in Extract_Name is invalid!!");
            ret = IMAGE_TYPE_INVALID;
            pResource_info = image_resource_info;
            type_number = sizeof(image_resource_info) / sizeof(RESOURCE_INFO);
            break;
    }

    for (i = 0; i < type_number; i++)
    {
        if (!(strcmp(arr, pResource_info[i].filename_ext)))
        {
            ret = pResource_info[i].file_type;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  ChangeExtension
 * DESCRIPTION
 *  Function Change the extension
 * PARAMETERS
 *  src             [IN]        -> string containing file name 
 *  res_type        [IN]        -> resource type
 *  ext_type        [IN]        -> extension type
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL ChangeExtension(S8 *src, U32 res_type, S32 ext_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 type_number;
    U8 ret = 0;
    S8 *arr;
    RESOURCE_INFO *pResource_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = strlen(src) - 1;
    arr = src+i;

    for (j = 0; j < 5 ; j--)
    {
        if(*arr == '.')
        {
            arr++;
            break;
        }
        else
        {
            arr--;
        }
    }

    if (j >= 5)
    {
        return FALSE;
    }

    switch (res_type)
    {
        case RES_IMAGE:
        case RES_MEDIA:
            ret = IMAGE_TYPE_INVALID;
            pResource_info = image_resource_info;
            type_number = sizeof(image_resource_info) / sizeof(RESOURCE_INFO);
            break;

        case RES_AUDIO:
            ret = AUDIO_TYPE_INVALID;
            pResource_info = audio_resource_info;
            type_number = sizeof(audio_resource_info) / sizeof(RESOURCE_INFO);
            break;

        default:
            RES_PRINT_INFO("res_type in Extract_Name is invalid!!");
            ret = IMAGE_TYPE_INVALID;
            pResource_info = image_resource_info;
            type_number = sizeof(image_resource_info) / sizeof(RESOURCE_INFO);
            break;
    }

    for (i = 0; i < type_number; i++)
    {
        if (pResource_info[i].file_type == ext_type)
        {
            break;
        }
    }

    if (i >= type_number)
    {
        return FALSE;
    }

    for (j = 0; j < 5; j++)
    {
        *(arr+j) = *(pResource_info[i].filename_ext+j);
    }

    return TRUE;
}

void str_upper(char* str, unsigned int max_length)
{
    unsigned int len = strlen(str);
    len = min(len, max_length);
    int i;

    for (i = 0; i <= len; ++i)
    {
        str[i] = toupper(str[i]);
    }
}

