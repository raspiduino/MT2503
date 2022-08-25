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
 * ul1_nvram_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM.
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
 *
 * Author:
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
 * removed!
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
#ifdef __GPS_SUPPORT__
#ifndef __VENUS_GPS_NVRAM_DEF_H__
#define __VENUS_GPS_NVRAM_DEF_H__



#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*
 *   Include Headers
 */
#include "MMI_features.h"


/*
 *   NVRAM Basic Headers
 */
#include "nvram_data_items.h"
#include "nvram_defs.h"


/*
 *   User Headers
 */




/*
 *   LID Enums
 */

typedef enum
{
    NVRAM_EF_AGPS_CURRENT_PROFILE_LID       = NVRAM_LID_GRP_GPS(0),
    NVRAM_EF_AGPS_SETTING_LID               = NVRAM_LID_GRP_GPS(1),
    NVRAM_EF_AGPS_EM_SETTING_LID            = NVRAM_LID_GRP_GPS(2),
    NVRAM_EF_AGPS_PROFILE_LID               = NVRAM_LID_GRP_GPS(3),
    NVRAM_EF_AGPS_EM_STATUS_LID             = NVRAM_LID_GRP_GPS(4),
    NVRAM_EF_AGPS_PAYLOAD_LID               = NVRAM_LID_GRP_GPS(5),
    NVRAM_EF_AGPS_MTLR_LID                  = NVRAM_LID_GRP_GPS(6),
    NVRAM_EF_AGPS_CP_CONFIG_LID             = NVRAM_LID_GRP_GPS(7),
    NVRAM_EF_AGPS_QOP_SETTING_LID           = NVRAM_LID_GRP_GPS(8),
    NVRAM_EF_AGPS_SUPL_NOTIFY_LID           = NVRAM_LID_GRP_GPS(9),
    NVRAM_EF_EM_GPS_POS_TYPE_LID            = NVRAM_LID_GRP_GPS(10),
    NVRAM_EF_GPS_MMI_SETTING_DATA_LID       = NVRAM_LID_GRP_GPS(11),
    NVRAM_EF_GPS_MMI_SIM_DATA_LID           = NVRAM_LID_GRP_GPS(12),
    NVRAM_EM_MINIGPS_UP_SETTING_LID         = NVRAM_LID_GRP_GPS(13),


/*
 *  Last LID of GPS Group
 */
    NVRAM_EF_GPS_LAST_LID                   = NVRAM_LID_GRP_GPS(255)
}nvram_lid_gps_enum;


/*
 *   Verno
 */
#define NVRAM_EF_AGPS_CURRENT_PROFILE_LID_VERNO         "000"
#define NVRAM_EF_AGPS_SETTING_LID_VERNO                 "000"
#define NVRAM_EF_AGPS_EM_SETTING_LID_VERNO              "000"
#define NVRAM_EF_AGPS_PROFILE_LID_VERNO                 "003"
#define NVRAM_EF_AGPS_EM_STATUS_LID_VERNO               "000"
#define NVRAM_EF_AGPS_PAYLOAD_LID_VERNO                 "000"
#define NVRAM_EF_AGPS_MTLR_LID_VERNO                    "000"
#define NVRAM_EF_AGPS_CP_CONFIG_LID_VERNO               "000"
#define NVRAM_EF_EM_GPS_POS_TYPE_LID_VERNO              "000"
#define NVRAM_EF_AGPS_QOP_SETTING_LID_VERNO             "000"
#define NVRAM_EF_AGPS_SUPL_NOTIFY_LID_VERNO             "000"
#define NVRAM_EF_GPS_MMI_SETTING_DATA_LID_VERNO         "000"
#define NVRAM_EF_GPS_MMI_SIM_DATA_LID_VERNO             "000"
#define NVRAM_EM_MINIGPS_UP_SETTING_LID_VERNO           "000"




/*
 * Record Size/Total Records
 */
#if defined(__GPS_SUPPORT__)||defined(__BT_GPS_SUPPORT__)
/**
 * GPS
 */
