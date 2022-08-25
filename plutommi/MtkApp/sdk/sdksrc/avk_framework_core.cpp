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
 *   avk_framework_core.cpp
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
#include "mmi_features.h" 
#include "mmi_frm_timer_gprot.h"
#include "GlobalResDef.h"
#include "mmi_frm_mem_gprot.h"
#include "custom_mmi_default_value.h"
#include "app_mem.h"
#include "Kal_release.h"
#include "custdatares.h"
}
#include "avk_framework_core.h"
#include "avk_framework_log.h"

#define AVK_FRAMEWORK_POOL_SIZE (1024*1024 > mmi_res_get_asm_common_pool_size()?mmi_res_get_asm_common_pool_size():1024*1024)

static  void* g_avk_framework_mem_pool = NULL;
static  U32	g_avk_framework_mem_pool_size = 0;
static  KAL_ADM_ID g_avk_framework_adm = 0;
static	U8	g_avk_framework_reg_flag = 0;



/***************************mem  begin***********************************/
static void avk_framework_reg_mem(void);
static void avk_framework_asm_stop_app_callback(void);
static void avk_framework_asm_memory_pool_request_success_callback(void);
static void avk_framework_init_adm(void);

/*****************************************************************************
 * FUNCTION
 *  avk_framework_reg_mem
 * DESCRIPTION
 *  register asm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
void avk_framework_reg_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
	if(g_avk_framework_reg_flag)
		return;
	applib_mem_ap_register( APPLIB_MEM_AP_ID_TEST_SDK, 
							STR_GLOBAL_1, 
							NULL, 
							avk_framework_asm_stop_app_callback);
	g_avk_framework_reg_flag = 1;
}


/*****************************************************************************
 * FUNCTION
 *  avk_framework_init_app_mem
 * DESCRIPTION
 *  initial asm and adm 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
int avk_framework_init_app_mem(void (*callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
	avk_framework_reg_mem();
	if(g_avk_framework_mem_pool)
		return 0;
	g_avk_framework_mem_pool_size = AVK_FRAMEWORK_POOL_SIZE;
	g_avk_framework_mem_pool = applib_mem_ap_alloc_framebuffer( APPLIB_MEM_AP_ID_TEST_SDK, g_avk_framework_mem_pool_size);
	if (!g_avk_framework_mem_pool)
	{
		mmi_frm_appmem_prompt_to_release_mem(
			APPLIB_MEM_AP_ID_TEST_SDK,
			0,
			g_avk_framework_mem_pool_size,
			/* Callback function when getting memory successfully */
			callback);
		return 1;
	}
	avk_framework_init_adm();
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  avk_framework_deinit_app_men
 * DESCRIPTION
 *  deinitial asm and adm 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
void avk_framework_deinit_app_men(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
	if(g_avk_framework_adm)
	{
		kal_adm_delete(g_avk_framework_adm);
		g_avk_framework_adm = 0;
	}
	if(g_avk_framework_mem_pool)
	{
		applib_mem_ap_free(g_avk_framework_mem_pool);
		g_avk_framework_mem_pool = NULL;
	}
}


/*****************************************************************************
 * FUNCTION
 *  avk_framework_asm_memory_pool_request_success_callback
 * DESCRIPTION
 *  avk_framework_asm_memory_pool_request_success_callback 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
void avk_framework_asm_memory_pool_request_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
	g_avk_framework_mem_pool_size = AVK_FRAMEWORK_POOL_SIZE;
	g_avk_framework_mem_pool = applib_mem_ap_alloc_framebuffer( APPLIB_MEM_AP_ID_TEST_SDK, AVK_FRAMEWORK_POOL_SIZE);
	avk_framework_init_adm();
}


/*****************************************************************************
 * FUNCTION
 *  avk_framework_init_adm
 * DESCRIPTION
 *  initial adm 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
void avk_framework_init_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
	g_avk_framework_adm =  kal_adm_create(g_avk_framework_mem_pool, g_avk_framework_mem_pool_size, NULL, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  avk_framework_asm_stop_app_callback
 * DESCRIPTION
 *  callback function to release my asm memory 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
void avk_framework_asm_stop_app_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
	avk_framework_deinit_app_men();
    /* Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST_SDK, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  avk_framework_malloc
 * DESCRIPTION
 *  malloc 
 * PARAMETERS
 *  size                :[IN]       memory size
 * RETURNS
 *  pointer point to memory
*****************************************************************************/
void* avk_framework_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
	return kal_adm_alloc(g_avk_framework_adm,size);
}


