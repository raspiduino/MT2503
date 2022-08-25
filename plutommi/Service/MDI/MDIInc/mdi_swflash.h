/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *  mdi_swflash.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SW Flash interfce header file
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

#ifndef _MDI_SWFLASH_H
#define _MDI_SWFLASH_H

#ifndef _MDI_DATATYPE_H_
#error "Please include mdi_datatype.h before mdi_swflash.h"
#endif 

#include "mmi_frm_gprot.h"
#include "custom_events_notify.h"
#ifdef SWFLASH_NEOMTEL


#include "sscStringhandle.h"
#include "Fat_fs.h"
#include "filemgr.h"

/* Maximum string length of swflash detail info every field, eg. title/company/size/date/time  */
#define MMI_SWFLASH_MAX_STR_LEN (FMGR_MAX_FILE_LEN + 1) *ENCODING_LENGTH

/* Maximum swflash file size */
#define MMI_SWFLASH_MAX_FILE_DATA_BUFFER_SIZE (301*1024)

#if (defined(__MMI_MOTION_DIAL__) || defined(__MMI_MOTION_MAINMENU__))
    #if defined(__MMI_MAINLCD_320X480__)
	/* Memory size used by swflash engine */
        #define MMI_SWFLASH_MEM_BUFFER_SIZE (4700*1024)
    #elif defined(__MMI_MAINLCD_240X400__)
	/* Memory size used by swflash engine */
        #define MMI_SWFLASH_MEM_BUFFER_SIZE (4500*1024)
    #elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
	/* Memory size used by swflash engine */
        #define MMI_SWFLASH_MEM_BUFFER_SIZE (2517*1024)
    #else
	/* Memory size used by swflash engine */
        #define MMI_SWFLASH_MEM_BUFFER_SIZE (1500*1024)
    #endif
#else
/* Memory size used by swflash engine */
#define MMI_SWFLASH_MEM_BUFFER_SIZE (600*1024)
#endif

/* Recommended performance value needed by swflash engine */
#define MMI_SWFLASH_PERFORMANCE 300

/* Play mode used to decide if need play sound ,  
including two categories: player(with sound) and screen(without sound) */
#define VIS_PLAYER 0x01

/* Play mode used to decide if need play sound ,  
including two categories: player(with sound) and screen(without sound) */
#define VIS_SCREEN 0x20

/*****************************************************************************
* <GROUP  CallBackFunctions>		
*
 * FUNCTION
 *    play_result_callback
 * DESCRIPTION
 *  SWflash engine will call this process function when play finished
 * PARAMETERS
 *  result :  [IN]  Play status enum from vis engine.
 * RETURNS
 *  void.
 *****************************************************************************/
typedef void (*play_result_callback) (MDI_RESULT);

/*****************************************************************************
* <GROUP  CallBackFunctions>		
*
 * FUNCTION
 *    mdi_swflash_predraw
 * DESCRIPTION
 *  Draw callback handler before swflash engine updates frame. 
 * PARAMETERS
 *  offset_x :  [IN]  Layer offset x.
 *  offset_y :  [IN]  Layer offset y.
 *  width :  [IN]  Blt width.
 *  height :  [IN]  Blt height.

 * RETURNS
 *  void.
 *****************************************************************************/
typedef void (*mdi_swflash_predraw)(S32 offset_x, S32 offset_y, S32 width, S32 height) ;

/*****************************************************************************
* <GROUP  CallBackFunctions>		
*
 * FUNCTION
 *    mdi_swflash_postdraw
 * DESCRIPTION
 *  Draw callback handler  after swflash engine updates frame. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mdi_swflash_postdraw)(void);


/* Play state enum, used by swflash player  to set corresponding LSK/RSK text and key handler */
typedef enum
{
    MDI_SWFLASH_PL_STATE_NULL, /*Default state */
    MDI_SWFLASH_PL_STATE_READY, /*Idle state */
    MDI_SWFLASH_PL_STATE_PLAY, /*Play state */
    MDI_SWFLASH_PL_STATE_PAUSE /*Pause state */
} mdi_swflash_pl_state_enum;

