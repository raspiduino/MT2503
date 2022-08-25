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
 *   avk_framework_log.cpp
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 *Jia Luo (mtk80935)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__ 
extern "C"
{
#include "MMIDataType.h"
#include "fs_gprot.h"
#include "Unicodexdcl.h"
}
#include "avk_framework_core.h"
#include "avk_framework_log.h"

#define AVK_FRAMEWORK_MAX_BUFF_LENGTH         256
#define AVK_FRAMEWORK_FUN_LIST_BUFF_LENGTH    300*1024
#define AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH    2*1024
#define AVK_FRAMEWORK_LOG_END_LENGTH          1024

#define AVK_FRAMEWORK_LOG_NUM_TYPE_PASS       0
#define AVK_FRAMEWORK_LOG_NUM_TYPE_FAIL       1
#define AVK_FRAMEWORK_LOG_NUM_TYPE_TOTAL      2

typedef struct
{
    FS_HANDLE   log_file;
    FS_HANDLE   list_file;
    FS_HANDLE   tmp_file;
    WCHAR       file_path[10];
    CHAR*       list_buff;
    CHAR*       read_buff;
    U32         deep;
    U32         pass_case_num;
    U32         fail_case_num;
    U32         total_case_num;
    MMI_BOOL    bRegression;
    CHAR*       done_flag;
    U32         pass_case_offset;
    U32         fail_case_offset;
    U32         total_case_offset;
    CHAR        parser_buff[100];
}avk_framework_log_ctx;

WCHAR avk_framework_testfile_path[20]={0};
static avk_framework_log_ctx* g_avk_framework_log_ctx;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
static void avk_framework_log_abort_case(avk_test_case* test_case, CHAR* buff)
{
    CHAR tmp[AVK_FRAMEWORK_MAX_BUFF_LENGTH] = {0};
    UINT deep = g_avk_framework_log_ctx->deep;

    if (!test_case)
    {
        return;
    }
    
    for(;deep > 0;deep--)
    {
        strcat(tmp,(const CHAR *)";");
    }

    strcat(tmp, (const CHAR *)test_case->test_name);
    strcat(tmp, (const CHAR *)";abort;\n");
    strcat(buff, tmp);
}

static void avk_framework_log_update_num(U32 num, U32 type)
{
    CHAR tmp[10] = {0};
    U32 offset = 0;
    UINT length = 0;
    
    switch (type)
    {
    case AVK_FRAMEWORK_LOG_NUM_TYPE_PASS:
        offset = g_avk_framework_log_ctx->pass_case_offset;
        break;
    case AVK_FRAMEWORK_LOG_NUM_TYPE_FAIL:
        offset = g_avk_framework_log_ctx->fail_case_offset;
        break;
    case AVK_FRAMEWORK_LOG_NUM_TYPE_TOTAL:
        offset = g_avk_framework_log_ctx->total_case_offset;
        break;        
    default:
        ASSERT(0);
        break;
    }

    sprintf(tmp,"%05d",num);
    FS_Seek(g_avk_framework_log_ctx->log_file,offset,FS_FILE_BEGIN);    
    FS_Write(g_avk_framework_log_ctx->log_file,tmp,strlen(tmp),&length);
    FS_Seek(g_avk_framework_log_ctx->log_file,0,FS_FILE_END);   
}

static void avk_framework_log_get_num(U32* num, U32 type)
{
    CHAR tmp[10] = {0};
    U32 offset = 0;
    UINT length = 0;
    
    switch (type)
    {
    case AVK_FRAMEWORK_LOG_NUM_TYPE_PASS:
        offset = g_avk_framework_log_ctx->pass_case_offset;
        break;
    case AVK_FRAMEWORK_LOG_NUM_TYPE_FAIL:
        offset = g_avk_framework_log_ctx->fail_case_offset;
        break;
    case AVK_FRAMEWORK_LOG_NUM_TYPE_TOTAL:
        offset = g_avk_framework_log_ctx->total_case_offset;
        break;        
    default:
        ASSERT(0);
        break;
    }

    FS_Seek(g_avk_framework_log_ctx->log_file,offset,FS_FILE_BEGIN);    
    FS_Read(g_avk_framework_log_ctx->log_file,tmp,5,&length);
    sscanf(tmp,"%d",num);
    FS_Seek(g_avk_framework_log_ctx->log_file,0,FS_FILE_END); 
}

