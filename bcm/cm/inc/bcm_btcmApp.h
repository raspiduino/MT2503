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
 * bcmapp.h
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for BT  app in BCM.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ****************************************************************************/
#ifndef __BCM_APP_H__
#define __BCM_APP_H__

#if defined( __BT_HF_PROFILE__) || defined( __BT_HFG_PROFILE__)
#include "bcm_BtAudioSrvGprot.h"
#endif/*defined( __BT_HF_PROFILE__) || defined( __BT_HFG_PROFILE__)*/

typedef void (*bcm_app_func_ptr) (void);

/***************************************************************************** 
* Definations
*****************************************************************************/
#define BCM_APP_SCR_MAX_NUM_OF_CONTEXT_OF_PRO_CON_SCR           64
#define BCM_APP_SCR_BUF_SIZE                                    64 //128
#define BCM_APP_UI_BUF_SIZE                                     400
#define BCM_APP_PIN_SCR_BUF_SIZE                                20
#define BCM_APP_POPUP_SCR_BUF_SIZE                              160        
#define BCM_APP_INQUIRY_TIMEOUT_DURATION                        60      /* 60 sec */
#define BCM_APP_CONNECT_ACCEPT_CNF_TIMER_DUR                    30000
#define BCM_APP_MAX_PASSKEY_LENGHT                              (16+1)
#define BCM_APP_BT_LP2_GUARD_TIMER_DUR                          30000    /* 30 sec */
#define BCM_APP_BT_LP2_DELAY_TIMER_DUR                          2500     /* 2.5 sec */
#define BCM_APP_MAX_SECURITY_PASSKEY_LENGTH                     6        
//#define BCM_APP_BT_TEMP_VISIBLE_TIMER_DUR                       60000    /* 60 sec */ /* in minutes*/
#define BCM_APP_MAX_ITEM_ICON                                   (SRV_BT_CM_MAX_PAIRED_DEVICE_LIST + 2)

// sys flag: record bt power status
#define BCM_APP_MASK_ON                      0x00000001
#define BCM_APP_MASK_OFF_BY_FLIGHT_MODE      0x00000002
#define BCM_APP_MASK_ON_BY_FLIGHT_MODE       0x00000004
#define BCM_APP_MASK_JUST_NOTIFY_FLIGHT_MODE 0x00000008


//#define  BCM_APP_POWER_ON                      0x01

#define  BCM_APP_INQ_TYPE_AUDIO                   0x00000001
#define  BCM_APP_INQ_TYPE_ALL_DEV                 0x00000002

#define  BCM_APP_INQUIRY                          0x00000004
//#define  BCM_APP_SIM_HOT_SWAP                     0x00000008

//#define  BCM_APP_FLIGHT_MODE_ON                0x00000010
//#define  BCM_APP_FLIGHT_MODE_OFF               0x00000020

/*from mmi call power switch*/
#define  BCM_APP_POWER_SWITCH               0x00000040
#define  BCM_APP_SCO_FAR_END_LP_TESTING        0x00000080


/*when set visibility, but bt power off*/
#define  BCM_APP_CONFIRM_SET_VISIBILITY           0x00000100
/*when search new device from cm, but bt power off*/
#define  BCM_APP_CONFIRM_INQ_ALL_DEV              0x00000200
/*when search audio device from cm, but bt power off*/
#define  BCM_APP_CONFIRM_INQ_AUDIO_DEV            0x00000400
/*when entry specific device from profile, but bt power off*/
#define  BCM_APP_CONFIRM_SPECIFIC_DEV             0x00000800
/*when rename host device, but bt power off*/
#define  BCM_APP_CONFIRM_SET_DEV_NAME             0x00001000
/*when entry advance screen, but bt power off*/
#define  BCM_APP_CONFIRM_SET                      0x00002000
/*when entry paired device option menu, but bt power off*/
#define  BCM_APP_CONFIRM_PAIRED_DEV_OPT           0x00004000
/*when entry paired device list, if press CSK to connect HFP, but BT not power on*/
#define  BCM_APP_CONFIRM_CONNECT_AUDIO            0x00008000
/*when entry paired device to unblock(LSK) , but BT power off*/
#define  BCM_APP_CONFIRM_UNBLOCK                  0x00010000

/*when delete device, the delete confirm*/
#define  BCM_APP_DELETE_DEV_CONFIRM                    0x00020000
/*when delete all device, the delete all confirm*/
#define  BCM_APP_DELETE_DEV_ALL_CONFIRM             0x00040000

