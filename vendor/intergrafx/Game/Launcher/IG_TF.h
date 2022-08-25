#ifdef __cplusplus
extern "C" {
#endif
/**
File: IG_TF.h
Author: Arvin Luo
Creat date: 2011.3.9
*/
#include "IG_Launcher_FactorDef.h"

#ifndef   __IG_TF_H_ 
#define   __IG_TF_H_ 


#if _IG_TF_
	void IG_TF_Tank_onInit(void* memBuff,long  memSize , void* dispBuff , int dispWidth,int dispHeight,int maskRed,
						 int maskGreen,int maskBlue,int isTopDown,IGMemoryPool  *system_mem);
	void IG_TF_Tank_onUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE);
	void IG_TF_Tank_onEnd(void);
#endif

#endif

#ifdef __cplusplus
}
#endif
