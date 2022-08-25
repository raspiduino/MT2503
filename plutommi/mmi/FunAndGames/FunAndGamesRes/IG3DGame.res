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
 * Filename:
 * ---------
 *  IG3DGame.c
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  Intergrafx Game Resource
 *
 * Author:
 * -------
 *	
 *   Stanley Lee (MTK03619)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 10 2012 stanley.lee
 * [MAUI_03159976] 3D games show red X in main menu
 * .
 *
 * .
 *
 * 04 06 2012 stanley.lee
 * [MAUI_03158369] Cosmos slim related check-in
 * .
 *
 * 04 06 2012 stanley.lee
 * [MAUI_03158369] Cosmos slim related check-in
 * .
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "CustResDef.h"

<?xml version="1.0" encoding="UTF-8"?>

/* Intergrafx 3d game */
#if defined(__MMI_3D_GAME_INTERGRAFX__) && defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_APP_MANAGER_SUPPORT__)

<APP id="APP_IG_3DGAME"  
    package_name="native.mtk.3dgame" 
    name="STR_ID_3D_GAME_INTERGRAFX"
    img = "IMG_ID_3D_GAME_INTERGRAFX" 
    launch = "mmi_fng_entry_3d_game_intergrafx" 
    type="venus">

#if defined(__VENUS_3D_UI_ENGINE__)
    #if defined(__MMI_MAINLCD_480X800__)
        <MEMORY base="max(17*1024*1024, total(SRV_MDI_VDOPLY))" />
    #else    
        <MEMORY base="max(15*1024*1024, total(SRV_MDI_VDOPLY))" />
    #endif

    <STRING id="STR_ID_3D_GAME_INTERGRAFX"/>
    <SCREEN id="SCR_ID_IG_MAIN"/>
    <IMAGE id="IMG_ID_3D_GAME_INTERGRAFX">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\PhotoEditor.png"</IMAGE>
#else
    #if defined(__MMI_MAINLCD_480X800__)
        <MEMORY base="8*1024*1024" />
    #else
        <MEMORY base="6*1024*1024" />
    #endif

    <SCREEN id="SCR_ID_IG_MAIN"/>
    <STRING id="STR_ID_3D_GAME_INTERGRAFX"/>
    <IMAGE id="IMG_ID_3D_GAME_INTERGRAFX">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\PhotoEditor.png"</IMAGE>
    <MENUITEM id="MENU_ID_3D_GAME_INTERGRAFX" str="STR_ID_3D_GAME_INTERGRAFX" img="IMG_ID_3D_GAME_INTERGRAFX" highlight="mmi_fng_3d_game_intergrafx_hilight_hdlr"/>

#endif




 
 </APP>

#endif
