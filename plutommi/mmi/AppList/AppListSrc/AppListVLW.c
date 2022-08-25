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
 *  AppListVLW.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AppList VLW
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
#include "AppListVLW.h"


#if defined(__MMI_LAUNCHER_APP_LIST__)

#include "MMIDataType.h"
#include "CustThemesRes.h"
#include "fs_type.h"
#include "Drm_gprot.h"  /* DRM check */
#include "SettingGprots.h"
#include "gdi_const.h"
#include "gdi_include.h"
#include "gdi_datatype.h"
#include "gui_themes.h"
#include "drm_def.h"
#include "fs_errcode.h"
#include "GlobalResDef.h"
#include "drm_errcode.h"
#include "mdi_include.h"
#include "mdi_video.h"
#include "mdi_audio.h"
#include "wgui_categories_util.h"
#include "ViewSettingCommonProt.h"
#include "med_utility.h"
#include "PhoneSetupResList.h"   /*For default image resource*/
#include "hal_custom_video_codec_if.h" 


static mmi_applist_vlw_context_struct g_mmi_applist_vlw_cntx;
mmi_applist_vlw_context_struct *vlw_p = &g_mmi_applist_vlw_cntx;

#ifdef __DRM_SUPPORT__
static S32 drm_consumer;
#endif

static gdi_handle layer_handle;
static mmi_applist_wallpaper_type_enum wallpaper_tpe;
static gdi_handle gui_animation_handle;

/*For gif pause/Resume use*/
#ifdef __MMI_APPLIST_SUPPORT_GIF_WALLPAPER__
typedef enum
{
    anim_open,
    anim_play,
    anim_pause,
} anim_wallpaper_play_state_type_enum;

static anim_wallpaper_play_state_type_enum anim_state;
#endif


#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__

typedef void (*video_close_func)(void);

/*Video wallpaper play struct*/
typedef struct
{
    mdi_video_info_struct  videoInfo;    
    U64                    start_play_time;
    video_close_func       close_func;
    int                    originalCodecPlaybackMode;
    U32                    blt_layer_flag;
    U32                    play_layer_flag;
    U32                    play_repeat_count;
} mmi_applist_video_wallpaper_struct;

static mmi_applist_video_wallpaper_struct video_wallpaper_struct;

/*Video wallpaper play state*/
typedef enum
{
    vlw_init,
    vlw_open,
    vlw_play,
    vlw_pause,
    vlw_stop,
} video_wallpaper_play_state_type_enum;

static video_wallpaper_play_state_type_enum vlw_play_state;

/*For video wallpapaer test in Modis*/
#ifdef VIDEO_WALLPAPER_TEST
#define VIDEO_WALLPAPER_DRIVER    'E'
#define VIDEO_WALLPAPER_PATH      "wallpaper"
#define VIDEO_WALLPAPER_FILE      "system"
#define VIDEO_WALLPAPER_FILE_EXT  "3gp"
#endif

extern S32 is_vlw_file;

#endif


#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__

//#define IVLW_TEST
#define MAX_PARTITION_COUNT 51
#define IVLW_STATE_SCALE  100
#define MAX_VIDEO_HEADER_LEN    50
#define ANIM_TIMER_DELAY   40

#ifdef IVLW_TEST
#define IVLW_DRIVER    'E'
#define IVLW_PATH      "@wallpaper_mwp"
#define IVLW_FILE      "New York"
#define IVLW_FILE_EXT  "mwp"
#endif

/*Interactive Video wallpaper play state*/
typedef enum
{
    ivlw_init,
    ivlw_open,
    ivlw_play,
    ivlw_pause,
    ivlw_stop,
} interactive_video_wallpaper_play_state_type_enum;

typedef struct
{
    APP_LIST_WP_DECODER_HANDLE *fileHandler;
    S32 partition_count;
    S32 image_frame_count;
    S32 partition_count_frame_num[MAX_PARTITION_COUNT];
    S32 partition_start_ptr[MAX_PARTITION_COUNT];
    S32 frame_header_len;
    S32 currentPartition;
    S32 currentFramePtr;
    S32 sourceBufferSize;
    U8  *sourceBuffer;
    STFSAL  m_fsal;
    interactive_video_wallpaper_play_state_type_enum play_state;
}mmi_applist_interactive_video_wallpaper_struct;

static mmi_applist_interactive_video_wallpaper_struct IVLW_Play_Struct;

/*Following is extern IVLE Decorder Function*/
extern APP_LIST_WP_DEC_STATUS
applistwallpaperDecSetAllocAndFree(
   APP_LIST_WP_DECODER_HANDLE* handle,
   alloc_func alloc_func,
   free_func free_func);

extern APP_LIST_WP_DEC_STATUS
applistwallpaperDecQuerySrcResolution(
   APP_LIST_WP_DECODER_HANDLE* handle,
   unsigned int* width,
   unsigned int* height);

extern APP_LIST_WP_DEC_STATUS
applistwallpaperDecQuerySrcFormat(
   APP_LIST_WP_DECODER_HANDLE* handle,
   APP_LIST_WP_COLOR_FORMAT *colorFormat);


extern APP_LIST_WP_DEC_STATUS
applistwallpaperDecSetDstFormat(
   APP_LIST_WP_DECODER_HANDLE* handle,
   APP_LIST_WP_COLOR_FORMAT colorFormat);

extern APP_LIST_WP_DEC_STATUS
applistwallpaperDecQueryFrameCount(
   APP_LIST_WP_DECODER_HANDLE* handle,
   unsigned int *frameCnt);

extern APP_LIST_WP_DEC_STATUS
applistwallpaperDecQueryPartitionCount(
   APP_LIST_WP_DECODER_HANDLE* handle,
   unsigned int *partitionCnt);

extern APP_LIST_WP_DEC_STATUS
applistwallpaperDecQueryPartitionInfo(
   APP_LIST_WP_DECODER_HANDLE* handle,
   unsigned int partitionIdx,
   unsigned int *frame_count,
   unsigned int *frame_start_index);

extern APP_LIST_WP_DEC_STATUS
applistwallpaperDecQuerySrcFrameBufSize(
   APP_LIST_WP_DECODER_HANDLE* handle,
   unsigned int frame_index,
   unsigned int *buf_size);

//APP_LIST_WP_DEC_STATUS
//vapp_wallpaperDecQueryDstFrameBufSize(
//   APP_LIST_WP_DECODER_HANDLE* handle,
//   unsigned int *buf_size);

extern APP_LIST_WP_DEC_STATUS
applistwallpaperDecQueryFrameHeaderLength(
   APP_LIST_WP_DECODER_HANDLE* handle,
   unsigned int *frame_header_len);

extern APP_LIST_WP_DEC_STATUS
applistwallpaperDecGetFrameSrcBuf(
   APP_LIST_WP_DECODER_HANDLE *handle,
   APP_LIST_WP_READ_FILE_MODE_ENUM read_mode,
   unsigned int frame_index,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned int *actual_rd_size,
   app_list_wallpaper_async_get_frame_callback  callback,
   void *param);

extern APP_LIST_WP_DEC_STATUS
applistwallpaperDecAbortGetFrameSrcBuf(
   APP_LIST_WP_DECODER_HANDLE *handle);

extern APP_LIST_WP_DEC_STATUS
applistwallpaperDecGetFramePixelData(
   APP_LIST_WP_DECODER_HANDLE *handle,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned char* dstBuf,
   unsigned int dst_buf_size);

extern S32 is_ivlw_file;

#endif

/*Extern functions*/
extern void mmi_phnset_wallpaper_reset_to_default(MMI_BOOL update_nvram);

extern S8 *idle_screen_wallpaper_name;
extern S8 *idle_screen_wallpaper_name_original;
extern MMI_ID_TYPE idle_screen_wallpaper_ID;
extern MMI_theme *current_MMI_theme;


////////////////////static wallpaper part////////////////////////////////////
#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  gui_wallpaper_drm_callback
 * DESCRIPTION
 *  gui wallpaper drm consumer callback
 * PARAMETERS
 *  res       [IN]
 *  id   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_static_wallpaper_drm_callback(S32 res, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_stop_consume(drm_consumer);
    PhnsetWallpaperBadFileCallBack(0);
}
#endif /* __DRM_SUPPORT__ */


