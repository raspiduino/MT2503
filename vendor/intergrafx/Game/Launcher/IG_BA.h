#ifdef __cplusplus
extern "C" {
#endif
/**
File: IG_BA.h
Author: Arvin Luo
Creat date: 2011.3.9
*/
#include "IG_Launcher_FactorDef.h"

#ifndef   __IG_BA_H_ 
#define   __IG_BA_H_ 


#if _IG_BA_
	void BALLSTICK_onInit(void* memBuff,long  memSize ,void* dispBuff,int dispWidth,int dispHeight,int maskRed,
						 int maskGreen,int maskBlue,int isTopDown,IGMemoryPool  *system_mem);
	void BALLSTICK_onUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE);
	void BALLSTICK_onEnd();
#endif

#endif

#ifdef __cplusplus
}
#endif
