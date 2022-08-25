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
 * camera_nvram_def.c
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
#ifndef NVRAM_NOT_PRESENT
/*
 *   Include Headers
 */

#include "kal_general_types.h"

/*
 *   NVRAM Basic Headers
 */
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "nvram_enums.h"
#include "nvram_defs.h"
#include "nvram_data_items.h"

/*
 *   User Headers
 */
#include "mmi_gps_nvram_def.h"


/*
 *   Default value
 */
#if defined(__AGPS_USER_PLANE__)
#if NVRAM_EF_AGPS_PROFILE_TOTAL > 0
static nvram_ef_agps_profile_struct const NVRAM_EF_AGPS_PROFILE_DEFAULT[NVRAM_EF_AGPS_PROFILE_TOTAL] =
{
    /* name                     addr                port */
    {{L"Default AGPS server"}, {L"supl.google.com"}, {7275}
#ifdef    __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}/* nap_id */
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}/* provurl */
#endif
    }
};
#endif /* #if NVRAM_EF_AGPS_PROFILE_TOTAL > 0 */
#endif /* #if defined(__AGPS_USER_PLANE__) */


/*
 *   LID table
 */
ltable_entry_struct logical_data_item_table_mmi_gps[] =
{
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    {
        NVRAM_EF_AGPS_SETTING_LID,
        NVRAM_EF_AGPS_SETTING_TOTAL,
        NVRAM_EF_AGPS_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP5F",
        VER(NVRAM_EF_AGPS_SETTING_LID)
    },

    {
        NVRAM_EF_EM_GPS_POS_TYPE_LID,
        NVRAM_EF_EM_GPS_POS_TYPE_TOTAL,
        NVRAM_EF_EM_GPS_POS_TYPE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP5G",
        VER(NVRAM_EF_EM_GPS_POS_TYPE_LID)
    },

    {
       NVRAM_EF_AGPS_QOP_SETTING_LID,
       NVRAM_EF_AGPS_QOP_SETTING_TOTAL,
       NVRAM_EF_AGPS_QOP_SETTING_SIZE,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       "MPDS",
       VER(NVRAM_EF_AGPS_QOP_SETTING_LID)
    },
#endif /* #if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__) */

#if defined(__AGPS_USER_PLANE__)
    {
       NVRAM_EF_AGPS_SUPL_NOTIFY_LID,
       NVRAM_EF_AGPS_SUPL_NOTIFY_TOTAL,
       NVRAM_EF_AGPS_SUPL_NOTIFY_SIZE,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       "MP5H",
       VER(NVRAM_EF_AGPS_SUPL_NOTIFY_LID)
    },
#endif /* #if defined(__AGPS_USER_PLANE__) */

#ifdef __AGPS_CONTROL_PLANE__
    {
       NVRAM_EF_AGPS_MTLR_LID,
       NVRAM_EF_AGPS_MTLR_TOTAL,
       NVRAM_EF_AGPS_MTLR_SIZE,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       "MP95",
       VER(NVRAM_EF_AGPS_MTLR_LID)
    },

    {
       NVRAM_EF_AGPS_CP_CONFIG_LID,
       NVRAM_EF_AGPS_CP_CONFIG_TOTAL,
       NVRAM_EF_AGPS_CP_CONFIG_SIZE,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       "MP97",
       VER(NVRAM_EF_AGPS_CP_CONFIG_LID)
    },
#endif

#if defined(__AGPS_USER_PLANE__)
    {
        NVRAM_EF_AGPS_CURRENT_PROFILE_LID,
        NVRAM_EF_AGPS_CURRENT_PROFILE_TOTAL,
        NVRAM_EF_AGPS_CURRENT_PROFILE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP98",
        VER(NVRAM_EF_AGPS_CURRENT_PROFILE_LID)
    },

    {
        NVRAM_EF_AGPS_EM_SETTING_LID,
        NVRAM_EF_AGPS_EM_SETTING_TOTAL,
        NVRAM_EF_AGPS_EM_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP99",
        VER(NVRAM_EF_AGPS_EM_SETTING_LID)
    },

    {
        NVRAM_EF_AGPS_PROFILE_LID,
        NVRAM_EF_AGPS_PROFILE_TOTAL,
        NVRAM_EF_AGPS_PROFILE_SIZE,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_AGPS_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET | NVRAM_ATTR_MULTI_DEFAULT,
        "MP9A",
        VER(NVRAM_EF_AGPS_PROFILE_LID)
    },

    {
        NVRAM_EF_AGPS_EM_STATUS_LID,
        NVRAM_EF_AGPS_EM_STATUS_TOTAL,
        NVRAM_EF_AGPS_EM_STATUS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP9B",
        VER(NVRAM_EF_AGPS_EM_STATUS_LID)
    },
#endif /* __AGPS_USER_PLANE__ */

#if defined(__AGPS_USER_PLANE__)
    {
        NVRAM_EF_AGPS_PAYLOAD_LID,
        NVRAM_EF_AGPS_PAYLOAD_TOTAL,
        NVRAM_EF_AGPS_PAYLOAD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPA7",
        VER(NVRAM_EF_AGPS_PAYLOAD_LID)
    },
#endif /* __AGPS_USER_PLANE__ */

#if defined(__GPS_SUPPORT__)
    {
        NVRAM_EF_GPS_MMI_SETTING_DATA_LID,
        NVRAM_EF_GPS_MMI_SETTING_DATA_TOTAL,
        NVRAM_EF_GPS_MMI_SETTING_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPDG",
        VER(NVRAM_EF_GPS_MMI_SETTING_DATA_LID)
    },

    #if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    {
        NVRAM_EF_GPS_MMI_SIM_DATA_LID,
        NVRAM_EF_GPS_MMI_SIM_DATA_TOTAL,
        NVRAM_EF_GPS_MMI_SIM_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPDH",
        VER(NVRAM_EF_GPS_MMI_SIM_DATA_LID)
    },
    #endif
#endif

#ifdef __AGPS_USER_PLANE__
	 {
        NVRAM_EM_MINIGPS_UP_SETTING_LID,
        NVRAM_EM_MINIGPS_UP_SETTING_TOTAL,
        NVRAM_EM_MINIGPS_UP_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPF0",
        VER(NVRAM_EM_MINIGPS_UP_SETTING_LID)
    },
#endif


};


#endif /* NVRAM_NOT_PRESENT */
#endif /* __GPS_SUPPORT__ */
