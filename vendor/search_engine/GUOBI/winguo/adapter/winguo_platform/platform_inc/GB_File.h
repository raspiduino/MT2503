#ifndef GBFILE_DEFINE_FOR_PLATFORM_KNIGHTNIU_2008_03_03_H
#define GBFILE_DEFINE_FOR_PLATFORM_KNIGHTNIU_2008_03_03_H

#include "GB_DataTypeDef.h"

#define GB_MAX_FILEPATH_LEN			(256)
#define GB_MAX_WCHAR_FILENAME_LEN	(512)
#define GB_FILE_SIZEDEFAULT			-1

typedef GB_INT  GB_FILEHANDLE;

#define GB_FILEHANDLE_ER  0
#define GB_FILE_NO_ERROR  0

//500k的空间
//#define GB_MIN_FREE_SPACE		(1024 * 1024)
#define GB_MIN_FREE_SPACE		(200 * 1024) // 暂用100k的空间吧

#if defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
#define GB_MIN_SMD_FREESPACE	(40 * 1024) // 低平台用20k来限制吧
#define GB_MIN_FILE_FREESPACE	(2 * 1024)
#else
#define GB_MIN_SMD_FREESPACE	(110 * 1024)
#define GB_MIN_FILE_FREESPACE	(8 * 1024)
#endif



typedef struct __GB_FILEINFO__ GB_FileInfo;
GB_FILEHANDLE GB_file_open(GB_CHAR * pName,const GB_CHAR*pMode); 

GB_VOID GB_file_close(GB_FILEHANDLE pFile);

GB_INT GB_file_createdir(GB_WCHAR * pDirName);
GB_INT GB_file_FloderFileAcountEx(GB_CHAR *pFloderName,GB_WCHAR drive);

GB_INT GB_file_Delete(GB_WCHAR * pDirName);

GB_INT GB_file_read(GB_FILEHANDLE pFile,GB_VOID *pBuf,GB_INT nDataSize);
GB_INT GB_file_write(GB_FILEHANDLE pFile,GB_VOID * pData,GB_INT nSize);
GB_INT GB_file_write_chars(GB_FILEHANDLE pFile,GB_CHAR * pData);

GB_BOOL GB_file_is_exist(GB_CHAR * pName);
GB_BOOL GB_file_is_existEx(GB_CHAR * pName,GB_WCHAR drive);

//GB_INT GB_file_write_ex(GB_CHAR * pName,GB_VOID * pData,GB_INT nSize,GB_UINT needFreeSpace);
GB_INT GB_file_write_ex(GB_CHAR * pName,GB_WCHAR driver,GB_VOID * pData,GB_INT nSize,GB_UINT needFreeSpace);
GB_INT GB_file_write_append_ex(GB_CHAR * pName,GB_VOID * pData,GB_INT offset,GB_INT nSize);
GB_INT GB_file_write_append(GB_CHAR * pName,GB_VOID * pData,GB_INT nSize);
GB_INT GB_file_write_appendEx(GB_CHAR * pName,GB_WCHAR drive,GB_UINT freeSpace,GB_VOID * pData,GB_INT nSize);
GB_INT GB_file_write_append_chars(GB_CHAR * pName,GB_CHAR * pData);

//GB_INT GB_file_read_dataExEx(GB_CHAR * pName,GB_VOID * pData,GB_INT nSize);
GB_INT GB_file_read_dataExEx(GB_CHAR * pName,GB_WCHAR driver,GB_VOID * pData,GB_INT nSize);
GB_INT GB_file_read_dataEx(GB_CHAR * pName,GB_VOID * pData,GB_INT nSize,GB_INT offset);
GB_INT GB_file_read_data(GB_CHAR * pName,GB_VOID * pData,GB_INT nSize);

GB_INT GB_file_write_INT(GB_FILEHANDLE pFile,GB_INT pData);
GB_INT GB_file_read_INT(GB_FILEHANDLE pFile);
GB_INT GB_file_skip(GB_FILEHANDLE pFile,GB_INT step);
GB_INT GB_file_SeekFromBegin(GB_FILEHANDLE pFile,GB_INT step);

GB_INT GB_file_init_path(GB_CHAR *pFolder);
GB_INT GB_file_check_path(GB_CHAR *pFolder);

GB_INT GB_file_init_pathEx(GB_CHAR *pFolder,const GB_WCHAR drive);
 
GB_INT GB_file_delete(GB_CHAR *pFileName);
GB_INT GB_file_deleteEx(GB_CHAR *pFileName,GB_WCHAR drive);

GB_BOOL GB_file_clear_dir(GB_CHAR *pDirectory);

GB_UINT GB_file_Get_file_size(GB_CHAR * pName);
GB_UINT GB_file_Get_file_sizeEx(GB_CHAR * pName,GB_WCHAR drive);
GB_UINT GB_file_Get_file_sizeByHandle(GB_FILEHANDLE pFile);

GB_INT GB_file_copy(GB_CHAR * pSourceName,GB_CHAR * pTargetName,GB_INT offset,GB_INT nSize);
GB_INT GB_file_copyEx(GB_CHAR * pSourceName,GB_CHAR * pTargetName,GB_INT offset,GB_INT nSize,GB_BOOL needDrive);
GB_BOOL GB_file_rename(GB_CHAR * pSourceName,GB_CHAR * pTargetName);

GB_INT GB_file_GetFileInfo(GB_CHAR * pName,GB_WCHAR drive,GB_FileInfo* info);
GB_INT GB_file_GetFileCreatTime(GB_CHAR * pName,GB_WCHAR drive,GB_TIME_STRUCT* creatDatatime);

extern GB_INT GB_WG_ReadFileData(GB_CHAR *buffer, GB_INT count, GB_FILEHANDLE gbfp, GB_INT seek);
extern GB_INT GB_WG_WriteFileData(GB_CHAR *buffer, GB_INT len, GB_FILEHANDLE gbfp, GB_INT seek);

extern GB_VOID GB_WG_SetSmartdailDrive(GB_WCHAR drive);
extern GB_WCHAR GB_WG_GetSmartdailDrive(GB_VOID);

extern GB_VOID GB_WG_SetWinguoDrive(GB_WCHAR drive);
extern GB_WCHAR GB_WG_GetWinguoDrive(GB_VOID);
GB_BOOL GB_WG_DriveIsVaild(GB_WCHAR drive);

GB_UINT GBFS_get_dirver_free_space(GB_WCHAR * dirname,GB_WCHAR drive);

GB_WCHAR GB_WG_GetPhoneDisc(GB_VOID);
GB_WCHAR GB_WG_GetTCard(GB_VOID);

GB_FILEHANDLE GB_WG_FindFirst(GB_WCHAR* floderPath,GB_WCHAR drive,GB_WCHAR* file_name,GB_UINT file_name_len);
GB_FILEHANDLE GB_WG_FindFirstEx(GB_WCHAR* floderPath,GB_WCHAR* extension,GB_WCHAR drive,GB_WCHAR* file_name,GB_UINT file_name_len);
GB_INT GB_WG_FindNext(GB_FILEHANDLE handle,GB_WCHAR* extension,GB_WCHAR* file_name,GB_UINT file_name_len);
GB_VOID GB_file_findClose(GB_FILEHANDLE pFindHandle);

#endif