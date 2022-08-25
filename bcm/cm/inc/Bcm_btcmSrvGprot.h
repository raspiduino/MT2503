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
 * BtcmSrvGprot.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for external module to use BT CM related apis
 *
 * Author:
 * -------
 * -------
 * 
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BT_CM_SRV_GPROT_H
#define BT_CM_SRV_GPROT_H

// RHR: add
#include "kal_public_api.h"
#include "kal_general_types.h"
// RHR: add

#include "app_ltlcom.h"
#include "bluetooth_gap_struct.h"
/*#include "bt_dm_struct.h"*/
#include "bluetooth_struct.h"

#include "bcm_struct.h"

#include "custom_bcm_btcm_config.h"
#include "..\..\..\bcm\adp\inc\bcmadp.h"
#ifdef __cplusplus
extern "C"
{
#endif

//#if (defined(__MMI_BT_SUPPORT__) &&  (defined(__BT_VER_21__) ||  defined(__BT_VER_30__)))
    #if (!defined(__MMI_BT_SIMPLE_PAIR__) && !defined(__BT_DISABLE_SSP_SUPPORT__))
    #define __MMI_BT_SIMPLE_PAIR__
    #endif
//#endif

#if !defined(__BT_BOND_CANCEL__) &&!defined(__MMI_BT_SLIM__)
#define __BT_BOND_CANCEL__
#endif

//#ifdef __MMI_BT_SUPPORT__
#define SRV_BT_CM_MASK_DM_RESET           0x00000008

/* bluetooth ucs2 name length */
#define SRV_BT_CM_BD_UCS2_NAME_LEN                 (18 + 1)

/* bluetooth device name UCS2 buffer length */
#define SRV_BT_CM_BD_NAME_UCS2_LEN                 (((SRV_BT_CM_BD_FNAME_LEN - 2) / 3) * ENCODING_LENGTH + ENCODING_LENGTH)

/* max searched device in result */
#ifdef __MMI_BT_SLIM__
#define SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST    10
#else
#define SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST    15
#endif
/* max profile number */
#define SRV_BT_CM_NUM_OF_PROFILE_UUID              34

/* max connection number */
#if defined(__PLUTO_MMI_PACKAGE__) && defined(__LOW_COST_SUPPORT_COMMON__) // SLIM:memory reduction
#ifdef __MMI_BT_DIALER_SUPPORT__
#define SRV_BT_CM_MAX_CONNECTION                   12
#else
#define SRV_BT_CM_MAX_CONNECTION                   6

#endif
#else
#define SRV_BT_CM_MAX_CONNECTION                   30
#endif  // __LOW_COST_SUPPORT_COMMON__

/* <GROUP Bluetooth Profile Service UUID>
   SPP Profile Service UUID */
#define SRV_BT_CM_SPP_PROFILE_UUID                 (0x1101)
/* <GROUP Bluetooth Profile Service UUID>
   LAP Profile Service UUID */
#define SRV_BT_CM_LAP_PROFILE_UUID                 (0x1102)
/* <GROUP Bluetooth Profile Service UUID>
   DUN Profile Service UUID */
#define SRV_BT_CM_DUN_PROFILE_UUID                 (0x1103)
/* <GROUP Bluetooth Profile Service UUID>
   OBEX IR MC SYNC Profile Service UUID */
#define SRV_BT_CM_OBEX_IR_MC_SYNC_SERVICE_UUID     (0x1104)
/* <GROUP Bluetooth Profile Service UUID>
   OBEX Object push Profile Service UUID */
#define SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID    (0x1105)
/* <GROUP Bluetooth Profile Service UUID>
   OBEX file transfer Profile Service UUID */
#define SRV_BT_CM_OBEX_FILE_TRANSFER_UUID          (0x1106)
/* <GROUP Bluetooth Profile Service UUID>
   Headset Profile Service UUID */
#define SRV_BT_CM_HS_PROFILE_UUID                  (0x1108)
/* <GROUP Bluetooth Profile Service UUID>
   CTP Profile Service UUID */
#define SRV_BT_CM_CTP_PROFILE_UUID                 (0x1109)
/* <GROUP Bluetooth Profile Service UUID>
   Audio source Profile Service UUID */
#define SRV_BT_CM_AUDIO_SOURCE_UUID                (0x110A)
/* <GROUP Bluetooth Profile Service UUID>
   Audio sink Profile Service UUID */
#define SRV_BT_CM_AUDIO_SINK_UUID                  (0x110B)
/* <GROUP Bluetooth Profile Service UUID>
   AVRCT Profile Service UUID */
#define SRV_BT_CM_AV_REMOTE_CONTROL_TARGET_UUID    (0x110C)
/* <GROUP Bluetooth Profile Service UUID>
   A2DP Profile Service UUID */
#define SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID      (0x110D)
/* <GROUP Bluetooth Profile Service UUID>
   AVRCP Profile Service UUID */
#define SRV_BT_CM_AV_REMOTE_CONTROL_UUID           (0x110E)
/* <GROUP Bluetooth Profile Service UUID>
   ICP Profile Service UUID */
#define SRV_BT_CM_ICP_PROFILE_UUID                 (0x1110)
/* <GROUP Bluetooth Profile Service UUID>
   FAX Profile Service UUID */
#define SRV_BT_CM_FAX_PROFILE_UUID                 (0x1111)
/* <GROUP Bluetooth Profile Service UUID>
   Headset AG Profile Service UUID */
#define SRV_BT_CM_HEADSET_AG_SERVICE_UUID          (0x1112)
/* <GROUP Bluetooth Profile Service UUID>
   PAN PANU Profile Service UUID */
#define SRV_BT_CM_PAN_PANU_PROFILE_UUID            (0x1115)
/* <GROUP Bluetooth Profile Service UUID>
   PAN NAP Profile Service UUID */
#define SRV_BT_CM_PAN_NAP_PROFILE_UUID             (0x1116)
/* <GROUP Bluetooth Profile Service UUID>
   PAN GN Profile Service UUID */
#define SRV_BT_CM_PAN_GN_PROFILE_UUID              (0x1117)
/* <GROUP Bluetooth Profile Service UUID>
   Direct printing Profile Service UUID */
#define SRV_BT_CM_DIRECT_PRINTING                  (0x1118)
/* <GROUP Bluetooth Profile Service UUID>
   OBEX imaging Profile Service UUID */
#define SRV_BT_CM_OBEX_IMAGING_UUID                (0x111A)
/* <GROUP Bluetooth Profile Service UUID>
   OBEX imaging responder Profile Service UUID */
#define SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID      (0x111B)
/* <GROUP Bluetooth Profile Service UUID>
   Handsfree Profile Service UUID */
#define SRV_BT_CM_HF_PROFILE_UUID                  (0x111E)
/* <GROUP Bluetooth Profile Service UUID>
   HFG Profile Service UUID */
#define SRV_BT_CM_HFG_PROFILE_UUID                 (0x111F)
/* <GROUP Bluetooth Profile Service UUID>
   Basic printing Profile Service UUID */
#define SRV_BT_CM_BASIC_PRINTING                   (0x1122)
/* <GROUP Bluetooth Profile Service UUID>
   HID Profile Service UUID */
#define SRV_BT_CM_HID_PROFILE_UUID                 (0x1124)
/* <GROUP Bluetooth Profile Service UUID>
   SIM Access Profile Service UUID */
#define SRV_BT_CM_SIM_ACCESS_PROFILE_UUID          (0x112D)
/* <GROUP Bluetooth Profile Service UUID>
   Phonebook asscess client Profile Service UUID */
#define SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID     (0x112E)
/* <GROUP Bluetooth Profile Service UUID>
   Phonebook access  Profile Service UUID */
#define SRV_BT_CM_OBEX_PBA_PROFILE_UUID            (0x112F)
/* <GROUP Bluetooth Profile Service UUID>
   BPP Profile Service UUID */
#define SRV_BT_CM_OBEX_BPPS_PROFILE_UUID           (0x1118)
/* <GROUP Bluetooth Profile Service UUID>
   SyncML Profile Service UUID */
#define SRV_BT_CM_MESSAGE_ACCESS_PROFILE_UUID      (0X1134)

#define SRV_BT_CM_MESSAGE_ACCESS_PROFILE_SERVER_UUID      (0X1132)

#define SRV_BT_CM_MESSAGE_NOTIF_SERVER_UUID      (0x1133)
/*
Message access service profile for message
synchronizing from sever
*/
#define SRV_BT_CM_SYNCML_DEV_PROFILE_UUID          (0x1119) 
/* <GROUP Bluetooth Profile Service UUID>
   Object push client Profile Service UUID */
#define SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID     (0xfffd)
/* <GROUP Bluetooth Profile Service UUID>
   OBEX file transfer client Profile Service UUID */
#define SRV_BT_CM_OBEX_FILE_TRANSFER_CLIENT_UUID   (0xfffe)
/* <GROUP Bluetooth Profile Service UUID>
   MAX Profile Service UUID */
#define SRV_BT_CM_MAX_PROFILE_UUID                 (0xffff)

/* class of device bit mask */

/* <GROUP Major Service Mask>
postioning major service mask */
#define SRV_BT_POSTIONING_MAJOR_SERVICE_MASK                            (0x010000)
/* <GROUP Major Service Mask>
networking major service mask */
#define SRV_BT_NETWORKING_MAJOR_SERVICE_MASK                            (0x020000)
/* <GROUP Major Service Mask>
rendering major service mask */
#define SRV_BT_RENDERING_MAJOR_SERVICE_MASK                                (0x040000)
/* <GROUP Major Service Mask>
capturing major service mask */
#define SRV_BT_CAPTURING_MAJOR_SERVICE_MASK                                (0x080000)
/* <GROUP Major Service Mask>
object transfer major service mask */
#define SRV_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK                        (0x100000)
/* <GROUP Major Service Mask>
audio major service mask */
#define SRV_BT_AUDIO_MAJOR_SERVICE_MASK                                    (0x200000)
/* <GROUP Major Service Mask>
telephony major service mask */
#define SRV_BT_TELEPHONY_MAJOR_SERVICE_MASK                                (0x400000)
/* <GROUP Major Service Mask>
information major service mask */
#define SRV_BT_INFORMATION_MAJOR_SERVICE_MASK                            (0x800000)


/* <GROUP Major Device Mask>
miscellaneous major device mask */
#define SRV_BT_MISCELLANEOUS_MAJOR_DEVICE_MASK                            (0x000000)
/* <GROUP Major Device Mask>
computer major device mask */
#define SRV_BT_COMPUTER_MAJOR_DEVICE_MASK                                (0x000100)
/* <GROUP Major Device Mask>
phone major device mask */
#define SRV_BT_PHONE_MAJOR_DEVICE_MASK                                    (0x000200)
/* <GROUP Major Device Mask>
LAN major device mask */
#define SRV_BT_LAN_MAJOR_DEVICE_MASK                                    (0x000300)
/* <GROUP Major Device Mask>
AV major device mask */
#define SRV_BT_AV_MAJOR_DEVICE_MASK                                        (0x000400)
/* <GROUP Major Device Mask>
peripheral major device mask */
#define SRV_BT_PERIPHERAL_MAJOR_DEVICE_MASK                                (0x000500)
/* <GROUP Major Device Mask>
imaging major device mask */
#define SRV_BT_IMAGING_MAJOR_DEVICE_MASK                                (0x000600)
/* <GROUP Major Device Mask>
unclassified major device mask */
#define SRV_BT_UNCLASSIFIED_MAJOR_DEVICE_MASK                            (0x001F00)

/* <GROUP Minor Device    Mask under computer major class>
desktop workstation minor device mask */
#define SRV_BT_DESKTOP_WORKSTATION_MINOR_DEVICE_MASK                    (0x000004)
/* <GROUP Minor Device    Mask under computer major class>
server class computer minor device mask */
#define SRV_BT_SERVER_CLASS_COMPUTER_MINOR_DEVICE_MASK                    (0x000008)
/* <GROUP Minor Device    Mask under computer major class>
laptop minor device mask */
#define SRV_BT_LAPTOP_MINOR_DEVICE_MASK                                    (0x00000C)
/* <GROUP Minor Device    Mask under computer major class>
handhelp PC PDA minor device mask */
#define SRV_BT_HANDHELP_PC_PDA_MINOR_DEVICE_MASK                        (0x000010)
/* <GROUP Minor Device    Mask under computer major class>
palm sized PC PDA minor device mask */
#define SRV_BT_PALM_SIZED_PC_PDA_MINOR_DEVICE_MASK                        (0x000014)
/* <GROUP Minor Device    Mask under computer major class>
unclassified computer minor device mask */
#define    SRV_BT_UNCLASSIFIED_COMPUTER_MINOR_DEVICE_MASK                    (0x000000)


/* <GROUP Minor Device    Mask under phone major class>
cellular minor device mask */
#define SRV_BT_CELLULAR_MINOR_DEVICE_MASK                                (0x000004)
/* <GROUP Minor Device    Mask under phone major class>
cordless minor device mask */
#define SRV_BT_CORDLESS_MINOR_DEVICE_MASK                                (0x000008)
/* <GROUP Minor Device    Mask under phone major class>
smart phone minor device mask */
#define SRV_BT_SMART_PHONE_MINOR_DEVICE_MASK                            (0x00000C)
/* <GROUP Minor Device    Mask under phone major class>
wired modem or voice gateway minor device mask */
#define SRV_BT_WIRED_MODEM_OR_VOICE_GATEWAY_MINOR_DEVICE_MASK            (0x000010)    
/* <GROUP Minor Device    Mask under phone major class>
unclassified phone minor device mask */
#define    SRV_BT_UNCLASSIFIED_PHONE_MINOR_DEVICE_MASK                        (0x000000)


/* <GROUP Minor Device    Mask under audio/video major class>
uncategorised AV minor device mask */
#define    SRV_BT_UNCATEGORISED_AV_MINOR_DEVICE_MASK                        (0x000000)
/* <GROUP Minor Device    Mask under audio/video major class>
wearable headset AV minor device mask */
#define SRV_BT_WEARABLE_HEADSET_AV_MINOR_DEVICE_CLASS                    (0x000004)
/* <GROUP Minor Device    Mask under audio/video major class>
handsfree AV minor device mask */
#define SRV_BT_HANDSFREE_AV_MINOR_DEVICE_CLASS                            (0x000008)
/* <GROUP Minor Device    Mask under audio/video major class>
microphone AV minor device mask */
#define SRV_BT_MICROPHONE_AV_MINOR_DEVICE_CLASS                            (0x000010)
/* <GROUP Minor Device    Mask under audio/video major class>
loudspeaker AV minor device mask */
#define SRV_BT_LOUDSPEAKER_AV_MINOR_DEVICE_CLASS                        (0x000014)
/* <GROUP Minor Device    Mask under audio/video major class>
headphone AV minor device mask */
#define SRV_BT_HEADPHONES_AV_MINOR_DEVICE_CLASS                            (0x000018)
/* <GROUP Minor Device    Mask under audio/video major class>
portable audio AV minor device mask */
#define SRV_BT_PORTABLE_AUDIO_AV_MINOR_DEVICE_CLASS                        (0x00001C)
/* <GROUP Minor Device    Mask under audio/video major class>
car audio AV minor device mask */
#define SRV_BT_CAR_AUDIO_AV_MINOR_DEVICE_CLASS                            (0x000020)
/* <GROUP Minor Device    Mask under audio/video major class>
settop box AV minor device mask */
#define SRV_BT_SETTOP_BOX_AV_MINOR_DEVICE_CLASS                            (0x000024)
/* <GROUP Minor Device    Mask under audio/video major class>
hifi audio AV minor device mask */
#define SRV_BT_HIFI_AUDIO_AV_MINOR_DEVICE_CLASS                            (0x000028)
/* <GROUP Minor Device    Mask under audio/video major class>
VCR AV minor device mask */
#define SRV_BT_VCR_AV_MINOR_DEVICE_CLASS                                (0x00002C)
/* <GROUP Minor Device    Mask under audio/video major class>
video camera AV minor device mask */
#define SRV_BT_VIDEO_CAMERA_AV_MINOR_DEVICE_CLASS                        (0x000030)
/* <GROUP Minor Device    Mask under audio/video major class>
camcorder AV minor device mask */
#define SRV_BT_CAMCORDER_AV_MINOR_DEVICE_CLASS                            (0x000034)
/* <GROUP Minor Device    Mask under audio/video major class>
video monitor AV minor device mask */
#define SRV_BT_VIDEO_MONITOR_AV_MINOR_DEVICE_CLASS                        (0x000038)
/* <GROUP Minor Device    Mask under audio/video major class>
video display and loudspeaker AV minor device mask */
#define SRV_BT_VIDEO_DISPLAY_AND_LOUDSPEAKER_AV_MINOR_DEVICE_CLASS        (0x00003C)
/* <GROUP Minor Device    Mask under audio/video major class>
video conferencing AV minor device mask */
#define SRV_BT_VIDEO_CONFERENCING_AV_MINOR_DEVICE_CLASS                    (0x000040)
/* <GROUP Minor Device    Mask under audio/video major class>
game toy AV minor device mask */
#define SRV_BT_GAME_TOY_AV_MINOR_DEVICE_CLASS                            (0x000048)

/* <GROUP Minor Device    Mask under LAN major class>
fully available minor device mask */
#define SRV_BT_FULLY_AVAILABLE_MINOR_DEVICE_MASK                        (0x000000) 
/* <GROUP Minor Device    Mask under LAN major class>
one to seventeen percent minor device mask */
#define SRV_BT_ONE_TO_SEVENTEEN_PERCENT_MINOR_DEVICE_MASK                (0x000020)
/* <GROUP Minor Device    Mask under LAN major class>
seventeen to thirtythree percent minor device mask */
#define SRV_BT_SEVENTEEN_TO_THIRTYTHREE_PERCENT_MINOR_DEVICE_MASK        (0x000040)
/* <GROUP Minor Device    Mask under LAN major class>
thirtythree to fifty percent minor device mask */
#define SRV_BT_THIRTYTHREE_TO_FIFTY_PERCENT_MINOR_DEVICE_MASK            (0x000060)
/* <GROUP Minor Device    Mask under LAN major class>
fifty to sixtyseven percent minor device mask */
#define SRV_BT_FIFTY_TO_SIXTYSEVEN_PERCENT_MINOR_DEVICE_MASK            (0x000080)
/* <GROUP Minor Device    Mask under LAN major class>
sixtyseven to eightythree percent minor device mask */
#define SRV_BT_SIXTYSEVEN_TO_EIGHTYTHREE_PERCENT_MINOR_DEVICE_MASK        (0x0000A0)
/* <GROUP Minor Device    Mask under LAN major class>
eightythree to ninetynine percent minor device mask */
#define SRV_BT_EIGHTYTHREE_TO_NINETYNINE_PERCENT_MINOR_DEVICE_MASK        (0x0000C0)
/* <GROUP Minor Device    Mask under LAN major class>
no service available minor device mask */
#define SRV_BT_NO_SERVICE_AVAILABLE_MINOR_DEVICE_MASK                    (0x0000E0)
/* <GROUP Minor Device    Mask under LAN major class>
unclassified LAN minor device mask */
#define    SRV_BT_UNCLASSIFIED_LAN_MINOR_DEVICE_MASK                        (0x000000)

/* <GROUP Minor Device Mask under Peripheral major Class (Keyboard/pointing device filed)>
joystick peripheral minor device mask */
#define SRV_BT_JOYSTICK_PERIPHERALS_MINOR_DEVICE_CLASS                    (0x000004)
/* <GROUP Minor Device Mask under Peripheral major Class (Keyboard/pointing device filed)>
gamepad device peripheral minor device mask */
#define SRV_BT_GAMEPAD_DEVICE_PERIPHERAL_MINOR_DEVICE_CLASS                (0x000008)
/* <GROUP Minor Device Mask under Peripheral major Class (Keyboard/pointing device filed)>
remote control device peripheral minor device mask */
#define SRV_BT_REMOTE_CONTRO_DEVICE_PERIPHERAL_MINOR_DEVICE_CLASS        (0x00000C)
/* <GROUP Minor Device Mask under Peripheral major Class (Keyboard/pointing device filed)>
sensing device peripheral minor device mask */
#define SRV_BT_SENSING_DEVICE_PERIPHERAL_MINOR_DEVICE_CLASS                (0x000010)
/* <GROUP Minor Device Mask under Peripheral major Class (Keyboard/pointing device filed)>
digitizer tablet peripheral minor device mask */
#define SRV_BT_DIGITIZER_TABLET_PERIPHERAL_MINOR_DEVICE_CLASS            (0x000014)
/* <GROUP Minor Device Mask under Peripheral major Class (Keyboard/pointing device filed)>
card reader peripheral minor device mask */
#define SRV_BT_CARD_READER_PERIPHERAL_MINOR_DEVICE_CLASS                (0x000018)

/* <GROUP Minor Device Mask under Imaging major Class (printing, scanner, caramera...)>
display imaging minor device mask */
#define SRV_BT_DISPLAY_IMAGING_MINOR_DEVICE_CLASS                        (0x000010)
/* <GROUP Minor Device Mask under Imaging major Class (printing, scanner, caramera...)>
camera imaging minor device mask */
#define SRV_BT_CAMERA_IMAGING_MINOR_DEVICE_CLASS                        (0x000020)
/* <GROUP Minor Device Mask under Imaging major Class (printing, scanner, caramera...)>
scanner imaging minor device mask */
#define SRV_BT_SCANNER_IMAGING_MINOR_DEVICE_CLASS                        (0x000040)
/* <GROUP Minor Device Mask under Imaging major Class (printing, scanner, caramera...)>
printer imaging minor device mask */
#define SRV_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS                        (0x000080)



//#define SRV_BT_CM_SEC_ON                        SRV_BT_CM_SEC_MODE3_LINK
//#define SRV_BT_CM_SEC_OFF                       SRV_BT_CM_SEC_MODE1_NON_SECURE

#define SRV_BT_CM_MAX_INSTANCE_NUM (20)

#define  MMI_BT_ASSERT(a)  ASSERT(a)
#ifdef __MMI_A2DP_SUPPORT__
#define __MMI_BT_CM_CONNECT_EXCLUDE_A2DP__
#endif
/* the security mode */
typedef enum
{
    SRV_BT_CM_SEC_MODE0_OFF,                    /* security mode off */
    SRV_BT_CM_SEC_MODE1_NON_SECURE,             /* security mode non secure */
    SRV_BT_CM_SEC_MODE2_SERVICE,                /* security mode service level */
    SRV_BT_CM_SEC_MODE3_LINK,                   /* security mode link level */
    SRV_BT_CM_SEC_MODE4_SIMPLE,                 /* security mode simple */
    SRV_BT_CM_SEC_TOTAL                         /* security mode total */
} srv_bt_cm_security_mode_enum;

/* operation type enum */
typedef enum
{
    SRV_BT_CM_OPER_TYPE_POWER_ON,               /* power on */
    SRV_BT_CM_OPER_TYPE_RESTORE,                /* restore state */
    SRV_BT_CM_OPER_TYPE_SET_HOST_DEV_NAME,      /* setting host device name */
    SRV_BT_CM_OPER_TYPE_SET_DISCOVERABLE_MODE,  /* set discoverable mode */
    SRV_BT_CM_OPER_TYPE_TOTAL                   /* last enum for operation type */
} srv_bt_cm_oper_type_enum;

/* authorize type enum */
typedef enum
{
    SRV_BT_CM_AUTHORIZE_ALWAYS_ASK,             /* always ask */
    SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT,         /* always connect */
    SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT,          /* always reject */
    SRV_BT_CM_AUTHORIZE_TOTAL                   /* last enum for authorize type */
} srv_bt_cm_authorize_type;

/* visibility type enum */
typedef enum
{
    SRV_BT_CM_VISIBILITY_ON = 1, /* visibility on, can be discovered by other bt device */

//#ifdef __MMI_BT_TEMP_VISIBILITY__

    SRV_BT_CM_VISIBILITY_TEMPORARY_ON, /* visibility temporary on, can be discovered by other bt device for some time */

//#endif  /* __MMI_BT_TEMP_VISIBILITY__ */

    SRV_BT_CM_VISIBILITY_OFF,   /* visibility off, can not be discovered by other bt device */
    SRV_BT_CM_VISIBILITY_TOTAL  /* last enum for visibility type */
} srv_bt_cm_visibility_type;

/* result type from BT BM enum */
typedef enum
{
    SRV_BT_CM_BTBM_SUCCESS   = BTBM_ADP_SUCCESS,   /* success */
    SRV_BT_CM_BTBM_FAILED    = BTBM_ADP_FAILED,    /* failed */
    SRV_BT_CM_BTBM_BUSY      = BTBM_ADP_FAIL_BUSY,      /* busy */
    SRV_BT_CM_BTBM_NOT_ALLOW = BTBM_ADP_FAIL_NOT_ALLOW, /* not allow */
    SRV_BT_CM_EXCEED_MAX_PAIRED_DEVICE_NUM,        /* exceed max device num */
    SRV_BT_CM_BTBM_DEVICE_FULL                     /* device full */
} srv_bt_cm_btbm_result_enum;

/* BT CM current state enum */
typedef enum
{
    SRV_BT_CM_STATE_INIT_ON,                           /* 0 */
    SRV_BT_CM_STATE_DEACTIVATING,                      /* 1 */
    SRV_BT_CM_STATE_ACTIVATING,                        /* 2 */
    SRV_BT_CM_STATE_ACTIVATING_WRITE_SCAN_ENABLE,      /* 3 */
    SRV_BT_CM_STATE_ACTIVATING_WRITE_SCAN_DISABLE,     /* 4 */
    SRV_BT_CM_STATE_IDLE,                              /* 5 */
    SRV_BT_CM_STATE_INQUIRING,                         /* 6 */
    SRV_BT_CM_STATE_INQUIR_RES_IND,                    /* 7 */
    SRV_BT_CM_STATE_INQUIR_CANCELLING,                 /* 8 */
    SRV_BT_CM_STATE_BONDING,                           /* 9 */
    SRV_BT_CM_STATE_PAIRING,                           /* 10 */
    SRV_BT_CM_STATE_SDC_SEARCHING,                     /* 11 */
    SRV_BT_CM_STATE_CONNECTING,                        /* 12 */
    SRV_BT_CM_STATE_DEBONDING,                         /* 13 */
    SRV_BT_CM_STATE_DELETING,                          /* 14 */
    SRV_BT_CM_STATE_DELETING_ALL,                      /* 15 */
    SRV_BT_CM_STATE_DISCONNECTING,                     /* 16 */
    SRV_BT_CM_STATE_PASSKEY_IND,                       /* 17 */
    SRV_BT_CM_STATE_PASSKEY_RES,                       /* 18 */
    SRV_BT_CM_STATE_NUMERIC_CONFIRM,                   /* 19 */
    SRV_BT_CM_STATE_NUMERIC_CONFIRM_RSP,               /* 20 */
    SRV_BT_CM_STATE_PASSKEY_NOTIFY,                    /* 21 */
    SRV_BT_CM_STATE_KEYPRESS_NOTIFY_CANCEL,            /* 22 */
    SRV_BT_CM_STATE_BLOCK_DEVICE_LINK,                 /* 23 */
    SRV_BT_CM_STATE_UNBLOCK_DEVICE_LINK,               /* 24 */
    SRV_BT_CM_STATE_CONNECT_ACCEPT_CONFIRM_IND,        /* 25 */
    SRV_BT_CM_STATE_SDC_REFRESHING,                    /* 26 */
    SRV_BT_CM_STATE_VISIBILITY_SETTING,                /* 27 */
    SRV_BT_CM_STATE_DISCOVERABLE_MODE_SETTING,         /* 28 */
    SRV_BT_CM_STATE_HOST_NAME_SETTING,                 /* 29 */
    SRV_BT_CM_STATE_AUTHENTICATION_SETTING,            /* 30 */
    SRV_BT_CM_STATE_RELEASE_ALL_CONNECTION,            /* 31 */
    SRV_BT_CM_STATE_RELEASE_DEV_CONNECTION,            /* 32 */
    SRV_BT_CM_STATE_SETTING_LIMIT_VISIBILITY,          /* 33 */
    SRV_BT_CM_STATE_RESETTING_LIMIT_VISIBILITY,        /* 34 */
    SRV_BT_CM_STATE_READING_REMOTE_DEV_NAME,           /* 35 */
    SRV_BT_CM_STATE_ACTIVATING_PROFILES,               /* 36 */

 #ifdef __BT_BOND_CANCEL__
    SRV_BT_CM_STATE_BONDING_CANCEL,                    /* 37 */
 #endif

    SRV_BT_CM_STATE_TOTAL                              /* 38 */
} srv_bt_cm_state_enum;

/* BT CM connection type enum */
typedef enum
{
    SRV_BT_CM_NO_CONNECTION,          /* 0 */
    SRV_BT_CM_HFP_CONNECTION,         /* 1 */
    SRV_BT_CM_HSP_CONNECTION,         /* 2 */
    SRV_BT_CM_SPP_CONNECTION,         /* 3 */
    SRV_BT_CM_DUN_CONNECTION,         /* 4 */
    SRV_BT_CM_FTP_CONNECTION,         /* 5 */
    SRV_BT_CM_OPP_CONNECTION,         /* 6 */
    SRV_BT_CM_A2DP_CONNECTION,        /* 7 */
    SRV_BT_CM_A2DP_SINK_CONNECTION,
    SRV_BT_CM_AVRCP_CONNECTION,       /* 8 */
    SRV_BT_CM_AVRCP_CT_CONNECTION,    /* 9 */
    SRV_BT_CM_BPP_CONNECTION,         /* 10 */
    SRV_BT_CM_SIMAP_CONNECTION,       /* 11 */
    SRV_BT_CM_FAX_CONNECTION,         /* 12 */
    SRV_BT_CM_HID_CONNECTION,         /* 13 */
    SRV_BT_CM_BIP_CONNECTION,         /* 14 */
    SRV_BT_CM_BIPC_CONNECTION,        /* 15 */
    SRV_BT_CM_PBAP_CONNECTION,        /* 16 */
    SRV_BT_CM_PBAPC_CONNECTION,       /*17*/
    SRV_BT_CM_FTPC_CONNECTION,        /* 17 */
    SRV_BT_CM_OPPC_CONNECTION,        /* 18 */
    SRV_BT_CM_SYNCML_CONNECTION,      /* 19 */
    SRV_BT_CM_MAPC_CONNECTION,        /* 20 */
    SRV_BT_CM_HF_CONNECTION,
    SRV_BT_CM_CONNECTION_TOTAL        /* 20 */
} srv_bt_cm_connection_type;


/* BT CM result code enum */
typedef enum
{
    SRV_BT_CM_RESULT_SUCCESS                = 0,  /* success */
    SRV_BT_CM_RESULT_FAILED                 = -1, /* failed */
    SRV_BT_CM_RESULT_INVALID_HANDLE         = -2, /* invalid instance handler */
    SRV_BT_CM_RESULT_DEV_NOT_FOUND          = -3, /* device not found */
    SRV_BT_CM_RESULT_DEV_LIST_FULL          = -4, /* device list full */
    SRV_BT_CM_RESULT_NO_CONNECTION          = -5, /* there is no connection */
    SRV_BT_CM_RESULT_ONE_HEADSET_CONNECTED  = -6, /* there is one headset connected */
    SRV_BT_CM_RESULT_ONE_A2DP_CONNECTED     = -7, /* there is one A2DP connection */
    SRV_BT_CM_RESULT_SAME_HEADSET_CONNECTED = -8, /* the same headset is connected */
    SRV_BT_CM_RESULT_PROFILE_NOT_SUPPORT    = -9, /* the profile is not supported */
    SRV_BT_CM_RESULT_TOTAL      /* last enum for BT CM result code */
} srv_bt_cm_result_codes_enum;


/* the power status of BT */
typedef enum
{
    SRV_BT_CM_POWER_ON,                 /* power on */
    SRV_BT_CM_POWER_OFF,                /* power off */
    SRV_BT_CM_POWER_SWITCHING_ON,       /* power switching on */
    SRV_BT_CM_POWER_SWITCHING_OFF,      /* power switching off */  
    SRV_BT_CM_POWER_TOTAL               /* last enum for BT power status */
} srv_bt_cm_power_status_enum;

/* the device property */
typedef enum
{
    SRV_BT_CM_DEV_PROPERTY_BLOCK,       /* blocked */
    SRV_BT_CM_DEV_PROPERTY_PAIR,        /* paired */
    SRV_BT_CM_DEV_PROPERTY_AUTHORIZE,   /* authorized */
    SRV_BT_CM_DEV_PROPERTY_TOTAL        /* last enum for device property */
} srv_bt_cm_dev_property_enum;

/* Bluetooth device type */
typedef enum
{
    SRV_BT_CM_DISCOVERED_DEV,   /* discovered device */
    SRV_BT_CM_RECENT_USED_DEV,  /* recent used device */
    SRV_BT_CM_PAIRED_DEV,       /* paired device */
    SRV_BT_CM_ALL_DEV,          /* all device */
    SRV_BT_CM_DEV_TYPE_TOTAL
} srv_bt_cm_dev_type_enum;

/* FuncPtr is a pointer to a func returns void */
typedef void (*profile_activate)(void);
typedef void (*profile_deactivate)(void);
typedef void (*profile_disconnect)(U32 conn_id);


/* supported profile callback table structure */
typedef struct
{
    U32                profile_id;   /* profile UUID */
    profile_activate   activater;    /* activater, CM wil call it to activate profile during bt power on procedure */
    profile_deactivate deactivater;  /* deactivater, CM will call it to deactivate profile during bt power off procedure */
    profile_disconnect disconnector; /* disconnector, CM will call it it to disconnect the profile */
} srv_bt_cm_profile_struct;

/* BT CM connection structure */
typedef struct
{
    U32 index_of_dev_list;               /* Connection identification */
    U32 conn_id;                         /* connection id */
    U32 profile_id;                      /* profile UUID, refer to the UUID macro defination */
    MMI_BOOL audio_on;                   /* audio on status */
    MMI_BOOL active;                     /* active or not */
} srv_bt_cm_connect_struct;


/***************************************************************************** 
 * Extern Global Function
 *****************************************************************************/

/*****************************************************************************
 * <GROUP Ext_other>
 * FUNCTION
 *  srv_bt_cm_init
 * DESCRIPTION
 *  This function is to init CM service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_init(void);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_profile_register
 * DESCRIPTION
 *  this function is to register profile info to CM service
 * PARAMETERS
 *  profile_info_p:    [IN]    profile information, refer to srv_bt_cm_profile_struct
 *  
 * RETURNS
 *  MMI_TRUE : success to register profile information to CM service
 *  MMI_FALSE: failed to register profile information to CM service
 ******************************************************************************/
extern MMI_BOOL srv_bt_cm_profile_register(const srv_bt_cm_profile_struct* profile_info_p);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_profile_deregister
 * DESCRIPTION
 *  this function is to deregister profile, CM will clear the profiles information from registered information table
 * PARAMETERS
 *  profile_id:    [IN]    profile UUID, refer to the UUID macro defination
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_bt_cm_profile_deregister(U32 profile_id);


/*****************************************************************************
 * <GROUP Int_local_dev_set> 
 * FUNCTION
 *  srv_bt_cm_switch_on
 * DESCRIPTION
 *  This function is to switch on bt chip,
 *  and it will also help to activate bt profiles registered to CM service
 * PARAMETERS
 *  void
 * RETURNS
 *  S32: refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
extern S32 srv_bt_cm_switch_on(void);

/*****************************************************************************
 * <GROUP Int_local_dev_set> 
 * FUNCTION
 *  srv_bt_cm_set_btdialor_mode
 * DESCRIPTION
 *  This function is to set the cm in bt dialor mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_set_btdialor_mode(MMI_BOOL val);

/*****************************************************************************
 * <GROUP Int_local_dev_set> 
 * FUNCTION
 *  srv_bt_cm_get_btdialor_mode
 * DESCRIPTION
 *  This function will return if the btdialor mode is on or off.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/	
extern MMI_BOOL srv_bt_cm_get_btdialor_mode(void);
/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Int_local_dev_set> 
 * FUNCTION
 *  srv_bt_cm_antenna_off
 * DESCRIPTION
 *  This function is to process antenna off request and invoke srv_bt_cm_antenna_off_req_hdler
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_antenna_off(void);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Int_local_dev_set> 
 * FUNCTION
 *  srv_bt_cm_power_on_activate_profile
 * DESCRIPTION
 *  This function is to activate BT profiles, invoke from MMI
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_activate_profile(void);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * <GROUP Int_local_dev_set> 
 * FUNCTION
 *  srv_bt_cm_switch_off
 * DESCRIPTION
 *  This function is to switch off bt, it will also help to deactivate all the activated bt profiles,
 *  if there is live connection(s), it will disconnect the live connection(s) firstly
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_switch_off(void);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Int_other> 
 * FUNCTION
 *  srv_bt_cm_recover_panic_req
 * DESCRIPTION
 *  This function is to process recover panic request and send MSG_ID_BT_MMI_RESET_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL: return MMI_TRUE
 *****************************************************************************/
extern MMI_BOOL srv_bt_cm_recover_panic_req(void);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * <GROUP Ext_callback>
 * FUNCTION
 *  srv_bt_cm_activate_cnf_hdler
 * DESCRIPTION
 *  during bt power on procedure, CM will call each profile's activator
 *  (registered to CM through srv_bt_cm_profile_register()) one by one after power bt chip,.
 *  This function is to notify CM the profile has completed activate procedure,
 *  then CM can begin to call next activator until all activator has been called
 *  
 * PARAMETERS
 *  profile_id:    [IN]    profile UUID, refer to the UUID macro defination
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_activate_cnf_hdler(U32 profile_id);


/*****************************************************************************
 * <GROUP Ext_callback>
 * FUNCTION
 *  srv_bt_cm_deactivate_cnf_hdler
 * DESCRIPTION
 *  during bt power off procedure, CM will call each profile's deactivator
 *  (registered to CM through srv_bt_cm_profile_register()),
 *  This function is to notify CM the profile has completed deactivate procedure,
 *  then CM can begin to power off bt chip
 *  
 * PARAMETERS
 *  profile_id:    [IN]    profile UUID, refer to the UUID macro defination
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_deactivate_cnf_hdler(U32 profile_id);


/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_get_power_status
 * DESCRIPTION
 *  This function is to get current bt power status
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_power_status_enum   
 *    SRV_BT_CM_POWER_ON means BT power is ON
 *    SRV_BT_CM_POWER_OFF means BT power is OFF
 *    SRV_BT_CM_POWER_SWITCHING_ON means switching power to be ON now
 *    SRV_BT_CM_POWER_SWITCHING_OFF means switching power to be OFF now 
 *****************************************************************************/
extern srv_bt_cm_power_status_enum srv_bt_cm_get_power_status(void);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_is_activated
 * DESCRIPTION
 *  This function is to check if bt is activated
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : bluetooth is activated
 *  MMI_FALSE : bluetooth is not activated
 *****************************************************************************/
extern MMI_BOOL srv_bt_cm_is_activated(void);
/* DOM-NOT_FOR_SDK-END */


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_set_visibility
 * DESCRIPTION
 *  this function is to set bluetooth visibility
 * PARAMETERS
 *  type:    [IN]    visibility type
 *  
 * RETURNS
 *  S32: refer to srv_bt_cm_result_codes_enum
 ******************************************************************************/
extern S32 srv_bt_cm_set_visibility(srv_bt_cm_visibility_type type);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_get_visibility
 * DESCRIPTION
 *  this function is to get bluetooth visibility
 * PARAMETERS
 *  void
 * RETURNS
 *  S32: refer to srv_bt_cm_visibility_type
 ******************************************************************************/
extern S32 srv_bt_cm_get_visibility(void);


#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_set_limit_vis
 * DESCRIPTION
 *  This function is to set limited discoverable mode
 * PARAMETERS
 *  vis:    MMI_TRUE means to set limit discovery mode, 
 *          MMI_FALSE means to reset limit discovery mode
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 srv_bt_cm_set_limit_vis(MMI_BOOL vis);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_is_limit_vis
 * DESCRIPTION
 *  This function is to check the limited visibility setting of bluetooth
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : the device is limited visible
 *  MMI_FALSE : the device is not limited visible
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_limit_vis(void);
/* DOM-NOT_FOR_SDK-END */
#endif /*__MMI_BT_LIMITED_DISCOVERY_SUPPORT__*/


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_set_discoverable_mode
 * DESCRIPTION
 *  This function is to set discoverable mode and invoke srv_bt_cm_write_scanenable_mode_req_hdler
 * PARAMETERS
 *  discoverable_mode:    [IN]    discoverable mode value
 * RETURNS
 *  MMI_BOOL    MMI_TRUE  : set discoverable mode successfully
 *              MMI_FALSE : otherwise
 *****************************************************************************/
extern S32 srv_bt_cm_set_discoverable_mode(U32 discoverable_mode);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * <GROUP Int_local_dev_set> 
 * FUNCTION
 *  srv_bt_cm_set_auth
 * DESCRIPTION
 *  This function is to process setting authentication request and invoke srv_bt_cm_security_level_req_hdler
 * PARAMETERS
 *  auth:    [IN]    MMI_TRUE:enable authentication, MMI_FALSE:disable authentication
 * RETURNS
 *  S32: refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
extern S32 srv_bt_cm_set_authentication(MMI_BOOL auth);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_is_auth
 * DESCRIPTION
 *  This function is to check the authentication setting
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : the authentication is on
 *  MMI_FALSE : the authentication is off
 *****************************************************************************/
extern MMI_BOOL srv_bt_cm_is_authentication(void);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_get_host_dev_security_level
 * DESCRIPTION
 *  This function is to get host device security level
 * PARAMETERS
 *  void
 * RETURNS
 *  U8      host device security level, refer to srv_bt_cm_security_mode_enum
 *****************************************************************************/
extern U8 srv_bt_cm_get_host_dev_security_level(void);


/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_search
 * DESCRIPTION 
 *  This function is to process inquiry request and invoke srv_bt_cm_discovery_req_hdler,
 *  each time finding a device, it will notify notifier
 *  (set to CM by srv_bt_cm_set_notify()) with event SRV_BT_CM_EVENT_INQUIRY_IND ,
 *  after search procedure completed, it will notify notifier SRV_BT_CM_EVENT_INQUIRY_COMPLETE.
 * PARAMETERS
 *  max_response  :    [IN]    max repsone number of device
 *  timeout       :    [IN]    inquiry timeout timer
 *  cod           :    [IN]    class of device
 *  name_discovery:    [IN]    name discovery 
 * RETURNS
 *  S32 :    refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
extern S32 srv_bt_cm_search(U8 max_response, U16 timeout, U32 cod, MMI_BOOL name_discovery);


/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_search_abort
 * DESCRIPTION
 *  This function is to process inquiry cancel request
 *  and invoke srv_bt_cm_cancel_discovery_req_hdler,
 *  notifier will receive SRV_BT_CM_EVENT_INQUIRY_COMPLETE after cancel inquiry procedure is completed
 * PARAMETERS
 *  void
 * RETURNS
 *  S32: refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
 extern S32 srv_bt_cm_search_abort(void);


/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_bond
 * DESCRIPTION
 *  This function is to initiate bond procedure to remote bt device,
 *  it will notify notifier SRV_BT_CM_EVENT_BOND_RES after bond completed
 * PARAMETERS
 *  index:    [IN]    discovered device index
 * RETURNS
 *  S32 : refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
extern S32 srv_bt_cm_bond(U32 index);


#ifdef __BT_BOND_CANCEL__
/* DOM-NOT_FOR_SDK-BEGIN */
/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_bond_cancel
 * DESCRIPTION
 *  this function is to cancel bond process
 * PARAMETERS
 *  void
 * RETURNS
 *  S32: refer to srv_bt_cm_result_codes_enum
 ******************************************************************************/
S32 srv_bt_cm_bond_cancel(void);
/* DOM-NOT_FOR_SDK-END */
#endif


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_debond
 * DESCRIPTION
 *  this function is to debond a device
 * PARAMETERS
 *  index:    [IN]    device index
 *  
 * RETURNS
 *  S32 : refer to srv_bt_cm_result_codes_enum
 ******************************************************************************/
extern S32 srv_bt_cm_debond(U32 index);


/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_send_passkey
 * DESCRIPTION
 *  This function is to process pair request and send passkey
 * PARAMETERS
 *  dev_addr   :    [IN]    device address
 *  dev_passkey:    [IN]    passkey
 *  result     :    [IN]    MMI_TURE: valid passkey, MMI_FALSE:reject this pair
 * RETURNS
 *  S32 : refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
extern S32 srv_bt_cm_send_passkey(srv_bt_cm_bt_addr* dev_addr, U8* dev_passkey, MMI_BOOL result);


#ifdef __MMI_BT_SIMPLE_PAIR__
/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_security_numeric_confirm
 * DESCRIPTION
 *  This function is to reply the numeric confirmation
 * PARAMETERS
 *  dev_addr:    [IN]    device address      
 *  accept  :    [IN]    MMI_TRUE means numeric confirmation result is correct
 *                       MMI_FALSE means numeric confirmation result is incorrect
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_security_numeric_confirm(srv_bt_cm_bt_addr* dev_addr, MMI_BOOL accept);


/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_security_keypress_notify_cancel
 * DESCRIPTION
 *  This function is to cancel the passkey keypress notify
 * PARAMETERS
 *  dev_addr:    [IN]    device address      
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_security_keypress_notify_cancel(srv_bt_cm_bt_addr* dev_addr);
#endif /* __MMI_BT_SIMPLE_PAIR__ */


/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_set_host_dev_name
 * DESCRIPTION
 *  This function is to set host device name, it will notify notifier SRV_BT_CM_EVENT_SET_NAME
 *  after set host device name procedure is completed.
 * PARAMETERS
 *  name :    [IN]    host device name, UTF-8 coding
 * RETURNS
 *  S32  : refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
extern S32 srv_bt_cm_set_host_dev_name(U8* name);


/*****************************************************************************
 * <GROUP Int_local_dev_set> 
 * FUNCTION
 *  srv_bt_cm_get_host_dev_info
 * DESCRIPTION
 *  This function is to get host device information
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_dev_struct*   :   the host device information
 *****************************************************************************/
extern srv_bt_cm_dev_struct* srv_bt_cm_get_host_dev_info(void);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_start_conn
 * DESCRIPTION
 *  This function is to process connect request
 * PARAMETERS
 *  in_out    :    [IN]    MMI_TRUE: incoming connection, MMI_FALSE: outgong connection
 *  profile_id:    [IN]    profile UUID, refer to the UUID macro defination
 *  dev_addr  :    [IN]    device address
 *  dev_name  :    [IN]    device name, UTF-8 coding
 *  
 * RETURNS
 *  S32 : if it is larger than 0, it means it is allowed to
 *  initiate a connection from host device currently, and the return value is a valid conn_id,
 *  otherwise, it is not allowed to start a connection currently.
 ******************************************************************************/
extern S32 srv_bt_cm_start_conn(MMI_BOOL in_out, U32 profile_id, srv_bt_cm_bt_addr* dev_addr, CHAR* dev_name);


/*****************************************************************************
 * <GROUP Ext_callback>
 * FUNCTION
 *  srv_bt_cm_stop_conn
 * DESCRIPTION
 *  This function is to handle disconnection indication
 * PARAMETERS
 *  conn_id:     [IN]     conneciton id, returned by srv_bt_cm_start_conn()
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_stop_conn(U32 conn_id);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_connect_ind
 * DESCRIPTION
 *  this function is to handle connect indication, if profile is set up successfully,
 *  after call srv_bt_cm_start_conn(), it should call this API to notify CM.
 * PARAMETERS
 *  conn_id:    [IN]    connection ID, returned by srv_bt_cm_start_conn()
 *  
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_bt_cm_connect_ind(U32 conn_id);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_callback>
 * FUNCTION
 *  srv_bt_cm_sco_connect_ind_hdler
 * DESCRIPTION
 *  This function is to handle SCO connect indication
 * PARAMETERS
 *  conn_id:    [IN]    connection id, returned by srv_bt_cm_start_conn()
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_sco_connect_ind_hdler(U32 conn_id);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_callback>
 * FUNCTION
 *  srv_bt_cm_sco_connect_cnf_hdler
 * DESCRIPTION
 *  This function is to handle SCO connent confirm
 * PARAMETERS
 *  result     :    [IN]    connect result
 *  conn_id    :    [IN]    connection id, returned by srv_bt_cm_start_conn()
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_sco_connect_cnf_hdler(U8 result, U32 conn_id);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_callback>
 * FUNCTION
 *  srv_bt_cm_sco_disconnect_ind_hdler
 * DESCRIPTION
 *  This function is to SCO disconnection indication
 * PARAMETERS
 *  connection_id:    [IN]    connection id
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_sco_disconnect_ind_hdler(U32 connection_id);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_get_sco_status
 * DESCRIPTION
 *  this function is to get sco status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 ******************************************************************************/
extern MMI_BOOL srv_bt_cm_get_sco_status(void);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * <GROUP Int_conn_mgr>
 * FUNCTION
 *  srv_bt_cm_release_dev_conn
 * DESCRIPTION
 *  This function is to process release device connection request,
 *  it will release the designated device's all live conneciton(s).
 * PARAMETERS
 *  dev_addr:    [IN]    the device address pointer
 * RETURNS
 *  S32: refer to srv_bt_cm_result_codes_enum       
 *****************************************************************************/
extern S32 srv_bt_cm_release_dev_conn(srv_bt_cm_bt_addr* dev_addr);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_release_profile
 * DESCRIPTION
 *  this function is to release the designated device's live connection of profile_id,
 *  after the procedure is completed, it will notify notifier SRV_BT_CM_EVENT_DISCONNECT_IND
 * PARAMETERS
 *  profile_id:    [IN]    profile ID, refer to the UUID macro defination
 *  
 * RETURNS
 *  S32 :refer to srv_bt_cm_result_codes_enum
 ******************************************************************************/
extern S32 srv_bt_cm_release_profile(srv_bt_cm_bt_addr* dev_addr, U32 profile_id);


/*****************************************************************************
 * <GROUP Int_conn_mgr>
 * FUNCTION
 *  srv_bt_cm_release_all_conn
 * DESCRIPTION
 *  This function is to process release the designated device's all live connection,
 *  after the procedure is completed, it will notify the notifier SRV_BT_CM_EVENT_RELEASE_ALL_CONN.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 : refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
extern S32 srv_bt_cm_release_all_conn(void);


#if defined(__MMI_BT_AUTHORIZE__)
/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_unblock
 * DESCRIPTION
 *  This function is to unblock the specific device
 * PARAMETERS
 *  dev_addr:    [IN]    device address      
 * RETURNS
 *  S32 : refer to srv_bt_cm_result_codes_enum    
 *****************************************************************************/
extern S32 srv_bt_cm_unblock(srv_bt_cm_bt_addr* dev_addr);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
* <GROUP Int_dev_mgr>
* FUNCTION
*  srv_bt_cm_set_authorize
* DESCRIPTION
*   This function is to set the authorize setting of a certain device
* PARAMETERS
*  dev_addr      :    [IN]    device address
*  authorize_type:    [IN]    authorize_type: refer to srv_bt_cm_authorize_type
* RETURNS
*  S32 : refer to srv_bt_cm_result_codes_enum
*****************************************************************************/
extern S32 srv_bt_cm_set_authorize(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_authorize_type authorize_type);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_authorize_type
 * DESCRIPTION
 *  this function will return the designated device's authorized type
 * PARAMETERS
 *  dev_addr:    [IN]    const device address pointer
 *  
 * RETURNS
 *  srv_bt_cm_authorize_type
 ******************************************************************************/
extern srv_bt_cm_authorize_type srv_bt_cm_get_authorize(const srv_bt_cm_bt_addr* dev_addr);
#endif /* (__MMI_BT_AUTHORIZE__) */

/* DOM-NOT_FOR_SDK-BEGIN */
#ifndef __EMPTY_MMI__
#if MMI_MAX_SIM_NUM > 1
extern mmi_sim_enum srv_bt_cm_get_prefer_sim(const srv_bt_cm_bt_addr *device);
extern void srv_bt_cm_set_prefer_sim(const srv_bt_cm_bt_addr *device, mmi_sim_enum sim);
extern mmi_sim_enum srv_bt_cm_get_binding_sim(const srv_bt_cm_bt_addr *dev_addr);
#endif
#endif /* __EMPTY_MMI__ */
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_refresh_service_list
 * DESCRIPTION
 *  This function is to process refresh service list request,
 *  it will notify application through event SRV_BT_CM_EVENT_REFRESH_PROFILE.
 * PARAMETERS
 *  dev_addr:    [IN]    device address
 * RETURNS
 *  S32 : refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
extern S32 srv_bt_cm_refresh_service_list(srv_bt_cm_bt_addr* dev_addr);


/*****************************************************************************
 * <GROUP Int_conn_mgr>
 * FUNCTION
 *  srv_bt_cm_get_existed_conn_num
 * DESCRIPTION
 *  This function is to get existed connection number
 * PARAMETERS
 *  void
 * RETURNS
 *  U8    :    existed connection number
 *****************************************************************************/
extern U8 srv_bt_cm_get_existed_conn_num(void);


/*****************************************************************************
 * <GROUP Int_conn_mgr>
 * FUNCTION
 *  srv_bt_cm_get_existed_conn_info
 * DESCRIPTION
 *  This function is to get existed connection info
 * PARAMETERS
 *  index:    [IN]    existed connection index
 * RETURNS
 *  srv_bt_cm_connect_struct* : existed connection info pointer
 *****************************************************************************/
srv_bt_cm_connect_struct* srv_bt_cm_get_existed_conn_info(U16 index);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_paired_dev_setting>
 * FUNCTION
 *  srv_bt_cm_is_headset_connected
 * DESCRIPTION
 *  This function is to check if headset is connected
 * PARAMETERS
 *  index_of_paried_list:    [IN]    the device index of the headset
 * RETURNS
 *  MMI_TRUE  : headset is connected
 *  MMI_FALSE : headset is not connected
 *****************************************************************************/
extern MMI_BOOL srv_bt_cm_is_headset_connected(const srv_bt_cm_bt_addr* dev_addr);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_is_profile_connected
 * DESCRIPTION
 *  This function is to check if a profile is connected
 * PARAMETERS
 *  conn_type:    [IN]    to check if conn_type is connected, conn_type is defind in srv_bt_cm_connection_type 
 * RETURNS
 *  MMI_TRUE  : the profile is connected
 *  MMI_FALSE : the profile is not connected
 *****************************************************************************/
extern MMI_BOOL srv_bt_cm_is_profile_connected(srv_bt_cm_connection_type conn_type);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_is_dev_conn_active
 * DESCRIPTION
 *  This function is to check if certain device is connected
 * PARAMETERS
 *  dev_addr  :    [IN]    device address  
 * RETURNS
 *  MMI_TRUE  : the device is connected
 *  MMI_FASLE : the device is not connected
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_dev_conn_active(srv_bt_cm_bt_addr* dev_addr);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_is_audio_path_to_headset
 * DESCRIPTION
 *  This function is to check if the audio path is set to headset
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : the audio path is set to headphone
 *  MMI_FALSE : the audio path is leave in phone
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_audio_path_to_headset(void);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_is_incall_aud_swap2bt
 * DESCRIPTION
 *  This function is to is incall and audio path is swap to bluetooth device
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : the audio path is swap to bluetooth device
 *  MMI_FALSE : the audio path is not swap to bluetooth device
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_incall_aud_swap2bt(void);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_is_audio_link_on
 * DESCRIPTION
 *  This function is to if headset audio link is connected
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : headset audio link is connected
 *  MMI_FALSE : headset audio link is not connected
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_audio_link_on(void);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_paired_dev_setting> 
 * FUNCTION
 *  srv_bt_cm_check_dev_profile_support_status
 * DESCRIPTION
 *  This function is to check if a service is support or not on a certain device
 * PARAMETERS
 *  addr      :    [IN]    address of the device
 *  service_id:    [IN]    the service to find
 * RETURNS
 *  MMI_TRUE  : the service is supported
 *  MMI_FALSE : the service is not supported
 *****************************************************************************/
extern MMI_BOOL srv_bt_cm_check_dev_profile_support_status(srv_bt_cm_bt_addr* dev_addr, U32 service_id);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_cm_is_simap_activate
 * DESCRIPTION
 *  This function is to check if SIMAP is activated
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : SIMAP is activated
 *  MMI_FALSE : SIMAP is not activated
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_simap_activate(void);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_paired_dev_setting>
 * FUNCTION
 *  srv_bt_cm_set_dev_cod
 * DESCRIPTION
 *  This function is to set device cod and write into nvram
 * PARAMETERS
 *  srv_bt_cm_bt_addr:    [IN]    device address
 *  cod              :    [IN]    class of device
 * RETURNS
 *  S32: refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
extern S32 srv_bt_cm_set_dev_cod(srv_bt_cm_bt_addr* dev_addr, U32 cod);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_paired_dev_setting>
 * FUNCTION
 *  srv_bt_cm_get_dev_cod
 * DESCRIPTION
 *  This function is to get device cod
 * PARAMETERS
 *  dev_addr:    [IN]    device address
 * RETURNS
 *  U32 :         class of device
 *****************************************************************************/
extern U32 srv_bt_cm_get_dev_cod(srv_bt_cm_bt_addr* dev_addr);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_get_searched_dev_num
 * DESCRIPTION
 *  This function is to get discovered device number
 * PARAMETERS
 *  void
 * RETURNS
 *  U8          discovered device number
 *****************************************************************************/
extern U8 srv_bt_cm_get_searched_dev_num(void);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_get_searched_dev_info
 * DESCRIPTION
 *  This function is to get discovered device info
 * PARAMETERS
 *  index:     [IN]    the index of discovered device
 * RETURNS
 *  srv_bt_cm_dev_struct* :      the device info structure pointer
 *****************************************************************************/
extern srv_bt_cm_dev_struct* srv_bt_cm_get_searched_dev_info(U16 index);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_get_paired_dev_num
 * DESCRIPTION
 *  This function is to get paired device number
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 : paired device number
 *****************************************************************************/
extern U8 srv_bt_cm_get_paired_dev_num(void);
/* DOM-NOT_FOR_SDK-END */


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_get_dev_num
 * DESCRIPTION
 *  this function is to get device number according to device type
 * PARAMETERS
 *  dev_type:    [IN]    refer to srv_bt_cm_dev_type_enum 
 *  
 * RETURNS
 *  U32 : device nuber of designated device type
 ******************************************************************************/
extern U32 srv_bt_cm_get_dev_num(srv_bt_cm_dev_type_enum dev_type);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_get_paired_dev_info
 * DESCRIPTION
 *  This function is to get paired device information
 * PARAMETERS
 *  index:    [IN]    index or paired device  
 * RETURNS
 *  srv_bt_cm_dev_struct*:   device information structure pointer
 *****************************************************************************/
extern srv_bt_cm_dev_struct* srv_bt_cm_get_paired_dev_info(U16 index);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_get_dev_info
 * DESCRIPTION
 *  this function will return the device information from paird device list and searched device list according to address,
 *  if can't find the device, it will return NULL
 * PARAMETERS
 *  dev_addr:    [IN]    BT device address
 *  
 * RETURNS
 *  srv_bt_cm_dev_struct* : device information structure pointer
 ******************************************************************************/
extern const srv_bt_cm_dev_struct* srv_bt_cm_get_dev_info(srv_bt_cm_bt_addr* dev_addr);
/* DOM-NOT_FOR_SDK-END */


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_set_dev_name
 * DESCRIPTION
 *  this function is to set paired device name
 * PARAMETERS
 *  dev_addr:    [IN]    BT device address
 *  name_p  :    [IN]    BT device name, UTF-8 encoding
 *  
 * RETURNS
 *  S32 : refer to srv_bt_cm_result_codes_enum
 ******************************************************************************/
extern S32 srv_bt_cm_set_dev_name(srv_bt_cm_bt_addr* dev_addr, U8* name_p);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_paired_dev_setting>
 * FUNCTION
 *  srv_bt_cm_get_dev_name
 * DESCRIPTION
 *  This function is to get the device UTF8 name
 * PARAMETERS
 *  dev_addr    :    [IN]     bluetooth address
 *  max_name_len:    [IN]     allowed max length of name_p
 *  name_p      :    [OUT]    name buffer pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_get_dev_name(srv_bt_cm_bt_addr* dev_addr, U32 max_name_len, U8* name_p);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/****************************************************************************** 
 * <GROUP Ext_paired_dev_setting>
 * FUNCTION
 *  srv_bt_cm_get_dev_ucs2_name
 * DESCRIPTION
 *  this function is to get the device's unicode name
 * PARAMETERS
 *  dev_addr    :    [IN]    bluetooth address
 *  max_name_len:    [IN]    allowed max length of name_p
 *  name_p      :    [IN]    name buffer pointer
 * RETURNS
 *  void
 ******************************************************************************/
extern void srv_bt_cm_get_dev_ucs2_name(const srv_bt_cm_bt_addr* dev_addr, U32 max_name_len, WCHAR* name_p);
/* DOM-NOT_FOR_SDK-END */


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_read_remote_dev_name
 * DESCRIPTION
 *  this function is to read the remote device name again,
 *  it will notify notifier SRV_BT_CM_EVENT_READ_REMOTE_DEV_NAME after procedure is completed
 * PARAMETERS
 *  dev_addr:    [IN]    device address
 *  
 * RETURNS
 *  S32 : refer to srv_bt_cm_result_codes_enum
 ******************************************************************************/
extern S32 srv_bt_cm_read_remote_dev_name(srv_bt_cm_bt_addr* dev_addr);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_get_dev_index
 * DESCRIPTION
 *  this function is to get device index in corresponding device list
 *  according to device type
 * PARAMETERS
 *  dev_addr:    [IN]    device address
 *  dev_type:    [IN]    device type
 *  
 * RETURNS
 *  if succeed to find the device, return index in corresponding device list
 *  if failed to find the device, return 0xFFFFFFFF
 ******************************************************************************/
extern U32 srv_bt_cm_get_dev_index(const srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_dev_type_enum dev_type);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_get_dev_info_by_addr
 * DESCRIPTION
 *  this function is to get the device information througth device address
 *  according to the device type
 * PARAMETERS
 *  dev_addr:    [IN]    device address
 *  dev_type:    [IN]    device type
 *  
 * RETURNS
 *  if succeed to find the device, return its information
 *  if failed to find the device, return NULL
 ******************************************************************************/
extern const srv_bt_cm_dev_struct* srv_bt_cm_get_dev_info_by_addr(
    const srv_bt_cm_bt_addr* dev_addr,
    srv_bt_cm_dev_type_enum dev_type);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_get_dev_info_by_index
 * DESCRIPTION
 *  this function is to get device info 
 * PARAMETERS
 *  index   :    [IN]    device index
 *  dev_type:    [IN]    device type
 *  
 * RETURNS
 *  if succeed to find the device, return its information
 *  if failed to find the device, return NULL
 ******************************************************************************/
extern const srv_bt_cm_dev_struct* srv_bt_cm_get_dev_info_by_index(U32 index, srv_bt_cm_dev_type_enum dev_type);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_paired_dev_setting>
 * FUNCTION
 *  srv_bt_cm_dev_property_check
 * DESCRIPTION
 *  This function is to check if device is matched certain property
 * PARAMETERS
 *  srv_bt_cm_bt_addr:    [IN]    BT device address    
 *  prop             :    [IN]    device property, refer to srv_bt_cm_dev_property_enum
 * RETURNS
 *  MMI_TRUE  : means matched
 *  MMI_FALSE : means not matched
 *****************************************************************************/
MMI_BOOL srv_bt_cm_dev_property_check(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_dev_property_enum prop);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_dev_del
 * DESCRIPTION
 *  This function is to process my device delete request,
 *  after successfully delete the device from paired device list,
 *  it will notify notifier SRV_BT_CM_EVENT_MYDEV_DEL.
 * PARAMETERS
 *  dev_addr:    [IN]    device address
 * RETURNS
 *  S32 : refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
extern S32 srv_bt_cm_dev_del(srv_bt_cm_bt_addr* dev_addr);


/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_dev_del_all
 * DESCRIPTION
 *  This function is to process My device delete all request,
 *  after successfully clear paired device list,
 *  it will notify notifier SRV_BT_CM_EVENT_MYDEV_DEL.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 : refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
extern S32 srv_bt_cm_dev_del_all(void);


/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_dev_add
 * DESCRIPTION
 *  This function is to process My device add request
 * PARAMETERS
 *  dev_addr:    [IN]    device address pointer
 * RETURNS
 *  S32 : refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
extern S32 srv_bt_cm_dev_add(srv_bt_cm_bt_addr* dev_addr);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Int_dev_mgr>
 * FUNCTION
 *  srv_bt_cm_dev_remove
 * DESCRIPTION
 *  This function is to process My device remove request
 * PARAMETERS
 *  dev_addr:    [IN]   device address pointer
 * RETURNS
 *  S32 : refer to srv_bt_cm_result_codes_enum
 *****************************************************************************/
extern S32 srv_bt_cm_dev_remove(srv_bt_cm_bt_addr* dev_addr);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_other>
 * FUNCTION
 *  srv_bt_cm_get_conn_type
 * DESCRIPTION
 *  This function is to get connection type
 * PARAMETERS
 *  profile_id:    [IN]    profile UUID, refer to the UUID macro defination
 * RETURNS
 *  srv_bt_cm_connection_type : connection type
 *****************************************************************************/
extern srv_bt_cm_connection_type srv_bt_cm_get_conn_type(U32 profile_id);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_other>
 * FUNCTION
 *  mmi_bt_register_operation_callback
 * DESCRIPTION
 *  This function is to register operation callback
 * PARAMETERS
 *  oper_type:    [IN]    operaion type
 *  func_p   :    [IN]    function pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_register_operation_callback(srv_bt_cm_oper_type_enum oper_type, FuncPtr func_p);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_other>
 * FUNCTION
 *  mmi_bt_unregister_operation_callback
 * DESCRIPTION
 *  This function is to unregister operation callback
 * PARAMETERS
 *  oper_type:    [IN]    operation type
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_unregister_operation_callback(srv_bt_cm_oper_type_enum oper_type);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_other>
 * FUNCTION
 *  srv_bt_cm_reg_pairing_permission
 * DESCRIPTION
 *  This function is to register the pairing permission function call
 * PARAMETERS
 *  U32 profile_id:    to specify the profile uuid
 *  void *fp      :    registered function call for CM to check if pairing procedure is permitted
 *                     the input argument of the registerd function call is srv_bt_cm_bt_addr, CM will pass this
 *                     information to registered function call.
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_reg_pairing_permission(U32 profile_id, void* fp);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_other>
 * FUNCTION
 *  srv_bt_cm_unreg_pairing_permission
 * DESCRIPTION
 *  This function is to unregister the pairing permission function call
 * PARAMETERS
 *  profile_id:    to specify the profile uuid
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_unreg_pairing_permission(U32 profile_id);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_other>
 * FUNCTION
 *  srv_bt_cm_send_msg
 * DESCRIPTION
 *  This function is the handler for send msg to XXX module
 * PARAMETERS
 *  dest_module :    [IN]    destination module
 *  sap_id      :    [IN]    SAP id
 *  msg_id      :    [IN]    message id
 *  p_local_para:    [IN]    local parameter
 *  p_peer_buff :    [IN]    peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_send_msg(U32 dest_module, U32 sap_id, U32 msg_id, void* p_local_para, void* p_peer_buff);
/* DOM-NOT_FOR_SDK-END */


#ifdef __DM_LAWMO_SUPPORT__
/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_lock_bt_module_req
 * DESCRIPTION
 *  This function is to lock BT module and send MSG_ID_BT_LOCK_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE : success
 *  MMI_FALSE: failed
 *****************************************************************************/
extern MMI_BOOL srv_bt_cm_lock_bt_module_req(void);
/* DOM-NOT_FOR_SDK-END */
#endif /*__DM_LAWMO_SUPPORT__*/

#if defined(__MMI_HIDD_SUPPORT__)
extern MMI_BOOL srv_bt_cm_dev_is_support_hid(srv_bt_cm_dev_struct *dev_p);
#endif /*defined(__MMI_HIDD_SUPPORT__)*/



/* begin activate event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    MMI_BOOL result;            /* activate result */
} srv_bt_cm_begin_activate_struct;

    
/* activate event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    MMI_BOOL result;            /* activate result */
} srv_bt_cm_activate_struct;


