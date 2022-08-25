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
 * BTMMIOppGprots.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
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
#ifndef __MMI_OPP_GPROTS_H__
#define __MMI_OPP_GPROTS_H__

#include "MMI_features.h"

#ifdef __MMI_OPP_SUPPORT__

#ifndef BT_MMI_CM_H
//#include "BTMMICm.h"
#include "BtcmSrvGprot.h"
#endif
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
/* RHR add end */
#ifdef __MMI_BT_SLIM__ 
#ifndef _MMI_BT_ULTRA_SLIM_ 
#define _MMI_BT_ULTRA_SLIM_ 
#endif 
#endif

/***************************************************************************** 
* Definations
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
/*BT Concurrency*/
/*****************************************************************************
 * FUNCTION
 *  mmi_opp_get_path
 * DESCRIPTION
 *  This function is to return the receiving file's path.
 * PARAMETERS
 *  void
 * RETURNS
 *  S8:      The path of receiving file
 *****************************************************************************/
extern S8 *mmi_opp_get_path(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_init
 * DESCRIPTION
 *  OPP initializing API. 
 *  This function initializes OPP client MMI and OPP server MMI and OPP service.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_opp_init(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_deinit
 * DESCRIPTION
 *  OPP de-initializing API. 
 *  This function de-initialize OPP service, OPP client MMI and OPP server MMI.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_opp_deinit(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_opp_is_receiving
 * DESCRIPTION
 *  This function is to check if OPP is about to receiving object. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_opp_is_receiving(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_opp_accepted_file
 * DESCRIPTION
 *  This function is to check if OPP is receiving object. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_opp_accepted_file(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_opp_set_recv_files_cnt
 * DESCRIPTION
 *  This function is change the count of the received objects. 
 * PARAMETERS
 *  cnt:      the number that the count of the received objects to be setted
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_opp_set_recv_files_cnt(U16 cnt);
/*****************************************************************************
 * FUNCTION
 *  mmi_opp_get_recv_files_cnt
 * DESCRIPTION
 *  This function is get the count of the received objects. 
 * PARAMETERS
 *  void
 * RETURNS
 *  U16:      the count of the received objects
 *****************************************************************************/
extern U16 mmi_opp_get_recv_files_cnt(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_opp_send_file_obj
 * DESCRIPTION
 *  This function is to send file object, now it is not used. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_opp_send_file_obj(void);
#ifdef __MMI_USB_SUPPORT__
extern mmi_ret mmi_opp_usb_plugin_hdlr(mmi_event_struct *evt);
#else
extern mmi_ret mmi_opp_usb_plugin_hdlr(mmi_event_struct *evt);
#endif
#endif /* __MMI_OPP_SUPPORT__ */

#endif /* __BT_MMI_OPP_GPROTS_H__ */ 


