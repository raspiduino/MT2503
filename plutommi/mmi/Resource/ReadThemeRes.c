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
 *   ReadThemeRes.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Functions for get theme resource.
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
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 *==============================================================================
 *******************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"

#include "CustVenusThemeRes.h"
#include "ThemeResProt.h"
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
#include "ResThirdROMUtil.h"
#include "CustVenusThemeData.h"
#include "CustVenusAppIconData.h"
#endif

#include "kal_general_types.h"
#include "fs_gprot.h"
#include "gdi_include.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "DebugInitDef_Int.h"
#include "GlobalResDef.h"
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
#include "third_rom.h"
#endif

#include "MMI_fw_trc.h"

#include "verno.h"

#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)
#include "CustVenusThemeId.h"
#endif /* __COSMOS_MMI_PACKAGE__ || defined(__MMI_APP_ICON_FW_SUPPORT__) */

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

#ifndef __MMI_PLUTO_SUPPORT_COSMOS_ACO__
 //for pluto support cosmos aco
 #define __MMI_PLUTO_SUPPORT_COSMOS_ACO__
#endif

extern mmi_res_theme_system_strcut* g_mmi_res_theme_system_data_ptr;
extern mmi_res_theme_system_strcut g_mmi_res_app_icon_data;


/*****************************************************************************
 * Definition
 *****************************************************************************/
#define MMI_RES_THEME_SIGNATURE         5064788     /* THM\0 */
#define MMI_RES_THEME_RES_TBL_SIZE      13          /* size of each item in resource table */
#define MMI_RES_THEME_INVALID_ADDR      0xFFFFFFFF  /* invalid address */
#define MMI_RES_THEME_MAX_CONCURRENT    3           /* maximun concurrent theme set, default + current (system / DLT / OTF) + other */
#define MMI_RES_THEME_PRIORITY_EMPTY    255         /* empty slot */
#define MMI_RES_THEME_PRIORITY_DEFAULT  254         /* priority of default theme */
#define MMI_RES_THEME_PRIORITY_CURRENT  253         /* priority of current theme */
#define MMI_RES_THEME_MAX_DLT_NUMBER    (MMI_RES_THEME_MAX_CONCURRENT - 1)                                  /* max number of downloadable, 1 = default */
#define MMI_RES_THEME_FILE_HINT_CNT     5           /* seek hint count for default DLT theme */
#define MMI_RES_THEME_FILE_HINT_SIZE    (FS_SEEKHINT_BUFFER_SIZE_FOR_HINT_CNT(MMI_RES_THEME_FILE_HINT_CNT)) /* seek hint size for DLT theme */
#define MMI_RES_THEME_MAX_STR_ID_LENGTH 64          /* maximun string ID length */

#if defined(__MMI_RES_THEME_CACHE_FROM_ASM__)
#define MMI_RES_THEME_DLT_BASE_POOL     2100        /* only store resource table without image data */
#endif /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */



#if !defined(__MTK_TARGET__)
#define __align(X)
#endif /* !defined(__MTK_TARGET__) */


/* theme package structure */
typedef struct
{
    mmi_res_theme_struct theme; /* theme structure */
    U8 priority;                /* theme priority: 1 is highest, 255 is lowest */
} mmi_res_theme_pack_struct;


/*****************************************************************************
 * Global variable
 *****************************************************************************/
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)

/* active theme set */
static mmi_res_theme_pack_struct g_mmi_res_theme[MMI_RES_THEME_MAX_CONCURRENT] = {0};

/* theme priority list */
static U8 g_mmi_res_theme_priority_list[MMI_RES_THEME_MAX_CONCURRENT] = {0};

#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)

/* global file handle for downloadable theme */
fs_file_tbl_struct g_mmi_res_theme_file_handle[MMI_RES_THEME_MAX_DLT_NUMBER];

/* file hint to speed up seek for current theme */
__align(4) static U8 g_mmi_res_theme_file_hint[MMI_RES_THEME_FILE_HINT_SIZE];

#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */


#endif /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__) */


/*****************************************************************************
 * memory pool utility
 *****************************************************************************/
/* memory node for each DLT */
typedef struct
{
    U8* ptr;    /* pointer to allocated memory */
    S32 size;   /* allocated size */
} mmi_res_theme_dlt_mem_node_struct;

/* memory pool manager */
typedef struct
{
    mmi_res_theme_dlt_mem_node_struct node[MMI_RES_THEME_MAX_DLT_NUMBER];   /* all allocated notes */
    U8* current_free_ptr;   /* pointer to current available address */
    S32 node_number;        /* allocated note number */
    S32 free_size;          /* current available size */
} mmi_res_theme_dlt_mem_manager;


#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)

/* memory pool */
#if defined(__MMI_RES_THEME_CACHE_FROM_ASM__)
__align(4) static U8 g_mmi_res_theme_dlt_mem_pool[MMI_RES_THEME_DLT_BASE_POOL] = {0};
#else /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */
__align(4) static U8 g_mmi_res_theme_dlt_mem_pool[MMI_RES_THEME_DLT_POOL] = {0};
#endif /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */

/* instance of memory pool manager */
static mmi_res_theme_dlt_mem_manager g_mmi_res_theme_dlt_mem_mgr = {0};

#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */


#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_dlt_mem_reset
 * DESCRIPTION
 *  reset DLT memory pool
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_res_theme_dlt_mem_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_res_theme_dlt_mem_mgr.current_free_ptr = (U8*)&g_mmi_res_theme_dlt_mem_pool[0];
    g_mmi_res_theme_dlt_mem_mgr.node_number = 0;
#if defined(__MMI_RES_THEME_CACHE_FROM_ASM__)
    g_mmi_res_theme_dlt_mem_mgr.free_size = MMI_RES_THEME_DLT_BASE_POOL;
#else /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */
    g_mmi_res_theme_dlt_mem_mgr.free_size = MMI_RES_THEME_DLT_POOL;
#endif /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_dlt_mem_alloc
 * DESCRIPTION
 *  allocate DLT memory
 * PARAMETERS
 *  size    [IN] size of memory to allocate
 * RETURNS
 *  pointer to the allocated buffer, NULL if failed
 *****************************************************************************/
