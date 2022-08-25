#ifdef __cplusplus
extern "C" {
#endif
/**
File: IG_FT.h
Author: Arvin Luo
Creat date: 2011.4.14
*/

#ifndef   __IG_LA_Utils_ 
#define   __IG_LA_Utils_ 

#include "Launcher.h"

typedef unsigned char byte;

IG_FS_HANDLE IG_LA_OpenForRead(IGCHAR *FileName);

/**
	Length :the length of writenbuf(bool:1,int:2,long:4)
*/
int IG_LA_WriteOrCreatFileAndWrite(IGCHAR *FileName,byte writenbuf[],IGU32 Length);

/**
	index:the index of writenbuf (bool:+1,int:+2,long:+4)
*/
int IG_LA_WriteBool(byte writenbuf[],igbool ib,int index);

/**
	index:the index of writenbuf (bool:+1,int:+2,long:+4)
*/
int IG_LA_WriteInt(byte writenbuf[],int i,int index);

/**
	index:the index of writenbuf (bool:+1,int:+2,long:+4)
*/
int IG_LA_WriteLong(byte writenbuf[],long l,int index);

/**
	Length :the length of writenbuf(bool:1,int:2,long:4)
*/
int IG_LA_ReadFromFile(IG_FS_HANDLE handle,byte readbuf[],IGU32 Length);

/**
	index:the index of readbuf (bool:+1,int:+2,long:+4)
*/
igbool IG_LA_ReadBool(byte readbuf[],int index);

/**
	index:the index of readbuf (bool:+1,int:+2,long:+4)
*/
int IG_LA_ReadInt(byte readbuf[],int index);

/**
	index:the index of readbuf (bool:+1,int:+2,long:+4)
*/
long IG_LA_ReadLong(byte readbuf[],int index);

/**
	Normal Exit in games,please invoke this function
*/
int IG_LA_ResetLauncherStatus(void);

#endif

#ifdef __cplusplus
}
#endif