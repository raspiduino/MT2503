/***************************************************************************
* File Name    :  gbtype.h
* Corporation  :  Guobi Technology Ltd. GuangZhou China
* Copyright    :  Copyright Guobi Technology Ltd. And Subject to Confidentiality 
*                 Restrictions. This document is the confidential and proprietary 
*                 property of Guobi Technology Ltd.It is neither the document                  *                 itself nor any part of it can be shared with any party  without 
*                 the written  permission. 
* Author       :  chenbinghui
* Date         :  2009-6-18
* Purpose      :  v5 GB API 可移植的类型定义
* Version      :  V1.0
* Last Changed List
* Name         |   date   |  Discription
****************************************************************************/

#ifndef __GBTYPE_H__
#define __GBTYPE_H__



/* adding for GinWave */
#ifndef _gb_far
#ifdef _C166
#define _gb_far _huge
//#pragma nocustack
#else
#define _gb_far
#endif
#endif

typedef unsigned short  GBCHAR;
typedef unsigned short  GBUCHAR;

typedef GBUCHAR							GBCHARU;


typedef unsigned char                   GBUINT8;
typedef signed char                     GBINT8;
typedef unsigned char					GBBYTE;

typedef unsigned short                  GBWCHAR;
typedef char                            GBACHAR;
typedef unsigned char                   GBUACHAR;

typedef GBWCHAR *                       GBPWCHAR;
typedef GBWCHAR _gb_far *               GBLPWCHAR;
typedef const GBWCHAR *                 GBPCWCHAR;
typedef const GBWCHAR _gb_far *         GBLPCWCHAR;

typedef GBACHAR *                       GBPACHAR;
typedef GBACHAR _gb_far *               GBLPACHAR;
typedef const GBACHAR *                 GBPCACHAR;
typedef const GBACHAR _gb_far *         GBLPCACHAR;
typedef GBACHAR _gb_far const * const * GBPCLPCACHAR;

typedef GBUACHAR *                      GBPUACHAR;
typedef GBUACHAR _gb_far *              GBLPUACHAR;
typedef const GBUACHAR *                GBPCUACHAR;
typedef const GBUACHAR _gb_far *        GBLPCUACHAR;

typedef short                           GBINT16;
typedef long                            GBINT32;
typedef unsigned short                  GBUINT16;
typedef unsigned long                   GBUINT32;

// start modify [2011-7-1 Zhaokun]
#ifdef _C166
typedef long                             GBINT;
typedef unsigned long                    GBUINT;
#else
typedef int                             GBINT;
typedef unsigned int                    GBUINT;
#endif
// end modify [2011-7-1 Zhaokun]

typedef GBCHAR *                        GBPCHAR;
typedef GBUCHAR *						GBPUCHAR;
typedef GBINT16 *                       GBPINT16;
typedef GBUINT16 *                      GBPUINT16;
typedef GBINT32 *                       GBPINT32;
typedef GBUINT32 *                      GBPUINT32;

typedef GBCHAR _gb_far *                GBLPCHAR;
typedef GBUCHAR _gb_far *				GBLPUCHAR;
typedef GBINT16 _gb_far *               GBLPINT16;
typedef GBUINT16 _gb_far *              GBLPUINT16;
typedef GBINT32 _gb_far *               GBLPINT32;
typedef GBUINT32 _gb_far *              GBLPUINT32;

typedef const unsigned short *          GBPCUSHORT;
typedef unsigned short  *               GBPUSHORT;

typedef const GBCHAR *                  GBPCCHAR;
typedef const GBINT16 *                 GBPCINT16;
typedef const GBUINT16 *                GBPCUINT16;
typedef const GBINT32 *                 GBPCINT32;
typedef const GBUINT32 *                GBPCUINT32;

typedef const GBCHAR _gb_far *          GBLPCCHAR;
typedef const GBUCHAR _gb_far *			GBLPCUCHAR;
typedef const GBINT16 _gb_far *         GBLPCINT16;
typedef const GBUINT16 _gb_far *        GBLPCUINT16;
typedef const GBINT32 _gb_far *         GBLPCINT32;
typedef const GBUINT32 _gb_far *        GBLPCUINT32;

/**********/
typedef const unsigned short _gb_far *	GBLPCUSHORT;
typedef unsigned short _gb_far *		GBLPUSHORT;

typedef GBBYTE *						GBPBYTE;
typedef GBBYTE _gb_far *				GBLPBYTE;
typedef const GBBYTE *					GBPCBYTE;
typedef const GBBYTE _gb_far *			GBLPCBYTE;

#ifdef _C166
typedef long *							GBPINT;
typedef unsigned long *					GBPUINT;

typedef long _gb_far *					GBLPINT;
typedef unsigned long _gb_far *			GBLPUINT;
#else
typedef int *							GBPINT;
typedef unsigned int *					GBPUINT;

typedef int _gb_far *					GBLPINT;
typedef unsigned int _gb_far *			GBLPUINT;
#endif

typedef void *							GBPVOID;
typedef const void *					GBPCVOID;

typedef void _gb_far *					GBLPVOID;
typedef const void _gb_far *			GBLPCVOID;

typedef GBUINT8							GBU8;
typedef GBUINT16    					GBU16;
typedef GBUINT32						GBU32;
typedef GBINT							GBI;
typedef GBUINT							GBU;
typedef GBINT8							GBI8;
typedef GBINT16							GBI16;
typedef GBINT32							GBI32;

typedef const GBINT8 *					GBPCI8;
typedef const GBINT16 *                 GBPCI16;
typedef const GBUINT16 *                GBPCU16;
typedef const GBINT32 *                 GBPCI32;
typedef const GBUINT32 *                GBPCU32;

typedef const GBINT8 _gb_far *			GBLPCI8;
typedef const GBINT16 _gb_far *         GBLPCI16;
typedef const GBUINT16 _gb_far *        GBLPCU16;
typedef const GBINT32 _gb_far *         GBLPCI32;
typedef const GBUINT32 _gb_far *        GBLPCU32;

//应用类型定义
typedef GBINT							GBRETURN ;
typedef GBINT							GBBOOL;
typedef GBU16							GBKEY;
typedef GBU16							GBLANG;
typedef GBU16							GBSUBLANG;
typedef GBU16							GB_CHN_ISN;
typedef GBBYTE							ENCODING_TYPE;
typedef GBLPCBYTE						pENCODING_TYPE;
//typedef GBWCHAR							GBEVENT;
typedef GBU8							GBINPUTMODE;
typedef GBU32							GBUDBID;
typedef GBINT							GBHRESULT; ///<键盘处理函数的处理结果

#define GBTrue							1
#define GBFalse							0

//start[2010-4-15 zhj]
typedef GBINT							GBEVENT;
//end[2010-4-15 zhj]

////start[2010-4-15 zhj]
//typedef void * pGBFILE;
////[2010-4-15 zhj]


//start[2010-4-15 haj]
typedef void *							 GBIMAGEHANDLE;
typedef void *							 GBFILEHANDLE;
//end[2010-4-15 haj]

// start add [2011-5-24 haj]
typedef void *                          GBPFILE; ///> 文件句柄指针
// end add [2011-5-24 haj]

#endif