/* begin deactivate event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    MMI_BOOL result;            /* deactivate result */
} srv_bt_cm_begin_deactivate_struct;


/* deactivate event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    MMI_BOOL result;            /* deactivate result */
} srv_bt_cm_deactivate_struct;


/* inquiry indication event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    U32 discovered_dev_num;     /* discovered device number */
} srv_bt_cm_inquiry_indication_struct;


/* inquiry complete event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    S32 result;                 /* inquiry complete result */
    MMI_BOOL is_cancelled;      /* MMI_TRUE: cancelled by MMI
                                 * MMI_FALSE: not cancelled by MMI */
} srv_bt_cm_inquiry_complete_struct;


/* bond result event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    srv_bt_cm_bt_addr dev_addr; /* device address */
    S32 result;                 /* MMI_TRUE: success */

    //MMI_BOOL is_first_bond;  /* MMI_TRUE: first pair, MMI_FALSE: not first pair */
} srv_bt_cm_bond_res_struct;


/* pair indication struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    U8* dev_name;                 /* device name */
    U8 enable_16digits_pin_code;  /* whether enable 16 digits pin code */
    srv_bt_cm_bt_addr dev_addr;   /* device address */
} srv_bt_cm_pair_ind_struct;


/* paire result event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    srv_bt_cm_bt_addr dev_addr; /* device address */
    S32 result;                 /* MMI_TRUE: success, MMI_FALSE: fail */
    MMI_BOOL is_first_pair;     /* MMI_TRUE: first pair, MMI_FALSE: not first pair */
} srv_bt_cm_pair_res_struct;


