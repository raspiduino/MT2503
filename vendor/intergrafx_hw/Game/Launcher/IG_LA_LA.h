#ifndef __IG_LA_LA__H_
#define __IG_LA_LA__H_

void IG_LA_InitTexureData(void);
void IG_LA_Launcher_Init(IGV5RC *pThisRC);
void IG_LA_Launcher_Update(IGV5RC *pThisRC, float fFrameTime,unsigned uNumEvents, IGV5Event *pEventsArray);
void IG_LA_Launcher_Unload(void);
void IG_LA_LA_Suspend(void);

#endif

