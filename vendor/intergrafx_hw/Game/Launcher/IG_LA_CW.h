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

#ifndef   __IG_LA_CW_H 
#define   __IG_LA_CW_H 


#if _IG_CW_

void IG_LA_CW_Init(IGV5RC *pThisRC);
void IG_LA_CW_Update(IGV5RC *pThisRC, float fFrameTime,unsigned uNumEvents, IGV5Event *pEventsArray);
void IG_LA_CW_Unload(IGV5RC *pThisRC);
void IG_LA_CW_Resume(void);
void IG_LA_CW_Suspend(void);

#endif

#endif

#ifdef __cplusplus
}
#endif