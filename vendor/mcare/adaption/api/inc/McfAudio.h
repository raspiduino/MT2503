#ifndef _mcfaudio_h_
#define _mcfaudio_h_

#include "McfCommon.h"

MINT  McfAud_PlayStream(MVOID *pUser,MVOID *pAudioData,MUINT len,MBYTE format,MBYTE playStyle, pfnMcfAudFunc handler);
MINT  McfAud_StopStream (MINT audHd);
MINT  McfAud_PlayFile(MVOID *pUser,MSHORT *pFile,MBYTE playStyle, pfnMcfAudFunc handler);
MINT  McfAud_StopFile(MINT audHd);
MINT  McfAud_Pause(MINT audHd,MVOID *pUser,pfnMcfAudFunc handler);
MINT  McfAud_Resume(MINT audHd,MVOID *pUser,pfnMcfAudFunc handler);
MVOID McfAud_SetVolume(MINT audHd ,MBYTE volume);
MVOID McfAud_StopAll(MVOID);


MINT McfAud_StartRecord(MVOID *pUser,McfAudRecord *pRecord,pfnAudFunc fnAudRecd);
MINT McfAud_StopRecord(MINT nHd);
MINT McfAud_GetDuration(MUINT *pDuration, MINT nType,MVOID *pSource,MINT nFormat,MINT nLen);

#endif
