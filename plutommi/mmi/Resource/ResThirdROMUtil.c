#include "string.h"
#include "third_rom.h"

#if !defined(__MTK_TARGET__)
#define UNICODE

#include <stdio.h>
#include "Windows.h"
#endif /* !defined(__MTK_TARGET__) */ 

#if !defined(__MTK_TARGET__)
#define _WINDOWS_       /* to solve redefine prbolem */
#endif 

#if !defined(__MTK_TARGET__)

#if !defined(ASSERT) 
	#define ASSERT(expr) do {if(!(expr)) {} } while (0)
#endif // ASSERT


typedef struct res_modis_thirdrom_bin
{
   unsigned char cid;
   TCHAR tchBuffer[40];
} THIRDROM_MODIS_BIN;

#define MAX_RES_MODIS_THIRDROM_BINS 6

THIRDROM_MODIS_BIN resThirdROMBins[] = {
  {ENFB_CONTENT_IMAGERES,    L"..\\MoDIS\\CustMMI3rdROM"},
  {ENFB_CONTENT_STRINGRES,   L""},
  {ENFB_CONTENT_THEMES,      L"..\\MoDIS\\CustEnfbVenusThemeData"},
  {ENFB_CONTENT_APPICONS,    L"..\\MoDIS\\CustEnfbVenusAppIconData"},
  {ENFB_CONTENT_HANDWRITING, L"..\\MoDIS\\hw_data.gbd"},
  {ENFB_CONTENT_FONT,        L"..\\MoDIS\\CustENFBFontData"}
};

TCHAR * MMI_NFB_RES_GET_MODIS_BIN(unsigned char localCid){
	int i =0;
	
	for(i =0; i < MAX_RES_MODIS_THIRDROM_BINS; i++){
		if(resThirdROMBins[i].cid == localCid){
            return resThirdROMBins[i].tchBuffer;
		}
	}
	return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  NFB_RES_Load
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cid             [IN]        
 *  dst_addr        [?]         [?]
 *  offset          [IN]        
 *  length          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int MMI_NFB_RES_Load(unsigned char cid, void *dst_addr, unsigned int offset, unsigned int length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define TCHAR_BUFFER_SIZE 512
    HANDLE hFile;
    int ret = 0;
    int size = length;
    char *buf = (char*)dst_addr;
    unsigned int bytesRead;
    TCHAR tchBuffer[TCHAR_BUFFER_SIZE];
	TCHAR * localBinFile = NULL;
    extern TCHAR fssim_root_dir[];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetCurrentDirectory(TCHAR_BUFFER_SIZE, tchBuffer);
    wcscpy(tchBuffer, fssim_root_dir);
	localBinFile = MMI_NFB_RES_GET_MODIS_BIN(cid);
	
	ASSERT(localBinFile!=NULL);
    wcscat(tchBuffer, localBinFile);
    

    hFile = CreateFile(tchBuffer, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
       ASSERT(0);
    }
    SetFilePointer(hFile, offset, NULL, FILE_BEGIN);
    ret = ReadFile(hFile, dst_addr, (DWORD) length, &bytesRead, NULL);

    CloseHandle(hFile);

    return 1;
}

#endif // __MTK_TARGET__