/* security user confirm event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    U8* dev_name;               /* device name */
    srv_bt_cm_bt_addr dev_addr; /* device address */
    U8 display_numeric;         /* whether display numeric */
    U8* passcode;               /* passcode */
} srv_bt_cm_security_user_confirm_struct;


/* security passkey event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    U8* dev_name;               /* device name */
    srv_bt_cm_bt_addr dev_addr; /* device address */
    U8* passcode;               /* passcode */
} srv_bt_cm_security_passkey_struct;


/* security keypress event struct*/
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    srv_bt_cm_bt_addr dev_addr; /* device address */
    U8 num_digit;               /* numeic digit */
} srv_bt_cm_security_keypress_struct;


/* connect request event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    U8* dev_name;               /* device name */
    srv_bt_cm_bt_addr dev_addr; /* device address */
    U32 conn_id;                /* connection ID */
    U32 profile_id;             /* profile ID */
} srv_bt_cm_conn_req_struct;


/* connect result event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    srv_bt_cm_bt_addr* dev_addr;/* device address */
    U32 profile_id;             /* profile ID */
    S32 result;                 /* connect result */
	U32 conn_id;
} srv_bt_cm_conn_res_struct;


/* disconnect indication event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    srv_bt_cm_bt_addr* dev_addr; /* device address */
    U32 profile_id;              /* profile ID */
