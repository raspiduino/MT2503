/*****************************************************************************
 *
 * Filename:  	C_RAMBUFFER.c
 *
 *
 * Author :    	MagicNing
 *
 *
 * Date : 	2010-03-16
 *
 *
 * Comment:  C_STL 控件的内存处理
 *
 *
 ****************************************************************************/




/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "c_RamBuffer.h"

#include "track_os_ell.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/


/*****************************************************************************
* Typedef  Enum
*****************************************************************************/



/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/



/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/

static kal_uint8 my_pool[ RAMBUFFER_LENGHT ];
static KAL_ADM_ID my_id;

static kal_mutexid rambuf_pool_mutex;
static kal_int32 MaxAlloc[RAMBUFFER_APP_MAX] = {0};


/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/



/*****************************************************************************
 *  Global Functions	- Extern		引用外部函数
 *****************************************************************************/
extern void track_cust_restart(kal_uint8 mode, kal_uint32 sec);
extern void track_cust_ram_alarm(kal_uint32 freesize, kal_uint32 mem_size);

/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/


/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/




/*---------------------------------------------------------------------------
 * FUNCTION			RamBuffer_Init
 *
 * DESCRIPTION		初始化ADM 数组，为VECTOR 和 STRING 控件准备缓存内存空间
 *
 * PARAMETERS
 *		void
 * RETURNS
 *  		void
 *
 *---------------------------------------------------------------------------*/

BOOL RamBuffer_Init(void)
{
#ifdef __RAMBUFFER_DEBUG__
    kal_prompt_trace(TRACE_INFO, "@@@   RamBuffer_Init()");
#endif

    rambuf_pool_mutex = kal_create_mutex("rambuf_pool_mutex");
    my_id = kal_adm_create(my_pool, RAMBUFFER_LENGHT, NULL, KAL_FALSE);

    if(my_id == NULL)
    {
#ifdef __RAMBUFFER_DEBUG__
        kal_prompt_trace(TRACE_INFO, "kal_adm_create  failed");
#endif
        return FALSE;
    }
    else
    {
#ifdef __RAMBUFFER_DEBUG__
        kal_prompt_trace(TRACE_INFO, "kal_adm_create  OK   --   ADM_ID = %d " , my_id);
#endif
        return TRUE;
    }
}


/*---------------------------------------------------------------------------
 * FUNCTION			RamBuffer_Release
 *
 * DESCRIPTION		清理ADM 数组，释放VECTOR 和 STRING 控件的内存空间，数据会丢失
 *
 * PARAMETERS
 *		void
 * RETURNS
 *  		void
 *                                   基本上用不到
 *---------------------------------------------------------------------------*/

BOOL RamBuffer_Release(void)
{
#ifdef __RAMBUFFER_DEBUG__
    kal_prompt_trace(TRACE_INFO, "@@@   RamBuffer_Release()");
#endif

    if((my_id == NULL) || (kal_adm_delete(my_id) != KAL_SUCCESS))
    {
#ifdef __RAMBUFFER_DEBUG__
        kal_prompt_trace(TRACE_INFO, "delete adm  failed");
#endif
        return FALSE;
    }
    else
    {
#ifdef __RAMBUFFER_DEBUG__
        kal_prompt_trace(TRACE_INFO, "delete adm   OK  ");
#endif
        return TRUE;
    }

}


/*---------------------------------------------------------------------------
 * FUNCTION			RamBuffer_Alloc
 *
 * DESCRIPTION		c_stl  控件申请内存空间
 *
 * PARAMETERS
 *		void
 * RETURNS
 *  		void
 *
 *---------------------------------------------------------------------------*/

