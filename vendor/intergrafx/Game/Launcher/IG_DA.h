/**
File: IG_DA.h
Author: Arvin Luo
Creat date: 2011.3.9
*/
#ifdef __cplusplus
extern "C"
{
#endif

#include "IG_Launcher_FactorDef.h"

#ifndef   __IG_DA_H_ 
#define   __IG_DA_H_ 


#if _IG_DA_
	void IG_DA_onInit(void* memBuff,long  memSize ,void* dispBuff, int dispWidth,int dispHeight,int maskRed,
							 int maskGreen,int maskBlue,int isTopDown,IGMemoryPool  *system_mem);
	void IG_DA_onUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE);
	void IG_DA_onEnd();
#endif

#endif

#ifdef __cplusplus
}
#endif