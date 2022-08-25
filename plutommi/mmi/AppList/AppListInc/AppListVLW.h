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
 *  AppListVLW.h
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
#ifndef _MMI_APPLIST_VLW_H_
#define _MMI_APPLIST_VLW_H_

#include "mmi_features.h"

//#define __MMI_LAUNCHER_APP_LIST__
//#define __MMI_LAUNCHER_APP_LIST__VIDEO_WALLPAPER__

#define __MMI_APPLIST_SUPPORT_GIF_WALLPAPER__
//#define __MMI_LAUNCHER_APP_LIST__INTERACTIVE_VIDEO_WALLPAPER__  //Move to MMI Features.h

//#define IVLW_FRAME_VIDEO_DELAY_MOVE


#ifdef __MMI_LAUNCHER_APP_LIST__

#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "AppList_video_decorder.h"   


#define APPLIST_BG_COLOR gdi_act_color_from_rgb(255, 0, 19, 30)


typedef enum
{
    MMI_APPLIST_WALLPAPER_TYPE_IMAGE,
#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
    MMI_APPLIST_WALLPAPER_TYPE_VLW,
#endif
#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
    MMI_APPLIST_WALLPAPER_TYPE_IVLW,
#endif
    MMI_APPLIST_WALLPAPER_TYPE_INVALID
} mmi_applist_wallpaper_type_enum;


/* Query */
typedef mmi_applist_wallpaper_type_enum (*get_type_func)(void);

/* Open the VLW */
typedef void (*open_func)(gdi_handle wallpaper_layer_handle, U32 blt_layer_flag, U32 play_layer_flag);

/* Play or Resume the VLW */
typedef void (*play_func)(void);

/* Pause the VLW */
typedef void (*stop_func)(void);

/* Close the VLW */
typedef void (*close_func)(void);

/* Blt: update wallpaper */
typedef void (*blt_func)(void);

/*Update page info for IVLW move effect*/
typedef void (*page_change_func)(S32 page_index, S32 total_page,S32 page_width, S32 page_margin);

/* VLW */
typedef struct
{
    get_type_func on_get_type;
    open_func on_open;     
    play_func on_play;     
    stop_func on_stop; 
    close_func on_close;
    page_change_func on_page_change;
} mmi_applist_vlw_config;

/* VLW Client */
typedef struct
{
    blt_func on_blt;             
} mmi_applist_vlw_client;

typedef struct
{
    mmi_applist_vlw_client *client;     
} mmi_applist_vlw_context_struct;

extern void mmi_applist_vlw_init(
        mmi_applist_vlw_client *client, mmi_applist_vlw_config *config);

extern void mmi_applist_vlw_restore_to_default_wallpaper();


#ifdef __MMI_LAUNCHER_APP_LIST__INTERACTIVE_VIDEO_WALLPAPER__
extern S32 mmi_applist_interactive_video_wallpaper_open_query_partition_num(PU8 wallpaper_name);
extern S32 mmi_applist_interactive_video_wallpaper_query_frame_buffer(S32 index, PU8 frame_buffer);
extern void mmi_applist_interactive_video_wallpaper_query_close();
#endif

#endif /* __MMI_LAUNCHER_APP_LIST__ */

#endif /* _MMI_APPLIST_VLW_H_ */
