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
 *   AVBT.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  AVBT resource file
 *
 * Author:
 * -------
 *   Kinse Lin (mtk01393)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime: $
 * $Log: $
 *
 * 10 14 2010 kinse.lin
 * [MAUI_02827892] [A2DP] split screen apis from av_bt.c
 * .
 *
 * Jul 9 2010 mtk01393
 * [MAUI_02583327] [Resource] apply new resource gen for AVBT and Sound Effect
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h" 
#include "custresdef.h"

#ifdef __MMI_A2DP_SUPPORT__

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_A2DP">   

<!----------------- String Id ----------------------------------------->
    <STRING id="STR_ID_A2DP_BLUETOOTH_SETTINGS"/>
    <STRING id="STR_ID_A2DP_SETTINGS_ERR_FLIGHT_MODE"/>
    <STRING id="STR_ID_A2DP_SETTINGS_OUTPUT"/>
    <STRING id="STR_ID_A2DP_SETTINGS_BT_HEADSET"/>
    <STRING id="STR_ID_A2DP_SETTINGS_ERR_MUST_SELECT_HEADSET"/>
    <STRING id="STR_ID_A2DP_SETTINGS_SET_TO_DEFAULT_EARPHONE"/>

<!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "GRP_ID_A2DP_SETTINGS"/>
    <SCREEN id = "SCR_ID_A2DP_SETTINGS"/>

<!----------------- XML END ------------------------------------------->
</APP>
#endif
