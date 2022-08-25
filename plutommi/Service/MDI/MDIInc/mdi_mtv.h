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
 *  mdi_mtv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Mobile TV interface header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MDI_MTV_H_
/* The macro is used to avoid re-include the same header file */
#define _MDI_MTV_H_

#if defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)


#ifndef _MDI_DATATYPE_H_
#error "Please include mdi_datatype.h before mdi_mtv.h"
#endif 

#ifndef _MDI_ENUM_H_
#include "mdi_enum.h"
#endif
#include "med_global.h" 
#include "med_struct.h" 
#include "mtv_error.h"
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) 
#include "mtv_esg_define.h"
#include "mtv_esg_query_datatype.h"
#include "cmmb_eb.h"
#include "app_datetime.h"
#endif
#include "MMI_features.h"
#include "mdi_datatype.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "mmi_frm_events_gprot.h"
#include "DtcntSrvGprot.h"
#include "drv_sw_features_video.h"

/***************************************************************************** 
* Compile option
*****************************************************************************/

#if defined(__MTK_TARGET__)
    /* HW Rotator support */
    #define __MDI_MTV_HW_ROTATOR_SUPPORT__
    #define __MDI_MTV_HW_ROTATOR_BY_IDP__
#endif

#if defined(VA2_RENDERER_VP_VIDEO_PROCESSING_SUPPORTED)
    #define __MDI_MTV_VIDEO_PROCESSING_SUPPORT__
#endif

#define MDI_MTV_MBBMS_DESC_LENGTH (MEDIA_MTV_MAX_APPEND_LEN)

/***************************************************************************** 
* Define
*****************************************************************************/

/* Brightness value which is darker than default value by 5 levels */
#define MDI_MTV_BRIGHTNESS_N5              0
/* Brightness value which is darker than default value by 4 levels */
#define MDI_MTV_BRIGHTNESS_N4              1
/* Brightness value which is darker than default value by 3 levels */
#define MDI_MTV_BRIGHTNESS_N3              2
/* Brightness value which is darker than default value by 2 levels */
#define MDI_MTV_BRIGHTNESS_N2              3
/* Brightness value which is darker than default value by 1 level */
#define MDI_MTV_BRIGHTNESS_N1              4
/* Default brightness value */
#define MDI_MTV_BRIGHTNESS_0               5
/* Brightness value which is brighter than default value by 1 level */
#define MDI_MTV_BRIGHTNESS_P1              6
/* Brightness value which is brighter than default value by 2 levels */
#define MDI_MTV_BRIGHTNESS_P2              7
/* Brightness value which is brighter than default value by 3 levels */
#define MDI_MTV_BRIGHTNESS_P3              8
/* Brightness value which is brighter than default value by 4 levels */
#define MDI_MTV_BRIGHTNESS_P4              9
/* Brightness value which is brighter than default value by 5 levels */
#define MDI_MTV_BRIGHTNESS_P5              10


/* Contrast value which is lower than default value by 5 levels */
#define MDI_MTV_CONTRAST_N5                0
/* Contrast value which is lower than default value by 4 levels */
#define MDI_MTV_CONTRAST_N4                1
/* Contrast value which is lower than default value by 3 levels */
#define MDI_MTV_CONTRAST_N3                2
/* Contrast value which is lower than default value by 2 levels */
#define MDI_MTV_CONTRAST_N2                3
/* Contrast value which is lower than default value by 1 levels */
#define MDI_MTV_CONTRAST_N1                4
/* Default contrast value */
#define MDI_MTV_CONTRAST_0                 5
/* Contrast value which is higher than default value by 1 levels */
#define MDI_MTV_CONTRAST_P1                6
/* Contrast value which is higher than default value by 2 levels */
#define MDI_MTV_CONTRAST_P2                7
/* Contrast value which is higher than default value by 3 levels */
#define MDI_MTV_CONTRAST_P3                8
/* Contrast value which is higher than default value by 4 levels */
#define MDI_MTV_CONTRAST_P4                9
/* Contrast value which is higher than default value by 5 levels */
#define MDI_MTV_CONTRAST_P5                10

/* Saturation value which is lower than default value by 5 levels */
#define MDI_MTV_SATURATION_N5                0
/* Saturation value which is lower than default value by 4 levels */
#define MDI_MTV_SATURATION_N4                1
/* Saturation value which is lower than default value by 3 levels */
#define MDI_MTV_SATURATION_N3                2
/* Saturation value which is lower than default value by 2 levels */
#define MDI_MTV_SATURATION_N2                3
/* Saturation value which is lower than default value by 1 levels */
#define MDI_MTV_SATURATION_N1                4
/* Default saturation value */
#define MDI_MTV_SATURATION_0                 5
/* Saturation value which is higher than default value by 1 levels */
#define MDI_MTV_SATURATION_P1                6
/* Saturation value which is higher than default value by 2 levels */
#define MDI_MTV_SATURATION_P2                7
/* Saturation value which is higher than default value by 3 levels */
#define MDI_MTV_SATURATION_P3                8
/* Saturation value which is higher than default value by 4 levels */
#define MDI_MTV_SATURATION_P4                9
/* Saturation value which is higher than default value by 5 levels */
#define MDI_MTV_SATURATION_P5                10


/* Taiwan band */
#define MDI_MTV_TDMB_BAND_TAIWAN    MEDIA_MTV_TDMB_BAND_III
/* Korea band */
#define MDI_MTV_TDMB_BAND_KOREA     MEDIA_MTV_TDMB_KOREA_BAND
/* China band */
#define MDI_MTV_TDMB_BAND_CHINA     MEDIA_MTV_TDMB_CHINESE_BAND
/* L band  */
#define MDI_MTV_TDMB_L_BAND         MEDIA_MTV_TDMB_L_BAND


/* U band  */
#define MDI_MTV_CMMB_U_BAND         MEDIA_MTV_CMMB_U_BAND

