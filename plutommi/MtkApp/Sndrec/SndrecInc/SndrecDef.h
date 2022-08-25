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
 * SndrecDef.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SOUND_RECORDER_DEF_H
#define SOUND_RECORDER_DEF_H
#include "MMI_features.h"
#if defined(__MMI_SOUND_RECORDER__)
#include "SndrecDef.h"
#include "FileMgrSrvGProt.h"
#include "MMIDataType.h"

#if defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)|| defined(__MMI_MAINLCD_320X240__))
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        #define MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    #endif
#endif

#define MMI_SNDREC_MAIN_SAVE_OPTION_ITEM     9
#define MMI_SNDREC_MAIN_OPTION_ITEM     9
#define MMI_SNDREC_REC_OPTION_ITEM      7

#define MMI_SNDREC_FILE_LEN         (SRV_FMGR_PATH_MAX_FILE_NAME_LEN)
#define MMI_SNDREC_PATH_LEN         10
#define MMI_SNDREC_FULL_NAME_LEN    MMI_SNDREC_FILE_LEN + MMI_SNDREC_PATH_LEN
#define MMI_SNDREC_EXT_NAME_SIZE    SRV_FMGR_PATH_MAX_FILE_EXT_LEN
#define MMI_SNDREC_SET_ITEM         6
#define MMI_SNDREC_MAX_REC_DELAY    3000
#define MMI_SNDREC_INPUT_FILE_LEN  35  /* max file length for user to input */
#define MMI_SNDREC_HOURS_DISPLAY_LIMIT 3600000

#define MMI_SNDREC_DEFAULT_PATH     L":\\Audio\\"
#define MMI_SNDREC_NAME_AMR         L".amr"
#define MMI_SNDREC_NAME_AWB         L".awb"
#define MMI_SNDREC_NAME_WAV         L".wav"
#define MMI_SNDREC_NAME_VM          L".vm"
#define MMI_SNDREC_NAME_ELV         L".evl"
#define MMI_SNDREC_NAME_OGG         L".ogg"


/*add sim mark in file name*/
#define MMI_SNDREC_SIM_ONE_CAPTION (L"SIM1_")
#define MMI_SNDREC_SIM_TWO_CAPTION (L"SIM2_")

typedef enum
{
    SNDREC_MAIN_REC = 0,
    SNDREC_MAIN_PLAY,
    SNDREC_MAIN_PREV,
    SNDREC_MAIN_NEXT
}mmi_sndrec_buttons_enum;

typedef enum
{
    MMI_SNDREC_IDLE_STATE,
    MMI_SNDREC_REC_STATE,
    MMI_SNDREC_PLAY_STATE,
    MMI_SNDREC_REC_PAUSE_STATE,
    MMI_SNDREC_PLAY_PAUSE_STATE,
    MMI_SNDREC_PREVIEW_STATE,
    MMI_SNDREC_PREVIEW_PAUSE_STATE,
    MMI_SNDREC_TOTAL_STATE
}mmi_sndrec_state_enum;
/*
typedef enum
{
#ifndef MT6205B
    MMI_SNDREC_TYPE_AMR,
    MMI_SNDREC_TYPE_WAV,
#endif 
#if defined(AMRWB_ENCODE) && defined(AMRWB_DECODE)
    MMI_SNDREC_TYPE_AWB,
#endif 
    MMI_SNDREC_TYPE_VM,
    MMI_SNDREC_TYPE_TOTAL
}mmi_sndrec_type_enum;

enum
{
    MMI_SNDREC_QUALITY_LOW,
    MMI_SNDREC_QUALITY_HIGH,
    MMI_SNDREC_QUALITY_TOTAL
};
*/
typedef enum
{
    MMI_SNDREC_CALL_TYPE_NULL,      /* No call */
    MMI_SNDREC_CALL_TYPE_NORMAL,
    MMI_SNDREC_CALL_TYPE_VOIP,      /* VOIP call */
    MMI_SNDREC_CALL_TYPE_TOTAL
}mmi_sndrec_call_type_enum;