/*****************************************************************************
 * FUNCTION
 *  avk_framework_free
 * DESCRIPTION
 *  memory free
 * PARAMETERS
 *  p          :[IN]       point to memory need to free
 * RETURNS
 *  void
*****************************************************************************/
void avk_framework_free(void* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
	kal_adm_free(g_avk_framework_adm,p);
}

/***************************mem  end***********************************/



static U32 g_avk_framework_count = 0;
static avk_framework_buffer g_avk_framework_buffer = {{AVK_ITEM,0,0,0,0,0},0};

avk_framework_ctx g_avk_framework_ctx = {0,0,0,0,0};


static U32 avk_framework_invoke_item(void);
static void avk_framework_invoke_cases_ext();
static avk_test_case* avk_framework_get_next_case(avk_test_case* current, avk_test_case* base, avk_case_type_enum filter);
static avk_test_case* avk_framework_get_next_case_no_child(avk_test_case* current, avk_test_case* base, avk_case_type_enum filter);
static void avk_framework_get_case_num(avk_test_case* item, U32* auto_num, U32* all_num);
static void avk_framework_insert_case_list(avk_test_case* test_case, U32 test_parent);
static void avk_framework_cases_done(void);
static void avk_framework_case_time_cb(void* para);
static void avk_framework_item_time_cb(void* para);
static void avk_framework_item_done_time_cb(void* para);
static void avk_framework_current_item_done(void);
static void avk_framework_clear_fun_list(void);


int avk_framework_core_init(void (*callback)(void))
{
    return avk_framework_init_app_mem(callback);
}

void avk_framework_core_deinit(void)
{
    avk_framework_clear_fun_list();
    avk_framework_deinit_app_men();
}

static avk_test_case* avk_framework_get_buffer()
{
    if (g_avk_framework_buffer.buffer_ptr > AVK_FRAMEWORK_TOTAL_CASE_BUFF)
    {
        return NULL;
    }
    return &g_avk_framework_buffer.buffer[g_avk_framework_buffer.buffer_ptr++];
}

void avk_framework_reset_ctx()
{
    memset(&g_avk_framework_ctx.test_item,0,sizeof(g_avk_framework_ctx)-(int)(&(((avk_framework_ctx*)(NULL))->test_item)));
    g_avk_framework_ctx.b_current_result = AVK_NA;
}

U32 avk_framework_insert_fun(CHAR* fun_name)
{
    avk_fun_list* fun_list, *tmp_list;
    CHAR*         name_buf;   

    if (!fun_name)
    {
        ASSERT(0);
    }
    
    fun_list = (avk_fun_list*)avk_framework_malloc(sizeof(avk_fun_list));
    if(!fun_list)
    {
        ASSERT(0);
    }
    name_buf = (CHAR*)avk_framework_malloc(strlen(fun_name)+1);
    if(!name_buf)
    {
        ASSERT(0);
    }
    strcpy(name_buf,fun_name);
    fun_list->fun_name = name_buf;
    fun_list->next = NULL;

    if (!g_avk_framework_ctx.fun_list)
    {
        g_avk_framework_ctx.fun_list = fun_list;
        return 1;
    }
    tmp_list = g_avk_framework_ctx.fun_list;
    while(tmp_list->next != NULL)
    {
        tmp_list = tmp_list->next;
    }
    tmp_list->next = fun_list;
    return 1;
}