/* Country type for Analog TV */
#define MDI_MTV_ATV_AFGHANISTAN     MEDIA_MTV_ATV_AFGHANISTAN
#define MDI_MTV_ATV_ARGENTINA       MEDIA_MTV_ATV_ARGENTINA
#define MDI_MTV_ATV_AUSTRALIA       MEDIA_MTV_ATV_AUSTRALIA
#define MDI_MTV_ATV_BRAZIL          MEDIA_MTV_ATV_BRAZIL
#define MDI_MTV_ATV_BURMA           MEDIA_MTV_ATV_BURMA
#define MDI_MTV_ATV_CAMBODIA        MEDIA_MTV_ATV_CAMBODIA
#define MDI_MTV_ATV_CANADA          MEDIA_MTV_ATV_CANADA
#define MDI_MTV_ATV_CHILE           MEDIA_MTV_ATV_CHILE
#define MDI_MTV_ATV_CHINA           MEDIA_MTV_ATV_CHINA
#define MDI_MTV_ATV_CHINA_HONGKONG  MEDIA_MTV_ATV_CHINA_HONGKONG
#define MDI_MTV_ATV_CHINA_SHENZHEN  MEDIA_MTV_ATV_CHINA_SHENZHEN
#define MDI_MTV_ATV_CONGO           MEDIA_MTV_ATV_FRENCH_COLONIE
#define MDI_MTV_ATV_EUROPE_EASTERN  MEDIA_MTV_ATV_EUROPE_EASTERN
#define MDI_MTV_ATV_EUROPE_WESTERN  MEDIA_MTV_ATV_EUROPE_WESTERN
#define MDI_MTV_ATV_FRANCE          MEDIA_MTV_ATV_FRANCE
#define MDI_MTV_ATV_FRENCH_COLONIE  MEDIA_MTV_ATV_FRENCH_COLONIE
#define MDI_MTV_ATV_GABON           MEDIA_MTV_ATV_FRENCH_COLONIE
#define MDI_MTV_ATV_INDIA           MEDIA_MTV_ATV_INDIA
#define MDI_MTV_ATV_INDONESIA       MEDIA_MTV_ATV_INDONESIA
#define MDI_MTV_ATV_IRAN            MEDIA_MTV_ATV_IRAN
#define MDI_MTV_ATV_IRELAND         MEDIA_MTV_ATV_IRELAND
#define MDI_MTV_ATV_ITALY           MEDIA_MTV_ATV_ITALY
#define MDI_MTV_ATV_IVORYCOAST      MEDIA_MTV_ATV_FRENCH_COLONIE
#define MDI_MTV_ATV_JAPAN           MEDIA_MTV_ATV_JAPAN
#define MDI_MTV_ATV_KOREA           MEDIA_MTV_ATV_KOREA
#define MDI_MTV_ATV_LAOS            MEDIA_MTV_ATV_LAOS
#define MDI_MTV_ATV_MADAGASCAR      MEDIA_MTV_ATV_FRENCH_COLONIE
#define MDI_MTV_ATV_MALAYSIA        MEDIA_MTV_ATV_MALAYSIA
#define MDI_MTV_ATV_MEXICO          MEDIA_MTV_ATV_MEXICO
#define MDI_MTV_ATV_MOROCCO         MEDIA_MTV_ATV_MOROCCO
#define MDI_MTV_ATV_NEWZEALAND      MEDIA_MTV_ATV_NEWZEALAND
#define MDI_MTV_ATV_PAKISTAN        MEDIA_MTV_ATV_PAKISTAN
#define MDI_MTV_ATV_PARAGUAY        MEDIA_MTV_ATV_PARAGUAY
#define MDI_MTV_ATV_PHILIPPINES     MEDIA_MTV_ATV_PHILIPPINES
#define MDI_MTV_ATV_PORTUGAL        MEDIA_MTV_ATV_PORTUGAL
#define MDI_MTV_ATV_REUNION         MEDIA_MTV_ATV_FRENCH_COLONIE
#define MDI_MTV_ATV_RUSSIA          MEDIA_MTV_ATV_RUSSIA
#define MDI_MTV_ATV_RWANDA          MEDIA_MTV_ATV_FRENCH_COLONIE
#define MDI_MTV_ATV_SENEGAL         MEDIA_MTV_ATV_FRENCH_COLONIE
#define MDI_MTV_ATV_SINGAPORE       MEDIA_MTV_ATV_SINGAPORE
#define MDI_MTV_ATV_SOUTHAFRICA     MEDIA_MTV_ATV_SOUTHAFRICA
#define MDI_MTV_ATV_SPAIN           MEDIA_MTV_ATV_SPAIN
#define MDI_MTV_ATV_TAIWAN          MEDIA_MTV_ATV_TAIWAN
#define MDI_MTV_ATV_THAILAND        MEDIA_MTV_ATV_THAILAND
#define MDI_MTV_ATV_TURKEY          MEDIA_MTV_ATV_TURKEY
#define MDI_MTV_ATV_UNITED_ARAB_EMIRATES    MEDIA_MTV_ATV_UNITED_ARAB_EMIRATES
#define MDI_MTV_ATV_UNITED_KINGDOM  MEDIA_MTV_ATV_UNITED_KINGDOM
#define MDI_MTV_ATV_USA             MEDIA_MTV_ATV_USA
#define MDI_MTV_ATV_URUGUAY         MEDIA_MTV_ATV_URUGUAY
#define MDI_MTV_ATV_VENEZUELA       MEDIA_MTV_ATV_VENEZUELA
#define MDI_MTV_ATV_VIETNAM         MEDIA_MTV_ATV_VIETNAM

/* Audio mode */
#define MDI_ATV_DEFAULT         ATV_DEFAULT_MODE

#define MDI_ATV_MONO            ATV_MTS_MONO   
#define MDI_ATV_MTS_STEREO      ATV_MTS_STEREO 
#define MDI_ATV_MTS_SAP         ATV_MTS_SAP

#define MDI_ATV_MPX_MONO        ATV_MPX_MONO
#define MDI_ATV_MPX_STEREO      ATV_MPX_STEREO
#define MDI_ATV_MPX_SUB         ATV_MPX_SUB
#define MDI_ATV_MPX_MAIN_SUB    ATV_MPX_MAIN_SUB
#define MDI_ATV_MPX_MAIN        ATV_MPX_MAIN

#define MDI_ATV_FM_MONO         ATV_FM_MONO
#define MDI_ATV_A2_STEREO       ATV_A2_STEREO
#define MDI_ATV_A2_DUAL1        ATV_A2_DUAL1
#define MDI_ATV_A2_DUAL2        ATV_A2_DUAL2
#define MDI_ATV_NICAM_MONO      ATV_NICAM_MONO
#define MDI_ATV_NICAM_STEREO    ATV_NICAM_STEREO
#define MDI_ATV_NICAM_DUAL1     ATV_NICAM_DUAL1
#define MDI_ATV_NICAM_DUAL2     ATV_NICAM_DUAL2

/* Chinese language  */
#define MDI_MTV_LANG_ZHO    ESG_QUERY_LANG_ZHO
/* English language  */
#define MDI_MTV_LANG_ENG    ESG_QUERY_LANG_ENG 

/* The length of CAS smart card number */
#define MDI_MTV_CARD_NUMBER_LEN 8

#if defined(ISP_SUPPORT)
/* LCD rotate: 0 degree */
#define MDI_MTV_LCD_ROTATE_0            LCD_LAYER_ROTATE_NORMAL
/* LCD rotate: 90 degree */
#define MDI_MTV_LCD_ROTATE_90           LCD_LAYER_ROTATE_90
/* LCD rotate: 180 degree */
#define MDI_MTV_LCD_ROTATE_180          LCD_LAYER_ROTATE_180
/* LCD rotate: 270 degree */
#define MDI_MTV_LCD_ROTATE_270          LCD_LAYER_ROTATE_270
#else /* defined(ISP_SUPPORT) */ 
/* LCD rotate: 0 degree */
#define MDI_MTV_LCD_ROTATE_0            0
/* LCD rotate: 90 degree */
#define MDI_MTV_LCD_ROTATE_90           1
/* LCD rotate: 180 degree */
#define MDI_MTV_LCD_ROTATE_180          2
/* LCD rotate: 270 degree */
#define MDI_MTV_LCD_ROTATE_270          3
#endif /* defined(ISP_SUPPORT) */

