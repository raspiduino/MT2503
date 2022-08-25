#include "MMI_features.h"

#ifdef __MMI_SSO__

#include "custom_sso_config.h"
#include "nvram_common_defs.h"

#ifndef WIN32
#ifdef __MMI_SSO_PRELOAD_YAHOO__
extern const kal_uint8 YAHOO_vpp[];
const kal_uint8 *custom_sso_get_preload_yahoo(void) { return YAHOO_vpp; }
#else
const kal_uint8 *custom_sso_get_preload_yahoo(void) { return NULL; }
#endif
#endif /* WIN32 */

kal_bool custom_sso_using_card_memory(void)
{
    return KAL_TRUE;
}

kal_uint16 custom_sso_get_lid(void)
{
    return NVRAM_EF_SRV_SSO_ACCOUNT_LID; 
}

#endif