void avk_framework_log_init()
{
    int driver;
    WCHAR tmp[AVK_FRAMEWORK_MAX_BUFF_LENGTH] = {0};

    g_avk_framework_log_ctx = (avk_framework_log_ctx*)avk_framework_malloc(sizeof(avk_framework_log_ctx));
    if (!g_avk_framework_log_ctx)
    {
        ASSERT(0);
    }
    memset(g_avk_framework_log_ctx,0,sizeof(avk_framework_log_ctx));

    driver = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    if (!driver)
    {
	    driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
	}
	kal_wsprintf(tmp,"%c:\\AVK",driver);
	if (FS_Open(tmp,FS_OPEN_DIR)<=0)
	{
	    FS_CreateDir(tmp);
	}
	kal_wstrcpy(g_avk_framework_log_ctx->file_path,tmp);
	kal_wstrcat(g_avk_framework_log_ctx->file_path,(const WCHAR *)L"\\");

//    driver = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    kal_wstrcpy(avk_framework_testfile_path,g_avk_framework_log_ctx->file_path);
    kal_wstrcat(avk_framework_testfile_path,(const WCHAR *)L"test file\\");
    avk_framework_testfile_path[0] = (WCHAR)driver;
    
	g_avk_framework_log_ctx->deep = avk_framework_get_item_deep();
	g_avk_framework_log_ctx->done_flag ="#done#!\n";
	g_avk_framework_log_ctx->pass_case_offset = strlen("pass cases:;");
	g_avk_framework_log_ctx->fail_case_offset = g_avk_framework_log_ctx->pass_case_offset + strlen("fail cases:;") + 6;
	g_avk_framework_log_ctx->total_case_offset = g_avk_framework_log_ctx->fail_case_offset + strlen("total cases:;") + 6;
}

