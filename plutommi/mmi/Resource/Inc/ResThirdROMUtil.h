#ifndef __RES_THIRD_ROM_UTIL_H__
#define __RES_THIRD_ROM_UTIL_H__

#include "ResCompressConfig.h"
    
#if !defined(__MTK_TARGET__)
    #define MMI_RESOURCE_NFB_RES_Load(cid, dst_addr, offset, length)  MMI_NFB_RES_Load(cid, dst_addr, offset, length)   
    extern int MMI_NFB_RES_Load(unsigned char cid, void *dst_addr, unsigned int offset, unsigned int length);
#else
    #define MMI_RESOURCE_NFB_RES_Load(cid, dst_addr, offset, length) NFB_RES_Load(cid, dst_addr, offset, length)
#endif //__MTK_TARGET__

#endif //__RES_THIRD_ROM_UTIL_H__