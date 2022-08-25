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
 * SndrecProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for sound recorder.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SNDREC_PROT_H
#define _SNDREC_PROT_H

#include "MMI_features.h"
#if defined(__MMI_SOUND_RECORDER__)

#include "MMIDataType.h"
#include "mdi_datatype.h"
#include "Mdi_audio.h"
#include "mmi_frm_input_gprot.h"
#include "FileMgrSrvGProt.h"
#include "MMI_media_app_trc.h"
#include "mmi_rp_file_type_def.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gui_data_types.h"
#include "gui_windows.h"
#include "SndrecDef.h"
#include "SoundRecSrvGProt.h"

/****************************************************************************
* Macro define
*****************************************************************************/
#if defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)|| defined(__MMI_MAINLCD_320X240__))
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        #define MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    #endif
#endif

#define MMI_SNDREC_TYPE_EVL (MMI_SNDREC_TYPE_TOTAL + 1)

#define MMI_SNDREC_ERR_TRACE(VAL) \
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_ERR_REPORT, __LINE__, VAL)
#define MMI_SNDREC_MSG_TRACE(VAL) \
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_MSG_REPORT, __LINE__, VAL)


#define __MMI_SNDREC_UT

#ifdef __MMI_SNDREC_UT
#define MMI_SNDREC_ASSERT MMI_ASSERT
#else
#define MMI_ASSERT do{}while(0)
#endif

#define MMI_SNDREC_CONTEXT_SIZE  2*1024
#define MMI_SNDREC_MEM_POOL_SIZE MMI_SNDREC_CONTEXT_SIZE

/****************************************************************************
*  in sndrecui.h
*****************************************************************************/
void mmi_sndrec_hightlight_main(void);

void mmi_sndrec_get_full_file_name(U16 *fullname, const U16*filename);
void mmi_sndrec_release_list_btn(void);
void mmi_sndrec_release_stop_btn(void);
void mmi_sndrec_get_file_path(U16 *fullname);
extern void mmi_sndrec_cb_for_other_app(MMI_BOOL is_true);

/****************************************************************************
*  in sndrecutil.h
*****************************************************************************/
void mmi_sndrec_util_fmgr_init(void);
S32  mmi_sndrec_util_reclist_create(void);
void mmi_sndrec_util_reclist_free(void);
void mmi_sndrec_util_reclist_ready(SRV_FMGR_FILELIST_HANDLE fl_hdl, S32 total);
void mmi_sndrec_util_filter_set(FMGR_FILTER *filter);
void mmi_sndrec_util_curridx_set_async(void);
MMI_BOOL mmi_sndrec_util_check_created(void);
MMI_BOOL mmi_sndrec_util_reclist_check_valid(void);
MMI_BOOL mmi_sndrec_util_get_next_pre_rec(MMI_BOOL is_next, CHAR *displayname);
MMI_BOOL mmi_sndrec_util_get_filename(CHAR *displayname);

MMI_BOOL mmi_sndrec_fs_check_file(U16 *file);
MMI_BOOL mmi_sndrec_fs_check_folder(U16 *filepath);
MMI_BOOL mmi_sndrec_util_reclist_query_is_process(void);

/****************************************************************************
*  in sndrecdraw.h
*****************************************************************************/
#ifdef __MMI_SNDREC_SKIN__ 
    enum
    {
        MMI_SNDREC_NONE,
        MMI_SNDREC_LSK,
        MMI_SNDREC_RSK,
        MMI_SNDREC_RECORD,
        MMI_SNDREC_PLAY,
        MMI_SNDREC_PREV,
        MMI_SNDREC_NEXT,
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        MMI_SNDREC_LIST,
#endif
    #ifdef __MMI_FTE_SUPPORT__
        MMI_SNDREC_STOP,
    #endif
        MMI_SNDREC_TOTAL
    };
    
    typedef struct
    {
        GDI_HANDLE skinlayer;
        GDI_HANDLE osdlayer;
        GDI_HANDLE oldbldlayer;
    }mmi_sndrec_screen_layer_struct;      /* app memory  */
    
    typedef struct
    {
        S16 x, y;
        S16 w, h;
        UI_string_type text;
    //    color color;             /* should be here  */
    //    color border_color
    }mmi_sndrec_draw_text_struct;
    
    typedef struct
    {
        S16 x1;
        S16 y1;
        S16 x2;
        S16 y2;
    }mmi_sndrec_area_struct;            
    
    typedef struct  
    {
        S16 x, y;
        GDI_HANDLE img_handle;
        U8 *img;
    }mmi_sndrec_animation_struct;
    
