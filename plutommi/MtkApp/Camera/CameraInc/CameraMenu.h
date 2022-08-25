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
 *  CameraMenu.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Camera option menu header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _CAMERA_MENU_H_
#define _CAMERA_MENU_H_

#include "MMI_features.h"
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)

typedef enum
{
    MMI_CAMERA_SETTING_INLINE_CUI_BASE_START =(CUI_INLINE_ITEM_ID_BASE + 0),

#ifdef __CAMERA_FEATURE_FLASH__
    MMI_CAMERA_SETTING_IL_FLASH_CAPTION, 
    MMI_CAMERA_SETTING_IL_FLASH_SELECT,
#endif

#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__ 
MMI_CAMERA_SETTING_IL_LED_HIGHLIGHT_CAPTION,
MMI_CAMERA_SETTING_IL_LED_HIGHLIGHT_SELECT,
#endif

#ifdef __CAMERA_FEATURE_SHUTTER_SOUND__
    MMI_CAMERA_SETTING_IL_SHUTTER_SOUND_CAPTION,
    MMI_CAMERA_SETTING_IL_SHUTTER_SOUND_SELECT,
#endif    

#ifdef __CAMERA_FEATURE_EV__
    MMI_CAMERA_SETTING_IL_EV_CAPTION,
    MMI_CAMERA_SETTING_IL_EV_SELECT,
#endif  

#ifdef __CAMERA_FEATURE_NIGHT__
    MMI_CAMERA_SETTING_IL_NIGHT_CAPTION,
    MMI_CAMERA_SETTING_IL_NIGHT_SELECT,
#endif  

#ifdef __CAMERA_FEATURE_AE_METER__
    MMI_CAMERA_SETTING_IL_AE_METER_CAPTION,
    MMI_CAMERA_SETTING_IL_AE_METER_SELECT,
#endif  

#ifdef __CAMERA_FEATURE_CONTRAST__
    MMI_CAMERA_SETTING_IL_CONTRAST_CAPTION,
    MMI_CAMERA_SETTING_IL_CONTRAST_SELECT,
#endif

#ifdef __CAMERA_FEATURE_BANDING__
    MMI_CAMERA_SETTING_IL_BANDING_CAPTION,
    MMI_CAMERA_SETTING_IL_BANDING_SELECT,
#endif

#ifdef __CAMERA_DSC_MODE__
    MMI_CAMERA_SETTING_IL_DSC_MODE_CAPTION,
    MMI_CAMERA_SETTING_IL_DSC_MODE_SELECT,
#endif

#ifdef __CAMERA_FEATURE_WB__
	MMI_CAMERA_SETTING_IL_WB_CAPTION,
    MMI_CAMERA_SETTING_IL_WB_SELECT,
#endif

#ifdef __CAMERA_FEATURE_DELAY_TIMER__
    MMI_CAMERA_SETTING_IL_DELAY_TIMER_CAPTION,
    MMI_CAMERA_SETTING_IL_DELAY_TIMER_SELECT,
#endif

#ifdef __CAMERA_FEATURE_CONT_SHOT__
    MMI_CAMERA_SETTING_IL_CONT_SHOT_CAPTION,
    MMI_CAMERA_SETTING_IL_CONT_SHOT_SELECT,
#endif

    MMI_CAMERA_SETTING_INLINE_CUI_BASE_END
}mmi_camera_setting_inline_cui_base_enum;

typedef enum
{
    MMI_CAMERA_SETTING_IMG_IL_SIZE_CAPTION =(CUI_INLINE_ITEM_ID_BASE + 0),
    MMI_CAMERA_SETTING_IMG_IL_SIZE_SELECT,
    
    MMI_CAMERA_SETTING_IMG_IL_QUALITY_CAPTION,
    MMI_CAMERA_SETTING_IMG_IL_QUALITY_SELECT,
    
    MMI_CAMERA_SETTING_IMG_INLINE_CUI_BASE_END
}mmi_camera_setting_image_inline_cui_base_enum;
/* Option Menu */
extern void mmi_camera_exit_option_menu_screen(void);
extern void mmi_camera_entry_option_menu_screen(void);
extern void mmi_camera_setting_inline_on_commit(mmi_id g_id);
#ifdef __CAMERA_AUTOFOCUS__
extern void mmi_camera_entry_autofocus_screen(void);
#endif
#ifdef __CAMERA_AUTOFOCUS_MODE__
extern void mmi_camera_entry_autofocus_mode_screen(void);
#endif



#ifdef __CAMERA_FEATURE_EFFECT__
extern void mmi_camera_entry_effect_setting_screen(void);
#endif

#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
extern void mmi_camera_set_self_capture(void);
#endif


#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */ 
#endif /* _CAMERA_MENU_H_ */ 

