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
 *   widget_view_ui.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements widget view UI presentation
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

//#include "mmi_include.h"

#include "MMI_features.h" 

#ifdef __MMI_GADGET_SUPPORT__

//#include "CommonScreens.h"
#include "Conversions.h"
#include "ProfilesSrvGprot.h"
//#include "gdi_mutex.h"      // for gdi_fast_mutex_get_count(void);
#include "med_utility.h" // TODO: remove this after using VRT memory API
#include "mmi_rp_app_widget_delegator_def.h"
#include "widget_adp_struct.h"
#include "widget_api.h"
//#include "gadget_adp_log.h"
#include "idlegprot.h"

#include "gadget_adp_avplugin.h"

#include "gdi_datatype.h"    
#include "gdi_const.h"    
#include "MMIDataType.h"    
#include "kal_public_defs.h"    
#include "GlobalConstants.h"    
#include "kal_general_types.h"    
#include "mmi_frm_input_gprot.h"    
#include "stack_config.h"    
#include "stack_msgs.h"    
#include "app_ltlcom.h"    
#include "stack_ltlcom.h"    
#include "stack_common.h"    
#include "task_config.h"    
#include "kal_public_api.h"    
#include "mmi_frm_scenario_gprot.h"    
#include "mmi_frm_mem_gprot.h"    
#include "string.h"    
#include "gdi_include.h"    
#include "mmi_frm_history_gprot.h"    
#include "GlobalResDef.h"    
#include "CustDataRes.h"    
#include "mmi_frm_events_gprot.h"    
#include "AlertScreen.h"    
#include "wgui_categories.h"    
#include "gui.h"    
#include "med_smalloc.h"    
#include "wgui_categories_util.h"
#include "custom_gadget_config.h"

#define WIDGET_VIEW_TRANSPARENT_COLOR gdi_act_color_from_rgb(255, 12, 56, 82)
/* Use for define 32 bits color format in details view */
#ifndef WIDGET_DETAILS_VIEW_ARGB8888_COLOR_FORMAT
#define WIDGET_DETAILS_VIEW_ARGB8888_COLOR_FORMAT
#endif
extern void gadget_adp_audio_service_suspend(void);
extern void gadget_adp_audio_service_resume(void);
extern gdi_handle gadget_adp_plugin_utils_get_video_layer();

/*****************************************************************************
 * Static Declaration
 *****************************************************************************/

typedef struct widget_view_context_st
{
    GDI_HANDLE title_layer;
    GDI_HANDLE bottom_layer;
    GDI_HANDLE render_layer;
    U32 render_area_x;
    U32 render_area_y;
    U32 render_area_width;
    U32 render_area_height;
    S32 lcd_width, lcd_height;

    int view_width;
    int view_height;

    int widget_id;
    void *view_handle;
    int view_type;
    int view_flags;
    int view_response;

    U8 *gdi_buffer1;
    U8 *gdi_buffer2;
    U8 view_caption[256];
    U8 closed_by_engine;
    U8 exception_occured;
    U8 is_content_available;
} widget_view_context_struct;

static widget_view_context_struct *g_widget_view_cntx = NULL;
static kal_mutexid g_widget_view_lock = NULL;

static U16 keycodes[] =
{
    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    //KEY_LSK,
    //KEY_RSK,
    //KEY_CSK,
    KEY_UP_ARROW,
    KEY_DOWN_ARROW,
    KEY_LEFT_ARROW,
    KEY_RIGHT_ARROW,
#ifdef __MTK_INTERNAL__
/* under construction !*/
#endif
    //KEY_END,
    KEY_CLEAR,
    //KEY_STAR,
    //KEY_POUND,
    KEY_VOL_UP,
    KEY_VOL_DOWN,
    //KEY_CAMERA,
    //KEY_QUICK_ACS, /* KEY_CAMERA */
    //KEY_ENTER,
    //KEY_WAP, /* KEY_ENTER */
    //KEY_IP, /* KEY_ENTER */
    //KEY_EXTRA_1,
    //KEY_EXTRA_2,
    //KEY_PLAY_STOP,
    //KEY_FWD,
    //KEY_BACK
    //KEY_POWER,
    //KEY_EXTRA_A,
    //KEY_EXTRA_B,
};

