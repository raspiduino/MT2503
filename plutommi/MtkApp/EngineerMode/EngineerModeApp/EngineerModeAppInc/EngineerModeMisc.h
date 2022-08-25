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
 *  EngineerModeMisc.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode misc items function prototype declaration.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_EM_MISC_H
#define MMI_EM_MISC_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
    #include "MMI_features.h"
    #include "MMIDataType.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

extern void EntryEmAutoAnswer(void);
extern void EntryEmSerialPortEnable(void);
extern void HighlightAutoTestSetting(void);
extern void HighlightEmHighSpeedSIM(void);
extern void HightlightEMCellReselect(void);

extern void EntryEmCellReselect(void);
extern void EMCellReselectDoneFunc(void);
extern void HightlightEMRAMTestHdlr(void);

#ifdef __MMI_FM_AUTO_TEST__
extern void HiliteAllTestIdx(S32 hiliteIdx);
extern U16 GetSelectedTestList(void);
extern void ReadTestResultFromNVRAM(void);
extern void WriteTestResultToNVRAM(void);
extern void ReadTimeFromNVRAM(void);
extern void WriteCurrentTimeToNVRAM(void);
extern void ReadSettingsFromNVRAM(void);
extern void SaveNewItemToNVRAM(void);
extern void SavePriorityChangeToNVRAM(void);
extern void SaveRemoveItemToNVRAM(void);
extern void HiliteAutoTestCurrSelIdx(S32 hiliteIdx);
#endif /*__MMI_FM_AUTO_TEST__*/

extern void EntryEMRAMTestMenu(void);

#ifdef __MMI_EM_MISC_X_DOWNLOAD__
/* under construction !*/
/* under construction !*/
#endif

extern void mmi_em_misc_menu_event_hdlr(cui_menu_event_struct *event);
extern void mmi_em_misc_menu_event_entry_hdlr(cui_menu_event_struct *event);
#endif /* MMI_EM_MISC_H */ 

#if defined(__MMI_EM_MISC_HIGHSPEED_SIM__)
/* under construction !*/
/* under construction !*/
#endif



