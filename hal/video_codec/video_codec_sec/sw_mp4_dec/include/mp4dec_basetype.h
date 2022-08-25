/*------------------------------------------------------------------------------
--                                                                            --
--       This software is confidential and proprietary and may be used        --
--        only as expressly authorized by a licensing agreement from          --
--                                                                            --
--                            Hantro Products Oy.                             --
--                                                                            --
--      In the event of publication, the following notice is applicable:      --
--                                                                            --
--                   (C) COPYRIGHT 2004-2006 HANTRO PRODUCTS OY               --
--                            ALL RIGHTS RESERVED                             --
--                                                                            --
--         The entire notice above must be reproduced on all copies.          --
--                                                                            --
--------------------------------------------------------------------------------
--
--  Abstract : Basic type definitions.
--
---------------------------------------------------------------------------*/


#ifndef MP4DECBASETYPE_H_INCLUDED
#define MP4DECBASETYPE_H_INCLUDED


#ifdef __arm
#define VOLATILE volatile
#else
#define VOLATILE
#endif

typedef unsigned char   u8;
typedef signed char     i8;
typedef unsigned short  u16;
typedef signed short    i16;
typedef unsigned int    u32;
typedef signed int      i32;

#if defined(VC1SWDEC_16BIT) || defined(MP4ENC_ARM11)
typedef unsigned short  u16x;
typedef signed short    i16x;
#else
typedef unsigned int    u16x;
typedef signed int      i16x;
#endif


#ifndef NULL
#ifdef  __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
#endif

#if !defined(GEN_FOR_PC) && !defined(__MTK_TARGET__) && !defined(GCC_COMPILER)
/* portable 64-bit unsigned integer */
   typedef unsigned __int64     uint64;
/* portable 64-bit signed integer */
   typedef __int64              int64;
#else
/* portable 64-bit unsigned integer */
   typedef unsigned long long   uint64;
/* portable 64-bit signed integer */
   typedef signed long long     int64;
#endif

/* boolean representation */
typedef enum 
{
    /* FALSE value */
    FG_FALSE,
    /* TRUE value */
    FG_TRUE
} FG_BOOL;


#endif  /* MP4DECBASETYPE_H_INCLUDED */
