#include "SatSrvGprot.h"
#include "SatAppGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_utility_gprot.h"


U8 IsSATPresent(void)
{
    return (U8) srv_sat_is_menu_present(MMI_SIM1);
}


U8 *GetSATMainMenuAlphaID(void)
{
    return (U8*) srv_sat_get_menu_title(MMI_SIM1);
}


U8 *GetSATIdleText(void)
{
    mmi_sim_enum sim_id[] = {MMI_SIM1, MMI_SIM2, MMI_SIM3, MMI_SIM4};
    S32 i;

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (srv_sat_is_idle_display_present(sim_id[i]))
        {
            return (U8*) srv_sat_get_idle_display_text(sim_id[i]);
        }
    }

    return NULL;
}


U8 *GetSATIdleIcon(void)
{
    mmi_sim_enum sim_id[] = {MMI_SIM1, MMI_SIM2, MMI_SIM3, MMI_SIM4};
    S32 i;

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (srv_sat_is_idle_display_present(sim_id[i]))
        {
            return (U8*) srv_sat_get_idle_display_icon(sim_id[i]);
        }
    }

    return NULL;
}


void GoToSATMainMenu(void)
{
    mmi_sat_app_launch(mmi_frm_group_get_active_id(), MMI_SIM1);
}


void mmi_sat_pre_entry_GoToSATMainMenu(void)
{
    mmi_sat_app_launch(mmi_frm_group_get_active_id(), MMI_SIM1);
}


#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
