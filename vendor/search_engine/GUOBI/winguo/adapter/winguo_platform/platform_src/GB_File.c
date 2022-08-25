
#include "MMI_features.h"

#ifdef __MMI_GB_WINGUO__

#undef GB_PACKAGE

#include "MMI_include.h"
#include "Fs_type.h"
#include "Fs_func.h"

#include "GB_WG_Public.h"
#include "GB_SystemPlat.h"
#include "GB_ConfigDef.h"	
#include "GB_File.h"
#include "GB_WG_MTKPlatver.h"


typedef struct __GB_FILEINFO__
{
	const FS_DOSDirEntry * DirEntry;
	UINT                  FilePos;
	UINT                  AllocatedSize;
	UINT                  ClusterChains;
	UINT                  VolumeSerialNumber;
	const char           * FullName;
};
#define GB_WgDelDirW(pSearchPath)	FS_XDelete((const WCHAR*)pSearchPath, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0)

#define GB_WgDelFileW(pwPath)   FS_Delete((const WCHAR*)pwPath)

#define GB_WgGetDirFileCount(pDirPath) FS_Count((const WCHAR*)pDirPath,FS_FILE_TYPE, NULL, 0)

#define GB_WgGetDirFirstFile(pDirPath,info,filename,maxLength) FS_FindFirst(pDirPath, 0, 0, &info, filename, maxLength)

#define GB_WgGetDirNextFile(handle,info,filename,maxLength) FS_FindNext(handle,&info,filename,maxLength)

#define GB_WgGetDirFindClose(handle) FS_FindClose(handle)

// 放在手机disk中
//#define GB_WgGetDrive() FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM)
// 放在T卡上
#define GB_WgGetDrive() FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE)

//GB_UINT GBFS_get_dirver_free_space(GB_WCHAR* dirname);

GB_WCHAR GB_WG_GetWinguoDrive(GB_VOID);


extern GB_WCHAR* GB_utf8_to_unicode(GB_CHAR* utf8,GB_INT len);
extern GB_CHAR* GBUnicodeToUtf8(GB_WCHAR* utf8,GB_INT len);

GB_FILEHANDLE GB_file_openEx(GB_CHAR * pName,
							 const GB_CHAR* pMode,
							 const GB_WCHAR drive,
							 const GB_UINT needFreeSpace);

GB_BOOL GB_file_clear_dir(GB_CHAR *pDirectory)
{
	GB_WCHAR *szWFile;
	GB_WCHAR *szWFileItem;
	GB_CHAR    *szfile;
	
	GB_WCHAR *pSearchPath = GB_NULL;
	if(pDirectory==GB_NULL)return GB_FALSE;
	
	szWFile = (GB_WCHAR *)GB_WG_Malloc(GB_MAX_FILEPATH_LEN*sizeof(GB_WCHAR));
	szWFileItem = (GB_WCHAR *)GB_WG_Malloc(GB_MAX_FILEPATH_LEN*sizeof(GB_WCHAR));
	szfile = (GB_CHAR *)GB_WG_Malloc(GB_MAX_FILEPATH_LEN*sizeof(GB_CHAR));
	if(szWFileItem==GB_NULL||szWFile==GB_NULL||szfile==GB_NULL){
		GB_free_ex((GB_VOID**)&szWFile);
		GB_free_ex((GB_VOID**)&szWFileItem);
		GB_free_ex((GB_VOID**)&szfile);
		return GB_FALSE;
	}


	GB_MEMSET(szfile,0,GB_MAX_FILEPATH_LEN);

	GB_MEMCPY(szfile,pDirectory,GB_STRLEN(pDirectory));
	
	pSearchPath =GB_utf8_to_unicode((GB_CHAR*)szfile,GB_STRLEN((GB_CHAR*)szfile));
	//pSearchPath[0] = (GB_WCHAR)GB_WgGetDrive();
	pSearchPath[0] =GB_WG_GetWinguoDrive();
    
	GB_WgDelDirW(pSearchPath);
	GB_WG_Free(pSearchPath);
	pSearchPath = GB_NULL;
	GB_free_ex((GB_VOID**)&szWFile);
	GB_free_ex((GB_VOID**)&szWFileItem);
	GB_free_ex((GB_VOID**)&szfile);
	return GB_TRUE;
}

GB_INT GB_file_delete(GB_CHAR *pFileName)
{
	return GB_file_deleteEx(pFileName,GB_WG_GetWinguoDrive());
// 	GB_INT ret = 0;
// 	GB_WCHAR* pwPath;
// 	
// 	pwPath = GB_utf8_to_unicode(pFileName,GB_STRLEN(pFileName));
// 	if(pwPath==GB_NULL)return 0;
// 	//pwPath[0] = (GB_WCHAR)GB_WgGetDrive();

// 	pwPath[0] =	GB_WG_GetWinguoDrive();
// 	if(gb_wg_wcslen(pwPath) != 0){////////
// 		ret = GB_WgDelFileW(pwPath);
// 	}
// 	GB_WG_Free(pwPath);
// 
// 	return ret;
}

GB_INT GB_file_deleteEx(GB_CHAR *pFileName,GB_WCHAR drive)
{
	GB_INT ret = 0;
	GB_WCHAR* pwPath;
	
	pwPath = GB_utf8_to_unicode(pFileName,GB_STRLEN(pFileName));
	if(pwPath==GB_NULL)return 0;
	//pwPath[0] = (GB_WCHAR)GB_WgGetDrive();
	pwPath[0] =	drive;
	if(gb_wg_wcslen(pwPath) != 0){////////
		ret = GB_WgDelFileW(pwPath);
	}
	GB_WG_Free(pwPath);
	pwPath = GB_NULL;
	
	return ret;
}


