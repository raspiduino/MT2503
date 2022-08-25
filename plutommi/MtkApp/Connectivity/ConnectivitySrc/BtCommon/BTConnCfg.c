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
 *  BTConnCfg.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  The table of BT Connection.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_BT_SUPPORT__ 
#ifdef __MMI_BT_DIALER_SUPPORT__

#include "MMIDataType.h"

#include "mmi_rp_app_bluetooth_def.h"


/***************************/
/* for MTK bluetooh       */
/***************************/
#ifdef __MMI_HFP_SUPPORT__

#include "BTMMIHfpGprots.h"
#include "BthfSrvGprot.h"
#endif/*__MMI_HFP_SUPPORT__*/

#ifdef __MMI_SPP_SUPPORT__
#include "BTMMISpp.h"
#include "BTMMISppGprots.h"
#endif/*__MMI_SPP_SUPPORT__*/


#ifdef __MMI_BT_MAP_CLIENT__
#include "MapSrvGprot.h"
#include "mapcsrv.h"
#endif/*__MMI_BT_MAP_CLIENT__*/

#if defined(__MMI_PBAP_SUPPORT__) || defined(__BT_PBAP_CLIENT__)
#include "BTMMIPbapGprots.h"
#endif/*__MMI_PBAP_SUPPORT__*/

#ifdef __MMI_BT_PBAP_CLIENT__
#include "PbapSrvGprot.h"
#include "pbapcsrv.h"
#endif/*__MMI_BT_PBAP_CLIENT__*/

#ifdef __MMI_HF_SUPPORT__
#include "BTDialerSrvGprot.h"
#endif/*__MMI_HF_SUPPORT__*/
#include "mmi_rp_app_bt_dialer_def.h"

#if defined(__MMI_A2DP_SUPPORT__)
#include "A2dpSrvGprot.h"
#endif/*__MMI_A2DP_SUPPORT__*/

#ifdef __MMI_AVRCP_SUPPORT__
#include "AvrcpSrvGprot.h"
#endif/*__MMI_AVRCP_SUPPORT__*/
#ifdef __MMI_BT_APK_SMART_INSTALL_SUPPORT__
#include "BTMMISendGprots.h"
#endif
/***************************/
/* bluetooh common files   */
/***************************/

#include "BTMMIScrGprots.h"
#include "BTMMIScr.h"
#include "BtcmSrvGprot.h"
#ifdef __MMI_BT_MAP_CLIENT__
static void mmi_bt_dialer_mapc_conn_adp(srv_bt_cm_bt_addr *addr, srv_bt_cm_map_callback cb);
#endif/*__MMI_BT_MAP_CLIENT__*/
extern mmi_bt_dialer_conn_callback_item g_mmi_btdialer_callback_tbl[] = 
{
#ifdef __MMI_BTBOX_NOLCD__
    #ifdef __MMI_HF_SUPPORT__
	{
		0,
        SRV_BT_CM_HF_CONNECTION,
		srv_bt_dialer_cm_connect_req,
		srv_bt_dialer_cm_disconnect_req
	},
    #endif/*__MMI_HF_SUPPORT__*/

    #ifdef __MMI_BT_SPEAKER_SUPPORT__
    #if defined(__MMI_A2DP_SUPPORT__)
	{
		1,
        SRV_BT_CM_A2DP_CONNECTION,
		srv_bt_a2dp_sink_cm_connect_req,
		srv_bt_a2dp_cm_disconnect_req
	},
    #endif /* __MMI_A2DP_SUPPORT__ */
    #endif /* __MMI_BT_SPEAKER_SUPPORT__ */

    #ifdef __MMI_AVRCP_SUPPORT__
	{
		2,
        SRV_BT_CM_AVRCP_CT_CONNECTION,
		srv_avrcp_connect_from_cm,
		srv_avrcp_disconnect_from_cm
	},
    #endif /* __MMI_AVRCP_SUPPORT__ */
#else  //__MMI_BTBOX_NOLCD__
#ifdef __MMI_HF_SUPPORT__
	{
		0,
        SRV_BT_CM_HF_CONNECTION,
		srv_bt_dialer_cm_connect_req,
		srv_bt_dialer_cm_disconnect_req
	},
#endif/*__MMI_HF_SUPPORT__*/

#ifdef __MMI_BT_MAP_CLIENT__
    {
        1,
        SRV_BT_CM_MAPC_CONNECTION, 
		mmi_bt_dialer_mapc_conn_adp,
		srv_mapc_disconnect_from_cm
	},
#endif/*__MMI_BT_MAP_CLIENT__*/

#ifdef __MMI_BT_PBAP_CLIENT__
    {
    	2,
        SRV_BT_CM_PBAPC_CONNECTION,
        srv_pbapc_connect,
        srv_pbapc_disconnect
	},
#endif/*__MMI_BT_PBAP_CLIENT__*/

#ifdef __MMI_BT_SPEAKER_SUPPORT__
#if defined(__MMI_A2DP_SUPPORT__)

	{
		3,
        SRV_BT_CM_A2DP_CONNECTION,
		srv_bt_a2dp_sink_cm_connect_req,
		srv_bt_a2dp_cm_disconnect_req
	},
#endif /* __MMI_A2DP_SUPPORT__ */
#endif /* __MMI_BT_SPEAKER_SUPPORT__ */

#ifdef __MMI_AVRCP_SUPPORT__

	{
		4,
        SRV_BT_CM_AVRCP_CT_CONNECTION,
		srv_avrcp_connect_from_cm,
		srv_avrcp_disconnect_from_cm
	},
#endif /* __MMI_AVRCP_SUPPORT__ */
#ifdef __MMI_BT_APK_SMART_INSTALL_SUPPORT__
	{
		5,
		SRV_BT_CM_OPPC_CONNECTION,
		mmi_bt_oppc_conn_for_smart_install,
		mmi_bt_oppc_disconn_for_smart_install		,
	},
#endif
#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__

	{
		5,
    SRV_BT_CM_SPP_CONNECTION,
		NULL,
		mmi_bt_spps_send_disconnect_req_from_cm
	},
#endif /* __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__ */
#endif  //__MMI_BTBOX_NOLCD__
    {0xFF, 0, NULL, NULL}
};

U32 mmi_bt_dialer_tbl_count(void)
{
    return sizeof(g_mmi_btdialer_callback_tbl) / sizeof (mmi_bt_dialer_conn_callback_item);

}

#ifdef __MMI_BT_MAP_CLIENT__
static void mmi_bt_dialer_mapc_conn_adp(srv_bt_cm_bt_addr *addr, srv_bt_cm_map_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_MAPC_CONN_FUNC);
	srv_bt_mapc_connect_req_from_cm((*addr), cb, MMI_TRUE);
}
#endif/*__MMI_BT_MAP_CLIENT__*/
/****************************************************************************
 * Configurations
 ****************************************************************************/
 #endif/*__MMI_BT_DIALER_SUPPORT__*/
 #endif/*__MMI_BT_SUPPORT__ */