#ifdef __MMI_FTE_SUPPORT__   
    /* Remove images of disabled status, change to 50% transparency(Apply in all FTE Project) */
    typedef struct
    {
        S16 x, y;
        S16 w, h;
        U8 *up_img; //,*disable_img;
    }mmi_sndrec_push_button_struct;

    /* Remove images of disabled status, change to 50% transparency(Apply in all FTE Project) */
    typedef struct
    {
        S16 x, y;
        S16 w, h;
        PU8 up_img;
    #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
	    PU8 down_img;
    #endif
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        UI_string_type text;
    #endif
	    //PU8 dis_img;
        color color;             /* move position from mmi_sndrec_main_draw_struct */
        color border_color;
    } mmi_sndrec_main_SK_button_struct;
    
    typedef struct
    {
        mmi_sndrec_main_SK_button_struct lsk;
        mmi_sndrec_main_SK_button_struct rsk;
        
        color title_color;
        color title_border_color;
    
        color filename_color;
        color filename_border_color;
    
        color time_color;
        color time_border_color;

        /* Remove Background image, change to use submenu’s background(Apply in all FTE Project) */
        //U8 *bg_img;
        mmi_sndrec_push_button_struct record;
        mmi_sndrec_push_button_struct rec_pause;
        mmi_sndrec_push_button_struct play;
        mmi_sndrec_push_button_struct play_pause;
        mmi_sndrec_push_button_struct previous;
        mmi_sndrec_push_button_struct next;
        mmi_sndrec_push_button_struct highlight_img;
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        mmi_sndrec_push_button_struct list;
    #endif
        mmi_sndrec_push_button_struct stop;
        mmi_sndrec_push_button_struct rec_icon;
        mmi_sndrec_push_button_struct rec_pause_icon;
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        S16 line_x, line_y, line_w, line_h;
        U8 *line_img;
    #else
    #ifdef __MMI_FTE_SUPPORT_SLIM__
        mmi_sndrec_push_button_struct line;
    #endif    
    #endif
        /* Remove unused images(cross), new design no need(Apply in all FTE Project) */
    /*#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    #ifdef __MMI_FTE_SUPPORT_SLIM__
        mmi_sndrec_push_button_struct cross;
    #endif
    #endif*/

#if 0 //def __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        mmi_sndrec_animation_struct animal;
    
        scrolling_text scroll_text;
        scrolling_text scroll_text_state;
        mmi_sndrec_draw_text_struct filename;
        mmi_sndrec_draw_text_struct time;
        mmi_sndrec_draw_text_struct title;
        mmi_sndrec_draw_text_struct state;

    #ifdef __MMI_TOUCH_SCREEN__
        S32 pen_dn_obj;
        mmi_pen_polygon_area_struct lsk_area;
        mmi_pen_polygon_area_struct rsk_area;
    #endif /* __MMI_TOUCH_SCREEN__ */
    }mmi_sndrec_main_draw_struct;          /* app memory */
    
