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
 *  DTVPlayerGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  External functions and variables of Mobile TV Player
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files
*****************************************************************************/
#ifndef _MMI_DTV_PLAYER_GPROT_H_
#define _MMI_DTV_PLAYER_GPROT_H_

#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__

#include "mmi_features.h"
#include "mmi_features_dtv_player.h"
#ifndef _GDI_INCLUDE_H_
   #include "gdi_include.h"
#endif
#include "wgui.h"
#ifndef _CUSTOM_EVENTS_NOTIFY_H
    #include "custom_events_notify.h"
#endif
#include "wgui_categories_list.h"

/*********************************************************************
 * DTVPlayer ASM Memory definition
 ********************************************************************/
/* (1) Opera engine memory config */ 
#ifdef __MBBMS_V30_OPERA__
	#define DTV_PLAYER_OPERA_ENGINE_MEM1   (15 * 1024 * 1024)
	#define DTV_PALYER_OPERA_ENGINE_PIXS   (4 * LCD_HEIGHT * (LCD_WIDTH + 128)) 
	#define DTV_PLAYER_OPERA_ENGINE_MEM2   ((DTV_PALYER_OPERA_ENGINE_PIXS * GDI_MAINLCD_BIT_PER_PIXEL) >> 3)
#else
	#define DTV_PLAYER_OPERA_ENGINE_MEM1   (0)
	#define DTV_PALYER_OPERA_ENGINE_PIXS   (0)
	#define DTV_PLAYER_OPERA_ENGINE_MEM2   (0)
#endif /* __MBBMS_V30_OPERA__ */

/* (2) Screen Layers memory config */
/* MAX(DLS_LAYER, INTER_LAYER) */  
#define DTV_PLAYER_DLS_BUFFER_WIDTH  (GDI_LCD_HEIGHT)
#define DTV_PLAYER_DLS_BUFFER_HEIGHT (27)
#define DTV_PLAYER_DLS_DRAWING_BUFFER_WIDTH (GDI_LCD_HEIGHT)
#define DTV_PLAYER_DLS_DRAWING_BUFFER_HEIGHT (27)
#ifdef __MBBMS_INTER__
	#define DTV_PLAYER_INTER_BUFFER_WIDTH  (GDI_LCD_WIDTH)
	#define DTV_PLAYER_INTER_BUFFER_HEIGHT (GDI_LCD_HEIGHT)
#else
	#define DTV_PLAYER_INTER_BUFFER_WIDTH (0)
	#define DTV_PLAYER_INTER_BUFFER_HEIGHT (0)
#endif /* __MBBMS_INTER__ */

#if (DTV_PLAYER_INTER_BUFFER_WIDTH * DTV_PLAYER_INTER_BUFFER_HEIGHT) > (DTV_PLAYER_DLS_BUFFER_WIDTH * DTV_PLAYER_DLS_BUFFER_HEIGHT)
	#undef DTV_PLAYER_DLS_BUFFER_WIDTH
	#undef DTV_PLAYER_DLS_BUFFER_HEIGHT
	#define DTV_PLAYER_DLS_BUFFER_WIDTH  (DTV_PLAYER_INTER_BUFFER_WIDTH)		
	#define DTV_PLAYER_DLS_BUFFER_HEIGHT (DTV_PLAYER_INTER_BUFFER_HEIGHT)
#endif 

#define MMI_DTV_PLAYER_DLS_BUFFER_SIZE  (((DTV_PLAYER_DLS_BUFFER_WIDTH*DTV_PLAYER_DLS_BUFFER_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
#define MMI_DTV_PLAYER_DLS_TOTAL_SIZE (MMI_DTV_PLAYER_DLS_BUFFER_SIZE * 3)
#else
#define MMI_DTV_PLAYER_DLS_TOTAL_SIZE (MMI_DTV_PLAYER_DLS_BUFFER_SIZE * 2)
#endif

/* Drawing layer */
#define MMI_DTV_PLAYER_DLS_DRAWING_BUFFER_SIZE  (((DTV_PLAYER_DLS_DRAWING_BUFFER_WIDTH*DTV_PLAYER_DLS_DRAWING_BUFFER_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))

/* OSD layer */
#define MMI_DTV_PLAYER_OSD_BUFFER_SIZE  (((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))
#define MMI_DTV_PLAYER_OSD_TOTAL_SIZE   (MMI_DTV_PLAYER_OSD_BUFFER_SIZE * 2)
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
#define MMI_DTV_PLAYER_OSD_ASM_SIZE (MMI_DTV_PLAYER_OSD_BUFFER_SIZE)
#else
#define MMI_DTV_PLAYER_OSD_ASM_SIZE (0)
#endif

