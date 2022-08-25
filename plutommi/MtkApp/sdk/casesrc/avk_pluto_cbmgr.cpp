extern "C"
{
#include "mmi_cb_mgr_gprot.h"
}

extern "C" mmi_ret vs_fw_cbmgr_001_cb(mmi_event_struct *param)
{
    AVK_CASE_RESULT(AVK_PASS);
    AVK_ASYN_DONE();
    return 0;
}

AVK_CASE(AVK_PLUTO_CB_AUTO_001,AVK_PLUTO_CB)
{
	MMI_BOOL result_reg = MMI_FALSE,  result_dereg = MMI_FALSE;
	AVK_LOG_ASYN(mmi_frm_cb_reg_event(EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND,vs_fw_cbmgr_001_cb,NULL));
    AVK_LOG(result_reg = mmi_frm_cb_has_event_reg(EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND,vs_fw_cbmgr_001_cb,NULL));
	AVK_LOG_ASYN(mmi_frm_cb_dereg_event(EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND,vs_fw_cbmgr_001_cb,NULL));
	result_dereg = mmi_frm_cb_has_event_reg(EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND,vs_fw_cbmgr_001_cb,NULL);

	AVK_CASE_RESULT(result_reg && !result_dereg);
}

AVK_ASYN_CASE(AVK_PLUTO_CB_AUTO_002,AVK_PLUTO_CB)
{
	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_event_struct evt;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AVK_LOG_ASYN(mmi_frm_cb_reg_event(EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND,vs_fw_cbmgr_001_cb,NULL));
    MMI_FRM_INIT_EVENT(&evt,EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
    AVK_LOG_EX(MMI_RET_OK == MMI_FRM_CB_EMIT_EVENT(&evt));
    if (AVK_FAIL == AVK_GET_CASE_RESULT())
    {
        AVK_ASYN_DONE();
    }
    
}

AVK_ASYN_CASE(AVK_PLUTO_CB_AUTO_003,AVK_PLUTO_CB)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_event_struct evt;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	AVK_LOG_ASYN(mmi_frm_cb_reg_event(EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND,vs_fw_cbmgr_001_cb,NULL));
	MMI_FRM_INIT_EVENT(&evt,EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
	AVK_LOG_NORMAL(MMI_FRM_CB_EMIT_POST_EVENT(&evt));
}


AVK_ASYN_CASE(AVK_PLUTO_CB_AUTO_004,AVK_PLUTO_CB)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_event_struct evt;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_FRM_INIT_EVENT(&evt,EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
	AVK_LOG_NORMAL(MMI_FRM_CB_EMIT_POST_EVENT_EX(&evt,vs_fw_cbmgr_001_cb,NULL));
}

