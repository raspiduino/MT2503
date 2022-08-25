#ifndef __XATYPES_H
#define __XATYPES_H
/***************************************************************************
 *
 * File:
 *     $Workfile:xatypes.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision:21$
 *
 * Description:
 *     This file contains declarations for iAnywhere (formerly iAnywhere)
 *     protocol stacks.
 *
 * Created:
 *     November 19, 1996
 *
 * Copyright 1999-2005 Extended Systems, Inc.
 * Portions copyright 2005 iAnywhere Solutions, Inc.
 * All rights reserved. All unpublished rights reserved.
 *
 * Unpublished Confidential Information of iAnywhere Solutions, Inc.  
 * Do Not Disclose.
 *
 * No part of this work may be used or reproduced in any form or by any 
 * means, or stored in a database or retrieval system, without prior written 
 * permission of iAnywhere Solutions, Inc.
 * 
 * Use of this work is governed by a license granted by iAnywhere Solutions, 
 * Inc.  This work contains confidential and proprietary information of 
 * iAnywhere Solutions, Inc. which is protected by copyright, trade secret, 
 * trademark and other intellectual property rights.
 *
 ****************************************************************************/
#include "btdrv_config.h"
#include "kal_general_types.h"
/****************************************************************************
 *
 * Base definitions used by the stack and framer
 *
 ****************************************************************************/

#ifndef BOOL_DEFINED
#ifndef BOOL
typedef unsigned char BOOL; /* IGNORESTYLE */
#endif 
#endif

#ifndef U32
typedef kal_uint32 U32;
#endif

#ifndef U16
typedef kal_uint16 U16;
#endif

#ifndef U8
typedef kal_uint8 U8;
#endif

#ifndef S32
typedef signed int S32;
#endif

#ifndef S16
typedef signed short S16;
#endif

#ifndef S8
typedef char S8;
#endif

/*
 * Variable sized integers. Used to optimize processor efficiency by
 * using the most efficient data size for counters, arithmatic, etc.
 */
#ifndef  I32
typedef unsigned long I32;
#endif

#if XA_INTEGER_SIZE == 4
#ifndef I16
typedef unsigned long I16;
#endif
#ifndef I8
typedef unsigned long I8;
#endif
#elif XA_INTEGER_SIZE == 2
#ifndef I16
typedef unsigned short I16;
#endif
#ifndef I8
typedef unsigned short I8;
#endif
#elif XA_INTEGER_SIZE == 1
#ifndef I16
typedef unsigned short I16;
#endif
#ifndef I8
typedef unsigned char I8;
#endif
#else 
#error No XA_INTEGER_SIZE specified!
#endif 

typedef void (*PFV) (void);

/* Boolean Definitions */
#ifndef TRUE
#define TRUE  (1==1)
#endif 

#ifndef FALSE
#define FALSE (0==1)
#endif 

#ifndef BtStatus
typedef I8 BtStatus;
#endif

#endif /* __XATYPES_H */ 

