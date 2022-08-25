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
 *  BarcodeReaderResDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  QR Code Reader Applications v0.1
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef MMI_BARCODEREADER_RES_DEF_H
#define MMI_BARCODEREADER_RES_DEF_H

#ifndef MMI_BARCODEREADER_FEATURES_H
// #error "Include MMI_features_barcodereader.h before BarcodeReaderResDefs.h"
#endif 

#define MMI_BARCODEREADER_OP00_RESOURCE_BASE     (BARCODEREADER_BASE + 150)
// #define MMI_BARCODEREADER_FLASH_BASE     (MMI_BARCODEREADER_OP00_RESOURCE_BASE)
// #define MMI_BARCODEREADER_STORAGE_BASE     (BARCODEREADER_BASE + 10)

/***************************************************************************** 
* Typedef ENUM
*****************************************************************************/
typedef enum
{
    SCR_ID_BARCODEREADER_MAIN = MMI_BARCODEREADER_OP00_RESOURCE_BASE + 1,
    SCR_ID_BARCODEREADER_PREVIEW,
    SCR_ID_BARCODEREADER_FILELIST_STORAGE_SELECT,
    SCR_ID_BARCODEREADER_FILELIST,
    SCR_ID_BARCODEREADER_FILELIST_OPTION,
    SCR_ID_BARCODEREADER_SERVICE_SUMMARY,
    SCR_ID_BARCODEREADER_HELP,
    /* SCR_ID_BARCODEREADER_SETTING, */
    SCR_ID_BARCODEREADER_APP_PREVIEW,
    SCR_ID_BARCODEREADER_APP_PREVIEW_OPTION,
    SCR_ID_BARCODEREADER_TIP,
    SCR_ID_BARCODEREADER_EDITOR,
    SCR_ID_BARCODEREADER_ORDER_CONFIRM,
    SCR_ID_BARCODEREADER_URL,
    SCR_ID_BARCODEREADER_PHONEBOOK_MULTI_CONTENT_SEL,
    SCR_ID_BARCODEREADER_OPTION_STORAGE,
    SCR_ID_BARCODEREADER_OPTION,
    SCR_ID_BARCODEREADER_SAVE,

    SCR_ID_BARCODEREADER_ALL
} barcodereader_scr_id_enum;

