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
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__
#include "avk_conn_btds.h"
#include "fs_func.h"

#if 1
/************************************************************************/
/* DS VECTOR START                                                      */
/************************************************************************/
#include <stdio.h>
static const char* sg_file = NULL;
static int sg_line = 0;


#if defined(WIN32) && defined(_DEBUG)

void vs_bt_win32_setdata(int line, const char* file)
{
    sg_file = file;
    sg_line = line;
}

void vs_bt_win32_outlog(const char* log, ...)
{
    DS_S8 buf[DS_BUF_SIZE] = {0};
    va_list ap;
    va_start(ap, log);
    vsprintf(buf, log, ap);
    sprintf(&buf[strlen(buf)], " line[%d], file[%s]", sg_line, sg_file);
    va_end(ap);
    printf(buf);
}

#else /* defined(WIN32) && defined(_DEBUG) */

extern void vs_bt_target_setdata(DS_S32 line, const DS_S8* file)
{
    sg_file = file;
    sg_line = line;
}

extern void vs_bt_target_outfile(const DS_S8* log, ...)
{
    char buf[DS_BUF_SIZE] = {0};
    DS_U16 wszBuf[DS_BUF_SIZE] = {0};
    FS_HANDLE file_hdl = -1;

    va_list ap;
    va_start(ap, log);
    vsprintf(buf, log, ap);
    sprintf(&buf[strlen(buf)], " line[%d], file[%s]", sg_line, sg_file);
    va_end(ap);

    mmi_asc_n_to_wcs(wszBuf, buf, DS_BUF_SIZE);

    file_hdl = vs_bt_ds_fileopen((DS_U16*)LOG_FILE);
    if (0 > file_hdl)
    {
        return;
    }

    if (!vs_bt_ds_filewrite(file_hdl, wszBuf, 2*kal_wstrlen(wszBuf) + 2))
    {
        return;
    }

    if (0 > vs_bt_ds_fileclose(file_hdl))
    {
        return;
    }
}

extern void vs_bt_target_catcher(const DS_S8* log, ...)
{
    char buf[DS_BUF_SIZE] = {0};

    va_list ap;
    va_start(ap, log);
    sprintf(buf, "[AVK_BT] line[%d], file[%s] ", sg_line, sg_file);
    vsprintf(&buf[strlen(buf)], log, ap);
    va_end(ap);

    kal_prompt_trace(MOD_MMI, buf);
}



#endif /* defined(WIN32) && defined(_DEBUG) */


FS_HANDLE vs_bt_ds_fileopen(const DS_U16* name)
{
    DS_S32 drv = FS_NO_ERROR;
    DS_U16 pathname[80] = {0};
    FS_HANDLE folder_hdl = -1;
    FS_HANDLE file_hdl = -1;

    ASSERT(name);

    drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);

    if (FS_NO_ERROR > drv)
    {
        return -1;
    }

    // THISrge pathnaTHIS
    kal_wsprintf(pathname, "%c:\\", (U8)drv);
    kal_wstrcat(pathname, LOG_FOLDER);

    // create if the path is not exist
    folder_hdl = FS_Open(pathname, FS_OPEN_DIR | FS_READ_ONLY);
    if (FS_NO_ERROR > folder_hdl)
    {
        folder_hdl = FS_CreateDir(pathname);
        //ASSERT(folder_hdl >= FS_NO_ERROR);
        return -2;
    }
    else
    {
        FS_Close(folder_hdl);
    }

    kal_wstrcat(pathname, name);

    file_hdl = FS_Open(pathname, FS_READ_WRITE);
    if (FS_NO_ERROR > file_hdl)
    {
        file_hdl = FS_Open(pathname, FS_READ_WRITE | FS_CREATE);
    }

    return file_hdl;
}

DS_S32 vs_bt_ds_filewrite(FS_HANDLE hdl, const DS_U16* txt, DS_U32 size)
{
    DS_S8 szbuf[DS_BUF_SIZE] = {0};
    DS_U16 wszbuf[DS_BUF_SIZE] = {0};
    DS_S32 len = 0;
    DS_U32 written = 0;

    ASSERT((FS_NO_ERROR <= hdl) && txt && (0 < size) && (DS_BUF_SIZE >=size));

    if (FS_NO_ERROR > FS_Seek(hdl, 0, FS_FILE_END))
    {
        return -1;
    }


    kal_wstrncpy(wszbuf, txt, size);
    mmi_wcs_n_to_asc(szbuf, wszbuf, size);
    strcat(&szbuf[strlen(szbuf)], "\r\n");

    len = strlen(szbuf);
    if (FS_NO_ERROR > FS_Write(hdl, szbuf, len, &written))
    {
        return -1;
    }

    return written;
}

// dummy.
DS_S32 vs_bt_ds_fileread(FS_HANDLE hdl, DS_U16* txt, DS_U32 size)
{
    /*
    S8 szbuf[DS_BUF_SIZE] = {0};
    S32 len = 0;
    UINT read = 0;
    */
    ASSERT((FS_NO_ERROR <= hdl) && txt && (0 < size));

    return 0;
}

DS_S32 vs_bt_ds_fileclose(FS_HANDLE hdl)
{
    ASSERT(hdl);
    return FS_Close(hdl);
}


U8  vs_str2hex(const CHAR * str)
{
    static CHAR sz[] = {"0123456789abcdef"};
    S32 i = 0;
    U8 ret = 0x00;
    CHAR tmp_sz[3] = {0};
    strncpy(tmp_sz, str, 2);

    for (i = 0; i < sizeof(sz) / sizeof(CHAR); i++)
    {
        if (tmp_sz[0] == sz[i])
            break;
    }

    ret = 0xf0 & (i << 4);
    
    for (i = 0; i < sizeof(sz) / sizeof(CHAR); i++)
    {
        if (tmp_sz[1] == sz[i])
            break;
    }

    ret |= (0x0f & i);
    
    return ret;
}


#endif /* 1 */

#endif /* __MAUI_SDK_TEST__ */

