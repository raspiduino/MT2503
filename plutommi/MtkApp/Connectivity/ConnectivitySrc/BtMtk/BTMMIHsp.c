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
 * BTMMIHSP.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for HSP application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_HFP_SUPPORT__
#include "MMI_include.h"
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "IdleAppProt.h"

/* MMI Nvram access */

/* Trace Header Files */

/* Call Management related API */
#include "UcmGProt.h"
#include "UcmSrvGProt.h"

/* MMI BT profile related files */
#include "ProfilesSrvGprot.h"

/* External Device Header Files */
#include "ExtDeviceDefs.h"

#include "bt_dm_struct.h"
#include "bt_hsg_struct.h"

#include "BtcmSrvGprot.h"
#include "BTMMIScrGprots.h"

/* HSP */
#include "BTMMIHspGprots.h"
#include "BTMMIHsp.h"

/* RHR ADD */
#include "MMIDataType.h"
#include "kal_general_types.h"
/* RHR ADD end */


/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Globol Variable
*****************************************************************************/

/***************************************************************************** 
* Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_init
 * DESCRIPTION
 *  This function is to init hsp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_init_hsp_event_handler
 * DESCRIPTION
 *  This function is to init hsp event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_init_hsp_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_activate_req_hdler
 * DESCRIPTION
 *  This function is to handle activation request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_activate_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_activate_cnf_hdler
 * DESCRIPTION
 *  This function is to handle activation cnf
 * PARAMETERS
 *  msg         [IN] inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_activate_cnf_hdler(void *msg)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_deactivate_req_hdler
 * DESCRIPTION
 *  This function is to handle deactivation request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_deactivate_req_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_deactivate_cnf_hdler
 * DESCRIPTION
 *  This function is to handle deactivation cnf
 * PARAMETERS
 *  msg         [IN] inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_deactivate_cnf_hdler(void *msg)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_connect_req_hdler
 * DESCRIPTION
 *  This function is to handle connect request
 * PARAMETERS
 *  device_addr     [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_connect_req_hdler(srv_bt_cm_bt_addr device_addr)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_connect_cnf_hdler
 * DESCRIPTION
 *  This function is to handle connect cnf
 * PARAMETERS
 *  msg         [IN] inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_connect_cnf_hdler(void *msg)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_connect_ind_hdler
 * DESCRIPTION
 *  This function is to handle connect indication
 * PARAMETERS
 *  msg         [IN] inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_connect_ind_hdler(void *msg)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_disconnect_req_hdler
 * DESCRIPTION
 *  This function is to handle disconnect request
 * PARAMETERS
 *  device_addr     [IN]            
 *  connect_id      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_disconnect_req_hdler(srv_bt_cm_bt_addr device_addr, U32 connect_id)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_disconnect_cnf_hdler
 * DESCRIPTION
 *  This function is to handle disconnect cnf
 * PARAMETERS
 *  msg         [IN] inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_disconnect_cnf_hdler(void *msg)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_disconnect_ind_hdler
 * DESCRIPTION
 *  This function is to handle disconnect indication
 * PARAMETERS
 *  msg         [IN] inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_disconnect_ind_hdler(void *msg)
{
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_connection_authorize_ind_hdler
 * DESCRIPTION
 *  This function is to handle the connect accept confirmation for incoming connection
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_connection_authorize_ind_hdler(void *msg)
{
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_connection_authorize_rsp_hdler
 * DESCRIPTION
 *  This function is to respond the connection accept confirmation for incoming connection
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_connection_authorize_rsp_hdler(srv_bt_cm_bt_addr bt_addr, U32 result)
{
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_speaker_gain_req_hdler
 * DESCRIPTION
 *  This function is to handle gain request
 * PARAMETERS
 *  speaker_gain        [IN]            
 *  conn_id             [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_speaker_gain_req_hdler(U8 speaker_gain, U32 conn_id)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_speaker_gain_cnf_hdler
 * DESCRIPTION
 *  This function is to handle gain cnf
 * PARAMETERS
 *  msg         [IN] inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_speaker_gain_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_speaker_gain_ind_hdler
 * DESCRIPTION
 *  This function is to handle gain ind
 * PARAMETERS
 *  msg         [IN] inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_speaker_gain_ind_hdler(void *msg)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_mic_gain_req_hdler
 * DESCRIPTION
 *  This function is to handle gain req
 * PARAMETERS
 *  speaker_gain        [IN]            
 *  conn_id             [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_mic_gain_req_hdler(U8 speaker_gain, U32 conn_id)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_mic_gain_cnf_hdler
 * DESCRIPTION
 *  This function is to handle gain cnf
 * PARAMETERS
 *  msg         [IN] inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_mic_gain_cnf_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_mic_gain_ind_hdler
 * DESCRIPTION
 *  This function is to handle gain ind
 * PARAMETERS
 *  msg         [IN] inter layer message             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hsg_mic_gain_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hsg_disconnect_all
 * DESCRIPTION
 *  This function is to disconnect all connections
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bth_hsg_disconnect_all(void)
{
    return MMI_TRUE;
}

MMI_BOOL mmi_bth_hsg_cancel_connect(void)
{
    return MMI_TRUE;
}

#endif /* __MMI_HFP_SUPPORT__ */ 