/***************************************************************************** 
* Typedef IMAGE ID 
*****************************************************************************/
typedef enum
{
    /* QR code reader app */
    STR_ID_BARCODEREADER_APP_NAME = MMI_BARCODEREADER_OP00_RESOURCE_BASE + 1,
//    STR_ID_BARCODEREADER_PREVIEW,
//    STR_ID_BARCODEREADER_RECOGNIZE,
//    STR_ID_BARCODEREADER_SETTING,

    /* encoding error */
    STR_ID_BARCODEREADER_ENCODING_ERROR,
//    STR_ID_BARCODEREADER_DECODE_FAILED,

    /* option */
    STR_ID_BARCODEREADER_RESTORE_DEFAULT,
//    STR_ID_BARCODEREADER_STORAGE,

    /* Notify */
//    STR_ID_BARCODEREADER_NOTIFY_DISK_FULL,
//    STR_ID_BARCODEREADER_NOTIFY_WRITE_PROTECTION,
//    STR_ID_BARCODEREADER_NOTIFY_HW_NOT_READY,
//    STR_ID_BARCODEREADER_NOTIFY_ERROR,
//    STR_ID_BARCODEREADER_NOTIFY_RESTORE_DEFAULT_CONFIRM,
    STR_ID_BARCODEREADER_NOTIFY_CAPTURE_AND_DECODE,
    STR_ID_BARCODEREADER_NOTIFY_SEND_TO,
    STR_ID_BARCODEREADER_NOTIFY_CONTENT,

    /* Error String */
//    STR_ID_BARCODEREADER_ERROR_OVER_VERSION,
//    STR_ID_BARCODEREADER_ERROR_MEMORY_NOT_ENOUGH,
//    STR_ID_BARCODEREADER_ERROR_BROKEN_IMAGE,

    /* 23key rsk string "capture" */
    STR_ID_BARCODEREADER_RSK_CAPTURE,

    /* Applications */
//    STR_ID_BARCODEREADER_TO_CARD,
//    STR_ID_BARCODEREADER_TO_CONTENT,
//    STR_ID_BARCODEREADER_TO_BUSINESS,
//    STR_ID_BARCODEREADER_TO_EMAIL,
    STR_ID_BARCODEREADER_TO_SMS,
    STR_ID_BARCODEREADER_TO_GENERAL,

    /* Functions */
    STR_ID_BARCODEREADER_FUNC_SAVE_TO_FOLDER,
    STR_ID_BARCODEREADER_FUNC_SEND_BY_SMS,
    STR_ID_BARCODEREADER_FUNC_SAVE_SMS,
    STR_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK,
    STR_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL,
    STR_ID_BARCODEREADER_FUNC_OPEN_URL,
    STR_ID_BARCODEREADER_FUNC_SAVE_URL,
    STR_ID_BARCODEREADER_FUNC_ORDER,
//    STR_ID_BARCODEREADER_FUNC_MAKE_CALL,
    STR_ID_BARCODEREADER_FUNC_SAVE_EMAIL,
    STR_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL,

//    STR_ID_BARCODEREADER_FUNC_EXIT,
    STR_ID_BARCODEREADER_FUNC_EDIT_BY_MMS,
    STR_ID_BARCODEREADER_FUNC_EDIT_BY_SMS,

    /* misc */
    STR_ID_BARCODEREADER_ORDER_CONFIRM,
    STR_ID_BARCODEREADER_ORDER_ATTENTION,

    /* append barcode */
//    STR_ID_BARCODEREADER_RSK_CONTINUE,
//    STR_ID_BARCODEREADER_LSK_RESET,
    STR_ID_BARCODEREADER_HELP_WRONG_SERIES,
    STR_ID_BARCODEREADER_HELP_DUPLICATED_CODE,
    STR_ID_BARCODEREADER_HELP_APPEND_BARCODE,
    STR_ID_BARCODEREADER_HELP_DECODE_NEXT,
    STR_ID_BARCODEREADER_SAVING,

    STR_ID_BARCODEREADER_STORAGE_PHONE,
    STR_ID_BARCODEREADER_STORAGE_MEMORY_CARD,

    /* Total string count */
    STR_ID_BARCODEREADER_TOTAL_COUNT
} barcodereader_str_id_enum;

