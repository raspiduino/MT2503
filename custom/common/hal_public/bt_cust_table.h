/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

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
 *
 * Filename:
 * ---------
 * bt_cust_type.h
 *
 * Project:
 * --------
 *   BT Project
 *
 * Description:
 * ------------
 *   This file is used to customization bt host
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __BT_CUST_TABLE_H__
#define __BT_CUST_TABLE_H__

#include "kal_general_types.h"


#ifdef __BT_USE_CUST_DATA__
/*********************************************
*  bt_config item fromat sample:
*  {
*      [item name],
*      [item value],
*  }
*********************************************/

kal_uint16 custSupportServices[20] = {0};
kal_char custInqTxPwr[2] = {6, -128/* -128 as terminator */};
kal_uint8 custInqLength[2] = {4, 0};
#if 0
/* under construction !*/
#endif

const bt_config_item cust_config_table[] = {
    {
        "pageTimeout",
        (void*)0x3800,
    },
    {
        "connectionTimeout",
        (void*)0x6400,
    },
    {
        "InquiryScanWindow",
       (void*)0x0012,
    },
    {
        "inquiryScanInterval",
        (void*)0x1000,
    },
    {
        "pageScanWindow",
        (void*)0x0012,
    },
    {
        "pageScanInterval",
        (void*)0x0800,
    },
    {
        "setupSyncCmdRawData",
        (void*)0x6400,
    },
    {
        "createConnRoleSwitchReq",
        (void*)1,
    },
    {
        "inquiryLengthArray",
        (void*)0x6400,
    },
    {
        "pinPairingReqTimeoutActive",
        (void*)0x4500,
    },
    {
        "pinPairingReqTimeoutPassive",
        (void*)0x4500,
    },
    {
        "SSPPairingReqTimeoutActive",
        (void*)0x4500,
    },
    {
        "SSPPairingReqTimeoutPassive",
        (void*)0x4500,
    },
    {
        "SCOPktType",
        (void*)0x03C7,
    },
    {
        "eSCOPktType",
        (void*)0x0388,
    },
    {
        "RoleSwitchRetryCount",
        (void*)1,
    },
    {
        "GapInquiryShowAddress",
        (void*)1,
    },
    {
        "AutoAcceptReqFromPairedDevice",
        (void*)1,
    },
    {
        "DelayAuthentication",
        (void*)0,
    },
    {
        "DisableInBandRingtone",
        (void*)1,
    },
    {
        "CreateConnectionRetryNoEventReported",
        (void*)0,
    },
    {
        "SSPSupport",
        (void*)1,
    },
    /*********************************************
    *  range : 0~4 (default: 1)
    *  0     : Display only
    *  1     : Display YesNo
    *  2     : Keyboard only
    *  3     : No input no output
    *  4     : Keyboard Display
    **********************************************/ 
    {
        "LocalIOCapability",
#ifdef __IOT__        
        (void*)3,
#else
        (void*)1,
#endif        
    },    
    /*********************************************
    *  range : 0~2 (default: 1)
    *  0     : No cache
    *  1     : Use cache when SDP query return "No Service"
    *  2     : Use cache first
    **********************************************/    
    {
        "HFPSDPCache",
        (void*)1,
    },
    /*********************************************
    *  range : 0~3 (default: 3)
    *  Bit 0 : HSP(AG) support
    *  Bit 1 : HFP(AG) support
    **********************************************/      
    {
        "HFPSupportMask",
        (void*)3,
    },    
    /*********************************************
    *  range : 0~1 (default: 0)
    *  0     : disable
    *  1     : enable
    **********************************************/  
    {
        "HFPVoiceRecognition",
        (void*)0,
    },      
    {   
         "30HSSupported",
#ifdef __BT_3_0_HS__
        (void*)1,
#else
        (void*)0,
#endif
    },
    {
        "LESupport",
#ifdef __BT_4_0_BLE__
        (void*)1,
#else
        (void*)0,
#endif
    },
    {
        "DevSupportServices",
        (void*)custSupportServices,
    },
    {
        "SDPDelayTimeout",
        (void*)500,  /* ms */
    },
    {
        "InquiryTxPwr",
        (void*)custInqTxPwr,
    },
    {
        "InquiryLength",
        (void*)custInqLength,
    },
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif     
    {
         "NoRoleSwitch",
         (void*)0,
    },
    {
         "KeepAwakeTime",    /* ms */
         (void*)5000,
    },
    {
         "LEInitiateInterval",    /* slot (0x625) */
        #ifdef __USE_CUST_INT_WIN__
         (void*)0x50,
        #else
         (void*)0x48,
        #endif
    },
    {
         "LEInitiateWindow",    /* slot (0x625) */
        #ifdef __USE_CUST_INT_WIN__
         (void*)0x12,
        #else
         (void*)0x30,
        #endif
    },
    {
         "LEScanInterval",    /* slot (0x625) */
        #ifdef __USE_CUST_INT_WIN__
         (void*)0x50,
        #else
         (void*)0x140,
        #endif
    },
    {
         "LEScanWindow",    /* slot (0x625) */
        #ifdef __USE_CUST_INT_WIN__
         (void*)0x12,
        #else
         (void*)0x140,
        #endif
    },
    /*********************************************
    *  Minimum value for the connection event interval.
    *  This shall be less than or equal to LEConnIntervalMax.    
    *  range : 0x0006 ~ 0x0C80 (default: 0x0100)
    *  Time = N * 1.25 msec
    *  Time Range : 7.5(msec) ~ 4(seconds)
    **********************************************/     
    {
         "LEConnIntervalMin",    
         (void*)0x000a,
    },
    /*********************************************
    *  Maximum value for the connection event interval.
    *  This shall be greater than or equal to LEConnIntervalMin.      
    *  range : 0x0006 ~ 0x0C80 (default: 0x0200)
    *  Time = N * 1.25 msec
    *  Time Range : 7.5(msec) ~ 4(seconds)
    **********************************************/     
    {
         "LEConnIntervalMax",    
         (void*)0x000f,
    },
    /*********************************************
    *  Slave latency for the connection in number of 
    *  connection events.      
    *  range : 0x0000 ~ 0x01F3 (default: 0x0000)
    **********************************************/    
    {
         "LEConnLatency",    
         (void*)0x0000,
    },
    /*********************************************
    *  Supervision timeout for the LE link.     
    *  range : 0x000A ~ 0x0C80 (default: 0x0500)
    *  Time = N * 10 msec
    *  Time Range : 100(msec) ~ 32(seconds)    
    **********************************************/    
    {
         "LESupervisionTO",    
         (void*)0x0500,
    },   
    {
		 "L2capLowPriorityMaxAcceptTimeoutMs",
		 (void *)500,
    },    
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
    {
        "ManufactureID",
        (void*)0x0046,  /* 0x0046 MediaTek Inc. */
    },
    {
        "ProductID",
        (void*)0x0802,  /* Vendor specific */
    },
    /*********************************************
    *  Anti_Lost Feature Settings.     
    *  threshold :  -120 ~ 0 dBm(default: -80)
    *  interval =  msec  
    **********************************************/       
    {
        "RssiThreshold",
        (void*)-80,  /* threshold for rssi change */
    },
    {
        "RssiInterval",
        (void*)2000,  /* Rssi report interval */
    },    
};


/*********************************************
*  bt_dev_config item fromat sample:
*  {
*      [item name],
*      [config table],
*  }
*********************************************/
kal_uint16 services[] = {0x111E, 0x1108, 0};
bt_dev_config_item item1[] = {
    {
         "DevSupportServices",
         (void*)services,
    },            
    {0} /* terminator */
};
bt_dev_config_item item2[] = {
    {
         "SDPDelayTimeout",
         (void*)0,
    },            
    {0} /* terminator */
};


bt_dev_config cust_dev_config[] = {
    /* MTK defined IOT list */
    {
         "i.Tech Clip R35",
         item1,
    },    
    {
         "PCM",
         item2,
    },    
};
#endif
#endif /* __BT_CUST_TABLE_H__ */