GB_FILEHANDLE GB_file_open(GB_CHAR * pName,const GB_CHAR* pMode)
{
	return GB_file_openEx(pName,pMode,(GB_WCHAR)GB_WG_GetWinguoDrive(),GB_MIN_FILE_FREESPACE);
// 	GB_FILEHANDLE fd; 
// 	GB_WCHAR* pwPath;
// 	unsigned int Flag = 0;
// 	FS_SEEK_POS_ENUM pos= FS_FILE_BEGIN;
// 	
// 	if(GB_STRICMP(pMode,"rb")==0)
// 	{
// 		Flag = FS_READ_ONLY;
// 	}
// 	else
// 	{
// 		GB_WCHAR szDir[4]={'d',':','\\',0};
// 		GB_UINT  freeSpace =0 ;
// 		freeSpace = GBFS_get_dirver_free_space(szDir,(GB_WCHAR)GB_WgGetDrive());
// 		if(freeSpace<GB_MIN_FREE_SPACE)
// 		{

// 			#ifdef GB_WINGUO_DEBUG

// 			GB_WG_Trace("文件可用空间不足:%d,",freeSpace);

// 			#endif
// 			
// 			return GB_FILEHANDLE_ER;
// 		}
// 
// 		if(GB_STRICMP(pMode,"ab")==0)
// 		{
// 			pos= FS_FILE_END;
// 		}
// 		else if(GB_STRICMP(pMode,"wb")==0)
// 		{
// 		}
// 		
// 		Flag = FS_CREATE | FS_READ_WRITE;
// 	}
// 	if(pName==GB_NULL||pMode==GB_NULL)
// 	{
// 		return GB_FILEHANDLE_ER;
// 	}
// 	pwPath = GB_utf8_to_unicode(pName,GB_STRLEN(pName));
// 	if(pwPath==GB_NULL)return GB_FILEHANDLE_ER;
// 	pwPath[0] = (GB_WCHAR)GB_WgGetDrive();
// 	if(pwPath != 0){////////
// 		fd = FS_Open((const WCHAR*)pwPath,Flag);
// 		if(fd<=0)
// 		{
// 			GB_WG_Free(pwPath);

// 
// 			#ifdef GB_WINGUO_DEBUG
// 			GB_WG_Trace("文件打开失败:%d,%s",fd,pName);

// 			#endif

// 
// 			return GB_FILEHANDLE_ER;
// 		}
// 		FS_Seek(fd, 0, pos);
// 		GB_WG_Free(pwPath);
// 	}
// 	return fd;
}

GB_INT GB_file_check_path(GB_CHAR *pFolder)
{
	GB_INT nIndex =0;
	GB_FILEHANDLE fd; 
	GB_WCHAR* pwPath;
	FS_SEEK_POS_ENUM pos= FS_FILE_BEGIN;
	
	if(pFolder==GB_NULL)
	{
		return 0;
	}
	pwPath = GB_utf8_to_unicode(pFolder,GB_STRLEN(pFolder));
	if(pwPath != 0)
	{
		GB_WCHAR *szwFile;
		GB_CHAR *szFile;
		GB_INT nIndex =0;
		GB_INT num    =gb_wg_wcslen(pwPath);
		
		szwFile = (GB_WCHAR*)GB_WG_Malloc(GB_MAX_FILEPATH_LEN*sizeof(GB_WCHAR));
		szFile = (GB_CHAR*)GB_WG_Malloc(GB_MAX_FILEPATH_LEN*sizeof(GB_CHAR));
		if(szwFile==GB_NULL||szFile==GB_NULL)
		{
			GB_free_ex((GB_VOID**)&szwFile);
			GB_free_ex((GB_VOID**)&szFile);
			return 0;
		}
		GB_MEMSET(szwFile,0,GB_MAX_FILEPATH_LEN*sizeof(GB_WCHAR));
		GB_MEMSET(szFile,0,GB_MAX_FILEPATH_LEN);
		
		#ifdef GB_WINGUO_DEBUG
		GB_WG_Trace("查看文件夹:%s",pFolder);
		#endif

		pwPath[0] = GB_WG_GetWinguoDrive();//(GB_WCHAR)GB_WgGetDrive();
		szFile[0] = (GB_CHAR)GB_WG_GetWinguoDrive();//(GB_CHAR)GB_WgGetDrive();
		while(nIndex<num)
		{
			szwFile[nIndex]=pwPath[nIndex];	
			if(nIndex>0)
			{
				szFile[nIndex]=pFolder[nIndex];
			}
			if(szwFile[nIndex]=='\\')
			{
				#ifdef GB_WINGUO_DEBUG
				GB_WG_Trace("查看文件夹:%s是否存在",(GB_CHAR*)szFile);
				#endif
				
				fd=FS_Open((const WCHAR*)szwFile,FS_OPEN_DIR|FS_READ_ONLY);
				if(fd<=0)
				{
					#ifdef GB_WINGUO_DEBUG
					GB_WG_Trace("查看文件夹:%s不存在",(GB_CHAR*)szFile);
					#endif

					GB_WG_Free(pwPath);
					pwPath = GB_NULL;
					GB_free_ex((GB_VOID**)&szwFile);
					GB_free_ex((GB_VOID**)&szFile);
					return 0;
				}
				else
				{
					#ifdef GB_WINGUO_DEBUG
					GB_WG_Trace("查看文件夹:%s已存在",(GB_CHAR*)szFile);
					#endif
					
					FS_Close(fd);
				}
			}
			nIndex++;
		}
		GB_WG_Free(pwPath);
		pwPath = GB_NULL;
		GB_free_ex((GB_VOID**)&szwFile);
		GB_free_ex((GB_VOID**)&szFile);
		return 1;
	}
	return 0;
}

GB_INT GB_file_init_path(GB_CHAR *pFolder)
{
	return GB_file_init_pathEx(pFolder,GB_WG_GetWinguoDrive());//(GB_WCHAR)GB_WgGetDrive());
// 	GB_INT nIndex =0;
// 	GB_FILEHANDLE fd; 
// 	GB_WCHAR* pwPath;
// 	FS_SEEK_POS_ENUM pos= FS_FILE_BEGIN;
// 	
// 	if(pFolder==GB_NULL)
// 	{
// 		return 0;
// 	}
// 	pwPath = GB_utf8_to_unicode(pFolder,GB_STRLEN(pFolder));
// 	if(pwPath != 0)
// 	{
// 		GB_WCHAR *szwFile;
// 		GB_CHAR *szFile;
// 		GB_INT nIndex =0;
// 		GB_INT num =gb_wg_wcslen(pwPath);
// 		
// 		szwFile = (GB_WCHAR*)GB_WG_Malloc(GB_MAX_FILEPATH_LEN*sizeof(GB_WCHAR));
// 		szFile = (GB_CHAR*)GB_WG_Malloc(GB_MAX_FILEPATH_LEN*sizeof(GB_CHAR));
// 		if(szwFile==GB_NULL||szFile==GB_NULL)
// 		{
// 			GB_free_ex((GB_VOID**)&szwFile);
// 			GB_free_ex((GB_VOID**)&szFile);
// 			return 0;
// 		}
// 		GB_MEMSET(szwFile,0,GB_MAX_FILEPATH_LEN*sizeof(GB_WCHAR));
// 		GB_MEMSET(szFile,0,GB_MAX_FILEPATH_LEN);

// 
// 		#ifdef GB_WINGUO_DEBUG
// 		GB_WG_Trace("查看文件夹:%s",pFolder);

// 		#endif

// 
// 		pwPath[0] = (GB_WCHAR)GB_WgGetDrive();
// 		szFile[0]=(GB_CHAR)GB_WgGetDrive();
// 		while(nIndex<num)
// 		{
// 			szwFile[nIndex]=pwPath[nIndex];	
// 			if(nIndex>0)
// 			{
// 				szFile[nIndex]=pFolder[nIndex];
// 			}
// 			if(szwFile[nIndex]=='\\')
// 			{
// 				#ifdef GB_WINGUO_DEBUG
// 				GB_WG_Trace("查看文件夹:%s是否存在",(GB_CHAR*)szFile);

// 				#endif
// 				

// 				if(GBFS_get_dirver_free_space(szwFile,(GB_WCHAR)GB_WgGetDrive()) < GB_MIN_FREE_SPACE)

// 				{

// 					GB_WG_Free(pwPath);

// 					GB_free_ex((GB_VOID**)&szwFile);

// 					GB_free_ex((GB_VOID**)&szFile);

// 					return 0;

// 				}

// 
// 				fd=FS_Open((const WCHAR*)szwFile,FS_OPEN_DIR|FS_READ_ONLY);
// 				if(fd<=0)
// 				{
// 					#ifdef GB_WINGUO_DEBUG	
// 					GB_WG_Trace("查看文件夹:%s不存在",(GB_CHAR*)szFile);

// 					#endif

// 
// 					if(FS_CreateDir((const WCHAR*)szwFile)!=0)
// 					{//	

// 						#ifdef GB_WINGUO_DEBUG
// 						GB_WG_Trace("查看文件夹:%s创建失败!",(GB_CHAR*)szFile);

// 						#endif

// 
// 						GB_WG_Free(pwPath);
// 						GB_free_ex((GB_VOID**)&szwFile);
// 						GB_free_ex((GB_VOID**)&szFile);
// 						return 0;
// 					}
// 					else
// 					{

// 						#ifdef GB_WINGUO_DEBUG
// 						GB_WG_Trace("查看文件夹:%s创建Ok!",(GB_CHAR*)szFile);						

// 						#endif
// 					}
// 				}
// 				else
// 				{

// 					#ifdef GB_WINGUO_DEBUG
// 					GB_WG_Trace("查看文件夹:%s已存在",(GB_CHAR*)szFile);

// 					#endif

// 
// 					FS_Close(fd);
// 				}
// 			}
// 			nIndex++;
// 		}

// 
// 		GB_WG_Free(pwPath);
// 		GB_free_ex((GB_VOID**)&szwFile);
// 		GB_free_ex((GB_VOID**)&szFile);

// 
// 		return 1;
// 	}
// 	return 0;
}


