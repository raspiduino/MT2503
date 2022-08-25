extern "C"
{
  #include "NwUsabSrvGprot.h"
}

AVK_ADD_ITEM(AVK_IDLE_USA_AUTO,L"Auto case",AVK_IDLE_USA);

AVK_CASE(AVK_IDLE_USA_CASE_AUTO,AVK_IDLE_USA_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#else
	AVK_LOG(srv_nw_usab_is_usable(MMI_SIM1));
#endif

	AVK_LOG(srv_nw_usab_get_one_usable_sim());
    AVK_LOG(srv_nw_usab_any_sim_is_usable());

}

