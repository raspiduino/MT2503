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
 *   VdoRecGProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Expose Video Recorder functions and variables.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VDORECGPROT_H
#define _MMI_VDORECGPROT_H

#include "MMI_features.h"

#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)

#include "gdi_include.h"
#include "gdi_lcd_config.h"
#include "MMIDataType.h"
#include "kal_general_types.h"

#ifndef _GDI_INCLUDE_H_
#error "Please include gdi_include.h first"
#endif 

/***************************************************************************** 
* Define
*****************************************************************************/
#define VDOREC_BUFFER_DEPTH         (2)

//#define VDOREC_OSD_BUFFER_SIZE      (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*VDOREC_BUFFER_DEPTH*2)
/* currently we only use one SCRN memory for OSD, the other is from GDI*/
#define VDOREC_OSD_BUFFER_SIZE      (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*VDOREC_BUFFER_DEPTH)

/*currently if in hw rotate, we will use hw temp layer for 2d rotate, this is malloc from app mem*/
#if defined(__MDI_VIDEO_HW_ROTATOR_SUPPORT__) && defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && !defined(__MMI_VIDEO_RECORDER_SLIM__)
#define VDOREC_APP_MEMORY_BUFFER_SIZE (VDOREC_OSD_BUFFER_SIZE)
#else
#define VDOREC_APP_MEMORY_BUFFER_SIZE (0)
#endif
//#define VDOREC_APP_MEMORY_BUFFER_SIZE (VDOREC_OSD_BUFFER_SIZE)

#ifdef __VDOREC_COLOR_IDX_FRAME__
#define VDOREC_OVERLAY_FRAME_BUFFER_SIZE     (GDI_LCD_WIDTH*GDI_LCD_HEIGHT)
#else 
#define VDOREC_OVERLAY_FRAME_BUFFER_SIZE     (0)
#endif 

#define mmi_vdorec_entry_app_screen_external mmi_vdorec_entry_app
/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_vdorec_init_app(void);

extern BOOL mmi_vdorec_is_in_app(void);
extern void mmi_vdorec_usb_mode_hdlr(void);

extern U32 mmi_vdorec_get_min_external_request_size(void);

extern void mmi_vdorec_lauch(void);

extern BOOL mmi_vdorec_notify_storage_change_hdlr(U32 notify_flag, void* para);
extern void mmi_vdorec_delete_all_from_history(void);
extern mmi_ret mmi_vdorec_notify_storage_change_evt_hdlr(mmi_event_struct *evt);
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
extern mmi_ret mmi_vdorec_notify_screen_lock_hdlr(mmi_event_struct *evt);
#endif


#endif /* __MMI_VIDEO_RECORDER__ && !__MMI_CAMCORDER__ */
#endif /* _MMI_VDORECGPROT_H */ 