/* Status layer */
#define MMI_DTV_PLAYER_STATUS_BAR_BUFFER_SIZE ((LCD_WIDTH*MMI_STATUS_BAR_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
#define MMI_DTV_PLAYER_STATUS_BAR_TOTAL_SIZE (MMI_DTV_PLAYER_STATUS_BAR_BUFFER_SIZE * 3)
#else
#define MMI_DTV_PLAYER_STATUS_BAR_TOTAL_SIZE (MMI_DTV_PLAYER_STATUS_BAR_BUFFER_SIZE)
#endif

/* (3) data struct list memory config */
#define MMI_DTV_MAX_SERVICES 50
#define MMI_DTV_MAX_SERVICE_INFO_STRUCTURE_SIZE 500 /* dtv_player_service_info_struct */
#define MMI_DTV_MAX_SCHEDULES 30
#define MMI_DTV_MAX_SCHEDULE_INFO_STRUCTURE_SIZE 250 /* dtv_player_schedule_info_struct */
#define MMI_DTV_MAX_ORDERS 20
#define MMI_DTV_MAX_ORDER_STRUCTURE_SIZE 350 /* dtv_player_order_struct */
#define MMI_DTV_MAX_ACCOUNT 20
#define MMI_DTV_MAX_ACCOUNT_STRUCTURE_SIZE 300 /* dtv_player_account_struct */
#define MMI_DTV_MAX_EB_MSG 20
#define MMI_DTV_MAX_EB_MSG_STRUCTURE_SIZE 350 /* dtv_player_eb_msg_struct */

#define MMI_DTV_PLAYER_SERVICE_LIST_SIZE  (MMI_DTV_MAX_SERVICES*MMI_DTV_MAX_SERVICE_INFO_STRUCTURE_SIZE)
#define MMI_DTV_PLAYER_EB_MSG_LIST_SIZE (MMI_DTV_MAX_EB_MSG*MMI_DTV_MAX_EB_MSG_STRUCTURE_SIZE)
#define MMI_DTV_PLAYER_ACCOUNT_LIST_SIZE (MMI_DTV_MAX_ACCOUNT*MMI_DTV_MAX_ACCOUNT_STRUCTURE_SIZE)
#define MMI_DTV_PLAYER_SCHEDULE_LIST_SIZE  (MMI_DTV_MAX_SCHEDULES*MMI_DTV_MAX_SCHEDULE_INFO_STRUCTURE_SIZE)
#define MMI_DTV_PLAYER_ORDER_LIST_SIZE  (MMI_DTV_MAX_ORDERS*MMI_DTV_MAX_ORDER_STRUCTURE_SIZE)

#ifdef __MBBMS_CITY_LIST__
	#define MMI_DTV_MAX_RECOMMEND_CITY 20
	#define MMI_DTV_MAX_CITY_STRUCTURE_SIZE 50 /* dtv_player_city_struct */
	#define MMI_DTV_MAX_DISPLAY_CITY 50
	#define MMI_DTV_MAX_DISPLAY_CITY_STRUCTURE_SIZE 50 /* dtv_player_display_city_struct */
	#define MMI_DTV_PLAYER_CITY_LIST_SIZE (MMI_DTV_MAX_RECOMMEND_CITY*MMI_DTV_MAX_CITY_STRUCTURE_SIZE)
	#define MMI_DTV_PLAYER_DISPLAY_CITY_LIST_SIZE  (MMI_DTV_MAX_DISPLAY_CITY*MMI_DTV_MAX_DISPLAY_CITY_STRUCTURE_SIZE)
#else
	#define MMI_DTV_PLAYER_CITY_LIST              (0)
	#define MMI_DTV_PLAYER_DISPLAY_CITY_LIST_SIZE (0)
#endif /* __MBBMS_CITY_LIST__*/

#ifdef __MBBMS_INTER__
	#define MMI_DTV_MAX_INTER_LIST 10
	#define MMI_DTV_MAX_INTER_LIST_STRUCTURE_SIZE 300 /* dtv_player_inter_list_struct */
	#define MMI_DTV_PLAYER_INTER_LIST_SIZE (MMI_DTV_MAX_INTER_LIST*MMI_DTV_MAX_INTER_LIST_STRUCTURE_SIZE)
#else
	#define MMI_DTV_PLAYER_INTER_LIST_SIZE (0)
