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

/*******************************************************************************
 * Filename:
 * ---------
 *   VdoPlyGProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Expose function and variable.
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
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VDOPLYGPROT_H
#define _MMI_VDOPLYGPROT_H

#include "MMI_features.h"

#if defined(__MMI_VIDEO_PLAYER__) 

/***************************************************************************** 
* Include
*****************************************************************************/
/* headers required by this this VdoPlyGrpot.h interface */
#include "mmi_features_video.h"
#include "gdi_include.h"
#include "FileMgr.h"
#include "DLAgentSrvDef.h"
#include "DLAgentSrvGprot.h"
#include "MMIDataType.h"
#include "mmi_res_range_def.h"
#include "common_nvram_editor_data_item.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#define VDOPLY_BUFFER_DEPTH         (2) /* RGB565 = 16 bits */
#ifdef __VDOPLY_FEATURE_SLIM_IMG_RES__
#define VDOPLY_OSD_BUFFER_SIZE      (0)
#elif defined(__VDOPLY_FEATURE_FTE20__)
#if (((LCD_WIDTH == 240) && (LCD_HEIGHT == 320)) || ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240)) || ((LCD_WIDTH == 240) && (LCD_HEIGHT == 400)))
#define VDOPLY_OSD_BUFFER_SIZE		(128*93*VDOPLY_BUFFER_DEPTH)
#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 480))
#define VDOPLY_OSD_BUFFER_SIZE		(160*115*VDOPLY_BUFFER_DEPTH)
#else
#define VDOPLY_OSD_BUFFER_SIZE      (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*VDOPLY_BUFFER_DEPTH)
#endif
#else
#define VDOPLY_OSD_BUFFER_SIZE      (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*VDOPLY_BUFFER_DEPTH*2)
#endif
#define VDOPLY_LAYER_BUFFER_SIZE    (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*VDOPLY_BUFFER_DEPTH)

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER         /* evt_id: event is; user_data: the receiver's user_data */
    /* DOM-NOT_FOR_SDK-END */
	MMI_BOOL with_popup;
    MMI_ID_TYPE error_str_id;                       /* error_string_id */
} cui_vdoply_exit_evt_struct;

typedef enum
{
    EVT_VDOPLY_EXIT_WITH_POPUP = VDOPLY_BASE
}cui_vdoply_event_enum;

typedef enum
{
    CUI_VDOPLY_TYPE_FILE,
	CUI_VDOPLY_TYPE_ID,
	CUI_VDOPLY_TYPE_PDL_FILE,
	CUI_VDOPLY_TYPE_RTSP_FILE,
	CUI_VDOPLY_TYPE_SDP,
	CUI_VDOPLY_TYPE_RAM_FILE,
	CUI_VDOPLY_TYPE_FILE_TOTAL
}cui_vdoply_type_enum;

typedef struct
{
    union{
        CHAR* file_name;
        U16 video_id;
    }video_hdr;
    union{
    CHAR* title_str;
    U16 title_id;
    }video_title;
    MMI_BOOL is_short;
}cui_vdoply_param_struct;


/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_vdoply_init_app(void);

extern void mmi_vdoply_entry_player_screen_from_file(CHAR* filename, MMI_BOOL is_short);
extern void mmi_vdoply_entry_player_screen_from_id(U16 video_id, U16 video_name_id);

extern MMI_ID cui_vdoply_create(mmi_id parent_id, cui_vdoply_type_enum video_type,cui_vdoply_param_struct* param);
extern MMI_ID cui_vdoply_run(mmi_id cid);
extern void cui_vdoply_close(mmi_id cid);


extern void mmi_vdoply_entry_app(void);

/* play video from file manager - will get file manager's selected file */
extern void mmi_vdoply_entry_player_screen(void);
extern void mmi_vdoply_exit_from_fmgr_emptry_folder(void);

