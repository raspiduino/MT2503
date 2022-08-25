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
 *  BarcodeReaderCameraSetting.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  barcodereader Camera Setting Header File
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_BARCODEREADER_CAMERA_SETTING_H
#define MMI_BARCODEREADER_CAMERA_SETTING_H

#include "BarcodereaderCameraSettingResDef.h"

#define MMI_BARCODEREADER_FLASH_ITEM_COUNT             (2)
#define MMI_BARCODEREADER_EV_ITEM_COUNT                (STR_ID_BARCODEREADER_EV_ALL-STR_ID_BARCODEREADER_EV_START-1)
#define MMI_BARCODEREADER_FOCUS_MODE_ITEM_COUNT        (STR_ID_BARCODEREADER_FOCUS_MODE_ALL-STR_ID_BARCODEREADER_FOCUS_MODE_START-1)
#define MMI_BARCODEREADER_BANDING_ITEM_COUNT           (STR_ID_BARCODEREADER_BANDING_ALL-STR_ID_BARCODEREADER_BANDING_START-1)
#define MMI_BARCODEREADER_CAMERA_SETTING_ITEM_COUNT    (4)

/***************************************************************************** 
* structure declare
*****************************************************************************/
typedef struct
{
    /* strings for inline selection display */
    /* +1 avoid this feature's item is zero */
    UI_string_type flash_str[MMI_BARCODEREADER_FLASH_ITEM_COUNT + 1];
    UI_string_type ev_str[MMI_BARCODEREADER_EV_ITEM_COUNT + 1];
    UI_string_type af_mode_str[MMI_BARCODEREADER_FOCUS_MODE_ITEM_COUNT + 1];
    UI_string_type banding_str[MMI_BARCODEREADER_BANDING_ITEM_COUNT + 1];

    /* selected item */
    S32 flash_selected;
    S32 ev_selected;
    S32 af_mode_selected;
    S32 banding_selected;

    U16 zoom_index;
    MMI_BOOL is_loaded;
} mmi_barcodereader_camera_setting_cntx_struct;

typedef struct
{
    /* camera setting - 8 byte */
    U16 flash;
    U16 ev;
    U16 af_mode;
    U16 storage;
    U16 banding;

    /* reserve 22 bytes */
    U16 reserved1;
    U16 reserved2;
    U16 reserved3;
    U16 reserved4;
    U16 reserved5;
    U16 reserved6;
    U16 reserved7;
    U16 reserved8;
    U16 reserved9;
    U16 reserved10;
} mmi_barcodereader_camera_record_setting_struct;

/***************************************************************************** 
* enum declare
*****************************************************************************/
typedef enum
{

#ifdef __MMI_BARCODEREADER_FLASH__
    MMI_BARCODEREADER_SETTING_FLASH,
#endif 

    MMI_BARCODEREADER_SETTING_EV,

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
    MMI_BARCODEREADER_SETTING_FOCUS_MODE,
#endif 

#ifdef __MMI_BARCODEREADER_BANDING__
    MMI_BARCODEREADER_SETTING_BANDING,
#endif 

    MMI_BARCODEREADER_SETTING_ITEM_COUNT
} mmi_barcodereader_setting_count_enum;

typedef enum
{
    MMI_BARCODEREADER_SETTING_FOCUS_MODE_AUTO,

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MACRO__
    MMI_BARCODEREADER_SETTING_FOCUS_MODE_MACRO,
#endif 

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
    MMI_BARCODEREADER_SETTING_FOCUS_MODE_MANUAL,
#endif 

    MMI_BARCODEREADER_SETTING_FOCUS_MODE_COUNT
} barcodereader_setting_focus_mode_enum;

/********************************************************************************************************************** 
* EV
**********************************************************************************************************************/
typedef enum
{

#ifdef __MMI_BARCODEREADER_EV_4__
    MMI_BARCODEREADER_SETTING_EV_N4,
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__

    MMI_BARCODEREADER_SETTING_EV_N3,
#endif /* __MMI_BARCODEREADER_EV_3__ */ 

#ifdef __MMI_BARCODEREADER_EV_2__
    MMI_BARCODEREADER_SETTING_EV_N2,
#endif 

    MMI_BARCODEREADER_SETTING_EV_N1,
    MMI_BARCODEREADER_SETTING_EV_0,
    MMI_BARCODEREADER_SETTING_EV_P1,

#ifdef __MMI_BARCODEREADER_EV_2__
    MMI_BARCODEREADER_SETTING_EV_P2,
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__
    MMI_BARCODEREADER_SETTING_EV_P3,
#endif 

#ifdef __MMI_BARCODEREADER_EV_4__
    MMI_BARCODEREADER_SETTING_EV_P4,
#endif 
    MMI_BARCODEREADER_SETTING_EV_COUNT
} barcodereader_setting_ev_enum;

/********************************************************************************************************************** 
* Flash
**********************************************************************************************************************/
typedef enum
{
    MMI_BARCODEREADER_SETTING_FLASH_OFF,
    MMI_BARCODEREADER_SETTING_FLASH_ON,
    MMI_BARCODEREADER_SETTING_FLASH_COUNT
} barcodereader_setting_flash_enum;

/********************************************************************************************************************** 
* Storage
**********************************************************************************************************************/
typedef enum
{
    MMI_BARCODEREADER_SETTING_STORAGE_PHONE,
    MMI_BARCODEREADER_SETTING_STORAGE_MEMORY_CARD,
    MMI_BARCODEREADER_SETTING_STORAGE_COUNT
} barcodereader_setting_storage_enum;

/********************************************************************************************************************** 
* Banding
**********************************************************************************************************************/
typedef enum
{
    MMI_BARCODEREADER_SETTING_BANDING_50HZ = 0,
    MMI_BARCODEREADER_SETTING_BANDING_60HZ,
    MMI_BARCODEREADER_SETTING_BANDING_COUNT
} barcodereader_setting_banding_enum;

#endif /* MMI_BARCODEREADER_CAMERA_SETTING_H */ 

