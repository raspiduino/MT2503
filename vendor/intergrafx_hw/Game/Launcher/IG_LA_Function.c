#include "IG_LA_Function.h"
#include "IGV5Def.h"

#ifdef IGV5_MTK_PHONE

#include "ig3d_adaptation56.h"

IG_FS_HANDLE IG_LA_OpenForRead(IGCHAR *FileName)
{
    return IGFS_Open(FileName, FS_READ_ONLY);
}
int IG_LA_ReadFromFile(IG_FS_HANDLE handle,byte readbuf[],IGU32 Length)
{

	IGU32 readbytes;
    if(handle > 0)
    {
        IGFS_Read(handle,readbuf,Length,&readbytes);
        IGFS_Close(handle);
    }
    return 0;
}
int IG_LA_LA_WriteInt(unsigned char writenbuf[],int i,int index)
{
    unsigned char b;
    b = ((unsigned char *)&i)[0]; 
    writenbuf[index] = b;
    b = ((unsigned char *)&i)[1]; 
    writenbuf[index+1] = b;

    return 0;
}

int IG_LA_LA_WriteOrCreatFileAndWrite(IGCHAR *FileName,unsigned char writenbuf[],int Length)
{
    IG_FS_HANDLE handle;
    U32 writtenbytes;
    handle = IGFS_Open(FileName, FS_READ_WRITE | FS_CREATE);
    if(handle > 0)
    {
        IGFS_Write(handle,writenbuf,Length,&writtenbytes);
        IGFS_Close(handle);
    }
    return 0;
}

int IG_LA_LA_ResetLauncherStatus(void)
{
    byte writenbuf[10];
    IG_LA_LA_WriteInt(writenbuf,0,0);
    IG_LA_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
    return 0;
}

int IG_LA_ReadInt(unsigned char readbuf[],int index)
{
    return (((int) readbuf[index]) | (((int)readbuf[index + 1]) << 8));
}

#endif

char IG_LA_isOnTouch(int x,int y,int x1,int y1,int x2,int y2)
{
    if(x >= x1 && x <= x2 && y >= y1 && y<= y2)
    {
        return 1;
    }
	return 0;
}