static U8* mmi_res_theme_dlt_mem_alloc(S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size <= g_mmi_res_theme_dlt_mem_mgr.free_size)
    {
        S32 idx = g_mmi_res_theme_dlt_mem_mgr.node_number;

        ptr = g_mmi_res_theme_dlt_mem_mgr.current_free_ptr;
        g_mmi_res_theme_dlt_mem_mgr.node[idx].ptr = ptr;
        g_mmi_res_theme_dlt_mem_mgr.node[idx].size = size;
        g_mmi_res_theme_dlt_mem_mgr.current_free_ptr += size;
        g_mmi_res_theme_dlt_mem_mgr.node_number ++;
        g_mmi_res_theme_dlt_mem_mgr.free_size -= size;
    }
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_dlt_mem_free
 * DESCRIPTION
 *  free allocated memory and pack memory pool
 * PARAMETERS
 *  ptr     [IN] pointer to allocated memory which needs to free
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_res_theme_dlt_mem_free(U8* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr)
    {
        S32 i;
        S32 number = g_mmi_res_theme_dlt_mem_mgr.node_number;

        /* find node */
        for (i = 0 ; i < number ; i++)
        {
            if (g_mmi_res_theme_dlt_mem_mgr.node[i].ptr == ptr)
            {
                g_mmi_res_theme_dlt_mem_mgr.node[i].size = 0;
            }
        }

        mmi_res_theme_dlt_mem_reset();

        /* pack pool */
        for (i = 0 ; i < number ; i++)
        {
            S32 size = g_mmi_res_theme_dlt_mem_mgr.node[i].size;
            U8* ori_ptr = g_mmi_res_theme_dlt_mem_mgr.node[i].ptr;

            if (size > 0)
            {
                /* move forward */
                U8* new_ptr = g_mmi_res_theme_dlt_mem_mgr.current_free_ptr;
                if (g_mmi_res_theme_dlt_mem_mgr.node[i].ptr != new_ptr)
                {
                    S32 j;

                    memmove(g_mmi_res_theme_dlt_mem_mgr.current_free_ptr, g_mmi_res_theme_dlt_mem_mgr.node[i].ptr, size);

                    /* update pointer in theme structure */
                    for (j = 0 ; j < MMI_RES_THEME_MAX_CONCURRENT ; j++)
                    {
                        if (g_mmi_res_theme[j].theme.dlt_mem_ptr == ori_ptr)
                        {
                            S32 diff = (S32)new_ptr - (S32)ori_ptr;
                            S32 k;

                            for (k = 0 ; k < MMI_RES_THEME_TYPE_MAX ; k++)
                            {
                                g_mmi_res_theme[j].theme.res_table[k] = (U8*)(g_mmi_res_theme[j].theme.res_table[k] + diff);
                            }
                            g_mmi_res_theme[j].theme.string_table = (U8*)(g_mmi_res_theme[j].theme.string_table + diff);
                        }
                    }
                }

                g_mmi_res_theme_dlt_mem_mgr.current_free_ptr += size;
                g_mmi_res_theme_dlt_mem_mgr.node_number ++;
                g_mmi_res_theme_dlt_mem_mgr.free_size -= size;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_dlt_mem_alloc_free
 * DESCRIPTION
 *  allocate all available memory
 * PARAMETERS
 *  size    [OUT] available size
 * RETURNS
 *   pointer to the allocated buffer, NULL if failed
 *****************************************************************************/
static U8* mmi_res_theme_dlt_mem_alloc_free(S32 *size)
{
    *size = g_mmi_res_theme_dlt_mem_mgr.free_size;
    return (U8*)g_mmi_res_theme_dlt_mem_mgr.current_free_ptr;
}


#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */


/*****************************************************************************
 * Byte stream helper
 *****************************************************************************/
/* byte strema struct */
typedef struct
{
    S32 size;           /* size of the byte stream, -1 if size is not available */
    S32 current_offset; /* current offset of the byte stream */
    U8* data;           /* data of the byte stream */
#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    FS_HANDLE fp;       /* file handle of the byte strame */
    MMI_BOOL is_file;   /* whether the byte stream is from file */
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
    MMI_BOOL is_pri_theme; /* whether is priority theme */
    U32 theme_offset;      /* theme offset in third rom */
    U32 theme_length;      /* theme length */
#endif
} mmi_res_theme_bytestream_struct;


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_bytestream_init_memory
 * DESCRIPTION
 *  init byte stream from memory
 * PARAMETERS
 *  bs_handle   [OUT] byte stream handle
 *  data        [IN] data of the byte stream
 *  size        [IN] size of the byte strame
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_res_theme_bytestream_init_memory (mmi_res_theme_bytestream_struct* bs_handle, U8* data, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bs_handle->size = size;
#ifndef __MMI_RES_THEME_THIRD_ROM_SUPPORT__    
    bs_handle->current_offset = 0;
#endif
    bs_handle->data = data;

#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    bs_handle->is_file = MMI_FALSE;
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)*/

    return MMI_TRUE;
}


#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_bytestream_init_file_handle
 * DESCRIPTION
 *  init byte stream from file
 * PARAMETERS
 *  bs_handle   [OUT] byte stream handle
 *  fh          [IN] file handle
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_res_theme_bytestream_init_file_handle (mmi_res_theme_bytestream_struct* bs_handle, FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        /* open file */
        bs_handle->fp = fh;

        /* get file size */
        if (FS_GetFileSize(bs_handle->fp, (U32*)&bs_handle->size) < FS_NO_ERROR)
        {
            break;
        }

        bs_handle->current_offset = 0;
        bs_handle->is_file = MMI_TRUE;

        ret = MMI_TRUE;
    } while (0);

    return ret;
}
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */


#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_bytestream_init_file
 * DESCRIPTION
 *  init byte stream from file
 * PARAMETERS
 *  bs_handle   [OUT] byte stream handle
 *  filename    [IN] filename of the byte stream
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_res_theme_bytestream_init_file (mmi_res_theme_bytestream_struct* bs_handle, const WCHAR* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((fh = FS_Open(filename, FS_READ_ONLY)) >= FS_NO_ERROR)
    {
        return mmi_res_theme_bytestream_init_file_handle(bs_handle, fh);
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_bytestream_seek_start
 * DESCRIPTION
 *  seek the byte strame from the beginning
 * PARAMETERS
 *  bs_handle   [IN/OUT] byte stream handle
 *  offset      [IN] offset to seek from the beginning
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_res_theme_bytestream_seek_start (mmi_res_theme_bytestream_struct* bs_handle, S32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    if (bs_handle->is_file)
    {
        FS_Seek(bs_handle->fp, offset, FS_FILE_BEGIN);
    }
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
    bs_handle->current_offset = bs_handle->theme_offset + offset;
#else
    bs_handle->current_offset = offset;
#endif
}


#if 0   /* no use now */
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
#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
/* under construction !*/
/* under construction !*/
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_bytestream_is_eof
 * DESCRIPTION
 *  check whether current offset is at the end
 * PARAMETERS
 *  bs_handle   [IN] byte stream handle
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_res_theme_bytestream_is_eof (mmi_res_theme_bytestream_struct* bs_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((bs_handle->size != -1) && (bs_handle->current_offset >= bs_handle->size)) ? (MMI_TRUE) : (MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_bytestream_get_byte
 * DESCRIPTION
 *  get byte from current offset
 * PARAMETERS
 *  bs_handle   [IN] byte stream handle
 * RETURNS
 *  byte
 *****************************************************************************/
static U8 mmi_res_theme_bytestream_get_byte (mmi_res_theme_bytestream_struct* bs_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_res_theme_bytestream_is_eof(bs_handle))
    {
#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
        if (bs_handle->is_file)
        {
            U32 len;

            if (FS_Read(bs_handle->fp, &data, 1, &len) < FS_NO_ERROR)
            {
                data = 0;
            }
        }
        else
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
        {
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
            if (bs_handle->data != NULL)
            {
                data = bs_handle->data[bs_handle->current_offset];
            }
            else if (bs_handle->is_pri_theme)
            {
                if (!MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_APPICONS, &data, bs_handle->current_offset, 1))
                {
                    data = 0;
                }
            }
            else
            {       
                if (!MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_THEMES, &data, bs_handle->current_offset, 1))
                {
                    data = 0;
                }
            }
#else
            data = bs_handle->data[bs_handle->current_offset];
#endif
        }
        bs_handle->current_offset++;
    }

    return data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_bytestream_get_word
 * DESCRIPTION
 *  get word from current offset
 * PARAMETERS
 *  bs_handle   [IN] byte stream handle
 * RETURNS
 *  word
 *****************************************************************************/
static U16 mmi_res_theme_bytestream_get_word (mmi_res_theme_bytestream_struct* bs_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 LSB = (U16)mmi_res_theme_bytestream_get_byte(bs_handle);
    U16 MSB = (U16)mmi_res_theme_bytestream_get_byte(bs_handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((MSB << 8) | LSB);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_bytestream_get_dword
 * DESCRIPTION
 *  get double word from current offset
 * PARAMETERS
 *  bs_handle   [IN] byte stream handle
 * RETURNS
 *  double word
 *****************************************************************************/
static U32 mmi_res_theme_bytestream_get_dword (mmi_res_theme_bytestream_struct* bs_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 LSB = (U32)mmi_res_theme_bytestream_get_word(bs_handle);
    U32 MSB = (U32)mmi_res_theme_bytestream_get_word(bs_handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((MSB << 16) | LSB);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_bytestream_read
 * DESCRIPTION
 *  read from current offset
 * PARAMETERS
 *  bs_handle   [IN] byte stream handle
 *  buf         [OUT] buffer
 *  len         [OUT] buffer length
 * RETURNS
 *  read length
 *****************************************************************************/
static size_t mmi_res_theme_bytestream_read (mmi_res_theme_bytestream_struct* bs_handle, U8* buf, size_t len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    if (bs_handle->is_file)
    {
        FS_Read(bs_handle->fp, buf, len, &count);
    }
    else
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
    {
        if (bs_handle->size != -1)
        {
            U32 total_size = bs_handle->size - bs_handle->current_offset;

            count = (total_size > len) ? (len) : (total_size);
        }
        else
        {
            count = len;
        }
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
        if (bs_handle->is_pri_theme)
        {
            MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_APPICONS, buf, bs_handle->current_offset, count);
        }
        else
        {
            MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_THEMES, buf, bs_handle->current_offset, count);
        }
#else
        memcpy(buf, &bs_handle->data[bs_handle->current_offset], count);
#endif
        bs_handle->current_offset += count;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_bytestream_close
 * DESCRIPTION
 *  close the byte stream
 * PARAMETERS
 *  bs_handle   [IN/OUT] byte stream handle
 *  is_keep_fh  [IN] whether to keep file handle after close
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_res_theme_bytestream_close (mmi_res_theme_bytestream_struct* bs_handle, MMI_BOOL is_keep_fh)
{
#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    if (bs_handle->is_file && !is_keep_fh)
    {
        FS_Close(bs_handle->fp);
    }
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)    
    else if (!bs_handle->is_file && bs_handle->data == NULL)
    {
        bs_handle->theme_offset = 0;
        bs_handle->theme_length = 0;
        bs_handle->is_pri_theme = MMI_FALSE;
    }
#endif /* defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__) */    
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */

    bs_handle->size = 0;
    bs_handle->current_offset = 0;
    bs_handle->data = NULL;

#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    bs_handle->is_file = MMI_FALSE;
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
}


/*****************************************************************************
 * Cache from ASM
 *****************************************************************************/
#if defined(__MMI_RES_THEME_CACHE_FROM_ASM__)

/* pointer to allocated ASM memory */
static MMI_ID g_mmi_res_theme_cache_asm_group_id = GRP_ID_INVALID;
static U8* g_mmi_res_theme_cache_asm_ptr = NULL;

#endif /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_cache_attach_asm
 * DESCRIPTION
 *  attach cache memory from ASM, only used for very special case, like launcher
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_res_theme_cache_attach_asm (void)
{
#if defined(__MMI_RES_THEME_CACHE_FROM_ASM__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_res_theme_cache_asm_group_id != GRP_ID_INVALID &&
        g_mmi_res_theme_cache_asm_ptr == NULL)
    {
        g_mmi_res_theme_cache_asm_ptr = mmi_frm_asm_alloc_nc_r(g_mmi_res_theme_cache_asm_group_id, MMI_RES_THEME_DLT_POOL);
    }
    mmi_res_venus_theme_cache_init(g_mmi_res_theme_cache_asm_ptr, MMI_RES_THEME_DLT_POOL);
#endif /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_cache_detach_asm
 * DESCRIPTION
 *  free cache memory from ASM, only used for very special case, like launcher
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_res_theme_cache_detach_asm (void)
{
#if defined(__MMI_RES_THEME_CACHE_FROM_ASM__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_res_theme_cache_asm_ptr)
    {
        mmi_frm_asm_free_r(g_mmi_res_theme_cache_asm_group_id, g_mmi_res_theme_cache_asm_ptr);
        mmi_res_venus_theme_cache_init(NULL, 0);
        g_mmi_res_theme_cache_asm_ptr = NULL;
    }
#endif /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */
}


#if defined(__MMI_RES_THEME_CACHE_FROM_ASM__)
/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_cache_asm_proc
 * DESCRIPTION
 *  proc for cache from ASM
 * PARAMETERS
 *  evt     [IN] mmi event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_res_theme_cache_asm_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    /* keep dangle group */
    case EVT_ID_DELETE_DANGLE_GROUP_REQ:
        ret = MMI_RET_ERR;
        break;

    /* volunteer / force free */
    case EVT_ID_ASM_FREE_REQ:
    case EVT_ID_ASM_FREE_REQ_NO_WAIT:
    case EVT_ID_ASM_FORCE_FREE:
#if defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__)
        mmi_res_theme_cache_detach_asm();
        ret = MMI_FRM_ASM_FREED;
#endif
        break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_cache_asm_init
 * DESCRIPTION
 *  init cache from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_res_theme_cache_asm_init (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_res_theme_cache_asm_group_id = mmi_frm_group_create(GRP_ID_ROOT, SRV_VENUS_THEME, mmi_res_theme_cache_asm_proc, NULL);

    if (g_mmi_res_theme_cache_asm_group_id != GRP_ID_INVALID)
    {
        mmi_frm_asm_property_struct property;

        if (mmi_frm_asm_get_property(g_mmi_res_theme_cache_asm_group_id, &property))
        {
            property.f_hide_in_oom = 1;
            mmi_frm_asm_set_property(g_mmi_res_theme_cache_asm_group_id, &property);
        }
    }

    g_mmi_res_theme_cache_asm_ptr = NULL;
}
#endif /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */


/*****************************************************************************
 * Static function
 *****************************************************************************/
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_find_1st_priority_slot
 * DESCRIPTION
 *  find the 1st appeared slot for specified priority
 * PARAMETERS
 *  priority    [IN] priority to search
 * RETURNS
 *  index to the slot
 *****************************************************************************/
static S32 mmi_res_theme_find_1st_priority_slot(U8 priority)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < MMI_RES_THEME_MAX_CONCURRENT ; i++)
    {
        if (g_mmi_res_theme[i].priority == priority)
        {
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_sort_priority_list
 * DESCRIPTION
 *  sort the priority list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_res_theme_sort_priority_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    MMI_BOOL is_check[MMI_RES_THEME_MAX_CONCURRENT] = {MMI_FALSE};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < MMI_RES_THEME_MAX_CONCURRENT ; i++)
    {
        S32 idx = -1;
        U8 min_priority = 255;

        for (j = 0 ; j < MMI_RES_THEME_MAX_CONCURRENT ; j++)
        {
            if ((!is_check[j]) &&
                (g_mmi_res_theme[j].priority <= min_priority))
            {
                idx = j;
                min_priority = g_mmi_res_theme[j].priority;
            }
        }

        if (idx != -1)
        {
            is_check[idx] = MMI_TRUE;
            g_mmi_res_theme_priority_list[i] = idx;
        }
    }

#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    /* init cache */
    {
#if defined(__MMI_RES_THEME_CACHE_FROM_ASM__)
        mmi_res_venus_theme_cache_init(NULL, 0);
#else /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */
        S32 cache_size;
        U8* cache_start = mmi_res_theme_dlt_mem_alloc_free(&cache_size);

        mmi_res_venus_theme_cache_init(cache_start, cache_size);
#endif /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */
    }
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_theme_check_is_valid
 * DESCRIPTION
 *  check whether the theme data is valid
 * PARAMETERS
 *  bs_handle   [IN] bytestream handle
 *  size        [OUT] size of verfication header
 *  is_skip     [IN] whehter to skip verification
 * RETURNS
 *  whether the data is valid theme or not
 *****************************************************************************/
static MMI_BOOL mmi_res_theme_check_is_valid(mmi_res_theme_bytestream_struct* bs_handle, S32* size, MMI_BOOL is_skip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THV", SA_start);
#endif

    *size = 0;
    do
    {
        S32 signature = 0;
        S32 ver_length = 0;
        U64 ver_value = 0;
        S32 theme_size = 0;
        U64 data_value = 0;
        S32 i;

        /* get signature */
        signature = (S32)mmi_res_theme_bytestream_get_dword(bs_handle);
        if (signature != MMI_RES_THEME_SIGNATURE)
        {
            ret = MMI_FALSE;
            break;
        }
        *size += 4;

        /* get verification length */
        ver_length = (S32)mmi_res_theme_bytestream_get_dword(bs_handle);
        *size += 4;

        /* get verification value */
        for (i = 0 ; i < ver_length ; i++)
        {
            ver_value |= ((U64)mmi_res_theme_bytestream_get_byte(bs_handle)) << (i * 8);
        }
        *size += ver_length;

        /* get verification value */
        theme_size = (S32)mmi_res_theme_bytestream_get_dword(bs_handle);
        *size += 4;

        /* verify */
        if (!is_skip)
        {
            U8 *temp = NULL;
            S32 temp_size = 2048;
            S32 left_size = theme_size;

            /* allocate memory */
            do
            {
                /* allocate all from ASM anonymous */
                temp_size = left_size;
                temp = mmi_frm_asm_alloc_anonymous(temp_size);
                if (temp)
                {
                    break;
                }

                /* allocate 200K from ASM anonymous */
                temp_size = 200 * 1024;
                temp = mmi_frm_asm_alloc_anonymous(temp_size);
                if (temp)
                {
                    break;
                }

                /* allocate 20K from ASM anonymous */
                temp_size = 20 * 1024;
                temp = mmi_frm_asm_alloc_anonymous(temp_size);
                if (temp)
                {
                    break;
                }

                /* allocate from control buffer */
                temp_size = 2048;
                temp = mmi_malloc(temp_size);
                if (temp)
                {
                    break;
                }
            } while (0);
            MMI_ASSERT(temp);

            while (left_size > 0)
            {
                S32 len = (left_size > temp_size) ? (temp_size) : (left_size);

                mmi_res_theme_bytestream_read(bs_handle, temp, len);
                for (i = 0 ; i < len ; i ++)
                {
                    data_value += (U64)temp[i];
                }

                left_size -= len;               
            }

            /* free memory */
            if (temp_size > 2048)
            {
                mmi_frm_asm_free_anonymous(temp);
            }
            else
            {
                mmi_mfree(temp);
            }        

            /* check check sum */
            data_value %= 0xFFFFFFFF;
            if ((data_value + ver_value) != 0xFFFFFFFF)
            {
                ret = MMI_FALSE;
                break;
            }

            mmi_res_theme_bytestream_seek_start(bs_handle, *size);
        }
    } while (0);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THV", SA_stop);
#endif

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_set_theme_int
 * DESCRIPTION
 *  set theme data
 * PARAMETERS
 *  bs_handle   [IN/OUT] byte stream handle
 *  theme       [OUT] theme structure to set
 * RETURNS
 *  mmi_res_theme_ret_enum
 *****************************************************************************/
static mmi_res_theme_ret_enum mmi_res_set_theme_int(mmi_res_theme_bytestream_struct* bs_handle, mmi_res_theme_struct* theme)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* dlt_mem_ptr = NULL;
    U8 num_of_res = 0;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read section table */
    for (i = 0 ; i < MMI_RES_THEME_SEC_END ; i++)
    {
        theme->section_table[i].addr = (S32)mmi_res_theme_bytestream_get_dword(bs_handle) + theme->ver_length;
        theme->section_table[i].size = (S32)mmi_res_theme_bytestream_get_dword(bs_handle);
    }

    /* read info */
    mmi_res_theme_bytestream_seek_start(bs_handle, theme->section_table[MMI_RES_THEME_SEC_INFO].addr);
    num_of_res = (U8)mmi_res_theme_bytestream_get_byte(bs_handle);

#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    /* load into memory, and check project, etc */
    if (theme->is_file || (!theme->is_file && theme->bin == NULL))
    {
        S32 mem_size = theme->section_table[MMI_RES_THEME_SEC_RES_TABLE].size +
                       theme->section_table[MMI_RES_THEME_SEC_STR_TABLE].size +
                       theme->section_table[MMI_RES_THEME_SEC_FONT].size;

        dlt_mem_ptr = mmi_res_theme_dlt_mem_alloc(mem_size);
        if (!dlt_mem_ptr)
        {
            return MMI_RES_THEME_BUF_NOT_ENOUGH;
        }
        theme->dlt_mem_ptr = dlt_mem_ptr;
    }
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */

    /* read resource table */
    mmi_res_theme_bytestream_seek_start(bs_handle, theme->section_table[MMI_RES_THEME_SEC_RES_TABLE].addr);

#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    if (theme->is_file || (!theme->is_file && theme->bin == NULL))
    {
        S32 size = theme->section_table[MMI_RES_THEME_SEC_RES_TABLE].size;
        mmi_res_theme_bytestream_struct temp_bs_handle;

        theme->section_table[MMI_RES_THEME_SEC_RES_TABLE].addr = (S32)dlt_mem_ptr;
        mmi_res_theme_bytestream_read(bs_handle, dlt_mem_ptr, size);
        dlt_mem_ptr += size;

#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
        temp_bs_handle.current_offset = 0;
#endif
        mmi_res_theme_bytestream_init_memory(&temp_bs_handle, (U8*)theme->section_table[MMI_RES_THEME_SEC_RES_TABLE].addr, size);
        for (i = 0 ; i < num_of_res ; i ++)
        {
            U8 type = (U8)mmi_res_theme_bytestream_get_byte(&temp_bs_handle);
            U16 num = (U16)mmi_res_theme_bytestream_get_word(&temp_bs_handle);
            U32 offset = (U32)mmi_res_theme_bytestream_get_dword(&temp_bs_handle);
            U8* addr = (U8*)theme->section_table[MMI_RES_THEME_SEC_RES_TABLE].addr + offset;
    
            if (type < MMI_RES_THEME_TYPE_MAX)
            {
                theme->res_num[type] = num;
                theme->res_table[type] = addr;
            }
        }
        mmi_res_theme_bytestream_close(&temp_bs_handle, MMI_FALSE);
    }
    else
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
    {
        for (i = 0 ; i < num_of_res ; i ++)
        {
            U8 type = (U8)mmi_res_theme_bytestream_get_byte(bs_handle);
            U16 num = (U16)mmi_res_theme_bytestream_get_word(bs_handle);
            U32 offset = (U32)mmi_res_theme_bytestream_get_dword(bs_handle);
            U8* addr = theme->bin + theme->section_table[MMI_RES_THEME_SEC_RES_TABLE].addr + offset;
    
            if (type < MMI_RES_THEME_TYPE_MAX)
            {
                theme->res_num[type] = num;
                theme->res_table[type] = addr;
            }
        }
    }

#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    /* copy string table */
    if (theme->is_file || (!theme->is_file && theme->bin == NULL))
    {
        S32 len = theme->section_table[MMI_RES_THEME_SEC_STR_TABLE].size;

        mmi_res_theme_bytestream_seek_start(bs_handle, theme->section_table[MMI_RES_THEME_SEC_STR_TABLE].addr);
        mmi_res_theme_bytestream_read(bs_handle, dlt_mem_ptr, len);
        theme->section_table[MMI_RES_THEME_SEC_STR_TABLE].addr = (S32)dlt_mem_ptr;
        dlt_mem_ptr += len;
    }
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */

    /* set string table */
    theme->string_table = theme->bin + theme->section_table[MMI_RES_THEME_SEC_STR_TABLE].addr;


#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    /* copy font table */
    if (theme->is_file || (!theme->is_file && theme->bin == NULL))
    {
        S32 len = theme->section_table[MMI_RES_THEME_SEC_FONT].size;

        mmi_res_theme_bytestream_seek_start(bs_handle, theme->section_table[MMI_RES_THEME_SEC_FONT].addr);
        mmi_res_theme_bytestream_read(bs_handle, dlt_mem_ptr, len);
        theme->section_table[MMI_RES_THEME_SEC_FONT].addr = (S32)dlt_mem_ptr;
        dlt_mem_ptr += len;
    }
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */

    return MMI_RES_THEME_RET_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_set_theme
 * DESCRIPTION
 *  set theme structure
 * PARAMETERS
 *  theme           [IN / OUT] theme structure
 * RETURNS
 *  whether set successfully
 *****************************************************************************/
static mmi_res_theme_ret_enum mmi_res_set_theme(mmi_res_theme_struct* theme)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_res_theme_bytestream_struct bs_handle;
    mmi_res_theme_ret_enum ret = MMI_RES_THEME_RET_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    /* init byte stream */
    if (theme->is_file)
    {
        if (!mmi_res_theme_bytestream_init_file_handle(&bs_handle, theme->fh))
        {
            return MMI_RES_THEME_RET_INVALID;
        }
    }
    else
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
    {
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)  
        if (theme->bin == NULL)
        {
            if (theme->is_pri_theme)
            {
                bs_handle.is_pri_theme = MMI_TRUE;
                bs_handle.theme_offset = g_mmi_res_app_icon_attr_array[theme->index].offset;
                bs_handle.theme_length = g_mmi_res_app_icon_attr_array[theme->index].length;  
            }
            else
            {
               bs_handle.is_pri_theme = MMI_FALSE;
               bs_handle.theme_offset = g_mmi_res_thm_attr_array[theme->index].offset;
               bs_handle.theme_length = g_mmi_res_thm_attr_array[theme->index].length;
            }
            bs_handle.current_offset = bs_handle.theme_offset;
        }
#endif
        mmi_res_theme_bytestream_init_memory(&bs_handle, theme->bin, -1);
    }

    do
    {
        S32 data_length = 0;

        /* verify theme first */
        if (!mmi_res_theme_check_is_valid(&bs_handle, &data_length, MMI_TRUE))
        {
            break;
        }
        theme->ver_length = data_length;

        /* read theme header info */
        ret = mmi_res_set_theme_int(&bs_handle, theme);
    } while (0);

    /* close byte stream */
    mmi_res_theme_bytestream_close(&bs_handle, MMI_TRUE);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_close_theme
 * DESCRIPTION
 *  close theme structure
 * PARAMETERS
 *  theme           [IN / OUT] theme structure
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_res_close_theme(mmi_res_theme_struct* theme)
{
#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    if (theme->dlt_mem_ptr)
    {
        mmi_res_theme_dlt_mem_free(theme->dlt_mem_ptr);
    }

    if (theme->fh >= FS_NO_ERROR)
    {
        FS_Close(theme->fh);
    }
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */

    memset(theme, 0, sizeof(mmi_res_theme_struct));
    theme->fh = -1;
}

#if defined(__MMI_PLUTO_SUPPORT_COSMOS_ACO__) && defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__)
typedef struct
{	U8 hash_value;
	const U8* pluto_str;
    const U8* cosmos_str;
} mmi_res_thm_id_convert_str_tbl_struct;
MMI_BOOL g_aco_check_flag = MMI_FALSE;
static const mmi_res_thm_id_convert_str_tbl_struct g_mmi_res_thm_img_id_convert_str_tbl_ext[] =
{
  {48, "IMG_ID_APPLIST_ALARM_ICON", "IMG_ID_VAPP_ALARM"},
#if defined(__MMI_AUDIO_PLAYER__)  
	{195, "IMG_ID_APPLIST_APLY_ICON", "IMG_ID_VAPP_MUSICPLY_ICON"},
#endif
#ifdef __MMI_AZAAN_ALARM__	
	{48, "IMG_ID_APPLIST_AALARM_ICON", "IMG_ID_VAPP_ALARM"},
#endif
#if defined(__MMI_CALCULATOR__)	
	{83, "IMG_ID_APPLIST_CALCULATOR_ICON", "IMG_ID_VAPP_CALCULATOR_MAIN_MENU_ICON"},
#endif
#if defined(__MMI_CALENDAR__)	
	{253, "IMG_ID_APPLIST_CALENDAR_ICON", "IMG_ID_VAPP_CALENDAR"},
#endif	
	{3, "IMG_ID_APPLIST_CLOG_ICON", "IMG_ID_VAPP_CLOG_MAIN_MENU"},
#if defined(__MMI_CAMCORDER__)	
	{9, "IMG_ID_APPLIST_CAMCORDER_ICON", "MAIN_MENU_CAMCO_ICON"},
#endif	
#if defined (__MMI_CAMERA__)
	{9, "IMG_ID_APPLIST_CAMERA_ICON", "MAIN_MENU_CAMCO_ICON"},
#endif		
	{116, "IMG_ID_APPLIST_DIALER_ICON", "IMG_ID_VAPP_DIALER"},
	{171, "IMG_ID_APPLIST_EMAIL_ICON", "IMG_EMAIL_FTO_MAINMENU"},
	{228, "IMG_ID_APPLIST_FMGR_ICON", "IMG_ID_VAPP_FMGR_MAINMENU_ICN"},
#ifdef __MMI_FM_RADIO__	
	{85, "IMG_ID_APPLIST_FMRDO_ICON", "IMG_ID_VAPP_FM"},
#endif	
	{158, "IMG_ID_APPLIST_IVIEWER_ICON", "IMG_ID_VAPP_GALLERY_APP_ICON"},
	{3,   "IMG_ID_APPLIST_JAVA_ICON", "IMG_ID_VAPP_LAUNCHER_ROBOT_MM_ICON_JAVA"},
	{195, "IMG_ID_APPLIST_MPLYER_ICON", "IMG_ID_VAPP_MUSICPLY_ICON"},
	{47,  "IMG_ID_APPLIST_MESSAGE_ICON", "IMG_ID_VAPP_MSG_MAIN"},
#if defined(__MMI_ATV_SUPPORT__)	
	{144, "IMG_ID_APPLIST_MTV_ICON", "MAIN_MENU_ATV_ICON"},
#endif
#ifdef __MMI_NOTE_APP__	
	{103, "IMG_ID_APPLIST_NOTE_ICON", "IMG_ID_VAPP_NOTES_MAIN_MENU"},
#endif	
	{207, "IMG_ID_APPLIST_PHB_ICON", "IMG_ID_VAPP_CONTACT"},
#ifdef __SYNCML_SUPPORT__	
	{0, "IMG_ID_APPLIST_SYNC_ICON", "IMG_ID_VAPP_SYNC"},
#endif	
	{110, "IMG_ID_APPLIST_SETTING_ICON", "IMG_ID_APP_SETTING_TITLE"},
	{170, "IMG_ID_APPLIST_SERVICE_ICON", "IMG_ID_VAPP_SAT"},
	{0, "IMG_ID_APPLIST_BARREL_ICON", NULL},
	{130, "IMG_ID_APPLIST_RECORDER_ICON", "IMG_ID_VAPP_SNDREC"},
#if defined(__MMI_TODOLIST__)	
	{245, "IMG_ID_APPLIST_TODO_ICON", "IMG_ID_VAPP_TASK"},
#endif	
#if defined(__MMI_UNIT_CONVERTER__)
	{124, "IMG_ID_APPLIST_UCONVERTER_ICON", "IMG_ID_VAPP_CONVERTER"},
#endif		
	{16, "IMG_ID_APPLIST_WIFI_ICON", "IMG_ID_VAPP_WLAN_MAIN_MENU"},
#ifdef __MMI_BROWSER_2__	
	{188, "IMG_ID_APPLIST_BROWSER_ICON", "IMG_ID_VAPP_BRW_BROWSER_ICON"},
#endif	
#if defined (__MMI_WORLD_CLOCK__)
	{184, "IMG_ID_APPLIST_WCLOCK_ICON", "IMG_ID_VAPP_WORLDCLOCK"},
#endif	
#ifdef __SOCIAL_NETWORK_SUPPORT__
	{172, "IMG_ID_APPLIST_SNS_ICON", "IMG_ID_VAPP_SNS_MAINMENU_ICN"},
#endif	
	{227, "IMG_ID_APPLIST_OPERA_ICON", "IMG_ID_APP_OPERA"},
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
	{110, "IMG_ID_APPLIST_SETTINGMSG_ICON", "IMG_ID_APP_SETTING_TITLE"},
#endif
    {56, "IMG_ID_APP_LIST_THEME_WALLPAPER_0", "IMG_ID_THEME_WALLPAPER_0"},
    {NULL}
};
#endif/*defined(__MMI_PLUTO_SUPPORT_COSMOS_ACO__) && defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__)*/

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_theme_data_int
 * DESCRIPTION
 *  get one theme item data from the whole theme binary data
 * PARAMETERS
 *  id                  [IN] resource ID
 *  number_of_all_ids   [IN] number of IDs of the resource type
 *  id_str_tbl          [IN] resource ID and string mapping table
 *  res_tyle            [IN] resource type
 *  theme               [IN] theme structure
 *  data                [OUT] output data
 *  size                [OUT] data size
 * RETURNS
 *  whether get theme resource successfully
 *****************************************************************************/
static MMI_BOOL mmi_res_get_theme_data_int(
    U16 id,
    S32 number_of_all_ids,
    mmi_res_thm_id_str_tbl_struct *id_str_tbl,
    mmi_res_theme_type_enum res_type,
    mmi_res_theme_struct* theme,
    S32* data,
    S32* size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx, idx_first, idx_mid, idx_last;
    U8* id_str = 0;
    U8 hash_value = 0;
    U8* res_table_p = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *data = 0;

    /* find ID string */
    idx = -1;
    idx_first = 0;
    idx_last = number_of_all_ids - 1;
    while (idx_last >= idx_first)
    {
        U16 mid_id;

        idx_mid = (idx_first + idx_last) / 2;
        mid_id = id_str_tbl[idx_mid].id;
        
        if (mid_id == id)
        {
            idx = idx_mid;
            id_str = (U8*)(id_str_tbl[idx].str);
            hash_value = id_str_tbl[idx].hash_value;
            break;
        }
        else if (mid_id > id)
        {
            idx_last = idx_mid - 1;
        }
        else if (mid_id < id)
        {
            idx_first = idx_mid + 1;
        }
    }
    if (idx == -1)
    {
        return MMI_FALSE;
    }
#if defined(__MMI_PLUTO_SUPPORT_COSMOS_ACO__) && defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__)
RETRY:
      if(g_aco_check_flag)
        {
          idx = 0;
          while(g_mmi_res_thm_img_id_convert_str_tbl_ext[idx].pluto_str != NULL)
             {
              if(strncmp((const CHAR*)g_mmi_res_thm_img_id_convert_str_tbl_ext[idx].pluto_str, (const CHAR*)id_str, MMI_RES_THEME_MAX_STR_ID_LENGTH) == 0)
                {
                  hash_value = (U8)g_mmi_res_thm_img_id_convert_str_tbl_ext[idx].hash_value;
                  id_str = (U8 *)g_mmi_res_thm_img_id_convert_str_tbl_ext[idx].cosmos_str;
                  break;
                }
              else
                {
                  idx++;
                }
             }
           if(g_mmi_res_thm_img_id_convert_str_tbl_ext[idx].pluto_str == NULL || g_mmi_res_thm_img_id_convert_str_tbl_ext[idx].cosmos_str == NULL)
            {
          g_aco_check_flag = MMI_FALSE;
              return MMI_FALSE;
            }
        } 
#endif/*defined(__MMI_PLUTO_SUPPORT_COSMOS_ACO__) && defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__)*/

    /* find string in theme by hash value */
    idx = -1;
    idx_first = 0;
    idx_last = theme->res_num[res_type] - 1;
    res_table_p = theme->res_table[res_type];
    while (idx_last >= idx_first)
    {
        U8 mid_value;

        idx_mid = (idx_first + idx_last) / 2;
        mid_value = *(res_table_p + idx_mid * MMI_RES_THEME_RES_TBL_SIZE);
        
        if (mid_value == hash_value)
        {
            idx = idx_mid;
            break;
        }
        else if (mid_value > hash_value)
        {
            idx_last = idx_mid - 1;
        }
        else if (mid_value < hash_value)
        {
            idx_first = idx_mid + 1;
        }
    }
    if (idx == -1)
    {
#if defined(__MMI_PLUTO_SUPPORT_COSMOS_ACO__) && defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__)    
      if(g_aco_check_flag == MMI_TRUE)
        {
          g_aco_check_flag = MMI_FALSE;
          return MMI_FALSE;
        }
      else
        {
          g_aco_check_flag = MMI_TRUE;
          goto RETRY;
         }
#else
      return MMI_FALSE;
#endif
    }
    else 
    {
        S32 i = idx - 1;
        MMI_BOOL ret = MMI_FALSE;
        S32 count = 0;

        /* calculate the start postion for the same hash value */
        while (i >= 0)
        {
            if (*(res_table_p + i * MMI_RES_THEME_RES_TBL_SIZE) != hash_value)
            {
                idx = i + 1;
                break;
            }
            i --;
        }

        /* calculate the count for the same hash value */
        for (i = idx ; i < theme->res_num[res_type] ; i++)
        {
            count ++;
            if (*(res_table_p + i * MMI_RES_THEME_RES_TBL_SIZE) != hash_value)
            {
                break;
            }
        }

        for (i = idx ; i < idx + count ; i++)
        {
            mmi_res_theme_bytestream_struct temp_bs;
            U8* res_table_item_p =  res_table_p + i * MMI_RES_THEME_RES_TBL_SIZE;
            U8* theme_id_string;

#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
            temp_bs.current_offset = 0;
#endif
            mmi_res_theme_bytestream_init_memory(&temp_bs, res_table_item_p, MMI_RES_THEME_RES_TBL_SIZE);

            mmi_res_theme_bytestream_get_byte(&temp_bs);    /* skip hash value */
            theme_id_string = theme->string_table + mmi_res_theme_bytestream_get_dword(&temp_bs);
            if (strncmp((const CHAR*)theme_id_string, (const CHAR*)id_str, MMI_RES_THEME_MAX_STR_ID_LENGTH) == 0)
            {
                *data = (S32)mmi_res_theme_bytestream_get_dword(&temp_bs);
                *size = (S32)mmi_res_theme_bytestream_get_dword(&temp_bs);
                ret = MMI_TRUE;
            }

            mmi_res_theme_bytestream_close(&temp_bs, MMI_FALSE);

            if (ret)
            {
                break;
            }
        }
#if defined(__MMI_PLUTO_SUPPORT_COSMOS_ACO__) && defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__)        
        if(!ret && !g_aco_check_flag)
          {
            g_aco_check_flag = MMI_TRUE;
            goto RETRY;
          }
#endif  
#if defined(__MMI_PLUTO_SUPPORT_COSMOS_ACO__) && defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__) 
            g_aco_check_flag = MMI_FALSE;
#endif
        return ret;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_theme_data
 * DESCRIPTION
 *  get one theme item data from the whole theme binary data
 * PARAMETERS
 *  id                  [IN] resource ID
 *  number_of_all_ids   [IN] number of IDs of the resource type
 *  id_str_tbl          [IN] resource ID and string mapping table
 *  res_tyle            [IN] resource type
 * RETURNS
 *  theme item data
 *****************************************************************************/
static S32 mmi_res_get_theme_data(
    U16 id,
    S32 number_of_all_ids,
    mmi_res_thm_id_str_tbl_struct *id_str_tbl,
    mmi_res_theme_type_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    S32 data = 0;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < MMI_RES_THEME_MAX_CONCURRENT ; i++)
    {
        S32 idx = g_mmi_res_theme_priority_list[i];

        if (idx != MMI_RES_THEME_PRIORITY_EMPTY)
        {
            mmi_res_theme_struct* theme = &g_mmi_res_theme[idx].theme;
            S32 size;

#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("TGD", SA_start);
#endif

            ret = mmi_res_get_theme_data_int(id, number_of_all_ids, id_str_tbl, res_type, theme, &data, &size);

#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("TGD", SA_stop);
#endif

            if (ret)
            {
                break;
            }
        }
    }

    return data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_theme_data_addr
 * DESCRIPTION
 *  get one theme item data in address type (offset from the beginning)
 *  from the whole theme binary data
 * PARAMETERS
 *  id                  [IN] resource ID
 *  number_of_all_ids   [IN] number of IDs of the resource type
 *  id_str_tbl          [IN] resource ID and string mapping table
 *  res_tyle            [IN] resource type
 *  sec                 [IN] resource section
 *  related_theme       [OUT] theme structure for this address
 *  size                [OUT] size of the data
 * RETURNS
 *  address of the theme item data
 *****************************************************************************/
U8* mmi_res_get_theme_data_addr(
    U16 id,
    S32 number_of_all_ids,
    mmi_res_thm_id_str_tbl_struct *id_str_tbl,
    mmi_res_theme_type_enum res_type,
    mmi_res_theme_sec_enum sec,
    mmi_res_theme_struct **related_theme,
    S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    U8* ptr = NULL;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < MMI_RES_THEME_MAX_CONCURRENT ; i++)
    {
        S32 idx = g_mmi_res_theme_priority_list[i];

        if (idx != MMI_RES_THEME_PRIORITY_EMPTY)
        {
            mmi_res_theme_struct* theme = &g_mmi_res_theme[idx].theme;
            S32 offset = 0;

#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("TGA", SA_start);
#endif
            ret = mmi_res_get_theme_data_int(id, number_of_all_ids, id_str_tbl, res_type, theme, &offset, size);

#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("TGA", SA_stop);
#endif

            if (ret)
            {
                ptr = (offset != MMI_RES_THEME_INVALID_ADDR) ? ((U8*)(theme->bin + theme->section_table[sec].addr + offset)) : (NULL);
                *related_theme = theme;
                break;
            }
        }
    }

    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_sys_theme_section
 * DESCRIPTION
 *  get one section from system theme
 * PARAMETERS
 *  theme        [IN] data of the theme
 *  section     [IN] section
 * RETURNS
 *  pointer to the address of the section
 *****************************************************************************/
static S8* mmi_res_get_theme_section(U8* theme, mmi_res_theme_sec_enum section)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8* ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_res_theme_bytestream_struct bs_handle;

    mmi_res_theme_bytestream_init_memory(&bs_handle, theme, -1);
    do
    {
        S32 data_length = 0, i;

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TSS", SA_start);
#endif

        /* verify theme */
        if (!mmi_res_theme_check_is_valid(&bs_handle, &data_length, MMI_TRUE))
        {
            break;
        }

        /* read section table */
        for (i = 0 ; i < MMI_RES_THEME_SEC_END ; i++)
        {
            S32 addr = (S32)mmi_res_theme_bytestream_get_dword(&bs_handle) + data_length;
            S32 size = (S32)mmi_res_theme_bytestream_get_dword(&bs_handle);

            if (i == section)
            {
                if (size != 0)
                {
                    ptr = (S8*)theme + addr;
                }
                break;
            }
        }

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TSS", SA_stop);
#endif

    } while (0);
    mmi_res_theme_bytestream_close(&bs_handle, MMI_FALSE);

    return ptr;
}


#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_dlt_theme_section
 * DESCRIPTION
 *  get one section from DLT theme
 * PARAMETERS
 *  filename    [IN] filename
 *  buf         [OUT] buffer to store section data
 *  buf_length  [IN] buffer length
 *  section     [IN] section
 * RETURNS
 *  mmi_res_theme_ret_enum
 *****************************************************************************/
static mmi_res_theme_ret_enum mmi_res_get_dlt_theme_section(const WCHAR* filename, S8* buf, S32 buf_length, mmi_res_theme_sec_enum section)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_res_theme_ret_enum ret = MMI_RES_THEME_RET_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_res_theme_bytestream_struct bs_handle;

    if (!mmi_res_theme_bytestream_init_file(&bs_handle, filename))
    {
        return ret;
    }

    do
    {
        S32 data_length = 0, i;

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TSD", SA_start);
#endif

        /* verify theme */
        if (!mmi_res_theme_check_is_valid(&bs_handle, &data_length, MMI_TRUE))
        {
            ret = MMI_RES_THEME_RET_INVALID;
            break;
        }

        /* read section table */
        for (i = 0 ; i < MMI_RES_THEME_SEC_END ; i++)
        {
            S32 addr = (S32)mmi_res_theme_bytestream_get_dword(&bs_handle) + data_length;
            S32 size = (S32)mmi_res_theme_bytestream_get_dword(&bs_handle);

            if (i == section)
            {
                if (size != 0)
                {
                    if (buf_length < size)
                    {
                        ret = MMI_RES_THEME_BUF_NOT_ENOUGH;
                        break;
                    }

                    mmi_res_theme_bytestream_seek_start(&bs_handle, addr);
                    mmi_res_theme_bytestream_read(&bs_handle, (U8*)buf, size);
                    ret = MMI_RES_THEME_RET_NO_ERROR;
                }
                break;
            }
        }

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TSD", SA_stop);
#endif

    } while (0);
    mmi_res_theme_bytestream_close(&bs_handle, MMI_FALSE);

    return ret;
}
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */


#endif /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__) */


/*****************************************************************************
 * Global funcion
 *****************************************************************************/

/* For detail description, please refer to CustVenusThemeRes.h */
void mmi_res_init_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
    mmi_res_theme_ret_enum ret = MMI_RES_THEME_RET_INVALID;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)
    S32 i;

    for (i = 0 ; i < MMI_RES_THEME_MAX_CONCURRENT ; i++)
    {
        g_mmi_res_theme_priority_list[i] = MMI_RES_THEME_PRIORITY_EMPTY;
        g_mmi_res_theme[i].priority = MMI_RES_THEME_PRIORITY_EMPTY;
    }

#if defined(__COSMOS_MMI_PACKAGE__)
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
    g_mmi_res_theme[0].theme.bin = NULL;
    g_mmi_res_theme[0].theme.index = 0;
    g_mmi_res_theme[0].theme.is_pri_theme = MMI_FALSE;
#else
    g_mmi_res_theme[0].theme.bin = (U8*)g_mmi_res_theme_system_data_ptr->data_array_ptr[0];
#endif /* defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__) */
#elif defined(__MMI_APP_ICON_FW_SUPPORT__)
    g_mmi_res_theme[0].theme.bin = (U8*)g_mmi_res_app_icon_data.data_array_ptr[0];
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    g_mmi_res_theme[0].theme.is_file = MMI_FALSE;
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
    g_mmi_res_theme[0].priority = MMI_RES_THEME_PRIORITY_DEFAULT;
    g_mmi_res_theme_priority_list[0] = 0;

#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    mmi_res_theme_dlt_mem_reset();
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */

#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
    ret = mmi_res_set_theme(&g_mmi_res_theme[0].theme);
    if (ret >= 0)
    {
        mmi_res_theme_sort_priority_list();
    }
#else
    mmi_res_set_theme(&g_mmi_res_theme[0].theme);
#endif

#if defined(__MMI_RES_THEME_CACHE_FROM_ASM__)
    mmi_res_theme_cache_asm_init();
#endif /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */

#endif /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
S32 mmi_res_get_theme_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
    S32 count = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__)
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
    count = MMI_VENUS_THEME_TOTAL_COUNT;
    return count;
#else
    return g_mmi_res_theme_system_data_ptr->number;
#endif
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    return 0;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
MMI_BOOL mmi_res_set_system_theme(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__)
    mmi_res_theme_ret_enum ret = MMI_RES_THEME_RET_INVALID;

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THS", SA_start);
#endif

    if (index > 0 && index < mmi_res_get_theme_count())
    {
        S32 idx = mmi_res_theme_find_1st_priority_slot(MMI_RES_THEME_PRIORITY_CURRENT);

        if (idx != -1)
        {
            mmi_res_close_theme(&g_mmi_res_theme[idx].theme);
        }
        else
        {
            idx = mmi_res_theme_find_1st_priority_slot(MMI_RES_THEME_PRIORITY_EMPTY);
        }

        if (idx > 0)
        {
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
            g_mmi_res_theme[idx].theme.bin = NULL;
            g_mmi_res_theme[idx].theme.index = index;
            g_mmi_res_theme[idx].theme.is_pri_theme = MMI_FALSE;
#else
            g_mmi_res_theme[idx].theme.bin = (U8*)g_mmi_res_theme_system_data_ptr->data_array_ptr[index];
#endif
#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
            g_mmi_res_theme[idx].theme.is_file = MMI_FALSE;
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
            ret = mmi_res_set_theme(&g_mmi_res_theme[idx].theme);
            if (ret >= 0)
            {
                g_mmi_res_theme[idx].priority = MMI_RES_THEME_PRIORITY_CURRENT;
            }
        }
    }
    else
    {   /* use default theme directly */
        S32 idx = mmi_res_theme_find_1st_priority_slot(MMI_RES_THEME_PRIORITY_CURRENT);

        if (idx > 0)
        {
            mmi_res_close_theme(&g_mmi_res_theme[idx].theme);
            g_mmi_res_theme[idx].priority = MMI_RES_THEME_PRIORITY_EMPTY;
        }
        ret = MMI_RES_THEME_RET_NO_ERROR;
    }

    if (ret >= 0)
    {
        mmi_res_theme_sort_priority_list();
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THS", SA_stop);
#endif

    return (ret >= 0) ? (MMI_TRUE) : (MMI_FALSE);
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    return MMI_FALSE;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
mmi_res_theme_ret_enum mmi_res_set_priority_theme (U8 index, U8 priority, mmi_res_theme_handle *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_res_theme_ret_enum ret = MMI_RES_THEME_RET_INVALID;
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)
    U8 *data = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)
    S32 idx = mmi_res_theme_find_1st_priority_slot(MMI_RES_THEME_PRIORITY_EMPTY);

#ifndef __MMI_RES_THEME_THIRD_ROM_SUPPORT__
    data = mmi_res_get_app_icon_data(index);
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THP", SA_start);
#endif

    if (idx > 0)
    {
        if (data)
        {
            g_mmi_res_theme[idx].theme.bin = data;
            g_mmi_res_theme[idx].theme.is_file = MMI_FALSE;

            ret = mmi_res_set_theme(&g_mmi_res_theme[idx].theme);

            if (ret >= 0)
            {
                *handle = (mmi_res_theme_handle)idx;
                g_mmi_res_theme[idx].priority = priority;
                mmi_res_theme_sort_priority_list();
            }
        }
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
        else
        {
            g_mmi_res_theme[idx].theme.bin = data;
            g_mmi_res_theme[idx].theme.index = index;
            g_mmi_res_theme[idx].theme.is_pri_theme = MMI_TRUE;
            g_mmi_res_theme[idx].theme.is_file = MMI_FALSE;

            ret = mmi_res_set_theme(&g_mmi_res_theme[idx].theme);

            if (ret >= 0)
            {
                *handle = (mmi_res_theme_handle)idx;
                g_mmi_res_theme[idx].priority = priority;
                mmi_res_theme_sort_priority_list();
            }
        }
#endif /* defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__) */       
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THP", SA_stop);
#endif

    return ret;

#else /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__) */
    return ret;
#endif /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
mmi_res_theme_ret_enum mmi_res_is_dlt_theme_valid (const WCHAR* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_res_theme_ret_enum ret = MMI_RES_THEME_RET_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    mmi_res_theme_bytestream_struct bs_handle;

    if (!mmi_res_theme_bytestream_init_file(&bs_handle, filename))
    {
        return ret;
    }

    do
    {
        S32 data_length = 0, start = 0, i;
        CHAR *str = NULL;
        U8 len = 0;
        U16 width = 0, height = 0;

        /* verify theme first */
        if (!mmi_res_theme_check_is_valid(&bs_handle, &data_length, MMI_FALSE))
        {
            break;
        }

        /* read section table */
        for (i = 0 ; i < MMI_RES_THEME_SEC_END ; i++)
        {
            S32 addr = mmi_res_theme_bytestream_get_dword(&bs_handle) + data_length;
            S32 size = mmi_res_theme_bytestream_get_dword(&bs_handle);

            if (i == MMI_RES_THEME_SEC_INFO)
            {
                start = addr;
            }
        }

        mmi_res_theme_bytestream_seek_start(&bs_handle, start);

        /* skip number of resource */
        mmi_res_theme_bytestream_get_byte(&bs_handle);

        ret = MMI_RES_THEME_RET_NO_ERROR;
        str = mmi_malloc(256);
        do
        {
            /* check project */
            len = (U8)mmi_res_theme_bytestream_get_byte(&bs_handle);
            mmi_res_theme_bytestream_read(&bs_handle, (U8*)str, len);
            if (strncmp(BUILD_BRANCH_STR, (const char *)str, strlen(BUILD_BRANCH_STR)) != 0)
            {
                ret = MMI_RES_THEME_RET_PROJECT_NOT_MATCH;
                break;
            }

            /* check version */
            len = (U8)mmi_res_theme_bytestream_get_byte(&bs_handle);
            mmi_res_theme_bytestream_read(&bs_handle, (U8*)str, len);
            if (strncmp(VERNO_STR, (const char *)str, strlen(VERNO_STR)) != 0)
            {
                ret = MMI_RES_THEME_RET_VERSION_NOT_MATCH;
                break;
            }

            /* check lcd */
            width = (U16)mmi_res_theme_bytestream_get_word(&bs_handle);
            height = (U16)mmi_res_theme_bytestream_get_word(&bs_handle);
            if ((width != LCD_WIDTH) || (height != LCD_HEIGHT))
            {
                ret = MMI_RES_THEME_RET_RESOLUTION_NOT_MATCH;
                break;
            }
        } while (0);
        mmi_mfree(str);

    } while (0);

    mmi_res_theme_bytestream_close(&bs_handle, MMI_FALSE);

    return ret;

#else /* (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
    return ret;
#endif /* (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
mmi_res_theme_ret_enum mmi_res_set_dlt_theme (const WCHAR* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_res_theme_ret_enum ret = MMI_RES_THEME_RET_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    S32 idx = mmi_res_theme_find_1st_priority_slot(MMI_RES_THEME_PRIORITY_CURRENT);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THD", SA_start);
#endif

    if (idx != -1)
    {
        mmi_res_close_theme(&g_mmi_res_theme[idx].theme);
    }
    else
    {
        idx = mmi_res_theme_find_1st_priority_slot(MMI_RES_THEME_PRIORITY_EMPTY);
    }

    if (idx > 0)
    {
        if ((g_mmi_res_theme[idx].theme.fh = FS_Open(filename, FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            /* set seek hint */
            FS_SetSeekHintEx(g_mmi_res_theme[idx].theme.fh, MMI_RES_THEME_FILE_HINT_CNT, 0, (void*)g_mmi_res_theme_file_hint, MMI_RES_THEME_FILE_HINT_SIZE);

            g_mmi_res_theme[idx].theme.is_file = MMI_TRUE;
            g_mmi_res_theme[idx].theme.bin = NULL;

            ret = mmi_res_set_theme(&g_mmi_res_theme[idx].theme);

            if (ret >= 0)
            {
                g_mmi_res_theme[idx].priority = MMI_RES_THEME_PRIORITY_CURRENT;
                mmi_res_theme_sort_priority_list();
            }
        }
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THD", SA_stop);
#endif

    return ret;

#else /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)*/
    return ret;
#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)*/
}


/* For detail description, please refer to CustVenusThemeRes.h */
mmi_res_theme_ret_enum mmi_res_set_dlt_priority_theme (const WCHAR* filename, U8 priority, mmi_res_theme_handle *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_res_theme_ret_enum ret = MMI_RES_THEME_RET_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    S32 idx = mmi_res_theme_find_1st_priority_slot(MMI_RES_THEME_PRIORITY_EMPTY);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THD", SA_start);
#endif

    if (idx > 0)
    {
        if ((g_mmi_res_theme[idx].theme.fh = FS_Open(filename, FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            g_mmi_res_theme[idx].theme.is_file = MMI_TRUE;
            g_mmi_res_theme[idx].theme.bin = NULL;

            ret = mmi_res_set_theme(&g_mmi_res_theme[idx].theme);

            if (ret >= 0)
            {
                *handle = (mmi_res_theme_handle)idx;
                g_mmi_res_theme[idx].priority = priority;
                mmi_res_theme_sort_priority_list();
            }
        }
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THD", SA_stop);
#endif

    return ret;

#else /* (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
    return ret;
#endif /* (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
S32 mmi_res_get_app_icon_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
    S32 count = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
    count = MMI_VENUS_APP_ICON_TOTAL_COUNT;
    return count;
#else
    return g_mmi_res_app_icon_data.number;
#endif
#else /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__) */
    return 0;
#endif /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
U8* mmi_res_get_app_icon_data(S32 index)
{
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)
    if (index >= 0 && index < mmi_res_get_app_icon_count())
    {
        return g_mmi_res_app_icon_data.data_array_ptr[index];
    }
    else
#endif /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__) */
    {
        return NULL;
    }
}


/* For detail description, please refer to CustVenusThemeRes.h */
void mmi_res_close_curr_theme (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__)
    S32 idx = mmi_res_theme_find_1st_priority_slot(MMI_RES_THEME_PRIORITY_CURRENT);

    if (idx != -1)
    {
        mmi_res_close_theme(&g_mmi_res_theme[idx].theme);
        g_mmi_res_theme[idx].priority = MMI_RES_THEME_PRIORITY_EMPTY;
        mmi_res_theme_sort_priority_list();
    }
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
void mmi_res_close_priority_theme(mmi_res_theme_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)
    S32 idx = (S32)handle;

    if (idx != -1)
    {
        mmi_res_close_theme(&g_mmi_res_theme[idx].theme);
        g_mmi_res_theme[idx].priority = MMI_RES_THEME_PRIORITY_EMPTY;
        mmi_res_theme_sort_priority_list();
    }
#endif /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
MMI_BOOL mmi_res_set_otf_theme(void)
{
#if defined(__COSMOS_MMI_PACKAGE__) && !defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern S8* mmi_res_otf_get_theme(void);
    S8* otf_theme = mmi_res_otf_get_theme();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (otf_theme)
    {
        S32 idx = mmi_res_theme_find_1st_priority_slot(MMI_RES_THEME_PRIORITY_CURRENT);
        
        if (idx != -1)
        {
            mmi_res_close_theme(&g_mmi_res_theme[idx].theme);
        }
        else
        {
            idx = mmi_res_theme_find_1st_priority_slot(MMI_RES_THEME_PRIORITY_EMPTY);
        }

        if (idx)
        {
            mmi_res_theme_ret_enum ret = MMI_RES_THEME_RET_INVALID;

#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
            g_mmi_res_theme[idx].theme.is_file = MMI_FALSE;
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
            g_mmi_res_theme[idx].theme.bin = otf_theme;
            ret = mmi_res_set_theme(&g_mmi_res_theme[idx].theme);
            if (ret >= 0)
            {
                g_mmi_res_theme[idx].priority = MMI_RES_THEME_PRIORITY_CURRENT;
                mmi_res_theme_sort_priority_list();
            }
            return (ret >= 0) ? (MMI_TRUE) : (MMI_FALSE);
        }
    }
    return MMI_FALSE;
#else /* defined(__COSMOS_MMI_PACKAGE__) && !defined(__MTK_TARGET__) */

    return MMI_FALSE;

#endif /* defined(__COSMOS_MMI_PACKAGE__) && !defined(__MTK_TARGET__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
MMI_BOOL mmi_res_is_theme_image(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__)
    mmi_res_theme_struct *theme;
    S32 size;

    if (mmi_res_get_theme_data_addr(id, MMI_RES_THM_ALL_IMG_IDS, (mmi_res_thm_id_str_tbl_struct*)g_mmi_res_thm_img_id_str_tbl, MMI_RES_THEME_TYPE_IMAGE, MMI_RES_THEME_SEC_IMG, &theme, &size))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
    
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    return MMI_FALSE;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */

}


/* For detail description, please refer to CustVenusThemeRes.h */
S8* mmi_res_get_theme_image(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)

#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    return (S8*)mmi_res_venus_theme_cache_get(id);
#else /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
    mmi_res_theme_struct *theme;
    S32 size;

    return (S8*)mmi_res_get_theme_data_addr(id, MMI_RES_THM_ALL_IMG_IDS, (mmi_res_thm_id_str_tbl_struct*)g_mmi_res_thm_img_id_str_tbl, MMI_RES_THEME_TYPE_IMAGE, MMI_RES_THEME_SEC_IMG, &theme, &size);
#endif
    
#else /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__) */
    return NULL;
#endif /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
S32 mmi_res_get_theme_color(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__)
    return (S32)mmi_res_get_theme_data(id, MMI_RES_THM_ALL_COL_IDS, (mmi_res_thm_id_str_tbl_struct*)g_mmi_res_thm_col_id_str_tbl, MMI_RES_THEME_TYPE_COLOR);
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    return 0;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
 mmi_res_theme_font_style_struct mmi_res_get_theme_font_style(U16 id)
{
#if defined(__COSMOS_MMI_PACKAGE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* data;
    mmi_res_theme_font_style_struct font = {0};
    mmi_res_theme_struct *theme;
    S32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (U8*)mmi_res_get_theme_data_addr(id, MMI_RES_THM_ALL_FNT_IDS, (mmi_res_thm_id_str_tbl_struct*)g_mmi_res_thm_fnt_id_str_tbl, MMI_RES_THEME_TYPE_FONT, MMI_RES_THEME_SEC_FONT, &theme, &size);

    font.size = data[0];
    font.attribute = data[1];
    font.effect = data[2];

    return font;
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    mmi_res_theme_font_style_struct font = {0};
    return font;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
S32 mmi_res_get_theme_integer(U16 id)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__)
    return (S32)mmi_res_get_theme_data(id, MMI_RES_THM_ALL_INT_IDS, (mmi_res_thm_id_str_tbl_struct*)g_mmi_res_thm_int_id_str_tbl, MMI_RES_THEME_TYPE_INTEGER);
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    return 0;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
S8* mmi_res_get_theme_audio(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__)
    mmi_res_theme_struct *theme;
    S32 size;

    return (S8*)mmi_res_get_theme_data_addr(id, MMI_RES_THM_ALL_ADO_IDS, (mmi_res_thm_id_str_tbl_struct*)g_mmi_res_thm_ado_id_str_tbl, MMI_RES_THEME_TYPE_AUDIO, MMI_RES_THEME_SEC_ADO, &theme, &size);
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    return NULL;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
S8* mmi_res_get_theme_binary(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__)
    mmi_res_theme_struct *theme;
    S32 size;

    return (S8*)mmi_res_get_theme_data_addr(id, MMI_RES_THM_ALL_BIN_IDS, (mmi_res_thm_id_str_tbl_struct*)g_mmi_res_thm_bin_id_str_tbl, MMI_RES_THEME_TYPE_BINARY, MMI_RES_THEME_SEC_BIN, &theme, &size);
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    return NULL;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
S8* mmi_res_get_sys_theme_thumbnail(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__)
    return mmi_res_get_theme_section((U8*)g_mmi_res_theme_system_data_ptr->data_array_ptr[index], MMI_RES_THEME_SEC_THUMBNAIL);
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    return NULL;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
S8* mmi_res_get_sys_theme_preview(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__)
    return mmi_res_get_theme_section((U8*)g_mmi_res_theme_system_data_ptr->data_array_ptr[index], MMI_RES_THEME_SEC_PREVIEW);
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    return NULL;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
S8* mmi_res_get_pri_theme_thumbnail(U8* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__)
    return mmi_res_get_theme_section(data, MMI_RES_THEME_SEC_THUMBNAIL);
#else /* defined(__COSMOS_MMI_PACKAGE__) */
    return NULL;
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
S8* mmi_res_get_pri_theme_preview(U8* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)
    return mmi_res_get_theme_section(data, MMI_RES_THEME_SEC_PREVIEW);
#else /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__) */
    return NULL;
#endif /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__) */
}


#if defined(__NFB_THIRD_ROM_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_theme_section_from_thirdrom
 * DESCRIPTION
 *  get one section of theme from third rom
 * PARAMETERS
 *  index            [IN] index of the theme
 *  buf               [OUT] buffer to store section data
 *  buf_length     [IN] buffer length
 *  section          [IN] section
 *  is_pri_theme  [IN] whether is priority theme
 * RETURNS
 *  mmi_res_theme_ret_enum
 *****************************************************************************/
static mmi_res_theme_ret_enum mmi_res_get_theme_section_from_thirdrom(U8 index, S8* buf, S32 buf_length, mmi_res_theme_sec_enum section, MMI_BOOL is_pri_theme)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_res_theme_ret_enum ret = MMI_RES_THEME_RET_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_res_theme_bytestream_struct bs_handle;

    if (is_pri_theme)
    {
        bs_handle.is_pri_theme = MMI_TRUE;
        bs_handle.theme_offset = g_mmi_res_app_icon_attr_array[index].offset;
        bs_handle.theme_length = g_mmi_res_app_icon_attr_array[index].length;  
    }
    else
    {
        bs_handle.is_pri_theme = MMI_FALSE;
        bs_handle.theme_offset = g_mmi_res_thm_attr_array[index].offset;
        bs_handle.theme_length = g_mmi_res_thm_attr_array[index].length;
    }
    bs_handle.current_offset = bs_handle.theme_offset; 

    mmi_res_theme_bytestream_init_memory(&bs_handle, NULL, -1);
    
    do
    {
        S32 data_length = 0, i;
    
        /* verify theme */
        if (!mmi_res_theme_check_is_valid(&bs_handle, &data_length, MMI_TRUE))
        {
            ret = MMI_RES_THEME_RET_INVALID;
            break;
        }
    
        /* read section table */
        for (i = 0 ; i < MMI_RES_THEME_SEC_END ; i++)
        {
            S32 addr = (S32)mmi_res_theme_bytestream_get_dword(&bs_handle) + data_length;
            S32 size = (S32)mmi_res_theme_bytestream_get_dword(&bs_handle);
    
            if (i == section)
            {
                if (size != 0)
                {
                    if (buf_length < size)
                    {
                        ret = MMI_RES_THEME_BUF_NOT_ENOUGH;
                        break;
                    }
    
                    mmi_res_theme_bytestream_seek_start(&bs_handle, addr);
                    mmi_res_theme_bytestream_read(&bs_handle, (U8*)buf, size);
                    ret = MMI_RES_THEME_RET_NO_ERROR;
                }
                break;
            }
        }
    } while (0);
    mmi_res_theme_bytestream_close(&bs_handle, MMI_FALSE);
    
    return ret;
}


/* For detail description, please refer to CustVenusThemeRes.h */
mmi_res_theme_ret_enum mmi_res_get_sys_theme_thumbnail_from_thirdrom(U8 index, S8* buf, S32 buf_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
        return mmi_res_get_theme_section_from_thirdrom(index, buf, buf_length, MMI_RES_THEME_SEC_THUMBNAIL, MMI_FALSE);
#else /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
        return MMI_RES_THEME_RET_INVALID;
#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
mmi_res_theme_ret_enum mmi_res_get_sys_theme_preview_from_thirdrom(U8 index, S8* buf, S32 buf_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    return mmi_res_get_theme_section_from_thirdrom(index, buf, buf_length, MMI_RES_THEME_SEC_PREVIEW, MMI_FALSE);
#else /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
    return MMI_RES_THEME_RET_INVALID;
#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
mmi_res_theme_ret_enum mmi_res_get_pri_theme_thumbnail_from_thirdrom(U8 index, S8* buf, S32 buf_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    return mmi_res_get_theme_section_from_thirdrom(index, buf, buf_length, MMI_RES_THEME_SEC_THUMBNAIL, MMI_TRUE);
#else /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
    return MMI_RES_THEME_RET_INVALID;
#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
}


/* For detail description, please refer to CustVenusThemeRes.h */
mmi_res_theme_ret_enum mmi_res_get_pri_theme_preview_from_thirdrom(U8 index, S8* buf, S32 buf_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    return mmi_res_get_theme_section_from_thirdrom(index, buf, buf_length, MMI_RES_THEME_SEC_PREVIEW, MMI_TRUE);
#else /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
    return MMI_RES_THEME_RET_INVALID;
#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
}
#endif /* defined(__NFB_THIRD_ROM_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */


/* For detail description, please refer to CustVenusThemeRes.h */
mmi_res_theme_ret_enum mmi_res_get_dlt_theme_thumbnail(const WCHAR* filename, S8* buf, S32 buf_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    return mmi_res_get_dlt_theme_section(filename, buf, buf_length, MMI_RES_THEME_SEC_THUMBNAIL);
#else /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)*/
    return MMI_RES_THEME_RET_INVALID;
#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)*/
}


/* For detail description, please refer to CustVenusThemeRes.h */
mmi_res_theme_ret_enum mmi_res_get_dlt_theme_preview(const WCHAR* filename, S8* buf, S32 buf_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
    return mmi_res_get_dlt_theme_section(filename, buf, buf_length, MMI_RES_THEME_SEC_PREVIEW);
#else /* (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
    return MMI_RES_THEME_RET_INVALID;
#endif /* (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_ICON_FW_SUPPORT__)) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */
}


#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)

/* dummy function to create global file handle buffer */
void mmi_res_theme_file_handle_init(void)
{
    extern void FS_SetFileTable(void* table);

    FS_SetFileTable(g_mmi_res_theme_file_handle);
}

#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */


/*****************************************************************************
 * Theme Cache Mechanism
 *****************************************************************************/

#ifdef __MMI_COSMOS_THEME_CACHE_MACHANISM__

//#define __MMI_COSMOS_THEME_CACHE_REQUIRE_LOG__

#ifdef __MTK_TARGET__

#define ThemeCacheTrace(...)

#define ThemeCacheContentTrace(...)

#else // __MTK_TARGET__

//#define ThemeCacheTrace printf
#define ThemeCacheTrace(...)

#define ThemeCacheContentTrace printf

#endif // __MTK_TARGET__


static U8 * s_venus_theme_cache_buffer = NULL;
//static U32 s_venus_theme_cache_buffer_size = 0;
static MMI_BOOL s_venus_theme_cache_has_dlt_theme = MMI_FALSE;
static const U32 s_venus_theme_cache_bit_table_count = (MMI_RES_THM_ALL_IMG_IDS+31)/32;
static U32 s_venus_theme_cache_bit_table[(MMI_RES_THM_ALL_IMG_IDS+31)/32];
static U32 s_venus_theme_cache_bit_table_not_dlt[(MMI_RES_THM_ALL_IMG_IDS+31)/32];
static U32 s_venus_theme_cache_bit_table_is_file[(MMI_RES_THM_ALL_IMG_IDS+31)/32];
static U32 s_venus_theme_cache_image_size[MMI_RES_THM_ALL_IMG_IDS];

#if defined(__MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__) || defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
    #if defined(__MMI_MAINLCD_480X800__)
    #define VENUS_THEME_CACHE_PLUTO_IMAGE_BUFFER_SIZE 40960
    #else
    #define VENUS_THEME_CACHE_PLUTO_IMAGE_BUFFER_SIZE 20480
    #endif
#else /* defined(__MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__) */
    #define VENUS_THEME_CACHE_PLUTO_IMAGE_BUFFER_SIZE 1
#endif /* defined(__MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__) */

static U8 s_venus_theme_cache_pluto_image_buffer[VENUS_THEME_CACHE_PLUTO_IMAGE_BUFFER_SIZE];
static U16 s_venus_theme_cache_pluto_image_buffer_id;

extern S8 *GetImageRaw(U16 ImageId);

typedef struct
{
    U16 res_id;
    U8 * data;
    U32 data_size;
} VenusThemeCahceIndex;

typedef struct
{
    U32 cache_version;

    VenusThemeCahceIndex * index_table;
    U16 cache_count;

    U16 image_count;

    U8 *cache_pool;
    U8 *cache_pool_end;
    U8 *cache_pool_i;
} VenusThemeCahceHeader;

// predeclaration
void mmi_res_venus_theme_cache_init_is_file_table(void);

// utilities

static void mmi_res_venus_theme_set_bit_table(U32 offset, U32 * bit_table)
{
    U32 index = offset / 32;
    U8 bit_offset = (offset % 32);
    bit_table[index] |= 1 << bit_offset;
}

static U8 mmi_res_venus_theme_get_bit_table(U32 offset, U32 * bit_table)
{
    U32 index = offset / 32;
    U8 bit_offset = (offset % 32);
    if (bit_table[index] & 1 << bit_offset)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static U32 mmi_res_venus_theme_get_id_index(U16 id)
{
    S32 idx, idx_first, idx_mid, idx_last;

    idx = -1;
    idx_first = 0;
    idx_last = MMI_RES_THM_ALL_IMG_IDS - 1;
    while (idx_last >= idx_first)
    {
        U16 mid_id;

        idx_mid = (idx_first + idx_last) / 2;
        mid_id = g_mmi_res_thm_img_id_str_tbl[idx_mid].id;

        if (mid_id == id)
        {
            idx = idx_mid;
            break;
        }
        else if (mid_id > id)
        {
            idx_last = idx_mid - 1;
        }
        else if (mid_id < id)
        {
            idx_first = idx_mid + 1;
        }
    }
    if (idx == -1)
    {
        return 0xFFFFFFFF;
    }
    return idx;
}


// implementation


MMI_BOOL mmi_res_venus_theme_cache_init(U8 * buffer, U32 size)
{
    int i;
    U16 image_count = MMI_RES_THM_ALL_IMG_IDS;
    U32 header_size = sizeof(VenusThemeCahceHeader);
    U32 index_size = image_count * sizeof(VenusThemeCahceIndex);
    //U32 pool_size = size - header_size - index_size;
    VenusThemeCahceHeader * header;

    s_venus_theme_cache_has_dlt_theme = MMI_FALSE;

    // claer cache image size
    for (i = 0; i < MMI_RES_THM_ALL_IMG_IDS; ++i)
    {
        s_venus_theme_cache_image_size[i] = 0;
    }
    s_venus_theme_cache_pluto_image_buffer_id = 0;

    for (i = 0 ; i < MMI_RES_THEME_MAX_CONCURRENT ; i++)
    {
        if (g_mmi_res_theme[i].theme.is_file == MMI_TRUE)
        {
            s_venus_theme_cache_has_dlt_theme = MMI_TRUE;
        }
    }

#ifndef __MMI_RES_THEME_THIRD_ROM_SUPPORT__
    if (s_venus_theme_cache_has_dlt_theme == MMI_FALSE)
    {
        s_venus_theme_cache_buffer = NULL;
        //s_venus_theme_cache_buffer_size = 0;
        s_venus_theme_cache_pluto_image_buffer_id = 0;
        return MMI_TRUE;
    }
#endif

#if defined(__MMI_RES_THEME_CACHE_FROM_ASM__)
    // init is file table
    mmi_res_venus_theme_cache_init_is_file_table();

    if (buffer == NULL)
    {
        s_venus_theme_cache_buffer = NULL;
        //s_venus_theme_cache_buffer_size = 0;
        s_venus_theme_cache_pluto_image_buffer_id = 0;
        return MMI_FALSE;
    }
    buffer = g_mmi_res_theme_cache_asm_ptr;
    size = MMI_RES_THEME_DLT_POOL;
#endif // defined(__MMI_RES_THEME_CACHE_FROM_ASM__)

    size -= (4 - (U32)buffer % 4) % 4;
    buffer = (U8*) ( ((U32)buffer + 3) / 4 * 4);
    header = (VenusThemeCahceHeader*) buffer;

    s_venus_theme_cache_buffer = buffer;
    //s_venus_theme_cache_buffer_size = size;

    header->cache_version = 0;
    header->index_table = (VenusThemeCahceIndex*)(buffer + header_size);
    header->image_count = image_count;
    header->cache_count = 0;
    header->cache_pool = buffer + header_size + index_size;
    header->cache_pool_i = header->cache_pool;
    header->cache_pool_end = buffer + size;

    // init index table
    for (i = 0; i < image_count; ++i)
    {
        header->index_table[i].data = NULL;
        header->index_table[i].data_size = 0;
    }

    memset(s_venus_theme_cache_bit_table_not_dlt, 0, s_venus_theme_cache_bit_table_count * 4);

    return MMI_TRUE;
}


MMI_BOOL mmi_res_venus_theme_cache_refresh_start(void)
{
    VenusThemeCahceHeader * header = (VenusThemeCahceHeader*)s_venus_theme_cache_buffer;

    ThemeCacheTrace("----------- cache refresh start\n");

    MMI_TRACE(MMI_FW_TRC_INFO, MMI_THEME_CACHE_REFRESH_START);

#ifdef __MMI_RES_THEME_CACHE_FROM_ASM__
    memset(s_venus_theme_cache_bit_table, 0, s_venus_theme_cache_bit_table_count * 4);
#endif // __MMI_RES_THEME_CACHE_FROM_ASM__

    if (header == NULL)
    {
        return MMI_TRUE;
    }

    ++header->cache_version;

#ifndef __MMI_RES_THEME_CACHE_FROM_ASM__
    memset(s_venus_theme_cache_bit_table, 0, s_venus_theme_cache_bit_table_count * 4);
#endif // __MMI_RES_THEME_CACHE_FROM_ASM__

    return MMI_TRUE;
}

MMI_BOOL mmi_res_venus_theme_cache_refresh_require(U16 id)
{
    // find the index table entry
    U32 index;
    VenusThemeCahceHeader * header = (VenusThemeCahceHeader*)s_venus_theme_cache_buffer;

    ThemeCacheTrace(">>> cache requre : %d\n", id);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_THEME_CACHE_REFRESH_REQUIRE, id);

#ifdef __MMI_RES_THEME_CACHE_FROM_ASM__
    index = mmi_res_venus_theme_get_id_index(id);
    if (index == 0xFFFFFFFF)
    {
        return MMI_FALSE;
    }

    mmi_res_venus_theme_set_bit_table(index, s_venus_theme_cache_bit_table);
#endif // __MMI_RES_THEME_CACHE_FROM_ASM__

    if (header == NULL)
    {
        return MMI_TRUE;
    }

#ifndef __MMI_RES_THEME_CACHE_FROM_ASM__
    index = mmi_res_venus_theme_get_id_index(id);
    if (index == 0xFFFFFFFF)
    {
        return MMI_FALSE;
    }

    mmi_res_venus_theme_set_bit_table(index, s_venus_theme_cache_bit_table);
#endif // __MMI_RES_THEME_CACHE_FROM_ASM__

    return MMI_TRUE;
}

static MMI_BOOL mmi_res_venus_theme_cache_refresh_do_cache()
{
    U32 i, j;
    VenusThemeCahceHeader * header = (VenusThemeCahceHeader*)s_venus_theme_cache_buffer;

    MMI_TRACE(MMI_FW_TRC_INFO, MMI_THEME_CACHE_REFRESH_DO_CACHE);
    
    for (i = 0; i < header->image_count; ++i)
    {
        if (mmi_res_venus_theme_get_bit_table(i, s_venus_theme_cache_bit_table))
        {
            U16 res_id = g_mmi_res_thm_img_id_str_tbl[i].id;
            for (j = 0; j < header->cache_count; ++j)
            {
                if(header->index_table[j].res_id == res_id)
                {
                    break;
                }
            }

            if (j == header->cache_count) // not found
            {
                U8* p_data;
                S32 data_offset;
                U32 img_size;
                const mmi_res_theme_struct * theme;

                ThemeCacheTrace("add image : %d\n", res_id);

                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_THEME_CACHE_ADD_IMAGE, res_id);

                p_data = mmi_res_get_theme_data_addr(res_id, MMI_RES_THM_ALL_IMG_IDS,
                        (mmi_res_thm_id_str_tbl_struct*)g_mmi_res_thm_img_id_str_tbl, MMI_RES_THEME_TYPE_IMAGE,
                        MMI_RES_THEME_SEC_IMG, (mmi_res_theme_struct **)&theme, (S32*)&img_size);
                if (p_data == 0)
                {
                    mmi_res_venus_theme_set_bit_table(i, s_venus_theme_cache_bit_table_not_dlt);
                    continue;
                }
                img_size = (img_size + 3) / 4 * 4;
#ifndef __MMI_RES_THEME_THIRD_ROM_SUPPORT__
                if (!theme->is_file)
                {
                    mmi_res_venus_theme_set_bit_table(i, s_venus_theme_cache_bit_table_not_dlt);
                    continue;
                }
                
                if (theme->fh < FS_NO_ERROR)
                {
                    //MMI_ASSERT(MMI_FALSE);
                    continue;
                }
#endif
                data_offset = (S32)p_data;
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
                data_offset += g_mmi_res_thm_attr_array[theme->index].offset;
#else
                FS_Seek(theme->fh, data_offset, FS_FILE_BEGIN);
#endif

                if (header->cache_pool_i + img_size < header->cache_pool_end)
                {
#ifndef __MMI_RES_THEME_THIRD_ROM_SUPPORT__
                    U32 len;
#endif
                    header->index_table[j].res_id = res_id;
                    header->index_table[j].data = header->cache_pool_i;
                    header->index_table[j].data_size = img_size;
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)  
                    if (theme->is_pri_theme)
                    {
                        if (!MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_APPICONS, header->cache_pool_i, data_offset, img_size))
                        {
                            continue;
                        } 
                    }
                    else
                    {
                        if (!MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_THEMES, header->cache_pool_i, data_offset, img_size))
                        {
                            continue;
                        }
                    }
#else /* defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__) */
                    if (FS_Read(theme->fh, header->cache_pool_i, img_size, &len) < FS_NO_ERROR)
                    {
                        //MMI_ASSERT(0);
                        continue;
                    }
#endif /* defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__) */                   
                    header->cache_pool_i += img_size;
                    ++header->cache_count;
                }
                else
                {
                    ThemeCacheTrace("out of cache free memory, shall clean !!!!\n");
                    
                    MMI_TRACE(MMI_FW_TRC_INFO, MMI_THEME_CACHE_OUT_OF_MEMORY);

                    return MMI_FALSE;
                }
            }
        }
    }
    return MMI_TRUE;
}

static void mmi_res_venus_theme_cache_print_bit_table()
{
    U32 i;
    for (i = 0; i < s_venus_theme_cache_bit_table_count; ++i)
    {
        ThemeCacheTrace("%x ", s_venus_theme_cache_bit_table[i]);
    }
    ThemeCacheTrace("\n");
}

static void mmi_res_venus_theme_cache_refresh_clean()
{
    U32 i;
    U32 cache_i = 0;
    VenusThemeCahceHeader * header = (VenusThemeCahceHeader*)s_venus_theme_cache_buffer;
    U8 * temp_cache_i = header->cache_pool;

    MMI_TRACE(MMI_FW_TRC_INFO, MMI_THEME_CACHE_REFRESH_CLEAN);
    
    mmi_res_venus_theme_cache_print_bit_table();

    for (i = 0; i < header->cache_count; ++i)
    {
        U32 index = mmi_res_venus_theme_get_id_index(header->index_table[i].res_id);
        if (index == 0xFFFFFFFF)
        {
             ThemeCacheTrace("invalid id !!!!\n");
             MMI_ASSERT(0);
        }

        if (mmi_res_venus_theme_get_bit_table(index, s_venus_theme_cache_bit_table))
        {
            // keep
            if (i != cache_i)
            {
                header->index_table[cache_i].res_id = header->index_table[i].res_id;
                header->index_table[cache_i].data_size = header->index_table[i].data_size;
                header->index_table[cache_i].data = temp_cache_i;

                memcpy(temp_cache_i, header->index_table[i].data, header->index_table[i].data_size);
                ThemeCacheTrace("clean 1 %d\n", header->index_table[i].res_id);

                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_THEME_CACHE_CLEAN_ONE, header->index_table[i].res_id);
            }
            else
            {
                ThemeCacheTrace("clean 2 %d\n", header->index_table[i].res_id);

                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_THEME_CACHE_CLEAN_TWO, header->index_table[i].res_id);
            }
            temp_cache_i += header->index_table[i].data_size;
            ++cache_i;
        }
        else
        {
            // drop
            ThemeCacheTrace("clean drop %d\n", header->index_table[i].res_id);

            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_THEME_CACHE_CLEAN_DROP, header->index_table[i].res_id);
        }
    }
    header->cache_count = cache_i;
    header->cache_pool_i = temp_cache_i;
}

#ifdef __MMI_COSMOS_THEME_CACHE_REQUIRE_LOG__
static U32 mmi_res_venus_theme_cache_max_require_size = 0;

void mmi_res_venus_theme_cache_refresh_success_log()
{
    U32 i, j;
    VenusThemeCahceHeader * header = (VenusThemeCahceHeader*)s_venus_theme_cache_buffer;
    U32 sum = 0;

    ThemeCacheContentTrace("dlt cache refresh succeeded, log:\n");

    MMI_TRACE(MMI_FW_TRC_INFO, MMI_THEME_CACHE_REFRESH_SUCCESS_LOG);

    for (i = 0; i < header->image_count; ++i)
    {
        if (mmi_res_venus_theme_get_bit_table(i, s_venus_theme_cache_bit_table))
        {
            U16 res_id = g_mmi_res_thm_img_id_str_tbl[i].id;
            for (j = 0; j < header->cache_count; ++j)
            {
                VenusThemeCahceIndex * entry = &(header->index_table[j]);
                if(entry->res_id == res_id)
                {
                    // found
                    sum += entry->data_size;
                    ThemeCacheContentTrace("id: %d, size: %d\n", entry->res_id, entry->data_size);

                    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_THEME_CACHE_IMAGE_INFO, entry->res_id, entry->data_size);

                    break;
                }
            }
        }
    }
    if (sum > mmi_res_venus_theme_cache_max_require_size)
    {
        mmi_res_venus_theme_cache_max_require_size = sum;
    }

    ThemeCacheContentTrace("dlt cache refresh succeeded log end:, required size: %d, max size: %d\n",
            sum, mmi_res_venus_theme_cache_max_require_size);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_THEME_CACHE_REFRESH_SUCCESS_LOG_END, sum, mmi_res_venus_theme_cache_max_require_size);
}

#endif // __MMI_COSMOS_THEME_CACHE_REQUIRE_LOG__

void mmi_res_venus_theme_cache_refresh_fail_log()
{
    U32 i;
    VenusThemeCahceHeader * header = (VenusThemeCahceHeader*)s_venus_theme_cache_buffer;
    U32 sum = 0;

    ThemeCacheContentTrace("dlt cache refresh failed, log:\n");

    MMI_TRACE(MMI_FW_TRC_INFO, MMI_THEME_CACHE_REFRESH_FAIL_LOG);

    for (i = 0; i < header->image_count; ++i)
    {
        if (mmi_res_venus_theme_get_bit_table(i, s_venus_theme_cache_bit_table))
        {
            U8 * p_data;
            const mmi_res_theme_struct * theme;
            U32 img_size;
            U16 res_id = g_mmi_res_thm_img_id_str_tbl[i].id;
            p_data = mmi_res_get_theme_data_addr(res_id, MMI_RES_THM_ALL_IMG_IDS,
                    (mmi_res_thm_id_str_tbl_struct*)g_mmi_res_thm_img_id_str_tbl, MMI_RES_THEME_TYPE_IMAGE,
                    MMI_RES_THEME_SEC_IMG, (mmi_res_theme_struct **)&theme, (S32*)&img_size);
            if (p_data == NULL)
            {
                continue;
            }
#ifndef __MMI_RES_THEME_THIRD_ROM_SUPPORT__
            if (!theme->is_file)
            {
                continue;
            }
#endif            
            sum += img_size;
            ThemeCacheContentTrace("id: %d, size: %d\n", res_id, img_size);

            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_THEME_CACHE_IMAGE_INFO, res_id, img_size);
        }
    }

    ThemeCacheContentTrace("dlt cache refresh fail log end:, required size: %d, cache size: %d\n",
            sum, header->cache_pool_end - header->cache_pool);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_THEME_CACHE_REFRESH_FAIL_LOG_END, sum, header->cache_pool_end - header->cache_pool);
}

MMI_BOOL mmi_res_venus_theme_cache_check_shall_alloc()
{
    U32 i;

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THC", SA_start);
#endif

#ifndef __MMI_RES_THEME_THIRD_ROM_SUPPORT__
    if (s_venus_theme_cache_has_dlt_theme == MMI_FALSE)
    {
        return MMI_FALSE;
    }
#endif

    for (i = 0; i < s_venus_theme_cache_bit_table_count; ++i)
    {
        if (s_venus_theme_cache_bit_table[i] & s_venus_theme_cache_bit_table_is_file[i])
        {

#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("THC", SA_stop);
#endif
            return MMI_TRUE;
        }
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THC", SA_stop);
#endif

    return MMI_FALSE;
}

void mmi_res_venus_theme_cache_init_is_file_table(void)
{
    U32 i;

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THD", SA_start);
#endif

    memset(s_venus_theme_cache_bit_table_is_file, 0, s_venus_theme_cache_bit_table_count * 4);

    for (i = 0; i < MMI_RES_THM_ALL_IMG_IDS; ++i)
    {
        U16 res_id = g_mmi_res_thm_img_id_str_tbl[i].id;

        {
            U8* p_data;
            U32 img_size;
            const mmi_res_theme_struct * theme;

            p_data = mmi_res_get_theme_data_addr(res_id, MMI_RES_THM_ALL_IMG_IDS,
                    (mmi_res_thm_id_str_tbl_struct*)g_mmi_res_thm_img_id_str_tbl, MMI_RES_THEME_TYPE_IMAGE,
                    MMI_RES_THEME_SEC_IMG, (mmi_res_theme_struct **)&theme, (S32*)&img_size);
            if (p_data == 0)
            {
                continue;
            }
            if (theme->is_file)
            {
                mmi_res_venus_theme_set_bit_table(i, s_venus_theme_cache_bit_table_is_file);
            }
        }
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("THD", SA_stop);
#endif
}

MMI_BOOL mmi_res_venus_theme_cache_refresh_end(void)
{
    VenusThemeCahceHeader * header = (VenusThemeCahceHeader*)s_venus_theme_cache_buffer;
    MMI_BOOL result;
    U32 i;

    ThemeCacheTrace("----------- cache refresh end\n");

    MMI_TRACE(MMI_FW_TRC_INFO, MMI_THEME_CACHE_REFRESH_END);

    if (header == NULL)
    {
#ifndef __MMI_RES_THEME_CACHE_FROM_ASM__
        return MMI_TRUE;
#else // __MMI_RES_THEME_CACHE_FROM_ASM__
        if (mmi_res_venus_theme_cache_check_shall_alloc() )
        {
            mmi_res_theme_cache_attach_asm();
            header = (VenusThemeCahceHeader*)s_venus_theme_cache_buffer;
            if (header == NULL)
            {
                return MMI_FALSE;
            }
        }
        else
        {
            return MMI_TRUE;
        }

#endif // __MMI_RES_THEME_CACHE_FROM_ASM__
    }

    // filter cache bit table -- filter res that is in system theme
    for (i = 0; i < s_venus_theme_cache_bit_table_count; ++i)
    {
        s_venus_theme_cache_bit_table[i] &= ~s_venus_theme_cache_bit_table_not_dlt[i];
    }
    // search

    result = mmi_res_venus_theme_cache_refresh_do_cache();
    if (!result)
    {
        MMI_BOOL result2;

        // clean
        mmi_res_venus_theme_cache_refresh_clean();

        result2 = mmi_res_venus_theme_cache_refresh_do_cache();
        // if fail again, fatal
        if (!result2)
        {
            mmi_res_venus_theme_cache_refresh_fail_log();
            //MMI_ASSERT(0);
            return MMI_FALSE;
        }
    }

#ifdef __MMI_COSMOS_THEME_CACHE_REQUIRE_LOG__
    mmi_res_venus_theme_cache_refresh_success_log();
#endif // __MMI_COSMOS_THEME_CACHE_REQUIRE_LOG__

    return MMI_TRUE;
}


U8 * mmi_res_venus_theme_cache_get(U16 id)
{
    U8 * p_data;
    VenusThemeCahceHeader * header = (VenusThemeCahceHeader*)s_venus_theme_cache_buffer;
    const mmi_res_theme_struct * theme;
    U32 img_size;
    U32 i;

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_THEME_CACHE_GET, id);

    p_data = mmi_res_get_theme_data_addr(id, MMI_RES_THM_ALL_IMG_IDS,
            (mmi_res_thm_id_str_tbl_struct*)g_mmi_res_thm_img_id_str_tbl, MMI_RES_THEME_TYPE_IMAGE,
            MMI_RES_THEME_SEC_IMG, (mmi_res_theme_struct **)&theme, (S32*)&img_size);

    if (p_data == NULL)
    {
        return NULL;
    }

#ifndef __MMI_RES_THEME_THIRD_ROM_SUPPORT__
    if (!theme->is_file)
    {
        return p_data;
    }
#endif

    if (header == NULL)
    {
        return NULL;
    }

    for (i = 0; i < header->cache_count; ++i)
    {
        if(header->index_table[i].res_id == id)
        {
            break;
        }
    }
    if (i == header->cache_count) // not found
    {
        //ThemeCacheTrace("XXX cache got NULL : %d\n", id);

        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_THEME_CACHE_GET_NULL, id);

        if (s_venus_theme_cache_pluto_image_buffer_id == id)
        {
            return s_venus_theme_cache_pluto_image_buffer;
        }

        if (theme->fh >= FS_NO_ERROR || (!theme->is_file && theme->bin == NULL))
        {
#ifndef __MMI_RES_THEME_THIRD_ROM_SUPPORT__
            U32 len;
#endif
            S32 data_offset;
            data_offset = (S32)p_data;
            if (img_size > VENUS_THEME_CACHE_PLUTO_IMAGE_BUFFER_SIZE)
            {
                //MMI_ASSERT(0);
                return NULL;
            }
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
            if (theme->is_pri_theme)
            {
                data_offset += g_mmi_res_app_icon_attr_array[theme->index].offset;
                if (!MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_APPICONS, s_venus_theme_cache_pluto_image_buffer, data_offset, img_size))
                {
                    return NULL;
                }  
            }
            else
            {
                data_offset += g_mmi_res_thm_attr_array[theme->index].offset;
                if (!MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_THEMES, s_venus_theme_cache_pluto_image_buffer, data_offset, img_size))
                {
                    return NULL;
                }
            }
#else /* defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__) */
            FS_Seek(theme->fh, data_offset, FS_FILE_BEGIN);
            if (FS_Read(theme->fh, s_venus_theme_cache_pluto_image_buffer, img_size, &len) < FS_NO_ERROR)
            {
                //MMI_ASSERT(0);
                return NULL;
            }
            if (len != img_size)
            {
                //MMI_ASSERT(0);
                return NULL;
            }
#endif /* defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__) */            
            s_venus_theme_cache_pluto_image_buffer_id = id;
            return s_venus_theme_cache_pluto_image_buffer;
        }
        else
        {
            return NULL;
        }
    }
    //ThemeCacheTrace("!!! cache found : %d\n", id);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_THEME_CACHE_GET_FOUND, id);

    return header->index_table[i].data;
}

