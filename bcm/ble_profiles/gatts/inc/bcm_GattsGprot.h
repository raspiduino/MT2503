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
 * bcm_pbapGport.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for dispatch primitive from goep obex to different applications.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/	 
#ifndef BCM_GATTSGPROT_H
#define BCM_GATTSGPROT_H

#include "bcmadp.h"
#include "bcm_struct.h"
#include "kal_general_types.h"
#include "bluetooth_gatts_struct.h"

extern void bcm_gatts_listen_req_handler(ilm_struct *msg);
extern void bcm_gatts_register_req_handler(ilm_struct *msg);
extern void bcm_gatts_deregister_req_handler(ilm_struct *msg);
extern void bcm_gatts_connect_req_handler(ilm_struct *msg);
extern void bcm_gatts_disconnect_req_handler(ilm_struct *msg);

extern void bcm_gatts_add_service_req_handler(ilm_struct *msg);
extern void bcm_gatts_delete_service_req_handler(ilm_struct *msg);
extern void bcm_gatts_add_include_service_req_handler(ilm_struct *msg);
extern void bcm_gatts_add_char_req_handler(ilm_struct *msg);
extern void bcm_gatts_add_descriptor_req_handler(ilm_struct *msg);

extern void bcm_gatts_start_service_req_handler(ilm_struct *msg);
extern void bcm_gatts_stop_service_req_handler(ilm_struct *msg);
extern void bcm_gatts_send_indication_req_handler(ilm_struct *msg);
extern void bcm_gatts_send_response_req_handler(ilm_struct *msg);
extern void bcm_gatt_read_local_addr_req_handler(ilm_struct* msg);

#ifdef MMI_SRV_BT_FMPT_PROFILE 	
extern void bcm_fmps_register_req_handler(ilm_struct *msg);
extern void bcm_fmps_deregister_req_handler(ilm_struct *msg);
#endif
#ifdef MMI_SRV_BT_PRXR_PROFILE 	
extern void bcm_pxps_register_req_handler(ilm_struct *msg);
extern void bcm_pxps_deregister_req_handler(ilm_struct *msg);
#endif
extern void bcm_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

#if defined (__BLE_GATT__)
extern void track_bcm_gatt_switch_req_handler(ilm_struct* msg);
#endif /* __BLE_GATT__ */

#endif