#if 0
void* RamBuffer_Alloc(U32 mem_size)
{

    U8* buf_ptr = NULL ;

#ifdef __RAMBUFFER_DEBUG__
    kal_prompt_trace(TRACE_INFO, "@@@   RamBuffer_Alloc( %d )", mem_size);
#endif

    if(mem_size > RAMBUFFER_LENGHT)
    {
#ifdef __RAMBUFFER_DEBUG__
        kal_prompt_trace(TRACE_INFO, "Alloc mem is too large ");
#endif
        LOGS("====Alloc mem is too large, sys_reset=====");
        ASSERT(0);
        return NULL;
    }
    else if(mem_size > kal_adm_get_total_left_size(my_id))
    {
#ifdef __RAMBUFFER_DEBUG__
        kal_prompt_trace(TRACE_INFO, "mem is no enough  ");
#endif
        LOGS("====mem is no enough, sys_reset=====");
        ASSERT(0);
        return NULL;
    }

    kal_take_mutex(rambuf_pool_mutex);
    buf_ptr = (U8*)kal_adm_alloc(my_id, mem_size);
    kal_give_mutex(rambuf_pool_mutex);

    if(buf_ptr == NULL)
    {
#ifdef __RAMBUFFER_DEBUG__
        kal_prompt_trace(TRACE_INFO, "alloc failed  ");
#endif
    }
    else
    {
#ifdef __RAMBUFFER_DEBUG__
        kal_prompt_trace(TRACE_INFO, "alloc is OK   --   buf_ptr = %d   " , buf_ptr);
#endif
    }

    return buf_ptr;
}


/*---------------------------------------------------------------------------
 * FUNCTION			RamBuffer_Alloc
 *
 * DESCRIPTION		c_stl  控件释放内存空间
 *
 * PARAMETERS
 *		void
 * RETURNS
 *  		void
 *
 *---------------------------------------------------------------------------*/

void RamBuffer_Free(void *mem_addr)
{
#ifdef __RAMBUFFER_DEBUG__
    kal_prompt_trace(TRACE_INFO, "@@@   RamBuffer_Free( %d )" , mem_addr);
#endif

    kal_take_mutex(rambuf_pool_mutex);

    if(mem_addr == NULL)
    {
#ifdef __RAMBUFFER_DEBUG__
        kal_prompt_trace(TRACE_INFO, "mem_addr is NULL  ");
#endif
    }
    else
    {
        kal_adm_free(my_id, mem_addr);
    }

    kal_give_mutex(rambuf_pool_mutex);
}
#endif /* 0 */

/*---------------------------------------------------------------------------
 * FUNCTION		Ram_Alloc
 * DESCRIPTION		c_stl  控件申请内存空间
 *---------------------------------------------------------------------------*/
void* Ram_Alloc1(const char *fun_name, U8 appid, U32 mem_size)
{
    U8* buf_ptr = NULL;
    kal_uint32 freesize;
    static kal_uint8 count = 0;
    LOGD(L_DRV, L_V9, "%s,%d,%d", fun_name, appid, mem_size);
    mem_size += 10;
    if(my_id == NULL)
    {
        if(!RamBuffer_Init())
        {
            ASSERT(0);
            return NULL;
        }
    }
    if(appid >= RAMBUFFER_APP_MAX)
    {
        LOGD(L_DRV, L_V1, "!!!   Error: App ID is out of range!");
        track_cust_restart(12, 0);
        return NULL;
    }
    if(mem_size > RAMBUFFER_ALLOC_ONE_MAX)
    {
        LOGD(L_DRV, L_V1, "!!!   Error: Alloc mem is too large!");
        track_cust_restart(13, 0);
        return NULL;
    }
    freesize = kal_adm_get_total_left_size(my_id);
    if(freesize < 100000 && count == 0)
    {//
        count++;
        track_cust_ram_alarm(freesize, mem_size);
    }
    else if(freesize < 50000 && count == 1)
    {//
        count++;
        track_cust_ram_alarm(freesize, mem_size);
    }
    else if(freesize < 10000 && count == 2)
    {//
        count++;
        track_cust_restart(6, 0);
        return NULL;
    }
    if(mem_size > freesize)
    {
        LOGD(L_DRV, L_V1, "!!!   Error: Mem is no enough!");
        track_cust_restart(7, 0);
        return NULL;
    }
    kal_take_mutex(rambuf_pool_mutex);
    buf_ptr = kal_adm_alloc(my_id, mem_size);
    if(buf_ptr == NULL)
    {
        kal_give_mutex(rambuf_pool_mutex);
        LOGD(L_DRV, L_V1, "!!!   Error: Alloc failed!");
        track_cust_restart(49, 0);
        return buf_ptr;
    }
    else
    {
        MaxAlloc[appid] += mem_size;
        kal_give_mutex(rambuf_pool_mutex);
        LOGD(L_DRV, L_V9, "***   alloc(%d), [%d]=%d, IdleAlloc=%d, %p, %p", 
            mem_size, appid, MaxAlloc[appid], kal_adm_get_max_alloc_size(my_id), buf_ptr, &buf_ptr[8]);
        memset(buf_ptr, 0, mem_size);
        buf_ptr[0] = 0xBB;
        buf_ptr[1] = 0xCC;
        buf_ptr[2] = appid;
        memcpy(&buf_ptr[4], &mem_size, 4);
        buf_ptr[mem_size-2] = 0xCC;
        buf_ptr[mem_size-1] = 0xBB;
        return &buf_ptr[8];
    }
}

