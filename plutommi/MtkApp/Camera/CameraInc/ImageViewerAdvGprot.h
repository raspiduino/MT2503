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
 *  ImageViewerAdvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  ImageViewer's prototype header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_VIEWER_ADV_GPROT_H_
#define _IMAGE_VIEWER_ADV_GPROT_H_

#include "MMI_features.h"


#if defined(__MMI_IMAGE_VIEWER_ADV__)

#include "kal_general_types.h"
#include "lcd_sw_inc.h"
#ifndef _GDI_INCLUDE_H_
#include "gdi_include.h"
#endif

#include "MMIDataType.h"

#include "FileMgrSrvGProt.h"
#ifndef _FMGR_GPROT_H_
#include "FileMgrGprot.h"
#include "FileMgrSrvGProt.h"
#endif

#include "ImageViewCuiGprot.h"

typedef struct
{
    CHAR*  filepath;
    U8   rotation;
    MMI_BOOL is_show_filename;
    MMI_BOOL is_short;
}mmi_imgadv_external_request;

#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
#define MMI_IMGADV_LAYER_SIZE (((LCD_WIDTH*LCD_HEIGHT*MAIN_MEDIA_LAYER_BITS_PER_PIXEL)>>3))
#else
#define MMI_IMGADV_LAYER_SIZE (((LCD_WIDTH*LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))
#endif
#define MMI_IMGADV_TOTAL_MEMORY_SIZE (MMI_IMGADV_LAYER_SIZE + SRV_FMGR_PATH_BUFFER_SIZE*2 + 60)
extern void mmi_imgadv_entry_app_screen(void);
extern void mmi_imgadv_exit_app_screen(void);
extern void mmi_imgadv_reset_app(void);
extern void mmi_imgadv_init_app(void);
extern U16 mmi_imgadv_get_rotate(void);
extern void mmi_imgadv_view_image_external_request(mmi_imgadv_external_request request);
extern void mmi_imgadv_preentry_view_screen(void);
/* The below APIs are for Imageview CUI */
extern void mmi_imgadv_app_reset(void);
extern void mmi_imgadv_set_ui_direct(mmi_id image_viewer_id, cui_imgview_ui_direction_enum direction);
extern void mmi_imgadv_enter_view_from_cui(mmi_id image_viewer_id);
#if defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__)
extern void mmi_imgadv_option_print_execute_forward(U16 highlight_item);
#endif
#else /* defined(__MMI_IMAGE_VIEWER_ADV__) */

#define MMI_IMGADV_TOTAL_MEMORY_SIZE (0)

#endif /* defined(__MMI_IMAGE_VIEWER_ADV__) */

#endif /* _IMAGE_VIEWER_ADV_GPROT_H_ */ 

