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
 *
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
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
#define _FMGR_INTERNAL_SOURCE_C_
#define _FMGR_TABLE_C_
#define _FMGR_TABLE_CONTENT_C_

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"
#if defined (__MMI_FILE_MANAGER__)

#include "FileMgrGProt.h"
#include "FileMgrProt.h"
#include "FileMgrInstance.h"
#include "FileMgrTable.h"

#ifdef __MMI_IMAGE_VIEWER__
#include "mmi_rp_app_imageviewer_def.h"
#endif

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif

#ifdef __MMI_OP01_DCD__
#include "mmi_rp_app_dcd_def.h"
#endif

#include "FileMgrSrvGProt.h"

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
#include "FontManagerGProt.h"
#endif

#include "MMIDataType.h"
#include "wgui_categories_list.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_res_range_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#ifdef __UM_SUPPORT__
#include "mmi_rp_app_unifiedmessage_def.h"
#endif
#include "mmi_rp_app_profiles_def.h"
#include "mmi_rp_app_bluetooth_def.h"
#ifdef __MMI_TELEPHONY_SUPPORT__
#include "mmi_rp_app_callset_def.h"
#endif
#ifdef __MMI_FM_RADIO__
#include "mmi_rp_app_fmrdo_def.h"
#endif
#include "GlobalMenuItems.h"
#include "mmi_rp_app_funandgames_def.h"
#ifdef __MMI_RMGR__
#include "mmi_rp_app_rmgr_def.h"
#endif
#include "mmi_rp_app_filemanager_def.h"
#if defined (__MMI_CSB_BROWSER__)
#include "mmi_rp_app_csb_def.h"
#endif
#include "VdoPlyResDef.h"
#include "FileMgrServicehdlr.h"
#include "FileMgrType.h"
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif
#include "GlobalResDef.h"
#include "kal_general_types.h"
#include "wgui_categories_util.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "fs_type.h"
#include "fs_func.h"
/****************************************************************************
* Define
*****************************************************************************/

/***** Enum & Macro *****/


/***** Struct *****/
#ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__
typedef struct _mmi_fmgr_app_title_info_struct
{
    U16 app_id;
    U16 title_id;
    U16 icon_menu_id;
} mmi_fmgr_app_title_info_struct;
#endif

typedef struct _mmi_fmgr_enabler_info_struct
{
    U16                         menu_id;
    mmi_fmgr_enabler_callback   enabler;
} mmi_fmgr_enabler_info_struct;

typedef struct _mmi_fmgr_notify_info_struct
{
    U32                         flag;
    mmi_fmgr_notify_callback    callback;
#ifdef WIN32
    S8                          *funcname;
#endif
} mmi_fmgr_notify_info_struct;

#ifdef __FMGR_HYPERLINK_SUPPORT__
typedef struct _mmi_fmgr_hyperlink_table_entry_struct
{
    U16                         app_id;
    S8                          *path;
    mmi_fmgr_hyperlink_callback callback;
} mmi_fmgr_hyperlink_table_entry_struct;
#endif

#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
typedef struct _mmi_fmgr_cr_table_entry_struct
{
    const U16       *path;
    S16             drv_type;
    S16             drv_flag;
    U16             string_id;
    U16             icon_id;
    
} mmi_fmgr_cr_table_entry_struct;

typedef struct _mmi_fmgr_cr_table_entry_ex_struct
{
    U16             string_id;
    U16             icon_id;
    U16             lsk_string_id;
    FuncPtr         lsk_hdlr;
    FuncPtr         rarrow_hdlr;
    
} mmi_fmgr_cr_table_entry_ex_struct;
#endif


/****************************************************************************
* Global Variable
*****************************************************************************/


/****************************************************************************
* Static Variable
*****************************************************************************/

/****************************************************************************/
/*
 *  Application Title string / icon info
 */
#ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__
#ifdef APP_INFO
#undef APP_INFO
#endif
#define APP_INFO(app_id, string_id, root_menu_id) {app_id, string_id, root_menu_id},

const static mmi_fmgr_app_title_info_struct g_mmi_fmgr_app_title_info_table[] = 
{
    FMGR_APP_TABLE_COL
    {0, 0, 0}
};
#endif/*__MMI_ULTRA_SLIM_FILE_MANAGER__*/


