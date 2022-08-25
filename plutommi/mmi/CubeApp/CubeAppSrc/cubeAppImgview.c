/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  cubeAppImgview.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Cube Image View 
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_3D_CUBE_APP_IMGVIEW__

/* exclude header file */
#include "FileMgrGProt.h"
#include "FileMgrSrvGProt.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "custom_events_notify.h"
#include "MediaCacheSrvGprot.h"
#include "med_api.h"

/* just for KEY_VOL_TIMER_ID timer id */
#include "mmi_rp_app_profiles_def.h"

/* internal header file */
#include "vapp_cube_imgview_config.h"
#include "CubeAppImgview.h"
#include "CubeApp\vadp_p2v_cube_imgview.h"
#include "CubeAppGprot.h"
#include "MobileTVPlayerGprot.h"
#include "USBDeviceGprot.h"

/* function declaration */
static void mmi_cube_imgview_malloc_cache_buffer(void);
static void mmi_cube_imgview_free_cache_buffer(void);
extern void mmi_cube_imgview_create_cache(void);
extern void mmi_cube_imgview_close_cache(void);
extern void mmi_cube_imgview_change_navigation_mode(S32 index);
extern void mmi_cube_imgview_set_small_image(S32 image_width, S32 image_height);
extern void mmi_cube_imgview_set_large_image(S32 image_width, S32 image_height);
static S32 mmi_cube_imgview_internal_index(S32 index, S32 mode);
static void mmi_cube_imgview_decode_next_in_queue(void);
static void mmi_cube_imgview_get_decoded_image_to_layer(void);
static void mmi_cube_imgview_view_mode_decode_result_cb(S32 err_group, S32 err_code, gdi_handle handle);

/* S32 mmi_cubecache_get_curr_img_to_layer(srv_mediacache_img_to_layer_struct *layer_info); */
static void mmi_cube_get_target_width_height(S32 index, S32 mode, PS32 width, PS32 height);
static S32 mmi_cube_imgview_file_sort_callback(fmgr_filelist_handle fl_hdl, S32 result, S32 progress, S32 total);
extern void mmi_imgview_get_storage_file_path(WCHAR *filepath);

