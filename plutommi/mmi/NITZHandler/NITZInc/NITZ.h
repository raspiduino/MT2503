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
 * NITZ.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * This file defines prototypes and structure of NITZ application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************
   FILENAME : NITZ.h
   PURPOSE     : NITZ Inlcude File
   REMARKS     : nil
   AUTHOR      : Restructured by Gurinder
   DATE     : Restructured on Dec-01-2003
**************************************************************/
#ifndef _MMI_NITZ_H
#define _MMI_NITZ_H

#include "MMI_features.h"

#ifdef __MMI_NITZ__
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "ps_public_enum.h"
#include "app_datetime.h"
#include "NitzSrvGprot.h"
#include "MenuCuiGprot.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#define NITZ_NOTIFY_LENGTH 250	/* NITZ nofity string max length */

#define MMI_NITZ_SIM_MASK   0x0F	/* SIM Card flag to mark SIM1 or SIM2 */
#define MMI_NITZ_STATE_MASK 0x10	/* NITZ state flag */

/***************************************************************************** 
* Typedef
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_nitz_is_need_update
* DESCRIPTION
*  Check function of NITZ message need update or not
* PARAMETERS
*  void
* RETURNS
*  void
 *****************************************************************************/
extern U8 mmi_nitz_is_need_update(void);


/*****************************************************************************
* FUNCTION
*  NITZHandler
* DESCRIPTION
*  entry function of NITZ confirm screen and use as idle callback 
* PARAMETERS
*  void
* RETURNS
*  void
 *****************************************************************************/
extern void mmi_nitz_entry_nitz_confirm_screen(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_phnset_menu_handler
 * DESCRIPTION
 *  This function is high light handler of NITZ menu
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_ret mmi_nitz_phnset_menu_handler(cui_menu_event_struct *menu_evt, mmi_id parent_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_nitz_get_curr_nitz_string
 * DESCRIPTION
 *  The current selected nitz string
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
extern U16 mmi_nitz_get_curr_nitz_string(void);

#endif /* defined(__MMI_NITZ__) */ 
#endif /* _MMI_NITZ_H */ 

