#ifdef __MCAREV31__
#ifndef _TENCENT_MCARE_ADP_
#define _TENCENT_MCARE_ADP_
#endif

#include "MAdpConfig.h"
#include "McfPlatform.h"

#include "McfFs.h"
#include "McfStdLib.h"
#include "McfTrace.h"

#define UINT_MAX ((MUINT)0xffffffff)

extern const MSHORT MADP_FS_NO_ERROR;
extern const MSHORT MADP_FS_PARAM_ERROR ;
extern const MSHORT MADP_FS_INVALID_FILENAME ;
extern const MSHORT MADP_FS_FILE_NOT_FOUND;
extern const MSHORT MADP_FS_PATH_NOT_FOUND ;
extern const MSHORT MADP_FS_ACCESS_DENIED ;
extern const MSHORT MADP_FS_OUT_OF_BUFFERS;
extern const MSHORT MADP_FS_STRING_BUFFER_TOO_SMALL;
extern const MSHORT MADP_FS_DISK_FULL;
extern const MSHORT MADP_FS_DATA_ERROR;
extern const MSHORT MADP_FS_DRIVE_NOT_READY;
extern const MSHORT MADP_FS_FILE_EXISTS;
extern const MUINT MADP_FS_READ_ONLY ; 
extern const MUINT MADP_FS_READ_WRITE ;
extern const MUINT MADP_FS_CREATE_ALWAYS ;
extern const MUINT MADP_FS_MOVE_COPY  ;
extern const MUINT MADP_FS_MOVE_KILL  ;
extern const MUINT MADP_FS_MOVE_OVERWRITE  ;
extern const MUINT MADP_FS_FILE_TYPE ;
extern const MUINT MADP_FS_DIR_TYPE  ;
extern const MUINT MADP_FS_RECURSIVE_TYPE;
extern const MUINT MADP_FS_DI_BASIC_INFO ;         
extern const MUINT MADP_FS_DI_FREE_SPACE  ;       
extern const MBYTE MADP_FS_MOUNT_STATE_ENUM  ;

extern MINT McfGetDiskInfo(const MWCHAR disk, McfDiskInfo* pDiskInfo, MINT Flags);
extern MINT McfFileFindFirst(const MWCHAR* namePattern, MWCHAR* pwFileName, MUINT nMaxLen);
extern MINT McfFileFindNext(MFd fd, MWCHAR* pwFileName, MUINT nMaxLen);
extern MINT McfFileGetFileInfo(MFd fd, MFileInfo* pFileInfo);
extern MINT McfGetDiskInfo(const MWCHAR disk, McfDiskInfo* pDiskInfo, MINT Flags);
extern MINT McfSelectPathAndEnter(pfnMcfSelPathCb callback, MWCHAR *pPath);

