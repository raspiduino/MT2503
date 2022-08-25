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
 * BtRmtCapMain.c
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for BTRemoteCapture App.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ****************************************************************************/

#include "mmi_features.h"

#ifdef __MMI_BT_REMOTE_CAPTURE__
#include "BtRmtCapProt.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_btremotecapture_def.h"
#include "CustDataRes.h"
#include "wgui_categories_multimedia.h"
#include "wgui_categories_popup.h"
#include "wgui_softkeys.h"
#include "BTNotiSrvGprot.h"
#include "App_str.h"
#include "Mmi_rp_srv_bt_noti_def.h"
#include "mmi_rp_app_btnotification_def.h"
#include "mmi_conn_app_trc.h"
#include "CommonScreens.h"
#include "wgui_fixed_menus.h"
#include "BtcmSrvGprot.h"
#include "BTConnScr.h"
#include "Gui.h"
#include "wgui_categories_util.h"
#include "gdi_include.h"
#include "ProfilesSrvGprot.h"
#include "Mdi_audio.h"
#include "AudioPlayerBTNowPlaying.h"
#include "mmi_rp_app_bluetooth_def.h"

const char g_rmtcap_cmd_header[] = "CAPC";
mmi_bt_rmt_cap_cntx_struct g_mmi_rmtcap_cntx = {0};
mmi_bt_rmt_cap_cntx_struct *g_mmi_rmtcap_cntx_p = &g_mmi_rmtcap_cntx;

static void mmi_bt_rmtcap_launch_rsp(void *data);
static void mmi_bt_rmtcap_play_shuttersound(void);
static void mmi_bt_rmtcap_write_default_pic(void);
static void mmi_bt_rmtcap_timeout(void);
static void mmi_bt_rmtcap_capture_rsp(void *data);
#ifndef __MTK_TARGET__
static void mmi_bt_rmtcap_modis_capture_timeout(void);
#endif
static void mmi_bt_rmtcap_exit(void);
static mmi_ret mmi_bt_rmtcap_main_scrn_proc (mmi_event_struct *evt);

#ifdef defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
extern void mmi_bt_music_disconnect(BT_MUSIC_CALLBACK callback);
extern MMI_BOOL mmi_bt_music_check_connection(void);

#endif

#define MMI_RMTCAP_STATE_TRANS(x)  \
{                                \
    kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[RMTCAP]State Change: %d-->%d",g_mmi_rmtcap_cntx_p->curr_state,x);\
    g_mmi_rmtcap_cntx_p->curr_state = (x);  \
}


void mmi_bt_rmtcap_preview_req()
{
    U16 cmd_len;
    MMI_BOOL result;   
    //MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_LAUNCH_REQ);
    cmd_len = mmi_bt_rmt_cap_gen_cmd_genaral(g_mmi_rmtcap_cntx_p->cmd, MMI_BT_RMTCAP_CMD_PRVIEW, NULL);
    MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_PRVIEW);
    result = srv_bt_noti_send_cmd_ext(g_mmi_rmtcap_cntx_p->bt_addr, g_rmtcap_cmd_header, g_mmi_rmtcap_cntx_p->cmd, cmd_len);

}

void mmi_bt_rmtcap_launch_req()
{
    U16 cmd_len;
    MMI_BOOL result;   
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_LAUNCH_REQ);
    mmi_bt_rmtcap_write_default_pic();
    cmd_len = mmi_bt_rmt_cap_gen_cmd_genaral(g_mmi_rmtcap_cntx_p->cmd, MMI_BT_RMTCAP_CMD_LAUNCH, NULL);
    MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_LAUNCH);
    result = srv_bt_noti_send_cmd_ext(g_mmi_rmtcap_cntx_p->bt_addr, g_rmtcap_cmd_header, g_mmi_rmtcap_cntx_p->cmd, cmd_len);

    if(!result)
    {
        srv_bt_noti_cap_event_notify_struct noti_evt;
        noti_evt.ret_is_num = MMI_TRUE;
        noti_evt.ret_code= -1;
        mmi_bt_rmtcap_launch_rsp(&noti_evt);
        MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);
    }
    else
    {
        StartTimer(MMI_BT_RMTCAP_TIMER_ID,MMI_BT_RMTCAP_TIME_OUT,mmi_bt_rmtcap_timeout);
    }
}


