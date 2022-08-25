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
 *  DTVPlayerOSD.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files
*****************************************************************************/
#ifndef _MMI_DTV_PLAYER_OSD_H_
#define _MMI_DTV_PLAYER_OSD_H_

#include "mmi_features.h"
#include "MMIDataType.h"
#include "lcd_sw_inc.h"
#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__

/*******************************************
 * Enumeration
 *******************************************/

typedef enum
{
    DTV_PLAYER_ICON_STATUS_ENABLE = 0,
    DTV_PLAYER_ICON_STATUS_DISABLE = 0x0001,
    DTV_PLAYER_ICON_STATUS_CLICKED = 0x0010
} dtv_player_icon_status_enum;


typedef enum
{
    DTV_PLAYER_PREVIEW_ICON_BROKEN,
    DTV_PLAYER_PREVIEW_ICON_ACCESS_DENIED
} dtv_player_preview_icon_enum;

/*******************************************
 * Structure
 *******************************************/

typedef struct
{
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    dtv_player_icon_status_enum status;
} dtv_player_osd_icon_struct;

typedef struct
{
	U8		r;
	U8		g;
	U8		b;
	U8		style_r;
	U8		style_g;
	U8		style_b;
	U16	    style;
} dtv_player_style_text_struct;

typedef struct
{
	S32     offset_x;
	S32     offset_y;
	S32     width;
	S32     height;
} dtv_player_osd_text_struct;

typedef struct
{
    /* osd_text_struct */
    dtv_player_osd_text_struct title;
    dtv_player_osd_text_struct hint_box;

    dtv_player_osd_text_struct subject;
    dtv_player_osd_text_struct prev_channel_name;
    dtv_player_osd_text_struct cur_channel_name;
    dtv_player_osd_text_struct next_channel_name;

    dtv_player_osd_icon_struct change;
    dtv_player_osd_icon_struct channel_box;

    /* osd_icon_struct */
    dtv_player_osd_icon_struct volume;
    dtv_player_osd_icon_struct play;
    dtv_player_osd_icon_struct record;
    dtv_player_osd_icon_struct cycle;
    dtv_player_osd_icon_struct fullscreen;
    dtv_player_osd_icon_struct forward;
    dtv_player_osd_icon_struct rewind;
    dtv_player_osd_icon_struct vol_inc;
    dtv_player_osd_icon_struct vol_dec;
    dtv_player_osd_icon_struct channel_next;
    dtv_player_osd_icon_struct channel_prev;

    dtv_player_osd_icon_struct ts_ind;
    dtv_player_osd_icon_struct ts_bar;
    dtv_player_osd_icon_struct lsk;
    dtv_player_osd_icon_struct rsk;
    dtv_player_osd_icon_struct vol_status;
    dtv_player_osd_icon_struct view;
} dtv_player_layout_struct;


extern dtv_player_layout_struct g_dtv_player_osd_cntx;
extern dtv_player_layout_struct g_dtv_player_osd_cntx_270;


/******************************************************************************
 *    CMMB OSD
 ******************************************************************************/

#if ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320)) /* CMMB */

/* Display layer */
#ifdef __MMI_FTE_SUPPORT__
#define DTV_PLAYER_DISPLAY_LAYER_OFFSET_X (24)
#define DTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (55)
#define DTV_PLAYER_DISPLAY_LAYER_WIDTH (192)
#define DTV_PLAYER_DISPLAY_LAYER_HEIGHT (144)
#else /* __MMI_FTE_SUPPORT__ */
#define DTV_PLAYER_DISPLAY_LAYER_OFFSET_X (16)
#define DTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (56)
#define DTV_PLAYER_DISPLAY_LAYER_WIDTH (210)
#define DTV_PLAYER_DISPLAY_LAYER_HEIGHT (158)
#endif /* __MMI_FTE_SUPPORT__ */
#define MMI_DTV_PLAYER_FULL_SCR_BG_OFFSET_X (4)
#define MMI_DTV_PLAYER_FULL_SCR_BG_OFFSET_Y (153)

#define MMI_DTV_PLAYER_SIGNAL_ICON_OFFSET_X 0
#define MMI_DTV_PLAYER_SIGNAL_ICON_OFFSET_Y 0
#define MMI_DTV_PLAYER_DYNAMIC_LABLEL_OFFSET_X (35)
#define MMI_DTV_PLAYER_BG_OFFSET_X (0)
#define MMI_DTV_PLAYER_BG_OFFSET_Y (0)


#define MMI_DTV_PLAYER_LOADING_ICON_Y (65)
#define MMI_DTV_PLAYER_FULL_SCR_LOADING_ICON_Y (30)
#define MMI_DTV_PLAYER_BT_CONNECT_ICON_Y (50)
#define MMI_DTV_PLAYER_FULL_SCR_BT_CONNECT_ICON_Y (100)

#define DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_OFFSET_X (0)
#define DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_OFFSET_Y (0)
#define DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_WIDTH (320)
#define DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_HEIGHT (240)

/* DLS layer */
#define DTV_PLAYER_INTER_LAYER_ONE_LINE_HEIGHT (27)
#define DTV_PLAYER_INTER_LAYER_ONE_LINE_VIEW_WIDTH (43)

#define DTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X (0)
#define DTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_Y (0)
#define DTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH (270)
#define DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT (27)