/* DOM-NOT_FOR_SDK-BEGIN */
    MMI_BOOL passive;
/* DOM-NOT_FOR_SDK-END */
    //MMI_BOOL result;             /* disconnect result */
} srv_bt_cm_disconnect_ind_struct;


/* release all device event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    srv_bt_cm_bt_addr* dev_addr;/* device address */
    MMI_BOOL result;            /* release all device result */
} srv_bt_cm_release_all_struct;


/* refresh service list event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    S32 result;                 /* release all service list result */
} srv_bt_cm_refresh_service_list_struct;


/* set authorize event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    MMI_BOOL result;            /* set authorize result */
} srv_bt_cm_set_authorize_struct;


/* unblock event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    MMI_BOOL result;            /* unblock event */
} srv_bt_cm_unblock_struct;


/* mydevice delete event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    MMI_BOOL result;            /* my device delete result */
	srv_bt_cm_dev_struct* del_dev;
} srv_bt_cm_mydev_del_struct;


/* typedef struct */
/* { */
/*     MMI_BOOL result; */
/* } srv_bt_cm_mydev_del_all_struct; */


/* set visibility event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    MMI_BOOL result;            /* set visibility result */
    MMI_BOOL is_from_mmi;       /* to identify whether the action is initiated by MMI
                                 * or change the visibility just by CM service due to A2DP connected */
} srv_bt_cm_set_visibility_struct;

    
/* set name event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    S32 result;                 /* set name result */
} srv_bt_cm_set_name_struct;

    
/* set authentication event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    S32 result;                 /* set authentication result */
} srv_bt_cm_set_authentication_struct;

    
/* set SIMAP event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    MMI_BOOL result;            /* set SIMAP result */
} srv_bt_cm_set_simap_struct;