static mmi_ret mmi_widget_view_event_handler_proc(mmi_event_struct *evt);
static void mmi_widget_view_repaint(void *param);
static void mmi_widget_entry_view(void);
static void mmi_widget_view_key_event_handler(void);
static MMI_BOOL mmi_widget_view_pen_handler(mmi_pen_point_struct point, mmi_pen_event_type_enum event_type);
static void mmi_widget_pen_up_hdlr(mmi_pen_point_struct point);
static void mmi_widget_pen_down_hdlr(mmi_pen_point_struct point);
static void mmi_widget_pen_move_hdlr(mmi_pen_point_struct point);
static void mmi_widget_pen_abort_hdlr(mmi_pen_point_struct point);
static void mmi_widget_pen_repeat_hdlr(mmi_pen_point_struct point);
static void mmi_widget_pen_long_tap_hdlr(mmi_pen_point_struct point);


static void send_message(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->msg_id = ilm_id;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

    SEND_ILM(MOD_MMI, dst_id, MMI_GADGET_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  widget_show_view_handler
 * DESCRIPTION
 *  Phonebook launch proc function
 * PARAMETERS
 *  evt
 * RETURNS
 *  void
 *****************************************************************************/
void widget_show_view_handler(void *param)
{
    widget_show_view_ind_struct *p = (widget_show_view_ind_struct *)param;

    send_message(NULL, NULL, MSG_ID_WIDGET_SHOW_VIEW_CNF, MOD_GADGET);

    if (!g_widget_view_lock)
    {
        g_widget_view_lock = kal_create_mutex("widget_view_lock");
    }

    if (g_widget_view_cntx)
    {
        ASSERT(mmi_frm_group_is_present(GRP_ID_WIDGET_VIEW));

        mmi_frm_group_close(GRP_ID_WIDGET_VIEW);
    }

    g_widget_view_cntx = OslMalloc(sizeof(widget_view_context_struct));

    ASSERT(g_widget_view_cntx);

    memset(g_widget_view_cntx, 0, sizeof(widget_view_context_struct));

    g_widget_view_cntx->widget_id = p->instance_id;
    g_widget_view_cntx->view_handle = p->view_handle;
    g_widget_view_cntx->view_width = p->width;
    g_widget_view_cntx->view_height = p->height;
    g_widget_view_cntx->view_type = p->type;
    g_widget_view_cntx->view_flags = p->flags;

    if (p->caption[0])
    {
        mmi_chset_utf8_to_ucs2_string(
            (U8*) g_widget_view_cntx->view_caption,
            sizeof(g_widget_view_cntx->view_caption),
            (U8*) p->caption);
    }

    gdi_lcd_get_dimension(&g_widget_view_cntx->lcd_width, &g_widget_view_cntx->lcd_height);

    if (g_confirm_dialog_gid)
    {
        mmi_frm_node_struct group_info;

        group_info.id = GRP_ID_WIDGET_VIEW;
        group_info.entry_proc = mmi_widget_view_event_handler_proc;

        mmi_frm_group_insert(mmi_idle_get_group_id(), g_confirm_dialog_gid, &group_info, MMI_FRM_NODE_BEFORE_FLAG);
        //mmi_frm_group_insert(GRP_ID_ROOT, g_confirm_dialog_gid, &group_info, MMI_FRM_NODE_BEFORE_FLAG);
        mmi_frm_group_set_attribute (GRP_ID_WIDGET_VIEW, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    else
    {
        /*mmi_frm_group_create(
            mmi_idle_get_group_id(),
            GRP_ID_WIDGET_VIEW,
            mmi_widget_view_event_handler_proc,
            g_widget_view_cntx);*/

		mmi_frm_node_struct group_info;

        group_info.id = GRP_ID_WIDGET_VIEW;
        group_info.entry_proc = mmi_widget_view_event_handler_proc;
		group_info.user_data = g_widget_view_cntx;
		
        mmi_frm_group_insert(GRP_ID_ROOT, mmi_idle_get_group_id(), &group_info, MMI_FRM_NODE_AFTER_FLAG);
        mmi_frm_group_enter(GRP_ID_WIDGET_VIEW, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    mmi_widget_entry_view();
}


int widget_close_view_by_id(int instance_id)
{
    if (!g_widget_view_cntx || g_widget_view_cntx->widget_id != instance_id)
    {
        return 0;
    }

    if (mmi_frm_scrn_get_active_id() != SCR_ID_WIDGET_VIEW)
    {
        mmi_frm_group_close(GRP_ID_WIDGET_VIEW);
    }
    else
    {
        //GoBackHistory();
        mmi_frm_group_close(GRP_ID_WIDGET_VIEW);
    }

    return 1;
}

static void widget_close_screen_group(void)
{
	mmi_frm_group_close(GRP_ID_WIDGET_VIEW);
}

static void widget_close_view_handler(void *param)
{
    widget_show_view_ind_struct *p = (widget_show_view_ind_struct *)param;

    if (!g_widget_view_cntx)
    {
        return;
    }

    // Check if the request is for the current view
    if (g_widget_view_cntx->view_handle != p->view_handle)
    {
        return;
    }

    g_widget_view_cntx->closed_by_engine = 1;

    if (mmi_frm_scrn_get_active_id() != SCR_ID_WIDGET_VIEW)
    {
        mmi_frm_group_close(GRP_ID_WIDGET_VIEW);
    }
    else
    {
        //GoBackHistory();
		mmi_frm_group_close(GRP_ID_WIDGET_VIEW);
    }
}


static void mmi_widget_view_handle_terminate_ind(void *param)
{
    widget_terminate_all_wgt_ind_struct *ind = (widget_terminate_all_wgt_ind_struct *)param;

    if (mmi_frm_scrn_get_active_id() != SCR_ID_WIDGET_VIEW)
    {
        ASSERT(g_widget_view_cntx);

        g_widget_view_cntx->exception_occured = 1;

        /* close widget view group if asm has been freed */
        if (ind->type == WIDGET_RESET_STOP_ASM)
        {
            g_widget_view_cntx->closed_by_engine = 1;
            mmi_frm_group_close(GRP_ID_WIDGET_VIEW);
        }
    }
    else
    {
        if (ind->type == WIDGET_RESET_MEMORY_FULL)
        {
            mmi_popup_display_simple((WCHAR *) GetString(STR_ID_WIDGET_MEMORY_FULL), MMI_EVENT_WARNING, GRP_ID_ROOT, NULL);
        }
        g_widget_view_cntx->closed_by_engine = 1;
        mmi_frm_group_close(GRP_ID_WIDGET_VIEW);
    }

    send_message(NULL, NULL, MSG_ID_WIDGET_TERMINATE_ALL_WGT_CNF, MOD_GADGET);
}

static void mmi_widget_send_notify_content_update_response(int instance_id, void *view_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_notify_content_update_cnf_struct *p = (widget_notify_content_update_cnf_struct*) construct_local_para(
                                                sizeof(widget_notify_content_update_cnf_struct),
                                                TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->instance_id = instance_id;
    p->view_handle = view_handle;

    send_message(p, NULL, MSG_ID_WIDGET_NOTIFY_CONTENT_UPDATE_CNF, MOD_GADGET);
}

void *mmi_widget_view_lock_canvas(int instance_id, void *view_handle, void **ptr_buffer, int width, int height)
{
    canvas_lock_struct *lock = NULL;
    
    int buffer_size = width * height * 2;
        
#ifdef WIDGET_DETAILS_VIEW_ARGB8888_COLOR_FORMAT
    buffer_size = width * height * 4;
#endif

    ASSERT(ptr_buffer);
    if (mmi_frm_scrn_get_active_id() != SCR_ID_WIDGET_VIEW)
    {
        return NULL;
    }

    kal_take_mutex(g_widget_view_lock);

    if (!g_widget_view_cntx || g_widget_view_cntx->widget_id != instance_id || g_widget_view_cntx->view_handle != view_handle || !g_widget_view_cntx->render_layer ||
        g_widget_view_cntx->view_width != width || g_widget_view_cntx->view_height != height)
    {
        kal_give_mutex(g_widget_view_lock);
        return NULL;
    }

    lock = (canvas_lock_struct *)OslMalloc(sizeof(canvas_lock_struct));
    memset(lock, 0, sizeof(canvas_lock_struct));
    lock->mutex = g_widget_view_lock;
    lock->view_type = g_widget_view_cntx->view_type;
    lock->unlock_canvas = mmi_widget_view_unlock_canvas;
    gdi_layer_push_and_set_active(g_widget_view_cntx->render_layer);


    memset(gdi_act_layer->buf_ptr1, 0xff, buffer_size);
    //gdi_layer_get_buffer_ptr(&layer_buffer);
    *ptr_buffer = gdi_act_layer->buf_ptr1;

    gdi_layer_pop_and_restore_active();

    return lock;
}


void mmi_widget_view_unlock_canvas(void *p)
{
    canvas_lock_struct * lock = (canvas_lock_struct *)p;
    ASSERT(lock);
    ASSERT(lock->mutex == g_widget_view_lock);

    kal_give_mutex(g_widget_view_lock);

    OslMfree(lock);
    return;
}

/*************************************************************************
    Local Functions
 *************************************************************************/
static mmi_ret mmi_widget_view_event_handler_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_NOTIFY_CONTENT_UPDATE_IND, NULL, KAL_FALSE);
            mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_CLOSE_VIEW_IND, NULL, KAL_FALSE);
            mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_TERMINATE_WGT_IND, NULL, KAL_FALSE);
            mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_TERMINATE_ALL_WGT_IND, NULL, KAL_FALSE);

            gadget_adp_avplugin_notify_close();

            kal_take_mutex(g_widget_view_lock);

            if (!g_widget_view_cntx->closed_by_engine)
            {
                widget_close_view(g_widget_view_cntx->widget_id, g_widget_view_cntx->view_handle, g_widget_view_cntx->view_type, g_widget_view_cntx->view_response);
            }

            if (g_widget_view_cntx->gdi_buffer1)
            {
                  med_free_asm_mem(GRP_ID_WIDGET_VIEW, (void **) &g_widget_view_cntx->gdi_buffer1);
            }

            if (g_widget_view_cntx->gdi_buffer2)
            {
                  med_free_asm_mem(GRP_ID_WIDGET_VIEW, (void **) &g_widget_view_cntx->gdi_buffer2);
            }

            if (g_widget_view_cntx->render_layer)
            {
                gdi_layer_free(g_widget_view_cntx->render_layer);
            }
            OslMfree(g_widget_view_cntx);
            g_widget_view_cntx = NULL;

            kal_give_mutex(g_widget_view_lock);
            
            widget_disable_view_cache();

            break;
        }
        default:
            break;
    }

    return MMI_RET_OK;

}