/****************************************************************************/
/*
 *
 */
#ifdef FE_INFO
#undef FE_INFO
#endif
#define FE_INFO(menu_id, enabler) {menu_id, enabler},
 
const static mmi_fmgr_enabler_info_struct g_mmi_fmgr_fwd_enabler_table[] =
{
    FMGR_FWD_ENABLER_COL
    {0, NULL}
};

const static mmi_fmgr_enabler_info_struct g_mmi_fmgr_app_enabler_table[] =
{
    FMGR_APP_ENABLER_COL
    {0, NULL}
};

#ifdef __FMGR_HYPERLINK_SUPPORT__
/****************************************************************************/
/*
 *
 */
#ifdef HL_INFO
#undef HL_INFO
#endif
#define HL_INFO(app_id, path, callback) {app_id, (S8*)path, callback},
const static mmi_fmgr_hyperlink_table_entry_struct g_mmi_fmgr_hyperlink_table[] =
{
    FMGR_HYPERLINK_COL
    {0, NULL, NULL}
};
#endif

#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
/****************************************************************************/
/*
 *
 */
#ifdef CR_LINK_INFO
#undef CR_LINK_INFO
#endif
#define CR_LINK_INFO(path, string_id, icon_id) {path, FMGR_LINK_FOLDER, 0, string_id, icon_id},

#ifdef CR_DRV_INFO
#undef CR_DRV_INFO
#endif
#define CR_DRV_INFO(drive_type, string_id, icon_id) {NULL, drive_type, 0, string_id, icon_id},

#ifdef CR_LINK2_INFO
#undef CR_LINK2_INFO
#endif
#define CR_LINK2_INFO(string_id, icon_id, lsk_string_id, lsk_hdlr, rarrow_hdlr) {NULL, FMGR_LINK_ITEM, 0, string_id, icon_id},

const static mmi_fmgr_cr_table_entry_struct g_mmi_fmgr_cr_table[] = 
{
    FMGR_CUST_ROOT_COL
    {NULL, 0, 0, 0, 0}
};

#ifdef CR_LINK_INFO
#undef CR_LINK_INFO
#endif
#define CR_LINK_INFO(path, string_id, icon_id) 

#ifdef CR_DRV_INFO
#undef CR_DRV_INFO
#endif
#define CR_DRV_INFO(drive_type, string_id, icon_id) 

#ifdef CR_LINK2_INFO
#undef CR_LINK2_INFO
#endif
#define CR_LINK2_INFO(string_id, icon_id, lsk_string_id, lsk_hdlr, rarrow_hdlr) \
    {string_id, icon_id, lsk_string_id, lsk_hdlr, rarrow_hdlr},

const static mmi_fmgr_cr_table_entry_ex_struct g_mmi_fmgr_cr_table2[] = 
{
    FMGR_CUST_ROOT_COL
    {0, 0, 0, NULL, NULL}
};

#endif /* __FMGR_CUSTOM_ROOT_SUPPORT__ */

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/


#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function Body
*****************************************************************************/

#define FILE_TABLE_FUNC

#define APP_TABLE_FUNC