/*when delete device, if connection exit*/
#define  BCM_APP_CONFIRM_PAIRED_DEV_DEL           0x00080000
/*when delete all device, if connection exit*/
#define  BCM_APP_CONFIRM_PAIRED_DEV_DEL_ALL       0x00100000
/*when power off BT, but connection exist, first release connection,then power off*/
#define  BCM_APP_CONFIRM_SWITCH_POWER_OFF         0x00200000
/*when set simap, but connection exit, first release conneciton*/
//#define  BCM_APP_CONFIRM_SIMAP_SET                0x00400000
/*when set authorize to reject, but connection exit, first release conneciton*/
#define  BCM_APP_CONFIRM_AUTHORIZE_REJECT         0x00800000
/*when connect audio device, but connection exit, first release conneciton*/
#define  BCM_APP_RELEASE_AUDIO_DEV_BEFORE_CONNECT 0x01000000
/*when user from mmi disconnect device or disconnect all connection*/
#define  BCM_APP_RElEASE_CONNECT             0x02000000
/*When first paired success, will set authorize as always connect, but not display popup"Done"*/
#define  BCM_APP_SET_ALWAYS_CONNECT_BY_PAIR       0x40000000
/* TO go to the audio path when power on is done  */
#define  BCM_APP_SET_AUDIO_PATH                   0x80000000

#define  BCM_APP_OPP_CLIENT_AUTO_ON                 0x04000000
#define  BCM_APP_BIP_CLIENT_AUTO_ON                 0x08000000
#define  BCM_APP_BPP_CLIENT_AUTO_ON                 0x10000000
#define  BCM_APP_AUTO_ON                            0x20000000


/* class of device bit mask */

/* <GROUP Major Service Mask>
postioning major service mask */
#define BCM_APP_POSTIONING_MAJOR_SERVICE_MASK                            (0x010000)
/* <GROUP Major Service Mask>
networking major service mask */
#define BCM_APP_NETWORKING_MAJOR_SERVICE_MASK                            (0x020000)
/* <GROUP Major Service Mask>
rendering major service mask */
#define BCM_APP_RENDERING_MAJOR_SERVICE_MASK                                (0x040000)
/* <GROUP Major Service Mask>
capturing major service mask */
#define BCM_APP_CAPTURING_MAJOR_SERVICE_MASK                                (0x080000)
/* <GROUP Major Service Mask>
object transfer major service mask */
#define BCM_APP_OBJECT_TRANSFER_MAJOR_SERVICE_MASK                        (0x100000)
/* <GROUP Major Service Mask>
audio major service mask */
#define BCM_APP_AUDIO_MAJOR_SERVICE_MASK                                    (0x200000)
/* <GROUP Major Service Mask>
telephony major service mask */
#define BCM_APP_TELEPHONY_MAJOR_SERVICE_MASK                                (0x400000)
/* <GROUP Major Service Mask>
information major service mask */
#define BCM_APP_INFORMATION_MAJOR_SERVICE_MASK                            (0x800000)


/* <GROUP Major Device Mask>
miscellaneous major device mask */
#define BCM_APP_MISCELLANEOUS_MAJOR_DEVICE_MASK                            (0x000000)
/* <GROUP Major Device Mask>
computer major device mask */
#define BCM_APP_COMPUTER_MAJOR_DEVICE_MASK                                (0x000100)
/* <GROUP Major Device Mask>
phone major device mask */
#define BCM_APP_PHONE_MAJOR_DEVICE_MASK                                    (0x000200)
/* <GROUP Major Device Mask>
LAN major device mask */
#define BCM_APP_LAN_MAJOR_DEVICE_MASK                                    (0x000300)
/* <GROUP Major Device Mask>
AV major device mask */
#define BCM_APP_AV_MAJOR_DEVICE_MASK                                        (0x000400)
/* <GROUP Major Device Mask>
peripheral major device mask */
#define BCM_APP_PERIPHERAL_MAJOR_DEVICE_MASK                                (0x000500)
/* <GROUP Major Device Mask>
imaging major device mask */
#define BCM_APP_IMAGING_MAJOR_DEVICE_MASK                                (0x000600)
/* <GROUP Major Device Mask>
unclassified major device mask */
#define BCM_APP_UNCLASSIFIED_MAJOR_DEVICE_MASK                            (0x001F00)

