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
 * AlarmGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file exports global functions provided by Alarm application.
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

   FILENAME : AlarmGprot.h

   PURPOSE     : Alarm application 

   REMARKS     : nil

   AUTHOR      : Gautam Saluja

   DATE     : June 16,03

**************************************************************/
#ifndef _MMI_ALARMGPROT_H
#define _MMI_ALARMGPROT_H

    #include "MMIDataType.h"
    #include "custom_mmi_default_value.h"
    #include "kal_non_specific_general_types.h"
	#include "AlarmProt.h"
	#include "AlarmDef.h"

/*****************************************************************************
 * Typedef 
*****************************************************************************/
#ifndef __MMI_DEV_NEW_SLIM__
typedef MMI_BOOL (*AlmSearchCallback)(U8, MYTIME *, MMI_BOOL);
typedef MMI_BOOL (*AlmCompareCallback)(U8, U8, MMI_BOOL);
#endif

/*****************************************************************************
 * FUNCTION
 *  AlmInit
 * DESCRIPTION
 *  Initailization function. Set the highlight handlers and get required strings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void AlmInit(void);
extern void EntryAlmIndicationScreen(void);
extern void AlmCommonExitProcedure(void);


#ifndef __MMI_DEV_NEW_SLIM__

/*****************************************************************************
 * FUNCTION
 *  EntryAlmSubLcdScreen
 * DESCRIPTION
 *  Display sub-lcd screen when alarm expires.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void EntryAlmSubLcdScreen(void);


/*****************************************************************************
 * FUNCTION
 *  AlmTimeEditorCallBack
 * DESCRIPTION
 *  Callback function for inline time editor.
 * PARAMETERS
 *  string_buffer : [IN/OUT] Buffer to store the result of time
 *  hours_buffer : [IN] Buffer to store hour string
 *  min_buffer : [IN] Buffer to store minute string
 *  AM_PM_flag : [IN] Flag to indicate the time format of time string
 * RETURNS
 *  void
 *****************************************************************************/
extern void AlmTimeEditorCallBack(U8 *string_buffer, U8 *hours_buffer, U8 *min_buffer, U8 *AM_PM_flag);
extern void AlmFCBInit(void);
#endif
#if 0
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_get_info
 * DESCRIPTION
 *  This function is used to get alarm data
 * PARAMETERS
 *  index   :[IN] Alarm index, start from 0, if index is error, it will assert.
 *  hour    :[OUT] alarm time hour field
 *  min     :[OUT] alarm time min field
 *  state   :[OUT] 1 -> turn on, 0 -> turn off
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_alm_get_info(U8 index, U8 *hour, U8 *min, U8 *state);


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_set_alarm_state
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  index        :[out] Alarm index, start from 0, if index is error, it will assert.
 *  state        :[IN]  1 -> turn on, 0 -> turn off
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_alm_set_alarm_state(U8 index, U8 state);
#if 0
#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN_0301__ */
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_alm_get_alm_time
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  time         :[out] next alarm time.
 *  soonze       :[IN] whether care about soonze alarm
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
extern MMI_BOOL mmi_alm_get_next_alarm(MYTIME *time, MMI_BOOL snooze);
/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_alm_eidt_screen
 * DESCRIPTION
 *  This function is entry alarm edit screen.
 * PARAMETERS
 *  U8      [IN]:   Alarm index from side info
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_alm_entry_alm_eidt_screen(U8 index);

#ifndef __MMI_DEV_NEW_SLIM__

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_search
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  time         :[out] next alarm time.
 *  soonze       :[IN] whether care about soonze alarm
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
extern void mmi_alm_search(U8 *list, U8 size, U8 *count, MMI_BOOL snooze, MYTIME *time, AlmSearchCallback callback);


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_sort
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  time         :[OUT] next alarm time.
 *  soonze       :[IN] whether care about soonze alarm
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
void mmi_alm_sort(U8 *list, U8 len, MMI_BOOL snooze, AlmCompareCallback callback);


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_check_next
 * DESCRIPTION
 *  post to handle the next alarm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_alm_check_next(void);
#endif
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__   */
#endif
#ifndef __MMI_DEV_NEW_SLIM__
extern void AlmExitIndScreen(void);
#endif
extern void mmi_factory_alm_set(U8 sec);


#endif /* _MMI_ALARMGPROT_H */ 