/* sco indication event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    MMI_BOOL result;            /* sco indication result */
} srv_bt_cm_sco_ind_struct;


/* panic indication struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
} srv_bt_cm_panic_ind_struct;


/* read remote device name struct */
typedef struct
{
    S32 srv_hd;                  /* service handle*/
    void* user_data;             /* user data */
    srv_bt_cm_bt_addr* dev_addr; /* device address */
} srv_bt_cm_read_remote_dev_name_struct;
    

/* set limit discoverable mode event struct */
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    S32 result;                 /* set limit discoverable mode result */
} srv_bt_cm_set_limit_discoverable_mode_struct;

typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    S32 result;                 /* 1: chip available, 0: chip not available */
} srv_bt_cm_chip_detect_struct;

// typedef struct
// {
//     U32 conn_id;
//     U32 profile_id;
//     MMI_BOOL result;
// } srv_bt_cm_notify_connector_struct;

// #ifdef __BT_BOND_CANCEL__
typedef struct
{
    S32 srv_hd;                 /* service handle*/
    void* user_data;            /* user data */
    MMI_BOOL result;            /* bond cancel result */
} srv_bt_cm_bond_cancel_result;
// #endif
    

/* bluetooth cm service handle form */
typedef void (*srv_bt_cm_notifier)(U32 event, void* para);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_set_notify
 * DESCRIPTION
 *  Bluetooth CM set notifier, after set successfully,
 *  notifier will receive the event notification it it happens.
 * PARAMETERS
 *  notifier  :    [IN]    notifier, refer to srv_bt_cm_notifier
 *  event_mask:    [IN]    event mask, refer to srv_bt_cm_event_enum
 *  user_data :    [IN]    user data
 *  
 * RETURNS
 *  service handle, if it is less than 0, it means invalid handle
 ******************************************************************************/