/* Play end result enum */
typedef enum
{
    MDI_SWFLASH_PL_RES_END_OF_FILE, /*Play end state */
    MDI_SWFLASH_PL_RES_DRM_END, /*Play end state, currently not used */
    MDI_SWFLASH_PL_RES_LOOP /*Play loop state, currently not used */
} mdi_swflash_pl_res_enum;

/* Play purpose enum for two different usages */
typedef enum
{
    MDI_SWFLASH_PURPOSE_PLAYER,        /* Default purpose: SWFlash player */
    MDI_SWFLASH_PURPOSE_MOTION_STYLE,  /* Motion purpose: for motion dial and motion main menu */
    MDI_SWFLASH_PURPOSE_TOTAL
} mdi_swflash_play_purpose;

/* Initiallized parameters needed by motion dial and motion main menu*/
typedef struct
{
	int num_of_para;                /* Number of parameter */
	char **para;                    /* Parameter between motion style categories and SWFlash engine, which is set depending on each category */
    void (*callbackfunction)(void); /* Callback function for SWFlash engine (if needed) */
    
} mdi_swflash_para;

/* Mdi swflash context structure */
typedef struct
{
    /* swflash AP */
    gdi_handle swflash_layer_handle; /*Layer handle*/        
    S32 layer_width;  /*Layer width */    
    S32 layer_height;  /*Layer height */    
    S32 layer_offsetx;  /*Layer offset x */    
    S32 layer_offsety;  /*Layer offset y */    
    
    FS_HANDLE fd;                           /*File handle*/
    void * instance;                        /*Vis engine instance handle*/
    U8 *decipher_buffer;                    /*Point to the decipher data*/
    U8 *decode_buffer;                      /*Buffer of decoded data*/
    U8 *back_buffer;                        /*Backup buffer mem*/
    U32 playmode;                           /*Play mode, see also VIS_PLAYER, VIS_SCREEN*/
    mdi_swflash_pl_state_enum state;                               /*Play state*/
    
    kal_uint8 *mem_ptr; /*Memory pointer needed by swflash engine*/
    U32 size; /*Content size, includes resource and file type*/
    S32 error;                              /*Error info from engine*/

    MMI_BOOL is_loop;                       /*Indicate if need play looply*/
    MMI_BOOL is_fromplayer;                          /* Indicate if enter from swflash player */
    MMI_BOOL is_first_frame;                /*Indicate if need just play the first frame*/
    MMI_BOOL is_ready_update;               /*Indicate if decode ready*/
   
    U8 imei[16]; /* Imei string for encrypt and decipher */
    play_result_callback play_result; /* Callback function pointer for play result */
    mdi_swflash_predraw  pre_blt; /* Callback function pointer for pre draw */
    mdi_swflash_postdraw post_blt; /* Callback function pointer for post draw */

    mdi_swflash_para *para_ptr;             /* Parameter between category and SWFlash engine */
    S32 play_purpose;                        /* Play purpose, see also  mdi_swflash_play_purpose */
} mdi_swflash_context_struct;


 /*File  info*/
typedef struct
{
    S8 title[MMI_SWFLASH_MAX_STR_LEN]; /* Title string */
    S8 company[MMI_SWFLASH_MAX_STR_LEN]; /* Company string */
    S8 date[MMI_SWFLASH_MAX_STR_LEN]; /* Content release date string */
    S8 time[MMI_SWFLASH_MAX_STR_LEN]; /* Content release time string */
    S32 size; /*Content size*/
    U16 type; /*Content category, eg. animation,karaok, game etc*/
    S16 width; /*Content width */
    S16 height; /*Content height */
} mdi_swflash_info_struct;                 
#endif