MMI_BOOL mmi_fmgr_get_app_title_info(U16 app_id, U16* title_id, U16* icon_id, S8* path)
{

#ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_fmgr_app_title_info_struct* info = NULL;
    S32 i;
    U16 icon, title;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Init return value */
    if (title_id)
    {
        *title_id = 0;
    }

    if (icon_id)
    {
        *icon_id = 0;
    }

    /* O(n) search */
    for (i=0; g_mmi_fmgr_app_title_info_table[i].app_id; i++)
    {
        if (app_id == g_mmi_fmgr_app_title_info_table[i].app_id)
        {
            info = &g_mmi_fmgr_app_title_info_table[i];
            break;
        }
    }

    if (!info)
    {
        return MMI_FALSE;
    }

    /* Default value */
    icon = 0;
    title = STR_FMGR_TITLE;

    /* Run-time decision */
    if (!info->title_id && !info->icon_menu_id) 
    {
        switch (app_id)
        {
        #ifdef __J2ME__
            case APP_JAVA:
                icon = mmi_java_get_install_title_icon();
                break;
        #endif /* __J2ME__ */
        #ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_MY_FAVORITE__ */
        #ifdef __MMI_OP01_DCD__
            case APP_DCD:
                icon = IMG_ID_DCD_SUB_ICON;
                break;
        #endif /* __MMI_OP01_DCD__ */
            default:
                break;
        }
    }
    else
    {
        icon = GetRootTitleIcon(info->icon_menu_id);
        title = info->title_id;
    }
    
    if (title_id)
    {
        *title_id = title;
    }

    if(icon_id)
    {
        *icon_id = icon;
    }
#else /*__MMI_ULTRA_SLIM_FILE_MANAGER__*/ 
    if (title_id)
    {
        *title_id = STR_FMGR_TITLE;
    }

    if(icon_id)
    {
        *icon_id = GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID);
    }
#endif /*__MMI_ULTRA_SLIM_FILE_MANAGER__*/  
    return MMI_TRUE;
}

mmi_fmgr_enabler_callback mmi_fmgri_table_get_forward_enabler(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while(g_mmi_fmgr_fwd_enabler_table[i].menu_id)
    {
        if(g_mmi_fmgr_fwd_enabler_table[i].menu_id == menu_id)
            return g_mmi_fmgr_fwd_enabler_table[i].enabler;
        i++;
    }
    return NULL;
}

mmi_fmgr_enabler_callback mmi_fmgri_table_get_option_enabler(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while(g_mmi_fmgr_app_enabler_table[i].menu_id)
    {
        if(g_mmi_fmgr_app_enabler_table[i].menu_id == menu_id)
            return g_mmi_fmgr_app_enabler_table[i].enabler;
        i++;
    }
    return NULL;
}

/* this is temporary for FMGR service call old style enabler */
//mick todo: should remove
void mmi_fmgri_table_do_enabler_for_service(mmi_menu_id menu_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_fmgr_enabler_callback enabler;
    S8 *buffer;
    FMGR_FILE_INFO_STRUCT *file_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    enabler = NULL;
    if(!enabler)
    {
        i = 0;
        while(g_mmi_fmgr_fwd_enabler_table[i].menu_id)
        {
            if(g_mmi_fmgr_fwd_enabler_table[i].menu_id == menu_id)
            {
                enabler = g_mmi_fmgr_fwd_enabler_table[i].enabler;
                break;
            }
            i++;
        }
    }
    if(!enabler)
    {
        i = 0;
        while(g_mmi_fmgr_app_enabler_table[i].menu_id)
        {
            if(g_mmi_fmgr_app_enabler_table[i].menu_id == menu_id)
            {
                enabler = g_mmi_fmgr_app_enabler_table[i].enabler;
                break;
            }
            i++;
        }
    }
    if(!enabler)
        return;

    file_info = OslMalloc(sizeof(FMGR_FILE_INFO_STRUCT));
    memset(file_info, 0, sizeof(FMGR_FILE_INFO_STRUCT));
    mmi_fmgr_get_file_info_by_path((S8*)filepath, file_info);
    buffer = mmi_fmgri_get_and_lock_buffer();
    mmi_ucs2cpy(buffer, (S8*)filepath);
    mmi_fmgri_query_result_setup(buffer, file_info, 0);
    enabler(menu_id, file_info);
    mmi_fmgri_query_result_clear();
    mmi_fmgri_free_and_unlock_buffer(buffer);
    OslMfree(file_info);
}


#define HYPERLINK_API

#ifdef __FMGR_HYPERLINK_SUPPORT__
mmi_fmgr_hyperlink_callback mmi_fmgri_table_get_hyperlink_callback(U16 app_id, S8* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_fmgr_hyperlink_table_entry_struct *entry;
    S32 len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_ASSERT(path);

    entry = g_mmi_fmgr_hyperlink_table;
    
    len = mmi_ucs2strlen(path);
    while(entry->app_id || entry->path || entry->callback)
    {
        /* callback must not NULL */
        FMGR_ASSERT(entry->callback);
        
        if(entry->app_id == app_id)
        {
            if(!entry->path)
                return entry->callback;
            if(len == 3 && mmi_ucs2cmp(entry->path, (S8*)L"\\") == 0)
                return entry->callback;
            if(len > 3 && mmi_ucs2icmp(path+6, entry->path) == 0)
                return entry->callback;
        }
        entry++;
    }
    return NULL;
}
#endif

