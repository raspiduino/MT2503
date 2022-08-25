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
 *   Alarm.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resource XML file for nitz
 *
 * Author:
 * -------
 *   Wen Wu(MTK80153)
 *
 *******************************************************************************/

/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#include "SettingDefs.h"                // FACTORY_RESTORE_DEFAULT_XXX

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_NITZ">

#ifdef __MMI_NITZ__
    <!-----------------------------------------------------Include Resource Area----------------------------------------------------->
	<INCLUDE file = "GlobalMenuItems.h"/>
    <INCLUDE file = "GlobalResDef.h"/>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_NITZ_BASE"/>
    <STRING id="STR_ID_NITZ_APP"/>
    <STRING id="STR_ID_NITZ_APP_CONFIRM_FIRST"/>
    <STRING id="STR_ID_NITZ_CONFIRM_TITLE"/>
    <STRING id="STR_ID_NITZ_CONFIRM_INFO"/>
    <STRING id="STR_ID_NITZ_MAX"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_NITZ_CONFIRM" >CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_NITZ_APP"/>
    <SCREEN id="GRP_ID_NITZ_INDICATION"/>
    <SCREEN id="SCR_ID_NITZ_BASE"/>
		<SCREEN id="SCR_ID_SETTINGS_NITZ"/>
    <SCREEN id="SCR_ID_NITZ_CONFIRM"/>
    <SCREEN id="SCR_ID_NITZ_MAX"/>
    
    <MENU id="MENU_ID_NITZ_APP" type="OPTION" str="STR_ID_NITZ_APP">
        <MENUITEM id="MENU_ID_NITZ_APP_OFF" str="STR_GLOBAL_OFF"></MENUITEM>
        <MENUITEM id="MENU_ID_NITZ_APP_CONFIRM_FIRST" str="STR_ID_NITZ_APP_CONFIRM_FIRST"></MENUITEM>
        <MENUITEM id="MENU_ID_NITZ_APP_ON" str="STR_GLOBAL_ON"></MENUITEM>
    </MENU>


    <CACHEDATA type="byte" id="RESTORE_DEFAULT_AUTOUPDATE_TIME">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_AUTOUPDATE_TIME_VALUE] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>    

    <!------------------------------------------------------callback manager  sender part---------------------------------------------------------->
       <RECEIVER id="EVT_ID_SRV_NITZ_UPDATE_REQ" proc="mmi_nitz_dt_update_handler"/>

#endif /* __MMI_NITZ__ */

</APP>

