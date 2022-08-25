/**
File: IG_JE.h
Author: Arvin Luo
Creat date: 2011.3.9
*/
#ifdef __cplusplus
extern "C"
{
#endif

#include "IG_LA_FactorDef.h"

#ifndef   __IG_LA_JE_H_ 
#define   __IG_LA_JE_H_ 


#if _IG_JE_

void IG_LA_JE_Init(IGV5RC *pThisRC);
void IG_LA_JE_Update(IGV5RC *pThisRC, float fFrameTime,unsigned uNumEvents, IGV5Event *pEventsArray);
void IG_LA_JE_Unload(IGV5RC *pThisRC);
void IG_LA_JE_Resume(void);
void IG_LA_JE_Suspend(void);

#endif

#endif

#ifdef __cplusplus
}
#endif