void mmi_bt_rmtcap_write_default_pic()
{
    WCHAR file_name[MMI_BT_RMTCAP_MAX_FILE_LENGTH] = {0};
    S32 default_height, default_width;
    gdi_handle temp_handle;
    FS_HANDLE fd = -1;
    U8 *img_buffer;

    app_ucs2_strncpy((kal_int8 *)file_name,
        (kal_int8 *)MMI_BT_RMTCAP_PIC_DEFAULT_PATH,
        mmi_wcslen(MMI_BT_RMTCAP_PIC_DEFAULT_PATH) * sizeof(WCHAR));
    fd = FS_Open((const WCHAR*)file_name, FS_READ_ONLY);
    if (fd < FS_NO_ERROR)
    {
        S32 result;
    
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_WRITE_DEFAULT_PIC_REQ_0);
        
        gui_measure_image((PU8)get_image(IMG_BT_RMTCAP_DFAULT_BG), &default_height, &default_width);
        
        img_buffer = mmi_frm_scrmem_alloc_framebuffer(default_height * default_width * 16 / 8);
        gdi_layer_create_using_outside_memory(0,
                                              0,
                                              default_width,
                                              default_height,
                                              &temp_handle,
                                              img_buffer,
                                              (default_height * default_width * 16 / 8));
        gdi_layer_push_and_set_active(temp_handle);
        gdi_image_draw_id(0,0,IMG_BT_RMTCAP_DFAULT_BG);
        result = gdi_image_encode_layer_to_jpeg(temp_handle, (PS8)file_name);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_WRITE_DEFAULT_PIC_REQ_1, result);
        gdi_layer_pop_and_restore_active();
        mmi_frm_scrmem_free(img_buffer);
    }
    else
    {
        FS_Close(fd);
    }
}


mmi_ret mmi_bt_rmtcap_loading_show(mmi_event_struct *evt, MMI_ID Str_id)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_SHOW_LOADING);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory165Screen(
            NULL,
            NULL,
            NULL,
            NULL,
            (UI_string_type) GetString(Str_id),
            IMG_GLOBAL_L1,
            gui_buffer);
    return MMI_RET_OK;
}


mmi_ret mmi_bt_rmtcap_popup_scrn_proc (mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            g_mmi_rmtcap_cntx_p->popup_src_id= SCR_ID_BTRMTCAP_POPUP_SCRN;
            mmi_bt_rmtcap_loading_show(evt, STR_ID_BTRMTCAP_CAPTURE_ING);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
             g_mmi_rmtcap_cntx_p->popup_src_id = 0;
             //g_mmi_rmtcap_cntx_p->main_scrn_id = 0;
             break;
        }
    }
    return MMI_RET_OK;
}

void mmi_bt_rmtcap_main_capture(void)
{
    U16 cmd_len;
    MMI_BOOL result;

    cmd_len = mmi_bt_rmt_cap_gen_cmd_genaral(g_mmi_rmtcap_cntx_p->cmd, MMI_BT_RMTCAP_CMD_CAPTURE, NULL);
    MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_CAPTURE);
    result = srv_bt_noti_send_cmd_ext(g_mmi_rmtcap_cntx_p->bt_addr, g_rmtcap_cmd_header, g_mmi_rmtcap_cntx_p->cmd, cmd_len);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_CAPTURE, cmd_len, result);
    if(!result)
    {
        srv_bt_noti_cap_event_notify_struct noti_evt;
        noti_evt.ret_is_num = MMI_TRUE;
        noti_evt.ret_code= -1;
        mmi_bt_rmtcap_capture_rsp(&noti_evt);
        MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);
    }
    else
    {
    #ifdef __MTK_TARGET__
        mmi_bt_rmtcap_play_shuttersound();
    #endif

    #ifndef __MTK_TARGET__
        StartTimer(MMI_BT_RMTCAP_TIMER_ID,1000,mmi_bt_rmtcap_modis_capture_timeout);
    #else
        StartTimer(MMI_BT_RMTCAP_TIMER_ID,MMI_BT_RMTCAP_TIME_OUT,mmi_bt_rmtcap_timeout);
    #endif
        mmi_frm_scrn_create(GRP_ID_BTRMTCAP_APP, 
                       SCR_ID_BTRMTCAP_POPUP_SCRN, 
                       mmi_bt_rmtcap_popup_scrn_proc,
                       g_mmi_rmtcap_cntx_p);
    }
}