#else/*__MMI_FTE_SUPPORT__*/
    
    typedef struct
    {
        S16 x, y;
        S16 w, h;
        U8 *up_img, *down_img, *disable_img;
    }mmi_sndrec_push_button_struct;
    
    typedef struct
    {
        UI_string_type text;
        color color;             /* move position from mmi_sndrec_main_draw_struct */
        color border_color;
    } mmi_sndrec_main_SK_struct;
    
    typedef struct
    {
        mmi_sndrec_main_SK_struct lsk;
        mmi_sndrec_main_SK_struct rsk;
    
        color title_color;
        color title_border_color;

        color state_color;
        color state_border_color;
    
        color filename_color;
        color filename_border_color;
    
        color time_color;
        color time_border_color;
    
        U8 *bg_img;
        mmi_sndrec_push_button_struct record;
        mmi_sndrec_push_button_struct rec_pause;
        mmi_sndrec_push_button_struct play;
        mmi_sndrec_push_button_struct play_pause;
        mmi_sndrec_push_button_struct previous;
        mmi_sndrec_push_button_struct next;
        mmi_sndrec_push_button_struct list;
    
        mmi_sndrec_animation_struct animal;
    
        scrolling_text scroll_text;
        scrolling_text scroll_text_state;
        mmi_sndrec_draw_text_struct filename;
        mmi_sndrec_draw_text_struct time;
        mmi_sndrec_draw_text_struct title;
        mmi_sndrec_draw_text_struct state;
    
    #ifdef __MMI_TOUCH_SCREEN__
            S32 pen_dn_obj;
            mmi_pen_polygon_area_struct lsk_area;
            mmi_pen_polygon_area_struct rsk_area;
    #endif /* __MMI_TOUCH_SCREEN__ */
    }mmi_sndrec_main_draw_struct;
    
#endif /*__MMI_FTE_SUPPORT__*/

    void mmi_sndrec_redraw_list_btn(MMI_BOOL isdown);    
#ifdef __MMI_FTE_SUPPORT__
    void mmi_sndrec_redraw_stop_btn(MMI_BOOL isdown);   
    void mmi_sndrec_redraw_rec_icon(void);               
#endif /* __MMI_FTE_SUPPORT__ */ 
#endif /* __MMI_SNDREC_SKIN__ */

typedef enum
{
    MMI_SNDREC_FORMAT_NULL,
    MMI_SNDREC_FORMAT_VM  
}mmi_sndrec_format_ext;
/****************************************************************************
*  in sndrectype.h
*****************************************************************************/
typedef struct
{
    MMI_BOOL is_created;
    MMI_BOOL is_process;
    S32 curr_index;
    S32 curr_index_async;
    S32 total_num;
    SRV_FMGR_FILELIST_HANDLE fl_hdl;
}mmi_sndrec_fmgr_reclist_struct;         /* app memory */

typedef struct
{
#ifndef __MMI_SNDREC_SLIM__
    MMI_BOOL isappend;
#endif
    MMI_BOOL isIncall;
    MMI_BOOL isdelete;
    //MMI_BOOL is_sim_two;
    //MMI_BOOL need_file_prefix;
    MMI_BOOL is_in_app;
    MMI_BOOL is_break;                   //saved when break by other app
#ifdef __MMI_SNDREC_SKIN__
    MMI_BOOL is_timer_on;
    MMI_BOOL isnext;
    MMI_BOOL isplay;
    MMI_BOOL isButtonDown;
#else /* __MMI_SNDREC_SKIN__ */ 
    MMI_BOOL isStartTimer;
#endif /* __MMI_SNDREC_SKIN__ */
#ifdef __MMI_OP02_LEMEI__ 
    MMI_BOOL need_save;
#endif
    MMI_BOOL isEntryFromOther;
    MMI_BOOL isStopBySelf;
    U8  state;
    U8  volume;
    U8  quality; 
    U16 displayname[MMI_SNDREC_FULL_NAME_LEN + 1];
    U32 fmgr_id;
#ifdef __MMI_SNDREC_SKIN__
    S32 rectime;
    S32 remaintime;
    U64 remindsize;
#else /* __MMI_SNDREC_SKIN__ */ 
    U32 rectime;
    U32 lasttime;
    U32 begintime;
    U32 playtime;
    U32 lastplaytime;
    U32 beginplaytime;
#endif /* __MMI_SNDREC_SKIN__ */ 
}mmi_sndrec_record_struct;     /* app memory */

