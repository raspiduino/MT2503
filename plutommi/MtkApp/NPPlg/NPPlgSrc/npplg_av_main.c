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
 *   npplg_av_main.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Implement the plug-in side NPAPIs and plug-in instance management
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__)

/************************************************************
 * Include
 ************************************************************/
#include "MMI_features.h"

#include "stack_config.h"

/* MDI header file */
#include "mdi_include.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_video.h"

/* MED header file */
#include "med_api.h"
#include "med_main.h"

/* Media Player */
#ifdef __COSMOS_MMI_PACKAGE__
#include "UriAgentSrvGprot.h"
#include "vapp_music_player_singleplayer_gprot.h"
#include "vapp_gallery_gprot.h"
#else
#include "MediaAppGProt.h"
#endif

/* File system header file*/
#include "fs_type.h"
#include "fs_func.h"

/* Applib header file */
#include "app_mine.h"
#include "app_str.h"
#include "app_url.h"

/* A/V Plug-in header file */
#include "npplg_av_include.h"
#include "npplg_av_main.h"
#include "npplg_av_audio.h"
#include "npplg_av_video.h"
#include "npplg_av_stream.h"
#include "npplg_av_util.h"
#include "npplg_av_custom_config.h"
#include "mmi_rp_app_npplg_def.h"
#include "npplg_struct.h"
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
#include "vapp_npplg_av_include.h"
#endif

#if defined(OPERA_V10_BROWSER)
#include "opera_adp_plugin.h"
#endif

#if defined(__GADGET_SUPPORT__)
#include "gadget_adp_plugin_funcs.h"
#endif

#include "gpiosrvgprot.h"

/* Homescreen */
#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_launcher_gprot.h"
#else
#include "IdleGprot.h"
#endif

/* USB */
#include "UsbSrvGProt.h"

#include "npn_mtk.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "ScreenRotationGprot.h"
#include "lcd_if.h"
#include "string.h"
#include "fs_errcode.h"
#include "gdi_const.h"
#include "CustDataRes.h"
#include "gdi_include.h"
#include "MMIDataType.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "MediaPlayerGProt.h"
#endif
#include "gdi_datatype.h"
#include "lcd_sw_inc.h"
#include "app_ltlcom.h"
#include "kal_active_module.h"
#include "mmi_rp_app_usbsrv_def.h"
#include "ProfilesSrvGprot.h"
#include "GlobalResDef.h"
#include "CbmSrvGprot.h"
#include "cbm_api.h"
#include "WgtMgrSrvGprot.h"


/************************************************************
 * Static Declaration
 ************************************************************/
#ifdef OJI
static JRIGlobalRef npplg_av_main_get_java_class(void);
#endif
static NPError npplg_av_main_delete_instance(NPP instance, NPSavedData **save);
static NPError npplg_av_main_get_value(NPP instance, NPPVariable variable, void *value);
static NPError npplg_av_main_set_value(NPP instance, NPNVariable variable, void *value);
static NPError npplg_av_main_create_stream(NPP instance,
                                           NPMIMEType type,
                                           NPStream *stream,
                                           NPBool seekable,
                                           kal_uint16 *stype);
static kal_int32 npplg_av_main_is_ready_to_recv_data(NPP instance, NPStream *stream);
static kal_int32 npplg_av_main_recv_data(NPP instance,
                                         NPStream *stream,
                                         kal_int32 offset,
                                         kal_int32 len,
                                         void *buf);
static void npplg_av_main_recv_data_as_file(NPP instance, NPStream *stream, const kal_char *fname);
static NPError npplg_av_main_delete_stream(NPP instance, NPStream *stream, NPReason reason);
static void npplg_av_main_handle_url_rsp(NPP instance, const kal_char *url, NPReason reason, void *notify_data);
static kal_int16 npplg_av_main_handle_mouse_event(npplg_av_instance_struct *plugin_data, npplg_av_evt_mouse_struct *event);
static kal_int16 npplg_av_main_handle_key_event(npplg_av_instance_struct *plugin_datae, npplg_av_evt_key_struct *event);
static kal_int16 npplg_av_main_handle_paint_event(npplg_av_instance_struct *plugin_data, npplg_av_evt_paint_struct *event);
static kal_int16 npplg_av_main_handle_timer_event(npplg_av_instance_struct *plugin_data, npplg_av_evt_timer_struct *event);
static kal_int16 npplg_av_main_handle_activate_event(npplg_av_instance_struct *plugin_data, npplg_av_evt_activate_struct *event);
static kal_int16 npplg_av_main_handle_focus_event(npplg_av_instance_struct *plugin_data, npplg_av_evt_focus_struct *event);
static kal_int16 npplg_av_main_handle_scroll_event(npplg_av_instance_struct *plugin_data);
static kal_uint8 npplg_av_main_cvt_ctrl_type_to_evt(kal_uint8 ctrl_type, kal_bool pressed);
static kal_uint8 npplg_av_main_cvt_mmi_screen_rotate_to_mdi(kal_int32 lcd_orientation);
static void npplg_av_main_dispatch_event(npplg_av_instance_struct *plugin_data, kal_uint8 event);
static void npplg_av_main_print(NPP instance, NPPrint *platform_print);
static void npplg_av_main_clear_folder(void);
static NPError npplg_av_main_create_file(npplg_av_instance_struct *plugin_data, kal_uint32 flag);
static void npplg_av_main_reset_context(kal_int32 app_id, kal_bool reset_all);
static void npplg_av_main_free_instance_data(npplg_av_instance_struct *plugin_data);
static void npplg_av_main_redraw_window(npplg_av_instance_struct *plugin_data, NPWindow *window);
static void npplg_av_main_get_image_dimension(void);
static npplg_av_timer_struct *npplg_av_main_get_timer_by_id(npplg_av_instance_struct *plugin_data, kal_int32 timer_id);
static kal_uint32 npplg_av_main_get_req_id(void);
static void npplg_av_main_create_folder(void);
static kal_bool npplg_av_main_is_instance_in_list(npplg_av_instance_list_struct *list, npplg_av_instance_struct *plugin_data);
static kal_bool npplg_av_main_add_instance_into_list(npplg_av_instance_list_struct **list, npplg_av_instance_struct *plugin_data);
static npplg_av_instance_struct* npplg_av_main_get_instance_from_list(kal_uint32 instance_id, kal_uint8 app_id);


/************************************************************
 * Global Variable
 ************************************************************/
npplg_av_context_struct     g_npplg_av_context;
static kal_uint32           g_npplg_av_instance_id = 0;
static kal_uint32           g_npplg_av_req_id = 0;

NPNetscapeFuncs g_npplg_av_netscape_funcs[NPPLG_AV_APP_ID_TOTAL]; /* Netscape Function table */
NPluginMTKExtFuncs g_npplg_av_util_funcs[NPPLG_AV_APP_ID_TOTAL];  /* Utility functions provided by application */


/************************************************************
 * Local Function
 ************************************************************/

#ifdef OJI
/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_java_class
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
static JRIGlobalRef npplg_av_main_get_java_class(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_delete_instance
 * DESCRIPTION
 *  This function is used to delete one plug-in instance.
 * PARAMETERS
 *  instance        [IN]        Pointer to the plug-in instance to delete
 *  save            [OUT]       State or other information to save for reuse by a new instance of this plug-in at the same URL
 * RETURNS
 *  Execution result
 * RETURN VALUE LIST
 *  NPERR_NO_ERROR      Delete instance successfully
 *  Other error code    Failed to delete instance
 *****************************************************************************/
static NPError npplg_av_main_delete_instance(NPP instance, NPSavedData **save)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data = (npplg_av_instance_struct*)instance->pdata;
    kal_int32 app_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data == NULL)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_DEL_INSTANCE_ERROR);
        return NPERR_INVALID_PLUGIN_ERROR;
    }

    NPPLG_AV_LOCK;
    
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_DEL_INSTANCE, plugin_data->instance_id, plugin_data->app_id);
    app_id = plugin_data->app_id;

    if (plugin_data == g_npplg_av_context.app_cnxt[plugin_data->app_id].interrupt_instance)
    {
        g_npplg_av_context.app_cnxt[plugin_data->app_id].interrupt_instance = NULL;
        g_npplg_av_context.app_cnxt[plugin_data->app_id].interrupt_event = NPPLG_AV_INT_EVT_UNKNOWN;
    }

    npplg_av_main_remove_instance_from_list(&(g_npplg_av_context.app_cnxt[app_id].auto_play_queue), plugin_data);
    
    /* Stop object activity */
    plugin_data->deleting = KAL_TRUE;
    
    if (g_npplg_av_context.app_cnxt[app_id].is_suspend_by_mmi == KAL_TRUE)
    {
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
        {
            npplg_av_audio_close_by_app(plugin_data);
        }
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
        else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
        {
            npplg_av_video_close_by_app(plugin_data);
        }
#ifdef __MMI_VIDEO_STREAM__
        else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
        {
            npplg_av_stream_close_by_app(plugin_data);
        }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    }

    npplg_av_main_dispatch_event(plugin_data, NPPLG_AV_INT_EVT_STOP);

    npplg_av_main_stop_all_timer(plugin_data);

    npplg_av_main_remove_instance_from_list(&(g_npplg_av_context.app_cnxt[app_id].instance_list), plugin_data);
    
    npplg_av_main_free_instance_data(plugin_data);
    instance->pdata = NULL;

    g_npplg_av_context.app_cnxt[app_id].instance_num--;
    if (g_npplg_av_context.app_cnxt[app_id].instance_num == 0)
    {
        NPPLG_AV_APP_ENTER_STATE(app_id, g_npplg_av_context.app_cnxt[app_id].state, NPPLG_AV_USER_STATE_INITIALIZED);
    }

    NPPLG_AV_UNLOCK;
    return NPERR_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_value
 * DESCRIPTION
 *  This function is used to get plug-in information.
 * PARAMETERS
 *  instance        [IN]        Pointer to the plug-in instance
 *  variable        [IN]        Plug-in information the call gets
 *  value           [OUT]       Destination for plug-in information returned by the function
 * RETURNS
 *  Execution result
 * RETURN VALUE LIST
 *  NPERR_NO_ERROR      Successful
 *  Other error code    Unsuccessful
 *****************************************************************************/
static NPError npplg_av_main_get_value(NPP instance, NPPVariable variable, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (variable)
    {
        case NPPVpluginNameString:
            *((char**)value) = "A/V Plug-in";
            break;

        case NPPVpluginDescriptionString:
            *((char**)value) = "Support audio and video playing";
            break;

        default:
            return NPERR_INVALID_PARAM;
    }

    return NPERR_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_set_value
 * DESCRIPTION
 *  This function is used to set plug-in information.
 * PARAMETERS
 *  instance        [IN]        Pointer to the plug-in instance
 *  variable        [IN]        The plug-in information the call is setting
 *  value           [IN]        The value Opera Browser want to set
 * RETURNS
 *  Execution result
 * RETURN VALUE LIST
 *  NPERR_NO_ERROR      Successful
 *  Other error code    Unsuccessful
 *****************************************************************************/
static NPError npplg_av_main_set_value(NPP instance, NPNVariable variable, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* A/V Plug-in does not need to support NPP_SetValue() */
    
    return NPERR_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_create_stream
 * DESCRIPTION
 *  This function is used to notify a plug-in instance when a new data stream is created.
 * PARAMETERS
 *  instance        [IN]        Pointer to the plug-in instance
 *  type            [IN]        Pointer to the MIME type of the stream
 *  stream          [IN]        Pointer to the new stream
 *  seekable        [IN]        Indicates whether the stream is seekable
 *  stype           [OUT]       The mode of the stream
 * RETURNS
 *  Execution result
 * RETURN VALUE LIST
 *  NPERR_NO_ERROR      Successful
 *  Other error code    Unsuccessful
 *****************************************************************************/
static NPError npplg_av_main_create_stream(NPP instance,
                                           NPMIMEType type,
                                           NPStream *stream,
                                           NPBool seekable,
                                           kal_uint16 *stype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data = (npplg_av_instance_struct*)instance->pdata;
    NPError ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data == NULL)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_CREATE_STREAM_ERROR);
        return NPERR_INVALID_PLUGIN_ERROR;
    }

    NPPLG_AV_LOCK;

    if (plugin_data->stream != NULL)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_CREATE_TWO_STREAM, plugin_data->instance_id, plugin_data->app_id);
        NPPLG_AV_UNLOCK;
        return NPERR_GENERIC_ERROR;
    }

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_CREATE_STREAM, plugin_data->instance_id, plugin_data->app_id, type);

    plugin_data->stream = stream;

    switch (plugin_data->obj_type)
    {
        case NPPLG_AV_OBJ_TYPE_AUDIO:
        {
#ifndef NPPLG_AV_OPERA_NOT_PROVIDE_CORRECT_FILE_EXTENSION
#ifdef OPERA_V10_BROWSER
            if (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER)
            {
                /* Does not need raw data */
                *stype = NP_ASFILEONLY;
            }
            else
#endif /* OPERA_V10_BROWSER */
#endif
            {
                if (plugin_data->file_handle > 0)
                {
                    FS_Close(plugin_data->file_handle);
                    plugin_data->file_handle = 0;
                }

                ret = npplg_av_main_create_file(plugin_data, FS_READ_WRITE | FS_CREATE_ALWAYS);
                if (ret != NPERR_NO_ERROR)
                {
                    plugin_data->error = NPPLG_AV_ERROR_FILE;
                    NPPLG_AV_UNLOCK;
                    return ret;
                }
                *stype = NP_NORMAL;
            }

            plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_DOWNLOADING;
            break;
        }

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
        case NPPLG_AV_OBJ_TYPE_VIDEO:
        {
            if (plugin_data->file_handle > 0)
            {
                FS_Close(plugin_data->file_handle);
                plugin_data->file_handle = 0;
            }
            
            ret = npplg_av_main_create_file(plugin_data, FS_READ_WRITE | FS_OPEN_SHARED | FS_CREATE_ALWAYS);
            if (ret != NPERR_NO_ERROR)
            {
                plugin_data->error = NPPLG_AV_ERROR_FILE;
                NPPLG_AV_UNLOCK;
                return ret;
            }

            /* Need raw data because plug-in has to check if the video is PDL format */
            *stype = NP_NORMAL;
            
            plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_DOWNLOADING;
            break;
        }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__)
        case NPPLG_AV_OBJ_TYPE_STREAMING:
        {
            if (((npplg_av_video_data_struct*)plugin_data->obj_data)->is_pdl_or_rtsp == KAL_FALSE)
            {
#ifndef NPPLG_AV_OPERA_NOT_PROVIDE_CORRECT_FILE_EXTENSION
#ifdef OPERA_V10_BROWSER
                if (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER)
                {
                    /* Does not need raw data */
                    *stype = NP_ASFILEONLY;
                }
                else
#endif /* OPERA_V10_BROWSER */
#endif
                {
                    if (plugin_data->file_handle > 0)
                    {
                        FS_Close(plugin_data->file_handle);
                        plugin_data->file_handle = 0; 
                    }
                    
                    ret = npplg_av_main_create_file(plugin_data, FS_READ_WRITE | FS_CREATE_ALWAYS);
                    if (ret != NPERR_NO_ERROR)
                    {
                        plugin_data->error = NPPLG_AV_ERROR_FILE;
                        NPPLG_AV_UNLOCK;
                        return ret;
                    }
                    *stype = NP_NORMAL;
                }

                plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_DOWNLOADING;
            }
            else
            {
                /* If the object url is rtsp:// link, plug-in instance should not run into here */
                ASSERT(0);
            }
            break;
        }
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__) */

        default:
        {
            ASSERT(0);
            NPPLG_AV_UNLOCK;
            return NPERR_INVALID_INSTANCE_ERROR;
        }
    }

    NPPLG_AV_UNLOCK;
    return NPERR_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_is_ready_to_recv_data
 * DESCRIPTION
 *  This function is used to provide the maximum number of bytes that the plug-in can consume.
 * PARAMETERS
 *  instance        [IN]        Pointer to the plug-in instance
 *  stream          [IN]        Pointer to current stream
 * RETURNS
 *  The maximum number of bytes that an instance is prepared to accept from the stream
 *****************************************************************************/
static kal_int32 npplg_av_main_is_ready_to_recv_data(NPP instance, NPStream *stream)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data = (npplg_av_instance_struct*)instance->pdata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data == NULL)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_READY_TO_RECV_DATA_ERROR);
        return 0;
    }

    NPPLG_AV_LOCK;

    if (plugin_data->stream != stream)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_READY_TO_RECV_DATA_ERROR_MISMATCH, plugin_data->instance_id);
        NPPLG_AV_UNLOCK;
        return 0;
    }

    /*MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_READY_TO_RECV_DATA, plugin_data->instance_id);*/

#ifdef OPERA_V10_BROWSER
    if (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER)
    {
        /*
         * This function should be called only for video file and PDL video object
         * The caller should not call this function for audio and streaming object
         */
#ifndef NPPLG_AV_OPERA_NOT_PROVIDE_CORRECT_FILE_EXTENSION
        ASSERT(plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO);
#endif
    }
#endif /* OPERA_V10_BROWSER */

    NPPLG_AV_UNLOCK;
    return NPPLG_AV_MAX_CHUNK_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_recv_data
 * DESCRIPTION
 *  This function is used to deliver data to a plug-in instance.
 * PARAMETERS
 *  instance        [IN]        Pointer to the plug-in instance
 *  stream          [IN]        Pointer to current stream
 *  offset          [IN]        Offset in bytes of buf from the beginning of the data in the stream
 *  len             [IN]        Length in bytes of buf
 *  buf             [IN]        Buffer of data
 * RETURNS
 *  If successful, the function returns the number of bytes consumed by the instance.
 *  If unsuccessful, the function returns a negative value.
 *****************************************************************************/
static kal_int32 npplg_av_main_recv_data(NPP instance,
                                         NPStream *stream,
                                         kal_int32 offset,
                                         kal_int32 len,
                                         void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data = (npplg_av_instance_struct*)instance->pdata;
    kal_uint32 write_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data == NULL)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_RECV_DATA_ERROR);
        return -1;
    }

    NPPLG_AV_LOCK;

    if (plugin_data->file_handle <= 0 || plugin_data->stream != stream)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_RECV_DATA_NO_STREAM, plugin_data->instance_id, offset, len, plugin_data->file_handle);
        NPPLG_AV_UNLOCK;
        return -1;
    }

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_RECV_DATA, plugin_data->instance_id, offset, len);

    if (FS_Write(plugin_data->file_handle, buf, len, &write_len) < 0)
    {
        plugin_data->error = NPPLG_AV_ERROR_FILE;
        NPPLG_AV_UNLOCK;
        return -1;
    }

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
        plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING)
    {
        /* Check if the video is PDL format */
        npplg_av_video_check_pdl_format(plugin_data);
    }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

    NPPLG_AV_UNLOCK;
    return (kal_int32)write_len;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_recv_data_as_file
 * DESCRIPTION
 *  This function is used to provide plug-in instance a local file name for the data from a stream.
 * PARAMETERS
 *  instance        [IN]        Pointer to the plug-in instance
 *  stream          [IN]        Pointer to current stream
 *  fname           [IN]        Pointer to full path to a local file
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_main_recv_data_as_file(NPP instance, NPStream *stream, const kal_char *fname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data = (npplg_av_instance_struct*)instance->pdata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data == NULL)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_RECV_DATA_AS_FILE_ERROR);
        return;
    }

    NPPLG_AV_LOCK;

    if (plugin_data->stream != stream)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_RECV_DATA_AS_FILE_ERROR_MISMATCH, plugin_data->instance_id);
        NPPLG_AV_UNLOCK;
        return;
    }
    
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_RECV_DATA_AS_FILE, plugin_data->instance_id, plugin_data->app_id, fname);

    /*
     * Save the file path to instance data
     * The encoding of the file path is UTF-8
     */
    if (plugin_data->file_path != NULL)
    {
        NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);
    }

    plugin_data->file_path = npplg_av_util_cvt_utf8_to_ucs2(fname, plugin_data->app_id);
    if (plugin_data->file_path == NULL)
    {
        /* Out of memory */
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_RECV_DATA_AS_FILE_NO_MEM);
    }
    else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
    {
        npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
        aud_data->player.file_path = plugin_data->file_path;
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_delete_stream
 * DESCRIPTION
 *  This function is used to provide plug-in instance a local file name for the data from a stream.
 * PARAMETERS
 *  instance        [IN]        Pointer to the plug-in instance
 *  stream          [IN]        Pointer to current stream
 *  reason          [IN]        Reason the stream was destroyed
 * RETURNS
 *  Execution result
 * RETURN VALUE LIST
 *  NPERR_NO_ERROR      Successful
 *  Other error code    Unsuccessful
 *****************************************************************************/
static NPError npplg_av_main_delete_stream(NPP instance, NPStream *stream, NPReason reason)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data = (npplg_av_instance_struct*)instance->pdata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data == NULL)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_DEL_STREAM_ERROR);
        return NPERR_INVALID_INSTANCE_ERROR;
    }

    NPPLG_AV_LOCK;

    if (plugin_data->stream != stream)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_DEL_STREAM_MISMATCH, plugin_data->instance_id, reason);
        NPPLG_AV_UNLOCK;
        return NPERR_GENERIC_ERROR;
    }
    
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_DEL_STREAM, plugin_data->instance_id, reason);

    plugin_data->stream = NULL;

    switch (plugin_data->obj_type)
    {
        case NPPLG_AV_OBJ_TYPE_AUDIO:
            npplg_av_audio_handle_url_rsp(plugin_data, reason);
            break;

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
        case NPPLG_AV_OBJ_TYPE_VIDEO:
            npplg_av_video_handle_url_rsp(plugin_data, reason);
            break;
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__)
        case NPPLG_AV_OBJ_TYPE_STREAMING:
            npplg_av_stream_handle_url_rsp(plugin_data, reason);
            break;
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__) */

        default:
            ASSERT(0);
            break;
    }

    NPPLG_AV_UNLOCK;
    return NPERR_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_handle_url_rsp
 * DESCRIPTION
 *  This function is used to inform the plug-in that the request was completed and supply a reason code for the completion.
 * PARAMETERS
 *  instance        [IN]        Pointer to the plug-in instance
 *  url             [IN]        The request URL
 *  reason          [IN]        Reason code for completion of request
 *  notify_data     [IN]        Plug-in private data for associating the download request and the response
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_main_handle_url_rsp(NPP instance, const kal_char *url, NPReason reason, void *notify_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data = (npplg_av_instance_struct*)instance->pdata; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data == NULL)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_HANDLE_URL_RSP_ERROR);
        return;
    }

    NPPLG_AV_LOCK;
    
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_HANDLE_URL_RSP, plugin_data->instance_id, *((kal_uint32*)notify_data), reason, plugin_data->app_id);

    if (plugin_data->dl_req_id != *((kal_uint32*)notify_data))
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_HANDLE_URL_INVALID_RSP);
        npplg_av_main_free_memory(plugin_data->app_id, notify_data);

        NPPLG_AV_UNLOCK;
        return;
    }

    npplg_av_main_free_memory(plugin_data->app_id, notify_data);

    if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
    {
        switch (plugin_data->obj_type)
        {
            case NPPLG_AV_OBJ_TYPE_AUDIO:
                npplg_av_audio_handle_url_rsp(plugin_data, reason);
                break;

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
            case NPPLG_AV_OBJ_TYPE_VIDEO:
                npplg_av_video_handle_url_rsp(plugin_data, reason);
                break;
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__)
            case NPPLG_AV_OBJ_TYPE_STREAMING:
                npplg_av_stream_handle_url_rsp(plugin_data, reason);
                break;
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__) */

            default:
                ASSERT(0);
                break;
        }
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_handle_mouse_event
 * DESCRIPTION
 *  This function is used to handle mouse event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  event           [IN]        Mouse event
 * RETURNS
 *  Indicate whether the event is handled by plug-in
 * RETURN VALUE LIST
 *  KAL_TRUE            Plug-in handles the event
 *  KAL_FALSE           Plug-in ignores the event
 *****************************************************************************/