void mmi_bt_rmtcap_exit_show_pic(void)
{
    MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_PRVIEW);
    if (g_mmi_rmtcap_cntx_p->show_pic_scrn_id != 0)
    {
        mmi_frm_scrn_close_active_id();
    }
}


void mmi_bt_rmtcap_send_exit_req(void)
{
    U16 cmd_len = 0;
    MMI_BOOL result = MMI_FALSE;
    if (!g_mmi_rmtcap_cntx_p->need_exit_cmd)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_EXIT_CAPTURE, cmd_len, result);
        return;
    }
    cmd_len = mmi_bt_rmt_cap_gen_cmd_genaral(g_mmi_rmtcap_cntx_p->cmd, MMI_BT_RMTCAP_CMD_EXIT, NULL);
    MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);
    result = srv_bt_noti_send_cmd_ext(g_mmi_rmtcap_cntx_p->bt_addr, g_rmtcap_cmd_header, g_mmi_rmtcap_cntx_p->cmd, cmd_len);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_EXIT_CAPTURE, cmd_len, result);
}


void mmi_bt_rmtcap_main_exit_capture(void)
{  
    MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);

    mmi_bt_rmtcap_exit();
}


void mmi_bt_rmtcap_image_preview_callback(S32 result)
{

}


#ifndef __MTK_TARGET__
void mmi_bt_rmtcap_modis_capture_timeout(void)
{
    WCHAR file_name[25] = L"Z:\\aa\\capture_pic.jpg";
    srv_bt_noti_cap_event_notify_struct noti_evt;
    noti_evt.ret_is_num = MMI_FALSE;
    noti_evt.ret_code= MMI_BT_RMTCAP_CMD_CAPTURE;
    noti_evt.user_data = OslMalloc(55);

    app_ucs2_strncpy((char *)noti_evt.user_data, (char *)file_name, 25);
    if (g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_CAPTURE)
    {
        mmi_bt_rmtcap_capture_rsp(&noti_evt);
    }
    OslMfree(noti_evt.user_data);
}

#endif

void mmi_bt_rmtcap_timeout(void)
{
    srv_bt_noti_cap_event_notify_struct noti_evt;
    noti_evt.ret_is_num = MMI_TRUE;
    noti_evt.ret_code= -1;

    #ifndef __MTK_TARGET__
    noti_evt.ret_code = 1;
    #endif

    StopTimer(MMI_BT_RMTCAP_TIMER_ID);
    if (g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_LAUNCH)
    {
        mmi_bt_rmtcap_launch_rsp(&noti_evt);
    }
    else if (g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_CAPTURE)
    {
        mmi_bt_rmtcap_capture_rsp(&noti_evt);
    }
}


MMI_BOOL mmi_bt_rmtcap_is_slient_mode()
{
    if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == MMI_TRUE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


void mmi_bt_rmtcap_play_shuttersound()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 aud_len;
    U8 *aud_data = NULL;
    U8 aud_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bt_rmtcap_is_slient_mode())
    {
        return;
    }
    aud_data = get_audio((U16) (AUD_ID_BTRMTCAP_CAMCO_CAPTURE), &aud_type, &aud_len);
    if (aud_data != NULL)
    {
        mdi_audio_play_string_with_vol_path(
            (void*)aud_data,
            aud_len,
            aud_type,
            DEVICE_AUDIO_PLAY_ONCE,
            NULL,
            NULL,
            MDI_AUD_VOL_4,
            MDI_DEVICE_SPEAKER_BOTH);
    }

}


mmi_ret mmi_btrmtcap_loading_key_handle(mmi_frm_key_evt_struct *evt)
{

    switch (evt->evt_id)
    {
        case EVT_ID_PRE_KEY:
        {
            if (evt->key_code == KEY_END && g_mmi_rmtcap_cntx_p->ignore_endkey)
            {
                return MMI_RET_ERR;
            }
        }
    }
    return MMI_RET_OK;
}


