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
 *  IdleNotificationManager.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource ID for the idle notification manager.
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
 * 10 21 2013 lu.xiao
 * [MAUI_03463174] [Pluto Slim][MSZ] Pluto slim checkin to 11C for MSZ
 * .
 *
 * 12 25 2012 lu.xiao
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * .
 *
 * 11 23 2012 lu.xiao
 * [MAUI_03260501] [MSZ] Remove unused string in 11BW1232OF_SLIM_DEV
 * .Because Idle nmgr is still use, STR_ID_NMGR_CANCEL_ASK can not remove.
 *
 * 11 23 2012 lu.xiao
 * [MAUI_03260501] [MSZ] Remove unused string in 11BW1232OF_SLIM_DEV
 * .Check in to 11B.
 *
 * 04 11 2012 chuangjie.xia
 * [MAUI_03166257] Move Timer ID to Module Own Res File
 * .move timer id
 *
 * 01 06 2011 ch.ko
 * [MAUI_02858129] [Idle] Wrap string resource with compile option
 * Fix daily build error.
 *
 * 01 05 2011 ch.ko
 * [MAUI_02858129] [Idle] Wrap string resource with compile option
 * Check-in patch.
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
#include "CustResDef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_IDLE_NMGR">

    <!----- Include Area ------------------------------------------------------>
    <INCLUDE file="GlobalResDef.h"/>


    <!----- String Resource Area ---------------------------------------------->
#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
    <STRING id="STR_ID_NMGR_CANCEL_ASK"/>
#endif

#if 0
#if defined(__OP12__)
    <STRING id="STR_ID_NMGR_MISSED_CALL_SUFFIX"/>
    <STRING id="STR_ID_NMGR_MISSED_CALLS_SUFFIX"/>
    <STRING id="STR_ID_NMGR_NEW_MSG_SUFFIX"/>
    <STRING id="STR_ID_NMGR_NEW_MSGS_SUFFIX"/>
    <STRING id="STR_ID_NMGR_NEW_SMS_MSG_SUFFIX"/>
    <STRING id="STR_ID_NMGR_NEW_SMS_MSGS_SUFFIX"/>
    <STRING id="STR_ID_NMGR_NEW_MMS_MSG_SUFFIX"/>
    <STRING id="STR_ID_NMGR_NEW_MMS_MSGS_SUFFIX"/>
    <STRING id="STR_ID_NMGR_NEW_PUSH_MSG_SUFFIX"/>
    <STRING id="STR_ID_NMGR_NEW_PUSH_MSGS_SUFFIX"/>
    <STRING id="STR_ID_NMGR_NEW_VOICEMAIL_SUFFIX"/>
    <STRING id="STR_ID_NMGR_NEW_VOICEMAILS_SUFFIX"/>
    <STRING id="STR_ID_NMGR_NEW_EMAIL_SUFFIX"/>
    <STRING id="STR_ID_NMGR_NEW_EMAILS_SUFFIX"/>
#endif /* defined(__OP12__) */
#endif

    <!----- Image Resource Area ----------------------------------------------->


    <!----- Screen Resource Area ---------------------------------------------->
    <SCREEN id="SCR_ID_NMGR_DUMMY"/>
    <SCREEN id="SCR_ID_NMGR_NOTIFY"/>
    <SCREEN id="SCR_ID_NMGR_NOTIFY_ON_IDLE"/>


    <!----- Menu Resource Area ------------------------------------------------>

    <!----- Timer Resource Area ----------------------------------------------->
    <TIMER id = "IDLE_NMGR_GUARD_TIMER"/>

</APP>