static kal_int16 npplg_av_main_handle_mouse_event(npplg_av_instance_struct *plugin_data, npplg_av_evt_mouse_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_obj_control_struct *found_ctrl = NULL;
    kal_int32 i;
    kal_uint8 evt_type, action = 0;
    kal_bool inside_obj = KAL_FALSE;
    kal_int16 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_HANDLE_MOUSE_EVT, plugin_data->instance_id, event->reason, event->x, event->y);
    
    if (event->reason != NPPLG_AV_EVT_MOUSE_DOWN && event->reason != NPPLG_AV_EVT_MOUSE_UP)
    {
        /* Not handle other mouse events */
        return KAL_FALSE;
    }

    if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_TRUE)
    {
        if (plugin_data->suspend == KAL_TRUE)
        {
            /* Plug-in may not receive mouse up event if interrupt comes */
            npplg_av_main_reset_control_state(plugin_data, KAL_FALSE);
        }

        /* Suspend by MMI -> not trigger any action */
        return KAL_FALSE;
    }
    
    /* Check if the position is inside the object */
    if (event->x < plugin_data->width && event->y < plugin_data->height)
    {
        inside_obj = KAL_TRUE;
    }

    /* The handling if play panel is hidden */
    if (plugin_data->play_panel_state == NPPLG_AV_PLAY_PANEL_STATE_HIDE ||
        plugin_data->play_panel_state == NPPLG_AV_PLAY_PANEL_STATE_HIDE_MOUSE_DOWN)
    {
        if (event->reason == NPPLG_AV_EVT_MOUSE_DOWN && inside_obj == KAL_TRUE)
        {
            plugin_data->play_panel_state = NPPLG_AV_PLAY_PANEL_STATE_HIDE_MOUSE_DOWN;
            return KAL_TRUE;
        }
        else if (event->reason == NPPLG_AV_EVT_MOUSE_UP)
        {
            if (plugin_data->play_panel_state == NPPLG_AV_PLAY_PANEL_STATE_HIDE_MOUSE_DOWN)
            {
                if (inside_obj)
                {
                    plugin_data->play_panel_state = NPPLG_AV_PLAY_PANEL_STATE_DISPLAY;
                    
                    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
                    {
                        /*
                         * Plug-in hides audio play panel only when plug-in draws 
                         * processing image.
                         * When plug-in draws processing image, plug-in would stop 
                         * current activity if user touches the object.
                         */
                        npplg_av_main_dispatch_event(plugin_data, NPPLG_AV_INT_EVT_STOP);
                    }
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
#if defined(__MMI_VIDEO_STREAM__)
                    else if ((plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO) ||
                             (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING))
#else /* __MMI_VIDEO_STREAM__ */
                    else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#endif /* __MMI_VIDEO_STREAM__ */
                    {
                        if( plugin_data->control_num == 1)
                        {
                            /*
                             * Video size is too small or too large so there is 
                             * only "Launch media player" control.
                             *
                             * The reason that play panel is hidden in this case 
                             * is user wants to launch media player to play the video.
                             * Therefore, plug-in is downloading the video.
                             * Since there is not "Stop" control so plug-in would 
                             * stop the data retrieval if user clicks the video object.
                             */
                            npplg_av_main_dispatch_event(plugin_data, NPPLG_AV_INT_EVT_STOP);
                        }
                        else
                        {
                            /*
                             * If inline audio/video plug-in starts to play the 
                             * video, plug-in will hide the playback/volume control 
                             * after a short period.
                             *
                             * If user presses key to let virtual cursor click the 
                             * object or touches the object when browser is playing 
                             * video, browser will show playback/volume control 
                             * again and hide the control after a short period.
                             */
                            npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

                            if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
                            {
                                mdi_video_ply_get_cur_play_time(&vdo_data->play_time);
                            }
#ifdef __MMI_VIDEO_STREAM__
                            else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
                            {
                                mdi_video_stream_get_cur_play_time(&vdo_data->play_time);
                            }
#endif /* __MMI_VIDEO_STREAM__ */

                            npplg_av_util_invalidate_rect(plugin_data, NULL);
                            npplg_av_main_start_timer(plugin_data,
                                                      NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR,
                                                      NPPLG_AV_UPDATE_PROGRESS_BAR_INTERVAL);
                            npplg_av_main_start_timer(plugin_data,
                                                      NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL,
                                                      NPPLG_AV_CFG_VDO_HIDE_PLAY_PANEL_AFTER_PLAY_TIME);
                        }
                    }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
                }
                else
                {
                    plugin_data->play_panel_state = NPPLG_AV_PLAY_PANEL_STATE_HIDE;
                }
                
                return KAL_TRUE;
            }
        }
        
        return KAL_FALSE;
    }

    /* Find the pressed control */
    for (i = 0; i < plugin_data->control_num; i++)
    {
        if (event->x >= plugin_data->control_list[i]->x &&
            event->x < (plugin_data->control_list[i]->x + plugin_data->control_list[i]->width - 1) &&
            event->y >= plugin_data->control_list[i]->y &&
            event->y < (plugin_data->control_list[i]->y + plugin_data->control_list[i]->height - 1))
        {
            found_ctrl = plugin_data->control_list[i];
            break;
        }
    }

#ifdef NPPLG_AV_CFG_PLAY_ANYWHERE
    if (found_ctrl == NULL && inside_obj == KAL_TRUE)
    {
        /* The empty area -> trigger the action of empty_control */
        found_ctrl = plugin_data->empty_control;
    }
#endif

    if (event->reason == NPPLG_AV_EVT_MOUSE_DOWN)
    {
        if (plugin_data->pressed_control != NULL)
        {
            npplg_av_main_reset_control_state(plugin_data, KAL_TRUE);
        }

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
        if (inside_obj)
        {
            /* Stop hide play panel */
            npplg_av_main_stop_timer(plugin_data, NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL);
        }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

        if (found_ctrl != NULL)
        {
            if (found_ctrl->type == NPPLG_AV_CTRL_TYPE_MUTE ||
                found_ctrl->display == NPPLG_AV_CTRL_DISP_ENABLE)
            {
                plugin_data->pressed_control = found_ctrl;
                found_ctrl->pressed = KAL_TRUE;
                npplg_av_util_invalidate_rect(plugin_data, found_ctrl);
                if ((found_ctrl->type == NPPLG_AV_CTRL_TYPE_FAST_FORWARD) ||
                    (found_ctrl->type == NPPLG_AV_CTRL_TYPE_REWIND))
                {
                    /* Issue seek start event */
                    evt_type = npplg_av_main_cvt_ctrl_type_to_evt(found_ctrl->type, KAL_TRUE);

                    if (evt_type != NPPLG_AV_INT_EVT_UNKNOWN)
                    {
                        npplg_av_main_dispatch_event(plugin_data, evt_type);
                    }
                }
            }

            return KAL_TRUE;
        }
    }
    else if (event->reason == NPPLG_AV_EVT_MOUSE_UP)
    {
        /* Hide play panel if object is video and state is playing */
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#ifdef __MMI_VIDEO_STREAM__
        if ((plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO && plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING) ||
            (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING && plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING))
#else
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO && plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_PLAYING)
#endif /* __MMI_VIDEO_STREAM__ */
        {
            npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
            if (npplg_av_main_check_timer_start(plugin_data, NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL) == KAL_FALSE &&
                vdo_data->audio_only == KAL_FALSE)
            {
                npplg_av_main_start_timer(plugin_data,
                                          NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL,
                                          NPPLG_AV_CFG_VDO_HIDE_PLAY_PANEL_AFTER_PLAY_TIME);
            }
        }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

        if ((found_ctrl == NULL) ||
            (found_ctrl && (found_ctrl->pressed == KAL_FALSE)))
        {
            /* Should reset the state of the pressed control */            
            ret = npplg_av_main_reset_control_state(plugin_data, KAL_TRUE);
            return ret;
        }
        else
        {
            plugin_data->pressed_control = NULL;
            
            if (found_ctrl->type == NPPLG_AV_CTRL_TYPE_MUTE)
            {
                found_ctrl->display = ((found_ctrl->display == NPPLG_AV_CTRL_DISP_ENABLE) ?
                                       NPPLG_AV_CTRL_DISP_DISABLE :
                                       NPPLG_AV_CTRL_DISP_ENABLE);
            }
            
            found_ctrl->pressed = KAL_FALSE;
            npplg_av_util_invalidate_rect(plugin_data, found_ctrl);

            if (found_ctrl->type == NPPLG_AV_CTRL_TYPE_MUTE)
            {
                if (found_ctrl->display == NPPLG_AV_CTRL_DISP_ENABLE)
                {
                    plugin_data->mute = KAL_FALSE;
                }
                else
                {
                    plugin_data->mute = KAL_TRUE;
                }

                if (plugin_data == g_npplg_av_context.app_cnxt[plugin_data->app_id].active_instance)
                {
                    g_npplg_av_context.app_cnxt[plugin_data->app_id].mute = plugin_data->mute;

                    if (!plugin_data->mute)
                    {
                        if (g_npplg_av_context.app_cnxt[plugin_data->app_id].volume == 0)
                        {
                            g_npplg_av_context.app_cnxt[plugin_data->app_id].volume = 1;
                        }

                        if (g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_OCCUPIED)
                        {
                            action |= NPPLG_AV_ACTION_SET_VOLUME;
                        }
                    }

                    if (g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_OCCUPIED)
                    {
                        action |= NPPLG_AV_ACTION_SET_MUTE;
                    }

                    if (action != 0)
                    {
                        npplg_av_util_send_notify_mmi_ind(kal_get_active_module_id(),
                                                          plugin_data->instance_id,
                                                          plugin_data->app_id,
                                                          action);
                    }
                }
            }
            else
            {
                evt_type = npplg_av_main_cvt_ctrl_type_to_evt(found_ctrl->type, found_ctrl->pressed);
                
                if ((evt_type == NPPLG_AV_INT_EVT_PLAY ||
                     evt_type == NPPLG_AV_INT_EVT_LAUNCH_MEDIA_PLAYER) &&
                     g_npplg_av_context.app_cnxt[plugin_data->app_id].active_instance != NULL &&
                     plugin_data != g_npplg_av_context.app_cnxt[plugin_data->app_id].active_instance)
                {
                    /* Already have one active instance, plug-in should first stop it */
                    g_npplg_av_context.app_cnxt[plugin_data->app_id].interrupt_instance = plugin_data;
                    g_npplg_av_context.app_cnxt[plugin_data->app_id].interrupt_event = evt_type;

                    /* Stop currently playing audio/video */
                    npplg_av_main_dispatch_event(g_npplg_av_context.app_cnxt[plugin_data->app_id].active_instance, NPPLG_AV_INT_EVT_STOP);
                }
                else if (evt_type != NPPLG_AV_INT_EVT_UNKNOWN)
                {
                    /* Dispatch event */
                    npplg_av_main_dispatch_event(plugin_data, evt_type);
                }
            }

            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_handle_key_event
 * DESCRIPTION
 *  This function is used to handle key event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  event           [IN]        Key event
 * RETURNS
 *  Indicate whether the event is handled by plug-in
 * RETURN VALUE LIST
 *  KAL_TRUE            Plug-in handles the event
 *  KAL_FALSE           Plug-in ignores the event
 *****************************************************************************/
static kal_int16 npplg_av_main_handle_key_event(npplg_av_instance_struct *plugin_data, npplg_av_evt_key_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_HANDLE_KEY_EVT, plugin_data->instance_id, event->key);

    /* Up/down/left/right arrow keys are used to browse the web page so A/V Plug-in does not need to handle key event */
    
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_handle_paint_event
 * DESCRIPTION
 *  This function is used to handle paint event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  event           [IN]        Paint event
 * RETURNS
 *  Indicate whether the event is handled by plug-in
 * RETURN VALUE LIST
 *  KAL_TRUE            Plug-in handles the event
 *  KAL_FALSE           Plug-in ignores the event
 *****************************************************************************/
static kal_int16 npplg_av_main_handle_paint_event(npplg_av_instance_struct *plugin_data, npplg_av_evt_paint_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP,
              NPPLG_AV_HANDLE_PAINT_EVT,
              plugin_data->instance_id,
              event->paint_area.x,
              event->paint_area.y,
              event->paint_area.w,
              event->paint_area.h);

    event->paint_area.x += plugin_data->x;
    event->paint_area.y += plugin_data->y;

    npplg_av_util_draw_controls(plugin_data, event->gdi_layer, event->paint_area);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_handle_timer_event
 * DESCRIPTION
 *  This function is used to handle timer timeout event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  event           [IN]        Timer event
 * RETURNS
 *  Indicate whether the event is handled by plug-in
 * RETURN VALUE LIST
 *  KAL_TRUE            Plug-in handles the event
 *  KAL_FALSE           Plug-in ignores the event
 *****************************************************************************/
static kal_int16 npplg_av_main_handle_timer_event(npplg_av_instance_struct *plugin_data, npplg_av_evt_timer_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 timer_type;
    npplg_av_timer_struct *timer_node;
    kal_int16 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    timer_node = npplg_av_main_get_timer_by_id(plugin_data, event->timer_id);
    
    /* Check the timer id is right */
    if (timer_node == NULL)
    {
        NPPLG_AV_UNLOCK;
        return KAL_FALSE;
    }

    if (timer_node->valid == KAL_FALSE ||
        g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_TRUE)
    {
        /*
         * Not handle timer event if
         * 1. timer node is invalid
         * 2. suspend by MMI
         */
        MMI_TRACE(NPPLG_AV_TRC_GROUP,
                  NPPLG_AV_HANDLE_INVALID_TIMER_EVT,
                  timer_node->timer_type,
                  plugin_data->instance_id,
                  plugin_data->obj_type,
                  plugin_data->state,
                  timer_node->valid,
                  g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi);

        NPPLG_AV_MEM_FREE(plugin_data->app_id, timer_node);
        NPPLG_AV_UNLOCK;
        return KAL_TRUE;
    }

    timer_type = timer_node->timer_type;
    NPPLG_AV_MEM_FREE(plugin_data->app_id, timer_node);

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_HANDLE_TIMER_EVT, timer_type, plugin_data->instance_id, plugin_data->obj_type, plugin_data->state);
    
    /* Dispatch according to object type */
    switch (plugin_data->obj_type)
    {
        case NPPLG_AV_OBJ_TYPE_AUDIO:
        {
            ret = npplg_av_audio_handle_timer_event(plugin_data, timer_type);
            break;
        }

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
        case NPPLG_AV_OBJ_TYPE_VIDEO:
        {
            ret = npplg_av_video_handle_timer_event(plugin_data, timer_type);
            break;
        }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__)
        case NPPLG_AV_OBJ_TYPE_STREAMING:
        {
            ret = npplg_av_stream_handle_timer_event(plugin_data, timer_type);
            break;
        }
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__) */

        default:
        {
            ASSERT(0);
            ret = KAL_FALSE;
            break;
        }
    }

    NPPLG_AV_UNLOCK;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_handle_activate_event
 * DESCRIPTION
 *  This function is used to handle ACTIVATE event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  event           [IN]        ACTIVATE event
 * RETURNS
 *  Indicate whether the event is handled by plug-in
 * RETURN VALUE LIST
 *  KAL_TRUE            Plug-in handles the event
 *  KAL_FALSE           Plug-in ignores the event
 *****************************************************************************/
static kal_int16 npplg_av_main_handle_activate_event(npplg_av_instance_struct *plugin_data, npplg_av_evt_activate_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool visual_update;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_HANDLE_ACTIVATE_EVT, plugin_data->instance_id, event->activate);

    visual_update = KAL_FALSE;

    if (plugin_data->active == KAL_TRUE && event->activate == KAL_FALSE)
    {
        plugin_data->active = event->activate;

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#ifdef __MMI_VIDEO_STREAM__
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO || plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
#else
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#endif /* __MMI_VIDEO_STREAM__ */
        {
            npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

            vdo_data->lcm_update = KAL_FALSE;
            visual_update = KAL_TRUE;
        }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    }
    else if (plugin_data->active == KAL_FALSE && event->activate == KAL_TRUE)
    {
        plugin_data->active = event->activate;

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#ifdef __MMI_VIDEO_STREAM__
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO || plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
#else
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#endif /* __MMI_VIDEO_STREAM__ */
        {
            npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

            vdo_data->lcm_update = KAL_TRUE;
            visual_update = KAL_TRUE;
        }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    }

    if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE &&
        plugin_data == npplg_av_main_get_active_instance(plugin_data->app_id) &&
        visual_update == KAL_TRUE)
    {
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
        npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
        {
            npplg_av_video_visual_update(plugin_data, npplg_av_main_decide_video_visual_update(plugin_data->app_id, vdo_data->lcm_update), KAL_TRUE);
        }
#ifdef __MMI_VIDEO_STREAM__
        else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
        {
            npplg_av_stream_visual_update(plugin_data, npplg_av_main_decide_video_visual_update(plugin_data->app_id, vdo_data->lcm_update), KAL_TRUE);
        }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_handle_focus_event
 * DESCRIPTION
 *  This function is used to handle FOCUS event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  event           [IN]        FOCUS event
 * RETURNS
 *  Indicate whether the event is handled by plug-in
 * RETURN VALUE LIST
 *  KAL_TRUE            Plug-in handles the event
 *  KAL_FALSE           Plug-in ignores the event
 *****************************************************************************/
static kal_int16 npplg_av_main_handle_focus_event(npplg_av_instance_struct *plugin_data, npplg_av_evt_focus_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_HANDLE_FOCUS_EVT, plugin_data->instance_id, event->focus);
    
    if (event->focus == KAL_FALSE)
    {
        npplg_av_main_reset_control_state(plugin_data, KAL_TRUE);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_handle_scroll_event
 * DESCRIPTION
 *  This function is used to handle SCREEN_SCROLLED event.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  Indicate whether the event is handled by plug-in
 * RETURN VALUE LIST
 *  KAL_TRUE            Plug-in handles the event
 *  KAL_FALSE           Plug-in ignores the event
 *****************************************************************************/
static kal_int16 npplg_av_main_handle_scroll_event(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_HANDLE_SCROLL_EVT, plugin_data->instance_id);
    
    /* Only need to update the position of video layer if object is video */
        
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
#if defined(__MMI_VIDEO_STREAM__)
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING ||
        plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#else
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#endif /* __MMI_VIDEO_STREAM__ */
    {
        npplg_av_video_set_position(plugin_data);
    }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_cvt_ctrl_type_to_evt
 * DESCRIPTION
 *  This function is used to get the event type according to the control type.
 * PARAMETERS
 *  ctrl_type       [IN]        Control type
 *  pressed         [IN]        The control is pressed or not
 * RETURNS
 *  Event type
 *****************************************************************************/
static kal_uint8 npplg_av_main_cvt_ctrl_type_to_evt(kal_uint8 ctrl_type, kal_bool pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ctrl_type)
    {
        case NPPLG_AV_CTRL_TYPE_PLAY:
            return NPPLG_AV_INT_EVT_PLAY;

        case NPPLG_AV_CTRL_TYPE_PAUSE:
            return NPPLG_AV_INT_EVT_PAUSE;

        case NPPLG_AV_CTRL_TYPE_STOP:
            return NPPLG_AV_INT_EVT_STOP;

        case NPPLG_AV_CTRL_TYPE_FAST_FORWARD:
        {
            if (pressed)
            {
                return NPPLG_AV_INT_EVT_FAST_FORWARD_START;
            }
            else
            {
                return NPPLG_AV_INT_EVT_FAST_FORWARD_STOP;
            }
        }

        case NPPLG_AV_CTRL_TYPE_REWIND:
        {
            if (pressed)
            {
                return NPPLG_AV_INT_EVT_REWIND_START;
            }
            else
            {
                return NPPLG_AV_INT_EVT_REWIND_STOP;
            }
        }

        case NPPLG_AV_CTRL_TYPE_MEDIA_PLAYER:
            return NPPLG_AV_INT_EVT_LAUNCH_MEDIA_PLAYER;

        default:
            return NPPLG_AV_INT_EVT_UNKNOWN;
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_cvt_mmi_screen_rotate_to_mdi
 * DESCRIPTION
 *  This function is used to convert mmi_frm_screen_rotate_enum to MDI enum.
 * PARAMETERS
 *  lcd_orientation     [IN]        LCD orientation
 * RETURNS
 *  MDI enum of LCD orientation
 *****************************************************************************/
static kal_uint8 npplg_av_main_cvt_mmi_screen_rotate_to_mdi(kal_int32 lcd_orientation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lcd_orientation)
    {
        case MMI_FRM_SCREEN_ROTATE_0:
        {
            return MDI_VIDEO_LCD_ROTATE_0;
        }

        case MMI_FRM_SCREEN_ROTATE_90:
        {
            return MDI_VIDEO_LCD_ROTATE_90;
        }

        case MMI_FRM_SCREEN_ROTATE_180:
        {
            return MDI_VIDEO_LCD_ROTATE_180;
        }

        case MMI_FRM_SCREEN_ROTATE_270:
        {
            return MDI_VIDEO_LCD_ROTATE_270;
        }

        default:
        {
            ASSERT(0);
        }
    }

    return MDI_VIDEO_LCD_ROTATE_0;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_dispatch_event
 * DESCRIPTION
 *  This function is used to dispatch event to plug-in instance.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  event           [IN]        Event
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_main_dispatch_event(npplg_av_instance_struct *plugin_data, kal_uint8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_DISPATCH_EVT, plugin_data->instance_id, plugin_data->obj_type, plugin_data->state, event);

    if (g_npplg_av_context.is_speech_mode)
    {
        g_npplg_av_context.is_speech_mode = (kal_bool)mdi_audio_is_speech_mode();
    }

#ifdef __COSMOS_MMI_PACKAGE__
    if ((event == NPPLG_AV_INT_EVT_PLAY || event == NPPLG_AV_INT_EVT_AUTO_PLAY) && g_npplg_av_context.is_speech_mode == KAL_TRUE)
#else
    if (event == NPPLG_AV_INT_EVT_PLAY && g_npplg_av_context.is_speech_mode == KAL_TRUE)
#endif
    {
        /* Do not dispatch play event if in call */
#ifdef __COSMOS_MMI_PACKAGE__
        npplg_av_main_display_popup(plugin_data, STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL);
#endif
        return;
    }
    
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
    {
        npplg_av_audio_handle_event(plugin_data, event);
    }
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
    {
        npplg_av_video_handle_event(plugin_data, event);
    }
#endif
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__)
    else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
    {
        npplg_av_stream_handle_event(plugin_data, event);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_print
 * DESCRIPTION
 *  Dummy function
 * PARAMETERS
 *  instance        [IN]        Pointer to the plug-in instance
 *  platform_print  [IN]        Pointer to the NPPrint structure
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_print(NPP instance, NPPrint *platform_print)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Do nothing */
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_clear_folder
 * DESCRIPTION
 *  This function is used to delete all files in the plug-in folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_main_clear_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar folder_name[NPPLG_AV_MAX_FOLDER_LEN];
    FS_HANDLE file_handle;
    NPError   result = NPERR_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_CLEAR_FOLDER_START);

    /*
     * Delete all files in the plug-in folder if plug-in folder exists
     * Create plug-in folder and set the folder as hidden
     */
    g_npplg_av_context.drive_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE);
    memset(folder_name, 0, sizeof(kal_wchar) * NPPLG_AV_MAX_FOLDER_LEN);
    if (g_npplg_av_context.drive_letter >= FS_NO_ERROR)
    {
        kal_wsprintf(folder_name, "%c:\\%s", g_npplg_av_context.drive_letter, NPPLG_AV_TMP_FILE_PATH);
        file_handle = FS_CreateDir((WCHAR*)folder_name);

        if (file_handle < 0)
        {
            if (file_handle == FS_FILE_EXISTS)
            {
                file_handle = FS_XDelete((WCHAR*)folder_name, 
                                         FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, 
                                         NULL,
                                         0);

                if (file_handle < 0)
                {
                    result = NPERR_INVALID_PLUGIN_DIR_ERROR;
                }
                else
                {
                    if (FS_CreateDir((WCHAR*)folder_name) < 0)
                    {
                        result = NPERR_INVALID_PLUGIN_DIR_ERROR;
                    }
                }
            }
            else
            {
                result = NPERR_INVALID_PLUGIN_DIR_ERROR;                    
            }
        }
    }
    else
    {
        result = NPERR_INVALID_PLUGIN_DIR_ERROR;
    }

    if (result == NPERR_NO_ERROR)
    {
        FS_SetAttributes((WCHAR*)folder_name, FS_ATTR_DIR | FS_ATTR_HIDDEN);        
    }

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_CLEAR_FOLDER_FIN, result);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_create_file
 * DESCRIPTION
 *  This function is used to generate filepath and open file.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  flag            [IN]        Open file flag
 * RETURNS
 *  Execution result
 *****************************************************************************/