void avk_framework_log_item_begin(avk_test_case* item)
{
    CHAR tmp[AVK_FRAMEWORK_MAX_BUFF_LENGTH] = {0};
    CHAR tmp2[AVK_FRAMEWORK_MAX_BUFF_LENGTH] = {0};
    UINT length = 0;
    U32  deep = g_avk_framework_log_ctx->deep;
        
    kal_wstrcpy((WCHAR*)tmp,g_avk_framework_log_ctx->file_path);
    if (item != g_avk_framework_ctx.root)
    {        
        kal_wstrcat((WCHAR*)tmp,item->parent->test_name);
        kal_wstrcat((WCHAR*)tmp,(const WCHAR *)L"_");
    }
    kal_wstrcat((WCHAR*)tmp,item->test_name);
    
    kal_wstrcat((WCHAR*)tmp,(const WCHAR *)L".txt");

    kal_wstrcpy((WCHAR*)tmp2,(const WCHAR *)tmp);
    kal_wstrcat((WCHAR*)tmp2,(const WCHAR *)L".bak");
    FS_Delete((WCHAR*)tmp2);
    FS_Rename((WCHAR*)tmp,(WCHAR*)tmp2);
    
    g_avk_framework_log_ctx->log_file= FS_Open((WCHAR*)tmp,FS_CREATE_ALWAYS|FS_READ_WRITE|FS_OPEN_NO_DIR|FS_OPEN_SHARED);

    strcpy(tmp,"pass cases:;00000;fail cases:;00000;total cases:;00000;\n");    
    
    for(;deep > 0;deep--)
    {
        strcat(tmp,(const CHAR *)"item;");
    }
    strcat(tmp,(const CHAR *)"case;");
    strcat(tmp,(const CHAR *)"result;");
    strcat(tmp,(const CHAR *)"function;");
    strcat(tmp,(const CHAR *)"result;\n");
    
    FS_Write(g_avk_framework_log_ctx->log_file,tmp,strlen(tmp),&length);
    //Update total case number
    if (g_avk_framework_log_ctx->bRegression)
    {
        g_avk_framework_log_ctx->bRegression = MMI_FALSE;
        avk_framework_log_update_num(g_avk_framework_log_ctx->pass_case_num, AVK_FRAMEWORK_LOG_NUM_TYPE_PASS);
        avk_framework_log_update_num(g_avk_framework_log_ctx->fail_case_num, AVK_FRAMEWORK_LOG_NUM_TYPE_FAIL);
        avk_framework_log_update_num(g_avk_framework_log_ctx->total_case_num, AVK_FRAMEWORK_LOG_NUM_TYPE_TOTAL);
    }
    else
    {
        g_avk_framework_log_ctx->pass_case_num = 0;
        g_avk_framework_log_ctx->fail_case_num = 0;
        avk_framework_log_update_num(g_avk_framework_ctx.all_case_num, AVK_FRAMEWORK_LOG_NUM_TYPE_TOTAL);
    }
    
    //write abort cases
    if (g_avk_framework_log_ctx->read_buff)
    {
        CHAR* tmp_ptr = g_avk_framework_log_ctx->read_buff;
        UINT tmp_strlen = strlen(g_avk_framework_log_ctx->read_buff);
        UINT headlen = strlen(tmp);
        
        if ( tmp_strlen > headlen)
        {
            //remove head
            tmp_ptr += headlen;
            tmp_strlen -= headlen;
        }
        FS_Write(g_avk_framework_log_ctx->log_file,tmp_ptr,tmp_strlen,&length);
    }
    FS_Commit(g_avk_framework_log_ctx->log_file);
    //function list
/*    kal_wstrcpy((WCHAR*)tmp,g_avk_framework_log_ctx->file_path);
    kal_wstrcat((WCHAR*)tmp,item->test_name);

    if (item != g_avk_framework_ctx.root)
    {        
        kal_wstrcat((WCHAR*)tmp,item->parent->test_name);
        kal_wstrcat((WCHAR*)tmp,(const WCHAR *)L"_");
    }
    kal_wstrcat((WCHAR*)tmp,(const WCHAR *)L"_list.txt");
    
    g_avk_framework_log_ctx->list_file= FS_Open((WCHAR*)tmp,FS_CREATE_ALWAYS|FS_READ_WRITE|FS_OPEN_NO_DIR);
    
    memset(tmp,0,sizeof(tmp));
    strcpy(tmp, (const CHAR *)"MAUI SDK functions list :\n");
    FS_Write(g_avk_framework_log_ctx->list_file,tmp,strlen(tmp),&length);
    FS_Commit(g_avk_framework_log_ctx->list_file);*/
    
}

void avk_framework_log_item_end(void)
{
    CHAR tmp[AVK_FRAMEWORK_MAX_BUFF_LENGTH] = {0};
    UINT length = 0;
    
    strcat(tmp, g_avk_framework_log_ctx->done_flag);
    FS_Write(g_avk_framework_log_ctx->log_file,tmp,strlen(tmp),&length);
    FS_Commit(g_avk_framework_log_ctx->log_file);
    FS_Close(g_avk_framework_log_ctx->log_file);

    //function list
//    FS_Close(g_avk_framework_log_ctx->list_file);
}

void avk_framework_log_case_begin(WCHAR* case_name)
{
    CHAR tmp[AVK_FRAMEWORK_MAX_BUFF_LENGTH] = {0};
    UINT length = 0, deep = g_avk_framework_log_ctx->deep;

    for(;deep > 0;deep--)
    {
        strcat(tmp,(const CHAR *)";");
    }

    strcat(tmp, (const CHAR *)case_name);
    strcat(tmp, (const CHAR *)"@;\n");
    FS_Write(g_avk_framework_log_ctx->log_file,tmp,strlen(tmp),&length);
    FS_Commit(g_avk_framework_log_ctx->log_file);
}