#endif /* __MBBMS_INTER__ */

#define MMI_DTV_CAT1023_HISTORY_SIZE    (MMI_CAT1023_MAX_DATE_COUNT*MMI_CAT1023_MAX_TAB_COUNT*12 + MMI_CAT1023_MAX_DATE_COUNT*4)
#define MMI_DTV_PLAYER_DETAIL_BUF_SIZE  (2048)


#ifdef __MMI_CMMB_CAS_2GPP_V10__
#define MMI_DTV_PLAYER_2GPP_MEM_SIZE (200*1024)
#else
#define MMI_DTV_PLAYER_2GPP_MEM_SIZE (0)
#endif


/* (4) calculate the total asm memory config */

/* MAX(MAX(CAT1023_HISTORY, ACCOUNT_LIST, CITY_LIST), MAIN_SCREEN_SIZE) */
#define MMI_DTV_PLAYER_ASM_SCREEN_SIZE (MMI_DTV_CAT1023_HISTORY_SIZE)
#if (MMI_DTV_PLAYER_ASM_SCREEN_SIZE < MMI_DTV_PLAYER_ACCOUNT_LIST_SIZE)
#undef MMI_DTV_PLAYER_ASM_SCREEN_SIZE
#define MMI_DTV_PLAYER_ASM_SCREEN_SIZE (MMI_DTV_PLAYER_ACCOUNT_LIST_SIZE)
#endif /* MMI_DTV_PLAYER_ASM_SCREEN_SIZE < MMI_DTV_PLAYER_ACCOUNT_LIST_SIZE */
#if (MMI_DTV_PLAYER_ASM_SCREEN_SIZE < MMI_DTV_PLAYER_CITY_LIST_SIZE)
#undef MMI_DTV_PLAYER_ASM_SCREEN_SIZE
#define MMI_DTV_PLAYER_ASM_SCREEN_SIZE (MMI_DTV_PLAYER_CITY_LIST_SIZE)
#endif /* MMI_DTV_PLAYER_ASM_SCREEN_SIZE < MMI_DTV_PLAYER_CITY_LIST_SIZE */
#define MMI_DTV_PLAYER_MAIN_SCREEN_SIZE (MMI_DTV_PLAYER_STATUS_BAR_TOTAL_SIZE + MMI_DTV_PLAYER_DLS_TOTAL_SIZE + MMI_DTV_PLAYER_OSD_ASM_SIZE + MMI_DTV_PLAYER_DLS_DRAWING_BUFFER_SIZE)
#if MMI_DTV_PLAYER_MAIN_SCREEN_SIZE > MMI_DTV_PLAYER_ASM_SCREEN_SIZE
#define MMI_DTV_PLAYER_APP_MEM_SIZE1 (256+32*9 + MMI_DTV_PLAYER_SERVICE_LIST_SIZE + MMI_DTV_PLAYER_MAIN_SCREEN_SIZE)
#else
#define MMI_DTV_PLAYER_APP_MEM_SIZE1 (256+32*9 + MMI_DTV_PLAYER_SERVICE_LIST_SIZE + MMI_DTV_PLAYER_ASM_SCREEN_SIZE)
#endif

#define MMI_DTV_PLAYER_APP_MEM_SIZE (MMI_DTV_PLAYER_APP_MEM_SIZE1 + DTV_PLAYER_OPERA_ENGINE_MEM1 + DTV_PLAYER_OPERA_ENGINE_MEM2 + MMI_DTV_PLAYER_2GPP_MEM_SIZE)

/*************************************************************************
 * DTVPlayer Screen Memory config
 ************************************************************************/
