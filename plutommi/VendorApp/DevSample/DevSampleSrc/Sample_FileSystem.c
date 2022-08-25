/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  Sample_FileSystem.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sample code for File System
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#include "APPSDKFrameworkGProt.h"
#include "APPSDKSystemServiceGProt.h"

/****************************************************************************
*
*  [Sample]
*  Purpose   : How to use these File system APIs
*  Function  : How to create a folder, create/open, read, write and close a file 
*  Notice    : 
*  Branch    : 08A, 08B, MAUI
*  API Ref   : FS_GetDrive, FS_CreateDir 
*              FS_Open, FS_Write, FS_Seek, FS_Read, FS_Close
*  
*
*****************************************************************************/

#define TEMP_BUFFER_LEN	40

/*****************************************************************************
 * FUNCTION
 *  mmi_sample_filesystem
 * DESCRIPTION
 *  files related operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_filesystem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    FS_HANDLE folder_handle;
    U16 folder[TEMP_BUFFER_LEN];
    U16 path[TEMP_BUFFER_LEN];
	S8 buf[TEMP_BUFFER_LEN];
    U16 content[TEMP_BUFFER_LEN];
    U32 size;
    U32 written;
    U32 readed;
    S32 ret_drv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	/*Get system drive*/
    ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, /*drive type*/
						2, /*drive number (NORMAL: 1 or 2)*/
						FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM); /*altMask*/
    if (ret_drv >= 0)
    {
        sprintf(buf, "%c:\\", (U8) ret_drv);
		mmi_asc_to_wcs(path, buf);
        mmi_asc_to_wcs(folder, buf);
        mmi_wcscat(path, L"foldername\\filename");
        mmi_wcscat(folder, L"foldername\\");
    }
   
	/* Open folder*/
	folder_handle = FS_Open(folder, FS_OPEN_DIR | FS_READ_ONLY);
    if (folder_handle < FS_NO_ERROR)
    {
		/*Fail to open the folder, means not the folder*/	
		/*Create folder*/
        folder_handle = FS_CreateDir(folder);
    }
    else
    {
		/*Success to open*/
        FS_Close(folder_handle);
    }

	/*open file*/
    file_handle = FS_Open(path, FS_READ_WRITE | FS_CREATE);
    if (file_handle < FS_NO_ERROR)
    {
		/*Fail to create file*/
		return;
    }
	else
	{
		/*Success to create file*/
	}

	size = strlen("sample") * ENCODING_LENGTH;
	/*write Ucs2 string to file*/
    FS_Write(file_handle, L"sample", size, &written);
	/*seek to file begin*/
    FS_Seek(file_handle, 0, FS_FILE_BEGIN);    
	memset(content, 0, sizeof(content));
	/*read data from file*/
    FS_Read(file_handle, content, size, &readed);

	/*close file*/
    FS_Close(file_handle);
}




