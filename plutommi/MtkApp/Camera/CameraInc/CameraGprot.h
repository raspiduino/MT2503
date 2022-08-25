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
 *  CameraGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Define Camera Extern Prototype
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _CAMERA_GPROT_H_
#define _CAMERA_GPROT_H_

#include "MMI_features.h"

#if defined(__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)

#define    MMI_CAMERA_ER_SUCCESS       (0)
#define    MMI_CAMERA_ER_FAIL          (-9001)
#define    MMI_CAMERA_ER_BT_IS_WORKING (-9002)
#define    MMI_CMAERA_ER_CLAM_IS_CLOSE (-9003)

#ifdef __MMI_CAMERA_DIRECT_COUPLE__
#define CAMERA_DIRECT_COUPLE_BUFFER_SIZE ((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#else
#define CAMERA_DIRECT_COUPLE_BUFFER_SIZE (0)
#endif

#if defined(__CAMERA_FEATURE_ROTATE_OSD_SELF__) &&  defined(__CAMERA_OSD_HORIZONTAL__)
#define CAMERA_HW_ROTATE_TMP_BUFFER ((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#else
#define CAMERA_HW_ROTATE_TMP_BUFFER (0)
#endif
#define CAMERA_OSD_BUFFER_SIZE            (((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))


#define CAMERA_APP_MEM_POOL (CAMERA_OSD_BUFFER_SIZE + CAMERA_HW_ROTATE_TMP_BUFFER)

typedef enum
{
    MMI_CAMERA_EXTERNAL_MODE_OFF,
    MMI_CAMERA_EXTERNAL_MODE_NORMAL,
    MMI_CAMERA_EXTERNAL_MODE_LARGEST_RESOLUTION,
    MMI_CAMERA_EXTERNAL_MODE_COUNT
}mmi_camera_external_mode_enum;

#if 0   /*Phase out API */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern MMI_ID_TYPE mmi_camera_get_error_string_by_error_enum(S32 err_code);
extern void mmi_camera_get_max_capture_resolution(S32 *width, S32 *height);
extern U32 mmi_camera_get_ext_memory_usage(void);
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
extern mmi_ret mmi_camera_notify_screen_lock_hdlr(mmi_event_struct *evt);
#endif

#endif /* defined(__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */ 

#endif /* _CAMERA_GPROT_H_*/ 