static void mmi_widget_view_repaint(void *param)
{
    widget_notify_content_update_ind_struct *p = (widget_notify_content_update_ind_struct*)param;

    if (mmi_frm_scrn_get_active_id() != SCR_ID_WIDGET_VIEW)
    {
        widget_canvas_free(p->buffer);
        goto final;
    }

    // Check if the update content is for the current view
    if (g_widget_view_cntx->view_handle != p->view_handle)
    {
        widget_canvas_free(p->buffer);
        goto final;
    }

    kal_take_mutex(g_widget_view_lock);

    gdi_layer_set_blt_layer(gadget_adp_plugin_utils_get_video_layer(), g_widget_view_cntx->render_layer, g_widget_view_cntx->title_layer, g_widget_view_cntx->bottom_layer);

    gdi_layer_push_and_set_active(g_widget_view_cntx->render_layer);

    gdi_layer_toggle_double();

    gdi_layer_pop_and_restore_active();

    kal_give_mutex(g_widget_view_lock);
    //gadget_adp_set_redraw_pending(g_widget_view_cntx->view_handle, MMI_FALSE); /*TESTING*/

    if (!g_widget_view_cntx->is_content_available)
    {
        g_widget_view_cntx->is_content_available = 1;
    }

    gdi_layer_blt_previous(g_widget_view_cntx->render_area_x,
            g_widget_view_cntx->render_area_y,
            g_widget_view_cntx->render_area_width - 1,
            g_widget_view_cntx->render_area_y + g_widget_view_cntx->render_area_height - 1);

final:
    mmi_widget_send_notify_content_update_response(p->instance_id, p->view_handle);
}