#ifdef __GEMINI__
#if (GEMINI_PLUS == 4)
#define NVRAM_EF_GPS_MMI_SIM_DATA_TOTAL      (4)
#elif (GEMINI_PLUS == 3)
#define NVRAM_EF_GPS_MMI_SIM_DATA_TOTAL      (3)
#else
#define NVRAM_EF_GPS_MMI_SIM_DATA_TOTAL     (2)
#endif /* GEMINI_PLUS */
#else /* __GEMINI__ */
#define NVRAM_EF_GPS_MMI_SIM_DATA_TOTAL     (1)
#endif /* __GEMINI__ */

#define NVRAM_EF_GPS_MMI_SETTING_DATA_TOTAL       1
#define NVRAM_EF_GPS_MMI_SETTING_DATA_SIZE       (sizeof(nvram_ef_gps_mmi_settings_struct))


#endif

/**
 * AGPS
 */
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)

#define NVRAM_EF_GPS_MMI_SIM_DATA_SIZE      (sizeof(nvram_ef_gps_mmi_sim_struct))

#define NVRAM_EF_AGPS_SETTING_TOTAL       1
#define NVRAM_EF_AGPS_SETTING_SIZE        1

#define NVRAM_EF_EM_GPS_POS_TYPE_TOTAL       1
#define NVRAM_EF_EM_GPS_POS_TYPE_SIZE        1

#define NVRAM_EF_AGPS_QOP_SETTING_TOTAL      1
#define NVRAM_EF_AGPS_QOP_SETTING_SIZE       (sizeof(nvram_ef_agps_qop_setting_struct))

#endif

#if defined(__AGPS_USER_PLANE__)
#define NVRAM_EF_AGPS_CURRENT_PROFILE_TOTAL        1
#define NVRAM_EF_AGPS_CURRENT_PROFILE_SIZE         1

#define NVRAM_EF_AGPS_EM_SETTING_TOTAL    1
#define NVRAM_EF_AGPS_EM_SETTING_SIZE     1

#define NVRAM_EF_AGPS_PROFILE_TOTAL       1
#define NVRAM_EF_AGPS_PROFILE_SIZE        (sizeof(nvram_ef_agps_profile_struct))
#define AGPS_MAX_PROFILE_NAME_LEN         64
#define AGPS_MAX_PROFILE_ADDR_LEN         64
#define AGPS_MAX_PROFILE_SMS_NUM_LEN      20
#define MMI_SUPL_OTA_HASH_LEN             16

#define NVRAM_EF_AGPS_EM_STATUS_TOTAL    1
#define NVRAM_EF_AGPS_PAYLOAD_TOTAL      1
#define NVRAM_EF_AGPS_PAYLOAD_SIZE        1
#define NVRAM_EF_AGPS_EM_STATUS_SIZE     1

#define NVRAM_EM_MINIGPS_UP_SETTING_TOTAL       1
#define NVRAM_EM_MINIGPS_UP_SETTING_SIZE        (sizeof(nvram_em_minigps_up_setting_struct))

#define NVRAM_EF_AGPS_SUPL_NOTIFY_TOTAL      1
#define NVRAM_EF_AGPS_SUPL_NOTIFY_SIZE       (sizeof(nvram_ef_agps_supl_notify_struct))

#endif

#ifdef __AGPS_CONTROL_PLANE__
#define NVRAM_EF_AGPS_MTLR_TOTAL       1
#define NVRAM_EF_AGPS_MTLR_SIZE        1

#define NVRAM_EF_AGPS_SEND_LOCATION_TOTAL       1
#define NVRAM_EF_AGPS_SEND_LOCATION_SIZE        1

#define NVRAM_EF_AGPS_CP_CONFIG_TOTAL       1
#define NVRAM_EF_AGPS_CP_CONFIG_SIZE        (sizeof(nvram_ef_agps_cp_config_struct))

#define NVRAM_EF_AGPS_CP_EXTERN_ADDR_LEN       42

#define NVRAM_EF_AGPS_CP_MLC_NUM_LEN       40

#endif


/*
 *   Data Structure
 */
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
typedef struct
{
    kal_uint32 data_account;
}nvram_ef_gps_mmi_sim_struct;

typedef struct
{
    kal_uint8 nvram_ef_agps_setting[NVRAM_EF_AGPS_SETTING_SIZE];
}nvram_ef_agps_setting_struct;

