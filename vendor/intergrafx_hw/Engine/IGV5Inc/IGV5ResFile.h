/*!****************************************************************************

 @File         IGV5ResFile.h

 @Title        IGV5ResFile

 @Version      

 @brief			header file for resource management

******************************************************************************/

#ifndef _IGV5RESOURCEFILE_H_
#define _IGV5RESOURCEFILE_H_


#include "IGV5Def.h"
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!***************************************************************************
 @struct IGV5ResFile
 @brief Simple resource file wrapper
*****************************************************************************/
typedef struct {

	int m_bOpen;
	int m_bMemoryFile;
	size_t m_Size;
	char* m_pData;
	char s_ReadPath[IGV5_MAXPATH_LEN];

} IGV5ResFile;

/*!***************************************************************************
@fn			IGV5ResFile_SetReadPath
@param		pszReadPath			The path where you would like to read from
@brief		Sets the read path
*****************************************************************************/
void IGV5ResFile_SetReadPath(IGV5ResFile *pThis, char* pszReadPath);

/*!***************************************************************************
@fn			IGV5ResFile_GetReadPath
@return		The currently set read path
@brief		Returns the currently set read path
*****************************************************************************/
char *IGV5ResFile_GetReadPath(IGV5ResFile *pThis);

/*!***************************************************************************
@fn			CPVRTResourceFile
@param				pszFilename Name of the file you would like to open
@brief		Constructor
*****************************************************************************/
IGV5Err IGV5ResFile_Create(IGV5ResFile *pThis, char* pszFilename);

/*!***************************************************************************
@fn			IGV5ResFile_CreateFromMemory
@param		pData A pointer to the data you would like to use
@param		i32Size The size of the data
@brief		Constructor
*****************************************************************************/
IGV5Err IGV5ResFile_CreateFromMemory(IGV5ResFile *pThis, char* pData, size_t i32Size);

/*!***************************************************************************
@fn			IGV5ResFile_Release
@brief		Destructor
*****************************************************************************/
void IGV5ResFile_Release(IGV5ResFile *pThis);


/*!***************************************************************************
@fn			IGV5ResFile_IsOpen
@return		true if the file is open
@brief		Is the file open
*****************************************************************************/
int IGV5ResFile_IsOpen(IGV5ResFile *pThis);

/*!***************************************************************************
@fn			IGV5ResFile_IsMemoryFile
@return		true if the file was opened from memory
@brief		Was the file opened from memory
*****************************************************************************/
int IGV5ResFile_IsMemoryFile(IGV5ResFile *pThis) ;

/*!***************************************************************************
@fn			IGV5ResFile_GetSize
@return		The size of the opened file
@brief		Returns the size of the opened file
*****************************************************************************/
size_t IGV5ResFile_GetSize(IGV5ResFile *pThis);

/*!***************************************************************************
@fn			IGV5ResFile_DataPtr
@return		A pointer to the file data
@brief		Returns a pointer to the file data
*****************************************************************************/
void* IGV5ResFile_DataPtr(IGV5ResFile *pThis);


/*!***************************************************************************
@fn			IGV5ResFile_StringPtr
@return		The file data as a string
@brief		Returns the file as a null-terminated string
*****************************************************************************/
// convenience getter. Also makes it clear that you get a null-terminated buffer.
char* IGV5ResFile_StringPtr(IGV5ResFile *pThis);


/*!***************************************************************************
@fn			IGV5ResFile_Close
@brief		Closes the file
*****************************************************************************/
void IGV5ResFile_Close(IGV5ResFile *pThis);

#ifdef __cplusplus
}
#endif

#endif


