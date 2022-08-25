#ifdef __MCARE_ON_MODIS__
#include "MMI_include.h"

mmi_ret vapp_mcare_on_ncenter_update(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}
void MCR_Entry(void)
{
#ifdef __COSMOS_MMI_PACKAGE1__
    vapp_nmgr_global_popup_show_command_str(
        MMI_SCENARIO_ID_DEFAULT, 
        VFX_WSTR_RES(STR_GLOBAL_NOT_SUPPORTED),
        NULL,
        NULL,
        NULL);
#else
	DisplayPopup((U8*)get_string(STR_GLOBAL_NOT_SUPPORTED), 0, 0, 200, 0);
#endif

}

void MCR_EntryQQBrowser(void)
{
#ifdef __COSMOS_MMI_PACKAGE1__
    vapp_nmgr_global_popup_show_command_str(
        MMI_SCENARIO_ID_DEFAULT, 
        VFX_WSTR_RES(STR_GLOBAL_NOT_SUPPORTED),
        NULL,
        NULL,
        NULL);
#else
	DisplayPopup((U8*)get_string(STR_GLOBAL_NOT_SUPPORTED), 0, 0, 200, 0);
#endif

}

void MCR_HiliteQQBrowser(void)
{
}

void MCR_HiliteMenu(void)
{
}

#endif
