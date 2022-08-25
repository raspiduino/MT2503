
#ifndef __GB_WG_COMMONDEBUG_H__
#define __GB_WG_COMMONDEBUG_H__

#include "GB_WG_CommonConfig.h"
#include "GB_WG_DataTypeDef.h"

/* assert∂®“Â */
#if defined(WIN32) || defined(GB_WINGUO_DEBUG)
#if !defined(ASSERT)
extern GB_VOID GB_WG_Assert(GB_CHAR* expr, GB_CHAR* file, GB_UINT line, GB_INT n);
#define  ASSERT(n)  GB_WG_Assert((GB_CHAR*)#n, (GB_CHAR *)__FILE__, __LINE__, (GB_INT)(n))
#endif
#else // #if defined(WIN32) || defined(GB_WINGUO_DEBUG)
#if !defined(ASSERT)
#define ASSERT(n)	((void)0)
#endif
#endif // #if defined(WIN32) || defined(GB_WINGUO_DEBUG)


GB_VOID GB_WG_DebugPrintLog(const GB_CHAR *pFomat, ...);
GB_VOID GB_WG_DebugWriteData(GB_CHAR* pData, GB_INT len);


#if defined(GB_WINGUO_DEBUG)
#define Debug_TraceLog  GB_WG_DebugPrintLog
#define Debug_TraceData GB_WG_DebugWriteData
#else // #if defined(WIN32) || defined(GB_WINGUO_DEBUG)
#define Debug_TraceLog	(void)
#define Debug_TraceData (void)
#endif // #if defined(WIN32) || defined(GB_WINGUO_DEBUG)





#endif //__GB_WG_COMMONDEBUG_H__