mmi_ret mmi_bt_rmtcap_pic_show(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_PIC_SHOW);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if (g_mmi_rmtcap_cntx_p->file_name)
    {
        WCHAR file_name[BT_NOTIFY_XML_FILE_NAME_LENTH] = {0};
        
        app_ucs2_strncpy((char *)file_name, 
                         (char *)g_mmi_rmtcap_cntx_p->file_name, 
                          BT_NOTIFY_XML_FILE_NAME_LENTH);
    
        ShowCategory222Screen(
            STR_ID_BTRMTCAP_APPLICATION_APP_NAME,//Tittle str
            NULL,//tittle_icon
            NULL,//lsk
            NULL,//lsk_icon
            STR_GLOBAL_BACK,//rsk
            NULL,//rsk_icon
            GDI_COLOR_BLACK,//bg_color
            NULL,//btn_str
            (CHAR *)file_name,//file_name
            MMI_FALSE,//is_short
            mmi_bt_rmtcap_image_preview_callback,//decode_callback
            GDI_IMAGE_SRC_FROM_FILE//src_type
            );
        SetRightSoftkeyFunction(mmi_bt_rmtcap_exit_show_pic, KEY_EVENT_UP);
    }  
    return MMI_RET_OK;
}

static S32 mmi_bt_rmtcap_get_device_list_item(S32 start_index, gui_iconlist_menu_item* menu_data, S32 num_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    const srv_bt_cm_dev_struct *dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    for (i = start_index; i < num_items; ++i)
    {
        dev_info = srv_bt_cm_get_linked_dev_info(i);
        if (dev_info != NULL)
        {
            mmi_chset_utf8_to_ucs2_string(
                (U8*)menu_data[i].item_list[0],
                SRV_BT_CM_BD_NAME_UCS2_LEN,
                ((srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(i))->name);
            //mmi_wcscpy(menu_data[i].item_list[0], (WCHAR *)dev_info->name);
            menu_data[i].image_list[0] = mmi_bt_get_device_image(dev_info->cod);
        }
    }

    return num_items;
}

void mmi_bt_rmtcap_device_list_lsk_hdlr(void) 
{
    mmi_frm_scrn_create(GRP_ID_BTRMTCAP_APP, 
       SCR_ID_BTRMTCAP_MAIN_SCRN, 
       mmi_bt_rmtcap_main_scrn_proc,
       g_mmi_rmtcap_cntx_p);
}


void mmi_bt_rmtcap_device_highlight_hdlr(S32 index)
{
    g_mmi_rmtcap_cntx_p->device_hilight_idx = index;
    g_mmi_rmtcap_cntx_p->bt_addr = &(((srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(index))->bd_addr);

    kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,
        "[RMTCAP]highlighthdlr, idx, :%d, lap: %d,uap: %d, nap:%d",
        g_mmi_rmtcap_cntx_p->device_hilight_idx,
        g_mmi_rmtcap_cntx_p->bt_addr->lap,
        g_mmi_rmtcap_cntx_p->bt_addr->uap,
        g_mmi_rmtcap_cntx_p->bt_addr->nap);
}


mmi_ret mmi_bt_rmtcap_device_list_show(mmi_event_struct *evt) 
{
    U8 *gui_buffer = NULL;
    S32 list_not_ready;
    S32 device_num = 2;

    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    g_mmi_rmtcap_cntx_p->bt_addr = &(((srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(0))->bd_addr);
    device_num = srv_bt_cm_get_linked_dev_list_idx();
    wgui_cat1032_show(
                    (WCHAR*)GetString(STR_ID_BTRMTCAP_APPLICATION_APP_NAME),
                    0,
                    (WCHAR*)GetString(STR_GLOBAL_OK),
                    0,
                    (WCHAR*)GetString(STR_GLOBAL_BACK),
                    0,
                    device_num,
                    mmi_bt_rmtcap_get_device_list_item,
                    NULL,
                    0,
                    0,
                    IMG_BT_DEV_OTHER,   
                    0,
                    gui_buffer,
                    &list_not_ready);

    RegisterHighlightHandler(mmi_bt_rmtcap_device_highlight_hdlr);
    SetLeftSoftkeyFunction(mmi_bt_rmtcap_device_list_lsk_hdlr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_bt_rmtcap_device_list_lsk_hdlr, KEY_EVENT_UP);

    return MMI_RET_OK;
}

mmi_ret mmi_bt_rmtcap_main_show(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_MAIN_SHOW, g_mmi_rmtcap_cntx_p->is_remote_launched);
    kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,
        "[RMTCAP]main_show, idx, :%d, lap: %d,uap: %d, nap:%d",
        g_mmi_rmtcap_cntx_p->device_hilight_idx,
        g_mmi_rmtcap_cntx_p->bt_addr->lap,
        g_mmi_rmtcap_cntx_p->bt_addr->uap,
        g_mmi_rmtcap_cntx_p->bt_addr->nap);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    g_mmi_rmtcap_cntx_p->ignore_endkey = MMI_FALSE;
#ifdef __MTK_TARGET__
    if (!srv_bt_noti_check_connection_ext(g_mmi_rmtcap_cntx_p->bt_addr))
    {
        S32 list_not_ready;
        MMI_ID hint_str_id;
        U8 *gui_buffer;
        
        if (srv_bt_cm_get_linked_dev_list_idx() == 0)
        {
            hint_str_id = STR_ID_BTNOTIFICATION_APPLICATION_NEED_USER_CONNECT;
        }
        else
        {
            hint_str_id = STR_ID_BTNOTIFICATION_APPLICATION_DISCONNECT;
        }
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        wgui_set_menu_empty_string_by_id(hint_str_id);
        wgui_cat1032_show(
                    (WCHAR*)GetString(STR_ID_BTRMTCAP_APPLICATION_APP_NAME),
                    0,
                    0,
                    0,
                    (WCHAR*)GetString(STR_GLOBAL_BACK),
                    0,
                    0,
                    NULL,
                    NULL,
                    NULL,
                    0,
                    0,   
                    0,
                    gui_buffer,
                    &list_not_ready);
        wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
        return MMI_RET_OK;
    }
#endif
    if (g_mmi_rmtcap_cntx_p->is_remote_launched)
    {

        WCHAR file_name[BT_NOTIFY_XML_FILE_NAME_LENTH] = {0};

        mdi_audio_suspend_background_play();
        dm_reset_context();
            
        if (g_mmi_rmtcap_cntx_p->file_name && 
            g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_PRVIEW)
        {
            app_ucs2_strncpy((char *)file_name, 
                             (char *)g_mmi_rmtcap_cntx_p->file_name, 
                              BT_NOTIFY_XML_FILE_NAME_LENTH);
        
            ShowCategory222Screen(
                STR_ID_BTRMTCAP_APPLICATION_APP_NAME,//Tittle str
                NULL,//tittle_icon
                STR_ID_BTRMTCAP_CAPTURE,//lsk
                NULL,//lsk_icon
                STR_GLOBAL_BACK,//rsk
                NULL,//rsk_icon
                GDI_COLOR_BLACK,//bg_color
                NULL,//btn_str
                (CHAR *)file_name,//file_name
                MMI_FALSE,//is_short
                mmi_bt_rmtcap_image_preview_callback,//decode_callback
                GDI_IMAGE_SRC_FROM_FILE//src_type
                );
        }    
        else
        {                       
            app_ucs2_strncpy((kal_int8 *)file_name,
                (kal_int8 *)MMI_BT_RMTCAP_PIC_DEFAULT_PATH,
                mmi_wcslen(MMI_BT_RMTCAP_PIC_DEFAULT_PATH) * sizeof(WCHAR));
            ShowCategory222Screen(
                STR_ID_BTRMTCAP_APPLICATION_APP_NAME,//Tittle str
                NULL,//tittle_icon
                STR_ID_BTRMTCAP_CAPTURE,//lsk
                NULL,//lsk_icon
                STR_GLOBAL_BACK,//rsk
                NULL,//rsk_icon
                GDI_COLOR_BLACK,//bg_color
                NULL,//btn_str
                (CHAR *)file_name,//file_name
                MMI_FALSE,//is_short
                mmi_bt_rmtcap_image_preview_callback,//decode_callback
                GDI_IMAGE_SRC_FROM_FILE//src_type
                );
            if (g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_IDLE)
            {
                mmi_bt_rmtcap_preview_req();
            }
        }
        
        SetLeftSoftkeyFunction(mmi_bt_rmtcap_main_capture, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_bt_rmtcap_main_exit_capture, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_bt_rmtcap_main_capture, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory123Screen(
            STR_ID_BTRMTCAP_APPLICATION_APP_NAME,
            0,
            NULL,
            NULL,
            NULL,
            NULL,
            STR_GLOBAL_LOADING,
            NULL,
            gui_buffer);
            
        mmi_bt_rmtcap_launch_req();
        clear_softkey_handler(MMI_RIGHT_SOFTKEY);
        g_mmi_rmtcap_cntx_p->ignore_endkey = MMI_TRUE;
        
        #ifndef __MTK_TARGET__
        StartTimer(MMI_BT_RMTCAP_TIMER_ID,1000,mmi_bt_rmtcap_timeout);
        #endif/*__MTK_TARGET__*/
    }
    MMI_SCR_SET_KEY_PROC(mmi_btrmtcap_loading_key_handle, NULL);
    return MMI_RET_OK;
}

mmi_ret mmi_bt_rmtcap_main_group_proc(mmi_event_struct *param)
{
    switch(param->evt_id)
    {
        case EVT_ID_GROUP_INACTIVE:
        {
            kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[RMTCAP]Inactive Exit");
            mmi_bt_rmtcap_main_exit_capture();
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
           g_mmi_rmtcap_cntx_p->grp_id = 0;
           break;
        }
    }
    return MMI_RET_OK;
}

mmi_ret mmi_bt_rmtcap_device_list_scrn_proc (mmi_event_struct *evt) 
{
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            g_mmi_rmtcap_cntx_p->devce_list_scrn_id = SCR_ID_BTRMTCAP_DEVICE_LIST;
            mmi_bt_rmtcap_device_list_show(evt);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
            g_mmi_rmtcap_cntx_p->devce_list_scrn_id = 0;
            g_mmi_rmtcap_cntx_p->is_remote_launched = MMI_FALSE;
            if (g_mmi_rmtcap_cntx_p->file_name)
            {
                OslMfree(g_mmi_rmtcap_cntx_p->file_name);
                g_mmi_rmtcap_cntx_p->file_name = NULL;
            }
            break;
        }
    }
    return MMI_RET_OK;
}


