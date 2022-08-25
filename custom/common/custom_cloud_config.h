#ifndef __CUSTOM_CLOUD_CONFIG_H__
#define __CUSTOM_CLOUD_CONFIG_H__

#include "MMI_features.h"
#include "kal_general_types.h"

#ifdef __MMI_SSO__

#define SRV_CLD_RESTORE_NUM  (20)

kal_bool custom_cloud_using_card_memory(void);

#endif /*  __MMI_SSO__ */

#ifdef __CLOUD_SUPPORT__

/*
 * Used to prevent res ID shifting when re-config feature options.
 */
extern kal_uint16 g_SMS_PHONE_ENTRY;
extern kal_uint16 g_MAX_PHB_PHONE_ENTRY;


typedef enum
{
#ifdef __SMS_CLOUD_SUPPORT__
    SRV_CLD_NVRAM_EF_SMS_USED_NUM_LID,
    SRV_CLD_NVRAM_EF_SMS_UID_COUNT_LID,
    SRV_CLD_NVRAM_EF_CLOUD_SMS_ITEM_LID,
#endif

#ifdef __VCARD_CLOUD_SUPPORT__
    SRV_CLD_NVRAM_EF_VCRD_USED_NUM_LID,
    SRV_CLD_NVRAM_EF_VCRD_UID_COUNT_LID,
    SRV_CLD_NVRAM_EF_CLOUD_VCRD_ITEM_LID,
    SRV_CLD_NVRAM_EF_VCRD_UID_LIST_URL_LID,
    SRV_CLD_NVRAM_EF_VCRD_IS_CHANGE_LID,
#endif

    SRV_CLD_NVRAM_EF_LID_TOTAL
}srv_cloud_nvram_lid_enum;

kal_uint16 custom_cloud_get_nvram_lid(srv_cloud_nvram_lid_enum nvram_lid_type);

#endif /*  __CLOUD_SUPPORT__ */

#endif /*  __CUSTOM_CLOUD_CONFIG_H__ */
