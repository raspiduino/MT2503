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
 *   bcm_init.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for bcm task init function
 *   entry point.
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
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __BCM_SUPPORT__
#include "kal_trace.h"
#include "event_shed.h"
#include "bcmadp.h"
#include "Bcm_btcmSrvProt.h"
#include "bcm_trc.h"
#include "comm_post_event.h"
#include "bt_maui_utility.h"
#include "bcm_btcmApp.h"
bcm_context_struct bcm_context;
bcm_context_struct *BCM_PTR = &bcm_context;

kal_bool bcm_init()
{
    BCM_PTR->event_scheduler_ptr = evshed_create("BCM base timer", MOD_BCM, 0, 0 );
	comm_post_event_create_adm();
//    bt_set_destination_module_id(MOD_BCM);

    BCM_PTR->inquiry_number = SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST;
    BCM_PTR->inquiry_length = BCM_APP_INQUIRY_TIMEOUT_DURATION;
    BCM_PTR->cod = 0;//BCM_APP_AUDIO_MAJOR_SERVICE_MASK |BCM_APP_OBJECT_TRANSFER_MAJOR_SERVICE_MASK|BCM_APP_TELEPHONY_MAJOR_SERVICE_MASK;
    BCM_PTR->urc_interval = 0xFF;

    BCM_PTR->ext_cm_state = BCM_EXT_CM_STATE_UNKNOWN;
    BCM_PTR->cm_pair_state = BCM_CM_PAIR_STATE_IDLE;
    BCM_PTR->full_map = 0xFFFFFFFFFFFFFFFF;

    //better in the last line of bcm_init();
    bcm_app_init();
#ifdef __BT_GATTS_PROFILE__ 
    srv_gatts_init();
#endif
#ifdef __BT_GATTC_PROFILE__ 
	srv_gattc_init();
#endif
    return KAL_TRUE;
}
#endif
