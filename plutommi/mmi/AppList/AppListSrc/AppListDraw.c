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
 *  AppListDraw.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AppList Draw
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
#include "AppListDraw.h"
#include "AppMgrSrvGprot.h"
#include "IdleMemCfg.h"
#include "mmi_rp_app_applist_def.h"
#include "gdi_linear_transform.h"
#include "gdi_2d_engine.h"


#include "iul_x_math.h"     /* For sine table */
#ifdef __MMI_APPLIST_BARREL_SUPPORT__
#include "AppListBarrel.h"
#endif


#ifdef __MTK_TARGET__
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

/*
SWLA labels:
DCI -- Draw Cell In Cache
DC  -- Draw Cell
CLT -- Cell Linear Transform
DI  -- Draw Indicator
DSB      -- Draw Shortcut Bar
DSA     -- Draw Slide Area Icon
DP        -- Draw Panel
CS -- Cache Barcell
CP -- Cache Page
*/
    

/*****************************************************************************
* Function declare
 *****************************************************************************/
static void mmi_applist_get_cell_transform(        
        mmi_applist_cell_struct *cell,
        mmi_applist_cell_type_enum cell_type,
        gdi_lt_matrix_struct *transform,
        U8 *opacity);
static void mmi_applist_draw_cell(
        mmi_applist_cell_struct *cell, 
        mmi_applist_draw_info_struct *draw_info);
static void mmi_applist_find_empty_cache_idx(void);
static MMI_BOOL mmi_applist_output_in_range(
    gdi_lt_matrix_struct *matrix,
    S32 in_width, S32 in_height);
#ifdef __MMI_APPLIST_KEY_SUPPORT__
static void mmi_applist_draw_hilight_frame(mmi_applist_rect *rect, gdi_lt_matrix_struct *transform);
#endif
static void mmi_applist_cache_slide_area_icon(S32 *idx_from, S32 *idx_to);