GB_FILEHANDLE GB_file_openEx(GB_CHAR * pName,
							 const GB_CHAR* pMode,
							 const GB_WCHAR drive,
							 const GB_UINT needFreeSpace)
{
	GB_FILEHANDLE fd; 
	GB_WCHAR* pwPath;
	unsigned int Flag = 0;
	FS_SEEK_POS_ENUM pos= FS_FILE_BEGIN;
	
	if(GB_STRICMP(pMode,"rb")==0)
	{
		Flag = FS_READ_ONLY;
	}
	else
	{
		GB_WCHAR szDir[4]={'c',':','\\',0};
		GB_UINT  freeSpace =0 ;

		// 这里做个容错有可能drive==0
		if(drive)
			szDir[0] = drive;

		freeSpace = GBFS_get_dirver_free_space(szDir,drive);

		
		// 不存在的情况下用这个判断
		if(freeSpace <= needFreeSpace)
		{
// #ifdef GB_WINGUO_DEBUG
// 			GB_WG_Trace("文件可用空间不足:%d,",freeSpace);
// #endif
			return GB_FILEHANDLE_ER;
		}
		
		if(GB_STRICMP(pMode,"ab")==0)
		{
			pos= FS_FILE_END;
		}
		else if(GB_STRICMP(pMode,"wb")==0)
		{
		}
		
		if(GB_STRICMP(pMode,"wr")==0)
		{
			Flag = FS_READ_WRITE;
		}
		else
		{
			Flag = FS_CREATE | FS_READ_WRITE;
		}
	}
	if(pName==GB_NULL||pMode==GB_NULL)
	{
		return GB_FILEHANDLE_ER;
	}
	pwPath = GB_utf8_to_unicode(pName,GB_STRLEN(pName));
	if(pwPath==GB_NULL)return GB_FILEHANDLE_ER;

	//pwPath[0] = (GB_WCHAR)GB_WgGetDrive();
	if (drive)
		pwPath[0] = drive;
	
	if(pwPath != 0)
	{////////
		fd = FS_Open((const WCHAR*)pwPath,Flag);
		if(fd<=0)
		{
			GB_WG_Free(pwPath);
			pwPath = GB_NULL;
			
#ifdef GB_WINGUO_DEBUG
			GB_WG_Trace("文件打开失败:%d,%s",fd,pName);
#endif
			
			return GB_FILEHANDLE_ER;
		}
		FS_Seek(fd, 0, pos);
		GB_WG_Free(pwPath);
		pwPath = GB_NULL;
	}
	return fd;
}

GB_INT GB_file_write_ex(GB_CHAR * pName,GB_WCHAR driver,GB_VOID * pData,GB_INT nSize,GB_UINT needFreeSpace)
{
	GB_INT nWrite =0;
	//GB_FILEHANDLE pFile =GB_file_open(pName,"wb");
	//GB_FILEHANDLE pFile = GB_file_openEx(pName,"wb",GB_WG_GetPhoneDisc(),needFreeSpace);
	GB_FILEHANDLE pFile = GB_file_openEx(pName,"wb",driver,needFreeSpace);
	if(pFile==GB_FILEHANDLE_ER)
	{
		GB_file_close(pFile);
		return 0;
	}
	if(pData==GB_NULL)
	{
		GB_file_close(pFile);
		return 0;
	}
	if(nSize==0){
		GB_file_close(pFile);
		return 0;
	}
	nWrite =GB_file_write(pFile,pData,nSize);
	GB_file_close(pFile);
	return nWrite;
}

GB_INT GB_file_read_dataExEx(GB_CHAR * pName,GB_WCHAR driver,GB_VOID * pData,GB_INT nSize)
{
	if((pData==GB_NULL)||(nSize==0))
		return 0;
	{
		GB_INT nRead =0;
		//GB_FILEHANDLE pFile =GB_file_openEx(pName,"rb",GB_WG_GetPhoneDisc(),GB_MIN_FILE_FREESPACE);
		GB_FILEHANDLE pFile =GB_file_openEx(pName,"rb",driver,GB_MIN_FILE_FREESPACE);
		if(pFile==GB_FILEHANDLE_ER)return 0;
		
		// 只有移动没有错误的时候才能读数据，否则都当是无效的移动
		if (0 <= GB_file_skip(pFile,0))
		{
			nRead = GB_file_read(pFile,pData,nSize);
		}
		
		GB_file_close(pFile);
		return nRead;
	}
}

