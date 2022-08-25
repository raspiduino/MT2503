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
 * Bt_mmi.h
 *
 * Project:
 * --------
 *   BT Project
 *
 * Description:
 * ------------
 *   This file is used on default platform as the common include header for both
 *   internal and external BT SW. The header file should contain common system
 *   definition which is necessary known by both internal and external layers.
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
#ifndef __BT_MMI_H__
#define __BT_MMI_H__

#include "bt_types.h"
#if defined(BTMTK_ON_LINUX) && !defined(GEN_FOR_PC)
// #include <sys/socket.h>
// #include <sys/un.h>
#endif

#if defined(GEN_FOR_PC)
//#include "tst_codegen.h"
#endif

/* Default is WIN Queue */
#ifndef BTMTK_ON_LINUX
#ifndef __WIN_SHARED_MEMORY__
#define __WIN_QUEUE__
#endif
#endif

#ifndef BTMTK_ON_MAUI
typedef enum
{
    MOD_BT = 0,
    MOD_TIMER,
    MOD_MMI,
    MOD_BWCS,
    MOD_TST,
    MOD_SPP_DEFAULT,
    MOD_PAL,
    END_OF_MOD_ID
} module_type;
#endif  /* BTMTK_ON_MAUI */

#ifdef BTMTK_ON_MAUI
#ifdef __BCM_SUPPORT__
#define MOD_EXTERNAL MOD_BCM
#else
#define MOD_EXTERNAL MOD_MMI
#endif

#else   /* BTMTK_ON_MAUI */
#define MOD_EXTERNAL MOD_MMI
#if defined (BTMTK_ON_WIN32) || defined (BTMTK_ON_WISESDK) ||defined(BTMTK_ON_LINUX)
#define MOD_SIM MOD_MMI
#endif
#endif  /* BTMTK_ON_MAUI */

#ifndef BTMTK_ON_MAUI
typedef enum
{
    io_low = 0,
    io_high
} IO_level;

/* Cast the module name in MAUI */
#define MOD_DT MOD_SPP_DEFAULT
#define MOD_ATCI MOD_SPP_DEFAULT
#define MOD_ATCI_2 MOD_SPP_DEFAULT
#define MOD_JASYN MOD_MMI

#define LOCAL_PARA_HDR \
    U8	ref_count; \
    U16	msg_len;

#ifdef BTMTK_ON_LINUX
#define MAX_ILM_BUFFER_SIZE 2048 //1024 since 1024 is not enough for BIP local para in ILM!!!
#define MAX_PAL_ILM_BUFFER_SIZE 4*MAX_ILM_BUFFER_SIZE
#else
#define MAX_ILM_BUFFER_SIZE 2048 //1024 since 1024 is not enough for BIP local para in ILM!!!
#define MAX_PAL_ILM_BUFFER_SIZE 4*MAX_ILM_BUFFER_SIZE
#endif

typedef struct
{
    unsigned char used;
    unsigned long msg_id;
    void *local_para_ptr;
    /* Belowed is not used in external platform */
    /*void *peer_buff_ptr;*/
    module_type src_mod_id;
    module_type dest_mod_id;
    unsigned char sap_id;
    //#if defined(BTMTK_ON_LINUX)
    //    long           mtype;
    //#endif
    void *peer_buff_ptr;
    unsigned char ilm_data[MAX_ILM_BUFFER_SIZE];
    //unsigned long ilm_data[(MAX_ILM_BUFFER_SIZE>>2)];
} ilm_struct;

typedef struct
{
    unsigned char used;
    unsigned long msg_id;
    void *local_para_ptr;
    /* Belowed is not used in external platform */
    module_type src_mod_id;
    module_type dest_mod_id;
    unsigned char sap_id;
    void *peer_buff_ptr;
    unsigned char ilm_data[MAX_PAL_ILM_BUFFER_SIZE];
} pal_ilm_struct;

//#define local_para_struct void
/* So that we can use catcher for logging */
typedef struct local_para_struct
{
    LOCAL_PARA_HDR
} local_para_struct;

#define peer_buff_struct void

typedef enum
{
    TD_UL = 0x01 << 0,   /* Uplink Direction */
    TD_DL = 0x01 << 1,   /* Downlink Direction */
    TD_CTRL = 0x01 << 2, /* Control Plane. Both directions */
    TD_RESET = 0x01 << 3 /* Reset buffer content to 0 */
} transfer_direction;