extern S32 srv_bt_cm_set_notify(srv_bt_cm_notifier notifier, U32 event_mask, void* user_data);


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_reset_notify
 * DESCRIPTION
 *  this function is to reset notifier, notifier will not receive any event from CM service any more
 * PARAMETERS
 *  srv_hd :    [IN]    notify handler, returned by srv_bt_cm_set_notify()
 *  
 * RETURNS
 *  S32 : refer to srv_bt_cm_result_codes_enum
 ******************************************************************************/
extern S32 srv_bt_cm_reset_notify(S32 srv_hd);


#ifdef __BT_AUTO_DETECT_SUPPORT__
/*****************************************************************************
 * <GROUP Ext_local_dev_setting>
 * FUNCTION
 *  srv_bt_chip_available
 * DESCRIPTION
 *  This function is to check the whether bluetooth chip is available.
 * PARAMETERS
 *  void
 * RETURNS
 *  1: chip available.
 *  0: chip not available.
 *****************************************************************************/
U32 srv_bt_chip_available(void);
#endif



/*--------------------------------------------------------------------------------*/
/* API will be moved Btcmsrvprot.h */
/*--------------------------------------------------------------------------------*/
/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Int_local_dev_set> 
 * FUNCTION
 *  srv_bt_cm_get_state
 * DESCRIPTION
 *  This function is to get current bluetooth state
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_state_enum : current bluetooth state
 *****************************************************************************/
