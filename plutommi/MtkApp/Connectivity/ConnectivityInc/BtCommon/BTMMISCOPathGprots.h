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
 * BTMMIScopathGprot.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file of BTMMISCOPath.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BT_MMI_SCO_PATH_GPROT_H__
#define __BT_MMI_SCO_PATH_GPROT_H__

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"

typedef enum
{
    MMI_BT_SCO_HFP_ACL,
    MMI_BT_SCO_HFP_SCO
} MMI_BT_SCO_CONNECT_TYPE_ENUM;

typedef enum
{
    MMI_BT_SCO_IND,
    MMI_BT_SCO_RSP,
    MMI_BT_SCO_REQ
} MMI_BT_SCO_IND_TYPE_ENUM;

typedef enum
{
    MMI_BT_SCO_OK,
    MMI_BT_SCO_FAIL,
    MMI_BT_SCO_TIMEOUT,
    MMI_BT_SCO_BUSY
} MMI_BT_SCO_RES_ENUM;

typedef enum
{
    MMI_BT_SCO_INQ_SCO_DISCONNECTED,
    MMI_BT_SCO_INQ_SCO_CONNECTED_DISCONNECTABLE,
    MMI_BT_SCO_INQ_SCO_CONNECTED_IN_CALL,
    MMI_BT_SCO_INQ_TOTAL
} mmi_bt_sco_inquiry_error_enum;


#define MMI_BT_SCO_INT_A2DP     0x01
#define MMI_BT_SCO_INT_FMRADIO  0x02
#define MMI_BT_SCO_INT_CAMERA   0x04
#define MMI_BT_SCO_INT_VIDEO   0x08

#ifdef __MMI_BT_AUDIO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_is_connected
 * DESCRIPTION
 *  to check if bt is connected
 * PARAMETERS
 *  connect_type        [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_bt_sco_is_connected(U8 connect_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_is_sco_connect_allowed
 * DESCRIPTION
 *  check if bt sco connect request is allowed
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE if allowed
 *****************************************************************************/
extern MMI_BOOL mmi_bt_sco_is_sco_connect_allowed(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_show_switch_path_popup
 * DESCRIPTION
 *  check is it allowed to popup
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_bt_sco_show_switch_path_popup(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_connect_sco
 * DESCRIPTION
 *  Connect sco link before running application, use callback to make sure sco connected
 * PARAMETERS
 *  callback        [IN]
 * RETURNS
 * BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_bt_sco_connect_sco(void (*callback) (void));

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_disconnect_sco
 * DESCRIPTION
 *  disconnect sco link
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_bt_sco_disconnect_sco(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_deactivate_cnf_hdlr
 * DESCRIPTION
 *  the cnf handler for bt a2dp deactivate req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_sco_deactivate_cnf_hdlr(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_reset
 * DESCRIPTION
 *  to reset bt profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_sco_reset(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_open_stream_req
 * DESCRIPTION
 *  bt connect request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_bt_sco_open_stream_req(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_close_stream_req
 * DESCRIPTION
 *  bt disconnect request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_sco_close_stream_req(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_call_start_callback
 * DESCRIPTION
 *  the call back function for call start
 * PARAMETERS
 *  void
 *  BOOL(?)     [IN]        Turn on
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_sco_call_start_callback(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_call_end_callback
 * DESCRIPTION
 *  the call back function for call end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_sco_call_end_callback(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_hfp_disconnect_callback
 * DESCRIPTION
 *  the call back function for bt disconnect indication
 * PARAMETERS
 *  callback_type       [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_sco_hfp_disconnect_callback(U8 callback_type);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_switch_profile_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  is_on              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_sco_switch_profile_path(MMI_BOOL is_on);


#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_disable_sco_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_sco_disable_sco_timeout(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_enable_sco_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_sco_enable_sco_timeout(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_disable_sco_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_sco_disable_sco_connection(U8 app_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_enable_sco_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_sco_enable_sco_connection(U8 app_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_inquery_start_callback
 * DESCRIPTION
 *  Callback function for BT inquery
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_bt_sco_inquiry_error_enum mmi_bt_sco_inquery_start_callback(void (*callback) (void));

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_inquery_stop_callback
 * DESCRIPTION
 *  Callback function for BT inquery
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_sco_inquery_stop_callback(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sco_connect_audio_via_sco
 * DESCRIPTION
 *  connect sco link
 * PARAMETERS
 *  void
 * RETURNS
 * void
 *****************************************************************************/
extern void mmi_bt_sco_connect_audio_via_sco(void);

#endif /* #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__) */
#endif /* __MMI_BT_AUDIO_SUPPORT__ */ 

#endif /* __BT_MMI_SCO_PATH_GPROT_H__ */ 

