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
 *  BarcodeReaderCameraSettingResDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  barcodereader Camera Setting Resource Header File
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

#ifndef MMI_BARCODEREADER_CAMERA_SETTING_RES_DEF_H
#define MMI_BARCODEREADER_CAMERA_SETTING_RES_DEF_H

// #include "BarcodereaderCommonProt.h"
#define MMI_BARCODEREADER_CAMERA_RESOURCE_BASE (BARCODEREADER_BASE)

/***************************************************************************** 
* base ID enum
*****************************************************************************/
#define MMI_BARCODEREADER_EV_BASE                   (MMI_BARCODEREADER_CAMERA_RESOURCE_BASE + 20)
#define MMI_BARCODEREADER_FLASH_BASE                (MMI_BARCODEREADER_CAMERA_RESOURCE_BASE + 40)
#define MMI_BARCODEREADER_FOCUS_MODE_BASE           (MMI_BARCODEREADER_CAMERA_RESOURCE_BASE + 60)
#define MMI_BARCODEREADER_BANDING_BASE              (MMI_BARCODEREADER_CAMERA_RESOURCE_BASE + 80)
#define MMI_BARCODEREADER_MENU_BASE                 (MMI_BARCODEREADER_CAMERA_RESOURCE_BASE + 90)

/***************************************************************************** 
* string ID enum
*****************************************************************************/

typedef enum
{
    SCR_ID_BARCODEREADER_CAMERA_SETTING = MMI_BARCODEREADER_CAMERA_RESOURCE_BASE
} mmi_barcodereader_camera_scr_id_enum;

typedef enum
{
    STR_ID_BARCODEREADER_FLASH = MMI_BARCODEREADER_CAMERA_RESOURCE_BASE,
    STR_ID_BARCODEREADER_EV,
    STR_ID_BARCODEREADER_FOCUS_MODE,
    STR_ID_BARCODEREADER_BANDING,
    STR_ID_BARCODEREADER_CAMERA_SETTING,

    STR_ID_BARCODEREADER_ALL
} mmi_barcodereader_str_enum;

/***************** ev *******************/
typedef enum
{
    STR_ID_BARCODEREADER_EV_START = MMI_BARCODEREADER_EV_BASE,

#ifdef __MMI_BARCODEREADER_EV_4__
    STR_ID_BARCODEREADER_EV_N4,
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__
    STR_ID_BARCODEREADER_EV_N3,
#endif 

#ifdef __MMI_BARCODEREADER_EV_2__
    STR_ID_BARCODEREADER_EV_N2,
#endif 

    STR_ID_BARCODEREADER_EV_N1,
    STR_ID_BARCODEREADER_EV_0,
    STR_ID_BARCODEREADER_EV_P1,

#ifdef __MMI_BARCODEREADER_EV_2__
    STR_ID_BARCODEREADER_EV_P2,
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__
    STR_ID_BARCODEREADER_EV_P3,
#endif 

#ifdef __MMI_BARCODEREADER_EV_4__
    STR_ID_BARCODEREADER_EV_P4,
#endif 

    STR_ID_BARCODEREADER_EV_ALL
} mmi_barcodereader_ev_str_id_enum;

/***************** flash *******************/
typedef enum
{
    STR_ID_BARCODEREADER_FLASH_START = MMI_BARCODEREADER_FLASH_BASE,

//    STR_ID_BARCODEREADER_FLASH_OFF,
//    STR_ID_BARCODEREADER_FLASH_ON,

    STR_ID_BARCODEREADER_FLASH_ALL
} mmi_barcodereader_flash_str_id_enum;

