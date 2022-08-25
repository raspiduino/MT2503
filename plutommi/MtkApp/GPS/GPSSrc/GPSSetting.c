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
 * GPSSetting.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   The GPS setting menu file
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"

#if defined(__GPS_SUPPORT__)

#include "mdi_datatype.h"
#include "GPSGProt.h"
#include "GPSSetting.h"
#include "NwUsabSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "MMIDataType.h"
#include "string.h"
#include "mmi_gps_nvram_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "stack_config.h"
#include "DtcntSrvGprot.h"
#include "kal_trace.h"
#include "mmi_media_app_trc.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mdi_gps.h"
#include "cbm_api.h"

#if defined(__AGPS_USER_PLANE__)
static mmi_gps_settings_cntx_struct g_gps_settings_cntx;
#endif

/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_get_sim
* DESCRIPTION
*  get prefer sim
* PARAMETERS
*  void
* RETURNS
*  mmi_gps_setting_prefer_sim_enum
*****************************************************************************/
mmi_gps_setting_prefer_sim_enum mmi_gps_setting_get_sim(void)
{
    mmi_gps_setting_prefer_sim_enum prefer_sim;
    srv_dtcnt_sim_type_enum sim_type = SRV_DTCNT_SIM_TYPE_1;

    srv_dtcnt_get_sim_preference(&sim_type);
    switch(sim_type)
    {
    case SRV_DTCNT_SIM_TYPE_1:
        prefer_sim = MMI_GPS_SETTING_PREFER_SIM_NO1;
        break;
    case SRV_DTCNT_SIM_TYPE_2:
        prefer_sim = MMI_GPS_SETTING_PREFER_SIM_NO2;
        break;
    case SRV_DTCNT_SIM_TYPE_3:
        prefer_sim = MMI_GPS_SETTING_PREFER_SIM_NO3;
        break;
    case SRV_DTCNT_SIM_TYPE_4:
        prefer_sim = MMI_GPS_SETTING_PREFER_SIM_NO4;
        break;
    default:
        prefer_sim = MMI_GPS_SETTING_PREFER_SIM_NO1;
        break;
    }

    return prefer_sim;
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_set_agps_on_off
* DESCRIPTION
*  save GPS setting and (mmi_void_funcptr_type)mmi_frm_scrn_close_active_id
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_gps_setting_set_agps_on_off(U8 on_off)
{
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    nvram_ef_gps_mmi_settings_struct gps_setting;

    mmi_gps_setting_get_mmi_setting(&gps_setting);

    gps_setting.agps_on_off = on_off;

    mmi_gps_setting_set_mmi_setting(&gps_setting);
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_get_is_agps_on
* DESCRIPTION
*  save GPS setting and (mmi_void_funcptr_type)mmi_frm_scrn_close_active_id
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL mmi_gps_setting_get_is_agps_on(void)
{
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    nvram_ef_gps_mmi_settings_struct gps_setting;

    mmi_gps_setting_get_mmi_setting(&gps_setting);

    return (MMI_BOOL)gps_setting.agps_on_off;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_set_data_account
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL mmi_gps_setting_set_data_account(U8 sim, U32 data_account)
{
#if !defined(__AGPS_USER_PLANE__)
    return MMI_TRUE;
#else
    nvram_ef_gps_mmi_sim_struct sim_setting;

    if (sim >= MMI_GPS_SIM_CARD_NUMBER)
    {
        return MMI_FALSE;
    }
    ASSERT (sim < MMI_GPS_SIM_CARD_NUMBER);

    mmi_gps_setting_get_sim_setting(sim, &sim_setting);

    sim_setting.data_account = cbm_encode_data_account_id(data_account, (cbm_sim_id_enum)sim, 0, MMI_FALSE);

    mmi_gps_setting_set_sim_setting(sim, &sim_setting);

    return MMI_TRUE;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_get_data_account
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
U32 mmi_gps_setting_get_data_account(U8 sim)
{
#if !defined(__AGPS_USER_PLANE__)
    return 0;
#else
    nvram_ef_gps_mmi_sim_struct sim_setting;

    if (sim >= MMI_GPS_SIM_CARD_NUMBER)
    {
        return 0;
    }
    ASSERT (sim < MMI_GPS_SIM_CARD_NUMBER);

    mmi_gps_setting_get_sim_setting(sim, &sim_setting);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MDI_GPS_SETTING_DATA_ACCOUNT, sim_setting.data_account);

    return sim_setting.data_account;
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_get_time_sync
* DESCRIPTION
*  save GPS setting and (mmi_void_funcptr_type)mmi_frm_scrn_close_active_id
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_gps_setting_set_time_sync(U8 time_sync)
{
    nvram_ef_gps_mmi_settings_struct gps_setting;

    mmi_gps_setting_get_mmi_setting(&gps_setting);

    gps_setting.time_sync = time_sync;

    mmi_gps_setting_set_mmi_setting(&gps_setting);
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_get_time_sync
* DESCRIPTION
*  save GPS setting and (mmi_void_funcptr_type)mmi_frm_scrn_close_active_id
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL mmi_gps_setting_get_time_sync(void)
{
    nvram_ef_gps_mmi_settings_struct gps_setting;

    mmi_gps_setting_get_mmi_setting(&gps_setting);

    if(gps_setting.time_sync == 0xff || gps_setting.time_sync == MMI_TRUE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_get_port_number
* DESCRIPTION
*  app can get the right uart port to use by calling this function
* PARAMETERS
*  void
* RETURNS
*  connected uart port number if great then 0 , else return -1
*****************************************************************************/
S32 mmi_gps_get_port_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 receive_on_off;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_GIS_TRC_GET_PORT_NUM);

    receive_on_off = mmi_gps_get_receiver_setting();
    if(receive_on_off == MMI_GPS_RECEIVER_YES){
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_GIS_TRC_RETURN_ON_BROAD_PORT);
        return mdi_get_gps_port();
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_GIS_TRC_GPS_OFF);
    return -1;
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_set_receiver_setting
* DESCRIPTION
*  the callback function for sdp
* PARAMETERS
*  srv_chnl_num     [IN]        the channel of service
* RETURNS
*  void
*****************************************************************************/
void mmi_gps_set_receiver_setting(U8 receiver)
{
    nvram_ef_gps_mmi_settings_struct gps_setting;

    mmi_gps_setting_get_mmi_setting(&gps_setting);

    gps_setting.receiver = receiver;

    mmi_gps_setting_set_mmi_setting(&gps_setting);
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_get_receiver_setting
* DESCRIPTION
*  the callback function for sdp
* PARAMETERS
*  srv_chnl_num     [IN]        the channel of service
* RETURNS
*  void
*****************************************************************************/
U8 mmi_gps_get_receiver_setting(void)
{
    nvram_ef_gps_mmi_settings_struct gps_setting;

#if defined(__PLUTO_MMI_PACKAGE__) //&& defined(__ATT_FLIGHT_MODE_GPS_HANDLING__)
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)  /* Flight mode */
    {
        return MMI_GPS_RECEIVER_OFF;
    }
#endif

    mmi_gps_setting_get_mmi_setting(&gps_setting);
    if (gps_setting.receiver == 0xff)
    {
        gps_setting.receiver = MMI_GPS_RECEIVER_OFF;
        mmi_gps_setting_set_mmi_setting(&gps_setting);
    }
    return gps_setting.receiver;
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_check_if_can_use_agps
* DESCRIPTION
*  check if can use agps
* PARAMETERS
*  void
* RETURNS
*  result
*****************************************************************************/
MMI_BOOL mmi_gps_check_if_can_use_agps(void)
{
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 is_agps_on;
    MMI_BOOL is_usable = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_gps_get_receiver_setting() != MMI_GPS_RECEIVER_YES)
    {
        return MMI_FALSE;
    }

    is_agps_on = mmi_gps_setting_get_is_agps_on();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_IS_AGPS_ON, is_agps_on);

    if (is_agps_on == MMI_FALSE)  /* AGPS Off */
    {
        return MMI_FALSE;
    }

    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)  /* Flight mode */
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_FLIGHT_MODE);
        return MMI_FALSE;
    }

    is_usable = srv_nw_usab_is_usable(MMI_SIM1);

    #if MMI_SIM_TOTAL > 1
        if (MMI_FALSE == is_usable)
        {
            is_usable = srv_nw_usab_is_usable(MMI_SIM2);
        }
    #endif

    #if MMI_SIM_TOTAL > 2
        if (MMI_FALSE == is_usable)
        {
            is_usable = srv_nw_usab_is_usable(MMI_SIM3);
        }
    #endif

    #if MMI_SIM_TOTAL > 3
        if (MMI_FALSE == is_usable)
        {
            is_usable = srv_nw_usab_is_usable(MMI_SIM4);
        }
    #endif

    if (is_usable == MMI_FALSE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_GPS_MGR_SIM_NOT_VAILD);
    }

    return is_usable;
#endif
    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*  mmi_gps_get_mtlr_setting
* DESCRIPTION
*  get mtlr item setting
* PARAMETERS
*  void
* RETURNS
*  result
*****************************************************************************/
void mmi_gps_setting_set_mtlr(U8 mtlr)
{
#if defined(__AGPS_CONTROL_PLANE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_AGPS_MTLR_LID, 1, &mtlr, NVRAM_EF_AGPS_MTLR_SIZE, &error);
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_gps_get_mtlr_setting
* DESCRIPTION
*  get mtlr item setting
* PARAMETERS
*  void
* RETURNS
*  result
*****************************************************************************/
U8 mmi_gps_setting_get_mtlr(void)
{
#if defined(__AGPS_CONTROL_PLANE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mtlr_setting;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_AGPS_MTLR_LID, 1, &mtlr_setting, NVRAM_EF_AGPS_MTLR_SIZE, &error);

    if (mtlr_setting == 0xff)
    {
        mtlr_setting = 0;
        WriteRecord(NVRAM_EF_AGPS_MTLR_LID, 1, &mtlr_setting, NVRAM_EF_AGPS_MTLR_SIZE, &error);
    }
    return mtlr_setting;
#else
    return 0;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_get_send_location_setting
* DESCRIPTION
*  get send location item setting
* PARAMETERS
*  void
* RETURNS
*  result
*****************************************************************************/
void mmi_gps_setting_set_send_location(U8 send_location)
{
#if defined(__AGPS_CONTROL_PLANE__)
    nvram_ef_gps_mmi_settings_struct gps_setting;

    mmi_gps_setting_get_mmi_setting(&gps_setting);

    gps_setting.send_location = send_location;

    mmi_gps_setting_set_mmi_setting(&gps_setting);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_get_send_location_setting
* DESCRIPTION
*  get send location item setting
* PARAMETERS
*  void
* RETURNS
*  result
*****************************************************************************/
U8 mmi_gps_setting_get_send_location(void)
{
#if defined(__AGPS_CONTROL_PLANE__) || defined(__AGPS_USER_PLANE__)
    nvram_ef_gps_mmi_settings_struct gps_setting;

    mmi_gps_setting_get_mmi_setting(&gps_setting);

    return gps_setting.send_location;
#else
    return 0;
#endif
}

void mmi_gps_setting_set_mmi_setting(nvram_ef_gps_mmi_settings_struct *setting)
{
    S16 error;

    WriteRecord(NVRAM_EF_GPS_MMI_SETTING_DATA_LID, 1, setting, NVRAM_EF_GPS_MMI_SETTING_DATA_SIZE, &error);
}

void mmi_gps_setting_get_mmi_setting(nvram_ef_gps_mmi_settings_struct *setting)
{
    S16 error;
    MMI_BOOL modified = MMI_FALSE;

    ReadRecord(NVRAM_EF_GPS_MMI_SETTING_DATA_LID, 1, setting, NVRAM_EF_GPS_MMI_SETTING_DATA_SIZE, &error);

    if (setting->receiver == 0xff)
    {
        setting->receiver = 0;
        modified = MMI_TRUE;
    }
    if (setting->time_sync == 0xff)
    {
        setting->time_sync = 0;
        modified = MMI_TRUE;
    }
    if (setting->em_on_off == 0xff)
    {
        setting->em_on_off = 0;
        modified = MMI_TRUE;
    }
    if (setting->agps_on_off == 0xff)
    {
        setting->agps_on_off = MMI_TRUE;
        modified = MMI_TRUE;
    }
    if (setting->send_location == 0xff)
    {
        #if defined(__ALLOW_FORBIDDEN_MY_LOCATION__)
            /* user can modify, so set it as default off */
            setting->send_location = 0;
        #else
            /* user can't modify, so set it as default ON, for NI case */
            setting->send_location = 1;
        #endif
        modified = MMI_TRUE;
    }

    if (modified == MMI_TRUE)
    {
        mmi_gps_setting_set_mmi_setting(setting);
    }
}

#if defined(__AGPS_USER_PLANE__)
void mmi_gps_setting_set_profile(nvram_ef_agps_profile_struct *profile)
{
    S16 error;

    WriteRecord(NVRAM_EF_AGPS_PROFILE_LID, 1, (void*)profile, NVRAM_EF_AGPS_PROFILE_SIZE, &error);
}

void mmi_gps_setting_get_profile(nvram_ef_agps_profile_struct *profile)
{
    S16 error;

    ReadRecord(NVRAM_EF_AGPS_PROFILE_LID, 1, profile, NVRAM_EF_AGPS_PROFILE_SIZE, &error);
}

void mmi_gps_setting_set_supl_notify_setting(nvram_ef_agps_supl_notify_struct* notify)
{
    S16 error;

    WriteRecord(NVRAM_EF_AGPS_SUPL_NOTIFY_LID, 1, notify, NVRAM_EF_AGPS_SUPL_NOTIFY_SIZE, &error);
}

void mmi_gps_setting_get_supl_notify_setting(nvram_ef_agps_supl_notify_struct* notify)
{
    S16 error;
    MMI_BOOL need_store = MMI_FALSE;

    ReadRecord(NVRAM_EF_AGPS_SUPL_NOTIFY_LID, 1, (void*)notify, NVRAM_EF_AGPS_SUPL_NOTIFY_SIZE, &error);
    if (notify->notify_time == 0xFFFFFFFF)
    {
        notify->notify_time = 10000; // default 10 sec.
        need_store = MMI_TRUE;
    }

    if (need_store)
    {
        WriteRecord(NVRAM_EF_AGPS_SUPL_NOTIFY_LID, 1, (void*)notify, NVRAM_EF_AGPS_SUPL_NOTIFY_SIZE, &error);
    }
}

void mmi_gps_setting_set_up_setting(nvram_em_minigps_up_setting_struct* setting)
{
    S16 error;

    WriteRecord(NVRAM_EM_MINIGPS_UP_SETTING_LID, 1, setting, NVRAM_EM_MINIGPS_UP_SETTING_SIZE, &error);
}

void mmi_gps_setting_get_up_setting(nvram_em_minigps_up_setting_struct* setting)
{
    S16 error;
    MMI_BOOL need_store = MMI_FALSE;

    ReadRecord(NVRAM_EM_MINIGPS_UP_SETTING_LID, 1, setting, NVRAM_EM_MINIGPS_UP_SETTING_SIZE, &error);

    if (setting->payload >= EM_GPS_UP_PAYLOAD_END)
    {
        setting->payload = EM_GPS_UP_PAYLOAD_BOTH;
        need_store = KAL_TRUE;
    }

    if (setting->molr_prefer == 0xff)
    {
        setting->molr_prefer = 0;
        need_store = KAL_TRUE;
    }

    if (setting->use_tls != KAL_TRUE &&
        setting->use_tls != KAL_FALSE)
    {
        setting->use_tls = KAL_TRUE;
        need_store = KAL_TRUE;
    }

    if (setting->ut_timer > 255)
    {
        /* invalid setting, set to default */
        setting->ut_timer = 10;
        need_store = MMI_TRUE;
    }

    if (need_store == KAL_TRUE)
    {
        mmi_gps_setting_set_up_setting(setting);
    }
}
#endif  //#if defined(__AGPS_USER_PLANE__)

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
void mmi_gps_setting_set_sim_setting(U8 sim, nvram_ef_gps_mmi_sim_struct *sim_setting)
{
    S16 error;

    WriteRecord(NVRAM_EF_GPS_MMI_SIM_DATA_LID, sim + 1, (void*)sim_setting, NVRAM_EF_GPS_MMI_SIM_DATA_SIZE, &error);
}

void mmi_gps_setting_get_sim_setting(U8 sim, nvram_ef_gps_mmi_sim_struct *sim_setting)
{
    S16 error;

    ReadRecord(NVRAM_EF_GPS_MMI_SIM_DATA_LID, sim + 1,
        (void*)sim_setting,
        NVRAM_EF_GPS_MMI_SIM_DATA_SIZE,
        &error);

    if (sim_setting->data_account == 0xFFFFFFFF)
    {
        sim_setting->data_account = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, (cbm_sim_id_enum)sim, 0, MMI_FALSE);
        mmi_gps_setting_set_sim_setting(sim, sim_setting);
    }
}
#endif  //#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)

/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_set_server_addr
* DESCRIPTION
*  set server_addr
* PARAMETERS
*  void
* RETURNS
*  result
*****************************************************************************/
void mmi_gps_setting_set_server_addr(U8 sim, const void *buffer, U32 size)
{
#if !defined(__AGPS_USER_PLANE__)
    return ;
#else
    nvram_ef_agps_profile_struct *profile_p;

    /* only 1 sim setting now. */
    sim = 0;

    if (sim >= MMI_GPS_SIM_CARD_NUMBER)
    {
        return ;
    }
    ASSERT (sim < MMI_GPS_SIM_CARD_NUMBER);
    profile_p = &g_gps_settings_cntx.settings.agps_profile[0];

    mmi_gps_setting_get_profile(profile_p);

    memcpy(profile_p->addr, (U8*)buffer, AGPS_MAX_PROFILE_ADDR_LEN * 2);

    mmi_gps_setting_set_profile(profile_p);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_get_send_location_setting
* DESCRIPTION
*  get send location item setting
* PARAMETERS
*  void
* RETURNS
*  result
*****************************************************************************/
void mmi_gps_setting_get_server_addr(U8 sim, void *buffer, U32 size)
{
#if !defined(__AGPS_USER_PLANE__)
    return;
#else
    nvram_ef_agps_profile_struct *profile_p;

    /* only 1 sim setting now. */
    sim = 0;

    if (sim >= MMI_GPS_SIM_CARD_NUMBER)
    {
        return ;
    }
    ASSERT (sim < MMI_GPS_SIM_CARD_NUMBER);
    profile_p = &g_gps_settings_cntx.settings.agps_profile[0];

    mmi_gps_setting_get_profile(profile_p);

    ASSERT(size >= AGPS_MAX_PROFILE_ADDR_LEN * 2);
    profile_p->addr[AGPS_MAX_PROFILE_ADDR_LEN - 1] = 0;
    memcpy((U8*)buffer, (U8*)profile_p->addr, AGPS_MAX_PROFILE_ADDR_LEN * 2);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_get_send_location_setting
* DESCRIPTION
*  get send location item setting
* PARAMETERS
*  void
* RETURNS
*  result
*****************************************************************************/
void mmi_gps_setting_set_server_port(U8 sim, U32 port)
{
#if !defined(__AGPS_USER_PLANE__)
    return ;
#else
    nvram_ef_agps_profile_struct *profile_p;

    profile_p = &g_gps_settings_cntx.settings.agps_profile[0];

    mmi_gps_setting_get_profile(profile_p);
    profile_p->port = port;
    mmi_gps_setting_set_profile(profile_p);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_get_send_location_setting
* DESCRIPTION
*  get send location item setting
* PARAMETERS
*  void
* RETURNS
*  result
*****************************************************************************/
U32 mmi_gps_setting_get_server_port(U8 sim)
{
#if !defined(__AGPS_USER_PLANE__)
    return 0;
#else
    nvram_ef_agps_profile_struct *profile_p;

    profile_p = &g_gps_settings_cntx.settings.agps_profile[0];

    mmi_gps_setting_get_profile(profile_p);

    return profile_p->port;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_set_em_on_off
* DESCRIPTION
*  get send location item setting
* PARAMETERS
*  void
* RETURNS
*  result
*****************************************************************************/
void mmi_gps_setting_set_em_on_off(MMI_BOOL on_off)
{
    nvram_ef_gps_mmi_settings_struct gps_setting;

    mmi_gps_setting_get_mmi_setting(&gps_setting);

    gps_setting.em_on_off = on_off;

    mmi_gps_setting_set_mmi_setting(&gps_setting);
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_get_em_on_off
* DESCRIPTION
*  get send location item setting
* PARAMETERS
*  void
* RETURNS
*  result
*****************************************************************************/
MMI_BOOL mmi_gps_setting_get_em_on_off(void)
{
    nvram_ef_gps_mmi_settings_struct gps_setting;

    mmi_gps_setting_get_mmi_setting(&gps_setting);

    return (MMI_BOOL)gps_setting.em_on_off;
}

#ifdef __FLIGHT_MODE_DISABLE_AGPS__
/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_set_flight_mode_agps
* DESCRIPTION
*  it is set on if agps and flight mode and on
* PARAMETERS
*  void
* RETURNS
*  result
*****************************************************************************/
void mmi_gps_setting_set_flight_mode_agps(MMI_BOOL on_off)
{
    nvram_ef_gps_mmi_settings_struct gps_setting;

    mmi_gps_setting_get_mmi_setting(&gps_setting);

    gps_setting.agps_flight_mode = on_off;

    mmi_gps_setting_set_mmi_setting(&gps_setting);
}


/*****************************************************************************
* FUNCTION
*  mmi_gps_setting_get_flight_mode_agps
* DESCRIPTION
*  get status of agps in flight mode
* PARAMETERS
*  void
* RETURNS
*  result
*****************************************************************************/
MMI_BOOL mmi_gps_setting_get_flight_mode_agps(void)
{
    nvram_ef_gps_mmi_settings_struct gps_setting;

    mmi_gps_setting_get_mmi_setting(&gps_setting);

    if (0xFF == gps_setting.agps_flight_mode)
    {
        gps_setting.agps_flight_mode = MMI_FALSE;
    }

    return (MMI_BOOL)gps_setting.agps_flight_mode;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_gps_setting_dtcnt_notify_hdlr
 * DESCRIPTION
 *  check data account status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_gps_setting_dtcnt_notify_hdlr(mmi_event_struct *param)
{
#if defined(__AGPS_USER_PLANE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_account_info_struct info;
    U32 data_acct;
    U32 i,j;
    U8 sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //sim_id = mmi_gps_setting_get_sim();
    for(sim_id = 0; sim_id < MMI_MAX_SIM_NUM; sim_id++)
    {
        data_acct = mmi_gps_setting_get_data_account(sim_id);

        if (cbm_decode_data_account_id_ext(data_acct, &info) == CBM_OK)
        {
            switch(param->evt_id)
            {
                case EVT_ID_SRV_DTCNT_ACCT_DELETE_IND:
                {
                    srv_dtcnt_acct_delete_ind_evt_struct *event = (srv_dtcnt_acct_delete_ind_evt_struct *)param;
                    for (i = 0; i < info.acct_num; i++)
                    {
                        for (j = 0; j < event->del_num; j++)
                        {
                            if (event->acc_id[j] == info.account[i].account_id)
                            {
                                 data_acct = CBM_DEFAULT_ACCT_ID;
                                 mmi_gps_setting_set_data_account(sim_id, data_acct);
                            }
                        }
                    }
                }
                break;

                case EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND:
                {
                    srv_dtcnt_acct_update_ind_evt_struct *event = (srv_dtcnt_acct_update_ind_evt_struct *)param;
                    for (i = 0; i < info.acct_num; i++)
                    {
                        if (event->acc_id == info.account[i].account_id && event->cause ==  1)
                        {
                            srv_dtcnt_bearer_enum bearer = srv_dtcnt_get_bearer_type(event->acc_id, SRV_DTCNT_ACCOUNT_PRIMARY);
                            if (bearer != SRV_DTCNT_BEARER_GPRS && bearer != SRV_DTCNT_BEARER_WIFI)
                            {
                                data_acct = CBM_DEFAULT_ACCT_ID;
                                mmi_gps_setting_set_data_account(sim_id, data_acct);
                            }
                        }
                    }
                }
                break;
            }
        }
    }
#endif // #if defined(__AGPS_USER_PLANE__)

    return MMI_RET_OK;
}

#endif /* __GPS_SUPPORT__ */