static NPError npplg_av_main_create_file(npplg_av_instance_struct *plugin_data, kal_uint32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_data_struct *aud_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->file_path != NULL)
    {
        NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);
    }

    /* Generate filepath */
    plugin_data->file_path = npplg_av_util_gen_filename(plugin_data->app_id,
                                                        plugin_data->instance_id,
                                                        g_npplg_av_context.drive_letter,
                                                        plugin_data->url,
                                                        plugin_data->mime_type);
    if (plugin_data->file_path == NULL)
    {
        return NPERR_OUT_OF_MEMORY_ERROR;
    }
    else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
    {
        aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
        aud_data->player.file_path = plugin_data->file_path;
    }

    /* Open file */
    plugin_data->file_handle = FS_Open(plugin_data->file_path, flag);
    if (plugin_data->file_handle <= 0)
    {
        NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
        {
            aud_data->player.file_path = NULL;
        }
        return NPERR_INVALID_PLUGIN_DIR_ERROR;
    }

    return NPERR_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_reset_context
 * DESCRIPTION
 *  This function is used to reset the context of A/V Plug-in.
 * PARAMETERS
 *  app_id      [IN]        Application id which is used to represent plug-in's user
 *  reset_all   [IN]        Reset all fields or just some fields
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_main_reset_context(kal_int32 app_id, kal_bool reset_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    g_npplg_av_context.app_cnxt[app_id].vdo_layer_handle = GDI_NULL_HANDLE;
    g_npplg_av_context.app_cnxt[app_id].vdo_layer_buf = NULL;
    g_npplg_av_context.app_cnxt[app_id].rotate = MDI_VIDEO_LCD_ROTATE_0;
#endif
    g_npplg_av_context.app_cnxt[app_id].instance_num = 0;
    g_npplg_av_context.app_cnxt[app_id].auto_play_queue = NULL;
    g_npplg_av_context.app_cnxt[app_id].active_instance = NULL;
    g_npplg_av_context.app_cnxt[app_id].interrupt_instance = NULL;
    g_npplg_av_context.app_cnxt[app_id].interrupt_event = NPPLG_AV_INT_EVT_UNKNOWN;
    g_npplg_av_context.app_cnxt[app_id].mod_id = MOD_NIL;
    g_npplg_av_context.app_cnxt[app_id].mimic_mod_id = MOD_NIL;
    g_npplg_av_context.app_cnxt[app_id].is_suspend_by_mmi = KAL_FALSE;
    g_npplg_av_context.app_cnxt[app_id].lcm_update = KAL_TRUE;

    /* User may adjust volume so plug-in needs to maintain the volume setting */
    if (reset_all)
    {
        g_npplg_av_context.app_cnxt[app_id].mute = KAL_FALSE;
        g_npplg_av_context.app_cnxt[app_id].volume = (MDI_MAX_VOLUME_LEVEL >> 1);
    }

    NPPLG_AV_APP_ENTER_STATE(app_id, g_npplg_av_context.app_cnxt[app_id].state, NPPLG_AV_USER_STATE_TERMINATED);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_free_instance_data
 * DESCRIPTION
 *  This function is used to free memory used by plug-in instance.
 * PARAMETERS
 *  plugin_data     [IN]            Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_main_free_instance_data(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
    {
        npplg_av_audio_free_data(plugin_data, plugin_data->obj_data);
    }

    /* Close file */
    if (plugin_data->file_handle > 0)
    {
        FS_Close(plugin_data->file_handle);
    }

    /* Delete audio/video file */
    if (plugin_data->file_path != NULL)
    {
        FS_Delete(plugin_data->file_path);
    }

    npplg_av_util_free_control_list(plugin_data);
    
    NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->file_path);
    NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->mime_type);
    NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->obj_data);
    NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data->url);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_redraw_window
 * DESCRIPTION
 *  This function is used to draw the playback control because window is changed.
 *  If the object is video, plug-in would stop video playing first.
 *  Plug-in may play the video again according to new size and new coordinates.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  window          [IN]        Pointer to the window into which the instance draws
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_main_redraw_window(npplg_av_instance_struct *plugin_data, NPWindow *window)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plugin_data->width = window->width;
    plugin_data->height = window->height;
    plugin_data->x = window->x;
    plugin_data->y = window->y;
    plugin_data->clip_region = window->clipRect;

    switch (plugin_data->obj_type)
    {
        case NPPLG_AV_OBJ_TYPE_AUDIO:
        {
            npplg_av_audio_redraw_window(plugin_data);
            break;
        }

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#ifdef __MMI_VIDEO_STREAM__
        case NPPLG_AV_OBJ_TYPE_STREAMING:
#endif /* __MMI_VIDEO_STREAM__*/
        case NPPLG_AV_OBJ_TYPE_VIDEO:
        {
            npplg_av_video_redraw_window(plugin_data);
            break;
        }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

        default:
            ASSERT(0);
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_image_dimension
 * DESCRIPTION
 *  This function is used to calculate the icon width/height and progress bar height.
 *  The values will be used to decide the play panel layout.
 * PARAMETERS
 *  void
 * RETURNS
 *  Already get image dimension or not
 * RETURN VALUE LIST
 *  void
 *****************************************************************************/
static void npplg_av_main_get_image_dimension(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *icon;
    kal_int32 bar_width, line_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon = (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PLAY);
    gdi_image_get_dimension(icon, &(g_npplg_av_context.icon_width), &(g_npplg_av_context.icon_height));

    icon = (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_PROGRESS_BG);
    gdi_image_get_dimension(icon, &bar_width, &(g_npplg_av_context.bar_height));

    icon = (kal_uint8*)GetImage(IMG_ID_NPPLG_AV_CTRL_SEPARATE_LINE);
    gdi_image_get_dimension(icon, &(g_npplg_av_context.separate_width), &line_height);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_timer_by_id
 * DESCRIPTION
 *  Get the timer from list
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  timer_id        [IN]        Timer id
 * RETURNS
 *  Timer node
 *****************************************************************************/
static npplg_av_timer_struct *npplg_av_main_get_timer_by_id(npplg_av_instance_struct *plugin_data, kal_int32 timer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_timer_struct *timer_node, *prev_timer, *curr_timer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    timer_node = NULL;
    
    if (plugin_data->timer_list->timer_id == timer_id)
    {
        timer_node = plugin_data->timer_list;
        plugin_data->timer_list = timer_node->next;
        timer_node->next = NULL;
    }
    else
    {
        prev_timer = curr_timer = plugin_data->timer_list;
        while (curr_timer != NULL)
        {
            if (curr_timer->timer_id == timer_id)
            {
                timer_node = curr_timer;
                prev_timer->next = curr_timer->next;
                timer_node->next = NULL;
                break;
            }
            prev_timer = curr_timer;
            curr_timer = curr_timer->next;
        }
    }

    return timer_node;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_req_id
 * DESCRIPTION
 *  This function is used to get unique request id.
 * PARAMETERS
 *  void
 * RETURNS
 *  Request id
 *****************************************************************************/
static kal_uint32 npplg_av_main_get_req_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;
    
    if (g_npplg_av_req_id == NPPLG_AV_MAX_UINT32)
    {
        g_npplg_av_req_id = 0;
    }

    g_npplg_av_req_id++;
    
    NPPLG_AV_UNLOCK;
    return g_npplg_av_req_id;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_create_folder
 * DESCRIPTION
 *  Create @avplugin folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void npplg_av_main_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar folder_name[NPPLG_AV_MAX_FOLDER_LEN];
    FS_HANDLE file_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(folder_name, 0, sizeof(kal_wchar) * NPPLG_AV_MAX_FOLDER_LEN);
    kal_wsprintf(folder_name, "%c:\\%s", g_npplg_av_context.drive_letter, NPPLG_AV_TMP_FILE_PATH);

    if(FS_GetAttributes((const WCHAR*)folder_name) < 0)
    {
        file_handle = FS_CreateDir((const WCHAR*)folder_name);
        if (file_handle >= 0 || (file_handle < 0 && file_handle == FS_FILE_EXISTS))
        {
            FS_SetAttributes((WCHAR*)folder_name, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_is_instance_in_list
 * DESCRIPTION
 *  Check whether plug-in instance is in the list
 * PARAMETERS
 *  list            [IN]        Application's list
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  Is instance in the list or not
 *****************************************************************************/
static kal_bool npplg_av_main_is_instance_in_list(npplg_av_instance_list_struct *list, npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_list_struct *cur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur = list;

    while (cur != NULL)
    {
        if (cur->instance == plugin_data)
        {
            return KAL_TRUE;
        }

        cur = cur->next;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_add_instance_into_list
 * DESCRIPTION
 *  Add plug-in instance to app's list
 * PARAMETERS
 *  list            [IN]        Application's list
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  Add plug-in instance to list successfully or not
 *****************************************************************************/
static kal_bool npplg_av_main_add_instance_into_list(npplg_av_instance_list_struct **list, npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_list_struct *cur, *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*list == NULL)
    {
        cur = (npplg_av_instance_list_struct*)g_npplg_av_netscape_funcs[plugin_data->app_id].memalloc(sizeof(npplg_av_instance_list_struct));

        if (cur == NULL)
        {
            return KAL_FALSE;
        }
        
        cur->instance = plugin_data;
        cur->next = NULL;

        *list = cur;
    }
    else
    {
        cur = *list;
        while (cur != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        
        prev->next = (npplg_av_instance_list_struct*)g_npplg_av_netscape_funcs[plugin_data->app_id].memalloc(sizeof(npplg_av_instance_list_struct));

        if (prev->next == NULL)
        {
            return KAL_FALSE;
        }

        prev->next->instance = plugin_data;
        prev->next->next = NULL;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_instance_from_list
 * DESCRIPTION
 *  Get plug-in instance from app's list
 * PARAMETERS
 *  instance_id     [IN]        Plug-in instance id
 *  app_id          [IN]        Application id
 * RETURNS
 *  Plug-in instance
 *****************************************************************************/
static npplg_av_instance_struct* npplg_av_main_get_instance_from_list(kal_uint32 instance_id, kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_list_struct *curr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr = g_npplg_av_context.app_cnxt[app_id].instance_list;
    while (curr != NULL)
    {
        if (curr->instance->instance_id == instance_id)
        {
            return curr->instance;
        }
        curr = curr->next;
    }

    return NULL;
}


/************************************************************
 * Global Function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_initialize
 * DESCRIPTION
 *  This function is used to initialize A/V Plug-in.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_INIT);

    memset(&g_npplg_av_context, 0, sizeof(npplg_av_context_struct));

    npplg_av_util_init_mutex_lock();

    /* Get the icon width/height and progress bar width/height */
    npplg_av_main_get_image_dimension();

    /* Delete all files in A/V Plug-in folder */
    npplg_av_main_clear_folder();

    /* Initialize the context of each plug-in' user */
    for (i = 0; i < NPPLG_AV_APP_ID_TOTAL; i++)
    {
        npplg_av_main_reset_context(i, KAL_TRUE);
    }

#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
    g_npplg_av_context.blt_layer_flag = NPPLG_AV_BLT_LAYER_FLAG;
    g_npplg_av_context.hw_layer_flag = NPPLG_AV_VDO_PLAY_LAYER_FLAG;
#endif

    /* Register the handler of MSG_ID_NPPLG_AV_LAUNCH_MEDIA_PLAYER_IND */
    mmi_frm_set_protocol_event_handler(MSG_ID_NPPLG_AV_LAUNCH_MEDIA_PLAYER_IND, npplg_av_main_launch_media_player_handler, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_NPPLG_AV_RESUME_BACKGROUND_PLAY_IND, npplg_av_main_resume_background_play, KAL_FALSE);    
    mmi_frm_set_protocol_event_handler(MSG_ID_NPPLG_AV_NOTIFY_MMI_IND, npplg_av_main_notify_mmi_ind_handler, KAL_FALSE);    
    mmi_frm_set_protocol_event_handler(MSG_ID_NPPLG_AV_SUSPEND_BACKGROUND_PLAY_REQ, npplg_av_main_suspend_background_play_req_handler, KAL_FALSE);
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
    mmi_frm_set_protocol_event_handler(MSG_ID_NPPLG_AV_CREATE_VDO_LAYER_REQ, npplg_av_main_create_vdo_layer_req_handler, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_NPPLG_AV_FREE_VDO_LAYER_IND, npplg_av_main_free_vdo_layer_ind_handler, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_NPPLG_AV_UPDATE_VDO_LAYER_IND, npplg_av_main_update_vdo_layer_ind_handler, KAL_FALSE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_user_initialize
 * DESCRIPTION
 *  This function is used to get information from plug-in's user and provide information to plug-in's user.
 * PARAMETERS
 *  ns_table        [IN]            The browser side Plug-in APIs
 *  plugin_func     [OUT]           The plug-in side Plug-in APIs
 *  app_id          [IN]            Application id
 * RETURNS
 *  The initialization result
 * RETURN VALUE LIST
 *  NPERR_NO_ERROR      Initialize successfully
 *  Other error code    Failed to initialize
 *****************************************************************************/
NPError npplg_av_main_user_initialize(NPNetscapeFuncs *ns_table,
                                      NPPluginFuncs *plugin_func,
                                      NPluginMTKExtFuncs *ext_func,
                                      kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_APP_INIT_BEGIN, app_id);

    /* Check input parameter */
    if ((ns_table == NULL) ||
        (plugin_func == NULL) ||
        (ns_table->size < sizeof(NPNetscapeFuncs)) ||
        (plugin_func->size < sizeof(NPPluginFuncs)))
    {
        ASSERT(0);
        return NPERR_INVALID_FUNCTABLE_ERROR;
    }
    
    NPPLG_AV_LOCK;

    /*
     * Fill Netscape function table
     * Because Google Gadget may also use A/V Plug-in, netscape function table is an array
     */
    g_npplg_av_netscape_funcs[app_id].size                  = ns_table->size;
    g_npplg_av_netscape_funcs[app_id].version               = ns_table->version;
    g_npplg_av_netscape_funcs[app_id].geturl                = ns_table->geturl;
    g_npplg_av_netscape_funcs[app_id].posturl               = ns_table->posturl;
    g_npplg_av_netscape_funcs[app_id].requestread           = ns_table->requestread;
    g_npplg_av_netscape_funcs[app_id].newstream             = ns_table->newstream;
    g_npplg_av_netscape_funcs[app_id].write                 = ns_table->write;
    g_npplg_av_netscape_funcs[app_id].destroystream         = ns_table->destroystream;
    g_npplg_av_netscape_funcs[app_id].status                = ns_table->status;
    g_npplg_av_netscape_funcs[app_id].uagent                = ns_table->uagent;
    g_npplg_av_netscape_funcs[app_id].memalloc              = ns_table->memalloc;
    g_npplg_av_netscape_funcs[app_id].memfree               = ns_table->memfree;
    g_npplg_av_netscape_funcs[app_id].memflush              = ns_table->memflush;
    g_npplg_av_netscape_funcs[app_id].reloadplugins         = ns_table->reloadplugins;
    g_npplg_av_netscape_funcs[app_id].getJavaEnv            = ns_table->getJavaEnv;
    g_npplg_av_netscape_funcs[app_id].getJavaPeer           = ns_table->getJavaPeer;
    g_npplg_av_netscape_funcs[app_id].geturlnotify          = ns_table->geturlnotify;
    g_npplg_av_netscape_funcs[app_id].posturlnotify         = ns_table->posturlnotify;
    g_npplg_av_netscape_funcs[app_id].getvalue              = ns_table->getvalue;
    g_npplg_av_netscape_funcs[app_id].setvalue              = ns_table->setvalue;
    g_npplg_av_netscape_funcs[app_id].invalidaterect        = ns_table->invalidaterect;
    g_npplg_av_netscape_funcs[app_id].invalidateregion      = ns_table->invalidateregion;    
    g_npplg_av_netscape_funcs[app_id].forceredraw           = ns_table->forceredraw;
    g_npplg_av_netscape_funcs[app_id].getstringidentifier   = ns_table->getstringidentifier;
    g_npplg_av_netscape_funcs[app_id].getstringidentifiers  = ns_table->getstringidentifiers;
    g_npplg_av_netscape_funcs[app_id].getintidentifier      = ns_table->getintidentifier;
    g_npplg_av_netscape_funcs[app_id].identifierisstring    = ns_table->identifierisstring;
    g_npplg_av_netscape_funcs[app_id].utf8fromidentifier    = ns_table->utf8fromidentifier;
    g_npplg_av_netscape_funcs[app_id].intfromidentifier     = ns_table->intfromidentifier;
    g_npplg_av_netscape_funcs[app_id].createobject          = ns_table->createobject;
    g_npplg_av_netscape_funcs[app_id].retainobject          = ns_table->retainobject;
    g_npplg_av_netscape_funcs[app_id].releaseobject         = ns_table->releaseobject;
    g_npplg_av_netscape_funcs[app_id].invoke                = ns_table->invoke;
    g_npplg_av_netscape_funcs[app_id].invokeDefault         = ns_table->invokeDefault;
    g_npplg_av_netscape_funcs[app_id].evaluate              = ns_table->evaluate;
    g_npplg_av_netscape_funcs[app_id].getproperty           = ns_table->getproperty;
    g_npplg_av_netscape_funcs[app_id].setproperty           = ns_table->setproperty;
    g_npplg_av_netscape_funcs[app_id].removeproperty        = ns_table->removeproperty;
    g_npplg_av_netscape_funcs[app_id].hasproperty           = ns_table->hasproperty;
    g_npplg_av_netscape_funcs[app_id].hasmethod             = ns_table->hasmethod;
    g_npplg_av_netscape_funcs[app_id].releasevariantvalue   = ns_table->releasevariantvalue;
    g_npplg_av_netscape_funcs[app_id].setexception          = ns_table->setexception;
    g_npplg_av_netscape_funcs[app_id].pushpopupsenabledstate    = ns_table->pushpopupsenabledstate;
    g_npplg_av_netscape_funcs[app_id].poppopupsenabledstate = ns_table->poppopupsenabledstate;
    g_npplg_av_netscape_funcs[app_id].enumerate             = ns_table->enumerate;
    g_npplg_av_netscape_funcs[app_id].pluginthreadasynccall = ns_table->pluginthreadasynccall;
    g_npplg_av_netscape_funcs[app_id].construct             = ns_table->construct;
    g_npplg_av_netscape_funcs[app_id].getvalueforurl        = ns_table->getvalueforurl;
    g_npplg_av_netscape_funcs[app_id].setvalueforurl        = ns_table->setvalueforurl;
    g_npplg_av_netscape_funcs[app_id].getauthenticationinfo = ns_table->getauthenticationinfo;

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_INIT_UTIL_FUNC, app_id);
    g_npplg_av_util_funcs[app_id].is_silent_setting         = ext_func->is_silent_setting;
    g_npplg_av_util_funcs[app_id].is_playing_audio          = ext_func->is_playing_audio;
    g_npplg_av_util_funcs[app_id].notify_play_finish        = ext_func->notify_play_finish;
    g_npplg_av_util_funcs[app_id].get_network_account       = ext_func->get_network_account;
    g_npplg_av_util_funcs[app_id].get_gdi_layer             = ext_func->get_gdi_layer;
    g_npplg_av_util_funcs[app_id].get_plugin_layer          = ext_func->get_plugin_layer;
    g_npplg_av_util_funcs[app_id].get_lcd_orientation       = ext_func->get_lcd_orientation;
    g_npplg_av_util_funcs[app_id].get_transparent_color     = ext_func->get_transparent_color;
    g_npplg_av_util_funcs[app_id].mem_alloc                 = ext_func->mem_alloc;
    g_npplg_av_util_funcs[app_id].mem_free                  = ext_func->mem_free;

    /* Set up plug-in function table */
    plugin_func->size       = sizeof(NPPluginFuncs);
    plugin_func->version    = (NP_VERSION_MAJOR << 8) + NP_VERSION_MINOR;

    switch (app_id)
    {
#ifdef OPERA_V10_BROWSER
        case NPPLG_AV_APP_ID_OPERA_BROWSER:
        {
            plugin_func->newp   = opera_adp_avplugin_create_instance;
            plugin_func->event  = opera_adp_avplugin_handle_event;
            plugin_func->setwindow = opera_adp_avplugin_set_window;
            break;
        }
#endif

#ifdef __GADGET_SUPPORT__
        case NPPLG_AV_APP_ID_GOOGLE_GADGET:
        {
            plugin_func->newp   = gadget_adp_avplugin_create_instance;
            plugin_func->event  = npplg_av_main_handle_event;
            plugin_func->setwindow = npplg_av_main_set_window;
            break;
        }
#endif

        default:
            ASSERT(0);
    }

    plugin_func->destroy    = npplg_av_main_delete_instance;
    plugin_func->newstream  = npplg_av_main_create_stream;
    plugin_func->destroystream = npplg_av_main_delete_stream;
    plugin_func->asfile     = npplg_av_main_recv_data_as_file;
    plugin_func->writeready = npplg_av_main_is_ready_to_recv_data;
    plugin_func->write      = npplg_av_main_recv_data;
    plugin_func->print      = npplg_av_main_print;
    plugin_func->urlnotify  = npplg_av_main_handle_url_rsp;
    plugin_func->getvalue   = npplg_av_main_get_value;
    plugin_func->setvalue   = npplg_av_main_set_value;
#ifdef OJI
    plugin_func->javaClass  = npplg_av_main_get_java_class;
#endif

    NPPLG_AV_APP_ENTER_STATE(app_id, g_npplg_av_context.app_cnxt[app_id].state, NPPLG_AV_USER_STATE_INITIALIZED);
    g_npplg_av_context.app_cnxt[app_id].mod_id = kal_get_active_module_id();

#if defined(OPERA_V10_BROWSER) && defined(__GADGET_SUPPORT__)
    if (app_id == NPPLG_AV_APP_ID_OPERA_BROWSER)
    {
        g_npplg_av_context.app_cnxt[app_id].mimic_mod_id = MOD_OPERA_CORE_MDI;
        g_npplg_av_context.app_cnxt[app_id].mem_app_id = APP_OPERA;
    }
    else if (app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
    {
        g_npplg_av_context.app_cnxt[app_id].mimic_mod_id = MOD_GADGET_MDI;
#ifdef __COSMOS_MMI_PACKAGE__
        g_npplg_av_context.app_cnxt[app_id].mem_app_id = VAPP_WIDGET_DELEGATOR;
#else
        g_npplg_av_context.app_cnxt[app_id].mem_app_id = 0;
#endif
    }
    else
    {
        ASSERT(0);
    }
#elif defined(OPERA_V10_BROWSER) && !defined(__GADGET_SUPPORT__)
    if (app_id == NPPLG_AV_APP_ID_OPERA_BROWSER)
    {
        g_npplg_av_context.app_cnxt[app_id].mimic_mod_id = MOD_OPERA_CORE_MDI;
        g_npplg_av_context.app_cnxt[app_id].mem_app_id = APP_OPERA;
    }
    else
    {
        ASSERT(0);
    }
#elif !defined(OPERA_V10_BROWSER) && defined(__GADGET_SUPPORT__)
    if (app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
    {
        g_npplg_av_context.app_cnxt[app_id].mimic_mod_id = MOD_GADGET_MDI;
#ifdef __COSMOS_MMI_PACKAGE__
        g_npplg_av_context.app_cnxt[app_id].mem_app_id = VAPP_WIDGET_DELEGATOR;
#else
        g_npplg_av_context.app_cnxt[app_id].mem_app_id = 0;
#endif
    }
    else
    {
        ASSERT(0);
    }
#else
    ASSERT(0);
#endif

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_APP_INIT_END, app_id);

    npplg_av_main_create_folder();

#ifdef __COSMOS_MMI_PACKAGE__
    g_npplg_av_context.app_cnxt[app_id].transparent_color = npplg_av_main_get_transparent_color(app_id);
#endif

    NPPLG_AV_UNLOCK;
    return NPERR_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_user_terminate
 * DESCRIPTION
 *  When plug-in's user terminates, it should call this function to tell A/V Plug-in.
 *  A/V Plug-in would de-initialize application's context.
 * PARAMETERS
 *  app_id          [IN]            Application id
 * RETURNS
 *  Result
 *****************************************************************************/
NPError npplg_av_main_user_terminate(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_APP_TERMINATE, app_id);

    NPPLG_AV_LOCK;

    if (g_npplg_av_context.app_cnxt[app_id].state == NPPLG_AV_USER_STATE_INITIALIZED &&
        g_npplg_av_context.app_cnxt[app_id].instance_num == 0)
    {
        if ((g_npplg_av_context.app_cnxt[app_id].active_instance != NULL &&
             g_npplg_av_context.app_cnxt[app_id].active_instance->app_id == app_id) ||
            (g_npplg_av_context.app_cnxt[app_id].interrupt_instance != NULL &&
             g_npplg_av_context.app_cnxt[app_id].interrupt_instance->app_id == app_id))
        {
            /* Before application calls this function, it should delete all instances which are created by it */
            ASSERT(0);
        }

        npplg_av_main_reset_context(app_id, KAL_FALSE);
        NPPLG_AV_APP_ENTER_STATE(app_id, g_npplg_av_context.app_cnxt[app_id].state, NPPLG_AV_USER_STATE_TERMINATED);
    }
    else
    {
        ASSERT(0);
    }

    NPPLG_AV_UNLOCK;
    return NPERR_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_create_instance
 * DESCRIPTION
 *  This function is used to create one plug-in instance to handle one embedded object
 * PARAMETERS
 *  pluginType      [IN]            The MIME type of the embedded object
 *  instance        [IN/OUT]        Contain instance-specific private data for the plug-in and the browser
 *  mode            [IN]            Display mode of plug-in
 *  argc            [IN]            Indicate the number of attributes in the argn and argv arrays
 *  argn            [IN]            Array of attribute names passed to the plug-in from the <EMBED> tag
 *  argv            [IN]            Array of attribute values passed to the plug-in from the <EMBED> tag
 *  saved           [IN]            Pointer to data saved by npplg_av_main_delete_instance() for a previous instance of this plug-in at the same URL
 *  app_id          [IN]            Application id
 * RETURNS
 *  Execution result
 * RETURN VALUE LIST
 *  NPERR_NO_ERROR      Create instance successfully
 *  Other error code    Failed to create instance
 *****************************************************************************/
NPError npplg_av_main_create_instance(NPMIMEType mime_type,
                                      NPP instance,
                                      kal_uint16 mode,
                                      kal_int16 argc,
                                      kal_char *argn[],
                                      kal_char *argv[],
                                      NPSavedData *saved,
                                      kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data = NULL;
    applib_mime_type_struct *entry = NULL;
    kal_int32 i, mime_len;
    kal_uint8 obj_type = NPPLG_AV_OBJ_TYPE_UNKNOWN;
    kal_bool launch_aud_player = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_CREATE_INSTANCE, mime_type, app_id);

    if (mime_type == NULL)
    {
        ASSERT(0);
        return NPERR_INVALID_PARAM;
    }

    NPPLG_AV_LOCK;
    
    if (g_npplg_av_context.app_cnxt[app_id].instance_num >= NPPLG_AV_CFG_MAX_OBJECT_NUM)
    {
        NPPLG_AV_UNLOCK;
        return NPERR_GENERIC_ERROR;
    }
    
    /* Check if MTK support the MIME type of this embedded object */
    if ((entry = applib_mime_type_look_up(mime_type, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_NONE)) != NULL)
    {
        if (entry->mime_type == MIME_TYPE_AUDIO)
        {
            obj_type = NPPLG_AV_OBJ_TYPE_AUDIO;
            
            if (entry->mime_subtype == MIME_SUBTYPE_3GPP_AUDIO ||
                entry->mime_subtype == MIME_SUBTYPE_MP4_AUDIO)
            {
                launch_aud_player = KAL_TRUE;
            }
        }
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
        else if (entry->mime_type == MIME_TYPE_VIDEO)
        {
            obj_type = NPPLG_AV_OBJ_TYPE_VIDEO;
        }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__)
        else if (entry->mime_subtype == MIME_SUBTYPE_SDP)
        {
            obj_type = NPPLG_AV_OBJ_TYPE_STREAMING;
        }
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__) */
        else
        {
            NPPLG_AV_UNLOCK;
            return NPERR_INVALID_PARAM;
        }
    }
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__)
    else if (strcmp(mime_type, "video/streaming") == 0)
    {
        obj_type = NPPLG_AV_OBJ_TYPE_STREAMING;
    }
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__) */
    else
    {
        NPPLG_AV_UNLOCK;
        return NPERR_INVALID_PARAM;
    }
    
    plugin_data = (npplg_av_instance_struct*)g_npplg_av_netscape_funcs[app_id].memalloc(sizeof(npplg_av_instance_struct));
    if (plugin_data == NULL)
    {
        NPPLG_AV_UNLOCK;
        return NPERR_OUT_OF_MEMORY_ERROR;
    }

    memset(plugin_data, 0, sizeof(npplg_av_instance_struct));
    
    if (g_npplg_av_instance_id == NPPLG_AV_MAX_INSTANCE_NUM)
    {
        g_npplg_av_instance_id = 0;
    }
    plugin_data->instance_id = ++g_npplg_av_instance_id;
    plugin_data->app_id = app_id;
    plugin_data->obj_type = obj_type;
    plugin_data->active = KAL_TRUE;
    plugin_data->file_handle = FS_FILE_NOT_FOUND;
    
    if (obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
    {
        plugin_data->obj_data = g_npplg_av_netscape_funcs[app_id].memalloc(sizeof(npplg_av_audio_data_struct));
        if (plugin_data->obj_data == NULL)
        {
            NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data);

            NPPLG_AV_UNLOCK;
            return NPERR_OUT_OF_MEMORY_ERROR;
        }
        memset(plugin_data->obj_data, 0, sizeof(npplg_av_audio_data_struct));
        plugin_data->state = NPPLG_AV_AUDIO_OBJ_STATE_IDLE;
    }
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
#if defined(__MMI_VIDEO_STREAM__)
    else if ((obj_type == NPPLG_AV_OBJ_TYPE_VIDEO) ||
		     (obj_type == NPPLG_AV_OBJ_TYPE_STREAMING))
#else /* __MMI_VIDEO_STREAM__ */
    else if (obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#endif /* __MMI_VIDEO_STREAM__ */
    {
        plugin_data->obj_data = g_npplg_av_netscape_funcs[app_id].memalloc(sizeof(npplg_av_video_data_struct));
        if (plugin_data->obj_data == NULL)
        {
            NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data);

            NPPLG_AV_UNLOCK;
            return NPERR_OUT_OF_MEMORY_ERROR;
        }
        memset(plugin_data->obj_data, 0, sizeof(npplg_av_video_data_struct));

#if defined(__MMI_VIDEO_STREAM__)
        if (obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
        {
            plugin_data->state = NPPLG_AV_STREAM_OBJ_STATE_IDLE;
        }
        else
#endif /* __MMI_VIDEO_STREAM__ */
        {
            plugin_data->state = NPPLG_AV_VIDEO_OBJ_STATE_IDLE;
        }
    }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    else
    {
        ASSERT(0);
    }

    mime_len = strlen(mime_type);
    plugin_data->mime_type = (kal_char*)g_npplg_av_netscape_funcs[app_id].memalloc(sizeof(kal_char) * (mime_len + 1));
    if (plugin_data->mime_type == NULL)
    {
        npplg_av_main_free_instance_data(plugin_data);
        NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data);

        NPPLG_AV_UNLOCK;
        return NPERR_OUT_OF_MEMORY_ERROR;
    }
    strncpy(plugin_data->mime_type, mime_type, mime_len);
    plugin_data->mime_type[mime_len] = '\0';

    /* Go through the args to get the URL of the embedded object */
    for (i = 0; i < argc; i++)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_OBJ_INFO, argn[i], argv[i]);
        if ((app_stricmp(argn[i], "data") == 0) ||
            (app_stricmp(argn[i], "src") == 0))
        {
            /* String should be UTF-8 encoded */
            kal_int32 obj_url_len = strlen(argv[i]);
            applib_url_struct url_info;

            if (applib_parse_url(argv[i], &url_info) == 0)
            {
                if ((url_info.scheme_type == applib_scheme_rtsp) ||
                    (url_info.scheme_type == applib_scheme_http) ||
                    (url_info.scheme_type == applib_scheme_https) ||
                    (url_info.scheme_type == applib_scheme_file) ||
                    (url_info.scheme_type == applib_scheme_empty))
                {
                    if (url_info.scheme_type == applib_scheme_rtsp)
                    {
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__)
                        /* rtsp:// link - should change object type to video streaming */
                        plugin_data->obj_type = NPPLG_AV_OBJ_TYPE_STREAMING;
                        plugin_data->state = NPPLG_AV_STREAM_OBJ_STATE_IDLE;
                        ((npplg_av_video_data_struct*)plugin_data->obj_data)->is_pdl_or_rtsp = KAL_TRUE;
#else /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__) */
                        continue;
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__) */
                    }
                    
                    plugin_data->url = (kal_char*)g_npplg_av_netscape_funcs[app_id].memalloc(sizeof(kal_char) * (obj_url_len + 1));
                    if (plugin_data->url == NULL)
                    {
                        npplg_av_main_free_instance_data(plugin_data);
                        NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data);

                        NPPLG_AV_UNLOCK;
                        return NPERR_OUT_OF_MEMORY_ERROR;
                    }
                    strncpy(plugin_data->url, argv[i], obj_url_len);
                    plugin_data->url[obj_url_len] = '\0';
                    break;
                }
            }
        }
    }
    
    if (i == argc)
    {
        /* Not contain the URL of the embedded object */
        npplg_av_main_free_instance_data(plugin_data);
        NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data);

        NPPLG_AV_UNLOCK;
        return NPERR_INVALID_PARAM;
    }

    if (npplg_av_main_add_instance_into_list(&(g_npplg_av_context.app_cnxt[app_id].instance_list), plugin_data) == KAL_FALSE)
    {
        npplg_av_main_free_instance_data(plugin_data);
        NPPLG_AV_MEM_FREE(plugin_data->app_id, plugin_data);

        NPPLG_AV_UNLOCK;
        return NPERR_OUT_OF_MEMORY_ERROR;
    }

    /* Set audio data */
    if (obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
    {
        npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;

        aud_data->player.handler = npplg_av_audio_play_callback;
        aud_data->player.file_path = NULL;
        aud_data->player.repeats = 1;
        aud_data->player.progressive_dl = KAL_FALSE;
        aud_data->player.app_id = g_npplg_av_context.app_cnxt[app_id].mem_app_id;

        if (launch_aud_player)
        {
            aud_data->only_launch_aud_player = KAL_TRUE;
        }
    }
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#ifdef __MMI_VIDEO_STREAM__
    else if (obj_type == NPPLG_AV_OBJ_TYPE_VIDEO || obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
#else
    else if (obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#endif /* __MMI_VIDEO_STREAM__ */
    {
        npplg_av_video_data_struct *vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;

        vdo_data->lcm_update = KAL_TRUE;
    }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

    /* Not use GDI_COLOR_FORMAT_32 because GDI_COLOR_FORMAT_16 can save memory */
    plugin_data->color_format = GDI_COLOR_FORMAT_16;

    /* Indicate plug-in is windowless */
    /* Must set NPPVpluginWindowBool as FALSE if user application is Opera Browser */
    g_npplg_av_netscape_funcs[app_id].setvalue(instance, NPPVpluginWindowBool, (void*)FALSE);

    /* Indicate transparent mode is opaque */
    g_npplg_av_netscape_funcs[app_id].setvalue(instance, NPPVpluginTransparentBool, (void*)FALSE);

    instance->pdata = plugin_data;
    plugin_data->brw_instance = instance;

    g_npplg_av_context.app_cnxt[app_id].instance_num++;
    if (g_npplg_av_context.app_cnxt[app_id].state == NPPLG_AV_USER_STATE_INITIALIZED)
    {
        NPPLG_AV_APP_ENTER_STATE(app_id, g_npplg_av_context.app_cnxt[app_id].state, NPPLG_AV_USER_STATE_INSTANCE_CREATED);
    }

    NPPLG_AV_UNLOCK;
    return NPERR_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_set_window
 * DESCRIPTION
 *  This function is used to tell the plug-in when a window is created, moved, sized, or destroyed.
 * PARAMETERS
 *  instance        [IN]        Pointer to the plug-in instance
 *  window          [IN]        Pointer to the window into which the instance draws
 * RETURNS
 *  Execution result
 * RETURN VALUE LIST
 *  NPERR_NO_ERROR      Delete instance successfully
 *  Other error code    Failed to delete instance
 *****************************************************************************/
NPError npplg_av_main_set_window(NPP instance, NPWindow *window)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data = (npplg_av_instance_struct*)instance->pdata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data == NULL)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_SET_WIN_ERROR);
        return NPERR_INVALID_INSTANCE_ERROR;
    }

    NPPLG_AV_LOCK;

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_SET_WIN, plugin_data->instance_id, plugin_data->app_id);
    
    if (window == NULL)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_NULL_WINDOW, plugin_data->instance_id, plugin_data->app_id, plugin_data->state);

        plugin_data->np_window = NULL;
        plugin_data->window = NULL;

        /* Stop audio/video playing */
        npplg_av_main_dispatch_event(plugin_data, NPPLG_AV_INT_EVT_STOP);

        NPPLG_AV_UNLOCK;
        return NPERR_NO_ERROR;
    }

    MMI_TRACE(NPPLG_AV_TRC_GROUP,
              NPPLG_AV_WIN_PROPERTY,
              window->x,
              window->y,
              window->width,
              window->height,
              window->clipRect.left,
              window->clipRect.top,
              window->clipRect.right,
              window->clipRect.bottom);

    if (window->window == NULL)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_NULL_WINDOW, plugin_data->instance_id, plugin_data->app_id, plugin_data->state);

        plugin_data->np_window = window;
        plugin_data->window = NULL;

