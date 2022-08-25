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
 *  MobileTVPlayerGprot.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _MMI_MOBILE_TV_PLAYER_GPROT_H_
#define _MMI_MOBILE_TV_PLAYER_GPROT_H_


#ifdef __MMI_ATV_SUPPORT__
#include "mmi_features.h"
#include "mmi_features_mtv_player.h"

#ifndef _GDI_INCLUDE_H_
   #include "gdi_include.h"
#endif
#include "wgui.h"
#ifndef _CUSTOM_EVENTS_NOTIFY_H
    #include "custom_events_notify.h"
#endif
#include "wgui_categories_list.h"

#ifdef __ATV_SMS_SUPPORT__
#include "MtvSmsGprot.h"
#endif

/******************************************
* Mobile TV DLS Layer 
******************************************/
#if GDI_LCD_WIDTH > GDI_LCD_HEIGHT
#define MTV_PLAYER_DLS_BUFFER_WIDTH (GDI_LCD_WIDTH) 
#define MTV_PLAYER_DLS_BUFFER_HEIGHT (27) 
#else
#define MTV_PLAYER_DLS_BUFFER_WIDTH (GDI_LCD_HEIGHT)
#define MTV_PLAYER_DLS_BUFFER_HEIGHT (27) 
#endif

#if defined(__ATV_SLIM_VERSION__)
#define MMI_MTV_MAX_SERVICES 30
#else  /* __ATV_SLIM_VERSION__ */
#define MMI_MTV_MAX_SERVICES 50
#endif /* __ATV_SLIM_VERSION__ */

#define MMI_MTV_MAX_SERVICE_INFO_STRUCTURE_SIZE 170    

/* Display layer */
#define MMI_MTV_PLAYER_DISPLAY_BUFFER_SIZE ((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#define MMI_MTV_PLAYER_SNAPSHOT_BUFFER_SIZE (MMI_MTV_PLAYER_DISPLAY_BUFFER_SIZE)

#if defined(__MMI_ATV_OSD_SUPPORT__)

/* Volume layer */
#define MTV_PLAYER_VOL_BUFFER_WIDTH     (GDI_LCD_WIDTH)
#define MTV_PLAYER_VOL_BUFFER_HEIGHT    (130)
#if defined(__MMI_FTE_SUPPORT__)
#define MTV_PLAYER_VOL_BUFFER_SIZE      ((MTV_PLAYER_VOL_BUFFER_WIDTH*MTV_PLAYER_VOL_BUFFER_HEIGHT*4))
#else 
#define MTV_PLAYER_VOL_BUFFER_SIZE      (0)
#endif
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
#define MTV_PLAYER_VOL_TOTAL_SIZE   (MTV_PLAYER_VOL_BUFFER_SIZE * 3)
#else
#define MTV_PLAYER_VOL_TOTAL_SIZE   (MTV_PLAYER_VOL_BUFFER_SIZE * 2)
#endif

/* DLS layer */
#if defined(GDI_2_LAYERS)
#define MMI_MTV_PLAYER_DLS_BUFFER_SIZE (0)
#else
#define MMI_MTV_PLAYER_DLS_BUFFER_SIZE  (((MTV_PLAYER_DLS_BUFFER_WIDTH*MTV_PLAYER_DLS_BUFFER_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))
#endif
#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
#define MMI_MTV_PLAYER_DLS_TOTAL_SIZE (MMI_MTV_PLAYER_DLS_BUFFER_SIZE * 3)
#else
#define MMI_MTV_PLAYER_DLS_TOTAL_SIZE (MMI_MTV_PLAYER_DLS_BUFFER_SIZE * 2)
#endif

/* Drawing layer */
#define MMI_MTV_PLAYER_DLS_DRAWING_BUFFER_SIZE  ((MMI_MTV_PLAYER_DLS_BUFFER_SIZE))

/* OSD layer */
#if defined(GDI_2_LAYERS)
#define MMI_MTV_PLAYER_OSD_BUFFER_SIZE ((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
    #ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    #define MMI_MTV_PLAYER_OSD_TOTAL_SIZE (MMI_MTV_PLAYER_OSD_BUFFER_SIZE * 2)
    #define MMI_MTV_PLAYER_OSD_ASM_SIZE (MMI_MTV_PLAYER_OSD_BUFFER_SIZE)
    #else
    #define MMI_MTV_PLAYER_OSD_TOTAL_SIZE (MMI_MTV_PLAYER_OSD_BUFFER_SIZE)
    #define MMI_MTV_PLAYER_OSD_ASM_SIZE (0)
    #endif
#else /* GDI_2_LAYERS */
#define MMI_MTV_PLAYER_OSD_BUFFER_SIZE  (((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))
    #define MMI_MTV_PLAYER_OSD_TOTAL_SIZE (MMI_MTV_PLAYER_OSD_BUFFER_SIZE * 2)
    #ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    #define MMI_MTV_PLAYER_OSD_ASM_SIZE (MMI_MTV_PLAYER_OSD_BUFFER_SIZE)
    #else
    #define MMI_MTV_PLAYER_OSD_ASM_SIZE (0)
    #endif