GB_INT GB_file_init_pathEx(GB_CHAR *pFolder,const GB_WCHAR drive)
{
	GB_INT nIndex =0;
	GB_FILEHANDLE fd; 
	GB_WCHAR* pwPath;
	FS_SEEK_POS_ENUM pos= FS_FILE_BEGIN;
	
	if(pFolder==GB_NULL)
	{
		return 0;
	}
	pwPath = GB_utf8_to_unicode(pFolder,GB_STRLEN(pFolder));
	if(pwPath != 0)
	{
		GB_WCHAR *szwFile;
		GB_CHAR *szFile;
		GB_INT nIndex =0;
		GB_INT num =gb_wg_wcslen(pwPath);
		
		szwFile = (GB_WCHAR*)GB_WG_Malloc(GB_MAX_FILEPATH_LEN*sizeof(GB_WCHAR));
		szFile = (GB_CHAR*)GB_WG_Malloc(GB_MAX_FILEPATH_LEN*sizeof(GB_CHAR));
		if(szwFile==GB_NULL||szFile==GB_NULL)
		{
			GB_free_ex((GB_VOID**)&szwFile);
			GB_free_ex((GB_VOID**)&szFile);
			return 0;
		}
		GB_MEMSET(szwFile,0,GB_MAX_FILEPATH_LEN*sizeof(GB_WCHAR));
		GB_MEMSET(szFile,0,GB_MAX_FILEPATH_LEN);
		
#ifdef GB_WINGUO_DEBUG
		GB_WG_Trace("查看文件夹:%s",pFolder);
#endif
		
		// 非空的情况下
		pwPath[0] = drive;
		szFile[0] = (GB_CHAR)drive;

		while(nIndex<num)
		{
			szwFile[nIndex]=pwPath[nIndex];	
			if(nIndex>0)
			{
				szFile[nIndex]=pFolder[nIndex];
			}
			if(szwFile[nIndex]=='\\')
			{
#ifdef GB_WINGUO_DEBUG
				GB_WG_Trace("查看文件夹:%s是否存在",(GB_CHAR*)szFile);
#endif
				// 文件夹的容量需要的不大
				//if(GBFS_get_dirver_free_space(szwFile,pwPath[0]) < GB_MIN_SMD_FREESPACE)
				if(GBFS_get_dirver_free_space(szwFile,pwPath[0]) < GB_MIN_FILE_FREESPACE)
				{
					GB_WG_Free(pwPath);
					pwPath = GB_NULL;
					GB_free_ex((GB_VOID**)&szwFile);
					GB_free_ex((GB_VOID**)&szFile);
					return 0;
				}
				
				fd=FS_Open((const WCHAR*)szwFile,FS_OPEN_DIR|FS_READ_ONLY);

				if(fd<=0)
				{
#ifdef GB_WINGUO_DEBUG	
					GB_WG_Trace("查看文件夹:%s不存在",(GB_CHAR*)szFile);
#endif
					
					if(FS_CreateDir((const WCHAR*)szwFile)!=0)
					{//	
#ifdef GB_WINGUO_DEBUG
						GB_WG_Trace("查看文件夹:%s创建失败!",(GB_CHAR*)szFile);
#endif
						
						GB_WG_Free(pwPath);
						pwPath = GB_NULL;
						GB_free_ex((GB_VOID**)&szwFile);
						GB_free_ex((GB_VOID**)&szFile);
						return 0;
					}
					else
					{
#ifdef GB_WINGUO_DEBUG
						GB_WG_Trace("查看文件夹:%s创建Ok!",(GB_CHAR*)szFile);						
#endif
					}
				}
				else
				{
#ifdef GB_WINGUO_DEBUG
					GB_WG_Trace("查看文件夹:%s已存在",(GB_CHAR*)szFile);
#endif
					
					FS_Close(fd);
				}
			}
			nIndex++;
		}
		GB_WG_Free(pwPath);
		pwPath = GB_NULL;
		GB_free_ex((GB_VOID**)&szwFile);
		GB_free_ex((GB_VOID**)&szFile);
		return 1;
	}
	return 0;
}

GB_INT GB_file_write_INT(GB_FILEHANDLE pFile,GB_INT pData)
{
	return GB_file_write(pFile,&pData,sizeof(GB_INT));
}

GB_INT GB_file_read_INT(GB_FILEHANDLE  pFile)
{
	GB_INT pData=0;
	GB_file_read(pFile,(GB_VOID*)&pData,sizeof(GB_INT));
	return pData;
}
GB_INT GB_file_read(GB_FILEHANDLE pFile,GB_VOID * pData,GB_INT nSize)
{
	GB_UINT Read=0;
	GB_INT rv=0;

	if(pData==GB_NULL)
	{
		//GB_file_close(pFile);
		return 0;
	}
	if(nSize==0)
	{
		//GB_file_close(pFile);
		return 0;
	}
	rv = FS_Read(pFile,pData,nSize,&Read);
	if(rv == 0)
	{
		return Read;
	}
	else
	{
		return rv;
	}
}

GB_INT GB_file_skip(GB_FILEHANDLE pFile,GB_INT step)
{
	return  FS_Seek(pFile,step,FS_FILE_CURRENT);
}

GB_INT GB_file_SeekFromBegin(GB_FILEHANDLE pFile,GB_INT step)
{
	return  FS_Seek(pFile,step,FS_FILE_BEGIN);
}

GB_VOID GB_file_close(GB_FILEHANDLE pFile)
{
	FS_Close(pFile);
}

GB_VOID GB_file_findClose(GB_FILEHANDLE pFindHandle)
{
	GB_WgGetDirFindClose(pFindHandle);
}

GB_INT GB_file_write(GB_FILEHANDLE pFile,GB_VOID * pData,GB_INT nSize)
{
	GB_UINT Written;
	GB_INT rv;

	if(pData==GB_NULL)
	{
		//GB_file_close(pFile);
		return 0;
	}
	if(nSize==0){
		//GB_file_close(pFile);
		return 0;
	}
	rv = FS_Write(pFile,pData,nSize,&Written);
	if(rv<0)
	{
		//GB_file_close(pFile);
		return 0;
	}
	if(rv == nSize){
		return Written;
	}
	else{
		return Written;
	}
}

GB_INT GB_file_write_chars(GB_FILEHANDLE pFile,GB_CHAR * pData)
{
	return GB_file_write(pFile,pData,GB_STRLEN(pData));
}

GB_INT  GB_file_write_append(GB_CHAR * pName,GB_VOID * pData,GB_INT nSize)
{
	return GB_file_write_appendEx(pName,GB_WG_GetWinguoDrive(),GB_MIN_FILE_FREESPACE,pData,nSize);
// 	GB_INT nWrite =0;
// 	GB_FILEHANDLE pFile =GB_file_open(pName,"ab");
// 	if(pFile==GB_FILEHANDLE_ER)
// 	{
// 		GB_file_close(pFile);
// 		return 0;
// 	}
// 	if(pData==GB_NULL)
// 	{
// 		GB_file_close(pFile);
// 		return 0;
// 	}
// 	if(nSize==0){
// 		GB_file_close(pFile);
// 		return 0;
// 	}
// 	nWrite =GB_file_write(pFile,pData,nSize);
// 	GB_file_close(pFile);
// 	return nWrite;
}

