/*******************************************************************************
 *
 * Filename:
 * ---------
 * btostypes.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file is used to define common OS data types
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
#ifndef __BTOSTYPES_H
#define __BTOSTYPES_H

#include "kal_release.h"    /* for kal types */
#include "app_ltlcom.h"     /* for ilm_struct */
#include "stack_config.h"   /* for module_type */

#include "fs_type.h"
#include "event_shed.h"     /* Event scheduler */

#define XA_INTEGER_SIZE 2   //TODO:

#ifndef U64
#define U64 unsigned long long
#endif

#ifndef U32
#define U32 kal_uint32
#endif

#ifndef U16
#define U16 kal_uint16
#endif

#ifndef U8
#define U8 kal_uint8
#endif


#ifndef S32
#define S32 signed int
#endif

#ifndef S16
#define S16 signed short
#endif

#ifndef S8
#define S8 char
#endif

#ifndef BOOL
#define BOOL unsigned char    //Todo
#endif

#ifndef BT_BOOL
#define BT_BOOL unsigned char    //Todo
#endif

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

#ifndef TRUE
#define TRUE  (1==1)
#endif 

#ifndef FALSE
#define FALSE (0==1)
#endif 

#ifndef NULL
#define NULL 0
#endif

//#define UART_PORT U8

//TODO: needs define some temp path 
#define BT_DB_FILE L"Z:\\@bt\\devdb"
#define BT_DB_COD_FILE L"Z:\\@bt\\cod"
#define BT_DB_PATH L"Z:\\@bt\\"

#ifdef __BT_4_0_BLE__
#define BT_DB_LE_FILE BT_DB_PATH"/le"
#endif

#define FS_MAX_PATH_LEN FS_MAX_PATH	
#define BT_MODULE_MAX_MEMORY_BLOCK_SIZE 512

#ifndef OS_FS_HANDLE
#define OS_FS_HANDLE S32                 //  Todo:Need define as U32?
#endif

#ifndef FHANDLE_INVALID_VALUE
#define FHANDLE_INVALID_VALUE      0     //  FileHanel <0 invalid. 0 is invalid. >0 is valid.
#endif


typedef void (*OS_Timer_Cb)(void *);

// TODO: 
typedef struct _os_timer_t {
	OS_Timer_Cb callback;
	void *cntx;
	U32	ms;

	eventid event_id;
    event_scheduler *evsh_sched;
} OS_TIMER;



#endif 

