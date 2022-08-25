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
 * camera_nvram_editor.h
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
#ifndef __VENUS_GPS_NVRAM_EDITOR_H__
#define __VENUS_GPS_NVRAM_EDITOR_H__
#ifndef NVRAM_NOT_PRESENT

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*
 *   Include Headers
 */


/*
 *   NVRAM Basic Headers
 */
#include "nvram_data_items.h"

/*
 *   User Headers
 */
#include "mmi_gps_nvram_def.h"


/*
 *   Bit Level Description Language
 */
#ifdef GEN_FOR_PC
BEGIN_NVRAM_DATA

#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)

    #if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
     LID_BIT VER_LID(NVRAM_EF_GPS_MMI_SIM_DATA_LID)
     nvram_ef_gps_mmi_sim_struct *NVRAM_EF_GPS_MMI_SIM_DATA_TOTAL
     {
     };
    #endif
     LID_BIT VER_LID(NVRAM_EF_GPS_MMI_SETTING_DATA_LID)
     nvram_ef_gps_mmi_settings_struct *NVRAM_EF_GPS_MMI_SETTING_DATA_TOTAL
     {
     };
#endif /* defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__) */

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
     LID_BIT VER_LID(NVRAM_EF_AGPS_SETTING_LID)
     nvram_ef_agps_setting_struct *NVRAM_EF_AGPS_SETTING_TOTAL
     {
     };

     LID_BIT VER_LID(NVRAM_EF_EM_GPS_POS_TYPE_LID)
     nvram_ef_em_gps_pos_type_struct *NVRAM_EF_EM_GPS_POS_TYPE_TOTAL
     {
     };

     LID_BIT VER_LID(NVRAM_EF_AGPS_QOP_SETTING_LID)
     nvram_ef_agps_qop_setting_struct *NVRAM_EF_AGPS_QOP_SETTING_TOTAL
     {
     };
#endif

#if defined(__AGPS_USER_PLANE__)
     LID_BIT VER_LID(NVRAM_EF_AGPS_CURRENT_PROFILE_LID)
     nvram_ef_agps_current_profile_struct *NVRAM_EF_AGPS_CURRENT_PROFILE_TOTAL
     {
     };

     LID_BIT VER_LID(NVRAM_EF_AGPS_EM_SETTING_LID)
     nvram_ef_agps_em_setting_struct *NVRAM_EF_AGPS_EM_SETTING_TOTAL
     {
     };

     LID_BIT VER_LID(NVRAM_EF_AGPS_PROFILE_LID)
     nvram_ef_agps_profile_struct *NVRAM_EF_AGPS_PROFILE_TOTAL
     {
     };

     LID_BIT VER_LID(NVRAM_EF_AGPS_EM_STATUS_LID)
     nvram_ef_agps_em_status_struct *NVRAM_EF_AGPS_EM_STATUS_TOTAL
     {
     };

     LID_BIT VER_LID(NVRAM_EF_AGPS_PAYLOAD_LID)
     nvram_ef_agps_payload_struct *NVRAM_EF_AGPS_PAYLOAD_TOTAL
     {
     };

     LID_BIT VER_LID(NVRAM_EF_AGPS_SUPL_NOTIFY_LID)
     nvram_ef_agps_supl_notify_struct *NVRAM_EF_AGPS_SUPL_NOTIFY_TOTAL
     {
     };
#endif /* __AGPS_USER_PLANE__ */

#if defined(__AGPS_CONTROL_PLANE__)
     LID_BIT VER_LID(NVRAM_EF_AGPS_MTLR_LID)
     nvram_ef_agps_mtlr_struct *NVRAM_EF_AGPS_MTLR_TOTAL
     {
     };

     LID_BIT VER_LID(NVRAM_EF_AGPS_CP_CONFIG_LID)
     nvram_ef_agps_cp_config_struct *NVRAM_EF_AGPS_CP_CONFIG_TOTAL
     {
     };
#endif /* __AGPS_USER_PLANE__ */

#ifdef __AGPS_USER_PLANE__
	  LID_BIT VER_LID(NVRAM_EM_MINIGPS_UP_SETTING_LID)
     nvram_em_minigps_up_setting_struct *NVRAM_EM_MINIGPS_UP_SETTING_TOTAL
     {
     };
#endif

END_NVRAM_DATA

#endif  /* GEN_FOR_PC */
#endif  /* !NVRAM_NOT_PRESENT */
#endif  /* __VENUS_GPS_NVRAM_EDITOR_H__ */
#endif /* __GPS_SUPPORT__ */
