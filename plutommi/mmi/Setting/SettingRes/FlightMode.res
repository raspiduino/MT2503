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
 * PhoneSeetting.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Flight mode resource file with XML format.   
 *
 * Author:
 * -------
 *   Lina Yuan
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 10 11 2013 yunliu.mao
 * [MAUI_03462439] [BT box] BT box feature check in to 11C
 * .[BT box] BT box feature check in to 11C
 *
 * 11 22 2012 ligen.li
 * [MAUI_03260501] [MSZ] Remove unused string in 11BW1232OF_SLIM_DEV
 * remove unused string.
 *
 * 09 22 2011 xiangnan.qi
 * [MAUI_03032484] [Settings]The sim status is wrong when insert block sim
 * ..change image to img_global_progress.
 *
 * 05 25 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 05 13 2011 cong.zhou
 * [MAUI_02940255] [Setting] Add compile option __MMI_BOOTUP_MODE_SEL_SUPPORT__
 * .
 *
 * 12 14 2010 diamond.lee
 * [MAUI_02846075] [MMI][Gemini+] 10A and MAUI check in
 * Mode switch app part
 *
 * Jun 9 2010 mtk80585
 * [MAUI_02208090] [Settings] Remove unused resource ID
 * 
 *
 * Jun 4 2010 mtk80585
 * [MAUI_02205693] [Need Patch] Fix build error
 * 
 *
 * Apr 14 2010 mtk80047
 * [MAUI_02179055] [new feature][phone setting][PlutoFW 10A] check in
 * 
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"

#ifdef __MMI_TELEPHONY_SUPPORT__
<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_FLIGHT_MODE">

    <!-- string ----------------------------------------------------------------------------------->
    <STRING id = "STR_MENU_FLIGHT_MODE"/>
    <STRING id = "STR_FLIGHT_MODE_NORMAL"/>
    <STRING id = "STR_FLIGHT_MODE_SILENT"/>
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__    
    <STRING id = "STR_FLIGHT_MODE_QUERY"/>
#endif  
#if 0  
    <STRING id = "STR_FLIGHT_MODE_CONFIRM"/>
#endif
    <STRING id = "STR_FLIGHT_MODE_PROGRESS"/>
//    <STRING id = "STR_FLIGHT_MODE_ASK"/>
    
    
    <!-- image ------------------------------------------------------------------------------------>
    <!-- IMG_FLIGHT_MODE_PROGRESS can be removed with CSB array  -->



    <!-- screen ----------------------------------------------------------------------------------->
    <SCREEN id = "SCR_FLIGHT_MODE_PROGRESS"/>


    <!-- menu ------------------------------------------------------------------------------------->
#ifdef __FLIGHT_MODE_SUPPORT__
    <MENUITEM id = "MENU_SETTING_FLIGHT_MODE" str = "STR_MENU_FLIGHT_MODE"/>
#endif

</APP>

#endif
