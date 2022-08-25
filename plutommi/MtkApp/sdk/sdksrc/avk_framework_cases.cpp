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
 *   avk_framework_cases.cpp
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
 *Jia Luo (mtk80935)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "avk_framework_core.h"
#include "avk_framework_ui.h"
#include "avk_framework_log.h"
#include "avk_framework_interface.h"

void avk_framework_cases_init(void)
{
    int dummy_para = 0;
    //do nothing!
}
//***********************************************************
//UI list architecture
//***********************************************************
AVK_ADD_ROOT(AVK_ROOT,L"AVK")
    AVK_TEST_ALL(AVK_ROOT)
    //***********************************************************
    //Framework
    //***********************************************************
#ifdef __VENUS_3D_UI_ENGINE__
    AVK_ADD_ITEM(AVK_V3D_ENGINE,L"V3D",AVK_ROOT)
    	  AVK_TEST_ALL(AVK_V3D_ENGINE)
#endif    	  
    AVK_ADD_ITEM(AVK_FW,L"Framework",AVK_ROOT)
        AVK_TEST_ALL(AVK_FW)
        AVK_ADD_ITEM(AVK_FW_PLUTO,L"Pluto",AVK_FW)
            AVK_TEST_ALL(AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_RES,L"Get Resource",AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_FONT,L"Font",AVK_FW_PLUTO)            
            AVK_ADD_ITEM_EX(AVK_PLUTO_CSET,L"Charset",AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_SENA,L"Senario",AVK_FW_PLUTO)
#ifdef __MMI_FRM_HISTORY__
            AVK_ADD_ITEM_EX(AVK_PLUTO_SCRN,L"Screen",AVK_FW_PLUTO)
#endif
            AVK_ADD_ITEM_EX(AVK_PLUTO_EVENT,L"Event",AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_MEM,L"Memory",AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_TOUCH,L"Touch panel",AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_KEY,L"Key related",AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_STR,L"String",AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_TIMER,L"Timer",AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_MUTEX,L"Mutex",AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_QUEUE,L"Queue",AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_NVRAM,L"NVRAM",AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_TRACE,L"Trace",AVK_FW_PLUTO)
            AVK_ADD_ITEM(AVK_PLUTO_CUI,L"CUI",AVK_FW_PLUTO)
                AVK_ADD_ITEM_EX(AVK_CUI_EDT,L"CUI editor",AVK_PLUTO_CUI)
                AVK_ADD_ITEM_EX(AVK_CUI_INLINE,L"CUI inline editor",AVK_PLUTO_CUI)
                AVK_ADD_ITEM_EX(AVK_CUI_MENU,L"CUI menu",AVK_PLUTO_CUI)
            AVK_ADD_ITEM_EX(AVK_PLUTO_CB,L"Callback Manager",AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_NM,L"Notification Manager",AVK_FW_PLUTO)
            AVK_ADD_ITEM_EX(AVK_PLUTO_AM,L"App Manager",AVK_FW_PLUTO)            
            AVK_ADD_ITEM_EX(AVK_PLUTO_ROTATION,L"Screen Rotation",AVK_FW_PLUTO)  
        AVK_ADD_ITEM(AVK_FW_VENUS,L"Venus",AVK_FW)
            AVK_TEST_ALL(AVK_FW_VENUS)
            AVK_ADD_ITEM_EX(AVK_VENUS_ENGINE,L"UI engine",AVK_FW_VENUS)
            AVK_ADD_ITEM_EX(AVK_VENUS_FW,L"Framework",AVK_FW_VENUS)
        AVK_ADD_ITEM_EX(AVK_FW_GRAPHIC,L"Graphic",AVK_FW)
        AVK_ADD_ITEM_EX(AVK_FW_GRAPHIC3D,L"Graphic3D",AVK_FW)
    //***********************************************************
    //App service
    //***********************************************************    
    AVK_ADD_ITEM(AVK_APPSRV,L"App service",AVK_ROOT)
        AVK_TEST_ALL(AVK_APPSRV)
        AVK_ADD_ITEM_EX(AVK_APPSRV_IDLE,L"Idle",AVK_APPSRV)
            AVK_TEST_ALL(AVK_APPSRV_IDLE)
            AVK_ADD_ITEM_EX(AVK_IDLE_BOOTUP,L"Bootup",AVK_APPSRV_IDLE)
            AVK_ADD_ITEM_EX(AVK_IDLE_INFO,L"Network info",AVK_APPSRV_IDLE)
            AVK_ADD_ITEM_EX(AVK_IDLE_USA,L"Network usability",AVK_APPSRV_IDLE)
            AVK_ADD_ITEM_EX(AVK_IDLE_SHUTDOWN,L"Shut down",AVK_APPSRV_IDLE)
            AVK_ADD_ITEM_EX(AVK_IDLE_NWNAME,L"Network Name",AVK_APPSRV_IDLE)
        AVK_ADD_ITEM(AVK_APPSRV_MSG,L"Message",AVK_APPSRV)
            AVK_TEST_ALL(AVK_APPSRV_MSG)
            AVK_ADD_ITEM_EX(AVK_MSG_SMS,L"SMS",AVK_APPSRV_MSG)
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
            AVK_ADD_ITEM_EX(AVK_MSG_MMS,L"MMS",AVK_APPSRV_MSG)
