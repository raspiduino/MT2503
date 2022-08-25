#ifndef _mcffs_h_
#define _mcffs_h_
#ifdef __cplusplus   
extern "C"{   
#endif // __cplusplus

#include "McfCommon.h"
#include "McfTime.h"


typedef struct
{
	MU64			m_nTotalSpace; // 总空间
	MU64			m_nFreeSpace; // 剩余空间
	MUINT           m_nFiles; // 文件数
}McfDiskInfo;

typedef MVOID (*pfnMcfSelPathCb)(MVOID *pFullname,MINT isShort);

MFd McfFile_Open(const MWCHAR* pcwszFileName, MUINT nOpenFlag);

MINT McfFile_Close(MFd fd);

MINT McfFile_Read(MFd fd, MVOID* pDataPtr, MUINT nLength);

MINT McfFile_Write(MFd fd, const MVOID* pDataPtr, MUINT nLength);

MINT McfFile_Flush(MFd fd);

MINT McfFile_Seek(MFd fd, MINT nOffset, MINT nSeekType);

MINT McfFile_CheckFile(const MWCHAR*pFileName);

MINT McfFile_Delete(const MWCHAR* pFileName);

MINT McfFile_Move(const MWCHAR* pSrcFullPath, const MWCHAR* pDstFullPath);

MFd McfFile_FindFirst(const MWCHAR* pNamePattern, MWCHAR* pwFileName, MUINT nMaxLen);

MINT McfFile_FindNext(MFd fd, MWCHAR* pwFileName, MUINT nMaxLen);

MINT McfFile_FindClose(MFd fd);

MINT McfFile_GetFileInfo(MFd fd, MFileInfo* pFileInfo);

MUINT McfFile_GetFileSize(MFd fd);

MINT McfFile_SetFileAttribute(const MWCHAR* pwFileName, MBYTE nAttr);

MINT McfFile_GetFilePosition(MFd fd, MUINT *pPosition);

MU64 McfFile_GetTCardFreeSpace(MVOID);

MU64 McfFile_GetTCardFreeSpaceKB(MVOID);

MU64 McfFile_GetPublicDrvFreeSpace(MVOID);

MWCHAR McfFile_GetCardDrv(MVOID);

MINT McfFile_CreateDir(const MWCHAR* pDirName);

MINT McfFile_RemoveDir(const MWCHAR* pDirName);

MINT McfFile_Rename(const MWCHAR* pFileName, const MWCHAR* pNewName);

MBOOL McfFile_IsTCardReady(MVOID);

MINT McfFmgr_SelectPathAndEnter(pfnMcfSelPathCb callback);

MWCHAR McfFile_GetPublicDrv(MVOID);

MWCHAR McfFile_GetPrivateDrv(MVOID);

MBOOL McfFile_IsStorageReady(MVOID);

MWCHAR McfFile_GetStorageDrv(MVOID);

MUINT McfFile_GetStorageFreeSpace(MVOID);

MUINT McfFile_GetFsSizeReq(MVOID);

MWCHAR* McfFile_GetSysPath(MVOID);

MWCHAR* McfFile_GetAppPath(MVOID);

#ifdef __cplusplus   
}   
#endif // __cplusplus
#endif//#ifndef MCRGDI_H
