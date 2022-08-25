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
 *  MobileTVPlayerOSD.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Mobile TV Player OSD
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _MMI_MOBILE_TV_PLAYER_OSD_H_
#define _MMI_MOBILE_TV_PLAYER_OSD_H_

#include "mmi_features.h"
#include "MMIDataType.h"
#include "lcd_sw_inc.h"
#ifdef __MMI_ATV_SUPPORT__

/*******************************************
 * Enumeration
 *******************************************/

typedef enum
{
    MTV_PLAYER_ICON_STATUS_ENABLE = 0,
    MTV_PLAYER_ICON_STATUS_DISABLE = 0x0001,
    MTV_PLAYER_ICON_STATUS_CLICKED = 0x0010
} mtv_player_icon_status_enum;


typedef enum
{
    MTV_PLAYER_PREVIEW_ICON_BROKEN
} mtv_player_preview_icon_enum;

/*******************************************
 * Structure
 *******************************************/

typedef struct
{
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    mtv_player_icon_status_enum status;
} mtv_player_osd_icon_struct;

typedef struct
{
	S32     offset_x;
	S32     offset_y;
	S32     width;
	S32     height;
} mtv_player_osd_text_struct;

typedef struct 
{
    /* osd_text_struct */
    mtv_player_osd_text_struct title;
    mtv_player_osd_text_struct hint_box;
    mtv_player_osd_text_struct channel_number;
    mtv_player_osd_text_struct channel_name;

    /* osd_icon_struct */
    mtv_player_osd_icon_struct volume;
    mtv_player_osd_icon_struct play;
    mtv_player_osd_icon_struct record;
    mtv_player_osd_icon_struct fullscreen;
    mtv_player_osd_icon_struct vol_inc;
    mtv_player_osd_icon_struct vol_dec;
    mtv_player_osd_icon_struct channel_next;
    mtv_player_osd_icon_struct channel_prev;

    mtv_player_osd_icon_struct lsk;
    mtv_player_osd_icon_struct rsk;
#if defined(__MMI_FTE_SUPPORT__)   
    mtv_player_osd_icon_struct vol_bg;
    mtv_player_osd_icon_struct vol_status;
    mtv_player_osd_icon_struct vol_bar;
    mtv_player_osd_icon_struct vol_idx; 
#else /* defined(__MMI_FTE_SUPPORT__)  */
    mtv_player_osd_icon_struct vol_status;
#endif /* defined(__MMI_FTE_SUPPORT__)  */
} mtv_player_layout_struct;


extern mtv_player_layout_struct g_mtv_player_osd_cntx; 
extern mtv_player_layout_struct g_mtv_player_osd_cntx_270;



#if ((LCD_WIDTH == 176) && (LCD_HEIGHT == 220)) /* ATV */

#define MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_X 0
#define MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_Y 0
#define MMI_MTV_PLAYER_DYNAMIC_LABLEL_OFFSET_X (35)
#define MMI_MTV_PLAYER_BG_OFFSET_X (0)
#define MMI_MTV_PLAYER_BG_OFFSET_Y (0)
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_X (2)
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_Y (144)
#define MMI_MTV_PLAYER_LOADING_ICON_Y (70)
#define MMI_MTV_PLAYER_FULL_SCR_LOADING_ICON_Y (100)
#define MMI_MTV_PLAYER_BT_CONNECT_ICON_Y (50)
#define MMI_MTV_PLAYER_FULL_SCR_BT_CONNECT_ICON_Y (100)

/* Display layer */
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_X (0)
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (20)
#define MTV_PLAYER_DISPLAY_LAYER_WIDTH (176)
#define MTV_PLAYER_DISPLAY_LAYER_HEIGHT (132)

/* DLS layer */
#define MTV_PLAYER_DLS_LAYER_OFFSET_X (0)
#define MTV_PLAYER_DLS_LAYER_OFFSET_Y (200)
#define MTV_PLAYER_DLS_LAYER_WIDTH (176)
#define MTV_PLAYER_DLS_LAYER_HEIGHT (27)

