
#ifndef __GB_WG_DATATYPEDEF_H__
#define __GB_WG_DATATYPEDEF_H__

#include<stdio.h>
#include<string.h>
#include<Stdlib.h>


typedef char                        GB_CHAR;
typedef unsigned char               GB_BYTE;
typedef signed short                GB_SHORT;
typedef unsigned short              GB_USHORT;
typedef signed long					GB_LONG;
typedef unsigned long				GB_ULONG;
typedef int                         GB_INT;
typedef unsigned int                GB_UINT;
typedef unsigned char*              GB_PU8;

typedef unsigned int 				GB_U32;
typedef unsigned short              GB_U16;
typedef unsigned char               GB_U8;
typedef int                         GB_BOOL;
typedef void                        GB_VOID;
typedef signed char                 GB_S8;
typedef signed short                GB_S16;
typedef signed char*                GB_PS8;
typedef signed char                 GB_INT8;
typedef GB_INT                      GBRETURN ;
typedef unsigned short              GB_WCHAR;
typedef const GB_WCHAR*             GB_CPWSTR;
typedef GB_WCHAR                    GB_CHARTYPE;
typedef GB_WCHAR*                   GB_STRTYPE;

typedef GB_LONG                     GB_COLOR;

#define GB_NULL					((void*)0)
#define GB_FALSE  				0
#define GB_TRUE  				1

typedef struct  
{
	GB_SHORT x;
	GB_SHORT y;
}GB_POINT;

											    			
#endif // #define __GB_WG_DATATYPEDEF_H__
