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
 *  AppListData.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AppList Applications v0.1
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files
*****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_LAUNCHER_APP_LIST__)

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "AppListGProt.h"
#include "AppList.h"
#include "AppListDef.h"
#include "AppMgrSrvGprot.h"
#include "IdleMemCfg.h"
#include "mmi_rp_app_applist_def.h"
#include "AppListIconTable.h"
#ifdef __MMI_APPLIST_BARREL_SUPPORT__
#include "AppListBarrel.h"
#endif
#if defined(__MMI_PHNSET_APPICON_SUPPORT__) || defined(__MMI_DOWNLOADABLE_APPICON_SUPPORT__)
#include "CustVenusThemeRes.h"
#include "Mmi_rp_srv_wallpaper_def.h"
#endif

#ifdef __MTK_TARGET__
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

/*
SWLA labels:
ALD   -- Load Data
*/


const mmi_app_package_name_struct g_mmi_applist_default_order[] = 
{
#if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    "native.mtk.op01_monternet",
    "native.mtk.op01_mobile_portal",
#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
    "native.mtk.dtvplayer",
#endif
    "native.mtk.customerservice",
    "native.mtk.phonebookmanager",
    "native.mtk.myfavorite",
    "native.mtk.op01_fetion",
    "native.mtk.op01_mobile_market",
    "native.mtk.op01_139_push_mail",
    "native.mtk.op01_music_walkman",
    "native.mtk.op01_mobile_read",
    "native.mtk.op01_mobile_game",
    "native.mtk.op01_mobile_stock",
#endif
#ifdef __MMI_TELEPHONY_SUPPORT__
    "native.mtk.dialer",
    "native.mtk.messaging",
    "native.mtk.phonebook",
    "native.mtk.calllog",
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#ifdef __OP02_0200__
    "native.mtk.mobile_internet",
    "native.mtk.wo_store",
    "native.mtk.lemei",
    "native.mtk.online_sales",
#endif
#ifdef __MMI_MEDIA_PLAYER__
    "native.mtk.mediaplayer",
#endif
    "native.mtk.filemgr",
    "native.mtk.imageviewer",
    "native.mtk.setting",
#if defined(__MMI_YOUTUBE_SHORTCUT__)
    "native.mtk.youtube",
#endif
    "native.mtk.calendar",
#if defined(__MMI_CAMCORDER__)
    "native.mtk.camcorder",
#endif
    "native.mtk.alarm",
    "native.mtk.calculator",
    "native.mtk.sndrec",
    "native.mtk.connectivity",
#if defined(__MMI_TODOLIST__)
    "native.mtk.todo",
#endif
    "native.mtk.fmrdo",
    "native.mtk.worldclock",
    "native.mtk.services_sat",
#ifdef __MMI_APPLIST_BARREL_SUPPORT__
    "native.mtk.barrel"
#endif
};

