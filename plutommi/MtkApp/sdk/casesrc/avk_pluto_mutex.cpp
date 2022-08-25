extern "C"
{
#include "mmi_frm_remutex_gprot.h"
}

AVK_CASE(AVK_PLUTO_MUTEX_CASE_001,AVK_PLUTO_MUTEX)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_frm_recursive_mutex_struct g_mmi_frm_recursive_mutex;
	kal_taskid g_mmi_tst_taskid;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(&g_mmi_frm_recursive_mutex, 0, sizeof(g_mmi_frm_recursive_mutex));
	AVK_LOG_NORMAL(mmi_frm_recursive_mutex_init(&g_mmi_frm_recursive_mutex, "mutex_sdk"));
	g_mmi_tst_taskid = kal_get_task_self_id();
    AVK_LOG_ASYN_NORMAL(mmi_frm_recursive_mutex_lock(&g_mmi_frm_recursive_mutex));
    mmi_frm_recursive_mutex_lock(&g_mmi_frm_recursive_mutex);
    
    AVK_LOG_ASYN_NORMAL(mmi_frm_recursive_mutex_unlock(&g_mmi_frm_recursive_mutex));
	if(!(g_mmi_frm_recursive_mutex.ref_count == 1))
	{
		AVK_CASE_RESULT(AVK_FAIL);
		return ;
    }
    mmi_frm_recursive_mutex_unlock(&g_mmi_frm_recursive_mutex);
	if(!(g_mmi_frm_recursive_mutex.ref_count == 0))
	{
		AVK_CASE_RESULT(AVK_FAIL);
		return ;
    }
    mmi_frm_recursive_mutex_lock(&g_mmi_frm_recursive_mutex);
    mmi_frm_recursive_mutex_unlock(&g_mmi_frm_recursive_mutex);
	if(!(g_mmi_frm_recursive_mutex.ref_count == 0))
	{
		AVK_CASE_RESULT(AVK_FAIL);
		return ;
    }
    mmi_frm_recursive_mutex_lock(&g_mmi_frm_recursive_mutex);
    mmi_frm_recursive_mutex_unlock(&g_mmi_frm_recursive_mutex);
	if(!(g_mmi_frm_recursive_mutex.ref_count == 0))
	{
		AVK_CASE_RESULT(AVK_FAIL);
		return ;
    }
    mmi_frm_recursive_mutex_lock(&g_mmi_frm_recursive_mutex);
    mmi_frm_recursive_mutex_lock(&g_mmi_frm_recursive_mutex);
    mmi_frm_recursive_mutex_unlock(&g_mmi_frm_recursive_mutex);
    mmi_frm_recursive_mutex_lock(&g_mmi_frm_recursive_mutex);
	if(!((g_mmi_frm_recursive_mutex.ref_count == 2) && (g_mmi_frm_recursive_mutex.taskid == g_mmi_tst_taskid)))
	{
		AVK_CASE_RESULT(AVK_FAIL);
		return ;
    }
    mmi_frm_recursive_mutex_unlock(&g_mmi_frm_recursive_mutex);
	if(!(g_mmi_frm_recursive_mutex.ref_count == 1))
	{
		AVK_CASE_RESULT(AVK_FAIL);
		return ;
    }
    mmi_frm_recursive_mutex_unlock(&g_mmi_frm_recursive_mutex);
	AVK_CASE_RESULT(AVK_PASS);
}



