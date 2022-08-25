#ifndef __COMPRESS_RES_UTIL_H__
#define __COMPRESS_RES_UTIL_H__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ResCompressConfig.h"

#if defined(__MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__) || defined(__MMI_RESOURCE_STR_LZMA_COMPRESS__)
extern S32 mmi_res_lzma_decompress_static_buffer(U8 *dest, U32 destLen, const U8 *source, U32 sourceLen);

#ifdef __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__
extern S32 mmi_res_lzma_decompress(U8 *dest, U32 destLen, const U8 *source, U32 sourceLen, void * workingBuffer);
#endif //__MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__

#endif //__MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__ || __MMI_RESOURCE_STR_LZMA_COMPRESS__

#endif //__COMPRESS_RES_UTIL_H__