GB_INT GB_file_write_appendEx(GB_CHAR * pName,GB_WCHAR drive,GB_UINT freeSpace,GB_VOID * pData,GB_INT nSize)
{
	GB_INT nWrite =0;
	GB_FILEHANDLE pFile = GB_file_openEx(pName,"ab",drive,freeSpace);
	if(pFile==GB_FILEHANDLE_ER)
	{
		GB_file_close(pFile);
		return 0;
	}
	if(pData==GB_NULL)
	{
		GB_file_close(pFile);
		return 0;
	}
	if(nSize==0){
		GB_file_close(pFile);
		return 0;
	}
	nWrite =GB_file_write(pFile,pData,nSize);
	GB_file_close(pFile);
	return nWrite;
}

GB_INT  GB_file_write_append_ex(GB_CHAR * pName,GB_VOID * pData,GB_INT offset,GB_INT nSize)
{
	GB_INT nWrite =0;
	GB_FILEHANDLE pFile =GB_file_open(pName,"ab");
	if(pFile==GB_FILEHANDLE_ER)return 0;
	nWrite =GB_file_write(pFile,(GB_VOID*)((GB_CHAR*)pData+offset),nSize-offset);
	GB_file_close(pFile);
	return nWrite;
}

GB_INT GB_file_read_data(GB_CHAR * pName,GB_VOID * pData,GB_INT nSize){
	if((pData==GB_NULL)||(nSize==0))
		return 0;
	return GB_file_read_dataEx(pName,pData,nSize,0);
}
GB_INT GB_file_read_dataEx(GB_CHAR * pName,GB_VOID * pData,GB_INT nSize,GB_INT offset){
	GB_INT nRead =0;
	GB_FILEHANDLE pFile =GB_file_open(pName,"rb");
	if(pFile==GB_FILEHANDLE_ER)return 0;

	// 只有移动没有错误的时候才能读数据，否则都当是无效的移动
	if (0 <= GB_file_skip(pFile,offset))
	{
		nRead = GB_file_read(pFile,pData,nSize);
	}
	
	GB_file_close(pFile);
	return nRead;
}
GB_INT GB_file_write_append_chars(GB_CHAR * pName,GB_CHAR * pData)
{
	return GB_file_write_append( pName, pData, GB_STRLEN(pData));
}

GB_BOOL GB_file_is_exist(GB_CHAR * pName)
{
	GB_BOOL ret = GB_FALSE;

	//GB_FILEHANDLE pFile = GB_file_open(pName,"rb");
	GB_FILEHANDLE pFile = GB_file_openEx(pName,"rb",GB_WG_GetWinguoDrive(),GB_MIN_FILE_FREESPACE);

	if (pFile != GB_FILEHANDLE_ER)
	{
		ret = GB_TRUE;
		GB_file_close(pFile);
	}

	return ret;
}

GB_BOOL GB_file_is_existEx(GB_CHAR * pName,GB_WCHAR drive)
{
	GB_BOOL ret = GB_FALSE;
	GB_FILEHANDLE pFile = 0;

	pFile = GB_file_openEx(pName,"rb",drive,GB_MIN_FILE_FREESPACE);
	
	if (pFile != GB_FILEHANDLE_ER)
	{
		ret = GB_TRUE;
		GB_file_close(pFile);
	}
	
	return ret;
}

/**********************************************************************
* 函数名称： GB_file_Get_file_size
* 功能描述：获取文件大小
* 输入参数： 无
* 输出参数：模式
* 返 回 值： 无
*-------------------------------------------------------------------
作者：          修改日期                        修改描述
bill                       20100525                       创建
***********************************************************************/
GB_UINT GB_file_Get_file_size(GB_CHAR * pName)
{
	GB_UINT size=0;
	GB_FILEHANDLE pFile = GB_file_open(pName,"rb");
	
	if(pFile==GB_FILEHANDLE_ER)return 0;
	
	FS_GetFileSize(pFile,&size);

	GB_file_close(pFile);
	return size;
}

GB_UINT GB_file_Get_file_sizeByHandle(GB_FILEHANDLE pFile)
{
	GB_UINT size=0;

	if (pFile != GB_FILEHANDLE_ER)
	{
		FS_GetFileSize(pFile,&size);
	}

	return size;
}


GB_UINT GB_file_Get_file_sizeEx(GB_CHAR * pName,GB_WCHAR drive)
{
	GB_UINT size=0;
	GB_FILEHANDLE pFile = GB_file_openEx(pName,"rb",drive,GB_MIN_FILE_FREESPACE);
	
	if(pFile==GB_FILEHANDLE_ER)return 0;
	
	FS_GetFileSize(pFile,&size);
	GB_file_close(pFile);
	return size;
}

/**********************************************************************
* 函数名称： GB_file_copy
* 功能描述：文件拷贝
* 输入参数：pSourceName 源文件
*			pTargetName 目标文件
*			offset 偏移量
*			nSize 拷贝长度
* 输出参数：模式
* 返 回 值： 无
*-------------------------------------------------------------------
作者：           修改日期                        修改描述
zhangwei-jerry   20101222                          创建
***********************************************************************/
GB_INT GB_file_copy(GB_CHAR * pSourceName,GB_CHAR * pTargetName,GB_INT offset,GB_INT nSize)
{
	return GB_file_copyEx(pSourceName,pTargetName,offset,nSize,GB_TRUE);
// 	GB_INT retWritenSize = -1;
// 
// 	if (pSourceName != GB_NULL && pTargetName != GB_NULL)
// 	{
// 		GB_FILEHANDLE pSourceFile = GB_FILEHANDLE_ER;
// 		GB_FILEHANDLE pTargetFile = GB_FILEHANDLE_ER;
//  		pSourceFile = GB_file_open(pSourceName,"rb");
// 		pTargetFile = GB_file_open(pTargetName,"wb");
// 
// 		// 读取到文件句柄
// 		if (pSourceFile != GB_FILEHANDLE_ER && 
// 			pTargetFile != GB_FILEHANDLE_ER)
// 		{
// 			GB_UINT size		= 0;
// 			GB_UINT	copySize	= 0;
// 			GB_CHAR* pData		= GB_NULL;
// 
// 			FS_GetFileSize(pSourceFile,&size);
// 
// 			// 获取能拷贝的文件最大长度
// 			if (nSize == GB_FILE_SIZEDEFAULT)
// 			{
// 				copySize = size;
// 			}
// 			else
// 			{
// 				copySize = size >= (GB_UINT)nSize ? nSize : size;
// 			}
// 		
// 			if(copySize > 0)
// 			{
// 				// 跳过offset数据
// 				GB_file_skip(pSourceFile,offset);
// 				
// 				// 分配一个数据缓存
// 				pData = (GB_CHAR*)GB_WG_Malloc(copySize * sizeof(GB_CHAR));
// 				
// 				if (pData)
// 				{
// 					GB_INT	nRead		= 0;
// 					// 读取文件流
// 					nRead = GB_file_read(pSourceFile,pData,copySize);
// 					
// 					if (nRead > 0)
// 					{
// 						// copy文件流
// 						retWritenSize = GB_file_write(pTargetFile,pData,nRead);
// 					}
// 					
// 					// 释放缓存数据
// 					GB_WG_Free(pData);
// 					pData = GB_NULL;
// 				}
// 			}
// 			else
// 			{
// 				retWritenSize = 0;
// 			}
// 
// 			// 关闭了
// 			GB_file_close(pSourceFile);
// 			GB_file_close(pTargetFile);
// 		}
// 	}
// 
// 	return retWritenSize;
}