/*---------------------------------------------------------------------------
 * FUNCTION		Ram_Free
 * DESCRIPTION		c_stl  控件释放内存空间
 *---------------------------------------------------------------------------*/
void Ram_Free1(const char *fun_name, U8 **mem_addr)
{
    U8* buf_ptr;
    U8 appid;
    U32 mem_size;
    LOGD(L_DRV, L_V9, " %s,%p", fun_name, *mem_addr);
    if(my_id == NULL)
    {
        if(!RamBuffer_Init())
        {
            track_cust_restart(14, 0);
            return;
        }
    }
    if(mem_addr == NULL)
    {
        LOGD(L_DRV, L_V1, "!!!   Error: mem_addr is NULL! (%s,%p)", fun_name, *mem_addr);
        track_cust_restart(15, 0);
        return;
    }
    if(*mem_addr == NULL)
    {
        LOGD(L_DRV, L_V1, "!!!   Error: mem_addr2 is NULL! (%s,%p)", fun_name, *mem_addr);
        track_cust_restart(16, 0);
        return;
    }
    buf_ptr = *mem_addr - 8;
    appid = buf_ptr[2];
    if(appid >= RAMBUFFER_APP_MAX)
    {
        LOGD(L_DRV, L_V1, "!!!   Error: App ID is out of range! (%s,%p,%p)", fun_name, *mem_addr, buf_ptr);
        track_cust_restart(17, 0);
        return;
    }
    memcpy(&mem_size, &buf_ptr[4], 4);
    if(mem_size > RAMBUFFER_ALLOC_ONE_MAX)
    {
        track_cust_restart(11, 0);
        return;
    }
    if(buf_ptr[0] != 0xBB || buf_ptr[1] != 0xCC || buf_ptr[mem_size-2] != 0xCC || buf_ptr[mem_size-1] != 0xBB)
    {
        LOGD(L_DRV, L_V1, "!!!   Error: head is out of range! (%d,%s,%p,%p)", mem_size, fun_name, *mem_addr, buf_ptr);
        track_cust_restart(24, 0);
        LOGH(L_DRV, L_V1, buf_ptr, (mem_size > 100 ? 100 : mem_size));
        return;
    }
    kal_take_mutex(rambuf_pool_mutex);
    MaxAlloc[appid] -= mem_size;
    kal_adm_free(my_id, buf_ptr);
    kal_give_mutex(rambuf_pool_mutex);
    *mem_addr = NULL;
    LOGD(L_DRV, L_V9, "***   free=%d, [%d]=%d, IdleAlloc=%d", 
        mem_size, appid, MaxAlloc[appid], kal_adm_get_max_alloc_size(my_id));
}

void Ram_view(char *outmsg)
{
    sprintf(outmsg, "RamBuffer total free:%d; use:[0]%d, [1]%d, [2]%d, [3]%d, [4]%d, [5]%d, [6]%d\r\n", 
        kal_adm_get_max_alloc_size(my_id), MaxAlloc[0], MaxAlloc[1], MaxAlloc[2], MaxAlloc[3], MaxAlloc[4], MaxAlloc[5], MaxAlloc[6]);
}

