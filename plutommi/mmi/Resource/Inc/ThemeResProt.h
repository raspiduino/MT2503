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
 * Filename:
 * ---------
 *  ThemeResProt.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Theme Resource Internal Interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __THEMERESPROT_H__
#define __THEMERESPROT_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMIDataType.h"
#include "fs_gprot.h"


/*****************************************************************************
 * Internal compile option
 *****************************************************************************/
#if defined(__NFB_THIRD_ROM_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
#define __MMI_RES_THEME_THIRD_ROM_SUPPORT__
#endif /* defined(__NFB_THIRD_ROM_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */

#if defined(__MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__) || defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) || defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__) || defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)
#define __MMI_RES_THEME_DOWNLOADABLE_SUPPORT__
#endif /* defined(__MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__) || defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__)  || defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__) */

#if !defined(__MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__) && (defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) || defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__)) && defined(LOW_COST_SUPPORT)
#define __MMI_RES_THEME_CACHE_FROM_ASM__
#endif /* !defined(__MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__) && (defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) || defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__))  && defined(LOW_COST_SUPPORT) */

#if defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__)
#define __MMI_COSMOS_THEME_CACHE_MACHANISM__
#endif /* defined(__MMI_RES_THEME_DOWNLOADABLE_SUPPORT__) */


/*****************************************************************************
 * Cache pool configuration
 *****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
    #define MMI_RES_THEME_DLT_POOL  400*1024
#else /* defined(__MMI_MAINLCD_480X800__) */

#if defined(__MMI_RES_THEME_CACHE_FROM_ASM__)

#if defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__)
    #define MMI_RES_THEME_DLT_POOL  220*1024
#else /* defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__) */
    #define MMI_RES_THEME_DLT_POOL  200*1024
#endif /* defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__) */

#else /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */

#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__) && !defined(__MMI_THEMES_APPLICATION__)
    #define MMI_RES_THEME_DLT_POOL  70*1024
#else /* defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__) && !defined(__MMI_THEMES_APPLICATION__) */
    #define MMI_RES_THEME_DLT_POOL  250*1024
#endif /* defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__) && !defined(__MMI_THEMES_APPLICATION__) */

#endif /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */

#endif /* defined(__MMI_MAINLCD_480X800__) */


/*****************************************************************************
 * Enum
 *****************************************************************************/
#define MMI_RES_THEME_DLT_MAX_FILE_BUF  260     /* max buffer size of file name in words, aligned with file manager */


/*****************************************************************************
 * Enum
 *****************************************************************************/
/* theme section enum */ 
typedef enum
{
    MMI_RES_THEME_SEC_THUMBNAIL = 0,    /* thumbnail */
    MMI_RES_THEME_SEC_PREVIEW   = 1,    /* preview */
    MMI_RES_THEME_SEC_INFO      = 2,    /* information */
    MMI_RES_THEME_SEC_RES_TABLE = 3,    /* resource table */
    MMI_RES_THEME_SEC_STR_TABLE = 4,    /* string table */
    MMI_RES_THEME_SEC_FONT      = 5,    /* font data */
    MMI_RES_THEME_SEC_IMG       = 6,    /* image data */
    MMI_RES_THEME_SEC_ADO       = 7,    /* audio data */
    MMI_RES_THEME_SEC_BIN       = 8,    /* binary data */

    MMI_RES_THEME_SEC_END
} mmi_res_theme_sec_enum;

/* resource type enum */
typedef enum
{
    MMI_RES_THEME_TYPE_IMAGE    = 0,    /* image resource */
    MMI_RES_THEME_TYPE_COLOR    = 1,    /* color resource */
    MMI_RES_THEME_TYPE_FONT     = 2,    /* font style resource */
    MMI_RES_THEME_TYPE_INTEGER  = 3,    /* integer resource */
    MMI_RES_THEME_TYPE_AUDIO    = 4,    /* audio resource */
    MMI_RES_THEME_TYPE_BINARY   = 5,    /* binary resource */

    MMI_RES_THEME_TYPE_MAX              /* max resource enum */
} mmi_res_theme_type_enum;


/*****************************************************************************
 * Data Structure
 *****************************************************************************/
/* theme section table structure */
typedef struct
{
    S32 addr;   /* address from the start of main theme (section table) */
    S32 size;   /* size of the section */
} mmi_res_theme_sec_tbl_struct;

/* theme resource structure */
typedef struct
{
    mmi_res_theme_sec_tbl_struct section_table[MMI_RES_THEME_SEC_END];  /* section table */
    U16 res_num[MMI_RES_THEME_TYPE_MAX];    /* number of each resource type */
    U8* res_table[MMI_RES_THEME_TYPE_MAX];  /* each resource table pointer */
    U8* bin;                                /* pointer to the start address of this theme */
    FS_HANDLE fh;                           /* file handle */
    U8* dlt_mem_ptr;                        /* pointer to allocated DLT memory buffer */
    U8* string_table;                       /* pointer to theme ID string table */
    S32 ver_length;                         /* header of verification length */
#if defined(__MMI_RES_THEME_THIRD_ROM_SUPPORT__)    
    U8 index;                               /* theme index */
    MMI_BOOL is_pri_theme;                  /* whether is priority theme */
#endif
    MMI_BOOL is_file;                       /* whether the theme is from file */
} mmi_res_theme_struct;


/*****************************************************************************
 * Global Function
 *****************************************************************************/


#endif /* __THEMERESPROT_H__ */