static void mmi_widget_view_response_ok(void)
{
    g_widget_view_cntx->view_response = VIEW_RESPONSE_OK;
    //GoBackHistory();
    mmi_frm_group_close(GRP_ID_WIDGET_VIEW);
}

static void mmi_widget_view_response_cancel(void)
{
    g_widget_view_cntx->view_response = VIEW_RESPONSE_CANCEL;
    //GoBackHistory();
    mmi_frm_group_close(GRP_ID_WIDGET_VIEW);
}

static void mmi_widget_exit_view(void)
{
    gadget_adp_audio_service_suspend();
    gadget_adp_avplugin_notify_suspend();

    kal_take_mutex(g_widget_view_lock);

    if (g_widget_view_cntx->render_layer && g_widget_view_cntx->is_content_available)
    {
        gdi_layer_flatten_to_base(GDI_NULL_HANDLE, g_widget_view_cntx->render_layer, g_widget_view_cntx->title_layer, g_widget_view_cntx->bottom_layer);
    }

    if (g_widget_view_cntx->gdi_buffer1)
    {
          med_free_asm_mem(GRP_ID_WIDGET_VIEW, (void **) &g_widget_view_cntx->gdi_buffer1);
    }

    if (g_widget_view_cntx->gdi_buffer2)
    {
          med_free_asm_mem(GRP_ID_WIDGET_VIEW, (void **) &g_widget_view_cntx->gdi_buffer2);
    }

    if (g_widget_view_cntx->render_layer)
    {
        gdi_layer_free(g_widget_view_cntx->render_layer);
        g_widget_view_cntx->render_layer = 0;
    }

    kal_give_mutex(g_widget_view_lock);

    widget_focus_out(g_widget_view_cntx->widget_id, g_widget_view_cntx->view_handle);

    widget_handle_pen_event(g_widget_view_cntx->widget_id, g_widget_view_cntx->view_handle, 0, 0, PEN_ABORT);
}

