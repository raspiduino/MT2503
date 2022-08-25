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
 *  BarcodeReaderProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Barcode Reader Commmon Prot Header File
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_BARCODEREADER_COMMON_PROT_H
#define MMI_BARCODEREADER_COMMON_PROT_H

/***************************************************************************** 
* Included .h file
*****************************************************************************/
#include "mdi_camera.h"
#include "FileManagerGProt.h"
#include "resource_barcodereader_skins.h"

/****************************************************************************
* macro declare                                                              
*****************************************************************************/
#define MMI_BARCODEREADER_DEFAULT_SETTING_ZOOM_IDX          (10)

#define MMI_BARCODEREADER_OSD_ROTATE_0        MDI_CAMERA_PREVIEW_ROTATE_0
#define MMI_BARCODEREADER_OSD_ROTATE_90       MDI_CAMERA_PREVIEW_ROTATE_90
#define MMI_BARCODEREADER_OSD_ROTATE_180         MDI_CAMERA_PREVIEW_ROTATE_180
#define MMI_BARCODEREADER_OSD_ROTATE_270         MDI_CAMERA_PREVIEW_ROTATE_270
#define MMI_BARCODEREADER_OSD_ROTATE_RESET       255

#define MMI_BARCODEREADER_PREVIEW_ROTATE_0                MDI_CAMERA_PREVIEW_ROTATE_0
#define MMI_BARCODEREADER_PREVIEW_ROTATE_90               MDI_CAMERA_PREVIEW_ROTATE_90
#define MMI_BARCODEREADER_PREVIEW_ROTATE_180           MDI_CAMERA_PREVIEW_ROTATE_180
#define MMI_BARCODEREADER_PREVIEW_RORATE_270           MDI_CAMERA_PREVIEW_ROTATE_270
#define MMI_BARCODEREADER_PREVIEW_ROTATE_0_MIRROR      MDI_CAMERA_PREVIEW_ROTATE_0_MIRROR
#define MMI_BARCODEREADER_PREVIEW_ROTATE_90_MIRROR     MDI_CAMERA_PREVIEW_ROTATE_90_MIRROR
#define MMI_BARCODEREADER_PREVIEW_ROTATE_180_MIRROR    MDI_CAMERA_PREVIEW_ROTATE_180_MIRROR
#define MMI_BARCODEREADER_PREVIEW_ROTATE_270_MIRROR    MDI_CAMERA_PREVIEW_ROTATE_270_MIRROR

#define MMI_BARCODEREADER_LCM_ROTATE_0                 MDI_CAMERA_LCM_ROTATE_0
#define MMI_BARCODEREADER_LCM_ROTATE_90                MDI_CAMERA_LCM_ROTATE_90
#define MMI_BARCODEREADER_LCM_ROTATE_180               MDI_CAMERA_LCM_ROTATE_180
#define MMI_BARCODEREADER_LCM_ROTATE_270                  MDI_CAMERA_LCM_ROTATE_270
#define MMI_BARCODEREADER_LCM_ROTATE_0_MIRROR             MDI_CAMERA_LCM_ROTATE_0_MIRROR
#define MMI_BARCODEREADER_LCM_ROTATE_90_MIRROR         MDI_CAMERA_LCM_ROTATE_90_MIRROR
#define MMI_BARCODEREADER_LCM_ROTATE_180_MIRROR        MDI_CAMERA_LCM_ROTATE_180_MIRROR
#define MMI_BARCODEREADER_LCM_ROTATE_270_MIRROR        MDI_CAMERA_LCM_ROTATE_270_MIRROR

#define MMI_BARCODEREADER_STORAGE_FILEPATH_PHONE          FMGR_DEFAULT_FOLDER_BARCODE
#define MMI_BARCODEREADER_STORAGE_FILEPATH_MEMORY_CARD    FMGR_DEFAULT_FOLDER_BARCODE

#define MMI_BARCODEREADER_AF_LARGE_WIDTH               (25)
#define MMI_BARCODEREADER_AF_NORMAL_WIDTH              (25)
#define MMI_BARCODEREADER_AF_SMALL_WIDTH               (25)

/****************************************************************************
* resource base                                                              
*****************************************************************************/