void avk_framework_log_case_end(WCHAR* case_name, U8 result)
{
    CHAR tmp[AVK_FRAMEWORK_MAX_BUFF_LENGTH] = {0};
    UINT length = 0,deep = g_avk_framework_log_ctx->deep;

    memset(tmp,0,AVK_FRAMEWORK_MAX_BUFF_LENGTH);
    for(;deep > 0;deep--)
    {
        strcat(tmp,(const CHAR *)";");
    }
    strcat(tmp,(const CHAR *)case_name);
    if (AVK_PASS == result)
    {
        g_avk_framework_log_ctx->pass_case_num++;
        avk_framework_log_update_num(g_avk_framework_log_ctx->pass_case_num,AVK_FRAMEWORK_LOG_NUM_TYPE_PASS);
        strcat(tmp, (const CHAR *)"#;pass;\n");
    }
    else if (AVK_FAIL == result)
    {
        g_avk_framework_log_ctx->fail_case_num++;
        avk_framework_log_update_num(g_avk_framework_log_ctx->fail_case_num,AVK_FRAMEWORK_LOG_NUM_TYPE_FAIL);
        strcat(tmp, (const CHAR *)"#;fail;\n");
    }    
    else
    {
        g_avk_framework_log_ctx->fail_case_num++;
        avk_framework_log_update_num(g_avk_framework_log_ctx->fail_case_num,AVK_FRAMEWORK_LOG_NUM_TYPE_FAIL);
        strcat(tmp, (const CHAR *)"#;fail;\n");
    }
    
    FS_Write(g_avk_framework_log_ctx->log_file,tmp,strlen(tmp),&length);
    FS_Commit(g_avk_framework_log_ctx->log_file);
}

void avk_framework_log_item_path(avk_test_case* test_case)
{
    WCHAR tmp[AVK_FRAMEWORK_MAX_BUFF_LENGTH] = {0};
    CHAR tmp2[AVK_FRAMEWORK_MAX_BUFF_LENGTH] = {0};
    UINT length = 0,i = 0;
    avk_test_case* tmp_cases[AVK_FRAMEWORK_MAX_ITEM_DEEP];

    tmp_cases[i] = test_case;
    while (tmp_cases[i]->parent && tmp_cases[i]->parent != g_avk_framework_ctx.root)
    {
        tmp_cases[i+1] = tmp_cases[i]->parent;
        i++;
    }
    while(i!=0)
    {
        kal_wstrcat(tmp,tmp_cases[i]->test_name);
        kal_wstrcat(tmp,(const WCHAR *)L";"); 
        i--;
    }
    kal_wstrcat(tmp,tmp_cases[i]->test_name);
    kal_wstrcat(tmp,(const WCHAR *)L"\n");
    mmi_ucs2_to_asc(tmp2,(CHAR *)tmp);
    FS_Write(g_avk_framework_log_ctx->log_file,tmp2,strlen(tmp2),&length);
    FS_Commit(g_avk_framework_log_ctx->log_file);
    
    //function list
/*    if(!g_avk_framework_log_ctx->list_buff)
    {
        g_avk_framework_log_ctx->list_buff = (CHAR*)avk_framework_malloc(AVK_FRAMEWORK_FUN_LIST_BUFF_LENGTH);
    }        
    if(!g_avk_framework_log_ctx->list_buff)
    {
        strcpy(tmp2,"no memory!");
        FS_Write(g_avk_framework_log_ctx->list_file,tmp2,strlen(tmp2),&length);
        FS_Commit(g_avk_framework_log_ctx->list_file);
        return;
    }
    memset(g_avk_framework_log_ctx->list_buff,0,AVK_FRAMEWORK_FUN_LIST_BUFF_LENGTH);*/
}

CHAR* avk_framework_log_parser(CHAR* str)
{
    U32 length = strlen(str);
    U32 i =0 ,j=0;
    S32 flag = 0;
    CHAR c;

    memset(g_avk_framework_log_ctx->parser_buff,0,sizeof(g_avk_framework_log_ctx->parser_buff));
    for (i = 0; i < length; i++)
    {
        c = *(str+i);
        if ((c >= 'a'&& c <= 'z') || (c >= 'A'&& c <= 'Z') || 
                (c >= '0'&& c <= ':') || c == '_')
        {
            g_avk_framework_log_ctx->parser_buff[j++] = c;
            flag = 1;
        }
        else if (' ' == c)
        {
            if (1 == flag)
            {
                flag = 2;
            }
            j = 0;
        }
        else if ('(' == c)
        {
            if (flag >= 1)
            {
                return g_avk_framework_log_ctx->parser_buff;
            }
            j = 0;
        }
        else
        {
            memset(g_avk_framework_log_ctx->parser_buff,0,sizeof(g_avk_framework_log_ctx->parser_buff));
            flag = -1;
            j = 0;
        }
    }

    return NULL;
}