/***************** focus mode *******************/
typedef enum
{
    STR_ID_BARCODEREADER_FOCUS_MODE_START = MMI_BARCODEREADER_FOCUS_MODE_BASE,
    STR_ID_BARCODEREADER_FOCUS_MODE_AUTO,
#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MACRO__
    STR_ID_BARCODEREADER_FOCUS_MODE_MACRO,
#endif 
#ifdef __MMI_BARCODEREADER_FOCUS_MODE_INFINITE__
    STR_ID_BARCODEREADER_FOCUS_MODE_INFINITE,
#endif 
#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
    STR_ID_BARCODEREADER_FOCUS_MODE_MANUAL,
#endif 

    STR_ID_BARCODEREADER_FOCUS_MODE_ALL
} mmi_barcodereader_af_mode_str_id_enum;

/***************** banding *******************/

typedef enum
{
    STR_ID_BARCODEREADER_BANDING_START = MMI_BARCODEREADER_BANDING_BASE,

    STR_ID_BARCODEREADER_BANDING_50HZ,
    STR_ID_BARCODEREADER_BANDING_60HZ,

    STR_ID_BARCODEREADER_BANDING_ALL
} mmi_banding_banding_str_id_enum;

/***************************************************************************** 
* image ID enum
*****************************************************************************/
/***************** ev *******************/
typedef enum
{
    IMG_ID_BARCODEREADER_OSD_EV_START = MMI_BARCODEREADER_EV_BASE,

#ifdef __MMI_BARCODEREADER_EV_4__
    IMG_ID_BARCODEREADER_OSD_EV_N4,
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__
    IMG_ID_BARCODEREADER_OSD_EV_N3,
#endif 

#ifdef __MMI_BARCODEREADER_EV_2__
    IMG_ID_BARCODEREADER_OSD_EV_N2,
#endif 

    IMG_ID_BARCODEREADER_OSD_EV_N1,
    IMG_ID_BARCODEREADER_OSD_EV_0,
    IMG_ID_BARCODEREADER_OSD_EV_P1,

#ifdef __MMI_BARCODEREADER_EV_2__
    IMG_ID_BARCODEREADER_OSD_EV_P2,
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__
    IMG_ID_BARCODEREADER_OSD_EV_P3,
#endif 

#ifdef __MMI_BARCODEREADER_EV_4__
    IMG_ID_BARCODEREADER_OSD_EV_P4,
#endif 

    IMG_ID_BARCODEREADER_OSD_EV_MAX,
    IMG_ID_BARCODEREADER_OSD_EV_MIN,

    IMG_ID_BARCODEREADER_OSD_EV_ALL
} mmi_barcodereader_ev_img_id_enum;

typedef enum
{
    IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_START = MMI_BARCODEREADER_FOCUS_MODE_BASE,

    IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_AUTO,

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MACRO__
    IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_MACRO,
#endif 

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
    IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_MANUAL,
#endif 

    IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_AUTO_SEL,

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MACRO__
    IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_MACRO_SEL,
#endif 

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
    IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_MANUAL_SEL,
#endif 

    IMG_ID_BARCODEREADER_OSD_FOCUS_MODE_ALL
} mmi_barcodereader_focus_mode_img_id_enum;

/***************** banding *******************/

typedef enum
{
    IMG_ID_BARCODEREADER_BANDING_START = MMI_BARCODEREADER_BANDING_BASE,

    IMG_ID_BARCODEREADER_BANDING_50HZ,
    IMG_ID_BARCODEREADER_BANDING_60HZ,

    IMG_ID_BARCODEREADER_BANDING_ALL
} mmi_banding_banding_img_id_enum;

typedef enum
{
    IMG_ID_BARCODEREADER_MENUICON_FLASH = MMI_BARCODEREADER_MENU_BASE,
    IMG_ID_BARCODEREADER_MENUICON_EV,
    IMG_ID_BARCODEREADER_MENUICON_FOCUS_MODE,
    IMG_ID_BARCODEREADER_MENUICON_BANDING,
    IMG_ID_BARCODEREADER_MENUICON_ALL
} mmi_barcodereader_menu_id_enum;

#endif /* MMI_BARCODEREADER_CAMERA_SETTING_RES_DEF_H */ 