/* play video from other app */
extern void mmi_vdoply_entry_player_screen_from_file_ext(CHAR* filename, MMI_BOOL is_short, CHAR* title_str);

/* progressive DL */
extern void mmi_vdoply_entry_player_screen_from_pdl_file(CHAR* filename, MMI_BOOL is_short);
extern void mmi_vdoply_pdl_da_notify_file(
            	S32	session_id,
            	S32	mime_type,                  
            	S32	mime_subtype,  
            	S32 action,            	
            	U32	filesize,
            	CHAR*	url,                        
            	CHAR*	mime_type_string,           
            	U32	content_len,
            	CHAR*	content,
            	srv_da_setting_struct *settings);
    
/* streaming */
extern void mmi_vdoply_entry_player_screen_from_rtsp_link(CHAR* rtsp_url);
extern void mmi_vdoply_entry_player_screen_from_sdp_file(CHAR* sdp_filename, MMI_BOOL is_short);
extern void mmi_vdoply_entry_player_screen_from_sdp_file_ext(CHAR* sdp_filename, MMI_BOOL is_short, CHAR* title_str);
extern void mmi_vdoply_entry_player_screen_from_ram_file(CHAR* ram_filename, MMI_BOOL is_short);
extern void mmi_vdoply_stream_receive_da_file(
                S32 session_id, 
                S32 mime_type, 
                S32 mime_subtype, 
                S32 action, 
                PU16 file_path, 
                CHAR* url, 
                CHAR* mime_type_string);
/* link from wap */
extern void mmi_vdoply_send_rtsp_url_req(CHAR* rtsp_url);

/* init */
extern BOOL mmi_vdoply_is_in_app(void);

/* speical check funciont for lcd sleep */
/* when in video player with tvout enable, when lcd sleep, we will force UI timer stay alive */
#ifdef __MMI_TVOUT__
extern MMI_BOOL mmi_vdoply_is_in_play_and_tvout_enable(void);
#endif 

void mmi_vdoply_get_next_snapshot_filename(CHAR* file_buf, CHAR* file_path);

#ifdef __MMI_VIDEO_STREAM__
/* these interfaces are for mmi streaming OTAP */
extern void mmi_vdoply_set_active_profile(U8 index);
extern MMI_BOOL mmi_vdoply_is_profile_in_use(U8 index);
extern void mmi_vdoply_del_all_app_screen(void);
extern void mmi_vdoply_load_profile(U8 index, nvram_ef_video_network_profile_struct *prof_p);
extern void mmi_vdoply_store_profile(U8 index,nvram_ef_video_network_profile_struct *prof_p);
extern U16 mmi_vdoply_get_cbm_app_id(void);
extern void mmi_vdoply_get_string_id_and_icon_id(U16 *string_id, U16 *icon_id);
extern mmi_ret mmi_vdoply_dtcnt_changed_hdlr(mmi_event_struct* param);
#endif

extern mmi_ret mmi_vdoply_notify_storage_change_evt_hdlr(mmi_event_struct *evt);
extern mmi_ret mmi_vdoply_gpio_after_lcd_leep_in(mmi_event_struct *evt);
extern mmi_ret mmi_vdoply_gpio_clam_open_close_query_tone(mmi_event_struct *evt);
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
extern mmi_ret mmi_vdoply_event_screen_locker_callback_hdlr(mmi_event_struct *event);
#endif

#endif /* __MMI_VIDEO_PLAYER__ */ 

/* storage util, use by other apps, even when video player is not available. */
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) || (defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__))
extern void mmi_vdoply_get_storage_file_path(CHAR* path_buf);
extern S32 mmi_vdoply_create_file_dir(CHAR* filepath);
extern U16 mmi_vdoply_get_storage(void);
extern void mmi_vdoply_set_storage(U16 storage);
extern void mmi_vdoply_load_setting(void);
extern void mmi_vdoply_store_setting(void);
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) || (defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)) */

#endif /* _MMI_VDOPLYGPROT_H */ 