srv_bt_cm_state_enum srv_bt_cm_get_state(void);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Int_other> 
 * FUNCTION
 *  srv_bt_cm_get_flag
 * DESCRIPTION
 *  This function is to get flag value
 * PARAMETERS
 *  get_flag:    [IN]    the flag
 * RETURNS
 *  U32 : flag value
 *****************************************************************************/
U32 srv_bt_cm_get_flag(U32 get_flag);
/* DOM-NOT_FOR_SDK-END */


/* the default device type enum */
typedef enum
{
    SRV_BT_CM_DEFAULT_DEV_TYPE_HS,      /* default headset */
    SRV_BT_CM_DEFAULT_DEV_TYPE_HID,     /* default HID device */   
    SRV_BT_CM_DEFAULT_DEV_TYPE_TOTAL    /* last enum for default device type */
} srv_bt_cm_default_dev_type_enum;


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_paired_dev_setting>
 * FUNCTION
 *  srv_bt_cm_get_default_dev_addr
 * DESCRIPTION
 *  This function is to get default device address, 
 *  NULL means default device not existed
 * PARAMETERS
 *  dev_type:    [IN]    default device type
 * RETURNS
 *  srv_bt_cm_bt_addr        default device address pointer, 
 *                           NULL means default device not existed
 *****************************************************************************/
