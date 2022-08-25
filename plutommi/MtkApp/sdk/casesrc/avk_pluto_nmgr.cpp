extern "C"
{
#include "NotificationGprot.h"
}

MMI_BOOL avk_pluto_nmgr_cb(mmi_scenario_id scen_id, void *arg)
{
	return MMI_TRUE;
}

AVK_CASE(AVK_PLUTO_NM_AUTO_001,AVK_PLUTO_NM)
{
	AVK_LOG_NORMAL(mmi_frm_nmgr_set_only_disp_scrn(MMI_TRUE));
	AVK_LOG_EX(mmi_frm_nmgr_popup(MMI_SCENARIO_ID_GENERAL,MMI_EVENT_INFO,(WCHAR *)L"PASS"));
}

AVK_CASE(AVK_PLUTO_NM_AUTO_002,AVK_PLUTO_NM)
{
    //why crash when invoke this function
	AVK_LOG_FUN(mmi_frm_nmgr_notify_by_idle,AVK_PASS);
}

AVK_CASE(AVK_PLUTO_NM_AUTO_003,AVK_PLUTO_NM)
{
	AVK_LOG_NORMAL(mmi_frm_nmgr_unblock_sound_vid_stop(MMI_FRM_NMGR_SOUND | MMI_FRM_NMGR_VIB));
	AVK_LOG_EX(mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_GENERAL,MMI_EVENT_INFO,avk_pluto_nmgr_cb,NULL));
	AVK_LOG_NORMAL(mmi_frm_nmgr_block_sound_vib_stop(MMI_FRM_NMGR_SOUND | MMI_FRM_NMGR_VIB));
}

AVK_CASE(AVK_PLUTO_NM_AUTO_004,AVK_PLUTO_NM)
{
	mmi_frm_start_scenario(MMI_SCENARIO_ID_GENERAL);
	AVK_LOG_EX(mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_GENERAL,MMI_EVENT_INFO,avk_pluto_nmgr_cb,NULL));
	mmi_frm_nmgr_cancel_deferred_scenario(MMI_SCENARIO_ID_GENERAL,avk_pluto_nmgr_cb,NULL);
	
	AVK_LOG_EX(!mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_GENERAL,avk_pluto_nmgr_cb,NULL));
	AVK_LOG(mmi_frm_nmgr_get_defer_notification_count());
	mmi_frm_scrn_close_active_id();
}

