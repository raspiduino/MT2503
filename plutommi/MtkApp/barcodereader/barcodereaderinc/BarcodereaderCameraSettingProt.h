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
 *  BarcodeReaderCameraSettingProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  barcodereader Camera Setting Prot Header File
 *
 * Author:
 * -------
 * -------
 *                      
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_BARCODEREADER_CAMERA_SETTING_PROT_H
#define MMI_BARCODEREADER_CAMERA_SETTING_PROT_H

#include "MMIDataType.h"

typedef enum
{
    MMI_BARCODEREADER_CAMERA_SETTING_FLASH = 0,
    MMI_BARCODEREADER_CAMERA_SETTING_BANDING,
    MMI_BARCODEREADER_CAMERA_SETTING_FOCUS_MODE,
    MMI_BARCODEREADER_CAMERA_SETTING_EV,

    MMI_BARCODEREADER_CAMERA_SETTING_ALL
} mmi_barcodereader_camera_setting_enum;

extern void mmi_barcodereader_enter_camera_setting_screen(void);
extern void mmi_barcodereader_check_flash_status(void);
extern void mmi_barcodereader_flash_change(MMI_BOOL is_next);
#ifdef  __MMI_BARCODEREADER_FOCUS_MODE__
extern void mmi_barcodereader_focus_mode_change(MMI_BOOL is_next);
#endif
extern void mmi_barcodereader_ev_status_change(MMI_BOOL is_next);
extern void mmi_barcodereader_banding_change(MMI_BOOL is_next);
extern void mmi_barcodereader_check_zoom_status(void);
extern void mmi_barcodereader_zoom_change(MMI_BOOL is_next);
extern U16 mmi_barcodereader_get_curr_zoom_factor(void);
extern U16 mmi_barcodereader_get_default_zoom_factor(void);
extern void mmi_barcodereader_get_camera_setting_string(
                mmi_barcodereader_camera_setting_enum setting_which,
                PS8 str1,
                PS8 str2);

extern void mmi_barcodereader_load_camera_setting(void);
extern U16 mmi_barcodereader_get_focus_mode_value(void);
extern U16 mmi_barcodereader_get_ev_value(void);
extern U16 mmi_barcodereader_get_banding_value(void);
extern U16 mmi_barcodereader_get_flash_value(void);

extern U16 mmi_barcodereader_set_curr_zoom_factor(U16 zoom_index);
extern void mmi_barcodereader_camera_set_title(U16 title_id);

extern MMI_BOOL mmi_barcodereader_ev_is_reach_max(void);
extern MMI_BOOL mmi_barcodereader_ev_is_reach_min(void);

#endif /* MMI_BARCODEREADER_CAMERA_SETTING_PROT_H */ 

