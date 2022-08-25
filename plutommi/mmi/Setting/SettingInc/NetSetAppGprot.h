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
 * NetSetAppGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines internal interface of network setup application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __NETSET_APP_GPROT_H__
#define __NETSET_APP_GPROT_H__

#include "MMI_features.h"

#include "MMIDataType.h"

#include "NetSetSrvGprot.h"

/***************************************************************************** 
* Local define
*****************************************************************************/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#define MMI_NETSET_SIM_NAME_MAX_LEN 11 /* Sim name string length for total */
#endif

/***************************************************************************** 
* Typedef for Network Setup
*****************************************************************************/
extern U8 mmi_netset_get_active_preferred_mode(void);

/***************************************************************************** 
* External Function
*****************************************************************************/
#ifndef __MMI_NETSET_SLIM__
extern pBOOL mmi_netset_is_t_mobile_us_sim(void);
#endif

#ifdef __MMI_WLAN_FEATURES__
extern void mmi_netset_refresh_wlan_status(U8 wlan_status);
extern mmi_ret mmi_netset_wlan_init_hdlr(mmi_event_struct *evt);
#endif /* __MMI_WLAN_FEATURES__ */


extern S16 mmi_netset_retrieve_opname_from_plmn(U8 *plmn, U8 *opname);
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__)
/* under construction !*/
#endif
#if defined(__MMI_EM_NW_GPRS_CONN__) && defined(__MMI_GPRS_FEATURES__)	
extern void mmi_nw_entry_gprs_conn_mode(MMI_ID menu_id);
#endif
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sim_name_setting_launch
 * DESCRIPTION
 *    Entry network setting manu.
 * PARAMETERS
 *  	Void
 * RETURNS
 *  static void
 *****************************************************************************/
extern void mmi_netset_sim_name_setting_launch(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_sim_name
 * DESCRIPTION
 *    EX user define sim 1 as CMCC. just return CMCC.
 * PARAMETERS
 *  	sim id
 * RETURNS
 *   sim name string
 *****************************************************************************/
extern WCHAR* mmi_netset_get_sim_name(mmi_sim_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_sim_name_user_define
 * DESCRIPTION
 *    Get sim name for app Example: 
 *	SIM name is CMCC. return:  (CMCC)
 * PARAMETERS
 *  	Void
 * RETURNS
 *  0 get sim name ok. -1 buffer is too short.
 *****************************************************************************/

extern S32 mmi_netset_get_sim_name_with_brace(mmi_sim_enum sim_id, WCHAR* buffer, U32 buff_len);

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_sim_name_with_simx_and_brace
 * DESCRIPTION
 *    Get sim name for app Example: 
 *	SIM 1 name is CMCC. return: "SIM 1 (CMCC)"
 * PARAMETERS
 *  	Void
 * RETURNS
 *  static -1 buffer len is two short. 0: result ok.
 *****************************************************************************/

extern S32 mmi_netset_get_sim_name_with_simx_and_brace(mmi_sim_enum sim_id, WCHAR* buffer, U32 buff_len);



#endif

#endif /* __NETSET_APP_GPROT_H__ */