GB_INT GB_file_copyEx(GB_CHAR * pSourceName,GB_CHAR * pTargetName,GB_INT offset,GB_INT nSize,GB_BOOL needDrive)
{
	GB_INT retWritenSize = -1;
	
	if (pSourceName != GB_NULL && pTargetName != GB_NULL)
	{
		GB_FILEHANDLE pSourceFile = GB_FILEHANDLE_ER;
		GB_FILEHANDLE pTargetFile = GB_FILEHANDLE_ER;

		if (needDrive)
		{
			pSourceFile = GB_file_openEx(pSourceName,"rb",GB_WG_GetWinguoDrive(),GB_MIN_FILE_FREESPACE);
			pTargetFile = GB_file_openEx(pTargetName,"wb",GB_WG_GetWinguoDrive(),GB_MIN_FILE_FREESPACE);
		}
		else
		{
			pSourceFile = GB_file_openEx(pSourceName,"rb",pSourceName[0],GB_MIN_FILE_FREESPACE);
			pTargetFile = GB_file_openEx(pTargetName,"wb",pTargetName[0],GB_MIN_FILE_FREESPACE);
		}
		
		
		// 读取到文件句柄
		if (pSourceFile != GB_FILEHANDLE_ER && 
			pTargetFile != GB_FILEHANDLE_ER)
		{
			GB_UINT size		= 0;
			GB_UINT	copySize	= 0;
			GB_CHAR* pData		= GB_NULL;
			
			FS_GetFileSize(pSourceFile,&size);
			
			// 获取能拷贝的文件最大长度
			if (nSize == GB_FILE_SIZEDEFAULT)
			{
				copySize = size;
			}
			else
			{
				copySize = size >= (GB_UINT)nSize ? nSize : size;
			}
			
			if(copySize > 0)
			{
				// 跳过offset数据
				GB_file_skip(pSourceFile,offset);
				
				// 分配一个数据缓存
				pData = (GB_CHAR*)GB_WG_Malloc(copySize * sizeof(GB_CHAR));
				
				if (pData)
				{
					GB_INT	nRead		= 0;
					// 读取文件流
					nRead = GB_file_read(pSourceFile,pData,copySize);
					
					if (nRead > 0)
					{
						// copy文件流
						retWritenSize = GB_file_write(pTargetFile,pData,nRead);
					}
					
					// 释放缓存数据
					GB_WG_Free(pData);
					pData = GB_NULL;
				}
			}
			else
			{
				retWritenSize = 0;
			}
			
			// 关闭了
			GB_file_close(pSourceFile);
			GB_file_close(pTargetFile);
		}
	}
	
	return retWritenSize;
}


GB_BOOL GB_file_rename(GB_CHAR * pSourceName,GB_CHAR * pTargetName)
{
	GB_BOOL ret = GB_FALSE;

	if (pSourceName && pTargetName)
	{
		GB_WCHAR* pwSourceName = GB_utf8_to_unicode(pSourceName,GB_STRLEN(pSourceName));
		GB_WCHAR* pwTargetName = GB_utf8_to_unicode(pTargetName,GB_STRLEN(pTargetName));

// 		pwSourceName[0] = (GB_WCHAR)GB_WgGetDrive();
// 		pwTargetName[0] = (GB_WCHAR)GB_WgGetDrive();
		pwSourceName[0] = GB_WG_GetWinguoDrive();
		pwTargetName[0] = GB_WG_GetWinguoDrive();


		if (pwSourceName && pwTargetName)
		{
			if (FS_Rename(pwSourceName,pwTargetName) >= GB_FILEHANDLE_ER)
			{
				ret = GB_TRUE;
			}
		}


		if (pwSourceName)
		{
			GB_WG_Free(pwSourceName);
			pwSourceName = GB_NULL;
		}

		if (pwTargetName)
		{
			GB_WG_Free(pwTargetName);
			pwTargetName = GB_NULL;
		}
	}

	return ret;
}

