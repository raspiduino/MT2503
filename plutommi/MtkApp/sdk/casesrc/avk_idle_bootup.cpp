extern "C"
{
 #include "BootupSrvGprot.h"
}

AVK_ADD_ITEM(AVK_IDLE_BOOTUP_AUTO,L"Auto case",AVK_IDLE_BOOTUP);


AVK_CASE(AVK_IDLE_BOOTUP_CASE_AUTO,AVK_IDLE_BOOTUP_AUTO)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 reval;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	AVK_LOG(srv_bootup_is_launched());
	AVK_LOG(!srv_bootup_is_booting());

	/*Bootup is completed and entered idle screen.*/
	AVK_LOG(srv_bootup_is_completed());

	/*
		SRV_BOOTUP_MODE_NORMAL
		SRV_BOOTUP_MODE_USB
		SRV_BOOTUP_MODE_CHARGE
		SRV_BOOTUP_MODE_PRECHARGE
		SRV_BOOTUP_MODE_ALARM*/ 
	AVK_LOG(srv_bootup_get_booting_mode()==SRV_BOOTUP_MODE_NORMAL);
	AVK_LOG(!srv_bootup_is_exception_mode());
	AVK_LOG(srv_bootup_verification_is_passed(MMI_SIM1)==MMI_TRUE);
	AVK_LOG(srv_bootup_get_verification_info(MMI_SIM1, &reval) == SRV_BOOTUP_VERI_NONE);
	//srv_bootup_verify(MMI_SIM1,L"1122",NULL,NULL);
	
}