srv_bt_cm_bt_addr* srv_bt_cm_get_default_dev_addr(srv_bt_cm_default_dev_type_enum dev_type);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_paired_dev_setting>
 * FUNCTION
 *  srv_bt_cm_set_default_dev
 * DESCRIPTION
 *  This function is to set default device
 * PARAMETERS
 *  dev_type:    [IN]    default device type
 *  dev_addr:    [IN]    device address
 * RETURNS
 *  srv_bt_cm_result_codes_enum : the result of setting default device
 *****************************************************************************/
srv_bt_cm_result_codes_enum srv_bt_cm_set_default_dev(srv_bt_cm_default_dev_type_enum dev_type, srv_bt_cm_bt_addr* dev_addr);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/* FuncPtr: a pointer to a function which is to connect headset */
typedef void (*srv_bt_cm_headset_connect_callback)(MMI_BOOL b_success);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * <GROUP Ext_other>
 * FUNCTION
 *  srv_bt_cm_connect_default_headset
 * DESCRIPTION
 *  This function is to process connect default headset request
 * PARAMETERS
 *  conn_cb    :    connection callback function
 * RETURNS
 *  MMI_TRUE  : success to connect
 *  MMI_FALSE : otherwise
 *****************************************************************************/
extern MMI_BOOL srv_bt_cm_connect_default_headset(srv_bt_cm_headset_connect_callback conn_cb);
/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_is_dev_addr_equal
 * DESCRIPTION
 *  this function is used to judge whether two bluetooth address is equal
 * PARAMETERS
 *  dev_addr1    [IN]    device address
 *  dev_addr2    [IN]    device address
 *  
 * RETURNS
 *  MMI_TRUE : two device address is equal
 *  MMI_FALSE: two device address is not equal
 ******************************************************************************/
extern MMI_BOOL srv_bt_cm_is_dev_addr_equal(const srv_bt_cm_bt_addr* dev_addr1, const srv_bt_cm_bt_addr* dev_addr2);
/* DOM-NOT_FOR_SDK-END */

//#endif /* __MMI_BT_SUPPORT__ */
#ifdef __MMI_BT_SUPPORT__
void srv_bt_cm_set_btdialor_app_mode(MMI_BOOL val);
MMI_BOOL srv_bt_cm_get_btdialor_app_mode(void);
#ifdef __MMI_BT_DIALER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_profile_connected_ex
 * DESCRIPTION
 *  This function is to check if XXX profile connected
 * PARAMETERS
 *  conn_type       [IN]        to check if conn_type is connected, conn_type is defind in srv_bt_cm_connection_type 
 *  dev_addr		[IN]		the profile related dev_addr
 * RETURNS
 *  MMI_BOOL            TRUE : the profile is connected
 *                      FALSE : the profile is not connected
 *****************************************************************************/
extern MMI_BOOL srv_bt_cm_is_profile_connected_ex(srv_bt_cm_connection_type conn_type, const srv_bt_cm_bt_addr* dev_addr);

/**********************************************************************
* FUNCTION: 
* 	srv_bt_cm_get_linked_dev_num
* DESCRIPTION:
*    Get the number of linked device.
* PARAMETERS:
* void
* RETURNS:
* U32 		the number of the linked device
***********************************************************************/
extern U32 srv_bt_cm_get_linked_dev_list_idx(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_linked_dev_info
 * DESCRIPTION
 *  This function is to check if a dev has been connected
 * PARAMETERS
 *  index_order     [IN]        the linked order. 
 * RETURNS
 *  srv_bt_cm_dev_struct*    the linked device info. 
 *****************************************************************************/
extern const srv_bt_cm_dev_struct* srv_bt_cm_get_linked_dev_info(U32 index_order);

extern const srv_bt_cm_bt_addr* srv_bt_cm_get_busy_dev(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_dev_busy
 * DESCRIPTION
 *  This function is to check if a dev is connecting
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 * RETURNS
 *  MMI_BOOL            TRUE : there is some profile connecting
 *                      FALSE : the device is not connected or connected already.
 *****************************************************************************/
extern MMI_BOOL srv_bt_cm_is_dev_busy(const srv_bt_cm_bt_addr* dev_addr);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_dev_busy_state
 * DESCRIPTION
 *  This function is provided for CONN app only, to set the connecting profile status.
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 *  conn_type       [IN]		the type of profile
 *  state			[IN]		indicate that it is connecting/disconnecting or done.
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_set_dev_busy_state(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL state);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_dev_link_state
 * DESCRIPTION
 *  This function is provided for CONN app only, to set the connecting profile status.
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 *  conn_type       [IN]		the type of profile
 *  state			[IN]		indicate that it is connecting/disconnecting or done.
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_cm_set_dev_link_state(srv_bt_cm_bt_addr* dev_addr, MMI_BOOL link_state);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_existed_conn_num_by_addr
 * DESCRIPTION
 *  This function is to get the number of connected profiles for a device.
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 * RETURNS
 *  S32   the number of connected profiles
 *****************************************************************************/
extern S32 srv_bt_cm_get_existed_conn_num_by_addr(srv_bt_cm_bt_addr* dev_addr);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_auto_reconn_flag
 * DESCRIPTION
 *  This function is to check if currently BT is auto-connecting.
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_cm_get_auto_reconn_flag(srv_bt_cm_bt_addr* dev_addr);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_auto_reconn_flag
 * DESCRIPTION
 *  This function is to set auto-connecting flag.
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern void srv_bt_cm_set_auto_reconn_flag(srv_bt_cm_bt_addr* dev_addr, MMI_BOOL auto_reconn);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_headset_connected_ex
 * DESCRIPTION
 *  This function is to check if there is headset connected.
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_cm_is_headset_connected_ex(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_bt_dialer
 * DESCRIPTION
 *  This function is to check if remote dev is MTK bt dialer.
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_cm_is_bt_dialer(const srv_bt_cm_bt_addr* dev_addr);
#endif
#endif
#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* BT_CM_SRV_GPROT_H */