#ifdef OPERA_V10_BROWSER
        /*
         * MAUI_02579576
         * GogiPluginWindow may be invalid before Opera calls NPP_Destroy().
         */
        if (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER)
        {
            /* Stop audio/video playing */
            npplg_av_main_dispatch_event(plugin_data, NPPLG_AV_INT_EVT_STOP);

            NPPLG_AV_UNLOCK;
            return NPERR_GENERIC_ERROR;
        }
#endif /* OPERA_V10_BROWSER */

        ASSERT(0);
        NPPLG_AV_UNLOCK;
        return NPERR_GENERIC_ERROR;
    }
    
    if (plugin_data->np_window != window || plugin_data->window != window->window)
    {
        plugin_data->np_window = window;
        plugin_data->window = window->window;
        
#ifdef __GADGET_SUPPORT__
        if (plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
        {
            npplg_av_window_struct *plugin_win = (npplg_av_window_struct*)(window->window);

            plugin_data->plugin_window.start_timer = plugin_win->start_timer;
            plugin_data->plugin_window.stop_timer = plugin_win->stop_timer;
            plugin_data->plugin_window.get_visible_screen_area = plugin_win->get_visible_screen_area;
            plugin_data->plugin_window.trans_coord = plugin_win->trans_coord;
            plugin_data->plugin_window.display_popup = plugin_win->display_popup;
        }
#endif
        
        npplg_av_main_redraw_window(plugin_data, window);
    }
    else if ((plugin_data->width != window->width) ||
             (plugin_data->height != window->height) ||
             (plugin_data->clip_region.top != window->clipRect.top) ||
             (plugin_data->clip_region.left != window->clipRect.left) ||
             (plugin_data->clip_region.right != window->clipRect.right) ||
             (plugin_data->clip_region.bottom != window->clipRect.bottom))
    {
        /* Need to redraw the paint buffer */
        npplg_av_main_redraw_window(plugin_data, window);        
    }
    else if (plugin_data->x != window->x || plugin_data->y != window->y)
    {
        plugin_data->x = window->x;
        plugin_data->y = window->y;

        /* Update the position of video layer if object is video */
        
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
#if defined(__MMI_VIDEO_STREAM__)
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING ||
            plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#else
        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#endif /* __MMI_VIDEO_STREAM__ */
        {
            npplg_av_video_set_position(plugin_data);
        }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    }

    NPPLG_AV_UNLOCK;
    return NPERR_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_handle_event
 * DESCRIPTION
 *  This function is used to tell the plug-in when events take place in the plug-in's window or drawable area or the event might be needed by the plug-in.
 * PARAMETERS
 *  instance        [IN]        Pointer to the plug-in instance
 *  event           [IN]        Indicate the event given to plug-in
 * RETURNS
 *  Indicate whether the event is handled by plug-in
 * RETURN VALUE LIST
 *  KAL_TRUE            Plug-in handles the event
 *  KAL_FALSE           Plug-in ignores the event
 *****************************************************************************/
kal_int16 npplg_av_main_handle_event(NPP instance, void *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data = (npplg_av_instance_struct*)instance->pdata;
    npplg_av_event_struct *plugin_evt = (npplg_av_event_struct*)event;
    kal_int16 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data == NULL)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_HANDLE_EVT_ERROR);
        return KAL_FALSE;
    }

    NPPLG_AV_LOCK;

    switch (plugin_evt->type)
    {
        case NPPLG_AV_EVT_TYPE_PAINT:
        {
            ret = npplg_av_main_handle_paint_event(plugin_data, (npplg_av_evt_paint_struct*)(plugin_evt->detail));
            break;
        }

        case NPPLG_AV_EVT_TYPE_TIMER:
        {
            ret = npplg_av_main_handle_timer_event(plugin_data, (npplg_av_evt_timer_struct*)(plugin_evt->detail));
            break;
        }

        case NPPLG_AV_EVT_TYPE_KEY:
        {
            ret = npplg_av_main_handle_key_event(plugin_data, (npplg_av_evt_key_struct*)(plugin_evt->detail));
            break;
        }
        
        case NPPLG_AV_EVT_TYPE_MOUSE:
        {
            ret = npplg_av_main_handle_mouse_event(plugin_data, (npplg_av_evt_mouse_struct*)(plugin_evt->detail));
            break;
        }
        
        case NPPLG_AV_EVT_TYPE_ACTIVATE:
        {
            ret = npplg_av_main_handle_activate_event(plugin_data, (npplg_av_evt_activate_struct*)(plugin_evt->detail));
            break;
        }

        case NPPLG_AV_EVT_TYPE_FOCUS:
        {
            ret = npplg_av_main_handle_focus_event(plugin_data, (npplg_av_evt_focus_struct*)(plugin_evt->detail));
            break;
        }

        case NPPLG_AV_EVT_TYPE_SCREEN_SCROLLED:
        {
            ret = npplg_av_main_handle_scroll_event(plugin_data);
            break;
        }
        
        default:
        {
            ret = KAL_FALSE;
            break;
        }
    }

    NPPLG_AV_UNLOCK;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_assign_utility_function
 * DESCRIPTION
 *  This function is used to assign utility functions provided by user application.
 * PARAMETERS
 *  instance        [IN]        Pointer to the plug-in instance
 *  plugin_win      [IN]        Used to get utility functions provided by NPWindow->window
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_assign_utility_function(NPP instance, npplg_av_window_struct *plugin_win)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data = (npplg_av_instance_struct*)instance->pdata;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    if (plugin_data != NULL)
    {
        plugin_data->plugin_window.start_timer = plugin_win->start_timer;
        plugin_data->plugin_window.stop_timer = plugin_win->stop_timer;
        plugin_data->plugin_window.get_visible_screen_area = plugin_win->get_visible_screen_area;
        plugin_data->plugin_window.trans_coord = plugin_win->trans_coord;
        plugin_data->plugin_window.display_popup = plugin_win->display_popup;
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_start_download
 * DESCRIPTION
 *  Start to download the data from network.
 * PARAMETERS
 *  plugin_data     [IN]        Plugin instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_start_download(npplg_av_instance_struct *plugin_data, kal_uint8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 *req_id = (kal_uint32*)g_npplg_av_netscape_funcs[plugin_data->app_id].memalloc(sizeof(kal_uint32));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *req_id = npplg_av_main_get_req_id();
    plugin_data->dl_req_id = *req_id;
    NPPLG_AV_OBJ_ENTER_STATE(plugin_data->instance_id, plugin_data->state, state);
    g_npplg_av_netscape_funcs[plugin_data->app_id].geturlnotify(plugin_data->brw_instance, (const kal_char*)plugin_data->url, NULL, (void*)req_id);
    plugin_data->dl_state = NPPLG_AV_OBJ_DL_STATE_DOWNLOADING;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_abort_download_req
 * DESCRIPTION
 *  Abort downloading
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_abort_download_req(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plugin_data->dl_state == NPPLG_AV_OBJ_DL_STATE_DOWNLOADING)
    {
        g_npplg_av_netscape_funcs[plugin_data->app_id].destroystream(plugin_data->brw_instance,
                                                                     plugin_data->stream,
                                                                     NPRES_USER_BREAK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_launch_media_player_handler
 * DESCRIPTION
 *  MSG_ID_NPPLG_AV_LAUNCH_MEDIA_PLAYER_IND handler
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  Whether this message is handled or not
 *****************************************************************************/
U8 npplg_av_main_launch_media_player_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_launch_media_player_ind_struct *data = (npplg_av_launch_media_player_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__PLUTO_MMI_PACKAGE__)

    switch (data->player_type)
    {
        case NPPLG_AV_PLAYER_TYPE_AUDIO:
        {
            mmi_media_app_play_audio_with_title(data->filepath, NULL, (U16)NULL, data->title);
            break;
        }

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
        case NPPLG_AV_PLAYER_TYPE_VIDEO:
        {
            mmi_media_app_play_video_ext(data->filepath, MMI_FALSE, data->title);
            break;
        }

#ifdef __MMI_VIDEO_STREAM__
        case NPPLG_AV_PLAYER_TYPE_STREAM:
        {
            if (data->rtsp)
            {
                mmi_media_app_play_stream_from_rtsp_link(data->filepath);
            }
            else
            {
                mmi_media_app_play_stream_from_sdp_file_ext(data->filepath, MMI_FALSE, data->title);
            }
            break;
        }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

        default:
            break;
    }

#elif defined(__COSMOS_MMI_PACKAGE__)

    if (data->player_type == NPPLG_AV_PLAYER_TYPE_STREAM && data->rtsp)
    {
        /* RTSP link -> use URIAgent service to dispatch request */
        switch (data->app_id)
        {
#ifdef __MMI_URI_AGENT__
#ifdef OPERA_V10_BROWSER
            case NPPLG_AV_APP_ID_OPERA_BROWSER:
            {
                srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_BRW,
                                                  (char*)data->filepath,
                                                  SRV_URIAGENT_OPTION_UNSPECIFIED,
                                                  NULL);
                break;
            }
#endif /* OPERA_V10_BROWSER */

#ifdef __GADGET_SUPPORT__
            case NPPLG_AV_APP_ID_GOOGLE_GADGET:
            {
                srv_uriagent_dispatch_uri_request(SRV_URIAGENT_APPID_WIDGET,
                                                  (char*)data->filepath,
                                                  SRV_URIAGENT_OPTION_UNSPECIFIED,
                                                  NULL);
                break;
            }
#endif /* __GADGET_SUPPORT__ */
#endif /* __MMI_URI_AGENT__ */

            default:
                break;
        }
    }
    else
    {
        /* Audio file, video file, sdp file -> use App Manager service to launch corresponding application */
        switch (data->player_type)
        {
            case NPPLG_AV_PLAYER_TYPE_AUDIO:
            {
                /* Launch music player */
                vapp_music_player_singleplayer_launch(data->filepath, data->title);
                break;
            }

#ifdef __MMI_FTO_GALLERY__
            case NPPLG_AV_PLAYER_TYPE_VIDEO:
            case NPPLG_AV_PLAYER_TYPE_STREAM:
            {
                /* Launch gallery */
                vapp_gallery_image_viewer_launch_option_struct option;
                option.title_string = data->title;
                option.show_blank_page = MMI_TRUE;
                vapp_gallery_image_viewer_launch(data->filepath, &option);
                break;
            }
#endif /* __MMI_FTO_GALLERY__ */

            default:
                break;
        }
    }

#endif /* __PLUTO_MMI_PACKAGE__ */

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_resume_background_play
 * DESCRIPTION
 *  MSG_ID_NPPLG_AV_RESUME_BACKGROUND_PLAY_IND handler
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  Whether this message is handled or not
 *****************************************************************************/
U8 npplg_av_main_resume_background_play(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_resume_background_play_ind_struct *data = (npplg_av_resume_background_play_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    if (g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_RELEASING)
    {
        mdi_audio_clear_interrupt_callback();
        if (data->resume_bgplay)
        {
            mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
        }
        g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_NULL;

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#ifdef __MMI_VIDEO_STREAM__
        if (data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO || data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
#else
        if (data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#endif /* __MMI_VIDEO_STREAM__ */
        {
            npplg_av_main_switch_backlight(KAL_FALSE);
        }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    }

    NPPLG_AV_UNLOCK;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_notify_mmi_ind_handler
 * DESCRIPTION
 *  MSG_ID_NPPLG_AV_NOTIFY_MMI_IND handler
 * PARAMETERS
 *  msg             [IN]
 * RETURNS
 *  Whether this message is handled or not
 *****************************************************************************/
U8 npplg_av_main_notify_mmi_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_notify_mmi_ind_struct *data = (npplg_av_notify_mmi_ind_struct*)msg;
    npplg_av_instance_struct *plugin_data;
    kal_int32 result = NPPLG_AV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    plugin_data = npplg_av_main_get_instance_from_list(data->instance_id, data->app_id);

    if (plugin_data != NULL &&
        plugin_data == npplg_av_main_get_active_instance(data->app_id) &&
        g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_OCCUPIED &&
        g_npplg_av_context.app_cnxt[data->app_id].is_suspend_by_mmi == KAL_FALSE &&
        mdi_audio_is_speech_mode() == KAL_FALSE)
    {
        if (data->action & NPPLG_AV_ACTION_SET_VOLUME)
        {
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, npplg_av_main_get_volume(data->app_id));
        }

        if (data->action & NPPLG_AV_ACTION_SET_MUTE)
        {
            mdi_audio_set_mute(MDI_VOLUME_MEDIA, plugin_data->mute);
        }

        if (data->action & NPPLG_AV_ACTION_TURN_ON_BACKLIGHT)
        {
            npplg_av_main_switch_backlight(KAL_TRUE);
        }

        if (data->action & NPPLG_AV_ACTION_TURN_OFF_BACKLIGHT)
        {
            npplg_av_main_switch_backlight(KAL_FALSE);
        }

        if (data->action & NPPLG_AV_ACTION_TERMINATE_BGPLAY)
        {
            mdi_audio_clear_interrupt_callback();
            mdi_audio_terminate_background_play();
            mdi_audio_register_interrupt_callback(npplg_av_main_interrupt_callback, NULL);
        }

        if (data->action & NPPLG_AV_ACTION_OPEN_AUDIO &&
            plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
        {
            npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
            kal_int32 mma_ret;

            if (aud_data->mma_handle == NULL)
            {
                aud_data->mma_handle = media_mma_aud_open(kal_get_active_module_id(), &(aud_data->player), &mma_ret);

                if (mma_ret == MED_RES_OK)
                {
                    /* Set audio output path */
                    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
                                        
                    if (aud_data->cache_status != NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_OK ||
                        aud_data->total_time == 0)
                    {
                        aud_data->total_time = media_mma_aud_get_duration(kal_get_active_module_id(), aud_data->mma_handle, aud_data->player.media_type);
                    }
                    else
                    {
                        media_mma_set_cache_table(kal_get_active_module_id(), aud_data->mma_handle, aud_data->cache);
                    }
                }
                else
                {
                    mdi_audio_clear_interrupt_callback();
                    if (!(data->action & NPPLG_AV_ACTION_TERMINATE_BGPLAY))
                    {
                        mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
                    }
                    g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_NULL;
                    result = NPPLG_AV_FAIL;
                }
            }
        }

        if (data->action & NPPLG_AV_ACTION_SEND_PLAY_IND)
        {
            npplg_av_util_send_suspend_background_play_rsp(npplg_av_main_get_app_mod_id(data->app_id),
                                                           data->app_id,
                                                           result);
        }
    }

    NPPLG_AV_UNLOCK;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_suspend_background_play_req_handler
 * DESCRIPTION
 *  MSG_ID_NPPLG_AV_SUSPEND_BACKGROUND_PLAY_REQ handler
 * PARAMETERS
 *  msg             [IN]
 * RETURNS
 *  Whether this message is handled or not
 *****************************************************************************/
U8 npplg_av_main_suspend_background_play_req_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_suspend_background_play_req_struct *req = (npplg_av_suspend_background_play_req_struct*)msg;
    npplg_av_instance_struct *plugin_data;
    kal_uint8 app_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    if (g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_OCCUPYING &&
        g_npplg_av_context.app_cnxt[g_npplg_av_context.play_app_id].is_suspend_by_mmi == KAL_FALSE)
    {
        if (req->suspend_bgplay)
        {
            /* Suspend background play by calling MDI Audio API */
            mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
        }
        else
        {
            /* Terminate background play */
            mdi_audio_terminate_background_play();
        }

        app_id = g_npplg_av_context.play_app_id;
        plugin_data = npplg_av_main_get_active_instance(app_id);
    
        /*
         * Always can succeed to occupy audio resource
         * Send message to plug-in to notify result
         */
        mdi_audio_register_interrupt_callback(npplg_av_main_interrupt_callback, NULL);

        if (plugin_data != NULL)
        {
            if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
            {
                npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)plugin_data->obj_data;
                kal_int32 mma_ret;
                
                aud_data->mma_handle = media_mma_aud_open(kal_get_active_module_id(), &(aud_data->player), &mma_ret);

                if (mma_ret == MED_RES_OK)
                {
                    /* Set audio output path */
                    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);

                    if (aud_data->cache_status != NPPLG_AV_AUDIO_CACHE_STATUS_BUILT_OK ||
                        aud_data->total_time == 0)
                    {
                        aud_data->total_time = media_mma_aud_get_duration(kal_get_active_module_id(), aud_data->mma_handle, aud_data->player.media_type);
                    }
                    else
                    {
                        media_mma_set_cache_table(kal_get_active_module_id(), aud_data->mma_handle, aud_data->cache);
                    }
                }
                else
                {
                    mdi_audio_clear_interrupt_callback();
                    g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_NULL;

                    if (req->suspend_bgplay)
                    {
                        mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
                    }

                    npplg_av_util_send_suspend_background_play_rsp(npplg_av_main_get_app_mod_id(app_id),
                                                                   app_id,
                                                                   NPPLG_AV_FAIL);

                    NPPLG_AV_UNLOCK;
                    return MMI_TRUE;
                }
            }
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#ifdef __MMI_VIDEO_STREAM__
            else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO ||
                     plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
#else
            else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#endif /* __MMI_VIDEO_STREAM__ */
            {
                npplg_av_main_switch_backlight(KAL_TRUE);
            }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

            /* Apply the mute setting of active plug-in instance */
            npplg_av_main_set_mute(plugin_data->mute, plugin_data->app_id);
            
            /* Set volume */
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, npplg_av_main_get_volume(plugin_data->app_id));

            g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_OCCUPIED;

            npplg_av_util_send_suspend_background_play_rsp(npplg_av_main_get_app_mod_id(app_id),
                                                           app_id,
                                                           NPPLG_AV_OK);

            NPPLG_AV_UNLOCK;
            return MMI_TRUE;
        }

        /* Error case */
        mdi_audio_clear_interrupt_callback();

        g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_NULL;

        if (req->suspend_bgplay)
        {
            mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
        }

        /*
         * Fail to occupy audio resource
         * Send message to plug-in to notify result
         */
        npplg_av_util_send_suspend_background_play_rsp(npplg_av_main_get_app_mod_id(app_id),
                                                       app_id,
                                                       NPPLG_AV_FAIL);
    }

    NPPLG_AV_UNLOCK;
    return MMI_TRUE;
}


#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_create_vdo_layer_req_handler
 * DESCRIPTION
 *  MSG_ID_NPPLG_AV_CREATE_VDO_LAYER_REQ handler
 * PARAMETERS
 *  msg             [IN]
 * RETURNS
 *  Whether this message is handled or not
 *****************************************************************************/
U8 npplg_av_main_create_vdo_layer_req_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_create_vdo_layer_req_struct *req = (npplg_av_create_vdo_layer_req_struct*)msg;
    npplg_av_instance_struct *plugin_data;
    gdi_handle vdo_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    plugin_data = npplg_av_main_get_instance_from_list(req->instance_id, req->app_id);

    if (plugin_data != NULL &&
        plugin_data == npplg_av_main_get_active_instance(req->app_id) &&
        g_npplg_av_context.app_cnxt[req->app_id].is_suspend_by_mmi == KAL_FALSE)
    {
        vdo_layer = vapp_npplg_av_video_create_vdo_layer(req->app_id,
                                                         req->instance_id,
                                                         req->x,
                                                         req->y,
                                                         req->w,
                                                         req->h,
                                                         req->transparent_color);
        npplg_av_util_send_create_vdo_layer_rsp(req->src_mod,
                                                req->app_id,
                                                req->instance_id,
                                                ((vdo_layer == NULL) ? NPPLG_AV_FAIL : NPPLG_AV_OK),
                                                vdo_layer,
                                                vapp_npplg_av_video_get_display_layer_flag(),
                                                vapp_npplg_av_video_get_hw_layer_flag());
    }

    NPPLG_AV_UNLOCK;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_free_vdo_layer_ind_handler
 * DESCRIPTION
 *  MSG_ID_NPPLG_AV_FREE_VDO_LAYER_IND handler
 * PARAMETERS
 *  msg             [IN]
 * RETURNS
 *  Whether this message is handled or not
 *****************************************************************************/
U8 npplg_av_main_free_vdo_layer_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_free_vdo_layer_ind_struct *ind = (npplg_av_free_vdo_layer_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    vapp_npplg_av_video_free_vdo_layer(ind->app_id, ind->instance_id);

    NPPLG_AV_UNLOCK;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_update_vdo_layer_ind_handler
 * DESCRIPTION
 *  MSG_ID_NPPLG_AV_UPDATE_VDO_LAYER_IND handler
 * PARAMETERS
 *  msg             [IN]
 * RETURNS
 *  Whether this message is handled or not
 *****************************************************************************/
U8 npplg_av_main_update_vdo_layer_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_update_vdo_layer_ind_struct *ind = (npplg_av_update_vdo_layer_ind_struct*)msg;
    npplg_av_video_data_struct *vdo_data;
    npplg_av_instance_struct *plugin_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    plugin_data = npplg_av_main_get_instance_from_list(ind->instance_id, ind->app_id);

    if (plugin_data != NULL &&
        plugin_data == npplg_av_main_get_active_instance(ind->app_id) &&
        g_npplg_av_context.app_cnxt[ind->app_id].is_suspend_by_mmi == KAL_FALSE)
    {
        vdo_data = (npplg_av_video_data_struct*)plugin_data->obj_data;
        if (vdo_data->vdo_layer_handle != GDI_NULL_HANDLE)
        {
            mdi_video_enable_mimic_task(g_npplg_av_context.app_cnxt[ind->app_id].mimic_mod_id);
            npplg_av_video_mmi_update_video_layer(plugin_data, ind->x, ind->y, ind->w, ind->h, ind->transparent_color);
            mdi_video_disable_mimic_task();
        }
    }

    NPPLG_AV_UNLOCK;
    return MMI_TRUE;
}
#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_free_memory
 * DESCRIPTION
 *  This function is used to free memory.
 * PARAMETERS
 *  app_id      [IN]
 *  data        [IN]            Pointer to block of memory
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_free_memory(kal_uint8 app_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data != NULL)
    {
        g_npplg_av_netscape_funcs[app_id].memfree(data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_set_callback_app_id
 * DESCRIPTION
 *  This function is used to set the app id which should be used by MDI callback.
 * PARAMETERS
 *  obj_type    [IN]        Object type
 *  app_id      [IN]        Application id
 * RETURNS
 *  Active plug-in instance
 *****************************************************************************/
void npplg_av_main_set_callback_app_id(kal_uint8 obj_type, kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
    {
        g_npplg_av_context.audio_callback_app_id = app_id;
    }
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
    else if (obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
    {
        g_npplg_av_context.video_callback_app_id = app_id;
    }
#ifdef __MMI_VIDEO_STREAM__
    else if (obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
    {
        g_npplg_av_context.stream_callback_app_id = app_id;
    }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_callback_app_id
 * DESCRIPTION
 *  This function is used to get the app id which should be used by MDI callback.
 * PARAMETERS
 *  obj_type    [IN]        Object type
 * RETURNS
 *  Application id
 *****************************************************************************/
kal_uint8 npplg_av_main_get_callback_app_id(kal_uint8 obj_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
    {
        return g_npplg_av_context.audio_callback_app_id;
    }
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
    else if (obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
    {
        return g_npplg_av_context.video_callback_app_id;
    }
#ifdef __MMI_VIDEO_STREAM__
    else if (obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
    {
        return g_npplg_av_context.stream_callback_app_id;
    }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__*/
    else
    {
        ASSERT(0);
    }

    return NPPLG_AV_APP_ID_TOTAL;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_active_instance
 * DESCRIPTION
 *  This function is used to get active plug-in instance.
 * PARAMETERS
 *  app_id      [IN]        Application id
 * RETURNS
 *  Active plug-in instance
 *****************************************************************************/
npplg_av_instance_struct *npplg_av_main_get_active_instance(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_id >= NPPLG_AV_APP_ID_TOTAL)
    {
        ASSERT(0);
    }

    return g_npplg_av_context.app_cnxt[app_id].active_instance;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_set_active_instance
 * DESCRIPTION
 *  This function is used to set active plug-in instance.
 * PARAMETERS
 *  active_instance [IN]            Active plug-in instance
 *  clear_interrupt [IN]            Clear interrupt instance
 *  app_id          [IN]            Application id
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_set_active_instance(npplg_av_instance_struct *active_instance,
                                       kal_bool clear_interrupt,
                                       kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *interrupt_instance;
    kal_uint8 interrupt_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_npplg_av_context.app_cnxt[app_id].active_instance = active_instance;
    if (active_instance != NULL)
    {
        NPPLG_AV_APP_ENTER_STATE(app_id, g_npplg_av_context.app_cnxt[app_id].state, NPPLG_AV_USER_STATE_INSTANCE_ACTIVE);
    }
    else
    {
        NPPLG_AV_APP_ENTER_STATE(app_id, g_npplg_av_context.app_cnxt[app_id].state, NPPLG_AV_USER_STATE_INSTANCE_CREATED);
        
        if (clear_interrupt)
        {
            g_npplg_av_context.app_cnxt[app_id].interrupt_instance = NULL;
            g_npplg_av_context.app_cnxt[app_id].interrupt_event = NPPLG_AV_INT_EVT_UNKNOWN;
        }

        /* Activate the interrupt instance */
        if (g_npplg_av_context.app_cnxt[app_id].interrupt_instance != NULL)
        {
            interrupt_instance = g_npplg_av_context.app_cnxt[app_id].interrupt_instance;
            interrupt_event = g_npplg_av_context.app_cnxt[app_id].interrupt_event;

            g_npplg_av_context.app_cnxt[app_id].interrupt_instance = NULL;
            g_npplg_av_context.app_cnxt[app_id].interrupt_event = NPPLG_AV_INT_EVT_UNKNOWN;
            
            npplg_av_main_dispatch_event(interrupt_instance, interrupt_event);
        }
        else
        {
            npplg_av_main_auto_play_audio(app_id, KAL_TRUE);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_volume
 * DESCRIPTION
 *  This function is used to get current volume setting.
 * PARAMETERS
 *  app_id      [IN]        Application id
 * RETURNS
 *  Current volume setting
 *****************************************************************************/
kal_uint8 npplg_av_main_get_volume(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    return MDI_AUD_VOL_EX_MUTE(MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_media_vol()));
#else
    if (g_npplg_av_context.app_cnxt[app_id].mute)
    {
        return MDI_AUD_VOL_EX_MUTE(0);
    }
    else
    {
        return MDI_AUD_VOL_EX_MUTE(g_npplg_av_context.app_cnxt[app_id].volume);
    }
#endif /* __COSMOS_MMI_PACKAGE__ */
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_set_mute
 * DESCRIPTION
 *  This function is used to set volume setting.
 * PARAMETERS
 *  mute        [IN]            Speaker on or off
 *  app_id      [IN]            Application id
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_set_mute(kal_bool mute, kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_npplg_av_context.app_cnxt[app_id].mute = mute;

    if (!mute && g_npplg_av_context.app_cnxt[app_id].volume == 0)
    {
        g_npplg_av_context.app_cnxt[app_id].volume = 1;
    }        
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_aud_default_size
 * DESCRIPTION
 *  This function is used to get the default size of audio object.
 *
 *  If NPPLG_AV_CFG_SET_DEFAULT_AUD_OBJ_SIZE is defined, application will use the 
 *  following configuration (NPPLG_AV_CFG_DEFAULT_AUD_WIDTH and 
 *  NPPLG_AV_CFG_DEFAULT_AUD_HEIGHT) as the default size when author does not assign 
 *  object width or object height.
 *
 *  If NPPLG_AV_CFG_SET_DEFAULT_AUD_OBJ_SIZE is not defined, application will use
 *  ((NPPLG_AV_CFG_DIFF_AUD_PLAY_PANEL_NUM - 1) * icon_width) and (icon_height + 
 *  progress_bar_height) as the default size when author does not assign object width 
 *  or object height.
 * PARAMETERS
 *  width           [OUT]        Default width
 *  height          [OUT]        Default height
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_get_aud_default_size(kal_int32 *width, kal_int32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef NPPLG_AV_CFG_SET_DEFAULT_AUD_OBJ_SIZE
    *width = NPPLG_AV_CFG_DEFAULT_AUD_WIDTH;
    *height = NPPLG_AV_CFG_DEFAULT_AUD_HEIGHT;
#else
    *width = (NPPLG_AV_CFG_DIFF_AUD_PLAY_PANEL_NUM - 1) * g_npplg_av_context.icon_width;
    *height = g_npplg_av_context.icon_height + g_npplg_av_context.bar_height;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_add_auto_play_instance
 * DESCRIPTION
 *  Add auto play instance to plug-in's queue
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_add_auto_play_instance(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_npplg_av_util_funcs[plugin_data->app_id].is_silent_setting() == KAL_FALSE &&
        npplg_av_main_is_instance_in_list(g_npplg_av_context.app_cnxt[plugin_data->app_id].auto_play_queue, plugin_data) == KAL_FALSE)
    {
        if (npplg_av_main_add_instance_into_list(&(g_npplg_av_context.app_cnxt[plugin_data->app_id].auto_play_queue), plugin_data) == KAL_TRUE)
        {
            npplg_av_main_auto_play_audio(plugin_data->app_id, KAL_FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_auto_play_audio
 * DESCRIPTION
 *  Play the audio automatically after the page is loaded
 * PARAMETERS
 *  app_id      [IN]            Application id
 *  notify_app  [IN]            Notify application to play bgsound
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_auto_play_audio(kal_uint8 app_id, kal_bool notify_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *play;
    npplg_av_instance_list_struct *list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_AUTO_PLAY_AUDIO, app_id);

    if (g_npplg_av_context.app_cnxt[app_id].is_suspend_by_mmi == KAL_TRUE ||
        g_npplg_av_context.is_speech_mode == KAL_TRUE ||
        g_npplg_av_context.app_cnxt[app_id].state == NPPLG_AV_USER_STATE_TERMINATED ||
        g_npplg_av_context.app_cnxt[app_id].state == NPPLG_AV_USER_STATE_INITIALIZED)
    {
        NPPLG_AV_UNLOCK;
        return;
    }

    if (kal_get_active_module_id() == MOD_MMI &&
        g_npplg_av_context.app_cnxt[app_id].auto_play_queue != NULL)
    {
        npplg_av_util_send_auto_play_audio_ind(g_npplg_av_context.app_cnxt[app_id].mod_id, app_id, notify_app);

        NPPLG_AV_UNLOCK;
        return;
    }

    if (g_npplg_av_util_funcs[app_id].is_silent_setting() ||
        g_npplg_av_util_funcs[app_id].is_playing_audio())
    {
        NPPLG_AV_UNLOCK;
        return;
    }

    /*
     * Plug-in should not play the audio in following scenarios:
     * 1. if user profile is silent mode or meeting mode
     * 2. if browser is playing <bgsound>
     * 3. if browser is in the background
     * 4. user has chosen to play one instance
     */
    if (g_npplg_av_context.app_cnxt[app_id].is_suspend_by_mmi == KAL_FALSE &&
        g_npplg_av_context.app_cnxt[app_id].state != NPPLG_AV_USER_STATE_INSTANCE_ACTIVE)
    {
        if (g_npplg_av_context.app_cnxt[app_id].auto_play_queue != NULL)
        {
            list = g_npplg_av_context.app_cnxt[app_id].auto_play_queue;
            g_npplg_av_context.app_cnxt[app_id].auto_play_queue = list->next;
            play = list->instance;
            npplg_av_main_free_memory(app_id, list);

#ifdef __COSMOS_MMI_PACKAGE__
            npplg_av_main_dispatch_event(play, NPPLG_AV_INT_EVT_AUTO_PLAY);
#else
            npplg_av_main_dispatch_event(play, NPPLG_AV_INT_EVT_PLAY);
#endif
        }
        else if (notify_app)
        {
            g_npplg_av_util_funcs[app_id].notify_play_finish();
        }
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_start_timer
 * DESCRIPTION
 *  Start a timer
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  timer_type      [IN]        Timer type
 *  interval        [IN]        Timeout interval
 * RETURNS
 *  The result of starting timer
 *****************************************************************************/
kal_bool npplg_av_main_start_timer(npplg_av_instance_struct *plugin_data, kal_uint8 timer_type, kal_uint32 interval)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_timer_struct *timer_node, *prev_timer, *curr_timer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef OPERA_V10_BROWSER
    /*
     * MAUI_02579576
     * GogiPluginWindow may be invalid but Opera does not let plug-in know by NPP_SetWindow() or NPP_Destroy().
     * Plug-in needs to check whether NPWindow->window is NULL before calling utility functions provided by GogiPluginWindow.
     */
    if (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER &&
        (plugin_data->np_window == NULL || plugin_data->np_window->window == NULL))
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_NULL_WINDOW, plugin_data->instance_id, plugin_data->app_id, plugin_data->state);
        plugin_data->window = NULL;
        return KAL_FALSE;
    }
#endif /* OPERA_V10_BROWSER */

    if (plugin_data->window == NULL || plugin_data->plugin_window.start_timer == NULL)
    {
        return KAL_FALSE;
    }

    if (plugin_data->seekable == KAL_FALSE && timer_type == NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR)
    {
        return KAL_FALSE;
    }
    
    timer_node = (npplg_av_timer_struct*)g_npplg_av_netscape_funcs[plugin_data->app_id].memalloc(sizeof(npplg_av_timer_struct));
    if (timer_node == NULL)
    {
        return KAL_FALSE;
    }

    timer_node->timer_id = plugin_data->plugin_window.start_timer(plugin_data->window, interval);
    timer_node->timer_type = timer_type;
    timer_node->next = NULL;
    timer_node->valid = KAL_TRUE;

    if (plugin_data->timer_list == NULL)
    {
        plugin_data->timer_list = timer_node;
    }
    else
    {
        prev_timer = curr_timer = plugin_data->timer_list;
        while (curr_timer != NULL)
        {
            prev_timer = curr_timer;
            curr_timer = curr_timer->next;
        }
        prev_timer->next = timer_node;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_stop_timer
 * DESCRIPTION
 *  Stop timer
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  timer_type      [IN]        Timer type
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_stop_timer(npplg_av_instance_struct *plugin_data, kal_uint8 timer_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_timer_struct *timer_node = NULL, *prev_timer, *curr_timer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_STOP_ONE_TIMER, plugin_data->instance_id, plugin_data->state, timer_type);
    
    if (plugin_data->timer_list != NULL)
    {
        if (plugin_data->timer_list->timer_type == timer_type)
        {
            if (kal_get_active_module_id() == MOD_MMI)
            {
                plugin_data->timer_list->valid = KAL_FALSE;
            }
            else
            {
                timer_node = plugin_data->timer_list;
                plugin_data->timer_list = timer_node->next;
            }
        }
        else
        {
            prev_timer = curr_timer = plugin_data->timer_list;
            while (curr_timer != NULL)
            {
                if (curr_timer->timer_type == timer_type)
                {
                    if (kal_get_active_module_id() == MOD_MMI)
                    {
                        curr_timer->valid = KAL_FALSE;
                    }
                    else
                    {
                        timer_node = curr_timer;
                        prev_timer->next = curr_timer->next;
                    }
                    break;
                }
                prev_timer = curr_timer;
                curr_timer = curr_timer->next;
            }
        }

        if (timer_node != NULL)
        {

#ifdef OPERA_V10_BROWSER
            /*
             * MAUI_02579576
             * GogiPluginWindow may be invalid but Opera does not let plug-in know by NPP_SetWindow() or NPP_Destroy().
             * Plug-in needs to check whether NPWindow->window is NULL before calling utility functions provided by GogiPluginWindow.
             */
            if (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER &&
                (plugin_data->np_window == NULL || plugin_data->np_window->window == NULL))
            {
                MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_NULL_WINDOW, plugin_data->instance_id, plugin_data->app_id, plugin_data->state);
                plugin_data->window = NULL;
            }
#endif /* OPERA_V10_BROWSER */

            if (plugin_data->window != NULL && plugin_data->plugin_window.stop_timer != NULL)
            {
#ifdef OPERA_V10_BROWSER
                if (plugin_data->app_id != NPPLG_AV_APP_ID_OPERA_BROWSER ||
                    (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER && plugin_data->deleting == KAL_FALSE))
#endif
                plugin_data->plugin_window.stop_timer(plugin_data->window, timer_node->timer_id);
            }
            npplg_av_main_free_memory(plugin_data->app_id, timer_node);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_stop_all_timer
 * DESCRIPTION
 *  Stop all timer
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_stop_all_timer(npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_timer_struct *timer_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_STOP_ALL_TIMER, plugin_data->instance_id, plugin_data->state);

    /*
     * Timer that audio may start:
     * NPPLG_AV_TIMER_AUDIO_BUILD_CACHE_CHECK
     * NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR
     * NPPLG_AV_TIMER_SEEK_REPEAT
     * NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG
     * NPPLG_AV_TIMER_RESET_PLAY_PANEL
     *
     * Timer that video may start:
     * NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR
     * NPPLG_AV_TIMER_SEEK_REPEAT
     * NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG
     * NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL
     * NPPLG_AV_TIMER_PDL_BUF_CHECK
     * NPPLG_AV_TIMER_RESET_PLAY_PANEL
     *
     * Timer that video streaming may start:
     * NPPLG_AV_TIMER_UPDATE_PROGRESS_BAR
     * NPPLG_AV_TIMER_SEEK_REPEAT
     * NPPLG_AV_TIMER_UPDATE_PROCESSNG_IMG
     * NPPLG_AV_TIMER_HIDE_VIDEO_PLAY_PANEL
     * NPPLG_AV_TIMER_STREAM_BUF_CHECK
     * NPPLG_AV_TIMER_RESET_PLAY_PANEL
     */
    if (kal_get_active_module_id() == MOD_MMI)
    {
        timer_node = plugin_data->timer_list;
        while (timer_node != NULL)
        {
            timer_node->valid = KAL_FALSE;
            timer_node = timer_node->next;
        }
    }
    else
    {
        while (plugin_data->timer_list != NULL)
        {
            timer_node = plugin_data->timer_list;
            plugin_data->timer_list = plugin_data->timer_list->next;

#ifdef OPERA_V10_BROWSER
            /*
             * MAUI_02579576
             * GogiPluginWindow may be invalid but Opera does not let plug-in know by NPP_SetWindow() or NPP_Destroy().
             * Plug-in needs to check whether NPWindow->window is NULL before calling utility functions provided by GogiPluginWindow.
             */
            if (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER &&
                (plugin_data->np_window == NULL || plugin_data->np_window->window == NULL))
            {
                MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_NULL_WINDOW, plugin_data->instance_id, plugin_data->app_id, plugin_data->state);
                plugin_data->window = NULL;
            }
#endif /* OPERA_V10_BROWSER */

            if (plugin_data->window != NULL && plugin_data->plugin_window.stop_timer != NULL)
            {
#ifdef OPERA_V10_BROWSER
                if (plugin_data->app_id != NPPLG_AV_APP_ID_OPERA_BROWSER ||
                    (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER && plugin_data->deleting == KAL_FALSE))
#endif
                plugin_data->plugin_window.stop_timer(plugin_data->window, timer_node->timer_id);
            }
            npplg_av_main_free_memory(plugin_data->app_id, timer_node);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_check_timer_start
 * DESCRIPTION
 *  Check timer has been start or not
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  timer_type      [IN]        Timer type
 * RETURNS
 *  KAL_TRUE: timer is in the list
 *  KAL_FALSE: timer is not in the list
 *****************************************************************************/
kal_bool npplg_av_main_check_timer_start(npplg_av_instance_struct *plugin_data, kal_uint8 timer_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_timer_struct *curr_timer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_timer = plugin_data->timer_list;
    while (curr_timer != NULL)
    {
        if (curr_timer->timer_type == timer_type &&
            curr_timer->valid == KAL_TRUE)
        {
            return KAL_TRUE;
        }
        curr_timer = curr_timer->next;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_reset_control_state
 * DESCRIPTION
 *  This function is used to reset the state of playback control since mouse up event occurrs on another control.
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  issue_evt       [IN]        Plug-in should issue seek stop event or not
 * RETURNS
 *  Indicate whether the event is handled by plug-in
 * RETURN VALUE LIST
 *  KAL_TRUE            Plug-in handles the event
 *  KAL_FALSE           Plug-in ignores the event
 *****************************************************************************/
kal_bool npplg_av_main_reset_control_state(npplg_av_instance_struct *plugin_data, kal_bool issue_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;
    
    if (plugin_data->pressed_control != NULL)
    {
        plugin_data->pressed_control->pressed = KAL_FALSE;

        if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE &&
            issue_evt == KAL_TRUE &&
            ((plugin_data->pressed_control->type == NPPLG_AV_CTRL_TYPE_FAST_FORWARD) ||
             (plugin_data->pressed_control->type == NPPLG_AV_CTRL_TYPE_REWIND)))
        {
            /* Issue seek stop event */
            kal_uint8 evt_type = npplg_av_main_cvt_ctrl_type_to_evt(plugin_data->pressed_control->type, plugin_data->pressed_control->pressed);

            if (evt_type != NPPLG_AV_INT_EVT_UNKNOWN)
            {
                npplg_av_main_dispatch_event(plugin_data, evt_type);
            }
        }

        npplg_av_util_invalidate_rect(plugin_data, plugin_data->pressed_control);
        plugin_data->pressed_control = NULL;

        NPPLG_AV_UNLOCK;
        return KAL_TRUE;
    }

    NPPLG_AV_UNLOCK;
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_app_mod_id
 * DESCRIPTION
 *  This function is used to get app module id.
 * PARAMETERS
 *  app_id              [IN]    Application id
 * RETURNS
 *  Module id
 *****************************************************************************/
module_type npplg_av_main_get_app_mod_id(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_npplg_av_context.app_cnxt[app_id].mod_id;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_remove_instance_from_list
 * DESCRIPTION
 *  This function is used to remove plug-in instance from app's list.
 * PARAMETERS
 *  list            [IN]        Application's list
 *  plugin_data     [IN]        Plug-in instance data 
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_remove_instance_from_list(npplg_av_instance_list_struct **list, npplg_av_instance_struct *plugin_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_list_struct *prev, *cur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*list == NULL)
    {
        return;
    }

    cur = *list;

    if (cur->instance == plugin_data)
    {
        *list = cur->next;
        npplg_av_main_free_memory(plugin_data->app_id, cur);
    }
    else
    {
        prev = cur;
        cur = cur->next;
        
        while (cur != NULL)
        {
            if (cur->instance == plugin_data)
            {
                prev->next = cur->next;
                cur->next = NULL;

                npplg_av_main_free_memory(plugin_data->app_id, cur);
                return;
            }

            prev = cur;
            cur = cur->next;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_decide_video_visual_update
 * DESCRIPTION
 *  This function is used to get video visual update state.
 * PARAMETERS
 *  app_id          [IN]        Application id
 *  lcm_update      [IN]        Video visual update
 * RETURNS
 *  Video visual update is enabled or disabled
 * RETURN VALUE LIST
 *  KAL_TRUE            Video visual update is enabled
 *  KAL_FALSE           Video visual update is disabled
 *****************************************************************************/
kal_bool npplg_av_main_decide_video_visual_update(kal_uint8 app_id, kal_bool lcm_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_npplg_av_context.app_cnxt[app_id].lcm_update == KAL_FALSE || lcm_update == KAL_FALSE)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_switch_backlight
 * DESCRIPTION
 *  This function is used to turn on/off backlight.
 * PARAMETERS
 *  backlight_on    [IN]        Turn on or turn off backlight
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_switch_backlight(kal_bool backlight_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_npplg_av_context.backlight_on != backlight_on)
    {
        g_npplg_av_context.backlight_on = backlight_on;

        if (backlight_on)
        {
            srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        }
        else
        {
            srv_backlight_turn_off();
        }
    }
}


#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_create_video_layer
 * DESCRIPTION
 *  Create video layer
 * PARAMETERS
 *  app_id          [IN]        Application id
 *  rect_in         [IN]        Input area
 *  rect_out        [OUT]       Output area
 * RETURNS
 *  GDI layer handle
 *****************************************************************************/
gdi_handle npplg_av_main_create_video_layer(kal_uint8 app_id,
                                            npplg_av_rect_struct *rect_in,
                                            npplg_av_rect_struct *rect_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_util_create_hw_layer_extmemory_in_struct layer_in;
    mdi_util_create_hw_layer_out_struct layer_out;
    kal_int32 vdo_buf_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rect_in->w <= 0 || rect_in->h <= 0)
    {
        return GDI_NULL_HANDLE;
    }

    /* Buffer size should be a multiple of 16 */
    vdo_buf_size = (rect_in->w * rect_in->h * 2 + 15) / 16 * 16;
    g_npplg_av_context.app_cnxt[app_id].vdo_layer_buf = (kal_uint8*)npplg_av_main_alloc_noncache_memory(app_id, vdo_buf_size);
    if (g_npplg_av_context.app_cnxt[app_id].vdo_layer_buf == NULL)
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_CREATE_VDO_LAYER_NO_MEM);
        return GDI_NULL_HANDLE;
    }

    memset(&layer_in, 0, sizeof(mdi_util_create_hw_layer_in_struct));
    layer_in.buffer = g_npplg_av_context.app_cnxt[app_id].vdo_layer_buf;
    layer_in.buffer_size = vdo_buf_size;
    layer_in.offset_x = rect_in->x;
    layer_in.offset_y = rect_in->y;
    layer_in.width = rect_in->w;
    layer_in.height = rect_in->h;
    layer_in.scenario_id = MDI_MULTIMEDIA_VIDEO;

    g_npplg_av_context.app_cnxt[app_id].vdo_layer_handle = mdi_util_hw_layer_create_with_extmemory(&layer_in, &layer_out);

    if (layer_out.result == GDI_SUCCEED && g_npplg_av_context.app_cnxt[app_id].vdo_layer_handle != GDI_NULL_HANDLE)
    {
        rect_out->x = layer_out.offset_x;
        rect_out->y = layer_out.offset_y;
        rect_out->w = layer_out.width;
        rect_out->h = layer_out.height;
    }
    else
    {
        memset(rect_out, 0, sizeof(npplg_av_rect_struct));
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_CREATE_VDO_LAYER_GDI_ERROR, layer_out.result);
        npplg_av_main_free_noncache_memory(app_id, g_npplg_av_context.app_cnxt[app_id].vdo_layer_buf);
        g_npplg_av_context.app_cnxt[app_id].vdo_layer_buf = NULL;
        return GDI_NULL_HANDLE;
    }

    gdi_layer_push_and_set_active(g_npplg_av_context.app_cnxt[app_id].vdo_layer_handle);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_set_background(npplg_av_main_get_transparent_color(app_id));
    gdi_layer_pop_and_restore_active();

    return g_npplg_av_context.app_cnxt[app_id].vdo_layer_handle;
}
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_video_layer_handle
 * DESCRIPTION
 *  This function is used to provide the GDI layer handle which is created for video playing.
 * PARAMETERS
 *  app_id      [IN]            Application id
 * RETURNS
 *  Video layer handle
 *****************************************************************************/
gdi_handle npplg_av_main_get_video_layer_handle(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;
    
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_QUERY_VDO_LAYER, g_npplg_av_context.app_cnxt[app_id].vdo_layer_handle, app_id);

    NPPLG_AV_UNLOCK;
    return g_npplg_av_context.app_cnxt[app_id].vdo_layer_handle;

#else

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_QUERY_VDO_LAYER, GDI_NULL_HANDLE, app_id); 

    NPPLG_AV_UNLOCK;
    return GDI_NULL_HANDLE;
    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_is_playing
 * DESCRIPTION
 *  Whether A/V Plug-in is playing audio/video
 * PARAMETERS
 *  app_id      [IN]            Application id
 * RETURNS
 *  Whether A/V Plug-in is playing audio/video
 *****************************************************************************/
kal_bool npplg_av_main_is_playing(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_IS_PLAYING, app_id, g_npplg_av_context.app_cnxt[app_id].state);

    NPPLG_AV_LOCK;

    if (g_npplg_av_context.app_cnxt[app_id].state == NPPLG_AV_USER_STATE_INSTANCE_ACTIVE)
    {
        NPPLG_AV_UNLOCK;
        return KAL_TRUE;
    }

    NPPLG_AV_UNLOCK;
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_data_account
 * DESCRIPTION
 *  Get application's data account id
 * PARAMETERS
 *  app_id      [IN]            Application id
 * RETURNS
 *  Data account id
 *****************************************************************************/
kal_uint32 npplg_av_main_get_data_account(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 da = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    da = g_npplg_av_util_funcs[app_id].get_network_account();
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_APP_NW_ACCOUNT, app_id, da);

    return da;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_visible_screen_area
 * DESCRIPTION
 *  Get rendering area
 * PARAMETERS
 *  plugin_data [IN]            Plug-in instance data
 *  x           [OUT]           The coordinate of the top-left point
 *  y           [OUT]           The coordinate of the top-left point
 *  w           [OUT]           The width
 *  h           [OUT]           The height
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_get_visible_screen_area(npplg_av_instance_struct *plugin_data,
                                           kal_int32 *x,
                                           kal_int32 *y,
                                           kal_int32 *w,
                                           kal_int32 *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef OPERA_V10_BROWSER
    /*
     * MAUI_02579576
     * GogiPluginWindow may be invalid but Opera does not let plug-in know by NPP_SetWindow() or NPP_Destroy().
     * Plug-in needs to check whether NPWindow->window is NULL before calling utility functions provided by GogiPluginWindow.
     */
    if (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER &&
        (plugin_data->np_window == NULL || plugin_data->np_window->window == NULL))
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_NULL_WINDOW, plugin_data->instance_id, plugin_data->app_id, plugin_data->state);
        plugin_data->window = NULL;
    }
#endif /* OPERA_V10_BROWSER */

    if (plugin_data->window != NULL && plugin_data->plugin_window.get_visible_screen_area != NULL)
    {
        plugin_data->plugin_window.get_visible_screen_area(plugin_data->window, x, y, w, h);
    }
    else
    {
        *x = 0;
        *y = 0;
        *w = LCD_WIDTH;
        *h = LCD_HEIGHT;
    }
    
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_APP_RENDER_AREA, *x, *y, *w, *h);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_display_popup
 * DESCRIPTION
 *  Display popup
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  message_id      [IN]        Message string id
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_display_popup(npplg_av_instance_struct *plugin_data, MMI_ID_TYPE message_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *title, *message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;
    
#ifdef OPERA_V10_BROWSER
    /*
     * MAUI_02579576
     * GogiPluginWindow may be invalid but Opera does not let plug-in know by NPP_SetWindow() or NPP_Destroy().
     * Plug-in needs to check whether NPWindow->window is NULL before calling utility functions provided by GogiPluginWindow.
     */
    if (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER &&
        (plugin_data->np_window == NULL || plugin_data->np_window->window == NULL))
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_NULL_WINDOW, plugin_data->instance_id, plugin_data->app_id, plugin_data->state);
        plugin_data->window = NULL;
    }
#endif /* OPERA_V10_BROWSER */

    if (g_npplg_av_context.app_cnxt[plugin_data->app_id].is_suspend_by_mmi == KAL_FALSE
#ifdef __GADGET_SUPPORT__
        || plugin_data->app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET
#endif
       )
    {
        if (plugin_data->window != NULL && plugin_data->plugin_window.display_popup != NULL)
        {
            title = npplg_av_util_cvt_ucs2_to_utf8((const kal_char*)GetString(STR_ID_NPPLG_ERROR_TITLE), plugin_data->app_id);
            message = npplg_av_util_cvt_ucs2_to_utf8((const kal_char*)GetString(message_id), plugin_data->app_id);
            if (title != NULL && message != NULL)
            {
                plugin_data->plugin_window.display_popup(plugin_data->window, (char*)title, (char*)message);
            }

            npplg_av_main_free_memory(plugin_data->app_id, title);
            npplg_av_main_free_memory(plugin_data->app_id, message);
        }
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_convert_coordinate
 * DESCRIPTION
 *  Convert to LCD coordinate
 * PARAMETERS
 *  plugin_data     [IN]        Plug-in instance data
 *  old_x           [IN]        Original x
 *  old_y           [IN]        Original y
 *  new_x           [OUT]       x coordinate relative to LCD
 *  new_y           [OUT]       y coordinate relative to LCD
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_convert_coordinate(npplg_av_instance_struct *plugin_data,
                                      kal_int32 old_x,
                                      kal_int32 old_y,
                                      kal_int32 *new_x,
                                      kal_int32 *new_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef OPERA_V10_BROWSER
    /*
     * MAUI_02579576
     * GogiPluginWindow may be invalid but Opera does not let plug-in know by NPP_SetWindow() or NPP_Destroy().
     * Plug-in needs to check whether NPWindow->window is NULL before calling utility functions provided by GogiPluginWindow.
     */
    if (plugin_data->app_id == NPPLG_AV_APP_ID_OPERA_BROWSER &&
        (plugin_data->np_window == NULL || plugin_data->np_window->window == NULL))
    {
        MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_NULL_WINDOW, plugin_data->instance_id, plugin_data->app_id, plugin_data->state);
        plugin_data->window = NULL;
    }
#endif /* OPERA_V10_BROWSER */

    *new_x = old_x;
    *new_y = old_y;

    if (plugin_data->window != NULL && plugin_data->plugin_window.trans_coord != NULL)
    {
        plugin_data->plugin_window.trans_coord(plugin_data->window, new_x, new_y);
    }
    
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_APP_CVT_COORDINATE, plugin_data->app_id, old_x, old_y, *new_x, *new_y);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_gdi_layer
 * DESCRIPTION
 *  Get GDI layers created by applicatioin
 * PARAMETERS
 *  app_id          [IN]        Application id
 *  handle_1        [OUT]       Layer 1
 *  handle_2        [OUT]       Layer 2
 *  handle_3        [OUT]       Layer 3
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_get_gdi_layer(kal_uint8 app_id,
                                 gdi_handle *handle_1,
                                 gdi_handle *handle_2,
                                 gdi_handle *handle_3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle handle_0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_npplg_av_util_funcs[app_id].get_gdi_layer(&handle_0, handle_1, handle_2, handle_3);
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_APP_LAYER, app_id, *handle_1, *handle_2, *handle_3);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_transparent_color
 * DESCRIPTION
 *  Get transparent color
 * PARAMETERS
 *  app_id          [IN]        Application id
 * RETURNS
 *  void
 *****************************************************************************/
gdi_color npplg_av_main_get_transparent_color(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_npplg_av_util_funcs[app_id].get_transparent_color();
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_alloc_noncache_memory
 * DESCRIPTION
 *  Allocate non-cacheable memory
 * PARAMETERS
 *  app_id          [IN]        Application id
 *  size            [IN]        Memory size
 * RETURNS
 *  Memory pointer
 *****************************************************************************/
void *npplg_av_main_alloc_noncache_memory(kal_uint8 app_id, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_npplg_av_util_funcs[app_id].mem_alloc(size);
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_free_noncache_memory
 * DESCRIPTION
 *  Free non-cacheable memory
 * PARAMETERS
 *  app_id          [IN]        Application id
 *  size            [IN]        Memory size
 * RETURNS
 *  Memory pointer
 *****************************************************************************/
void npplg_av_main_free_noncache_memory(kal_uint8 app_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_npplg_av_util_funcs[app_id].mem_free(data);
    data = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_adjust_volume
 * DESCRIPTION
 *  This function is used to adjust volume.
 * PARAMETERS
 *  app_id          [IN]        Application id
 *  volume_up       [IN]        KAL_TRUE: volume up; KAL_FALSE: volume down
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_adjust_volume(kal_uint8 app_id, kal_bool volume_up)
{
#ifndef __COSMOS_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_obj_control_struct *found_ctrl = NULL;
    npplg_av_instance_struct *apply_instance = g_npplg_av_context.app_cnxt[app_id].active_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;
    
    if (g_npplg_av_context.app_cnxt[app_id].is_suspend_by_mmi == KAL_TRUE ||
        apply_instance == NULL)
    {
        NPPLG_AV_UNLOCK;
        return;
    }

    found_ctrl = npplg_av_util_get_control(apply_instance, NPPLG_AV_CTRL_TYPE_MUTE);
    
    if (volume_up)
    {
        if (g_npplg_av_context.app_cnxt[app_id].volume < NPPLG_AV_MAX_VOLUME_LEVEL)
        {
            /* Increase volume */
            g_npplg_av_context.app_cnxt[app_id].volume++;
            if (g_npplg_av_context.app_cnxt[app_id].volume > 0 &&
                found_ctrl != NULL &&
                found_ctrl->display == NPPLG_AV_CTRL_DISP_DISABLE)
            {
                /* Update mute control */
                found_ctrl->display = NPPLG_AV_CTRL_DISP_ENABLE;
                npplg_av_util_invalidate_rect(apply_instance, found_ctrl);
            }

            if (apply_instance != NULL)
            {
                apply_instance->mute = KAL_FALSE;
            }
        }
    }
    else
    {
        if (g_npplg_av_context.app_cnxt[app_id].volume > 0)
        {
            /* Decrease volume */
            g_npplg_av_context.app_cnxt[app_id].volume--;
            if (g_npplg_av_context.app_cnxt[app_id].volume == 0 &&
                found_ctrl != NULL &&
                found_ctrl->display == NPPLG_AV_CTRL_DISP_ENABLE)
            {
                /* Update mute control */
                found_ctrl->display = NPPLG_AV_CTRL_DISP_DISABLE;
                npplg_av_util_invalidate_rect(apply_instance, found_ctrl);
            }

            if (apply_instance != NULL && g_npplg_av_context.app_cnxt[app_id].volume == 0)
            {
                apply_instance->mute = KAL_TRUE;
            }
        }
    }

    if (g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_OCCUPIED)
    {
        npplg_av_main_set_mute(apply_instance->mute, apply_instance->app_id);

        npplg_av_util_send_notify_mmi_ind(kal_get_active_module_id(),
                                          apply_instance->instance_id,
                                          apply_instance->app_id,
                                          NPPLG_AV_ACTION_SET_VOLUME);
    }

    NPPLG_AV_UNLOCK;
#endif /* __COSMOS_MMI_PACKAGE__ */
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_notify_scroll
 * DESCRIPTION
 *  This function is used to scroll video.
 * PARAMETERS
 *  app_id          [IN]        Application id
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_notify_scroll(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *active_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_APP_NOTIFY_SCROLL, app_id);

    active_instance = npplg_av_main_get_active_instance(app_id);

    if (active_instance == NULL)
    {
        NPPLG_AV_UNLOCK;
        return;
    }

    /* Only need to update the position of video layer if object is video */
        
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
#if defined(__MMI_VIDEO_STREAM__)
    if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING ||
        active_instance->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#else
    if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#endif /* __MMI_VIDEO_STREAM__ */
    {
        npplg_av_video_set_position(active_instance);
    }
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_notify_screen_rotation_complete
 * DESCRIPTION
 *  This function is used to resume video playing after screen is rotated.
 * PARAMETERS
 *  app_id              [IN]    Application id
 *  lcd_orientatioin    [IN]    LCD orientation
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_notify_screen_rotation_complete(kal_uint8 app_id, kal_int32 lcd_orientatioin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *active_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_APP_NOTIFY_SCREEN_ROTATE, app_id, lcd_orientatioin);

    active_instance = npplg_av_main_get_active_instance(app_id);

    if (active_instance == NULL ||
        g_npplg_av_context.app_cnxt[app_id].is_suspend_by_mmi == KAL_TRUE ||
        g_npplg_av_context.is_speech_mode == KAL_TRUE)
    {
        /*
         * 1. Can not resume video playing if plug-in is suspended due to interrupt
         * 2. Can not resume video playing if plug-in is not suspended but handset is in call
         */
        NPPLG_AV_UNLOCK;
        return;
    }

    g_npplg_av_context.app_cnxt[active_instance->app_id].rotate = npplg_av_main_cvt_mmi_screen_rotate_to_mdi(lcd_orientatioin);
    
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
    {
        if (active_instance->state == NPPLG_AV_VIDEO_OBJ_STATE_PAUSED_PLAY)
        {
            npplg_av_main_dispatch_event(active_instance, NPPLG_AV_INT_EVT_PLAY);
        }
        else
        {
            npplg_av_video_redraw_vdo_layer(active_instance);
        }
    }
#if defined(__MMI_VIDEO_STREAM__)
    else if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
    {
        if (active_instance->state == NPPLG_AV_STREAM_OBJ_STATE_PAUSED_PLAY)
        {
            npplg_av_main_dispatch_event(active_instance, NPPLG_AV_INT_EVT_PLAY);
        }
        else
        {
            npplg_av_util_invalidate_rect(active_instance, NULL);
        }
    }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

    NPPLG_AV_UNLOCK; 
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_mmi_notify_suspend
 * DESCRIPTION
 *  This function is invoked by MMI to stop audio/video playing.
 * PARAMETERS
 *  app_id          [IN]        Application id
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_mmi_notify_suspend(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *active_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_MMI_SUSPEND, app_id);

    ASSERT(kal_get_active_module_id() == MOD_MMI);

    NPPLG_AV_LOCK;

    g_npplg_av_context.app_cnxt[app_id].is_suspend_by_mmi = KAL_TRUE;

    active_instance = npplg_av_main_get_active_instance(app_id);

    if (active_instance != NULL && active_instance->suspend == KAL_FALSE)
    {
        active_instance->suspend = KAL_TRUE;

        if (g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_OCCUPIED)
        {
            mdi_audio_clear_interrupt_callback();
#ifdef __COSMOS_MMI_PACKAGE__
            if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
            {
                npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)active_instance->obj_data;
                if (aud_data->suspend_bgplay)
                {
                    mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
                }
            }
#else
            mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
#endif /* __COSMOS_MMI_PACKAGE__ */
        }

        if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
        {
            npplg_av_audio_suspend_by_app(active_instance);
        }
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
        else if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
        {
            mdi_video_enable_mimic_task(g_npplg_av_context.app_cnxt[app_id].mimic_mod_id);
            npplg_av_video_suspend_by_app(active_instance);
            mdi_video_disable_mimic_task();
        }
#ifdef __MMI_VIDEO_STREAM__
        else if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
        {
            mdi_video_enable_mimic_task(g_npplg_av_context.app_cnxt[app_id].mimic_mod_id);
            npplg_av_stream_suspend_by_app(active_instance);
            mdi_video_disable_mimic_task();
        }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_mmi_notify_resume
 * DESCRIPTION
 *  This function is invoked by MMI to resume audio/video playing.
 * PARAMETERS
 *  app_id          [IN]        Application id
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_mmi_notify_resume(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *active_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_MMI_RESUME, app_id);
    
    ASSERT(kal_get_active_module_id() == MOD_MMI);
    
    NPPLG_AV_LOCK;

    g_npplg_av_context.is_speech_mode = (kal_bool)mdi_audio_is_speech_mode();

    g_npplg_av_context.app_cnxt[app_id].is_suspend_by_mmi = KAL_FALSE;

    active_instance = npplg_av_main_get_active_instance(app_id);

    if (active_instance != NULL && active_instance->suspend)
    {
#if defined(__GADGET_SUPPORT__) && defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__)
        if (app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET &&
            active_instance->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING &&
            (active_instance->state == NPPLG_AV_STREAM_OBJ_STATE_CONNECTING ||
             active_instance->state == NPPLG_AV_STREAM_OBJ_STATE_BUFFERING ||
             active_instance->state == NPPLG_AV_STREAM_OBJ_STATE_PLAYING))
        {
            kal_int32 bearer_status = cbm_get_bearer_status(srv_wgtmgr_get_data_account());

            MMI_TRACE(NPPLG_AV_TRC_GROUP,
                      NPPLG_AV_BEARER_STATUS,
                      srv_wgtmgr_get_data_account(),
                      bearer_status);

            if (bearer_status == CBM_DEACTIVATING || bearer_status == CBM_DEACTIVATED)
            {
                active_instance->error = NPPLG_AV_ERROR_NETWORK;
                if (g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_OCCUPIED)
                {
                    g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_NULL;
                }
                npplg_av_stream_close_by_app(active_instance);
            }
        }
#endif /* defined(__GADGET_SUPPORT__) && defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_VIDEO_STREAM__) */

        if (g_npplg_av_context.is_speech_mode == KAL_FALSE &&
            g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_OCCUPIED)
        {
            mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
            mdi_audio_register_interrupt_callback(npplg_av_main_interrupt_callback, NULL);

            /* Apply the mute setting of active plug-in instance */
            npplg_av_main_set_mute(active_instance->mute, active_instance->app_id);
            
            /* Set volume */
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, npplg_av_main_get_volume(active_instance->app_id));

#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
#ifdef __MMI_VIDEO_STREAM__
            if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO ||
                active_instance->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
#else
            if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
#endif /* __MMI_VIDEO_STREAM__ */
            {
                /* Get GDI layer flag */
                g_npplg_av_context.blt_layer_flag = vapp_npplg_av_video_get_display_layer_flag();
                g_npplg_av_context.hw_layer_flag = vapp_npplg_av_video_get_hw_layer_flag();
            }
#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__) */
        }
        else if (g_npplg_av_context.is_speech_mode == KAL_TRUE)
        {
            /* Background call */
            g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_NULL;
        }
        
        active_instance->suspend = KAL_FALSE;
        
        /*
         * Plug-in may not receive mouse up event if interrupt comes
         * but this case should be handled by user application because
         * plug-in can not call the utility function provided by user 
         * application in MMI task. So plug-in does not call
         * npplg_av_main_reset_control_state(active_instance, KAL_FALSE);
         * here.
         */

        if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
        {
            npplg_av_audio_resume_by_app(active_instance);
        }
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
        else if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
        {
            mdi_video_enable_mimic_task(g_npplg_av_context.app_cnxt[app_id].mimic_mod_id);
            npplg_av_video_resume_by_app(active_instance);
            mdi_video_disable_mimic_task();
        }
#ifdef __MMI_VIDEO_STREAM__
        else if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
        {
            mdi_video_enable_mimic_task(g_npplg_av_context.app_cnxt[app_id].mimic_mod_id);
            npplg_av_stream_resume_by_app(active_instance);
            mdi_video_disable_mimic_task();
        }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    }

    /* Check if plug-in should play audio */
    npplg_av_main_auto_play_audio(app_id, KAL_FALSE);
    
    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_mmi_notify_close
 * DESCRIPTION
 *  This function is invoked by MMI to close audio/video playing.
 * PARAMETERS
 *  app_id          [IN]        Application id
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_mmi_notify_close(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *active_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_MMI_CLOSE, app_id);
    
    ASSERT(kal_get_active_module_id() == MOD_MMI);

    NPPLG_AV_LOCK;

    g_npplg_av_context.app_cnxt[app_id].is_suspend_by_mmi = KAL_TRUE;

    active_instance = npplg_av_main_get_active_instance(app_id);

    if (active_instance != NULL)
    {
        if (active_instance->suspend == KAL_FALSE &&
            g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_OCCUPIED)
        {
            mdi_audio_clear_interrupt_callback();
#ifdef __COSMOS_MMI_PACKAGE__
            if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
            {
                npplg_av_audio_data_struct *aud_data = (npplg_av_audio_data_struct*)active_instance->obj_data;
                if (aud_data->suspend_bgplay)
                {
                    mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
                }
            }
#else
            mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_ASYNC_APP);
#endif /* __COSMOS_MMI_PACKAGE__ */

        }

        if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
        {
            if (active_instance->suspend == KAL_FALSE)
            {
                active_instance->suspend = KAL_TRUE;
                npplg_av_audio_suspend_by_app(active_instance);
            }
            npplg_av_audio_close_by_app(active_instance);
        }
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
        else if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
        {
            mdi_video_enable_mimic_task(g_npplg_av_context.app_cnxt[app_id].mimic_mod_id);
            if (active_instance->suspend == KAL_FALSE)
            {
                active_instance->suspend = KAL_TRUE;
                npplg_av_video_suspend_by_app(active_instance);
            }
            npplg_av_video_close_by_app(active_instance);
            mdi_video_disable_mimic_task();
        }
#ifdef __MMI_VIDEO_STREAM__
        else if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
        {
            mdi_video_enable_mimic_task(g_npplg_av_context.app_cnxt[app_id].mimic_mod_id);
            if (active_instance->suspend == KAL_FALSE)
            {
                active_instance->suspend = KAL_TRUE;
                npplg_av_stream_suspend_by_app(active_instance);
            }
            npplg_av_stream_close_by_app(active_instance);
            mdi_video_disable_mimic_task();
        }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    }
    
    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_mmi_notify_reset
 * DESCRIPTION
 *  This function is invoked by MMI to reset plug-in state to idle state.
 * PARAMETERS
 *  app_id          [IN]        Application id
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_mmi_notify_reset(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *active_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_MMI_RESET, app_id);
    
    ASSERT(kal_get_active_module_id() == MOD_MMI);

    NPPLG_AV_LOCK;

    active_instance = npplg_av_main_get_active_instance(app_id);

    if (active_instance != NULL && active_instance->suspend == KAL_TRUE)
    {
#ifdef __GADGET_SUPPORT__
        if (app_id == NPPLG_AV_APP_ID_GOOGLE_GADGET)
        {
            /*
             * Check plug-in is in idle screen or in details view
             *
             * If plug-in is in idle screen, plug-in should switch to idle state because media player and plug-in can
             * exist in idle screen at the same time.
             * If user plays audio from media player widget when plug-in is playing audio, MDI Audio will call plug-in's
             * interrupt callback. Plug-in should stop audio playing and switch to idle state in this case because plug-in
             * can not let user do something when plug-in is suspended.
             */
#ifdef __COSMOS_MMI_PACKAGE__
            if (vapp_launcher_is_active())
#else
            if (mmi_idle_is_active())
#endif
            {
                /*
                 * Idle screen:
                 * 1. Set state as RESET_PLAY_PANEL state
                 * 2. Send primitive to user task to set state as IDLE state
                 */

                if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
                {
                    npplg_av_audio_close_by_app(active_instance);
                }
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
                else if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
                {
                    npplg_av_video_close_by_app(active_instance);
                }
#ifdef __MMI_VIDEO_STREAM__
                else if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
                {
                    npplg_av_stream_close_by_app(active_instance);
                }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

                if (g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_OCCUPIED)
                {
                    g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_NULL;
                }

                npplg_av_util_send_reset_ind(g_npplg_av_context.app_cnxt[app_id].mod_id,
                                             active_instance->instance_id,
                                             active_instance->app_id);
            }
        }
#endif /* __GADGET_SUPPORT__ */
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_mmi_notify_video_visual_update
 * DESCRIPTION
 *  This function is invoked by MMI to enable/disable video visual update.
 * PARAMETERS
 *  app_id          [IN]        Application id
 *  lcm_update      [IN]        TRUE: enable video visual update; FALSE: disable video visual update
 *  force_update    [IN]        TRUE: apply until browser change next time; FALSE: only apply once
 *  clear_vdo_layer [IN]        TRUE: clear video layer; FALSE: not clear video layer
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_mmi_notify_video_visual_update(kal_uint8 app_id, kal_bool lcm_update, kal_bool force_update, kal_bool clear_vdo_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *active_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_MMI_NOTIFY_VIDEO_VISUAL_UPDATE, lcm_update, app_id, force_update);

    ASSERT(kal_get_active_module_id() == MOD_MMI);

    NPPLG_AV_LOCK;

    if (force_update)
    {
        g_npplg_av_context.app_cnxt[app_id].lcm_update = lcm_update;
    }

    active_instance = npplg_av_main_get_active_instance(app_id);

    if (active_instance != NULL &&
        g_npplg_av_context.app_cnxt[app_id].is_suspend_by_mmi == KAL_FALSE)
    {
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
        if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
        {
            mdi_video_enable_mimic_task(g_npplg_av_context.app_cnxt[app_id].mimic_mod_id);
            npplg_av_video_visual_update(active_instance, lcm_update, clear_vdo_layer);
            mdi_video_disable_mimic_task();
        }
#ifdef __MMI_VIDEO_STREAM__
        else if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
        {
            mdi_video_enable_mimic_task(g_npplg_av_context.app_cnxt[app_id].mimic_mod_id);
            npplg_av_stream_visual_update(active_instance, lcm_update, clear_vdo_layer);
            mdi_video_disable_mimic_task();
        }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_mmi_notify_screen_rotate
 * DESCRIPTION
 *  This function is invoked by MMI to notify screen rotate.
 * PARAMETERS
 *  app_id              [IN]    Application id
 *  lcd_orientatioin    [IN]    LCD orientation
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_mmi_notify_screen_rotate(kal_uint8 app_id, kal_int32 lcd_orientation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *active_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_MMI_NOTIFY_SCREEN_ROTATE, app_id);

    ASSERT(kal_get_active_module_id() == MOD_MMI);

    NPPLG_AV_LOCK;
    g_npplg_av_context.app_cnxt[app_id].rotate = npplg_av_main_cvt_mmi_screen_rotate_to_mdi(lcd_orientation);

    active_instance = npplg_av_main_get_active_instance(app_id);

    if (active_instance != NULL &&
        g_npplg_av_context.app_cnxt[app_id].is_suspend_by_mmi == KAL_FALSE)
    {
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
        if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
        {
            mdi_video_enable_mimic_task(g_npplg_av_context.app_cnxt[app_id].mimic_mod_id);
            npplg_av_video_stop_by_app_for_screen_rotate(active_instance);
            mdi_video_disable_mimic_task();
        }
#ifdef __MMI_VIDEO_STREAM__
        else if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
        {
            mdi_video_enable_mimic_task(g_npplg_av_context.app_cnxt[app_id].mimic_mod_id);
            npplg_av_stream_stop_by_app_for_screen_rotate(active_instance);
            mdi_video_disable_mimic_task();
        }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_stop_current_activity
 * DESCRIPTION
 *  This function is invoked to stop current activity.
 *  The state of active instance will be reset to idle state.
 * PARAMETERS
 *  app_id              [IN]    Application id
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_stop_current_activity(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *active_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;
    
    active_instance = npplg_av_main_get_active_instance(app_id);

    if (active_instance != NULL)
    {
        /* Clear interrupt instance */
        g_npplg_av_context.app_cnxt[app_id].interrupt_instance = NULL;
        g_npplg_av_context.app_cnxt[app_id].interrupt_event = NPPLG_AV_INT_EVT_UNKNOWN;

        if (g_npplg_av_context.app_cnxt[app_id].is_suspend_by_mmi == KAL_FALSE)
        {
            /* Stop current activity */
            npplg_av_main_dispatch_event(active_instance, NPPLG_AV_INT_EVT_STOP);
        }
        else
        {
            ASSERT(active_instance->suspend == KAL_TRUE);

            if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
            {
                npplg_av_audio_close_by_app(active_instance);
            }
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
            else if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
            {
                npplg_av_video_close_by_app(active_instance);
            }
#ifdef __MMI_VIDEO_STREAM__
            else if (active_instance->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
            {
                npplg_av_stream_close_by_app(active_instance);
            }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

            npplg_av_main_dispatch_event(active_instance, NPPLG_AV_INT_EVT_STOP);

            active_instance->suspend = KAL_FALSE;
        }
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_get_plugin_layer
 * DESCRIPTION
 *  This function is used to get GDI layer which plug-in uses to draw UI.
 * PARAMETERS
 *  app_id              [IN]    Application id
 * RETURNS
 *  GDI layer handle
 *****************************************************************************/
gdi_handle npplg_av_main_get_plugin_layer(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle handle = GDI_NULL_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    g_npplg_av_util_funcs[app_id].get_plugin_layer(&handle);

    NPPLG_AV_UNLOCK;
    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_suspend_background_play
 * DESCRIPTION
 *  Suspend background play
 * PARAMETERS
 *  app_id          [IN]    Application id
 *  suspend_bgplay  [IN]    Suspend or terminate bgplay (TRUE: suspend, FALSE: terminate)
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_suspend_background_play(kal_uint8 app_id, kal_bool suspend_bgplay)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_suspend_background_play_req_struct *req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_npplg_av_context.res_status == NPPLG_AV_RES_STATUS_NULL)
    {
        g_npplg_av_context.res_status = NPPLG_AV_RES_STATUS_OCCUPYING;
        g_npplg_av_context.play_app_id = app_id;

        req = (npplg_av_suspend_background_play_req_struct*)
                        construct_local_para(sizeof(npplg_av_suspend_background_play_req_struct), TD_CTRL | TD_RESET);
        req->suspend_bgplay = suspend_bgplay;

        npplg_av_util_send_ilm(kal_get_active_module_id(),
                               MOD_MMI,
                               MSG_ID_NPPLG_AV_SUSPEND_BACKGROUND_PLAY_REQ,
                               req,
                               NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_interrupt_callback
 * DESCRIPTION
 *  MDI Audio will call this callback in MMI task when interrupt comes
 * PARAMETERS
 *  result          [IN]        Result
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_interrupt_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_INTERRUPT_CALLBACK, g_npplg_av_context.play_app_id, result);
    
    if (result == MDI_AUDIO_TERMINATED)
    {
        npplg_av_main_mmi_notify_suspend(g_npplg_av_context.play_app_id);
        npplg_av_main_mmi_notify_reset(g_npplg_av_context.play_app_id);
    }
    else
    {
        /* MDI Audio should only provide result MDI_AUDIO_TERMINATED */
        ASSERT(0);
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_suspend_background_play_rsp_handler
 * DESCRIPTION
 *  MSG_ID_NPPLG_AV_SUSPEND_BACKGROUND_PLAY_RSP handler
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_suspend_background_play_rsp_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_suspend_background_play_rsp_struct *rsp;
    npplg_av_instance_struct *plugin_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    rsp = (npplg_av_suspend_background_play_rsp_struct*)info;

    plugin_data = npplg_av_main_get_active_instance(rsp->app_id);

    if (plugin_data != NULL)
    {
        switch (plugin_data->obj_type)
        {
            case NPPLG_AV_OBJ_TYPE_AUDIO:
            {
                npplg_av_audio_handle_suspend_background_play_rsp(plugin_data, rsp->result);
                break;
            }

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
            case NPPLG_AV_OBJ_TYPE_VIDEO:
            {
                npplg_av_video_handle_suspend_background_play_rsp(plugin_data, rsp->result);
                break;
            }
            
#ifdef __MMI_VIDEO_STREAM__
            case NPPLG_AV_OBJ_TYPE_STREAMING:
            {
                npplg_av_stream_handle_suspend_background_play_rsp(plugin_data, rsp->result);
                break;
            }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__*/

            default:
                break;
        }
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_audio_play_res_handler
 * DESCRIPTION
 *  MSG_ID_NPPLG_AV_AUDIO_PLAY_RES handler
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_audio_play_res_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_audio_play_res_struct *res;
    npplg_av_instance_struct *plugin_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    res = (npplg_av_audio_play_res_struct*)info;

    if (res->session_id == g_npplg_av_context.session_id)
    {
        plugin_data = npplg_av_main_get_active_instance(g_npplg_av_context.play_app_id);

        npplg_av_audio_play_result_handler(plugin_data, res->result);
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_mmi_resume_ind_handler
 * DESCRIPTION
 *  MSG_ID_NPPLG_AV_MMI_RESUME_IND handler
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_mmi_resume_ind_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_mmi_resume_ind_struct *ind;
    npplg_av_instance_struct *plugin_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    ind = (npplg_av_mmi_resume_ind_struct*)info;

    plugin_data = npplg_av_main_get_instance_from_list(ind->instance_id, ind->app_id);

    if (plugin_data != NULL)
    {
        if (npplg_av_main_get_active_instance(ind->app_id) != NULL)
        {
            MMI_TRACE(NPPLG_AV_TRC_GROUP,
                      NPPLG_AV_MMI_RESUME_IND_HDLR,
                      plugin_data->instance_id,
                      plugin_data->obj_type,
                      plugin_data->state,
                      g_npplg_av_context.app_cnxt[ind->app_id].is_suspend_by_mmi,
                      g_npplg_av_context.app_cnxt[ind->app_id].active_instance->instance_id);
        }
        else
        {
            MMI_TRACE(NPPLG_AV_TRC_GROUP,
                      NPPLG_AV_MMI_RESUME_IND_HDLR,
                      plugin_data->instance_id,
                      plugin_data->obj_type,
                      plugin_data->state,
                      g_npplg_av_context.app_cnxt[ind->app_id].is_suspend_by_mmi,
                      0);
        }
        
        if (g_npplg_av_context.app_cnxt[ind->app_id].is_suspend_by_mmi == KAL_FALSE)
        {
            if (ind->state == plugin_data->state &&
                npplg_av_main_get_active_instance(ind->app_id) == plugin_data)
            {
                /* Resume previous action */
                if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO)
                {
                    npplg_av_audio_mmi_resume_ind_handler(plugin_data);
                }
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
                else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
                {
                    npplg_av_video_mmi_resume_ind_handler(plugin_data);
                }
#ifdef __MMI_VIDEO_STREAM__
                else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
                {
                    npplg_av_stream_mmi_resume_ind_handler(plugin_data);
                }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
            }
            else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO &&
                     ind->state == NPPLG_AV_AUDIO_OBJ_STATE_DOWNLOADING &&
                     (plugin_data->state == NPPLG_AV_AUDIO_OBJ_STATE_BUILDING_CACHE ||
                      plugin_data->state == NPPLG_AV_AUDIO_OBJ_STATE_WAITING_PLAY))
            {
                /* Not do anything for this condition */
            }
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
            else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO &&
                     ((ind->state == NPPLG_AV_VIDEO_OBJ_STATE_PRE_BUFFERING &&
                       (plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING || plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_WAITING_PLAY)) ||
                      (ind->state == NPPLG_AV_VIDEO_OBJ_STATE_DOWNLOADING && plugin_data->state == NPPLG_AV_VIDEO_OBJ_STATE_WAITING_PLAY)))
            {
                /* Not do anything for this condition */
            }
#ifdef __MMI_VIDEO_STREAM__
            else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING &&
                     ind->state == NPPLG_AV_STREAM_OBJ_STATE_DOWNLOADING &&
                     plugin_data->state == NPPLG_AV_STREAM_OBJ_STATE_WAITING_PLAY)
            {
                /* Not do anything for this condition */
            }
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
            else
            {
                if ((plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO && plugin_data->state != NPPLG_AV_AUDIO_OBJ_STATE_IDLE)
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
                    || (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO && plugin_data->state != NPPLG_AV_VIDEO_OBJ_STATE_IDLE)
#ifdef __MMI_VIDEO_STREAM__
                    || (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING && plugin_data->state != NPPLG_AV_STREAM_OBJ_STATE_IDLE)
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
                   )
                {
                    ASSERT(0);
                }
            }
        }
    }

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_auto_play_audio_ind_handler
 * DESCRIPTION
 *  MSG_ID_NPPLG_AV_AUTO_PLAY_AUDIO_IND handler
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_auto_play_audio_ind_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_auto_play_audio_ind_struct *ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    ind = (npplg_av_auto_play_audio_ind_struct*)info;

    npplg_av_main_auto_play_audio(ind->app_id, ind->notify_app);

    NPPLG_AV_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_reset_ind_handler
 * DESCRIPTION
 *  MSG_ID_NPPLG_AV_RESET_IND handler
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_reset_ind_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_reset_ind_struct *ind;
    npplg_av_instance_struct *plugin_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    ind = (npplg_av_reset_ind_struct*)info;

    MMI_TRACE(NPPLG_AV_TRC_GROUP, NPPLG_AV_RESET_IND_HDLR, ind->app_id, ind->instance_id, g_npplg_av_context.app_cnxt[ind->app_id].is_suspend_by_mmi);
    
    plugin_data = npplg_av_main_get_instance_from_list(ind->instance_id, ind->app_id);

    if (plugin_data != NULL)
    {
        /* Clear interrupt instance */
        g_npplg_av_context.app_cnxt[ind->app_id].interrupt_instance = NULL;
        g_npplg_av_context.app_cnxt[ind->app_id].interrupt_event = NPPLG_AV_INT_EVT_UNKNOWN;
        
        npplg_av_main_dispatch_event(plugin_data, NPPLG_AV_INT_EVT_STOP);

        plugin_data->suspend = KAL_FALSE;
        g_npplg_av_context.app_cnxt[ind->app_id].is_suspend_by_mmi = KAL_FALSE;
    }

    NPPLG_AV_UNLOCK;
}


#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_create_vdo_layer_rsp_handler
 * DESCRIPTION
 *  MSG_ID_NPPLG_AV_CREATE_VDO_LAYER_RSP handler
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void npplg_av_main_create_vdo_layer_rsp_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_create_vdo_layer_rsp_struct *rsp;
    npplg_av_instance_struct *plugin_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NPPLG_AV_LOCK;

    rsp = (npplg_av_create_vdo_layer_rsp_struct*)info;

    MMI_TRACE(NPPLG_AV_TRC_GROUP,
              NPPLG_AV_CREATE_VDO_LAYER_RSP_HDLR,
              rsp->app_id,
              rsp->instance_id,
              rsp->result,
              rsp->layer_handle);
    
    plugin_data = npplg_av_main_get_instance_from_list(rsp->instance_id, rsp->app_id);

    if (plugin_data != NULL)
    {
        g_npplg_av_context.blt_layer_flag = rsp->blt_layer_flag;
        g_npplg_av_context.hw_layer_flag = rsp->hw_layer_flag;

        if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO)
        {
            npplg_av_video_create_vdo_layer_rsp_handler(plugin_data, rsp->layer_handle);
        }
#ifdef __MMI_VIDEO_STREAM__
        else if (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING)
        {
            npplg_av_stream_create_vdo_layer_rsp_handler(plugin_data, rsp->layer_handle);
        }
#endif /* __MMI_VIDEO_STREAM__ */
    }
    else
    {
        /* Free video layer */
        npplg_av_util_send_free_vdo_layer_ind(kal_get_active_module_id(),
                                              rsp->app_id,
                                              rsp->instance_id);
    }

    NPPLG_AV_UNLOCK;
}
#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__) */


#ifdef __MMI_USB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_exit_usb_mode
 * DESCRIPTION
 *  Called when exit usb mode
 * PARAMETERS
 *  evt             [IN]
 * RETURNS
 *  Must return MMI_RET_OK 
 *****************************************************************************/
mmi_ret npplg_av_main_exit_usb_mode(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_USB_EXIT_MS_MODE)
    {
        NPPLG_AV_LOCK;

        npplg_av_main_create_folder();

        NPPLG_AV_UNLOCK;
    }
    
    return MMI_RET_OK;
}
#else /* __MMI_USB_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_exit_usb_mode
 * DESCRIPTION
 *  Called when exit usb mode
 * PARAMETERS
 *  evt             [IN]
 * RETURNS
 *  Must return MMI_RET_OK 
 *****************************************************************************/
mmi_ret npplg_av_main_exit_usb_mode(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}
#endif /* __MMI_USB_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_message_dispatcher()
 * DESCRIPTION
 *  Message dispatcher of adaptation layer
 * PARAMETERS
 *  ilm_ptr             [IN]    ilm pointer
 * RETURNS
 *  Consume the message or not 
 *****************************************************************************/
kal_bool npplg_av_main_message_dispatcher(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_p = ilm_ptr;
    kal_bool handle_msg = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(ilm_p->msg_id)
    {
        case MSG_ID_NPPLG_AV_SUSPEND_BACKGROUND_PLAY_RSP:
        {
            npplg_av_main_suspend_background_play_rsp_handler((void*)ilm_p->local_para_ptr);
            break;
        }

        case MSG_ID_NPPLG_AV_AUDIO_PLAY_RES:
        {
            npplg_av_main_audio_play_res_handler((void*)ilm_p->local_para_ptr);
            break;
        }

        case MSG_ID_NPPLG_AV_MMI_RESUME_IND:
        {
            npplg_av_main_mmi_resume_ind_handler((void*)ilm_p->local_para_ptr);
            break;
        }

        case MSG_ID_NPPLG_AV_AUTO_PLAY_AUDIO_IND:
        {
            npplg_av_main_auto_play_audio_ind_handler((void*)ilm_p->local_para_ptr);
            break;
        }

        case MSG_ID_NPPLG_AV_RESET_IND:
        {
            npplg_av_main_reset_ind_handler((void*)ilm_p->local_para_ptr);
            break;
        }

#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
        case MSG_ID_NPPLG_AV_CREATE_VDO_LAYER_RSP:
        {
            npplg_av_main_create_vdo_layer_rsp_handler((void*)ilm_p->local_para_ptr);
            break;
        }
#endif
        
        default:
            handle_msg = KAL_FALSE;
            break;
    }

    return handle_msg;
}


/*****************************************************************************
 * FUNCTION
 *  npplg_av_main_is_instance_active
 * DESCRIPTION
 *  This function is used to check whether one plug-in instance is active.
 * PARAMETERS
 *  instance            [IN]    NPP instance
 *  is_active           [OUT]   Is active or not
 * RETURNS
 *  Execution result
 *****************************************************************************/
NPError npplg_av_main_is_instance_active(NPP instance, kal_bool *is_active)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    npplg_av_instance_struct *plugin_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (instance == NULL || instance->pdata == NULL)
    {
        *is_active = KAL_FALSE;
        return NPERR_INVALID_INSTANCE_ERROR;
    }

    NPPLG_AV_LOCK;

    plugin_data = (npplg_av_instance_struct*)instance->pdata;

    if ((plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_AUDIO && plugin_data->state != NPPLG_AV_AUDIO_OBJ_STATE_IDLE)
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
        || (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_VIDEO && plugin_data->state != NPPLG_AV_VIDEO_OBJ_STATE_IDLE)
#ifdef __MMI_VIDEO_STREAM__
        || (plugin_data->obj_type == NPPLG_AV_OBJ_TYPE_STREAMING && plugin_data->state != NPPLG_AV_STREAM_OBJ_STATE_IDLE)
#endif /* __MMI_VIDEO_STREAM__ */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
       )
    {
        *is_active = KAL_TRUE;
    }
    else
    {
        *is_active = KAL_FALSE;
    }
    
    NPPLG_AV_UNLOCK;
    return NPERR_NO_ERROR;
}

#endif /* defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__) */