#ifdef __MMI_APPLIST_CACHE_PATH_APP_ICON__
#define MMI_APPLIST_APP_ICON_CACHE_COUNT 64
#define MMI_APPLIST_APP_ICON_CACHE_POOL_SIZE (100 * 1024)
static U32 s_applist_app_icon_cache_app_ids[MMI_APPLIST_APP_ICON_CACHE_COUNT];
static KAL_ADM_ID s_applist_app_icon_cache_pool_adm_id;
static U8 s_applist_app_icon_cache_pool[MMI_APPLIST_APP_ICON_CACHE_POOL_SIZE];
static U8 *s_applist_app_icon_cache_datas[MMI_APPLIST_APP_ICON_CACHE_COUNT];


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_create_app_icon_cache_adm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_create_app_icon_cache_adm()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s_applist_app_icon_cache_pool_adm_id = kal_adm_create(s_applist_app_icon_cache_pool,
													 MMI_APPLIST_APP_ICON_CACHE_POOL_SIZE,
													 NULL,
													 KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_delete_app_icon_cache_adm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_delete_app_icon_cache_adm()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    s_applist_app_icon_cache_pool_adm_id = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_app_icon_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_applist_get_app_icon_info(S32 index, U32 app_id, S32 cache_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_app_info_struct info;
    mmi_ret result;
	U8 type = 0;
    #ifndef __MMI_APPLIST_CACHE_APP_NAME__
    mmi_app_package_name_struct pac_name = {0};
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_APPLIST_CACHE_APP_NAME__    
    result = srv_appmgr_get_app_package_info(applist_p->app_name[index], &info);
    #else
    srv_appmgr_get_app_package_name_by_id(app_id, pac_name);
    result = srv_appmgr_get_app_package_info(pac_name, &info);
    #endif
    
    ASSERT(result != MMI_RET_ERR);
    
    if (info.image.type == MMI_IMAGE_SRC_TYPE_PATH)
    {
        FS_HANDLE file_handle;
        UINT file_size, read_size;
        S32 icon_width, icon_height;
        
        s_applist_app_icon_cache_app_ids[cache_idx] = app_id;
        
        file_handle = FS_Open ((const WCHAR *)info.image.data.path, FS_READ_ONLY);        
        FS_GetFileSize(file_handle, &file_size);
        gdi_image_get_dimension_file((S8*)info.image.data.path, &icon_width, &icon_height);
        
        s_applist_app_icon_cache_datas[cache_idx] = (U8 *)kal_adm_alloc(s_applist_app_icon_cache_pool_adm_id, file_size + 8);
        type = gdi_image_get_type_from_file((S8*)info.image.data.path);
		if (s_applist_app_icon_cache_datas[cache_idx] == NULL || type == GDI_IMAGE_TYPE_DEVICE_BMP_FILE)
        {
            kal_adm_free(s_applist_app_icon_cache_pool_adm_id, s_applist_app_icon_cache_datas[cache_idx]);
        	FS_Close(file_handle);
            return MMI_FALSE;
        }

        FS_Read(file_handle, s_applist_app_icon_cache_datas[cache_idx] + 8, file_size, &read_size);
		if(type == GDI_IMAGE_TYPE_AB2_FILE)
		{
			type = GDI_IMAGE_TYPE_AB2;  // map for mre pre shortcut abm2 files.
		}
		else
		{
			type = (U8)gdi_image_get_type_from_mem((PS8)(s_applist_app_icon_cache_datas[cache_idx] + 8));
		}

		s_applist_app_icon_cache_datas[cache_idx][0] = type;
        s_applist_app_icon_cache_datas[cache_idx][1] = 1;
        s_applist_app_icon_cache_datas[cache_idx][2] = file_size & 0xff;
        s_applist_app_icon_cache_datas[cache_idx][3] = (file_size >> 8) & 0xff;
        s_applist_app_icon_cache_datas[cache_idx][4] = (file_size >> 16) & 0xff;
        s_applist_app_icon_cache_datas[cache_idx][5] = icon_height & 0xff;
        s_applist_app_icon_cache_datas[cache_idx][6] = ((icon_height & 0xf00) >> 8) + ((icon_width & 0xf) << 4);
        s_applist_app_icon_cache_datas[cache_idx][7] = (icon_width >> 4) & 0xff;
        
        FS_Close(file_handle);
        
        //RANFOW_TRACE("[APPLIST]cache app=%d icon data\n", app_id);
        
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_app_icon_data_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/    
MMI_BOOL mmi_applist_get_app_icon_data_cache(U32 app_id, U8 **image_mem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for (i = 0; i < MMI_APPLIST_APP_ICON_CACHE_COUNT; ++i)
    {
        if (s_applist_app_icon_cache_app_ids[i] == 0)
        {
            return MMI_FALSE;
        }
        
        if (s_applist_app_icon_cache_app_ids[i] == app_id)
        {
            break;
        }
    }
    
    if (i == MMI_APPLIST_APP_ICON_CACHE_COUNT)
    {
        return MMI_FALSE;
    }

    *image_mem = s_applist_app_icon_cache_datas[i];
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_update_app_icon_data_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_update_app_icon_data_cache()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, cache_idx = 0;
    MMI_BOOL is_cached;
    U32 j;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*// free old cache
    for (i = 0; i < MMI_APPLIST_APP_ICON_CACHE_COUNT; ++i)
    {
        if (s_applist_app_icon_cache_datas[i])
        {
            kal_adm_free(s_applist_app_icon_cache_pool_adm_id, s_applist_app_icon_cache_datas[i]);
            s_applist_app_icon_cache_datas[i] = NULL;
        }
    }*/

    /* cache bar item */
    for (j = 0; j < MMI_APPLIST_BAR_APP_NUM; ++j)
    {
        if (applist_p->data.bar_id[j] == 0)
            continue;
        
        is_cached = mmi_applist_get_app_icon_info(j, applist_p->data.bar_id[j], cache_idx);
        if (is_cached)
        {
            ++cache_idx;
        }
    }
    
    /* cache panel item */
    for (j = 0; j < MMI_APPLIST_PANEL_APP_NUM; ++j)
    {
        if (applist_p->data.panel_id[j] == 0)
            continue;
        
        is_cached = mmi_applist_get_app_icon_info(MMI_APPLIST_BAR_APP_NUM+j, applist_p->data.panel_id[j], cache_idx);
        if (is_cached)
        {
            ++cache_idx;
        }
    }

    for (; cache_idx < MMI_APPLIST_APP_ICON_CACHE_COUNT; ++cache_idx)
    {
        s_applist_app_icon_cache_app_ids[cache_idx] = 0;
    }
}
#endif  //__MMI_APPLIST_CACHE_PATH_APP_ICON__


/*****************************************************************************
* Function definition
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_sin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
float mmi_applist_sin(float rad)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return APPLIST_X_TO_F(iul_x_sin_rad(APPLIST_F_TO_X(rad)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_cos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
float mmi_applist_cos(float rad)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return APPLIST_X_TO_F(iul_x_cos_rad(APPLIST_F_TO_X(rad)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_reset_anima_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_reset_anima_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_mem_set(
        applist_p->anima_node_pool, 
        0, 
        sizeof(mmi_applist_anima_node_struct) * MMI_APPLIST_APP_ANIMA_NODE_NUM);

    /* Reset used anima queue */
    applist_p->used_anima_tail = NULL;  
    applist_p->empty_anima_index = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_anima_queue_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_get_anima_queue_len(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_anima_node_struct *node, *head, *tail;
    S32 count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    tail = applist_p->used_anima_tail;
    if (tail == NULL)
    {
        return 0;
    }

    head = applist_p->used_anima_tail->next;

    count = 1;
    node = head;
    while (node->next != head)
    {
        node = node->next;
        count ++;
    }
    
    return count;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_assign_target_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_assign_target_value(
        U32 cur_time, mmi_applist_anima_node_struct *node, S32 page_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 elapse;
    float factor, diff, tmp_rotate;
   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cur_time < node->start_time)
    {
        elapse = 0xFFFFFFFF - node->start_time + cur_time;
    }
    else
    {
        elapse = cur_time - node->start_time;
    }
    factor = (float)elapse / node->duration;
    if (factor > 1.0f)
    {
        factor = 1.0f;
    }
    
    switch (node->type)
    {
        case MMI_APPLIST_ANIMA_TYPE_POSITION_X:
            diff = (float)(node->to.pos_x - node->from.pos_x);
            *(node->target.pos_x) = (S32)(node->from.pos_x + factor * diff);

            /*if (node == applist_p->slide_region.anima_node_p) 
            {
                //to decrease the call rate, select some to call
                if ((elapse < node->duration && elapse % 10 == 0) || elapse == node->duration)
                {
                    applist_p->wp_config.on_page_change(
                        *(node->target.pos_x), page_num, MMI_APPLIST_PAGE_WIDTH_INC_MARGIN, MMI_APPLIST_INTER_PAGE_MARGIN);
                }
            }*/
            break;
            
        case MMI_APPLIST_ANIMA_TYPE_POSITION: 
            diff = (float)(node->to.pos.x - node->from.pos.x);
            node->target.pos->x = (S32)(node->from.pos.x + factor * diff);

            diff = (float)(node->to.pos.y - node->from.pos.y);
            node->target.pos->y = (S32)(node->from.pos.y + factor * diff);
            break;
            
        case MMI_APPLIST_ANIMA_TYPE_OPACITY:
            diff =  (float)(node->to.opacity - node->from.opacity);
            *(node->target.opacity) = (U8)(node->from.opacity + factor * diff);
            break;

        case MMI_APPLIST_ANIMA_TYPE_RESIZE: 
            diff = node->to.resize - node->from.resize;
            *(node->target.resize) = node->from.resize + factor * diff;
            break;
            
        case MMI_APPLIST_ANIMA_TYPE_ROTATE:            
            diff = node->to.rotate - node->from.rotate;
            *(node->target.rotate) = node->from.rotate + factor * diff;

            /* Assume auto_reverse & infinite */
            if (factor == 1.0f)
            {
                node->start_time = cur_time;
                tmp_rotate = node->from.rotate;
                node->from.rotate = node->to.rotate;
                node->to.rotate = tmp_rotate;
            }
            break;
        default:
            ASSERT(0);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_remove_unused_anima_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_remove_unused_anima_node(U32 cur_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_anima_node_struct *node, *head, *prev_node;    
    S32 count;
    MMI_BOOL invisible_animation = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = mmi_applist_get_anima_queue_len();
    
    prev_node = applist_p->used_anima_tail;
    node = head = prev_node->next;
    ASSERT(prev_node != NULL && head != NULL);
    while(count > 0)
    {
        if (node->type == MMI_APPLIST_ANIMA_TYPE_POSITION_X || node->type == MMI_APPLIST_ANIMA_TYPE_POSITION)
        {
            if ((node->target.pos->x < applist_p->slide_region.x && node->to.pos.x < applist_p->slide_region.x) || 
                (node->target.pos->x > applist_p->slide_region.x + LCD_WIDTH && node->to.pos.x > applist_p->slide_region.x + LCD_WIDTH) || 
                (node->target.pos->y < 0 && node->to.pos.y < 0) || (node->target.pos->y > LCD_HEIGHT && node->to.pos.y > LCD_HEIGHT))
            {
                node->target.pos->x = node->to.pos.x;
                node->target.pos->y = node->to.pos.y;
                invisible_animation = MMI_TRUE;
            }
        }
        
        if (node->start_time + node->duration <= cur_time || invisible_animation)
        {
            if (node == applist_p->slide_region.anima_node_p)
            {
                applist_p->slide_region.anima_node_p = NULL;
            }
            
            /* Left one node */
            if (node == node->next)
            {
                node->next = NULL;
                prev_node = NULL;
                break;
            }
            prev_node->next = node->next;
            node->next = NULL;
            if (node == head)
            {
                head = prev_node->next;
            } 
            node = prev_node->next;
        }
        else
        {
            prev_node = node;
            node = node->next;
        }
        
        invisible_animation = MMI_FALSE;
        count --;
    }
    applist_p->used_anima_tail = prev_node;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_update_anima_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_update_anima_data(void)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_anima_node_struct *node, *head, *tail;
    U32 cur_time, page_num, total_length;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->state == MMI_APPLIST_STATE_NONE)
        return;
    
    /* Queue is empty */
    tail = applist_p->used_anima_tail;
    if (tail == NULL)
    {
        /* Draw panel */
        mmi_applist_draw_panel();
        
        mmi_applist_blt_previous();
        return;
    }
    
    cur_time = mmi_applist_get_cur_time();

    /* For wallpaper */
    page_num = mmi_applist_get_current_page_num();
    total_length = page_num * MMI_APPLIST_PAGE_WIDTH_INC_MARGIN - 
        MMI_APPLIST_INTER_PAGE_MARGIN;
    
    /* Assign target value */
    head = applist_p->used_anima_tail->next;
    node = head;
    while(1)
    {
        mmi_applist_assign_target_value(cur_time, node, page_num);
        
        if (node->next == head)
        {
            break;
        }            
        node = node->next;        
    } 

    /* Remove timeout node */
    mmi_applist_remove_unused_anima_node(cur_time);     
    
    /* start timer */
    len = mmi_applist_get_anima_queue_len();
    if (len > 0)
    {
        gui_start_timer(
            MMI_APPLIST_UPDATE_ANIMA_QUEUE_DELAY,
            mmi_applist_update_anima_data);
    }
    
    /* Draw panel */
    mmi_applist_draw_panel();
    
    mmi_applist_blt_previous();
    
    //not sliding, reset state to normal
    if (applist_p->slide_region.anima_node_p == NULL)
    {        
        applist_p->state = MMI_APPLIST_STATE_NORMAL;
        #ifdef __MMI_APPLIST_KEY_LOOP__
        applist_p->is_loop = MMI_FALSE;
        #endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_empty_anima_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_applist_anima_node_struct *mmi_applist_get_empty_anima_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, end;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(applist_p->empty_anima_index != MMI_APPLIST_INVALID_INDEX);

    /* Search backward */
    for (i = applist_p->empty_anima_index; i < MMI_APPLIST_APP_ANIMA_NODE_NUM; i ++)
    {
        if (!applist_p->anima_node_pool[i].next)
        {
            applist_p->empty_anima_index = i;
            break;
        }
    }
    
    /* found */
    if (i < MMI_APPLIST_APP_ANIMA_NODE_NUM)
    {
        memset(&applist_p->anima_node_pool[i], 0, sizeof(mmi_applist_anima_node_struct));
        return &applist_p->anima_node_pool[i];
    }

    /* Search from beginning */
    end = applist_p->empty_anima_index;
    for (i = 0; i < end; i ++)
    {
        if (!applist_p->anima_node_pool[i].next)
        {
            applist_p->empty_anima_index = i;
            break;
        }
    }
    
    /* found */
    if (i < end)
    {
        memset(&applist_p->anima_node_pool[i], 0, sizeof(mmi_applist_anima_node_struct));
        return &applist_p->anima_node_pool[i];
    } 

    /* Not found: enlarge array size */
    applist_p->empty_anima_index = MMI_APPLIST_INVALID_INDEX;
    ASSERT(0);
    return NULL;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_applist_add_to_used_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_add_to_used_queue(mmi_applist_anima_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_anima_node_struct *head, *tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tail = applist_p->used_anima_tail;
    if (tail == NULL)
    {
        applist_p->used_anima_tail = node;
        node->next = node;
    }
    else
    {
        head = applist_p->used_anima_tail->next;
        tail->next = node;
        node->next = head;
        applist_p->used_anima_tail = node;        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_remove_from_used_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_remove_from_used_queue(mmi_applist_anima_node_struct *remove_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_anima_node_struct *node, *head, *tail, *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    tail = applist_p->used_anima_tail;
    ASSERT(tail != NULL);

    head = tail->next;
    node = head;
    prev = tail;
    while (node != remove_node)
    {
        prev = node;
        node = node->next;
        if (node == head)
        {
            break;
        }
    }

    /* Must found */
    ASSERT(node == remove_node);

    /* Left one */    
    if (node->next == node)
    {
        applist_p->used_anima_tail = NULL;
        node->next = NULL;
    }
    else
    {
        if (node == tail)
        {
            applist_p->used_anima_tail = prev;
        }
        prev->next = node->next;
        node->next = NULL;
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_change_slide_x_anima
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_change_slide_x_anima(S32 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_anima_node_struct *slide_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!applist_p->slide_region.anima_node_p)
    {
         slide_node = mmi_applist_get_empty_anima_node();
         mmi_applist_add_to_used_queue(slide_node);  

         applist_p->slide_region.anima_node_p = slide_node;
    }
    else
    {
        slide_node = applist_p->slide_region.anima_node_p;
    }

    slide_node->type = MMI_APPLIST_ANIMA_TYPE_POSITION_X;
    slide_node->from.pos_x = applist_p->slide_region.x;
    slide_node->to.pos_x = x;
    slide_node->target.pos_x = &applist_p->slide_region.x;
    if (applist_p->slide_type == MMI_APPLIST_SLIDE_BY_KEY)
        slide_node->duration = MMI_APPLIST_PAGE_SLIDE_BY_KEY_DURATION;
    else
        slide_node->duration = MMI_APPLIST_PAGE_SLIDE_DURATION;
    slide_node->start_time = mmi_applist_get_cur_time();       
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_change_pos_anima
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_change_pos_anima(
        mmi_applist_position *target_pos, 
        mmi_applist_position *new_pos, 
        U32 cur_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_anima_node_struct *anima_node;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //avoid invisible animation
    if ((target_pos->x < applist_p->slide_region.x && new_pos->x < applist_p->slide_region.x) || 
        (target_pos->x > applist_p->slide_region.x + LCD_WIDTH && new_pos->x > applist_p->slide_region.x + LCD_WIDTH) || 
        (target_pos->y < 0 && new_pos->y < 0) || (target_pos->y > LCD_HEIGHT && new_pos->y > LCD_HEIGHT))
    {
        target_pos->x = new_pos->x;
        target_pos->y = new_pos->y;
        return;
    }
    
    anima_node = mmi_applist_get_empty_anima_node();
    mmi_applist_add_to_used_queue(anima_node);  
    
    anima_node->type = MMI_APPLIST_ANIMA_TYPE_POSITION;
    anima_node->from.pos = *target_pos;
    anima_node->to.pos = *new_pos;
    anima_node->target.pos = target_pos;
    anima_node->duration = MMI_APPLIST_MOVE_POSITION_DURATION;
    anima_node->start_time = cur_time;       
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_change_cell_resize_anima
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_change_cell_resize_anima(
        mmi_applist_cell_struct *cell_p, 
        float new_resize, 
        U32 cur_time)
{
 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_anima_node_struct *anima_node;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    anima_node = mmi_applist_get_empty_anima_node();
    mmi_applist_add_to_used_queue(anima_node);  
    
    anima_node->type = MMI_APPLIST_ANIMA_TYPE_RESIZE;
    anima_node->from.resize = cell_p->resize;
    anima_node->to.resize = new_resize;
    anima_node->target.resize = &cell_p->resize;
    anima_node->duration = MMI_APPLIST_AUTO_ANIMA_DURATION;
    anima_node->start_time = cur_time; 
 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_cache_buf_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  S32 cache_index
 * RETURNS
 *  U8*
 *****************************************************************************/
static U8* mmi_applist_get_cache_buf_ptr(S32 cache_index)
{
    #ifdef __MMI_APPLIST_SMART_ASM__
    if (!applist_p->can_cache_cell)
    {
        return applist_p->base_layer_buf_ptr + MMI_APPLIST_APP_CACHE_SIZE * cache_index;
    }
    else
    #endif
    {
        if (cache_index < (MMI_APPLIST_APP_CACHE_NUM - MMI_APPLIST_BASE_LAYER_CAN_CACHE_APP_NUM))
        {
            return applist_p->cache_pool[cache_index].buffer;
        }
        else
        {
            return applist_p->base_layer_buf_ptr + MMI_APPLIST_APP_CACHE_SIZE * (cache_index + MMI_APPLIST_BASE_LAYER_CAN_CACHE_APP_NUM - MMI_APPLIST_APP_CACHE_NUM);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_resized_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_draw_resized_image(mmi_applist_cell_struct *cell, S32 start_x, S32 start_y, S32 org_w, S32 org_h, S32 dst_w, S32 dst_h, 
    U16 raw_data_img_type, U8* image_mem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_w, icon_h, shift_x, shift_y;
    #ifdef __MMI_APPLIST_SMART_ICON_SCALE__
    gdi_lt_matrix_struct move_matrix, resize_matrix, transform_matrix;
    S32 tmp_layer_size;
    PU8 tmp_layer_buf_ptr = NULL;
    gdi_handle tmp_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    MMI_BOOL can_smart_scale = MMI_FALSE;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon_w = dst_w;
    icon_h = dst_h;
    shift_x = start_x;
    shift_y = start_y;
    #ifdef __MMI_APPLIST_SMART_ICON_SCALE__
    if ((dst_w > org_w || dst_h > org_h) && cell->image_type == MMI_IMAGE_SRC_TYPE_PATH)
    {
        tmp_layer_size = org_w * org_h * 3;
        mmi_applist_find_empty_cache_idx();
        ASSERT(applist_p->empty_cache_index != MMI_APPLIST_INVALID_INDEX);
        tmp_layer_buf_ptr = mmi_applist_get_cache_buf_ptr(applist_p->empty_cache_index);
        memset(tmp_layer_buf_ptr, 0, MMI_APPLIST_APP_CACHE_SIZE);
        if (tmp_layer_buf_ptr != NULL)
        {
            gdi_layer_create_cf_using_outside_memory(
                #ifdef __MMI_FTE_SUPPORT__
                GDI_COLOR_FORMAT_PARGB6666,
                #else  //__MMI_FTE_SUPPORT__
                GDI_COLOR_FORMAT_32_PARGB,
                #endif  //__MMI_FTE_SUPPORT__
                0,
                0,
                org_w,
                org_h,
                &tmp_layer_handle,
                tmp_layer_buf_ptr,
                tmp_layer_size);

            gdi_layer_push_and_set_active(tmp_layer_handle);
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            shift_x = shift_y = 0;
            icon_w = org_w;
            icon_h = org_h;
            can_smart_scale = MMI_TRUE;
        }
    }
    #endif  //__MMI_APPLIST_SMART_ICON_SCALE__

    /* Image buffer */
    if (cell->image_type == MMI_IMAGE_SRC_TYPE_ROM_MEMORY && cell->image_ptr != NULL)
    {
        if (raw_data_img_type != GDI_IMAGE_TYPE_INVALID)
        {//raw data without 8 bits head
            gdi_image_draw_resized_mem(
                shift_x, shift_y, icon_w, icon_h, cell->image_ptr, raw_data_img_type, cell->image_len);
        }
        else
        {//raw data with 8 bits head
            gdi_image_draw_resized(
                shift_x, shift_y, icon_w, icon_h, cell->image_ptr);
        }
    }
    /* Image ID */
    else if (cell->image_type == MMI_IMAGE_SRC_TYPE_RES_ID && cell->image.res_id != 0)
    {        
        gdi_image_draw_resized_id(
            shift_x, shift_y, icon_w, icon_h, cell->image.res_id);
    }
    /* Image path */
    else if (cell->image_type == MMI_IMAGE_SRC_TYPE_PATH && mmi_ucs2strlen((CHAR *)cell->image.path) != 0)
    {
        #ifdef __MMI_APPLIST_CACHE_PATH_APP_ICON__
        if (image_mem != NULL)
        {
            gdi_image_draw_resized(
                shift_x, shift_y, icon_w, icon_h, image_mem);
        }
        else
        #endif
        {
            gdi_image_draw_resized_file(
                shift_x, shift_y, icon_w, icon_h, (S8*)cell->image.path);
        }
    }
    else
    {
        ASSERT(0);
    }

    #ifdef __MMI_APPLIST_SMART_ICON_SCALE__
    if (can_smart_scale)
    {
        gdi_layer_pop_and_restore_active();
        
        mmi_applist_get_matrix(
            MMI_APPLIST_MATRIX_TYPE_MOVE,
            start_x,
            start_y,
            &move_matrix);
        mmi_applist_get_matrix(
            MMI_APPLIST_MATRIX_TYPE_SCALE,
            (float)((float)dst_w/(float)org_w),
            (float)((float)dst_h/(float)org_h),
            &resize_matrix);
        mmi_applist_matrix_multiply(move_matrix.m, resize_matrix.m, transform_matrix.m);

        gdi_2d_linear_transfrom(
            transform_matrix.m,
            tmp_layer_handle,
            0,
            0,
            org_w,
            org_h,
            start_x,
            start_y,
            dst_w,
            dst_h,      
            GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
            GDI_COLOR_TRANSPARENT,
            GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,
            0);

        gdi_layer_free(tmp_layer_handle);
    }
    #endif
}


#ifdef __MMI_APPLIST_EDIT_WITH_BG__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_icon_bg_in_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_icon_bg_in_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_w, icon_h, shift_x, shift_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->icon_bg_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        mmi_applist_find_empty_cache_idx();
        ASSERT(applist_p->empty_cache_index != MMI_APPLIST_INVALID_INDEX);
        ASSERT(applist_p->empty_cache_index >= 0 &&
           applist_p->empty_cache_index < MMI_APPLIST_APP_CACHE_NUM);

        applist_p->cache_used[applist_p->empty_cache_index] = MMI_TRUE;

        /* Create layer handle */
        gdi_layer_create_cf_using_outside_memory(
            #ifdef __MMI_FTE_SUPPORT__
            GDI_COLOR_FORMAT_PARGB6666,
            #else  //__MMI_FTE_SUPPORT__
            GDI_COLOR_FORMAT_32_PARGB,
            #endif  //__MMI_FTE_SUPPORT__
            0,
            0,
            MMI_APPLIST_CELL_WIDTH,
            MMI_APPLIST_CELL_HEIGHT,
            &applist_p->icon_bg_handle,
            mmi_applist_get_cache_buf_ptr(applist_p->empty_cache_index),
            MMI_APPLIST_APP_CACHE_SIZE); 
     
        gdi_layer_push_and_set_active(applist_p->icon_bg_handle);    
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        
        gdi_image_get_dimension_id(IMG_ID_APPLIST_ICON_BG, &icon_w, &icon_h);
        shift_x = ((MMI_APPLIST_CELL_WIDTH - icon_w) >> 1);
        #ifdef __MMI_APPLIST_ONLY_ICON_SUPPORT__ 
        shift_y = ((MMI_APPLIST_CELL_HEIGHT - icon_h) >> 1);
        #else /* __MMI_APPLIST_ONLY_ICON_SUPPORT__ */
        shift_y = ((MMI_APPLIST_CELL_STRING_Y - icon_h) >> 1);
        #endif /* __MMI_APPLIST_ONLY_ICON_SUPPORT__ */

        /* draw image */       
        gdi_image_draw_id(shift_x, shift_y, IMG_ID_APPLIST_ICON_BG);

        gdi_layer_pop_and_restore_active();
    }
}

#else //__MMI_APPLIST_EDIT_WITH_BG__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_add_shake_anima
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_add_shake_anima(U32 cur_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_anima_node_struct *anima_node;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(applist_p->shake_info.anima_node_p == NULL);
    anima_node = mmi_applist_get_empty_anima_node();
    mmi_applist_add_to_used_queue(anima_node); 
    applist_p->shake_info.anima_node_p = anima_node;
    
    anima_node->type = MMI_APPLIST_ANIMA_TYPE_ROTATE;
    anima_node->from.rotate = -MMI_APPLIST_CELL_SHAKE_ROTATE_ANGLE;
    anima_node->to.rotate = MMI_APPLIST_CELL_SHAKE_ROTATE_ANGLE;
    anima_node->target.rotate = &applist_p->shake_info.angle;
    anima_node->duration = MMI_APPLIST_CELL_SHAKE_DURATION;
    anima_node->start_time = cur_time;       
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_remove_shake_anima
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_remove_shake_anima(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (applist_p->shake_info.anima_node_p)
    {
        /* Reset angle */
        applist_p->shake_info.angle = 0.0f;
        
        mmi_applist_remove_from_used_queue(applist_p->shake_info.anima_node_p);
        applist_p->shake_info.anima_node_p = NULL;      
    }    
}
#endif  //__MMI_APPLIST_EDIT_WITH_BG__


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_remove_slide_x_anima
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_remove_slide_x_anima(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (applist_p->slide_region.anima_node_p)
    {
        mmi_applist_remove_from_used_queue(applist_p->slide_region.anima_node_p);
        applist_p->slide_region.anima_node_p = NULL;
    }    
}


#ifndef __MMI_APPLIST_ONLY_ICON_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_cell_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_applist_draw_cell_string(UI_string_type cell_name, MMI_BOOL scrolling, S32 start_x, S32 start_y)
{ 

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 name_w, name_h;
    stFontAttribute font = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //RANFOW_TRACE("[APPLIST]mmi_applist_draw_cell_string start\n");

    font.type = 1;
    font.bold = 1;
    font.italic = 0;
    font.underline = 0;
    font.type = 1;
    font.oblique = 0;
    font.size = (MMI_APPLIST_APP_NAME_FONT_SIZE | 0x80);
    #ifdef __MMI_FONT_EFFECTS__
    font.smallCaps = applist_p->font_attr->attribute_id;
    #endif
    gui_set_font(&font);    

    gui_measure_string((UI_string_type)cell_name, &name_w, &name_h);

    gui_set_text_color(gui_color(255, 255, 255));

    /* Draw text */ 
    if (scrolling)
    {
        #ifdef __MMI_BIDI_ALG__
        if (mmi_fe_is_r2l_state())
        {
            start_x += name_w;
        }
        #endif
        gui_move_text_cursor(start_x, start_y);
            
        gui_print_text((UI_string_type)cell_name);
    }   
    else if (name_w < MMI_APPLIST_STRING_REGION)
    {
        start_x += (MMI_APPLIST_STRING_REGION - name_w) >> 1;
        #ifdef __MMI_BIDI_ALG__
        if (mmi_fe_is_r2l_state())
        {
            start_x += name_w;
        }
        #endif
        gui_move_text_cursor(start_x, start_y);
        gui_print_text((UI_string_type)cell_name);
    }
    /* Draw truncated text */
    else
    {
        #ifdef __MMI_BIDI_ALG__
        if (mmi_fe_is_r2l_state())
        {
            start_x += MMI_APPLIST_STRING_REGION;
        }
        #endif
        gui_move_text_cursor(start_x, start_y);

        #ifdef __MMI_FONT_EFFECTS__
        gui_print_truncated_text(
            start_x, 
            start_y + 2, MMI_APPLIST_STRING_REGION, (UI_string_type)cell_name);
        #else
        gui_print_truncated_text(
            start_x, 
            start_y, MMI_APPLIST_STRING_REGION, (UI_string_type)cell_name);
        #endif
    }

    //RANFOW_TRACE("[APPLIST]mmi_applist_draw_cell_string end\n");

    return name_w;
}


#ifdef __MMI_APPLIST_KEY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_scroll_cell_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_scroll_cell_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    S32 start_x, end_x, start_y, end_y, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (applist_p->mode != MMI_APPLIST_MODE_NORMAL || applist_p->hilight_frame.cell_p == NULL || applist_p->hilight_frame.cell_p->app_id == 0 ||
        applist_p->hilight_frame.cell_p->name_len <= MMI_APPLIST_STRING_REGION)
        return;

    gui_cancel_timer(mmi_applist_scroll_cell_string);    

    if (applist_p->state != MMI_APPLIST_STATE_NORMAL)
    {    
        gui_start_timer(MMI_APPLIST_CELL_STRING_SCROLL_DELAY, mmi_applist_scroll_cell_string);
        return;
    }
        
    cell = applist_p->hilight_frame.cell_p;

    start_x = -MMI_APPLIST_CELL_WIDTH / 2 + GET_CELL_X(applist_p->hilight_frame.type, cell->pos.x) + MMI_APPLIST_CELL_STRING_X;
    end_x = start_x + MMI_APPLIST_STRING_REGION - 4;
    start_y = -MMI_APPLIST_CELL_HEIGHT / 2 + cell->pos.y + MMI_APPLIST_CELL_STRING_Y;
    end_y = cell->pos.y + MMI_APPLIST_CELL_HEIGHT / 2;

    if (cell->name_len + MMI_APPLIST_STRING_SCROLL_SPACE_LEN - applist_p->hilight_frame.scroll_x < MMI_APPLIST_CELL_STRING_SCROLL_SPEED)        
        applist_p->hilight_frame.scroll_x = 0;
    else
        applist_p->hilight_frame.scroll_x += MMI_APPLIST_CELL_STRING_SCROLL_SPEED;

    /* clear the string area and redraw */
    gdi_layer_push_and_set_active(applist_p->panel_layer_handle);
    gdi_layer_push_and_set_clip(start_x, start_y, end_x, end_y);
    gdi_draw_solid_rect(start_x, start_y, end_x, end_y, GDI_COLOR_TRANSPARENT);

    #ifdef __MMI_BIDI_ALG__
    if (mmi_fe_is_r2l_state())
    {
        end_x += applist_p->hilight_frame.scroll_x - cell->name_len + 4;
        
        mmi_applist_draw_cell_string((UI_string_type)cell->name, MMI_TRUE, end_x, start_y);

        if (applist_p->hilight_frame.scroll_x + MMI_APPLIST_STRING_REGION > cell->name_len + MMI_APPLIST_STRING_SCROLL_SPACE_LEN)
            mmi_applist_draw_cell_string((UI_string_type)cell->name, MMI_TRUE, end_x - cell->name_len - MMI_APPLIST_STRING_SCROLL_SPACE_LEN, start_y);
    }
    else
    #endif
    {
        start_x -= applist_p->hilight_frame.scroll_x;
        
        mmi_applist_draw_cell_string((UI_string_type)cell->name, MMI_TRUE, start_x, start_y);

        if (applist_p->hilight_frame.scroll_x + MMI_APPLIST_STRING_REGION > cell->name_len + MMI_APPLIST_STRING_SCROLL_SPACE_LEN)
            mmi_applist_draw_cell_string((UI_string_type)cell->name, MMI_TRUE, start_x + cell->name_len + MMI_APPLIST_STRING_SCROLL_SPACE_LEN, start_y);
    }
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
    mmi_applist_blt_previous();
    gui_start_timer(MMI_APPLIST_CELL_STRING_SCROLL_DELAY, mmi_applist_scroll_cell_string);
}

#endif  //__MMI_APPLIST_KEY_SUPPORT__

#endif //__MMI_APPLIST_ONLY_ICON_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_cell_in_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_cell_in_cache(mmi_applist_cell_struct *cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_w, icon_h, shift_x, shift_y, icon_w_org, icon_h_org;
    gdi_handle cell_handle;
    U16 raw_data_img_type = GDI_IMAGE_TYPE_INVALID;     
	U8 *image_mem = NULL;
    #ifdef __MMI_APPLIST_CACHE_PATH_APP_ICON__   
	MMI_BOOL is_cached = MMI_FALSE;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_draw_cell_in_cache start\n");
    SLA_CustomLogging("DCI", SA_start);
#endif

    ASSERT(applist_p->empty_cache_index >= 0 &&
           applist_p->empty_cache_index < MMI_APPLIST_APP_CACHE_NUM);

    ASSERT(applist_p->panel_layer_handle != GDI_LAYER_EMPTY_HANDLE);

    /* Assign cache index */
    ASSERT(cell->cache_idx == MMI_APPLIST_INVALID_INDEX);
    cell->cache_idx = applist_p->empty_cache_index;
    #ifdef __MMI_APPLIST_SMART_ASM__
    if (applist_p->can_cache_cell)
    #endif
    {
        applist_p->cache_used[cell->cache_idx] = MMI_TRUE;
    }
    
    /* Create layer handle */
    gdi_layer_create_cf_using_outside_memory(
        #ifdef __MMI_FTE_SUPPORT__
        GDI_COLOR_FORMAT_PARGB6666,
        #else  //__MMI_FTE_SUPPORT__
        GDI_COLOR_FORMAT_32_PARGB,
        #endif  //__MMI_FTE_SUPPORT__
        0,
        0,
        MMI_APPLIST_CELL_WIDTH,
        MMI_APPLIST_CELL_HEIGHT,
        &cell_handle,
        mmi_applist_get_cache_buf_ptr(cell->cache_idx),
        MMI_APPLIST_APP_CACHE_SIZE); 
 
    gdi_layer_push_and_set_active(cell_handle);    
    gdi_layer_clear(GDI_COLOR_TRANSPARENT); 

    gdi_push_and_set_alpha_blending_source_layer(cell_handle);

    /* 
     * Get image size
     */
     
    /* Image buffer */
    if (cell->image_type == MMI_IMAGE_SRC_TYPE_ROM_MEMORY && cell->image_ptr != NULL)
    {
        raw_data_img_type = gdi_image_get_type_from_mem(cell->image_ptr);
        if (raw_data_img_type != GDI_IMAGE_TYPE_INVALID)
        {//raw data without 8 bits head        
            gdi_image_get_dimension_mem(raw_data_img_type,
                                        cell->image_ptr,
                                        cell->image_len,
                                        &icon_w,
                                        &icon_h);
        }
        else
        {//raw data with 8 bits head
            gdi_image_get_dimension(cell->image_ptr, &icon_w, &icon_h);
        }
    }
    /* Image ID */
    else if (cell->image_type == MMI_IMAGE_SRC_TYPE_RES_ID && cell->image.res_id != 0)
    {
        gdi_image_get_dimension_id(cell->image.res_id, &icon_w, &icon_h);        
    }
    /* Image path */
    else if (cell->image_type == MMI_IMAGE_SRC_TYPE_PATH && mmi_ucs2strlen((CHAR *)cell->image.path) != 0)
    {
        #ifdef __MMI_APPLIST_CACHE_PATH_APP_ICON__
        is_cached = mmi_applist_get_app_icon_data_cache(cell->app_id, &image_mem);
		if(is_cached && image_mem != NULL)
		{
            gdi_image_get_dimension(image_mem, &icon_w, &icon_h);
		}
		else
        #endif
		{
		    gdi_image_get_dimension_file((S8 *)cell->image.path, &icon_w, &icon_h);        
		}
    }

    icon_w_org = icon_w;
    icon_h_org = icon_h;

    if (cell->type == SRV_APPMGR_MRE_APP_PACKAGE_TYPE ||
        cell->type == SRV_APPMGR_JAVA_APP_PACKAGE_TYPE)
    {
        if (icon_w > MMI_APPLIST_APP_ICON_WIDTH_MAX &&
            icon_h > MMI_APPLIST_APP_ICON_HEIGHT_MAX)
        {
            icon_w = MMI_APPLIST_APP_ICON_WIDTH_MAX;
            icon_h = MMI_APPLIST_APP_ICON_HEIGHT_MAX;
        }
        else if (icon_w < MMI_APPLIST_APP_ICON_WIDTH_MIN &&
                 icon_h < MMI_APPLIST_APP_ICON_HEIGHT_MIN)
        {
            icon_w = MMI_APPLIST_APP_ICON_WIDTH_MIN;
            icon_h = MMI_APPLIST_APP_ICON_HEIGHT_MIN;
        }
    }

    shift_x = ((MMI_APPLIST_CELL_WIDTH - icon_w) >> 1);

#ifdef __MMI_APPLIST_ONLY_ICON_SUPPORT__ 
    shift_y = ((MMI_APPLIST_CELL_HEIGHT - icon_h) >> 1);
#else /* __MMI_APPLIST_ONLY_ICON_SUPPORT__ */
    shift_y = ((MMI_APPLIST_CELL_STRING_Y - icon_h) >> 1);
#endif /* __MMI_APPLIST_ONLY_ICON_SUPPORT__ */

    //Draw image
    mmi_applist_draw_resized_image(cell, shift_x, shift_y, icon_w_org, icon_h_org, icon_w, icon_h, raw_data_img_type, image_mem);

#ifndef __MMI_APPLIST_ONLY_ICON_SUPPORT__ 
    /* 
     * Draw string
     */
    cell->name_len = mmi_applist_draw_cell_string((UI_string_type)cell->name, MMI_FALSE, MMI_APPLIST_CELL_STRING_X, MMI_APPLIST_CELL_STRING_Y);
#endif /*  __MMI_APPLIST_ONLY_ICON_SUPPORT__ */

    if (mmi_applist_is_preinstall(cell->app_id))
    {
        gdi_layer_set_background(0);
        gdi_layer_flatten(cell_handle, applist_p->download_icon_handle, NULL, NULL);
    }

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();

    /* Free layer */
    gdi_layer_free(cell_handle);    
  
#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_draw_cell_in_cache end\n");
    SLA_CustomLogging("DCI", SA_stop);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_cache_bar_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_cache_bar_cell(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_APPLIST_SMART_ASM__
    if (!applist_p->can_cache_cell)
        return;
    #endif
#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_cache_bar_cell start\n");
    SLA_CustomLogging("CS", SA_start);
#endif

    /* Cache bar cell */
    for (i = 0; i < MMI_APPLIST_BAR_APP_NUM; i ++)
    {
        if (applist_p->bar_cell[i] == NULL)
            return;
        
        if (applist_p->bar_cell[i]->cache_idx == MMI_APPLIST_INVALID_INDEX)
        {
            mmi_applist_find_empty_cache_idx();
            ASSERT(applist_p->empty_cache_index != MMI_APPLIST_INVALID_INDEX);
            mmi_applist_draw_cell_in_cache(applist_p->bar_cell[i]);
        }        
    }
#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_cache_bar_cell end\n");
    SLA_CustomLogging("CS", SA_stop);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_cache_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_cache_cell(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_draw_info_struct draw_info = {0};
    mmi_applist_cell_struct *cell_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (applist_p->cache_cell.cell_p != NULL)
    { 
        cell_p = applist_p->cache_cell.cell_p;
        mmi_applist_get_cell_transform(
            cell_p,
            MMI_APPLIST_CELL_TYPE_PANEL,
            &draw_info.transform, 
            &draw_info.opacity);
        if (mmi_applist_output_in_range(&draw_info.transform, MMI_APPLIST_CELL_WIDTH, MMI_APPLIST_CELL_HEIGHT) == MMI_TRUE)
        {
            mmi_applist_draw_cell(cell_p, &draw_info);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_find_empty_cache_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_find_empty_cache_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, end, max;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_APPLIST_SMART_ASM__
    if (!applist_p->can_cache_cell)        
    {
        max = MMI_APPLIST_BASE_LAYER_CAN_CACHE_APP_NUM;
    }
    else
    #endif
    {
        max = MMI_APPLIST_APP_CACHE_NUM;
    }

    if (applist_p->empty_cache_index == MMI_APPLIST_INVALID_INDEX)
    {
        applist_p->empty_cache_index = 0;
    }

    /* Search backward */
    for (i = applist_p->empty_cache_index; i < max; i ++)
    {
        if (!applist_p->cache_used[i])
        {
            applist_p->empty_cache_index = i;
            break;
        }
    }
    /* found */
    if (i < max)
    {
        return;
    }

    /* Search from beginning */
    end = applist_p->empty_cache_index;
    for (i = 0; i < end; i ++)
    {
        if (!applist_p->cache_used[i])
        {
            applist_p->empty_cache_index = i;
            break;
        }
    } 
    /* found */
    if (i < end)
    {
        return;
    }

    /* Not found */
    applist_p->empty_cache_index = MMI_APPLIST_INVALID_INDEX;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_cache_page_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_get_cache_page_index(
        mmi_applist_cache_type_enum cache_type, MMI_BOOL cache_page[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, cur_page_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cur_page_idx = mmi_applist_get_current_page_idx();

    /* Assign clear page index */
    for (i = 0; i < MMI_APPLIST_MAX_PAGE_NUM; i ++)
    {
        if (cache_type == MMI_APPLIST_CACHE_TYPE_THIS &&
            i == cur_page_idx)
        {
            cache_page[i] = MMI_TRUE;
        }
        else if (cache_type == MMI_APPLIST_CACHE_TYPE_NEARBY &&
                 (i == cur_page_idx || 
                  i == cur_page_idx - 1 || 
                  i == cur_page_idx + 1))
        {
            cache_page[i] = MMI_TRUE;
        }
        else if (cache_type == MMI_APPLIST_CACHE_TYPE_PREVIOUS &&
                 (i == cur_page_idx || i == cur_page_idx - 1))
        {
            cache_page[i] = MMI_TRUE;
        }
        else if (cache_type == MMI_APPLIST_CACHE_TYPE_NEXT &&
                 (i == cur_page_idx || i == cur_page_idx + 1))
        {
            cache_page[i] = MMI_TRUE;
        }
        else
        {
            cache_page[i] = MMI_FALSE;
        }
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_remove_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_remove_cache(MMI_BOOL cache_page[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, start_idx, to_idx, cache_idx;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* clear page cache */
    for (i = 0; i < MMI_APPLIST_MAX_PAGE_NUM; i ++)
    {
        if (cache_page[i])
        {
            continue;
        }
        
        mmi_applist_get_page_cell_idx(i, &start_idx, &to_idx);

        for (j = start_idx; j <= to_idx; j++)
        {
            if (applist_p->panel_cell[j] == NULL)
            {
                continue;
            }
            cache_idx = applist_p->panel_cell[j]->cache_idx;
            if (cache_idx != MMI_APPLIST_INVALID_INDEX)
            {
                applist_p->cache_used[cache_idx] = MMI_FALSE;
            }
            applist_p->panel_cell[j]->cache_idx = MMI_APPLIST_INVALID_INDEX;
        }
    }  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_cache_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_cache_page(MMI_BOOL cache_page[], S32 *cell_start, S32 *cell_end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, start_idx, to_idx, curr_page_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_cache_page start\n");
    SLA_CustomLogging("CP", SA_start);
#endif

    *cell_start = 0x7FFFFFFF;
    *cell_end = 0;
    
    /* Cache panel cell */
    for (i = 0; i < MMI_APPLIST_MAX_PAGE_NUM; i ++)
    {
        if (!cache_page[i])
        {
            continue;
        }

        mmi_applist_get_page_cell_idx(i, &start_idx, &to_idx);

        for (j = start_idx; j <= to_idx; j++)
        {
            if (applist_p->panel_cell[j] == NULL)
                continue;
                        
            if (applist_p->panel_cell[j]->cache_idx != MMI_APPLIST_INVALID_INDEX)
            {
                continue;
            }
            
            mmi_applist_find_empty_cache_idx();
            /* Remove cache */
            if (applist_p->empty_cache_index == MMI_APPLIST_INVALID_INDEX)
            {
                mmi_applist_remove_cache(cache_page);
            }

            mmi_applist_find_empty_cache_idx();
            ASSERT(applist_p->empty_cache_index != MMI_APPLIST_INVALID_INDEX);
            
            mmi_applist_draw_cell_in_cache(applist_p->panel_cell[j]);
        }

        /* Update cell_start and cell_end */
        if (start_idx < *cell_start)
        {
            *cell_start = start_idx;            
        }
        if (to_idx > *cell_end)
        {
            *cell_end = to_idx;
        }
    }  
#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_cache_page end\n");
    SLA_CustomLogging("CP", SA_stop);
#endif  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_quiet_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_quiet_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx_from, idx_to;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (applist_p->state == MMI_APPLIST_STATE_NONE)
        return;
    
    #ifdef __MMI_APPLIST_CACHE_PATH_APP_ICON__
    if (applist_p->state != MMI_APPLIST_STATE_FIRST_ENTER && applist_p->state != MMI_APPLIST_STATE_ENTER && s_applist_app_icon_cache_pool_adm_id == NULL)
    {
        mmi_applist_create_app_icon_cache_adm();
        mmi_applist_update_app_icon_data_cache();
    }
    #endif
    
    mmi_applist_cache_slide_area_icon(&idx_from, &idx_to);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_cache_slide_area_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_cache_slide_area_icon(S32 *idx_from, S32 *idx_to)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL cache_page[MMI_APPLIST_MAX_PAGE_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_APPLIST_SMART_ASM__
    if (!applist_p->can_cache_cell)
    {
        S32 tmp_from, tmp_to, cur_page_idx = mmi_applist_get_current_page_idx();
        mmi_applist_get_page_cell_idx(cur_page_idx, &tmp_from, &tmp_to);
        if (applist_p->slide_region.slide_dir == MMI_APPLIST_DIR_LEFT && cur_page_idx > 0)
        {
            *idx_to = tmp_to;
            mmi_applist_get_page_cell_idx(cur_page_idx-1, &tmp_from, &tmp_to);
            *idx_from = tmp_from;
        }
        else if (applist_p->slide_region.slide_dir == MMI_APPLIST_DIR_RIGHT && cur_page_idx < mmi_applist_get_current_page_num() - 1)
        {
            *idx_from = tmp_from;
            mmi_applist_get_page_cell_idx(cur_page_idx+1, &tmp_from, &tmp_to);
            *idx_to = tmp_to;
        }
        else
        {
            *idx_from = tmp_from;
            *idx_to = tmp_to;
        }
        RANFOW_TRACE("[APPLIST]slide dir=%d,curr page=%d,from %d to %d\n", applist_p->slide_region.slide_dir, cur_page_idx, *idx_from, *idx_to);
        return;
    }
    #endif
    ASSERT(MMI_APPLIST_APP_CACHE_PAGE_NUM > 1);

    /* Prepare cache */
    if (applist_p->state == MMI_APPLIST_STATE_FIRST_ENTER || applist_p->state == MMI_APPLIST_STATE_ENTER)
    {
        mmi_applist_get_cache_page_index(
            MMI_APPLIST_CACHE_TYPE_THIS, cache_page);
    }
    else
    {
        #if MMI_APPLIST_APP_CACHE_PAGE_NUM == 2
        if (applist_p->slide_region.slide_dir == MMI_APPLIST_DIR_LEFT)
        {
            mmi_applist_get_cache_page_index(
                MMI_APPLIST_CACHE_TYPE_PREVIOUS, cache_page);
        }
        else
        {
            mmi_applist_get_cache_page_index(
                MMI_APPLIST_CACHE_TYPE_NEXT, cache_page);
        }
        #else
        mmi_applist_get_cache_page_index(
            MMI_APPLIST_CACHE_TYPE_NEARBY, cache_page);   
        #endif
    }

    mmi_applist_remove_cache(cache_page);
    mmi_applist_cache_page(cache_page, idx_from, idx_to);
    gui_start_timer(MMI_APPLIST_QUIET_CACHE_DELAY, mmi_applist_quiet_cache);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_matrix_multiply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_matrix_multiply(float *a, float *b, float *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, k, idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < 3; i ++)
    {
        for (j = 0; j < 3; j ++)
        {
            idx = i * 3 + j;
            out[idx] = 0; 
            for (k = 0; k < 3; k ++)
            {
                out[idx] += a[i * 3 + k] * b[k * 3 + j];
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_matrix
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_get_matrix(
        mmi_applist_matrix_type_enum type, 
        float value1,
        float value2,
        gdi_lt_matrix_struct *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float radian;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (type == MMI_APPLIST_MATRIX_TYPE_MOVE)
    {
        out->m[0] = 1.0f;
        out->m[1] = 0.0f;
        out->m[2] = value1; 
        out->m[3] = 0.0f;
        out->m[4] = 1.0f;   
        out->m[5] = value2;
        
    }
    else if (type == MMI_APPLIST_MATRIX_TYPE_SCALE)
    {
        out->m[0] = value1;
        out->m[1] = 0.0f;
        out->m[2] = 0.0f; 
        out->m[3] = 0.0f;
        out->m[4] = value2;   
        out->m[5] = 0.0f;
    }
    else if (type == MMI_APPLIST_MATRIX_TYPE_ROTATE)
    {
        radian = value1 * 3.14f / 180;
        out->m[0] = mmi_applist_cos(radian);
        out->m[1] = -mmi_applist_sin(radian);
        out->m[2] = 0.0f; 
        out->m[3] = mmi_applist_sin(radian);
        out->m[4] = mmi_applist_cos(radian);
        out->m[5] = 0.0f;
    }  
    
    out->m[6] = 0.0f;
    out->m[7] = 0.0f;
    out->m[8] = 1.0f;
}


void mmi_applist_transform_apply_point(const gdi_lt_matrix_struct *matrix, mmi_applist_position *point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float px, py, u, v, w;
    const float *m = matrix->m;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    px = point->x;
    py = point->y;

    u = px * m[0] + py * m[1] + m[2];
    v = px * m[3] + py * m[4] + m[5];
    w = px * m[6] + py * m[7] + m[8];

    /* get rid of divided by zero */
    // TODO: maybe assert...
    if (w == 0)
    {
        w = 1;
    }

    point->x = u / w;
    point->y = v / w;
}


void mmi_applist_get_output_rect(gdi_lt_matrix_struct *matrix, S32 in_width, S32 in_height, mmi_applist_rect *rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    float   x1, y1, x2, y2;
    float   x, y;

    mmi_applist_position vertex[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* top-left point */
    vertex[0].x = 0;
    vertex[0].y = 0;
    /* top-right point */
    vertex[1].x = (float)(in_width - 1);
    vertex[1].y = 0;
    /* bottom-left point */
    vertex[2].x = 0;
    vertex[2].y = (float)(in_height - 1);
    /* bottom-right point */
    vertex[3].x = (float)(in_width - 1);
    vertex[3].y = (float)(in_height - 1);

    x1 = 1000000;
    y1 = 1000000;
    x2 = -1000000;
    y2 = -1000000;

    /* get the output rect */
    for (i = 0; i < 4; i++)
    {
        mmi_applist_transform_apply_point(matrix, &vertex[i]);

        x = vertex[i].x;
        y = vertex[i].y;

        if (x < x1)
        {
            x1 = x;
        }

        if (x > x2)
        {
            x2 = x;
        }

        if (y < y1)
        {
            y1 = y;
        }

        if (y > y2)
        {
            y2 = y;
        }
    }

    /* enlarge the output rect a little to be safer from errors */
    // TODO: These are experiment values...
    x1 -= 4;
    y1 -= 4;
    x2 += 4;
    y2 += 4;

    rect->x1 = x1;
    rect->x2 = x2;
    rect->y1 = y1;
    rect->y2 = y2;
}

static MMI_BOOL mmi_applist_output_in_range(
    gdi_lt_matrix_struct *matrix,
    S32 in_width, S32 in_height)
{
    mmi_applist_rect rect;
    /*Only translate*/
    if(matrix->m[0] == 1.0 &&
       matrix->m[1] == 0.0 &&
       matrix->m[3] == 0.0 &&
       matrix->m[4] == 1.0 &&
       matrix->m[6] == 0.0 &&
       matrix->m[7] == 0.0 &&
       matrix->m[8] == 1.0)
    {
        if(matrix->m[2] < -in_width  || matrix->m[5] < -in_height)
        {
            return MMI_FALSE;
        }

        if(matrix->m[2] > LCD_WIDTH || matrix->m[5] > LCD_HEIGHT)
        {
            return MMI_FALSE;
        }

        return MMI_TRUE;
    }
    else
    {
        mmi_applist_get_output_rect(matrix, in_width, in_height, &rect);
        if(rect.x1 >= LCD_WIDTH || rect.y1 >= LCD_HEIGHT)
            return MMI_FALSE;

        if(rect.x2 <= 0 || rect.y2 <= 0)
            return MMI_FALSE;

        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_draw_cell(
        mmi_applist_cell_struct *cell, 
        mmi_applist_draw_info_struct *draw_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle src_layer_handle;    
    mmi_applist_rect rect;
    #if defined(G2D_SUPPORT) && defined(__MMI_APPLIST_APP_UNINSTALL_SUPPORT__)
    PU8 layer_buf = NULL;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MAUI_SOFTWARE_LA__
    RANFOW_TRACE("[APPLIST]mmi_applist_draw_cell start\n");
    SLA_CustomLogging("DC", SA_start);
    #endif

    #ifdef __MMI_APPLIST_SMART_ASM__
    if (!applist_p->can_cache_cell)
    {//draw current cell in cache first
        mmi_applist_find_empty_cache_idx();
        mmi_applist_draw_cell_in_cache(cell);
    }
    #endif    

    /* No cache */
    if (cell->cache_idx == MMI_APPLIST_INVALID_INDEX)
    {
        return;
    }

    if(draw_info->transform.m[0] == 1.0 &&
       draw_info->transform.m[1] == 0.0 &&
       draw_info->transform.m[3] == 0.0 &&
       draw_info->transform.m[4] == 1.0 &&
       draw_info->transform.m[6] == 0.0 &&
       draw_info->transform.m[7] == 0.0 &&
       draw_info->transform.m[8] == 1.0)
    {
        rect.x1 = draw_info->transform.m[2];
        rect.y1 = draw_info->transform.m[5];
        rect.x2 = draw_info->transform.m[2] + MMI_APPLIST_CELL_WIDTH -1;
        rect.y2 = draw_info->transform.m[5] + MMI_APPLIST_CELL_HEIGHT -1;
    }
#ifdef G2D_SUPPORT
    else
    {
        mmi_applist_get_output_rect(&draw_info->transform, MMI_APPLIST_CELL_WIDTH, MMI_APPLIST_CELL_HEIGHT, &rect);
    }
#else  //G2D_SUPPORT
    else
    {
        ASSERT(0);
    }
#endif   //G2D_SUPPORT
    
    #ifdef __MMI_APPLIST_KEY_SUPPORT__
    if (applist_p->hilight_frame.cell_p == cell && applist_p->hilight_frame.cell_p->app_id != 0)
    {
        mmi_applist_draw_hilight_frame(&rect, &draw_info->transform);
    }
    #endif

    #ifdef __MMI_APPLIST_EDIT_WITH_BG__
    if (applist_p->mode == MMI_APPLIST_MODE_EDIT)
    {
        gdi_layer_push_and_set_active(applist_p->icon_bg_handle);    
        gdi_layer_set_opacity(MMI_TRUE, cell->opacity);
        gdi_layer_set_position(rect.x1,rect.y1);
        gdi_layer_set_background(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
        gdi_layer_push_and_set_clip(rect.x1, rect.y1, rect.x2, rect.y2);
        gdi_layer_set_background(0);
        gdi_layer_flatten_with_clipping((gdi_handle)gdi_act_layer, applist_p->icon_bg_handle, NULL, NULL);
        gdi_layer_pop_clip();
    }
    #endif

    #if defined(G2D_SUPPORT) && defined(__MMI_APPLIST_APP_UNINSTALL_SUPPORT__)
    if (applist_p->mode == MMI_APPLIST_MODE_EDIT && mmi_applist_is_installed_app(cell->app_id))
    {
        mmi_applist_find_empty_cache_idx();
        ASSERT(applist_p->empty_cache_index != MMI_APPLIST_INVALID_INDEX);
        layer_buf = mmi_applist_get_cache_buf_ptr(applist_p->empty_cache_index);
        memcpy(layer_buf, mmi_applist_get_cache_buf_ptr(cell->cache_idx), MMI_APPLIST_APP_CACHE_SIZE);
        /* Create layer handle */
        gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_PARGB6666,
            0,
            0,
            MMI_APPLIST_CELL_WIDTH,
            MMI_APPLIST_CELL_HEIGHT,
            &src_layer_handle,
            layer_buf,
            MMI_APPLIST_APP_CACHE_SIZE);
        
        gdi_layer_push_and_set_active(src_layer_handle);
        gdi_layer_set_background(GDI_COLOR_TRANSPARENT);
        gdi_layer_flatten((gdi_handle)gdi_act_layer, applist_p->uninstall_icon_handle, NULL, NULL);
    }
    else
    #endif  //defined(G2D_SUPPORT) && defined(__MMI_APPLIST_APP_UNINSTALL_SUPPORT__)
    {
        /* Create layer handle */
        gdi_layer_create_cf_using_outside_memory(
            #ifdef __MMI_FTE_SUPPORT__
            GDI_COLOR_FORMAT_PARGB6666,
            #else  //__MMI_FTE_SUPPORT__
            GDI_COLOR_FORMAT_32_PARGB,
            #endif  //__MMI_FTE_SUPPORT__
            0,
            0,
            MMI_APPLIST_CELL_WIDTH,
            MMI_APPLIST_CELL_HEIGHT,
            &src_layer_handle,
            mmi_applist_get_cache_buf_ptr(cell->cache_idx),
            MMI_APPLIST_APP_CACHE_SIZE);
        
        gdi_layer_push_and_set_active(src_layer_handle);
    }

    #ifndef G2D_SUPPORT    
    gdi_layer_set_position(rect.x1,rect.y1);
    gdi_layer_set_background(GDI_COLOR_TRANSPARENT);
    #endif
    
    gdi_layer_set_opacity(MMI_TRUE, draw_info->opacity);
    gdi_layer_pop_and_restore_active();

    #ifdef G2D_SUPPORT  //Only use LT API when defined G2D
    if (rect.x1 < LCD_WIDTH && rect.y1 < LCD_HEIGHT && rect.x2 > 0  && rect.y2 > 0 && rect.x2 - rect.x1 + 1 <= LCD_WIDTH && rect.y2 - rect.y1 + 1 <= LCD_HEIGHT)
    { 
        #ifdef __MAUI_SOFTWARE_LA__
        //RANFOW_TRACE("[APPLIST]linear transform start\n");
        SLA_CustomLogging("CLT", SA_start);
        #endif
        gdi_2d_linear_transfrom(
            draw_info->transform.m,
            src_layer_handle,
            0,
            0,
            MMI_APPLIST_CELL_WIDTH,
            MMI_APPLIST_CELL_HEIGHT,  
            rect.x1, //0,
            rect.y1, //0, 
            rect.x2 - rect.x1 + 1, //LCD_WIDTH, 
            rect.y2 - rect.y1 + 1, //LCD_HEIGHT,       
            GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
            GDI_COLOR_TRANSPARENT,
            GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,
            0);          
        #ifdef __MAUI_SOFTWARE_LA__
        //RANFOW_TRACE("[APPLIST]linear transform end\n");
        SLA_CustomLogging("CLT", SA_stop);
        #endif
    }
    #else  //G2D_SUPPORT
    if(draw_info->transform.m[0] == 1.0 &&
       draw_info->transform.m[1] == 0.0 &&
       draw_info->transform.m[3] == 0.0 &&
       draw_info->transform.m[4] == 1.0 &&
       draw_info->transform.m[6] == 0.0 &&
       draw_info->transform.m[7] == 0.0 &&
       draw_info->transform.m[8] == 1.0)
    {
        gdi_layer_push_and_set_clip(rect.x1, rect.y1, rect.x2, rect.y2);
        gdi_layer_set_background(0);
        gdi_layer_flatten_with_clipping((gdi_handle)gdi_act_layer, src_layer_handle, NULL, NULL);
        gdi_layer_pop_clip();
        #ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
        if (applist_p->mode == MMI_APPLIST_MODE_EDIT && mmi_applist_is_installed_app(cell->app_id))
        {
            gdi_layer_push_and_set_active(applist_p->uninstall_icon_handle);    
            gdi_layer_set_opacity(MMI_TRUE, cell->opacity);
            gdi_layer_set_position(rect.x1,rect.y1);
            gdi_layer_set_background(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            gdi_layer_push_and_set_clip(rect.x1, rect.y1, rect.x2, rect.y2);
            gdi_layer_set_background(0);
            gdi_layer_flatten_with_clipping((gdi_handle)gdi_act_layer, applist_p->uninstall_icon_handle, NULL, NULL);
            gdi_layer_pop_clip();
        }
        #endif
    }
    #endif  //G2D_SUPPORT
    
    /* Free layer */
    gdi_layer_free(src_layer_handle);    

    #ifdef __MMI_APPLIST_SMART_ASM__
    if (!applist_p->can_cache_cell)
    {//free cache
        cell->cache_idx = MMI_APPLIST_INVALID_INDEX;
    }
    #endif

#ifdef __MAUI_SOFTWARE_LA__
    RANFOW_TRACE("[APPLIST]mmi_applist_draw_cell end\n");
    SLA_CustomLogging("DC", SA_stop);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_cell_transform
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_get_cell_transform(        
        mmi_applist_cell_struct *cell,
        mmi_applist_cell_type_enum cell_type,
        gdi_lt_matrix_struct *transform,
        U8 *opacity)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef G2D_SUPPORT
    gdi_lt_matrix_struct rotate, move_origin;
    gdi_lt_matrix_struct scale, out;
    float angle;
    #endif
    float anchor_x, anchor_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Move to origin */
    anchor_x = anchor_y = 0.5f;
    
    #ifdef G2D_SUPPORT
    if (applist_p->mode == MMI_APPLIST_MODE_EDIT && cell->resize == 1.0f)
    {
        anchor_x += ((rand()%3)/200.0f);
        anchor_y += ((rand()%3)/100.0f);
    }
    
    mmi_applist_get_matrix(
        MMI_APPLIST_MATRIX_TYPE_MOVE, 
        -MMI_APPLIST_CELL_WIDTH * anchor_x, 
        -MMI_APPLIST_CELL_HEIGHT * anchor_y,
        &move_origin);
    
    /* Scale */
    mmi_applist_get_matrix(
        MMI_APPLIST_MATRIX_TYPE_SCALE, 
        cell->resize, 
        cell->resize,
        &scale);
    
    /* Rotate */
    angle = 0.0f;
    if (cell->resize == 1.0f)
    {
        /* Selected cell doens't rotate */
        angle = applist_p->shake_info.angle + (rand()%10)/200.0f;        
    }

    mmi_applist_get_matrix(
        MMI_APPLIST_MATRIX_TYPE_ROTATE, 
        angle, 
        0, /* unused */
        &rotate);
    
    mmi_applist_matrix_multiply(rotate.m, move_origin.m, out.m);
    mmi_applist_matrix_multiply(scale.m, out.m, transform->m);
    #else  //G2D_SUPPORT
    mmi_applist_get_matrix(
        MMI_APPLIST_MATRIX_TYPE_MOVE, 
        -MMI_APPLIST_CELL_WIDTH * anchor_x, 
        -MMI_APPLIST_CELL_HEIGHT * anchor_y,
        transform);
    #endif  //G2D_SUPPORT
    
    /* Move to destination */
    if (cell == applist_p->focus_cell.cell_p)
    {
        transform->m[2] += GET_FINAL_CELL_X(cell_type, cell->pos.x); 
    }
    else
    {
        transform->m[2] += GET_CELL_X(cell_type, cell->pos.x); 
    }
    transform->m[5] += cell->pos.y;

    /* Opacity */
    *opacity = cell->opacity;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_shortcut_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_draw_shortcut_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, selected = MMI_APPLIST_INVALID_INDEX;
    mmi_applist_cell_struct *cell_p;
    mmi_applist_draw_info_struct draw_info = {0};
    MMI_BOOL need_redraw = MMI_FALSE;
    gdi_handle act_handle = NULL;
    gdi_layer_struct *act_layer_struct = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_draw_shortcut_bar start\n");
    SLA_CustomLogging("DSB", SA_start);
#endif

#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
    //copy from previous layer buffer
    if (applist_p->state != MMI_APPLIST_STATE_FIRST_ENTER && applist_p->state != MMI_APPLIST_STATE_RESET && applist_p->state != MMI_APPLIST_STATE_ENTER &&
        (applist_p->mode == MMI_APPLIST_MODE_NORMAL
        #ifdef __MMI_APPLIST_BARREL_SUPPORT__
        || applist_p->mode == MMI_APPLIST_MODE_EFFECT_PREVIEW
        #endif
        ))
    {
        gdi_rect_struct dest_clip = {0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1};
        gdi_layer_get_active(&act_handle);
        act_layer_struct = (gdi_layer_struct*)act_handle;
        gdi_2d_memory_blt_without_transpant_check(act_layer_struct->buf_ptr1, LCD_WIDTH, 0, MMI_APPLIST_SHORTCUT_BAR_Y, LCD_WIDTH, MMI_APPLIST_SHORTCUT_BAR_HEIGHT, 
            act_layer_struct->buf_ptr, LCD_WIDTH, 0, MMI_APPLIST_SHORTCUT_BAR_Y, dest_clip,  act_layer_struct->bits_per_pixel);
    } 

    /* Icon */
    for (i = 0; i < MMI_APPLIST_BAR_APP_NUM; i ++)
    {
        if (applist_p->bar_cell[i] != NULL)
        {
            if (applist_p->bar_cell[i]->resize != 1.0f)
            {
                selected = i;
                continue;
            }

            if (applist_p->mode == MMI_APPLIST_MODE_EDIT || applist_p->mode == MMI_APPLIST_MODE_POPUP ||
                applist_p->state == MMI_APPLIST_STATE_FIRST_ENTER || applist_p->state == MMI_APPLIST_STATE_RESET || applist_p->state == MMI_APPLIST_STATE_ENTER)
            {
                need_redraw = MMI_TRUE;
            }
            #ifdef __MMI_APPLIST_BARREL_SUPPORT__
            else if (applist_p->mode == MMI_APPLIST_MODE_EFFECT_PREVIEW)
            {
                need_redraw = MMI_FALSE;
            }
            #endif
            #ifdef __MMI_APPLIST_KEY_SUPPORT__
            //redraw cell if it turn to highlight from normal or reverse
            else if (((applist_p->hilight_frame.type == MMI_APPLIST_CELL_TYPE_SHORTCUT && i == applist_p->hilight_frame.index) ||
                (applist_p->hilight_frame.pre_type == MMI_APPLIST_CELL_TYPE_SHORTCUT && i == applist_p->hilight_frame.pre_index)) &&
                (applist_p->hilight_frame.pre_index != applist_p->hilight_frame.index || applist_p->hilight_frame.pre_type != applist_p->hilight_frame.type))
            {
                //remove to redraw the cell in normal or highlight
                for (j = 0; j < MMI_APPLIST_SHORTCUT_BAR_HEIGHT; j++)
                {
                    memset(act_layer_struct->buf_ptr + APPLIST_PIXES_PER_POINT * LCD_WIDTH * (MMI_APPLIST_SHORTCUT_BAR_Y+j) + (mmi_applist_get_bar_start_x() + i * MMI_APPLIST_CELL_WIDTH) * APPLIST_PIXES_PER_POINT, 
                        0,  MMI_APPLIST_CELL_WIDTH * APPLIST_PIXES_PER_POINT);
                }
                need_redraw = MMI_TRUE;
            }
            #ifndef __MMI_APPLIST_ONLY_ICON_SUPPORT__
            else if (i == applist_p->hilight_frame.index && applist_p->hilight_frame.cell_p->name_len > MMI_APPLIST_STRING_REGION)
            {//scroll text
                need_redraw = MMI_TRUE;
            }
            #endif
            #endif
            
            if (need_redraw)
            {
                cell_p = applist_p->bar_cell[i];
                mmi_applist_get_cell_transform(
                    cell_p, 
                    MMI_APPLIST_CELL_TYPE_SHORTCUT,
                    &draw_info.transform,
                    &draw_info.opacity);

                mmi_applist_draw_cell(cell_p, &draw_info);
                need_redraw = MMI_FALSE;
            }
        }        
    }
#else  //__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
    for (i = 0; i < MMI_APPLIST_BAR_APP_NUM; i ++)
    {
        if (applist_p->bar_cell[i] != NULL)
        {
            if (applist_p->bar_cell[i]->resize != 1.0f)
            {
                selected = i;
                continue;
            }

            cell_p = applist_p->bar_cell[i];
            mmi_applist_get_cell_transform(
                cell_p, 
                MMI_APPLIST_CELL_TYPE_SHORTCUT,
                &draw_info.transform,
                &draw_info.opacity);

            mmi_applist_draw_cell(cell_p, &draw_info);
        }        
    }
#endif  //__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__

#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_draw_shortcut_bar end\n");
    SLA_CustomLogging("DSB", SA_stop);
#endif

    return selected;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_applist_get_draw_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_get_slide_icon_draw_info(
        mmi_applist_cell_struct *cell, 
        S32 cell_index, 
        mmi_applist_draw_info_struct *draw_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MMI_APPLIST_BARREL_SUPPORT__    
    transform_func trans_func;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_APPLIST_BARREL_SUPPORT__    
    if (applist_p->mode != MMI_APPLIST_MODE_EDIT
        #ifdef __MMI_APPLIST_KEY_LOOP__
        && !applist_p->is_loop
        #endif
        )
    {
        trans_func = mmi_applist_barrel_get_transform();
        trans_func(
            cell_index, 
            &draw_info->transform, 
            &draw_info->opacity, 
            &draw_info->pos_z);
    }
    else
#endif        
    {
        mmi_applist_get_cell_transform(
            cell, 
            MMI_APPLIST_CELL_TYPE_PANEL,
            &draw_info->transform, 
            &draw_info->opacity);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_slide_area_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_draw_slide_area_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, max_idx, idx_from, idx_to;
    S32 selected = MMI_APPLIST_INVALID_INDEX;
    mmi_applist_cell_struct *cell_p;

    mmi_applist_draw_info_struct *draw_info_list, draw;
    mmi_applist_cell_struct *cell_list[MMI_APPLIST_DRAW_INFO_NUM];
    S32 cell_count, cell_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_draw_slide_area_icon start\n");
    SLA_CustomLogging("DSA", SA_start);
#endif

    /* Cache icon */
    gui_cancel_timer(mmi_applist_quiet_cache);
    mmi_applist_cache_slide_area_icon(&idx_from, &idx_to);
    
    /* two pages is the max pages we need to draw*/
    if (idx_to - idx_from > MMI_APPLIST_DRAW_INFO_NUM - 1)
    {
        S32 curr_page_idx = mmi_applist_get_current_page_idx();
        if (applist_p->slide_region.x > curr_page_idx * MMI_APPLIST_PAGE_WIDTH_INC_MARGIN)
            idx_from = idx_to - MMI_APPLIST_DRAW_INFO_NUM + 1;
        else
            idx_to = idx_from + MMI_APPLIST_DRAW_INFO_NUM - 1;
    }

    /* Get draw info */
    draw_info_list = (mmi_applist_draw_info_struct *)get_ctrl_buffer(
        sizeof(mmi_applist_draw_info_struct) * MMI_APPLIST_DRAW_INFO_NUM);    

    kal_mem_set(
        draw_info_list, 
        0, 
        sizeof(mmi_applist_draw_info_struct) * MMI_APPLIST_DRAW_INFO_NUM);

    cell_num = idx_to - idx_from + 1;
    ASSERT(cell_num <= MMI_APPLIST_DRAW_INFO_NUM);

    cell_count = 0;
    for (i = idx_from; i <= idx_to; i ++)
    {
        if (applist_p->panel_cell[i] != NULL)
        {            
            if (applist_p->panel_cell[i]->resize != 1.0f)
            {
                selected = i;
                continue;
            }
            mmi_applist_get_slide_icon_draw_info(
                applist_p->panel_cell[i],
                i,
                &draw_info_list[cell_count]);
            
            cell_list[cell_count] = applist_p->panel_cell[i];
            cell_count ++;                                 
        }    
    }
    
    /* Sort cell list with pos_z */
    for (i = 0; i < cell_count - 1; i ++)
    {
        max_idx = i;
        for(j = i + 1; j < cell_count; j ++)
        {
            if (draw_info_list[j].pos_z > draw_info_list[max_idx].pos_z)
            {
                max_idx = j;
            }
        }
        
        /* swap */
        if (i != max_idx)
        {
            draw = draw_info_list[i];
            draw_info_list[i] = draw_info_list[max_idx];
            draw_info_list[max_idx] = draw;

            cell_p = cell_list[i];
            cell_list[i] = cell_list[max_idx];
            cell_list[max_idx] = cell_p;
        }
    }
    
    /* Draw cell list */
    for (i = 0; i < cell_count; i ++)
    {
        if (mmi_applist_output_in_range(&draw_info_list[i].transform, MMI_APPLIST_CELL_WIDTH, MMI_APPLIST_CELL_HEIGHT) == MMI_TRUE)
        {
            mmi_applist_draw_cell(cell_list[i], &draw_info_list[i]);
        }
    }

    free_ctrl_buffer(draw_info_list);

    /* Cache cell */
    mmi_applist_draw_cache_cell();
    
#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_draw_slide_area_icon end\n");
    SLA_CustomLogging("DSA", SA_stop);
#endif

    return selected;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_selected_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_selected_cell(S32 shortcut_index, S32 slide_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_draw_info_struct draw_info = {0};
    mmi_applist_cell_struct *cell_p = NULL;
    mmi_applist_cell_type_enum cell_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (applist_p->focus_cell.cell_p)
    {
        cell_p = applist_p->focus_cell.cell_p;
        cell_type = applist_p->focus_cell.type;
    }
    /* When pen up, focus_cell is reset, 
       so we use resize to check who is selected_cell */
    else if (shortcut_index != MMI_APPLIST_INVALID_INDEX)
    {
        cell_p = applist_p->bar_cell[shortcut_index]; 
        cell_type = MMI_APPLIST_CELL_TYPE_SHORTCUT;
    }
    else if (slide_index != MMI_APPLIST_INVALID_INDEX)
    {
        cell_p = applist_p->panel_cell[slide_index];
        cell_type = MMI_APPLIST_CELL_TYPE_PANEL;
    } 

    /* There is selected cell */
    if (cell_p)
    {
        mmi_applist_get_cell_transform(
            cell_p, 
            cell_type, 
            &draw_info.transform,
            &draw_info.opacity);

        mmi_applist_draw_cell(cell_p, &draw_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_app_download_icon_in_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_app_download_icon_in_cache()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (applist_p->download_icon_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        mmi_applist_find_empty_cache_idx();
        ASSERT(applist_p->empty_cache_index != MMI_APPLIST_INVALID_INDEX);
        ASSERT(applist_p->empty_cache_index >= 0 &&
           applist_p->empty_cache_index < MMI_APPLIST_APP_CACHE_NUM);

        applist_p->cache_used[applist_p->empty_cache_index] = MMI_TRUE;

        /* Create layer handle */
        gdi_layer_create_cf_using_outside_memory(
            #ifdef __MMI_FTE_SUPPORT__
            GDI_COLOR_FORMAT_PARGB6666,
            #else  //__MMI_FTE_SUPPORT__
            GDI_COLOR_FORMAT_32_PARGB,
            #endif  //__MMI_FTE_SUPPORT__
            0,
            0,
            MMI_APPLIST_CELL_WIDTH,
            MMI_APPLIST_CELL_HEIGHT,
            &applist_p->download_icon_handle,
            mmi_applist_get_cache_buf_ptr(applist_p->empty_cache_index),
            MMI_APPLIST_APP_CACHE_SIZE); 
     
        gdi_layer_push_and_set_active(applist_p->download_icon_handle);    
        gdi_layer_clear(GDI_COLOR_TRANSPARENT); 

        /* draw image */       
        gdi_image_draw_id(MMI_APPLIST_APP_DOWNLOAD_ICON_X, MMI_APPLIST_APP_DOWNLOAD_ICON_Y, IMG_ID_APPLIST_APP_DOWNLOAD_ICON);

        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_indicator_in_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_indicator_in_cache()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle gdi_hdl;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Create layer handle to draw highlight indicator */
    gdi_layer_create_cf_using_outside_memory(
        #ifdef __MMI_FTE_SUPPORT__
        GDI_COLOR_FORMAT_PARGB6666,
        #else  //__MMI_FTE_SUPPORT__
        GDI_COLOR_FORMAT_32_PARGB,
        #endif  //__MMI_FTE_SUPPORT__
        0,
        0,
        MMI_APPLIST_INDICATOR_SIDE,
        MMI_APPLIST_INDICATOR_SIDE * 2,
        &gdi_hdl,
        applist_p->indicator_ptr,
        MMI_APPLIST_INDICATOR_CACHE_SIZE); 
 
    gdi_layer_push_and_set_active(gdi_hdl);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);    
 
    /* draw image */       
    gdi_image_draw_id(0, 0, IMG_ID_APPLIST_INDICATOR_DOT_H);
    gdi_image_draw_id(0, MMI_APPLIST_INDICATOR_SIDE, IMG_ID_APPLIST_INDICATOR_DOT_N);

    gdi_layer_pop_and_restore_active();
 
    /* Free layer */
    gdi_layer_free(gdi_hdl);
}


#ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_app_uninstall_icon_in_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_app_uninstall_icon_in_cache()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->uninstall_icon_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        mmi_applist_find_empty_cache_idx();
        ASSERT(applist_p->empty_cache_index != MMI_APPLIST_INVALID_INDEX);
        ASSERT(applist_p->empty_cache_index >= 0 &&
           applist_p->empty_cache_index < MMI_APPLIST_APP_CACHE_NUM);

        applist_p->cache_used[applist_p->empty_cache_index] = MMI_TRUE;

        /* Create layer handle */
        gdi_layer_create_cf_using_outside_memory(
            #ifdef __MMI_FTE_SUPPORT__
            GDI_COLOR_FORMAT_PARGB6666,
            #else  //__MMI_FTE_SUPPORT__
            GDI_COLOR_FORMAT_32_PARGB,
            #endif  //__MMI_FTE_SUPPORT__
            0,
            0,
            MMI_APPLIST_CELL_WIDTH,
            MMI_APPLIST_CELL_HEIGHT,
            &applist_p->uninstall_icon_handle,
            mmi_applist_get_cache_buf_ptr(applist_p->empty_cache_index),
            MMI_APPLIST_APP_CACHE_SIZE); 
     
        gdi_layer_push_and_set_active(applist_p->uninstall_icon_handle);    
        gdi_layer_clear(GDI_COLOR_TRANSPARENT); 

        /* draw image */       
        gdi_image_draw_id(0, 0, IMG_ID_APPLIST_APP_UNINSTALL_ICON);

        gdi_layer_pop_and_restore_active();
    }
}
#endif  //__MMI_APPLIST_APP_UNINSTALL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_indicator
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_indicator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, page_num;
    gdi_handle active_handle = NULL;
    gdi_layer_struct *active_layer_struct = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_draw_indicator start\n");
    SLA_CustomLogging("DI", SA_start);
#endif

    page_num = mmi_applist_get_current_page_num();
    gdi_layer_get_active(&active_handle);
    active_layer_struct = (gdi_layer_struct*)active_handle;
    /* Assign enable item */
    for (i = 0; i < page_num; i ++)
    {        
        if (applist_p->indicator[i].state == MMI_APPLIST_INDICATOR_STATE_INACTIVE)
        {
            for (j = 0; j < MMI_APPLIST_INDICATOR_SIDE; j++)
            {
                memcpy(active_layer_struct->buf_ptr + LCD_WIDTH * (applist_p->indicator[i].pos.y + j) * APPLIST_PIXES_PER_POINT + applist_p->indicator[i].pos.x * APPLIST_PIXES_PER_POINT, 
                    applist_p->indicator_ptr + MMI_APPLIST_INDICATOR_SIZE + MMI_APPLIST_INDICATOR_SIDE * j * APPLIST_PIXES_PER_POINT, MMI_APPLIST_INDICATOR_SIDE * APPLIST_PIXES_PER_POINT);
            }
        }
        else if (applist_p->indicator[i].state == MMI_APPLIST_INDICATOR_STATE_ACTIVE)
        {
            for (j = 0; j < MMI_APPLIST_INDICATOR_SIDE; j++)
            {
                memcpy(active_layer_struct->buf_ptr + LCD_WIDTH * (applist_p->indicator[i].pos.y + j) * APPLIST_PIXES_PER_POINT + applist_p->indicator[i].pos.x * APPLIST_PIXES_PER_POINT, 
                    applist_p->indicator_ptr + MMI_APPLIST_INDICATOR_SIDE * j * APPLIST_PIXES_PER_POINT, MMI_APPLIST_INDICATOR_SIDE * APPLIST_PIXES_PER_POINT);
            }
        }
    }
    
#ifdef __MAUI_SOFTWARE_LA__
    //RANFOW_TRACE("[APPLIST]mmi_applist_draw_indicator end\n");
    SLA_CustomLogging("DI", SA_stop);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_panel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_panel()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 shortcut_idx, slide_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (applist_p->state == MMI_APPLIST_STATE_NONE)
        return;
    
#ifdef __MAUI_SOFTWARE_LA__
    RANFOW_TRACE("[APPLIST]mmi_applist_draw_panel start\n");
    SLA_CustomLogging("DP", SA_start);
#endif
    
    gdi_layer_push_and_set_active(applist_p->panel_layer_handle);

#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
    gdi_layer_toggle_double();
#endif

#ifdef GDI_G2D_FILL_RECT_SUPPORT
    gdi_2d_fill_rect(
        (gdi_handle) gdi_act_layer,
        (gdi_handle) gdi_act_layer,
        0,
        0,
        gdi_act_layer->width,
        gdi_act_layer->height,
        255,
        GDI_COLOR_TRANSPARENT,
        0,
        NULL);
#else
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
#endif

    gdi_push_and_set_alpha_blending_source_layer(applist_p->panel_layer_handle);

    /* draw title */
#if defined(__MMI_APPLIST_KEY_SUPPORT__) && defined(__MMI_APPLIST_ONLY_ICON_SUPPORT__)
    mmi_applist_draw_title();
#endif

    /* Draw indicator */
    mmi_applist_draw_indicator();
    
    /* Draw slide area */
    slide_idx = mmi_applist_draw_slide_area_icon(); 

    /* Draw shortcut bar */
    if (applist_p->mode == MMI_APPLIST_MODE_EDIT || applist_p->state == MMI_APPLIST_STATE_RESET)
    {
        mmi_applist_cache_bar_cell();
    }
    shortcut_idx = mmi_applist_draw_shortcut_bar();

    /* Draw selected cell */
    mmi_applist_draw_selected_cell(shortcut_idx, slide_idx);

    gdi_layer_pop_and_restore_active();
    gdi_pop_and_restore_alpha_blending_source_layer();
    
#ifdef __MAUI_SOFTWARE_LA__
    RANFOW_TRACE("[APPLIST]mmi_applist_draw_panel end\n");
    SLA_CustomLogging("DP", SA_stop);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_wallpaper_blt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_wallpaper_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_applist_blt_previous();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_set_wp_stop_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_set_wp_stop_type(mmi_applist_wp_stop_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applist_p->wp_stop_type |= type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_unset_wp_stop_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_unset_wp_stop_type(mmi_applist_wp_stop_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applist_p->wp_stop_type &= ~(type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_is_stop_type_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_is_stop_type_set(mmi_applist_wp_stop_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((applist_p->wp_stop_type & type) != 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_if_wallpaper_can_play
 * DESCRIPTION
 *  usb mode handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_applist_if_wallpaper_can_play(void)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (applist_p->wp_stop_type == MMI_APPLIST_WP_STOP_TYPE_NONE)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_open_wallpaper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_open_wallpaper(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 page_idx, page_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(applist_p->wp_state == MMI_APPLIST_WP_STATE_CLOSED);
    applist_p->wp_client.on_blt = mmi_applist_wallpaper_blt;
    mmi_applist_vlw_init(&applist_p->wp_client, &applist_p->wp_config);

    page_idx = mmi_applist_get_current_page_idx();
    page_num = mmi_applist_get_current_page_num();
    
    applist_p->wp_config.on_page_change(
        page_idx, page_num,
        MMI_APPLIST_PAGE_WIDTH_INC_MARGIN, MMI_APPLIST_INTER_PAGE_MARGIN);
    
    applist_p->wp_config.on_open(
        applist_p->wallpaper_layer_handle,
        applist_p->blt_layer_flag,
        applist_p->play_layer_flag);
    
    applist_p->wp_state = MMI_APPLIST_WP_STATE_OPENED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_start_wallpaper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_start_wallpaper(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (applist_p->wp_state == MMI_APPLIST_WP_STATE_OPENED)
    {
        applist_p->wp_config.on_play();
            //applist_p->wallpaper_layer_handle,
            //applist_p->blt_layer_flag,
            //applist_p->play_layer_flag);
        applist_p->wp_state = MMI_APPLIST_WP_STATE_PLAYING;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_start_wallpaper_with_delay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_delay_start_wallpaper(
        mmi_applist_wp_stop_type_enum type, S32 ms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_applist_unset_wp_stop_type(type);
    
    if (mmi_applist_if_wallpaper_can_play())
    {
        gui_start_timer(ms, mmi_applist_start_wallpaper);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_stop_wallpaper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_stop_wallpaper(mmi_applist_wp_stop_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_applist_set_wp_stop_type(type);
    gui_cancel_timer(mmi_applist_start_wallpaper);
    
    if (applist_p->wp_state == MMI_APPLIST_WP_STATE_PLAYING)
    {
        applist_p->wp_config.on_stop();
        applist_p->wp_state = MMI_APPLIST_WP_STATE_OPENED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_close_wallpaper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_close_wallpaper(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_cancel_timer(mmi_applist_start_wallpaper);
    
    if (applist_p->wp_state == MMI_APPLIST_WP_STATE_PLAYING)
    {
        applist_p->wp_config.on_stop();
        applist_p->wp_config.on_close();
    }
    else if (applist_p->wp_state == MMI_APPLIST_WP_STATE_OPENED)
    {
        applist_p->wp_config.on_close();
    }
    
    applist_p->wp_state = MMI_APPLIST_WP_STATE_CLOSED;
}


#ifdef __MMI_APPLIST_KEY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_highlight_frame_in_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_highlight_frame_in_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_w, icon_h, shift_x, shift_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (applist_p->hilight_frame.hilight_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        mmi_applist_find_empty_cache_idx();
        ASSERT(applist_p->empty_cache_index >= 0 &&
               applist_p->empty_cache_index < MMI_APPLIST_APP_CACHE_NUM);

        applist_p->cache_used[applist_p->empty_cache_index] = MMI_TRUE;

        /* Create layer handle */
        gdi_layer_create_cf_using_outside_memory(
            #ifdef __MMI_FTE_SUPPORT__
            GDI_COLOR_FORMAT_PARGB6666,
            #else  //__MMI_FTE_SUPPORT__
            GDI_COLOR_FORMAT_32_PARGB,
            #endif  //__MMI_FTE_SUPPORT__
            0,
            0,
            MMI_APPLIST_CELL_WIDTH,
            MMI_APPLIST_CELL_HEIGHT,
            &applist_p->hilight_frame.hilight_handle,
            mmi_applist_get_cache_buf_ptr(applist_p->empty_cache_index),
            MMI_APPLIST_APP_CACHE_SIZE); 
     
        gdi_layer_push_and_set_active(applist_p->hilight_frame.hilight_handle);    
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        gdi_image_get_dimension_id(IMG_ID_APPLIST_HILIGHT_FRAME, &icon_w, &icon_h);
        shift_x = ((MMI_APPLIST_CELL_WIDTH - icon_w) >> 1);
        #ifdef __MMI_APPLIST_ONLY_ICON_SUPPORT__ 
        shift_y = ((MMI_APPLIST_CELL_HEIGHT - icon_h) >> 1);
        #else /* __MMI_APPLIST_ONLY_ICON_SUPPORT__ */
        shift_y = ((MMI_APPLIST_CELL_STRING_Y - icon_h) >> 1);
        #endif /* __MMI_APPLIST_ONLY_ICON_SUPPORT__ */
        /* draw image */       
        gdi_image_draw_id(shift_x, shift_y, IMG_ID_APPLIST_HILIGHT_FRAME);    

        gdi_layer_pop_and_restore_active();
    }  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_hilight_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_draw_hilight_frame(mmi_applist_rect *rect, gdi_lt_matrix_struct *transform)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(applist_p->hilight_frame.hilight_handle != GDI_LAYER_EMPTY_HANDLE);    
    ASSERT(applist_p->hilight_frame.cell_p != NULL);
    
    /*Set highlight frame property*/
    gdi_layer_push_and_set_active(applist_p->hilight_frame.hilight_handle);
    gdi_layer_set_opacity(MMI_TRUE, applist_p->hilight_frame.cell_p->opacity);
    #ifndef G2D_SUPPORT
    gdi_layer_set_position(rect->x1,rect->y1);
    gdi_layer_set_background(GDI_COLOR_TRANSPARENT);
    #endif
    gdi_layer_pop_and_restore_active();
    
    #ifdef G2D_SUPPORT
    if (rect->x1 < LCD_WIDTH && rect->y1 < LCD_HEIGHT && rect->x2 > 0 && rect->y2 > 0 && rect->x2 - rect->x1 + 1 <= LCD_WIDTH && rect->y2 - rect->y1 + 1 <= LCD_HEIGHT)
    {
        gdi_2d_linear_transfrom(
            transform->m,
            applist_p->hilight_frame.hilight_handle,
            0,
            0,
            MMI_APPLIST_CELL_WIDTH,
            MMI_APPLIST_CELL_HEIGHT,
            rect->x1, //0,
            rect->y1, //0, 
            rect->x2 - rect->x1 + 1, //LCD_WIDTH, 
            rect->y2 - rect->y1 + 1, //LCD_HEIGHT, 
            GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
            GDI_COLOR_TRANSPARENT,
            GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,
            0);
    }
    #else  //G2D_SUPPORT    
    if(transform->m[0] == 1.0 &&
       transform->m[1] == 0.0 &&
       transform->m[3] == 0.0 &&
       transform->m[4] == 1.0 &&
       transform->m[6] == 0.0 &&
       transform->m[7] == 0.0 &&
       transform->m[8] == 1.0)
    {
        gdi_layer_push_and_set_clip(rect->x1, rect->y1, rect->x2, rect->y2);
        gdi_layer_set_background(0);
        gdi_layer_flatten_with_clipping((gdi_handle)gdi_act_layer, applist_p->hilight_frame.hilight_handle, NULL, NULL);
        gdi_layer_pop_clip();
    }
    #endif  //G2D_SUPPORT
}

#ifdef __MMI_APPLIST_ONLY_ICON_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell_p;
    S32 name_w, name_h, string_region, shift_x, shift_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell_p = applist_p->hilight_frame.cell_p;
    if (!cell_p)
    {
        return;
    }

    ASSERT(applist_p->title_layer_handle != GDI_LAYER_EMPTY_HANDLE);
    
    gdi_layer_push_and_set_active(applist_p->title_layer_handle);    
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        
    /* Background */
    gui_draw_filled_area(
        0, 0, 
        LCD_WIDTH - 1, MMI_APPLIST_TITLE_BAR_HEIGHT - 1, 
        current_MMI_theme->title_filler);

    if (applist_p->mode != MMI_APPLIST_MODE_EDIT || applist_p->hilight_frame.type == MMI_APPLIST_CELL_TYPE_SHORTCUT || 
        !mmi_applist_if_panel_page_empty(mmi_applist_get_final_page_idx()))
    {    
        /* String */ 
        gdi_layer_reset_clip();
        gdi_layer_reset_text_clip();
        
        gui_set_font(&MMI_large_font); 
       
        gui_measure_string((UI_string_type) cell_p->name, &name_w, &name_h);
        
        gui_set_text_color(*(current_MMI_theme->title_text_color));
        gui_set_text_border_color(*(current_MMI_theme->title_text_border_color));

        string_region = LCD_WIDTH - (MMI_APPLIST_CELL_STRING_X<<1);
        shift_x = MMI_APPLIST_CELL_STRING_X;
        shift_y = (MMI_APPLIST_TITLE_BAR_HEIGHT - name_h) >> 1;
            
        /* Draw text */    
        if (name_w < string_region)
        {
            shift_x += ((string_region - name_w) >> 1);
            
            #ifdef __MMI_BIDI_ALG__
            if (mmi_fe_is_r2l_state())
            {
                shift_x += name_w;
            }
            #endif
            
            gui_move_text_cursor(shift_x, shift_y);
            gui_print_text((UI_string_type) cell_p->name);
        }
        /* Draw truncated text */
        else
        {        
            #ifdef __MMI_BIDI_ALG__
            if (mmi_fe_is_r2l_state())
            {
                shift_x += string_region;
            }
            #endif
            
            gui_move_text_cursor(shift_x, shift_y);
            
            gui_print_truncated_text(
                shift_x, shift_y, string_region, 
                (UI_string_type) cell_p->name);
        }
    }
    
    gdi_layer_set_position(0, MMI_STATUS_BAR_HEIGHT);
    gdi_layer_pop_and_restore_active();
    gdi_layer_push_and_set_clip(0, MMI_STATUS_BAR_HEIGHT, LCD_WIDTH, MMI_STATUS_BAR_HEIGHT + MMI_APPLIST_TITLE_BAR_HEIGHT);
    gdi_layer_set_background(0);
    gdi_layer_flatten_with_clipping((gdi_handle)gdi_act_layer, applist_p->title_layer_handle, NULL, NULL);
    gdi_layer_pop_clip();
}
#endif /* __MMI_APPLIST_ONLY_ICON_SUPPORT__ */


#endif /* __MMI_APPLIST_KEY_SUPPORT__ */

#endif /* __MMI_LAUNCHER_APP_LIST__ */

