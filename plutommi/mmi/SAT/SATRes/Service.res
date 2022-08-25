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
 * Service.res
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 *  Xiaolin Chen (mtk80776)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 10 15 2013 vikrant.jaiswal
 * [MAUI_03462439] [BT box] BT box feature check in to 11C
 * .
 *
 * 03 25 2013 vikrant.jaiswal
 * [MAUI_03363784] [SWPL Approved][Change feature]BT Dialer Package Check in
 * .
 *
 * 06 13 2012 sparsh.birla
 * [MAUI_03199297] [FTE2.0][Slim] FTE Launcher Main menu icon Slim on key launcher only projects
 * .
 *
 * 03 23 2012 xiaolin.chen
 * [MAUI_03149892] [TD Gemini 2.0][APOLLO55V2][STK] SAT 不符合移动白皮书要求
 * .
 *
 * 09 05 2011 xiaolin.chen
 * [MAUI_03017700] [SAT][FTE Launcher] integration
 * .
 *
 * 08 31 2011 xiaolin.chen
 * [MAUI_03017700] [SAT][FTE Launcher] integration
 * .
 *
 * 08 31 2011 xiaolin.chen
 * NULL
 * .
 *
 * 08 26 2011 xiaolin.chen
 * NULL
 * .
 *
 * 08 12 2011 xiaolin.chen
 * NULL
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_SERVICES_SAT"
#ifdef __MMI_APP_MANAGER_SUPPORT__  && defined (__MMI_TELEPHONY_SUPPORT__)
     package_name = "native.mtk.services_sat"
     name = "@OID:STR_ID_SAT_MENU_TITLE"
 #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
     img = "IMG_ID_SERVICE_SAT_TITLE"
 #endif
     #ifdef __OP01_3G__
         launch = "mmi_stk_key_launcher_proc"
     #else
         launch = "mmi_service_sat_proc"
     #endif
#else
     name = "@OID:STR_ID_SAT_MENU_TITLE"
#endif /* __MMI_APP_MANAGER_SUPPORT__ */
>

#ifdef __MMI_APP_MANAGER_SUPPORT__ && defined (__MMI_TELEPHONY_SUPPORT__)

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h, mmi_rp_srv_editor_def.h, mmi_rp_srv_sat_def.h, mmi_rp_app_mainmenu_def.h"/>

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->


    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
  #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
    <IMAGE id="IMG_ID_SERVICE_SAT_TITLE">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\MainMenu\\\\Icons\\\\SAT.png"</IMAGE>
  #endif

    /* For the detail of scope="XML" please check user manual */

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

    <!--Option Menu Tree Area-->
    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */

    <!------------------------------------------------------Other Resource---------------------------------------------------------->

#endif /* __MMI_APP_MANAGER_SUPPORT__ */
</APP>