#else // __MMI_COSMOS_THEME_CACHE_MACHANISM__

MMI_BOOL mmi_res_venus_theme_cache_init(U8 * buffer, U32 size)
{
    return MMI_TRUE;
}

U8 * mmi_res_venus_theme_cache_get(U16 id)
{
    return NULL;
}

MMI_BOOL mmi_res_venus_theme_cache_refresh_start(void)
{
    return MMI_TRUE;
}

MMI_BOOL mmi_res_venus_theme_cache_refresh_require(U16 id)
{
    return MMI_TRUE;
}

MMI_BOOL mmi_res_venus_theme_cache_refresh_end(void)
{
    return MMI_TRUE;
}

#endif // __MMI_COSMOS_THEME_CACHE_MACHANISM__

static void mmi_res_get_image_size_from_8_byte_header(U8 * _8_byte_header, U16 * width, U16 * height)
{
    *width  = (U16)(( ((U16)_8_byte_header[7])        << 4) | (((U16)_8_byte_header[6] & 0xF0) >> 4));
    *height = (U16)(((((U16)_8_byte_header[6]) & 0xF) << 8) |  ((U16)_8_byte_header[5]));
}

#ifdef __MMI_COSMOS_THEME_CACHE_MACHANISM__
MMI_BOOL mmi_res_theme_cache_get_image_size_from_file(U32 index, const mmi_res_theme_struct * theme, S32 data_offset, U16 * width, U16 * height)
{
    if (theme->fh >= FS_NO_ERROR || (!theme->is_file && theme->bin == NULL))
    {
#ifndef __MMI_RES_THEME_THIRD_ROM_SUPPORT__
        U32 len;
#endif
        U8 data[8];
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
        if (theme->is_pri_theme)
        {
            data_offset += g_mmi_res_app_icon_attr_array[theme->index].offset;
            if (!MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_APPICONS, data, data_offset, 8))
            {
                return MMI_FALSE;
            }   
        }
        else
        {
            data_offset += g_mmi_res_thm_attr_array[theme->index].offset;
            if (!MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_THEMES, data, data_offset, 8))
            {
                return MMI_FALSE;
            }
        }
