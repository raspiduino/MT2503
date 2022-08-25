/*****************************************************************************
 *
 * Filename:  	c_RamBuffer.h
 *   
 *   
 * Author :    	MagicNing
 * 
 *
 * Date : 	2010-03-16
 * 
 *
 * Comment:  C_STL 控件的内存处理
 *
 *
 ****************************************************************************/

#ifndef __C_RAMBUFFER_H__
#define __C_RAMBUFFER_H__

/****************************************************************************
* Include Files                   		包含头文件                                             
*****************************************************************************/
#include "GlobalDefs.h"
#include "GlobalConstants.h"
#include "PixtelDataTypes.h"
#include "stack_common.h"          /* message and module IDs */
#include "stack_msgs.h"            /* enum for message IDs */
#include "stdlib.h"
#include "app_ltlcom.h"
#include "Device.h"
#include <math.h>
#include "ems.h"


/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
//#define __RAMBUFFER_DEBUG__

#define RAMBUFFER_LENGHT    ( 600 * 1024 )  // ( 1024 * 1024 )    /*1M 内存空间*/
#define RAMBUFFER_APP_MAX    10
#define RAMBUFFER_ALLOC_ONE_MAX 600000           /*单次可申请的最大空间*/

#define Ram_Alloc(appid, mem_size)          Ram_Alloc1(__func__, appid, mem_size)
#define Ram_Free(mem_addr)                  Ram_Free1(__func__, &mem_addr)

/***************************************************************************** 
* Typedef  Enum
*****************************************************************************/


/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/




/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/



/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/
extern BOOL RamBuffer_Init(void);
extern BOOL RamBuffer_Release(void);
//extern void* RamBuffer_Alloc(U32 mem_size);
//extern void RamBuffer_Free(void *mem_addr);




#endif	/*	#ifndef __C_RAMBUFFER_H__	*/