mmi_ret mmi_bt_rmtcap_main_scrn_proc (mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            g_mmi_rmtcap_cntx_p->main_scrn_id = SCR_ID_BTRMTCAP_MAIN_SCRN;
            mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_REMOTE_CAPTURE);
            mmi_bt_rmtcap_main_show(evt);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
            g_mmi_rmtcap_cntx_p->main_scrn_id = 0;
            g_mmi_rmtcap_cntx_p->is_remote_launched = MMI_FALSE;
            if (g_mmi_rmtcap_cntx_p->file_name)
            {
                OslMfree(g_mmi_rmtcap_cntx_p->file_name);
                g_mmi_rmtcap_cntx_p->file_name = NULL;
            }
            mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_REMOTE_CAPTURE);
            mmi_bt_rmtcap_send_exit_req();
            mdi_audio_resume_background_play();
            break;
        }
    }
    return MMI_RET_OK;
}

mmi_ret mmi_bt_rmtcap_show_pic_scrn_proc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            g_mmi_rmtcap_cntx_p->show_pic_scrn_id = SCR_ID_BTRMTCAP_SHOW_PICTURE;
            mmi_bt_rmtcap_pic_show(evt);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
            g_mmi_rmtcap_cntx_p->show_pic_scrn_id = 0;
            MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);
            break;
        }
    }
    return MMI_RET_OK;
}

