
#ifndef __IG_LA_FUNCTION__H_
#define __IG_LA_FUNCTION__H_

#ifdef IGV5_MTK_PHONE
#include "ig3d_adaptation56.h"

IG_FS_HANDLE IG_LA_OpenForRead(IGCHAR *FileName);
int IG_LA_ReadFromFile(IG_FS_HANDLE handle,byte readbuf[],IGU32 Length);
int IG_LA_LA_WriteInt(unsigned char writenbuf[],int i,int index);
int IG_LA_LA_WriteOrCreatFileAndWrite(IGCHAR *FileName,unsigned char writenbuf[],int Length);
#endif

int IG_LA_LA_ResetLauncherStatus(void);
int IG_LA_ReadInt(unsigned char readbuf[],int index);
char IG_LA_isOnTouch(int x,int y,int x1,int y1,int x2,int y2);






#endif