static U32 avk_framework_get_fun(CHAR fun_name[])
{
    avk_fun_list* tmp_list;

    if (!fun_name)
    {
        return -1;
    }
    
    tmp_list = g_avk_framework_ctx.fun_list;
    if (tmp_list)
    {
        strcpy(fun_name,tmp_list->fun_name);
        g_avk_framework_ctx.fun_list = tmp_list->next;
        avk_framework_free(tmp_list->fun_name);
        avk_framework_free(tmp_list);
        return 0;
    } 
    return -1;
}

static void avk_framework_clear_fun_list(void)
{
    avk_fun_list* tmp_list;    
    
    while (g_avk_framework_ctx.fun_list)
    {
        tmp_list = g_avk_framework_ctx.fun_list;
        g_avk_framework_ctx.fun_list = tmp_list->next;
        avk_framework_free(tmp_list->fun_name);
        avk_framework_free(tmp_list);
    } 
}

static avk_test_case* avk_framework_get_next_case(avk_test_case* current, avk_test_case* base, avk_case_type_enum filter)
{
    U32 flag = 0;//find child   
    avk_test_case* test_case = current;
    avk_test_case* tmp_case;

    ASSERT(base);
    
    if (NULL == current)
    {
        test_case = base;
    }
    
    while (1)
    {        
        if (flag)
        {
            goto find_brother;
        }
        tmp_case = test_case->first_child;
        if (tmp_case)        
        {
            if (AVK_FRAMEWORK_IS_TYPE(tmp_case, filter))
            {
                return tmp_case;
            }
            test_case = tmp_case;
        }
        else
        {
find_brother:                           
            tmp_case = test_case->next;
            if (tmp_case)
            {
                if (AVK_FRAMEWORK_IS_TYPE(tmp_case, filter))
                {
                    return tmp_case;
                }
                test_case = tmp_case;
                flag = 0;//find child
            }
            else
            {
                test_case = test_case->parent;
                flag = 1;//find brother
                if (test_case == base || test_case == base->parent)
                {
                    //can not find
                    return NULL;
                }
            }
        }
        
    }
}

static avk_test_case* avk_framework_get_next_case_no_child(avk_test_case* current, avk_test_case* base, avk_case_type_enum filter)
{
    U32 flag = 1;//find brother   
    avk_test_case* test_case = current;
    avk_test_case* tmp_case;

    ASSERT(base);
    
    if (NULL == current)
    {
        test_case = base;
    }

    while (1)
    {        
        if (flag)
        {
            goto find_brother;
        }
        tmp_case = test_case->first_child;
        if (tmp_case)        
        {
            if (AVK_FRAMEWORK_IS_TYPE(tmp_case, filter))
            {
                return tmp_case;
            }
            test_case = tmp_case;
        }
        else
        {
find_brother:                           
            tmp_case = test_case->next;
            if (tmp_case)
            {
                if (AVK_FRAMEWORK_IS_TYPE(tmp_case, filter))
                {
                    return tmp_case;
                }
                test_case = tmp_case;
                flag = 0;//find child
            }
            else
            {
                test_case = test_case->parent;
                flag = 1;//find brother
                if (test_case == base || test_case == base->parent)
                {
                    //can not find
                    return NULL;
                }
            }
        }
        
    }
}

static void avk_framework_reset_case_flag(avk_test_case* item)
{
    U32 flag = 0;//find child first   
    avk_test_case* test_case = item;
    avk_test_case* tmp_case;
    
    if (NULL == item)
    {
        return;
    }

    while (1)
    {        
        if (flag)
        {
            goto find_brother;
        }
        tmp_case = test_case->first_child;
        if (tmp_case)        
        {
            AVK_FRAMEWORK_RESET_FLAG(tmp_case);
            test_case = tmp_case;
        }
        else
        {
find_brother:                           
            tmp_case = test_case->next;
            if (tmp_case)
            {
                AVK_FRAMEWORK_RESET_FLAG(tmp_case);
                test_case = tmp_case;
                flag = 0;//find child
            }
            else
            {
                test_case = test_case->parent;
                flag = 1;//find brother
                if (test_case == item || test_case == item->parent)
                {
                    //done
                    return;
                }
            }
        }
        
    }
}