static void mmi_widget_entry_view(void)
{
    int keylen = sizeof(keycodes) / sizeof(U16);
    U8 *guiBuffer;

    int is_fullscreen = (g_widget_view_cntx->view_type == VIEW_DETAILS && g_widget_view_cntx->view_flags & DETAILS_VIEW_FLAG_NO_FRAME);    
    
    int buffer_size = g_widget_view_cntx->view_width * g_widget_view_cntx->view_height * 2;

#ifdef WIDGET_DETAILS_VIEW_ARGB8888_COLOR_FORMAT
    buffer_size = g_widget_view_cntx->view_width * g_widget_view_cntx->view_height * 4;
#endif

    if (g_widget_view_cntx->exception_occured)
    {
        mmi_popup_display_simple((WCHAR *) GetString(STR_ID_WIDGET_MEMORY_FULL), MMI_EVENT_WARNING, GRP_ID_WIDGET_VIEW, NULL);
        return;
    }

    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_NOTIFY_CONTENT_UPDATE_IND, (PsIntFuncPtr)mmi_widget_view_repaint, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_CLOSE_VIEW_IND, (PsIntFuncPtr)widget_close_view_handler, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_TERMINATE_WGT_IND, (PsIntFuncPtr)mmi_widget_view_handle_terminate_ind, KAL_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_TERMINATE_ALL_WGT_IND, (PsIntFuncPtr)mmi_widget_view_handle_terminate_ind, KAL_FALSE);

    if (!mmi_frm_scrn_enter(GRP_ID_WIDGET_VIEW, SCR_ID_WIDGET_VIEW, mmi_widget_exit_view, mmi_widget_entry_view, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);

    kal_take_mutex(g_widget_view_lock);

    if (!is_fullscreen)
    {
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

        ShowCategory431Screen(
            g_widget_view_cntx->view_caption,  /* title */
            0,  /* left title icon */
            0,  /* right title icon */
            0,  /* LSK */
            0,  /* LSK icon */
            0,  /* RSK */
            0,  /* RSK icon */
            mmi_widget_view_pen_handler,
            MMI_FALSE,  /* is full screen mode */
            -1, /* progress percentage */
            NULL,   /* progress indicator text */
            guiBuffer);

        Cat431GetScreenInfo(MMI_FALSE, &g_widget_view_cntx->render_area_x, &g_widget_view_cntx->render_area_y, &g_widget_view_cntx->render_area_width, &g_widget_view_cntx->render_area_height, &g_widget_view_cntx->title_layer, &g_widget_view_cntx->bottom_layer);
    }
    else
    {
        g_widget_view_cntx->render_area_x = 0;
        g_widget_view_cntx->render_area_y = 0;
        g_widget_view_cntx->render_area_width = UI_device_width;
        g_widget_view_cntx->render_area_height = UI_device_height;

    }

    if(!g_widget_view_cntx->gdi_buffer1)
    {
        g_widget_view_cntx->gdi_buffer1 = (U8 *)med_alloc_asm_mem(GRP_ID_WIDGET_VIEW, buffer_size);
    }

    ASSERT(g_widget_view_cntx->gdi_buffer1);

    memset(g_widget_view_cntx->gdi_buffer1, 0, buffer_size);

    if(!g_widget_view_cntx->gdi_buffer2)
    {
        g_widget_view_cntx->gdi_buffer2 = (U8 *)med_alloc_asm_mem(GRP_ID_WIDGET_VIEW, buffer_size);
    }

    ASSERT(g_widget_view_cntx->gdi_buffer2);

    memset(g_widget_view_cntx->gdi_buffer2, 0, buffer_size);

#ifdef WIDGET_DETAILS_VIEW_ARGB8888_COLOR_FORMAT
    ASSERT(gdi_layer_create_cf_double_using_outside_memory(
            GDI_COLOR_FORMAT_32,
            g_widget_view_cntx->render_area_x,
            g_widget_view_cntx->render_area_y,
            g_widget_view_cntx->view_width,
            g_widget_view_cntx->view_height,
            &g_widget_view_cntx->render_layer,
            (U8 *)g_widget_view_cntx->gdi_buffer1,
            buffer_size,
            (U8 *)g_widget_view_cntx->gdi_buffer2,
            buffer_size) >= 0);
#else
    ASSERT(gdi_layer_create_cf_double_using_outside_memory(
            GDI_COLOR_FORMAT_16,
            g_widget_view_cntx->render_area_x,
            g_widget_view_cntx->render_area_y,
            g_widget_view_cntx->view_width,
            g_widget_view_cntx->view_height,
            &g_widget_view_cntx->render_layer,
            (U8 *)g_widget_view_cntx->gdi_buffer1,
            buffer_size,
            (U8 *)g_widget_view_cntx->gdi_buffer2,
            buffer_size) >= 0);
#endif

    gdi_layer_push_and_set_active(g_widget_view_cntx->render_layer);
    gdi_layer_clear_background(WIDGET_VIEW_TRANSPARENT_COLOR);
    gdi_layer_set_source_key(TRUE, WIDGET_VIEW_TRANSPARENT_COLOR);
    gdi_layer_pop_and_restore_active();

    SetGroupKeyHandler(mmi_widget_view_key_event_handler, keycodes, keylen, KEY_EVENT_DOWN);
    SetGroupKeyHandler(mmi_widget_view_key_event_handler, keycodes, keylen, KEY_EVENT_UP);
    SetGroupKeyHandler(mmi_widget_view_key_event_handler, keycodes, keylen, KEY_EVENT_REPEAT);
    SetGroupKeyHandler(mmi_widget_view_key_event_handler, keycodes, keylen, KEY_LONG_PRESS);

    if (g_widget_view_cntx->view_type == VIEW_OPTIONS)
    {
        if (g_widget_view_cntx->view_flags & OPTIONS_VIEW_FLAG_OK)
        {
            ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
            SetLeftSoftkeyFunction(mmi_widget_view_response_ok, KEY_EVENT_UP);
        }
        if (g_widget_view_cntx->view_flags & OPTIONS_VIEW_FLAG_CANCEL)
        {
            ChangeRightSoftkey(STR_GLOBAL_CANCEL, 0);
            SetRightSoftkeyFunction(mmi_widget_view_response_cancel, KEY_EVENT_UP);
        }
    }
    else if (g_widget_view_cntx->view_type == VIEW_DETAILS)
    {
        if (is_fullscreen)
        {
            //SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);
			SetKeyHandler(widget_close_screen_group, KEY_RSK, KEY_EVENT_UP);
            mmi_pen_register_up_handler(mmi_widget_pen_up_hdlr);
            mmi_pen_register_down_handler(mmi_widget_pen_down_hdlr);
            mmi_pen_register_move_handler(mmi_widget_pen_move_hdlr);
            mmi_pen_register_abort_handler(mmi_widget_pen_abort_hdlr);
            mmi_pen_register_repeat_handler(mmi_widget_pen_repeat_hdlr);
            mmi_pen_register_long_tap_handler(mmi_widget_pen_long_tap_hdlr);
        }
        else
        {
            ChangeRightSoftkey(STR_GLOBAL_CLOSE, 0);
            //SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
			SetRightSoftkeyFunction(widget_close_screen_group, KEY_EVENT_UP);
        }
    }

    kal_give_mutex(g_widget_view_lock);

    gadget_adp_audio_service_resume();
    gadget_adp_avplugin_notify_resume();

    g_widget_view_cntx->is_content_available = 0;

    widget_update_content(g_widget_view_cntx->widget_id, g_widget_view_cntx->view_handle);
    widget_focus_in(g_widget_view_cntx->widget_id, g_widget_view_cntx->view_handle);
}

