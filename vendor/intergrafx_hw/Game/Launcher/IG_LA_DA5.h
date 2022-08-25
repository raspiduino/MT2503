/**
File: IG_DA.h
Author: Arvin Luo
Creat date: 2011.3.9
*/
#ifdef __cplusplus
extern "C"
{
#endif

#include "IG_LA_FactorDef.h"

#ifndef   __IG_LA_DA5_H_ 
#define   __IG_LA_DA5_H_ 


#if _IG_DA5_

void IG_LA_DA5_Init(IGV5RC *pThisRC);
void IG_LA_DA5_Update(IGV5RC *pThisRC, float fFrameTime,unsigned uNumEvents, IGV5Event *pEventsArray);
void IG_LA_DA5_Unload(IGV5RC *pThisRC);
void IG_LA_DA5_Resume(void);
void IG_LA_DA5_Suspend(void);

#endif

#endif

#ifdef __cplusplus
}
#endif