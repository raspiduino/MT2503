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
 * BTMMISpp.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for SPP application.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#ifndef BT_MMI_SIMAP_H
#define BT_MMI_SIMAP_H

#include "BtcmSrvGprot.h"
#include "MMIDataType.h"

/***************************************************************************** 
* Macro
*****************************************************************************/

/***************************************************************************** 
* Definations
*****************************************************************************/
#define MMI_BTH_SIMAP_MAX_CONNECTION        1
#define MMI_BTH_SIMAP_MAX_DEV_NAME_LEN 80



/***************************************************************************** 
* typedef 
*****************************************************************************/
typedef enum
{
	MMI_BTH_SIMAP_STAT_IDLE,
	MMI_BTH_SIMAP_STAT_ACTIVATING,
	MMI_BTH_SIMAP_STAT_ACTIVATE,
	MMI_BTH_SIMAP_STAT_AUTHORIZING,
	MMI_BTH_SIMAP_STAT_AUTHORIZED,
	MMI_BTH_SIMAP_STAT_CONNECT,	
	MMI_BTH_SIMAP_STAT_DISCONNECT,
	MMI_BTH_SIMAP_STAT_DEACTIVATING
} mmi_bth_simap_state_enum;

/***************************************************************************** 
* Structure
*****************************************************************************/

typedef struct
{
	mmi_bth_simap_state_enum state;
	U16 connect_id;
    srv_bt_cm_bt_addr bt_addr;
    U32 cmgr_id;
	U8 used_sim_id;
    MMI_BOOL link_flag;
} mmi_simap_cntx_struct;


/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Functions
*****************************************************************************/
void mmi_bth_simap_event_handler(void);
void mmi_bth_simap_activate_cnf(void *msg);
void mmi_bth_simap_deactivate_cnf(void *msg);
void mmi_bth_simap_connect_ind(void *msg);
void mmi_bth_simap_disconnect_cnf(void *msg);
void mmi_bth_simap_disconnect_ind(void *msg);
void mmi_bt_simap_disconnect(U32 cmgr_id);
void mmi_bth_simap_authorize_ind(void *msg);
void mmi_bth_simap_send_status_ind_with_unavailable_req(void);
U8 mmi_bt_disallow_acl_link_cnf_hdler(void *msg);
U8 mmi_bt_allow_acl_link_cnf_hdler(void *msg);


#endif//end of BT_MMI_SIMAP_H