#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__

S32 mmi_fmgri_table_cr_get_count(SRV_FMGR_DRVLIST_HANDLE drvlist_hdl, S8 exclude_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_fmgr_cr_table_entry_struct* mf_info;
    S32 count = 0, index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (mf_info = g_mmi_fmgr_cr_table; mf_info->drv_type || mf_info->path; mf_info++)
    {
        if (mf_info->drv_type < 0)
        {
            if (exclude_item && mf_info->drv_type == FMGR_LINK_ITEM)
            {
                continue;
            }
            count++;
        }
        else
        {
            index = srv_fmgr_drivelist_get_index_by_drv_type(drvlist_hdl, mf_info->drv_type);            
            if (srv_fmgr_drv_is_accessible(srv_fmgr_drivelist_get_drv_letter(drvlist_hdl, index)) == MMI_TRUE)
            {
                count++;
            }
        }
    }
    return count;
}

MMI_BOOL mmi_fmgri_table_cr_get_info(SRV_FMGR_DRVLIST_HANDLE drvlist_hdl, S32 index, fmgr_drive_info_struct* info, S8 exclude_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_fmgr_cr_table_entry_struct* mf_info;
    const mmi_fmgr_cr_table_entry_ex_struct* ex_info;
    S32 count = 0, drv_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for(mf_info = g_mmi_fmgr_cr_table; mf_info->drv_type || mf_info->path; mf_info++)
    {
        if(mf_info->drv_type < 0)
        {
            if(exclude_item && mf_info->drv_type == FMGR_LINK_ITEM)
            {
                continue;
            }
            count++;
        }
        else
        {
            drv_index = srv_fmgr_drivelist_get_index_by_drv_type(drvlist_hdl, mf_info->drv_type);            
            if (srv_fmgr_drv_is_accessible(srv_fmgr_drivelist_get_drv_letter(drvlist_hdl, drv_index)) == MMI_TRUE)
            {
                count++;
            }
        }

        if(count == index + 1)
        {
            if(mf_info->drv_type == FMGR_LINK_FOLDER)
            {
                kal_wsprintf(info->drv_path, "%c:\\", SRV_FMGR_PUBLIC_DRV);
                mmi_wcscat(info->drv_path, mf_info->path);
            }
            else if(mf_info->drv_type >= 0)
            {
                mmi_ucs2cpy((S8*)info->drv_path, (S8*) srv_fmgr_drv_get_path_by_type(mf_info->drv_type));
            }
            
            info->drv_type = mf_info->drv_type;
            info->string_id = mf_info->string_id;
            info->icon_id = mf_info->icon_id;
            
            if(info->drv_type == FMGR_LINK_ITEM)
            {
                FMGR_ASSERT(info->string_id || info->icon_id);

                for(ex_info = g_mmi_fmgr_cr_table2; ex_info->string_id || ex_info->icon_id; ex_info++)
                {
                    if(info->string_id == ex_info->string_id && info->icon_id == ex_info->icon_id)
                    {
                        info->lsk_string_id = ex_info->lsk_string_id;
                        info->lsk_hdlr = ex_info->lsk_hdlr;
                        info->rarrow_hdlr = ex_info->rarrow_hdlr;
                    }
                }
            }

        #ifdef FMGR_TAB_SUPPORT
            /* return tab info */
            if(mf_info->drv_type == FMGR_LINK_FOLDER ||mf_info->drv_type >= 0)
            {
                info->tab_id = (U32)mf_info;
            }
        #endif /* FMGR_TAB_SUPPORT */

            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

S32 mmi_fmgri_table_cr_get_index(const U16* path, S8 exclude_item, S8 full_match, U8 drv_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_fmgr_cr_table_entry_struct* mf_info;
    SRV_FMGR_DRVLIST_HANDLE drvlist_hdl;
    U8 drv_letter;
    U16 path_buf[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    S32 count, index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for (mf_info = g_mmi_fmgr_cr_table, count=0; mf_info->drv_type || mf_info->path; mf_info++)
    {
        if (mf_info->drv_type < 0)
        {
            if (exclude_item && mf_info->drv_type == FMGR_LINK_ITEM)
            {
                continue;
            }
            count++;
        }
        else
        {
            drvlist_hdl = srv_fmgr_drivelist_create(drv_type);
            if (srv_fmgr_drivelist_get_index_by_drv_type(drvlist_hdl, mf_info->drv_type) != -1)
            {
                count++;
            }
        }

        if (mf_info->drv_type >= 0)
        {
            index = srv_fmgr_drivelist_get_index_by_drv_type(drvlist_hdl, mf_info->drv_type);
            if (index != -1)
            {           
                drv_letter = srv_fmgr_drivelist_get_drv_letter(drvlist_hdl, index);
                kal_wsprintf(path_buf, "%c:\\", drv_letter);
            }
            srv_fmgr_drivelist_destroy(drvlist_hdl);
        }
        else if (mf_info->drv_type == FMGR_LINK_FOLDER)
        {
            kal_wsprintf(path_buf, "%c:\\", SRV_FMGR_PUBLIC_DRV);
            mmi_wcscat(path_buf, mf_info->path);
        }
        else if (mf_info->drv_type == FMGR_LINK_ITEM)
        {
            kal_wsprintf(path_buf, "%d", mf_info->string_id);
        }
        else
        {
            continue;
        }

        if (full_match)
        {
            if (mmi_wcscmp(path, path_buf) == 0)
            {
                return count -1;
            }
        }
        else
        {
            if (mmi_wcsncmp(path, path_buf, mmi_wcslen(path_buf)) == 0)
            {
                return count -1;
            }
        }
    }
    return -1;
}

#ifdef FMGR_TAB_SUPPORT
S32  mmi_fmgri_table_tab_get_count(U32 tab_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_fmgr_cr_table_entry_struct* mf_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mf_info = (const mmi_fmgr_cr_table_entry_struct*)tab_id;

    switch (mf_info->drv_type)
    {
        case FMGR_LINK_FOLDER:
            return 2;
        default:
            return 1;
    }
}

S32  mmi_fmgri_table_tab_get_path(U32 tab_id, S32 tab_index, WCHAR* path_buf, U32 path_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_fmgr_cr_table_entry_struct* mf_info;
    mmi_fmgr_instance_struct* instance;
    SRV_FMGR_DRVLIST_HANDLE drvlist_hdl;
    U8 drv_letter;
    S32 index;
    S8 drv;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mf_info = (const mmi_fmgr_cr_table_entry_struct*)tab_id;

    switch (mf_info->drv_type)
    {
        case FMGR_LINK_FOLDER:
            if (tab_index == 0)
            {
                drv = SRV_FMGR_PUBLIC_DRV;
            }
            else
            {
                drv = SRV_FMGR_CARD_DRV;
            }
        
            kal_wsprintf(path_buf, "%c:\\", drv);
            mmi_wcscat(path_buf, mf_info->path);
            break;

        default:
            instance = mmi_fmgri_get_active_instance();
            drvlist_hdl = srv_fmgr_drivelist_create(instance->drv_type);
            index = srv_fmgr_drivelist_get_index_by_drv_type(drvlist_hdl, mf_info->drv_type);
            if (index != -1)
            {
                drv_letter = srv_fmgr_drivelist_get_drv_letter(drvlist_hdl, index);
                kal_wsprintf(path_buf, "%c:\\", drv_letter);
            }
            srv_fmgr_drivelist_destroy(drvlist_hdl);
            break;
    }
    
    return 0;
}

U16  mmi_fmgri_table_tab_get_icon(U32 tab_id, S32 tab_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_fmgr_cr_table_entry_struct* mf_info;
    U16 icon_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mf_info = (const mmi_fmgr_cr_table_entry_struct*)tab_id;

    switch(mf_info->drv_type)
    {
    case FMGR_LINK_FOLDER:
        if(tab_index == 0)
            icon_id = IMG_ID_FMGR_TAB_PHONE;
        else
            icon_id = IMG_ID_FMGR_TAB_CARD;
        break;

    default:
        icon_id = IMG_ID_FMGR_TAB_CARD;
        break;
    }
    
    return icon_id;
}

U16  mmi_fmgri_table_tab_get_title(U32 tab_id, S32 tab_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return ((const mmi_fmgr_cr_table_entry_struct*)tab_id)->string_id;
}

S32  mmi_fmgri_table_tab_get_index(U32 tab_id, const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_fmgr_cr_table_entry_struct* mf_info;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mf_info = (const mmi_fmgr_cr_table_entry_struct*)tab_id;

    if (!path)
    {
        return 0;
    }

    switch (mf_info->drv_type)
    {
        case FMGR_LINK_FOLDER:
            if (path[0] == SRV_FMGR_PUBLIC_DRV)
            {
                index = 0;
            }
            else
            {
                index = 1;
            }
            break;

        default:
            index = 0;
            break;
    }

    return index;
}

MMI_BOOL mmi_fmgri_table_tab_switch(U32 tab_id, WCHAR* path, U32 path_size, S8 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_fmgr_cr_table_entry_struct* mf_info;
    S32 index, count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mf_info = (const mmi_fmgr_cr_table_entry_struct*)tab_id;

    count = mmi_fmgri_table_tab_get_count(tab_id);
    if (count <= 1)
    {
        return MMI_FALSE;
    }
    index = mmi_fmgri_table_tab_get_index(tab_id, path);
    index = (index + offset) % count;

    mmi_fmgri_table_tab_get_path(tab_id, index, path, path_size);
    return MMI_TRUE;
}

S32  mmi_fmgri_table_tab_get_root_index(U32 tab_id, const U16* path, U8 drv_type, S8 exclude_item, S8 full_match)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_fmgr_cr_table_entry_struct* mf_info;
    SRV_FMGR_DRVLIST_HANDLE drvlist_hdl;
    U8 drv_letter;
    U16 path_buf[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    S32 count, index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mf_info = (const mmi_fmgr_cr_table_entry_struct*)tab_id;
    drvlist_hdl = srv_fmgr_drivelist_create(drv_type);

    if (mf_info->drv_type >= 0)
    {
        index = srv_fmgr_drivelist_get_index_by_drv_type(drvlist_hdl, mf_info->drv_type);
        if (index != -1)
        {
            drv_letter = srv_fmgr_drivelist_get_drv_letter(drvlist_hdl, index);
            kal_wsprintf(path_buf, "%c:\\", drv_letter);
        }
    }
    else if (mf_info->drv_type == FMGR_LINK_FOLDER)
    {
        kal_wsprintf(path_buf, "%c:\\", path[0]);
        mmi_wcscat(path_buf, mf_info->path);
    }
    else
    {
        return -1;
    }

    if (full_match)
    {
        if (mmi_wcscmp(path, path_buf))
            return -1;
    }
    else
    {
        if (mmi_wcsncmp(path, path_buf, mmi_wcslen(path_buf)))
            return -1;
    }
    
    for (mf_info = g_mmi_fmgr_cr_table, count = 0; mf_info->drv_type || mf_info->path; mf_info++)
    {
        if (mf_info->drv_type < 0)
        {
            if(exclude_item && mf_info->drv_type == FMGR_LINK_ITEM)
            {
                continue;
            }
            count++;
        }
        else
        {
            if (srv_fmgr_drivelist_get_index_by_drv_type(drvlist_hdl, mf_info->drv_type) != -1)
            {
               count++;
            }
        }

        if (tab_id == (U32)mf_info)
        {
            srv_fmgr_drivelist_destroy(drvlist_hdl);
            return count-1;
        }
    }
    srv_fmgr_drivelist_destroy(drvlist_hdl);
    return -1;
}

#endif /* FMGR_TAB_SUPPORT */
#endif /* __FMGR_CUSTOM_ROOT_SUPPORT__ */
#endif /* __MMI_FILE_MANAGER__ */




