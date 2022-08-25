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
 *   npn_mtk.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   This file includes the structures, enums, interfaces exported by A/V Plug-in.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NPN_MTK_H
#define NPN_MTK_H

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************
 * Typedef
 ************************************************************/

/*
 * Check whether plug-in can play the audio automatically in current user profile setting
 * Return KAL_TRUE: user profile setting is silent mode or meeting mode
 * Return KAL_FALSE: plug-in can play the audio automatically
 */
typedef int (*npplg_is_silent_setting_funcptr_type) (void);

/*
 * Check application is playing audio
 * Return KAL_TRUE: browser is playing bgsound
 * Return KAL_FALSE: browser is not playing bgsound
 */
typedef int (*npplg_app_is_playing_audio_funcptr_type) (void);

/* Notify application that plug-in finish playing audio */
typedef void (*npplg_audio_play_finish_funcptr_type) (void);


/* Get data account id */
typedef unsigned int (*npplg_get_network_account_funcptr_type) (void);

/*
 * Return the GDI layer browser will use to paint on screen
 * handle0 will be video layer (the most bottom layer) created by plug-in so browser does not need to provide to plug-in
 * The order is the same as gdi_layer_set_blt_layer()
 * For handle2 and handle3, if browser does not use them, browser can just provide GDI_NULL_HANDLE
 */
typedef void (*npplg_get_gdi_layer_funcptr_type) (unsigned int *handle0, unsigned int *handle1, unsigned int *handle2, unsigned int *handle3);

/*
 * Get the gdi layer which plugin use to draw UI.
 */
typedef void (*npplg_get_plugin_layer_funcptr_type)(unsigned int *handle);

/* Get LCD orientation (mmi_frm_screen_rotate_enum) */
typedef int (*npplg_get_lcd_orientation_funcptr_type) (void);

/* Get application's transparent color */
typedef unsigned int (*npplg_get_app_transparent_color_funcptr_type) (void);

/* Allocate non-cacheable memory */
typedef void* (*npplg_mem_alloc_funcptr_type) (unsigned int size);

/* Free non-cacheable memory */
typedef void (*npplg_mem_free_funcptr_type) (void *data);



/************************************************************
 * Typedef
 ************************************************************/
typedef struct _NPluginMTKExtFuncs {
  npplg_is_silent_setting_funcptr_type           is_silent_setting;
  npplg_app_is_playing_audio_funcptr_type        is_playing_audio;
  npplg_audio_play_finish_funcptr_type           notify_play_finish;
  npplg_get_network_account_funcptr_type         get_network_account;
  npplg_get_gdi_layer_funcptr_type               get_gdi_layer;
  npplg_get_plugin_layer_funcptr_type            get_plugin_layer;
  npplg_get_lcd_orientation_funcptr_type         get_lcd_orientation;
  npplg_get_app_transparent_color_funcptr_type   get_transparent_color;
  npplg_mem_alloc_funcptr_type                   mem_alloc;
  npplg_mem_free_funcptr_type                    mem_free;
} NPluginMTKExtFuncs;

typedef NPluginMTKExtFuncs NPluginExtFuncs;



extern NPluginExtFuncs* OP_GetNPN_Extentions(void);

#ifdef __cplusplus
}
#endif

#endif /* NPN_MTK_H */
