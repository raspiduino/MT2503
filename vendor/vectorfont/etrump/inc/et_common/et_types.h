///////////////////////////////////////////////////////////////////////
/// \file       et_types.h
/// \brief      types definitions
/// \details
/// <br><br>
/// Chang Log: <br>
///   0.1       Zheng Xu     Initialize <br>
///
/// \author     Zheng Xu<zxu@etrump.net>
/// \version    0.1
/// \date       October 2010
///
///////////////////////////////////////////////////////////////////////
#ifndef __ET_TYPES_H__
#define __ET_TYPES_H__

typedef     signed char     ET_SINT8;   ///< 8-bit signed int
typedef     signed short    ET_SINT16;  ///< 16-bit signed int
typedef     signed long     ET_SINT32;  ///< 32-bit signed int

typedef     unsigned char   ET_UINT8;   ///< 8-bit unsigned int
typedef     unsigned short  ET_UINT16;  ///< 16-bit unsigned int
typedef     unsigned long   ET_UINT32;  ///< 32-bit unsigned int

typedef     char            ET_CHAR;    ///< char
typedef     ET_SINT32       ET_BOOL;    ///< boolean
typedef     float           ET_FLOAT;   ///< float
typedef     void            ET_VOID;    ///< void
typedef     void*           ET_HANDLE;  ///< handle

/// define true
#ifndef TRUE
#define TRUE     (1)
#endif
/// define false
#ifndef FALSE
#define FALSE    (0)
#endif

/// used to declare that the parameter is passed to a function
#ifndef IN
#define IN
#endif
/// used to declare that the parameter will contain a return value
#ifndef OUT
#define OUT
#endif
/// used to declare that the parameter will be used bidirectionally
#ifndef INOUT
#define INOUT
#endif

/// define null
#ifndef NULL
#define NULL     ((ET_HANDLE)0)
#endif

/// used to declare API functions
#ifdef __cplusplus
#define ET_API extern "C"
#else
#define ET_API
#endif

/// used to declare local functions that only be used with-in a module
#ifdef __cplusplus
#define ET_LOCAL extern "C"
#else
#define ET_LOCAL
#endif

/// used to declare static functions that only be used with-in a file
#define ET_STATIC static

#endif