/***************************************************************************** 
* Enumeration
*****************************************************************************/
/* System event */
typedef enum
{
    MDI_MTV_SYSTEM_OPENED = 0,                  /* System is opened successfully */         
    MDI_MTV_SYSTEM_CLOSED,                      /* System is closed successfully */            
    MDI_MTV_SYSTEM_FATAL_ERROR,                 /* A severe problem happens */              
    MDI_MTV_SYSTEM_BAD_RECEPTION = 10,          /* Signal reception is bad */     
    MDI_MTV_SYSTEM_GOOD_RECEPTION,              /* Signal reception is good */       
    MDI_MTV_SYSTEM_DATE_TIME = 20,              /* Current date and time is received */       
    MDI_MTV_SYSTEM_EMERGENCY_MSG = 30,          /* An emergency message is received */      
    MDI_MTV_SYSTEM_ESG_NEW_AVAILABLE = 40,      /* A new ESG is available */    
    MDI_MTV_SYSTEM_ESG_DOWNLOADED,              /* A new ESG is downloaded, but is not ready for query */           
    MDI_MTV_SYSTEM_ESG_UPDATED,                 /* A new ESG is ready for query */
    MDI_MTV_SYSTEM_UNSAVED_RECORDING_DISCARDED  /* Unsaved recorded material is discarded */
} mdi_mtv_system_event_enum;


/* Service event */
typedef enum
{
    MDI_MTV_SERVICE_STARTED,            /* A service is started to connect */
    MDI_MTV_SERVICE_READY,              /* The service is connected successfully */
    MDI_MTV_SERVICE_STOPPED,            /* The service is stopped */
    MDI_MTV_SERVICE_ABORTED,            /* The service is aborted because some error occurs */
    MDI_MTV_SERVICE_ADDED,              /* A new service is available */
    MDI_MTV_SERVICE_REMOVED,            /* An existing service is removed */
    MDI_MTV_SERVICE_UPDATED,            /* The information of an existing service is updated */
    MDI_MTV_SERVICE_ACCESS_GRANTED,     /* The access permission of a service is granted */
    MDI_MTV_SERVICE_ACCESS_DENIED,      /* The access permission of a service is denied */
    MDI_MTV_SERVICE_BAD_RECEPTION,      /* The signal reception is bad */
    MDI_MTV_SERVICE_GOOD_RECEPTION,     /* The signal reception is good */
    MDI_MTV_SERVICE_FATAL_ERROR,        /* A severe problem happens  */
    MDI_MTV_SERVICE_DATE_TIME,          /* Current date and time is received */
    MDI_MTV_SERVICE_PROGRAM_INFO,       /* Current program info is received */
    MDI_MTV_SERVICE_EMERGENCY_MSG,      /* An emergency message is received */
    MDI_MTV_SERVICE_ESG_NEW_AVAILABLE,  /* A new ESG is available */
    MDI_MTV_SERVICE_ESG_DOWNLOADED,     /* A new ESG is downloaded, but is not ready for query */
    MDI_MTV_SERVICE_ESG_UPDATED,        /* ESG is updated */
    MDI_MTV_SERVICE_UPGRADE_RET,        /* Upgrade */
    MDI_MTV_SERVICE_AREA_RETRIEVE_RET,  /* Area retrieve  */
    MDI_MTV_SERVICE_INTERACTIVITY_RETRIEVE_RET,  /* Area retrieve  */
    MDI_MTV_SERVICE_SG_UPDATE_RET,    /* ESG fails to update */
    MDI_MTV_SERVICE_SUBSCRIPTION_RET,  /* Subscription table fails to update */
    MDI_MTV_SERVICE_ACCOUNT_INQUIRY_DONE, /* Account inquiry done */
    MDI_MTV_SERVICE_GBA_RET,           /* GBA process ret */
    MDI_MTV_SERVICE_SUBSCRIBE_DONE,     /* Subscribe done */
    MDI_MTV_SERVICE_UNSUBSCRIBE_DONE,   /* Unsubscribe done */
    MDI_MTV_SERVICE_MSK_RETRIEVE_DONE,    /* msk retrieve done */
    MDI_MTV_SERVICE_IMD_READY,            /* IMD ready  */
    MDI_MTV_SERVICE_SET_EMM_DONE,
    MDI_MTV_SERVICE_GET_CA_DONE
} mdi_mtv_service_event_enum;

/* Player event */
typedef enum
{
    MDI_MTV_PLAYER_STARTED,             /* The player is started  */
    MDI_MTV_PLAYER_TIMESHIFT_PAUSED,    /* The playback of time-shift buffer content is paused  */
    MDI_MTV_PLAYER_TIMESHIFT_DELAYED,   /* The time-shift buffered content is played */
    MDI_MTV_PLAYER_TIMESHIFT_LIVE,      /* The live content is played */
    MDI_MTV_PLAYER_TIMESHIFT_ERROR,     /* Time-shift buffer encounters some error */         
    MDI_MTV_PLAYER_BEGINNING_OF_CONTENT,/* A rewind hits the beginning of time-shift buffer */     
    MDI_MTV_PLAYER_END_OF_CONTENT,      /* a forward playback catches up with the live content  */     
    MDI_MTV_PLAYER_SNAPSHOT_TAKEN,      /* A snapshot of the current video frame is taken */     
    MDI_MTV_PLAYER_DYNAMIC_LABEL,       /* A dynamic label segment is received */     
    MDI_MTV_PLAYER_ERROR,               /* The playback encounters some error */     
    MDI_MTV_PLAYER_STOPPED,             /* The player is stopped */     
    MDI_MTV_PLAYER_RATE_CHANGE          /* The play speed is updated */     
} mdi_mtv_player_event_enum;

/* Recorder event */
typedef enum
{
    MDI_MTV_RECORDER_STARTED,           /* The recorder is started */
    MDI_MTV_RECORDER_SAVING,            /* The recorder enters saving status */
    MDI_MTV_RECORDER_SAVING_SUCCEEDED,  /* The recording content is saved successfully */
    MDI_MTV_RECORDER_SAVING_FAILED,     /* The recording content is saved fail */
    MDI_MTV_RECORDER_ERROR,             /* The recorder enters some error */
    MDI_MTV_RECORDER_STOPPED,           /* The recorder is stopped */
    MDI_MTV_RECORDER_RECORDING_DISCARDED/* The recording content is discarded */
} mdi_mtv_recorder_event_enum;

typedef enum
{    
    MDI_MTV_RECORDER_SIZE_QCIF,
    MDI_MTV_RECORDER_SIZE_QVGA,
    MDI_MTV_RECORDER_SIZE_HVGA,
    MDI_MTV_RECORDER_SIZE_COUNT
} mdi_mtv_recorder_size_enum;

typedef enum
{    
    MDI_MTV_RECORDER_STORAGE_PHONE,
    MDI_MTV_RECORDER_STORAGE_CARD
} mdi_mtv_recorder_storage_enum;

typedef enum
{
    MDI_MTV_MBBMS_OK = 0,
    MDI_MTV_MBBMS_DEVICE_AUTHENTICATION_FAILED = 1,
    MDI_MTV_MBBMS_PURCHASE_ITEM_UNKNOWN = 3,
    MDI_MTV_MBBMS_SERVICE_ERROR = 7,
    MDI_MTV_MBBMS_MAL_FORMED_MESSAGE_ERROR = 8,
    MDI_MTV_MBBMS_NO_SUBSCRIPTION = 10,
    MDI_MTV_MBBMS_OPERATION_NOT_PERMITTED = 11,
    MDI_MTV_MBBMS_REQUESTED_SERVICE_UNAVAILABLE = 15,
    MDI_MTV_MBBMS_REQUESTED_SERVICE_ACCEPTED = 16,
    MDI_MTV_MBBMS_INVALID_REQUEST = 22,
    MDI_MTV_MBBMS_DELIVERY_OF_WRONG_KEY_INFORMATION = 24,
    MDI_MTV_MBBMS_ALREADY_IN_USE = 27,
    MDI_MTV_MBBMS_NO_MATCHING_FRAGMENT = 28,
    MDI_MTV_MBBMS_NOW_SUBSCRIBED = 29,
    MDI_MTV_MBBMS_LOCATION_DETECT_FAIL = 30, /* MBBMS 3.0 */
    MDI_MTV_MBBMS_INSUFFICIENT_CHARGE = 131,

    MDI_MTV_MBBMS_SET_CHANNEL_FAIL = MTV_E_INVALID_PARAM,
    MDI_MTV_MBBMS_NW_TIMEOUT = MTV_E_TIMEOUT
} mdi_mtv_mbbms_status_enum;