void mmi_btrmtcap_launch()
{
    g_mmi_rmtcap_cntx_p->need_exit_cmd = MMI_TRUE;
    g_mmi_rmtcap_cntx_p->bt_addr = &(((srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(0))->bd_addr);

    
    g_mmi_rmtcap_cntx_p->grp_id = mmi_frm_group_create_ex(
                                    GRP_ID_ROOT,
                                    GRP_ID_BTRMTCAP_APP,
                                    mmi_bt_rmtcap_main_group_proc,
                                    g_mmi_rmtcap_cntx_p,
                                    MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    if (srv_bt_cm_get_linked_dev_list_idx() > 1)
    {
        mmi_frm_scrn_create(GRP_ID_BTRMTCAP_APP, 
           SCR_ID_BTRMTCAP_DEVICE_LIST, 
           mmi_bt_rmtcap_device_list_scrn_proc,
           g_mmi_rmtcap_cntx_p);
    }
    else 
    {
       mmi_frm_scrn_create(GRP_ID_BTRMTCAP_APP, 
       SCR_ID_BTRMTCAP_MAIN_SCRN, 
       mmi_bt_rmtcap_main_scrn_proc,
       g_mmi_rmtcap_cntx_p);
    }
}

void mmi_btrmtcap_bt_music_disconn_cb(MMI_BOOL result)
{
    if (result)
    {
        mmi_btrmtcap_launch();
    }
}
    
void mmi_btrmtcap_entry_main_message_menu()
{
#if defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
    if (mmi_bt_music_check_connection())
    {
        mmi_bt_music_disconnect(NULL);
        //return;
    }
    //else
#endif
    {
        mmi_btrmtcap_launch();
    }
}


void mmi_bt_rmtcap_exit()
{
    mmi_frm_scrn_close(g_mmi_rmtcap_cntx_p->grp_id, g_mmi_rmtcap_cntx_p->popup_src_id);
    mmi_frm_scrn_close(g_mmi_rmtcap_cntx_p->grp_id, g_mmi_rmtcap_cntx_p->main_scrn_id);
    if (g_mmi_rmtcap_cntx_p->devce_list_scrn_id == 0) 
    {
        mmi_frm_group_close(g_mmi_rmtcap_cntx_p->grp_id);   
    }
}


void mmi_bt_rmtcap_launch_rsp(void *data)
{
    srv_bt_noti_cap_event_notify_struct *noti_evt = data;
    S32 error_code = 0;
    StopTimer(MMI_BT_RMTCAP_TIMER_ID);
                  

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_LAUNCED_RSP, noti_evt->ret_is_num, noti_evt->ret_code);
    if (noti_evt->ret_is_num)
    {
        error_code = noti_evt->ret_code;
        
        if (error_code == MMI_BT_RMTCAP_CMD_LAUNCH)
        {
            MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE); 
            if (g_mmi_rmtcap_cntx_p->grp_id == 0)
            {
                return;
            }
            g_mmi_rmtcap_cntx_p->is_remote_launched = MMI_TRUE;
            mmi_frm_scrn_create(GRP_ID_BTRMTCAP_APP, 
                SCR_ID_BTRMTCAP_MAIN_SCRN, 
                mmi_bt_rmtcap_main_scrn_proc,
                g_mmi_rmtcap_cntx_p);
            
            if (!mmi_frm_scrn_is_present(
                    GRP_ID_BTRMTCAP_APP,
                    SCR_ID_BTRMTCAP_MAIN_SCRN,
                    MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                mmi_bt_rmtcap_main_show(NULL);
            }
        }
        else if (error_code < 0)
        {
            MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE); 
            mmi_display_popup((UI_string_type)get_string(STR_ID_BTRMTCAP_LAUNCH_FAILED), MMI_EVENT_FAILURE);
            mmi_frm_scrn_close(g_mmi_rmtcap_cntx_p->grp_id,g_mmi_rmtcap_cntx_p->main_scrn_id);
            //mmi_frm_group_close(g_mmi_rmtcap_cntx_p->grp_id);
        }
    }
}