avk_test_case* avk_framework_find_case_by_name(CHAR* case_name)
{
    U32 flag = 0;  
    avk_test_case* test_case = g_avk_framework_ctx.root;
    avk_test_case* tmp_case;
    
    while (1)
    {        
        if (flag)
        {
            goto find_brother;
        }
        tmp_case = test_case->first_child;
        if (tmp_case)        
        {
            if (AVK_FRAMEWORK_IS_CASE(tmp_case))
            {
                if (0 == strcmp(case_name,(const char *)tmp_case->test_name))
                {
                    return tmp_case;
                }                
            }
            test_case = tmp_case;
        }
        else
        {
find_brother:                           
            tmp_case = test_case->next;
            if (tmp_case)
            {
                if (AVK_FRAMEWORK_IS_CASE(tmp_case))
                {
                    if (0 == strcmp(case_name,(const char *)tmp_case->test_name))
                    {
                        return tmp_case;
                    }                
                }
                test_case = tmp_case;
                flag = 0;//find child
            }
            else
            {
                test_case = test_case->parent;
                flag = 1;//find brother
                if (test_case == g_avk_framework_ctx.root)
                {
                    //can not find
                    return NULL;
                }
            }
        }
        
    }
}

static void avk_framework_get_case_num(avk_test_case* item, U32* auto_num, U32* all_num,avk_case_type_enum filter)
{
    U32 flag = 0;//find child   
    avk_test_case* test_case = item;
    avk_test_case* tmp_case;

    ASSERT(auto_num);
    ASSERT(all_num);
    
    *auto_num = 0;
    *all_num = 0;

    if (NULL == item)
    {
        return;
    }

    if (!test_case->first_child)
    {
        return;
    }

    filter = (avk_case_type_enum)(filter&0xff00);
    while (1)
    {        
        if (flag)
        {
            goto find_brother;
        }
        tmp_case = test_case->first_child;
        if (tmp_case)        
        {
            if (AVK_FRAMEWORK_IS_CASE(tmp_case)&&AVK_FRAMEWORK_IS_TYPE(tmp_case, filter))
            {
                if (AVK_FRAMEWORK_IS_AUTO_CASE(tmp_case))
                {
                    (*auto_num)++;
                }
                (*all_num)++;
            }            
            test_case = tmp_case;
        }
        else
        {
find_brother:                           
            tmp_case = test_case->next;
            if (tmp_case)
            {
                if (AVK_FRAMEWORK_IS_CASE(tmp_case)&&AVK_FRAMEWORK_IS_TYPE(tmp_case, filter))
                {
                    if (AVK_FRAMEWORK_IS_AUTO_CASE(tmp_case))
                    {
                        (*auto_num)++;
                    }
                    (*all_num)++;
                }
                test_case = tmp_case;
                flag = 0;//find child
            }
            else
            {
                test_case = test_case->parent;
                flag = 1;//find brother
                if (test_case == item || test_case == item->parent)
                {
                    //can not find
                    return;
                }
            }
        }
        
    }
}

U32 avk_framework_get_item_deep(void)
{
    U32 flag = 0;//find child 
    U32 deep = 1;
    U32 max_deep = 1;
    avk_test_case* test_case;
    avk_test_case* tmp_case;

    test_case = g_avk_framework_ctx.root;
    while (1)
    {        
        if (flag)
        {
            goto find_brother;
        }
        tmp_case = test_case->first_child;
        if (tmp_case)        
        {
            if (AVK_FRAMEWORK_IS_ITEM(tmp_case))
            {
                deep++;
                test_case = tmp_case;
            }  
            else
            {
                if (deep > max_deep)
                {
                    max_deep = deep;
                }
                flag = 1;
            }            
        }
        else
        {
find_brother:                           
            tmp_case = test_case->next;
            if (tmp_case)
            {
                test_case = tmp_case;
                flag = 0;//find child
            }
            else
            {
                test_case = test_case->parent;
                flag = 1;//find brother
                deep--;
                if (test_case == g_avk_framework_ctx.root)
                {
                    //finished
                    return max_deep;
                }
            }
        }
        
    }
}

