extern "C"
{
#include "CharBatSrvGprot.h"

}

AVK_ADD_ITEM(AVK_DEVICE_BATT_AUTO,L"Auto case",AVK_DEVICE_BATT);

AVK_CASE(AVK_DEVICE_BATT_CASE_AUTO,AVK_DEVICE_BATT_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    battery_level_enum var_level; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*srv_charbat_check_if_mo_allow*/
    AVK_LOG(srv_charbat_check_if_mo_allow() == MMI_TRUE);

    /*srv_charbat_get_bat_level*/
    var_level=srv_charbat_get_bat_level();
	AVK_LOG_FUN(srv_charbat_get_bat_level, (var_level >= BATTERY_LOW_WARNING));

    /*srv_charbat_get_battery_level*/
    var_level=srv_charbat_get_battery_level();
	AVK_LOG_FUN(srv_charbat_get_battery_level, (var_level >= BATTERY_LOW_WARNING));

    /*srv_charbat_is_charging*/
	AVK_LOG(srv_charbat_is_charging() == MMI_FALSE);

    /*srv_charbat_is_low_battery*/
	AVK_LOG(srv_charbat_is_low_battery() == MMI_FALSE);
  
}

