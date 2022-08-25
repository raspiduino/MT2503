#ifdef __cplusplus
extern "C" {
#endif

#include "IG_Launcher_FactorDef.h"
#include "IG_LA_Utils.h"

IG_FS_HANDLE IG_LA_OpenForRead(IGCHAR *FileName){
#if _IS_MTK_EMU_
	return IGFS_Open(FileName, FS_READ_ONLY);
#endif
}

int IG_LA_WriteOrCreatFileAndWrite(IGCHAR *FileName,byte writenbuf[],IGU32 Length){
#if _IS_MTK_EMU_
	IG_FS_HANDLE handle;
	U32 writtenbytes;
	handle = IGFS_Open(FileName, FS_READ_WRITE | FS_CREATE);
	if(handle > 0){
		IGFS_Write(handle,writenbuf,Length,&writtenbytes);
		IGFS_Close(handle);
	}
#endif
	return 0;
}

int IG_LA_WriteBool(byte writenbuf[],igbool ib,int index){
#if _IS_MTK_EMU_
	byte b;
	if(ib) b = (byte)1;
	else b = (byte)0;
	writenbuf[index] = b;
#endif
	return 0;
}

int IG_LA_WriteInt(byte writenbuf[],int i,int index){
#if _IS_MTK_EMU_
	byte b;
	b = ((byte *)&i)[0]; 
	writenbuf[index] = b;
	b = ((byte *)&i)[1]; 
	writenbuf[index+1] = b;
#endif
	return 0;
}

int IG_LA_WriteLong(byte writenbuf[],long l,int index){
#if _IS_MTK_EMU_
	byte b;
	b = ((byte *)&l)[0]; 
	writenbuf[index] = b;
	b = ((byte *)&l)[1]; 
	writenbuf[index+1] = b;
	b = ((byte *)&l)[2]; 
	writenbuf[index+2] = b;
	b = ((byte *)&l)[3]; 
	writenbuf[index+3] = b;
#endif
	return 0;
}

int IG_LA_ReadFromFile(IG_FS_HANDLE handle,byte readbuf[],IGU32 Length){
#if _IS_MTK_EMU_
	U32 readbytes;
	if(handle > 0){
		IGFS_Read(handle,readbuf,Length,&readbytes);
		IGFS_Close(handle);
	}
#endif
	return 0;
}

igbool IG_LA_ReadBool(byte readbuf[],int index){
#if _IS_MTK_EMU_
	if((int)readbuf[index] == 0)	return IGBOOL_FALSE;
	else if((int)readbuf[index] == 1) return IGBOOL_TRUE;
#endif
}

int IG_LA_ReadInt(byte readbuf[],int index){
#if _IS_MTK_EMU_
	return (((int) readbuf[index]) | (((int)readbuf[index + 1]) << 8));
#endif
}

long IG_LA_ReadLong(byte readbuf[],int index){
#if _IS_MTK_EMU_
	return (((long) readbuf[index]) | (((long)readbuf[index + 1]) << 8) | (((long)readbuf[index + 1]) << 16) | (((long)readbuf[index + 1]) << 24));
#endif
}

int IG_LA_ResetLauncherStatus(void){
#if _IS_MTK_EMU_
	byte writenbuf[10];
	IG_LA_WriteInt(writenbuf,0,0);
	IG_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif	
	return 0;
}


#ifdef __cplusplus
}
#endif