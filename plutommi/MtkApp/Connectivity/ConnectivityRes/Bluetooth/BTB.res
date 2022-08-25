/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  BTB.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the BTB resources.
 *
 * Author:
 * -------
 *  Renxiao Zeng(MTK71448)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 09 16 2014 renxiao.zeng
 * [MAUI_03515623] [Side effect][??][BT BOX][Music]No prompt tone pop up after reconnection with SP Samsung S3
 * patch back from SP2.
 *
 * 06 07 2014 renxiao.zeng
 * [MAUI_03495461] [BT Box] BTB Feature check in to 11C & 11CW1418SP2 from 11CW1412OF_BTBOX_DEV
 * fix bugs.
 *
 * 06 05 2014 renxiao.zeng
 * [MAUI_03495461] [BT Box] BTB Feature check in to 11C & 11CW1418SP2 from 11CW1412OF_BTBOX_DEV
 * fix led issues and connect bugs.
 *
 * 05 26 2014 renxiao.zeng
 * [MAUI_03495461] [BT Box] BTB Feature check in to 11C & 11CW1418MP & 11CW1418SP2 from 11CW1412OF_BTBOX_DEV
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"

#ifdef __MMI_BT_BTBOX_NOLCD__
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_BLUETOOTH">

    <!-----------------------------------------------------Event Resource Area Begin----------------------------------------------------->
    <EVENT id="EVT_ID_BTB_A2DP_CONNECTED" type="SENDER" />
    <EVENT id="EVT_ID_BTB_A2DP_DISCONNECTED" type="SENDER" />
    
    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_NORMAL_START" proc="btb_event_hdlr"/>
    <RECEIVER id="EVT_ID_BTB_CHANGE_VISIBILITY" proc="btb_event_hdlr" />
    <RECEIVER id="EVT_ID_BTB_CONNECT" proc="btb_event_hdlr" />
    <RECEIVER id="EVT_ID_BTB_DISCONNECT" proc="btb_event_hdlr" />
    <RECEIVER id="EVT_ID_BTB_RESET" proc="btb_event_hdlr" />
    #if 0
    //move to callback_mgr.res
    <RECEIVER id="EVT_ID_GPIO_LINEIN_PLUG_IN" proc="btb_event_hdlr" />
    <RECEIVER id="EVT_ID_GPIO_LINEIN_PLUG_OUT" proc="btb_event_hdlr" />
    #endif
    <!-----------------------------------------------------Event Resource Area End----------------------------------------------------->

    <!-----------------------------------------------------String Resource Area Begin----------------------------------------------------->

    <!-----------------------------------------------------String Resource Area End----------------------------------------------------->
    

    <AUDIO id="AUD_ID_BT_POWER_ON" desc="BT power on" path="BT_PowerOn.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\BT_PowerOn.mp3"</AUDIO>
    <AUDIO id="AUD_ID_BT_POWER_OFF" desc="BT power off" path="BT_PowerOff.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\BT_PowerOff.mp3"</AUDIO>
    <AUDIO id="AUD_ID_BT_CONNECTING" desc="BT connecting" path="BT_Conn.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\BT_Connecting.mp3"</AUDIO>
    <AUDIO id="AUD_ID_BT_CONNECTION_FAIL" desc="BT connection fail" path="BT_Conn_Fail.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\BT_Conn_Fail.mp3"</AUDIO>
    <AUDIO id="AUD_ID_BT_OPERATION_FAIL" desc="BT operation fail" path="BT_Opt_Fail.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\BT_Opt_Fail.mp3"</AUDIO>
    <AUDIO id="AUD_ID_BT_VISIBILITY_ON" desc="BT visibility on" path="Visibility_On.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\Visibility_On.mp3"</AUDIO>
    <AUDIO id="AUD_ID_BT_VISIBILITY_OFF" desc="BT visibility off" path="Visibility_Off.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\Visibility_Off.mp3"</AUDIO>
    <AUDIO id="AUD_ID_BT_CONNECTED" desc="BT connected" path="BT_Conn.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\BT_Conn.mp3"</AUDIO>
    <AUDIO id="AUD_ID_BT_DISCONNECTED" desc="BT disconnected" path="BT_Discon.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\BT_Discon.mp3"</AUDIO>

    <NOTIFY id="NOTIFY_ID_BT_POWER_ON" desc="BT power on" voice="AUD_ID_BT_POWER_ON" />
    <NOTIFY id="NOTIFY_ID_BT_POWER_OFF" desc="BT power off" voice="AUD_ID_BT_POWER_OFF" />
    <NOTIFY id="NOTIFY_ID_BT_CONNECTING" desc="BT connecting" led="INPUT_EVENT_LED_ID_9" voice="AUD_ID_BT_CONNECTING" />
    <NOTIFY id="NOTIFY_ID_BT_RESETTING" desc="BT resetting" led="INPUT_EVENT_LED_ID_7" />
    <NOTIFY id="NOTIFY_ID_BT_CONNECTION_FAIL" desc="BT connection fail" led="INPUT_EVENT_LED_ID_9" voice="AUD_ID_BT_CONNECTION_FAIL" />
    <NOTIFY id="NOTIFY_ID_BT_OPERATION_FAIL" desc="BT operation fail" led="INPUT_EVENT_LED_ID_9" voice="AUD_ID_BT_OPERATION_FAIL" />
    <NOTIFY id="NOTIFY_ID_BT_VISIBILITY_ON" desc="BT visibility on" voice="AUD_ID_BT_VISIBILITY_ON" />
    <NOTIFY id="NOTIFY_ID_BT_VISIBILITY_ON_LED" desc="BT visibility on led" led="INPUT_EVENT_LED_ID_16" />
    <NOTIFY id="NOTIFY_ID_BT_VISIBILITY_OFF" desc="BT visibility off" voice="AUD_ID_BT_VISIBILITY_OFF" />
    <NOTIFY id="NOTIFY_ID_BT_CONNECTED" desc="BT connected" led="INPUT_EVENT_LED_ID_2" voice="AUD_ID_BT_CONNECTED" />
    <NOTIFY id="NOTIFY_ID_BT_DISCONNECTED" desc="BT disconnected" led="INPUT_EVENT_LED_ID_9" voice="AUD_ID_BT_DISCONNECTED" />
    
    <NOTIFY id="NOTIFY_ID_BT_SINK_CONNECTED" desc="BT be connected" led="INPUT_EVENT_LED_ID_21" voice="AUD_ID_BT_CONNECTED" />
 	
</APP>

#endif  //__MMI_BT_BTBOX_NOLCD__

