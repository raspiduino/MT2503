/******************************************************************************
 * track_os_data_types.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        基础数据类型 定义
 *
 * modification history
 * --------------------
 * v1.0   2012-07-15,  chengjun create this file
 *
 ******************************************************************************/

#ifndef _TRACK_DATA_TYPES_H
#define _TRACK_DATA_TYPES_H


/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "clib.h"
#include "kal_general_types.h"
/*******************************************************************************
 * Type Definitions
 *******************************************************************************/
/*
 * general definitions
 */
typedef signed char                       int8;
typedef signed short                      int16;
typedef signed long                       int32;
typedef signed int                        intx;
typedef unsigned char                     uint8;
typedef unsigned short                    uint16;
typedef unsigned long                     uint32;
typedef unsigned int                      uintx;

typedef unsigned char                     U8;
typedef char                                  S8;       //0-255  
typedef unsigned short                    U16;
typedef signed short                      S16;
typedef unsigned int                      U32;
typedef signed int                        S32;

typedef unsigned char                     US8;
typedef unsigned short                    US16;
typedef unsigned int                      US32;

typedef volatile unsigned char *          P_U8;
typedef volatile signed char *            P_S8;
typedef volatile unsigned short *         P_U16;
typedef volatile signed short *           P_S16;
typedef volatile unsigned int *           P_U32;
typedef volatile signed int *             P_S32;

typedef volatile const unsigned char *    CONST_P_U8;
typedef volatile const signed char *      CONST_P_S8;
typedef volatile const unsigned short *   CONST_P_U16;
typedef volatile const signed short *     CONST_P_S16;
typedef volatile const unsigned int *     CONST_P_U32;
typedef volatile const signed int *       CONST_P_S32;

#if !defined(WIN32)
typedef unsigned long long                U64;
typedef signed long long                  S64;
typedef unsigned long long *              P_U64;
typedef signed long long *                P_S64;
#endif

#ifndef __cplusplus
typedef unsigned char  bool;
#endif

/* portable character for multichar character set */
typedef char                    kal_char;
/* portable wide character for unicode character set */
typedef unsigned short          kal_wchar;

/* portable 8-bit unsigned integer */
typedef unsigned char           kal_uint8;
/* portable 8-bit signed integer */
typedef signed char             kal_int8;
/* portable 16-bit unsigned integer */
typedef unsigned short int      kal_uint16;
/* portable 16-bit signed integer */
typedef signed short int        kal_int16;
/* portable 32-bit unsigned integer */
typedef unsigned int            kal_uint32;
/* portable 32-bit signed integer */
typedef signed int              kal_int32;

#if !defined(GEN_FOR_PC) && !defined(__MTK_TARGET__)
/* portable 64-bit unsigned integer */
typedef unsigned __int64     kal_uint64;
/* portable 64-bit signed integer */
typedef __int64              kal_int64;
#else
/* portable 64-bit unsigned integer */
typedef unsigned long long   kal_uint64;
/* portable 64-bit signed integer */
typedef signed long long     kal_int64;
#endif

/*
 * Definitions for BOOLEAN
 */

#ifndef FALSE
#define FALSE          0
#endif 

#ifndef TRUE
#define TRUE           1
#endif 

#ifndef NULL
#define NULL               0
#endif


#if !defined(_WINNT_H) && !defined(_WINNT_)
typedef unsigned short WCHAR;
#endif

#ifdef __vxworks
typedef int BOOL;
#else
typedef unsigned char  BOOL;
#endif

#define YES   (BOOL)1
#define NO    (BOOL)0

#define YES_GO_ON       (BOOL)1
#define NO_STOP         (BOOL)0

typedef void (*FuncPtr) (void);

#endif  /* _TRACK_DATA_TYPES_H */