#endif
            AVK_ADD_ITEM_EX(AVK_MSG_UM,L"UM",AVK_APPSRV_MSG)
            AVK_ADD_ITEM_EX(AVK_MSG_EMAIL,L"Email",AVK_APPSRV_MSG)
        AVK_ADD_ITEM_EX(AVK_APPSRV_PIM,L"PIM",AVK_APPSRV)
            AVK_ADD_ITEM_EX(AVK_PIM_PB,L"Phonebook",AVK_APPSRV_PIM)
        AVK_ADD_ITEM(AVK_APPSRV_CALL,L"Call",AVK_APPSRV)
            AVK_TEST_ALL(AVK_APPSRV_CALL)
            AVK_ADD_ITEM_EX(AVK_CALL_UCM,L"UCM",AVK_APPSRV_CALL)
            AVK_ADD_ITEM_EX(AVK_CALL_LOG,L"Call log",AVK_APPSRV_CALL)
            AVK_ADD_ITEM_EX(AVK_CALL_SS,L"SS",AVK_APPSRV_CALL)
            AVK_ADD_ITEM_EX(AVK_CALL_SIM,L"SIM",AVK_APPSRV_CALL)
            AVK_ADD_ITEM_EX(AVK_CALL_CPHS,L"CPHS",AVK_APPSRV_CALL)
            AVK_ADD_ITEM_EX(AVK_CALL_SET,L"Call setting",AVK_APPSRV_CALL)
        AVK_ADD_ITEM_EX(AVK_APPSRV_MM,L"MultiMedia",AVK_APPSRV)
            AVK_TEST_ALL(AVK_APPSRV_MM)
            AVK_ADD_ITEM_EX(AVK_MM_CAMERA,L"Camera",AVK_APPSRV_MM)
            AVK_ADD_ITEM_EX(AVK_MM_AUDIO,L"Audio",AVK_APPSRV_MM)
            AVK_ADD_ITEM_EX(AVK_MM_VIDEO,L"Video",AVK_APPSRV_MM)
            AVK_ADD_ITEM_EX(AVK_MM_DRM,L"DRM",AVK_APPSRV_MM)
            AVK_ADD_ITEM_EX(AVK_MM_PROFILE,L"Profile",AVK_APPSRV_MM)
            AVK_ADD_ITEM_EX(AVK_MM_BITSTREAM,L"Bitstream",AVK_APPSRV_MM)
        AVK_ADD_ITEM_EX(AVK_APPSRV_FMGR,L"File manager",AVK_APPSRV)
        AVK_ADD_ITEM_EX(AVK_APPSRV_SECU,L"Security",AVK_APPSRV)
            AVK_ADD_ITEM_EX(AVK_SECU_CERT,L"Certificate",AVK_APPSRV_SECU)
            AVK_ADD_ITEM_EX(AVK_SECU_CHIPHER,L"Cipher",AVK_APPSRV_SECU)
        AVK_ADD_ITEM_EX(AVK_APPSRV_SET,L"Setting",AVK_APPSRV)
            AVK_TEST_ALL(AVK_APPSRV_SET)
            AVK_ADD_ITEM_EX(AVK_SET_DEV,L"Device profile",AVK_APPSRV_SET)
            AVK_ADD_ITEM_EX(AVK_SET_TIME,L"Alarm&Time",AVK_APPSRV_SET)
            AVK_ADD_ITEM_EX(AVK_SET_MODE,L"Mode switch",AVK_APPSRV_SET)
			AVK_ADD_ITEM_EX(AVK_DATE_TIME,L"Date time",AVK_APPSRV_SET)
    //***********************************************************
    //System servic
    //***********************************************************     
    AVK_ADD_ITEM_EX(AVK_SYSSRV,L"System service",AVK_ROOT)
        AVK_TEST_ALL(AVK_SYSSRV)
        AVK_ADD_ITEM_EX(AVK_SYSSRV_BASE,L"Base",AVK_SYSSRV)
        AVK_ADD_ITEM_EX(AVK_SYSSRV_FILE,L"File system",AVK_SYSSRV)
        AVK_ADD_ITEM_EX(AVK_SYSSRV_FILE_ASYNC,L"File system async",AVK_SYSSRV)
    //***********************************************************
    //Network
    //***********************************************************    
    AVK_ADD_ITEM_EX(AVK_NW,L"Network",AVK_ROOT)
        AVK_TEST_ALL(AVK_NW)
        AVK_ADD_ITEM_EX(AVK_NW_CBM,L"CBM",AVK_NW)
        AVK_ADD_ITEM_EX(AVK_NW_SOC,L"Socket",AVK_NW)
        AVK_ADD_ITEM_EX(AVK_NW_WPS,L"WPS",AVK_NW)
        AVK_ADD_ITEM_EX(AVK_NW_DA,L"Data account",AVK_NW)
    //***********************************************************
    //Device
    //***********************************************************    
    AVK_ADD_ITEM_EX(AVK_DEVICE,L"Device",AVK_ROOT)
        AVK_TEST_ALL(AVK_DEVICE)
        AVK_ADD_ITEM_EX(AVK_DEVICE_BATT,L"Charge battery",AVK_DEVICE)
        AVK_ADD_ITEM_EX(AVK_DEVICE_BACKLIGHT,L"Backlight",AVK_DEVICE)
        AVK_ADD_ITEM_EX(AVK_DEVICE_GPIO,L"GPIO",AVK_DEVICE)
        AVK_ADD_ITEM_EX(AVK_DEVICE_CONN,L"Connection",AVK_DEVICE)
            AVK_ADD_ITEM_EX(AVK_CONN_BIP,L"BIP",AVK_DEVICE_CONN)
            AVK_ADD_ITEM_EX(AVK_CONN_BPP,L"BPP",AVK_DEVICE_CONN)
            AVK_ADD_ITEM_EX(AVK_CONN_BTCM,L"BTCM",AVK_DEVICE_CONN)
            AVK_ADD_ITEM_EX(AVK_CONN_BTHFP,L"BTHFP",AVK_DEVICE_CONN)
            AVK_ADD_ITEM_EX(AVK_CONN_BTOPP,L"BTOPP",AVK_DEVICE_CONN)