#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X (0)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_Y (0)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH (200)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT (27)

#elif ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320)) /* ATV */

#define MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_X 0
#define MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_Y 0
#define MMI_MTV_PLAYER_DYNAMIC_LABLEL_OFFSET_X (35)
#define MMI_MTV_PLAYER_BG_OFFSET_X (0)
#define MMI_MTV_PLAYER_BG_OFFSET_Y (0)
#ifdef __MMI_FTE_SUPPORT__
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_X (50)
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_Y (198)
#else
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_X (7)
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_Y (196)
#endif
#define MMI_MTV_PLAYER_LOADING_ICON_Y (70)
#define MMI_MTV_PLAYER_FULL_SCR_LOADING_ICON_Y (100)
#ifdef __MMI_FTE_SUPPORT
#define MMI_MTV_PLAYER_BT_CONNECT_ICON_Y (70)
#else
#define MMI_MTV_PLAYER_BT_CONNECT_ICON_Y (50)
#endif
#define MMI_MTV_PLAYER_FULL_SCR_BT_CONNECT_ICON_Y (100)

/* Display layer */
#if defined(MT6223P)
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_X (10)
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (22)
#define MTV_PLAYER_DISPLAY_LAYER_WIDTH (220)
#define MTV_PLAYER_DISPLAY_LAYER_HEIGHT (176)
#else /* MT6223P */
#ifndef __MMI_FTE_SUPPORT__
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_X (0)
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (20)
#define MTV_PLAYER_DISPLAY_LAYER_WIDTH (240)
#define MTV_PLAYER_DISPLAY_LAYER_HEIGHT (180)
#else
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_X (12)
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (20)
#define MTV_PLAYER_DISPLAY_LAYER_WIDTH (212)
#define MTV_PLAYER_DISPLAY_LAYER_HEIGHT (159)
#endif

#endif /* MT6223P */


/* DLS layer */
#define MTV_PLAYER_DLS_LAYER_OFFSET_X (0)
#define MTV_PLAYER_DLS_LAYER_OFFSET_Y (200)
#define MTV_PLAYER_DLS_LAYER_WIDTH (240)
#define MTV_PLAYER_DLS_LAYER_HEIGHT (27)

#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X (0)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_Y (0)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH (270)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT (27)

#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240)) /* ATV */
#define MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_X 0
#define MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_Y 0
#define MMI_MTV_PLAYER_DYNAMIC_LABLEL_OFFSET_X (35)
#define MMI_MTV_PLAYER_BG_OFFSET_X (0)
#define MMI_MTV_PLAYER_BG_OFFSET_Y (0)
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_X (30)
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_Y (201)
#define MMI_MTV_PLAYER_LOADING_ICON_Y (70)
#define MMI_MTV_PLAYER_FULL_SCR_LOADING_ICON_Y (100)
#define MMI_MTV_PLAYER_BT_CONNECT_ICON_Y (50)
#define MMI_MTV_PLAYER_FULL_SCR_BT_CONNECT_ICON_Y (100)

#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_X (57)
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (15)
#define MTV_PLAYER_DISPLAY_LAYER_WIDTH (206)
#define MTV_PLAYER_DISPLAY_LAYER_HEIGHT (154)

/* DLS layer */
#define MTV_PLAYER_DLS_LAYER_OFFSET_X (0)
#define MTV_PLAYER_DLS_LAYER_OFFSET_Y (200)
#define MTV_PLAYER_DLS_LAYER_WIDTH (240)
#define MTV_PLAYER_DLS_LAYER_HEIGHT (27)

#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X (0)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_Y (0)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH (320)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT (27)

#elif ((LCD_WIDTH == 240) && (LCD_HEIGHT == 400))  /* ATV */