int avk_framework_mark_case(avk_test_case* test_case,avk_test_case* item, avk_case_type_enum flag)
{
    avk_test_case* tmp_case = test_case;
    avk_case_type_enum test_type;
    int pass_count = 0;
    
    if (!tmp_case)
    {
        return 0;
    }
    
    if (AVK_CASE_ABORT == flag)
    {
        tmp_case = avk_framework_get_next_case_no_child(test_case,item,test_case->test_type);
        if (tmp_case)
        {
            //all after cases mark as fail
            while(tmp_case)
            {
                avk_framework_mark_case(tmp_case,item, AVK_CASE_FAIL);
                tmp_case = avk_framework_get_next_case(tmp_case,item,test_case->test_type);
            }
        }
 
        test_type = (avk_case_type_enum)(((test_case->test_type&0x00fe)<<1 )&0x00ff);
        if(test_type > AVK_CASE_MANUAL || 0 == test_type)
        {
            return 0;
        }
        tmp_case = avk_framework_get_next_case(item,item,test_type);
        while(tmp_case)
        {
            avk_framework_mark_case(tmp_case,item, AVK_CASE_FAIL);
            tmp_case = avk_framework_get_next_case(tmp_case,item,test_type);
        }
        
        return 0;
    }
    else
    {
        AVK_FRAMEWORK_SET_FLAG(tmp_case,AVK_CASE_FAIL);
        while(tmp_case != g_avk_framework_ctx.root)
        {        
            tmp_case = tmp_case->parent;
            if (AVK_FRAMEWORK_IS_CASE(tmp_case)&&!AVK_FRAMEWORK_IS_TYPE(tmp_case,AVK_CASE_FAIL))
            {
                pass_count++;
            }
            AVK_FRAMEWORK_SET_FLAG(tmp_case,AVK_CASE_FAIL);
        }
    }
    return pass_count;
}

static void avk_framework_insert_case_list(avk_test_case* test_case, U32 test_parent)
{
    avk_test_case* tmp_case = NULL;
    avk_test_case* parent_case = NULL;

    if (NULL == test_case)
    {
        return;
    }
    
    parent_case = AVK_GET_CASE_BY_ID(test_parent);
    if (parent_case)
    {
        test_case->parent = parent_case;
        tmp_case = parent_case;
        if (NULL == tmp_case->first_child)
        {
            tmp_case->first_child = test_case;
        }
        else
        {
            tmp_case = tmp_case->first_child;
            while(tmp_case->next != NULL)
            {
                tmp_case = tmp_case->next;
            }
            tmp_case->next = test_case;
        }
        //item type, set parent item
        if (AVK_FRAMEWORK_IS_ITEM(test_case))
        {      
            if (AVK_ITEM_CASE == parent_case->test_type)
            {
                // **************************
                //please follow guild to add case!!
                // **************************
                ASSERT(0);
                return;
            } 
            if (AVK_FRAMEWORK_IS_EMPTY_ITEM(parent_case))
            {
                parent_case->test_type = AVK_ITEM_ITEM;
            }
            
            if (AVK_ITEM_ITEM_SP_ROOT == AVK_FRAMEWORK_CASE_TYPE(parent_case))
            {
                parent_case->test_type = (avk_case_type_enum)(parent_case->test_type+AVK_ITEM_ITEM);
            }
        }
        else //insert case
        {
            if (AVK_ITEM_ITEM == parent_case->test_type)
            {
                // // **************************
                //please follow guild to add case!!
                // **************************
                ASSERT(0);
                return;
            } 
            if (AVK_FRAMEWORK_IS_AUTO_CASE(test_case)&&AVK_FRAMEWORK_IS_ITEM(parent_case))
            {
                parent_case->test_type = AVK_ITEM_CASE;
            }
            else if (AVK_FRAMEWORK_IS_MANUAL_CASE(test_case)&&AVK_FRAMEWORK_IS_ITEM(parent_case))//manual case
            {
                parent_case->test_type = AVK_ITEM_CASE_MANUAL;
            }
            
            
        }
    }
}