#ifdef __MMI_SNDREC_SKIN__

#ifdef __MMI_TOUCH_SCREEN__
typedef struct
{
    S16 x;
    S16 y;
} mmi_sndrec_point_struct;

typedef struct
{
    const mmi_sndrec_point_struct *points;
    S16 num;
} mmi_sndrec_polygon_area_struct;
#endif /* __MMI_TOUCH_SCREEN__ */ 
#ifdef __MMI_FTE_SUPPORT__
/* FTE Changes
    - Remove Background image, change to use submenu’s background(Apply in all FTE Project)
    - Remove images of disabled status, change to 50% transparency(Apply in all FTE Project)
    - Remove unused images(cross), new design no need(Apply in all FTE Project)
*/
typedef struct
{
    /* Background Image */ 
    //U16 bg_img_id;

    /* LSK */
    U16 lsk_img_id;
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    U16 lsk_img_down_id;
#endif
    //U16 lsk_dis_img_id;
    S16 lsk_img_x, lsk_img_y;

    /* RSK */
    U16 rsk_img_id;
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    U16 rsk_img_down_id;
#endif
    //U16 rsk_dis_img_id;
    S16 rsk_img_x, rsk_img_y;

    /* Title */	
    U8 title_text_color_r, title_text_color_g, title_text_color_b;
    U8 title_text_border_color_r, title_text_border_color_g, title_text_border_color_b;
    S16 title_x, title_y, title_w, title_h;	

    /* State */    
   /*  U8 state_text_color_r, state_text_color_g, state_text_color_b;
    U8 state_text_border_color_r, state_text_border_color_g, state_text_border_color_b;
    S16 state_x, state_y, state_w, state_h;*/

    /* Name */
    U8 name_text_color_r, name_text_color_g, name_text_color_b;
    U8 name_text_border_color_r, name_text_border_color_g, name_text_border_color_b;
    S16 filename_x, filename_y, filename_w, filename_h;

    /* Time */	    
    U8 time_text_color_r, time_text_color_g, time_text_color_b;
    U8 time_text_border_color_r, time_text_border_color_g, time_text_border_color_b;    
    S16 time_x, time_y, time_w, time_h;

    /* ANIMATION IMG*/
    S16 animal_img_x, animal_img_y;
    U16 animal_img_id;

    /* REC Button */
    S16 record_btn_x, record_btn_y;
    U16 record_btn_up_id;
    U16 record_pause_btn_up_id;
    //U16 record_btn_disable_id;
#if defined(__MMI_OP02_LEMEI__)
    U16 record_pause_btn_disable_id;
#endif

    /* PLAY Button */
    S16 play_btn_x, play_btn_y;
    U16 play_btn_up_id;
    U16 play_pause_btn_up_id;
    //U16 play_btn_diable_id;

    /* PREV Button */
    S16 prev_btn_x, prev_btn_y;
    U16 prev_btn_up_id;
    //U16 prev_btn_disable_id;

    /* NEXT Button */
    S16 next_btn_x, next_btn_y;
    U16 next_btn_up_id;
    //U16 next_btn_disable_id;    

    /* Hilight Image */
    U16 highlight_img_id;

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    /* LIST Button */
    S16 list_btn_x, list_btn_y;
    U16 list_btn_up_id;
    //U16 list_btn_disable_id;
#endif

    /* STOP Button */
    S16 stop_btn_x, stop_btn_y;
    U16 stop_btn_up_id;
    //U16 stop_btn_disable_id;  

    /* REC Sign */
    S16 rec_icon_x, rec_icon_y;
    U16 rec_icon_id;
    U16 rec_pause_icon_id;  

    /* LINE */
#ifdef __MMI_FTE_SUPPORT_SLIM__
    S16 line_img_x, line_img_y;
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    S16 line_img_w, line_img_h;
#endif
    U16 line_img_id;
#endif    

    /* CROSS*/
/*#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
#ifdef __MMI_FTE_SUPPORT_SLIM__
    S16 cross_img_x, cross_img_y;
    U16 cross_img_id;
#endif
#endif */

#if 0 //def __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__ */

#ifdef __MMI_TOUCH_SCREEN__
    mmi_sndrec_polygon_area_struct record_btn_area;
    mmi_sndrec_polygon_area_struct play_btn_area;
    mmi_sndrec_polygon_area_struct prev_btn_area;
    mmi_sndrec_polygon_area_struct next_btn_area;
    mmi_sndrec_polygon_area_struct list_btn_area;
    mmi_sndrec_polygon_area_struct stop_btn_area;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    U8 up_key_map, down_key_map, left_key_map, right_key_map;
}mmi_sndrec_draw_skin_struct;