#define MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_X 0
#define MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_Y 0
#define MMI_MTV_PLAYER_DYNAMIC_LABLEL_OFFSET_X (35)
#define MMI_MTV_PLAYER_BG_OFFSET_X (0)
#define MMI_MTV_PLAYER_BG_OFFSET_Y (0)
#ifdef __MMI_FTE_SUPPORT__
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_X (90)
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_Y (198)
#else
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_X (3)
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_Y (196)
#endif
#define MMI_MTV_PLAYER_LOADING_ICON_Y (60)
#define MMI_MTV_PLAYER_FULL_SCR_LOADING_ICON_Y (105)
#ifdef __MMI_FTE_SUPPORT
#define MMI_MTV_PLAYER_BT_CONNECT_ICON_Y (84)
#else
#define MMI_MTV_PLAYER_BT_CONNECT_ICON_Y (85)
#endif
#define MMI_MTV_PLAYER_FULL_SCR_BT_CONNECT_ICON_Y (105)

/* Display layer */
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_X (0)
#ifdef __MMI_FTE_SUPPORT__
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (28)
#else /* __MMI_FTE_SUPPORT__ */
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (28)
#endif /*__MMI_FTE_SUPPORT__ */

#define MTV_PLAYER_DISPLAY_LAYER_WIDTH (240)
#define MTV_PLAYER_DISPLAY_LAYER_HEIGHT (180)

/* DLS layer */
#define MTV_PLAYER_DLS_LAYER_OFFSET_X (10)
#define MTV_PLAYER_DLS_LAYER_OFFSET_Y (250)
#define MTV_PLAYER_DLS_LAYER_WIDTH (220)
#define MTV_PLAYER_DLS_LAYER_HEIGHT (27)

#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X (5)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_Y (0)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH (345)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT (27)

#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 480))  /* ATV */

#define MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_X 0
#define MMI_MTV_PLAYER_SIGNAL_ICON_OFFSET_Y 0
#define MMI_MTV_PLAYER_DYNAMIC_LABLEL_OFFSET_X (35)
#define MMI_MTV_PLAYER_BG_OFFSET_X (0)
#define MMI_MTV_PLAYER_BG_OFFSET_Y (0)
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_X (82)
#define MMI_MTV_PLAYER_FULL_SCR_BG_OFFSET_Y (263)
#define MMI_MTV_PLAYER_LOADING_ICON_Y (70)
#define MMI_MTV_PLAYER_FULL_SCR_LOADING_ICON_Y (120)
#ifdef __MMI_FTE_SUPPORT__
#define MMI_MTV_PLAYER_BT_CONNECT_ICON_Y    (65) // (85)
#else
#define MMI_MTV_PLAYER_BT_CONNECT_ICON_Y (85)
#endif
#define MMI_MTV_PLAYER_FULL_SCR_BT_CONNECT_ICON_Y (120)

/* Display layer */
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_X (0)
#ifdef __MMI_FTE_SUPPORT__
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (27) //(72)
#else /* __MMI_FTE_SUPPORT__ */
#define MTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (76)
#endif /*__MMI_FTE_SUPPORT__ */

#define MTV_PLAYER_DISPLAY_LAYER_WIDTH (320)
#define MTV_PLAYER_DISPLAY_LAYER_HEIGHT (240)

/* DLS layer */
#define MTV_PLAYER_DLS_LAYER_OFFSET_X (10)
#define MTV_PLAYER_DLS_LAYER_OFFSET_Y (320)
#define MTV_PLAYER_DLS_LAYER_WIDTH (300)
#define MTV_PLAYER_DLS_LAYER_HEIGHT (27)

#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X (5)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_Y (0)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH (425)
#define MTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT (27)

#else /* other LCD size */
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */

#endif /* __MMI_ATV_SUPPORT__ */

#endif /* _MMI_MOBILE_TV_PLAYER_OSD_H_ */