typedef struct
{
    U8  drive_index;
    U8  quality_temp;
    U8  drive;
    U8  quality;
}mmi_sndrec_setting_struct;    /* app memory */

typedef struct
{
    U8 auto_record;
    U8 auto_record_count;
    U8 vm_support;
}mmi_sndrec_auto_rec_struct;   /* app memory */

typedef struct
{
    U16 hour;
    U8  minute;
    U8  second;
}mmi_sndrec_time_struct;            /* temp memory */

typedef struct
{
    mmi_sndrec_record_struct record;
    mmi_sndrec_setting_struct setting;
#ifdef __VM_CODEC_SUPPORT__    
    mmi_sndrec_auto_rec_struct autorec;
#endif
    MMI_ID save_rename_cui_id;
    MMI_ID setting_cui_id;
    MMI_ID rename_cui_id;
    MMI_ID flist_cui_id; 
//    PU8    app_mem_bufer;
}mmi_sndrec_cntx;                


typedef struct
{
    MMI_BOOL show_start_icon;
    PU8      file_path;
    U32      max_file_size;
    U32      max_record_time;
}cui_sndrec_run_struct;             /* static memory for cui of sndrec */

/****************************************************************************
*  in sndrecmsg.h
*****************************************************************************/
/*
 * function for send mdi request
 */
extern MMI_BOOL mmi_sndrec_send_record_req(U16 *file, U8 format, U8 quality);
extern MMI_BOOL mmi_sndrec_send_record_limit_req(U16 *file, U8 format, U8 quality, U32 size_limit, U32 time_limit, U32 flag);
extern MMI_BOOL mmi_sndrec_send_resume_req(U16 endstate);
extern MMI_BOOL mmi_sndrec_send_pause_req(U16 endstate);
extern MMI_BOOL mmi_sndrec_send_play_req(UI_string_type file, void (*end_cb)(MDI_RESULT result));
extern void mmi_sndrec_record_cb_hdlr(MDI_RESULT result, void *user_data);
extern void mmi_sndrec_send_stop_req(MMI_BOOL isrecord);
extern void mmi_sndrec_pause_cb_hdlr(mdi_result result, void *user_data);
extern void mmi_sndrec_resume_cb_hdlr(mdi_result result, void *user_data);
extern void mmi_sndrec_play_cb_hdlr(MDI_RESULT result, void *user_data);

#ifdef __MMI_OP12_SNDREC_STYLE__
extern MMI_BOOL mmi_sndrec_send_preview_req(UI_string_type file, void (*end_cb)(MDI_RESULT result));
#endif

/*
 *  function for other
 */
extern U8   mmi_sndrec_get_record_format(U8 format);
extern MMI_ID mmi_sndrec_error_hdlr(S32 cause, MMI_BOOL isRecord);
extern void mmi_sndrec_bgsound_resume(void);
extern void mmi_sndrec_bgsound_suspend(void);

/*
 *   function for update time
 */
extern void mmi_sndrec_init_time(void);
extern void mmi_sndrec_increase_rectime(void);
#if defined(__MMI_OP02_LEMEI__)
extern void mmi_sndrec_set_app_record_time_limit(U32 time_limit);
extern void mmi_sndrec_set_app_record_size_limit(U32 size_limit);
extern void mmi_sndrec_enable_app_recording_time_left(void);
extern void mmi_sndrec_disable_app_recording_time_left(void);
extern void mmi_sndrec_enable_record_pause(void);
extern void mmi_sndrec_disable_record_pause(void);
extern MMI_BOOL mmi_sndrec_query_is_record_pause_enabled(void);
extern void mmi_sndrec_release_record_btn_other_app(void);
#endif /*__MMI_OP02_LEMEI__ */

#ifdef __MMI_SNDREC_SKIN__
extern S32 mmi_sndrec_get_record_rate(U8 format, U8 quality);
extern void mmi_sndrec_get_record_time_string(UI_string_type string);
extern void mmi_sndrec_get_drive_size(void);
extern void mmi_sndrec_get_play_time_string(UI_string_type string);
extern void mmi_sndrec_transte_time(U32 second, mmi_sndrec_time_struct *time);
#else /* __MMI_SNDREC_SKIN__ */ 
extern U32 mmi_sndrec_get_ticks(void);
extern void mmi_sndrec_start_ticks(void);
extern void mmi_sndrec_update_play_ticks(void);
extern void mmi_sndrec_update_rec_ticks(void);
#endif /* __MMI_SNDREC_SKIN__ */ 


