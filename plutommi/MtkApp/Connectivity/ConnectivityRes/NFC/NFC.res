/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*  
OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
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
 *   NFC.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  nfc mmi resource file
 *
 * Author:
 * -------
 *   xiangnan qi (mtk81125)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime: $
 * $Log: $
 *
 * 09 30 2011 xiangnan.qi
 * [MAUI_03040003] [11B][NFC] MMI on/off setting for PLUTO and COSMOS
 * .
 *
 * 09 30 2011 xiangnan.qi
 * [MAUI_03040003] [11B][NFC] MMI on/off setting for PLUTO and COSMOS
 * .
 *
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h" 
#include "custresdef.h"

#ifdef __NFC_SUPPORT__

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_NFC">   

<!----------------- String Id ----------------------------------------->
    <STRING id="STR_ID_NFC_SETTING"/>
    <STRING id="STR_ID_NFC_SETTING_ON"/>
    <STRING id="STR_ID_NFC_SETTING_OFF"/>
    <STRING id="STR_ID_NFC_ON_ERR"/>
	<STRING id="STR_ID_NFC_OFF_ERR"/>
	<STRING id="STR_ID_NFC_PROGRESS"/>
<!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "GRP_ID_NFC_SETTINGS"/>
    <SCREEN id = "SCR_ID_NFC_PROGRESS"/>


    <MENU id="MENU_CONN_NFC_MAIN" type="APP_SUB" str="STR_ID_NFC_SETTING" highlight="mmi_nfc_main_hilight_handler" launch="mmi_nfc_entry_main_menu">
		</MENU>

<!----------------- XML END ------------------------------------------->
</APP>
#endif