U8 avk_framework_log_fun(CHAR* fun_name, U8 result)
{
    CHAR tmp[AVK_FRAMEWORK_MAX_BUFF_LENGTH] = {0};
    UINT length = 0, deep = g_avk_framework_log_ctx->deep;

    if (!fun_name)
    {
        return AVK_FAIL;
    }
    
    for(;deep > 0;deep--)
    {
        strcat(tmp,(const CHAR *)";");
    }
    strcat(tmp,(const CHAR *)";;");//case
    strcat(tmp,(const CHAR *)fun_name);
    strcat(tmp,(const CHAR *)";");
    if (AVK_PASS == result)
    {
        strcat(tmp,"pass;\n");
    }
    else if (AVK_FAIL == result || AVK_NA == result)
    {
        strcat(tmp,"fail;\n");
    }
    else if (AVK_UNSUPPORT == result)
    {
        strcat(tmp,"unsupport;\n");
    }

    g_avk_framework_ctx.b_current_result &= result;
        
    FS_Write(g_avk_framework_log_ctx->log_file,tmp,strlen(tmp),&length);
    FS_Commit(g_avk_framework_log_ctx->log_file);
    
    //function list
/*    if(!g_avk_framework_log_ctx->list_buff)
    {
        return result;
    }
    strcpy(tmp,fun_name);
    strcat(tmp,"\n");
    if (!strstr(g_avk_framework_log_ctx->list_buff, tmp))
    {
        strcat(g_avk_framework_log_ctx->list_buff,tmp);
        FS_Write(g_avk_framework_log_ctx->list_file,tmp,strlen(tmp),&length);
    }
    FS_Commit(g_avk_framework_log_ctx->list_file);*/
    return result;
}

