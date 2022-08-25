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
 * EmsMiscell.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI SMS APP.
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
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
 /**************************************************************

   FILENAME : EmsMiscell.c

   PURPOSE     : Dislay all EMS objects(Manufacture picture, 
               User defined picture, Predefined animation, Usedefiend animation,
               Manufacturer melodies, Usedefined melodies, Predefined sound.)

   REMARKS     : nil

   AUTHOR      : Hiran, Magesh k

   DATE     : 

**************************************************************/
#include "MMI_features.h"

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "custom_mmi_default_value.h"
#include "fs_errcode.h"
#include "gui_data_types.h"
#include "fs_type.h"
#include "fs_func.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "kal_general_types.h"
#include "string.h"
#include "wgui_categories_ems.h"
#include "CustDataRes.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "FileMgrResDef.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "wgui_categories_util.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_categories_list.h"
#include "gui_typedef.h"
#include "TimerEvents.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "gui_config.h"
#include "gui.h"
#include "wgui_draw_manager.h"
#include "EmsMiscell.h"
#include "SmsAppType.h"
#include "FileMgrType.h"
#include "mmi_rp_app_sms_def.h"

/* ...Add MSG header */
#include "MessagesResourceData.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SMsGuiInterfaceType.h"
#include "ProfilesSrvGprot.h"
#include "ems.h"
#include "wgui_ems.h"
#include "SmsSrvGprot.h"
#include "FileMgrSrvGProt.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
 #endif /* __USB_IN_NORMAL_MODE__ */



#include "SmsAppGprot.h"
#include "SmsAppProt.h"
#include "FileMgrCuiGProt.h"
#include "Filemgrcuigprot.h"

#ifdef __MMI_SMS_APP_EMS_SUPPORT__
/*  */
#ifndef NVRAM_EMS_MY_PICTURE_NAME_RECORD_SIZE
#define NVRAM_EMS_MY_PICTURE_NAME_RECORD_SIZE   140
#endif 

#ifndef NVRAM_EMS_MY_ANIMATION_NAME_RECORD_SIZE
#define NVRAM_EMS_MY_ANIMATION_NAME_RECORD_SIZE 140
#endif 

#if defined(__MMI_IMELODY_SUPPORT__)
#ifndef NVRAM_EMS_MY_MELODY_NAME_RECORD_SIZE
#define NVRAM_EMS_MY_MELODY_NAME_RECORD_SIZE 140
#endif 
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 

#define   MESSAGES_ONE_SEC_TIME_OUT     1000

#define   MAX_EMS_OBJECT_LIST_DISPLAY     15
#define   MAX_EMS_PREDEFINED_ANIMATION    15
#define   MAX_EMS_PREDEFINED_SOUND     10
#define   MAX_EMS_USER_AUDO    5
#ifdef __EMS_REL5__
#define   MAX_EMS_OBJECT_INSERT_SIZE            1588
#else /* __EMS_REL5__ */ 
#define   MAX_EMS_OBJECT_INSERT_SIZE               128
#endif /* __EMS_REL5__ */ 

/*  */
#define STR_EMS_PICTURE_OBJECT_FILE_NAME_EXTN_ID   ".ems"
#define STR_EMS_ANIMATION_OBJECT_FILE_NAME_EXTN_ID ".anm"
#define STR_EMS_IMELODY_OBJECT_FILE_NAME_EXTN_ID   ".imy"
#if (defined(__MMI_FILE_MANAGER__))
#define STR_EMS_PIC_A_ANIM_OBJECT_FILE_NAME_INIT_PATH_ID       FMGR_DEFAULT_FOLDER_IMAGES       /* "USER\\image\\ems\\" */
#define STR_EMS_IMELODY_OBJECT_FILE_NAME_INIT_PATH_ID          FMGR_DEFAULT_FOLDER_AUDIO        /* "USER\\sound\\ems\\" */
#else /* (defined(__MMI_FILE_MANAGER__)) */ 
#define MAX_EMS_STR_FOLDER_LEN 30
#define STR_EMS_USER_FOLDER_ID "c:\\USER\\"
#define STR_EMS_IMAGE_FOLDER_ID "image\\"
#define STR_EMS_IMELODY_FOLDER_ID "sound\\"
#define STR_EMS_FOLDER_ID "ems\\"
#define STR_EMS_PIC_A_ANIM_OBJECT_FILE_NAME_INIT_PATH_ID       "c:\\USER\\image\\ems\\" /* SYNC with above define values ! */
#define STR_EMS_IMELODY_OBJECT_FILE_NAME_INIT_PATH_ID          "c:\\USER\\sound\\ems\\" /* SYNC with above define values ! */
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 
/* MTK Joy added for file names, 1128 */
/* MTK end */

extern void (*EMS_inputbox_input_callback) (void);
#endif /* __MMI_SMS_APP_EMS_SUPPORT__ */


#if defined(__MMI_SMS_APP_EMS_SUPPORT__) || defined(__MMI_MESSAGE_SMS_HILITE_VIEWER__) || defined(__MMI_MESSAGE_SMS_USE_DETAIL__)

#ifdef __EMS_REL5__
#define   MAX_CURR_EMS_OBJECT_DATA_BUFF            1588+12
#else /* __EMS_REL5__ */ 
#define   MAX_CURR_EMS_OBJECT_DATA_BUFF            128+12
#endif /* __EMS_REL5__ */ 

#if defined (__MMI_FILE_MANAGER__)
#define   MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN         SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN 
#define   MAX_EMS_DOWNLOAD_OBJECT_NAME_INIT_PATH   SRV_FMGR_PATH_MAX_LEN
#define   MAX_EMS_DOWNLOAD_OBJECT_NAME_EXTN_LEN SRV_FMGR_PATH_MAX_FILE_EXT_LEN
#define  MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN       SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN 
#else /* defined (__MMI_FILE_MANAGER__) */
#define MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN        13
#define MAX_EMS_DOWNLOAD_OBJECT_NAME_INIT_PATH	30	
#define MAX_EMS_DOWNLOAD_OBJECT_NAME_EXTN_LEN	5	
#define MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN		MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN + MAX_EMS_DOWNLOAD_OBJECT_NAME_INIT_PATH + MAX_EMS_DOWNLOAD_OBJECT_NAME_EXTN_LEN	
#endif /* defined (__MMI_FILE_MANAGER__) */

#if defined(__MMI_SMS_APP_EMS_SUPPORT__) 
static S32 userDefinedObjectDataSize = 0;
static U8 userDefinedObjectDataBuff[MAX_CURR_EMS_OBJECT_DATA_BUFF] = {0, 0};
static EMS_OBJECT_DISPLAY_STATE currEmsObjectDisplayListState;
static U8 userEmsObjectNameInput[(MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN + 1) * ENCODING_LENGTH] = {0, 0};
#endif
#endif /* defined(__MMI_SMS_APP_EMS_SUPPORT__) || defined(__MMI_MESSAGE_SMS_HILITE_VIEWER__) */

#if defined (__MMI_VCARD__) || defined (__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
#ifndef MAX_EMS_OBJECT_INSERT_SIZE
#ifdef __EMS_REL5__
#define   MAX_EMS_OBJECT_INSERT_SIZE               1588
#else 
#define   MAX_EMS_OBJECT_INSERT_SIZE               128
#endif 
#endif /* MAX_EMS_OBJECT_INSERT_SIZE */ 
#ifndef MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN
#define  MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN          260+41       /* SRV_FMGR_PATH_MAX_LEN + SRV_FMGR_PATH_MAX_FILE_NAME_LEN */
#endif 
#endif /* defined (__MMI_VCARD__) || defined (__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__) */ 
/*  */

#ifdef __MMI_SMS_APP_EMS_SUPPORT__
U16 PredefinedAnimationStrIDs[] =   /* Predefined Animations */
{
    STR_PREDEFINED_ANIMATION_0,
    STR_PREDEFINED_ANIMATION_1,
    STR_PREDEFINED_ANIMATION_2,
    STR_PREDEFINED_ANIMATION_3,
    STR_PREDEFINED_ANIMATION_4,
    STR_PREDEFINED_ANIMATION_5,
    STR_PREDEFINED_ANIMATION_6,
    STR_PREDEFINED_ANIMATION_7,
    STR_PREDEFINED_ANIMATION_8,
    STR_PREDEFINED_ANIMATION_9,
    STR_PREDEFINED_ANIMATION_10,
    STR_PREDEFINED_ANIMATION_11,
    STR_PREDEFINED_ANIMATION_12,
    STR_PREDEFINED_ANIMATION_13,
    STR_PREDEFINED_ANIMATION_14
};
const U16 PredefinedSoundStrIDs[] = /* Predefined Sounds */
{
    STR_PREDEFINED_SOUND_0,
    STR_PREDEFINED_SOUND_1,
    STR_PREDEFINED_SOUND_2,
    STR_PREDEFINED_SOUND_3,
    STR_PREDEFINED_SOUND_4,
    STR_PREDEFINED_SOUND_5,
    STR_PREDEFINED_SOUND_6,
    STR_PREDEFINED_SOUND_7,
    STR_PREDEFINED_SOUND_8,
    STR_PREDEFINED_SOUND_9
};
U16 ManufacturerPictureStrIDs[] =   /* ManufacturerPicture Str IDs */
{
    STR_MANUFACTURER_PICTURE_0,
    STR_MANUFACTURER_PICTURE_1,
    STR_MANUFACTURER_PICTURE_2,
    STR_MANUFACTURER_PICTURE_3,
    STR_MANUFACTURER_PICTURE_4,
    STR_MANUFACTURER_PICTURE_5,
    STR_MANUFACTURER_PICTURE_6,
    STR_MANUFACTURER_PICTURE_7,
    STR_MANUFACTURER_PICTURE_8,
    STR_MANUFACTURER_PICTURE_9
};
const U16 ManufacturerMelodiesStrIDs[] =    /* Manufacturer Melodies Str IDs */
{
    STR_MANUFACTURER_MELODIES_0,
    STR_MANUFACTURER_MELODIES_1,
    STR_MANUFACTURER_MELODIES_2,
    STR_MANUFACTURER_MELODIES_3,
    STR_MANUFACTURER_MELODIES_4,
    STR_MANUFACTURER_MELODIES_5,
    STR_MANUFACTURER_MELODIES_6,
    STR_MANUFACTURER_MELODIES_7,
    STR_MANUFACTURER_MELODIES_8,
    STR_MANUFACTURER_MELODIES_9
};

