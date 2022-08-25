

#include "MMI_include.h"
#include "mmi_rp_app_gb_winguo_def.h"
//#include "app_mem_med.h"

#include "GB_WG_Common.h"

#define APPMEM_WINGUO_MEM_POLL_SIZE (300*1024)

static GB_VOID *g_GB_WG_MemoryPool = NULL;
static KAL_ADM_ID  g_GB_WG_MemPoolID = 0;

GB_VOID *GB_WG_Platform_MallocFun(GB_ULONG size)
{
	GB_VOID * result =NULL;
	if(size>0)
	{
		return (void*)kal_adm_alloc(g_GB_WG_MemPoolID, size);
	}
	return GB_NULL;
}


GB_VOID GB_WG_Platform_FreeFun(GB_VOID* p)
{
	if(p!=0)
	{
		kal_adm_free(g_GB_WG_MemPoolID, p);
	}
}



void mmi_gb_winguo_app_memory(void)
{
	if (g_GB_WG_MemoryPool == NULL)
	{
		g_GB_WG_MemoryPool = mmi_frm_asm_alloc_r(APP_GB_WINGUO, APPMEM_WINGUO_MEM_POLL_SIZE);
	}

	MMI_ASSERT(g_GB_WG_MemoryPool!=NULL);
	kal_mem_set(g_GB_WG_MemoryPool, 0, APPMEM_WINGUO_MEM_POLL_SIZE);

	g_GB_WG_MemPoolID = kal_adm_create(g_GB_WG_MemoryPool, APPMEM_WINGUO_MEM_POLL_SIZE, NULL, KAL_FALSE);
	MMI_ASSERT(g_GB_WG_MemPoolID != NULL);    
}

void mmi_gb_winguo_app_free(void)
{
	if(g_GB_WG_MemPoolID)
	{
		kal_adm_delete(g_GB_WG_MemPoolID);
		g_GB_WG_MemPoolID = NULL;
	}

	if (g_GB_WG_MemoryPool != NULL)
	{
		mmi_frm_asm_free_r(APP_GB_WINGUO, g_GB_WG_MemoryPool);
		g_GB_WG_MemoryPool = NULL;
	}    
}

GB_BOOL GB_WG_Platform_Is_Winguo()
{
	return (mmi_frm_group_get_active_id() == GRP_GB_WINGUO_SCREEN ? GB_TRUE : GB_FALSE);
}