static void avk_framework_case_init(void)
{
    g_avk_framework_ctx.current_num++;   
    avk_framework_log_case_begin(g_avk_framework_ctx.current_case->test_name);
}

static void avk_framework_case_deinit(void)
{
    CHAR tmp_buf[AVK_MAX_FUN_NAME_LEN];
    //log result
    if (g_avk_framework_ctx.current_case)
    {
        while(0 == avk_framework_get_fun(tmp_buf))
        {
            avk_framework_log_fun(tmp_buf,g_avk_framework_ctx.b_current_result);
        }
        avk_framework_log_case_end(g_avk_framework_ctx.current_case->test_name,g_avk_framework_ctx.b_current_result);
        avk_framework_clear_fun_list();
    }
}

void avk_framework_invoke_next_case()
{        
    //avoid case error
    if (!g_avk_framework_ctx.current_item)
    {
        return;
    }
    
    avk_framework_case_deinit();
    if (g_avk_framework_ctx.b_current_result)
    {
        g_avk_framework_ctx.current_case = avk_framework_get_next_case(g_avk_framework_ctx.current_case,g_avk_framework_ctx.current_item,g_avk_framework_ctx.current_type);
    }
    else
    {
        g_avk_framework_ctx.current_case = avk_framework_get_next_case_no_child(g_avk_framework_ctx.current_case,g_avk_framework_ctx.current_item,g_avk_framework_ctx.current_type);
    }
    g_avk_framework_ctx.b_current_result = AVK_NA;
    avk_framework_invoke_cases_ext();
}

static void avk_framework_case_time_cb()
{
    StopTimer(AVK_FRAMEWORK_TIME_ID);
    avk_framework_invoke_next_case();
}

static void avk_framework_invoke_cases_ext()
{
    if (!g_avk_framework_ctx.current_case)
    {
        avk_framework_current_item_done();
    }  
    else 
    {
        //init
        avk_framework_case_init();
        
        if (AVK_FRAMEWORK_IS_ASYN_CASE(g_avk_framework_ctx.current_case))
        {
            (*g_avk_framework_ctx.current_case->test_fun)();           
        }
        else if (AVK_FRAMEWORK_IS_AUTO_CASE(g_avk_framework_ctx.current_case))
        {        
            (*g_avk_framework_ctx.current_case->test_fun)();       
            
            //invoke
            avk_framework_asyn_invoke_next_case(0);
        }    
        else if (AVK_FRAMEWORK_IS_MANUAL_CASE(g_avk_framework_ctx.current_case))
        {
            (*g_avk_framework_ctx.current_case->test_fun)();
        }
        else
        {
            ASSERT(0);
        }
    }
    
}

void avk_framework_re_invoke_case()
{
    avk_framework_clear_fun_list();
    if (AVK_FRAMEWORK_IS_ASYN_CASE(g_avk_framework_ctx.current_case))
    {
        (*g_avk_framework_ctx.current_case->test_fun)();           
    }
    else if (AVK_FRAMEWORK_IS_AUTO_CASE(g_avk_framework_ctx.current_case))
    {        
        (*g_avk_framework_ctx.current_case->test_fun)();       
        
        //invoke
        avk_framework_asyn_invoke_next_case(0);
    }    
    else if (AVK_FRAMEWORK_IS_MANUAL_CASE(g_avk_framework_ctx.current_case))
    {
        (*g_avk_framework_ctx.current_case->test_fun)();
    }
    else
    {
        ASSERT(0);
    }
}

void avk_framework_asyn_invoke_next_case(U32 delay)
{
    StartTimer(AVK_FRAMEWORK_TIME_ID,delay,avk_framework_case_time_cb);
}