#endif /* GDI_2_LAYERS */

/* Status layer */
#if defined(GDI_2_LAYERS)
#define MMI_MTV_PLAYER_STATUS_BAR_BUFFER_SIZE (0)
#define MMI_MTV_PLAYER_STATUS_BAR_TOTAL_SIZE (0)
#else /* GDI_2_LAYERS */
#define MMI_MTV_PLAYER_STATUS_BAR_BUFFER_SIZE ((LCD_WIDTH*MMI_STATUS_BAR_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
    #ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    #define MMI_MTV_PLAYER_STATUS_BAR_TOTAL_SIZE (MMI_MTV_PLAYER_STATUS_BAR_BUFFER_SIZE * 3)
    #else
    #define MMI_MTV_PLAYER_STATUS_BAR_TOTAL_SIZE (MMI_MTV_PLAYER_STATUS_BAR_BUFFER_SIZE)
    #endif
#endif /* GDI_2_LAYERS */
#else /* __MMI_ATV_OSD_SUPPORT__ */
#define MMI_MTV_PLAYER_DLS_TOTAL_SIZE (0)
#define MMI_MTV_PLAYER_OSD_TOTAL_SIZE (0)
#define MMI_MTV_PLAYER_OSD_ASM_SIZE (0)
#define MMI_MTV_PLAYER_DLS_DRAWING_BUFFER_SIZE (0)
#define MTV_PLAYER_VOL_TOTAL_SIZE (0)
#define MMI_MTV_PLAYER_STATUS_BAR_TOTAL_SIZE (0)
#endif /* __MMI_ATV_OSD_SUPPORT__ */

#define MMI_MTV_PLAYER_SERVICE_LIST_SIZE  (MMI_MTV_MAX_SERVICES*MMI_MTV_MAX_SERVICE_INFO_STRUCTURE_SIZE) 

#ifdef __ATV_SMS_SUPPORT__ 
#define MMI_MTV_SMS_MEM (MATV_VIDEO_LAYER_BUF_SIZE + MATV_UTIL_LAYER_BUF_SIZE)
#else
#define MMI_MTV_SMS_MEM (0)
#endif

/* ASM size */
typedef union
{
    /* 1 is used to avoid 0 */   
    kal_uint8 main_screen[1 + MMI_MTV_PLAYER_STATUS_BAR_TOTAL_SIZE + MMI_MTV_PLAYER_DLS_TOTAL_SIZE + MMI_MTV_PLAYER_OSD_ASM_SIZE + MTV_PLAYER_VOL_TOTAL_SIZE + MMI_MTV_PLAYER_DLS_DRAWING_BUFFER_SIZE + MMI_MTV_PLAYER_SNAPSHOT_BUFFER_SIZE];
#ifdef __ATV_SMS_SUPPORT__    
    kal_uint8 sms_screen[MMI_MTV_SMS_MEM];
#endif
} mmi_mtv_player_scrn_asm;

#define MMI_MTV_PLAYER_APP_MEM_SIZE ((256+32*9) + MMI_MTV_PLAYER_SERVICE_LIST_SIZE + sizeof(mmi_mtv_player_scrn_asm))

/* Screen memory size */
#define MMI_MTV_PLAYER_SCR_MEM_SIZE (MMI_MTV_PLAYER_OSD_TOTAL_SIZE)

/* error result code */
#define MMI_MTV_PLAYER_ERR_IS_BG_RUNNING    (-700)

/******************************************
* Mobile TV Global Function  
******************************************/
mmi_ret mmi_mtv_player_fmgr_notify_handler(mmi_event_struct* para);
extern void mmi_mtv_player_enter_usb_mode_callback(void);
extern void mmi_mtv_player_exit_usb_mode_callback(void);
extern void mmi_mtv_player_terminate_app(void);
extern void mmi_mtv_player_enter_app_main(void);
extern void mmi_mtv_player_launch(void);

extern void mmi_mtv_player_init_app(void);
extern MMI_BOOL mmi_mtv_player_is_bg_running(void);
extern void mmi_mtv_player_popup_mtv_is_running(void);
extern U16 mmi_mtv_player_get_notify_bg_running_str_id(void);
extern MMI_STR_ID mmi_mtv_player_get_error_info(S32 error_result, mmi_event_notify_enum* popup_type);
extern void mmi_mtv_player_unmute(void);

#ifdef __BT_SPK_VOL_CONTROL__
extern MMI_BOOL mmi_mtv_player_bt_volume_sync_hdlr(U8 volume, MMI_BOOL is_mute);
#endif
#if defined(__MMI_MTV_A2DP_SUPPORT__)
extern void mmi_mtv_player_bt_power_off_notify_hdlr(void);
#endif /* __MMI_MTV_A2DP_SUPPORT__ */

#endif /* __MMI_ATV_SUPPORT__ */ 
#endif /* _MMI_MOBILE_TV_PLAYER_GPROT_H_ */ 
