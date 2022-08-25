#ifdef __cplusplus
extern "C" {
#endif

#include "IG_LA_FactorDef.h"

#ifndef   __IG_LA_TK_H_ 
#define   __IG_LA_TK_H_ 


#if _IG_TK_


void IG_LA_Tank_Init(IGV5RC *pThisRC);
void IG_LA_Tank_Update(IGV5RC *pThisRC, float fFrameTime,unsigned uNumEvents, IGV5Event *pEventsArray);
void IG_LA_Tank_Unload(IGV5RC *pThisRC);
void IG_LA_TK_Resume(void);
void IG_LA_TK_Suspend(void);

#endif

#endif

#ifdef __cplusplus
}
#endif