/***************************************************************************** 
* Enum Declare
*****************************************************************************/
typedef enum
{
    MMI_BARCODEREADER_ERROR_NO_ERROR = 0,
    MMI_BARCODEREADER_ERROR_ENCODING_ERROR,
    MMI_BARCODEREADER_ERROR_COMMON,
    MMI_BARCODEREADER_ERROR_TOO_LONG_NUMBER,
    MMI_BARCODEREADER_ERROR_DECODE_FAILED,
    MMI_BARCODEREADER_ERROR_NOT_DM_CODE,
    MMI_BARCODEREADER_ERROR_NOT_SUPPORT_THIS_SERIVCE,
    MMI_BARCODEREADER_ERROR_NOT_SUPPORT_THIS_MODE,
    MMI_BARCODEREADER_ERROR_FORMAT,
    MMI_BARCODEREADER_ERROR_TOO_LONG_URL,
    MMI_BARCODEREADER_ERROR_FORBID_DIRECT_MODE,
    MMI_BARCODEREADER_ERROR_SERVER_NOT_CONNECT,
    MMI_BARCODEREADER_ERROR_SERVER_NOT_CONFIGED,
    MMI_BARCODEREADER_ERROR_FILE_CORRUPT,
    MMI_BARCODEREADER_ERROR_NO_SIMCARD,
    MMI_BARCODEREADER_OP01_ENCODING_ERROR,
    MMI_BARCODEREADER_ERROR_NO_STORAGE,

    MMI_BARCODEREADER_ERROR_ALL
} mmi_barcodereader_error_result_enum;

typedef enum
{
    MMI_BARCODEREADER_ERROR_TYPE_FROM_FS = 0,
    MMI_BARCODEREADER_ERROR_TYPE_FROM_CAMERA,
    MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER,
    MMI_BARCODEREADER_ERROR_TYPE_ALL
} mmi_barcodereader_error_type_enum;

typedef enum
{
    MMI_BARCODEREADER_AF_ANIMATION_STEP1,
    MMI_BARCODEREADER_AF_ANIMATION_STEP2,
    MMI_BARCODEREADER_AF_ANIMATION_STEP3,

    MMI_BARCODEREADER_AF_ANIMATION_ALL
} mmi_barcodereader_af_animtaion_process;

typedef enum
{
    MMI_BARCODEREADER_AF_IDLE = 0,
    MMI_BARCODEREADER_AF_CALCULATE,
    MMI_BARCODEREADER_AF_SUCCEED,
    MMI_BARCODEREADER_AF_FAIL,
    MMI_BARCODEREADER_AF_ONFOCUS,

    MMI_BARCODEREADER_AF_ALL
} mmi_barcodereader_af_states;

/***************************************************************************** 
* Structure Declare
*****************************************************************************/
typedef struct
{
    S32 error_result;
    mmi_barcodereader_error_type_enum error_type;
    U8 tone_id;
} mmi_barcodereader_error_struct;

typedef struct
{
    U16 image_id;
    U16 string_id;
} mmi_barcodereader_menu_list_node;

/***************************************************************************** 
* Function Declare
*****************************************************************************/
extern S32 mmi_barcodereader_create_file_dir(PS8 filepath);
extern void mmi_barcodereader_init_framework(void);
extern void mmi_barcodereader_uninit_frameword(void);
extern void mmi_barcodereder_init_camera_befor_preview(mdi_camera_setting_struct *camera_setting_data);
extern void mmi_barcodereader_draw_bolder_rect(S32 x1, S32 y1, S32 x2, S32 y2, S32 bolder_width, gdi_color frame_color);
extern void mmi_barcodereader_display_error_popup(S32 error_result, S32 error_type, U8 tone_id);
extern void mmi_barcodereader_ucs2_strtoken(PS8 string, S8 seperate, PS32 length);
extern void mmi_barcodereader_draw_style_text(
                PS8 str,
                S32 offset_x,
                S32 offset_y,
                S32 truncated_width,
                barcodereader_style_text_struct *style_txt);
extern MMI_BOOL mmi_barcodereader_is_network_permit(MMI_BOOL is_net);

#endif /* MMI_BARCODEREADER_COMMON_PROT_H */ 