/* <GROUP Minor Device    Mask under computer major class>
desktop workstation minor device mask */
#define BCM_APP_DESKTOP_WORKSTATION_MINOR_DEVICE_MASK                    (0x000004)
/* <GROUP Minor Device    Mask under computer major class>
server class computer minor device mask */
#define BCM_APP_SERVER_CLASS_COMPUTER_MINOR_DEVICE_MASK                    (0x000008)
/* <GROUP Minor Device    Mask under computer major class>
laptop minor device mask */
#define BCM_APP_LAPTOP_MINOR_DEVICE_MASK                                    (0x00000C)
/* <GROUP Minor Device    Mask under computer major class>
handhelp PC PDA minor device mask */
#define BCM_APP_HANDHELP_PC_PDA_MINOR_DEVICE_MASK                        (0x000010)
/* <GROUP Minor Device    Mask under computer major class>
palm sized PC PDA minor device mask */
#define BCM_APP_PALM_SIZED_PC_PDA_MINOR_DEVICE_MASK                        (0x000014)
/* <GROUP Minor Device    Mask under computer major class>
unclassified computer minor device mask */
#define    BCM_APP_UNCLASSIFIED_COMPUTER_MINOR_DEVICE_MASK                    (0x000000)


/* <GROUP Minor Device    Mask under phone major class>
cellular minor device mask */
#define BCM_APP_CELLULAR_MINOR_DEVICE_MASK                                (0x000004)
/* <GROUP Minor Device    Mask under phone major class>
cordless minor device mask */
#define BCM_APP_CORDLESS_MINOR_DEVICE_MASK                                (0x000008)
/* <GROUP Minor Device    Mask under phone major class>
smart phone minor device mask */
#define BCM_APP_SMART_PHONE_MINOR_DEVICE_MASK                            (0x00000C)
/* <GROUP Minor Device    Mask under phone major class>
wired modem or voice gateway minor device mask */
#define BCM_APP_WIRED_MODEM_OR_VOICE_GATEWAY_MINOR_DEVICE_MASK            (0x000010)    
/* <GROUP Minor Device    Mask under phone major class>
unclassified phone minor device mask */
#define    BCM_APP_UNCLASSIFIED_PHONE_MINOR_DEVICE_MASK                        (0x000000)


/* <GROUP Minor Device    Mask under audio/video major class>
uncategorised AV minor device mask */
#define    BCM_APP_UNCATEGORISED_AV_MINOR_DEVICE_MASK                        (0x000000)
/* <GROUP Minor Device    Mask under audio/video major class>
wearable headset AV minor device mask */
#define BCM_APP_WEARABLE_HEADSET_AV_MINOR_DEVICE_CLASS                    (0x000004)
/* <GROUP Minor Device    Mask under audio/video major class>
handsfree AV minor device mask */
#define BCM_APP_HANDSFREE_AV_MINOR_DEVICE_CLASS                            (0x000008)
/* <GROUP Minor Device    Mask under audio/video major class>
microphone AV minor device mask */
#define BCM_APP_MICROPHONE_AV_MINOR_DEVICE_CLASS                            (0x000010)
/* <GROUP Minor Device    Mask under audio/video major class>
loudspeaker AV minor device mask */
#define BCM_APP_LOUDSPEAKER_AV_MINOR_DEVICE_CLASS                        (0x000014)
/* <GROUP Minor Device    Mask under audio/video major class>
headphone AV minor device mask */
#define BCM_APP_HEADPHONES_AV_MINOR_DEVICE_CLASS                            (0x000018)
/* <GROUP Minor Device    Mask under audio/video major class>
portable audio AV minor device mask */
#define BCM_APP_PORTABLE_AUDIO_AV_MINOR_DEVICE_CLASS                        (0x00001C)
/* <GROUP Minor Device    Mask under audio/video major class>
car audio AV minor device mask */
#define BCM_APP_CAR_AUDIO_AV_MINOR_DEVICE_CLASS                            (0x000020)
/* <GROUP Minor Device    Mask under audio/video major class>
settop box AV minor device mask */
#define BCM_APP_SETTOP_BOX_AV_MINOR_DEVICE_CLASS                            (0x000024)
/* <GROUP Minor Device    Mask under audio/video major class>
hifi audio AV minor device mask */
#define BCM_APP_HIFI_AUDIO_AV_MINOR_DEVICE_CLASS                            (0x000028)
/* <GROUP Minor Device    Mask under audio/video major class>
VCR AV minor device mask */
#define BCM_APP_VCR_AV_MINOR_DEVICE_CLASS                                (0x00002C)
/* <GROUP Minor Device    Mask under audio/video major class>
video camera AV minor device mask */
#define BCM_APP_VIDEO_CAMERA_AV_MINOR_DEVICE_CLASS                        (0x000030)
/* <GROUP Minor Device    Mask under audio/video major class>
camcorder AV minor device mask */
#define BCM_APP_CAMCORDER_AV_MINOR_DEVICE_CLASS                            (0x000034)
/* <GROUP Minor Device    Mask under audio/video major class>
video monitor AV minor device mask */
#define BCM_APP_VIDEO_MONITOR_AV_MINOR_DEVICE_CLASS                        (0x000038)
/* <GROUP Minor Device    Mask under audio/video major class>
video display and loudspeaker AV minor device mask */
#define BCM_APP_VIDEO_DISPLAY_AND_LOUDSPEAKER_AV_MINOR_DEVICE_CLASS        (0x00003C)
/* <GROUP Minor Device    Mask under audio/video major class>
video conferencing AV minor device mask */
#define BCM_APP_VIDEO_CONFERENCING_AV_MINOR_DEVICE_CLASS                    (0x000040)
/* <GROUP Minor Device    Mask under audio/video major class>
game toy AV minor device mask */
#define BCM_APP_GAME_TOY_AV_MINOR_DEVICE_CLASS                            (0x000048)

