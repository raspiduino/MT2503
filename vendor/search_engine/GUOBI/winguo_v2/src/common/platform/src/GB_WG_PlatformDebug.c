
/*********  平台头文件 ********/
#include "fs_gprot.h"

/*********  内部头文件 ********/
#include "GB_WG_DataTypeDef.h"

/*****************************/
/*****************************/

#define GB_WG_DEBUG_LOG_FILE L"C:\\wg_debug.txt"


GB_VOID GB_WG_Platform_Assert(GB_CHAR* expr, GB_CHAR* file, GB_UINT line, GB_INT n)
{
	if (!n)
	{
		kal_assert_fail(expr, file, line, KAL_FALSE, 0, 0, 0, NULL);
	}
}


GB_VOID GB_WG_Platform_WriteLog(GB_CHAR* pData, GB_INT len)
{
	FS_HANDLE fh;
	if (!pData || !pData)
	{
		return;
	}
	fh = FS_Open(GB_WG_DEBUG_LOG_FILE, FS_READ_WRITE);
	if (fh >= FS_NO_ERROR)
	{
		UINT Written = 0;
		FS_Write(fh, pData, len, &Written);
		if (Written != len)
		{
			ASSERT(0);
		}
		FS_Close(fh);
	}
}
