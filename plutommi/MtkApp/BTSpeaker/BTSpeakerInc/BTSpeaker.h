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
 * BTSpeaker.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file of btmmiscr.c
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
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __MMI_FTE_SUPPORT__
#include "wgui_touch_screen.h"
#endif 

#include "MMI_features.h"
#include "MMIDataType.h"

/* The maximum volume of 6 level volume + mute level (mute) */
#define MDI_A2DP_SINK_VOL_EX_MUTE_MIN 0
#define MDI_A2DP_SINK_VOL_EX_MUTE_MAX 6

typedef enum
{
	BTSP_PEN_NONE,
    BTSP_PEN_LSK,
	BTSP_PEN_PLAY,
	BTSP_PEN_NEXT,
	BTSP_PEN_PREV,
	BTSP_PEN_STOP
} BTSPEAKER_PEN_STATE;

typedef enum
{
	PEN_EVENT_DOWN,
	PEN_EVENT_UP
}btsp_pen_events;

/***************************************************************************** 
* External Global Variable
*****************************************************************************/
/*******************************/
MMI_BOOL mmi_bt_speaker_launch_fn(MMI_ID parent_gid);
MMI_BOOL srv_avrcp_sink_vol_control_callback(U8 volume, MMI_BOOL is_mute);
MMI_RET mmi_bt_speaker_avrcp_sink_send_cmd_frame(mmi_event_struct *evt);

void mmi_audply_redraw_main_buttons_bt(void);
void mmi_bt_draw_softkey(void);
void mmi_bt_speaker_redraw_main_all(void);
void mmi_bt_speaker_init_main(void);
void mmi_bt_speaker_update_main_screen(srv_a2dp_callback_event_enum event);

extern  void mmi_bt_speaker_de_launch_fn(void);
extern void srv_avrcp_sink_send_cmd_frame(int cmd_frame);

void mmi_bt_speaker_pen_up_hdlr(mmi_pen_point_struct pos);
void mmi_bt_speaker_pen_down_hdlr(mmi_pen_point_struct pos);
void mmi_bt_speaker_pen_hdlr(mmi_pen_point_struct pos,btsp_pen_events event);