/* <GROUP Minor Device    Mask under LAN major class>
fully available minor device mask */
#define BCM_APP_FULLY_AVAILABLE_MINOR_DEVICE_MASK                        (0x000000) 
/* <GROUP Minor Device    Mask under LAN major class>
one to seventeen percent minor device mask */
#define BCM_APP_ONE_TO_SEVENTEEN_PERCENT_MINOR_DEVICE_MASK                (0x000020)
/* <GROUP Minor Device    Mask under LAN major class>
seventeen to thirtythree percent minor device mask */
#define BCM_APP_SEVENTEEN_TO_THIRTYTHREE_PERCENT_MINOR_DEVICE_MASK        (0x000040)
/* <GROUP Minor Device    Mask under LAN major class>
thirtythree to fifty percent minor device mask */
#define BCM_APP_THIRTYTHREE_TO_FIFTY_PERCENT_MINOR_DEVICE_MASK            (0x000060)
/* <GROUP Minor Device    Mask under LAN major class>
fifty to sixtyseven percent minor device mask */
#define BCM_APP_FIFTY_TO_SIXTYSEVEN_PERCENT_MINOR_DEVICE_MASK            (0x000080)
/* <GROUP Minor Device    Mask under LAN major class>
sixtyseven to eightythree percent minor device mask */
#define BCM_APP_SIXTYSEVEN_TO_EIGHTYTHREE_PERCENT_MINOR_DEVICE_MASK        (0x0000A0)
/* <GROUP Minor Device    Mask under LAN major class>
eightythree to ninetynine percent minor device mask */
#define BCM_APP_EIGHTYTHREE_TO_NINETYNINE_PERCENT_MINOR_DEVICE_MASK        (0x0000C0)
/* <GROUP Minor Device    Mask under LAN major class>
no service available minor device mask */
#define BCM_APP_NO_SERVICE_AVAILABLE_MINOR_DEVICE_MASK                    (0x0000E0)
/* <GROUP Minor Device    Mask under LAN major class>
unclassified LAN minor device mask */
#define    BCM_APP_UNCLASSIFIED_LAN_MINOR_DEVICE_MASK                        (0x000000)

/* <GROUP Minor Device Mask under Peripheral major Class (Keyboard/pointing device filed)>
joystick peripheral minor device mask */
#define BCM_APP_JOYSTICK_PERIPHERALS_MINOR_DEVICE_CLASS                    (0x000004)
/* <GROUP Minor Device Mask under Peripheral major Class (Keyboard/pointing device filed)>
gamepad device peripheral minor device mask */
#define BCM_APP_GAMEPAD_DEVICE_PERIPHERAL_MINOR_DEVICE_CLASS                (0x000008)
/* <GROUP Minor Device Mask under Peripheral major Class (Keyboard/pointing device filed)>
remote control device peripheral minor device mask */
#define BCM_APP_REMOTE_CONTRO_DEVICE_PERIPHERAL_MINOR_DEVICE_CLASS        (0x00000C)
/* <GROUP Minor Device Mask under Peripheral major Class (Keyboard/pointing device filed)>
sensing device peripheral minor device mask */
#define BCM_APP_SENSING_DEVICE_PERIPHERAL_MINOR_DEVICE_CLASS                (0x000010)
/* <GROUP Minor Device Mask under Peripheral major Class (Keyboard/pointing device filed)>
digitizer tablet peripheral minor device mask */
#define BCM_APP_DIGITIZER_TABLET_PERIPHERAL_MINOR_DEVICE_CLASS            (0x000014)
/* <GROUP Minor Device Mask under Peripheral major Class (Keyboard/pointing device filed)>
card reader peripheral minor device mask */
#define BCM_APP_CARD_READER_PERIPHERAL_MINOR_DEVICE_CLASS                (0x000018)