/*****************************************************************************
 * FUNCTION
 *    mdi_swflash_open_file
 * DESCRIPTION
 *  To open swflash file , and decrypt to get content and category type. 
 * PARAMETERS
 *  filename 		:  [IN]    File name string.
 *  playmode 		:  [IN]    Used to diff swflash player and swflash category
 *  info 			:  [OUT]  To get swflash information.
 * RETURN VALUES
 *  MDI_RES_SWFLASH_SUCCEED: Open success
 *  MDI_RES_SWFLASH_ERR_OPEN_FILE : File open failed
 *  MDI_RES_SWFLASH_ERR_GET_FILE_SIZE : Get file size failed
 *  MDI_RES_SWFLASH_ERR_WRONG_FILE_SIZE: File size too large (> MMI_SWFLASH_MAX_FILE_DATA_BUFFER_SIZE)
 *  MDI_RES_SWFLASH_ERR_DECIPHER: SWflash file decrypt failed
 *  MDI_RES_SWFLASH_ERR_FAILED: Other failure

 *****************************************************************************/
extern MDI_RESULT mdi_swflash_open_file(const S8 *filename, U32 playmode, mdi_swflash_info_struct *info);

/*****************************************************************************
 * FUNCTION
 *    mdi_swflash_close_file
 * DESCRIPTION
 *  To close swflash file , and release all memory resource. 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_SWFLASH_SUCCEED: Close success
 *  MDI_RES_SWFLASH_ERR_FAILED: Close failed

 *****************************************************************************/
extern MDI_RESULT mdi_swflash_close_file(void);

/*****************************************************************************
 * FUNCTION
 *    mdi_swflash_open_id
 * DESCRIPTION
 *  To open swflash resource , and get content and category type information. 
 * PARAMETERS
 *  id 			:  [IN]  SWflash resource id.
 *  playmode 		:  [IN]  Used to diff swflash player and swflash category
 *  info 			:  [OUT] To get swflash information.
 * RETURN VALUES
 *  MDI_RES_SWFLASH_SUCCEED: Open success
 *  MDI_RES_SWFLASH_ERR_FAILED: Open failed

 *****************************************************************************/
extern MDI_RESULT mdi_swflash_open_id(U16 id, U32 playmode, mdi_swflash_info_struct *info);

/*****************************************************************************
 * FUNCTION
 *    mdi_swflash_close_file
 * DESCRIPTION
 *  To release all resource. 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_SWFLASH_SUCCEED: Close success
 *  MDI_RES_SWFLASH_ERR_FAILED: Close failed

 *****************************************************************************/
extern MDI_RESULT mdi_swflash_close_id(void);

/*****************************************************************************
 * FUNCTION
 *    mdi_swflash_play
 * DESCRIPTION
 *  To play swflash file. 
 * PARAMETERS
 *  layer_handle 		:  [IN]  Swflash update frame layer handle.
 *  repeat_count 		:  [IN]  Repreat times, 0 means loop.
 *  audio_path 		:  [IN]  To set audio path device.
 *  play_result_hdlr		:  [IN]  To register play result callback function.
 * RETURN VALUES
 *  MDI_RES_SWFLASH_SUCCEED: SWflash file play success.
 *  MDI_RES_SWFLASH_ERR_FILE_ERROR: SWflash file is not valid file.
 *  MDI_RES_SWFLASH_ERR_CREATE_INSTANCE: SWflash engine create instance failed.
 *  MDI_RES_SWFLASH_ERR_LOAD: SWflash engine load content failed.
 *****************************************************************************/
extern MDI_RESULT mdi_swflash_play(gdi_handle layer_handle,
                                   U16 repeat_count, U8 audio_path, play_result_callback play_result_hdlr);

/*****************************************************************************
 * FUNCTION
 *    mdi_swflash_stop
 * DESCRIPTION
 *  To stop swflash. 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_SWFLASH_SUCCEED: Success
 *  MDI_RES_SWFLASH_ERR_FAILED:  Fail

 *****************************************************************************/
extern MDI_RESULT mdi_swflash_stop(void);

/*****************************************************************************
 * FUNCTION
 *    mdi_swflash_pause
 * DESCRIPTION
 *  To pause swflash. 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_SWFLASH_SUCCEED:  Success
 *  MDI_RES_SWFLASH_ERR_FAILED:  Fail
 *****************************************************************************/
