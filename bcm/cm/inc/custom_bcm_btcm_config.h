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
 * Filename:
 * ---------
 *  custom_btcm_config.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __CUSTOM_BTCM_CONFIG_H__
#define __CUSTOM_BTCM_CONFIG_H__

#include "MMI_features.h"
#include "kal_general_types.h"

/***************************************************************************** 
 * Include 
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* bluetooth device name UTF8 buffen length */
#define SRV_BT_CM_BD_FNAME_LEN                     56 /* 18 * 3 + 2 */

/* supported profile number */
#if defined(__PLUTO_MMI_PACKAGE__) && defined(__LOW_COST_SUPPORT_COMMON__) // SLIM:memory reduction
    #ifdef __MMI_BT_DIALER_SUPPORT__
    #define SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE       12
    #else
    #define SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE       10
    #endif
#else
	#define SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE       23
#endif

/* max paired device number */
#define SRV_BT_CM_MAX_PAIRED_DEVICE_LIST           10

/* max recent used device number */
#if defined(__PLUTO_MMI_PACKAGE__) && defined(__LOW_COST_SUPPORT_COMMON__) // SLIM:memory reduction
#define SRV_BT_CM_MAX_USED_DEVICE_LIST             1
#else
#define SRV_BT_CM_MAX_USED_DEVICE_LIST             10
#endif  // SLIM:memory reduction

/* max device number */
#define SRV_BT_CM_MAX_DEVICE_LIST                  (SRV_BT_CM_MAX_PAIRED_DEVICE_LIST + SRV_BT_CM_MAX_USED_DEVICE_LIST)

/* Bluetooth device address struct */
typedef struct
{
    kal_uint32 lap;    /* Lower Address Part 00..23 */
    kal_uint8  uap;    /* upper Address Part 24..31 */
    kal_uint16 nap;    /* Non-significant    32..47 */
} srv_bt_cm_bt_addr;

/* Bluetooth device struct */
typedef struct
{
    kal_uint32 cod;                                                /* class of device */
    kal_uint8 name[SRV_BT_CM_BD_FNAME_LEN];                        /* device name */
    srv_bt_cm_bt_addr bd_addr;                              /* device addres */
#ifdef __BT_4_0_BLE__
	srv_bt_cm_bt_addr le_bd_addr;
#endif
    kal_uint8 attribute;                                           /* authorized or blocked */
    kal_uint8 service_list_num;                                    /* supported service number */
    kal_uint32 service_list[SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE]; /* supported service list */
} srv_bt_cm_dev_struct;

/* BT CM user data NVRAM structure */
typedef struct
{
    kal_uint32 flag;                                                               /* bt flag */
    kal_uint32 idx_of_last_hid_dev;                                                /* Last HID Dev Info */
    srv_bt_cm_dev_struct host_dev;                                          /* Host Dev Info */
    kal_uint8 pad_list[8];                                                         /* 4 byte pad size */
} srv_bt_cm_nvram_struct;

/* BT CM system data NVRAM structure */
typedef struct
{
    kal_uint32 sys_flag;                               /* bt flag */
    kal_uint8 host_dev_name[SRV_BT_CM_BD_FNAME_LEN];   /* host device name */
} srv_bt_cm_sys_nvram_struct;


/* Bluetooth device struct */
typedef struct
{
    srv_bt_cm_dev_struct dev_info;
    kal_uint32 ref_cnt;
} srv_bt_cm_dev_struct_int;


typedef struct
{
    kal_uint16 paired_dev_num;                                                     /* paired device number*/
    kal_uint16 recent_dev_num;                                                     /* recent used device number*/
    kal_uint8 paired_idx_list[SRV_BT_CM_MAX_PAIRED_DEVICE_LIST];
    kal_uint8 recent_idx_list[SRV_BT_CM_MAX_USED_DEVICE_LIST];
    kal_uint8 pad_list[20];            // 20 bytes pad size
#if defined(__PLUTO_MMI_PACKAGE__) && defined(__LOW_COST_SUPPORT_COMMON__) // SLIM:memory reduction
    kal_uint8 pad[9];
#endif                                         // SLIM:memory reduction
} srv_bt_cm_nvram_dev_list_index_struct;

#endif /* __CUSTOM_BTCM_CONFIG_H__ */

