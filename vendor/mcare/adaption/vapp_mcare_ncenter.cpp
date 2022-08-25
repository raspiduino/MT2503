/*****************************************************************************
 * 该文件仅在1112COSMOS下需要编译
 *****************************************************************************/
#ifdef __MCAREV31__
#if (MCR_MTK_VER >=MTK_VER_1112)

#include "MMI_features.h"
#ifdef __MMI_NCENTER_SUPPORT__

#include "Vapp_mcare_ncenter.h"
// TODO: remove
#include "vcp_res.h"

#include "vcp_global_popup.h"


extern "C"
{
#include "GlobalResDef.h"
#include "Wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_app_launcher_gprot.h"
#include "NotificationGprot.h"

#include "mmi_rp_app_tencent_mcare_def.h"
#include "MMI_inet_app_trc.h"
#include "MAdpMenuDef.h" //by purple
}

/*****************************************************************************
 * Class VappMcare
 *****************************************************************************/
extern "C" void McfIdleRegistePressIconCb(void);
extern "C" VfxS32 McfStatusIcon_getIconId(void);
extern "C" void McfStatusIcon_PressedTimerEventProc(void);
extern "C" void mcare_ncenter_exit(void);
extern "C" VfxU32 McfIsMcrRunning(void);
extern "C" VfxU32 McfIsStatusIconShow(VfxS16 nIconId);

#if (0)
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
#if 1
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
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif
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
#if 0
/* under construction !*/
#else
/* under construction !*/
#endif
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
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif /* #if (0) */

#ifdef __cplusplus
extern "C"
{
#endif

#include "mmi_cb_mgr_gprot.h"
#include "AppMgrSrvGprot.h"

void vapp_mcare_update_cell(VsrvNotificationOngoing *noti)
{
   	VfxWString mainText;
    VfxWString subText;
    VfxS32 IconId;

	McfIdleRegistePressIconCb(); 
	IconId = McfStatusIcon_getIconId();
	switch (IconId)
	{
		case MIDLE_ICON_MCARE:
            noti->setIcon(VfxImageSrc(IMG_MCARE_NCENTER_MCR));
			mainText = VFX_WSTR_RES(STR_MCARE_MAIN);
			break;
		case MIDLE_ICON_QQ_AWAYLINE:
			noti->setIcon(VfxImageSrc(IMG_MCARE_NCENTER_QQ_AWAY));
			mainText = VFX_WSTR("QQ");
			subText = VFX_WSTR_RES(STR_TENCENT_MCARE_QQ_AWAY); 

			break;
		case MIDLE_ICON_QQ_HAVEMSG:
			noti->setIcon(VfxImageSrc(IMG_MCARE_NCENTER_QQ_MESSEGE));
			mainText = VFX_WSTR("QQ (");
            mainText += VFX_WSTR_RES(STR_TENCENT_MCARE_QQ_HAVEMSG);
            mainText += VFX_WSTR(")");
			subText = VFX_WSTR_RES(STR_TENCENT_MCARE_QQ_HAVEMSG); 

			break;
		case MIDLE_ICON_QQ_INVISBLE:
			noti->setIcon(VfxImageSrc(IMG_MCARE_NCENTER_QQ_INVISBLE));
			mainText = VFX_WSTR("QQ");
			subText = VFX_WSTR_RES(STR_TENCENT_MCARE_QQ_INVISBLE); 

			break;
		case MIDLE_ICON_QQ_OFFLINE:
			noti->setIcon(VfxImageSrc(IMG_MCARE_NCENTER_QQ_OFF));
			mainText = VFX_WSTR("QQ");
			subText = VFX_WSTR_RES(STR_TENCENT_MCARE_QQ_OFFLINE); 

			break;
		case MIDLE_ICON_QQ_ONLINE:
			noti->setIcon(VfxImageSrc(IMG_MCARE_NCENTER_QQ_ON));
			mainText = VFX_WSTR("QQ");
			subText = VFX_WSTR_RES(STR_TENCENT_MCARE_QQ_ONLINE); 

			break;
		default:
            noti->setIcon(VfxImageSrc(IMG_MCARE_NCENTER_MCR));
			mainText = VFX_WSTR_RES(STR_MCARE_MAIN);
			mainText = VFX_WSTR_RES(STR_MCARE_MAIN);
			break;
	}

    noti->setMainText(mainText);
    noti->setSubText(subText);
    noti->setQuestionText(VFX_WSTR_RES(STR_MCARE_RUNNING));

}

void vapp_mcare_Intent_callback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
	 if (intent.type == VSRV_NINTENT_TYPE_TERMINATE)
	 {
		 //MMI_ID instance_id ;
         mcare_ncenter_exit();
		 //instance_id = srv_appmgr_query_instance_single_id("native.mtk.tencent");
		 //srv_appmgr_close_app(instance_id);
		 mmi_frm_app_close(APP_TENCENT_MCARE);
	 }	
	 else if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
	 {
		//srv_appmgr_launch("native.mtk.tencent");
        if(mmi_frm_app_is_hidden(APP_TENCENT_MCARE))
       	{
       		mmi_frm_app_set_hidden(APP_TENCENT_MCARE, MMI_FALSE, 0);
       	}
		else
		{
        	mmi_frm_app_set_active(APP_TENCENT_MCARE, 0);
		}
		//maomaolin add
		//McfIdleRegistePressIconCb(); 
        //McfStatusIcon_PressedTimerEventProc( );
	 }
}

mmi_ret vapp_mcare_on_ncenter_update(mmi_event_struct *evt)
{

    vapp_mcare_ncenter_update_evt_struct *power_evt = (vapp_mcare_ncenter_update_evt_struct*) evt;

    if(power_evt->is_shown)
    {
		VsrvNGroupSingleTitle *mcare_group;
		VSRV_NGROUP_CREATE_EX(mcare_group, VsrvNGroupSingleTitle, (APP_TENCENT_MCARE));
		mcare_group->setTitle(VFX_WSTR_RES(STR_MCARE_MAIN));
		
		VsrvNotificationOngoing *mcare_noti;
		VSRV_NOTIFICATION_CREATE_EX(mcare_noti, VsrvNotificationOngoing, ((VsrvNGroup*)mcare_group, 0));
		vapp_mcare_update_cell(mcare_noti);
		mcare_noti->setIntentCallback(vapp_mcare_Intent_callback, NULL, 0);
		mcare_noti->notify();
	}
    else
    {
    	VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)APP_TENCENT_MCARE, 0);
    }
    return MMI_OK;

}


extern "C" void McrNcenterStateChange(VfxBool isShow)
{
	vapp_mcare_ncenter_update_evt_struct evt;
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_MCARE_UPDATE_NCENTER);

	if(isShow)
	{
		evt.is_shown = VFX_TRUE;
	}
	else
	{
		evt.is_shown = VFX_FALSE;
	}

	MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


#ifdef __cplusplus
}
#endif

#else /* __MMI_NCENTER_SUPPORT__ */

#include "MMI_include.h"
extern "C" mmi_ret vapp_mcare_on_ncenter_update(mmi_event_struct *evt)
{
    return MMI_OK;
}

extern "C" void McrNcenterStateChange(bool isShow)
{
    return;
}

#endif /* __MMI_NCENTER_SUPPORT__ */

#endif
#endif

