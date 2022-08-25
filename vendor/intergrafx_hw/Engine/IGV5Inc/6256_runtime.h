/* vim:set sts=4 ts=4 noexpandtab: */


#ifndef __6256_runtime_h
#define __6256_runtime_h


#include "IGV5Renderer.h"



#ifdef __cplusplus
extern "C" {
#endif


unsigned IGV5Time_Init(void);
unsigned IGV5Time_GetElapsed(void);
unsigned IGV5Time_Get(void);
void IGV5Time_UpdateFPS(FrameStatics *pPF);

#ifdef __cplusplus
}
#endif

#endif /* __linux_runtime_h */