void mmi_bt_rmtcap_capture_rsp(void *data)
{
    srv_bt_noti_cap_event_notify_struct *noti_evt = data;
    S32 error_code = 0;    
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_CAPTURE_RSP, noti_evt->ret_is_num, noti_evt->ret_code); 
    
    if (!noti_evt->ret_is_num)
    {
        error_code = noti_evt->ret_code;

        if (error_code == MMI_BT_RMTCAP_CMD_CAPTURE)
        {
            MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_PIC_SHOW);
            StopTimer(MMI_BT_RMTCAP_TIMER_ID);
            if (g_mmi_rmtcap_cntx_p->file_name == NULL)
            {
                g_mmi_rmtcap_cntx_p->file_name = (WCHAR *)OslMalloc(BT_NOTIFY_XML_FILE_NAME_LENTH * 2);
            }
            app_ucs2_strncpy((char *)g_mmi_rmtcap_cntx_p->file_name, (char *)noti_evt->user_data, BT_NOTIFY_XML_FILE_NAME_LENTH);
            if (g_mmi_rmtcap_cntx_p->grp_id == 0)
            {
                MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);
                return;
            }
            if (g_mmi_rmtcap_cntx_p->popup_src_id != 0)
            {
                mmi_frm_scrn_close(g_mmi_rmtcap_cntx_p->grp_id, g_mmi_rmtcap_cntx_p->popup_src_id);
            }
            mmi_frm_scrn_create(GRP_ID_BTRMTCAP_APP, 
                SCR_ID_BTRMTCAP_SHOW_PICTURE, 
                mmi_bt_rmtcap_show_pic_scrn_proc,
                g_mmi_rmtcap_cntx_p);
        }       
    }
    else
    {
        error_code = noti_evt->ret_code;
        StopTimer(MMI_BT_RMTCAP_TIMER_ID);
        MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);
        if (error_code < 0)
        {            
            if (g_mmi_rmtcap_cntx_p->grp_id == 0)
            {
                return;
            }
            mmi_display_popup((UI_string_type)get_string(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE);
            if (g_mmi_rmtcap_cntx_p->popup_src_id != 0)
            {
                mmi_frm_scrn_close(g_mmi_rmtcap_cntx_p->grp_id, g_mmi_rmtcap_cntx_p->popup_src_id);
            }
        }
    }
}

