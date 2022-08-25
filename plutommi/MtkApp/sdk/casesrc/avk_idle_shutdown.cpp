extern "C"
{
 #include "ShutdownSrvGprot.h"
}

AVK_ADD_ITEM(AVK_IDLE_SHUTDOWN_AUTO,L"Auto case",AVK_IDLE_SHUTDOWN);
AVK_ADD_ITEM_SPECIAL(AVK_IDLE_SHUTDOWN_SPEC1,L"Special case 01",AVK_IDLE_SHUTDOWN);
AVK_ADD_ITEM_SPECIAL(AVK_IDLE_SHUTDOWN_SPEC2,L"Special case 02",AVK_IDLE_SHUTDOWN);


void avk_idle_shutdown_normal_start(void)
{
	srv_shutdown_normal_start(SRV_BOOTUP_MODE_NORMAL);
}

void avk_idle_shutdown_exit_system(void)
{
	srv_shutdown_exit_system(0);
}

AVK_SPECIAL_CASE(AVK_IDLE_SHUTDOWN_NORMAL_START,AVK_IDLE_SHUTDOWN_SPEC1)
{
	AVK_MANU_SHOW_TIPS(L"If you see the target power off normally, it's pass",avk_idle_shutdown_normal_start);
}

AVK_SPECIAL_CASE(AVK_IDLE_SHUTDOWN_EXIT_SYSTEM,AVK_IDLE_SHUTDOWN_SPEC2)
{
	AVK_MANU_SHOW_TIPS(L"If you see the target exit system (target shutdown immediately), it's pass",avk_idle_shutdown_exit_system);
}


AVK_CASE(AVK_IDLE_SHUTDOWN_CASE_AUTO,AVK_IDLE_SHUTDOWN_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    AVK_LOG(srv_shutdown_is_running());
    
} 