static U16 preDefinedObjectIds[MAX_EMS_OBJECT_LIST_DISPLAY] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
static U8 *userDefinedObjectDataPtrs[MAX_EMS_OBJECT_LIST_DISPLAY];
static S32 currObjectListHiliteIndex = 0;
static U8 currMaxEmsObjectList = 0;
static U8 currMaxEmsPictureObjects = 0;

static U8 *emsObjectNameWhenPreview = NULL;
static U8 IsAllowed = FALSE;
static S32 listOfIsAllowedData[MAX_EMS_OBJECT_LIST_DISPLAY];

/*  */
static EMSObject *previewObjectListPtr = NULL;
static S32 nObjectLists = 0;
static S32 currObjectIndex = 0;

static MMI_ID mmi_ems_object_name_edit_gid;


#ifdef __MMI_FILE_MANAGER__
static S32 ems_object_file_error_code = FS_NO_ERROR;
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 

/* MTK end */
#if (defined(__MMI_FILE_MANAGER__))
void mmi_ems_add_object_from_fm(void);
void mmi_ems_preview_object_from_fm(PU16 filePath, S32 is_short);
EMSTATUS mmi_ems_fm_open_file(S8 *emsObjectFileNameBuf, EMS_OBJECT_DISPLAY_STATE emsObjectType);
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 

extern void handle_category28_input(void);

extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);

#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
extern mmi_sms_hilite_struct hilite_cntx;
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */
static MMI_ID mmi_ems_gid = GRP_ID_INVALID;

static void mmi_ems_entry_object_list(void);
static void mmi_ems_entry_pre_view_object(void);
static void mmi_ems_change_object_title_with_index(S32 nIndex);
static void mmi_ems_get_object_hilite_index(S32 nIndex);
static S8 *MessagesGetString(S8 *pathStr);

