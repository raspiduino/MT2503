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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   ATHandler.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  .......
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 11 2013 kamal.sharma
 * removed!
 * Fix warning.
 *
 * 10 25 2011 fachao.zhang
 * removed!
 * remove cosmos AT command to own app.
 *
 * 09 28 2011 fachao.zhang
 * removed!
 * .
 *
 * 09 26 2011 fachao.zhang
 * removed!
 * .
 *
 * 09 25 2011 fachao.zhang
 * removed!
 * 
 * modify S8 to CHAR.
 *
 * 09 05 2011 fachao.zhang
 * removed!
 * remove GPS at command to GPS module.
 *
 * 09 04 2011 fachao.zhang
 * removed!
 * remove FM-Camera AT cmd to FM-Camera Moudle code.
 *
 * 08 16 2011 macross.chen
 * removed!
 * .
 *
 * 03 31 2011 fachao.zhang
 * removed!
 * .
 *
 * 12 14 2010 fachao.zhang
 * removed!
 * .
 *
 * 12 09 2010 yixiong.zhao
 * removed!
 * .
 *
 * 12 02 2010 cong.zhou
 * removed!
 * .
 *
 * 11 09 2010 fachao.zhang
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Update network name after AT change language
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * AT set language support for SIM2
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * send MSG_ID_MMI_AT_GENERAL_RES_REQ to L4 in ATSetDateandTimeFormat()
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * Remove compile option: MMI_ON_HARDWARE_P & MMI_ON_WIN32
 *
 * removed!
 * removed!
 * Add check for MMI_PS_AT_LANG_EN.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Fix compile warning.
 *
 * removed!
 * removed!
 * Add LCM Test support.
 *
 * removed!
 * removed!
 * Set Greeting text modification.
 *
 * removed!
 * removed!
 * Modify Index parameter of AtSetProfileTone.
 *
 * removed!
 * removed!
 * Add check length: 0xFF = only modify mode for setting greeting text.
 *
 * removed!
 * removed!
 * Add AT general response for set_silent mode.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      ATHandler.c
   Author:        Gautam
   Date Created:  
   Contains:   AT comamnd handler
**********************************************************************************/
#include "MMI_features.h"
#include "ProtocolEvents.h"

#include "AlarmFrameWorkProt.h"
#include "IdleGprot.h"
#include "MMIThemes.h"
#include "SettingGprots.h"
#include "WPSSProtos.h"
#include "ShortcutsProts.h"

#include "app_datetime.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "FontRes.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_input_gprot.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "wgui_categories_text_viewer.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "GlobalConstants.h"
#include "mmi_phnset_dispchar.h"
#include "stack_msgs.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"



/*********************/
/* Send Message Func */
/*********************/


/*****************************************************************************
 * FUNCTION
 *  SendMsg2AT
 * DESCRIPTION
 *  Send message to AT
 * PARAMETERS
 *  msg_id              [IN]        Message id
 *  local_param_ptr     [?]         Local parameter pointer
 *  peer_buf_ptr        [?]         Peer buffer pointer
 * RETURNS
 *  void
 *****************************************************************************/
void SendMsg2AT(U16 msg_id, int mod_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm((oslModuleType)mod_id, (oslMsgType)msg_id, 
                    (oslParaType*) local_param_ptr, (oslPeerBuffType *)peer_buf_ptr);
}