#ifdef __MMI_APPLIST_SUPPORT_GIF_WALLPAPER__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_static_wallpaper_init
 * DESCRIPTION
 *  static wallpaper init for gif wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_static_wallpaper_init()
{
    gui_animation_handle = GDI_ERROR_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_static_wallpaper_stop
 * DESCRIPTION
 *  static wallpaper stop for gif wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_static_wallpaper_stop()
{
    if(gui_animation_handle != GDI_ERROR_HANDLE)
    {
        gdi_anim_pause(gui_animation_handle);
        anim_state = anim_pause;
    } 
}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_static_wallpaper
 * DESCRIPTION
 *  draw static wallpaper, support from id/from path, and support gif wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_static_wallpaper()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 hs_wallpaper;
    S32 disp_height = UI_device_height, disp_width = UI_device_width;
    S32 image_width, image_height, image_offset_x, image_offset_y,image_frame_count;
    GDI_RESULT ret = GDI_SUCCEED;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hs_wallpaper = get_image(idle_screen_wallpaper_ID);

#ifdef __MMI_APPLIST_SUPPORT_GIF_WALLPAPER__
    mmi_applist_static_wallpaper_init();
#endif

    gdi_layer_push_and_set_active(layer_handle);
    /*draw background with theme*/
    gdi_layer_clear(APPLIST_BG_COLOR);
    //gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, APPLIST_BG_COLOR);//current_MMI_theme->general_background_filler);

    if (idle_screen_wallpaper_ID != 0)  /* image comes from resource */
    {
        gdi_image_get_dimension(hs_wallpaper, &image_width, &image_height);
        gdi_image_get_frame_count(hs_wallpaper,&image_frame_count);
        
        /*Calc image offset*/
        image_offset_x = (UI_device_width - image_width) >> 1;
        image_offset_y = (UI_device_height - image_height)>> 1;

        if(image_frame_count > 1)           //Animation wallpaper, such as gif
        {
            #ifdef __MMI_APPLIST_SUPPORT_GIF_WALLPAPER__
            gdi_image_draw_animation_frames(image_offset_x, 
                                            image_offset_y,
                                            hs_wallpaper,
                                            &gui_animation_handle,
                                            0);
            #else
            gdi_image_draw_animation_single_frame(image_offset_x,
                                                  image_offset_y,
                                                  hs_wallpaper,
                                                  0);
            #endif
        }
        else //static wallpaper
        {
            if (mmi_phnset_check_themeid_wallpaper(idle_screen_wallpaper_ID))
            {
                gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->idle_bkg_filler);
            }
            else
            {
                gdi_image_draw(image_offset_x, image_offset_y, hs_wallpaper);            
            }
        }
     }
     /*Image from file path*/
     else
     {
        /* 102406 DRM check Start */
        FS_HANDLE handle = 0;
        kal_bool is_allowed = KAL_TRUE;
        
        if (idle_screen_wallpaper_name_original == NULL)
        {
            ret = GDI_IMAGE_ERR_INVALID_FILE;
        }
        else
        {
            handle = DRM_open_file((PU16) idle_screen_wallpaper_name_original, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
            if (handle >= FS_NO_ERROR)
            {
                #ifdef __DRM_SUPPORT__
                if (DRM_validate_forward_rule(handle, DRM_PERMISSION_DISPLAY))
                {
                    drm_consumer = DRM_consume_rights(handle, DRM_PERMISSION_DISPLAY, mmi_applist_static_wallpaper_drm_callback);
                    is_allowed = KAL_TRUE;
                }
                else
                {
                    is_allowed = KAL_FALSE;
                    ret = GDI_IMAGE_ERR_INVALID_FILE;
                }
                #endif /* __DRM_SUPPORT__ */ 
    
                DRM_close_file(handle);
            }
            else
            {
                ret = GDI_IMAGE_ERR_INVALID_FILE;
            }               
        }
            
        if (ret != GDI_IMAGE_ERR_INVALID_FILE)
        {    
            gdi_image_get_dimension_file(idle_screen_wallpaper_name, &image_width, &image_height);
            gdi_image_get_frame_count_file(idle_screen_wallpaper_name,&image_frame_count);
            
            image_offset_x = (disp_width - image_width) >> 1;
            image_offset_y = (disp_height - image_height) >> 1;
    
            if ((disp_width >= image_width) && (disp_height >= image_height))       /* image can be displayed entirely */
            {
                #ifdef __MMI_APPLIST_SUPPORT_GIF_WALLPAPER__
                ret = gdi_image_draw_animation_frames_file(image_offset_x, image_offset_y, idle_screen_wallpaper_name, &gui_animation_handle, 0);
                #else
                ret = gdi_image_draw_file(image_offset_x, image_offset_y, (CHAR *) idle_screen_wallpaper_name);
                #endif
            }
            else    /* image is larger than screen size */
            {
                S32 resized_offset_x;
                S32 resized_offset_y;
                S32 resized_width;
                S32 resized_height;
    
                gdi_image_util_fit_bbox(
                        disp_width,
                        disp_height,
                        image_width,
                        image_height,
                        &resized_offset_x,
                        &resized_offset_y,
                        &resized_width,
                        &resized_height);
                #ifdef __MMI_APPLIST_SUPPORT_GIF_WALLPAPER__
                ret = gdi_image_draw_animation_resized_file(
                            resized_offset_x,
                            resized_offset_y,
                            resized_width,
                            resized_height,
                            (CHAR *) idle_screen_wallpaper_name,
                            &gui_animation_handle);
                #else
                ret = gdi_image_draw_resized_file(
                            resized_offset_x,
                            resized_offset_y,
                            resized_width,
                            resized_height,
                            (CHAR *) idle_screen_wallpaper_name);
                #endif

            }
        }
    
        if (ret < 0 && ret != GDI_GIF_ERR_OUT_OF_CLIP_REGION && ret != GDI_BMP_ERR_OUT_OF_CLIP_REGION)
        {
            if (is_allowed)
                PhnsetWallpaperBadFileCallBack(0);
            else
                PhnsetWallpaperBadFileCallBack(STR_GLOBAL_DRM_PROHIBITED);

            gdi_image_get_dimension(hs_wallpaper, &image_width, &image_height);
            gdi_image_get_frame_count(hs_wallpaper,&image_frame_count);
            
            image_offset_x = (disp_width - image_width) >> 1;
            image_offset_y = (disp_height - image_height) >> 1;

            if(image_frame_count > 1) //Animation picture
            {
                #ifdef __MMI_APPLIST_SUPPORT_GIF_WALLPAPER__
                gdi_image_draw_animation_frames(image_offset_x, 
                                                image_offset_y,
                                                hs_wallpaper,
                                                &gui_animation_handle,
                                                0);
                #else
                gdi_image_draw_animation_single_frame(image_offset_x,
                                                      image_offset_y,
                                                      hs_wallpaper,
                                                      0);
                #endif
            }
            else
            {
                gdi_image_draw(image_offset_x, image_offset_y, hs_wallpaper);
            }
        }
    }
    gdi_layer_pop_and_restore_active();
#ifdef __MMI_APPLIST_SUPPORT_GIF_WALLPAPER__
    anim_state = anim_open;
#endif
    vlw_p->client->on_blt();
}