void mmi_bt_rmt_cap_preview(void *data)
{
    
        srv_bt_noti_cap_event_notify_struct *noti_evt = data;
        S32 error_code = 0;
        
        MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_PRVIEW);      
        kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[RMTCAP]Preview,cur_state:%d, error_code:%d",g_mmi_rmtcap_cntx_p->curr_state,noti_evt->ret_code);
        
        if (!noti_evt->ret_is_num)
        {
            error_code = noti_evt->ret_code;
    
            if (error_code == MMI_BT_RMTCAP_CMD_PRVIEW)
            {
                if (g_mmi_rmtcap_cntx_p->file_name == NULL)
                {
                    g_mmi_rmtcap_cntx_p->file_name = (WCHAR *)OslMalloc(BT_NOTIFY_XML_FILE_NAME_LENTH * 2);
                }
                app_ucs2_strncpy((char *)g_mmi_rmtcap_cntx_p->file_name, (char *)noti_evt->user_data, BT_NOTIFY_XML_FILE_NAME_LENTH);
                if (g_mmi_rmtcap_cntx_p->grp_id == 0)
                {
                    return;
                }
                if (!mmi_frm_scrn_is_present(
                    GRP_ID_BTRMTCAP_APP,
                    SCR_ID_BTRMTCAP_MAIN_SCRN,
                    MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                {
                    mmi_bt_rmtcap_main_show(NULL);
                }
            }
            else if (error_code < 0)
            {
                if (g_mmi_rmtcap_cntx_p->file_name)
                {
                    OslMfree(g_mmi_rmtcap_cntx_p->file_name);
                    g_mmi_rmtcap_cntx_p->file_name = NULL;
                }
            }
        }
}


mmi_ret mmi_bt_rmtcap_event_hdlr(mmi_event_struct *param)
{
    switch (param->evt_id)
    {
        case EVT_ID_SRV_BT_NOTI_CAP_CMD_NOTIFY:
        {
            srv_bt_noti_cap_event_notify_struct *noti_evt = (srv_bt_noti_cap_event_notify_struct *)param;
            S32 error_code;            
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_EVENT_HDLR, g_mmi_rmtcap_cntx_p->curr_state);
            if (g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_LAUNCH)
            {
                mmi_bt_rmtcap_launch_rsp(param);
            }
            else if (g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_CAPTURE)
            {
                mmi_bt_rmtcap_capture_rsp(param);
            }
            else if ((g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_IDLE ||
                g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_PRVIEW)
                && g_mmi_rmtcap_cntx_p->is_remote_launched)
            {
                mmi_bt_rmt_cap_preview(param);
            }

            if (noti_evt->ret_is_num)
            {
                error_code = noti_evt->ret_code;
                if (error_code == MMI_BT_RMTCAP_CMD_EXIT)
                {
                    g_mmi_rmtcap_cntx_p->need_exit_cmd = MMI_FALSE;
                    mmi_bt_rmtcap_exit();
                }
            }
            break;
        }
        case EVT_ID_SRV_BT_NOTI_MAP_DISCONNECT_CNF:
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_EVENT_HDLR2, g_mmi_rmtcap_cntx_p->curr_state);
            mmi_bt_rmtcap_exit();
            break;
        }
    }
    
    return MMI_RET_OK;
}

void mmi_bt_rmtcap_bootup_init()
{
    WCHAR file_name[MMI_BT_RMTCAP_MAX_FILE_LENGTH] = {0};

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_BOOTUP_INIT);
    app_ucs2_strncpy((kal_int8 *)file_name,
        (kal_int8 *)MMI_BT_RMTCAP_FOLDER_PATH,
        mmi_wcslen(MMI_BT_RMTCAP_FOLDER_PATH) * sizeof(WCHAR));
    memset(g_mmi_rmtcap_cntx_p, 0, sizeof(mmi_bt_rmt_cap_cntx_struct));   
}

mmi_ret mmi_bt_rmtcap_package_proc(mmi_event_struct *evt)
{
    return MMI_RET_DONT_CARE;
}


#endif /*__MMI_BT_REMOTE_CAPTURE__*/

