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
 * JavaSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to handle all scenario of Java Content Manager and 
 *   interaction betweens MMI and Java task.
 *
 * Author:
 * -------
 * -------
 * -------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifdef __J2ME__
#include "MMI_include.h"

#include "kal_public_api.h"
#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
#include "jam_msg_handler.h"
#include "JavaAppFactorySrvGprot.h"
#include "jal.h"
#include "jam_internal.h"

#include "drm_def.h"
#include "drm_gprot.h"

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
#endif
#include "SettingProfileEnum.h"

//#include "MTPNP_AD_master_header.h"
#include "IdleNotificationManagerGProt.h"
//#include "SimDetectionDef.h"            /* SCR_SIM_INSERTION*/
#include "PhoneBookDef.h"               /* IMG_PROCESSING_PHONEBOOK */
#include "ProtocolEvents.h"             /* PRT_GET_IMSI_RSP*/
#include "CommonScreens.h"              /* DisplayPopup */
#include "AlarmFrameworkProt.h"         /* AlmIsTonePlaying()*/
//#include "CallManagementGprot.h"        /* GetCmMarkerScrnID */
//#include "SimDetectionGprot.h"          /* mmi_bootup_is_sim_valid() */
#ifdef __MMI_UCM__
#include "UCMGprot.h"
#endif
#include "UcmSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#ifdef __MMI_MMS_2__
#ifndef __COSMOS_MMI_PACKAGE__
#include "MMSAppCommonGprot.h"  
#endif /* __MMI_MMS_2__ */
#endif
#ifndef __COSMOS_MMI_PACKAGE__
#ifdef WAP_SUPPORT
#include "WAPPushGprots.h"
#endif
#endif
#include "SmsGuiInterfaceProt.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_mainmenu_def.h"
#endif
#include "NetSetAppGprot.h"
#include "idleappresdef.h"
#include "timerevents.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_java_srv.h"
#include "vapp_launcher_gprot.h"
#endif
#include "shutdownsrvgprot.h"
#ifdef __MMI_NCENTER_SUPPORT__
#include "vapp_ncenter_gprot.h"
#endif

kal_bool g_jam_user_update_setting_exclusive = KAL_FALSE;
kal_int32 g_mmi_java_select_permission_vm_id = -1;

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
CHAR *mmi_java_ucs2cat_secure(CHAR *strDestination, const CHAR *strSource, S32 destSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n = mmi_ucs2strlen(strDestination);

    destSize = destSize / 2;

    if (destSize - n - 1 <= 0)
    {
        return NULL;
    }

    return mmi_ucs2ncat(strDestination, strSource, destSize - n - 1 );
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_msg_screen_active
 * DESCRIPTION
 *  this function is to check if active screen is msg-related screen
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_java_is_msg_screen_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_2__
#ifndef __COSMOS_MMI_PACKAGE__
    if (mmi_umms_app_if_is_msg_screen_active())
    {
        return MMI_TRUE;
    }
#endif /* __MMI_MMS_2__ */
#endif


#if defined(__WAP_PUSH_SUPPORT__) && defined(__WAP_PUSH_SERVICE_ONLY_SUPPORT__)/* The folloing API is not available in cosmos */
#ifndef __COSMOS_MMI_PACKAGE__
    if (mmi_brw_push_is_new_msg_popup_scr_active())
    {
        return MMI_TRUE;
    }
#endif
#endif /* __WAP_PUSH_SUPPORT__ */

    if (mmi_msg_is_new_msg_popup_scr_active())
    {
        return MMI_TRUE;        
    }
#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
    if (mmi_nmgr_is_active())
    {
        return MMI_TRUE;
    }
#endif
    
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_in_voice_call
 * DESCRIPTION
 *  this function use to detect taht current have voice call or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_java_is_in_voice_call_ext(MMI_BOOL avoid_bg_call)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*if (AlmIsTonePlaying())
    {
        return MMI_TRUE;
    }*/

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        /*
            outgoing/incoming => true
            wap call connecting  => true
            wap call connected => false
            backgroun call => false
            other call connecting/connected => true
        */

        if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 || 
            srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
        {
            return MMI_TRUE;
        }

    #ifdef __MMI_UCM__
        if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
    #else
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CSD_CALL_TYPE_ALL, NULL) > 0)
    #endif
        {
            return MMI_FALSE;
        }
        else
        {
        #ifdef __MMI_BACKGROUND_CALL__
            if (avoid_bg_call && srv_ucm_is_background_call())
            {
                return MMI_FALSE;
            }
        #endif

            return MMI_TRUE;
        }
    }
    else
    {
#ifdef __PLUTO_MMI_PACKAGE__
        if (GetActiveScreenId()==mmi_ucm_get_marker_scrn_id() ||
            mmi_frm_group_is_present(mmi_ucm_get_marker_scrn_id()))
        {
            /* special case here, sometimes CM change state too early
                but still have call marker in the history */
            return MMI_TRUE;
        }
#endif
        return MMI_FALSE;
    }

}