/* <GROUP Minor Device Mask under Imaging major Class (printing, scanner, caramera...)>
display imaging minor device mask */
#define BCM_APP_DISPLAY_IMAGING_MINOR_DEVICE_CLASS                        (0x000010)
/* <GROUP Minor Device Mask under Imaging major Class (printing, scanner, caramera...)>
camera imaging minor device mask */
#define BCM_APP_CAMERA_IMAGING_MINOR_DEVICE_CLASS                        (0x000020)
/* <GROUP Minor Device Mask under Imaging major Class (printing, scanner, caramera...)>
scanner imaging minor device mask */
#define BCM_APP_SCANNER_IMAGING_MINOR_DEVICE_CLASS                        (0x000040)
/* <GROUP Minor Device Mask under Imaging major Class (printing, scanner, caramera...)>
printer imaging minor device mask */
#define BCM_APP_PRINTER_IMAGING_MINOR_DEVICE_CLASS                        (0x000080)
/////////////////////////////////
typedef enum{
    BCM_CM_PAIR_STATE_IDLE = 0,
    BCM_CM_PAIR_STATE_PIN_CODE = 1,
    BCM_CM_PAIR_STATE_USER_CONFIRM = 2,
    BCM_CM_PAIR_STATE_PASSKEY_NOTIFY = 3,
    BCM_CM_PAIR_STATE_KEYPRESS_NOTIFY = 4,
    BCM_CM_PAIR_STATE_MAX
}bcm_cm_pair_state;


typedef enum{
    BCM_EXT_CM_STATE_ERROR = 0,
    BCM_EXT_CM_STATE_START = 1,
    BCM_EXT_CM_STATE_READY = 2,
    BCM_EXT_CM_STATE_PAIRING = 3,
    BCM_EXT_CM_STATE_INQUIRING = 4,
    BCM_EXT_CM_STATE_CONNECTING = 5,
    BCM_EXT_CM_STATE_CONNECTED = 6,
    BCM_EXT_CM_STATE_UNKNOWN = 7,
    BCM_EXT_CM_STATE_MAX
    /*
    1 START    BT is power-up ing.
    2 READY    BT Power on already, in idle.
    3 PAIRING  
    4 INQUIRING
    5 CONNECTING
    6 CONNECTED
    7 UNKNOWN  BT is not power on yet or in some temp state.
    */

}bcm_ext_cm_state;
typedef enum
{
    BCM_EXT_PROFILE_STATE_ERROR = 0,
    BCM_EXT_PROFILE_STATE_START = 1, // reserved.
    BCM_EXT_PROFILE_STATE_IDLE = 2, //  app not activated.
    BCM_EXT_PROFILE_STATE_ACTIVATE = 3,//  app  activated
    BCM_EXT_PROFILE_STATE_AUTHORIZING = 4,// AUTHORIZING
    BCM_EXT_PROFILE_STATE_DISCONNECTING = 5,// DISCONNECTING
    BCM_EXT_PROFILE_STATE_DEACTIVATING = 6,// DEACTIVATING
    BCM_EXT_PROFILE_STATE_MAX
    
/*
1 START
2 IDLE
3 ACTIVATE
4 AUTHORIZING
5 DISCONNECTING
6 DEACTIVATING

*/
}bcm_ext_profile_state;

#ifdef __BT_HFG_PROFILE__

typedef struct {
    U32 srv_hd;
    U32 flags;
    btaud_device_info dev_info;
    BtAudDevAddr pend_dev;
} bcm_btaud_cntx_struct;

#endif/*#ifdef __BT_HFG_PROFILE__*/

#endif/*__BCM_SPP_H__*/