static MINT __McfFileErrCodeConvert(MINT nCode)
{
	MINT nRet = nCode;//MCF_FILE_ERROR;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE,__MCR_FUNCTION__" Entry");

	if(nCode == MADP_FS_NO_ERROR)
	{
		nRet = MCR_SUCCESS;
	}
	else if(nCode== MADP_FS_PARAM_ERROR)
	{
		nRet = MFILE_ERR_BAD_PARAM;
	}
	else if(nCode== MADP_FS_INVALID_FILENAME)
	{
		nRet = MFILE_ERR_BAD_FSNAME;
	}
	else if(nCode== MADP_FS_FILE_NOT_FOUND||nCode ==MADP_FS_PATH_NOT_FOUND)
	{
		nRet = MFILE_ERR_NOT_FOUND;
	}
	else if(nCode== MADP_FS_ACCESS_DENIED)
	{
		nRet = MFILE_ERR_LOCKED;
	}
	else if(nCode== MADP_FS_OUT_OF_BUFFERS ||nCode== MADP_FS_STRING_BUFFER_TOO_SMALL)
	{
		nRet = MFILE_ERR_BUFFER_FULL;
	}
	else if(nCode== MADP_FS_DISK_FULL)
	{
		nRet = MFILE_ERR_DISK_FULL;
	}
	else if(nCode== MADP_FS_DATA_ERROR)
	{
		nRet = MFILE_ERR_BAD_DATA;
	}
	else if(nCode== MADP_FS_DRIVE_NOT_READY)
	{
		nRet = MFILE_ERR_NOT_READY;
	}
	else if(nCode== MADP_FS_FILE_EXISTS)
	{
		nRet = MFILE_ERR_ALREADY_EXIST;
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave, ret = %d", nRet);

	return nRet;
}


static MUINT __McfFileFlagConvert(MUINT nFlag)
{
	MUINT nRet = MADP_FS_READ_ONLY;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if (nFlag == MFILE_OPEN_RO)
	{
		nRet = MADP_FS_READ_ONLY;
	}

	else if (nFlag == MFILE_OPEN_RW)
	{
		nRet = MADP_FS_READ_WRITE;
	}

	else if (nFlag == MFILE_OPEN_CW)
	{
		nRet = MADP_FS_CREATE_ALWAYS | MADP_FS_READ_WRITE;
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave");
	return nRet;
}


static MINT __GetDiskInfo(const MWCHAR disk, McfDiskInfo* pDiskInfo, MINT nFlags)
{
	MINT nRet = MCR_FAIL;
	nRet = McfGetDiskInfo(disk,pDiskInfo, nFlags);
	nRet = __McfFileErrCodeConvert(nRet);

	return nRet;
}


MFd McfFile_Open(const MWCHAR* pcwszFileName, MUINT nOpenFlag)
{
	MUINT nFlag = 0;
	MINT nRet = MCR_FAIL;
#ifdef WIN32    
    {
        MWCHAR wcsFileName[256] = {0};

        if(McfStdC_wcsncmp(L"..\\..\\WIN32FS\\DRIVE_E", pcwszFileName, McfStdC_wcslen(L"..\\..\\WIN32FS\\DRIVE_E")) == 0)
        {
            McfStdC_wcsncpy(wcsFileName, L"E:", McfStdC_wcslen(L"E:"));
            McfStdC_wcsncat(wcsFileName, pcwszFileName + McfStdC_wcslen(L"..\\..\\WIN32FS\\DRIVE_E"), 200);
            pcwszFileName = wcsFileName;
        }
    }
#endif
    MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if(pcwszFileName)
	{
		nFlag = __McfFileFlagConvert(nOpenFlag);
		nRet = FS_Open(pcwszFileName, nFlag);

		MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" FS_Open ret = %d", nRet);

		if(nRet < 0)
		{
			nRet = __McfFileErrCodeConvert(nRet);
		}
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);

	return nRet;
}

MINT McfFile_Read(MFd fd, MVOID* pDataPtr, MUINT nLength)
{
	MINT nRet = MCR_FAIL;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if(fd >= 0 && pDataPtr && nLength >0)
	{
		MUINT nRead = 0;

		nRet = __McfFileErrCodeConvert(FS_Read(fd, pDataPtr, nLength, &nRead));
		if(nRead >= 0)
		{
			nRet = nRead;
		}
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);

	return nRet;
}

MINT McfFile_Write(MFd fd, const MVOID* pDataPtr, MUINT nLength)
{
	MINT nRet = MCR_FAIL;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");
	if(fd >= 0 && pDataPtr && nLength >0)
	{
		MUINT nWrite = 0;
		nRet = __McfFileErrCodeConvert(FS_Write(fd, (MVOID*)pDataPtr, nLength, &nWrite));
		if(nWrite >= 0)
		{
			nRet = nWrite;
		}
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);

	return nRet;
}

MINT McfFile_Flush(MFd fd)
{
	MINT nRet = MCR_FAIL;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");
	if(fd >= 0)
	{
		nRet = __McfFileErrCodeConvert(FS_Commit(fd));
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave");

	return nRet;
}

MINT McfFile_Seek(MFd fd, MINT nOffset, MINT nSeekType)
{
	MINT nRet = MCR_FAIL;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");
	if(fd >= 0 && nSeekType >= 0)
	{
		nRet = __McfFileErrCodeConvert(FS_Seek(fd, nOffset, nSeekType));
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);

	return nRet;
}

MFd McfFile_FindFirst(const MWCHAR* namePattern, MWCHAR* pwFileName, MUINT nMaxLen)
{
	MINT nRet = MCR_FAIL;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if(namePattern && pwFileName && nMaxLen > 0)
	{
		nRet = McfFileFindFirst(namePattern, pwFileName, nMaxLen);
		if(nRet < 0)
		{
			nRet = __McfFileErrCodeConvert(nRet);
		}
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);
	return nRet;
}


MINT McfFile_FindNext(MFd fd, MWCHAR* pwFileName, MUINT nMaxLen)
{
	MINT nRet = MCR_FAIL;
	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if(fd >= 0 && pwFileName && nMaxLen > 0)
	{
		nRet = McfFileFindNext(fd, pwFileName, nMaxLen);
		nRet = __McfFileErrCodeConvert(nRet);
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);

	return nRet;
}

MINT McfFile_FindClose(MFd fd)
{
	MINT nRet = MCR_FAIL;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");
	if(fd >= 0)
	{
		nRet = __McfFileErrCodeConvert(FS_FindClose(fd));
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);

	return nRet;
}


MINT McfFile_GetFileInfo(MFd fd, MFileInfo* pFileInfo)
{
	MINT nRet = MCR_FAIL;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if(fd >= 0 && pFileInfo)
	{
		nRet = McfFileGetFileInfo(fd,pFileInfo);
		if(nRet < 0)
		{
			nRet = __McfFileErrCodeConvert(nRet);
		}
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);

	return nRet;
}


MUINT McfFile_GetFileSize(MFd fd)
{
	MFileInfo sFileInfo;
	MUINT nSize = 0;

	if(MCR_SUCCESS == McfFile_GetFileInfo(fd, &sFileInfo))
	{
		nSize = sFileInfo.m_nSize;
	}

	return nSize;
}


MINT McfFile_SetFileAttribute(const MWCHAR* pwFileName, MBYTE nAttr)
{
	MINT nRet = MCR_FAIL;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if(pwFileName)
	{
		nRet = __McfFileErrCodeConvert(FS_SetAttributes(pwFileName, nAttr));
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);
	return nRet;
}



MINT McfFile_GetFilePosition(MFd fd, MUINT *pPosition)
{
	MINT nRet = MCR_FAIL;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");
	if(fd >= 0 && pPosition)
	{
		nRet = __McfFileErrCodeConvert(FS_GetFilePosition(fd, pPosition));
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);

	return nRet;
}

//单位为字节
MU64 McfFile_GetTCardFreeSpace(MVOID)
{
	MU64 nTotal = 0;
	MWCHAR drv = McfFile_GetCardDrv();
	McfDiskInfo diskInfo = {0};

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	__GetDiskInfo(drv, &diskInfo, MADP_FS_DI_BASIC_INFO | MADP_FS_DI_FREE_SPACE);
	if(diskInfo.m_nFreeSpace > UINT_MAX)
	{
		nTotal = UINT_MAX;
	}
	else
	{
		nTotal = (MU64)diskInfo.m_nFreeSpace;
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave nTotal = %d", nTotal);
	return nTotal;
}


//增加单位为KB的api
MU64 McfFile_GetTCardFreeSpaceKB(MVOID)
{
	MU64 nTotal = 0;
	MWCHAR drv = McfFile_GetCardDrv();
	McfDiskInfo diskInfo = {0};

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	__GetDiskInfo(drv, &diskInfo, MADP_FS_DI_BASIC_INFO | MADP_FS_DI_FREE_SPACE);
	nTotal = (MU64)(diskInfo.m_nFreeSpace / 1024);

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave nTotal = %d", nTotal);
	return nTotal;
}


MU64 McfFile_GetPublicDrvFreeSpace(MVOID)
{
	MU64 nTotal = 0;
	MWCHAR drv = McfFile_GetPublicDrv();
	McfDiskInfo diskInfo = {0};

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	__GetDiskInfo(drv, &diskInfo, MADP_FS_DI_BASIC_INFO | MADP_FS_DI_FREE_SPACE);
	nTotal = diskInfo.m_nFreeSpace;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave nTotal = %d", nTotal);

	return nTotal;
}

MINT McfFile_Close(MFd fd)
{
	MINT nRet = MCR_FAIL;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry, fd = %d", fd);

	if(fd >= 0)
	{
		nRet = __McfFileErrCodeConvert(FS_Close(fd));
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);

	return nRet;
}


MINT McfFile_CheckFile(const MWCHAR* pwFileName)
{//just check file exist or not..
	MINT nRet = MCR_FAIL;
	MINT fd;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if(pwFileName)
	{
	    fd = McfFile_Open(pwFileName,MFILE_OPEN_RO);
	    if( fd >= 0)
	    {
		   McfFile_Close(fd);
		   nRet = MCR_SUCCESS;
		}
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);
	return nRet;
}


MINT McfFile_Delete(const MWCHAR* pwFileName)
{
	MINT nRet = MCR_SUCCESS;
	MINT nTest = -1;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if(pwFileName)
	{
		MINT nResult =0;

		nResult = FS_Delete(pwFileName);
		nRet = __McfFileErrCodeConvert(nResult);
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);

	return nRet;
}


MINT McfFile_Move(const MWCHAR* pSrcFullPath, const MWCHAR* pDstFullPath)
{
	MINT nRet = MCR_FAIL;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if (pSrcFullPath && pDstFullPath)
	{
		MUINT flag = MADP_FS_MOVE_KILL;

		flag = MADP_FS_MOVE_COPY | MADP_FS_MOVE_OVERWRITE;
		nRet = __McfFileErrCodeConvert(FS_Move(pSrcFullPath,pDstFullPath , flag,MNULL,MNULL,0));
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);
	return nRet;
}


//新增目录
MINT McfFile_CreateDir(const MWCHAR* pDirName)
{
	MINT nRet = MCR_FAIL;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if(pDirName)
	{
		nRet = __McfFileErrCodeConvert(FS_CreateDir(pDirName));
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", nRet);
	return nRet;
}


//清空目录，递归删除子目录
MINT McfFile_RemoveDir(const MWCHAR* pDirName)
{
	MINT bRet = MCR_FAIL;
	//MCHAR szTemp[256];

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if (pDirName)
	{
		bRet = __McfFileErrCodeConvert(FS_XDelete(pDirName, MADP_FS_FILE_TYPE | MADP_FS_DIR_TYPE | MADP_FS_RECURSIVE_TYPE,MNULL,0));
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", bRet);
	return bRet;
}


MINT McfFile_Rename(const MWCHAR* pSrcName, const MWCHAR* pDstName)
{
	MINT bRet = MCR_FAIL;

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if (pSrcName && pDstName)
	{
		bRet = __McfFileErrCodeConvert(FS_Rename(pSrcName, pDstName));
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave ret = %d", bRet);

	return bRet;
}


MBOOL McfFile_IsTCardReady(MVOID)
{
	MBOOL nRet = MFALSE;
	MWCHAR drv = McfFile_GetCardDrv();

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Entry");

	if(FS_GetDevStatus(drv, MADP_FS_MOUNT_STATE_ENUM) == 0)
	{
		nRet = MTRUE;
	}

	MCFAPI_FILE_PRINT(ALOG_INFO,MLOG_SDKFILE, __MCR_FUNCTION__" Leave,ret = %d", nRet);

	return nRet;
}

static MVOID* s_callback;

static MVOID __HandleFsSelectPath(MVOID* pFullName, MINT nIsShort)
{
    if (MNULL != s_callback)
    {
        ((pfnMcfSelPathCb)s_callback)(pFullName, nIsShort);
    }
    else
    {
        //no return;
    }

    MCR_HandleDelayedWork();

	GoBackHistory();
}

MINT McfFmgr_SelectPathAndEnter(pfnMcfSelPathCb callback)
{
	s_callback = (MVOID*)callback;
	return McfSelectPathAndEnter(__HandleFsSelectPath, L"root");
}

//fixme: we should make sure: 
// 1.当t卡拔出时，如果存储区使用的是t卡该函数需要返回MFALSE
MBOOL McfFile_IsStorageReady(MVOID)
{
	MWCHAR wchDrv = 0;
	MBOOL bRet = MFALSE;

	wchDrv = McfFile_GetStorageDrv();
	if(FS_GetDevStatus(wchDrv, MADP_FS_MOUNT_STATE_ENUM) == 0)
	{
		bRet = MTRUE;
	}

	return bRet;
}



#endif