typedef enum
{
    IMG_ID_BARCODEREADER_APP_ICON = MMI_BARCODEREADER_OP00_RESOURCE_BASE + 1,

    /******************************************
    * Menu Icon 
    *******************************************/
    IMG_ID_BARCODEREADER_PREVIEW_ICON,
#ifdef __MMI_BARCODEREADER_OPERATOR1__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_BARCODEREADER_OPERATOR1__ */ 
    /******************************************
    * Menu Icon 
    *******************************************/
    IMG_ID_BARCODEREADER_MENUICON_STORAGE,

    /******************************************
    * OSD Icon 
    *******************************************/
    IMG_ID_BARCODEREADER_OSD_EV_INC,
    IMG_ID_BARCODEREADER_OSD_EV_INC_SEL,
    IMG_ID_BARCODEREADER_OSD_EV_DEC,
    IMG_ID_BARCODEREADER_OSD_EV_DEC_SEL,
    IMG_ID_BARCODEREADER_OSD_MF_INC,
    IMG_ID_BARCODEREADER_OSD_MF_INC_SEL,
    IMG_ID_BARCODEREADER_OSD_MF_DEC,
    IMG_ID_BARCODEREADER_OSD_MF_DEC_SEL,
    IMG_ID_BARCODEREADER_OSD_MF_BAR,
    IMG_ID_BARCODEREADER_OSD_MF_SLIDER,
    IMG_ID_BARCODEREADER_OSD_CAPTURE,
    IMG_ID_BARCODEREADER_OSD_CAPTURE_SEL,

   /******************************************
   * MISC
   *******************************************/
    IMG_ID_BARCODEREADER_PREVIEW_SUBLCD_ICON,
    IMG_ID_BARCODEREADER_PREVIEW_BACKGROUND,

    /******************************************
    * FUNCS
    *******************************************/
    /* Applications */
    IMG_ID_BARCODEREADER_TO_CARD,
    IMG_ID_BARCODEREADER_TO_CONTENT,
    IMG_ID_BARCODEREADER_TO_BUSINESS,
    IMG_ID_BARCODEREADER_TO_EMAIL,
    IMG_ID_BARCODEREADER_TO_SMS,
    IMG_ID_BARCODEREADER_TO_GENERAL,

    /* Functions */
    IMG_ID_BARCODEREADER_FUNC_SAVE,
    IMG_ID_BARCODEREADER_FUNC_EXIT,
    IMG_ID_BARCODEREADER_FUNC_SAVE_TO_PHONEBOOK,
    IMG_ID_BARCODEREADER_FUNC_EDIT_BY_MMS,
    IMG_ID_BARCODEREADER_FUNC_EDIT_BY_SMS,
    IMG_ID_BARCODEREADER_FUNC_EDIT_BY_EMAIL,
    IMG_ID_BARCODEREADER_FUNC_ORDER,
    IMG_ID_BARCODEREADER_FUNC_SAVE_URL,
    IMG_ID_BARCODEREADER_FUNC_OPEN_URL,
    IMG_ID_BARCODEREADER_FUNC_SEND_BY_EMAIL,
    IMG_ID_BARCODEREADER_FUNC_SEND_BY_SMS,
    IMG_ID_BARCODEREADER_FUNC_MAKE_CALL,
    IMG_ID_BARCODEREADER_FUNC_SAVE_SMS,
    IMG_ID_BARCODEREADER_FUNC_SAVE_EMAIL,

    IMG_ID_BARCODEREADER_OSD_FLASH_START,
    IMG_ID_BARCODEREADER_OSD_FLASH_OFF,
    IMG_ID_BARCODEREADER_OSD_FLASH_ON,
    IMG_ID_BARCODEREADER_OSD_FLASH_OFF_SEL,
    IMG_ID_BARCODEREADER_OSD_FLASH_ON_SEL,
    IMG_ID_BARCODEREADER_OSD_FLASH_END,

    IMG_ID_BARCODEREADER_OSD_STORAGE_START,
    IMG_ID_BARCODEREADER_OSD_STORAGE_PHONE,
    IMG_ID_BARCODEREADER_OSD_STORAGE_MEMORY_CARD,
    IMG_ID_BARCODEREADER_OSD_STORAGE_PHONE_SEL,
    IMG_ID_BARCODEREADER_OSD_STORAGE_MEMORY_CARD_SEL,
    IMG_ID_BARCODEREADER_OSD_STORAGE_OTG_1,
    IMG_ID_BARCODEREADER_OSD_STORAGE_OTG_2,
    IMG_ID_BARCODEREADER_OSD_STORAGE_OTG_3,
    IMG_ID_BARCODEREADER_OSD_STORAGE_OTG_4,
    IMG_ID_BARCODEREADER_OSD_STORAGE_OTG_5,
    IMG_ID_BARCODEREADER_OSD_STORAGE_OTG_6,
    IMG_ID_BARCODEREADER_OSD_STORAGE_OTG_7,
    IMG_ID_BARCODEREADER_OSD_STORAGE_OTG_8,
    IMG_ID_BARCODEREADER_OSD_STORAGE_END,

    IMG_ID_BARCODEREADER_TOTAL_COUNT
} barcodereader_img_id_enum;

#endif /* MMI_BARCODEREADER_RES_DEF_H */ /* _MMI_BARCODEREADER_RES_DEF_H_ */                                                                     /* _CAMERA_RES_DEF_H_ */

