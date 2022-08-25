#ifndef _platform_inc_h_
#define _platform_inc_h_

#ifdef __cplusplus   
extern "C"{   
#endif // __cplusplus
//#ifdef WIN32
//#include "Windows.h"
//#endif

#include "MAdpConfig.h"
#ifdef _TENCENT_MCARE_ADP_

#include "MMI_features.h"
#include "mmi_include.h"
#include "MMIDataType.h"

#include "Gdi_const.h"
#include "Gdi_include.h"

#if (MCR_MTK_VER >= MTK_VER_1112)
#include "Mmi_frm_input_gprot.h"//purple 
#else
#include "EventsGProt.h" // GetkeyInfo
#include "HistoryGprot.h"
#endif

#include "Mdi_datatype.h"
#include "Mdi_audio.h"
#include "Device.h"
#include "AudioInc.h"
#include "gpioInc.h"

#include "stack_msgs.h"
#include "ProtocolEvents.h"
#if (MCR_MTK_VER >= MTK_VER_1112)
#include "mmi_frm_Queue_Gprot.h"//purple
#else
#include "QueueGprot.h"
#endif
#include "App_ltlcom.h"
#include "kal_trace.h"
#include "custom_config.h"
#include "Kal_release.h"
#if (MCR_MTK_VER >= MTK_VER_1132) //purple
#include "fs_gprot.h"
#else
#include "rtfiles.h"
#endif
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "FileManagerGProt.h"
#include "FileMgrStruct.h"
#if (MCR_MTK_VER >= MTK_VER_1112)
#include "FileMgrGprot.h"
#include "wgui_categories_util.h"
#endif
#include "Unicodexdcl.h"
#include "DateTimeGprot.h"
#if (MCR_MTK_VER >= MTK_VER_1012)
#include "wgui_status_icon_bar.h"
#include "mmi_frm_events_gprot.h"
#else
#include "wgui_status_icons.h"
#endif
#include "kal_non_specific_general_types.h"
#include "stack_config.h"
//#include "app2soc_struct.h"
//#include "Soc_api.h"
#include "Gui_Setting.h"

#include "ProtocolEvents.h"

#if (MCR_MTK_VER < MTK_VER_1112)
#include "TouchScreenGprot.h"
#endif

#include "AudioInc.h"
#include "gpioInc.h"
#include "gdi_include.h"
#include "GlobalDefs.h"
#include "wgui_categories_inputs.h" // ShowCategory5Screen
#include "wap_ps_struct.h" 
#include "med_smalloc.h"
#include "med_utility.h"
#include "usbdevicegprot.h"
#include "gdi_image_gif.h"
#include "CommonScreens.h"

#if (MCR_MTK_VER > MTK_VER_652)
#include "app_datetime.h"
#else
#include "DateTimeGprot.h"
#endif
#include "DateTimeType.h"
#include "TimerEvents.h"

#if (MCR_MTK_VER >= 1132) //by purple
#else
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#ifndef  MMI_ON_WIN32
#include "smsal_l4c_enum.h"

#if (MCR_MTK_VER >= MTK_VER_1112)
#include "FrameworkStruct_int.h"//jason
#else
#include "FrameworkStruct.h"
#endif

#if (MCR_MTK_VER >= MTK_VER_1012)
#include "SmsSrvGProt.h"
#else
#include "SMSApi.h"
#endif
#include "ems.h"
#include "SmsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#endif
#include "CallManagementGprot.h"

#include "keyBrd.h"
#include "app_mem.h"


#if (MCR_MTK_VER >= MTK_VER_828)
#include "Cbm_api.h"
#else
#include "ConnectManageGProt.h"
#endif

#if (MCR_MTK_VER >= MTK_VER_1032)
#include "DataAccountStruct.h"
extern mmi_dtcnt_list_disp_struct g_mmi_dtcnt_list_item[];
#endif
#include "DataAccountGProt.h"

#if (MCR_MTK_VER >= MTK_VER_828)
#include "ImeGprot.h"
#endif

#include "app_mem.h"

#include "soc_api.h"
#include "Conversions.h"

#include "ProtocolEvents.h"


#include "mdi_audio.h"

#if MCR_MTK_VER<MTK_VER_1210
#include "profilegprots.h"
#endif

#if MCR_MTK_VER>MTK_VER_812
#include "browser_api.h"
#else
#include "wapadp.h"
#endif

#include "custom_wap_config.h"

#ifdef PIXTEL_UI_XXX   //elvis
#include "PixtelDataTypes.h"
#endif

#if MCR_MTK_VER >= MTK_VER_1032
#include "mmi_frm_history_gprot.h"
#elif  MCR_MTK_VER>MTK_VER_812
#include "HistoryGprot_Int.h"//frike
#else
#include "HistoryGprot.h"
#endif

#if MCR_MTK_VER >= MTK_VER_1032
#include "bootupsrvgprot.h"
#endif

#if MCR_MTK_VER >= MTK_VER_1032
#include "nwinfosrvgprot.h"
#include "simctrlsrvgprot.h"
#endif

#if MCR_MTK_VER >= MTK_VER_1032
#include "ProfilesAppGprot.h"
#endif

#if MCR_MTK_VER >= MTK_VER_1032 
#include "DtcntSrv.h"
#include "Servicedefs.h"
#include "cbm_api.h"
#ifdef __TCPIP__
#if (MCR_MTK_VER >= MTK_VER_1112) && defined (__COSMOS_MMI_PACKAGE__)
#include "mmi_rp_vapp_data_account_wlan_def.h"//jason
#else
#include "mmi_rp_app_dataaccount_def.h"
#endif
#endif /* __TCPIP__ */
#else

#include "DataAccountDef.h"
#if (MCR_MTK_VER >= MTK_VER_912)
#include "DataAccountEnum.h"
#endif
#include "DataAccountStruct.h"
#include "abm_soc_enums.h"
#endif

#if (MCR_MTK_VER >= 1132)  //purple
#include "gpiosrvgprot.h"
#include "gdi_image_bmp.h"
#include "APPSDKAppGProt.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#endif

#if (MCR_MTK_VER >= MTK_VER_1210)
#include "wgui_editor.h"
#endif

#endif
#ifdef __cplusplus   
}   
#endif // __cplusplus
#endif // 
