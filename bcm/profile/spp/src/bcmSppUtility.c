/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE: BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES:
*  EXPRESS OR IMPLIED: INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY: FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY: INCORPORATED IN: OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE: AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE:
*  AT MEDIATEK'S OPTION: TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE:
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA: USA: EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES: CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO: CA: UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   profile_adp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for implementing more profile api for BCM than mmi service.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line: this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 02 20 2014 guoqing.ren
 * removed!
 * when sppc is not init, we need return NULL inst in state check function.
 *
 * 02 19 2014 guoqing.ren
 * removed!
 * fix spp client definition and some  spp client connect issue.
 *
 * 02 18 2014 guoqing.ren
 * removed!
 * Fix PAIR way judge condition when confirm them.
 *
 * 02 10 2014 guoqing.ren
 * removed!
 * 	Fix bug that when got state of a conn with an addr we didn't consider the conn role.
 *
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line: this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __BCM_AT_CMD__

/*****************
Include Statements
******************/
//#include "kal_release.h"      	/* Basic data type */

//#include "stack_common.h"  
//#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"      	/* Task creation */

//#include "stacklib.h"        	/* Basic type for dll: evshed: stacktimer */

//#include "event_shed.h"       	/* Event scheduler */

//#include "stack_timer.h"      	/* Stack timer */
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "Bcm_btcmSrvProt.h"
#include "BcmSppSrv.h"
#include "bcm_trc.h"
#include "Bcm_btcmUtility.h"
#include "bcmadp.h"
#include "bcm_struct.h"
#include "bcm_btcmApp.h"
#include "bcmSppUtility.h"
#include "bcm_spp_app.h"
/*
* use addr and role to unify a conn.
* case currently each role has only one conn, so this is possible.
*/
srv_spp_connect_state srv_bt_spp_get_state(srv_bt_cm_bt_addr addr,kal_uint8 role)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	srv_spp_conn_cntx* conn;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(role)//server
    {
        inst = srv_spp_get_inst_by_handle(g_bcm_spp_cntx_p->handle);
    }
    else//client
    {
        /*
            * we init sppc client(g_bcm_spp_client_cntx) each time we receive sppc conn reqest.
            * but it not perfect.
            * because when we get the state of the client, if the client is not init yet, we may get handle 0's inst,
            * the handle 0's inst may be the inited spps client(g_bcm_spp_cntx_p).
            * so we just add a flag is_initted to record whether or not the sppc is initeded.
            */
        if(g_bcm_spp_client_cntx->is_initted)
        {
            inst = srv_spp_get_inst_by_handle(g_bcm_spp_client_cntx->handle);
        }
        else
        {
            inst = NULL;
        }
    }

    if(inst)
    {
        for (conn = inst->cntx.connect; conn != NULL; conn = conn->next)
        {
        	if (conn->bt_addr.lap == addr.lap &&
                conn->bt_addr.uap == addr.uap &&
                conn->bt_addr.nap == addr.nap) 
            {
                BCM_STATE_ENTRY(STATE_PROFILE_STATE,SRV_BT_CM_SPP_PROFILE_UUID,addr.lap,addr.uap,addr.nap,conn->conn_state);
                return conn->conn_state;
            }
        }
    }

	return SRV_SPP_CONN_STATE_IDLE;
}

srv_spp_conn_cntx* srv_spp_get_conn_by_handle_addr(SppHandle handle,srv_bt_cm_bt_addr addr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	srv_spp_conn_cntx* conn;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst = srv_spp_get_inst_by_handle(handle))
    {
        for (conn = inst->cntx.connect; conn != NULL; conn = conn->next)
            if (conn->bt_addr.lap == addr.lap &&
                conn->bt_addr.nap == addr.nap &&
                conn->bt_addr.uap == addr.uap ) return conn;

    }
	return NULL;
}

#endif



