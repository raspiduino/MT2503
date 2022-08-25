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
 * SettingGprots.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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

/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : setting_gprot.h

   PURPOSE     : Settings application global function prototypes

   REMARKS     : nil

   AUTHOR      : Vanita Jain

   DATE     : 

**************************************************************/

#ifndef _PIXCOM_SETTINGGPROTS_H
#define _PIXCOM_SETTINGGPROTS_H
#include "MMI_features.h"

/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "PhoneSetup.h"
/* auto add by kw_check end */
typedef void (*SECSETFuncPtr) (void);
typedef void (*SECSETFuncPtr2) (U8 *text, U8 *cursor, S32 length);

#ifndef MAX_PASS_COUNTDOWN_DISP
#define MAX_PASS_COUNTDOWN_DISP 60
#endif

typedef struct  
{
    U16 scr_id;     
    U16 RSK_strID;  
    U16 comm_strID; 
    U8 min_length;  /* no need */  
    U8 PWDCountDisp[MAX_PASS_COUNTDOWN_DISP];
    U8 *inputBuffer;      /* input buffer for password */
    SECSETFuncPtr entry_func; 
    SECSETFuncPtr exit_func;
    SECSETFuncPtr rightkey_func;    
    SECSETFuncPtr length_callback;    
    SECSETFuncPtr sendkey_func;   
    SECSETFuncPtr star_func;      
    SECSETFuncPtr2 input_valid_func;  
} SecsetCommScrnContext;


extern void InitSettingApp(void);

/* micha0530 */
extern void EntryScrSettingMenu(void);
extern U8 GetAutoKeypadLockTime(void);
extern MMI_BOOL IsShowWelcomeScr1(void);
extern CHAR *GetWelcomeText(void);
extern MMI_BOOL IsShowAphorismScr1(void);
extern MMI_BOOL PhnsetGetNITZFuncStatus(void);

#if 0
/* under construction !*/
#if defined(__MMI_OPERATOR_NAME_MENU__)
/* under construction !*/
#endif 
#endif 
extern MMI_BOOL PhnsetGetShowDateTimeStatus(void);
extern MMI_BOOL SetLanguage(U8 *);
extern S16 PhnsetSetTimeFormat(U8 timeformat);
extern S16 PhnsetSetDateFormat(U8 dateformat);
extern BOOL ATSetHomeCity(U8 CityIndex);
#ifndef __MMI_PHNSET_AT_DISABLE__
extern void mmi_phnset_date_and_time_init_at_handler(void);
#endif
extern void Highlight_ScreenSaver_Menu(void);
extern void GetSettingOptionsStatus(void);
extern MMI_BOOL PhnsetSetWelcomeText(MMI_BOOL mode, U8 dcs, U8 *text, U8 length);
extern void PhnsetGetWelcomeText(S8 *buf, U16 buf_len);
extern void InitSettingBootup(void);
extern void InitSettingNVRAM(void);
extern void RstrSettingPasswdScrSoftKeyFunc(U8 *text, U8 *cursor, S32 length);
extern pBOOL SET_DefaultDateFormat(void);
extern pBOOL SET_DefaultTimeFormat(void);
extern void GoToAddEditScreen(void);
extern void PhbUpdateSpeedDial(U8, U16, U8, PU8, PU8);
extern void PhbDeleteAllSpeedDial(U8 storage, U8 type);
extern MMI_BOOL PhbRestoreSpeedDial(void);
extern void SettingInlineCustomFunction(void);
extern void GetDateTimeSetupNvRam(void);
#ifdef __MMI_TIMEZONE_SETTING__
extern void PhnsetReadNvmHomeCityIdxNStoreCityName(void);
extern void PhnsetReinitHomeCity(void);
#endif
extern void PhnsetSendSetTimeReqMessage(const MYTIME *time);
extern U8 PhnsetGetFontSize(void);

extern MMI_BOOL mmi_secset_is_in_puk_check(void);
#if 0
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif
#if 0
#if ((defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_12MATRIX__)) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
#endif
#endif

extern MMI_BOOL mmi_phnset_check_themeid_wallpaper(U16 imgID);



#ifdef __MMI_VUI_MAINMENU__
extern U8 mmi_phnset_get_vui_mm_effect_status(void);
#endif

#endif /* _PIXCOM_SETTINGGPROTS_H */ 