mmi_cube_imgview_cntx_struct g_mmi_cube_imgview_cntx = 
{
    NULL,
    NULL,
    MMI_CUBE_IMGVIEW_SORT_STATE_IDLE,
    0,
    {0},
    {0},
    {0},
    {0},
    0,
    0,
    NULL,
    0,
    0,
    0,
    NULL,
    0,
    NULL,
    0,
    0,
    0,
    0,
    0,
    NULL,
    0,
    0,
    0,
    MMI_FALSE,
    MMI_FALSE
};


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_get_file_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_cube_imgview_get_file_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_pathname[SRV_FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgview_get_storage_file_path((WCHAR*) buf_pathname);

    if (g_mmi_cube_imgview_cntx.fl)
    {
        if (buf_pathname[0] != g_mmi_cube_imgview_cntx.curr_drv)
        {
            mmi_cube_imgview_free_file_list();
        }
    }
    return g_mmi_cube_imgview_cntx.fl;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_create_file_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data           [?]         
 *  path                [IN]        
 *  filter              [IN]        
 *  sort_type           [IN]        
 *  sort_callback       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_cube_imgview_create_file_list(
        void *user_data,
        PU16 path,
        FMGR_FILTER filter,
        U16 sort_type,
        mmi_cube_imgview_sort_callback sort_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    S32 file_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_cube_imgview_cntx.user_data = user_data;
    g_mmi_cube_imgview_cntx.sort_callback = sort_callback;

    /* if already created, will not create again */
    if (g_mmi_cube_imgview_cntx.fl)
    {
        return FS_NO_ERROR;
    }

    mmi_ucs2cpy((PS8) g_mmi_cube_imgview_cntx.folder_path, (PS8) path);

    result = mmi_fmgr_filelist_create_async(
                &(g_mmi_cube_imgview_cntx.fl),
                (PS8) path,
                &filter,
                sort_type,
                0,
                mmi_cube_imgview_file_sort_callback);

    g_mmi_cube_imgview_cntx.curr_drv = (S8) path[0];

    if (result == FS_NO_ERROR)
    {
        g_mmi_cube_imgview_cntx.sort_state = MMI_CUBE_IMGVIEW_SORT_STATE_OVER;
        file_count = mmi_fmgr_filelist_get_count(g_mmi_cube_imgview_cntx.fl);
        g_mmi_cube_imgview_cntx.sort_callback(
                                    g_mmi_cube_imgview_cntx.user_data,
                                    file_count,
                                    MMI_CUBE_IMGVIEW_SORT_STATE_OVER);
    }
    else if (result == MMI_FMGR_ERROR_LOADING)
    {
        g_mmi_cube_imgview_cntx.sort_state = MMI_CUBE_IMGVIEW_SORT_STATE_DOING;
    }
    else
    {
        g_mmi_cube_imgview_cntx.fl = 0;
        g_mmi_cube_imgview_cntx.sort_state = MMI_CUBE_IMGVIEW_SORT_STATE_IDLE;
        /* here means occurs error */ ;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_free_file_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_free_file_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cube_imgview_cntx.fl)
    {
        /* mmi_cube_imgview_close_cache(); */

        g_mmi_cube_imgview_cntx.sort_callback = NULL;
        g_mmi_cube_imgview_cntx.user_data = NULL;
        mmi_fmgr_filelist_free(g_mmi_cube_imgview_cntx.fl);
        g_mmi_cube_imgview_cntx.fl = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_get_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
PU16 mmi_cube_imgview_get_file_path(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    S32 info_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info_result = mmi_fmgr_filelist_get_info(g_mmi_cube_imgview_cntx.fl, index, &file_info);
    if (info_result == MMI_FMGR_ERROR_INDEX_INVALID)
    {
        return NULL;
    }

    if (mmi_ucs2strlen((PS8) (g_mmi_cube_imgview_cntx.folder_path)) + mmi_ucs2strlen((PS8) (file_info.file_name)) >=
        (SRV_FMGR_PATH_MAX_LEN+1))
    {
        return NULL;
    }

    mmi_ucs2cpy((PS8) (g_mmi_cube_imgview_cntx.file_path), "");
    mmi_ucs2cat((PS8) (g_mmi_cube_imgview_cntx.file_path), (PS8) (g_mmi_cube_imgview_cntx.folder_path));
    mmi_ucs2cat((PS8) (g_mmi_cube_imgview_cntx.file_path), (PS8) (file_info.file_name));

    return (PU16) (g_mmi_cube_imgview_cntx.file_path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_file_sort_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fl_hdl          [IN]        
 *  result          [IN]        
 *  progress        [IN]        
 *  total           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_cube_imgview_file_sort_callback(fmgr_filelist_handle fl_hdl, S32 result, S32 progress, S32 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (progress == total)
    {
        g_mmi_cube_imgview_cntx.sort_state = MMI_CUBE_IMGVIEW_SORT_STATE_OVER;
        if (g_mmi_cube_imgview_cntx.sort_callback != NULL)
        {
            /* mmi_cube_imgview_create_cache(); */
            g_mmi_cube_imgview_cntx.sort_callback(
                                        g_mmi_cube_imgview_cntx.user_data,
                                        total,
                                        MMI_CUBE_IMGVIEW_SORT_STATE_OVER);
            if (result < 0)
            {
                mmi_cube_imgview_free_file_list();
                total = 0;
            }
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_get_file_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_cube_imgview_get_file_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cube_imgview_cntx.fl != 0)
    {
        file_count = mmi_fmgr_filelist_get_count(g_mmi_cube_imgview_cntx.fl);
        if (file_count == MMI_FMGR_ERROR_LOADING)
        {
            ;
        }
        else if (file_count == MMI_FMGR_ERROR_INDEX_INVALID)
        {
            ;
        }
        else if (file_count < 0)
        {
            file_count = 0;
        }
    }
    else
    {
        file_count = 0;
    }

    return file_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_get_sort_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_cube_imgview_get_sort_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cube_imgview_cntx.fl != 0)
    {
        return g_mmi_cube_imgview_cntx.sort_state;
    }
    else
    {
        return MMI_CUBE_IMGVIEW_SORT_STATE_IDLE;
    }
}

/* will give mode, although current mode is reserved */


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_get_file_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  width       [IN]        
 *  height      [IN]        
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_get_file_size(S32 index, PS32 width, PS32 height, S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    srv_mediacache_get_img_info_struct image_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_mediacache_get_image_info(g_mmi_cube_imgview_cntx.cache_handle, index, &image_info);
    if (ret == SRV_MEDIACACHE_OK)
    {
        *width = image_info.org_width;
        *height = image_info.org_height;
    }
    else
    {
        PU16 path;

        path = mmi_cube_imgview_get_file_path(index);

        gdi_image_get_dimension_file((PS8) path, width, height);
    }
    if (*width == -1 || *height == -1)
    {
        PU16 path;

        path = mmi_cube_imgview_get_file_path(index);

        gdi_image_get_dimension_file((PS8) path, width, height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_decode_result_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  err_group       [IN]        
 *  err_code        [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_decode_result_cb(S32 err_group, S32 err_code, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 internal_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    internal_index = mmi_cube_imgview_internal_index(
                        g_mmi_cube_imgview_cntx.curr_decode_index,
                        g_mmi_cube_imgview_cntx.curr_decode_mode);

    if (internal_index == MMI_CUBE_IMGVIEW_CURR_DECODE_NONE)
    {
        StartTimer(KEY_VOL_TIMER_ID, 1, mmi_cube_imgview_decode_next_in_queue);
        return;
    }

    if (err_code < 0)
    {
        ////TODO decode failed, will notify cube, and then release the handle
        //mmi_cube_imgview_free_file_layer_handle(g_mmi_cube_imgview_cntx.curr_decode_index);
        g_mmi_cube_imgview_cntx.layers[internal_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR;
        g_mmi_cube_imgview_cntx.decode_cb(
                                    g_mmi_cube_imgview_cntx.decode_user_data,
                                    g_mmi_cube_imgview_cntx.curr_decode_index,
                                    GDI_LAYER_EMPTY_HANDLE,
                                    MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR,
                                    g_mmi_cube_imgview_cntx.layers[internal_index].mode);

        StartTimer(KEY_VOL_TIMER_ID, 1, mmi_cube_imgview_decode_next_in_queue);
    }
    else
    {
        /* //TODO tell cube, this image is decode done. then update the cell image */
        mmi_cube_imgview_get_decoded_image_to_layer();
        /* gui_start_timer(10, mmi_cube_imgview_decode_next_in_queue); */
        StartTimer(KEY_VOL_TIMER_ID, 1, mmi_cube_imgview_decode_next_in_queue);

        /* gdi_layer_save_bmp_file(g_mmi_cube_imgview_cntx.layers[internal_index].handle, (char*)(L"D:\\src1.bmp")); */
        g_mmi_cube_imgview_cntx.decode_cb(
                                    g_mmi_cube_imgview_cntx.decode_user_data,
                                    g_mmi_cube_imgview_cntx.curr_decode_index,
                                    g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr,
                                    MMI_CUBE_IMGVIEW_FILE_DECODE_OVER,
                                    g_mmi_cube_imgview_cntx.layers[internal_index].mode);
        /* gdi_layer_save_bmp_file(g_mmi_cube_imgview_cntx.layers[internal_index].handle, (char*)(L"D:\\src1.bmp")); */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_init_layer_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layer_infos         [?]         
 *  handle              [IN]        
 *  target_width        [IN]        
 *  target_height       [IN]        
 *  src_width           [IN]        
 *  src_height          [IN]        
 *  layer_index         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_init_layer_struct(
        srv_mediacache_img_to_layer_struct *layer_infos,
        gdi_handle handle,
        S32 target_width,
        S32 target_height,
        S32 src_width,
        S32 src_height,
        S32 layer_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    layer_infos->dst.x = 0;
    layer_infos->dst.y = 0;
    layer_infos->dst.width = target_width;
    layer_infos->dst.height = target_height;

    layer_infos->src.x = 0;
    layer_infos->src.y = 0;
    layer_infos->src.width = src_width;
    layer_infos->src.height = src_height;

    layer_infos->dst_layer = handle;
    layer_infos->callback = mmi_cube_imgview_decode_result_cb;

    layer_infos->user_data = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_find_available_layer_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_cube_imgview_find_available_layer_index(S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode == MMI_CUBE_IMGVIEW_MODE_NAVIGATION)
    {
        for (i = 0; i < MMI_VAPP_CUBE_IMGVIEW_NAVIGATION_LAYER_COUNT; i++)
        {
            if (g_mmi_cube_imgview_cntx.layers[i].is_using)
            {
                continue;
            }
            else
            {
                return i;
            }
        }
        if (i >= MMI_VAPP_CUBE_IMGVIEW_NAVIGATION_LAYER_COUNT)
        {
            /* all layers is using now */
            MMI_ASSERT(0);
        }
    }
    else
    {
        for (i = MMI_VAPP_CUBE_IMGVIEW_NAVIGATION_LAYER_COUNT; i < MMI_VAPP_CUBE_IMGVIEW_LAYER_COUNT; i++)
        {
            if (g_mmi_cube_imgview_cntx.layers[i].is_using)
            {
                continue;
            }
            else
            {
                return i;
            }
        }
        if (i >= MMI_VAPP_CUBE_IMGVIEW_LAYER_COUNT)
        {
            /* all layers is using now */
            MMI_ASSERT(0);
        }
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_find_if_someone_is_decoding
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_cube_imgview_find_if_someone_is_decoding(S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VAPP_CUBE_IMGVIEW_LAYER_COUNT; i++)
    {
        if (g_mmi_cube_imgview_cntx.layers[i].is_using == MMI_TRUE)
        {
            if (g_mmi_cube_imgview_cntx.layers[i].state == MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODING)
            {
                if (g_mmi_cube_imgview_cntx.layers[i].index == g_mmi_cube_imgview_cntx.curr_decode_index)
                {
                    if (g_mmi_cube_imgview_cntx.layers[i].mode == mode)
                        //although this decoding image maybe not in my current mode, but I still allow it to decode over
                        //this is my current policy
                    {
                        return i;
                    }
                }
            }
        }
    }

    return MMI_CUBE_IMGVIEW_LAYER_INDEX_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_internal_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  mode        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_cube_imgview_internal_index(S32 index, S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VAPP_CUBE_IMGVIEW_LAYER_COUNT; i++)
    {
        if (g_mmi_cube_imgview_cntx.layers[i].is_using == MMI_TRUE)
        {
            if (g_mmi_cube_imgview_cntx.layers[i].mode == mode)
            {
                if (g_mmi_cube_imgview_cntx.layers[i].index == index)
                {
                    return i;
                }
            }
        }
    }

    return MMI_CUBE_IMGVIEW_CURR_DECODE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_find_need_decode_in_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_cube_imgview_find_need_decode_in_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VAPP_CUBE_IMGVIEW_LAYER_COUNT; i++)
    {
        if (g_mmi_cube_imgview_cntx.layers[i].mode == g_mmi_cube_imgview_cntx.curr_decode_mode)
        {
            if (g_mmi_cube_imgview_cntx.layers[i].is_using == MMI_TRUE)
            {
                if ((g_mmi_cube_imgview_cntx.layers[i].state == MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_WAITING_FOR_DECODE)
                    || (g_mmi_cube_imgview_cntx.layers[i].state == MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODING))
                {
                    return i;
                }
            }
        }
    }

    return MMI_CUBE_IMGVIEW_LAYER_INDEX_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_find_need_decode_in_queue_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_cube_imgview_find_need_decode_in_queue_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cube_imgview_cntx.curr_decode_mode == MMI_CUBE_IMGVIEW_MODE_VIEW)
    {
        for (i = MMI_VAPP_CUBE_IMGVIEW_NAVIGATION_LAYER_COUNT; i < MMI_VAPP_CUBE_IMGVIEW_LAYER_COUNT; i++)
        {
            if (g_mmi_cube_imgview_cntx.layers[i].mode == g_mmi_cube_imgview_cntx.curr_decode_mode)
            {
                if (g_mmi_cube_imgview_cntx.layers[i].is_using == MMI_TRUE)
                {
                    if (g_mmi_cube_imgview_cntx.layers[i].draw_source == SRV_MEDIACACHE_OK_L2)
                    {
                        return i;
                    }
                }
            }
        }
    }

    return MMI_CUBE_IMGVIEW_LAYER_INDEX_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_get_image_to_small
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cube_imgview_get_image_to_small()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_get_decoded_image_to_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cube_imgview_get_decoded_image_to_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret, file_width, file_height, internal_index;
    srv_mediacache_img_to_layer_struct layer_info;
    gdi_handle layer_handle;
    void *mem_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    internal_index = mmi_cube_imgview_internal_index(
                        g_mmi_cube_imgview_cntx.curr_decode_index,
                        g_mmi_cube_imgview_cntx.curr_decode_mode);

    if (internal_index != MMI_CUBE_IMGVIEW_LAYER_INDEX_ERROR)
    {
        mmi_cube_imgview_get_file_size(
            g_mmi_cube_imgview_cntx.layers[internal_index].index,
            &file_width,
            &file_height,
            g_mmi_cube_imgview_cntx.curr_decode_mode);

        srv_mediacache_goto_index(
            g_mmi_cube_imgview_cntx.cache_handle,
            g_mmi_cube_imgview_cntx.layers[internal_index].index);

        if (g_mmi_cube_imgview_cntx.layers[internal_index].mode == MMI_CUBE_IMGVIEW_MODE_VIEW)
        {
            if (srv_mediacache_can_draw_curr(g_mmi_cube_imgview_cntx.cache_handle) == SRV_MEDIACACHE_OK_L1)
            {
                mem_addr = g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr2;
            }
            else
            {
                mem_addr = g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr;
            }
        }
        else
        {
            mem_addr = g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr;
        }

        gdi_layer_create_using_outside_memory(
            0,
            0,
            g_mmi_cube_imgview_cntx.layers[internal_index].real_width,
            g_mmi_cube_imgview_cntx.layers[internal_index].real_height,
            &layer_handle,
            mem_addr,
            g_mmi_cube_imgview_cntx.layers[internal_index].real_width * g_mmi_cube_imgview_cntx.layers[internal_index].real_height * 2);
        mmi_cube_imgview_init_layer_struct(
            &layer_info,
            layer_handle,
            g_mmi_cube_imgview_cntx.layers[internal_index].real_width,
            g_mmi_cube_imgview_cntx.layers[internal_index].real_height,
            file_width,
            file_height,
            internal_index);

        ret = srv_mediacache_get_curr_img_to_layer(g_mmi_cube_imgview_cntx.cache_handle, &layer_info);
        if (ret == SRV_MEDIACACHE_OK)
        {
            g_mmi_cube_imgview_cntx.curr_decode_index = g_mmi_cube_imgview_cntx.layers[internal_index].index;
            g_mmi_cube_imgview_cntx.curr_decode_mode = g_mmi_cube_imgview_cntx.layers[internal_index].mode;
            if (g_mmi_cube_imgview_cntx.layers[internal_index].mode == MMI_CUBE_IMGVIEW_MODE_VIEW)
            {
                g_mmi_cube_imgview_cntx.layers[internal_index].draw_source = srv_mediacache_can_draw_curr(g_mmi_cube_imgview_cntx.cache_handle);
            }
            g_mmi_cube_imgview_cntx.layers[internal_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER;
            gdi_layer_free(layer_handle);
        }
        else if (ret == SRV_MEDIACACHE_ERR_DECODING)
        {
            g_mmi_cube_imgview_cntx.layers[internal_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODING;
            g_mmi_cube_imgview_cntx.curr_decode_index = g_mmi_cube_imgview_cntx.layers[internal_index].index;
            g_mmi_cube_imgview_cntx.curr_decode_mode = g_mmi_cube_imgview_cntx.layers[internal_index].mode;
            gdi_layer_free(layer_handle);
        }
        else
        {
            g_mmi_cube_imgview_cntx.layers[internal_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR;
            //g_mmi_cube_imgview_cntx.curr_decode_index = MMI_CUBE_IMGVIEW_CURR_DECODE_NONE;
            //g_mmi_cube_imgview_cntx.curr_decode_mode = MMI_CUBE_IMGVIEW_MODE_UNKNOWN;
            gdi_layer_free(layer_handle);
            /* mmi_cube_imgview_decode_result_cb(0, ret, NULL); */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_decode_next_in_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cube_imgview_decode_next_in_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret, file_width, file_height, internal_index;
    srv_mediacache_img_to_layer_struct layer_info;
    gdi_handle layer_handle;
    void *mem_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    internal_index = mmi_cube_imgview_find_need_decode_in_queue();
    if (internal_index != MMI_CUBE_IMGVIEW_LAYER_INDEX_ERROR)
    {
        mmi_cube_imgview_get_file_size(
            g_mmi_cube_imgview_cntx.layers[internal_index].index,
            &file_width,
            &file_height,
            g_mmi_cube_imgview_cntx.curr_decode_mode);

        srv_mediacache_goto_index(
            g_mmi_cube_imgview_cntx.cache_handle,
            g_mmi_cube_imgview_cntx.layers[internal_index].index);

        if (g_mmi_cube_imgview_cntx.layers[internal_index].mode == MMI_CUBE_IMGVIEW_MODE_VIEW)
        {
            if (srv_mediacache_can_draw_curr(g_mmi_cube_imgview_cntx.cache_handle) == SRV_MEDIACACHE_OK_L1)
            {
                mem_addr = g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr2;
            }
            else
            {
                mem_addr = g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr;
            }
        }
        else
        {
            mem_addr = g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr;
        }

        gdi_layer_create_using_outside_memory(
            0,
            0,
            g_mmi_cube_imgview_cntx.layers[internal_index].real_width,
            g_mmi_cube_imgview_cntx.layers[internal_index].real_height,
            &layer_handle,
            mem_addr,
            g_mmi_cube_imgview_cntx.layers[internal_index].real_width * g_mmi_cube_imgview_cntx.layers[internal_index].real_height * 2);
        mmi_cube_imgview_init_layer_struct(
            &layer_info,
            layer_handle,
            g_mmi_cube_imgview_cntx.layers[internal_index].real_width,
            g_mmi_cube_imgview_cntx.layers[internal_index].real_height,
            file_width,
            file_height,
            internal_index);

        ret = srv_mediacache_get_curr_img_to_layer(g_mmi_cube_imgview_cntx.cache_handle, &layer_info);
        if (ret == SRV_MEDIACACHE_OK)
        {
            g_mmi_cube_imgview_cntx.curr_decode_index = g_mmi_cube_imgview_cntx.layers[internal_index].index;
            g_mmi_cube_imgview_cntx.curr_decode_mode = g_mmi_cube_imgview_cntx.layers[internal_index].mode;
            g_mmi_cube_imgview_cntx.layers[internal_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER;
            if (g_mmi_cube_imgview_cntx.layers[internal_index].mode == MMI_CUBE_IMGVIEW_MODE_VIEW)
            {
                g_mmi_cube_imgview_cntx.layers[internal_index].draw_source = srv_mediacache_can_draw_curr(g_mmi_cube_imgview_cntx.cache_handle);
            }
            gdi_layer_free(layer_handle);
            mmi_cube_imgview_decode_result_cb(0, 0, NULL);
        }
        else if (ret == SRV_MEDIACACHE_ERR_DECODING)
        {
            g_mmi_cube_imgview_cntx.layers[internal_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODING;
            g_mmi_cube_imgview_cntx.curr_decode_index = g_mmi_cube_imgview_cntx.layers[internal_index].index;
            g_mmi_cube_imgview_cntx.curr_decode_mode = g_mmi_cube_imgview_cntx.layers[internal_index].mode;
            gdi_layer_free(layer_handle);
        }
        else
        {
            g_mmi_cube_imgview_cntx.layers[internal_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR;
            g_mmi_cube_imgview_cntx.curr_decode_index = g_mmi_cube_imgview_cntx.layers[internal_index].index;
            g_mmi_cube_imgview_cntx.curr_decode_mode = g_mmi_cube_imgview_cntx.layers[internal_index].mode;
            gdi_layer_free(layer_handle);
            mmi_cube_imgview_decode_result_cb(0, ret, NULL);
        }
    }
    else if (g_mmi_cube_imgview_cntx.curr_decode_mode == MMI_CUBE_IMGVIEW_MODE_VIEW)
    {
        internal_index = mmi_cube_imgview_find_need_decode_in_queue_ext();
        if (internal_index != MMI_CUBE_IMGVIEW_LAYER_INDEX_ERROR)
        {
            mmi_cube_imgview_get_file_size(
                g_mmi_cube_imgview_cntx.layers[internal_index].index,
                &file_width,
                &file_height,
                g_mmi_cube_imgview_cntx.curr_decode_mode);

            srv_mediacache_goto_index(
                g_mmi_cube_imgview_cntx.cache_handle,
                g_mmi_cube_imgview_cntx.layers[internal_index].index);

            mem_addr = g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr2;

            gdi_layer_create_using_outside_memory(
                0,
                0,
                g_mmi_cube_imgview_cntx.layers[internal_index].real_width,
                g_mmi_cube_imgview_cntx.layers[internal_index].real_height,
                &layer_handle,
                mem_addr,
                g_mmi_cube_imgview_cntx.layers[internal_index].real_width * g_mmi_cube_imgview_cntx.layers[internal_index].real_height * 2);
            mmi_cube_imgview_init_layer_struct(
                &layer_info,
                layer_handle,
                g_mmi_cube_imgview_cntx.layers[internal_index].real_width,
                g_mmi_cube_imgview_cntx.layers[internal_index].real_height,
                file_width,
                file_height,
                internal_index);

            ret = srv_mediacache_get_curr_img_to_layer(g_mmi_cube_imgview_cntx.cache_handle, &layer_info);
            if (ret == SRV_MEDIACACHE_OK)
            {
                if (srv_mediacache_can_draw_curr(g_mmi_cube_imgview_cntx.cache_handle) == SRV_MEDIACACHE_OK_L1)
                {
                    g_mmi_cube_imgview_cntx.curr_decode_index = g_mmi_cube_imgview_cntx.layers[internal_index].index;
                    g_mmi_cube_imgview_cntx.curr_decode_mode = g_mmi_cube_imgview_cntx.layers[internal_index].mode;
                    g_mmi_cube_imgview_cntx.layers[internal_index].state =
                        MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER;
                    if (g_mmi_cube_imgview_cntx.layers[internal_index].mode == MMI_CUBE_IMGVIEW_MODE_VIEW)
                    {
                        g_mmi_cube_imgview_cntx.layers[internal_index].draw_source = srv_mediacache_can_draw_curr(g_mmi_cube_imgview_cntx.cache_handle);
                    }
                    gdi_layer_free(layer_handle);
                    mmi_cube_imgview_decode_result_cb(0, 0, NULL);
                }
                else
                {
                    g_mmi_cube_imgview_cntx.curr_decode_index = g_mmi_cube_imgview_cntx.layers[internal_index].index;
                    g_mmi_cube_imgview_cntx.curr_decode_mode = g_mmi_cube_imgview_cntx.layers[internal_index].mode;
                    gdi_layer_free(layer_handle);
                }
            }
            else if (ret == SRV_MEDIACACHE_ERR_DECODING)
            {
                /* g_mmi_cube_imgview_cntx.layers[internal_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODING; */
                g_mmi_cube_imgview_cntx.curr_decode_index = g_mmi_cube_imgview_cntx.layers[internal_index].index;
                g_mmi_cube_imgview_cntx.curr_decode_mode = g_mmi_cube_imgview_cntx.layers[internal_index].mode;
                gdi_layer_free(layer_handle);
            }
            else
            {
                g_mmi_cube_imgview_cntx.layers[internal_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR;
                g_mmi_cube_imgview_cntx.curr_decode_index = g_mmi_cube_imgview_cntx.layers[internal_index].index;
                g_mmi_cube_imgview_cntx.curr_decode_mode = g_mmi_cube_imgview_cntx.layers[internal_index].mode;
                gdi_layer_free(layer_handle);
                mmi_cube_imgview_decode_result_cb(0, ret, NULL);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_get_file_layer_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index               [IN]        
 *  target_width        [IN]        
 *  target_height       [IN]        
 *  mode                [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_cube_imgview_get_file_layer_memory(S32 index, S32 target_width, S32 target_height, S32 mode, PS32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_width, file_height;
    S32 real_offset_x, real_offset_y, real_width, real_height;
    srv_mediacache_img_to_layer_struct layer_info;
    gdi_handle layer_handle = GDI_LAYER_EMPTY_HANDLE, src_layer = GDI_LAYER_EMPTY_HANDLE;
    S32 ret = 0;
    S32 layer_index;
    S16 is_someone_decoding;
    S32 internal_index;
    void *mem_addr;
    S32 temp_mode = mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mode)
    {
        case MMI_CUBE_IMGVIEW_MODE_TURN_TO_BACK:
            temp_mode = MMI_CUBE_IMGVIEW_MODE_NAVIGATION;
            break;

        case MMI_CUBE_IMGVIEW_MODE_TURN_TO_FRONT:
            temp_mode = MMI_CUBE_IMGVIEW_MODE_VIEW;
            break;

        case MMI_CUBE_IMGVIEW_MODE_TURN_TO_BLUR:
            temp_mode = MMI_CUBE_IMGVIEW_MODE_VIEW;
            break;

        default:
            temp_mode = mode;
    }
    internal_index = mmi_cube_imgview_internal_index(index, temp_mode);

    if (internal_index != MMI_CUBE_IMGVIEW_CURR_DECODE_NONE)
    {
        *result = g_mmi_cube_imgview_cntx.layers[internal_index].state;

        if (g_mmi_cube_imgview_cntx.layers[internal_index].state == MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER)
        {
            if (temp_mode == MMI_CUBE_IMGVIEW_MODE_VIEW)
            {
                if (g_mmi_cube_imgview_cntx.layers[internal_index].draw_source == SRV_MEDIACACHE_OK_L2)
                {
                    return g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr;
                }
                else
                {
                    return g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr2;
                }
            }
            else
            {
                return g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr;
            }
        }
        else if (g_mmi_cube_imgview_cntx.layers[internal_index].state == MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODING)
        {
            return NULL;
        }
        else if (g_mmi_cube_imgview_cntx.layers[internal_index].state ==
                 MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_WAITING_FOR_DECODE)
        {
            return NULL;
        }
        else if (g_mmi_cube_imgview_cntx.layers[internal_index].state ==
                 MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR)
        {
            return NULL;
        }
        else if (g_mmi_cube_imgview_cntx.layers[internal_index].state ==
                 MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER_BUT_BLUR)
        {
            /* still need decodeing; */
        }
    }

    /* here means we need create the */
    mmi_cube_imgview_get_file_size(index, &file_width, &file_height, temp_mode);

    if (mode == MMI_CUBE_IMGVIEW_MODE_VIEW)
    {
        if (internal_index == MMI_CUBE_IMGVIEW_CURR_DECODE_NONE)
        {
            gdi_util_fit_box(
                GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                target_width,
                target_height,
                file_width,
                file_height,
                &real_offset_x,
                &real_offset_y,
                &real_width,
                &real_height);

            layer_index = mmi_cube_imgview_find_available_layer_index(mode);

            g_mmi_cube_imgview_cntx.layers[layer_index].is_using = MMI_TRUE;
            g_mmi_cube_imgview_cntx.layers[layer_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_WAITING_FOR_DECODE;
            g_mmi_cube_imgview_cntx.layers[layer_index].index = index;
            g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_x = real_offset_x;
            g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_y = real_offset_y;
            g_mmi_cube_imgview_cntx.layers[layer_index].real_width = real_width;
            g_mmi_cube_imgview_cntx.layers[layer_index].real_height = real_height;
            g_mmi_cube_imgview_cntx.layers[layer_index].memory_source = MMI_CUBE_IMGVIEW_MEMORY_SOURCE_UNKNOWN;
            g_mmi_cube_imgview_cntx.layers[layer_index].mode = mode;
        }
        else
        {
            layer_index = internal_index;
            real_width = g_mmi_cube_imgview_cntx.layers[layer_index].real_width;
            real_height = g_mmi_cube_imgview_cntx.layers[layer_index].real_height;
        }

        is_someone_decoding = mmi_cube_imgview_find_if_someone_is_decoding(mode);
        if (is_someone_decoding == MMI_CUBE_IMGVIEW_LAYER_INDEX_ERROR)
        {
            srv_mediacache_goto_index(g_mmi_cube_imgview_cntx.cache_handle, index);

            if (srv_mediacache_can_draw_curr(g_mmi_cube_imgview_cntx.cache_handle) == SRV_MEDIACACHE_OK_L1)
            {
                mem_addr = g_mmi_cube_imgview_cntx.layers[layer_index].mem_addr2;
            }
            else
            {
                mem_addr = g_mmi_cube_imgview_cntx.layers[layer_index].mem_addr;
            }
            gdi_layer_create_using_outside_memory(
                0,
                0,
                real_width,
                real_height,
                &layer_handle,
                mem_addr,
                real_width * real_height * 2);

            mmi_cube_imgview_init_layer_struct(
                &layer_info,
                layer_handle,
                real_width,
                real_height,
                file_width,
                file_height,
                layer_index);

            ret = srv_mediacache_get_curr_img_to_layer(g_mmi_cube_imgview_cntx.cache_handle, &layer_info);

            if (ret == SRV_MEDIACACHE_OK)
            {
                g_mmi_cube_imgview_cntx.curr_decode_index = index;
                g_mmi_cube_imgview_cntx.curr_decode_mode = mode;
                g_mmi_cube_imgview_cntx.layers[layer_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER;
                g_mmi_cube_imgview_cntx.layers[layer_index].draw_source = srv_mediacache_can_draw_curr(g_mmi_cube_imgview_cntx.cache_handle);
                gdi_layer_free(layer_handle);
                return mem_addr;
            }
            else if (ret == SRV_MEDIACACHE_ERR_DECODING)
            {
                g_mmi_cube_imgview_cntx.curr_decode_index = index;
                g_mmi_cube_imgview_cntx.curr_decode_mode = mode;
                gdi_layer_free(layer_handle);

                if (g_mmi_cube_imgview_cntx.layers[layer_index].state !=
                    MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER_BUT_BLUR)
                {
                    g_mmi_cube_imgview_cntx.layers[layer_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODING;
                }
                else
                {
                    return g_mmi_cube_imgview_cntx.layers[layer_index].mem_addr2;
                }
            }
            else
            {
                g_mmi_cube_imgview_cntx.layers[layer_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR;
                //g_mmi_cube_imgview_cntx.curr_decode_index = MMI_CUBE_IMGVIEW_CURR_DECODE_NONE;
                //g_mmi_cube_imgview_cntx.curr_decode_mode = MMI_CUBE_IMGVIEW_MODE_UNKNOWN;
                gdi_layer_free(layer_handle);

                mmi_cube_imgview_decode_result_cb(0, ret, NULL);
            }
        }
        else
        {
            if (g_mmi_cube_imgview_cntx.layers[layer_index].state ==
                MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER_BUT_BLUR)
            {
                return g_mmi_cube_imgview_cntx.layers[layer_index].mem_addr2;
            }
        }
    }
    else if (mode == MMI_CUBE_IMGVIEW_MODE_NAVIGATION)
    {
        S32 fit_method = GDI_UTIL_MODE_NO_RESIZE_OR_SHORT_SIDE_FIT;

        if (file_width > file_height)
        {
            if (file_width * MMI_CUBE_IMGVIEW_SMALL_IMGVIEW_DEFAULT_HEIGHT_RATE >
                file_height * MMI_CUBE_IMGVIEW_SMALL_IMGVIEW_DEFAULT_WIDTH_RATE)
            {
                fit_method = GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT;
            }
        }

        if (file_width < file_height)
        {
            if (file_height * MMI_CUBE_IMGVIEW_SMALL_IMGVIEW_DEFAULT_HEIGHT_RATE >
                file_width * MMI_CUBE_IMGVIEW_SMALL_IMGVIEW_DEFAULT_WIDTH_RATE)
            {
                fit_method = GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT;
            }
        }

        gdi_util_fit_box(
            fit_method,
            target_width,
            target_height,
            file_width,
            file_height,
            &real_offset_x,
            &real_offset_y,
            &real_width,
            &real_height);

        if (internal_index == MMI_CUBE_IMGVIEW_CURR_DECODE_NONE)
        {
            layer_index = mmi_cube_imgview_find_available_layer_index(mode);

            g_mmi_cube_imgview_cntx.layers[layer_index].is_using = MMI_TRUE;
            g_mmi_cube_imgview_cntx.layers[layer_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_WAITING_FOR_DECODE;
            g_mmi_cube_imgview_cntx.layers[layer_index].index = index;
            g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_x = real_offset_x;
            g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_y = real_offset_y;
            g_mmi_cube_imgview_cntx.layers[layer_index].real_width = real_width;
            g_mmi_cube_imgview_cntx.layers[layer_index].real_height = real_height;
            /* g_mmi_cube_imgview_cntx.layers[layer_index].handle = layer_handle; */
            g_mmi_cube_imgview_cntx.layers[layer_index].memory_source = MMI_CUBE_IMGVIEW_MEMORY_SOURCE_UNKNOWN;
            g_mmi_cube_imgview_cntx.layers[layer_index].mode = mode;
        }
        else
        {
            layer_index = internal_index;
        }

        is_someone_decoding = mmi_cube_imgview_find_if_someone_is_decoding(mode);
        if (is_someone_decoding == MMI_CUBE_IMGVIEW_LAYER_INDEX_ERROR)
        {
            gdi_layer_create_using_outside_memory(
                0,
                0,
                real_width,
                real_height,
                &layer_handle,
                g_mmi_cube_imgview_cntx.layers[layer_index].mem_addr,
                real_width * real_height * 2);

            srv_mediacache_goto_index(g_mmi_cube_imgview_cntx.cache_handle, index);
            mmi_cube_imgview_init_layer_struct(
                &layer_info,
                layer_handle,
                real_width,
                real_height,
                file_width,
                file_height,
                layer_index);

            ret = srv_mediacache_get_curr_img_to_layer(g_mmi_cube_imgview_cntx.cache_handle, &layer_info);
            if (ret == SRV_MEDIACACHE_OK)
            {
                g_mmi_cube_imgview_cntx.curr_decode_index = MMI_CUBE_IMGVIEW_CURR_DECODE_NONE;
                g_mmi_cube_imgview_cntx.layers[layer_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER;
                g_mmi_cube_imgview_cntx.curr_decode_mode = mode;
                g_mmi_cube_imgview_cntx.layers[layer_index].draw_source = srv_mediacache_can_draw_curr(g_mmi_cube_imgview_cntx.cache_handle);
                gdi_layer_free(layer_handle);
                return g_mmi_cube_imgview_cntx.layers[layer_index].mem_addr;
            }
            else if (ret == SRV_MEDIACACHE_ERR_DECODING)
            {
                g_mmi_cube_imgview_cntx.layers[layer_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODING;
                g_mmi_cube_imgview_cntx.curr_decode_index = index;
                g_mmi_cube_imgview_cntx.curr_decode_mode = mode;
                gdi_layer_free(layer_handle);
            }
            else
            {
                g_mmi_cube_imgview_cntx.layers[layer_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR;
                g_mmi_cube_imgview_cntx.curr_decode_index = index;
                g_mmi_cube_imgview_cntx.curr_decode_mode = mode;
                gdi_layer_free(layer_handle);
                mmi_cube_imgview_decode_result_cb(0, ret, NULL);
            }
        }
    }
    else if (mode == MMI_CUBE_IMGVIEW_MODE_TURN_TO_BACK)
    {
        if (internal_index == MMI_CUBE_IMGVIEW_CURR_DECODE_NONE)
        {
            S32 fit_method = GDI_UTIL_MODE_NO_RESIZE_OR_SHORT_SIDE_FIT;

            if (file_width > file_height)
            {
                if (file_width * MMI_CUBE_IMGVIEW_SMALL_IMGVIEW_DEFAULT_HEIGHT_RATE >
                    file_height * MMI_CUBE_IMGVIEW_SMALL_IMGVIEW_DEFAULT_WIDTH_RATE)
                {
                    fit_method = GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT;
                }
            }

            if (file_width < file_height)
            {
                if (file_height * MMI_CUBE_IMGVIEW_SMALL_IMGVIEW_DEFAULT_HEIGHT_RATE >
                    file_width * MMI_CUBE_IMGVIEW_SMALL_IMGVIEW_DEFAULT_WIDTH_RATE)
                {
                    fit_method = GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT;
                }
            }

            gdi_util_fit_box(
                fit_method,
                target_width,
                target_height,
                file_width,
                file_height,
                &real_offset_x,
                &real_offset_y,
                &real_width,
                &real_height);

            if (internal_index == MMI_CUBE_IMGVIEW_CURR_DECODE_NONE)
            {
                layer_index = mmi_cube_imgview_find_available_layer_index(MMI_CUBE_IMGVIEW_MODE_NAVIGATION);

                g_mmi_cube_imgview_cntx.layers[layer_index].is_using = MMI_TRUE;
                g_mmi_cube_imgview_cntx.layers[layer_index].state =
                    MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_WAITING_FOR_DECODE;
                g_mmi_cube_imgview_cntx.layers[layer_index].index = index;
                g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_x = real_offset_x;
                g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_y = real_offset_y;
                g_mmi_cube_imgview_cntx.layers[layer_index].real_width = real_width;
                g_mmi_cube_imgview_cntx.layers[layer_index].real_height = real_height;
                /* g_mmi_cube_imgview_cntx.layers[layer_index].handle = layer_handle; */
                g_mmi_cube_imgview_cntx.layers[layer_index].memory_source = MMI_CUBE_IMGVIEW_MEMORY_SOURCE_UNKNOWN;
                g_mmi_cube_imgview_cntx.layers[layer_index].mode = MMI_CUBE_IMGVIEW_MODE_NAVIGATION;
            }
            else
            {
                layer_index = internal_index;
            }
        }
    }
    else if (mode == MMI_CUBE_IMGVIEW_MODE_TURN_TO_FRONT)
    {
        if (internal_index == MMI_CUBE_IMGVIEW_CURR_DECODE_NONE)
        {
            gdi_util_fit_box(
                GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                target_width,
                target_height,
                file_width,
                file_height,
                &real_offset_x,
                &real_offset_y,
                &real_width,
                &real_height);

            layer_index = mmi_cube_imgview_find_available_layer_index(MMI_CUBE_IMGVIEW_MODE_VIEW);

            g_mmi_cube_imgview_cntx.layers[layer_index].is_using = MMI_TRUE;
            g_mmi_cube_imgview_cntx.layers[layer_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_WAITING_FOR_DECODE;
            g_mmi_cube_imgview_cntx.layers[layer_index].index = index;
            g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_x = real_offset_x;
            g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_y = real_offset_y;
            g_mmi_cube_imgview_cntx.layers[layer_index].real_width = real_width;
            g_mmi_cube_imgview_cntx.layers[layer_index].real_height = real_height;
            g_mmi_cube_imgview_cntx.layers[layer_index].memory_source = MMI_CUBE_IMGVIEW_MEMORY_SOURCE_UNKNOWN;
            g_mmi_cube_imgview_cntx.layers[layer_index].mode = MMI_CUBE_IMGVIEW_MODE_VIEW;
        }
        else
        {
            layer_index = internal_index;
        }
    }
    else if (mode == MMI_CUBE_IMGVIEW_MODE_TURN_TO_BLUR)
    {
        internal_index = mmi_cube_imgview_internal_index(index, MMI_CUBE_IMGVIEW_MODE_NAVIGATION);

        if (internal_index != MMI_CUBE_IMGVIEW_CURR_DECODE_NONE)
        {
            S32 internal_index_of_view_mode;

            internal_index_of_view_mode = mmi_cube_imgview_internal_index(index, MMI_CUBE_IMGVIEW_MODE_VIEW);
            if (internal_index_of_view_mode == MMI_CUBE_IMGVIEW_CURR_DECODE_NONE)
            {
                gdi_util_fit_box(
                    GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                    target_width,
                    target_height,
                    file_width,
                    file_height,
                    &real_offset_x,
                    &real_offset_y,
                    &real_width,
                    &real_height);

                layer_index = mmi_cube_imgview_find_available_layer_index(MMI_CUBE_IMGVIEW_MODE_VIEW);

                g_mmi_cube_imgview_cntx.layers[layer_index].is_using = MMI_TRUE;
                g_mmi_cube_imgview_cntx.layers[layer_index].state =
                    MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER_BUT_BLUR;
                g_mmi_cube_imgview_cntx.layers[layer_index].index = index;
                g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_x = real_offset_x;
                g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_y = real_offset_y;
                g_mmi_cube_imgview_cntx.layers[layer_index].real_width = real_width;
                g_mmi_cube_imgview_cntx.layers[layer_index].real_height = real_height;
                g_mmi_cube_imgview_cntx.layers[layer_index].memory_source = MMI_CUBE_IMGVIEW_MEMORY_SOURCE_UNKNOWN;
                g_mmi_cube_imgview_cntx.layers[layer_index].mode = MMI_CUBE_IMGVIEW_MODE_VIEW;
            }
            else
            {
                layer_index = internal_index_of_view_mode;
                real_width = g_mmi_cube_imgview_cntx.layers[internal_index_of_view_mode].real_width;;
                real_height = g_mmi_cube_imgview_cntx.layers[internal_index_of_view_mode].real_height;
            }

            if (g_mmi_cube_imgview_cntx.layers[internal_index].state == MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER)
            {
                gdi_layer_create_using_outside_memory(
                    0,
                    0,
                    real_width,
                    real_height,
                    &layer_handle,
                    g_mmi_cube_imgview_cntx.layers[layer_index].mem_addr2,
                    real_width * real_height * 2);

                gdi_layer_create_using_outside_memory(
                    0,
                    0,
                    g_mmi_cube_imgview_cntx.layers[internal_index].real_width,
                    g_mmi_cube_imgview_cntx.layers[internal_index].real_height,
                    &src_layer,
                    g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr,
                    g_mmi_cube_imgview_cntx.layers[internal_index].real_width * g_mmi_cube_imgview_cntx.layers[internal_index].real_height * 2);

                gdi_layer_push_and_set_active(layer_handle);
                gdi_bitblt_resized(
                    src_layer,
                    0,
                    0,
                    g_mmi_cube_imgview_cntx.layers[internal_index].real_width - 1,
                    g_mmi_cube_imgview_cntx.layers[internal_index].real_height - 1,
                    0,
                    0,
                    real_width - 1,
                    real_height - 1);
                gdi_layer_pop_and_restore_active();

                gdi_layer_free(layer_handle);

                gdi_layer_free(src_layer);
                return g_mmi_cube_imgview_cntx.layers[layer_index].mem_addr2;
            }
        }
    }
    else
    {
        MMI_ASSERT(0);
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_find_internal_layer_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_index      [IN]        
 *  mode            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_cube_imgview_find_internal_layer_index(S32 file_index, S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VAPP_CUBE_IMGVIEW_LAYER_COUNT; i++)
    {
        if (file_index == g_mmi_cube_imgview_cntx.layers[i].index)
        {
            if (g_mmi_cube_imgview_cntx.layers[i].is_using)
            {
                if (g_mmi_cube_imgview_cntx.layers[i].mode == mode)
                {
                    return i;
                }
            }
            else
            {
                MMI_ASSERT(0);
                /* //TODO find the layer, but the layer is not used yet */
            }
        }
    }

    return MMI_CUBE_IMGVIEW_LAYER_INDEX_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_free_file_layer_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_free_file_layer_memory(S32 index, S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    layer_index = mmi_cube_imgview_find_internal_layer_index(index, mode);
    if (layer_index == MMI_CUBE_IMGVIEW_LAYER_INDEX_ERROR)
    {
        return;
    }
    else
    {
        /* gdi_layer_free(g_mmi_cube_imgview_cntx.layers[layer_index].handle); */
        g_mmi_cube_imgview_cntx.layers[layer_index].is_using = MMI_FALSE;
        g_mmi_cube_imgview_cntx.layers[layer_index].index = -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_get_file_layer_real_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  offset_x        [IN]        
 *  offset_y        [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  mode            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_get_file_layer_real_size(
        S32 index,
        PS32 offset_x,
        PS32 offset_y,
        PS32 width,
        PS32 height,
        S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    layer_index = mmi_cube_imgview_find_internal_layer_index(index, mode);

    if (layer_index != MMI_CUBE_IMGVIEW_LAYER_INDEX_ERROR)
    {
        *offset_x = g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_x;
        *offset_y = g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_y;
        *width = g_mmi_cube_imgview_cntx.layers[layer_index].real_width;
        *height = g_mmi_cube_imgview_cntx.layers[layer_index].real_height;
    }
    else
    {
        *offset_x = -1;
        *offset_y = -1;
        *width = -1;
        *height = -1;
    }
}

S32 total_memory_size = 0;


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_malloc_cache_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_malloc_cache_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_memory_size = 0;

    g_mmi_cube_imgview_cntx.cache_run_buffer_size = SRV_MEDIACACHE_RUN_BUF_SIZE(MMI_VAPP_CUBE_IMGVIEW_LAYER_COUNT);
    media_get_ext_buffer_framebuffer(
        stack_int_get_active_module_id(),
        &(g_mmi_cube_imgview_cntx.cache_run_buffer),
        g_mmi_cube_imgview_cntx.cache_run_buffer_size);
    total_memory_size += g_mmi_cube_imgview_cntx.cache_run_buffer_size;

    g_mmi_cube_imgview_cntx.cache_db_buffer_size = SRV_MEDIACACHE_SQLITE_DB_BUF_SIZE_DEFAULT;
    media_get_ext_buffer_framebuffer(
        stack_int_get_active_module_id(),
        &(g_mmi_cube_imgview_cntx.cache_db_buffer),
        g_mmi_cube_imgview_cntx.cache_db_buffer_size);
    total_memory_size += g_mmi_cube_imgview_cntx.cache_db_buffer_size;

    /* g_mmi_cube_imgview_cntx.cache_small_buffer = mmi_frm_scrmem_alloc_framebuffer(240*320); */
    g_mmi_cube_imgview_cntx.cache_small_buffer_size = MMI_VAPP_CUBE_IMGVIEW_SMALL_CELL_MEM_IN_CACHE_SRV;
    media_get_ext_buffer_framebuffer(
        stack_int_get_active_module_id(),
        &(g_mmi_cube_imgview_cntx.cache_small_buffer),
        g_mmi_cube_imgview_cntx.cache_small_buffer_size);
    total_memory_size += g_mmi_cube_imgview_cntx.cache_small_buffer_size;

    g_mmi_cube_imgview_cntx.cache_large_buffer_size = MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_MEM_IN_CACHE_SRV;
    media_get_ext_buffer_framebuffer(
        stack_int_get_active_module_id(),
        &(g_mmi_cube_imgview_cntx.cache_large_buffer),
        g_mmi_cube_imgview_cntx.cache_large_buffer_size);
    total_memory_size += g_mmi_cube_imgview_cntx.cache_large_buffer_size;

    for (i = 0; i < MMI_VAPP_CUBE_IMGVIEW_LAYER_COUNT; i++)
    {
        if (i < MMI_VAPP_CUBE_IMGVIEW_NAVIGATION_LAYER_COUNT)
        {
            g_mmi_cube_imgview_cntx.layers[i].is_using = MMI_FALSE;
            /* g_mmi_cube_imgview_cntx.layers[i].mem_addr = g_stati_memory[i]; */
            media_get_ext_buffer_framebuffer(
                stack_int_get_active_module_id(),
                &(g_mmi_cube_imgview_cntx.layers[i].mem_addr),
                MMI_VAPP_CUBE_IMGVIEW_SMALL_CELL_MEM_ONE);
            total_memory_size += MMI_VAPP_CUBE_IMGVIEW_SMALL_CELL_MEM_ONE;

            /* g_mmi_cube_imgview_cntx.layers[i].mem_addr = g_mmi_cube_imgview_cntx.layers[i].mem_addr; */
            g_mmi_cube_imgview_cntx.layers[i].mem_addr2 = 0;
            g_mmi_cube_imgview_cntx.layers[i].index = -1;
            g_mmi_cube_imgview_cntx.layers[i].memory_source = MMI_CUBE_IMGVIEW_MEMORY_SOURCE_UNKNOWN;
            g_mmi_cube_imgview_cntx.layers[i].mode = MMI_CUBE_IMGVIEW_MODE_UNKNOWN;
        }
        else
        {
            g_mmi_cube_imgview_cntx.layers[i].is_using = MMI_FALSE;
            /* g_mmi_cube_imgview_cntx.layers[i].mem_addr = g_stati_memory2[i - MMI_VAPP_CUBE_IMGVIEW_NAVIGATION_LAYER_COUNT]; */
            media_get_ext_buffer_framebuffer(
                stack_int_get_active_module_id(),
                &(g_mmi_cube_imgview_cntx.layers[i].mem_addr),
                MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_MEM_ONE);
            total_memory_size += MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_MEM_ONE;

            media_get_ext_buffer_framebuffer(
                stack_int_get_active_module_id(),
                &(g_mmi_cube_imgview_cntx.layers[i].mem_addr2),
                MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_MEM_ONE);
            total_memory_size += MMI_VAPP_CUBE_IMGVIEW_BIG_CELL_MEM_ONE;

            g_mmi_cube_imgview_cntx.layers[i].index = -1;
            g_mmi_cube_imgview_cntx.layers[i].memory_source = MMI_CUBE_IMGVIEW_MEMORY_SOURCE_UNKNOWN;
            g_mmi_cube_imgview_cntx.layers[i].mode = MMI_CUBE_IMGVIEW_MODE_UNKNOWN;
        }

        //g_mmi_cube_imgview_cntx.layers[14].mem_addr = 0;
        //g_mmi_cube_imgview_cntx.layers[14].mem_addr2 = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_free_cache_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_free_cache_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cube_imgview_cntx.cache_run_buffer)
    {
        media_free_ext_buffer(stack_int_get_active_module_id(), &(g_mmi_cube_imgview_cntx.cache_run_buffer));
        g_mmi_cube_imgview_cntx.cache_run_buffer = NULL;
    }

    if (g_mmi_cube_imgview_cntx.cache_db_buffer)
    {
        media_free_ext_buffer(stack_int_get_active_module_id(), &(g_mmi_cube_imgview_cntx.cache_db_buffer));
        g_mmi_cube_imgview_cntx.cache_db_buffer = NULL;
    }

    if (g_mmi_cube_imgview_cntx.cache_large_buffer)
    {
        media_free_ext_buffer(stack_int_get_active_module_id(), &(g_mmi_cube_imgview_cntx.cache_large_buffer));
        g_mmi_cube_imgview_cntx.cache_large_buffer = NULL;
    }

    if (g_mmi_cube_imgview_cntx.cache_small_buffer)
    {
        media_free_ext_buffer(stack_int_get_active_module_id(), &(g_mmi_cube_imgview_cntx.cache_small_buffer));
        /* mmi_frm_scrmem_free(g_mmi_cube_imgview_cntx.cache_small_buffer); */
        g_mmi_cube_imgview_cntx.cache_small_buffer = NULL;
    }

    for (i = 0; i < MMI_VAPP_CUBE_IMGVIEW_LAYER_COUNT; i++)
    {
        if (i < MMI_VAPP_CUBE_IMGVIEW_NAVIGATION_LAYER_COUNT)
        {
            media_free_ext_buffer(stack_int_get_active_module_id(), &(g_mmi_cube_imgview_cntx.layers[i].mem_addr));
            g_mmi_cube_imgview_cntx.layers[i].mem_addr = 0;
            g_mmi_cube_imgview_cntx.layers[i].mem_addr2 = 0;
        }
        else
        {
            if (1)  /* (i < 14) */
            {
                media_free_ext_buffer(stack_int_get_active_module_id(), &(g_mmi_cube_imgview_cntx.layers[i].mem_addr));
                media_free_ext_buffer(stack_int_get_active_module_id(), &(g_mmi_cube_imgview_cntx.layers[i].mem_addr2));
                g_mmi_cube_imgview_cntx.layers[i].mem_addr = 0;
                g_mmi_cube_imgview_cntx.layers[i].mem_addr2 = 0;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_create_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_create_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_malloc_cache_buffer();

    g_mmi_cube_imgview_cntx.cache_handle = srv_mediacache_create(g_mmi_cube_imgview_cntx.cache_run_buffer, g_mmi_cube_imgview_cntx.cache_run_buffer_size);
    srv_mediacache_config_work_mode_to_filelist(g_mmi_cube_imgview_cntx.cache_handle, g_mmi_cube_imgview_cntx.fl);
    srv_mediacache_config_database(
        g_mmi_cube_imgview_cntx.cache_handle,
        g_mmi_cube_imgview_cntx.cache_db_buffer,
        g_mmi_cube_imgview_cntx.cache_db_buffer_size,
        NULL);
    /* srv_mediacache_config_level2_size(g_mmi_cube_imgview_cntx.cache_handle, g_mmi_cube_imgview_cntx.cache_small_image_width, g_mmi_cube_imgview_cntx.cache_small_image_height); */
    srv_mediacache_add_cache(
        g_mmi_cube_imgview_cntx.cache_handle,
        SRV_MEDIACACHE_CACHE_TYPE_L2,
        g_mmi_cube_imgview_cntx.cache_small_buffer,
        g_mmi_cube_imgview_cntx.cache_small_buffer_size);
    srv_mediacache_add_cache(
        g_mmi_cube_imgview_cntx.cache_handle,
        SRV_MEDIACACHE_CACHE_TYPE_L2,
        g_mmi_cube_imgview_cntx.cache_large_buffer,
        g_mmi_cube_imgview_cntx.cache_large_buffer_size);
    srv_mediacache_start(g_mmi_cube_imgview_cntx.cache_handle, g_mmi_cube_imgview_cntx.cache_focus_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_close_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_close_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cube_imgview_cntx.cache_handle)
    {
        srv_mediacache_stop(g_mmi_cube_imgview_cntx.cache_handle);
        if (g_mmi_cube_imgview_cntx.cache_small_buffer)
        {
            srv_mediacache_remove_cache(
                g_mmi_cube_imgview_cntx.cache_handle,
                g_mmi_cube_imgview_cntx.cache_small_buffer);
        }
        if (g_mmi_cube_imgview_cntx.cache_large_buffer)
        {
            srv_mediacache_remove_cache(
                g_mmi_cube_imgview_cntx.cache_handle,
                g_mmi_cube_imgview_cntx.cache_large_buffer);
        }
        srv_mediacache_destroy(g_mmi_cube_imgview_cntx.cache_handle);
        g_mmi_cube_imgview_cntx.cache_handle = 0;
    }

    mmi_cube_imgview_free_cache_buffer();
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_init_view_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cube_imgview_init_view_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MMI_VAPP_CUBE_IMGVIEW_NAVIGATION_LAYER_COUNT; i < MMI_VAPP_CUBE_IMGVIEW_LAYER_COUNT; i++)
    {
        g_mmi_cube_imgview_cntx.layers[i].is_using = MMI_FALSE;
        g_mmi_cube_imgview_cntx.layers[i].index = -1;
        g_mmi_cube_imgview_cntx.layers[i].memory_source = MMI_CUBE_IMGVIEW_MEMORY_SOURCE_UNKNOWN;
        g_mmi_cube_imgview_cntx.layers[i].mode = MMI_CUBE_IMGVIEW_MODE_UNKNOWN;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_change_to_navigation_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_change_to_navigation_mode(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* srv_mediacache_remove_cache(g_mmi_cube_imgview_cntx.cache_handle, g_mmi_cube_imgview_cntx.cache_small_buffer); */
    srv_mediacache_stop(g_mmi_cube_imgview_cntx.cache_handle);
    srv_mediacache_remove_cache(g_mmi_cube_imgview_cntx.cache_handle, g_mmi_cube_imgview_cntx.cache_large_buffer);
    srv_mediacache_add_cache(
        g_mmi_cube_imgview_cntx.cache_handle,
        SRV_MEDIACACHE_CACHE_TYPE_L2,
        g_mmi_cube_imgview_cntx.cache_large_buffer,
        g_mmi_cube_imgview_cntx.cache_large_buffer_size);
    srv_mediacache_start(g_mmi_cube_imgview_cntx.cache_handle, index);  /* g_mmi_cube_imgview_cntx.cache_focus_index); */

    mmi_cube_imgview_resume_navigation_mode_decode();

    mmi_cube_imgview_init_view_mode();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_change_to_view_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_change_to_view_mode(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mediacache_stop(g_mmi_cube_imgview_cntx.cache_handle);
    srv_mediacache_remove_cache(g_mmi_cube_imgview_cntx.cache_handle, g_mmi_cube_imgview_cntx.cache_large_buffer);
    srv_mediacache_add_cache(
        g_mmi_cube_imgview_cntx.cache_handle,
        SRV_MEDIACACHE_CACHE_TYPE_L1,
        g_mmi_cube_imgview_cntx.cache_large_buffer,
        g_mmi_cube_imgview_cntx.cache_large_buffer_size);
    srv_mediacache_start(g_mmi_cube_imgview_cntx.cache_handle, index);

    mmi_cube_imgview_pause_navigation_mode_decode();
    /* srv_mediacache_add_cache(g_mmi_cube_imgview_cntx.cache_handle, SRV_MEDIACACHE_CACHE_TYPE_L1, g_mmi_cube_imgview_cntx.cache_small_buffer, g_mmi_cube_imgview_cntx.cache_small_buffer_size); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_focus_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_focus_change(S32 index, S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_width, file_height;
    srv_mediacache_img_to_layer_struct layer_info;
    S32 ret = 0;
    S32 internal_index;
    S16 is_someone_decoding;
    S32 real_offset_x, real_offset_y, real_width, real_height;
    S32 layer_index;
    S32 target_width, target_height;
    gdi_handle layer_handle;
    void *mem_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cube_imgview_cntx.cache_handle == 0)
    {
        return;
    }

    internal_index = mmi_cube_imgview_internal_index(index, mode);

    mmi_cube_imgview_get_file_size(index, &file_width, &file_height, mode);

    if (internal_index == MMI_CUBE_IMGVIEW_CURR_DECODE_NONE)
    {
        mmi_cube_get_target_width_height(index, mode, &target_width, &target_height);
        gdi_util_fit_box(
            GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
            target_width,
            target_height,
            file_width,
            file_height,
            &real_offset_x,
            &real_offset_y,
            &real_width,
            &real_height);

        layer_index = mmi_cube_imgview_find_available_layer_index(mode);
        gdi_layer_create_using_outside_memory(
            0,
            0,
            real_width,
            real_height,
            &layer_handle,
            g_mmi_cube_imgview_cntx.layers[layer_index].mem_addr,
            real_width * real_height * 2);

        g_mmi_cube_imgview_cntx.layers[layer_index].is_using = MMI_TRUE;
        g_mmi_cube_imgview_cntx.layers[layer_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_WAITING_FOR_DECODE;
        g_mmi_cube_imgview_cntx.layers[layer_index].index = index;
        g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_x = real_offset_x;
        g_mmi_cube_imgview_cntx.layers[layer_index].real_offset_y = real_offset_y;
        g_mmi_cube_imgview_cntx.layers[layer_index].real_width = real_width;
        g_mmi_cube_imgview_cntx.layers[layer_index].real_height = real_height;
        /* g_mmi_cube_imgview_cntx.layers[layer_index].handle = layer_handle; */
        g_mmi_cube_imgview_cntx.layers[layer_index].memory_source = MMI_CUBE_IMGVIEW_MEMORY_SOURCE_UNKNOWN;
        g_mmi_cube_imgview_cntx.layers[layer_index].mode = mode;

        internal_index = layer_index;
    }
    else
    {
        gdi_layer_create_using_outside_memory(
            0,
            0,
            g_mmi_cube_imgview_cntx.layers[internal_index].real_width,
            g_mmi_cube_imgview_cntx.layers[internal_index].real_height,
            &layer_handle,
            g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr,
            g_mmi_cube_imgview_cntx.layers[internal_index].real_width * g_mmi_cube_imgview_cntx.layers[internal_index].real_height * 2);
    }

    srv_mediacache_goto_index(g_mmi_cube_imgview_cntx.cache_handle, index);

    if (g_mmi_cube_imgview_cntx.layers[internal_index].mode == MMI_CUBE_IMGVIEW_MODE_VIEW)
    {
        if (srv_mediacache_can_draw_curr(g_mmi_cube_imgview_cntx.cache_handle) == SRV_MEDIACACHE_OK_L1)
        {
            mem_addr = g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr2;
        }
        else
        {
            mem_addr = g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr;
        }
    }
    else
    {
        mem_addr = g_mmi_cube_imgview_cntx.layers[internal_index].mem_addr;
    }

    mmi_cube_imgview_init_layer_struct(
        &layer_info,
        layer_handle,
        g_mmi_cube_imgview_cntx.layers[internal_index].real_width,
        g_mmi_cube_imgview_cntx.layers[internal_index].real_height,
        file_width,
        file_height,
        internal_index);

    is_someone_decoding = mmi_cube_imgview_find_if_someone_is_decoding(mode);
    if (is_someone_decoding != MMI_CUBE_IMGVIEW_LAYER_INDEX_ERROR)
    {
        g_mmi_cube_imgview_cntx.layers[is_someone_decoding].state =
            MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_WAITING_FOR_DECODE;
    }

    ret = srv_mediacache_get_curr_img_to_layer(g_mmi_cube_imgview_cntx.cache_handle, &layer_info);

    if (ret == SRV_MEDIACACHE_OK)
    {
        g_mmi_cube_imgview_cntx.curr_decode_index = index;
        g_mmi_cube_imgview_cntx.curr_decode_mode = mode;
        g_mmi_cube_imgview_cntx.layers[internal_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER;
        gdi_layer_free(layer_handle);

        if (g_mmi_cube_imgview_cntx.layers[internal_index].mode == MMI_CUBE_IMGVIEW_MODE_VIEW)
        {
            g_mmi_cube_imgview_cntx.layers[internal_index].draw_source = srv_mediacache_can_draw_curr(g_mmi_cube_imgview_cntx.cache_handle);
        }
        mmi_cube_imgview_decode_result_cb(0, 0, NULL);
    }
    else if (ret == SRV_MEDIACACHE_ERR_DECODING)
    {
        g_mmi_cube_imgview_cntx.layers[internal_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODING;
        g_mmi_cube_imgview_cntx.curr_decode_index = index;
        g_mmi_cube_imgview_cntx.curr_decode_mode = mode;
        gdi_layer_free(layer_handle);
    }
    else
    {
        g_mmi_cube_imgview_cntx.layers[internal_index].state = MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR;
        //g_mmi_cube_imgview_cntx.curr_decode_index = MMI_CUBE_IMGVIEW_CURR_DECODE_NONE;
        //g_mmi_cube_imgview_cntx.curr_decode_mode = MMI_CUBE_IMGVIEW_MODE_UNKNOWN;
        gdi_layer_free(layer_handle);
        mmi_cube_imgview_decode_result_cb(0, ret, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_pause_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_pause_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cube_imgview_cntx.cache_handle)
    {
        srv_mediacache_pause_decode(g_mmi_cube_imgview_cntx.cache_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_resume_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_resume_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cube_imgview_cntx.cache_handle)
    {
        srv_mediacache_resume_decode(g_mmi_cube_imgview_cntx.cache_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_pause_navigation_mode_decode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_pause_navigation_mode_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_cube_imgview_cntx.is_small_image_dec_pause = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_resume_navigation_mode_decode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_resume_navigation_mode_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_cube_imgview_cntx.is_small_image_dec_pause = MMI_FALSE;
    g_mmi_cube_imgview_cntx.curr_decode_mode = MMI_CUBE_IMGVIEW_MODE_NAVIGATION;
    StartTimer(KEY_VOL_TIMER_ID, 1, mmi_cube_imgview_decode_next_in_queue);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_get_forbid_item_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_cube_imgview_get_forbid_item_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID string_id = 0;
    mmi_event_notify_enum event_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        string_id = mmi_usb_get_error_info(MMI_USB_ERR_IS_UNAVAILABLE, &event_type);

        return string_id;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 


    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_get_target_width_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  mode        [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_get_target_width_height(S32 index, S32 mode, PS32 width, PS32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_p2v_cube_vapp_imgview_get_target_width_height(index, mode, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_set_small_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_width         [IN]        
 *  image_height        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_set_small_image(S32 image_width, S32 image_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_cube_imgview_cntx.cache_small_image_width = image_width;
    g_mmi_cube_imgview_cntx.cache_small_image_height = image_height;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_set_large_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_width         [IN]        
 *  image_height        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_set_large_image(S32 image_width, S32 image_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_cube_imgview_cntx.cache_large_image_width = image_width;
    g_mmi_cube_imgview_cntx.cache_large_image_height = image_height;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_register_decode_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [?]         
 *  cb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_register_decode_cb(void *user_data, mmi_cube_imgview_file_decode_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_cube_imgview_cntx.decode_user_data = user_data;
    g_mmi_cube_imgview_cntx.decode_cb = cb;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_imgview_get_layer_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_imgview_get_layer_info(gdi_handle handle, PS32 width, PS32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(0);
}

#endif /* __MMI_VUI_3D_CUBE_APP_IMGVIEW__ */ 