static void mmi_widget_view_key_event_handler(void)
{
    U16 keycode, keytype;

    if (!g_widget_view_cntx->view_handle)
    {
        return;
    }

    GetkeyInfo(&keycode, &keytype);

    widget_handle_key_event(g_widget_view_cntx->widget_id, g_widget_view_cntx->view_handle, keycode, keytype);
}

static void mmi_widget_pen_up_hdlr(mmi_pen_point_struct point)
{
    mmi_widget_view_pen_handler(point, MMI_PEN_EVENT_UP);
}

static void mmi_widget_pen_down_hdlr(mmi_pen_point_struct point)
{
    mmi_widget_view_pen_handler(point, MMI_PEN_EVENT_DOWN);
}

static void mmi_widget_pen_move_hdlr(mmi_pen_point_struct point)
{
    mmi_widget_view_pen_handler(point, MMI_PEN_EVENT_MOVE);
}

static void mmi_widget_pen_abort_hdlr(mmi_pen_point_struct point)
{
    mmi_widget_view_pen_handler(point, MMI_PEN_EVENT_ABORT);
}

static void mmi_widget_pen_repeat_hdlr(mmi_pen_point_struct point)
{
    mmi_widget_view_pen_handler(point, MMI_PEN_EVENT_REPEAT);
}