/****************************************************************************
*  in sndrecprot.h
*****************************************************************************/
#ifdef __MMI_SNDREC_SKIN__
void mmi_sndrec_show_main_screen(U16 titleid);
void mmi_sndrec_redraw_skins_animal_img(MMI_BOOL isact);
void mmi_sndrec_redraw_main_lsk(void);
void mmi_sndrec_redraw_main_rsk(void);
void mmi_sndrec_redraw_main_lsk_down(void);
void mmi_sndrec_redraw_main_rsk_down(void);
void mmi_sndrec_redraw_record_btn(MMI_BOOL isdown);
void mmi_sndrec_redraw_play_btn(MMI_BOOL isdown);
void mmi_sndrec_redraw_next_btn(MMI_BOOL isdown);
void mmi_sndrec_redraw_prev_btn(MMI_BOOL isdown);
void mmi_sndrec_redraw_state_text(void);
void mmi_sndrec_pen_down_hdlr(mmi_pen_point_struct pos);
void mmi_sndrec_pen_up_hdlr(mmi_pen_point_struct pos);
void mmi_sndrec_pen_move_hdlr(mmi_pen_point_struct pos);

void mmi_sndrec_mainscr_lsk_up_hdlr(void);
void mmi_sndrec_mainscr_rsk_up_hdlr(void);
void mmi_sndrec_release_record_btn(void);
void mmi_sndrec_release_play_btn(void);
void mmi_sndrec_release_prev_btn(void);
void mmi_sndrec_release_next_btn(void);
void mmi_sndrec_show_time_text(MMI_BOOL isact);
void mmi_sndrec_show_time_text_without_blt(MMI_BOOL isact);
void mmi_sndrec_redraw_file_name(U16* filename);
void mmi_sndrec_exit_draw_screen(void);
void mmi_sndrec_blt_screen(void);
void mmi_sndrec_update_time_text(void);
#else /* __MMI_SNDREC_SKIN__ */
void mmi_sndrec_show_record_screen(void);
#endif /* __MMI_SNDREC_SKIN__ */

MMI_BOOL mmi_sndrec_record_is_on(void);

void mmi_sndrec_record_stop_hdlr(void);
#ifndef __MMI_SNDREC_SLIM__
void mmi_sndrec_append_stop_hdlr(void);
#endif

MMI_BOOL mmi_sndrec_is_idle_state(void);
MMI_BOOL mmi_sndrec_check_file_isnull(void);
MMI_BOOL mmi_sndrec_is_file_exist(void);
BOOL mmi_sndrec_check_usb_mode(void);

S32 mmi_sndrec_reclist_create_callback(SRV_FMGR_FILELIST_HANDLE fl_hdl, S32 result, S32 progress, S32 total);
void mmi_sndrec_reclist_set_callback(MMI_BOOL bret);
void mmi_sndrec_reclist_play_callback(void);

MDI_AUDIO_REC_MODE_ENUM mmi_sndrec_get_rec_type(void);
MDI_FORMAT_ENUM  mmi_sdnrec_append_mdi_format_enum(void);

MMI_BOOL mmi_sndrec_func_allow_incall(void);

#ifdef __MMI_OP12_SNDREC_STYLE__
void mmi_sndrec_highlight_save_option_discard(void);
void mmi_sndrec_highlight_save_option_play(void);
void mmi_sndrec_highlight_save_option_save(void);
void mmi_sndrec_highlight_save_option_rename_save(void);
#endif /* __MMI_OP12_SNDREC_STYLE__ */

#endif /* defined(__MMI_SOUND_RECORDER__) */ 
#endif /* _SNDREC_PROT_H */ 
