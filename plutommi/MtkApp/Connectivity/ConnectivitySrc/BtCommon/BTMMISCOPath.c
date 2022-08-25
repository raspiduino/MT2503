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
 * BTMMISCOPath.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Bluetooth SCO Link path control
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Included files
*****************************************************************************/
#include "mmi_features.h"

#include "mdi_datatype.h"
#include "BTMMISCOPathGProts.h"
#include "BthSCOPathSrvGProt.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
/***************************************************************************** 
* Globol Variable
*****************************************************************************/


#ifdef __MMI_BT_AUDIO_SUPPORT__

MMI_BOOL mmi_bt_sco_is_connected(U8 connect_type)
{
    MMI_BOOL bt_connect = MMI_FALSE;

    switch (connect_type)
    {
        case MMI_BT_SCO_HFP_ACL:
            ASSERT(0);
            break;
        case MMI_BT_SCO_HFP_SCO:
            bt_connect = srv_btsco_is_sco_open();
            break;
        default:
            break;
    }
    return bt_connect;
}

MMI_BOOL mmi_bt_sco_is_sco_connect_allowed(void)
{
    ASSERT(0);
	return MMI_FALSE;
}

MMI_BOOL mmi_bt_sco_show_switch_path_popup(void)
{
    ASSERT(0);    
	return MMI_FALSE;
}

MMI_BOOL mmi_bt_sco_connect_sco(void (*callback) (void))
{
    return srv_btsco_connect_sco_req(callback);
}

MMI_BOOL mmi_bt_sco_disconnect_sco(void)
{
    return srv_btsco_disconnect_sco_req();
}

void mmi_bt_sco_deactivate_cnf_hdlr(void)
{
    srv_btsco_deactivate_cnf_hdlr();
}

void mmi_bt_sco_reset(void)
{
    ASSERT(0);
}

MMI_BOOL mmi_bt_sco_open_stream_req(void)
{
    return srv_btsco_open_stream_req();
}

void mmi_bt_sco_close_stream_req(void)
{
    srv_btsco_close_stream_req(); 
}

void mmi_bt_sco_call_start_callback(void)
{
    srv_btsco_call_start_callback();
}

void mmi_bt_sco_call_end_callback(void)
{
    srv_btsco_call_end_callback();
}

void mmi_bt_sco_hfp_disconnect_callback(U8 callback_type)
{
    ASSERT(0);
}


void mmi_bt_sco_switch_profile_path(MMI_BOOL turn_on_sco)
{
    ASSERT(0);
}


#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
void mmi_bt_sco_disable_sco_timeout(void)
{
    srv_btsco_set_always_on(MMI_TRUE);
}

void mmi_bt_sco_enable_sco_timeout(void)
{
    srv_btsco_set_always_on(MMI_FALSE);
}

void mmi_bt_sco_disable_sco_connection(U8 app_id)
{
    srv_btsco_disable_sco_connection(app_id);
}

void mmi_bt_sco_enable_sco_connection(U8 app_id)
{
    srv_btsco_enable_sco_connection(app_id);
}

mmi_bt_sco_inquiry_error_enum mmi_bt_sco_inquery_start_callback(void (*callback) (void))
{
    ASSERT(0);
	return MMI_BT_SCO_INQ_SCO_DISCONNECTED;
}

void mmi_bt_sco_inquery_stop_callback(void)
{
    ASSERT(0);
}

void mmi_bt_sco_connect_audio_via_sco(void)
{
    srv_btsco_connect_audio_via_sco();
}

#endif /* #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__) */

#endif /* __MMI_BT_AUDIO_SUPPORT__ */ 