extern MDI_RESULT mdi_swflash_pause(void);

/*****************************************************************************
 * FUNCTION
 *    mdi_swflash_resume
 * DESCRIPTION
 *  To resume swflash. 
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_SWFLASH_SUCCEED:  Success
 *  MDI_RES_SWFLASH_ERR_FAILED:  Fail
 *****************************************************************************/
extern MDI_RESULT mdi_swflash_resume(void);


/*****************************************************************************
* FUNCTION
*    mdi_swflash_check_download_file
* DESCRIPTION
*    Start download the swflash file from server
* PARAMETERS
*  descriptor_filename 		:    [IN]          SWflash download descriptor  filename 
*  total_len 				:    [OUT]       Total size
*  current_len 			:    [OUT]       Current downloaded size
*  category 				:    [OUT]       The category of works
* RETURN VALUE LIST
*  MDI_RES_SWFLASH_SUCCEED					:  Success
*  MDI_RES_SWFLASH_ERR_WRONG_FILE_SIZE   	:  File size too large (> MMI_SWFLASH_MAX_FILE_DATA_BUFFER_SIZE)
*  MDI_RES_SWFLASH_ERR_READ_FILE 		   	:  File read error.
*  MDI_RES_SWFLASH_ERR_READ_FILE_PARTIAL  	:  File size not matched with readed size.
*  MDI_RES_SWFLASH_ERR_OPEN_FILE			:  File open failed.
*****************************************************************************/
extern MDI_RESULT mdi_swflash_check_download_file(
                    U16 *descriptor_filename,
                    U32 *total_len,
                    U32 *current_len,
                    U32 *category);

/*****************************************************************************
* FUNCTION
*  mdi_swflash_key_down_event
* DESCRIPTION
* Transfer key_down_event to swflash engine.
* PARAMETERS
*  key :     [IN]   Keycode.     
* RETURN VALUE LIST
*  MDI_RES_SWFLASH_SUCCEED:  Success
*****************************************************************************/
extern MDI_RESULT mdi_swflash_key_down_event(kal_uint16 key);

/*****************************************************************************
* FUNCTION
*  mdi_swflash_key_up_event
* DESCRIPTION
* Transfer key_up_event to swflash engine.
* PARAMETERS
*  key :     [IN]   Keycode.     
* RETURN VALUE LIST
*  MDI_RES_SWFLASH_SUCCEED:  Success
*****************************************************************************/
extern MDI_RESULT mdi_swflash_key_up_event(kal_uint16 key);

#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
* FUNCTION
*  mdi_swflash_pen_down_event
* DESCRIPTION
*  Transfer pen_down_event to swflash engine.
* PARAMETERS
*  pos :     [IN]   Pen point position.     
* RETURN VALUE LIST
*  MMI_TRUE:  Pen event translate success.
*  MMI_FALSE: Invalid pen point
*****************************************************************************/
extern MMI_BOOL  mdi_swflash_pen_down_event(mmi_pen_point_struct pos);

/*****************************************************************************
* FUNCTION
*  mdi_swflash_pen_up_event
* DESCRIPTION
*  Transfer pen_up_event to swflash engine.
* PARAMETERS
*  pos :     [IN]   Pen point position.     
* RETURN VALUE LIST
*  MMI_TRUE:  Pen event translate success.
*  MMI_FALSE: Invalid pen point
*****************************************************************************/
extern MMI_BOOL mdi_swflash_pen_up_event(mmi_pen_point_struct pos);

/*****************************************************************************
* FUNCTION
*  mdi_swflash_pen_move_event
* DESCRIPTION
*  Transfer pen_move_event to swflash engine.
* PARAMETERS
*  pos :     [IN]   Pen point position.     
* RETURN VALUE LIST
*  MMI_TRUE:  Pen event translate success.
*  MMI_FALSE: Invalid pen point
*****************************************************************************/
extern MMI_BOOL mdi_swflash_pen_move_event(mmi_pen_point_struct pos);
#endif

