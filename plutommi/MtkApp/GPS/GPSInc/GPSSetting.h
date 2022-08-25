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

/*******************************************************************************
 * Filename:
 * ---------
 * GPSSetting.h
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __GPSSETTING_H__
#define __GPSSETTING_H__
#include "mmi_gps_nvram_def.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "GPSGProt.h"

#if defined(__GPS_SUPPORT__)

#define MMI_GPS_SIM_CARD_NUMBER     (NVRAM_EF_GPS_MMI_SIM_DATA_TOTAL)

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
typedef struct
{
    nvram_ef_gps_mmi_sim_struct         settings;
} mmi_gps_nvram_single_sim_settings_struct;
#endif

typedef struct
{
    nvram_ef_gps_mmi_settings_struct    gps;

#if defined(__AGPS_USER_PLANE__)
    nvram_ef_agps_profile_struct        agps_profile[NVRAM_EF_AGPS_PROFILE_TOTAL];/*profiles*/
#endif

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    mmi_gps_nvram_single_sim_settings_struct sim[MMI_GPS_SIM_CARD_NUMBER];
#endif
} mmi_gps_nvram_settings_struct;

typedef struct
{
    mmi_gps_nvram_settings_struct settings;
} mmi_gps_settings_cntx_struct;

extern mmi_gps_setting_prefer_sim_enum mmi_gps_setting_get_sim(void);
extern MMI_BOOL mmi_gps_setting_get_is_agps_on(void);
extern void mmi_gps_setting_set_agps_on_off(U8 on_off);
extern MMI_BOOL mmi_gps_setting_set_data_account(U8 sim, U32 data_account);
extern U32 mmi_gps_setting_get_data_account(U8 sim);
extern void mmi_gps_setting_set_time_sync(U8 time_sync);
extern MMI_BOOL mmi_gps_setting_get_time_sync(void);

extern S32 mmi_gps_get_port_number(void);
extern void mmi_gps_set_receiver_setting(U8 receiver);
extern U8 mmi_gps_get_receiver_setting(void);
extern MMI_BOOL mmi_gps_check_if_can_use_agps(void);
extern void mmi_gps_setting_set_mtlr(U8 mtlr);
extern U8 mmi_gps_setting_get_mtlr(void);
extern void mmi_gps_setting_set_send_location(U8 send_location);
extern U8 mmi_gps_setting_get_send_location(void);

extern void mmi_gps_setting_set_mmi_setting(nvram_ef_gps_mmi_settings_struct *setting);
extern void mmi_gps_setting_get_mmi_setting(nvram_ef_gps_mmi_settings_struct *setting);
#if defined(__AGPS_USER_PLANE__)
    extern void mmi_gps_setting_set_profile(nvram_ef_agps_profile_struct *profile);
    extern void mmi_gps_setting_get_profile(nvram_ef_agps_profile_struct *profile);
    extern void mmi_gps_setting_set_supl_notify_setting(nvram_ef_agps_supl_notify_struct* notify);
    extern void mmi_gps_setting_get_supl_notify_setting(nvram_ef_agps_supl_notify_struct* notify);
    extern void mmi_gps_setting_set_up_setting(nvram_em_minigps_up_setting_struct* setting);
    extern void mmi_gps_setting_get_up_setting(nvram_em_minigps_up_setting_struct* setting);
#endif

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    extern void mmi_gps_setting_set_sim_setting(U8 sim, nvram_ef_gps_mmi_sim_struct *sim_setting);
    extern void mmi_gps_setting_get_sim_setting(U8 sim, nvram_ef_gps_mmi_sim_struct *sim_setting);
#endif

extern void mmi_gps_setting_set_server_addr(U8 sim, const void *buffer, U32 size);
extern void mmi_gps_setting_get_server_addr(U8 sim, void *buffer, U32 size);
extern void mmi_gps_setting_set_server_port(U8 sim, U32 port);
extern U32 mmi_gps_setting_get_server_port(U8 sim);
extern void mmi_gps_setting_set_em_on_off(MMI_BOOL on_off);
extern MMI_BOOL mmi_gps_setting_get_em_on_off(void);
#ifdef __FLIGHT_MODE_DISABLE_AGPS__
extern void mmi_gps_setting_set_flight_mode_agps(MMI_BOOL on_off);
extern MMI_BOOL mmi_gps_setting_get_flight_mode_agps(void);
#endif

#endif // #if defined(__GPS_SUPPORT__)

#endif /* __GPSSETTING_H__ */


