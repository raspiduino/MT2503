/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  safemodeRes.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the safe mode resources.
 *
 * Author:
 * -------
 *  Hongxi Shi (mtk80137)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 06 2012 hongxi.shi
 * [MAUI_03195338] [RTC] String "exit safe mode" appears at the top corner when clear few characters entered by keypad
 * .
 *
 * 05 24 2012 hongxi.shi
 * [MAUI_03187622] [check in] MRE autostart and safe mode
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_SAFE_MODE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_SAFEMODE">

    <!-- System Resource Area -------------------------------------------------->

    <CACHEDATA type="byte" id="NVRAM_MMI_SAFE_MODE_FLAG">
        <DEFAULT_VALUE>[0x00]</DEFAULT_VALUE>
        <DESCRIPTION>Safe mode system abnormal reset flag</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_MMI_SAFE_MODE_TIME">
        <DEFAULT_VALUE>[0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF]</DEFAULT_VALUE>
        <DESCRIPTION>Safe mode system abnormal reset time</DESCRIPTION>
    </CACHEDATA>


    <!-- String Resource Area ------------------------------------------------->
    <STRING id="STR_ID_SAFE_MODE_EXIT"/>
    <STRING id="STR_ID_SAFE_MODE_HELP_TEXT"/>
    <STRING id="STR_ID_SAFE_MODE_RESTART"/>
    <STRING id="STR_ID_SAFE_MODE_DO_IT_LATER"/>
    
    <STRING id="STR_ID_SAFE_MODE_QUERY_CHECK"/>
    <STRING id="STR_ID_SAFE_MODE_QUERY_LAUNCH"/>
    <!-- Image Resource Area -------------------------------------------------->


    <!-- APP Images -->


    <!-- Event Area (Sender) -------------------------------------------------->


    <!-- Event Area (Receiver) ------------------------------------------------>

   // <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_safe_mode_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SETTING_LANGUAGE_CHANGED" proc="mmi_safe_mode_main_evt_hdlr"/>
    <SCREEN id="GRP_ID_SAFE_MODE_CONFIRM"/>
    <SCREEN id="SCR_ID_SAFE_MODE_CONFIRM"/>
</APP>

#endif /* defined(__MMI_SAFE_MODE__) */
