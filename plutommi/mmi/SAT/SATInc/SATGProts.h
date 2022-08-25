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
 * SATGProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   SIM application toolkit related functions
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

   FILENAME : SATGProts.h

   PURPOSE     : SAT application 

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : Mar 24,03

**************************************************************/

#ifndef _PIXTEL_SATGPROTS_H
#define _PIXTEL_SATGPROTS_H

#ifdef __SAT__
#include "MMIDataType.h"
/* file path of icon2 */
#define SAT_ICON2_FILEPATH L"Z:\\@USER\\saticon2.pbm"


/*****************************************************************************
 * FUNCTION
 *  InitSimAppToolkit
 * DESCRIPTION
 *  Initialises variables & Protocol Handlers for SAT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void InitSimAppToolkit(void);


/*****************************************************************************
 * FUNCTION
 *  GoToSATMainMenu
 * DESCRIPTION
 *  Displays SAT Main Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void GoToSATMainMenu(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_pre_entry_GoToSATMainMenu
 * DESCRIPTION
 *  Pre Entry Function for displaying SAT Main Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sat_pre_entry_GoToSATMainMenu(void);


#if ( MMI_MAX_SIM_NUM >=2)
/*****************************************************************************
 * FUNCTION
 *  mmi_sat_pre_entry_GoToSATMainMenu_2
 * DESCRIPTION
 *  Pre Entry Function for displaying SAT Main Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sat_pre_entry_GoToSATMainMenu_2(void);
#endif


/*****************************************************************************
 * FUNCTION
 *  GetSATIdleText
 * DESCRIPTION
 *  Get the strings of idle text
 * PARAMETERS
 *  void
 * RETURNS
 *  Point of idle text string
 *****************************************************************************/
extern U8 *GetSATIdleText(void);


/*****************************************************************************
 * FUNCTION
 *  GetSATIdleIcon
 * DESCRIPTION
 *  Get the data of idle icon
 * PARAMETERS
 *  void
 * RETURNS
 *  Point of icon
 *****************************************************************************/
extern U8 *GetSATIdleIcon(void);


/*****************************************************************************
 * FUNCTION
 *  GetSATMainMenuAlphaID
 * DESCRIPTION
 *  Get the alpha identifier of main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  String of SAT Main Menu AlphaID
 *****************************************************************************/
extern U8 *GetSATMainMenuAlphaID(void);

#endif /* __SAT__ */


/*****************************************************************************
 * FUNCTION
 *  IsSATPresent
 * DESCRIPTION
 *  Get the status about sat1 present
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 * RETURN VALUES
 *  1: SAT present
 *  0: SAT not present
 *****************************************************************************/
extern U8 IsSATPresent(void);

#endif