U32 avk_framework_add_test(avk_case_type_enum test_type, void* test_fun, WCHAR* test_name, U32 test_parent)
{
    U32 test_id = g_avk_framework_count++;
    avk_test_case* test_case = NULL;
    
    test_case = avk_framework_get_buffer();
 
    ASSERT(test_case);
    
    memset(test_case,0,sizeof(avk_test_case));
    test_case->test_type = test_type;
    test_case->test_fun = (p_test_fun)test_fun;
    test_case->test_name = test_name;

    if (0 == test_id)
    {
        //root item
        avk_framework_reset_ctx();
        g_avk_framework_ctx.root = test_case;        
    }
    else if (AVK_FRAMEWORK_IS_TYPE(test_case,AVK_ITEM_ITEM_SP_ROOT))
    {
        g_avk_framework_ctx.root_special = test_case;
        avk_framework_insert_case_list(test_case, test_parent);
        return (U32)test_case;
    }
    else
    {
        avk_framework_insert_case_list(test_case, test_parent);
    }

    if (AVK_FRAMEWORK_IS_ITEM(test_case))
    {
        g_avk_framework_ctx.item = test_case;
    }
    return (U32)test_case;
}
/*
static void avk_framework_item_time_cb(void* para)
{
    avk_framework_invoke_cases_in_current_item();
}

static void avk_framework_current_item_done_time_cb(void* para)
{
    avk_framework_invoke_next_item();
}
*/
U32 avk_framework_invoke_next_item()
{    
    g_avk_framework_ctx.current_item = avk_framework_get_next_case(g_avk_framework_ctx.current_item,
                                    g_avk_framework_ctx.test_item,(avk_case_type_enum)((g_avk_framework_ctx.current_type&0xff00)|((g_avk_framework_ctx.current_type&0x00ff)>>2)));
    return avk_framework_invoke_item();
}

static void avk_framework_current_item_done()
{
    avk_framework_invoke_next_item();
}
    
static U32 avk_framework_invoke_item()
{
    U32 auto_case_num, all_case_num;
    
    if (NULL == g_avk_framework_ctx.current_item)
    {    
        if (AVK_CASE_AUTO == (g_avk_framework_ctx.current_type&0x00ff))
        {
            //auto case done!
            if (g_avk_framework_ctx.auto_case_done_handle)
            {
                (*g_avk_framework_ctx.auto_case_done_handle)();
            }
        }
        else if (((g_avk_framework_ctx.current_type&0x00ff)<<1) > AVK_CASE_MANUAL)
        {
            //all case done!
            avk_framework_log_item_end();
            if (g_avk_framework_ctx.all_case_done_handle)
            {
                (*g_avk_framework_ctx.all_case_done_handle)();
            }
            return g_avk_framework_ctx.current_num;
        }
        g_avk_framework_ctx.current_type = (avk_case_type_enum)((g_avk_framework_ctx.current_type&0xff00)|((g_avk_framework_ctx.current_type<<1)&0x00ff));
        g_avk_framework_ctx.current_item = g_avk_framework_ctx.test_item;
        g_avk_framework_ctx.current_case = NULL;
        return avk_framework_invoke_next_item();
    }
    //
    avk_framework_get_case_num(g_avk_framework_ctx.current_item,&auto_case_num,&all_case_num, g_avk_framework_ctx.current_type);
    if (0 == all_case_num)
    {
        return avk_framework_invoke_next_item();
    }
    //

    //wo log the case path for easy to anasys the output result
    avk_framework_log_item_path(g_avk_framework_ctx.current_item);

    g_avk_framework_ctx.current_case = NULL;
    g_avk_framework_ctx.b_current_result = MMI_TRUE;
    g_avk_framework_ctx.b_running = MMI_TRUE;
    
    avk_framework_invoke_cases_in_current_item();
    return all_case_num;
}

U32 avk_framework_invoke_cases_in_current_item()
{
/*    StopTimer(AVK_FRAMEWORK_TIME_ID);
    if (g_avk_framework_ctx.b_current_result)    
    {
        avk_framework_invoke_next_case();
    }
    else
    {        
        avk_framework_invoke_next_item();
    }*/
    avk_framework_asyn_invoke_next_case(0);
    return g_avk_framework_ctx.current_num;
}

