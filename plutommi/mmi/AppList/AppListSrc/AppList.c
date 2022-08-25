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
 *  AppList.c
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
#include "kal_release.h"
#include "AppList.h"
#include "AppListDef.h"
#include "IdleMemCfg.h"
#include "GDI_include.h"
#include "wgui.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_idle_def.h"
#include "mmi_rp_app_applist_def.h"
#ifdef __MMI_APPLIST_BARREL_SUPPORT__
#include "AppListBarrel.h"
#endif
#ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#endif

#ifdef __MTK_TARGET__
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

/*
SWLA labels:
ABP      -- blt previous
*/

static MMI_RET mmi_applist_launch_cell(mmi_event_struct *evt);


static mmi_applist_context_struct g_mmi_applist_cntx;
mmi_applist_context_struct *applist_p = &g_mmi_applist_cntx;


#ifdef __MMI_FONT_EFFECTS__
    static stFontAttributeNode gApplistAttributeNode = 
    {
        {
            90,    /* Shadow Degree */
            0,     /* Engraved Degree */
            2,     /* Shadow Distant */
            1,     /* Shadow Range */
            80,    /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},    /* Border Color */
            {0, 0,0,0},    /* First Gradient Color */
            {0, 0,0,0},    /* Second Gradient Color */
            {255, 0,0,0},  /* Shadow Color */
            {0, 0,0,0},    /* Outer Glow Color */
            {0, 0,0,0},    /* Upper Engraved Color */
            {0, 0,0,0},    /* Lower Engraved Color */
        },
        17,     /* Attribute ID */
        2,      /* Effect Type */
        1,      /* Node Type, 0: static node, 1: dynamic node */
        NULL    /* Next Node Pointer */
    };
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_alloc_base_layer
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_alloc_base_layer(void)
{
#if !defined(GDI_2_LAYERS)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* base layer */
    gdi_layer_get_base_handle(&handle);
    gdi_layer_push_and_set_active(handle);

    gdi_layer_get_buffer_ptr(&applist_p->base_layer_buf_ptr);

    kal_mem_set(applist_p->base_layer_buf_ptr, 0, LCD_WIDTH * LCD_HEIGHT * 2);
    
    gdi_layer_pop_and_restore_active();

#endif /* GDI_2_LAYERS */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_free_base_layer
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_free_base_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(GDI_2_LAYERS)
    //memset(applist_p->base_layer_buf_ptr, 0, LCD_WIDTH * LCD_HEIGHT * 2);
    if (applist_p->base_layer_buf_ptr != NULL)
    {        
        applist_p->base_layer_buf_ptr = NULL;
    }
#endif /* GDI_2_LAYERS */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_create_adm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_create_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Create MemoryPool */
    if (applist_p->app_mem_pool != NULL && applist_p->adm_pool_id == NULL)
    {
        applist_p->adm_pool_id = kal_adm_create((void*)applist_p->app_mem_pool,
                                                    MMI_APPLIST_MEM_SIZE,
                                                    NULL,
                                                    KAL_FALSE);
        ASSERT(applist_p->adm_pool_id != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_delete_adm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_delete_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Delete ADM */
    if (applist_p->adm_pool_id != NULL)
    {
        ret = kal_adm_delete(applist_p->adm_pool_id);

        ASSERT(ret == KAL_SUCCESS);
        applist_p->adm_pool_id = NULL;
    }

    #ifdef __MMI_APPLIST_CACHE_PATH_APP_ICON__
    mmi_applist_delete_app_icon_cache_adm();
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_alloc_adm_structure
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  voidgdi_act_layer->width
 *****************************************************************************/
void mmi_applist_alloc_adm_structure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->mode != MMI_APPLIST_MODE_POPUP)
    {
        /* Cell pool */
        if (applist_p->cell_pool == NULL)
        {
            ASSERT(sizeof(mmi_applist_cell_struct) < MMI_APPLIST_APP_CELL_INFO_SIZE);
       
            applist_p->cell_pool = (mmi_applist_cell_struct*) kal_adm_alloc(
                applist_p->adm_pool_id,
                sizeof(mmi_applist_cell_struct)*MMI_APPLIST_ENTRY_NUM);
                                       
            ASSERT(applist_p->cell_pool != NULL);
       
            kal_mem_set(
                applist_p->cell_pool, 
                0, 
                sizeof(mmi_applist_cell_struct)*MMI_APPLIST_ENTRY_NUM);
        }
    }

    /* Anima node pool */
    if (applist_p->anima_node_pool == NULL)
    {
        ASSERT(sizeof(mmi_applist_anima_node_struct) < MMI_APPLIST_APP_ANIMA_NODE_SIZE);

        applist_p->anima_node_pool = (mmi_applist_anima_node_struct*) kal_adm_alloc(
            applist_p->adm_pool_id,
            sizeof(mmi_applist_anima_node_struct) * MMI_APPLIST_APP_ANIMA_NODE_NUM);
                                    
        ASSERT(applist_p->anima_node_pool != NULL);

        kal_mem_set(
            applist_p->anima_node_pool, 
            0, 
            sizeof(mmi_applist_anima_node_struct) * MMI_APPLIST_APP_ANIMA_NODE_NUM);
    }
   
    /* Cache pool */
    #ifdef __MMI_APPLIST_SMART_ASM__
    if (applist_p->can_cache_cell && applist_p->cache_pool == NULL)
    #else
    if (applist_p->cache_pool == NULL)
    #endif
    {
        ASSERT(MMI_APPLIST_APP_CACHE_PAGE_NUM > 1);
        ASSERT(sizeof(mmi_applist_cache_struct) <= MMI_APPLIST_APP_CACHE_SIZE);

        applist_p->cache_pool = (mmi_applist_cache_struct*) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(
            applist_p->adm_pool_id,
            sizeof(mmi_applist_cache_struct) * (MMI_APPLIST_APP_CACHE_NUM - MMI_APPLIST_BASE_LAYER_CAN_CACHE_APP_NUM));
                                    
        ASSERT(applist_p->cache_pool != NULL);

        kal_mem_set(
            applist_p->cache_pool, 
            0, 
            sizeof(mmi_applist_cache_struct) * (MMI_APPLIST_APP_CACHE_NUM - MMI_APPLIST_BASE_LAYER_CAN_CACHE_APP_NUM));

        kal_mem_set(
            applist_p->cache_used, 
            0, 
            sizeof(MMI_BOOL) * MMI_APPLIST_APP_CACHE_NUM);
    }

   /* indicator cache */
   if (applist_p->indicator_ptr == NULL)
    {
        applist_p->indicator_ptr = (PU8) kal_adm_alloc_noncacheable(
            applist_p->adm_pool_id,
            MMI_APPLIST_INDICATOR_CACHE_SIZE, 0 );
                                    
        ASSERT(applist_p->indicator_ptr != NULL);

        kal_mem_set(
            applist_p->indicator_ptr, 
            0, 
            MMI_APPLIST_INDICATOR_CACHE_SIZE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_free_adm_structure
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_free_adm_structure(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->mode != MMI_APPLIST_MODE_POPUP)
    {
        /* Cell pool */
        if (applist_p->cell_pool != NULL)
        {
            kal_adm_free(applist_p->adm_pool_id, (void *) applist_p->cell_pool);
            applist_p->cell_pool = NULL;
        }
    }

    /* Anima node pool */
    if (applist_p->anima_node_pool != NULL)
    {
        kal_adm_free(applist_p->adm_pool_id, (void *) applist_p->anima_node_pool);
        applist_p->anima_node_pool = NULL;
    }   
    
    /* Cache pool */
    if (applist_p->cache_pool != NULL)
    {
        kal_adm_free(applist_p->adm_pool_id, (void *) applist_p->cache_pool);
        applist_p->cache_pool = NULL;
    }

    /* indicator cache */
    if (applist_p->indicator_ptr != NULL)
    {
        kal_adm_free( applist_p->adm_pool_id, (void*)applist_p->indicator_ptr);
        applist_p->indicator_ptr = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_alloc_adm_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_alloc_adm_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Wallpaper layer */
    #ifdef __GDI_MEMORY_PROFILE_2__
    result = gdi_layer_create(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &applist_p->wallpaper_layer_handle);
    #else  //__GDI_MEMORY_PROFILE_2__    
    applist_p->wallpaper_layer_buf_ptr =
        (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(applist_p->adm_pool_id, MMI_APPLIST_WALLPAPER_MEM_SIZE);

    ASSERT(applist_p->wallpaper_layer_buf_ptr != NULL);

    result = gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_16,
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &applist_p->wallpaper_layer_handle,
        (PU8) applist_p->wallpaper_layer_buf_ptr,
        (S32) MMI_APPLIST_WALLPAPER_MEM_SIZE);
    #endif  //__GDI_MEMORY_PROFILE_2__
    ASSERT (result == GDI_SUCCEED);

#if defined(__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__) || defined(__MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__)
    /* Panel layer */
    applist_p->panel_layer_buf_ptr =
        (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(applist_p->adm_pool_id, MMI_APPLIST_PANEL_LAYER_BUFFER_SIZE*2);

    ASSERT(applist_p->panel_layer_buf_ptr != NULL);

    gdi_layer_create_cf_double_using_outside_memory(
        #ifdef __MMI_FTE_SUPPORT__
        GDI_COLOR_FORMAT_PARGB6666,
        #else  //__MMI_FTE_SUPPORT__
        GDI_COLOR_FORMAT_32_PARGB,
        #endif  //__MMI_FTE_SUPPORT__
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &applist_p->panel_layer_handle,
        (PU8) applist_p->panel_layer_buf_ptr,
        (S32) MMI_APPLIST_PANEL_LAYER_BUFFER_SIZE,
        (PU8) (applist_p->panel_layer_buf_ptr + MMI_APPLIST_PANEL_LAYER_BUFFER_SIZE),
        (S32) MMI_APPLIST_PANEL_LAYER_BUFFER_SIZE);

    /* Status bar layer */    
    applist_p->status_bar_buf_ptr =
        (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(applist_p->adm_pool_id, MMI_APPLIST_STATUS_BAR_BUFFER_SIZE * 2);

    ASSERT(applist_p->status_bar_buf_ptr != NULL);

    gdi_layer_create_cf_double_using_outside_memory(
        GDI_COLOR_FORMAT_32_PARGB,
        0,
        0,
        LCD_WIDTH,
        MMI_STATUS_BAR_HEIGHT,
        &applist_p->status_bar_layer_handle,
        applist_p->status_bar_buf_ptr,
        (S32) MMI_APPLIST_STATUS_BAR_BUFFER_SIZE,
        (PU8) (applist_p->status_bar_buf_ptr + MMI_APPLIST_STATUS_BAR_BUFFER_SIZE),
        (S32) MMI_APPLIST_STATUS_BAR_BUFFER_SIZE);   
#else
    /* Panel layer */
    applist_p->panel_layer_buf_ptr =
        (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(applist_p->adm_pool_id, MMI_APPLIST_PANEL_LAYER_BUFFER_SIZE);

    ASSERT(applist_p->panel_layer_buf_ptr != NULL);

    gdi_layer_create_cf_using_outside_memory(
        #ifdef __MMI_FTE_SUPPORT__
        GDI_COLOR_FORMAT_PARGB6666,
        #else  //__MMI_FTE_SUPPORT__
        GDI_COLOR_FORMAT_32_PARGB,
        #endif  //__MMI_FTE_SUPPORT__
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &applist_p->panel_layer_handle,
        (PU8) applist_p->panel_layer_buf_ptr,
        (S32) MMI_APPLIST_PANEL_LAYER_BUFFER_SIZE);

    /* Status bar layer */    
    applist_p->status_bar_buf_ptr =
        (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(applist_p->adm_pool_id, MMI_APPLIST_STATUS_BAR_BUFFER_SIZE);

    ASSERT(applist_p->status_bar_buf_ptr != NULL);

    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_32_PARGB,
        0,
        0,
        LCD_WIDTH,
        MMI_STATUS_BAR_HEIGHT,
        &applist_p->status_bar_layer_handle,
        applist_p->status_bar_buf_ptr,
        MMI_APPLIST_STATUS_BAR_BUFFER_SIZE);    
#endif

    gdi_layer_push_and_set_active(applist_p->status_bar_layer_handle);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR, applist_p->status_bar_layer_handle);

    /* Set status bar's blending layer */
    wgui_status_icon_bar_set_alpha_blend_layer(
        WGUI_STATUS_ICON_BAR_H_BAR, applist_p->panel_layer_handle);

    /* Register draw-background callback */
    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_H_BAR,
        hide_status_icons_bar0_by_transparent);

    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR); 

    #ifdef __MMI_APPLIST_ONLY_ICON_SUPPORT__
    /* Title layer */ 
    applist_p->title_layer_buf_ptr =
        (PU8) MMI_FRM_ADM_ALLOC_FRAMEBUFFER(applist_p->adm_pool_id, MMI_APPLIST_TITLE_LAYER_BUFFER_SIZE);

    ASSERT(applist_p->title_layer_buf_ptr != NULL);

    gdi_layer_create_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        34,
        &applist_p->title_layer_handle,
        (PU8) applist_p->title_layer_buf_ptr,
        (S32) MMI_APPLIST_TITLE_LAYER_BUFFER_SIZE);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_free_adm_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_free_adm_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Free wallpaper layer */ 
    if (applist_p->wallpaper_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(applist_p->wallpaper_layer_handle);
        applist_p->wallpaper_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    #if !defined(__GDI_MEMORY_PROFILE_2__)
    if (applist_p->wallpaper_layer_buf_ptr != NULL)
    {
        kal_adm_free(applist_p->adm_pool_id, (void*)applist_p->wallpaper_layer_buf_ptr);
        applist_p->wallpaper_layer_buf_ptr = NULL;
    }
    #endif  //!defined(__GDI_MEMORY_PROFILE_2__)
    
    /* Free status bar layer */  
    wgui_status_icon_bar_reset_alpha_blend_layer(WGUI_STATUS_ICON_BAR_H_BAR);

    if (applist_p->status_bar_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        /* Reset status bar layer config */
        wgui_status_icon_bar_set_target_layer(
            WGUI_STATUS_ICON_BAR_H_BAR, GDI_ERROR_HANDLE);

        gdi_layer_free(applist_p->status_bar_layer_handle);
        applist_p->status_bar_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (applist_p->status_bar_buf_ptr != NULL)
    {
        kal_adm_free(applist_p->adm_pool_id, (void*)applist_p->status_bar_buf_ptr);
        applist_p->status_bar_buf_ptr = NULL;
    }

    /* Free panel layer */ 
    if (applist_p->panel_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(applist_p->panel_layer_handle);
        applist_p->panel_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (applist_p->panel_layer_buf_ptr != NULL)
    {
        kal_adm_free(applist_p->adm_pool_id, (void*)applist_p->panel_layer_buf_ptr);
        applist_p->panel_layer_buf_ptr = NULL;
    }

    #ifdef __MMI_APPLIST_ONLY_ICON_SUPPORT__
    /* Free title layer */ 
    if (applist_p->title_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(applist_p->title_layer_handle);
        applist_p->title_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (applist_p->title_layer_buf_ptr != NULL)
    {
        kal_adm_free(applist_p->adm_pool_id, (void*)applist_p->title_layer_buf_ptr);
        applist_p->title_layer_buf_ptr = NULL;
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_alloc_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_alloc_pool()
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RANFOW_TRACE("[APPLIST]MMI_APPLIST_MEM_SIZE=%d,MMI_APPLIST_APP_CACHE_NUM=%d,MMI_APPLIST_APP_CACHE_MEM_SIZE=%d\n", MMI_APPLIST_MEM_SIZE, MMI_APPLIST_APP_CACHE_NUM, MMI_APPLIST_APP_CACHE_MEM_SIZE);

    /* alloc memory for wallpaper */

    
    /* allocate memory from App-Based ASM */
    if (applist_p->app_mem_pool == NULL)
    {
        applist_p->app_mem_pool = mmi_frm_asm_alloc_r(
        applist_p->parent_gid, MMI_APPLIST_MEM_SIZE);
        #ifdef __MMI_APPLIST_SMART_ASM__
        if (applist_p->app_mem_pool == NULL)
        {
            RANFOW_TRACE("[APPLIST]cannot alloc big asm\n");
            applist_p->app_mem_pool = mmi_frm_asm_alloc_r(
            applist_p->parent_gid, MMI_APPLIST_MEM_SIZE-MMI_APPLIST_APP_CACHE_MEM_SIZE);

            ASSERT(applist_p->app_mem_pool != NULL);
            applist_p->can_cache_cell = MMI_FALSE;
        }
        else
        {
            applist_p->can_cache_cell = MMI_TRUE;
        }
        #endif
        
        ASSERT(applist_p->app_mem_pool != NULL);
        
        #ifdef __MMI_APPLIST_SMART_ASM__
        RANFOW_TRACE("[APPLIST]can cache cell=%d\n", applist_p->can_cache_cell);
        #endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_free_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_free_pool()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* allocate memory from App-Based ASM */
    if (applist_p->app_mem_pool != NULL)
    {
        mmi_frm_asm_free_r(applist_p->parent_gid, applist_p->app_mem_pool);
        applist_p->app_mem_pool = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_clear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->cell_pool != NULL)
    {
        RANFOW_TRACE("[APPLIST]mmi_applist_clear\n");
        kal_adm_free(applist_p->adm_pool_id, (void *) applist_p->cell_pool);
        applist_p->cell_pool = NULL;
    }
    /* Free pool & delete ADM */
    mmi_applist_free_pool();
    mmi_applist_delete_adm();
    applist_p->mode = MMI_APPLIST_MODE_NORMAL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_applist_event_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ASSERT(evt);

    RANFOW_TRACE("[APPLIST]Got event %d[IBGE=%d,AIP=%d,AUP=%d,AUNP=%d, FNF=%d], mode=%d\n", evt->evt_id, EVT_ID_IDLE_BEFORE_GROUP_EXIT, EVT_ID_SRV_APPMGR_INSTALL_PACKAGE,
        EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE, EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE, EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT, applist_p->mode);
    
    switch (evt->evt_id)
    {
        case EVT_ID_IDLE_BEFORE_GROUP_EXIT:
            {
                if (applist_p->mode == MMI_APPLIST_MODE_POPUP)
                {
                    mmi_applist_clear();
                }
            }
            break;
        case EVT_ID_SRV_APPMGR_INSTALL_PACKAGE:
        case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
        case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
            {
                applist_p->mainmenu_need_sync = MMI_TRUE;
                mmi_applist_refresh();
            }
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_set_blt_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_set_blt_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_set_blt_layer(        
        applist_p->wallpaper_layer_handle,
        applist_p->panel_layer_handle,
        applist_p->status_bar_layer_handle,
        NULL);

    applist_p->blt_layer_flag = 
        GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
    applist_p->play_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_blt_previous
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_blt_previous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_blt_previous start\n");
    SLA_CustomLogging("ABP", SA_start);
#endif

#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
    gdi_layer_blt_with_flag(
        applist_p->wallpaper_layer_handle,
        applist_p->panel_layer_handle,
        applist_p->status_bar_layer_handle,
        NULL,
        0, 0, LCD_WIDTH, LCD_HEIGHT,
        GDI_LAYER_BLT_FLAG_NON_BLOCKING,
        NULL); 
#else
    gdi_layer_blt(applist_p->wallpaper_layer_handle,
        applist_p->panel_layer_handle,
        applist_p->status_bar_layer_handle,
        NULL,
        0, 0, LCD_WIDTH, LCD_HEIGHT);
#endif

#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_blt_previous end\n");
    SLA_CustomLogging("ABP", SA_stop);
#endif
}


#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_APPLIST_KEY_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_pen_change_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_pen_change_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (applist_p->focus_cell.cell_p == NULL || applist_p->focus_cell.index == MMI_APPLIST_INVALID_INDEX)
        return;
    
    /* store previous highlight info */
    applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
    applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
    
    applist_p->hilight_frame.cell_p = applist_p->focus_cell.cell_p;
    applist_p->hilight_frame.index = applist_p->focus_cell.index;
    applist_p->hilight_frame.type = applist_p->focus_cell.type;
    #if defined(__MMI_APPLIST_KEY_SUPPORT__) && !defined(__MMI_APPLIST_ONLY_ICON_SUPPORT__)
    if (applist_p->mode == MMI_APPLIST_MODE_NORMAL && applist_p->hilight_frame.cell_p->name_len > MMI_APPLIST_STRING_REGION)
    {
        applist_p->hilight_frame.scroll_x = 0;
        gui_start_timer(MMI_APPLIST_CELL_STRING_SCROLL_DELAY, mmi_applist_scroll_cell_string);
    }
    #endif
}

#endif  //defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_APPLIST_KEY_SUPPORT__)


#ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__

typedef struct
{
    MMI_STR_ID              string_id;
    mmi_event_notify_enum   event;
    MMI_ID                  parent_id;
} mmi_applist_popup_ctx;


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_display_popup
 * DESCRIPTION
 *  Functionality:
 * PARAMETERS
 *  mmi_applist_popup_ctx [IN]                       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_display_popup(mmi_applist_popup_ctx *popup_ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct popup_property;
    mmi_popup_property_init(&popup_property);
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (popup_ctx)
    {
        if (popup_ctx->event == MMI_EVENT_PROGRESS)
        {
            popup_property.f_auto_dismiss = MMI_FALSE;
        }
        else
        {
            popup_property.f_auto_dismiss = MMI_TRUE;
        }
        popup_property.parent_id = popup_ctx->parent_id;
        mmi_popup_display_ext(popup_ctx->string_id, popup_ctx->event, &popup_property);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_uninstall_app_proc
 * DESCRIPTION
 *  Functionality:
 * PARAMETERS
 *  mmi_event_struct [IN]                       
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_applist_uninstall_app_proc(mmi_event_struct *evt)
{
    mmi_frm_scrn_close_active_id();
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_uninstall_app_callback
 * DESCRIPTION
 *  Functionality:
 * PARAMETERS
 *  srv_appmgr_cb_event_enum [IN]       
 *  void* [IN]                   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_uninstall_app_callback(srv_appmgr_cb_event_enum result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;
    mmi_applist_popup_ctx popup_ctx;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case SRV_APPMGR_CB_EVENT_DONE:
        {
            MMI_FRM_INIT_EVENT(&evt, 0);
            mmi_frm_post_event(&evt, mmi_applist_uninstall_app_proc, 0);
            return;
        }            
        case SRV_APPMGR_CB_EVENT_ERROR:
        case SRV_APPMGR_CB_EVENT_CANCEL:
        default:
            popup_ctx.string_id = STR_GLOBAL_FAILED;
            popup_ctx.event = MMI_EVENT_FAILURE;
            break;
    }

    if (applist_p->parent_gid != GRP_ID_INVALID)
    {
        popup_ctx.parent_id  = applist_p->parent_gid;
    }
    else
    {
        popup_ctx.parent_id  = GRP_ID_ROOT;
    }
    
    RANFOW_TRACE("[APPLIST]uninstall fail in uninstall callback, result=%d\n", result);
    mmi_applist_display_popup(&popup_ctx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_uninstall_confirm_proc
 * DESCRIPTION
 *  mmi_applist_uninstall confirm proc
 *  Functionality:
 * PARAMETERS
 *  mmi_alert_result_evt_struct [IN]                       
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_applist_uninstall_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_popup_ctx popup_ctx = {0};
    mmi_alert_result_evt_struct *confirm_evt = NULL;
    mmi_applist_user_tag *user_tag = NULL;
    mmi_app_package_name_struct app_name = {0};
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ASSERT(evt);
    
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            confirm_evt = (mmi_alert_result_evt_struct*)evt;
            user_tag = (mmi_applist_user_tag*)confirm_evt->user_tag;
            switch (confirm_evt->result)
            {
                case MMI_ALERT_CNFM_OK:
                case MMI_ALERT_CNFM_YES:
                {
                    mmi_applist_popup_ctx popup_ctx;
                    popup_ctx.string_id = STR_ID_APPLIST_UNINSTALLING;
                    popup_ctx.event = MMI_EVENT_PROGRESS;
                    if (applist_p->parent_gid != GRP_ID_INVALID)
                    {
                        popup_ctx.parent_id  = applist_p->parent_gid;
                    }
                    else
                    {
                        popup_ctx.parent_id  = GRP_ID_ROOT;
                    }
                    mmi_applist_display_popup(&popup_ctx);

                    #ifdef __MMI_APPLIST_CACHE_APP_NAME__
                    if (user_tag->cell_type == MMI_APPLIST_CELL_TYPE_PANEL)
                        mmi_ucs2ncpy((CHAR *)app_name, (CHAR *)applist_p->app_name[MMI_APPLIST_BAR_APP_NUM+user_tag->idx], MMI_APP_NAME_MAX_LEN);
                    else
                        mmi_ucs2ncpy((CHAR *)app_name, (CHAR *)applist_p->app_name[user_tag->idx], MMI_APP_NAME_MAX_LEN);
                    
                    #else  //__MMI_APPLIST_CACHE_APP_NAME__
                    
                    
                    if (user_tag->cell_type == MMI_APPLIST_CELL_TYPE_PANEL)
                        srv_appmgr_get_app_package_name_by_id(applist_p->panel_cell[user_tag->idx]->app_id, app_name);
                    else
                        srv_appmgr_get_app_package_name_by_id(applist_p->bar_cell[user_tag->idx]->app_id, app_name);
                    #endif  //__MMI_APPLIST_CACHE_APP_NAME__
                    
                    if (srv_appmgr_uninstall_app(app_name, mmi_applist_uninstall_app_callback, NULL) == MMI_RET_ERR)
                    {
                        RANFOW_TRACE("[APPLIST]uninstall fail in confirm proc\n");
                        popup_ctx.string_id = STR_GLOBAL_FAILED;
                        popup_ctx.event = MMI_EVENT_FAILURE;
                        if (applist_p->parent_gid != GRP_ID_INVALID)
                        {
                            popup_ctx.parent_id  = applist_p->parent_gid;
                        }
                        else
                        {
                            popup_ctx.parent_id  = GRP_ID_ROOT;
                        }
                        mmi_applist_display_popup(&popup_ctx);
                    }
                    break;
                }
                default:
                break;
            }
        }
    }

    return  MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_uninstall_app_by_name
 * DESCRIPTION
 *  
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_uninstall_app_by_name(S32 idx, mmi_applist_cell_type_enum cell_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_bg_running = MMI_FALSE;
    mmi_app_package_name_struct app_name = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_APPLIST_CACHE_APP_NAME__
    if (cell_type == MMI_APPLIST_CELL_TYPE_PANEL)
        mmi_ucs2ncpy((CHAR *)app_name, (CHAR *)applist_p->app_name[MMI_APPLIST_BAR_APP_NUM+idx], MMI_APP_NAME_MAX_LEN);
    else
        mmi_ucs2ncpy((CHAR *)app_name, (CHAR *)applist_p->app_name[idx], MMI_APP_NAME_MAX_LEN);

    #else  //__MMI_APPLIST_CACHE_APP_NAME__
    
    if (cell_type == MMI_APPLIST_CELL_TYPE_PANEL)
        srv_appmgr_get_app_package_name_by_id(applist_p->panel_cell[idx]->app_id, app_name);
    else
        srv_appmgr_get_app_package_name_by_id(applist_p->bar_cell[idx]->app_id, app_name);
    #endif  //__MMI_APPLIST_CACHE_APP_NAME__

    if(strncmp(app_name, "mre", 3) == 0)
    {
        is_bg_running = srv_mre_appmgr_is_bg_running(app_name);
    }
#if defined(__J2ME__)
    else if (strncmp(app_name, "java", 4) == 0)
    {
         is_bg_running = srv_java_appfactory_is_app_running(app_name);
    }
#endif

    /* set mode as MMI_APPLIST_MODE_POPUP to keep cell info cache to improve performance */
    applist_p->mode = MMI_APPLIST_MODE_POPUP;

    if(is_bg_running)
    {
        mmi_applist_popup_ctx popup_ctx;
        popup_ctx.string_id = STR_ID_APPLIST_EXIT_RUNNING_APP;
        popup_ctx.event = MMI_EVENT_FAILURE;
        if (applist_p->parent_gid != GRP_ID_INVALID)
        {
            popup_ctx.parent_id  = applist_p->parent_gid;
        }
        else
        {
            popup_ctx.parent_id  = GRP_ID_ROOT;
        }
        mmi_applist_display_popup(&popup_ctx);
    }
    else
    {
        WCHAR display_str[255] = {0};
        mmi_confirm_property_struct confirm_property;
        
        mmi_confirm_property_init(&confirm_property, CNFM_TYPE_YESNO);
        confirm_property.callback = (mmi_proc_func)mmi_applist_uninstall_confirm_proc;
        applist_p->user_tag.idx = idx;
        applist_p->user_tag.cell_type = cell_type;
        confirm_property.user_tag = &applist_p->user_tag;
        if (applist_p->parent_gid != GRP_ID_INVALID)
        {
            confirm_property.parent_id  = applist_p->parent_gid;
        }
        else
        {
            confirm_property.parent_id  = GRP_ID_ROOT;
        }
        //confirm_property.f_auto_question_mark = MMI_TRUE;
        
        if (cell_type == MMI_APPLIST_CELL_TYPE_PANEL)
            kal_wsprintf(display_str, "%w %w \0\?\0 ", GetString(STR_ID_APPLIST_UNINSTALL), applist_p->panel_cell[idx]->name);
        else
            kal_wsprintf(display_str, "%w %w \0\?\0 ", GetString(STR_ID_APPLIST_UNINSTALL), applist_p->bar_cell[idx]->name);
        
        mmi_confirm_display(
            display_str,
            MMI_EVENT_CONFIRM,
            &confirm_property);
    }
}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_reset_focus_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_reset_focus_cell(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    applist_p->focus_cell.state = MMI_APPLIST_CELL_STATE_UNSELECTED;    
    applist_p->focus_cell.index = MMI_APPLIST_INVALID_INDEX;   
    applist_p->focus_cell.cell_p = NULL;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_entry_edit_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_entry_edit_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cur_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
    if (applist_p->installed_id[0] == 0)
    {
        mmi_applist_get_installed_app_id();
    }
    #endif
    
    cur_time = mmi_applist_get_cur_time();
#if defined(__MMI_APPLIST_KEY_SUPPORT__) && !defined(__MMI_APPLIST_ONLY_ICON_SUPPORT__)
    gui_cancel_timer(mmi_applist_scroll_cell_string);
#endif

#if !defined(__MMI_APPLIST_KEY_SUPPORT__) && defined(G2D_SUPPORT)
    /* Change opacity */
    applist_p->focus_cell.cell_p->opacity = MMI_APPLIST_CELL_NORMAL_OPACITY;
    
    /* Change size */
    mmi_applist_change_cell_resize_anima(
        applist_p->focus_cell.cell_p,
        MMI_APPLIST_CELL_SELECTED_RESIZE,
        cur_time);
#else
    /* Normal(from long press Enter key): no focus cell
     * Normal(from long touch icon): hilight frame == focus cell
     */
    if (applist_p->mode == MMI_APPLIST_MODE_EDIT)
    {
        /* store previous highlight info */
        applist_p->hilight_frame.pre_type = applist_p->hilight_frame.type;
        applist_p->hilight_frame.pre_index = applist_p->hilight_frame.index;
        /* Update touched cell as highligt cell */
        applist_p->hilight_frame.cell_p = applist_p->focus_cell.cell_p;
        applist_p->hilight_frame.index = applist_p->focus_cell.index;
        applist_p->hilight_frame.type = applist_p->focus_cell.type;
    }
#endif

    if (applist_p->focus_cell.state == MMI_APPLIST_CELL_STATE_TOUCHED)
    {        
        applist_p->focus_cell.state = MMI_APPLIST_CELL_STATE_SELECTED;
    }
    
    applist_p->slide_state = MMI_APPLIST_SLIDE_STATE_DISABLE;

    /* Entry edit mode */
    if (applist_p->mode != MMI_APPLIST_MODE_EDIT)
    {
        /* Stop wallpaper */
        mmi_applist_stop_wallpaper(MMI_APPLIST_WP_STOP_TYPE_EDIT_MODE);
        
        applist_p->edit_page_num = mmi_applist_get_current_page_num();
        #ifdef G2D_SUPPORT
        mmi_applist_add_shake_anima(cur_time);
        #endif

        applist_p->mode = MMI_APPLIST_MODE_EDIT; 
    }

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_APPLIST_KEY_SUPPORT__)
    mmi_applist_pen_change_highlight();
#endif

    gui_cancel_timer(mmi_applist_update_anima_data);    
    mmi_applist_update_anima_data(); 
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_exit_edit_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_exit_edit_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_page_idx, curr_hilight_page;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->state == MMI_APPLIST_STATE_NONE)
        return;    

    /* Compact page */
    new_page_idx = mmi_applist_compact_page();

    mmi_applist_save_data();    
    
    #ifdef G2D_SUPPORT
    mmi_applist_remove_shake_anima();
    #endif

    if (applist_p->mode != MMI_APPLIST_MODE_EDIT)
        return;

    #ifdef __MMI_APPLIST_KEY_SUPPORT__
    curr_hilight_page = applist_p->hilight_frame.index / MMI_APPLIST_APP_COUNT_PER_PAGE;
    if (applist_p->hilight_frame.type == MMI_APPLIST_CELL_TYPE_PANEL && curr_hilight_page != new_page_idx)
    {
        applist_p->slide_region.x = new_page_idx * MMI_APPLIST_PAGE_WIDTH_INC_MARGIN;
        mmi_applist_init_hilight_index_in_page();
    }
    #ifndef __MMI_APPLIST_ONLY_ICON_SUPPORT__
    else if (applist_p->hilight_frame.cell_p->name_len > MMI_APPLIST_STRING_REGION)
    {
        applist_p->hilight_frame.scroll_x = 0;
        gui_start_timer(MMI_APPLIST_CELL_STRING_SCROLL_DELAY * 2, mmi_applist_scroll_cell_string);
    }
    #endif  //__MMI_APPLIST_ONLY_ICON_SUPPORT__
    #endif  //__MMI_APPLIST_KEY_SUPPORT__
 
    /* Slide to new page */
    applist_p->slide_type = MMI_APPLIST_SLIDE_BY_KEY;
    mmi_applist_slide_to_page(new_page_idx);
    
    gui_cancel_timer(mmi_applist_update_anima_data);    
    mmi_applist_update_anima_data(); 

    applist_p->mode = MMI_APPLIST_MODE_NORMAL;
    applist_p->state = MMI_APPLIST_STATE_RESET;

    /* Start wallpaper */
    mmi_applist_delay_start_wallpaper(
        MMI_APPLIST_WP_STOP_TYPE_EDIT_MODE, MMI_APPLIST_WALLPAPER_DELAY_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_slide_to_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_slide_to_page(S32 page_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 page_num, curr_page_idx = mmi_applist_get_current_page_idx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (page_idx > curr_page_idx
        #ifdef __MMI_APPLIST_KEY_LOOP__
        && !applist_p->is_loop
        #endif
        )
    {
        applist_p->slide_region.slide_dir = MMI_APPLIST_DIR_RIGHT;
    }
    else
    {
        applist_p->slide_region.slide_dir = MMI_APPLIST_DIR_LEFT;
    }
    page_num = mmi_applist_get_current_page_num();    
    
    if (page_idx >= page_num)
    {
        page_idx = page_num - 1;
    }
    else if (page_idx < 0)
    {
        page_idx = 0;
    }

    gui_cancel_timer(mmi_applist_quiet_cache);

    mmi_applist_change_slide_x_anima(page_idx * MMI_APPLIST_PAGE_WIDTH_INC_MARGIN);

    /* Update indicator info */
    mmi_applist_set_indicator_info(page_idx);

#ifdef __MMI_APPLIST_KEY_SUPPORT__
#ifdef __MMI_TOUCH_SCREEN__
    if (applist_p->state == MMI_APPLIST_STATE_CYCLIC || (applist_p->slide_type == MMI_APPLIST_SLIDE_BY_PEN && applist_p->state != MMI_APPLIST_STATE_AUTOSLIDE))
#else
    if (applist_p->state == MMI_APPLIST_STATE_CYCLIC)
#endif
    {
        mmi_applist_init_hilight_index_in_page();
    }
#endif

    if (applist_p->state != MMI_APPLIST_STATE_FIRST_ENTER && applist_p->state != MMI_APPLIST_STATE_ENTER)
    {
        applist_p->state = MMI_APPLIST_STATE_SLIDING;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_slide_to_nearest_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_slide_to_nearest_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 page_idx, remain;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (applist_p->slide_region.x < 0)
    {
        mmi_applist_change_slide_x_anima(0);
    }
    else
    {
        page_idx = applist_p->slide_region.x / MMI_APPLIST_PAGE_WIDTH_INC_MARGIN;
        remain = applist_p->slide_region.x % MMI_APPLIST_PAGE_WIDTH_INC_MARGIN;
        
        if (remain > LCD_WIDTH / 2)
        {
            page_idx ++;
        } 

        mmi_applist_slide_to_page(page_idx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_post_launch_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_post_launch_cell(U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_launch_event_struct event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_FRM_INIT_EVENT(&event, 0);
    event.app_id = app_id; 
    MMI_FRM_POST_EVENT(&event, mmi_applist_launch_cell, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_if_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_if_auto_slide(S32 pos_x, S32 pos_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 start_y = MMI_STATUS_BAR_HEIGHT + MMI_APPLIST_TITLE_BAR_HEIGHT;
    S32 end_y = MMI_STATUS_BAR_HEIGHT + 
        MMI_APPLIST_TITLE_BAR_HEIGHT +  
        MMI_APPLIST_SLIDE_AREA_HEIGHT + 
        MMI_APPLIST_INDICATOR_BAR_HEIGHT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (pos_y >= start_y && pos_y < end_y)
    {
        if (pos_x < MMI_APPLIST_PAGE_AUTO_SLIDE_THRESHOLD)
        {
            return MMI_TRUE;
        }
        
        if (pos_x > LCD_WIDTH - MMI_APPLIST_PAGE_AUTO_SLIDE_THRESHOLD)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


#if defined(__MMI_TOUCH_SCREEN__)

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_auto_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_auto_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 page_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Change state */
    if (applist_p->slide_state == MMI_APPLIST_SLIDE_STATE_DISABLE)
    {
        applist_p->slide_state = MMI_APPLIST_SLIDE_STATE_ENABLE;
    }
    else if (applist_p->slide_state == MMI_APPLIST_SLIDE_STATE_DISABLE_EXPENDED)
    {
        applist_p->slide_state = MMI_APPLIST_SLIDE_STATE_ENABLE_EXPENDED;
    }
    
    page_idx = mmi_applist_get_current_page_idx();        
    
    if (applist_p->pen_last_pos.x < MMI_APPLIST_PAGE_AUTO_SLIDE_THRESHOLD)
    {
        page_idx --;
    } 
    else if (applist_p->pen_last_pos.x > LCD_WIDTH - MMI_APPLIST_PAGE_AUTO_SLIDE_THRESHOLD)
    {
        page_idx ++;
    }
    else 
    {
        mmi_applist_cancel_auto_slide();
        return;
    }

    if (page_idx < 0 || page_idx >= MMI_APPLIST_MAX_PAGE_NUM)
    {        
        mmi_applist_cancel_auto_slide();
        return;
    }

    /* Expend page num */
    if (page_idx + 1 > applist_p->edit_page_num)
    {        
        if (applist_p->slide_state == MMI_APPLIST_SLIDE_STATE_ENABLE)
        {
            applist_p->edit_page_num = page_idx + 1;
            applist_p->slide_state = MMI_APPLIST_SLIDE_STATE_ENABLE_EXPENDED;
        }
        else
        {
            mmi_applist_cancel_auto_slide();
            return;
        }
    }

    applist_p->state = MMI_APPLIST_STATE_AUTOSLIDE;
    
    /* Slide to page_idx */
    mmi_applist_slide_to_page(page_idx);
        
    /* Reposition in the new page */
    mmi_applist_reposition_cell();
    
    /* Re-start auto slide timer */
    gui_start_timer(
        MMI_APPLIST_PAGE_AUTO_SLIDE_DELAY, 
        mmi_applist_auto_slide);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_cancel_auto_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_cancel_auto_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (applist_p->slide_state == MMI_APPLIST_SLIDE_STATE_ENABLE)
    {
        applist_p->slide_state = MMI_APPLIST_SLIDE_STATE_DISABLE;
    }
    else if (applist_p->slide_state == MMI_APPLIST_SLIDE_STATE_ENABLE_EXPENDED)
    {
        applist_p->slide_state = MMI_APPLIST_SLIDE_STATE_DISABLE_EXPENDED;
    }
    
    gui_cancel_timer(mmi_applist_auto_slide);
    
    gui_start_timer(
        MMI_APPLIST_ENTER_ORGANIZE_CELL_DELAY, 
        mmi_applist_reposition_cell);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_if_swipe(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cur_time, elapse;
    S32 diff_x; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    cur_time = mmi_applist_get_cur_time();

    if (cur_time > applist_p->pen_down_tick)
    {
        elapse = cur_time - applist_p->pen_down_tick;
    }
    else 
    {
        elapse = (0xFFFFFFFF - applist_p->pen_down_tick) + cur_time;
    }
    
    diff_x = pos.x - applist_p->pen_down_pos.x;

    if (elapse < MMI_APPLIST_PAGE_SWIPE_TIME_THRESHOLD &&
        abs(diff_x) > MMI_APPLIST_PAGE_SWIPE_DIST_THRESHOLD)  
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_applist_slide_to_nearby_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_slide_to_nearby_page(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (pos.x < applist_p->pen_down_pos.x)
    {        
        mmi_applist_slide_to_page(applist_p->pen_down_page_idx + 1);                
    }
    else 
    {        
        mmi_applist_slide_to_page(applist_p->pen_down_page_idx - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    mmi_applist_cell_struct *cell_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    if (applist_p->state == MMI_APPLIST_STATE_NONE)
        return;
    
    #ifdef __MMI_APPLIST_BARREL_SUPPORT__
    gui_cancel_timer(mmi_applist_barrel_auto_slide_back);
    if (applist_p->mode == MMI_APPLIST_MODE_EFFECT_PREVIEW)
    {
        applist_p->mode = MMI_APPLIST_MODE_NORMAL;
    }
    #endif
    
    #if defined(__MMI_APPLIST_KEY_SUPPORT__) && !defined(__MMI_APPLIST_ONLY_ICON_SUPPORT__)
    gui_cancel_timer(mmi_applist_scroll_cell_string);
    #endif
        
    /* Stop wallpaper */
    mmi_applist_stop_wallpaper(MMI_APPLIST_WP_STOP_TYPE_PEN_DOWN);
    
    applist_p->slide_state = MMI_APPLIST_SLIDE_STATE_DISABLE;    
    applist_p->slide_type = MMI_APPLIST_SLIDE_BY_PEN;        
    applist_p->pen_down_pos = pos;
    applist_p->pen_last_pos = pos;
    applist_p->pen_down_tick = mmi_applist_get_cur_time();
    applist_p->pen_down_page_idx = mmi_applist_get_current_page_idx(); 
      
    mmi_applist_get_hit_area(pos.x, pos.y, &applist_p->hit_area);

    /* Handle slide */
    if (applist_p->hit_area.type == MMI_APPLIST_AREA_TYPE_SLIDE ||
        applist_p->hit_area.type == MMI_APPLIST_AREA_TYPE_SHORTCUT_BAR)
    {
        /* Assign focus cell */
        if (applist_p->hit_area.type == MMI_APPLIST_AREA_TYPE_SLIDE)
        {
            applist_p->focus_cell.type = MMI_APPLIST_CELL_TYPE_PANEL;
            mmi_applist_set_focus_cell_info();
            
        }
        else if (applist_p->hit_area.type == MMI_APPLIST_AREA_TYPE_SHORTCUT_BAR)
        {
            applist_p->focus_cell.type = MMI_APPLIST_CELL_TYPE_SHORTCUT;
            mmi_applist_set_focus_cell_info();            
        }
        else
        {
            //TODO: focus_cell.type is not reset. Is it ok ?
            mmi_applist_reset_focus_cell();
        }

        /* If in sliding state */
        if (applist_p->slide_region.anima_node_p)
        {
            mmi_applist_remove_slide_x_anima();
            /* Don't reset focus type */
            mmi_applist_reset_focus_cell();
        }
        
        if (applist_p->focus_cell.state == MMI_APPLIST_CELL_STATE_TOUCHED)
        {
            /* Change opacity */            
            cell_ptr = applist_p->focus_cell.cell_p;
        #ifndef __MMI_APPLIST_KEY_SUPPORT__            
            cell_ptr->opacity = MMI_APPLIST_CELL_TOUCHED_OPACITY;
        #endif
            /* Assign pen down shift */
            applist_p->focus_cell.pen_shift.x = pos.x - GET_CELL_X(applist_p->focus_cell.type, cell_ptr->pos.x);
            applist_p->focus_cell.pen_shift.y = pos.y - cell_ptr->pos.y;
            
            /* Start timer */
            if (applist_p->mode == MMI_APPLIST_MODE_NORMAL)
            {
                gui_start_timer(
                    MMI_APPLIST_ENTER_EDIT_MODE_DELAY, 
                    mmi_applist_entry_edit_mode);
            }
            else
            {
                gui_start_timer(
                    MMI_APPLIST_ENTER_SELECTED_DELAY_IN_EDIT, 
                    mmi_applist_entry_edit_mode);
            }

            mmi_applist_draw_panel();
            mmi_applist_blt_previous();
        }
    }
    else if (applist_p->hit_area.type == MMI_APPLIST_AREA_TYPE_INDICATOR_BAR)
    {       
        mmi_applist_reset_focus_cell();
        
        mmi_applist_slide_to_page(applist_p->hit_area.index);

        gui_cancel_timer(mmi_applist_update_anima_data);    
        mmi_applist_update_anima_data(); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (applist_p->state == MMI_APPLIST_STATE_NONE)
        return;

    if (pos.x > applist_p->pen_last_pos.x)
    {
        applist_p->slide_region.slide_dir = MMI_APPLIST_DIR_LEFT;
    }
    else
    {
        applist_p->slide_region.slide_dir = MMI_APPLIST_DIR_RIGHT;
    }

    if (applist_p->hit_area.type == MMI_APPLIST_AREA_TYPE_SLIDE ||
        applist_p->hit_area.type == MMI_APPLIST_AREA_TYPE_SHORTCUT_BAR)
    {
        cell_ptr = applist_p->focus_cell.cell_p;
        
        if (applist_p->focus_cell.state == MMI_APPLIST_CELL_STATE_TOUCHED)
        {
            if (APPLIST_ABS(pos.x - applist_p->pen_down_pos.x) > MMI_APPLIST_CANCEL_EDIT_THRESHOLD_X ||
                APPLIST_ABS(pos.y - applist_p->pen_down_pos.y) > MMI_APPLIST_CANCEL_EDIT_THRESHOLD_Y)
            {
                gui_cancel_timer(mmi_applist_entry_edit_mode);

            #ifndef __MMI_APPLIST_KEY_SUPPORT__
                cell_ptr->opacity = MMI_APPLIST_CELL_NORMAL_OPACITY; 
            #endif
                mmi_applist_reset_focus_cell();            
                    
                    
                if (applist_p->focus_cell.type == MMI_APPLIST_CELL_TYPE_PANEL)
                {
                    /* Do slide */        
                    mmi_applist_change_slide_x(pos);
                } 
            }
            applist_p->pen_last_pos = pos;
        }
        else if (applist_p->focus_cell.state == MMI_APPLIST_CELL_STATE_UNSELECTED)
        { 
            if (applist_p->focus_cell.type == MMI_APPLIST_CELL_TYPE_PANEL)
            {
                /* Do slide */        
                mmi_applist_change_slide_x(pos);
            }
            applist_p->pen_last_pos = pos;
        }
        else if (applist_p->focus_cell.state == MMI_APPLIST_CELL_STATE_SELECTED)
        {
            applist_p->pen_last_pos = pos;       
            
            /* Start timer to re-position cell */
            gui_cancel_timer(mmi_applist_reposition_cell);       

            /* If slide */
            if (mmi_applist_if_auto_slide(pos.x, pos.y))
            {            
                if (applist_p->slide_state == MMI_APPLIST_SLIDE_STATE_DISABLE ||
                    applist_p->slide_state == MMI_APPLIST_SLIDE_STATE_DISABLE_EXPENDED)
                {                   
                    mmi_applist_auto_slide();
                    return; /* Already blt. so return */
                }
            }
            else
            {      
                mmi_applist_cancel_auto_slide();
                          
            }

            /* Update focus cell's position */
            mmi_applist_update_focus_cell_pos();        
        }
    }
    else if (applist_p->hit_area.type == MMI_APPLIST_AREA_TYPE_INDICATOR_BAR)
    {   
        /* Update index */
        applist_p->hit_area.index = mmi_applist_get_indicator_hit_index(pos.x, pos.y); 

        mmi_applist_slide_to_page(applist_p->hit_area.index);

        gui_cancel_timer(mmi_applist_update_anima_data);    
        mmi_applist_update_anima_data(); 
        return; /* Already blt. so return */
    }
    
    mmi_applist_draw_panel();
    mmi_applist_blt_previous();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell_ptr = NULL;
    mmi_applist_position dst_pos;
    U32 cur_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->state == MMI_APPLIST_STATE_NONE)
        return;
    
    cur_time = mmi_applist_get_cur_time();

    #ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
    if (applist_p->mode == MMI_APPLIST_MODE_EDIT && cur_time - applist_p->pen_down_tick < MMI_APPLIST_ENTER_EDIT_MODE_DELAY)
    {
        if ((pos.y >= MMI_APPLIST_SLIDE_AREA_Y && pos.y <= MMI_APPLIST_INDICATOR_BAR_Y + MMI_APPLIST_APP_UNINSTALL_ICON_HEIGHT - MMI_APPLIST_CELL_HEIGHT) &&
            ((pos.y - MMI_APPLIST_SLIDE_AREA_Y) % MMI_APPLIST_CELL_HEIGHT <= MMI_APPLIST_APP_UNINSTALL_ICON_HEIGHT) &&
            (pos.x % MMI_APPLIST_CELL_WIDTH <= MMI_APPLIST_APP_UNINSTALL_ICON_WIDTH))
        {//panel
            S32 idx = mmi_applist_get_cell_idx(mmi_applist_get_current_page_idx(), pos.x/MMI_APPLIST_CELL_WIDTH, (pos.y-MMI_APPLIST_SLIDE_AREA_Y)/MMI_APPLIST_CELL_HEIGHT);
            if (applist_p->panel_cell[idx] != NULL && mmi_applist_is_installed_app(applist_p->panel_cell[idx]->app_id))
            {
                mmi_applist_uninstall_app_by_name(idx, MMI_APPLIST_CELL_TYPE_PANEL);
                return;
            }
        }
        else if ((pos.y >= MMI_APPLIST_SHORTCUT_BAR_Y && pos.y <= LCD_HEIGHT - MMI_APPLIST_APP_UNINSTALL_ICON_HEIGHT) &&
            (pos.x + mmi_applist_get_bar_start_x() < LCD_WIDTH - MMI_APPLIST_CELL_WIDTH + MMI_APPLIST_APP_UNINSTALL_ICON_WIDTH) &&
            ((pos.x - mmi_applist_get_bar_start_x()) % MMI_APPLIST_CELL_WIDTH <= MMI_APPLIST_APP_UNINSTALL_ICON_WIDTH))
        {//shourtcut bar
            S32 idx = (pos.x - mmi_applist_get_bar_start_x()) / MMI_APPLIST_CELL_WIDTH;
            if (applist_p->bar_cell[idx] != NULL && mmi_applist_is_installed_app(applist_p->bar_cell[idx]->app_id))
            {
                mmi_applist_uninstall_app_by_name(idx, MMI_APPLIST_CELL_TYPE_SHORTCUT);
                return;
            }
        }
    }
    #endif

    /* Delay start wallpaper */
    mmi_applist_delay_start_wallpaper(
        MMI_APPLIST_WP_STOP_TYPE_PEN_DOWN, MMI_APPLIST_WALLPAPER_DELAY_TIME); 
                    
    if (applist_p->hit_area.type == MMI_APPLIST_AREA_TYPE_SLIDE ||
        applist_p->hit_area.type == MMI_APPLIST_AREA_TYPE_SHORTCUT_BAR)
    {
        
        cell_ptr = applist_p->focus_cell.cell_p;
        
        if (applist_p->focus_cell.state == MMI_APPLIST_CELL_STATE_TOUCHED)
        {        
            gui_cancel_timer(mmi_applist_entry_edit_mode);
        #ifndef __MMI_APPLIST_KEY_SUPPORT__
            cell_ptr->opacity = MMI_APPLIST_CELL_NORMAL_OPACITY;
        #endif
            if (applist_p->mode == MMI_APPLIST_MODE_NORMAL)
            {
                #ifdef __MMI_APPLIST_KEY_SUPPORT__
                mmi_applist_pen_change_highlight();
                #endif
                /* Launch application */
                mmi_applist_post_launch_cell(
                    applist_p->focus_cell.cell_p->app_id);           
            
                mmi_applist_reset_focus_cell();
            }
        }
        else if (applist_p->focus_cell.state == MMI_APPLIST_CELL_STATE_UNSELECTED)
        { 
            if (applist_p->focus_cell.type == MMI_APPLIST_CELL_TYPE_PANEL)
            {
                mmi_applist_change_slide_x(pos);
                
                /* Do slide */  
                if (mmi_applist_if_swipe(pos))
                {
                    mmi_applist_slide_to_nearby_page(pos);
                }
                else
                {
                    mmi_applist_slide_to_nearest_page();
                }           
            }
            else if (applist_p->focus_cell.type == MMI_APPLIST_CELL_TYPE_SHORTCUT)
            {
                mmi_applist_slide_to_nearest_page();
            }

            gui_cancel_timer(mmi_applist_update_anima_data);    
            mmi_applist_update_anima_data();
            return; /* Return here to avoid blt again */
        }
        else if (applist_p->focus_cell.state == MMI_APPLIST_CELL_STATE_SELECTED)
        {
            /* Cancel re-position cell timer  */
            gui_cancel_timer(mmi_applist_reposition_cell);
            
            /* Reset auto slide */
            gui_cancel_timer(mmi_applist_auto_slide);
            applist_p->slide_state = MMI_APPLIST_SLIDE_STATE_DISABLE;

            #if !defined(__MMI_APPLIST_KEY_SUPPORT__) && defined(G2D_SUPPORT)
            /* Change size */
            mmi_applist_change_cell_resize_anima(
                cell_ptr, MMI_APPLIST_CELL_NORMAL_RESIZE, cur_time);
            #endif
            
            /* Move focus cell */
            mmi_applist_get_cell_position(
                applist_p->focus_cell.type,
                applist_p->focus_cell.index,
                &dst_pos);
            mmi_applist_change_pos_anima(&cell_ptr->pos, &dst_pos, cur_time);
            
            /* Reset focus cell */
            mmi_applist_reset_focus_cell();

            mmi_applist_put_cache_cell();

            gui_cancel_timer(mmi_applist_update_anima_data);    
            mmi_applist_update_anima_data();
            return; /* Return here to avoid blt again */
        }
    }
    else if (applist_p->hit_area.type == MMI_APPLIST_AREA_TYPE_INDICATOR_BAR)
    {   
        /* Do nothing */
    }
 
    mmi_applist_draw_panel();
    mmi_applist_blt_previous();
}
#endif /* __MMI_TOUCH_SCREEN__ */


#ifdef __MMI_APPLIST_KEY_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_up_arrow_key_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_up_arrow_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_applist_arrow_key_press(MMI_APPLIST_DIR_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_down_arrow_key_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_down_arrow_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_applist_arrow_key_press(MMI_APPLIST_DIR_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_enter_key_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_enter_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (applist_p->state != MMI_APPLIST_STATE_NORMAL)
        return;

    applist_p->key_down_tick = mmi_applist_get_cur_time();
    
    if (applist_p->mode == MMI_APPLIST_MODE_NORMAL)
    {
        gui_start_timer(
            MMI_APPLIST_ENTER_EDIT_MODE_DELAY, 
            mmi_applist_entry_edit_mode);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_enter_key_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_enter_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->state == MMI_APPLIST_STATE_NONE)
        return;
    
    cur_time = mmi_applist_get_cur_time();
    
    #ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
    if (applist_p->mode == MMI_APPLIST_MODE_EDIT && cur_time - applist_p->key_down_tick < MMI_APPLIST_ENTER_EDIT_MODE_DELAY &&
        applist_p->hilight_frame.cell_p != NULL && mmi_applist_is_installed_app(applist_p->hilight_frame.cell_p->app_id))
    {
        mmi_applist_uninstall_app_by_name(applist_p->hilight_frame.index, applist_p->hilight_frame.type);
        return;
    }
    #endif
    
    if (applist_p->state != MMI_APPLIST_STATE_NORMAL)
        return;
    
    gui_cancel_timer(mmi_applist_entry_edit_mode);
    
    /* Launcher app */
    if (applist_p->mode == MMI_APPLIST_MODE_NORMAL)
    {
        /* Launch application */
        mmi_applist_post_launch_cell(
            applist_p->hilight_frame.cell_p->app_id);           
    }
}


#endif /* __MMI_APPLIST_KEY_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_auto_slide_with_key_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_auto_slide_with_key_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 final_page_idx, page_num, page_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    page_idx = final_page_idx = mmi_applist_get_final_page_idx();
    page_num = mmi_applist_get_current_page_num(); 

    
    switch (applist_p->long_press_dir)
    {
        case MMI_APPLIST_DIR_LEFT:
            /* Slide to previous page */
            if (final_page_idx > 0)
            {
                #ifdef __MMI_APPLIST_KEY_LOOP__
                applist_p->is_loop = MMI_FALSE;
                #endif
                page_idx = final_page_idx - 1;
            }
            else
            {
                #ifdef __MMI_APPLIST_KEY_LOOP__
                applist_p->is_loop = MMI_TRUE;
                page_idx = page_num - 1;
                #endif
            }
    
            break;
        case MMI_APPLIST_DIR_RIGHT:

            /* Slide to next page */
            if (final_page_idx + 1 < page_num)
            {
                #ifdef __MMI_APPLIST_KEY_LOOP__
                applist_p->is_loop = MMI_FALSE;
                #endif
                page_idx = final_page_idx + 1;
            }
            else
            {
                #ifdef __MMI_APPLIST_KEY_LOOP__
                applist_p->is_loop = MMI_TRUE;
                page_idx = 0;
                #endif
            }
            break;
    }

    if (page_idx != final_page_idx)
    {
        applist_p->state = MMI_APPLIST_STATE_CYCLIC;
        /* Slide to page_idx */
        mmi_applist_slide_to_page(page_idx);
    }
    
    gui_cancel_timer(mmi_applist_update_anima_data);    
    mmi_applist_update_anima_data();  
    
    /* Re-start auto slide timer */
    gui_start_timer(
        MMI_APPLIST_PAGE_AUTO_SLIDE_DELAY, 
        mmi_applist_auto_slide_with_key_cyclic);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_arrow_key_press_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_arrow_key_press_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (applist_p->long_press_dir)
    {
        #ifdef __MMI_APPLIST_KEY_SUPPORT__
        case MMI_APPLIST_DIR_UP:
        case MMI_APPLIST_DIR_DOWN:
            mmi_applist_arrow_key_press(applist_p->long_press_dir);

            gui_start_timer(
                MMI_APPLIST_KEY_LONG_PRESS_DELAY,
                mmi_applist_arrow_key_press_cyclic);
            break;
        #endif
        case MMI_APPLIST_DIR_LEFT:
        case MMI_APPLIST_DIR_RIGHT:
            #ifdef __MMI_APPLIST_KEY_SUPPORT__
            if (applist_p->mode == MMI_APPLIST_MODE_EDIT ||
                applist_p->hilight_frame.type == MMI_APPLIST_CELL_TYPE_SHORTCUT)                
            {
                mmi_applist_arrow_key_press(applist_p->long_press_dir);
            #else
            if (applist_p->mode == MMI_APPLIST_MODE_EDIT)
            {
            #endif
                gui_start_timer(
                    MMI_APPLIST_KEY_LONG_PRESS_DELAY,
                    mmi_applist_arrow_key_press_cyclic);
            }
            else
            {
                mmi_applist_auto_slide_with_key_cyclic();

                if (!mmi_applist_is_stop_type_set(MMI_APPLIST_WP_STOP_TYPE_SLIDE_BY_KEY))
                {
                    /* Stop wallpaper */
                    mmi_applist_stop_wallpaper(MMI_APPLIST_WP_STOP_TYPE_SLIDE_BY_KEY);   
                }
            }

            break;    
    }

    
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_left_arrow_key_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_left_arrow_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_APPLIST_KEY_SUPPORT__
    S32 curr_idx = mmi_applist_get_current_page_idx();
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (applist_p->state != MMI_APPLIST_STATE_NORMAL)
        return;
    
    #ifdef __MMI_APPLIST_KEY_SUPPORT__
    mmi_applist_arrow_key_press(MMI_APPLIST_DIR_LEFT);
    #else
    //reject key operation when sliding
    if (applist_p->state != MMI_APPLIST_STATE_NORMAL)
        return;
    
    if (curr_idx > 0)
    {
        applist_p->slide_type = MMI_APPLIST_SLIDE_BY_KEY;    
        mmi_applist_slide_to_page(curr_idx - 1);
        gui_cancel_timer(mmi_applist_update_anima_data);    
        mmi_applist_update_anima_data();
        
        applist_p->long_press_dir = MMI_APPLIST_DIR_LEFT;
        gui_start_timer(
            MMI_APPLIST_KEY_LONG_PRESS_DELAY_FIRST_TIME,
            mmi_applist_arrow_key_press_cyclic);
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_right_arrow_key_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_right_arrow_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_APPLIST_KEY_SUPPORT__
    S32 curr_idx = mmi_applist_get_current_page_idx();
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (applist_p->state != MMI_APPLIST_STATE_NORMAL)
        return;
    
    #ifdef __MMI_APPLIST_KEY_SUPPORT__
    mmi_applist_arrow_key_press(MMI_APPLIST_DIR_RIGHT);
    #else
    //reject key operation when sliding
    if (applist_p->state != MMI_APPLIST_STATE_NORMAL)
        return;
    
    if (curr_idx < mmi_applist_get_current_page_num() - 1)
    {
        applist_p->slide_type = MMI_APPLIST_SLIDE_BY_KEY;   
        mmi_applist_slide_to_page(curr_idx + 1);
        gui_cancel_timer(mmi_applist_update_anima_data);    
        mmi_applist_update_anima_data(); 
        
        applist_p->long_press_dir = MMI_APPLIST_DIR_RIGHT;
        gui_start_timer(
            MMI_APPLIST_KEY_LONG_PRESS_DELAY_FIRST_TIME,
            mmi_applist_arrow_key_press_cyclic);
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_up_arrow_key_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_arrow_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (applist_p->state == MMI_APPLIST_STATE_NONE)
        return;
    
    gui_cancel_timer(mmi_applist_arrow_key_press_cyclic);
    gui_cancel_timer(mmi_applist_auto_slide_with_key_cyclic);
    
    mmi_frm_clear_key_events();

    if (mmi_applist_is_stop_type_set(MMI_APPLIST_WP_STOP_TYPE_SLIDE_BY_KEY))
    {
        /* Delay start wallpaper */
        mmi_applist_delay_start_wallpaper(
            MMI_APPLIST_WP_STOP_TYPE_SLIDE_BY_KEY, 
            MMI_APPLIST_WALLPAPER_DELAY_TIME);   
    }      
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_back_key_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_back_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (applist_p->state != MMI_APPLIST_STATE_NORMAL)
        return;
    
    mmi_applist_exit_edit_mode();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_unregister_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_unregister_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ClearKeyHandler(KEY_BACK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_HOME, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
    
#ifdef __MMI_APPLIST_KEY_SUPPORT__    
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);    

    ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);

    ClearKeyHandler(KEY_CSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_CSK, KEY_EVENT_UP);    
#endif /* __MMI_APPLIST_KEY_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_register_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_register_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    SetKeyHandler(mmi_applist_back_key_press, KEY_BACK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_applist_back_key_press, KEY_HOME, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_applist_back_key_press, KEY_RSK, KEY_EVENT_DOWN);
    
    SetKeyHandler(mmi_applist_left_arrow_key_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_applist_right_arrow_key_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_applist_arrow_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_applist_arrow_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);  
    
#if defined(__MMI_TOUCH_SCREEN__)
    /* register pen down/up/move event */
    wgui_register_pen_down_handler(mmi_applist_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_applist_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_applist_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __MMI_APPLIST_KEY_SUPPORT__    
    SetKeyHandler(mmi_applist_up_arrow_key_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_applist_down_arrow_key_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    
    SetKeyHandler(mmi_applist_arrow_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_applist_arrow_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);  

    SetKeyHandler(mmi_applist_enter_key_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_applist_enter_key_release, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_applist_enter_key_press, KEY_CSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_applist_enter_key_release, KEY_CSK, KEY_EVENT_UP);    
#endif /* __MMI_APPLIST_KEY_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_applist_reset_focus_cell();
    
    applist_p->wp_state = MMI_APPLIST_WP_STATE_CLOSED;
    applist_p->wp_stop_type = MMI_APPLIST_WP_STOP_TYPE_NONE;
    if (applist_p->parent_gid == 0)
    {
        applist_p->state = MMI_APPLIST_STATE_FIRST_ENTER;

        applist_p->mainmenu_need_sync = MMI_TRUE;
    }
    else
    {
        applist_p->state = MMI_APPLIST_STATE_ENTER;
    }
    
    applist_p->slide_state = MMI_APPLIST_SLIDE_STATE_DISABLE;
    applist_p->slide_type = MMI_APPLIST_SLIDE_BY_KEY;
    applist_p->slide_region.anima_node_p = NULL;
    applist_p->empty_cache_index = MMI_APPLIST_INVALID_INDEX;
    
    #ifdef G2D_SUPPORT
    applist_p->shake_info.anima_node_p = NULL;
    applist_p->shake_info.angle = 0;
    #endif    
    
    #ifdef __MMI_APPLIST_KEY_LOOP__
    applist_p->is_loop = MMI_FALSE;
    #endif

    if (applist_p->state == MMI_APPLIST_STATE_FIRST_ENTER)
    {
        #if defined(__MMI_PHNSET_APPICON_SUPPORT__) || defined(__MMI_DOWNLOADABLE_APPICON_SUPPORT__)
        applist_p->is_cached = MMI_FALSE;
        applist_p->theme_changed = MMI_FALSE;
        #endif
    }

    #ifdef __MMI_FONT_EFFECTS__
    //add customize font shadow effect
    applist_p->font_attr = &gApplistAttributeNode;
    applist_p->font_attr->attribute_id =  addFontEffectAttributeNode(applist_p->font_attr);
    #endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_cancel_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_cancel_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_cancel_timer(mmi_applist_entry_edit_mode);
    gui_cancel_timer(mmi_applist_update_anima_data);
    gui_cancel_timer(mmi_applist_start_wallpaper);
#if defined(__MMI_TOUCH_SCREEN__)
    gui_cancel_timer(mmi_applist_reposition_cell);
    gui_cancel_timer(mmi_applist_auto_slide);
#endif    

    gui_cancel_timer(mmi_applist_arrow_key_press_cyclic);
    gui_cancel_timer(mmi_applist_auto_slide_with_key_cyclic);

#ifdef __MMI_APPLIST_BARREL_SUPPORT__
    gui_cancel_timer(mmi_applist_barrel_auto_slide_back);
#endif

    gui_cancel_timer(mmi_applist_quiet_cache);

#if defined(__MMI_APPLIST_KEY_SUPPORT__) && !defined(__MMI_APPLIST_ONLY_ICON_SUPPORT__)
    gui_cancel_timer(mmi_applist_scroll_cell_string);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_enter
 * DESCRIPTION
 *  functions to enter applist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_enter(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 page_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MOD_MMI_COMMON_APP, TRC_APPLIST_LAUNCH);
    
    ASSERT(applist_p->state == MMI_APPLIST_STATE_NONE);
    
    RANFOW_TRACE("[APPLIST]enter, slide x=%d, need sync=%d\n", applist_p->slide_region.x, applist_p->mainmenu_need_sync);

    /* Init parameter */
    mmi_applist_init();
    
    applist_p->parent_gid = group_id;      
    
    /* entry full screen app */
    entry_full_screen();

    if (applist_p->mode != MMI_APPLIST_MODE_POPUP)
    {
        /* Allocate pool & create ADM */
        mmi_applist_alloc_pool();
        mmi_applist_create_adm();
    }

    /* load data: need memory, put before allocate adm memory */
    if (applist_p->mainmenu_need_sync)
    {
        mmi_applist_load_data();    
        mmi_applist_save_data();
    }
    else
    {
        mmi_applist_load_data(); 
    }
    
    /* disalbe align timer  */
    UI_disable_alignment_timers();

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();
    
    mmi_applist_alloc_base_layer();

    mmi_applist_alloc_adm_structure();

    mmi_applist_alloc_adm_layer();

    mmi_applist_set_blt_layer();    

    mmi_applist_validate_slide_x();

    /* Init cell info */
    mmi_applist_init_cell_info();

    /* Init indicator */
    page_idx = mmi_applist_get_current_page_idx();
    mmi_applist_set_indicator_info(page_idx);
   
    /* Cache indicator */
    mmi_applist_draw_indicator_in_cache();

    #ifdef __MMI_APPLIST_KEY_SUPPORT__
    /* Cache highlight frame */    
    mmi_applist_draw_highlight_frame_in_cache();
    #endif
    
    /* Cache app download icon */
    mmi_applist_draw_app_download_icon_in_cache();

    /* Cache slide area icon */    
    mmi_applist_quiet_cache();

    /* Cache shortcut bar */
    mmi_applist_cache_bar_cell();
    
    /* Hilight frame */
    #ifdef __MMI_APPLIST_KEY_SUPPORT__ 
    mmi_applist_init_hilight_frame(page_idx);  
    #endif

    /* Draw panel */
    mmi_applist_draw_panel();

    /* Blt panel first */
    mmi_applist_blt_previous();

    /* Wallpaper */
    mmi_applist_open_wallpaper();
    mmi_applist_delay_start_wallpaper(
        MMI_APPLIST_WP_STOP_TYPE_NONE, MMI_APPLIST_WALLPAPER_DELAY_TIME);
     
    /* Status bar */
    wgui_status_icon_bar_update();

    #if defined(__MMI_PHNSET_APPICON_SUPPORT__) || defined(__MMI_DOWNLOADABLE_APPICON_SUPPORT__)
    if (applist_p->theme_changed == MMI_TRUE)
    {
        mmi_phnset_appicon_complete_active(applist_p->is_cached);
        applist_p->theme_changed = MMI_FALSE;
    }
    #endif
    
    applist_p->state = MMI_APPLIST_STATE_NORMAL;

    mmi_applist_init_cell_info();
    
#ifdef __MMI_APPLIST_BARREL_SUPPORT__
    mmi_applist_barrel_load_type();
#endif
        
    /* Reset queue */
    mmi_applist_reset_anima_queue();
    
#ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
    mmi_applist_draw_app_uninstall_icon_in_cache();
#endif
        
#ifdef __MMI_APPLIST_EDIT_WITH_BG__
    /* Cache icon bg */
    mmi_applist_draw_icon_bg_in_cache();
#endif
    
    /* Register handler */
    mmi_applist_register_event_handler();

    applist_p->mode = MMI_APPLIST_MODE_NORMAL;
    applist_p->mainmenu_need_sync = MMI_FALSE;

    RANFOW_TRACE("[APPLIST]enter end\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_exit
 * DESCRIPTION
 *  functions to exit applist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 page_idx = mmi_applist_get_final_page_idx();
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RANFOW_TRACE("[APPLIST]mmi_applist_exit[mode=%d]\n", applist_p->mode);
    mmi_applist_unregister_event_handler();
    mmi_applist_exit_edit_mode();

    /* Wallpaper */
    mmi_applist_close_wallpaper();   

    mmi_applist_cancel_timer();    

    //restore animation
    applist_p->slide_region.x = page_idx * MMI_APPLIST_PAGE_WIDTH_INC_MARGIN;
    #ifdef __MMI_APPLIST_KEY_SUPPORT__
    mmi_applist_init_hilight_index_in_page();
    #endif
    mmi_applist_draw_panel();
    mmi_applist_blt_previous();
    
    /* free base layer */
    mmi_applist_free_base_layer();
    
    gdi_layer_flatten_previous_to_base();
    
    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* enable multi-layer */
    gdi_layer_multi_layer_disable();

    leave_full_screen();    

    /* release ADM */
    mmi_applist_free_adm_structure();    

    mmi_applist_free_adm_layer();

    if (applist_p->mode != MMI_APPLIST_MODE_POPUP)
    {//do not free asm to keep cell info to improve performance
        /* Free pool & delete ADM */
        mmi_applist_free_pool();
        mmi_applist_delete_adm();
    }
    else
    {//reset cell cache in cell info
        for (i = 0; i < MMI_APPLIST_BAR_APP_NUM; i++)
        {
            if (applist_p->bar_cell[i] != NULL)
            {
                applist_p->bar_cell[i]->cache_idx = MMI_APPLIST_INVALID_INDEX;
                applist_p->bar_cell[i]->opacity = 255;
            }
        }
        for (i = 0; i < MMI_APPLIST_PANEL_APP_NUM; i++)
        {
            if (applist_p->panel_cell[i] != NULL)
            {
                applist_p->panel_cell[i]->cache_idx = MMI_APPLIST_INVALID_INDEX;
                applist_p->panel_cell[i]->opacity = 255;
            }
        }
    }

    #if defined(__MMI_PHNSET_APPICON_SUPPORT__) || defined(__MMI_DOWNLOADABLE_APPICON_SUPPORT__)
    mmi_res_theme_cache_detach_asm();
    #endif

    #ifdef __MMI_APPLIST_KEY_SUPPORT__
    if (applist_p->hilight_frame.hilight_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(applist_p->hilight_frame.hilight_handle);
        applist_p->hilight_frame.hilight_handle = GDI_LAYER_EMPTY_HANDLE;
    }
    #endif
    
    if (applist_p->download_icon_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(applist_p->download_icon_handle);
        applist_p->download_icon_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    #ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
    if (applist_p->uninstall_icon_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(applist_p->uninstall_icon_handle);
        applist_p->uninstall_icon_handle = GDI_LAYER_EMPTY_HANDLE;
    }
    #endif

    #ifdef __MMI_APPLIST_EDIT_WITH_BG__
    if (applist_p->icon_bg_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(applist_p->icon_bg_handle);
        applist_p->icon_bg_handle = GDI_LAYER_EMPTY_HANDLE;
    }
    #endif
    
    applist_p->state = MMI_APPLIST_STATE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_launch_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_applist_launch_cell(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 app_id;
    mmi_app_package_name_struct pac_name = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    ASSERT(evt);
    
    app_id = ((mmi_applist_launch_event_struct *)evt)->app_id;

    if (app_id == 0)
        return MMI_RET_OK;
    
    srv_appmgr_get_app_package_name_by_id(app_id, pac_name);

    #ifdef __MMI_APPLIST_BARREL_SUPPORT__
    if (strcmp(pac_name, "native.mtk.barrel") != 0)
    #endif
    {
        mmi_applist_exit();
    }   

    srv_appmgr_launch(pac_name);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_refresh
 * DESCRIPTION
 *  functions to refresh applist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
void mmi_applist_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (applist_p->parent_gid != 0 && mmi_frm_group_is_in_active_serial(applist_p->parent_gid))
    {
        RANFOW_TRACE("[APPLIST]mmi_applist_refresh");
        mmi_frm_display_dummy_screen();
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_is_existed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_is_existed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return (applist_p->state == MMI_APPLIST_STATE_NONE ? MMI_FALSE : MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_is_in_edit_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_is_in_edit_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return (applist_p->mode == MMI_APPLIST_MODE_EDIT ? MMI_TRUE : MMI_FALSE);
}

#endif /* __MMI_LAUNCHER_APP_LIST__ */