S32 avk_framework_log_init_regression(avk_test_case* item , U32 type)
{
    WCHAR tmp[AVK_FRAMEWORK_MAX_BUFF_LENGTH] = {0};   
    UINT length = 0;
    UINT file_size = 0;
    CHAR* pos = NULL, *tmp_pos = NULL;
//    U32  deep = g_avk_framework_log_ctx->deep;
    U32  first_flag = 1;
    avk_test_case* tmp_case;
        
    kal_wstrcpy((WCHAR*)tmp,g_avk_framework_log_ctx->file_path);
    if (item != g_avk_framework_ctx.root)
    {        
        kal_wstrcat((WCHAR*)tmp,item->parent->test_name);
        kal_wstrcat((WCHAR*)tmp,(const WCHAR *)L"_");
    }
    kal_wstrcat((WCHAR*)tmp,item->test_name);
    
    kal_wstrcat((WCHAR*)tmp,(const WCHAR *)L".txt");
    
    if (AVK_FRAMEWORK_ABORT_REGRESSION == type)
    {
        WCHAR tmp2[AVK_FRAMEWORK_MAX_BUFF_LENGTH] = {0};
        
        kal_wstrcpy((WCHAR*)tmp2,(const WCHAR *)tmp);
        kal_wstrcat((WCHAR*)tmp2,(const WCHAR *)L".abort");
        FS_Rename((WCHAR*)tmp,(WCHAR*)tmp2);
        kal_wstrcpy((WCHAR*)tmp,(const WCHAR *)tmp2);
    }

    FS_Close(g_avk_framework_log_ctx->log_file);
    g_avk_framework_log_ctx->log_file= FS_Open((WCHAR*)tmp,FS_READ_WRITE|FS_OPEN_NO_DIR|FS_OPEN_SHARED);
    if (g_avk_framework_log_ctx->log_file <= 0)
    {
        return -1;
    }

    g_avk_framework_log_ctx->bRegression = MMI_TRUE;
    avk_framework_log_get_num(&g_avk_framework_log_ctx->pass_case_num,AVK_FRAMEWORK_LOG_NUM_TYPE_PASS);
    avk_framework_log_get_num(&g_avk_framework_log_ctx->fail_case_num,AVK_FRAMEWORK_LOG_NUM_TYPE_FAIL);
    avk_framework_log_get_num(&g_avk_framework_log_ctx->total_case_num,AVK_FRAMEWORK_LOG_NUM_TYPE_TOTAL);
    
    //use list buff to read file
    if(!g_avk_framework_log_ctx->read_buff)
    {
        g_avk_framework_log_ctx->read_buff = (CHAR*)avk_framework_malloc(AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH+1);
        memset(g_avk_framework_log_ctx->read_buff,0,AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH+1);
    }        
    if(!g_avk_framework_log_ctx->read_buff)
    {
        FS_Close(g_avk_framework_log_ctx->log_file);
        return -1;
    }   

    FS_Seek(g_avk_framework_log_ctx->log_file,0,FS_FILE_BEGIN);
    do
    {        
        length = 0;
        FS_Read(g_avk_framework_log_ctx->log_file,g_avk_framework_log_ctx->read_buff,AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH,&length);
        if(0 == length)
        {
            break;
        }

        pos = g_avk_framework_log_ctx->read_buff;
        if (first_flag && AVK_FRAMEWORK_ABORT_REGRESSION == type)
        {
            CHAR case_name_buff[AVK_FRAMEWORK_MAX_CASE_NAME_LENGTH];
            while(1)
            {  
begin1:            
                pos = strstr(pos,";abort;");
                if (!pos)
                {
                    break;
                }
                tmp_pos = pos-1;
                while(*tmp_pos != ';')
                {
                    if (tmp_pos == g_avk_framework_log_ctx->read_buff)
                    {
                        pos++;
                        goto begin1;
                    }
                    tmp_pos--;
                }
                tmp_pos++;
                memset(case_name_buff,0,AVK_FRAMEWORK_MAX_CASE_NAME_LENGTH);
                memcpy(case_name_buff,tmp_pos,pos-tmp_pos);
                pos++;
                tmp_case = avk_framework_find_case_by_name(case_name_buff);
                g_avk_framework_log_ctx->pass_case_num -= avk_framework_mark_case(tmp_case,item,AVK_CASE_FAIL);
//                g_avk_framework_log_ctx->fail_case_num--;
            }
            first_flag = 0;
        }
        
        pos = g_avk_framework_log_ctx->read_buff;
        while(1)
        { 
begin2:        
            pos = strstr(pos,"#;fail");
            if (!pos)
            {
                break;
            }
            tmp_pos = pos-1;
            while(*tmp_pos != ';')
            {
                if (tmp_pos == g_avk_framework_log_ctx->read_buff || *tmp_pos == 0)
                {
                    pos++;
                    goto begin2;
                }
                tmp_pos--;
            }
            *pos = 0;
            pos++;
            tmp_pos++;
            tmp_case = avk_framework_find_case_by_name(tmp_pos);
            g_avk_framework_log_ctx->pass_case_num -= avk_framework_mark_case(tmp_case,item,AVK_CASE_FAIL);
            g_avk_framework_log_ctx->fail_case_num--;
        }
        FS_Seek(g_avk_framework_log_ctx->log_file,-(AVK_FRAMEWORK_MAX_CASE_NAME_LENGTH+10),FS_FILE_CURRENT);
    }
    while (AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH == length);

    tmp_case = NULL;
    
    FS_GetFileSize(g_avk_framework_log_ctx->log_file,&file_size);
    FS_Seek(g_avk_framework_log_ctx->log_file,0,FS_FILE_END);
    
reget:  
    memset(g_avk_framework_log_ctx->read_buff,0,AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH+1);
    if (0 == file_size)
    {
        goto return_pos;
    }
    else if (file_size > AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH)
    {
        FS_Seek(g_avk_framework_log_ctx->log_file,-AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH,FS_FILE_CURRENT);
        FS_Read(g_avk_framework_log_ctx->log_file,g_avk_framework_log_ctx->read_buff,AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH,&length);
        FS_Seek(g_avk_framework_log_ctx->log_file,-AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH,FS_FILE_CURRENT);
        file_size -= AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH;
    }
    else
    {
        FS_Seek(g_avk_framework_log_ctx->log_file,0,FS_FILE_BEGIN);
        FS_Read(g_avk_framework_log_ctx->log_file,g_avk_framework_log_ctx->read_buff,file_size,&length);
        file_size = 0;
    }
    
    pos = strstr(g_avk_framework_log_ctx->read_buff,g_avk_framework_log_ctx->done_flag);
    if (!pos)
    {
        //some place abort!! find it!!
        pos = g_avk_framework_log_ctx->read_buff + length - 1;
        while(*pos != '@'||*(pos+1) != ';')
        {
            if (pos == g_avk_framework_log_ctx->read_buff)
            {
                goto reget;
            }
            pos--;            
        }
        tmp_pos = (CHAR*)(pos-1);
        while(*tmp_pos != ';')
        {
            if (tmp_pos == g_avk_framework_log_ctx->read_buff)
            {
                goto return_pos;
            }
            tmp_pos--;
        }
        *pos = 0;
        tmp_pos++;
        tmp_case = avk_framework_find_case_by_name(tmp_pos);
        if (AVK_FRAMEWORK_ABORT_REGRESSION == type)
        {
            avk_framework_mark_case(tmp_case,item,AVK_CASE_FAIL);
        }
        else
        {
            avk_framework_mark_case(tmp_case,item,AVK_CASE_ABORT);
        }
        g_avk_framework_log_ctx->fail_case_num++;
    }
      
    FS_Seek(g_avk_framework_log_ctx->log_file,0,FS_FILE_BEGIN);
    if(FS_NO_ERROR == FS_Read(g_avk_framework_log_ctx->log_file,g_avk_framework_log_ctx->read_buff,AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH,&length))
    {
        //we suppose abort cases region will not exceed buff length
        pos = g_avk_framework_log_ctx->read_buff + length - 1;
        while(*pos != ';'|| *(pos+1) != 'a' || *(pos+2) != 'b'
                || *(pos+3) != 'o' || *(pos+4) != 'r' || *(pos+5) != 't' || *(pos+6) != ';')
        {
            if (pos == g_avk_framework_log_ctx->read_buff)
            { 
                memset(g_avk_framework_log_ctx->read_buff,0,AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH);
                break;
            }
            pos--;
        }
        *(pos+8) = 0;  
        avk_framework_log_abort_case(tmp_case,g_avk_framework_log_ctx->read_buff); 
        FS_Close(g_avk_framework_log_ctx->log_file);
        return 0;
    }
    
return_pos: 
    memset(g_avk_framework_log_ctx->read_buff,0,AVK_FRAMEWORK_LOG_READ_BUFF_LENGTH);
    FS_Close(g_avk_framework_log_ctx->log_file);
    return 0;
}

MMI_BOOL avk_framework_log_is_log_exist(avk_test_case* item)
{
    WCHAR tmp[AVK_FRAMEWORK_MAX_BUFF_LENGTH/2] = {0};   
    FS_HANDLE file;
    
    kal_wstrcpy((WCHAR*)tmp,g_avk_framework_log_ctx->file_path);
    if (item != g_avk_framework_ctx.root)
    {
        kal_wstrcat((WCHAR*)tmp,item->parent->test_name);
        kal_wstrcat((WCHAR*)tmp,(const WCHAR *)L"_");
    }
    kal_wstrcat((WCHAR*)tmp,item->test_name);
    
    kal_wstrcat((WCHAR*)tmp,(const WCHAR *)L".txt");
    
    file= FS_Open((WCHAR*)tmp,FS_READ_ONLY|FS_OPEN_NO_DIR|FS_OPEN_SHARED);
    if (file <= 0)
    {
        return MMI_FALSE;
    }
    FS_Close(file);
    return MMI_TRUE;
}

#endif
