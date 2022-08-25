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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : PopulateRes.h

   PURPOSE     : Common Resource Populate Header

   REMARKS     : nil

   AUTHOR      : Yogesh

   DATE     : August-11-2003

**************************************************************/

#include "GlobalDefs.h"
#include "CustDataRes.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#if !defined(__IOT__)
#include "MainMenuDef.h"
#endif
#include "GlobalMenuItems.h"
#ifdef __PLUTO_MMI_PACKAGE__ 
#if !defined(__IOT__)
#include "mmi_rp_app_mainmenu_def.h"
#endif
#endif
#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "CustResDef.h"

/* PhoneBook */
extern void PopulatePbResData(void);
extern void PopulateAdvancedPbResData(void);
extern void PopulateInlineEditRes(void);
extern void PopulateCopyAllResData(void);
extern void PopulateExtraNumberRes(void);
extern void PopulatePbookSettingsData(void);
extern void PopulatePhbExtraMainMenuRes(void);


/* SAT */
extern void PopulateSATRes(void);

/* Alarm */
extern void PopulateAlarmRes(void);

/* Help */
extern void PopulateHelpResources(void);

/* Organizer */
extern void PopulateCalorieData();
extern void PopulateHealthMensisRes(void);
extern void PopulateOrganizerRes(void);
extern void PopulateExtraRes(void);
extern void PopulateBMIData();
extern void PopulateCurrencyConvertor(void);
extern void PopulateUnitConvertor();
extern void mod_mmiPopulateWClockData(void);
extern void PopulateEcompass(void);

#ifdef __MMI_INDICAL__
extern void PopulateIndianCalendarRes(void);
extern void PopulateIndianCalendarStrRes(void);
extern void PopulateIndianCalendarImgRes(void);
extern void PopulateIndianCalendarMenuRes(void);
#endif

#ifdef __MMI_HIJRI_CALENDAR__
extern void PopulateHijriCalendarRes(void);
#endif

#ifdef __MMI_AZAAN_ALARM__
extern void PopulateAzaanAlarmRes(void);
#endif


/* Connect Management*/
#ifdef __MMI_CBM_CONNECTION_MANAGER__
extern void PopulateConnManageRes(void);
#endif /* __MMI_CBM_CONNECTION_MANAGER__ */

extern void PopulateCBM(void);
/* SSC */
extern void PopulateSSCRes();


#if defined(__MMI_NITZ__)
/* NITZHandler */
extern void PopulateResourceNITZ(void);
#endif /* defined(__MMI_NITZ__) */ 

/* FunAndGames */
extern void PopulateComposeRingTone(void);
extern void PopulateRingComposer(void);
extern void populateFunAndGamesMenu(void);
extern void PopulateThemes(void);

//Robin 0604 StopWatch Integration
//void PopulateStopwatchRes(void);

/* Games */
extern void PopulateGamesRes(void);
extern void PopulateF1RaceRes(void);
extern void PopulateTOHRes(void);
extern void PopulateRichesRes(void);
extern void PopulateColorBallRes(void);
extern void PopulateSnakeRes(void);
extern void PopulateSmashRes(void);
extern void PopulateJavaGameRes(void);

#ifdef __MMI_3D_GAME__
extern void Populate3DGameRes(void);
#endif 

#ifdef __MMI_MOTION_APP__
extern void PopulateMotionAppRes(void);
#endif 


/* Common Screens */
extern void PopulateCommonScreensResData(void);

/* IdleDemo */
extern void PopulateIdleMenuRes(void);
extern void PopulateMainDemoRes(void);

/* MiscFramework */
extern void PopulateChgrPwrOnScrRes(void);
extern void PopulateQuickAccessData(void);
extern void PopulateSimDetectionMenuRes(void);
extern void populateOptionMenu(void);

#if 0
/* under construction !*/
/* under construction !*/
#endif

/* Settings */
extern void PopulateCallBarring();
extern void PopulateCallForward(void);
extern void PopulateCallWait();
extern void PopulateCallerId(void);
extern void PopulateSettingMenu(void);
extern void PopulateEncodingStrings(void);
extern void PopulateLineSwitch(void);
extern void populateManageCalls();
extern void PopulateNetworkSetupResData(void);
extern void PopulatePhoneSetupResData(void);
extern void PopulatePrefNwk(void);
extern void PopulateSpofRes(void);
extern void PopulateScreenSaverRes(void);
extern void PopulateWallpaper();
extern void PopulategrouplistMenu(void);
extern void PopulateIPNumber(void);

/* CallManagement */
extern void PopulateCmResData(void);

/* Calls */
extern void PopulateBarredDialList(void);
extern void PopulateFixedDialList(void);
extern void PopulateAPNControlList(void);

/* Unified Message */
extern void PopulateUnifiedMessageResData(void);

/* Unified Composer */
extern void PopulateUnifiedComposerResData(void);

#ifdef __MMI_MMS_POSTCARD__
extern void PopulateMMSPostcardResData(void);
#endif

/* MainMenu */
extern void PopulateMainMenuRes(void);

/* Robin 0604 Stopwatch Integration */
#ifdef __MMI_STOPWATCH__
extern void PopulateStopwatchRes(void);
#endif 

#ifdef __MMI_EMAIL__
extern void EmailResourceData(void);
#endif /* def __MMI_EMAIL__ */

#if defined(__MMI_SMART_MESSAGE_MT__) || ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_MYPICTURE__)
extern void PopulateNSMRes(void);
extern void PopulateNsmStrRes(void);
extern void PopulateNsmImgRes(void);
extern void PopulateNsmMenuItemRes(void);
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_MYPICTURE__) */ 

/* micha_PoC */
#ifdef __MMI_POC__
extern void PoCResourceData(void);
#endif 

#ifdef __MMI_VOIP__
void VoIPResourceData(void);
#endif

#ifdef __MMI_UCM__
void UCMResourceData(void);
#endif

#ifdef __MMI_VIDEO_TELEPHONY__
extern void VTResourceData(void);
#endif

#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
#endif

#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
#endif

#ifdef __MMI_MMS_2__
extern void PopulateMMSAppResource(void);
#endif

#if defined(__MMI_MAPBAR_GIS__) || defined(__MMI_SUNAVI_GIS__) || defined(__MMI_MIGO_GIS__)
extern void PopulateGISRes(void);
#endif

#ifdef __CERTMAN_SUPPORT__
extern void PopulateCertManRes(void);
#endif /*__CERTMAN_SUPPORT__*/

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif


#if defined(__MMI_OPP_SUPPORT__) || defined(__MMI_BIP_SUPPORT__)
extern void PopulateExtDevBTIdleNotifyRes(void);
#endif

#ifdef __MMI_UDX_SUPPORT__
extern void PopulateUDXRes(void);
#endif /* __MMI_UDX_SUPPORT__ */

#ifdef __QQIM_SUPPORT__
extern void PopulateQQRes(void);
#endif

#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
extern void PopulateVirtualKeyboardRes(void);
#endif

#ifdef __MMI_SEARCH_WEB__
extern void PopulateSearchWebRes(void);
#endif

#endif /* DEVELOPER_BUILD_FIRST_PASS */ 