#if defined(__MMI_IMELODY_SUPPORT__)
static void mmi_ems_paly_menufacturer_imelody(void);
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
static void mmi_ems_play_menufacturer_sound(void);
static void mmi_ems_stop_imelody_and_sound(void);
static void mmi_ems_save_object_name_and_download(void);
static mmi_ret mmi_ems_object_name_edit_proc(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_set_cur_object_display_list_state
 * DESCRIPTION
 *  Set object state
 * PARAMETERS
 *  userDefinedObjectDataType       [IN]        Object data type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_set_cur_object_display_list_state(U8 userDefinedObjectDataType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (userDefinedObjectDataType)
    {
        case EMS_USERDEFINED_PICTURE:
            currEmsObjectDisplayListState = EMS_OBJECT_MY_PICTURE_STATE;
            break;
        case EMS_USERDEFINED_ANIMATION:
            currEmsObjectDisplayListState = EMS_OBJECT_MY_ANIMATION_STATE;
            break;
            /* MTK Joy added for customization, 1014 */
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_USERDEFINED_MELODY:
            currEmsObjectDisplayListState = EMS_OBJECT_MY_MELODY_STATE;
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            /* MTK end */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_object_name_edit
 * DESCRIPTION
 *  Entry object name edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ems_object_name_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 emsObjectFileNameBuf[(MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN + 1) * ENCODING_LENGTH] = {0, 0};
    mmi_id ems_gid;
    S32 remaining_lenth = MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN;
    U16 driveName;
    S8 temp[4];
    UI_character_type dir_ems_root[4];
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ems_gid = mmi_frm_group_create(
                            mmi_ems_gid,
                            GRP_ID_AUTO_GEN,
                            mmi_ems_object_name_edit_proc,
                            0);
                            
    mmi_frm_group_enter(ems_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* calculate length remained */
#if (defined(__MMI_FILE_MANAGER__))
   driveName = SRV_FMGR_PUBLIC_DRV;
   sprintf(temp, "%c:\\", (S8) driveName);
   mmi_asc_to_ucs2((S8*) dir_ems_root, temp);
   
   mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);   
   switch (currEmsObjectDisplayListState)
    {

        case EMS_OBJECT_MY_PICTURE_STATE:   /* All Download Objects Only... */
            mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
            mmi_ucs2cat((s8*)emsObjectFileNameBuf, (S8*) MessagesGetString((S8*) STR_EMS_PICTURE_OBJECT_FILE_NAME_EXTN_ID));
            break;
        case EMS_OBJECT_MY_ANIMATION_STATE:
            mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
            mmi_ucs2cat((s8*)emsObjectFileNameBuf, (S8*) MessagesGetString((S8*) STR_EMS_ANIMATION_OBJECT_FILE_NAME_EXTN_ID));
            break;
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MY_MELODY_STATE:
            mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_AUDIO);
            mmi_ucs2cat((s8*)emsObjectFileNameBuf, (S8*) MessagesGetString((S8*) STR_EMS_IMELODY_OBJECT_FILE_NAME_EXTN_ID));
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
    }

    remaining_lenth = (MAX_EMS_DOWNLOAD_OBJECT_NAME_INIT_PATH - mmi_ucs2strlen((const CHAR *)emsObjectFileNameBuf));
    if (remaining_lenth >= MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN)
    {
        remaining_lenth = MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN;
    }
#endif
    mmi_ems_object_name_edit_gid = cui_filename_editor_create(ems_gid, 
        (WCHAR *)userEmsObjectNameInput, 
        (remaining_lenth + 1)*ENCODING_LENGTH,
        remaining_lenth,
        NULL,
        NULL);

    if (mmi_ems_object_name_edit_gid != GRP_ID_INVALID)
    {
        cui_filename_editor_set_title(mmi_ems_object_name_edit_gid, STR_GLOBAL_FILENAME, IMG_SMS_ENTRY_SCRN_CAPTION);
        cui_filename_editor_run(mmi_ems_object_name_edit_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_object_name_edit_proc
 * DESCRIPTION
 *  Proc function of fmgr file name group.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_ems_object_name_edit_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
        {
            cui_filename_editor_result_event_struct *param =
                        (cui_filename_editor_result_event_struct*)evt;
            if (param->result > 0)
            {
                cui_filename_editor_get_fullpath(
                                    mmi_ems_object_name_edit_gid, 
                                    (WCHAR *)userEmsObjectNameInput,
                                    (MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN + 1)*ENCODING_LENGTH);
            #ifdef __MMI_SMS_APP_EMS_SUPPORT__
                mmi_ems_save_object_name_and_download(); /* Close CUI if save OK, determined inside this function */
            #else
                mmi_sms_display_popup_ext(
                    STR_GLOBAL_NOT_SUPPORTED,
                    MMI_EVENT_FAILURE);
            #endif
            }
            else
            {
                if (0 == param->result) /* request by app to close */
                {
                    cui_filename_editor_close(mmi_ems_object_name_edit_gid);
                }
            }
            break;
        }

    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_pre_entry_edit_object_name
 * DESCRIPTION
 *  Before entry save object name, get object type and size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_pre_entry_edit_object_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
    EMSObject *pObject;
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ 
*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    memset(&userEmsObjectNameInput, 0, (MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
    memset(&userDefinedObjectDataBuff, 0, MAX_CURR_EMS_OBJECT_DATA_BUFF);

#if defined(__MMI_MESSAGE_SMS_HILITE_VIEWER__)
    pObject = hilite_cntx.hilite_list[hilite_cntx.currHiliteItemIndex].object;

    switch (pObject->Type)
    {
        case EMS_TYPE_PIC:
            currEmsObjectDisplayListState = EMS_OBJECT_MY_PICTURE_STATE;
            userDefinedObjectDataSize = pObject->data->picture.pdu_length + 9;
            userDefinedObjectDataBuff[0] = (U8) EMS_USERDEFINED_PICTURE;
            userDefinedObjectDataBuff[1] = (U8) pObject->data->picture.bitsPerPixel;
            userDefinedObjectDataBuff[2] = (U8) pObject->data->picture.attribute;
            userDefinedObjectDataBuff[3] = (U8) pObject->data->picture.hDim;
            userDefinedObjectDataBuff[4] = (U8) (pObject->data->picture.hDim >> 8);
            userDefinedObjectDataBuff[5] = (U8) pObject->data->picture.vDim;
            userDefinedObjectDataBuff[6] = (U8) (pObject->data->picture.vDim >> 8);
            userDefinedObjectDataBuff[7] = (U8) pObject->data->picture.pdu_length;
            userDefinedObjectDataBuff[8] = (U8) (pObject->data->picture.pdu_length >> 8);
            memcpy(
                userDefinedObjectDataBuff + 9,
                pObject->data->picture.pdu,
                pObject->data->picture.pdu_length);
            break;
        case EMS_TYPE_USERDEF_ANM:
            currEmsObjectDisplayListState = EMS_OBJECT_MY_ANIMATION_STATE;
            userDefinedObjectDataSize = pObject->data->animation.pdu_length + 12;
            userDefinedObjectDataBuff[0] = (U8) EMS_USERDEFINED_ANIMATION;
            userDefinedObjectDataBuff[1] = (U8) pObject->data->animation.bitsPerPixel;
            userDefinedObjectDataBuff[2] = (U8) pObject->data->animation.attribute;
            userDefinedObjectDataBuff[3] = (U8) pObject->data->animation.cFrame;
            userDefinedObjectDataBuff[4] = (U8) pObject->data->animation.cRepeat;
            userDefinedObjectDataBuff[5] = (U8) pObject->data->animation.Duration;
            userDefinedObjectDataBuff[6] = (U8) pObject->data->animation.hDim;
            userDefinedObjectDataBuff[7] = (U8) (pObject->data->animation.hDim >> 8);
            userDefinedObjectDataBuff[8] = (U8) pObject->data->animation.vDim;
            userDefinedObjectDataBuff[9] = (U8) (pObject->data->animation.vDim >> 8);
            userDefinedObjectDataBuff[10] = (U8) pObject->data->animation.pdu_length;
            userDefinedObjectDataBuff[11] = (U8) (pObject->data->animation.pdu_length >> 8);
            memcpy(
                userDefinedObjectDataBuff + 12,
                pObject->data->animation.pdu,
                pObject->data->animation.pdu_length);
            break;
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_TYPE_USERDEF_SND:
            currEmsObjectDisplayListState = EMS_OBJECT_MY_MELODY_STATE;
            userDefinedObjectDataSize = pObject->data->sound.pdu_length;
            memcpy(
                userDefinedObjectDataBuff,
                pObject->data->sound.pdu,
                pObject->data->sound.pdu_length);
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
    }
#elif defined (__MMI_SMS_APP_EMS_SUPPORT__)
    mmi_ems_set_cur_object_display_list_state(GetCategory143DataType());
    userDefinedObjectDataSize = GetCategory143DataSize();
#if defined(__MMI_IMELODY_SUPPORT__)
    if (currEmsObjectDisplayListState == EMS_OBJECT_MY_MELODY_STATE)
    {
        U8 userDefinedObjectDataBuffTemp[MAX_CURR_EMS_OBJECT_DATA_BUFF];

        GetCategory143Data(userDefinedObjectDataBuffTemp);
        EMS_userdefined_melody_detach_header(
            userDefinedObjectDataBuffTemp,
            userDefinedObjectDataBuff,
            &userDefinedObjectDataSize);
    }
    else
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
    {
        GetCategory143Data(userDefinedObjectDataBuff);
    }
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ 
*/
    mmi_ems_object_name_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_insert_object_error_hdlr
 * DESCRIPTION
 *  Handle error case when insert object
 * PARAMETERS
 *  emsObjectStatus     [IN]        Insert status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_insert_object_error_hdlr(EMSTATUS emsObjectStatus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* hander error case, if could not insert objects. */
    switch (emsObjectStatus)
    {
        case EMS_OK:
            break;
        case EMS_NO_MEMORY:
            mmi_sms_display_popup_ext(
                STR_EMS_OBJECT_NUM_EXCEED,
                MMI_EVENT_FAILURE);
            break;

        case EMS_NO_SPACE:
            mmi_sms_display_popup_ext(
                STR_NO_SPACE_TO_INSERT_OBJECT,
                MMI_EVENT_FAILURE);
            break;

        case EMS_INVALID_OBJECT:
    #if (defined(__MMI_FILE_MANAGER__))
            mmi_sms_display_popup_ext(
                STR_GLOBAL_UNSUPPORTED_FORMAT,
                MMI_EVENT_FAILURE);
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_sms_display_popup_ext(
                STR_GLOBAL_NOT_SUPPORTED,
                MMI_EVENT_FAILURE);
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
            break;

        case EMS_EMS_DATA_EXCEEDED:
            mmi_sms_display_popup_ext(
                STR_SMS_FAILURE_MSG_LEN_EXCEEDED,
                MMI_EVENT_FAILURE);
            break;

        case EMS_NULL_POINTER:
            mmi_sms_display_popup_ext(
                STR_READ_SMS_DATA_FAILED,
                MMI_EVENT_FAILURE);
            break;

        case EMS_NO_ALIGNMENT_FMT:
            mmi_sms_display_popup_ext(
                STR_SMS_OBJECT_EXISTENCE_ERROR,
                MMI_EVENT_FAILURE);
            break;
        
        default /* EMS_UNSPECIFIED_ERROR */ :
            mmi_sms_display_popup_ext(
                STR_GLOBAL_NOT_SUPPORTED,
                MMI_EVENT_FAILURE);
            break;
    }
}


/**************************************************************
            text format
**************************************************************/

/*****************************************************************************
 * FUNCTION
 *  InitUserDefinedObjectDataPtrs
 * DESCRIPTION
 *  Init user defined object data pointers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitUserDefinedObjectDataPtrs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_EMS_OBJECT_LIST_DISPLAY; index++)
    {
        userDefinedObjectDataPtrs[index] = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  MessagesGetString
 * DESCRIPTION
 *  Get string in UCS2 format
 * PARAMETERS
 *  pathStr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static S8 *MessagesGetString(S8 *pathStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8 emsObjectFileNameStaticBuf[(MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN + 1) * ENCODING_LENGTH] = {0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(emsObjectFileNameStaticBuf, 0, (MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN + 1) * ENCODING_LENGTH);
    mmi_asc_to_ucs2(emsObjectFileNameStaticBuf, pathStr);
    return emsObjectFileNameStaticBuf;
}


/*****************************************************************************
 * FUNCTION
 *  GetEmsObjectDataSize
 * DESCRIPTION
 *  Get object data size
 * PARAMETERS
 *  void
 * RETURNS
 *  object data size
 *****************************************************************************/
S32 GetEmsObjectDataSize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IsAllowed = FALSE;
    switch (currEmsObjectDisplayListState)
    {
        case EMS_OBJECT_PICTURE_STATE:
            return EMS_check_predefined_picture_data_size(userDefinedObjectDataBuff, &IsAllowed);
        case EMS_OBJECT_MY_PICTURE_STATE:
            return EMS_check_userdefined_picture_size(userDefinedObjectDataBuff, &IsAllowed);
        case EMS_OBJECT_MY_ANIMATION_STATE:
            return EMS_check_userdefined_animation_size(userDefinedObjectDataBuff, &IsAllowed);
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MELODY_STATE:
            return EMS_check_predefined_melody_data_size(userDefinedObjectDataBuff, &IsAllowed);
        case EMS_OBJECT_MY_MELODY_STATE:
        case EMS_OBJECT_MY_MELODY_DOWNLOAD_APP_STATE:
            return EMS_check_userdefined_melody_size(userDefinedObjectDataBuff, &IsAllowed);
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        case EMS_OBJECT_MY_PICTURE_A_ANIMATION_DOWNLOAD_APP_STATE:
            if (currObjectListHiliteIndex < currMaxEmsPictureObjects)
            {
                return EMS_check_userdefined_picture_size(userDefinedObjectDataBuff, &IsAllowed);
            }
            else
            {
                return EMS_check_userdefined_animation_size(userDefinedObjectDataBuff, &IsAllowed);
            }
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_save_object_error_hdlr
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  emsObjectStatus     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_save_object_error_hdlr(EMSTATUS emsObjectStatus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (emsObjectStatus)
    {
        case EMS_OK:
            mmi_sms_display_popup_ext(
                STR_GLOBAL_SAVED,
                MMI_EVENT_EXPLICITLY_SAVED);
            break;
        case EMS_ALREADY_INITIALIZED:
            mmi_sms_display_popup_ext(
                STR_EMS_OBJECT_DUPLICATED_NAME_INPUT_AGAIN,
                MMI_EVENT_FAILURE);
            break;
        case EMS_NO_SPACE:
    #if (defined(__MMI_FILE_MANAGER__))
            mmi_sms_display_popup_ext(
                FMGR_FS_DISK_FULL_TEXT,
                MMI_EVENT_FAILURE);
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_sms_display_popup_ext(
                STR_GLOBAL_MEMORY_FULL,
                MMI_EVENT_FAILURE);
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
            break;
        case EMS_INVALID_FILE_NAME:
            mmi_sms_display_popup_ext(
                srv_fmgr_fs_error_get_string(FS_INVALID_FILENAME),
                MMI_EVENT_FAILURE);
            break;
            
        case EMS_EMPTY_FILE_NAME:
            mmi_sms_display_popup_ext(
                STR_GLOBAL_PLEASE_INPUT_THE_FILENAME,
                MMI_EVENT_FAILURE);
            break; 

        default:
		#ifdef __MMI_FILE_MANAGER__
			if (ems_object_file_error_code != FS_NO_ERROR)
			{
                mmi_sms_display_popup_ext(
                    srv_fmgr_fs_error_get_string(ems_object_file_error_code),
                    MMI_EVENT_FAILURE);

				ems_object_file_error_code = FS_NO_ERROR;
			}
			else
		#endif /* (defined(__MMI_FILE_MANAGER__)) */ 
			{
                mmi_sms_display_popup_ext(
                    STR_GLOBAL_UNFINISHED,
                    MMI_EVENT_FAILURE);
			}
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_skip_space
 * DESCRIPTION
 *  skip space in a string
 * PARAMETERS
 *  line        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
PS8 mmi_msg_skip_space(S8 *line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ptr;
    S32 i = 0, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = line;

    len = (mmi_ucs2strlen(line)) << 1;

    while (ptr[i] == ' ' && ptr[i + 1] == 0)
    {
        ptr += 2;
        if (i >= len)
        {
            break;
        }
    }
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  WriteDownloadObjectDataIntoFileSystem
 * DESCRIPTION
 *  Write object data into file system
 * PARAMETERS
 *  void
 * RETURNS
 *  write result
 *****************************************************************************/
EMSTATUS WriteDownloadObjectDataIntoFileSystem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 wByte = 0;
    S32 gWriteResult = 0;
    FS_HANDLE emsObjectFilePtr = 0;
    S8 emsObjectFileNameBuf[(MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN + 1) * ENCODING_LENGTH] = {0, 0};
    S8 *temptr = NULL;
#if (defined(__MMI_FILE_MANAGER__))
    U16 driveName;
    S8 temp[4];
    UI_character_type dir_ems_root[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptr = mmi_msg_skip_space((PS8)userEmsObjectNameInput);
    if (mmi_ucs2strlen(temptr) == 0)
    {
        return EMS_EMPTY_FILE_NAME;
    }
	if (srv_fmgr_path_is_filename_valid((WCHAR*)userEmsObjectNameInput) == FALSE)
	{
		return EMS_INVALID_FILE_NAME;
	}
    driveName = SRV_FMGR_PUBLIC_DRV;
    sprintf(temp, "%c:\\", (S8) driveName);
    mmi_asc_to_ucs2((S8*) dir_ems_root, temp);
#endif /* (defined(__MMI_FILE_MANAGER__)) */
    temptr = mmi_msg_skip_space((PS8)userEmsObjectNameInput);
    if (mmi_ucs2strlen(temptr) == 0)
    {
        return EMS_EMPTY_FILE_NAME;
    }
    switch (currEmsObjectDisplayListState)
    {
        case EMS_OBJECT_MY_PICTURE_STATE:   /* All Download Objects Only... */
    #if (defined(__MMI_FILE_MANAGER__))
            mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_ucs2cpy(
                (S8*) emsObjectFileNameBuf,
                (S8*) MessagesGetString((S8*) STR_EMS_PIC_A_ANIM_OBJECT_FILE_NAME_INIT_PATH_ID));
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) temptr);
            mmi_ucs2cat(
                (S8*) emsObjectFileNameBuf,
                (S8*) MessagesGetString((S8*) STR_EMS_PICTURE_OBJECT_FILE_NAME_EXTN_ID));
            break;
        case EMS_OBJECT_MY_ANIMATION_STATE:
    #if (defined(__MMI_FILE_MANAGER__))
            mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_ucs2cpy(
                (S8*) emsObjectFileNameBuf,
                (S8*) MessagesGetString((S8*) STR_EMS_PIC_A_ANIM_OBJECT_FILE_NAME_INIT_PATH_ID));
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) temptr);
            mmi_ucs2cat(
                (S8*) emsObjectFileNameBuf,
                (S8*) MessagesGetString((S8*) STR_EMS_ANIMATION_OBJECT_FILE_NAME_EXTN_ID));
            break;
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MY_MELODY_STATE:
    #if (defined(__MMI_FILE_MANAGER__))
            mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_AUDIO);
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_ucs2cpy(
                (S8*) emsObjectFileNameBuf,
                (S8*) MessagesGetString((S8*) STR_EMS_IMELODY_OBJECT_FILE_NAME_INIT_PATH_ID));
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) temptr);
            mmi_ucs2cat(
                (S8*) emsObjectFileNameBuf,
                (S8*) MessagesGetString((S8*) STR_EMS_IMELODY_OBJECT_FILE_NAME_EXTN_ID));
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
    }
    /* duplicated filename */
    emsObjectFilePtr = FS_Open((U16*)emsObjectFileNameBuf, FS_READ_ONLY);
    if (emsObjectFilePtr > 0)
    {
        FS_Close(emsObjectFilePtr);
        return EMS_ALREADY_INITIALIZED;
    }
    emsObjectFilePtr = FS_Open((U16*)emsObjectFileNameBuf, FS_READ_WRITE|FS_CREATE_ALWAYS);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_WRITE_DOWNLOAD_OBJECTDATA_INTO_FILE, emsObjectFilePtr);

    if (emsObjectFilePtr > 0)
    {
        gWriteResult = FS_Write(emsObjectFilePtr, (void*)userDefinedObjectDataBuff, userDefinedObjectDataSize, &wByte);
    	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_WRITE_DOWNLOAD_OBJECTDATA_INTO_FILE_1, gWriteResult);

        /* if(userDefinedObjectDataSize==wByte) success ele failure; */
        FS_Close(emsObjectFilePtr);
        if (gWriteResult < 0)
        {
            FS_Delete((U16*)emsObjectFileNameBuf);
            return EMS_NO_SPACE;
        }
        else
        {
            return EMS_OK;
        }
    }

    if (emsObjectFilePtr == FS_INVALID_FILENAME)
    {
        return EMS_INVALID_FILE_NAME;
    }
    else
    {
	#ifdef __MMI_FILE_MANAGER__
		ems_object_file_error_code = emsObjectFilePtr;
	#endif /* (defined(__MMI_FILE_MANAGER__)) */ 
        return EMS_UNSPECIFIED_ERROR;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  ReadDownloadObjectDataFromFileSystem
 * DESCRIPTION
 *  Read object data from file system
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  read result
 *****************************************************************************/
U8 ReadDownloadObjectDataFromFileSystem(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < 0)
    {
        MMI_ASSERT(0);
    }
    switch (currEmsObjectDisplayListState)
    {
        case EMS_OBJECT_PICTURE_STATE:
        {
            U8 *imagedata;
            U16 imageindex = IMG_EMS01_PIC + (U16) index;
            U16 imagedatasize;

            memset(&userDefinedObjectDataBuff, 0, MAX_CURR_EMS_OBJECT_DATA_BUFF);
            if (imageindex  > IMG_EMS010_PIC)
            {
                MMI_ASSERT(0);
            }
            imagedata = (U8*) GetImage(imageindex);
            imagedatasize = 9 + (*(imagedata + 7)) | (*(imagedata + 8)) << 8;
            memcpy(userDefinedObjectDataBuff, imagedata, imagedatasize);
            emsObjectNameWhenPreview = (U8*) GetString(ManufacturerPictureStrIDs[index]);
            return TRUE;
        }
    #ifdef __MMI_IMELODY_SUPPORT__
        case EMS_OBJECT_MELODY_STATE:
        {
            U8 userDefinedObjectDataBuffTemp[MAX_CURR_EMS_OBJECT_DATA_BUFF];
            U8 *audio_data;
            U8 audio_type;

            memset(&userDefinedObjectDataBuff, 0, MAX_CURR_EMS_OBJECT_DATA_BUFF);
            if (index > 4)
            {
                MMI_ASSERT(0);
            }
            audio_data = get_audio(AUD_ID_SMS_EMS_IMY1 + index, &audio_type, (U32 *)&userDefinedObjectDataSize);
            memcpy(userDefinedObjectDataBuff, audio_data, userDefinedObjectDataSize);
            EMS_predefined_melody_attach_header(
                userDefinedObjectDataBuff,
                userDefinedObjectDataBuffTemp,
                &userDefinedObjectDataSize);
            memcpy(userDefinedObjectDataBuff, userDefinedObjectDataBuffTemp, userDefinedObjectDataSize);
            return TRUE;
        }
    #endif /* __MMI_IMELODY_SUPPORT__ */ 
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  CallBackLoadUserDefinedObjectDataBuffPtr
 * DESCRIPTION
 *  Call back to get user defined object data
 * PARAMETERS
 *  index       [IN]        Object index
 * RETURNS
 *  data buffer pointer
 *****************************************************************************/
U8 *CallBackLoadUserDefinedObjectDataBuffPtr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ReadDownloadObjectDataFromFileSystem(index))
    {
        userDefinedObjectDataSize = GetEmsObjectDataSize();
        if (!whether_no_small_screen())
        {
            ChangeTitleString(emsObjectNameWhenPreview);
            draw_title();
        }
        return userDefinedObjectDataBuff;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetEmsObjectDataInsertStatus
 * DESCRIPTION
 *  Get object insert status
 * PARAMETERS
 *  index       [IN]        Object index
 * RETURNS
 *  insert status
 *****************************************************************************/
U16 GetEmsObjectDataInsertStatus(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ReadDownloadObjectDataFromFileSystem(index))
    {
        userDefinedObjectDataSize = GetEmsObjectDataSize();
        listOfIsAllowedData[index] = IsAllowed;
    }
    else
    {
        IsAllowed = 0;
        listOfIsAllowedData[index] = IsAllowed;
    }
    if (IsAllowed)
    {
        return EMS_CAN_INSERT_OBJECT_ID;
    }
    else
    {
        return EMS_CANNOT_INSERT_OBJECT_ID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetEmsObjectDataSizeHint
 * DESCRIPTION
 *  Get object data size hint
 * PARAMETERS
 *  index       [IN]        Object index
 * RETURNS
 *  hint data pointer
 *****************************************************************************/
U8 *GetEmsObjectDataSizeHint(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsAllowed)
    {
        U8 emsObjectDataSizeHintBuff[10] = { '\0', '\0' };
        memset(hintData[index], 0, MAX_SUB_MENU_HINT_SIZE);
        mmi_asc_to_ucs2((S8*) hintData[index], (S8*) emsObjectDataSizeHintBuff);
        return hintData[index];
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  GetEmsObjectDisplayListDetails
 * DESCRIPTION
 *  Get object display list
 * PARAMETERS
 *  lskStrID            [IN/OUT]        LSK string ID
 *  strItemListPtr      [IN/OUT]        String list pointer
 *  imgItemListPtr      [IN/OUT]        Image list pointer
 *  popUpList           [IN/OUT]        Popup list pointer
 * RETURNS
 *  void
 *****************************************************************************/
void GetEmsObjectDisplayListDetails(U16 *lskStrID, U8 **strItemListPtr, U16 *imgItemListPtr, U8 **popUpList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_GET_EMS_OBJECT_DISPLAY_LIST_DETAILS, currEmsObjectDisplayListState);
    switch (currEmsObjectDisplayListState)
    {
        case EMS_OBJECT_PICTURE_STATE:
            currMaxEmsObjectList = EmsPictureNum();
            *lskStrID = STR_GLOBAL_VIEW;
            for (index = 0; index < currMaxEmsObjectList; index++)
            {
                strItemListPtr[index] = (PU8) GetString((U16) ManufacturerPictureStrIDs[index]);
                imgItemListPtr[index] = GetEmsObjectDataInsertStatus(index);
                popUpList[index] = GetEmsObjectDataSizeHint(index);
            }
            break;
        case EMS_OBJECT_PREDEFINED_ANIMATION_STATE:
            currMaxEmsObjectList = MAX_EMS_PREDEFINED_ANIMATION;
            *lskStrID = STR_GLOBAL_VIEW;
            for (index = 0; index < currMaxEmsObjectList; index++)
            {
                strItemListPtr[index] = (PU8) GetString((U16) PredefinedAnimationStrIDs[index]);
                imgItemListPtr[index] = EMS_CAN_INSERT_OBJECT_ID;
                popUpList[index] = NULL;
            }
            break;
        #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MELODY_STATE:
            EnableDisableAudioPlayback();
            currMaxEmsObjectList = MAX_EMS_USER_AUDO;
            *lskStrID = STR_GLOBAL_OK;
            for (index = 0; index < currMaxEmsObjectList; index++)
            {
                strItemListPtr[index] = (PU8) GetString((U16) ManufacturerMelodiesStrIDs[index]);
                imgItemListPtr[index] = GetEmsObjectDataInsertStatus(index);
                popUpList[index] = GetEmsObjectDataSizeHint(index);
            }
            break;
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        case EMS_OBJECT_PREDEFINED_SOUND_STATE:
            EnableDisableAudioPlayback();
            currMaxEmsObjectList = MAX_EMS_PREDEFINED_SOUND;
            *lskStrID = STR_GLOBAL_OK;
            for (index = 0; index < currMaxEmsObjectList; index++)
            {
                strItemListPtr[index] = (PU8) GetString((U16) PredefinedSoundStrIDs[index]);
                imgItemListPtr[index] = EMS_CAN_INSERT_OBJECT_ID;
                popUpList[index] = NULL;
            }
            break;
        default:
            currMaxEmsObjectList = 0;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_entry_object_list
 * DESCRIPTION
 *  Entry object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategoryEMSScreen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_symbols,
                MMI_ID_TYPE *symbols,
                MMI_ID_TYPE *descriptions,
                S32 highlighted_item,
                U8 *history_buffer);
extern U16 EMS_predefined_images[];
extern U16 EMS_predefined_animations[];

void mmi_ems_entry_object_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 lskStrID = 0;
    U8 *guiBuffer = NULL;
    MMI_ID curr_gid = mmi_ems_gid;
    U8 *strItemList[MAX_EMS_OBJECT_LIST_DISPLAY
                    /* MTK Joy added for customization, 1014 */
#if defined(__MMI_IMELODY_SUPPORT__)
                    + MAXIMUM_DOWNLOAD_AUDIO + MAXIMUM_COMPOSED_RINGTONE
#endif 
                    /* MTK end */
        ];
    U16 imgItemList[MAX_EMS_OBJECT_LIST_DISPLAY
                    /* MTK Joy added for customization, 1014 */
#if defined(__MMI_IMELODY_SUPPORT__)
                    + MAXIMUM_DOWNLOAD_AUDIO + MAXIMUM_COMPOSED_RINGTONE
#endif 
                    /* MTK end */
        ];
    U8 *popUpList[MAX_EMS_OBJECT_LIST_DISPLAY
                  /* MTK Joy added for customization, 1014 */
#if defined(__MMI_IMELODY_SUPPORT__)
                  + MAXIMUM_DOWNLOAD_AUDIO + MAXIMUM_COMPOSED_RINGTONE
#endif 
                  /* MTK end */
        ];

#if (defined(__MMI_FILE_MANAGER__))
    U16 driveName;
    S8 temp[4];
    UI_character_type dir_ems_root[4];
    S8 emsObjectFileNameBuf[(MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN + 1) * ENCODING_LENGTH] = {0, 0};
    FMGR_FILTER filter;
    MMI_ID fmgr_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    driveName = SRV_FMGR_PUBLIC_DRV;
    sprintf(temp, "%c:\\", (S8) driveName);
    mmi_asc_to_ucs2((S8*) dir_ems_root, temp);

    mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 

    switch (currEmsObjectDisplayListState)
    {
            S32 path_status;
#if (defined(__MMI_FILE_MANAGER__))
        case EMS_OBJECT_MY_PICTURE_STATE:
            /* [Bear] 2004/6/23 - begin */
            FMGR_FILTER_INIT(&filter);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_EMS);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
            
            path_status = FS_CreateDir((U16*)emsObjectFileNameBuf);
            if ((path_status == FS_FILE_EXISTS) || (path_status == FS_NO_ERROR))
            {
                fmgr_gid = 
                    cui_file_selector_create(
                        mmi_ems_gid,
                        (const WCHAR *)emsObjectFileNameBuf,
                        &filter,
                        CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                        CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FOLDER | CUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON |CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);
                cui_file_selector_run(fmgr_gid);  
            }
            else
            {
                mmi_sms_display_popup_ext(srv_fmgr_fs_error_get_string(path_status), MMI_EVENT_FAILURE);
            }
            mmi_frm_scrn_close(curr_gid, SCR_ID_MSG_EMS_INSERT_OBJECT);
            /* [Bear] 2004/6/23 - end */
            break;

        case EMS_OBJECT_MY_ANIMATION_STATE:
            /* [Bear] 2004/6/23 - begin */
            FMGR_FILTER_INIT(&filter);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_ANM);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
            
            path_status = FS_CreateDir((U16*)emsObjectFileNameBuf);
            if ((path_status == FS_FILE_EXISTS) || (path_status == FS_NO_ERROR))
            {
                fmgr_gid = 
                    cui_file_selector_create(
                        mmi_ems_gid,
                        (const WCHAR *)emsObjectFileNameBuf,
                        &filter,
                        CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                        CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FOLDER | CUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON |CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);
                cui_file_selector_run(fmgr_gid);  
            }
            else
            {
                mmi_sms_display_popup_ext(srv_fmgr_fs_error_get_string(path_status), MMI_EVENT_FAILURE);
            }
            mmi_frm_scrn_close(curr_gid, SCR_ID_MSG_EMS_INSERT_OBJECT);
            /* [Bear] 2004/6/23 - end */
            break;

    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MY_MELODY_STATE:
            /* [Bear] 2004/6/23 - begin */
            FMGR_FILTER_INIT(&filter);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_IMY);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_AUDIO);

                        path_status = FS_CreateDir((U16*)emsObjectFileNameBuf);
            if ((path_status == FS_FILE_EXISTS) || (path_status == FS_NO_ERROR))
            {
                fmgr_gid = 
                    cui_file_selector_create(
                        mmi_ems_gid,
                        (const WCHAR *)emsObjectFileNameBuf,
                        &filter,
                        CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                        CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FOLDER | CUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON |CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);
                cui_file_selector_run(fmgr_gid);
            }
            else
            {
                mmi_sms_display_popup_ext(srv_fmgr_fs_error_get_string(path_status), MMI_EVENT_FAILURE);
            }
            mmi_frm_scrn_close(curr_gid, SCR_ID_MSG_EMS_INSERT_OBJECT);
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 

#else /* (defined(__MMI_FILE_MANAGER__)) */ 
        case EMS_OBJECT_MY_PICTURE_STATE:
        case EMS_OBJECT_MY_ANIMATION_STATE:
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MY_MELODY_STATE:
    #endif 
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 
        case EMS_OBJECT_PICTURE_STATE:
        case EMS_OBJECT_MELODY_STATE:
        case EMS_OBJECT_PREDEFINED_SOUND_STATE:
    #if !defined(__MMI_MAINLCD_176X220__) && !defined(__MMI_MAINLCD_240X320__)
        case EMS_OBJECT_PREDEFINED_ANIMATION_STATE:
    #endif 

            GetEmsObjectDisplayListDetails(&lskStrID, strItemList, imgItemList, popUpList);
            if (currMaxEmsObjectList > 0)
            {
            #ifdef UI_SMALL_IMAGE_SELECTOR_SCREEN
            #if !defined(__MMI_MAINLCD_176X220__) && !defined(__MMI_MAINLCD_240X320__)
                if (currEmsObjectDisplayListState == EMS_OBJECT_PICTURE_STATE ||
                    currEmsObjectDisplayListState == EMS_OBJECT_PREDEFINED_ANIMATION_STATE)
            #else /* !defined(__MMI_MAINLCD_176X220__) && !defined(__MMI_MAINLCD_240X320__) */ 
                if (currEmsObjectDisplayListState == EMS_OBJECT_PICTURE_STATE)
            #endif /* !defined(__MMI_MAINLCD_176X220__) && !defined(__MMI_MAINLCD_240X320__) */ 
                {
                    enable_resized_small_screen();  /* small screen is only applicable to picture and animation */
                }
                else
                {
                    disable_resized_small_screen(); /* small screen is not applicable to sound and melody */
                }
                if (whether_no_small_screen())
                {
                    if (mmi_frm_scrn_enter(curr_gid, SCR_ID_MSG_EMS_PREVIEW_OBJECT, mmi_msg_exit_generic, mmi_ems_entry_object_list, MMI_FRM_SMALL_SCRN))
                    {
                        guiBuffer = mmi_frm_scrn_get_gui_buf(curr_gid, SCR_ID_MSG_EMS_PREVIEW_OBJECT);

    					if (guiBuffer == NULL)
    					{
    						currObjectListHiliteIndex = 0;
    					}

    					RegisterCategory144ObjectLoader(CallBackLoadUserDefinedObjectDataBuffPtr);

                        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

                        ShowImageSelectorScreen(
                            GetString(STR_EMS_OBJECT_LIST),
                            0,
                            STR_GLOBAL_OK,
                            IMG_GLOBAL_OK,
                            STR_GLOBAL_BACK,
                            IMG_GLOBAL_BACK,
                            currEmsObjectDisplayListState,
                            currMaxEmsObjectList,
                            NULL,
                            preDefinedObjectIds,
                            userDefinedObjectDataPtrs,
                            (PS32) & currObjectListHiliteIndex,
                            guiBuffer);

                        SetLeftSoftkeyFunction(PreviewEmsObjectIsDone, KEY_EVENT_UP);
                        SetCenterSoftkeyFunction(PreviewEmsObjectIsDone, KEY_EVENT_UP);
                        //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
                    }
                }
                else
                {
                    restore_small_screen();
            #endif /* UI_SMALL_IMAGE_SELECTOR_SCREEN */ 

                    if (mmi_frm_scrn_enter(curr_gid, SCR_ID_MSG_EMS_OBJECT_LIST, ExitEMSObjectList, mmi_ems_entry_object_list, MMI_FRM_FULL_SCRN))
                    {
                        RegisterHighlightHandler(mmi_ems_get_object_hilite_index);

                        guiBuffer = mmi_frm_scrn_get_gui_buf(curr_gid, SCR_ID_MSG_EMS_OBJECT_LIST);

                        if (guiBuffer != NULL)
                        {
                            change_list_menu_category_history(
                                guiBuffer,
                                currObjectListHiliteIndex,
                                currMaxEmsObjectList,
                                0);
                        }
                        else
                        {
                            currObjectListHiliteIndex = 0;
                        }

                        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

                        ShowCategory53Screen(
                            STR_EMS_OBJECT_LIST,
                            IMG_SMS_ENTRY_SCRN_CAPTION,
                            lskStrID,
                            IMG_GLOBAL_OK,
                            STR_GLOBAL_BACK,
                            IMG_GLOBAL_BACK,
                            currMaxEmsObjectList,
                            (U8 **) strItemList,
                            imgItemList,
                            (U8 **) popUpList,
                            0,
                            currObjectListHiliteIndex,
                            guiBuffer);

                        SetLeftSoftkeyFunction(mmi_ems_entry_pre_view_object, KEY_EVENT_UP);
                        SetCenterSoftkeyFunction(mmi_ems_entry_pre_view_object, KEY_EVENT_UP);
                        //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
                    }
                #ifdef UI_SMALL_IMAGE_SELECTOR_SCREEN
                }
                #endif 
            }
            else
            {
                mmi_sms_display_popup_ext(
                    STR_GLOBAL_EMPTY,
                    MMI_EVENT_FAILURE);
            }
            break;
        #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)        /* 041205 Calvin modified */
        case EMS_OBJECT_PREDEFINED_ANIMATION_STATE:
        {
            MMI_ID_TYPE *imglist = (currEmsObjectDisplayListState == EMS_OBJECT_PICTURE_STATE) ?
                EMS_predefined_images : EMS_predefined_animations;
            MMI_ID_TYPE *strlist = (currEmsObjectDisplayListState == EMS_OBJECT_PICTURE_STATE) ?
                ManufacturerPictureStrIDs : PredefinedAnimationStrIDs;
            S32 objectcount = (currEmsObjectDisplayListState == EMS_OBJECT_PICTURE_STATE) ?
                EmsPictureNum() : MAX_EMS_PREDEFINED_ANIMATION;

            if (mmi_frm_scrn_enter(curr_gid, SCR_ID_MSG_EMS_OBJECT_LIST, mmi_msg_exit_generic, mmi_ems_entry_object_list, MMI_FRM_SMALL_SCRN))
            {
                guiBuffer = mmi_frm_scrn_get_gui_buf(curr_gid, SCR_ID_MSG_EMS_OBJECT_LIST);
                if (guiBuffer == NULL)
                {
                    currObjectListHiliteIndex = 0;
                }

                RegisterHighlightHandler(mmi_ems_get_object_hilite_index);

                EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

                ShowCategoryEMSScreen(
                    STR_EMS_OBJECT_LIST,
                    IMG_SMS_ENTRY_SCRN_CAPTION,
                    STR_GLOBAL_OK,
                    IMG_GLOBAL_OK,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    objectcount,
                    imglist,
                    strlist,
                    currObjectListHiliteIndex,
                    guiBuffer);
                SetLeftSoftkeyFunction(PreviewEmsObjectIsDone, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(PreviewEmsObjectIsDone, KEY_EVENT_UP);
                //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
            }
        }
            break;
        #endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitEMSObjectList
 * DESCRIPTION
 *  Exit object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitEMSObjectList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* history currHistory; */
    currObjectListHiliteIndex = GetHighlightedItem();
    mmi_ems_stop_imelody_and_sound();
    /* currHistory.scrnID = SCR_ID_MSG_EMS_OBJECT_LIST; */
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_ID_MSG_EMS_OBJECT_LIST;
    //currHistory.entryFuncPtr = mmi_ems_entry_object_list;
    //memset (currHistory.inputBuffer, 0, ENCODING_LENGTH);
    //GetCategoryHistory (currHistory.guiBuffer);
    //AddHistory (currHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_entry_pre_view_object
 * DESCRIPTION
 *  Entry preview object screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_entry_pre_view_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 objectType = 0;
    U8 *guiBuffer = NULL;
    U8 isPictureOrAnimation = FALSE;
    MMI_ID curr_gid = mmi_ems_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (currEmsObjectDisplayListState)
    {
        case EMS_OBJECT_PICTURE_STATE:
            objectType = EMS_PREDEFINED_PICTURE;
            isPictureOrAnimation = TRUE;
            break;
        case EMS_OBJECT_MY_PICTURE_STATE:
            objectType = EMS_USERDEFINED_PICTURE;
            isPictureOrAnimation = TRUE;
            break;
        case EMS_OBJECT_PREDEFINED_ANIMATION_STATE:
            objectType = EMS_PREDEFINED_ANIMATION;
            isPictureOrAnimation = TRUE;
            break;
        case EMS_OBJECT_MY_ANIMATION_STATE:
            objectType = EMS_USERDEFINED_ANIMATION;
            isPictureOrAnimation = TRUE;
            break;
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MELODY_STATE:
            objectType = EMS_PREDEFINED_MELODY | CATEGORY144_DISABLE_PREVIEW;
            isPictureOrAnimation = FALSE;
            break;
        case EMS_OBJECT_MY_MELODY_STATE:
            objectType = EMS_USERDEFINED_MELODY | CATEGORY144_DISABLE_PREVIEW;
            isPictureOrAnimation = FALSE;
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        case EMS_OBJECT_PREDEFINED_SOUND_STATE:
            objectType = EMS_PREDEFINED_SOUND | CATEGORY144_DISABLE_PREVIEW;
            isPictureOrAnimation = FALSE;
            break;
    }
    if (isPictureOrAnimation == TRUE)
    {
        if (mmi_frm_scrn_enter(curr_gid, SCR_ID_MSG_EMS_PREVIEW_OBJECT, mmi_msg_exit_generic, mmi_ems_entry_pre_view_object, MMI_FRM_SMALL_SCRN))
        {
            guiBuffer = mmi_frm_scrn_get_gui_buf(curr_gid, SCR_ID_MSG_EMS_PREVIEW_OBJECT);

            if (currEmsObjectDisplayListState == EMS_OBJECT_PREDEFINED_ANIMATION_STATE)
            {
                emsObjectNameWhenPreview = (U8*) GetString(PredefinedAnimationStrIDs[currObjectListHiliteIndex]);
                RegisterHighlightHandler(mmi_ems_change_object_title_with_index);
            }
            else
            {
                RegisterCategory144ObjectLoader(CallBackLoadUserDefinedObjectDataBuffPtr);
            }
            SetMessagesCurrScrnID(SCR_ID_MSG_EMS_PREVIEW_OBJECT);

            EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

            ShowCategory144Screen(
                emsObjectNameWhenPreview,
                IMG_SMS_ENTRY_SCRN_CAPTION,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                objectType,
                currMaxEmsObjectList,
                NULL,
                preDefinedObjectIds,
                MMI_FALSE,
                userDefinedObjectDataPtrs,
                (PS32) & currObjectListHiliteIndex,
                guiBuffer);
            SetLeftSoftkeyFunction(PreviewEmsObjectIsDone, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(PreviewEmsObjectIsDone, KEY_EVENT_UP);
            //SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        }
    }
    else
    {
        ExitCategoryFunction();
        RegisterCategory144ObjectLoader(CallBackLoadUserDefinedObjectDataBuffPtr);
        ShowCategory144Screen(
            (PU8) GetString(STR_GLOBAL_PREVIEW),
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            objectType,
            currMaxEmsObjectList,
            NULL,
            preDefinedObjectIds,
            MMI_FALSE,
            userDefinedObjectDataPtrs,
            (PS32) & currObjectListHiliteIndex,
            guiBuffer);
        PreviewEmsObjectIsDone();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_change_object_title_with_index
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  index       [IN]        Object index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ems_change_object_title_with_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    emsObjectNameWhenPreview = (U8*) GetString(PredefinedAnimationStrIDs[index]);
    ChangeTitleString(emsObjectNameWhenPreview);
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_get_object_hilite_index
 * DESCRIPTION
 *  Get object highlight index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ems_get_object_hilite_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currObjectListHiliteIndex = index;
    switch (currEmsObjectDisplayListState)
    {
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MELODY_STATE:
            StopTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID);
            EMSObjectStopPlayBack();
            if (ReadDownloadObjectDataFromFileSystem(index))
            {
                StartTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID, MESSAGES_ONE_SEC_TIME_OUT, mmi_ems_paly_menufacturer_imelody);
            }
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        case EMS_OBJECT_PREDEFINED_SOUND_STATE:
            StopTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID);
            EMSObjectStopPlayBack();
            StartTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID, MESSAGES_ONE_SEC_TIME_OUT, mmi_ems_play_menufacturer_sound);
            break;
    }
}

/* MTK Joy added for customization, 1014 */
#if defined(__MMI_IMELODY_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_paly_menufacturer_imelody
 * DESCRIPTION
 *  Play manufacturer melody
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ems_paly_menufacturer_imelody(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID);
    EMSObjectStopPlayBack();

    if (SRV_PROF_RET_PROFILE_ACTIVATED !=srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE))
    {
#ifdef __MMI_SILENT_MEETING_PROFILE__
        if (SRV_PROF_RET_PROFILE_ACTIVATED != srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE))
#endif 
        {
            EMSObjectPlayback(EMS_PREDEFINED_MELODY, userDefinedObjectDataBuff, -1);
        }
    }
}
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_play_menufacturer_sound
 * DESCRIPTION
 *  Play manufacturer sound
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ems_play_menufacturer_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID);
    EMSObjectStopPlayBack();

    if (SRV_PROF_RET_PROFILE_ACTIVATED !=srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE))
    {
#ifdef __MMI_SILENT_MEETING_PROFILE__
        if (SRV_PROF_RET_PROFILE_ACTIVATED != srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE))