typedef enum
{
    MDI_MTV_FAVO_CHANNEL,
    MDI_MTV_FAVO_CONTENT,
    MDI_MTV_FAVO_LOCAL_PURCHASE_ITEM,
    MDI_MTV_FAVO_EB
} mdi_mtv_favorite_type_enum;

typedef enum
{
    MDI_MTV_SOURCE_LIVE_SIGNAL,    /**< scanning services from live signal */
    MDI_MTV_SOURCE_LOCAL_DATABASE  /**< load service info from local cache */
} mdi_mtv_service_source_enum;

typedef enum
{
    MDI_MTV_MTS_TYPE_GBA,    
    MDI_MTV_MTS_TYPE_MSK_RETRIEVE
} mdi_mtv_mts_type_enum;

typedef enum
{
    MDI_MTV_IMD_TYPE_SERVICE = MED_MTV_IMD_TYPE_SERVICE,
    MDI_MTV_IMD_TYPE_CONTENT = MED_MTV_IMD_TYPE_CONTENT
} mdi_mtv_imd_type_enum;

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef struct
{
    U8  bdscell_id[17];
    MMI_BOOL is_usim;
    CHAR imsi[16];
    U16  sim_id;
    MMI_BOOL same_imsi;
} mdi_mtv_cas_sim_struct;

typedef struct
{
    U32 net_id;         /* data account id */
    CHAR  prx_ip[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN];      /* proxy ip */
    U8 use_proxy;
    U16 prx_port;       /* proxy port */
    U8  app_id;         /* app id */
    CHAR sg_url[30];
    U16 sg_port;
} mdi_mtv_cas_net_struct;

typedef struct
{
    /* Input */
    S32 imd_index;
    S32 desc_len; /* UCS2 len, not include null termination */
    
    /* Output */
    MMI_BOOL *if_read;
    WCHAR *desc;    
} mdi_mtv_imd_desc_struct;

typedef struct
{
    /* Input */
    mdi_mtv_imd_type_enum imd_type;
    S32 path_len; /* UCS2 len, not include null termination */
    /* For service type */
    S32 imd_index;
    /* For contetnt type */
    CHAR *content_id;
    
    /* Output */
    WCHAR *path;    
} mdi_mtv_imd_detail_struct;

typedef struct
{
    S32 ret;
    WCHAR desc[MDI_MTV_MBBMS_DESC_LENGTH];
} mdi_mtv_purchase_desc_struct;

typedef struct
{
    U32 randvalue[2];
    U32 demodType;
    U32 caType;
    U8  cardSN[8];
    //must pedding at tail
    U32 result;    
} mdi_mtv_ca_info_struct;

typedef struct
{
    U16 nYear;
    U8  nMonth;
    U8  nDay;
    U8  nHour;
    U8  nMin;
    U8  nSec;
    U8  week;
} mdi_mtv_nit_time_struct;


/* MTV setting structure */
typedef struct
{
    U32 max_timeshift_buffer_kb;/* The maximal disk size that the time shift buffer engine could use  */
    U16 brightness;             /* The player's brightness value  */
    U16 contrast;               /* The player's contrast value  */
    U16 saturation;             /* The player's saturation value  */
    U16 volume_level;           /* The player's volume level */
    U8 record_size;             /* The player's record size */
    PU8 record_dir;             /* The recorder's destination folder */
    pBOOL is_timeshift_enabled; /* Used to enable or disable time shift buffer engine */
    mdi_mtv_cas_sim_struct *sim;
}mdi_mtv_setting_struct;

/* Service info structure */
typedef struct
{
    U32 service_id;                         /* Service identifier */
    CHAR *service_name;                       /* Service name in UCS2 encoding */
    U32 service_number;                     /* Service serial number */
    mdi_mtv_service_type_enum service_type; /* Service type, such as TV, Radio or data service */
    S32 service_flags;                      /* Access right information of the service */
    kal_uint32 audio_mode;                  /**< the current audio mode. @see matvctrl.h */
    kal_uint32 supported_audio_mode;
}mdi_mtv_service_info_struct;


/* this is the struct for account inquiry done event */

typedef struct
{
    kal_uint8   *fragment_id;
    kal_uint8   *purchaseitem_id;
    kal_wchar   *purchaseitem_name;
    kal_wchar   *purchaseitem_desc;
    kal_uint8 type;
    kal_uint8 period;
    float price;
} mdi_mtv_account_item_struct;


typedef struct
{ 
    kal_uint32  purchase_count;                   
    mdi_mtv_account_item_struct  purchase_info[5];
} mdi_mtv_account_inquiry_struct;

/* this is the struct for recommended city event */

typedef struct
{
    kal_wchar   *city_name;
} mdi_mtv_city_struct;

typedef struct
{
    kal_uint32  city_count;
    mdi_mtv_city_struct  city_info[5];
} mdi_mtv_city_info_struct;

/* Player setting structure */
typedef struct
{ 
    gdi_handle play_layer_handle;   /* Provide the TV layer handle  */
    U32 blt_layer_flag;             /* Provide the blt layer configuration */
    U32 play_layer_flag;            /* Provide the TV layer configuration */
    MMI_BOOL is_visual_update;      /* Set the visibility of the TV layer */      
    U8 play_audio;                  /* Play audio or not */
    U16 rotate;
    mdi_mtv_recorder_storage_enum storage;
}mdi_mtv_player_setting_struct;

/* Service status structure */
typedef struct
{
    mdi_mtv_service_state_enum state;   /* Service state */
    U32 signal_strength;                /* Signal strength */
    pBOOL timeshift_available;          /* Notify if the current disk storage size is enough to enable time shift buffer engine */
}mdi_mtv_service_status_struct;

/* Player status structure */
typedef struct
{
    mdi_mtv_player_state_enum state;    /* Player state */
    U32 play_delay;                     /* Playback delay in time shift buffer. The unit is millisecond. */   
    U32 max_delay;                      /* Maximal playback delay in time shift buffer. The unit is millisecond. */ 
    U32 buffer_duration;                /* Allowable time shift buffer duration in millisecond */
    S32 play_rate;                      /* Play speed */
}mdi_mtv_player_status_struct;

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
/* Program info structure */
typedef struct
{
    U32 record_num;                     /* Indicate the number of the program info */
    struct
    {
        U32 date;                       /* 16-bit MJD value */
        U32 time;                       /* 24-bit UTC value */
        U32 duration;                   /* The program duration in seconds */
        kal_wchar *title;               /* The program title in UCS2 encoding */
    } records[2];
} mdi_mtv_program_info_struct;

/* Order status Structure */
typedef struct 
{
    CHAR *gid;    
    U8 subscribed;
} mdi_mtv_order_struct;

/* Order status Structure */
typedef struct 
{
    U32 id;
    CHAR rid[21];
    S32 lang_type;
    applib_time_struct *time;
    WCHAR *keyword; 
    U32 start_idx;
    U32 query_num;
} mdi_mtv_query_struct;