//return totall num of cases
U32 avk_framework_invoke_cases(avk_test_case* test_item)
{
    if (AVK_FRAMEWORK_INVALID_CASE_ID == (U32)test_item || NULL == test_item)
    {
        return 0;
    }
    
    avk_framework_reset_ctx();
    if (AVK_FRAMEWORK_IS_EMPTY_ITEM(test_item))
    {
        return 0;
    }   
    
    avk_framework_get_case_num(test_item,&g_avk_framework_ctx.auto_case_num,&g_avk_framework_ctx.all_case_num,AVK_FRAMEWORK_NULL_FILTER);
    if (0 == g_avk_framework_ctx.all_case_num)
    {
        return 0;
    }
    avk_framework_log_item_begin(test_item);
    
    if (!AVK_FRAMEWORK_IS_UI_ITEM(test_item))
    {
        //item only contain cases
        g_avk_framework_ctx.test_item = test_item;
        g_avk_framework_ctx.current_item = test_item;
        g_avk_framework_ctx.current_type = (avk_case_type_enum)(test_item->test_type << 2);
        return avk_framework_invoke_item();
    }
    else 
    {
        //item contain others items
        g_avk_framework_ctx.test_item = test_item;
        g_avk_framework_ctx.current_item = avk_framework_get_next_case(test_item,test_item,AVK_ITEM_CASE);
        g_avk_framework_ctx.current_type = AVK_CASE_AUTO;
        
        avk_framework_invoke_item();
        return g_avk_framework_ctx.all_case_num;
    }    
}

U32 avk_framework_invoke_cases_regression(avk_test_case* test_item, U32 type)
{
    S32 res = 0;
    if (AVK_FRAMEWORK_INVALID_CASE_ID == (U32)test_item || NULL == test_item)
    {
        return -1;
    }
    
    avk_framework_reset_ctx();
    if (AVK_FRAMEWORK_IS_EMPTY_ITEM(test_item))
    {
        return 0;
    }   

    avk_framework_reset_case_flag(test_item);
    //
    res =avk_framework_log_init_regression(test_item, type);
    if (res)
    {
        return res;
    }
    
    avk_framework_get_case_num(test_item,&g_avk_framework_ctx.auto_case_num,&g_avk_framework_ctx.all_case_num,AVK_CASE_FAIL);
    if (0 == g_avk_framework_ctx.all_case_num)
    {
        return 0;
    }
    avk_framework_log_item_begin(test_item);
    
    if (!AVK_FRAMEWORK_IS_UI_ITEM(test_item))
    {
        //item only contain cases
        g_avk_framework_ctx.test_item = test_item;
        g_avk_framework_ctx.current_item = test_item;
        g_avk_framework_ctx.current_type = (avk_case_type_enum)((test_item->test_type << 2)|AVK_CASE_FAIL);
        return avk_framework_invoke_item();
    }
    else 
    {
        //item contain others items
        g_avk_framework_ctx.test_item = test_item;
        g_avk_framework_ctx.current_item = avk_framework_get_next_case(test_item,test_item,AVK_ITEM_CASE);
        g_avk_framework_ctx.current_type = (avk_case_type_enum)(AVK_CASE_AUTO|AVK_CASE_FAIL);
        
        avk_framework_invoke_item();
        return g_avk_framework_ctx.all_case_num;
    }
}

void avk_framework_case_special_time_cb(void* param)
{
    avk_test_case* test_case = (avk_test_case*)param;
    test_case->test_fun();
}

U32 avk_framework_invoke_cases_special(avk_test_case* test_item)
{
    g_avk_framework_ctx.current_case = avk_framework_get_next_case(NULL,test_item,AVK_CASE_SPECIAL);
    
    if (g_avk_framework_ctx.current_case)
    {
        StartTimerEx(AVK_FRAMEWORK_TIME_ID,0,avk_framework_case_special_time_cb,g_avk_framework_ctx.current_case);
    }
    return 1;
}

#endif