#else /* defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__) */
        FS_Seek(theme->fh, data_offset, FS_FILE_BEGIN);
        if (FS_Read(theme->fh, data, 8, &len) < FS_NO_ERROR)
        {
            //MMI_ASSERT(0);
            return MMI_FALSE;
        }
        if (len != 8)
        {
            //MMI_ASSERT(0);
            return MMI_FALSE;
        }
#endif /* defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__) */        
        mmi_res_get_image_size_from_8_byte_header(data, width, height);
        s_venus_theme_cache_image_size[index] = *width + (*height) * 0x10000;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif // __MMI_COSMOS_THEME_CACHE_MACHANISM__

MMI_BOOL mmi_res_theme_cache_get_image_size(U16 id, U16 * width, U16 * height)
{
#ifndef __COSMOS_MMI_PACKAGE__
    return MMI_FALSE;
#else // __COSMOS_MMI_PACKAGE__
    U8 * p_data;
    const mmi_res_theme_struct * theme;
    U32 img_size;

    *width = 0;
    *height = 0;

    p_data = mmi_res_get_theme_data_addr(id, MMI_RES_THM_ALL_IMG_IDS,
            (mmi_res_thm_id_str_tbl_struct*)g_mmi_res_thm_img_id_str_tbl, MMI_RES_THEME_TYPE_IMAGE,
            MMI_RES_THEME_SEC_IMG, (mmi_res_theme_struct **)&theme, (S32*)&img_size);

    if (p_data == NULL)
    {
        return MMI_FALSE;
    }

#ifndef __MMI_RES_THEME_THIRD_ROM_SUPPORT__
    if (!theme->is_file)
    {
        mmi_res_get_image_size_from_8_byte_header(p_data, width, height);
        return MMI_TRUE;
    }
#endif    

#ifndef __MMI_COSMOS_THEME_CACHE_MACHANISM__
    return MMI_FALSE;
#else // __MMI_COSMOS_THEME_CACHE_MACHANISM__
    {
        U32 i;
        U32 index;
        VenusThemeCahceHeader * header = (VenusThemeCahceHeader*)s_venus_theme_cache_buffer;

        index = mmi_res_venus_theme_get_id_index(id);
        if (s_venus_theme_cache_image_size[index] != 0)
        {
            *width = s_venus_theme_cache_image_size[index] % 0x10000;
            *height = s_venus_theme_cache_image_size[index] / 0x10000;
            return MMI_TRUE;
        }

        if (header == NULL)
        {
#ifndef __MMI_RES_THEME_CACHE_FROM_ASM__
            return MMI_FALSE;
#endif // __MMI_RES_THEME_CACHE_FROM_ASM__
        }
        else
        {
            for (i = 0; i < header->cache_count; ++i)
            {
                if(header->index_table[i].res_id == id)
                {
                    break;
                }
            }
        }

        if (header == NULL || i == header->cache_count) // not found
        {
            return mmi_res_theme_cache_get_image_size_from_file(index, theme, (S32)p_data, width, height);
        }
        else
        {
            U8 * p_data2 = header->index_table[i].data;
            mmi_res_get_image_size_from_8_byte_header(p_data2, width, height);
            s_venus_theme_cache_image_size[index] = *width + (*height) * 0x10000;
            return MMI_TRUE;
        }
    }
#endif // __MMI_COSMOS_THEME_CACHE_MACHANISM__
#endif // __COSMOS_MMI_PACKAGE__
}