#endif 
        {
            EMSObjectPlayback(EMS_PREDEFINED_SOUND, NULL, currObjectListHiliteIndex);
        }  
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_stop_imelody_and_sound
 * DESCRIPTION
 *  Stop melody/sound
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ems_stop_imelody_and_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (currEmsObjectDisplayListState)
    {
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MELODY_STATE:
            StopTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID);
            EMSObjectStopPlayBack();
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        case EMS_OBJECT_PREDEFINED_SOUND_STATE:
            StopTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID);
            EMSObjectStopPlayBack();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PreviewEmsObjectIsDone
 * DESCRIPTION
 *  After preview, add object to message body
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreviewEmsObjectIsDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    {
        U8 *guibuffer;
        guibuffer = mmi_frm_scrn_get_gui_buf(g_sms_gid, SCR_ID_SMS_EDITOR);
        wgui_cat28_highlight_to_content(guibuffer);
    }
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */

    if ((currEmsObjectDisplayListState != EMS_OBJECT_PREDEFINED_ANIMATION_STATE) &&
        (currEmsObjectDisplayListState != EMS_OBJECT_PREDEFINED_SOUND_STATE) &&
        (!listOfIsAllowedData[currObjectListHiliteIndex]))
    {
        mmi_sms_display_popup_ext(
            STR_EMS_OBJECT_SIZE_NOT_ALLOWED_ID,
            MMI_EVENT_FAILURE);
    }
    else
    {
        switch (currEmsObjectDisplayListState)
        {
            case EMS_OBJECT_PICTURE_STATE:
                emsObjectStatus = EMS_inputbox_insert_predefined_picture(currObjectListHiliteIndex);
                break;
            case EMS_OBJECT_MY_PICTURE_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_picture(userDefinedObjectDataBuff);
                break;
            case EMS_OBJECT_PREDEFINED_ANIMATION_STATE:
                emsObjectStatus = EMS_inputbox_insert_predefined_animation(currObjectListHiliteIndex);
                break;
            case EMS_OBJECT_MY_ANIMATION_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_animation(userDefinedObjectDataBuff);
                break;
        #if defined(__MMI_IMELODY_SUPPORT__)
            case EMS_OBJECT_MELODY_STATE:
                emsObjectStatus = EMS_inputbox_insert_predefined_melody(currObjectListHiliteIndex);
                break;
            case EMS_OBJECT_MY_MELODY_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_melody(userDefinedObjectDataBuff);
                break;
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            case EMS_OBJECT_PREDEFINED_SOUND_STATE:
                emsObjectStatus = EMS_inputbox_insert_predefined_sound(currObjectListHiliteIndex);
                break;
            default:
                emsObjectStatus = EMS_inputbox_insert_predefined_picture(currObjectListHiliteIndex);
                break;
        }

        mmi_ems_insert_object_error_hdlr(emsObjectStatus); /* check whetehr it is inserted or not. */

        mmi_frm_group_close(mmi_ems_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_ems_picture
 * DESCRIPTION
 *  Highlight insert picture handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_ems_picture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currEmsObjectDisplayListState = EMS_OBJECT_PICTURE_STATE;
    currObjectListHiliteIndex = 0;
    mmi_ems_entry_object_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_ems_my_picture
 * DESCRIPTION
 *  Highlight insert my picture handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_ems_my_picture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currEmsObjectDisplayListState = EMS_OBJECT_MY_PICTURE_STATE;
    mmi_ems_entry_object_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_ems_predef_animation
 * DESCRIPTION
 *  Highlight insert predefined animation handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_ems_predef_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currEmsObjectDisplayListState = EMS_OBJECT_PREDEFINED_ANIMATION_STATE;
    currMaxEmsObjectList = MAX_EMS_PREDEFINED_ANIMATION;
    mmi_ems_entry_object_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_ems_my_animation
 * DESCRIPTION
 *  Highlight insert my animation handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_ems_my_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currEmsObjectDisplayListState = EMS_OBJECT_MY_ANIMATION_STATE;
    mmi_ems_entry_object_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_ems_melody
 * DESCRIPTION
 *  Highlight insert melody handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* MTK Joy added for customization, 1014 */
#if defined(__MMI_IMELODY_SUPPORT__)
void mmi_msg_entry_ems_melody(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currEmsObjectDisplayListState = EMS_OBJECT_MELODY_STATE;
    mmi_ems_entry_object_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_ems_my_melody
 * DESCRIPTION
 *  Highlight insert my melody handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_ems_my_melody(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currEmsObjectDisplayListState = EMS_OBJECT_MY_MELODY_STATE;
    mmi_ems_entry_object_list();
}
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_ems_predef_sound
 * DESCRIPTION
 *  Highlight insert predefined sound handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_ems_predef_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currEmsObjectDisplayListState = EMS_OBJECT_PREDEFINED_SOUND_STATE;
    mmi_ems_entry_object_list();
}


#if (defined(__MMI_FILE_MANAGER__))
/*****************************************************************************
 * FUNCTION
 *  mmi_ems_add_object_from_fm
 * DESCRIPTION
 *  Add object from file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_add_object_from_fm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    userDefinedObjectDataSize = GetEmsObjectDataSize();
    if (IsAllowed == TRUE)
    {
        switch (currEmsObjectDisplayListState)
        {
            case EMS_OBJECT_MY_PICTURE_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_picture(userDefinedObjectDataBuff);
                break;
            case EMS_OBJECT_MY_ANIMATION_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_animation(userDefinedObjectDataBuff);
                break;
        #if defined(__MMI_IMELODY_SUPPORT__)
            case EMS_OBJECT_MY_MELODY_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_melody(userDefinedObjectDataBuff);
                break;
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            default:
                emsObjectStatus = EMS_inputbox_insert_userdefined_picture(userDefinedObjectDataBuff);
                break;
        }

        mmi_ems_insert_object_error_hdlr(emsObjectStatus);

        mmi_frm_group_close(mmi_ems_gid);
    }
    else
    {
        mmi_sms_display_popup_ext(
            STR_EMS_OBJECT_SIZE_NOT_ALLOWED_ID,
            MMI_EVENT_FAILURE);

        mmi_frm_group_close(mmi_ems_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_entry_preview_object_from_fm
 * DESCRIPTION
 *  Entry preview object screen from file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_entry_preview_object_from_fm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 objectType = 0;
    U8 *guiBuffer = NULL;
    mmi_id curr_gid = mmi_ems_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(curr_gid, SCR_ID_MSG_EMS_PREVIEW_OBJECT, mmi_msg_exit_generic, mmi_ems_entry_preview_object_from_fm, MMI_FRM_SMALL_SCRN))
    {
        switch (currEmsObjectDisplayListState)
        {
            case EMS_OBJECT_MY_PICTURE_STATE:
                objectType = EMS_USERDEFINED_PICTURE;
                break;
            case EMS_OBJECT_MY_ANIMATION_STATE:
                objectType = EMS_USERDEFINED_ANIMATION;
                break;
        #if defined(__MMI_IMELODY_SUPPORT__)
            case EMS_OBJECT_MY_MELODY_STATE:
                objectType = EMS_USERDEFINED_MELODY;
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
                break;
        }

        guiBuffer = mmi_frm_scrn_get_gui_buf(curr_gid, SCR_ID_MSG_EMS_PREVIEW_OBJECT);

        emsObjectNameWhenPreview = (U8*) GetString(STR_GLOBAL_PREVIEW);
        currObjectListHiliteIndex = 0;
        userDefinedObjectDataPtrs[0] = userDefinedObjectDataBuff;
        EnableDisableAudioPlayback();

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory144Screen(
            emsObjectNameWhenPreview,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            objectType,
            1,
            NULL,
            preDefinedObjectIds,
            MMI_FALSE,
            userDefinedObjectDataPtrs,
            (PS32) & currObjectListHiliteIndex,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_ems_add_object_from_fm, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_ems_add_object_from_fm, KEY_EVENT_UP);
        //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_preview_object_from_fm
 * DESCRIPTION
 *  Preview object from file manager
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_preview_object_from_fm(PU16 filePath, S32 is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath != NULL)
    {
        emsObjectStatus = mmi_ems_fm_open_file((S8*) filePath, currEmsObjectDisplayListState);

        if (emsObjectStatus != EMS_OK)
        {
            mmi_ems_insert_object_error_hdlr(emsObjectStatus);
        }
        else
        {
            mmi_ems_entry_preview_object_from_fm();
        }
    }
    else
    {
        mmi_frm_group_close(mmi_ems_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_fm_open_file
 * DESCRIPTION
 *  Open file
 * PARAMETERS
 *  emsObjectFileNameBuf        [IN]        File name
 *  emsObjectType               [IN]        Object type
 * RETURNS
 *  TRUE: open success, FALSE: open fail
 *****************************************************************************/
EMSTATUS mmi_ems_fm_open_file(S8 *emsObjectFileNameBuf, EMS_OBJECT_DISPLAY_STATE emsObjectType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 errorCode = 0;
    FS_HANDLE emsObjectFilePtr = 0;
    U32 read_size = 0;
    U32 file_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&userDefinedObjectDataBuff, 0, MAX_CURR_EMS_OBJECT_DATA_BUFF);
    emsObjectFilePtr = FS_Open((U16*)emsObjectFileNameBuf, FS_READ_ONLY);
    if (emsObjectFilePtr > 0)
    {
        FS_GetFileSize(emsObjectFilePtr, &file_size);
        userDefinedObjectDataSize = file_size;
        switch (emsObjectType)
        {
        #if defined(__MMI_IMELODY_SUPPORT__)    /* Pending work here ...abt hint for over sized.. */
            case EMS_OBJECT_MY_MELODY_STATE:
                if (userDefinedObjectDataSize > MAX_EMS_OBJECT_INSERT_SIZE /* 128 bytes */ )
                {
                    FS_Close(emsObjectFilePtr);
                    return EMS_EMS_DATA_EXCEEDED;
                }
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            default:
                if (userDefinedObjectDataSize > MAX_CURR_EMS_OBJECT_DATA_BUFF /* bytes */ )
                {
                    FS_Close(emsObjectFilePtr);
                    return EMS_EMS_DATA_EXCEEDED;
                }
        }
        errorCode = FS_Read( emsObjectFilePtr, userDefinedObjectDataBuff, userDefinedObjectDataSize, &read_size);
        FS_Close(emsObjectFilePtr);
        if (errorCode < 0)
        {
			ems_object_file_error_code = errorCode;
            return EMS_UNSPECIFIED_ERROR;
        }
        switch (emsObjectType)
        {
        #if defined(__MMI_IMELODY_SUPPORT__)
            case EMS_OBJECT_MY_MELODY_STATE:
            {
                U8 userDefinedObjectDataBuffTemp[MAX_CURR_EMS_OBJECT_DATA_BUFF];

                EMS_userdefined_melody_attach_header(
                    userDefinedObjectDataBuff,
                    userDefinedObjectDataBuffTemp,
                    &userDefinedObjectDataSize);
                memcpy(userDefinedObjectDataBuff, userDefinedObjectDataBuffTemp, userDefinedObjectDataSize);
            }
                break;
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        }
        return EMS_OK;
    }

	ems_object_file_error_code = emsObjectFilePtr;
    return EMS_UNSPECIFIED_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_fm_send_by_ems
 * DESCRIPTION
 *  Send by EMS from file manager
 * PARAMETERS
 *  emsObjectFileNameBuf        [IN]        File name
 *  emsObjectType               [IN]        Object type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_fm_send_by_ems(S8 *emsObjectFileNameBuf, EMS_OBJECT_DISPLAY_STATE emsObjectType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currEmsObjectDisplayListState = emsObjectType;

    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    if ((srv_sms_is_sms_valid() == MMI_FALSE) ||
        (mmi_sms_is_re_entry_send() == MMI_TRUE))
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
        return;
    }
    else if (mmi_sms_is_sms_ready() == MMI_FALSE)
    {
        mmi_sms_display_popup_ext(
            STR_SMS_MSG_NOT_READY_YET,
            MMI_EVENT_FAILURE);
        return;
    }

    emsObjectStatus = mmi_ems_fm_open_file(emsObjectFileNameBuf, emsObjectType);
    if (emsObjectStatus != EMS_OK)
    {
        mmi_ems_insert_object_error_hdlr(emsObjectStatus);
        return;
    }
    GetEmsObjectDataSize();
    if (!IsAllowed)
    {
        mmi_sms_display_popup_ext(
            STR_EMS_OBJECT_SIZE_NOT_ALLOWED_ID,
            MMI_EVENT_FAILURE);
        return;
    }
    else
    {
        EMSTATUS emsObjectStatus = EMS_UNSPECIFIED_ERROR;

    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_lock_double_buffer();
    #endif 
        GetEMSDataForEdit(0, 1);    /* Force init */
        mmi_sms_reset_recipient_data();
        mmi_sms_group_entry(GRP_ID_ROOT);
        mmi_sms_entry_write_msg(SMS_SEND_CASE_WRITE_FROM_OTHER_APP);

        switch (emsObjectType)
        {
            case EMS_OBJECT_MY_PICTURE_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_picture(userDefinedObjectDataBuff);
                break;
            case EMS_OBJECT_MY_ANIMATION_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_animation(userDefinedObjectDataBuff);
                break;
        #if defined(__MMI_IMELODY_SUPPORT__)
            case EMS_OBJECT_MY_MELODY_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_melody(userDefinedObjectDataBuff);
                break;
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        }
        handle_category28_input();
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_unlock_double_buffer();
    #endif 
        dm_redraw_category_screen();
        mmi_ems_insert_object_error_hdlr(emsObjectStatus); /* check whetehr it is inserted or not. */
    }
}

/* MTk end */
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_entry_save_object_list
 * DESCRIPTION
 *  Entry save object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_entry_save_object_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    CreateCategory143ObjectList(GetEMSDataForView(&pEms, 0), &previewObjectListPtr);

    if (previewObjectListPtr != NULL)
    {
        if (mmi_frm_scrn_enter(mmi_ems_gid, SCR_ID_MSG_SAVE_OBJECT_LIST, ExitScrSaveObjectList, mmi_ems_entry_save_object_list, MMI_FRM_SMALL_SCRN))
        {
            U8 *guiBuffer = NULL;

            guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_ems_gid, SCR_ID_MSG_SAVE_OBJECT_LIST);

            if (guiBuffer == NULL)
            {
                currObjectIndex = 0;
            }

            EnableDisableAudioPlayback();

            EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

            ShowCategory143Screen(
                STR_EMS_OBJECT_LIST,
                IMG_SMS_ENTRY_SCRN_CAPTION,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                previewObjectListPtr,
                &nObjectLists,
                &currObjectIndex,
                guiBuffer);

            SetLeftSoftkeyFunction(mmi_ems_pre_entry_edit_object_name, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_ems_pre_entry_edit_object_name, KEY_EVENT_UP);
            //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        }
    }
    else
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_EMPTY,
            MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrSaveObjectList
 * DESCRIPTION
 *  Exit save object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrSaveObjectList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeCategory143ObjectList(&previewObjectListPtr);
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_ID_MSG_SAVE_OBJECT_LIST;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_save_object_name_and_download
 * DESCRIPTION
 *  Save object name and data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_save_object_name_and_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS saveResult;
    S32 create_directory_result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_directory_result = mmi_ems_create_ems_folder();

    /* Create folder success */
    if (create_directory_result == FS_FILE_EXISTS || create_directory_result == FS_NO_ERROR)
    {

        saveResult = WriteDownloadObjectDataIntoFileSystem();

        mmi_ems_save_object_error_hdlr(saveResult);

        if (saveResult != EMS_ALREADY_INITIALIZED &&
            saveResult != EMS_INVALID_FILE_NAME && 
            saveResult != EMS_EMPTY_FILE_NAME &&
            saveResult != EMS_UNSPECIFIED_ERROR)
        {
            memset(&userEmsObjectNameInput, 0, (MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
            cui_filename_editor_close(mmi_ems_object_name_edit_gid);
        }
    }
    else
    {
        mmi_sms_display_popup_ext(
            srv_fmgr_fs_error_get_string(create_directory_result),
            MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_create_ems_folder
 * DESCRIPTION
 *  Create EMS object folder in boot up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_ems_create_ems_folder(void)
{
#if (defined(__MMI_FILE_MANAGER__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 emsObjectFileNameBuf[(MAX_EMS_DOWNLOAD_OBJECT_NAME_INIT_PATH + 1) * ENCODING_LENGTH] = {0, 0};
    U16 driveName;
    S8 temp[4];
    S32 result = FS_NO_ERROR;
    S32 result1 = FS_NO_ERROR;
    S32 result2 = FS_NO_ERROR;
    UI_character_type dir_ems_root[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    driveName = SRV_FMGR_PUBLIC_DRV;
    sprintf(temp, "%c:\\", (S8) driveName);
    mmi_asc_to_ucs2((S8*) dir_ems_root, temp);

    memset(emsObjectFileNameBuf, 0, ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
    mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
    result1 = FS_CreateDir((U16*)emsObjectFileNameBuf);

    memset(emsObjectFileNameBuf, 0, ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
    mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_AUDIO);
    result2 = FS_CreateDir((U16*)emsObjectFileNameBuf);

	/* Open Image Folder Error */
	if ((result1 != FS_FILE_EXISTS) && (result1 != FS_NO_ERROR))
    {
		result = result1;
	}
	else
	{
		result = result2;
	}
#else /* (defined(__MMI_FILE_MANAGER__)) */ 

    U8 *file_name = OslMalloc((MAX_EMS_STR_FOLDER_LEN + 1) * ENCODING_LENGTH);
    S32 result = 0;
    FS_HANDLE fh = 0;
    
#if (0)
/* under construction !*/
/* under construction !*/
#endif /* #if(0) */

    memset(file_name, 0, (MAX_EMS_STR_FOLDER_LEN + 1) * ENCODING_LENGTH);

    fh = FS_Open((U16*)MessagesGetString((S8*) STR_EMS_PIC_A_ANIM_OBJECT_FILE_NAME_INIT_PATH_ID), 
    		 FS_OPEN_DIR|FS_READ_ONLY);
    
    if (fh < 0)
    {
        mmi_ucs2cpy((S8*)file_name, (S8*)MessagesGetString((S8*)STR_EMS_USER_FOLDER_ID));
        FS_CreateDir((U16*)file_name); /* the api does not support recursive creation */
        mmi_ucs2cat((S8*)file_name, (S8*)MessagesGetString((S8*)STR_EMS_IMAGE_FOLDER_ID));
        FS_CreateDir((U16*)file_name);
        mmi_ucs2cat((S8*)file_name, (S8*)MessagesGetString((S8*)STR_EMS_FOLDER_ID));
        FS_CreateDir((U16*)file_name);        
    }
    else
    {
        FS_Close(fh);
    }

    memset(file_name, 0, (MAX_EMS_STR_FOLDER_LEN + 1) * ENCODING_LENGTH);

    fh = FS_Open((U16*)MessagesGetString((S8*) STR_EMS_IMELODY_OBJECT_FILE_NAME_INIT_PATH_ID), 
    		 FS_OPEN_DIR|FS_READ_ONLY);
    
    if (fh < 0)
    {
        mmi_ucs2cpy((S8*)file_name, (S8*)MessagesGetString((S8*)STR_EMS_USER_FOLDER_ID));
        FS_CreateDir((U16*)file_name); /* the api does not support recursive creation */
        mmi_ucs2cat((S8*)file_name, (S8*)MessagesGetString((S8*)STR_EMS_IMELODY_FOLDER_ID));
        FS_CreateDir((U16*)file_name);
        mmi_ucs2cat((S8*)file_name, (S8*)MessagesGetString((S8*)STR_EMS_FOLDER_ID));
        FS_CreateDir((U16*)file_name);        
    }
    else
    {
        FS_Close(fh);
    }

    OslMfree(file_name);

#endif /* (defined(__MMI_FILE_MANAGER__)) */ 

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_set_group_id
 * DESCRIPTION
 *  Add object from file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_set_group_id(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ems_gid = group_id;
}

//For Fixed Build Error, should be modify in the file manager
#else /* __MMI_SMS_APP_EMS_SUPPORT__) */
#ifdef __MMI_MESSAGES_EMS__
/*****************************************************************************
 * FUNCTION
 *  PreviewEmsObjectIsDone
 * DESCRIPTION
 *  After preview, add object to message body
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreviewEmsObjectIsDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_MESSAGES_EMS__ */
#endif /* __MMI_SMS_APP_EMS_SUPPORT__) */ 