static void mmi_widget_pen_long_tap_hdlr(mmi_pen_point_struct point)
{
    mmi_widget_view_pen_handler(point, MMI_PEN_EVENT_LONG_TAP);
}

static MMI_BOOL mmi_widget_view_pen_handler(mmi_pen_point_struct point, mmi_pen_event_type_enum event_type)
{
    int x = point.x - g_widget_view_cntx->render_area_x;
    int y = point.y - g_widget_view_cntx->render_area_y;
    int type = 0;

    if (!g_widget_view_cntx->view_handle)
        return MMI_FALSE;

    switch(event_type)
    {
    case MMI_PEN_EVENT_DOWN:
        type = PEN_DOWN;
        break;
    case MMI_PEN_EVENT_UP:
        type = PEN_UP;
        break;
    case MMI_PEN_EVENT_MOVE:
        type = PEN_MOVE;
        break;
    case MMI_PEN_EVENT_ABORT:
        type = PEN_ABORT;
        break;
    default:
        return MMI_FALSE;
    }

    widget_handle_pen_event(g_widget_view_cntx->widget_id, g_widget_view_cntx->view_handle, x, y, type);
    return MMI_TRUE;
}

int gadget_adp_view_get_visible_area(kal_int32 *x, kal_int32 *y, kal_int32 *width, kal_int32 *height)
{
    if (!g_widget_view_cntx || g_widget_view_cntx->render_area_width == 0 || g_widget_view_cntx->render_area_height == 0)
    {
        return -1;
    }

    *x = g_widget_view_cntx->render_area_x;
    *y = g_widget_view_cntx->render_area_y;
    *width = g_widget_view_cntx->render_area_width;
    *height = g_widget_view_cntx->render_area_height;
    return 0;
}

int gadget_adp_view_get_screen_handle(gdi_handle * handle1, gdi_handle * handle2, gdi_handle *handle3)
{
    if (!g_widget_view_cntx)
    {
        return -1;
    }

    *handle1 = g_widget_view_cntx->render_layer;
    *handle2 = g_widget_view_cntx->title_layer;
    *handle3 = g_widget_view_cntx->bottom_layer;
    return 0;
}

int gadget_adp_is_in_meeting_or_silent_mode(void)
{
    return (srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) || srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE));
}

int gadget_adp_view_get_screen_orientation(void)
{
    return 0;
}

int gadget_adp_view_get_absolute_pos(int *x, int* y)
{
    if (!g_widget_view_cntx)
    {
        return -1;
    }

    *x = g_widget_view_cntx->render_area_x;
    *y = g_widget_view_cntx->render_area_y;

    return 0;
}

unsigned int gadget_adp_view_get_transparent_color(void)
{
    return WIDGET_VIEW_TRANSPARENT_COLOR;
}

#endif /* __MMI_GADGET_SUPPORT__ */