typedef struct
{
    kal_uint8 nvram_ef_em_gps_pos_type[NVRAM_EF_EM_GPS_POS_TYPE_SIZE];
}nvram_ef_em_gps_pos_type_struct;

typedef struct
{
    kal_uint8 hor_acc;
    kal_uint8 ver_acc_used;
    kal_uint8 ver_acc;
    kal_uint8 rsp_time_used;
    kal_uint8 rsp_time;
    kal_uint8 max_loc_age_used;
    kal_uint16 max_loc_age;
}nvram_ef_agps_qop_setting_struct;
#endif

#if defined(__AGPS_USER_PLANE__)
typedef struct
{
    kal_uint8 nvram_ef_agps_current_profile[NVRAM_EF_AGPS_CURRENT_PROFILE_SIZE];
}nvram_ef_agps_current_profile_struct;

typedef struct
{
    kal_uint8 nvram_ef_agps_em_setting[NVRAM_EF_AGPS_EM_SETTING_SIZE];
}nvram_ef_agps_em_setting_struct;

typedef struct
{
    kal_uint16 name[AGPS_MAX_PROFILE_NAME_LEN];
    kal_uint16 addr[AGPS_MAX_PROFILE_ADDR_LEN];
    kal_uint32 port;
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    kal_uint8 nap_id[MMI_SUPL_OTA_HASH_LEN];
    kal_uint8 provurl[MMI_SUPL_OTA_HASH_LEN];
#endif
}nvram_ef_agps_profile_struct;

typedef struct
{
    kal_uint8 nvram_ef_agps_em_status[NVRAM_EF_AGPS_EM_STATUS_SIZE];
}nvram_ef_agps_em_status_struct;
typedef struct
{
    kal_uint8 nvram_ef_agps_payload[NVRAM_EF_AGPS_PAYLOAD_SIZE];
}nvram_ef_agps_payload_struct;

typedef struct
{
    kal_uint32 notify_time;
}nvram_ef_agps_supl_notify_struct;

#endif /* defined(__AGPS_USER_PLANE__) */

#ifdef __GPS_SUPPORT__
    typedef struct
    {
        kal_uint8  receiver;
        kal_uint8  time_sync;
        kal_uint8  em_on_off;

        kal_uint8 agps_on_off; /*AGPS on or off*/
        kal_uint8 send_location;

        #ifdef  __FLIGHT_MODE_DISABLE_AGPS__
            kal_uint8  agps_flight_mode;
        #endif

    } nvram_ef_gps_mmi_settings_struct;
#endif  // #ifdef __GPS_SUPPORT__

#ifdef __AGPS_USER_PLANE__
    typedef struct
    {
        kal_uint8 payload;
        kal_uint8 molr_prefer;
        kal_bool  use_tls;
        kal_uint16 ut_timer;
    }nvram_em_minigps_up_setting_struct;
#endif  // #ifdef __AGPS_USER_PLANE__

#ifdef __AGPS_CONTROL_PLANE__
typedef struct
{
    kal_uint8 nvram_ef_agps_mtlr[NVRAM_EF_AGPS_MTLR_SIZE];
}nvram_ef_agps_mtlr_struct;

typedef struct
{
    kal_uint8 nvram_ef_agps_send_location[NVRAM_EF_AGPS_SEND_LOCATION_SIZE];
}nvram_ef_agps_send_location_struct;

typedef struct
{
    kal_uint8 molr_type;
    kal_uint8 molr_location_method;
    kal_uint8 molr_external_address_valid;
    kal_uint8 molr_external_address[NVRAM_EF_AGPS_CP_EXTERN_ADDR_LEN];
    kal_uint8 molr_mlc_number_valid;
    kal_uint8 molr_mlc_number[NVRAM_EF_AGPS_CP_MLC_NUM_LEN];
}nvram_ef_agps_cp_config_struct;
#endif  // __AGPS_CONTROL_PLANE__

#ifdef __GPS_SUPPORT__
    extern nvram_ltable_entry_struct logical_data_item_table_mmi_gps[];
#endif


#ifdef __cplusplus
}
#endif

#endif /* __VENUS_GPS_NVRAM_DEF_H__ */
#endif /* __GPS_SUPPORT__ */