#else/*__MMI_FTE_SUPPORT__*/

typedef struct
{

	U16 bg_img_id;
	/*LSK*/
	U8 lsk_text_color_r, lsk_text_color_g, lsk_text_color_b;
    U8 lsk_text_border_color_r, lsk_text_border_color_g, lsk_text_border_color_b;
	/*RSK*/
	U8 rsk_text_color_r, rsk_text_color_g, rsk_text_color_b;
    U8 rsk_text_border_color_r, rsk_text_border_color_g, rsk_text_border_color_b;
	/* Title */	
    U8 title_text_color_r, title_text_color_g, title_text_color_b;
    U8 title_text_border_color_r, title_text_border_color_g, title_text_border_color_b;
	S16 title_x, title_y, title_w, title_h;	
	/* State */    
    U8 state_text_color_r, state_text_color_g, state_text_color_b;
    U8 state_text_border_color_r, state_text_border_color_g, state_text_border_color_b;
	S16 state_x, state_y, state_w, state_h;
	/* Name */
	U8 name_text_color_r, name_text_color_g, name_text_color_b;
    U8 name_text_border_color_r, name_text_border_color_g, name_text_border_color_b;
	S16 filename_x, filename_y, filename_w, filename_h;
	/* Time */	    
    U8 time_text_color_r, time_text_color_g, time_text_color_b;
    U8 time_text_border_color_r, time_text_border_color_g, time_text_border_color_b;    
    S16 time_x, time_y, time_w, time_h;

	S16 animal_img_x, animal_img_y;
    U16 animal_img_id;
    
	S16 record_btn_x, record_btn_y;
    U16 record_btn_up_id;
    U16 record_btn_down_id;
    U16 record_pause_btn_up_id;
    U16 record_pause_btn_down_id;
    U16 record_btn_disable_id;
    
    U16 stop_btn_up_id;
    U16 stop_btn_down_id;
    
    S16 play_btn_x, play_btn_y;
    U16 play_btn_up_id;
    U16 play_btn_down_id;
    U16 play_pause_btn_up_id;
    U16 play_pause_btn_down_id;
    U16 play_btn_diable_id;
    
    S16 prev_btn_x, prev_btn_y;
    U16 prev_btn_up_id;
    U16 prev_btn_down_id;
    U16 prev_btn_disable_id;
    
    S16 next_btn_x, next_btn_y;
    U16 next_btn_up_id;
    U16 next_btn_down_id;
    U16 next_btn_disable_id;    

    S16 list_btn_x, list_btn_y;
    U16 list_btn_up_id;
    U16 list_btn_down_id;
    U16 list_btn_disable_id;    

    #ifdef __MMI_TOUCH_SCREEN__
        mmi_sndrec_polygon_area_struct record_btn_area;
        mmi_sndrec_polygon_area_struct play_btn_area;
        mmi_sndrec_polygon_area_struct prev_btn_area;
        mmi_sndrec_polygon_area_struct next_btn_area;
        mmi_sndrec_polygon_area_struct list_btn_area;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    U8 up_key_map, down_key_map, left_key_map, right_key_map;
}mmi_sndrec_draw_skin_struct;
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_SNDREC_SKIN__ */

#endif /* (defined(__MMI_SOUND_RECORDER__) ) */ 
#endif /* SOUND_RECORDER_DEF_H */ 

