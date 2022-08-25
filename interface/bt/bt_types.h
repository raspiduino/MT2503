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
 * Bt_types.h
 *
 * Project:
 * --------
 *   BT Project
 *
 * Description:
 * ------------
 *   This file is used to
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
#ifndef __BT_KAL_RELEASE_H
#define __BT_KAL_RELEASE_H

#include "bt_config.h"
#include "btostypes.h"

#ifdef BTMTK_ON_MAUI
#include "kal_release.h"    /* for kal types */
#include "app_ltlcom.h"     /* for ilm_struct */
#include "stack_config.h"   /* for module_type */
#endif /* BTMTK_ON_MAUI*/

// TODO: To be removed
#ifndef BTMTK_ON_MAUI
typedef unsigned int kal_uint32;
typedef unsigned short kal_uint16;
typedef unsigned char kal_uint8;

typedef unsigned char kal_bool;

typedef long kal_int32;
typedef short kal_int16;
typedef char kal_int8;
typedef char kal_char;

typedef unsigned short WCHAR;
#endif  /* BTMTK_ON_MAUI */

//#ifndef BOOL
//#define BOOL unsigned char  /* IGNORESTYLE */
//#endif

// Basic types are defined in btostypes.h
#if 0
#ifndef U64
/* under construction !*/
#endif
/* under construction !*/
#ifndef U32
/* under construction !*/
#endif
/* under construction !*/
#ifndef U16
/* under construction !*/
#endif
/* under construction !*/
#ifndef U8
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifndef S32
/* under construction !*/
#endif
/* under construction !*/
#ifndef S16
/* under construction !*/
#endif
/* under construction !*/
#ifndef S8
/* under construction !*/
#endif
/* under construction !*/
#endif

// TODO: To be removed
#ifndef BT_BOOL
#define BT_BOOL char
#endif

#ifndef TRUE
#define TRUE  (1==1)
#endif

#ifndef FALSE
#define FALSE (0==1)
#endif

/**
* String could be unicode or codepage.
* Codepage should only used in external platform's porting implement.
* ASCII should use U8 to present a character.(1B)
* Unicode has UCS2(Always 2 byte, Mapping of Unicode character planes),
*    UTF8(1,2,4B), UTF16(2,4B), UTF32 formats.
* Note: WCHAR primitive type has be defined in Linux(4B) - UTF32 format
* Note: WCHAR primitive type has be defined in WINDOS(2B) - UCS2 format
*/
/* UCS2 String in little endian */
#ifndef W16
#define W16
#endif

/* UTF8, UTF16, ASCII use U8 to present it */


/*
 * Variable sized integers. Used to optimize processor efficiency by
 * using the most efficient data size for counters, arithmatic, etc.
 */
#ifndef I32
#define I32 unsigned long
#endif


#if XA_INTEGER_SIZE == 4
#ifndef I16
#define I16 unsigned long
#endif

#ifndef I8
#define I8 unsigned long
#endif


#elif XA_INTEGER_SIZE == 2

#ifndef I16
#define I16 unsigned short
#endif

#ifndef I8
#define I8 unsigned short
#endif


#elif XA_INTEGER_SIZE == 1
#ifndef I16
#define I16 unsigned short
#endif

#ifndef I8
#define I8 unsigned char
#endif

#else
#error No XA_INTEGER_SIZE specified!
#endif

// TODO: To be removed
#ifndef BTMTK_ON_MAUI
#define KAL_TRUE (1)
#define KAL_FALSE (0)
#endif  /* BTMTK_ON_MAUI */

#ifndef NULL
#define NULL 0
#endif

#ifndef BTMTK_ON_MAUI
#define UART_PORT kal_uint8
#endif  /* BTMTK_ON_MAUI */

#ifndef BT_UUID
typedef struct
{
    /* the len can only be 2, 4, or 16 */
    U8 len;
    U8 uuid[16];
} BT_UUID;
#endif

#ifndef ATT_UUID
typedef struct
{
    BT_UUID uuid;
    U8 inst;
} ATT_UUID;
#endif

#ifndef GATT_SVC_UUID
typedef struct
{
    ATT_UUID uuid;
    U8 is_primary;
} GATT_SVC_UUID;
#endif

#ifndef ATT_MAX_VALUE_LEN
#ifdef __BLUEANGEL_MEMORY_REDUCE__
#define ATT_MAX_VALUE_LEN 23
#else
#define ATT_MAX_VALUE_LEN 512
#endif /* __BLUEANGEL_MEMORY_REDUCE__ */
#endif

#ifndef ATT_VALUE
typedef struct
{
    U16 len;
    U8 value[ATT_MAX_VALUE_LEN];
} ATT_VALUE;
#endif

#ifndef ATT_HANDLE
typedef U16 ATT_HANDLE;
#endif

#define INVALID_ATT_HANDLE 0xFFFF

#endif /* BT_KAL_RELEASE */

