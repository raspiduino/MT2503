/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  ScrSaver.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource ID for the screen saver.
 *
 * Author:
 * -------
 *  Cheng-Hung Ko (mtk01585)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 08 2011 weilun.liu
 * [MAUI_02952144] [SLIM][UE change] use specific scrSaver/Backlight time value instead of user setting
 * UE change: remove backlight/scrSaver setting and launch scrSaver when backlight dimming
 *
 * 03 22 2011 weilun.liu
 * [MAUI_02899518] [Idle] add screen saver compile option
 * add compile option __MMI_SCREEN_SAVER__
 *
 * 01 18 2011 weilun.liu
 * [MAUI_02862898] [Idle] register pre touch event
 * register pre touch event.
 *
 * 10 27 2010 yan.liang
 * [MAUI_02634102] [FRM] Framework Callback Manager Revise
 * Fix spelling mistake
 *
 * 09 30 2010 weilun.liu
 * [MAUI_02824995] [Idle, Scrsaver, ScrLocker, Eons, NwName] callback manager register revise
 * .
 *
 * Jun 22 2010 mtk01585
 * [MAUI_02567833] [Idle] Revise codes by using XML resources
 * Check-in XML resources.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_SCREEN_SAVER__)
#include "CustResDef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_SCR_SAVER">

    <!----- Include Area ------------------------------------------------------>
    <INCLUDE file="GlobalResDef.h"/>


    <!----- String Resource Area ---------------------------------------------->


    <!----- Image Resource Area ----------------------------------------------->


    <!----- Screen Resource Area ---------------------------------------------->
    <SCREEN id="GRP_ID_SSV_MAIN"/>
    <SCREEN id="SCR_ID_SSV_MAIN"/>


    <!----- Menu Resource Area ------------------------------------------------>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->    
#ifdef __MMI_CLAMSHELL__
    <RECEIVER id="EVT_ID_GPIO_CLAM_OPEN" proc="mmi_ssv_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_ssv_main_evt_hdlr"/>
#endif
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="mmi_ssv_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_ssv_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_ssv_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_GROUP_ENTER" proc="mmi_ssv_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_GROUP_EXIT" proc="mmi_ssv_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SCR_LOCKER_LOCKED" proc="mmi_ssv_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_PRE_TOUCH_EVT_ROUTING" proc="mmi_ssv_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_BACKLIGHT_DIMMING" proc="mmi_ssv_main_evt_hdlr"/>
    
    /*
     * This event is emitted when the screen saver is on.
     *
     * Structure: mmi_scr_saver_enter_evt_struct
     */
    <EVENT id="EVT_ID_SCR_SAVER_ENTER" type="SENDER"/>

    /*
     * This event is emitted when the screen saver is terminated.
     *
     * Structure: mmi_scr_saver_exit_evt_struct
     */
    <EVENT id="EVT_ID_SCR_SAVER_EXIT" type="SENDER"/>

    <RECEIVER id="EVT_ID_SCR_SAVER_ENTER" proc="mmi_ssv_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SCR_SAVER_EXIT" proc="mmi_ssv_main_evt_hdlr"/>

    <EVENT id="EVT_ID_SSV_OBJ_CLOSE_REQ"/>
    <EVENT id="EVT_ID_SSV_OBJ_CLOSED_IND"/>

</APP>
#endif /* defined(__MMI_SCREEN_SAVER__) */