#ifdef __MMI_SPP_SUPPORT__
            AVK_ADD_ITEM_EX(AVK_CONN_BTSPP, L"BTSPP", AVK_DEVICE_CONN)
#endif  // __MMI_SPP_SUPPORT__
#ifdef __MMI_USB_SUPPORT__
        AVK_ADD_ITEM_EX(AVK_DEVICE_USB, L"USB", AVK_DEVICE)
#endif
   //***********************************************************
    //Others
    //***********************************************************    
    AVK_ADD_ITEM_EX(AVK_OTHER,L"Others",AVK_ROOT)
        AVK_TEST_ALL(AVK_OTHER)
        AVK_ADD_ITEM_EX(AVK_OTHER_IMEI,L"IMEI",AVK_OTHER)
        AVK_ADD_ITEM_EX(AVK_OTHER_URI,L"URI agent",AVK_OTHER)
        AVK_ADD_ITEM_EX(AVK_OTHER_APPLIB,L"App lib",AVK_OTHER)
        AVK_ADD_ITEM_EX(AVK_OTHER_XML,L"XML",AVK_OTHER)
    //***********************************************************
    //Special
    //***********************************************************
    AVK_ADD_ITEM_SPECIAL_ROOT(AVK_SPECIAL,L"Special Cases",AVK_ROOT)
    //***********************************************************
    //Settings
    //***********************************************************
    AVK_SETTING(AVK_ROOT)         
/***********************************************************
NOTE:   Please do NOT modify this file. 
            if you want to add item whose cases are only in one .cpp file,    
            please just add in your file. 
            Otherwise,please notify me to add.
            Or,if something wrong,please let me know.
***********************************************************/


#define __AVK_FRAMEWORK_INTERNAL__
#include "..\casesrc\avk_framework_cases_internal.h"