GB_UINT GBFS_get_dirver_free_space(GB_WCHAR * dirname,GB_WCHAR drive)
{
    GB_UINT result;
    FS_DiskInfo disc_info;
	
	//dirname[0] = (GB_WCHAR)GB_WgGetDrive();
	if (drive)
		dirname[0] = (GB_WCHAR)drive;
    result = FS_GetDiskInfo((GB_U16 *)dirname, &disc_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if( result >= 0 )
    {
        result = disc_info.FreeClusters * disc_info.SectorsPerCluster * disc_info.BytesPerSector;
		return result;
    }
    else
    {
        return 0;
    }
}

GB_INT GB_WG_ReadFileData(GB_CHAR *buffer, GB_INT count, GB_FILEHANDLE fp, GB_INT seek)
{
	FS_Seek(fp, seek, FS_FILE_BEGIN);
	GB_file_read(fp, buffer, count);
	return 1;
}
GB_INT GB_WG_WriteFileData(GB_CHAR *buffer, GB_INT len, GB_FILEHANDLE fp, GB_INT seek)
{	
	GB_UINT olen;
	FS_Seek(fp, seek, FS_FILE_BEGIN);
	olen = GB_file_write(fp, buffer, len);
	if (olen != (GB_UINT)len)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

GB_INT GB_file_createdir(GB_WCHAR * pDirName)
{
	pDirName[0] = GB_WG_GetWinguoDrive();//GB_WgGetDrive();
	return FS_CreateDir(pDirName);
}

GB_INT GB_file_FloderFileAcountEx(GB_CHAR *pFloderName,GB_WCHAR drive)
{
	GB_INT ret = 0;
	GB_WCHAR* pwPath;
	
	pwPath = GB_utf8_to_unicode(pFloderName,GB_STRLEN(pFloderName));
	if(pwPath==GB_NULL)return 0;
	//pwPath[0] = (GB_WCHAR)GB_WgGetDrive();
	if (drive)
		pwPath[0] =	drive;
	if(gb_wg_wcslen(pwPath) != 0){////////
		ret = GB_WgGetDirFileCount(pwPath);
	}

	GB_WG_Free(pwPath);
	
	return ret;
}

GB_INT GB_file_Delete(GB_WCHAR * pDirName)
{
	return FS_Delete(pDirName);
}


GB_INT GB_file_GetFileInfo(GB_CHAR * pName,GB_WCHAR drive,GB_FileInfo* info)
{
	GB_INT result = 0;
	GB_FILEHANDLE pFile = GB_file_openEx(pName,"rb",drive,GB_MIN_FILE_FREESPACE);

	if(pFile==GB_FILEHANDLE_ER)
	{
		GB_file_close(pFile);
		return 0;
	}

	if (info)
	{
		result = FS_GetFileInfo(pFile,(FS_FileInfo*)info);
	}

	return result;
}

GB_INT GB_file_GetFileCreatTime(GB_CHAR * pName,GB_WCHAR drive,GB_TIME_STRUCT* creatDatatime)
{
	GB_INT result = 0;

	GB_FileInfo info = {0};

	GB_TIME_STRUCT* pCreatDatatime = (GB_TIME_STRUCT*)creatDatatime;

	result = GB_file_GetFileInfo(pName,drive,&info);

	if (creatDatatime)
	{
		const FS_DOSDateTime* pTime = &info.DirEntry->CreateDateTime;

		pCreatDatatime->nYear	= pTime->Year1980 + 1980;
		pCreatDatatime->nMonth	= pTime->Month;
		pCreatDatatime->nDay	= pTime->Day;
		pCreatDatatime->nHour	= pTime->Hour;
		pCreatDatatime->nMin	= pTime->Minute;
		pCreatDatatime->nSec	= pTime->Second2;
	}

	return result;
}


// add by zhangwei-jerry 20110921
// winguo储存的驱动
GB_WCHAR g_GB_WG_winguoSaveDrive = 0;
// smartdail储存的驱动
GB_WCHAR g_GB_WG_smartdailSaveDrive = 0;

// 判断drive的有效性
GB_BOOL GB_WG_DriveIsVaild(GB_WCHAR drive)
{
	if (drive)
	{
		if (drive == GB_WG_GetPhoneDisc() ||
			drive == GB_WG_GetTCard())
		{
			return GB_TRUE;
		}
	}
	
	return GB_FALSE;
}

//////////////////////////////////////////////////////////////////////////
GB_VOID GB_WG_SetSmartdailDrive(GB_WCHAR drive)
{
	// 容错,无效的情况下，赋值为phonedisc
	if (!GB_WG_DriveIsVaild(drive))
	{
		g_GB_WG_smartdailSaveDrive = GB_WG_GetPhoneDisc();
	}
	else
	{
		g_GB_WG_smartdailSaveDrive = drive;
	}
// 	GB_WCHAR anotherDrive = 0x0000;
// 
// 	GB_UINT needFreeSpace = GB_MIN_FREE_SPACE;
// 	//如果没空间需要存储另外一个盘了，如果另外一个盘都没有空间了就创建不了了
// 	anotherDrive = GB_WG_GetTCard();
// 
// 	if (GBFS_get_dirver_free_space(L"c:\\guobi\\",drive) > needFreeSpace)
// 	{
// 		if (!GB_WG_DriveIsVaild(g_GB_WG_winguoSaveDrive))
// 		{
// 			g_GB_WG_winguoSaveDrive = GB_WG_GetPhoneDisc();
// 		}
// 		else
// 		{
// 			g_GB_WG_winguoSaveDrive = drive;
// 		}
// 	}
// 	else if (GBFS_get_dirver_free_space(L"c:\\guobi\\",anotherDrive) > needFreeSpace)
// 	{
// 		if (!GB_WG_DriveIsVaild(g_GB_WG_winguoSaveDrive))
// 		{
// 			g_GB_WG_winguoSaveDrive = anotherDrive;
// 		}
// 		else
// 		{
// 			g_GB_WG_winguoSaveDrive = anotherDrive;
// 		}
// 	}
}

GB_WCHAR GB_WG_GetSmartdailDrive(GB_VOID)
{
	return g_GB_WG_smartdailSaveDrive;
}


//////////////////////////////////////////////////////////////////////////
GB_VOID GB_WG_SetWinguoDrive(GB_WCHAR drive)
{
	// 容错,无效的情况下，赋值为phonedisc
// 	GB_WCHAR anotherDrive = 0x0000;
// 
// 	GB_UINT needFreeSpace = GB_MIN_FREE_SPACE;
// 	//如果没空间需要存储另外一个盘了，如果另外一个盘都没有空间了就创建不了了
// 	anotherDrive = GB_WG_GetTCard();
// 
// 	if (GBFS_get_dirver_free_space(L"c:\\guobi\\",drive) > needFreeSpace)
// 	{
// 		if (!GB_WG_DriveIsVaild(g_GB_WG_winguoSaveDrive))
// 		{
// 			g_GB_WG_winguoSaveDrive = GB_WG_GetPhoneDisc();
// 		}
// 		else
// 		{
// 			g_GB_WG_winguoSaveDrive = drive;
// 		}
// 	}
// 	else if (GBFS_get_dirver_free_space(L"c:\\guobi\\",anotherDrive) > needFreeSpace)
// 	{
// 		if (!GB_WG_DriveIsVaild(g_GB_WG_winguoSaveDrive))
// 		{
// 			g_GB_WG_winguoSaveDrive = anotherDrive;
// 		}
// 		else
// 		{
// 			g_GB_WG_winguoSaveDrive = anotherDrive;
// 		}
// 	}

	if (!GB_WG_DriveIsVaild(drive))
	{
		g_GB_WG_winguoSaveDrive = GB_WG_GetPhoneDisc();
	}
	else
	{
		g_GB_WG_winguoSaveDrive = drive;
	}

}

GB_WCHAR GB_WG_GetWinguoDrive(GB_VOID)
{
	if (!GB_WG_DriveIsVaild(g_GB_WG_winguoSaveDrive))
		return GB_WG_GetPhoneDisc();
	else
		return g_GB_WG_winguoSaveDrive;
}

GB_BOOL GB_WG_CanSaveWinguoData()
{
	if (GB_WG_GetWinguoDrive())
	{
		return GB_TRUE;
	}
	else
	{
		return GB_FALSE;
	}
}

// 放在手机disk中
GB_WCHAR GB_WG_GetPhoneDisc(GB_VOID)
{
	return FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
}
// 放在T卡上
GB_WCHAR GB_WG_GetTCard(GB_VOID)
{
	return FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
}


GBRETURN GB_WG_File_match_pattern(const GB_WCHAR *p, const GB_WCHAR *n)
{
    const GB_WCHAR * LastWild = NULL;
    const GB_WCHAR * LastWildN = NULL;
	
    ASSERT(p!= NULL && n!= NULL);
	
    while (1)
    {
        while ( p[0] && n[0] )
        {
			GB_WCHAR P = GB_WCHARLOW(p[0]);
			GB_WCHAR N = GB_WCHARLOW(n[0]);
			
			if (P == 0x2a)
			{
				LastWild = p;
				if (GB_WCHARLOW(p[1]) == N)
				{
					LastWildN = n;
					p++;
					P = GB_WCHARLOW(p[0]);
				}
			}
			if ((P == N) || (P == 0x3F))
				p++, n++;
			else if (P == 0x2A)
				n++;
			else
				break;
        }
        if ( (n[0]==0) && (p[0]==0 || (p[0]==0x2a && p[1]==0)) )
			return 1;
        if (LastWild && LastWildN && LastWildN[1])
        {
			p = LastWild;
			n = ++LastWildN;
        }
        else
			return 0;
    }
}

GB_FILEHANDLE GB_WG_FindFirst(GB_WCHAR* floderPath,GB_WCHAR drive,GB_WCHAR* file_name,GB_UINT file_name_len)
{
	FS_DOSDirEntry  file_info;
	GB_FILEHANDLE	file_handle = 0;

	// 获取句柄
	if (floderPath && gb_wg_wcslen(floderPath) > 0)
	{
		// 需要组合星号，找寻该文件夹下所有的文件
		GB_WCHAR star[6] = L"\\*";
		GB_INT len = gb_wg_wcslen(star) + gb_wg_wcslen(floderPath);
		GB_WCHAR* pFloderPath = (GB_WCHAR*)GB_WG_Malloc((len + 1) * sizeof(GB_WCHAR));

		if (pFloderPath)
		{
			GB_MEMSET(pFloderPath,0,(len + 1) * sizeof(GB_WCHAR));
			
			gb_wg_wcsncat(pFloderPath,floderPath,gb_wg_wcslen(floderPath));
			gb_wg_wcsncat(pFloderPath,star,gb_wg_wcslen(star));

			pFloderPath[0] = drive;
			
			file_handle = GB_WgGetDirFirstFile(pFloderPath,file_info,file_name,file_name_len);

			GB_WG_Free(pFloderPath);
		}
	}

	return file_handle;
}

GB_FILEHANDLE GB_WG_FindFirstEx(GB_WCHAR* floderPath,GB_WCHAR* extension,GB_WCHAR drive,GB_WCHAR* file_name,GB_UINT file_name_len)
{
	FS_DOSDirEntry  file_info;
	GB_FILEHANDLE	file_handle = GB_FILEHANDLE_ER;

	GB_WCHAR* pFloderPath = GB_NULL;
	GB_WCHAR* pExtension = GB_NULL;
	// 获取句柄
	if (floderPath && gb_wg_wcslen(floderPath) > 0)
	{
		// 需要组合星号，找寻该文件夹下所有的文件
		GB_WCHAR star[6] = L"\\*";
		GB_INT len = gb_wg_wcslen(star) + gb_wg_wcslen(floderPath);
		
		GB_WCHAR star_extension[3]  = L"*.";
		//GB_WG_Malloc((gb_wg_wcslen(star_extension) + gb_wg_wcslen(extension) + 1) * sizeof(GB_WCHAR));

		pFloderPath = (GB_WCHAR*)GB_WG_Malloc((len + 1) * sizeof(GB_WCHAR));

		// 需要判断后缀
		if (extension)
		{
			pExtension = GB_WG_Malloc((gb_wg_wcslen(star_extension) + gb_wg_wcslen(extension) + 1) * sizeof(GB_WCHAR));
			
			if (pExtension)
			{
				GB_MEMSET(pExtension,0,(gb_wg_wcslen(star_extension) + gb_wg_wcslen(extension) + 1) * sizeof(GB_WCHAR));

				gb_wg_wcscat(pExtension,star_extension);
				gb_wg_wcscat(pExtension,extension);
			}
		}
		
		if (pFloderPath)
		{
			GB_MEMSET(pFloderPath,0,(len + 1) * sizeof(GB_WCHAR));
			
			gb_wg_wcsncat(pFloderPath,floderPath,gb_wg_wcslen(floderPath));
			gb_wg_wcsncat(pFloderPath,star,gb_wg_wcslen(star));
			
			pFloderPath[0] = drive;
			
			file_handle = GB_WgGetDirFirstFile(pFloderPath,file_info,file_name,file_name_len);

			if (file_handle <= 0)
			{
				goto END;
			}
			else
			{

				if (extension)
				{
					//if (GB_STRNICMP(extension,file_info.Extension,GB_STRLEN(extension)) == 0)
					if (GB_WG_File_match_pattern(pExtension,file_name))
					{
						goto END;
					}
					else
					{
						// 获取下一个文件的句柄
						if (GB_WG_FindNext(file_handle,extension,file_name,file_name_len) != GB_FILE_NO_ERROR)
						{
							// 关闭句柄吧
							GB_file_findClose(file_handle);
							file_handle = GB_FILEHANDLE_ER;
						}
					}
				}
			}
		}
	}

END:
	if (pFloderPath)
	{
		GB_WG_Free(pFloderPath);
	}

	if (pExtension)
	{
		GB_WG_Free(pExtension);
	}

	return file_handle;
}

GB_INT GB_WG_FindNext(GB_FILEHANDLE handle,GB_WCHAR* extension,GB_WCHAR* file_name,GB_UINT file_name_len)
{
	GB_INT	retFindResult = GB_FILE_NO_ERROR;
	FS_DOSDirEntry  file_info;
	GB_WCHAR star[3]  = L"*.";
	GB_WCHAR* pExtension = GB_WG_Malloc((gb_wg_wcslen(star) + gb_wg_wcslen(extension) + 1) * sizeof(GB_WCHAR));
	
	// 获取句柄
	if (handle > 0)
	{
		if (pExtension)
		{
			GB_MEMSET(pExtension,0,(gb_wg_wcslen(star) + gb_wg_wcslen(extension) + 1) * sizeof(GB_WCHAR));
			gb_wg_wcscat(pExtension,star);
			gb_wg_wcscat(pExtension,extension);
		//}
		// 是否需要后缀匹配
		//if (pExtension && gb_wg_wcslen(pExtension) > 0)
		//{
			retFindResult = GB_WgGetDirNextFile(handle,file_info,file_name,file_name_len);

			do 
			{
				if (retFindResult < 0)
				{
					goto END;
				}
				else
				{
					//if (GB_STRNICMP(extension,file_info.Extension,GB_STRLEN(extension)) == 0)
					if (GB_WG_File_match_pattern(pExtension,file_name))
					{
						goto END;
					}
					else
					{
						// 获取下一个文件的句柄
						retFindResult = GB_WgGetDirNextFile(handle,file_info,file_name,file_name_len);
					}
				}

			} while (1);
		}
		else
		{
			retFindResult = GB_WgGetDirNextFile(handle,file_info,file_name,file_name_len);
		}
	}
	
END:
	if (pExtension)
	{
		GB_WG_Free(pExtension);
	}

	return retFindResult;
}
#endif /* #ifdef __MMI_GB_WINGUO__ */