#elif ((LCD_WIDTH == 240) && (LCD_HEIGHT == 400)) /* CMMB */
#define MMI_DTV_PLAYER_SIGNAL_ICON_OFFSET_X 0
#define MMI_DTV_PLAYER_SIGNAL_ICON_OFFSET_Y 0
#define MMI_DTV_PLAYER_DYNAMIC_LABLEL_OFFSET_X (35)
#define MMI_DTV_PLAYER_BG_OFFSET_X (0)
#define MMI_DTV_PLAYER_BG_OFFSET_Y (0)
#define MMI_DTV_PLAYER_FULL_SCR_BG_OFFSET_X (4)
#define MMI_DTV_PLAYER_FULL_SCR_BG_OFFSET_Y (196)
#define MMI_DTV_PLAYER_LOADING_ICON_Y (100)
#define MMI_DTV_PLAYER_FULL_SCR_LOADING_ICON_Y (40)
#define MMI_DTV_PLAYER_BT_CONNECT_ICON_Y (100)
#define MMI_DTV_PLAYER_FULL_SCR_BT_CONNECT_ICON_Y (40)

/* Display layer */
#define DTV_PLAYER_DISPLAY_LAYER_OFFSET_X (0)
#ifdef __MMI_FTE_SUPPORT__
#define DTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (81)
#else
#define DTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (84)
#endif
#define DTV_PLAYER_DISPLAY_LAYER_WIDTH (240)
#define DTV_PLAYER_DISPLAY_LAYER_HEIGHT (180)

#define DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_OFFSET_X (39)
#define DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_OFFSET_Y (0)
#define DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_WIDTH (320)
#define DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_HEIGHT (240)

/* DLS layer */
#define DTV_PLAYER_INTER_LAYER_ONE_LINE_HEIGHT (27)
#define DTV_PLAYER_INTER_LAYER_ONE_LINE_VIEW_WIDTH (43)


#define DTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X (5)
#define DTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_Y (0)
#define DTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH (345)
#define DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT (27)

#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 480)) /* CMMB */

#define MMI_DTV_PLAYER_SIGNAL_ICON_OFFSET_X 0
#define MMI_DTV_PLAYER_SIGNAL_ICON_OFFSET_Y 0
#define MMI_DTV_PLAYER_DYNAMIC_LABLEL_OFFSET_X (35)
#define MMI_DTV_PLAYER_BG_OFFSET_X (0)
#define MMI_DTV_PLAYER_BG_OFFSET_Y (0)
#define MMI_DTV_PLAYER_FULL_SCR_BG_OFFSET_X (4)
#define MMI_DTV_PLAYER_FULL_SCR_BG_OFFSET_Y (268)
#define MMI_DTV_PLAYER_LOADING_ICON_Y (100)
#define MMI_DTV_PLAYER_FULL_SCR_LOADING_ICON_Y (40)
#define MMI_DTV_PLAYER_BT_CONNECT_ICON_Y (100)
#define MMI_DTV_PLAYER_FULL_SCR_BT_CONNECT_ICON_Y (80)


/* Display layer */
#define DTV_PLAYER_DISPLAY_LAYER_OFFSET_X (0)
#define DTV_PLAYER_DISPLAY_LAYER_OFFSET_Y (76)
#define DTV_PLAYER_DISPLAY_LAYER_WIDTH (320)
#define DTV_PLAYER_DISPLAY_LAYER_HEIGHT (240)

#define DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_OFFSET_X (28)
#define DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_OFFSET_Y (0)
#define DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_WIDTH (426)
#define DTV_PLAYER_FULLSCREEN_DISPLAY_LAYER_HEIGHT (320)

/* DLS layer */
#define DTV_PLAYER_INTER_LAYER_ONE_LINE_VIEW_WIDTH (50)
#define DTV_PLAYER_INTER_LAYER_ONE_LINE_HEIGHT (27)

#define DTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_X (5)
#define DTV_PLAYER_FULLSCREEN_DLS_LAYER_OFFSET_Y (0)
#define DTV_PLAYER_FULLSCREEN_DLS_LAYER_WIDTH (425)
#define DTV_PLAYER_FULLSCREEN_DLS_LAYER_HEIGHT (27)

#else /* other LCD size */
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */

#define DTV_PLAYER_INTER_LAYER_ONE_LINE_WIDTH (DTV_PLAYER_INTER_BUFFER_WIDTH - DTV_PLAYER_INTER_LAYER_ONE_LINE_VIEW_WIDTH - (3 <<1))
#define DTV_PLAYER_INTER_LAYER_ONE_LINE_OFFSET_Y (DTV_PLAYER_DISPLAY_LAYER_OFFSET_Y + DTV_PLAYER_DISPLAY_LAYER_HEIGHT - DTV_PLAYER_INTER_LAYER_ONE_LINE_HEIGHT)
#define DTV_PLAYER_INTER_LAYER_HALF_SCREEN_WIDTH (DTV_PLAYER_INTER_BUFFER_WIDTH)
#define DTV_PLAYER_INTER_LAYER_HALF_SCREEN_HEIGHT (GDI_LCD_HEIGHT>>1)
#define DTV_PLAYER_INTER_LAYER_HALF_SCREEN_OFFSET_Y (LCD_HEIGHT - MMI_SOFTKEY_HEIGHT - DTV_PLAYER_INTER_LAYER_HALF_SCREEN_HEIGHT)

#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */
#endif /* _MMI_DTV_PLAYER_OSD_H_ */