const S32 mmi_applist_default_order_count = sizeof(g_mmi_applist_default_order) / sizeof(mmi_app_package_name_struct);


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_allocate_appmgr_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_allocate_appmgr_list(
        mmi_app_package_name_struct **array, U32 *total_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count, pre_count, name_count, i;
    mmi_ret result;
    mmi_app_package_name_struct *name;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pre_count = srv_appmgr_get_app_package_num(
                SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);

    count = srv_appmgr_get_app_package_num(
                SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);

    
    name_count = count + pre_count;       
        
    name = (mmi_app_package_name_struct *) kal_adm_alloc(
            applist_p->adm_pool_id,
            sizeof(mmi_app_package_name_struct) * name_count);
    ASSERT(name != NULL); 

    kal_mem_set(name, 0, sizeof(mmi_app_package_name_struct) * name_count);    
    
    //preinstall first
    result = srv_appmgr_get_app_package_list(
                SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE, 
                name, pre_count);    
    ASSERT(result != MMI_RET_ERR);

    memset(applist_p->preinstall_id, 0, 4 * MMI_APPLIST_PANEL_APP_NUM);  //sizeof(U32) = 4

    for (i = 0; i < pre_count; i++)
    {
        applist_p->preinstall_id[i] = 
        srv_appmgr_get_id_by_app_package_name(name[i]);
    }
    
    result = srv_appmgr_get_app_package_list(
                SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE, 
                name + pre_count, count);
    ASSERT(result != MMI_RET_ERR);

    /* Assign output value */
    *array = name;
    *total_count = name_count;
    RANFOW_TRACE("[APPLIST]mmi_applist_allocate_appmgr_list[pre_count=%d,count=%d]\n", pre_count, count);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_release_appmgr_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_release_appmgr_list(mmi_app_package_name_struct *array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* free memory */
    kal_adm_free(applist_p->adm_pool_id, (void *) array);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_load_default_order_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_load_default_order_table()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 app_id;
    S32 i, bar_idx, panel_idx;
    mmi_app_package_name_struct name;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Load app list */
    bar_idx = 0;
    panel_idx = 0;
    for (i = 0; i < mmi_applist_default_order_count; i ++)
    {

        /* Copy to non-const variable to fix build error */
        strncpy(name, g_mmi_applist_default_order[i], MMI_APP_NAME_MAX_LEN - 1);
        app_id = srv_appmgr_get_id_by_app_package_name(name);
        
        if (i < MMI_APPLIST_BAR_APP_NUM)
        {
            applist_p->data.bar_id[bar_idx] = app_id;
            bar_idx ++;
        }
        else
        {
            applist_p->data.panel_id[panel_idx] = app_id;
            panel_idx ++;
        }                
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_mark_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_mark_exist(
            S32 index, U32 app_id, mmi_app_package_name_struct *array, U32 array_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 j;
    U32 array_id;
    MMI_BOOL found = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (j = 0; j < array_count; ++j)
    {
        if (strncmp(array[j], "ADDED", MMI_APP_NAME_MAX_LEN) != 0)
        {
            array_id = srv_appmgr_get_id_by_app_package_name(array[j]);

            if (app_id == array_id)
            {                
                #ifdef __MMI_APPLIST_CACHE_APP_NAME__
                mmi_ucs2ncpy((CHAR *)applist_p->app_name[index], (CHAR *)array[j], MMI_APP_NAME_MAX_LEN);
                #endif
                strncpy(array[j], "ADDED", MMI_APP_NAME_MAX_LEN - 1);
                found = MMI_TRUE;
                break;
            }
        }
    }
    return found;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_compact_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_compact_list(S32 start_idx, U32 *list, S32 list_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < list_len; i++)
    {
        if (list[i] != 0)
        {
            continue;
        }

        for (j= i + 1; j < list_len; j ++)
        {
            if (list[j] != 0)
            {
                list[i] = list[j];
                list[j] = 0;
                #ifdef __MMI_APPLIST_CACHE_APP_NAME__
                mmi_ucs2ncpy((CHAR*)applist_p->app_name[start_idx+i], (CHAR*)applist_p->app_name[start_idx+j], MMI_APP_NAME_MAX_LEN);
                memset(applist_p->app_name[start_idx+j], 0, MMI_APP_NAME_MAX_LEN);
                #endif
                break;
            }
        }

        /* Not found */
        if (j == list_len)
        {
            break;
        }
    }  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_if_shortcut_bar_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_if_shortcut_bar_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < MMI_APPLIST_BAR_APP_NUM; i ++)
    {
        if (applist_p->data.bar_id[i] == 0)
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_if_panel_page_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_if_panel_page_full(S32 page_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, idx_from, idx_to;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_applist_get_page_cell_idx(page_idx, &idx_from, &idx_to);
    
    for (i = idx_to; i >= idx_from; i --)
    {
        if (applist_p->data.panel_id[i] == 0)
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_sync_appmgr_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_sync_appmgr_list(
        mmi_app_package_name_struct *array, U32 array_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, array_idx, in_page_len, append_idx;
    U32 app_id;
    MMI_BOOL exist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RANFOW_TRACE("[APPLIST]mmi_applist_sync_appmgr_list start\n");
    #ifdef __MMI_APPLIST_CACHE_APP_NAME__
    memset(applist_p->app_name, 0, MMI_APP_NAME_MAX_LEN * MMI_APPLIST_ENTRY_NUM);
    #endif

    /* Validate bar item */
    for (i = 0; i < MMI_APPLIST_BAR_APP_NUM; ++i)
    {        
        exist = mmi_applist_mark_exist(
                    i, applist_p->data.bar_id[i], array, array_count);
        if (!exist)
        {
            applist_p->data.bar_id[i] = 0;
        }
    }
    
    /* Validate panel item */
    for (i = 0; i < MMI_APPLIST_PANEL_APP_NUM; ++i)
    {        
        exist = mmi_applist_mark_exist(
                    MMI_APPLIST_BAR_APP_NUM+i, applist_p->data.panel_id[i], array, array_count);
        if (!exist)
        {
            applist_p->data.panel_id[i] = 0;
        }
    }
    
    /* Compact bar item */
    mmi_applist_compact_list(0, applist_p->data.bar_id, MMI_APPLIST_BAR_APP_NUM);

    /* Compact panel item */
    in_page_len = MMI_APPLIST_APP_COUNT_PER_PAGE;
    array_idx = 0;
    for (i = 0; i < MMI_APPLIST_MAX_PAGE_NUM; ++i)
    {       
        if (array_idx + in_page_len > MMI_APPLIST_PANEL_APP_NUM)
        {
            in_page_len = MMI_APPLIST_PANEL_APP_NUM - array_idx;
        }
        mmi_applist_compact_list(
            MMI_APPLIST_BAR_APP_NUM+array_idx, &applist_p->data.panel_id[array_idx], in_page_len);

        array_idx += in_page_len;
    }

    /* Append added list */
    append_idx = mmi_applist_get_last_panel_index() + 1;

    for (i = 0; i < array_count; ++i)
    {
        if (strncmp(array[i], "ADDED", MMI_APP_NAME_MAX_LEN) == 0)
        {
            continue;
        }

        if (append_idx >= MMI_APPLIST_PANEL_APP_NUM)
        {
            //last page is full, search forward
            S32 idx = MMI_APPLIST_MAX_PAGE_NUM - 2;
            while (idx >= 0)
            {
                if (!mmi_applist_if_panel_page_full(idx))
                {
                    append_idx = mmi_applist_get_last_panel_index_in_page(idx) + 1;
                    break;
                }
                idx--;
            }
            
            if (append_idx >= MMI_APPLIST_PANEL_APP_NUM)  //all pages are full
                break;
        }

        app_id = srv_appmgr_get_id_by_app_package_name(array[i]);
        applist_p->data.panel_id[append_idx] = app_id;
        #ifdef __MMI_APPLIST_CACHE_APP_NAME__
        mmi_ucs2ncpy((CHAR *)applist_p->app_name[MMI_APPLIST_BAR_APP_NUM+append_idx], (CHAR *)array[i], MMI_APP_NAME_MAX_LEN);
        #endif
        append_idx ++;        
    }

    //applist_p->mainmenu_need_sync = MMI_FALSE;  //do this on enter
    RANFOW_TRACE("[APPLIST]mmi_applist_sync_appmgr_list end\n");
}


#ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_installed_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_get_installed_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result;
    mmi_app_package_name_struct *name;
    U32 installed_count, i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    installed_count = srv_appmgr_get_app_package_num(
                SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    
    if (installed_count > 0)
    {
        name = (mmi_app_package_name_struct *) kal_adm_alloc(
                applist_p->adm_pool_id,
                sizeof(mmi_app_package_name_struct) * installed_count);
        ASSERT(name != NULL); 

        kal_mem_set(name, 0, sizeof(mmi_app_package_name_struct) * installed_count);    
    
        result = srv_appmgr_get_app_package_list(
                    SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE, 
                    name, installed_count);
        
        ASSERT(result != MMI_RET_ERR);

        for (i = 0; i < installed_count; i++)
        {
            applist_p->installed_id[i] = 
            srv_appmgr_get_id_by_app_package_name(name[i]);
        }
    
        kal_adm_free(applist_p->adm_pool_id, (void *)name);
    }
}

#endif  //__MMI_APPLIST_APP_UNINSTALL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_load_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_load_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    mmi_app_package_name_struct *app_list = NULL;
    U32 app_count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_load_data start\n");
    SLA_CustomLogging("ALD", SA_start);
#endif
    
    ReadRecord(
        NVRAM_EF_APPLIST_DATA_LID,
        1,
        (void*)&applist_p->data,
        NVRAM_EF_APPLIST_DATA_SIZE,
        &error);

    if (applist_p->mainmenu_need_sync)
    {
        mmi_applist_allocate_appmgr_list(&app_list, &app_count);

        //TODO: check if criteria is correct
        if (applist_p->data.panel_id[0] == 0 && applist_p->data.panel_id[1] == 0)
        {
             mmi_applist_load_default_order_table();
        }

        mmi_applist_sync_appmgr_list(app_list, app_count);
        mmi_applist_release_appmgr_list(app_list);

        #ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
        memset(applist_p->installed_id, 0, 4 * MMI_APPLIST_PANEL_APP_NUM);  //sizeof(U32) = 4
        #endif
    }

#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_load_data end\n");
    SLA_CustomLogging("ALD", SA_stop);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_save_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_save_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    WriteRecord(
        NVRAM_EF_APPLIST_DATA_LID,
        1,
        (void*)&(applist_p->data),
        NVRAM_EF_APPLIST_DATA_SIZE,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_last_bar_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_last_bar_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MMI_APPLIST_BAR_APP_NUM - 1; i >= 0; --i)
    {        
        if (applist_p->data.bar_id[i] != 0)
        {
            return i;
        }
    }
    return MMI_APPLIST_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_last_panel_index_in_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_last_panel_index_in_page(S32 page_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx_from, idx_to, i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_applist_get_page_cell_idx(page_idx, &idx_from, &idx_to);
    
    for (i = idx_to; i >= idx_from; --i)
    {        
        if (applist_p->data.panel_id[i] != 0)
        {
            return i;
        }
    }
    
    return MMI_APPLIST_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_last_panel_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_last_panel_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MMI_APPLIST_PANEL_APP_NUM - 1; i >= 0; --i)
    {        
        if (applist_p->data.panel_id[i] != 0)
        {
            break;
        }
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_bar_start_x
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_bar_start_x(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_APPLIST_SHORTCUT_AUTO_REPOSITION__
    return (LCD_WIDTH - (mmi_applist_get_last_bar_index()+1) * MMI_APPLIST_CELL_WIDTH)/2;
    #else
    return 0;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_page_cell_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_get_page_cell_idx(S32 page_idx, S32 *idx_from, S32 *idx_to)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 max_idx = mmi_applist_get_last_panel_index();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *idx_from = page_idx * MMI_APPLIST_APP_COUNT_PER_PAGE;
    *idx_to = (page_idx + 1) * MMI_APPLIST_APP_COUNT_PER_PAGE - 1;

    if (*idx_from > MMI_APPLIST_PANEL_APP_NUM - 1)
    {
        *idx_from = MMI_APPLIST_PANEL_APP_NUM - 1;
    }
    if (*idx_to > MMI_APPLIST_PANEL_APP_NUM - 1)
    {
        *idx_to = MMI_APPLIST_PANEL_APP_NUM - 1;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_last_empty_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_last_empty_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, page_num, last_idx, to_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    page_num = mmi_applist_get_current_page_num();

    for (i = page_num - 1; i >= 0; i --)
    {
        last_idx = mmi_applist_get_last_panel_index_in_page(i);

        /* Page is empty */
        if (last_idx == MMI_APPLIST_INVALID_INDEX)
        {
            return i * MMI_APPLIST_APP_COUNT_PER_PAGE;
        }
        
        to_idx = (i + 1) * MMI_APPLIST_APP_COUNT_PER_PAGE - 1;
        if (last_idx < to_idx)
        {
            return last_idx + 1;
        }
    }
    /* Page is full */
    return MMI_APPLIST_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_current_page_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_current_page_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (applist_p->mode == MMI_APPLIST_MODE_EDIT)
    {
        return applist_p->edit_page_num;
    }
    else
    {
        idx = mmi_applist_get_last_panel_index();

        return (idx + MMI_APPLIST_APP_COUNT_PER_PAGE) / 
               MMI_APPLIST_APP_COUNT_PER_PAGE;
    }   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_current_page_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_current_page_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 page_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    page_idx = applist_p->slide_region.x / (MMI_APPLIST_PAGE_WIDTH_INC_MARGIN);

    if (applist_p->slide_region.slide_dir == MMI_APPLIST_DIR_LEFT)
    {
        if (applist_p->slide_region.x % (MMI_APPLIST_PAGE_WIDTH_INC_MARGIN) > 0)
        {//it should still in current page
            page_idx += 1;
        }
    }
    
    if (page_idx < 0)
    {
        page_idx = 0;
    }
    else if (page_idx >= MMI_APPLIST_MAX_PAGE_NUM)
    {
        page_idx = MMI_APPLIST_MAX_PAGE_NUM - 1;
    }    
    return page_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_current_page_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_final_page_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 page_idx;
    S32 slide_x;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->slide_region.anima_node_p)
    {
        slide_x = applist_p->slide_region.anima_node_p->to.pos_x;
    }
    else
    {
        slide_x = applist_p->slide_region.x;
    }

    page_idx = slide_x /(MMI_APPLIST_PAGE_WIDTH_INC_MARGIN);

    if (page_idx < 0)
    {
        page_idx = 0;
    }
    else if (page_idx >= MMI_APPLIST_MAX_PAGE_NUM)
    {
        page_idx = MMI_APPLIST_MAX_PAGE_NUM - 1;
    }    
    return page_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_cell_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_applist_cell_struct *mmi_applist_get_cell_ptr(
                            mmi_applist_cell_type_enum type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (type)
    {
        case MMI_APPLIST_CELL_TYPE_PANEL:
            if (index == MMI_APPLIST_CACHE_INDEX)
            {
                return applist_p->cache_cell.cell_p;  
            }
            else
            {
                return applist_p->panel_cell[index];
            }
        case MMI_APPLIST_CELL_TYPE_SHORTCUT: 
            return applist_p->bar_cell[index];
        default:
            return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_scell_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_applist_get_cell_id(mmi_applist_cell_type_enum type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    switch (type)
    {
        case MMI_APPLIST_CELL_TYPE_PANEL:
            return applist_p->data.panel_id[index];
        case MMI_APPLIST_CELL_TYPE_SHORTCUT: 
            return applist_p->data.bar_id[index];
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_validate_slide_x
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_validate_slide_x(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 max, page_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //TODO: has bug
    
    page_num = mmi_applist_get_current_page_num();

    max = (page_num - 1) * MMI_APPLIST_PAGE_WIDTH_INC_MARGIN;
    if (applist_p->slide_region.x > max)
    {
        applist_p->slide_region.x = max;
    }
    else if (applist_p->slide_region.x < 0)
    {
        applist_p->slide_region.x = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_panel_cell_location
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_get_panel_cell_location(
        S32 cell_idx, S32 *page_idx, S32 *step_x, S32 *step_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *page_idx = cell_idx / MMI_APPLIST_APP_COUNT_PER_PAGE;
    icon_idx = cell_idx - (*page_idx * MMI_APPLIST_APP_COUNT_PER_PAGE);
    *step_x = icon_idx % MMI_APPLIST_CELL_COLUMN_COUNT;
    *step_y = icon_idx / MMI_APPLIST_CELL_COLUMN_COUNT;
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_cell_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_get_cell_position(
        mmi_applist_cell_type_enum cell_type,
        S32 cell_idx,
        mmi_applist_position *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, x_base;
    S32 page_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cell_type == MMI_APPLIST_CELL_TYPE_SHORTCUT)
    {
        #ifdef __MMI_APPLIST_SHORTCUT_AUTO_REPOSITION__
        pos->x = mmi_applist_get_bar_start_x() + cell_idx * MMI_APPLIST_CELL_WIDTH + MMI_APPLIST_CELL_WIDTH/2;
        #else
        pos->x = (cell_idx * MMI_APPLIST_CELL_WIDTH) + MMI_APPLIST_CELL_WIDTH/2;
        #endif
        pos->y = MMI_APPLIST_SHORTCUT_BAR_Y + MMI_APPLIST_CELL_HEIGHT/2;
    }
    else /* Panel */
    {
        mmi_applist_get_panel_cell_location(cell_idx, &page_idx, &x, &y);
        x_base = page_idx * (LCD_WIDTH + MMI_APPLIST_INTER_PAGE_MARGIN); 
        
        pos->x = x_base + x * MMI_APPLIST_CELL_WIDTH + MMI_APPLIST_CELL_WIDTH/2;
        pos->y = MMI_APPLIST_SLIDE_AREA_Y + y * MMI_APPLIST_CELL_HEIGHT + MMI_APPLIST_CELL_HEIGHT/2;
    }  
}



/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_cell_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_cell_idx(S32 page_idx, S32 step_x, S32 step_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Security check */
    if (step_x >= MMI_APPLIST_CELL_COLUMN_COUNT)
    {
        step_x = MMI_APPLIST_CELL_COLUMN_COUNT - 1;
    }

    if (step_y >= MMI_APPLIST_CELL_ROW_COUNT)
    {
        step_y = MMI_APPLIST_CELL_ROW_COUNT - 1;
    }    
    
    return page_idx * MMI_APPLIST_APP_COUNT_PER_PAGE + 
           step_y * MMI_APPLIST_CELL_COLUMN_COUNT + step_x;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_if_panel_page_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_if_panel_page_empty(S32 page_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx_from;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_from = page_idx * MMI_APPLIST_APP_COUNT_PER_PAGE;

    if (applist_p->panel_cell[idx_from])
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_set_bar_cell_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_set_bar_cell_position(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_applist_position pos;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < MMI_APPLIST_BAR_APP_NUM; i ++)
    {
        if (applist_p->bar_cell[i] != NULL)
        {
            mmi_applist_get_cell_position(
                MMI_APPLIST_CELL_TYPE_SHORTCUT, i, &pos);
            applist_p->bar_cell[i]->pos = pos;
        }
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_set_panel_cell_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_set_panel_cell_position(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_applist_position pos;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < MMI_APPLIST_PANEL_APP_NUM; i ++)
    {
        if (applist_p->panel_cell[i] != NULL)
        {
            mmi_applist_get_cell_position(
                MMI_APPLIST_CELL_TYPE_PANEL, i, &pos);
            applist_p->panel_cell[i]->pos = pos;
        }
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_self_icon_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_applist_get_self_icon_id(mmi_app_package_name_struct *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID new_icon = 0;
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < g_mmi_applist_icon_table_len; i ++)
    {
        if(strncmp((CHAR *)app_name, g_mmi_applist_icon_table[i].app_name, MMI_APP_NAME_MAX_LEN) == 0)
        {
            new_icon = g_mmi_applist_icon_table[i].image_icon;
            break;
        }
    }
    return new_icon;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_set_appmgr_cell_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_set_appmgr_cell_info(S32 index, U32 app_id, mmi_applist_cell_struct *cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_app_package_name_struct pac_name = {0};
    srv_app_info_struct info;
    mmi_ret result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #ifdef __MMI_APPLIST_CACHE_APP_NAME__
    mmi_ucs2ncpy((CHAR *)pac_name, (CHAR *)applist_p->app_name[index], MMI_APP_NAME_MAX_LEN);
    #else
    srv_appmgr_get_app_package_name_by_id(app_id, pac_name);
    #endif
    
    result = srv_appmgr_get_app_package_info(pac_name, &info);
    ASSERT(result != MMI_RET_ERR);

    /* image */
    if (info.image.type == MMI_IMAGE_SRC_TYPE_RES_ID)
    {
        /* Use self-defined icon */
        cell->image.res_id = mmi_applist_get_self_icon_id(&pac_name);
        if(cell->image.res_id == 0)
        {
            cell->image.res_id = info.image.data.res_id;
        }
    }
    else if(info.image.type == MMI_IMAGE_SRC_TYPE_ROM_MEMORY)
    {
        cell->image_ptr = info.image.data.image.image_ptr;
        cell->image_len = info.image.data.image.image_len;
    }
    else if (info.image.type == MMI_IMAGE_SRC_TYPE_PATH)
    {
        mmi_ucs2ncpy(
            (CHAR *)cell->image.path,
            (const CHAR *)info.image.data.path,
            MMI_MAX_FILE_NAME_LEN);
    }
    else
    {
        ASSERT(0);
    }

    cell->image_type = info.image.type;
    cell->app_id = app_id;

    /* name */
    mmi_ucs2ncpy((CHAR *)cell->name, (CHAR *)info.string, MMI_APP_NAME_MAX_LEN);

    /* Type */
    cell->type = srv_appmgr_get_app_package_type(pac_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_is_preinstall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_is_preinstall(U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_APPLIST_PANEL_APP_NUM; i++)
    {
        if (applist_p->preinstall_id[i] == 0)
            break;
        if (applist_p->preinstall_id[i] == app_id)
            return MMI_TRUE;
    }
    return MMI_FALSE;
}


#ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_is_installed_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_is_installed_app(U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_APPLIST_PANEL_APP_NUM; i++)
    {
        if (applist_p->installed_id[i] == 0)
            break;
        if (applist_p->installed_id[i] == app_id)
            return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif  //__MMI_APPLIST_APP_UNINSTALL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_init_cell_info
 * DESCRIPTION
 *  Divide the init process to two part, first just load current page, and then load the left
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_init_cell_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, idx;
    S32 idx_from, idx_to;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->state == MMI_APPLIST_STATE_NONE)
        return;
    
    //RANFOW_TRACE("[APPLIST]mmi_applist_init_cell_info start\n");
    
    if (applist_p->state == MMI_APPLIST_STATE_FIRST_ENTER || applist_p->state == MMI_APPLIST_STATE_ENTER)
    {
        #if defined(__MMI_PHNSET_APPICON_SUPPORT__) || defined(__MMI_DOWNLOADABLE_APPICON_SUPPORT__)
        applist_p->is_cached = mmi_applist_cache_theme_icon();
        #endif
    }

    if (!applist_p->mainmenu_need_sync && applist_p->mode == MMI_APPLIST_MODE_POPUP)
    {
        //RANFOW_TRACE("[APPLIST]mmi_applist_init_cell_info end\n");
        return;
    }
    
    mmi_applist_get_page_cell_idx(mmi_applist_get_final_page_idx(), &idx_from, &idx_to);
    
    if (applist_p->state == MMI_APPLIST_STATE_FIRST_ENTER || applist_p->state == MMI_APPLIST_STATE_ENTER)
    {
        kal_mem_set(applist_p->bar_cell, 0, sizeof(mmi_applist_cell_struct *) * MMI_APPLIST_BAR_APP_NUM);
        kal_mem_set(applist_p->panel_cell, 0, sizeof(mmi_applist_cell_struct *) * MMI_APPLIST_PANEL_APP_NUM);

        /* init cell pointer, image, name, opacity, resize */
        for (i = 0; i < MMI_APPLIST_BAR_APP_NUM; i++)
        {
            if (applist_p->data.bar_id[i] != 0)
            {
                applist_p->bar_cell[i] = &applist_p->cell_pool[i];           

                mmi_applist_set_appmgr_cell_info(
                    i,
                    applist_p->data.bar_id[i],
                    applist_p->bar_cell[i]);

                applist_p->bar_cell[i]->opacity = 255;
                applist_p->bar_cell[i]->resize = 1.0f;
                applist_p->bar_cell[i]->cache_idx = MMI_APPLIST_INVALID_INDEX;
            }
            else
            {
                applist_p->bar_cell[i] = NULL;
            }        
        }
        
        for (i = idx_from; i <= idx_to; i++)
        {
            idx = MMI_APPLIST_BAR_APP_NUM + i;

            if (applist_p->data.panel_id[i] != 0)
            {
                applist_p->panel_cell[i] = &applist_p->cell_pool[idx];            

                mmi_applist_set_appmgr_cell_info(
                    idx,
                    applist_p->data.panel_id[i],
                    applist_p->panel_cell[i]);

                applist_p->panel_cell[i]->opacity = 255;
                applist_p->panel_cell[i]->resize = 1.0f;
                applist_p->panel_cell[i]->cache_idx = MMI_APPLIST_INVALID_INDEX;
            }
            else
            {
                applist_p->panel_cell[i] = NULL;
            }
        }
        
        /* Set cell position */
        mmi_applist_set_bar_cell_position();
        mmi_applist_set_panel_cell_position();
    }
    else  //applist_p->state == MMI_APPLIST_STATE_FIRST_ENTER || applist_p->state == MMI_APPLIST_STATE_ENTER
    {
        //RANFOW_TRACE("[APPLIST]init cell info not in current page\n");
        for (i = 0; i < MMI_APPLIST_PANEL_APP_NUM; i ++)
        {
            if (i >= idx_from && i <= idx_to)
                continue;
            
            idx = MMI_APPLIST_BAR_APP_NUM + i;

            if (applist_p->data.panel_id[i] != 0)
            {
                applist_p->panel_cell[i] = &applist_p->cell_pool[idx];            

                mmi_applist_set_appmgr_cell_info(
                    idx,
                    applist_p->data.panel_id[i],
                    applist_p->panel_cell[i]);

                applist_p->panel_cell[i]->opacity = 255;
                applist_p->panel_cell[i]->resize = 1.0f;
                applist_p->panel_cell[i]->cache_idx = MMI_APPLIST_INVALID_INDEX;
            }
            else
            {
                applist_p->panel_cell[i] = NULL;
            }
        }
        
        /* Set cell position */
        mmi_applist_set_panel_cell_position();
    }//applist_p->state == MMI_APPLIST_STATE_FIRST_ENTER || applist_p->state == MMI_APPLIST_STATE_ENTER

    //RANFOW_TRACE("[APPLIST]mmi_applist_init_cell_info end\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_set_indicator_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_set_indicator_info(S32 page_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, page_num, start_x, start_y, icon_w, icon_h, step, org_page_num;
    mmi_applist_indicator_state_enum org_state; 
    mmi_applist_position new_pos;
    U32 cur_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    page_num = mmi_applist_get_current_page_num();

    gdi_image_get_dimension_id(IMG_ID_APPLIST_INDICATOR_DOT_H, &icon_w, &icon_h);

    step = icon_w + MMI_APPLIST_INDICATOR_SIDE;
    start_x = ((LCD_WIDTH - (step * (page_num - 1) + icon_w))>>1);
    start_y = MMI_APPLIST_INDICATOR_BAR_Y + MMI_APPLIST_INDICATOR_BAR_HEIGHT/2;
             // ((MMI_APPLIST_INDICATOR_BAR_HEIGHT - icon_h)>>1);

    cur_time = mmi_applist_get_cur_time();

    /* Get original page number */
    for (i = 0; i < MMI_APPLIST_MAX_PAGE_NUM; i ++)
    {
        if (applist_p->indicator[i].state == MMI_APPLIST_INDICATOR_STATE_DISABLE)
        {
            break;
        }
    }
    org_page_num = i;
    
    /* Assign enable item */
    for (i = 0; i < page_num; i ++)
    {   
        org_state = applist_p->indicator[i].state;
        if (i == page_idx)
        {
            applist_p->indicator[i].state = MMI_APPLIST_INDICATOR_STATE_ACTIVE;
        }
        else
        {
            applist_p->indicator[i].state = MMI_APPLIST_INDICATOR_STATE_INACTIVE;
        }

        new_pos.x = start_x + step * i;
        new_pos.y = start_y;

        /* Check if need animation */
        if (applist_p->state != MMI_APPLIST_STATE_FIRST_ENTER && applist_p->state != MMI_APPLIST_STATE_ENTER && 
            org_page_num != page_num && org_state != MMI_APPLIST_INDICATOR_STATE_DISABLE)
        {
            mmi_applist_change_pos_anima(
                &applist_p->indicator[i].pos, &new_pos, cur_time);
        }
        else
        {
            applist_p->indicator[i].pos = new_pos;
        }
    }

    /* Assign disable item */
    for (i = page_num; i < MMI_APPLIST_MAX_PAGE_NUM; i ++)
    {
        applist_p->indicator[i].state = MMI_APPLIST_INDICATOR_STATE_DISABLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_move_cell_in_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_move_cell_in_page(
        mmi_applist_cell_type_enum cell_type, S32 from_idx, S32 to_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *id_p;
    mmi_applist_cell_struct **cell_p;
    S32 i;
    U32 tmp_id;
    mmi_applist_cell_struct *tmp_cell;
    mmi_applist_position pos;
    U32 cur_time;
    #ifdef __MMI_APPLIST_CACHE_APP_NAME__
    mmi_app_package_name_struct tmp_name = {0};
    S32 index_diff = 0;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cell_type)
    {
        case MMI_APPLIST_CELL_TYPE_PANEL:
            id_p = applist_p->data.panel_id;
            cell_p = applist_p->panel_cell;
            #ifdef __MMI_APPLIST_CACHE_APP_NAME__
            index_diff = MMI_APPLIST_BAR_APP_NUM;
            #endif
            break;
        case MMI_APPLIST_CELL_TYPE_SHORTCUT:
            id_p = applist_p->data.bar_id;
            cell_p = applist_p->bar_cell;
            break;
    }

    cur_time = mmi_applist_get_cur_time();
    
    if (from_idx < to_idx)
    {
        /* ID & PTR */
        tmp_id = id_p[from_idx];
        tmp_cell = cell_p[from_idx];

        for (i = from_idx; i <= to_idx - 1; i ++)
        {
            id_p[i] = id_p[i + 1];
            cell_p[i] = cell_p[i + 1];
            #ifdef __MMI_APPLIST_CACHE_APP_NAME__
            memset(tmp_name, 0, MMI_APP_NAME_MAX_LEN);
            mmi_ucs2ncpy((CHAR*)tmp_name, (CHAR*)applist_p->app_name[index_diff+i], MMI_APP_NAME_MAX_LEN);
            mmi_ucs2ncpy((CHAR*)applist_p->app_name[index_diff+i], (CHAR*)applist_p->app_name[index_diff+i+1], MMI_APP_NAME_MAX_LEN);
            mmi_ucs2ncpy((CHAR*)applist_p->app_name[index_diff+i+1], (CHAR*)tmp_name, MMI_APP_NAME_MAX_LEN);
            #endif
        }
        id_p[to_idx] = tmp_id;
        cell_p[to_idx] = tmp_cell;

        /* Change position */
        for (i = from_idx; i <= to_idx - 1; i ++)
        {
            mmi_applist_get_cell_position(cell_type, i, &pos);
            mmi_applist_change_pos_anima(&cell_p[i]->pos, &pos, cur_time);
        }           
    }
    else if (from_idx > to_idx)
    {
        /* ID & PTR */
        tmp_id = id_p[from_idx];
        tmp_cell = cell_p[from_idx];

        for (i = from_idx; i >= to_idx + 1; i --)
        {
            id_p[i] = id_p[i - 1];
            cell_p[i] = cell_p[i - 1];
            #ifdef __MMI_APPLIST_CACHE_APP_NAME__
            memset(tmp_name, 0, MMI_APP_NAME_MAX_LEN);
            mmi_ucs2ncpy((CHAR*)tmp_name, (CHAR*)applist_p->app_name[index_diff+i], MMI_APP_NAME_MAX_LEN);
            mmi_ucs2ncpy((CHAR*)applist_p->app_name[index_diff+i], (CHAR*)applist_p->app_name[index_diff+i-1], MMI_APP_NAME_MAX_LEN);
            mmi_ucs2ncpy((CHAR*)applist_p->app_name[index_diff+i-1], (CHAR*)tmp_name, MMI_APP_NAME_MAX_LEN);
            #endif
        }
        id_p[to_idx] = tmp_id;
        cell_p[to_idx] = tmp_cell;        

        /* Change position */
        for (i = to_idx + 1; i <= from_idx; i ++)
        {
            mmi_applist_get_cell_position(cell_type, i, &pos);
            mmi_applist_change_pos_anima(&cell_p[i]->pos, &pos, cur_time);
        }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_move_cell_in_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_applist_get_cur_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 tick, cur_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&tick);
    cur_time = kal_ticks_to_milli_secs(tick);  
    return cur_time;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_move_panel_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_move_panel_cell(S32 from_idx, S32 to_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 from_page_idx, to_page_idx, last_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* no need to move */
    if (from_idx == to_idx)
    {
        return to_idx;
    }
    
    from_page_idx = from_idx / MMI_APPLIST_APP_COUNT_PER_PAGE;
    to_page_idx = to_idx / MMI_APPLIST_APP_COUNT_PER_PAGE;

    /* Adjust to_idx */
    last_idx = mmi_applist_get_last_panel_index_in_page(to_page_idx);    
    
    if (from_page_idx == to_page_idx)
    {
        ASSERT(last_idx != MMI_APPLIST_INVALID_INDEX);
        /* Adjust to_idx */
        if (to_idx > last_idx)
        {
            to_idx = last_idx;
        }

        mmi_applist_move_cell_in_page(
            MMI_APPLIST_CELL_TYPE_PANEL, from_idx, to_idx);      
    }
    else
    {
        mmi_applist_remove_cell(MMI_APPLIST_CELL_TYPE_PANEL, from_idx);
        to_idx = mmi_applist_add_panel_cell(to_idx);
    }

    return to_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_move_bar_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_move_bar_cell(S32 from_idx, S32 to_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* no need to move */
    if (from_idx == to_idx)
    {
        return to_idx;
    }

    /* Adjust to_idx */
    last_idx = mmi_applist_get_last_bar_index();
    
        
    /* Adjust to_idx */
    if (to_idx > last_idx)
    {
        to_idx = last_idx;
    }

    mmi_applist_move_cell_in_page(
        MMI_APPLIST_CELL_TYPE_SHORTCUT, from_idx, to_idx);   
    
    return to_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_add_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_add_cell(mmi_applist_cell_type_enum cell_type, S32 add_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_idx, i, page_idx;
    mmi_applist_position pos;
    U32 *id_p;
    mmi_applist_cell_struct **cell_p;
    U32 cur_time;
    #ifdef __MMI_APPLIST_CACHE_APP_NAME__
    S32 index_diff = 0;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cell_type)
    {
        case MMI_APPLIST_CELL_TYPE_PANEL:
            id_p = applist_p->data.panel_id;
            cell_p = applist_p->panel_cell;
            page_idx = add_idx / MMI_APPLIST_APP_COUNT_PER_PAGE;
            last_idx = mmi_applist_get_last_panel_index_in_page(page_idx);
            #ifdef __MMI_APPLIST_CACHE_APP_NAME__
            index_diff = MMI_APPLIST_BAR_APP_NUM;
            #endif
            break;
        case MMI_APPLIST_CELL_TYPE_SHORTCUT:
            id_p = applist_p->data.bar_id;
            cell_p = applist_p->bar_cell;
            last_idx = mmi_applist_get_last_bar_index();
            break;
    }   
    
    cur_time = mmi_applist_get_cur_time();  

    /* Empty */
    if (last_idx == MMI_APPLIST_INVALID_INDEX)
    {
        if (cell_type == MMI_APPLIST_CELL_TYPE_PANEL)
        {
            add_idx = page_idx * MMI_APPLIST_APP_COUNT_PER_PAGE;
        }
        else
        {
            add_idx = 0;
        }
        cell_p[add_idx] = applist_p->focus_cell.cell_p;
        id_p[add_idx] = applist_p->focus_cell.cell_p->app_id;
        #ifdef __MMI_APPLIST_CACHE_APP_NAME__
        srv_appmgr_get_app_package_name_by_id(id_p[add_idx], applist_p->app_name[index_diff+add_idx]);
        #endif
    }
    else if (add_idx > last_idx)
    {
        /* Add to last_idx + 1 */
        add_idx = last_idx + 1;
        cell_p[add_idx] = applist_p->focus_cell.cell_p;  
        id_p[add_idx] = applist_p->focus_cell.cell_p->app_id; 
        #ifdef __MMI_APPLIST_CACHE_APP_NAME__
        srv_appmgr_get_app_package_name_by_id(id_p[add_idx], applist_p->app_name[index_diff+add_idx]);
        #endif     
    }
    else
    {
        /* ID & PTR */
        for (i = last_idx + 1; i >= add_idx + 1; i --)
        {
            id_p[i] = id_p[i - 1];
            cell_p[i] = cell_p[i - 1];
            #ifdef __MMI_APPLIST_CACHE_APP_NAME__
            mmi_ucs2ncpy((CHAR*)applist_p->app_name[index_diff+i], (CHAR*)applist_p->app_name[index_diff+i-1], MMI_APP_NAME_MAX_LEN);
            #endif
        }
        cell_p[add_idx] = applist_p->focus_cell.cell_p;
        id_p[add_idx] = applist_p->focus_cell.cell_p->app_id;
        #ifdef __MMI_APPLIST_CACHE_APP_NAME__
        srv_appmgr_get_app_package_name_by_id(id_p[add_idx], applist_p->app_name[index_diff+add_idx]);
        #endif

        #ifdef __MMI_APPLIST_SHORTCUT_AUTO_REPOSITION__
        if (cell_type != MMI_APPLIST_CELL_TYPE_SHORTCUT)
        #endif
        /* Change position */
        for (i = add_idx + 1; i <= last_idx + 1; i ++)
        {
            mmi_applist_get_cell_position(cell_type, i, &pos);
            mmi_applist_change_pos_anima(&cell_p[i]->pos, &pos, cur_time);
        }
    }

    #ifdef __MMI_APPLIST_SHORTCUT_AUTO_REPOSITION__
    if (cell_type == MMI_APPLIST_CELL_TYPE_SHORTCUT)
        /* Change position */
        for (i = 0; i < MMI_APPLIST_BAR_APP_NUM; i++)
        {
            if (applist_p->data.bar_id[i] != 0)
            {
                mmi_applist_get_cell_position(cell_type, i, &pos);
                mmi_applist_change_pos_anima(&cell_p[i]->pos, &pos, cur_time);
            }
        }
    #endif
    return add_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_add_panel_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_add_panel_cell(S32 add_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 page_idx, cache_idx, adjusted_idx;
    mmi_applist_position new_pos;
    MMI_BOOL full;
    U32 cur_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    page_idx = add_idx / MMI_APPLIST_APP_COUNT_PER_PAGE;

    full = mmi_applist_if_panel_page_full(page_idx);
    
    if (full)
    {
        ASSERT(applist_p->cache_cell.cell_p == NULL);       
        cache_idx = (page_idx + 1) * MMI_APPLIST_APP_COUNT_PER_PAGE - 1;

        /* Assign cache cell */
        applist_p->cache_cell.page_idx = page_idx;
        applist_p->cache_cell.cell_p = applist_p->panel_cell[cache_idx];
        
        /* Remove panel cell */
        applist_p->data.panel_id[cache_idx] = 0;
        applist_p->panel_cell[cache_idx]= NULL;

        /* Add cache cell into anima queue */
        new_pos.x = applist_p->cache_cell.cell_p->pos.x + MMI_APPLIST_CELL_WIDTH;
        new_pos.y = applist_p->cache_cell.cell_p->pos.y;
        cur_time = mmi_applist_get_cur_time();
        
        mmi_applist_change_pos_anima(
            &(applist_p->cache_cell.cell_p->pos), &new_pos, cur_time);
        
    }

    adjusted_idx = mmi_applist_add_cell(MMI_APPLIST_CELL_TYPE_PANEL, add_idx);    
    
    return adjusted_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_reset_cache_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_reset_cache_cell(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applist_p->cache_cell.cell_p = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_restore_cache_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_restore_cache_cell(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL full;
    S32 cache_idx, page_idx;
    mmi_applist_position pos;
    U32 cur_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(applist_p->cache_cell.cell_p != NULL);
    
    page_idx = applist_p->cache_cell.page_idx;
    full = mmi_applist_if_panel_page_full(page_idx);

    /* Restore cache cell */    
    if (!full)
    {        
        cache_idx = (page_idx + 1) * MMI_APPLIST_APP_COUNT_PER_PAGE - 1;    
        applist_p->panel_cell[cache_idx] = applist_p->cache_cell.cell_p;    
        applist_p->data.panel_id[cache_idx] = applist_p->cache_cell.cell_p->app_id;

        cur_time = mmi_applist_get_cur_time();
        mmi_applist_get_cell_position(
            MMI_APPLIST_CELL_TYPE_PANEL, cache_idx, &pos);
        
        mmi_applist_change_pos_anima(
            &(applist_p->panel_cell[cache_idx]->pos), &pos, cur_time);
        
        
        mmi_applist_reset_cache_cell();
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_put_cache_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_put_cache_cell(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL restore;
    S32 page_idx, put_idx, page_num;
    mmi_applist_position pos;
    U32 cur_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* No cache cell */
    if (applist_p->cache_cell.cell_p == NULL)
    {
        return;        
    }

    /* put to the original page first */
    restore = mmi_applist_restore_cache_cell();
    if (restore)
    {
        return;
    }    

    /* We want to use focus cell to put cache cell. So focus cell must be null */
    ASSERT(applist_p->focus_cell.state == MMI_APPLIST_CELL_STATE_UNSELECTED);

    /* put to the next page */
    while(applist_p->cache_cell.cell_p != NULL)
    {
        page_idx = applist_p->cache_cell.page_idx + 1;
        
        if (page_idx < MMI_APPLIST_MAX_PAGE_NUM)
        {
            applist_p->focus_cell.index = 
                mmi_applist_get_cell_idx(page_idx, 0, 0);
        }
        else
        {            
            applist_p->focus_cell.index = mmi_applist_get_last_empty_index();
            /* Impossible. Check why ? */
            ASSERT(applist_p->focus_cell.index != MMI_APPLIST_INVALID_INDEX);
        }       
        
        applist_p->focus_cell.type = MMI_APPLIST_CELL_TYPE_PANEL;        
        applist_p->focus_cell.cell_p = applist_p->cache_cell.cell_p;
        mmi_applist_reset_cache_cell();
        
        put_idx = mmi_applist_add_panel_cell(applist_p->focus_cell.index);
        ASSERT(put_idx == applist_p->focus_cell.index);
        
        /* Set put-in cell's position */
        mmi_applist_get_cell_position(
            applist_p->focus_cell.type, 
            applist_p->focus_cell.index, 
            &pos);
        
        cur_time = mmi_applist_get_cur_time();
        mmi_applist_change_pos_anima(
            &(applist_p->focus_cell.cell_p->pos), &pos, cur_time);        
        //applist_p->focus_cell.cell_p->pos = pos;
    }
    
    /* Reset parameter */
    mmi_applist_reset_focus_cell();

    /* Expend page num */
    page_num = put_idx / MMI_APPLIST_APP_COUNT_PER_PAGE + 1;
    
    ASSERT(page_num <= MMI_APPLIST_MAX_PAGE_NUM);    
    if (page_num > applist_p->edit_page_num)
    {
        applist_p->edit_page_num = page_num;

        /* Update indicator info */
        put_idx = mmi_applist_get_current_page_idx();
        mmi_applist_set_indicator_info(page_idx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_remove_bar_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_remove_cell(
        mmi_applist_cell_type_enum cell_type, S32 remove_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, last_idx, page_idx;
    mmi_applist_position pos;
    kal_uint32 *id_p;
    mmi_applist_cell_struct **cell_p;
    U32 cur_time;
    #ifdef __MMI_APPLIST_CACHE_APP_NAME__
    mmi_app_package_name_struct tmp_name = {0};
    S32 index_diff = 0;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (cell_type)
    {
        case MMI_APPLIST_CELL_TYPE_PANEL:
            id_p = applist_p->data.panel_id;
            cell_p = applist_p->panel_cell;            
            page_idx = remove_idx / MMI_APPLIST_APP_COUNT_PER_PAGE;                
            last_idx = mmi_applist_get_last_panel_index_in_page(page_idx);
            #ifdef __MMI_APPLIST_CACHE_APP_NAME__
            index_diff = MMI_APPLIST_BAR_APP_NUM;
            #endif
            break;
        case MMI_APPLIST_CELL_TYPE_SHORTCUT:
            id_p = applist_p->data.bar_id;
            cell_p = applist_p->bar_cell;
            last_idx = mmi_applist_get_last_bar_index();
            break;
    }

    cur_time = mmi_applist_get_cur_time();
    
    /* ID & PTR */
    for (i = remove_idx; i <= last_idx - 1; i ++)
    {
        id_p[i] = id_p[i + 1];
        cell_p[i] = cell_p[i + 1];
        #ifdef __MMI_APPLIST_CACHE_APP_NAME__
        memset(tmp_name, 0, MMI_APP_NAME_MAX_LEN);
        mmi_ucs2ncpy((CHAR*)tmp_name, (CHAR*)applist_p->app_name[index_diff+i], MMI_APP_NAME_MAX_LEN);
        mmi_ucs2ncpy((CHAR*)applist_p->app_name[index_diff+i], (CHAR*)applist_p->app_name[index_diff+i+1], MMI_APP_NAME_MAX_LEN);
        mmi_ucs2ncpy((CHAR*)applist_p->app_name[index_diff+i+1], (CHAR*)tmp_name, MMI_APP_NAME_MAX_LEN);
        #endif
    }
    id_p[last_idx] = 0;
    cell_p[last_idx] = NULL;
    #ifdef __MMI_APPLIST_CACHE_APP_NAME__
    memset(applist_p->app_name[index_diff+last_idx], 0, MMI_APP_NAME_MAX_LEN);
    #endif

    /* Change position */
    #ifdef __MMI_APPLIST_SHORTCUT_AUTO_REPOSITION__
    if (cell_type == MMI_APPLIST_CELL_TYPE_SHORTCUT)
        for (i = 0; i < MMI_APPLIST_BAR_APP_NUM; i++)
        {
            if (applist_p->data.bar_id[i] != 0)
            {
                mmi_applist_get_cell_position(cell_type, i, &pos);
                mmi_applist_change_pos_anima(&cell_p[i]->pos, &pos, cur_time);
            }        
        }
    else
    #endif
    for (i = remove_idx; i <= last_idx - 1; i++)
    {
        mmi_applist_get_cell_position(cell_type, i, &pos);        
        mmi_applist_change_pos_anima(&cell_p[i]->pos, &pos, cur_time);        
    }

    /* Restore cache cell */
    if (cell_type == MMI_APPLIST_CELL_TYPE_PANEL &&
        applist_p->cache_cell.cell_p != NULL)
    {
        mmi_applist_restore_cache_cell();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_organize_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_organize_cell(mmi_applist_hit_area_struct *hit_area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 adjust_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->focus_cell.type == MMI_APPLIST_CELL_TYPE_PANEL)
    {
        if (hit_area->type == MMI_APPLIST_AREA_TYPE_SLIDE)
        {
            adjust_idx = mmi_applist_move_panel_cell(
                applist_p->focus_cell.index, hit_area->index);

            /* Update focus cell */
            applist_p->focus_cell.index = adjust_idx;
        }
        else if (hit_area->type == MMI_APPLIST_AREA_TYPE_SHORTCUT_BAR)
        {
            /* No need to move */
            if (mmi_applist_if_shortcut_bar_full())
            {
                return;
            }            
            
            mmi_applist_remove_cell(
                MMI_APPLIST_CELL_TYPE_PANEL, 
                applist_p->focus_cell.index);

            adjust_idx = mmi_applist_add_cell(
                MMI_APPLIST_CELL_TYPE_SHORTCUT, hit_area->index);

            /* Update focus cell */
            applist_p->focus_cell.index = adjust_idx;
            applist_p->focus_cell.type = MMI_APPLIST_CELL_TYPE_SHORTCUT;
        }
    }
    else if (applist_p->focus_cell.type == MMI_APPLIST_CELL_TYPE_SHORTCUT)
    {
        if (hit_area->type == MMI_APPLIST_AREA_TYPE_SLIDE)
        {
            mmi_applist_remove_cell(
                MMI_APPLIST_CELL_TYPE_SHORTCUT, 
                applist_p->focus_cell.index);            

            /* add panel cell */
            adjust_idx = mmi_applist_add_panel_cell(hit_area->index);
            
            /* Update focus cell */
            applist_p->focus_cell.index = adjust_idx;
            applist_p->focus_cell.type = MMI_APPLIST_CELL_TYPE_PANEL;
            
        }
        else if (hit_area->type == MMI_APPLIST_AREA_TYPE_SHORTCUT_BAR)
        {
            adjust_idx = mmi_applist_move_bar_cell(
                applist_p->focus_cell.index, hit_area->index);

            /* Update focus cell */
            applist_p->focus_cell.index = adjust_idx;
        }
    }    

#ifdef __MMI_APPLIST_KEY_SUPPORT__ 
    /* store previous highlight info */
    applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
    applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
        
    applist_p->hilight_frame.index = applist_p->focus_cell.index;
    applist_p->hilight_frame.type = applist_p->focus_cell.type;
#endif  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_target_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_applist_get_target_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 page_idx, page_num, i, start_idx, end_idx, tmp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    page_idx = mmi_applist_get_current_page_idx();
    page_num = mmi_applist_get_current_page_num();    

    /* Search forward first */
    mmi_applist_get_page_cell_idx(page_idx, &start_idx, &tmp);
    mmi_applist_get_page_cell_idx(page_num - 1, &tmp, &end_idx);
    
    for (i = start_idx; i <= end_idx; i ++)
    {
        if (applist_p->data.panel_id[i] != 0)
        {
            return applist_p->data.panel_id[i];
        }
    }

    /* Search backward */
    for (i = start_idx; i >= 0; i --)
    {
        if (applist_p->data.panel_id[i] != 0)
        {
            return applist_p->data.panel_id[i];
        }
    }

    /* Not found */
    ASSERT(0);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_target_page_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_target_page_idx(U32 target_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < MMI_APPLIST_PANEL_APP_NUM; i ++)
    {
        if (applist_p->data.panel_id[i] == target_id)
        {
            break;
        }
    }

    /* Should be found */
    ASSERT(i < MMI_APPLIST_PANEL_APP_NUM);
    
    return i / MMI_APPLIST_APP_COUNT_PER_PAGE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_move_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_move_page(S32 to_page_idx, S32 from_page_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dst_start_idx, src_start_idx, cell_count;
    #ifdef __MMI_APPLIST_CACHE_APP_NAME__
    S32 i;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(to_page_idx < from_page_idx);
    
    dst_start_idx = to_page_idx * MMI_APPLIST_APP_COUNT_PER_PAGE;
    src_start_idx = from_page_idx * MMI_APPLIST_APP_COUNT_PER_PAGE;

    /* Sanity check */
    cell_count = MMI_APPLIST_APP_COUNT_PER_PAGE;
    if (src_start_idx + cell_count >= MMI_APPLIST_PANEL_APP_NUM)
    {
        cell_count = MMI_APPLIST_PANEL_APP_NUM - src_start_idx;
    }    
    
    #ifdef __MMI_APPLIST_CACHE_APP_NAME__
    for (i = 0; i < cell_count; i++)
    {
        if (applist_p->data.panel_id[src_start_idx+i] != 0)
        {
            mmi_ucs2ncpy((CHAR*)applist_p->app_name[MMI_APPLIST_BAR_APP_NUM+dst_start_idx+i], (CHAR*)applist_p->app_name[MMI_APPLIST_BAR_APP_NUM+src_start_idx+i], MMI_APP_NAME_MAX_LEN);
            memset(applist_p->app_name[MMI_APPLIST_BAR_APP_NUM+src_start_idx+i], 0, MMI_APP_NAME_MAX_LEN);
        }
    }
    #endif
    
    /* Move app_id */
    kal_mem_cpy(
        &applist_p->data.panel_id[dst_start_idx],
        &applist_p->data.panel_id[src_start_idx],
        cell_count * sizeof(U32));

    kal_mem_set(
        &applist_p->data.panel_id[src_start_idx],
        0,
        cell_count * sizeof(U32));

    /* Move cell_p */
    kal_mem_cpy(
        &applist_p->panel_cell[dst_start_idx],
        &applist_p->panel_cell[src_start_idx],
        cell_count * sizeof(mmi_applist_cell_struct *));
    
    kal_mem_set(
        &applist_p->panel_cell[src_start_idx],
        0,
        cell_count * sizeof(mmi_applist_cell_struct *));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_compact_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_compact_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 page_num, i, j;
    MMI_BOOL empty;
    U32 target_app_id; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    target_app_id = mmi_applist_get_target_app_id();
    
    page_num = mmi_applist_get_current_page_num();
    
    for (i = 0; i < page_num - 1; i ++)
    {
        empty = mmi_applist_if_panel_page_empty(i);
        if (!empty)
        {
            continue;
        }
        
        /* Find non-empty page */
        for (j = i + 1; j < page_num; j ++)
        {
            empty = mmi_applist_if_panel_page_empty(j);
            if (!empty)
            {
                break;
            }
        }

        /* not found */
        if (j >= page_num)
        {
            break;
        }

        mmi_applist_move_page(i, j);
    }

    /* Set panel cell position */
    mmi_applist_set_panel_cell_position();

    return mmi_applist_target_page_idx(target_app_id);
}

#if defined(__MMI_TOUCH_SCREEN__)

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_change_slide_x
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_change_slide_x(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 diff_x, page_num, max;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_applist_remove_slide_x_anima();

    diff_x = pos.x - applist_p->pen_last_pos.x;

    applist_p->slide_region.x -= diff_x;

    page_num = mmi_applist_get_current_page_num();
    
    /* Add limitation */    
    if (applist_p->slide_region.x < - MMI_APPLIST_SLIDE_MARGIN)
    {
        applist_p->slide_region.x = - MMI_APPLIST_SLIDE_MARGIN;
    }
    else
    {
        max = (page_num - 1) * MMI_APPLIST_PAGE_WIDTH_INC_MARGIN + MMI_APPLIST_SLIDE_MARGIN;

        if (applist_p->slide_region.x > max)
        {
            applist_p->slide_region.x = max;
        }
    }

    /* Update to wallpaper */
    //applist_p->wp_config.on_page_change(
    //    applist_p->slide_region.x, page_num,
    //    MMI_APPLIST_PAGE_WIDTH_INC_MARGIN, MMI_APPLIST_INTER_PAGE_MARGIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_hit_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_get_hit_area(S32 pos_x, S32 pos_y, mmi_applist_hit_area_struct *hit_area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 title_bar_y = MMI_STATUS_BAR_HEIGHT + MMI_APPLIST_TITLE_BAR_HEIGHT;
    S32 slide_y = title_bar_y + MMI_APPLIST_SLIDE_AREA_HEIGHT;
    S32 indicator_y = slide_y + MMI_APPLIST_INDICATOR_BAR_HEIGHT;
    S32 step_x, step_y, page_idx;
    #ifdef __MMI_APPLIST_SHORTCUT_AUTO_REPOSITION__
    S32 shortcut_start_x = mmi_applist_get_bar_start_x();
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   
    /* Status Bar */
    if (pos_y < title_bar_y)
    {
        hit_area->type = MMI_APPLIST_AREA_TYPE_INVALID;
        hit_area->index = MMI_APPLIST_INVALID_INDEX;
    }
    /* Slide area */
    else if (pos_y >= title_bar_y && pos_y < slide_y)
    {
        hit_area->type = MMI_APPLIST_AREA_TYPE_SLIDE;

        //TODO: use target value
        page_idx = applist_p->slide_region.x / MMI_APPLIST_PAGE_WIDTH_INC_MARGIN;
        step_x = pos_x / MMI_APPLIST_CELL_WIDTH;
        step_y = (pos_y - title_bar_y) / MMI_APPLIST_CELL_HEIGHT;
        
        hit_area->index = mmi_applist_get_cell_idx(page_idx, step_x, step_y);
    }
    /* Indicator area */
    else if (pos_y >= slide_y && pos_y < indicator_y)
    {
        hit_area->type = MMI_APPLIST_AREA_TYPE_INDICATOR_BAR; 
        hit_area->index = mmi_applist_get_indicator_hit_index(pos_x, pos_y);               
    } 
    /* Shortcut area */
    else
    {
        hit_area->type = MMI_APPLIST_AREA_TYPE_SHORTCUT_BAR;
        #ifdef __MMI_APPLIST_SHORTCUT_AUTO_REPOSITION__
        if (pos_x >= shortcut_start_x && pos_x + shortcut_start_x <= LCD_WIDTH)
        {
            hit_area->index = (pos_x - shortcut_start_x) / MMI_APPLIST_CELL_WIDTH;
        }
        else
        {
            hit_area->index = MMI_APPLIST_INVALID_INDEX;
        }
        #else
        hit_area->index = pos_x / MMI_APPLIST_CELL_WIDTH;
        #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_reposition_hit_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_get_reposition_hit_area(S32 pos_x, S32 pos_y, mmi_applist_hit_area_struct *hit_area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 title_bar_y = MMI_STATUS_BAR_HEIGHT + MMI_APPLIST_TITLE_BAR_HEIGHT;
    S32 slide_y = MMI_STATUS_BAR_HEIGHT + MMI_APPLIST_TITLE_BAR_HEIGHT + MMI_APPLIST_SLIDE_AREA_HEIGHT + MMI_APPLIST_INDICATOR_BAR_HEIGHT/2;
    S32 step_x, step_y, page_idx, to_slide_x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

    /* Slide area */
    if (pos_y < slide_y)
    {
        hit_area->type = MMI_APPLIST_AREA_TYPE_SLIDE;

        if (applist_p->slide_region.anima_node_p)
        {
            to_slide_x = applist_p->slide_region.anima_node_p->to.pos_x;
        }
        else
        {
            to_slide_x = applist_p->slide_region.x;
        }
        page_idx = to_slide_x / MMI_APPLIST_PAGE_WIDTH_INC_MARGIN;
        step_x = pos_x / MMI_APPLIST_CELL_WIDTH;
        step_y = (pos_y - title_bar_y) / MMI_APPLIST_CELL_HEIGHT;
        if (step_y < 0)
        {
            step_y = 0;
        }
        
        hit_area->index = mmi_applist_get_cell_idx(page_idx, step_x, step_y);
    }
    /* Shortcut area */
    else
    {
        hit_area->type = MMI_APPLIST_AREA_TYPE_SHORTCUT_BAR;
        hit_area->index = pos_x / MMI_APPLIST_CELL_WIDTH;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_indicator_hit_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_indicator_hit_index(S32 pos_x, S32 pos_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 page_num, icon_w, icon_h, i;
    S32 hit_idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    page_num = mmi_applist_get_current_page_num();        
    gdi_image_get_dimension_id(
        IMG_ID_APPLIST_INDICATOR_DOT_H, &icon_w, &icon_h);

    for (i = 0; i < page_num - 1; i ++)
    {
        if (pos_x < applist_p->indicator[i].pos.x + 
                    icon_w + MMI_APPLIST_INDICATOR_SIDE /2)
        {
            hit_idx = i;
            break;
        }
    }

    if (i >= page_num - 1)
    {
        hit_idx = page_num - 1;
    } 

    return hit_idx;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_applist_if_hit_area_has_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_if_hit_area_has_cell(mmi_applist_hit_area_struct *hit_area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (hit_area->type == MMI_APPLIST_AREA_TYPE_SHORTCUT_BAR)
    {
        if (hit_area->index >= 0 && hit_area->index < MMI_APPLIST_BAR_APP_NUM)
        {
            if (applist_p->data.bar_id[hit_area->index] != 0)
            {
                return MMI_TRUE;
            }
        }
        
    }
    else if (hit_area->type == MMI_APPLIST_AREA_TYPE_SLIDE)
    {
        if (hit_area->index >= 0 && hit_area->index < MMI_APPLIST_PANEL_APP_NUM)
        {
            if (applist_p->data.panel_id[hit_area->index] != 0)
            {
                return MMI_TRUE;
            }
        }
    }  
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_set_focus_cell_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_set_focus_cell_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_applist_if_hit_area_has_cell(&applist_p->hit_area))
    {
        applist_p->focus_cell.state = MMI_APPLIST_CELL_STATE_TOUCHED;                
        applist_p->focus_cell.index = applist_p->hit_area.index;
        applist_p->focus_cell.cell_p = mmi_applist_get_cell_ptr(
                                            applist_p->focus_cell.type,
                                            applist_p->focus_cell.index);
    }
    else
    {
        mmi_applist_reset_focus_cell();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_update_focus_cell_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_update_focus_cell_pos(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell_ptr = applist_p->focus_cell.cell_p;

    ASSERT(cell_ptr != NULL);

    /* Move focus cell */
    cell_ptr->pos.x = GET_FINAL_G_CELL_X(applist_p->focus_cell.type, applist_p->pen_last_pos.x) - 
        applist_p->focus_cell.pen_shift.x;
    cell_ptr->pos.y = applist_p->pen_last_pos.y - applist_p->focus_cell.pen_shift.y;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_reposition_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_reposition_cell(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_hit_area_struct hit_area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_applist_get_reposition_hit_area(
        applist_p->pen_last_pos.x, 
        applist_p->pen_last_pos.y, &hit_area);

    mmi_applist_organize_cell(&hit_area);

    /* Update focus cell's position */
    mmi_applist_update_focus_cell_pos();  
    
    gui_cancel_timer(mmi_applist_update_anima_data);    
    mmi_applist_update_anima_data();   
}
#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __MMI_APPLIST_KEY_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_first_panel_index_of_column
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_first_panel_index_of_column(S32 page_idx, S32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    idx = mmi_applist_get_cell_idx(page_idx, column, 0);
    if (applist_p->panel_cell[idx])
    {
        return idx;
    }

    return MMI_APPLIST_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_last_panel_index_of_column
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_last_panel_index_of_column(S32 page_idx, S32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 row, idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    for (row = MMI_APPLIST_CELL_ROW_COUNT - 1; row >= 0; row--)
    {
        idx = mmi_applist_get_cell_idx(page_idx, column, row);
        if (applist_p->panel_cell[idx])
        {
            return idx;
        }
    }

    return MMI_APPLIST_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_prev_page_hilight_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_prev_page_hilight_index(S32 page_idx, S32 row)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 start_idx, to_idx, i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    to_idx = mmi_applist_get_cell_idx(page_idx, MMI_APPLIST_CELL_COLUMN_COUNT - 1, row);
    start_idx = page_idx * MMI_APPLIST_APP_COUNT_PER_PAGE;
    
    for (i = to_idx; i >= start_idx; i --)
    {
        if (applist_p->panel_cell[i])
        {
            return i;
        }
    }   

    return MMI_APPLIST_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_next_page_hilight_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_next_page_hilight_index(S32 page_idx, S32 row)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 start_idx, to_idx, i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    to_idx = mmi_applist_get_cell_idx(page_idx, 0, row);
    start_idx = page_idx * MMI_APPLIST_APP_COUNT_PER_PAGE;
    
    for (i = to_idx; i >= start_idx; i -= MMI_APPLIST_CELL_COLUMN_COUNT)
    {
        if (applist_p->panel_cell[i])
        {
            return i;
        }
    }   

    return MMI_APPLIST_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_init_highlight_frame_in_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_init_hilight_index_in_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx_from, idx_to;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* No need to init */
    if (applist_p->hilight_frame.type == MMI_APPLIST_CELL_TYPE_SHORTCUT &&
        applist_p->hilight_frame.index != MMI_APPLIST_INVALID_INDEX)
    {
        return;
    }

    mmi_applist_get_page_cell_idx(mmi_applist_get_final_page_idx(), &idx_from, &idx_to);

    /* No need to init */
    if (applist_p->hilight_frame.type == MMI_APPLIST_CELL_TYPE_PANEL &&
        applist_p->hilight_frame.index >= idx_from &&
        applist_p->hilight_frame.index <= idx_to)
    {
        return;
    }   

    /* Init as the first cell in the page */
    if (applist_p->data.panel_id[idx_from] != 0)
    {
        /* store previous highlight info */
        applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
        applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
        
        applist_p->hilight_frame.type = MMI_APPLIST_CELL_TYPE_PANEL;
        applist_p->hilight_frame.index = idx_from;
        applist_p->hilight_frame.cell_p = applist_p->panel_cell[idx_from];
        #ifndef __MMI_APPLIST_ONLY_ICON_SUPPORT__
        if (applist_p->mode == MMI_APPLIST_MODE_NORMAL && applist_p->hilight_frame.cell_p->name_len > MMI_APPLIST_STRING_REGION)
        {
            applist_p->hilight_frame.scroll_x = 0;
            gui_start_timer(MMI_APPLIST_CELL_STRING_SCROLL_DELAY, mmi_applist_scroll_cell_string);
        }
        #endif
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_init_hilight_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_init_hilight_frame(S32 page_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->hilight_frame.cell_p != NULL && applist_p->hilight_frame.cell_p->app_id != 0 &&
        ((applist_p->hilight_frame.type == MMI_APPLIST_CELL_TYPE_PANEL && applist_p->panel_cell[applist_p->hilight_frame.index] != NULL) || 
        (applist_p->hilight_frame.type == MMI_APPLIST_CELL_TYPE_SHORTCUT && applist_p->bar_cell[applist_p->hilight_frame.index] != NULL)))
    {
        if (applist_p->hilight_frame.type == MMI_APPLIST_CELL_TYPE_PANEL)
            applist_p->hilight_frame.cell_p = applist_p->panel_cell[applist_p->hilight_frame.index];
        else
            applist_p->hilight_frame.cell_p = applist_p->bar_cell[applist_p->hilight_frame.index];
        #ifndef __MMI_APPLIST_ONLY_ICON_SUPPORT__
        if (applist_p->hilight_frame.cell_p->name_len > MMI_APPLIST_STRING_REGION)
        {
            applist_p->hilight_frame.scroll_x = 0;
            gui_start_timer(MMI_APPLIST_CELL_STRING_SCROLL_DELAY * 2, mmi_applist_scroll_cell_string);
        }
        #endif
    }
    else
    {
        applist_p->hilight_frame.index = MMI_APPLIST_INVALID_INDEX;
        applist_p->hilight_frame.cell_p = NULL;
        mmi_applist_init_hilight_index_in_page();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_last_row
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_last_row(S32 page_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 row, idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    for (row = MMI_APPLIST_CELL_ROW_COUNT - 1; row >= 0; row --)
    {
        idx = mmi_applist_get_cell_idx(page_idx, 0, row);
        if (applist_p->panel_cell[idx])
        {
            return row;
        }
    }
    return MMI_APPLIST_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_change_bar_hilight_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_get_change_bar_hilight_frame(
        mmi_applist_dir_enum dir, 
        mmi_applist_cell_type_enum *frame_type,
        S32 *frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx, final_page_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    final_page_idx = mmi_applist_get_final_page_idx();
    if (dir == MMI_APPLIST_DIR_LEFT)
    {
        if (*frame_index > 0)
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            (*frame_index) --;                
        }
        else
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_index = mmi_applist_get_last_bar_index();
        }
    }
    else if (dir == MMI_APPLIST_DIR_RIGHT)
    {
        idx = *frame_index + 1;
        
        if (idx < MMI_APPLIST_BAR_APP_NUM && 
            applist_p->bar_cell[idx])
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_index = idx;
        }
        else
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_index = 0;
        }
    }
    else if (dir == MMI_APPLIST_DIR_UP)
    {
        idx = mmi_applist_get_last_panel_index_of_column(
                final_page_idx, *frame_index);

        //there is not another icon in current column, move highlight to the last icon of current panel page
        if (idx == MMI_APPLIST_INVALID_INDEX)
        {
            idx = mmi_applist_get_last_panel_index_in_page(final_page_idx);
        }
        
        if (idx != MMI_APPLIST_INVALID_INDEX)
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            /* Change type */
            *frame_type = MMI_APPLIST_CELL_TYPE_PANEL;
            *frame_index = idx;            
        }
    }
    else /* Down */
    {        
        idx = mmi_applist_get_first_panel_index_of_column(
                final_page_idx, *frame_index);
        
        //there is not another icon in current column, move highlight to the first icon of current panel page
        if (idx == MMI_APPLIST_INVALID_INDEX)
        {
            idx = final_page_idx * MMI_APPLIST_APP_COUNT_PER_PAGE;
            if (applist_p->data.panel_id[idx] == 0)
            {
                idx = MMI_APPLIST_INVALID_INDEX;
            }
        }
        
        if (idx != MMI_APPLIST_INVALID_INDEX)
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            /* Change type */
            *frame_type = MMI_APPLIST_CELL_TYPE_PANEL;
            *frame_index = idx;            
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_move_bar_hilight_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_get_move_bar_hilight_frame(
        mmi_applist_dir_enum dir, 
        mmi_applist_cell_type_enum *frame_type,
        S32 *frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx, final_page_idx, last_row;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    final_page_idx = mmi_applist_get_final_page_idx();
    if (dir == MMI_APPLIST_DIR_LEFT)
    {
        if (*frame_index > 0)
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            (*frame_index) --;                
        }
        else
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_index = mmi_applist_get_last_bar_index();
        }
    }
    else if (dir == MMI_APPLIST_DIR_RIGHT)
    {
        idx = *frame_index + 1;
        
        if (idx < MMI_APPLIST_BAR_APP_NUM && 
            applist_p->bar_cell[idx])
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_index = idx;
        }
        else
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_index = 0;
        }
    }
    else if (dir == MMI_APPLIST_DIR_UP)
    {
        last_row = mmi_applist_get_last_row(final_page_idx);
        if (last_row == MMI_APPLIST_INVALID_INDEX)
        {
            last_row = 0;
        }
        /* store previous highlight info */
        applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
        applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
        *frame_index = mmi_applist_get_cell_idx(
                            final_page_idx, *frame_index, last_row);
        
        /* Change type */
        *frame_type = MMI_APPLIST_CELL_TYPE_PANEL;        
    }
    else /* Down */
    {
        /* store previous highlight info */
        applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
        applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
        /* Change type */
        *frame_index = mmi_applist_get_cell_idx(final_page_idx, *frame_index, 0);
        *frame_type = MMI_APPLIST_CELL_TYPE_PANEL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_change_panel_hilight_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_get_change_panel_hilight_frame(
        mmi_applist_dir_enum dir, 
        mmi_applist_cell_type_enum *frame_type,
        S32 *frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx, row, column, page_idx, final_page_idx, page_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    final_page_idx = mmi_applist_get_final_page_idx();
    page_num = mmi_applist_get_current_page_num();            
         
    mmi_applist_get_panel_cell_location(
        *frame_index, &page_idx, &column, &row);

    if (dir == MMI_APPLIST_DIR_UP)
    {
        if (row > 0)
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_index -= MMI_APPLIST_CELL_COLUMN_COUNT;
        }
        else if (applist_p->bar_cell[column])
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            *frame_type = MMI_APPLIST_CELL_TYPE_SHORTCUT;
            *frame_index = column;
        }
        else
        {
            idx = mmi_applist_get_last_panel_index_of_column(
                final_page_idx, column);            
        
            if (idx != *frame_index)
            {
                /* store previous highlight info */
                applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
                applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
                *frame_index = idx;            
            }
            else
            {
                //there is not another icon in current column, move highlight to the first icon of shortcut bar
                if (applist_p->data.bar_id[0] != 0)
                {
                    /* store previous highlight info */
                    applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
                    applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
                    *frame_type = MMI_APPLIST_CELL_TYPE_SHORTCUT;
                    *frame_index = 0;   
                }
            }
        }
    }
    else if (dir == MMI_APPLIST_DIR_DOWN)
    {
        idx = *frame_index + MMI_APPLIST_CELL_COLUMN_COUNT;
        
        if (row + 1 < MMI_APPLIST_CELL_ROW_COUNT &&
            applist_p->panel_cell[idx])
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_index = idx;
        }
        else if (applist_p->bar_cell[column])
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            *frame_type = MMI_APPLIST_CELL_TYPE_SHORTCUT;
            *frame_index = column;
        }
        else
        {
            idx = mmi_applist_get_last_panel_index_in_page(final_page_idx);

            if (idx != *frame_index && row != (idx - page_idx * MMI_APPLIST_APP_COUNT_PER_PAGE) / MMI_APPLIST_CELL_COLUMN_COUNT)
            {
                /* store previous highlight info */
                applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
                applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
                *frame_index = idx;            
            }
            else
            {
                //there is not another icon in current column, move highlight to the last icon of shortcut bar
                idx = mmi_applist_get_last_bar_index();
                
                if (idx != MMI_APPLIST_INVALID_INDEX)
                {
                    /* store previous highlight info */
                    applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
                    applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
                    *frame_type = MMI_APPLIST_CELL_TYPE_SHORTCUT;
                    *frame_index = idx;   
                }
            }
        }
    }
    else if (dir == MMI_APPLIST_DIR_LEFT)
    {
        if (column > 0)
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            (*frame_index) --;
        }
        else
        {
            /* Slide to previous page */
            if (final_page_idx > 0)
            {
                #ifdef __MMI_APPLIST_KEY_LOOP__
                applist_p->is_loop = MMI_FALSE;
                #endif
                idx = final_page_idx - 1;
                *frame_index = mmi_applist_get_prev_page_hilight_index(idx, row);
            }
            else
            {
                #ifdef __MMI_APPLIST_KEY_LOOP__
                applist_p->is_loop = MMI_TRUE;
                idx = page_num - 1;
                *frame_index = mmi_applist_get_prev_page_hilight_index(idx, row);
                #else
                idx = final_page_idx;
                #endif
            }
            if (idx != final_page_idx)
                mmi_applist_slide_to_page(idx);
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            ASSERT(*frame_index != MMI_APPLIST_INVALID_INDEX);

            /* Return true if change page */
            return MMI_TRUE;
        }
    }
    else if (dir == MMI_APPLIST_DIR_RIGHT)
    {
        idx = *frame_index + 1;
        
        if (column + 1 < MMI_APPLIST_CELL_COLUMN_COUNT &&
            applist_p->panel_cell[idx])
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_index = idx;
        }
        else
        {
            /* Slide to next page */
            if (final_page_idx + 1 < page_num)
            {
                #ifdef __MMI_APPLIST_KEY_LOOP__
                applist_p->is_loop = MMI_FALSE;
                #endif
                idx = final_page_idx + 1;
                *frame_index = mmi_applist_get_next_page_hilight_index(idx, row);
            }
            else
            {
                #ifdef __MMI_APPLIST_KEY_LOOP__
                applist_p->is_loop = MMI_TRUE;
                idx = 0;
                *frame_index = mmi_applist_get_next_page_hilight_index(idx, row);
                #else
                idx = final_page_idx;
                #endif
            }
            if (idx != final_page_idx)
                mmi_applist_slide_to_page(idx);
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            ASSERT(*frame_index != MMI_APPLIST_INVALID_INDEX);

            /* Return true if change page */
            return MMI_TRUE;
        }
    }

    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_move_panel_hilight_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_get_move_panel_hilight_frame(
        mmi_applist_dir_enum dir, 
        mmi_applist_cell_type_enum *frame_type,
        S32 *frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx, row, column, page_idx, final_page_idx, page_num;
    S32 cur_idx_from, cur_idx_to;
    S32 last_idx, end_idx, cur_last_idx, last_row;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    final_page_idx = mmi_applist_get_final_page_idx();
    page_num = mmi_applist_get_current_page_num();            
    mmi_applist_get_page_cell_idx(final_page_idx, &cur_idx_from, &cur_idx_to); 
    cur_last_idx = mmi_applist_get_last_panel_index_in_page(final_page_idx);
    ASSERT(cur_last_idx != MMI_APPLIST_INVALID_INDEX);
    mmi_applist_get_panel_cell_location(
        *frame_index, &page_idx, &column, &row);

    if (dir == MMI_APPLIST_DIR_UP)
    {
        if (row > 0)
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_index -= MMI_APPLIST_CELL_COLUMN_COUNT;
        }        
        else if (!mmi_applist_if_shortcut_bar_full())
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_type = MMI_APPLIST_CELL_TYPE_SHORTCUT;
            *frame_index = column;
        }
        else
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            last_row = mmi_applist_get_last_row(final_page_idx);
            *frame_index += (last_row - row) *  MMI_APPLIST_CELL_COLUMN_COUNT;            
        }
    }
    else if (dir == MMI_APPLIST_DIR_DOWN)
    {
        if (row < mmi_applist_get_last_row(final_page_idx))
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_index += MMI_APPLIST_CELL_COLUMN_COUNT;
        }
        else if (!mmi_applist_if_shortcut_bar_full())
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_type = MMI_APPLIST_CELL_TYPE_SHORTCUT;
            *frame_index = column;
        }
        else
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            *frame_index = mmi_applist_get_cell_idx(
                                final_page_idx, column, 0);
        }
    }
    else if (dir == MMI_APPLIST_DIR_LEFT)
    {
        if (*frame_index > cur_idx_from)
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            (*frame_index) --;
        }
        else
        {
            /* Slide to previous page */
            if (final_page_idx > 0)
            {
                #ifdef __MMI_APPLIST_KEY_LOOP__
                applist_p->is_loop = MMI_FALSE;
                #endif
                idx = final_page_idx - 1;
            }
            else
            {
                #ifdef __MMI_APPLIST_KEY_LOOP__
                applist_p->is_loop = MMI_TRUE;
                idx = page_num - 1;
                #else
                idx = final_page_idx;
                #endif
            }
            if (idx != final_page_idx)
            {
                mmi_applist_slide_to_page(idx);
 
                last_idx = mmi_applist_get_last_panel_index_in_page(idx);
                end_idx = (idx + 1) * MMI_APPLIST_APP_COUNT_PER_PAGE - 1;
                /* Empty */
                if (last_idx == MMI_APPLIST_INVALID_INDEX)
                {
                    /* store previous highlight info */
                    applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
                    applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
                    *frame_index = idx * MMI_APPLIST_APP_COUNT_PER_PAGE;
                }
                /* Full */
                else if(last_idx + 1 > end_idx)
                {
                    /* store previous highlight info */
                    applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
                    applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
                    *frame_index = end_idx;
                }
                else
                {
                    /* store previous highlight info */
                    applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
                    applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
                    *frame_index = last_idx + 1;
                }
            }
        }
    }
    else if (dir == MMI_APPLIST_DIR_RIGHT)
    {        
        if (*frame_index < cur_last_idx)
        {
            /* store previous highlight info */
            applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
            applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
            (*frame_index) ++;
        }
        else
        {
            /* Slide to next page */
            idx = final_page_idx + 1;
            if (idx + 1 > MMI_APPLIST_MAX_PAGE_NUM)
            {
                #ifdef __MMI_APPLIST_KEY_LOOP__
                idx = 0;
                #else
                idx = final_page_idx;
                #endif
            }
            else if (idx + 1 > applist_p->edit_page_num)
            {    
                if (applist_p->slide_state != MMI_APPLIST_SLIDE_STATE_ENABLE_EXPENDED &&
                    applist_p->slide_state != MMI_APPLIST_SLIDE_STATE_DISABLE_EXPENDED)
                {
                    #ifdef __MMI_APPLIST_KEY_LOOP__
                    applist_p->is_loop = MMI_FALSE;
                    #endif
                    applist_p->edit_page_num = idx + 1;
                    applist_p->slide_state = MMI_APPLIST_SLIDE_STATE_DISABLE_EXPENDED;  
                }
                else
                {
                    #ifdef __MMI_APPLIST_KEY_LOOP__
                    applist_p->is_loop = MMI_TRUE;
                    idx = 0;
                    #else
                    idx = final_page_idx;
                    #endif
                }
            }
            if (idx != final_page_idx)
            {
                mmi_applist_slide_to_page(idx);
                /* store previous highlight info */
                applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
                applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
                *frame_index = idx * MMI_APPLIST_APP_COUNT_PER_PAGE;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_cell_to_area_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_applist_area_type_enum mmi_applist_cell_to_area_type(mmi_applist_cell_type_enum cell_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cell_type)
    {
        case MMI_APPLIST_CELL_TYPE_PANEL:
            return MMI_APPLIST_AREA_TYPE_SLIDE;
        case MMI_APPLIST_CELL_TYPE_SHORTCUT:
            return MMI_APPLIST_AREA_TYPE_SHORTCUT_BAR;
        default:
            ASSERT(0);
            return MMI_APPLIST_AREA_TYPE_SLIDE;
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_change_type_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_get_change_type_pos(
        mmi_applist_cell_type_enum cell_type,
        mmi_applist_position *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* from shortcut to panel */
    if (cell_type == MMI_APPLIST_CELL_TYPE_SHORTCUT)
    {
        pos->x = GET_FINAL_G_CELL_X(MMI_APPLIST_CELL_TYPE_PANEL, pos->x);
    }
    /* from panel to shortcut */
    else 
    {
        pos->x = GET_FINAL_CELL_X(MMI_APPLIST_CELL_TYPE_PANEL, pos->x);        
    }  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_move_hilight_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_move_hilight_frame(mmi_applist_dir_enum dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_hilight_frame_info_struct *frame_p = NULL;
    mmi_applist_hit_area_struct hit_area;
    mmi_applist_position pos;
    mmi_applist_cell_type_enum org_type;
    U32 cur_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    frame_p = &applist_p->hilight_frame;
    
    /* Assign highligt cell as focus cell */
    applist_p->focus_cell.cell_p = frame_p->cell_p;
    applist_p->focus_cell.index = frame_p->index;
    applist_p->focus_cell.type = frame_p->type;

    /* Assign hit area */
    org_type = frame_p->type;
    if (org_type == MMI_APPLIST_CELL_TYPE_SHORTCUT)
    {
        mmi_applist_get_move_bar_hilight_frame(dir, &frame_p->type, &frame_p->index);
    }
    else
    {
        mmi_applist_get_move_panel_hilight_frame(dir, &frame_p->type, &frame_p->index);
    }
    
    hit_area.type = mmi_applist_cell_to_area_type(frame_p->type);
    hit_area.index = frame_p->index;
    mmi_applist_organize_cell(&hit_area);

    /* Update organized cell to hilight frame */
    frame_p->type = applist_p->focus_cell.type;
    frame_p->index = applist_p->focus_cell.index;    

    if (org_type != frame_p->type)
    {
        mmi_applist_get_change_type_pos(org_type, &frame_p->cell_p->pos);
    }
    
    /* Set hilight frame cell's position */
    mmi_applist_get_cell_position(frame_p->type, frame_p->index, &pos);
    cur_time = mmi_applist_get_cur_time();
    mmi_applist_change_pos_anima(
        &frame_p->cell_p->pos, &pos, cur_time);
    
    /* Reset focus cell */
    mmi_applist_reset_focus_cell();
    
    mmi_applist_put_cache_cell();
    
    gui_cancel_timer(mmi_applist_update_anima_data);    
    mmi_applist_update_anima_data();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_arrow_key_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_arrow_key_press(mmi_applist_dir_enum dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_hilight_frame_info_struct *frame_p = NULL;
    S32 final_page_idx, hilight_page;
    MMI_BOOL change_page;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //reject key operation when sliding
    if (applist_p->state != MMI_APPLIST_STATE_NORMAL)
        return;
    
    #ifndef __MMI_APPLIST_ONLY_ICON_SUPPORT__
    gui_cancel_timer(mmi_applist_scroll_cell_string);
    #endif
        
    applist_p->slide_type = MMI_APPLIST_SLIDE_BY_KEY;    

    frame_p = &applist_p->hilight_frame;
    if (applist_p->mode == MMI_APPLIST_MODE_NORMAL)
    {
        if (frame_p->type == MMI_APPLIST_CELL_TYPE_SHORTCUT)
        {
            mmi_applist_get_change_bar_hilight_frame(
                dir, &frame_p->type, &frame_p->index);
        }
        else
        {
            change_page = mmi_applist_get_change_panel_hilight_frame(
                dir, &frame_p->type, &frame_p->index);

            if (change_page)
            {
                /* Stop wallpaper */
                mmi_applist_stop_wallpaper(
                    MMI_APPLIST_WP_STOP_TYPE_SLIDE_BY_KEY);
            }
        } 
        
        /* Update cell pointer */
        frame_p->cell_p = mmi_applist_get_cell_ptr(frame_p->type, frame_p->index);
        
        #ifndef __MMI_APPLIST_ONLY_ICON_SUPPORT__
        if (applist_p->mode == MMI_APPLIST_MODE_NORMAL && applist_p->hilight_frame.cell_p->name_len > MMI_APPLIST_STRING_REGION)
        {
            applist_p->hilight_frame.scroll_x = 0;
            gui_start_timer(MMI_APPLIST_CELL_STRING_SCROLL_DELAY, mmi_applist_scroll_cell_string);
        }
        #endif
    }
    else
    {
        /* current page is empty */
        if (frame_p->type == MMI_APPLIST_CELL_TYPE_PANEL && mmi_applist_get_final_page_idx() != frame_p->index / MMI_APPLIST_APP_COUNT_PER_PAGE)
        {
            goto done;
        }

        /* Hilight frame is in the curent page */
        mmi_applist_move_hilight_frame(dir);        
    }
    
    gui_cancel_timer(mmi_applist_update_anima_data);    
    mmi_applist_update_anima_data(); 

done:
    applist_p->long_press_dir = dir;
    gui_start_timer(
        MMI_APPLIST_KEY_LONG_PRESS_DELAY_FIRST_TIME,
        mmi_applist_arrow_key_press_cyclic);
}

#endif /* __MMI_APPLIST_KEY_SUPPORT__ */


#if defined(__MMI_PHNSET_APPICON_SUPPORT__) || defined(__MMI_DOWNLOADABLE_APPICON_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_cache_theme_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_applist_cache_theme_icon()
{
    if (mmi_res_venus_theme_cache_refresh_start())
    {
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_ALARM_ICON);
        #if defined(__MMI_AUDIO_PLAYER__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_APLY_ICON);
        #endif
        #ifdef __MMI_AZAAN_ALARM__
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_ALARM_ICON);
        #endif
        #if defined(__MMI_SEARCH_WEB_BAIDU__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_BAIDU_ICON);
        #endif
        #ifdef __MMI_BT_SUPPORT__
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_BT_ICON);
        #endif
        #if defined(__MMI_CALCULATOR__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_CALCULATOR_ICON);
        #endif
        #if defined(__MMI_CALENDAR__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_CALENDAR_ICON);
        #endif
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_CLOG_ICON);
        #if defined(__MMI_CAMCORDER__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_CAMCORDER_ICON);
        #endif
        #if defined (__MMI_CAMERA__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_CAMERA_ICON);
        #endif
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_CONNECT_ICON);
        #if defined(__MMI_CURRENCY_CONVERTER__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_CURRENCY_ICON);
        #endif
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_DIALER_ICON);
        #ifdef __MMI_EBOOK_READER__
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_EBOOK_ICON);
        #endif
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_EMAIL_ICON);
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_FMGR_ICON);
        #ifdef __MMI_FM_RADIO__
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_FMRDO_ICON);
        #endif
        #if defined(__MMI_BMI__) || defined(__MMI_MENSTRUAL__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_HEALTH_ICON);
        #endif
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_IVIEWER_ICON);
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_JAVA_ICON);
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_MPLYER_ICON);
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_MESSAGE_ICON);
        #if defined(__MMI_ATV_SUPPORT__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_MTV_ICON);
        #endif
        #ifdef __MMI_NOTE_APP__
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_NOTE_ICON);
        #endif
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_PHB_ICON);
        #ifdef __MMI_PHOTOEDITOR__
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_PEDITOR_ICON);
        #endif
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_PROFILES_ICON);
        #ifdef __SYNCML_SUPPORT__
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_PSYNC_ICON);
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_SYNC_ICON);
        #endif
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_SETTING_ICON);
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_SERVICE_ICON);
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_BARREL_ICON);
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_RECORDER_ICON);
        #if defined(__MMI_TODOLIST__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_TODO_ICON);
        #endif
        #if defined(__MMI_UNIT_CONVERTER__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_UCONVERTER_ICON);
        #endif
        #if defined(__MMI_VIDEO_PLAYER__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_VPLY_ICON);
        #endif
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_WIFI_ICON);
        #ifdef __MMI_BROWSER_2__
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_BROWSER_ICON);
        #endif
        #if defined (__MMI_WORLD_CLOCK__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_WCLOCK_ICON);
        #endif
        #ifdef __SOCIAL_NETWORK_SUPPORT__
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_SNS_ICON);
        #endif
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_VCALL_ICON);
        #if defined(__MMI_3D_GAME_INTERGRAFX__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_3DGAME_ICON);
        #endif
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_OPERA_ICON);
        #if defined(__MMI_VIDEO_RECORDER__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_VREC_ICON);
        #endif
        #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_SETTINGMSG_ICON);
        #endif
        #ifdef __MMI_MOT_SUPPORT__
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_MOT_ICON);
        #endif
        #if defined(__MMI_YOUTUBE_SHORTCUT__)
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APPLIST_YOUTUBE_ICON);
        #endif
        mmi_res_venus_theme_cache_refresh_require(IMG_ID_APP_LIST_THEME_WALLPAPER_0);      
        return mmi_res_venus_theme_cache_refresh_end();
    }    
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_theme_change_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_theme_change_notify()
{
    //need to recache
    applist_p->is_cached = MMI_FALSE;
    applist_p->theme_changed = MMI_TRUE;
}

#endif /* defined(__MMI_PHNSET_APPICON_SUPPORT__) || defined(__MMI_DOWNLOADABLE_APPICON_SUPPORT__) */

#endif /* __MMI_LAUNCHER_APP_LIST__ */