#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */

/* The service found callback function  */
typedef void (*mdi_mtv_service_found_callback)(mdi_mtv_service_info_struct *service_info, void *user_data);
/* The service scan progress notification callback function  */
typedef void (*mdi_mtv_search_progress_callback)(S32 value, void *user_data);
/* The unsaved recorded content is completely recovered callback function  */
typedef void (*mdi_mtv_complete_recovering_callback)(S32 value, void *user_data);
/* The callback function to notify some event */
typedef void (*mdi_mtv_event_callback)(U32 event_id, S32 param, void *user_data);

typedef void (*mdi_mtv_account_callback)(mdi_mtv_account_inquiry_struct *account, void *user_data);

typedef void (*mdi_mtv_city_found_callback)(mdi_mtv_city_info_struct *city, void *user_data);


/* MTV configuration structure */
typedef struct
{
    mdi_mtv_service_found_callback service_found_hdlr;              /* Service found callback function */
    mdi_mtv_search_progress_callback search_progress_hdlr;          /* Service scan progress callback function */
    mdi_mtv_complete_recovering_callback complete_recovering_hdlr;  /* The unsaved recording completely recovered callback function */
    mdi_mtv_event_callback system_event_hdlr;                       /* System event callback function */
    mdi_mtv_event_callback service_event_hdlr;                      /* Service event callback function */
    mdi_mtv_event_callback player_event_hdlr;                       /* Player event callback function */
    mdi_mtv_event_callback recorder_event_hdlr;                     /* Recorder event callback function */
    mdi_mtv_account_callback account_inquiry_hdlr;                /* Service found callback function */
    mdi_mtv_city_found_callback city_found_hdlr;                    /* Service found callback function */
    void *user_data;
}mdi_mtv_service_config_struct;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
/*
 * System function
 */
 
/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_open
 * DESCRIPTION
 *  This function is to open Mobile TV engine and check if there is unsaved 
 *  recording content. If so, the application could invoke 
 *  mdi_mtv_recover_recording() to save the unsaved recording content.
 * PARAMETERS
 *  mtv_handle          : [OUT] The handle of a Mobile TV engine
 *  mtv_setting         : [IN]  Configuration of mtv setting
 *  mtv_service_config  : [IN]  Configuration of callback function
 * RETURNS
 *  MDI_RES_MTV_SUCCEED                     : Success
 *  MDI_RES_MTV_FIND_UNSAVED_RECORDING_FAIL : Success, but found out unsaved recording content
 *  MDI_RES_MTV_FAILED                FALSE : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_open(const U16 app_id,
                               U32 *mtv_handle, 
                               mdi_mtv_setting_struct* mtv_setting,
                               mdi_mtv_service_config_struct* mtv_service_config);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_close
 * DESCRIPTION
 *  This function is to close Mobile TV engine.
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_close(U32 mtv_handle);