#if defined(BTMTK_ON_LINUX)
#define BT_SOCK_NAME_APP_GAP "bt.app.gap"
#define BT_SOCK_NAME_APP_GAP_TWIN "bt.app.gap.twin"
#define BT_SOCK_NAME_INT_ADP "/dev/socket/bt.int.adp"
#define BT_SOCK_NAME_EXT_ADP "bt.ext.adp"
#define BT_SOCK_NAME_A2DP_STREAM "/dev/socket/bt.a2dp.stream"
#define BT_SOCK_NAME_EXT_ADP_A2DP "bt.ext.adp.a2dp"
#define BT_SOCK_NAME_EXT_ADP_A2DP_DATA "bt.ext.adp.a2dp.data"
#define BT_SOCK_NAME_EXT_ADP_HFP "bt.ext.adp.hfp"
#define BT_SOCK_NAME_EXT_ADP_SPP "bt.ext.adp.spp"
#define BT_SOCK_NAME_EXT_ADP_SPP_DATA "bt.ext.adp.spp.data"
#define BT_SOCK_NAME_EXT_ADP_AVRCP "bt.ext.adp.avrcp"
#define BT_SOCK_NAME_EXT_ADP_OPP "bt.ext.adp.opp"
#define BT_SOCK_NAME_EXT_ADP_BIP "bt.ext.adp.bip"
#define BT_SOCK_NAME_EXT_ADP_HID "bt.ext.adp.hid"
#define BT_SOCK_NAME_EXT_ADP_PBAP "bt.ext.adp.pbap"
#define BT_SOCK_NAME_EXT_ADP_FTP "bt.ext.adp.ftp"
#define BT_SOCK_NAME_EXT_ADP_BPP "bt.ext.adp.bpp"
#define BT_SOCK_NAME_EXT_ADP_SIMAP "bt.ext.adp.simap"
#define BT_SOCK_NAME_EXT_ADP_JSR82 "bt.ext.adp.jsr82"
#define BT_SOCK_NAME_EXT_ADP_PRX "bt.ext.adp.prx"
#define BT_SOCK_NAME_EXT_ADP_PAN "bt.ext.adp.pan"
#define BT_SOCK_NAME_EXT_ADP_MAP "bt.ext.adp.map"
#define BT_SOCK_NAME_EXT_ADP_TIME BT_SOCK_NAME_EXT_ADP_PRX
#define BT_SOCK_NAME_EXT_ADP_HDP_DATA_PREFIX "bt.ext.hdp."
#define BT_SOCK_NAME_EXT_ADP_HDP "bt.ext.adp.hdp"
// #define BT_SOCK_NAME_EXT_ADP_HTP "bt.ext.adp.htp"
#define BT_SOCK_NAME_EXT_ADP_HTP BT_SOCK_NAME_EXT_ADP_PRX
#define BT_SOCK_NAME_EXT_ADP_FMP "bt.ext.adp.fmp"
#define BT_SOCK_NAME_EXT_ADP_ADVANCED "bt.ext.adp.advanced"
#define BT_SOCK_NAME_EXT_ADP_GATTC "bt.ext.adp.gattc"
#define BT_SOCK_NAME_EXT_ADP_GATTS "bt.ext.adp.gatts"

#define BT30HS_NOT_ROOT 1
#ifdef BT30HS_NOT_ROOT
#define BT_SOCK_NAME_PAL "palbt_bt30hs"
#else
#define BT_SOCK_NAME_PAL "/dev/socket/palbt"
#endif
#ifdef __BT_SINGLE_ANTENNA__
#define WIFI_SOCK_NAME "bwcs.wifi"
#endif
#define BT_SOCK_NAME_INT_ADP_BTTM "bt.int.adp.bttm"



typedef enum
{
    PROFILE_A2DP = 0,
    PROFILE_A2DP_DATA,
    PROFILE_HFP,
    PROFILE_SPP,
    PROFILE_AVRCP,
    PROFILE_OPP,
    PROFILE_BIP,
    PROFILE_BPP,
    PROFILE_FTP,
    PROFILE_PBAP,
    PROFILE_HID,
    PROFILE_PAN,
    PROFILE_SIMAP,
    PROFILE_JSR82,
    PROFILE_PRX,
    PROFILE_MAP,
    PROFILE_TIME,
    PROFILE_HDP,
    PROFILE_HTP,
    PROFILE_FMP,
    PROFILE_GATTC,
    PROFILE_GATTS,
    PROFILE_GAP,
    PROFILE_ADVANCED,  //For advanced profiles control service
    NUM_OF_PROFILE,
} PROFILE_enum;

/*
typedef struct _PROFILE_ADDR
{
    struct sockaddr_un     addr;
    socklen_t                       addrlen;
} PROFILE_ADDR;
*/

// BOOL bt_setProfileAddress(PROFILE_enum profile, struct sockaddr_un *addr, socklen_t addrlen);
void bt_removeProfileAddress(PROFILE_enum profile);
void bt_messagehdl_init(void);
U8 bt_enQueue_message(module_type mod_type, void *ptr, U16 size);
void *bt_deQueue_message(module_type mod_type);
void bt_ResumeThread(module_type type);
#else
void win_messagehdl_init(void);
void win_enQueue_message(module_type mod_type, void *ptr);
void *win_deQueue_message(module_type mod_type);
void win_ResumeThread(module_type type);
#endif
void free_ilm(void *ptr);
void *construct_local_para(U16 size, U8 type);
void free_local_para(void *ptr);

void *bt_win_malloc(U32 size);
void bt_win_free(void *ptr);

// #define free_ctrl_buffer bt_win_free
#define free_ctrl_buffer OS_MemFree

// #define get_ctrl_buffer bt_win_malloc
#define get_ctrl_buffer OS_MemAlloc

#endif  /* BTMTK_ON_MAUI */


#if defined(BTMTK_ON_MAUI)
#define BTMTK_ASSERT(exp) (((exp) != 0) ? (void)0 : kal_assert_fail(#exp, __FILE__, __LINE__, FALSE, 0, 0, 0, NULL))
#else
void btmtk_assert(char* expr, char* file, U32 line);

#define BTMTK_ASSERT(exp)  (((exp) != 0) ? (void)0 : (void)btmtk_assert(#exp, __FILE__, __LINE__))
#endif

#endif  /* __BT_MMI_H__ */

