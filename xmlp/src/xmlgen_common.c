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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  xmlgen_common.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  xml generator file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if (defined(__XML_SUPPORT__) || defined(__WBXML_SUPPORT__))

//#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include "kal_release.h"        /* Basic data type */
//#include "App_buff_alloc.h"

#include "fs_type.h"
//#include "fat_fs.h"

#include "xmlgen_common.h"
//#include "Xmlgen_def.h"

#include "fs_errcode.h"
#include "fs_func.h"

#include "kal_general_types.h"
#include "kal_public_api.h"

#define COM_BUF_SIZE    512



/*****************************************************************************
 * FUNCTION
 *  xml_generate_write_filetobuf
 * DESCRIPTION
 *  this function is used to write data from file to buffer
 * PARAMETERS
 *  dest        [IN]    dest buffer
 *  src         [IN]    src file handle  
 *  len         [IN]    actual length to be written
 * RETURNS
 *      <0 : means failed, returns error code;
 *      >0 :  means succeed
 *****************************************************************************/

kal_int32 xml_generate_write_filetobuf (char * dest, FS_HANDLE src, kal_uint32 *len)
{
    char *load = NULL, *p;
    kal_uint32 length;
    kal_int32 ret;
    

    load = get_ctrl_buffer(COM_BUF_SIZE);
    if (load == NULL)
    {
        return XG_E_NO_MEMORY;
    }
    p = dest;
    *len = 0;
    while ((ret = FS_Read(src, load, COM_BUF_SIZE-1, &length)) >= FS_NO_ERROR)
    {
        if (length == 0)
        {
            break;
        }
        memcpy(p, load, length);
        p += length;
        *len += length;
    }
    free_ctrl_buffer(load);
    if (ret < FS_NO_ERROR)
    {
        return XG_E_FAIL; 
    }
    else
    {
        return 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  xml_generate_write_filetofile
 * DESCRIPTION
 *  this function is used to write data from file to file
 * PARAMETERS
 *  dest        [IN]    dest file handle which data will be copy to
 *  src         [IN]    src file handle 
 *  len         [IN]    actual length to be written
 * RETURNS
 *      <0 : means failed, returns error code;
 *      >0 :  means succeed
 *****************************************************************************/

kal_int32 xml_generate_write_filetofile(FS_HANDLE dest, FS_HANDLE src, kal_uint32 *len)
{
    char *load = NULL;
    kal_uint32 len_read, len_write;
    kal_int32 ret;
    

    load = get_ctrl_buffer(COM_BUF_SIZE);
    if (load == NULL)
    {
        return XG_E_NO_MEMORY;
    }

    *len = 0;
    while ((ret = FS_Read(src, load, COM_BUF_SIZE-1, &len_read)) >= FS_NO_ERROR)
    {
        if (len_read == 0)
        {
            break;
        }
        ret = FS_Write(dest, load, len_read, &len_write);
        if (ret < FS_NO_ERROR)
        {
            free_ctrl_buffer(load);            
            return XG_E_FAIL;
        }
        *len += len_write;
    }
    free_ctrl_buffer(load);
    if (ret < FS_NO_ERROR)
    {
        return XG_E_FAIL; 
    }
    else
    {
        return 0;
    }
}


#endif     /* (defined(__XML_SUPPORT__) || defined(__WBXML_SUPPORT__)) */