#if defined(__OP01__ )  && defined(J2ME_SUPPORT_BACKGROUND)
/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_in_voice_call
 * DESCRIPTION
 *  this function use to detect taht current have voice call or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_java_is_in_voice_call_op11()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (AlmIsTonePlaying())
    {
        return MMI_TRUE;
    }

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        /*
            outgoing/incoming => true
            wap call connecting  => true
            wap call connected => false
            backgroun call => false
            other call connecting/connected => true
        */

        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
        {
            return MMI_TRUE;

        }
    }
    else
    {
        if (GetActiveScreenId()==mmi_ucm_get_marker_scrn_id() ||
            mmi_frm_group_is_present(mmi_ucm_get_marker_scrn_id()))
        {
            /* special case here, sometimes CM change state too early
                but still have call marker in the history */
            return MMI_TRUE;
        }

        return MMI_FALSE;
    }

}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_in_voice_call
 * DESCRIPTION
 *  this function use to detect taht current have voice call or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_java_is_in_voice_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_java_is_in_voice_call_ext(MMI_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_need_block_msg
 * DESCRIPTION
 *  this function use to detect taht current have voice call or not
 *  then java task cannot send message to MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_java_need_block_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_java_is_in_voice_call_ext(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_in_idle_screen
 * DESCRIPTION
 *  This function is used to detect "current screen" is idle screen or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_java_is_in_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #ifdef __PLUTO_MMI_PACKAGE__   
    if(srv_shutdown_is_running() ==  MMI_TRUE)
    {
        return MMI_FALSE;
    }
    return mmi_idle_is_active();
 #elif __COSMOS_MMI_PACKAGE__
    return vapp_launcher_is_active();
 #endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_no_network_service
 * DESCRIPTION
 *  This function is to detect if network is available or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_java_is_no_network_service(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WLAN_FEATURES__
    if(!srv_nw_usab_is_any_network_available())
    {
        return MMI_TRUE;
    }
    else
#endif
    {
        return MMI_FALSE;
    }
}

MMI_BOOL mmi_java_is_sim_card_avaiable(void)
{
    return (MMI_BOOL)(
        (srv_sim_ctrl_is_available(MMI_SIM1)) 
#if (MMI_MAX_SIM_NUM >= 2)
        || (srv_sim_ctrl_is_available(MMI_SIM2))
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        ||(srv_sim_ctrl_is_available(MMI_SIM3))
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        ||(srv_sim_ctrl_is_available(MMI_SIM4))
#endif 
        ); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_no_sim
 * DESCRIPTION
 *  This function is to detect if there is a sim in phone or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_java_is_no_sim(void)
{
    return (mmi_java_is_sim_card_avaiable()== MMI_FALSE ? MMI_TRUE : MMI_FALSE);
}

#ifdef __PLUTO_MMI_PACKAGE__

/*****************************************************************************
 * FUNCTION
 *  mmi_java_widget_not_ready
 * DESCRIPTION
 *  The exit function of some popup window. We should stop timer here.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_display_is_busy_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(J2ME_NOT_READY_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_display_is_busy_internal
 * DESCRIPTION
 *  To show java is busy now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_java_display_is_busy_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(GRP_ID_JAVA_BUSY, SCR_J2ME_SCREEN_NOT_READY, mmi_java_display_is_busy_exit,mmi_java_display_is_busy_entry, MMI_FRM_FG_ONLY_SCRN))
    {
        StartTimer(J2ME_NOT_READY_TIMER, 2000, mmi_frm_scrn_close_active_id);

        guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_BUSY,SCR_J2ME_SCREEN_NOT_READY);
        ShowCategory66Screen(
            STR_JAVA_VM_BUSY,
            mmi_java_get_install_title_icon(),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_GLOBAL_PLEASE_WAIT),
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            guiBuffer);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}

static void mmi_java_display_is_busy_int(void)
{
    if (mmi_frm_group_is_present(GRP_ID_JAVA_BUSY))
    {
        return;
    }
	
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_JAVA_BUSY,
        mmi_java_busy_sg_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_java_display_is_busy_entry();
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_java_display_is_busy
 * DESCRIPTION
 *  To show java is busy now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_display_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __PLUTO_MMI_PACKAGE__
    mmi_java_display_is_busy_int();
    #elif defined __COSMOS_MMI_PACKAGE__
    vapp_java_display_is_busy();
    #endif
}

#ifdef __PLUTO_MMI_PACKAGE__

/*****************************************************************************
 * FUNCTION
 *  mmi_java_display_push_busy_ok_hdlr
 * DESCRIPTION
 *  Handler Function: revoked when press "OK" in "PUSH BUSY" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_display_push_busy_ok_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_display_push_busy_proc
 * DESCRIPTION
 * 
 * PARAMETERS
 *  evt     [IN]        The event pass in
 * RETURNS
 *  mmi_ret [OUT] the result of event handling
 *****************************************************************************/
mmi_ret mmi_java_display_push_busy_proc(mmi_event_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (evt->evt_id)
    {
#ifdef __MMI_NCENTER_SUPPORT__
        case EVT_ID_VAPP_NCENTER_DRAG:
            return MMI_RET_ERR;
#endif
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_display_push_busy
 * DESCRIPTION
 *  Display VM is busy for timealarm push
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_display_push_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        APP_JAVA,
        mmi_java_display_push_busy_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if(mmi_frm_scrn_enter(APP_JAVA, SCR_JAVA_PUSH_BUSY, NULL, mmi_java_display_push_busy ,MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(APP_JAVA, SCR_JAVA_PUSH_BUSY);
        ShowCategory74Screen(
        STR_JAVA_VM_BUSY,
        mmi_java_get_install_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        (U16) 0,
        (U16) 0,
        (PU8) GetString(STR_JAVA_PUSH_BUSY),
        mmi_ucs2strlen(GetString(STR_JAVA_PUSH_BUSY)),
        guiBuffer);

        SetLeftSoftkeyFunction(mmi_java_display_push_busy_ok_hdlr, KEY_EVENT_UP);
    }
}
#endif

/*****************************
 *  User permission dialog
 ************************************/
static mmi_java_get_permission_ind_struct mmi_java_get_permission_msg;
S32 *mmi_java_get_permission_index;
/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_get_permission
 * DESCRIPTION
 *  The entry function to get user's permission to use Network or some
 *  resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_java_permission_strid(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(index)
    {
        case JAVA_PERMISSION_SOCKET:             return STR_JAVA_PERMISSION_SOCKET;
        case JAVA_PERMISSION_HTTP:               return STR_JAVA_PERMISSION_HTTP;
        case JAVA_PERMISSION_HTTPS:              return STR_JAVA_PERMISSION_HTTPS;
        case JAVA_PERMISSION_SSL:                return STR_JAVA_PERMISSION_SSL;
        case JAVA_PERMISSION_DATAGRAM:           return STR_JAVA_PERMISSION_DATAGRAM;
        case JAVA_PERMISSION_SVR_SOCKET:         return STR_JAVA_PERMISSION_SVR_SOCKET;
        case JAVA_PERMISSION_SVR_DATAGRAM:       return STR_JAVA_PERMISSION_SVR_DATAGRAM;
        case JAVA_PERMISSION_RTSP:               return STR_JAVA_PERMISSION_RTSP;
        case JAVA_PERMISSION_COMM:               return STR_JAVA_PERMISSION_COMM;
        case JAVA_PERMISSION_PUSH:               return STR_JAVA_PERMISSION_PUSH;
        case JAVA_PERMISSION_SMS:                return STR_JAVA_PERMISSION_SMS;
        case JAVA_PERMISSION_CBS:                return STR_JAVA_PERMISSION_CBS;
        case JAVA_PERMISSION_MMS:                return STR_JAVA_PERMISSION_MMS;
        case JAVA_PERMISSION_RECORD_CTRL:        return STR_JAVA_PERMISSION_RECORD_CTRL;
        case JAVA_PERMISSION_SNAPSHOT:           return STR_JAVA_PERMISSION_SNAPSHOT;
        case JAVA_PERMISSION_FILE_READ:          return STR_JAVA_PERMISSION_FILE_READ;
        case JAVA_PERMISSION_FILE_WRITE:         return STR_JAVA_PERMISSION_FILE_WRITE;
        case JAVA_PERMISSION_CONTACT_LIST_READ:  return STR_JAVA_PERMISSION_CONTACT_LIST_READ;
        case JAVA_PERMISSION_CONTACT_LIST_WRITE: return STR_JAVA_PERMISSION_CONTACT_LIST_WRITE;
        case JAVA_PERMISSION_EVENT_LIST_READ:    return STR_JAVA_PERMISSION_EVENT_LIST_READ;
        case JAVA_PERMISSION_EVENT_LIST_WRITE:   return STR_JAVA_PERMISSION_EVENT_LIST_WRITE;
        case JAVA_PERMISSION_TODO_LIST_READ:     return STR_JAVA_PERMISSION_TODO_LIST_READ;
        case JAVA_PERMISSION_TODO_LIST_WRITE:    return STR_JAVA_PERMISSION_TODO_LIST_WRITE;
        case JAVA_PERMISSION_OBEX_CLIENT:        return STR_JAVA_PERMISSION_OBEX_CLIENT;
        case JAVA_PERMISSION_OBEX_SERVER:        return STR_JAVA_PERMISSION_OBEX_SERVER;
        case JAVA_PERMISSION_OBEX_CLIENT_TCP:    return STR_JAVA_PERMISSION_OBEX_CLIENT_TCP;
        case JAVA_PERMISSION_OBEX_SERVER_TCP:    return STR_JAVA_PERMISSION_OBEX_SERVER_TCP;
        case JAVA_PERMISSION_BT_CLIENT:          return STR_JAVA_PERMISSION_BT_CLIENT;
        case JAVA_PERMISSION_BT_SERVER:          return STR_JAVA_PERMISSION_BT_SERVER;
        case JAVA_PERMISSION_TELEPHONE:          return STR_JAVA_PERMISSION_TELEPHONE;
#ifdef SUPPORT_JSR_177
        case JAVA_PERMISSION_APDU_AID:          return STR_JAVA_PERMISSION_APDU_AID;
        case JAVA_PERMISSION_JCRMI:          	return STR_JAVA_PERMISSION_JCRMI;
        case JAVA_PERMISSION_APDU_SAT:          return STR_JAVA_PERMISSION_APDU_SAT;
#endif
#ifdef SUPPORT_JSR_257
        case JAVA_PERMISSION_CONTACTLESS_DISCOVERY:          return STR_JAVA_PERMISSION_CONTACTLESS_DISCOVERY;
        case JAVA_PERMISSION_CONTACTLESS_WRITE:          return STR_JAVA_PERMISSION_CONTACTLESS_WRITE;
        case JAVA_PERMISSION_NDEFTAG_OPEN:          return STR_JAVA_PERMISSION_OPEN_NDEFTAG;
        case JAVA_PERMISSION_PLAINTAG_OPEN:          return STR_JAVA_PERMISSION_OPEN_PLAINTAG;
        case JAVA_PERMISSION_ISOOFFFFT_OPEN:          return STR_JAVA_PERMISSION_OPEN_ISOOFFFFT;
        case JAVA_PERMISSION_VISUALTAG_OPEN:          return STR_JAVA_PERMISSION_OPEN_VISUALTAG;
#endif
        case JAVA_PERMISSION_EXCLUSIVE_PUSH:     return STR_JAVA_PERMISSION_EXCLUSIVE_PUSH;
        case JAVA_PERMISSION_EXCLUSIVE_NET:      return STR_JAVA_PERMISSION_EXCLUSIVE_NET;
        case JAVA_PERMISSION_LOCATION:           return STR_JAVA_PERMISSION_LOCATION;
        case JAVA_PERMISSION_LOCATION_ORIENTATION:              return STR_JAVA_PERMISSION_LOCATION_ORIENTATION;
        case JAVA_PERMISSION_LOCATION_PROXIMITYLISTENER:        return STR_JAVA_PERMISSION_LOCATION_PRXLISTENER;
        case JAVA_PERMISSION_LOCATION_LANDMARKSTORE_READ:       return STR_JAVA_PERMISSION_LANDMARKSTORE_READ;
        case JAVA_PERMISSION_LOCATION_LANDMARKSTORE_WRITE:      return STR_JAVA_PERMISSION_LANDMARKSTORE_WRITE;
        case JAVA_PERMISSION_LOCATION_LANDMARKSTORE_CATEGORY:   return STR_JAVA_PERMISSION_LANDMARKSTORE_CATEGORY;
        case JAVA_PERMISSION_LOCATION_LANDMARKSTORE_MNGR:       return STR_JAVA_PERMISSION_LANDMARKSTORE_MANAGEMENT;
		case JAVA_PERMISSION_DISABLE_BACKGROUND:                return STR_JAVA_PERMISSION_DISABLE_BACKGROUND;
        case JAVA_PERMISSION_UNKNOWN:            return STR_JAVA_PERMISSION_UNKNOWN;
        default:
            return STR_JAVA_PERMISSION_UNKNOWN;
    }
}
#ifdef __PLUTO_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_permission_lsk_hdlr
 * DESCRIPTION
 *  Handler Function: revoked when press "YES" in "PERMISSION" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_get_permission_lsk_hdlr(void)
{
    mmi_java_get_permission_res(MMI_TRUE);
    g_jam_user_update_setting_exclusive = KAL_FALSE;
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_permission_rsk_hdlr
 * DESCRIPTION
 *  Handler Function: revoked when press "NO" in "PERMISSION" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_get_permission_rsk_hdlr(void)
{
    mmi_java_get_permission_res(MMI_FALSE);
    g_jam_user_update_setting_exclusive = KAL_FALSE;
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_frm_scrn_close_active_id();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mids_get_permisson_del_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  in_param    [IN]    no use here
 * RETURNS
 *  return if we want to stop delete the screen
 *****************************************************************************/
mmi_ret mmi_java_entry_mids_get_permission_del_cb(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            if(mmi_java_get_permission_index != NULL)
            {
                (*mmi_java_get_permission_index) = MMI_FALSE;
            }
            g_jam_user_update_setting_exclusive = KAL_FALSE;
            return MMI_RET_OK;
        case EVT_ID_SCRN_GOBACK:
            if((mmi_java_get_permission_msg.title_id == JAVA_PERMISSION_EXCLUSIVE_NET ||mmi_java_get_permission_msg.title_id ==JAVA_PERMISSION_EXCLUSIVE_PUSH)&& g_jam_user_update_setting_exclusive)
            {
                return MMI_RET_ERR;
            }
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_get_permission_proc
 * DESCRIPTION
 * 
 * PARAMETERS
 *  evt     [IN]        The event pass in
 * RETURNS
 *  mmi_ret [OUT] the result of event handling
 *****************************************************************************/
mmi_ret mmi_java_entry_get_permission_proc(mmi_event_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (evt->evt_id)
    {
#ifdef __MMI_NCENTER_SUPPORT__
        case EVT_ID_VAPP_NCENTER_DRAG:
            return MMI_RET_ERR;
#endif
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_get_permission_ext
 * DESCRIPTION
 *  The entry function to get user's permission to use Network or some
 *  resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_get_permission_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 title_id = 0;
    kal_char *buffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(GRP_ID_JAVA_CONFIRM, SCR_JAVA_GET_PERMISSION, NULL, mmi_java_entry_get_permission,MMI_FRM_FULL_SCRN))
    {
        return;
    }
    mmi_java_get_permission_info(&buffer,&title_id);
    mmi_frm_scrn_set_leave_proc(GRP_ID_JAVA_CONFIRM,SCR_JAVA_GET_PERMISSION,mmi_java_entry_mids_get_permission_del_cb);
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_CONFIRM,  SCR_JAVA_GET_PERMISSION);
    ShowCategory74Screen(
        title_id,
        mmi_java_get_install_title_icon(),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) buffer,
        mmi_ucs2strlen(buffer),
        guiBuffer);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_java_get_permission_lsk_hdlr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_java_get_permission_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_get_permission_rsk_hdlr, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_get_permission
 * DESCRIPTION
 *  Handler Function: revoked when receive the message "MSG_ID_MMI_JAVA_GET_PERMISSION_IND"
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_java_entry_get_permission(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_group_is_present(GRP_ID_JAVA_CONFIRM))
    {
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_JAVA_CONFIRM,
            mmi_java_entry_get_permission_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    mmi_java_entry_get_permission_ext();
}

#endif

void mmi_java_get_permission_info(CHAR** confirmStr,U16 *title)
{
    U16 title_id = 0;
    U16 strid = mmi_java_permission_strid((U8)mmi_java_get_permission_msg.title_id);
    CHAR *buffer;
    mmi_java_get_permission_index = mmi_java_get_permission_msg.chosen_id;
    buffer = (CHAR*)subMenuData;
    kal_mem_set(buffer, 0, MAX_SUB_MENUS * MAX_SUB_MENU_SIZE);
    mmi_ucs2cpy(buffer, (const CHAR*)GetString(strid));
    if(mmi_java_get_permission_msg.appendix)
    {
        mmi_java_ucs2cat_secure(buffer, (const CHAR*)mmi_java_get_permission_msg.appendix,
            MAX_SUB_MENUS * MAX_SUB_MENU_SIZE);
    }
    if(mmi_java_get_permission_msg.trusted_display == JAM_DISPLAY_NONE)
    {
        title_id = STR_JAVA_PERMISSION_TITLE;
    }
    else if(mmi_java_get_permission_msg.trusted_display == JAM_DISPLAY_TRUSTED)
    {
        title_id = STR_JAVA_PERMISSION_TRUSTED_TITLE;
    }
    else if(mmi_java_get_permission_msg.trusted_display == JAM_DISPLAY_UNTRUSTED)
    {
        title_id = STR_JAVA_PERMISSION_UNTRUSTED_TITLE;
    }
    else
    {
        ASSERT(0);
    }
    if(title)
    {
        *title = title_id;
    }
    if(confirmStr)
    {
        *confirmStr = buffer;
    }
}

kal_bool mmi_java_is_permission_force_fgmmi()
{
    U16 strid = mmi_java_permission_strid((U8)mmi_java_get_permission_msg.title_id);

	if(strid == STR_JAVA_PERMISSION_DISABLE_BACKGROUND)
	{
	    return KAL_TRUE;
	}
	else
	{
	    return KAL_FALSE;
	}


}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_permission_lsk_hdlr
 * DESCRIPTION
 *  Handler Function: revoked when press "YES" in "PERMISSION" screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_get_permission_res(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_permission_cnf_struct* msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (mmi_java_get_permission_cnf_struct*) OslConstructDataPtr(sizeof(mmi_java_get_permission_cnf_struct));
    msg->user_confirm = MMI_TRUE;
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_GET_PERMISSION_CNF, msg);
    
    if(mmi_java_get_permission_index != NULL)
    {
        (*mmi_java_get_permission_index) = result;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_get_permission_ind
 * DESCRIPTION
 *  Handler Function: revoked when receive the message "MSG_ID_MMI_JAVA_GET_PERMISSION_IND"
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_get_permission_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&mmi_java_get_permission_msg, MsgStruct, sizeof(mmi_java_get_permission_ind_struct));

    /* mmi_java_get_permission_msg.trusted_display == JAM_DISPLAY_NONE means it's not the permission dialog raised
         from VM, it's a confirm dialog. */
    if (jam_is_own_screen())
    {
        g_mmi_java_select_permission_vm_id = jam_mvm_get_current_vm_id();
        jam_mvm_set_vm_need_call_pauseapp(g_mmi_java_select_permission_vm_id,KAL_FALSE);
        #ifdef __PLUTO_MMI_PACKAGE__
        mmi_java_entry_get_permission();
        #elif defined (__COSMOS_MMI_PACKAGE__)   
        vapp_java_get_permission_entry();
        #endif
    }
    else if(mmi_java_get_permission_msg.trusted_display == JAM_DISPLAY_NONE)
    {
        #ifdef __PLUTO_MMI_PACKAGE__
        mmi_java_entry_get_permission();
        #elif defined (__COSMOS_MMI_PACKAGE__)   
        vapp_java_get_permission_entry();
        #endif
    }
    else
    {
        mmi_java_get_permission_cnf_struct* msg;

        msg = (mmi_java_get_permission_cnf_struct*) OslConstructDataPtr(sizeof(mmi_java_get_permission_cnf_struct));
        msg->user_confirm = MMI_FALSE;
        mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,
            MSG_ID_MMI_JAVA_GET_PERMISSION_CNF, msg);
        
        if(mmi_java_get_permission_msg.chosen_id != NULL)
        {
            (*mmi_java_get_permission_msg.chosen_id) = MMI_FALSE;
        }
    }
}



void mmi_java_send_message_from_active_mod( kal_int32 dst_id, kal_int32 sap_id, kal_int32 msg_id, void *local_para_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type src_mod_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_mod_id = stack_get_active_module_id();
    msg_send5(src_mod_id, (module_type)dst_id, (sap_type)sap_id, (msg_type) msg_id, 
                   (local_para_struct *)local_para_ptr);
}
/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_send_get_imsi_res(U8* imsi, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_java_get_imsi_res_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_get_imsi_res_struct*) OslConstructDataPtr(sizeof(mmi_java_get_imsi_res_struct));
    msg->error = error;

    memset(msg->imsi, 0, sizeof(msg->imsi));

    if (imsi)
    {
        for( i = 0 ;i < 17; i++)
        {
            msg->imsi[i] = imsi[i];
        }
    }

    mmi_java_send_message_from_active_mod(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_GET_IMSI_RES, msg);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_get_imsi_rsp
 * DESCRIPTION
 *  get the sim card IMSI
 * PARAMETERS
 *  MsgStruct   [In]    Message
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_java_recv_l4_get_imsi_rsp(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_get_imsi_rsp_struct* msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_smu_get_imsi_rsp_struct*)MsgStruct;

    if (msg->result == ST_SUCCESS)
    {
        mmi_java_send_get_imsi_res(msg->imsi, J2ME_NO_ERROR);
    }
    else
    {
        mmi_java_send_get_imsi_res(NULL, J2ME_UNDEFINED_ERROR);
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_get_imsi_req
 * DESCRIPTION
 *  Send the message PRT_GET_IMSI_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_l4_get_imsi_req(S32 dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(PRT_GET_IMSI_RSP, mmi_java_recv_l4_get_imsi_rsp, MMI_TRUE);
    mmi_java_send_message_from_active_mod(dst_id, MMI_L4C_SAP, PRT_GET_IMSI_REQ, NULL);
}

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_recv_get_imsi_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dst_mod = MOD_L4C;
    mmi_java_get_imsi_ind_struct *msg = (mmi_java_get_imsi_ind_struct*)MsgStruct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(msg->sim_id)
    {
        case 0:
            dst_mod = MOD_L4C;
            break;
#ifdef __GEMINI__
        case 1:
            dst_mod = MOD_L4C_2;
            break;
#if (MMI_MAX_SIM_NUM >= 3)
        case 2:
            dst_mod = MOD_L4C_3;
            break;
#if (MMI_MAX_SIM_NUM >= 4)
         case 3:
            dst_mod = MOD_L4C_4;
            break;
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 3 */
#endif /* __GEMINI__ */
        default:
            break;
    }
    mmi_java_send_l4_get_imsi_req(dst_mod);
}
/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_send_get_lai_res(mmi_java_get_lai_res_struct* lai)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_java_get_lai_res_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(lai == NULL) return;
}

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_recv_l4_get_lai_rsp(void *MsgStruct)
{
#ifdef __MMI_EM_NW_NETWORK_INFO__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_status_ind_struct* msg = NULL;
    mmi_java_get_lai_res_struct *lai_res = NULL; 
    static rr_em_lai_info_struct last_data = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_em_status_ind_struct*)MsgStruct;
    if(msg->em_info == RR_EM_LAI_INFO)
    {
        rr_em_lai_info_struct *data_ptr;
        kal_uint16 mm_pdu_len;

        /* Get the pdu_ptr where MM peer msg will be stored for transmission */
        data_ptr = (rr_em_lai_info_struct*) get_peer_buff_pdu(msg->info, &mm_pdu_len);
                
        if(data_ptr!= NULL)
        {
            if(last_data.cell_id != data_ptr->cell_id
               || last_data.mcc != data_ptr->mcc
               || last_data.mnc != data_ptr->mnc
               || last_data.lac != data_ptr->lac )
            {
                memcpy(&last_data,data_ptr,sizeof(rr_em_lai_info_struct));
            lai_res = (mmi_java_get_lai_res_struct*) OslConstructDataPtr(sizeof(mmi_java_get_lai_res_struct));
            lai_res->error = J2ME_NO_ERROR;
            sprintf(lai_res->cell_id,"%04X\0", data_ptr->cell_id);
            sprintf(lai_res->lac,"%02X%02X\0",data_ptr->lac[0],data_ptr->lac[1]);        
                if(data_ptr->mnc[2] == 0x0F)
            {
                sprintf(lai_res->mnc,"%d%d\0",data_ptr->mnc[0],data_ptr->mnc[1]);
            }
            else
            {
                sprintf(lai_res->mnc,"%d%d%d\0",data_ptr->mnc[0],data_ptr->mnc[1],data_ptr->mnc[2]);
            }
            sprintf(lai_res->mcc,"%d%d%d\0",data_ptr->mcc[0],data_ptr->mcc[1],data_ptr->mcc[2]);

            mmi_java_send_message_from_active_mod(MOD_JASYN, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_GET_LAI_RES, lai_res);
         }
        }

    }
    free_peer_buff(msg->info);
    
#endif /*__MMI_EM_NW_NETWORK_INFO__*/

}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_l4_get_lai_req
 * DESCRIPTION
 *  Send the message PRT_GET_LAI_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_l4_get_lai_req(void)
{
 #ifdef __MMI_EM_NW_NETWORK_INFO__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    mmi_em_update_req_struct *em_start_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_MMI_EM_UPDATE_RSP);
    SetProtocolEventHandler((PsIntFuncPtr)mmi_java_recv_l4_get_lai_rsp,MSG_ID_MMI_EM_STATUS_IND);
    em_start_req = OslConstructDataPtr(sizeof(mmi_em_update_req_struct));
    for (i=0;i<EM_INFO_REQ_NUM;i++)
    {
        em_start_req->info_request[i] = EM_NC;
    }
    em_start_req->info_request[RR_EM_LAI_INFO] = EM_ON;
    mmi_java_send_message_from_active_mod(MOD_L4C, MMI_L4C_SAP, MSG_ID_MMI_EM_UPDATE_REQ, em_start_req);  
#endif /*__MMI_EM_NW_NETWORK_INFO__*/
}
/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_update_mids_runtime_info_req(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_nw_update_setting_req_struct* msg = NULL;
    
    msg = (mmi_java_nw_update_setting_req_struct*) OslConstructDataPtr(sizeof(mmi_java_nw_update_setting_req_struct));
    msg->vm_id = vm_id;
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_NW_UPDATE_SETTING_REQ, msg);

    kal_sleep_task(3);
    /*update lai req*/
    mmi_java_send_l4_get_lai_req();
}
void mmi_java_update_mids_runtime_setting(kal_int32 vm_id)
{
    jam_mvm_set_vm_vk_on(vm_id,srv_java_appfactory_vk_is_on(jam_mvm_get_vm_storage_name(vm_id)));
    mmi_java_load_setting();
    mmi_java_update_mids_runtime_info_req(vm_id);
}

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/

MMI_BOOL mmi_java_is_drm_file(PU16 filename)
{

#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (filename == NULL ) return MMI_FALSE;

    if (DRM_get_object_method(0, (kal_wchar*)filename) != DRM_METHOD_NONE)
    {
        return MMI_TRUE;
    }
#endif
    return MMI_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *   mmi_java_driver_is_mounted
 * DESCRIPTION
 * check whether memory card is mounted.
 * PARAMETERS
 * U16 drv
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/

MMI_BOOL mmi_java_driver_is_mounted(U16 drv)
{
    if(FS_NO_ERROR == FS_GetDevStatus(drv ,FS_MOUNT_STATE_ENUM))
        return MMI_TRUE;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
U16 mmi_java_get_title_icon(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_MY_FAVORITE_JAVABOX__
    #ifdef __JAM_CHECK_JAD_LEVEL2__
	#ifndef __MRE_AM__
        return GetRootTitleIcon(MAIN_MENU_FUNANDGAMES_MENUID);
	#else
	 return GetRootTitleIcon(MAIN_MENU_EXTRA_MENUID);
	#endif
    #endif
    return mmi_my_favorite_get_java_title_icon();
#else
    #ifndef __MRE_AM__
    return GetRootTitleIcon(MAIN_MENU_FUNANDGAMES_MENUID);
	#else
	 return GetRootTitleIcon(MAIN_MENU_EXTRA_MENUID);
	#endif
#endif
#else
    return IMG_NONE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
U16 mmi_java_get_install_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PLUTO_MMI_PACKAGE__
#if defined(__MMI_MY_FAVORITE_JAVABOX__) && defined(__OP01__)
    return IMG_ID_MY_FAVORITE_TITLE_JAVABOX;
#else
    #ifndef __MRE_AM__
    return GetRootTitleIcon(MAIN_MENU_FUNANDGAMES_MENUID);
	#else
	 return GetRootTitleIcon(MAIN_MENU_EXTRA_MENUID);
	#endif
#endif
#else
    return IMG_NONE;
#endif
}
#endif /* __J2ME__ */ /* ifdef J2ME */

