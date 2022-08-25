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
 *   VTCallScrGProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video Telephony Call Screen Prototype
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef VT_CALL_SCR_GPROT_H
#define VT_CALL_SCR_GPROT_H

#include "MMI_features.h"
#ifdef __MMI_VIDEO_TELEPHONY__

#include "Med_global.h"
#include "MMIDataType.h"
#include "Mmi_frm_scenario_gprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__)&& defined(__OP01__)&& defined(__MMI_FTE_SUPPORT__)
#define MMI_VTCS_MAX_WIDTH        (320) 
#define MMI_VTCS_MAX_HEIGHT       (262) 
#elif (defined(__MMI_MAINLCD_240X320__)||defined(__MMI_MAINLCD_240X400__))&& defined(__OP01__)
#define MMI_VTCS_MAX_WIDTH        (240) 
#define MMI_VTCS_MAX_HEIGHT       (196) 
#else 
#define MMI_VTCS_MAX_WIDTH        (176) 
#define MMI_VTCS_MAX_HEIGHT       (144) 
#endif

#define MMI_VTCS_SKIN_BUF_DEPTH     (2) /* 16 bit */
#define MMI_VTCS_SKIN_BUF_SIZE      (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * MMI_VTCS_SKIN_BUF_DEPTH * 2) /* *2 for double buffer */

#define MMI_VTCS_ENCODE_BUF_DEPTH   (2) /* 16 bit */
#define MMI_VTCS_ENCODE_BUF_WIDTH   (MMI_VTCS_MAX_WIDTH)
#define MMI_VTCS_ENCODE_BUF_HEIGHT  (MMI_VTCS_MAX_HEIGHT)
#define MMI_VTCS_ENCODE_BUF_SIZE    (MMI_VTCS_ENCODE_BUF_WIDTH * MMI_VTCS_ENCODE_BUF_HEIGHT * MMI_VTCS_ENCODE_BUF_DEPTH)

#define MMI_VTCS_MDI_PREVIEW_MEM    (MMI_VTCS_MAX_HEIGHT * MMI_VTCS_MAX_WIDTH * MDI_VT_SRV_FACTOR)
#define MMI_VTCS_APP_MEMORY_POOL    (MMI_VTCS_SKIN_BUF_SIZE + MMI_VTCS_MDI_PREVIEW_MEM)

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/***************************************************************************** 
 * Variable 
 *****************************************************************************/

/***************************************************************************** 
 * Function 
 *****************************************************************************/
extern void mmi_vtcs_entry_call_scr(mmi_scrn_essential_struct* scr_info);
extern void mmi_vtcs_entry_call_scr_for_ut(mmi_scrn_essential_struct* scr_info);

extern void mmi_ucm_vt_delete_call_scr_history(void);

extern void mmi_vtcs_call_status_callback(MMI_BOOL start_timer);

#endif /* __MMI_VIDEO_TELEPHONY__ */
#endif /* VT_CALL_SCR_PROT_H */ 