//////////////////////////////////Video wallpapaer part//////////////////////
#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_video_wallpaper_init
 * DESCRIPTION
 *  init globle wallpaper struct data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_video_wallpaper_init(void)
{
    video_wallpaper_struct.close_func = NULL;
    video_wallpaper_struct.start_play_time = 0;
    video_wallpaper_struct.play_repeat_count = 0xFFFFFFFF;
    kal_mem_set(&video_wallpaper_struct.videoInfo, 0, sizeof(mdi_video_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_video_wallpaper_seek
 * DESCRIPTION
 *  seek video file by time
 * PARAMETERS
 *  time   [IN] 
 *  videoLayer    [IN]
 *  subtitleLayer   [IN]
 * RETURNS
 *  MDI_RESULT    return MDI_RES_VDOPLY_SUCCEED if seek succeed
 *****************************************************************************/
MDI_RESULT mmi_applist_video_wallpaper_seek(U64 time , gdi_handle videoLayer, gdi_handle subtitleLayer)
{
    mdi_video_seek_struct param;
    mdi_video_ply_get_default_seek_setting(&param);

    // seek option
    param.time = time;
    param.blocking = MMI_TRUE;
    param.seek_result_callback = NULL;
    param.user_data = NULL;

    // get frame option
    param.get_frame = MMI_TRUE;
    param.frame.player_layer_handle = videoLayer;
    param.frame.subtitle_layer_handle = subtitleLayer;

    return mdi_video_ply_seek_ex(&param);
}

extern void mmi_applist_video_wallpaper_cb();

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_video_wallpaper_play_finish_callback
 * DESCRIPTION
 *  Play finish callback function, will handle looping here
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_video_wallpaper_play_finish_callback(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT video_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((result == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR) || (result == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR))
    {
        return; /* Special handle , requiered by MDI */
    }
    else if (result >= 0)
    {
        /* success play finished */

        /* teminate condition */
        if (video_wallpaper_struct.play_repeat_count == 0)
        {
            return;
        }

        /* force stopped, will not loop again */
        if (vlw_play_state == vlw_stop)
        {
            return;
        }

        /* calc remain count */
        if (video_wallpaper_struct.play_repeat_count > 0)  /* play again */
        {
            video_wallpaper_struct.play_repeat_count--;
        }

        /* the callback function maybe already exit this category and close video file */
        /* check before play this video */
        {
            if(vlw_play_state == vlw_pause)
            {
                gui_start_timer(50, mmi_applist_video_wallpaper_cb);
                return;
            }
            /* seek to first frame */
            video_ret = mdi_video_ply_seek(0);
            video_ret = mdi_video_ply_play(
                                layer_handle,
                                video_wallpaper_struct.blt_layer_flag,
                                video_wallpaper_struct.play_layer_flag,
                                1,                      /* repeat count */
                                video_wallpaper_struct.videoInfo.track == MDI_VIDEO_TRACK_A_ONLY? MMI_FALSE: MMI_TRUE,       /* update to LCM or not */
                                MMI_FALSE,         /* play aud or not */    
                                MDI_DEVICE_SPEAKER2,    /* speaker & earphone */
                                MDI_VIDEO_LCD_ROTATE_0, /* rotate */
                                100,                    /* 1x play speed */
                                mmi_applist_video_wallpaper_play_finish_callback, 0);    /* hook callback */
        }
    }
}


void mmi_applist_video_wallpaper_cb()
{
    MDI_RESULT video_ret;
    if(vlw_play_state == vlw_play)
    {
            video_ret = mdi_video_ply_seek(0);

            video_ret = mdi_video_ply_play(
                                layer_handle,
                                video_wallpaper_struct.blt_layer_flag,
                                video_wallpaper_struct.play_layer_flag,
                                1,                      /* repeat count */
                                video_wallpaper_struct.videoInfo.track == MDI_VIDEO_TRACK_A_ONLY? MMI_FALSE: MMI_TRUE,       /* update to LCM or not */
                                MMI_FALSE,         /* play aud or not */    
                                MDI_DEVICE_SPEAKER2,    /* speaker & earphone */
                                MDI_VIDEO_LCD_ROTATE_0, /* rotate */
                                100,                    /* 1x play speed */
                                mmi_applist_video_wallpaper_play_finish_callback, 0);    /* hook callback */
        gui_cancel_timer(mmi_applist_video_wallpaper_cb);
        }
    else if(vlw_play_state == vlw_stop)
    {
        gui_cancel_timer(mmi_applist_video_wallpaper_cb);
    }
    else
    {
        gui_start_timer(50, mmi_applist_video_wallpaper_cb);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_video_wallpaper_play
 * DESCRIPTION
 *  play video file
 * PARAMETERS
 *  layer_handle     : [IN]
 *  blt_layer_flag    : [IN]
 *  play_layer_flag  : [IN]
 * RETURNS
 *  MDI_RESULT    return MDI_RES_VDOPLY_SUCCEED if play succeed
 *****************************************************************************/
MDI_RESULT mmi_applist_video_wallpaper_play(gdi_handle layer_handle, U32 blt_layer_flag, U32 play_layer_flag)
{
    mdi_video_play_struct param;
    pBOOL isAudioOnly;
    
    mdi_video_ply_get_default_play_setting(&param);
    isAudioOnly = (video_wallpaper_struct.videoInfo.track == MDI_VIDEO_TRACK_A_ONLY);
     // general part
    param.player_layer_handle  = layer_handle;
    param.blt_layer_flag       = blt_layer_flag;
    param.play_layer_flag      = play_layer_flag;
    param.repeat_count         = 1;
    param.is_visual_update     = (isAudioOnly ? MMI_FALSE : MMI_TRUE);
    param.is_play_audio        = MMI_FALSE;
    param.audio_path           = MDI_DEVICE_SPEAKER2;      // config audio output path. Use earphone if present
    param.rotate               = 0;                          // no rotation
    param.play_speed           = 100,                        // always use 1X playback
    param.play_finish_callback = mmi_applist_video_wallpaper_play_finish_callback;
    param.user_data            = NULL;
    // subtitle part
    param.subtitle_layer_handle = NULL;
    param.subtitle_layer_flag   = NULL;
    return mdi_video_ply_play_ex(&param);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_video_wallpaper_pause
 * DESCRIPTION
 *  pause play video
 * PARAMETERS
 *  void 
 * RETURNS
 *  MDI_RESULT    return MDI_RES_VDOPLY_SUCCEED if stop succeed
 *****************************************************************************/
MDI_RESULT mmi_applist_video_wallpaper_pause()
{
    if(vlw_play_state == vlw_play)
    {
        vlw_play_state = vlw_pause;
        return mdi_video_ply_update_layer_pause();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_video_wallpaper_pause
 * DESCRIPTION
 *  pause play video
 * PARAMETERS
 *  void 
 * RETURNS
 *  MDI_RESULT    return MDI_RES_VDOPLY_SUCCEED if stop succeed
 *****************************************************************************/
MDI_RESULT mmi_applist_video_wallpaper_resume(gdi_handle layer_handle, U32 blt_layer_flag, U32 play_layer_flag)
{
    // init resume option
    mdi_video_update_layer_resume_struct param;
    pBOOL isAudioOnly;
    
    mdi_video_ply_get_default_resume_setting(&param);
    isAudioOnly = (video_wallpaper_struct.videoInfo.track == MDI_VIDEO_TRACK_A_ONLY);
    // video part
    param.player_layer_handle  = layer_handle;
    param.blt_layer_flag       = blt_layer_flag;
    param.play_layer_flag      = play_layer_flag;
    param.is_visual_update     = (isAudioOnly ? MMI_FALSE : MMI_TRUE);
    param.rotate               = 0;
    // subtitle part
    param.subtitle_layer_handle = NULL;
    param.subtitle_layer_flag   = NULL;
    return mdi_video_ply_update_layer_resume_ex(&param);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_video_wallpaper_stop
 * DESCRIPTION
 *  stop play video
 * PARAMETERS
 *  void 
 * RETURNS
 *  MDI_RESULT    return MDI_RES_VDOPLY_SUCCEED if stop succeed
 *****************************************************************************/
MDI_RESULT mmi_applist_video_wallpaper_stop()
{
    mdi_video_ply_get_cur_play_time(&video_wallpaper_struct.start_play_time);
    return mdi_video_ply_stop();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_video_wallpaper_close
 * DESCRIPTION
 *  close video file
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_video_wallpaper_close()
{
    if(vlw_play_state == vlw_play || vlw_play_state == vlw_pause)
    {
        mmi_applist_video_wallpaper_stop();
    }
    
    mdi_video_ply_close_file();


    mply_codec_custom_query(MPLY_CODEC_CUSTOM_FORMAT_MP4,
                                MPLY_CODEC_CUSTOM_ITEM_SET_PLAYBACK_MODE,
                                video_wallpaper_struct.originalCodecPlaybackMode);

    kal_mem_set(&video_wallpaper_struct.videoInfo, 0, sizeof(mdi_video_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_video_wallpaper
 * DESCRIPTION
 *  draw video wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_video_wallpaper()
{
    MDI_RESULT ret;
    
    if(vlw_play_state == vlw_open)  // Open -> Play
    {
        gdi_layer_push_and_set_active(layer_handle);
        ret = mmi_applist_video_wallpaper_play(layer_handle, video_wallpaper_struct.blt_layer_flag, video_wallpaper_struct.play_layer_flag);
        gdi_layer_pop_and_restore_active();

        if(ret == MDI_RES_VDOPLY_SUCCEED)
        {
            vlw_play_state = vlw_play;
        }
        else // Play failed
        {
            mmi_applist_vlw_restore_to_default_wallpaper(ret);
        }
    }
    else if(vlw_play_state == vlw_pause)
    {
        gdi_layer_push_and_set_active(layer_handle);
        ret = mmi_applist_video_wallpaper_resume(layer_handle, video_wallpaper_struct.blt_layer_flag, video_wallpaper_struct.play_layer_flag);
        gdi_layer_pop_and_restore_active();

        if(ret == MDI_RES_VDOPLY_SUCCEED)
        {
            vlw_play_state = vlw_play;
        }
        else // Play failed
        {
            mmi_applist_vlw_restore_to_default_wallpaper(ret);
        }
    }
    else
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_video_wallpaper_open
 * DESCRIPTION
 *  open video file
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT:  MDI_RES_VDOPLY_SUCCEED if open succeed
 *****************************************************************************/
void mmi_applist_video_wallpaper_open_result_cb(MDI_RESULT result, mdi_video_info_struct *vdo_clip, void *user_data)
{
    MDI_RESULT ret;
    
    if(result == MDI_RES_VDOPLY_SUCCEED)
    {
        //memcpy(&video_wallpaper_struct.videoInfo, vdo_clip, sizeof(mdi_video_info_struct));
        video_wallpaper_struct.videoInfo.width = vdo_clip->width;
        video_wallpaper_struct.videoInfo.height = vdo_clip->height;
        video_wallpaper_struct.videoInfo.track = vdo_clip->track;
        if(MDI_VIDEO_TRACK_A_ONLY == video_wallpaper_struct.videoInfo.track ||
           video_wallpaper_struct.videoInfo.width == 0 ||
           video_wallpaper_struct.videoInfo.height == 0)
        {
            mmi_applist_vlw_restore_to_default_wallpaper(result);
        }
        else
        {
            vlw_play_state = vlw_open;
            video_wallpaper_struct.close_func = mmi_applist_video_wallpaper_close;
            ret = mmi_applist_video_wallpaper_seek(video_wallpaper_struct.start_play_time, layer_handle, 0);
            if(ret != MDI_RES_VDOPLY_SUCCEED)
            {
                mmi_applist_vlw_restore_to_default_wallpaper(ret);
            }
            else
            {
                mmi_applist_draw_video_wallpaper();
                //mmi_applist_video_wallpaper_pause();
            }
        }
    }
    else
    {
        mmi_applist_vlw_restore_to_default_wallpaper(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_video_wallpaper_open
 * DESCRIPTION
 *  open video file
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT:  MDI_RES_VDOPLY_SUCCEED if open succeed
 *****************************************************************************/
MDI_RESULT mmi_applist_video_wallpaper_open(void)
{
    MDI_RESULT res = MDI_RES_VDOPLY_SUCCEED;

#ifdef VIDEO_WALLPAPER_TEST    
    kal_wchar buf[60];
#endif

    filetypes_file_type_enum type;


    video_wallpaper_struct.originalCodecPlaybackMode= mply_codec_custom_query(MPLY_CODEC_CUSTOM_FORMAT_MP4,
                                                                              MPLY_CODEC_CUSTOM_ITEM_GET_PLAYBACK_MODE,
                                                                              0);
    //Set codec mode
    mply_codec_custom_query(MPLY_CODEC_CUSTOM_FORMAT_MP4,
                            MPLY_CODEC_CUSTOM_ITEM_SET_PLAYBACK_MODE,
                            MPLY_CODEC_CUSTOM_PLAYBACK_MODE_QUALITY);


    /*Init struct data and play state*/
    vlw_play_state = vlw_init;

    /*Init video wallpaper struct*/
    mmi_applist_video_wallpaper_init();
    
    /*Init mdi video*/
    mdi_video_ply_init();
		
		//mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
	  mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_MPEG4);
		 
    if(idle_screen_wallpaper_ID != 0)  //From Resource
    {
        res = mdi_video_ply_open_clip_id(0, idle_screen_wallpaper_ID, &video_wallpaper_struct.videoInfo);
        //mdi_video_ply_open_file(idle_screen_wallpaper_ID, NULL, mmi_applist_video_wallpaper_open_result_cb, NULL);
    }
    else   //From File
    {
#ifdef VIDEO_WALLPAPER_TEST
        kal_wsprintf(
                &buf,
                "%c:\\%s\\%s.%s",
                VIDEO_WALLPAPER_DRIVER,
                VIDEO_WALLPAPER_PATH,
                VIDEO_WALLPAPER_FILE,
                VIDEO_WALLPAPER_FILE_EXT);
        type = srv_fmgr_types_find_type_by_filename_str(&buf);
#else
        type = srv_fmgr_types_find_type_by_filename_str((WCHAR *)idle_screen_wallpaper_name);
#endif

        if(type != FMGR_TYPE_MP4 && type!= FMGR_TYPE_3GP && type!= FMGR_TYPE_AVI)
        {
            res = MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT;
        }
        else
        {
            res = mdi_video_ply_open_clip_file(0, idle_screen_wallpaper_name, &video_wallpaper_struct.videoInfo);
            //mdi_video_ply_open_file(mmi_frm_group_get_active_id(), idle_screen_wallpaper_name, mmi_applist_video_wallpaper_open_result_cb, NULL);
        }
    }

    if(res != MDI_RES_VDOPLY_SUCCEED)
    {
        mmi_applist_vlw_restore_to_default_wallpaper(res);
    }
    else
    {
        mmi_applist_video_wallpaper_open_result_cb(MDI_RES_VDOPLY_SUCCEED, &video_wallpaper_struct.videoInfo, NULL);
    }
    return res;         
}

#endif


////////////////////////IVLW part/////////////////////////////////////
#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_ivlw_mem_alloc
 * DESCRIPTION
 *  malloc memory for ivlw
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void * mmi_applist_ivlw_mem_alloc(void *opaque, unsigned int items, unsigned int size)
{
    unsigned int total_bytes;
    void *buffer_ptr;

    if (opaque)
    {
        items += size - size;   /// make compiler happy
    }
    total_bytes = items * size;
    buffer_ptr = mmi_frm_asm_alloc_anonymous(total_bytes);
    return buffer_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_ivlw_mem_free
 * DESCRIPTION
 *  malloc memory for ivlw
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_ivlw_mem_free(void *opaque, void *address)
{
    mmi_frm_asm_free_anonymous(address);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_interactive_video_wallpaper_restore_to_default
 * DESCRIPTION
 *  restore to default wallpaper
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_interactive_video_wallpaper_restore_to_default(S32 error_code)
{
	if(error_code == -1)
	{
    	mmi_applist_vlw_restore_to_default_wallpaper(MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT);
	}
	else
	{
		mmi_applist_vlw_restore_to_default_wallpaper(0);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_interactive_video_wallpaper_open
 * DESCRIPTION
 *  open ivlw file
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_interactive_video_wallpaper_open(PU8 wallpaper_name)
{
    APP_LIST_WP_DEC_STATUS status;
    APP_LIST_WP_COLOR_FORMAT srcFormat;
    S32 image_width, image_height;
    S32 i, errorCode = 0;
    int applist_use_abm;
    //WCHAR buf[60];
#ifdef IVLW_TEST
    WCHAR buf[60];
    kal_wsprintf(
                buf,
                "%c:\\%s\\%s.%s",
                IVLW_DRIVER,
                IVLW_PATH,
                IVLW_FILE,
                IVLW_FILE_EXT);
#endif

    /*Init play struct data*/
    kal_mem_set(&IVLW_Play_Struct, 0, sizeof(mmi_applist_interactive_video_wallpaper_struct));
    IVLW_Play_Struct.play_state = ivlw_init;
    
#ifdef IVLW_TEST    
    if (FSAL_Open(&IVLW_Play_Struct.m_fsal, buf, FSAL_READ)!= FSAL_OK)
    {
        errorCode = 1000;
        return errorCode;
    }
#else
    if(wallpaper_name == NULL)
    {
        if (FSAL_Open(&IVLW_Play_Struct.m_fsal, idle_screen_wallpaper_name, FSAL_READ)!= FSAL_OK)
        {
            errorCode = 1000;
            return errorCode;
        }
    }
    else
    {
        if (FSAL_Open(&IVLW_Play_Struct.m_fsal, wallpaper_name, FSAL_READ)!= FSAL_OK)
        {
            errorCode = 1000;
            return errorCode;
        }
    }
#endif

    if(wallpaper_name == NULL)
    {
        applist_use_abm = applistwallpaperDecGetTypeFromFileName((WCHAR *)idle_screen_wallpaper_name);
        applistwallpaperDecSetType(applist_use_abm);
    }
    else
    {
        applist_use_abm = applistwallpaperDecGetTypeFromFileName((WCHAR *)wallpaper_name);
        applistwallpaperDecSetType(applist_use_abm);
    }

    status = applistwallpaperDecGetHandle(&IVLW_Play_Struct.fileHandler);
    if (status != APP_LIST_WP_DEC_STATUS_OK)
    {
       errorCode = 1001;
       return errorCode;

    }

    status = applistwallpaperDecSetAllocAndFree(IVLW_Play_Struct.fileHandler, &mmi_applist_ivlw_mem_alloc, &mmi_applist_ivlw_mem_free);
    if (status != APP_LIST_WP_DEC_STATUS_OK)
    {
       errorCode = 1002;
       return errorCode;
    }

    status = applistwallpaperDecSetSrcFile(IVLW_Play_Struct.fileHandler, &IVLW_Play_Struct.m_fsal);
    if (status != APP_LIST_WP_DEC_STATUS_OK)
    {
       errorCode = 1003;
       return errorCode;
    }


    status = applistwallpaperDecQuerySrcResolution(IVLW_Play_Struct.fileHandler, &image_width, &image_height);
    if ((status != APP_LIST_WP_DEC_STATUS_OK) || (image_width != LCD_WIDTH) || (image_height != LCD_HEIGHT))
    {
       errorCode = 1004;
       return errorCode;
    }

    status = applistwallpaperDecSetDstFormat(IVLW_Play_Struct.fileHandler, APP_LIST_WP_RGB565);
   
    if (status != APP_LIST_WP_DEC_STATUS_OK)
    {
       errorCode = 1005;
       return errorCode;
    }

    status = applistwallpaperDecQuerySrcFormat(IVLW_Play_Struct.fileHandler, &srcFormat);
    if (status != APP_LIST_WP_DEC_STATUS_OK)
    {
       errorCode = 1006;
       return errorCode;
    }

    if(srcFormat != APP_LIST_WP_RGB565)
    {
        errorCode = 1007;
        return errorCode;
    }

    status = applistwallpaperDecQueryPartitionCount(IVLW_Play_Struct.fileHandler, &IVLW_Play_Struct.partition_count);
    if (status != APP_LIST_WP_DEC_STATUS_OK)
    {
        errorCode = 1008;
        return errorCode;
    }

    if(IVLW_Play_Struct.partition_count > MAX_PARTITION_COUNT)
        IVLW_Play_Struct.partition_count = MAX_PARTITION_COUNT;
        
    for(i = 0; i < IVLW_Play_Struct.partition_count; i++)
    {
        status = applistwallpaperDecQueryPartitionInfo(
            IVLW_Play_Struct.fileHandler,
            i,
            &IVLW_Play_Struct.partition_count_frame_num[i],
            &IVLW_Play_Struct.partition_start_ptr[i]);

        if (status != APP_LIST_WP_DEC_STATUS_OK)
        {
            errorCode = 1009;
            return errorCode;
        }
    }

    status = applistwallpaperDecQueryFrameCount(IVLW_Play_Struct.fileHandler, &IVLW_Play_Struct.image_frame_count);
    if (status != APP_LIST_WP_DEC_STATUS_OK)
    {
       errorCode = 1010;
       return errorCode;
    }

    status = applistwallpaperDecQueryFrameHeaderLength(IVLW_Play_Struct.fileHandler, &IVLW_Play_Struct.frame_header_len);
    if (status != APP_LIST_WP_DEC_STATUS_OK)
    {
       errorCode = 1011;
       return errorCode;
    }

    IVLW_Play_Struct.play_state = ivlw_open;
    
    return errorCode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_interactive_video_wallpaper_draw_frame
 * DESCRIPTION
 *  play ivlw file
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_interactive_video_wallpaper_draw_frame()
{
    APP_LIST_WP_DEC_STATUS status;
    S32 size;
    U8 *layer_buffer_ptr = NULL;
    U8 *dest_buffer_ptr = NULL;
    U8 *source_buffer;
    //gdi_img_buf_struct source, dest;
    S32 actual_rd_size = 0;
    /*Alloc source buffer from ASM*/
    size = LCD_WIDTH * LCD_HEIGHT * 2 + MAX_VIDEO_HEADER_LEN;
    source_buffer/*IVLW_Play_Struct.sourceBuffer*/ = mmi_applist_ivlw_mem_alloc(NULL, 1, size);

	if(source_buffer == NULL)
	{
		mmi_applist_interactive_video_wallpaper_restore_to_default(-1);
		return;
	}
    dest_buffer_ptr = mmi_applist_ivlw_mem_alloc(NULL, 1, size);

    if(dest_buffer_ptr == NULL)
    {
    	mmi_applist_ivlw_mem_free(NULL, source_buffer);
        mmi_applist_interactive_video_wallpaper_restore_to_default(-1);
		return;
    }

    /*Query source buffer size*/
    status = applistwallpaperDecQuerySrcFrameBufSize(IVLW_Play_Struct.fileHandler, 
                                              IVLW_Play_Struct.currentFramePtr, 
                                              &IVLW_Play_Struct.sourceBufferSize);

    if(status != APP_LIST_WP_DEC_STATUS_OK || (IVLW_Play_Struct.sourceBufferSize > size))
    {
        mmi_applist_interactive_video_wallpaper_restore_to_default(1013);
        mmi_applist_ivlw_mem_free(NULL, source_buffer);
        mmi_applist_ivlw_mem_free(NULL, dest_buffer_ptr);
        return;
    }

    /*Get Src buffer*/
    status = applistwallpaperDecGetFrameSrcBuf(
                    IVLW_Play_Struct.fileHandler,
                    APP_LIST_WP_READ_FILE_SYNC,
                    IVLW_Play_Struct.currentFramePtr,
                    source_buffer,
                    IVLW_Play_Struct.sourceBufferSize,
                    &actual_rd_size,
                    NULL,
                    NULL);

    if(status != APP_LIST_WP_DEC_STATUS_OK)
    {
        mmi_applist_interactive_video_wallpaper_restore_to_default(1014);
        mmi_applist_ivlw_mem_free(NULL, source_buffer);
        mmi_applist_ivlw_mem_free(NULL, dest_buffer_ptr);
        return;
    }

    gdi_layer_push_and_set_active(layer_handle);

    gdi_layer_get_buffer_ptr(&layer_buffer_ptr);

    status = applistwallpaperDecGetFramePixelData(
                    IVLW_Play_Struct.fileHandler,
                    source_buffer,
                    IVLW_Play_Struct.sourceBufferSize,
                    dest_buffer_ptr,
                    size);
    
    /*source.ptr = dest_buffer_ptr + MAX_VIDEO_HEADER_LEN;
    source.pitch_bytes = LCD_WIDTH * 2;
    source.color_format = 2;
    
    dest.ptr = layer_buffer_ptr;
    dest.pitch_bytes = LCD_WIDTH * 2;
    dest.color_format = 2;
    
    gdi_img_buf_copy(source,dest,LCD_WIDTH,LCD_HEIGHT);*/
    
    
    memcpy(layer_buffer_ptr,dest_buffer_ptr + IVLW_Play_Struct.frame_header_len, LCD_WIDTH * LCD_HEIGHT * 2);

    /*Free source & dest buffer*/
    mmi_applist_ivlw_mem_free(NULL, source_buffer);
    mmi_applist_ivlw_mem_free(NULL, dest_buffer_ptr);
    
    gdi_layer_pop_and_restore_active();

    vlw_p->client->on_blt();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_interactive_video_wallpaper_cb
 * DESCRIPTION
 *  timer callback for animation
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_interactive_video_wallpaper_cb()
{
    S32 partion_num, start_index, end_index, current_partion, frame_ptr;
    S32 preview_partition;
    float ratio;

    if(IVLW_Play_Struct.currentPartition % IVLW_STATE_SCALE == 0)
    {
        partion_num = (IVLW_Play_Struct.currentPartition / IVLW_STATE_SCALE) * 2;
        start_index = IVLW_Play_Struct.partition_start_ptr[partion_num];
        end_index   = start_index + IVLW_Play_Struct.partition_count_frame_num[partion_num];

        /*Calcu current partion by frame ptr*/
        current_partion = 0;
        for(frame_ptr = IVLW_Play_Struct.currentFramePtr - IVLW_Play_Struct.partition_count_frame_num[0]; 
                frame_ptr >= 0; 
                frame_ptr -= IVLW_Play_Struct.partition_count_frame_num[current_partion])
        {
            ++current_partion;
        }

        /*Current frame ptr in the same partion, only loop is this partion*/
        if(IVLW_Play_Struct.currentFramePtr >= start_index && IVLW_Play_Struct.currentFramePtr < end_index)
        {
            ++IVLW_Play_Struct.currentFramePtr;
            if(IVLW_Play_Struct.currentFramePtr >= end_index)
            {
                IVLW_Play_Struct.currentFramePtr = start_index;
            }
        }
        else   //Need to move partion
        {
            if(current_partion > partion_num)  //Go back
            {
                if(current_partion%2 != 0)
                {
                    --IVLW_Play_Struct.currentFramePtr;
                }
                else if(partion_num = current_partion - 1)
                {
                    IVLW_Play_Struct.currentFramePtr = start_index;
                }
                else
                {
                    preview_partition = current_partion - 1 - (current_partion%2);
                    IVLW_Play_Struct.currentFramePtr = IVLW_Play_Struct.partition_start_ptr[preview_partition] + IVLW_Play_Struct.partition_count_frame_num[preview_partition];
                }
            }
            else
            {
                if(current_partion%2 != 0)
                {
                    ++IVLW_Play_Struct.currentFramePtr;
                }
                else if(partion_num = current_partion + 1)
                {
                    IVLW_Play_Struct.currentFramePtr = start_index;
                }
                else
                {
                    preview_partition = current_partion + 1 + (current_partion%2);
                    IVLW_Play_Struct.currentFramePtr = IVLW_Play_Struct.partition_start_ptr[preview_partition] + IVLW_Play_Struct.partition_count_frame_num[preview_partition];
                }
            }
        }
    }
#ifndef IVLW_FRAME_VIDEO_DELAY_MOVE
    else
    {
        partion_num = (IVLW_Play_Struct.currentPartition / IVLW_STATE_SCALE) * 2 + 1;
        frame_ptr = IVLW_Play_Struct.partition_start_ptr[partion_num];

        ratio = (float)(IVLW_Play_Struct.currentPartition % IVLW_STATE_SCALE) / 100.0;
        frame_ptr += (S32)(ratio * IVLW_Play_Struct.partition_count_frame_num[partion_num]); 

        IVLW_Play_Struct.currentFramePtr = frame_ptr;
    }
#endif

    mmi_applist_interactive_video_wallpaper_draw_frame();
    
    if(IVLW_Play_Struct.play_state == ivlw_play)
    {
        gui_start_timer(ANIM_TIMER_DELAY, mmi_applist_interactive_video_wallpaper_cb);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_interactive_video_wallpaper_play
 * DESCRIPTION
 *  play ivlw file
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_interactive_video_wallpaper_play()
{ 
    /*Calculate Current Partition num*/
    //IVLW_Play_Struct.currentPartition = (IVLW_Play_Struct.partition_count/2) * IVLW_STATE_SCALE;

    /*Calculate Current Frame Start Ptr*/
#ifdef IVLW_FRAME_VIDEO_DELAY_MOVE
    IVLW_Play_Struct.currentFramePtr = IVLW_Play_Struct.partition_start_ptr[(IVLW_Play_Struct.currentPartition/IVLW_STATE_SCALE) * 2];
#else
    IVLW_Play_Struct.currentFramePtr = IVLW_Play_Struct.partition_start_ptr[(IVLW_Play_Struct.currentPartition/IVLW_STATE_SCALE) * 2 + 1];
#endif

    mmi_applist_interactive_video_wallpaper_draw_frame();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_interactive_video_wallpaper_pause
 * DESCRIPTION
 *  pause play ivlw file
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_interactive_video_wallpaper_pause()
{ 
    /*Cancel timer for animation*/
    if(IVLW_Play_Struct.play_state == ivlw_play)
    {
    gui_cancel_timer(mmi_applist_interactive_video_wallpaper_cb);
    IVLW_Play_Struct.play_state = ivlw_pause;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_interactive_video_wallpaper_close
 * DESCRIPTION
 *  close ivlw file
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_interactive_video_wallpaper_close()
{ 
    /*Cancel timer for animation*/
    if(IVLW_Play_Struct.play_state == ivlw_play)
    {
    gui_cancel_timer(mmi_applist_interactive_video_wallpaper_cb);
    }

    if(IVLW_Play_Struct.fileHandler != NULL)
    {
        applistwallpaperDecReleaseHandle(&IVLW_Play_Struct.fileHandler);
        IVLW_Play_Struct.fileHandler = NULL;
    }
    
    FSAL_Close(&IVLW_Play_Struct.m_fsal);
    IVLW_Play_Struct.play_state = ivlw_stop;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_interactive_video_wallpaper_open_ext
 * DESCRIPTION
 *  open ivlw file
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_interactive_video_wallpaper_open_ext(PU8 wallpaper_name)
{
    S32 errorCode;
    errorCode = mmi_applist_interactive_video_wallpaper_open(wallpaper_name);
    if(errorCode != 0)
    {
        mmi_applist_interactive_video_wallpaper_restore_to_default(errorCode);
		return;
    }

    mmi_applist_interactive_video_wallpaper_play();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_draw_interactive_video_wallpaper
 * DESCRIPTION
 *  draw interactive wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_draw_interactive_video_wallpaper()
{
    if(IVLW_Play_Struct.play_state == ivlw_open || IVLW_Play_Struct.play_state == ivlw_pause)
    {
        gui_start_timer(ANIM_TIMER_DELAY, mmi_applist_interactive_video_wallpaper_cb);
		IVLW_Play_Struct.play_state = ivlw_play;
    }
	else
    {
		ASSERT(0);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_interactive_video_wallpaper_page_index_change
 * DESCRIPTION
 *  update page infomation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_interactive_video_wallpaper_page_index_change(S32 page_index, S32 total_page, S32 page_width, S32 page_margin)
{
    S32 wallpaperPageNumber;
    S32 page_pos = page_index;
    S32 partion_num, start_index, end_index, current_partion, frame_ptr;
    S32 preview_partition;
    float ratio;
    wallpaperPageNumber = (IVLW_Play_Struct.partition_count / 2) + 1;

    if(page_pos % page_width == 0)  //in one page of launcher
    {
        IVLW_Play_Struct.currentPartition = 0;
        IVLW_Play_Struct.currentPartition += (page_pos / page_width) * IVLW_STATE_SCALE;
    }
    else
    {
        IVLW_Play_Struct.currentPartition = (page_pos % page_width) * IVLW_STATE_SCALE / page_width;
        IVLW_Play_Struct.currentPartition += ((page_pos / page_width)* IVLW_STATE_SCALE);
    }

    if(total_page != wallpaperPageNumber)
    {
        IVLW_Play_Struct.currentPartition = IVLW_Play_Struct.currentPartition - (total_page / 2) * IVLW_STATE_SCALE + (wallpaperPageNumber / 2) * IVLW_STATE_SCALE;

        if(IVLW_Play_Struct.currentPartition < 0)
        {
            IVLW_Play_Struct.currentPartition = 0;
        }

        if(IVLW_Play_Struct.currentPartition > (wallpaperPageNumber - 1) * IVLW_STATE_SCALE)
        {
            IVLW_Play_Struct.currentPartition = (wallpaperPageNumber - 1) * IVLW_STATE_SCALE;
        }        
    }
    if(IVLW_Play_Struct.play_state == ivlw_open || IVLW_Play_Struct.play_state == ivlw_pause)
    {
        if(IVLW_Play_Struct.currentPartition % IVLW_STATE_SCALE == 0)
        {
            partion_num = (IVLW_Play_Struct.currentPartition / IVLW_STATE_SCALE) * 2;
            start_index = IVLW_Play_Struct.partition_start_ptr[partion_num];
            end_index   = start_index + IVLW_Play_Struct.partition_count_frame_num[partion_num];

            /*Calcu current partion by frame ptr*/
            current_partion = 0;
            for(frame_ptr = IVLW_Play_Struct.currentFramePtr - IVLW_Play_Struct.partition_count_frame_num[0]; 
                    frame_ptr >= 0; 
                    frame_ptr -= IVLW_Play_Struct.partition_count_frame_num[current_partion])
            {
                ++current_partion;
            }

            /*Current frame ptr in the same partion, only loop is this partion*/
            if(IVLW_Play_Struct.currentFramePtr >= start_index && IVLW_Play_Struct.currentFramePtr < end_index)
            {
                ++IVLW_Play_Struct.currentFramePtr;
                if(IVLW_Play_Struct.currentFramePtr >= end_index)
                {
                    IVLW_Play_Struct.currentFramePtr = start_index;
                }
            }
            else   //Need to move partion
            {
                if(current_partion > partion_num)  //Go back
                {
                    if(current_partion%2 != 0)
                    {
                        --IVLW_Play_Struct.currentFramePtr;
                    }
                    else if(partion_num = current_partion - 1)
                    {
                        IVLW_Play_Struct.currentFramePtr = start_index;
                    }
                    else
                    {
                        preview_partition = current_partion - 1 - (current_partion%2);
                        IVLW_Play_Struct.currentFramePtr = IVLW_Play_Struct.partition_start_ptr[preview_partition] + IVLW_Play_Struct.partition_count_frame_num[preview_partition];
                    }
                }
                else
                {
                    if(current_partion%2 != 0)
                    {
                        ++IVLW_Play_Struct.currentFramePtr;
                    }
                    else if(partion_num = current_partion + 1)
                    {
                        IVLW_Play_Struct.currentFramePtr = start_index;
                    }
                    else
                    {
                        preview_partition = current_partion + 1 + (current_partion%2);
                        IVLW_Play_Struct.currentFramePtr = IVLW_Play_Struct.partition_start_ptr[preview_partition] + IVLW_Play_Struct.partition_count_frame_num[preview_partition];
                    }
                }
            }
        }
        #ifndef IVLW_FRAME_VIDEO_DELAY_MOVE
        else
        {
            partion_num = (IVLW_Play_Struct.currentPartition / IVLW_STATE_SCALE) * 2 + 1;
            frame_ptr = IVLW_Play_Struct.partition_start_ptr[partion_num];

            ratio = (float)(IVLW_Play_Struct.currentPartition % IVLW_STATE_SCALE) / 100.0;
            frame_ptr += (S32)(ratio * IVLW_Play_Struct.partition_count_frame_num[partion_num]); 

            IVLW_Play_Struct.currentFramePtr = frame_ptr;
        }
        #endif

        mmi_applist_interactive_video_wallpaper_draw_frame();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_interactive_video_wallpaper_open_query_partition_num
 * DESCRIPTION
 *  open ivlw file and query the center partition frame num
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_interactive_video_wallpaper_open_query_partition_num(PU8 wallpaper_name)
{
    S32 index, partition_num;
    if(mmi_applist_interactive_video_wallpaper_open(wallpaper_name) != 0)
    {
        return 0;
    }
    partition_num = IVLW_Play_Struct.partition_count/2;
    index = IVLW_Play_Struct.partition_count_frame_num[partition_num];

    IVLW_Play_Struct.currentPartition = (((IVLW_Play_Struct.partition_count / 2) + 1) / 2) * IVLW_STATE_SCALE;
    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_interactive_video_wallpaper_query_frame_buffer
 * DESCRIPTION
 *  open ivlw file and query the center partition frame num
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_applist_interactive_video_wallpaper_query_frame_buffer(S32 index, PU8 frame_buffer)
{
    APP_LIST_WP_DEC_STATUS status;
    S32 size;
    U8 *source_buffer = NULL;
    S32 actual_rd_size = 0;
    
    size = LCD_WIDTH * LCD_HEIGHT * 2 + MAX_VIDEO_HEADER_LEN;
    source_buffer = mmi_frm_asm_alloc_r(mmi_frm_group_get_active_id(),size); //mmi_applist_ivlw_mem_alloc(NULL, 1, size);
    if(source_buffer  == NULL)
    {
        ASSERT(0);
    }

    IVLW_Play_Struct.currentFramePtr = IVLW_Play_Struct.partition_start_ptr[(IVLW_Play_Struct.currentPartition/IVLW_STATE_SCALE) * 2] + index;
 
 		if(IVLW_Play_Struct.fileHandler == NULL)
 		{
 			return -1;
 		}
    status = applistwallpaperDecQuerySrcFrameBufSize(IVLW_Play_Struct.fileHandler, 
                                              IVLW_Play_Struct.currentFramePtr, 
                                              &IVLW_Play_Struct.sourceBufferSize);

    if(status != APP_LIST_WP_DEC_STATUS_OK || (IVLW_Play_Struct.sourceBufferSize > size))
    {
        mmi_applist_ivlw_mem_free(NULL, source_buffer);
        return -1;
    }

    /*Get Src buffer*/
    status = applistwallpaperDecGetFrameSrcBuf(
                    IVLW_Play_Struct.fileHandler,
                    APP_LIST_WP_READ_FILE_SYNC,
                    IVLW_Play_Struct.currentFramePtr,
                    source_buffer,
                    IVLW_Play_Struct.sourceBufferSize,
                    &actual_rd_size,
                    NULL,
                    NULL);

    if(status != APP_LIST_WP_DEC_STATUS_OK)
    {
        mmi_applist_ivlw_mem_free(NULL, source_buffer);
        return -1;
    }

    status = applistwallpaperDecGetFramePixelData(
                    IVLW_Play_Struct.fileHandler,
                    source_buffer,
                    IVLW_Play_Struct.sourceBufferSize,
                    frame_buffer,
                    size);

    if(status != APP_LIST_WP_DEC_STATUS_OK)
    {
        mmi_applist_ivlw_mem_free(NULL, source_buffer);
        return -1;
    }

    mmi_applist_ivlw_mem_free(NULL, source_buffer);
    return IVLW_Play_Struct.frame_header_len;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_interactive_video_wallpaper_query_close
 * DESCRIPTION
 *  close ivlw file play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_interactive_video_wallpaper_query_close()
{ 
    applistwallpaperDecReleaseHandle(&IVLW_Play_Struct.fileHandler);
    FSAL_Close(&IVLW_Play_Struct.m_fsal);   
    IVLW_Play_Struct.play_state = ivlw_stop;
}


#endif


#if defined(__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__) || defined(__MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_wallpaper_notify_hdl
 * DESCRIPTION
 *  Handler for memory card plug out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_applist_wallpaper_notify_hdl(mmi_event_struct* para)
{
    //idle_screen_wallpaper_ID = IMG_ID_PHNSET_WP_START;
    //mmi_phnset_wallpaper_reset_to_default(MMI_TRUE);
    S16 error;
    
    /*Restore Interactive Video wallpaper NVRAM*/
#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
    is_ivlw_file = 0;
    WriteValue(NVRAM_PHNSET_IVLW_WALLPAPER, &is_ivlw_file, DS_BYTE, &error);
#endif

    /*Restore Video wallpaper NVRAM*/
#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
     is_vlw_file = 0;
     WriteValue(NVRAM_PHNSET_VLW_WALLPAPER, &is_vlw_file, DS_BYTE, &error);
#endif

    idle_screen_wallpaper_ID = IMG_ID_PHNSET_WP_START;
    mmi_dispchar_set_img_id(NVRAM_FUNANDGAMES_SETWALLPAPER, &idle_screen_wallpaper_ID);
    
    kal_prompt_trace(MOD_IDLE, "mmi_applist_wallpaper_notify_hdl");
    return MMI_RET_OK;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_vlw_on_get_type
 * DESCRIPTION
 *  get wallpaper type
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_applist_wallpaper_type_enum
 *****************************************************************************/
mmi_applist_wallpaper_type_enum mmi_applist_vlw_on_get_type(void)
{

    if(idle_screen_wallpaper_ID != 0)  //From resource
    {
#if 0
#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
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
#else

#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
    if(is_vlw_file == 1)
    {
        return MMI_APPLIST_WALLPAPER_TYPE_VLW;
    }
    else
#endif

#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
    if(is_ivlw_file == 1)
    {
        return MMI_APPLIST_WALLPAPER_TYPE_IVLW;
    }
    else
#endif

    {
        return MMI_APPLIST_WALLPAPER_TYPE_IMAGE;
    }
    
#endif
    }
    else
    {
#if 0
#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#else

#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
    if(is_ivlw_file == 1)
    {
        return MMI_APPLIST_WALLPAPER_TYPE_IVLW;
    }
    else
#endif
    
#endif

#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
        if(srv_fmgr_types_find_group_by_filename_str((WCHAR *)idle_screen_wallpaper_name) == FMGR_GROUP_VIDEO)
        {
            return MMI_APPLIST_WALLPAPER_TYPE_VLW;
        }
        else
#endif
        {
            return MMI_APPLIST_WALLPAPER_TYPE_IMAGE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_vlw_on_open
 * DESCRIPTION
 *  open wallpaper file
 * PARAMETERS
 *  wallpaper_layer_handle       : [IN]
 *  blt_layer_flag                    : [IN]
 *  play_layer_flag                  : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_vlw_on_open(
        gdi_handle wallpaper_layer_handle, 
        U32 blt_layer_flag, 
        U32 play_layer_flag)
{
    mmi_applist_wallpaper_type_enum wallpaper_type;
    MDI_RESULT ret;
    wallpaper_type = mmi_applist_vlw_on_get_type();

    wallpaper_tpe = wallpaper_type;
    
    layer_handle = wallpaper_layer_handle;

    /*For restore default wallpaper use*/
#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
    video_wallpaper_struct.blt_layer_flag = blt_layer_flag;
    video_wallpaper_struct.play_layer_flag = play_layer_flag;
#endif

    switch(wallpaper_type)
    {
        case MMI_APPLIST_WALLPAPER_TYPE_IMAGE:
            mmi_applist_draw_static_wallpaper();
            break;
#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
        case MMI_APPLIST_WALLPAPER_TYPE_VLW:
            mmi_applist_video_wallpaper_open();
            break;
#endif
#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
		case MMI_APPLIST_WALLPAPER_TYPE_IVLW:
		    mmi_applist_interactive_video_wallpaper_open_ext(NULL);
            break;
#endif
        default:
            ASSERT(0);
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_vlw_on_play
 * DESCRIPTION
 *  play wallpaper
 * PARAMETERS
 *  wallpaper_layer_handle    :  [IN]
 *  blt_layer_flag                 :  [IN]
 *  play_layer_flag               :  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_vlw_on_play(void)
{
    mmi_applist_wallpaper_type_enum wallpaper_type;
    wallpaper_type = wallpaper_tpe; //mmi_applist_vlw_on_get_type();

    switch(wallpaper_type)
    {
        case MMI_APPLIST_WALLPAPER_TYPE_IMAGE:
#ifdef __MMI_APPLIST_SUPPORT_GIF_WALLPAPER__
          if(anim_state == anim_pause && gui_animation_handle!= GDI_ERROR_HANDLE)
          {
              gdi_anim_resume(gui_animation_handle);
          }                
#endif
            break;
#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
        case MMI_APPLIST_WALLPAPER_TYPE_VLW:
            mmi_applist_draw_video_wallpaper();
            break;
#endif
#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
		case MMI_APPLIST_WALLPAPER_TYPE_IVLW:
		    mmi_applist_draw_interactive_video_wallpaper();
            break;
#endif
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_vlw_on_stop
 * DESCRIPTION
 *  play wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_vlw_on_stop()
{
    mmi_applist_wallpaper_type_enum wallpaper_type;
    MDI_RESULT ret;
    wallpaper_type = wallpaper_tpe; //mmi_applist_vlw_on_get_type();

    switch(wallpaper_type)
    {
        case MMI_APPLIST_WALLPAPER_TYPE_IMAGE:
#ifdef __MMI_APPLIST_SUPPORT_GIF_WALLPAPER__
            mmi_applist_static_wallpaper_stop();
#endif
            break ;
#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
        case MMI_APPLIST_WALLPAPER_TYPE_VLW:
            mmi_applist_video_wallpaper_pause();
            break;
#endif
#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
        case MMI_APPLIST_WALLPAPER_TYPE_IVLW:
            mmi_applist_interactive_video_wallpaper_pause();
            break;
#endif
        default:
            ASSERT(0);
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_vlw_on_stop
 * DESCRIPTION
 *  play wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_vlw_on_close(void)
{
    mmi_applist_wallpaper_type_enum wallpaper_type;
    MDI_RESULT ret;
    wallpaper_type = wallpaper_tpe; //mmi_applist_vlw_on_get_type();

    switch(wallpaper_type)
    {
        case MMI_APPLIST_WALLPAPER_TYPE_IMAGE:
#ifdef __MMI_APPLIST_SUPPORT_GIF_WALLPAPER__
            if(gui_animation_handle!= GDI_ERROR_HANDLE)
            {
                gdi_image_stop_animation(gui_animation_handle);
                gui_animation_handle = GDI_ERROR_HANDLE;
            }                
#endif

            break ;
#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
        case MMI_APPLIST_WALLPAPER_TYPE_VLW:
            if(video_wallpaper_struct.close_func)
                video_wallpaper_struct.close_func();
            break;
#endif
#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
        case MMI_APPLIST_WALLPAPER_TYPE_IVLW:
            mmi_applist_interactive_video_wallpaper_close();
            break;
#endif
        default:
            ASSERT(0);
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_vlw_on_page_change
 * DESCRIPTION
 *  page index change function
 * PARAMETERS
 *  page_index      :[IN]
 *  total_page       :[IN]
 *  page_width      :[IN]
 *  page_margin     :[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_vlw_on_page_change(S32 page_index, S32 total_page,S32 page_width, S32 page_margin)
{
#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
    mmi_applist_wallpaper_type_enum wallpaper_type;
    wallpaper_type = wallpaper_tpe; //mmi_applist_vlw_on_get_type();
    if(wallpaper_type == MMI_APPLIST_WALLPAPER_TYPE_IVLW)
    {
        mmi_applist_interactive_video_wallpaper_page_index_change(page_index, total_page,page_width,page_margin);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_vlw_restore_to_default_wallpaper
 * DESCRIPTION
 *  Restore to default wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_vlw_restore_to_default_wallpaper(MDI_RESULT err_code)
{
    U8 is_interactive_video_wallpaper = 0;
    U8 is_video_wallpaper = 0;
	mmi_event_notify_enum popupType;
	MMI_ID_TYPE err_str_id;
    S16 error;
    mmi_applist_vlw_on_close();
    idle_screen_wallpaper_ID = IMG_ID_PHNSET_WP_START;

    /*Restore Interactive Video wallpaper NVRAM*/
#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
    WriteValue(NVRAM_PHNSET_IVLW_WALLPAPER, &is_interactive_video_wallpaper, DS_BYTE, &error);
    is_ivlw_file = 0;
#endif

    /*Restore Video wallpaper NVRAM*/
#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
     WriteValue(NVRAM_PHNSET_VLW_WALLPAPER, &is_video_wallpaper, DS_BYTE, &error);
     is_vlw_file = 0;
#endif


    mmi_applist_vlw_on_open(layer_handle,0,0);

    kal_prompt_trace(MOD_IDLE, "mmi_applist_vlw_restore_to_default_wallpaper");

	if(err_code = MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT)
	{
		err_str_id = mdi_util_get_mdi_error_info(err_code, &popupType);
		PhnsetWallpaperBadFileCallBack(err_str_id);
	}
	else
	{
    	PhnsetWallpaperBadFileCallBack(0);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_vlw_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  client           : [IN]
 *  config           : [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_vlw_init(mmi_applist_vlw_client *client, mmi_applist_vlw_config *config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Store callback function */
    vlw_p->client =  client;

    /* Assign */
    config->on_get_type = mmi_applist_vlw_on_get_type;
    config->on_open = mmi_applist_vlw_on_open;     
    config->on_play = mmi_applist_vlw_on_play;     
    config->on_stop = mmi_applist_vlw_on_stop; 
    config->on_close = mmi_applist_vlw_on_close; 
    config->on_page_change = mmi_applist_vlw_on_page_change;
}

#endif /* __MMI_LAUNCHER_APP_LIST__ */

