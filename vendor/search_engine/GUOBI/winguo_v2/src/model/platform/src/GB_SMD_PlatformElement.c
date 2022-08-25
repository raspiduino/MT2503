
#include "MMI_include.h"
#include "ModeSwitchSrvGprot.h"
#include "NwUsabSrvGprot.h"
#include "mmi_rp_app_gb_winguo_def.h"

#include "GB_WG_Common.h"

extern int GBMD_AddLangKeyMap(long nLangName);

enum __MD_Lang_Enum__
{
	MD_Lang_Name_Arabic, 
	MD_Lang_Name_Bulgarian, 
	MD_Lang_Name_Danish, 
	MD_Lang_Name_Dutch, 
	MD_Lang_Name_Farsi, 
	MD_Lang_Name_French, 
	MD_Lang_Name_German, 
	MD_Lang_Name_Greek, 
	MD_Lang_Name_Hebrew, 
	MD_Lang_Name_Hindi, 
	MD_Lang_Name_Hungarian, 
	MD_Lang_Name_Indonesia, 
	MD_Lang_Name_Italian, 
	MD_Lang_Name_Malay, 
	MD_Lang_Name_Philipino, 
	MD_Lang_Name_Polish, 
	MD_Lang_Name_Potuguese, 
	MD_Lang_Name_Russian, 
	MD_Lang_Name_Spanish, 
	MD_Lang_Name_Swahili, 
	MD_Lang_Name_Thai, 
	MD_Lang_Name_Tibetan, 
	MD_Lang_Name_Turkish, 
	MD_Lang_Name_Uyghur, 
	MD_Lang_Name_Vietnam, 
	MD_Lang_Name_Bengali, 
	MD_Lang_Name_COUNT
};


GB_VOID GB_SMD_LanguageAdd(GB_VOID)
{
#ifdef __MMI_LANG_ARABIC__
	GBMD_AddLangKeyMap(MD_Lang_Name_Arabic); 
#endif
#ifdef __MMI_LANG_BULGARIAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Bulgarian); 
#endif
#ifdef __MMI_LANG_DANISH__
	GBMD_AddLangKeyMap(MD_Lang_Name_Danish); 
#endif
#ifdef __MMI_LANG_DUTCH__
	GBMD_AddLangKeyMap(MD_Lang_Name_Dutch); 
#endif
#ifdef __MMI_LANG_PERSIAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Farsi); 
#endif
#ifdef __MMI_LANG_FRENCH__
	GBMD_AddLangKeyMap(MD_Lang_Name_French); 
#endif
#ifdef __MMI_LANG_GERMAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_German); 
#endif
#ifdef __MMI_LANG_GREEK__
	GBMD_AddLangKeyMap(MD_Lang_Name_Greek); 
#endif
#ifdef __MMI_LANG_HEBREW__
	GBMD_AddLangKeyMap(MD_Lang_Name_Hebrew); 
#endif
#ifdef __MMI_LANG_HINDI__
	GBMD_AddLangKeyMap(MD_Lang_Name_Hindi); 
#endif
#ifdef __MMI_LANG_HUNGARIAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Hungarian); 
#endif
#ifdef __MMI_LANG_INDONESIAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Indonesia); 
#endif
#ifdef __MMI_LANG_ITALIAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Italian); 
#endif
#ifdef __MMI_LANG_MALAY__
	GBMD_AddLangKeyMap(MD_Lang_Name_Malay); 
#endif
#ifdef __MMI_LANG_FILIPINO__
	GBMD_AddLangKeyMap(MD_Lang_Name_Philipino); 
#endif
#ifdef __MMI_LANG_POLISH__
	GBMD_AddLangKeyMap(MD_Lang_Name_Polish); 
#endif
#ifdef __MMI_LANG_PORTUGUESE__
	GBMD_AddLangKeyMap(MD_Lang_Name_Potuguese); 
#endif
#ifdef __MMI_LANG_RUSSIAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Russian); 
#endif
#ifdef __MMI_LANG_SPANISH__
	GBMD_AddLangKeyMap(MD_Lang_Name_Spanish); 
#endif
#ifdef __MMI_LANG_SWAHILI__
	GBMD_AddLangKeyMap(MD_Lang_Name_Swahili); 
#endif
#ifdef __MMI_LANG_THAI__
	GBMD_AddLangKeyMap(MD_Lang_Name_Thai); 
#endif
#ifdef __MMI_LANG_TIBETAN__
	GBMD_AddLangKeyMap(MD_Lang_Name_Tibetan); 
#endif
#ifdef __MMI_LANG_TURKISH__
	GBMD_AddLangKeyMap(MD_Lang_Name_Turkish); 
#endif
#ifdef __MMI_LANG_UYGHUR__
	GBMD_AddLangKeyMap(MD_Lang_Name_Uyghur); 
#endif
#ifdef __MMI_LANG_VIETNAMESE__
	GBMD_AddLangKeyMap(MD_Lang_Name_Vietnam); 
#endif
#ifdef __MMI_LANG_BENGALI__
	GBMD_AddLangKeyMap(MD_Lang_Name_Bengali); 
#endif
}

GB_BYTE GB_WG_CheckUsbmode(GB_VOID)
{
#ifdef __USB_IN_NORMAL_MODE__
#ifdef __COSMOS_MMI_PACKAGE__
	if (mmi_usb_is_in_mass_storage_mode())
#else
	if(srv_usb_is_in_mass_storage_mode())//modify by zhangchenglong
#endif
	{ 
		return 1; 
	} 
#endif /* __USB_IN_NORMAL_MODE__ */ 
	return 0;
}

GB_WG_Phone_Mode GB_WG_Get_Phone_Mode(GB_VOID)
{
	GB_WG_Phone_Mode nmode = e_GB_WG_SMD_PHONE_NORMAL;
	if (GB_WG_CheckUsbmode())
	{
		nmode = e_GB_WG_PHONE_MODE_USB;
	}
	else if(srv_mode_switch_is_network_service_available() == MMI_FALSE)
	{
		nmode = e_GB_WG_PHONE_MODE_FLIGHT;
	}
	else
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
#endif
/* under construction !*/
#else
		if (!mmi_bootup_is_sim_valid())
#endif
		{
			nmode = e_GB_WG_PHONE_MODE_NOSIM;
		}
		return nmode;
}


GB_VOID *GB_SMD_Mode_Malloc(GB_U32 size)
{
	return GB_WG_Malloc(size);
}


GB_VOID GB_SMD_Mode_Free(GB_VOID *p)
{
	GB_WG_Free(p);
}