#ifdef __MTV_REC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recover_recording
 * DESCRIPTION
 *  This function is to recover the unsaved recording content. When the 
 *  application opens the Mobile TV engine, if the return value of
 *  mdi_mtv_open() is MDI_RES_MTV_FIND_UNSAVED_RECORDING_FAIL, the application
 *  could call this function to save the unsaved recording content. 
 *  The recovering process is asyncronous and when the process is finished, 
 *  application will be notified by the callback function complete_recovering_hdlr 
 *  defined in mdi_mtv_service_config_struct.
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_recover_recording(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_discard_unsaved_recording
 * DESCRIPTION
 *  This function is to discard the unsaved recording content. When the 
 *  application opens the Mobile TV engine, if the return value of
 *  mdi_mtv_open() is MDI_RES_MTV_FIND_UNSAVED_RECORDING_FAIL, the application
 *  could call this function to discard the unsaved recording content. The
 *  process is asyncronous and when the process is finished, application will
 *  be notified by the callback function system_event_hdlr defined in 
 *  mdi_mtv_service_config_struct with the event type, 
 *  MDI_MTV_SYSTEM_UNSAVED_RECORDING_DISCARDED.
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_discard_unsaved_recording(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_abort_recovering
 * DESCRIPTION
 *  This function is to abort recovering process after mdi_mtv_recover_recording()
 *  is invoked. 
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_abort_recovering(U32 mtv_handle);
#endif /* __MTV_REC_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_scan_services_on_air
 * DESCRIPTION
 *  This function is to scan available services on air. When available services
 *  are found, service_found_hdlr defined in mdi_mtv_service_config_struct will
 *  be invoked to notify application. When the scanning process is finished,
 *  search_progress_hdlr will also be invoked with the progress value, 100. 
 *  MED will store the available services to reduce the scanning time at the next
 *  time
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 *  band                : [IN]  The band value
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_scan_services(U32 mtv_handle, mdi_mtv_service_source_enum source, U32 band, void *param);


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_abort_scan_services
 * DESCRIPTION
 *  This function is to abort scanning process after mdi_mtv_scan_services_on_air()
 *  or mdi_mtv_scan_services_from_database() is invoked.
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_abort_scan_services(U32 mtv_handle);

/*
 * Service function
 */
 
/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_start_service
 * DESCRIPTION
 *  This function is to start a service and is an asyncronous function. After
 *  the service connects successfully, service_event_hdlr with the event 
 *  MDI_MTV_SERVICE_READY will invoked to notify the application. Application
 *  could use the 4th parameter, which is auto_play, to ask MED task to or not to
 *  play the service automatically after the service is connected successfully.
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 *  service_id          : [IN]  The service ID 
 *  service_type        : [IN]  The service type
 *  auto_play           : [IN]  Ask MED task to or not to automatically play the service
 *  setting_p           : [IN]  The video setting
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_start_service(
                        U32 mtv_handle, 
                        U32 service_id, 
                        mdi_mtv_service_type_enum service_type,
                        MMI_BOOL auto_play,
                        mdi_mtv_player_setting_struct *setting_p);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_stop_service
 * DESCRIPTION
 *  This function is to stop a service.
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 *  service_id          : [IN]  The service ID 
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_stop_service(U32 mtv_handle, U32 service_id);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_service_get_status
 * DESCRIPTION
 *  This function is to query the status of a service
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 *  status              : [OUT] The service status
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_service_get_status(U32 mtv_handle, mdi_mtv_service_status_struct *status);

/*
 * Player function
 */

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_set_hw_rotator
 * DESCRIPTION
 *  This function is to set hw rotater
 * PARAMETERS
 *  rotate          : [IN]  Rotate angle
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_player_set_hw_rotator(U16 rotate); 

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_play
 * DESCRIPTION
 *  This function is to start a Mobile TV player
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 *  setting_p           : [IN] The video setting
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_player_play(U32 mtv_handle, mdi_mtv_player_setting_struct *setting_p);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_stop
 * DESCRIPTION
 *  This function is to stop a Mobile TV player
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_player_stop(U32 mtv_handle);

#ifdef __MTV_TS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_pause
 * DESCRIPTION
 *  This function is to pause a Mobile TV player
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED             : Success
 *  MDI_RES_MTV_ERR_PAUSE_FAILED    : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_player_pause(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_seek
 * DESCRIPTION
 *  This function is to forward or rewind the time shift buffer
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 *  play_delay          : [IN]  The play delay of the time shift buffer
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_player_seek(U32 mtv_handle, U32 play_delay);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_get_status
 * DESCRIPTION
 *  This function is to query the status of the Mobile TV player
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 *  status      : [OUT]  The player status
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_player_get_status(U32 mtv_handle, mdi_mtv_player_status_struct *status);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_set_speed
 * DESCRIPTION
 *  This function is to set play speed of the Mobile TV player.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 *  speed       : [IN]  The play speed
 * RETURNS
 *  MDI_RES_MTV_SUCCEED                 : Success
 *  MDI_RES_MTV_ERR_SET_SPEED_FAILED    : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_player_set_speed(U32 mtv_handle, S32 speed);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_start_timeshift
 * DESCRIPTION
 *  This function is to start time shift function. Normally, time shift is 
 *  automatically started after the Mobile TV player enters playing status. If
 *  a application hopes the time shift function starts when the player is at
 *  stopped status, then the function could be invoked to reach the goal.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED   : Success
 *  MDI_RES_MTV_FAILED    : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_start_timeshift(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_enable_timeshift
 * DESCRIPTION
 *  This function is to re-configure record_dir and is_timeshift_enabled in
 *  the structure mdi_mtv_setting_struct.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 *  record_dir  : [IN]  The recorder's destination folder
 * RETURNS
 *  MDI_RES_MTV_SUCCEED     : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_enable_timeshift(U32 mtv_handle,PU8 record_dir);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_disable_timeshift
 * DESCRIPTION
 *  This function is to re-configure is_timeshift_enabled in the structure
 *  mdi_mtv_setting_struct as false
 *  is invoked.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED     : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_disable_timeshift(U32 mtv_handle);

#endif /* __MTV_TS_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_set_brightness
 * DESCRIPTION
 *  This function is to set brightness value
 * PARAMETERS
 *  brightness  : [IN]  The brightness value
 * RETURNS
 *  MDI_RES_MTV_SUCCEED   : Success
*****************************************************************************/
extern void mdi_mtv_set_brightness(U16 brightness);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_set_contrast
 * DESCRIPTION
 *  This function is to set contrast value
 * PARAMETERS
 *  contrast  : [IN]  The contrast value
 * RETURNS
 *  MDI_RES_MTV_SUCCEED   : Success
*****************************************************************************/
extern void mdi_mtv_set_contrast(U16 contrast);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_set_saturation
 * DESCRIPTION
 *  This function is to set saturation value
 * PARAMETERS
 *  contrast  : [IN]  The saturation value
 * RETURNS
 *  MDI_RES_MTV_SUCCEED   : Success
*****************************************************************************/
extern void mdi_mtv_set_saturation(U16 saturation);


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_get_audio_sample_rate
 * DESCRIPTION
 *  This function is to query audio sample rate
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 *  service_id  : [IN]  Service ID
 *  sample_rate : [OUT]  Audio sampling rate
 * RETURNS
 *  MDI_RES_MTV_SUCCEED   : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_get_audio_sample_rate (U32 mtv_handle, U32 service_id, U32 *sample_rate);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_get_audio_channel_number
 * DESCRIPTION
 *  This function is to query audio channel number
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 *  service_id          : [IN]  Service ID
 *  aud_channel_num     : [OUT]  Audio channel number
 * RETURNS
 *  MDI_RES_MTV_SUCCEED   : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_get_audio_channel_number (U32 mtv_handle, U32 service_id, U32 *aud_channel_num);

/* 
 * Recorder function
 */
 
#ifdef __MTV_REC_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_set_record_size
 * DESCRIPTION
 *  This function is to set record size
 * PARAMETERS
 *  size  : [IN]  The record size
 * RETURNS
 *  MDI_RES_MTV_SUCCEED   : Success
*****************************************************************************/
extern void mdi_mtv_set_record_size(U8 size);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recorder_start
 * DESCRIPTION
 *  This function is to start a recorder. If some error happens during the
 *  recording process, the callback function recorder_event_hdlr with the event
 *  MDI_MTV_RECORDER_ERROR will be invoked to notify the application.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 *  file_name   : [IN]  The destination file name
 * RETURNS
 *  MDI_RES_MTV_SUCCEED             : Success
 *  MDI_RES_MTV_ERR_RECORD_FAILED   : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_recorder_start(U32 mtv_handle, CHAR *file_name);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recorder_stop
 * DESCRIPTION
  *  This function is to stop a recorder.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED     : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_recorder_stop(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recorder_pause
 * DESCRIPTION
  *  This function is to pause a recorder.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED     : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_recorder_pause(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recorder_resume
 * DESCRIPTION
  *  This function is to resume a recorder.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED     : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_recorder_resume(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recorder_save
 * DESCRIPTION
 *  This function is to save the recording content. Application should invoke
 *  mdi_mtv_recorder_stop() to stop recording first and then invoke the function
 *  to save the recording content. The function is asyncronous and when the saving
 *  process is finished, the callback function recorder_event_hdlr with the event
 *  MDI_MTV_RECORDER_SAVING_SUCCEEDED or MDI_MTV_RECORDER_SAVING_FAILED will be 
 *  invoked to notify the application. 
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED     : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_recorder_save(U32 mtv_handle, WCHAR *file_path);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recorder_discard_recording
 * DESCRIPTION
 *  This function is to discard the recording content. Application should invoke
 *  mdi_mtv_recorder_stop() to stop recording first and then invoke the function
 *  to discard the recording content. The function is asyncronous and when the 
 *  discarding process is finished, the callback function recorder_event_hdlr 
 *  with the event MDI_MTV_RECORDER_RECORDING_DISCARDED will be invoked to notify
 *  the application.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED     : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_recorder_discard_recording(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_recorder_abort_saving
 * DESCRIPTION
 *  This function is to abort the saving process after mdi_mtv_recorder_save() 
 *  is invoked.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED     : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_recorder_abort_saving(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_set_storage
 * DESCRIPTION
 *  This function is to re-configure record_dir and is_timeshift_enabled in 
 *  the structure mdi_mtv_setting_struct.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 *  record_dir  : [IN]  The recorder's destination folder
 * RETURNS
 *  MDI_RES_MTV_SUCCEED     : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_set_storage(U32 mtv_handle,PU8 record_dir);

#endif /* __MTV_REC_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_get_snapshot
 * DESCRIPTION
 *  This function is to get snapshot
 * PARAMETERS
 *  mtv_handle    : [IN]  The handle of the Mobile TV engine
 *  layer_handle  : [IN]  The layer handle of video
 *  file_path     : [IN]  The snapshot's destination folder
 * RETURNS
 *  MDI_RES_MTV_SUCCEED     : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_get_snapshot(U32 mtv_handle, gdi_handle layer_handle, WCHAR *file_path);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_get_hw_layer_buffer_content
 * DESCRIPTION
 *  This function is to get buffer content
 * PARAMETERS
 *  layer_handle    : [IN]  The GDI layer handle
 *  dst_buff_p      : [IN]  The destination buffer address
 *  dst_buff_size   : [IN]  The destination buffer size
 * RETURNS
 *  MDI_RES_MTV_SUCCEED     : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_get_hw_layer_buffer_content(gdi_handle layer_handle, U8 *dst_buff_p, U32 dst_buff_size);

#if defined(__MMI_ATV_SUPPORT__) 
/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_get_supported_record_size
 * DESCRIPTION
 *  This function is to get snapshot
 * PARAMETERS
 *  record_size_num    : [OUT]  The number of supported record size
 *  record_size_list   : [OUT]  The list of supported record size
 * RETURNS
 *  MDI_RES_MTV_SUCCEED     : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_get_supported_record_size(U32 mtv_handle, S32 *record_size_num, mdi_mtv_recorder_size_enum *record_size_list);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_pause_engine
 * DESCRIPTION
 *  This function is to pause Mobile TV engine.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_pause_engine(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_resume_engine
 * DESCRIPTION
 *  This function is to resume Mobile TV engine.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_resume_engine(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_delete_channel
 * DESCRIPTION
 *  The function is to delete a service from the service list.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 *  service_id  : [IN]  The service ID
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_delete_channel(U32 mtv_handle, U32 service_id);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_rename_channel
 * DESCRIPTION
 *  The function is to rename a service.
 * PARAMETERS
 *  mtv_handle      : [IN]  The handle of the Mobile TV engine
 *  service_id      : [IN]  The service ID
 *  service_name    : [IN]  The service name
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_rename_channel(U32 mtv_handle, U32 service_id, CHAR* service_name);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_set_audio_mode
 * DESCRIPTION
 *  The function is to set audio mode.
 * PARAMETERS
 *  mode            : [IN]  The audio mode
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_set_audio_mode(U32 mtv_handle, U32 service_id, U32 mode);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_get_service_by_index
 * DESCRIPTION
 *  The function is to get service by index.
 * PARAMETERS
 *  mtv_handle      : [IN]  The handle of the Mobile TV engine
 *  index           : [IN]  The service index
 *  service_info    : [OUT] The service info
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_get_service_by_index(U32 mtv_handle, S32 index, mdi_mtv_service_info_struct *service_info);

#endif /* __MMI_ATV_SUPPORT__ */

 
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) 
/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_resume_visual_update
 * DESCRIPTION
 *  This function is to resume visual update
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 *  setting_p           : [IN] The video setting
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_player_resume_visual_update(U32 mtv_handle, mdi_mtv_player_setting_struct *setting_p);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_player_pause_visual_update
 * DESCRIPTION
 *  This function is to pause visual update
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
*****************************************************************************/
extern MDI_RESULT mdi_mtv_player_pause_visual_update(U32 mtv_handle);


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_start_esg_download
 * DESCRIPTION
 *    This function is to start to download ESG and is an asyncronous function. 
 *  After one application invokes mdi_mtv_scan_services_on_air or mdi_mtv_scan_services_from_database  
 *  to enter scanning state, if it receives the service event, MEDIA_MTV_SERVICE_ESG_NEW_AVAILABLE,
 *  during the scanning state, it could invoke the function immediately to download
 *  ESG, after the scanning process is finished.
 *    After ESG is downloaded successfully, service_event_hdlr with the event type
 *  MEDIA_MTV_SERVICE_ESG_DOWNLOADED will be invoked to notify the application.
 *  The downloaded ESG is processed in the background and when the ESG is ready to
 *  query information, the application will receive another service event called
 *  MEDIA_MTV_SERVICE_ESG_UPDATED. And then the application could use ESG query APIs
 *  to query ESG related information.
 *    The number of connecting service at the same time has limitation. Therefore,
 *  application MUST stop all the TV or radio service before invoking the function
 *  to download ESG and wait until it receives the service event, MEDIA_MTV_SERVICE_ESG_DOWNLOADED,
 *  then the application could start the TV and radio service again.
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_start_esg_download(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_abort_esg_download
 * DESCRIPTION
 *  This function is to abort ESG downloading process after mdi_mtv_start_esg_download()
 *  is invoked. 
 * PARAMETERS
 *  mtv_handle          : [IN]  The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_abort_esg_download(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_add_favorite
 * DESCRIPTION
 *  The function is to add a service into favorite service list.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 *  service_id  : [IN]  The service ID
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_add_favorite(
                U32 mtv_handle, 
                mdi_mtv_favorite_type_enum type,
                U32 id,
                CHAR *rid);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_delete_favorite
 * DESCRIPTION
 *  The function is to delete a service from the favorite service list.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 *  service_id  : [IN]  The service ID
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_delete_favorite(
                U32 mtv_handle, 
                mdi_mtv_favorite_type_enum type,
                U32 id,
                CHAR *rid);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_set_net_info
 * DESCRIPTION
 *  This function is to network info.
 *  is invoked.
 * PARAMETERS
 *  mtv_handle   : [IN]  The handle of the Mobile TV engine
 *  net          : [IN]  The network information
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_set_net_info(U32 mtv_handle, mdi_mtv_cas_net_struct *net);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_subscribe_purchase_item
 * DESCRIPTION
 *  This function is to subscribe purchase item. It's an asynchronous function. 
 *  Application should wait until service event: MEDIA_MTV_SERVICE_SUBSCRIBE_DONE 
 *  is callbacked. Subscribe action doesn't have abort function.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 *  id          : [IN]  The fragment ID in SG
 *  gid          : [IN]  The global ID in SG
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_subscribe_purchase_item(U32 mtv_handle, CHAR *id, CHAR *gid);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_unsubscribe_purchase_item
 * DESCRIPTION
 *  This function is to unsubscribe purchase item. It's an asynchronous function. 
 *  Application should wait until service event: MEDIA_MTV_SERVICE_UNSUBSCRIBE_DONE 
 *  is callbacked. Unsubscribe action doesn't have abort function.
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 *  id          : [IN]  The fragment ID in SG
 *  gid          : [IN]  The global ID in SG
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_unsubscribe_purchase_item(U32 mtv_handle, CHAR *id, CHAR *gid);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_get_services_ca
 * DESCRIPTION
 *  This function is get CA related attribute of a service. 
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 *  service_id  : [IN]  The service ID
 *  flag        : [OUT] The CA attribute. Please refer to media_mtv_service_flag_enum
 *  purchase_id : [OUT] reserved now
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_get_services_ca(U32 mtv_handle, U32 service_id, U32 *flag, CHAR *purchase_id);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_get_mbbms_description
 * DESCRIPTION
 *  This function is get mbbms description
 * PARAMETERS
 *  mtv_handle  : [IN]  The handle of the Mobile TV engine
 *  service_id  : [IN]  The service ID
 *  desc        : [OUT] The CA attribute. Please refer to media_mtv_service_flag_enum
 *  desc_len    : [IN]  UCS2 len, not include null termination
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_get_mbbms_description(U32 mtv_handle, U32 service_id, WCHAR *desc, S32 desc_len);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_esg_query
 * DESCRIPTION
 *  This function is query ESG database. 
 * PARAMETERS
 *  mtv_handle  : [IN] The handle of the Mobile TV engine
 *  source      : [IN] If MTV engine is closed, the source should be MEDIA_MTV_ESG_SOURCE_MBBMS
 *  query_type  : [IN] The query type
 *  query_param : [IN] The query paramter
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_esg_query(
                U32 mtv_handle, 
                media_mtv_esg_source_enum source,
                esg_query_type_enum query_type, 
                mdi_mtv_query_struct *query_param);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_esg_get_result
 * DESCRIPTION
 *  This function is get query result from ESG database. 
 * PARAMETERS
 *  mtv_handle  : [IN] The handle of the Mobile TV engine
 *  source      : [IN] If MTV engine is closed, the source should be MEDIA_MTV_ESG_SOURCE_MBBMS
 *  query_type  : [IN] The query type
 *  buf_ptr     : [OUT] Structure pointer to the query result
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_esg_get_result(
                U32 mtv_handle, 
                media_mtv_esg_source_enum source,
                esg_query_type_enum query_type, 
                void **buf_ptr);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_open_stand_alone_db
 * DESCRIPTION
 *  This function is to open SG database when MTV engine is closed. 
 * PARAMETERS
 *  db_handle   : [OUT] The database handle
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_open_stand_alone_db(const U16 app_id, U32 *db_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_close_stand_alone_db
 * DESCRIPTION
 *  This function is to close SG database when MTV engine is closed.  
 * PARAMETERS
 *  db_handle   : [IN] The database handle
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_close_stand_alone_db(U32 db_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_purify_program_reminder
 * DESCRIPTION
 *  This function is to purify program reminder. The program time which is greater 
 *  than input time will be removed from database.
 * PARAMETERS
 *  db_handle   : [IN] The database handle
 *  time        : [IN] The input time. For example, current time.
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_purify_program_reminder(U32 mtv_handle, applib_time_struct *time);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_set_preview_data_downloaded
 * DESCRIPTION
 *  This function is to tell MED if the preview data is downloaded
 * PARAMETERS
 *  mtv_handle   : [IN] The handle of the Mobile TV engine
 *  file_path    : [IN] The file path of the downloaded preview data
 *  downloaded   : [IN] If the file path is downloaded or not
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_set_preview_data_downloaded(U32 mtv_handle, WCHAR *file_path, MMI_BOOL downloaded);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_account_inquiry
 * DESCRIPTION
 *  This function is to do account inquiry. The function is an asynchronous 
 *  function. MDI will call account_inquiry_hdlr() to notify application the subscribed 
 *  purchase item and use the service event: MEDIA_MTV_SERVICE_ACCOUNT_INQUIRY_DONE 
 *  to notify application the action is done.
 * PARAMETERS
 *  mtv_handle   : [IN] The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_account_inquiry(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_upgrade_query
 * DESCRIPTION
 *  This function is to send a query request to server to know if the client 
 *  needs to upgrade. The function is an asynchronous function and application 
 *  should wait until service event: MEDIA_MTV_SERVICE_UPGRADE_RET is callbacked.
 * PARAMETERS
 *  mtv_handle   : [IN] The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_upgrade_query(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_account_inquiry
 * DESCRIPTION
 *  This function is to do area set retrieve. The function is an asynchronous 
 *  function. MDI will call city_found_hdlr() to notify application the recommended 
 *  city list and use the service event: MEDIA_MTV_SERVICE_AREA_RETRIEVE_RET 
 *  to notify application the action is done.
 * PARAMETERS
 *  mtv_handle   : [IN] The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_area_set_retrieve(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_download_service_guide
 * DESCRIPTION
 *  This function is to download service guide with specified city name
 * PARAMETERS
 *  mtv_handle   : [IN] The handle of the Mobile TV engine
 *  param        : [IN] The city name. If it's null, MED will do SG retrieve with auto detecting city mode
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_download_service_guide(U32 mtv_handle, void *param);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_interactivity_retrieve
 * DESCRIPTION
 *  This function is to retrieve the interactivity URL of the specified content. 
 * PARAMETERS
 *  mtv_handle   : [IN] The handle of the Mobile TV engine
 *  content_id   : [IN] The content ID
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_interactivity_retrieve(U32 mtv_handle, CHAR *content_id);


extern MDI_RESULT mdi_mtv_get_imd_detail(
                U32 mtv_handle, 
                U32 service_id, 
                mdi_mtv_imd_detail_struct *imd_detail);
extern MDI_RESULT mdi_mtv_get_imd_desc(
                U32 mtv_handle, 
                U32 service_id, 
                mdi_mtv_imd_desc_struct *imd_desc);
extern MDI_RESULT mdi_mtv_get_imd_count(
                U32 mtv_handle, 
                U32 service_id, 
                U32 *count, 
                U32 *unread_count, 
                U32 *first_unread_idx);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_update_service_guide
 * DESCRIPTION
 *  This function is to ask MED to update service list from SG 
 * PARAMETERS
 *  mtv_handle   : [IN] The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_update_service_guide(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_set_sim_info
 * DESCRIPTION
 *  This function is to set SIM related information 
 * PARAMETERS
 *  mtv_handle   : [IN] The handle of the Mobile TV engine
 *  sim          : [IN] SIM related information
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_set_sim_info(U32 mtv_handle, mdi_mtv_cas_sim_struct *sim);


/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_subscription_update
 * DESCRIPTION
 *  This function is to update subscription table. The function is an asynchronous 
 *  function and application should wait until service event: MEDIA_MTV_SERVICE_SUBSCRIPTION_UPDATE_RET 
 *  is callbacked.
 * PARAMETERS
 *  mtv_handle   : [IN] The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_subscription_update(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_cancel_subscription_update
 * DESCRIPTION
 *  This function is to cancel subscription table updating
 * PARAMETERS
 *  mtv_handle   : [IN] The handle of the Mobile TV engine
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_cancel_subscription_update(U32 mtv_handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_mts_test
 * DESCRIPTION
 *  This function is to do the test item defined in MTS system
 * PARAMETERS
 *  mtv_handle   : [IN] The handle of the Mobile TV engine
 *  type         : [IN] The action type
 *  service_id   : [IN] service ID
 * RETURNS
 *  MDI_RES_MTV_SUCCEED : Success
 *  MDI_RES_MTV_FAILED  : Fail
*****************************************************************************/
extern MDI_RESULT mdi_mtv_mts_test(U32 mtv_handle, mdi_mtv_mts_type_enum type, S32 service_id);

#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_init
 * DESCRIPTION
 *  The function is to initialize parameters.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
extern void mdi_mtv_init(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_is_playing
 * DESCRIPTION
 *  The function is to query if Mobile TV player is at playing status.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_TRUE   : Mobile TV player is playing.
 *  MDI_FALSE  : Mobile TV player is not playing.
*****************************************************************************/
extern MMI_BOOL mdi_mtv_is_playing(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_is_opened
 * DESCRIPTION
 *  The function is to query if Mobile TV player is at opened status.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_TRUE   : Mobile TV player is opened.
 *  MDI_FALSE  : Mobile TV player is not opened.
*****************************************************************************/
extern MMI_BOOL mdi_mtv_is_opened(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_mtv_get_error_info
 * DESCRIPTION
 *  The function is to query error string and pop up type.
 * PARAMETERS
 *  error_code  : [IN]  The MDI error code
 *  popup_type  : [OUT] The popup type
 * RETURNS
 *  MMI_EVENT_FAILURE   : Pop up type is FAILURE
 *  MMI_EVENT_ERROR     : Pop up type is ERROR
*****************************************************************************/
extern MMI_ID_TYPE mdi_mtv_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type);

extern MDI_RESULT mdi_mtv_set_emm(U32 mtv_handle, U32 emm_len, U8* emm_data);

extern MDI_RESULT mdi_mtv_get_nit_time(U32 mtv_handle, mdi_mtv_nit_time_struct *nit_time);

extern MDI_RESULT mdi_mtv_get_nit_area_code(U32 mtv_handle, U8* net_mode, U16* area_code);

extern MDI_RESULT mdi_mtv_ca_query(U32 mtv_handle, U32 block_len , U32* block_data);
#endif /* (__MMI_ATV_SUPPORT__) || (__MMI_MOBILE_TV_CMMB_SUPPORT__) */
#endif /* _MDI_MTV_H_ */