/*****************************************************************************
* FUNCTION
*  mdi_swflash_init
* DESCRIPTION
*  To initialize mdi swflash context.
* PARAMETERS
*  void     
* RETURNS
*  void
*****************************************************************************/
void mdi_swflash_init(void);

/*****************************************************************************
* FUNCTION
*  mdi_swflash_set_imei
* DESCRIPTION
*  To store imei string to mdi swflash context.
* PARAMETERS
*  imei: [IN] Imei string pointer     
* RETURNS
*  void
*****************************************************************************/
void mdi_swflash_set_imei(U8 *imei);

/*****************************************************************************
* FUNCTION
*  mdi_swflash_on_end
* DESCRIPTION
*  Callback for play end
* PARAMETERS
*  void
* RETURNS          
*  void
*****************************************************************************/
void mdi_swflash_on_end(void);

/*****************************************************************************
* FUNCTION
*  mdi_swflash_set_is_from_player
* DESCRIPTION
*  To set if it's from player
* PARAMETERS
*  from_player : [IN] Flag if is from player.
* RETURNS          
*  void
*****************************************************************************/
void mdi_swflash_set_is_from_player(MMI_BOOL from_player);

/*****************************************************************************
* FUNCTION
*  mdi_swflash_transform_info
* DESCRIPTION
*  To get swflash content information, eg title/company/size/date etc.
* PARAMETERS
*  str : [OUT] Print string pointer
* RETURN VALUE LIST
*  MDI_RES_SWFLASH_SUCCEED				: SWflash file play success.
*  MDI_RES_SWFLASH_ERR_FILE_ERROR		: SWflash file is not valid file.
*  MDI_RES_SWFLASH_ERR_CREATE_INSTANCE: SWflash engine create instance failed.
*  MDI_RES_SWFLASH_ERR_LOAD			: SWflash engine load content failed.
*****************************************************************************/
MDI_RESULT mdi_swflash_transform_info(S8 *str);

/*****************************************************************************
* FUNCTION
*  mdi_swflash_register_blt_callback
* DESCRIPTION
*  To register the pre and post draw function
* PARAMETERS
*  pre_blt_callback 	: [IN] Pre blt function
*  post_blt_callback 	: [IN] Post blt function
* RETURNS          
*  void
*****************************************************************************/
void mdi_swflash_register_blt_callback(
        mdi_swflash_predraw pre_blt_callback, 
        mdi_swflash_postdraw post_blt_callback);


/*****************************************************************************
* FUNCTION
*  mdi_swflash_init_data
* DESCRIPTION
*  To initialize swflash data for wgui category usage
* PARAMETERS
*  data_ptr : [IN] Initialize data
* RETURNS          
*  void
*****************************************************************************/
extern void mdi_swflash_init_data(mdi_swflash_para* data_ptr);

/*****************************************************************************
* FUNCTION
*  mdi_swflash_change_play_mode
* DESCRIPTION
*  SWFlash default mode is player.
*  This function is to change mode according to user definition.
* PARAMETERS
*  play_purpose :       [IN]     Play purpose, refer to mdi_swflash_play_purpose enum        
* RETURNS
*  void  
*****************************************************************************/
extern void mdi_swflash_change_play_purpose(S32 play_purpose);

/*****************************************************************************
* FUNCTION
*  mdi_swflash_get_play_purpose
* DESCRIPTION
*  Get swflash player purpose
* PARAMETERS
*  void       
* RETURNS
*  Play purpose enum
* SEE ALSO
*  mdi_swflash_play_purpose enum
*****************************************************************************/
extern S32 mdi_swflash_get_play_purpose(void);

/*****************************************************************************
* FUNCTION
*  mdi_swflash_get_mdi_error_info
* DESCRIPTION
*  Get error code and string id for popup usage
* PARAMETERS
*  error_code		: [IN]    Error code
*  type_p 		: [OUT] Error type
* RETURNS
*  String id for this error.
*****************************************************************************/
extern MMI_ID_TYPE mdi_swflash_get_mdi_error_info(MDI_RESULT error_code, mmi_event_notify_enum* type_p);

#endif /* _MDI_SWFLASH_H */ 