/* MAX(OST_TOTAL, DETAIL_BUF, SCHEDULES, ORDERS, EB_MSGS, DISPLAY_CITYS, INTERS) */ 
#define MMI_DTV_PLAYER_SCR_MEM_SIZE (MMI_DTV_PLAYER_OSD_TOTAL_SIZE)
#if (MMI_DTV_PLAYER_SCR_MEM_SIZE < MMI_DTV_PLAYER_DETAIL_BUF_SIZE)
#undef MMI_DTV_PLAYER_SCR_MEM_SIZE
#define MMI_DTV_PLAYER_SCR_MEM_SIZE (MMI_DTV_PLAYER_DETAIL_BUF_SIZE)
#endif /* MMI_DTV_PLAYER_SCR_MEM_SIZE < MMI_DTV_PLAYER_DETAIL_BUF_SIZE */
#if (MMI_DTV_PLAYER_SCR_MEM_SIZE < MMI_DTV_PLAYER_SCHEDULE_LIST_SIZE)
#undef MMI_DTV_PLAYER_SCR_MEM_SIZE
#define MMI_DTV_PLAYER_SCR_MEM_SIZE (MMI_DTV_PLAYER_SCHEDULE_LIST_SIZE)
#endif /* MMI_DTV_PLAYER_SCR_MEM_SIZE < MMI_DTV_PLAYER_SCHEDULE_LIST_SIZE */
#if (MMI_DTV_PLAYER_SCR_MEM_SIZE < MMI_DTV_PLAYER_ORDER_LIST_SIZE)
#undef MMI_DTV_PLAYER_SCR_MEM_SIZE
#define MMI_DTV_PLAYER_SCR_MEM_SIZE (MMI_DTV_PLAYER_ORDER_LIST_SIZE)
#endif /* MMI_DTV_PLAYER_SCR_MEM_SIZE < MMI_DTV_PLAYER_ORDER_LIST_SIZE */
#if (MMI_DTV_PLAYER_SCR_MEM_SIZE < MMI_DTV_PLAYER_EB_MSG_LIST_SIZE)
#undef MMI_DTV_PLAYER_SCR_MEM_SIZE
#define MMI_DTV_PLAYER_SCR_MEM_SIZE (MMI_DTV_PLAYER_EB_MSG_LIST_SIZE)
#endif /* MMI_DTV_PLAYER_SCR_MEM_SIZE < MMI_DTV_PLAYER_EB_MSG_LIST_SIZE */
#if (MMI_DTV_PLAYER_SCR_MEM_SIZE < MMI_DTV_PLAYER_DISPLAY_CITY_LIST_SIZE)
#undef MMI_DTV_PLAYER_SCR_MEM_SIZE
#define MMI_DTV_PLAYER_SCR_MEM_SIZE (MMI_DTV_PLAYER_DISPLAY_CITY_LIST_SIZE)
#endif /* MMI_DTV_PLAYER_SCR_MEM_SIZE < MMI_DTV_PLAYER_DISPLAY_CITY_LIST_SIZE */
#if (MMI_DTV_PLAYER_SCR_MEM_SIZE < MMI_DTV_PLAYER_INTER_LIST_SIZE)
#undef MMI_DTV_PLAYER_SCR_MEM_SIZE
#define MMI_DTV_PLAYER_SCR_MEM_SIZE (MMI_DTV_PLAYER_INTER_LIST_SIZE)
#endif /* MMI_DTV_PLAYER_SCR_MEM_SIZE < MMI_DTV_PLAYER_INTER_LIST_SIZE */


/*****************************************************************
 * DTVPlayer External Interface
 *****************************************************************/
#define MMI_DTV_PLAYER_ERR_IS_BG_RUNNING    (-700)

extern mmi_ret mmi_dtv_player_fmgr_notify_handler(mmi_event_struct* para);
extern void mmi_dtv_player_enter_usb_mode_callback(void);
extern void mmi_dtv_player_exit_usb_mode_callback(void);
extern void mmi_dtv_player_terminate_app(void);
extern void mmi_dtv_player_enter_app_main(void);
extern void mmi_dtv_player_launch(void);
extern void mmi_dtv_player_init_app(void);
extern MMI_BOOL mmi_dtv_player_is_bg_running(void);
extern void mmi_dtv_player_popup_dtv_is_running(void);
extern U16 mmi_dtv_player_get_notify_bg_running_str_id(void);
extern MMI_STR_ID mmi_dtv_player_get_error_info(S32 error_result, mmi_event_notify_enum* popup_type);
extern void mmi_dtv_player_unmute(void);
extern void mmi_dtv_player_date_time_update_hdlr(void);
extern void mmi_dtv_player_set_mts_display(MMI_BOOL display);
extern MMI_BOOL mmi_dtv_player_get_mts_display(void);
extern U32 mmi_dtv_player_get_setting_account_id(void);
#ifdef __BT_SPK_VOL_CONTROL__
extern MMI_BOOL mmi_dtv_player_bt_volume_sync_hdlr(U8 volume, MMI_BOOL is_mute);
#endif

#if defined(__MMI_DTV_A2DP_SUPPORT__)
extern void mmi_dtv_player_bt_power_off_notify_hdlr(void);
#endif /* __MMI_DTV_A2DP_SUPPORT__ */

#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */
#endif /* _MMI_DTV_PLAYER_GPROT_H_ */
