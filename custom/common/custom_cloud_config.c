#include "MMI_features.h"
#include "DebugInitDef_Int.h"
#include "custom_cloud_config.h"
#include "nvram_common_defs.h"
#include "EmailSrvGprot.h"

#ifdef __MMI_SSO__
kal_bool custom_cloud_using_card_memory(void)
{
    return KAL_TRUE;
}
#endif

#ifdef __CLOUD_SUPPORT__
/*
 * Used to prevent NVRAM  LID shifting when re-config feature options.
 */
kal_uint16 custom_cloud_get_nvram_lid(srv_cloud_nvram_lid_enum nvram_lid_type)
{
    kal_uint16 result = NULL;
    switch(nvram_lid_type)
    {
    #ifdef __SMS_CLOUD_SUPPORT__
        case SRV_CLD_NVRAM_EF_SMS_USED_NUM_LID:
        {
            result = NVRAM_EF_SMS_USED_NUM_LID;
            break;
        }

        case SRV_CLD_NVRAM_EF_SMS_UID_COUNT_LID:
        {
            result = NVRAM_EF_SMS_UID_COUNT_LID;
            break;
        }

        case SRV_CLD_NVRAM_EF_CLOUD_SMS_ITEM_LID:
        {
            result = NVRAM_EF_CLOUD_SMS_ITEM_LID;
            break;
        }
    #endif

    #ifdef __VCARD_CLOUD_SUPPORT__
        case SRV_CLD_NVRAM_EF_VCRD_USED_NUM_LID:
        {
            result = NVRAM_EF_VCRD_USED_NUM_LID;
            break;
        }

        case SRV_CLD_NVRAM_EF_VCRD_UID_COUNT_LID:
        {
            result = NVRAM_EF_VCRD_UID_COUNT_LID;
            break;
        }

        case SRV_CLD_NVRAM_EF_CLOUD_VCRD_ITEM_LID:
        {
            result = NVRAM_EF_CLOUD_VCRD_ITEM_LID;
            break;
        }
        
        case SRV_CLD_NVRAM_EF_VCRD_UID_LIST_URL_LID:
        {
            result = NVRAM_EF_VCRD_UID_LIST_URL_LID;
            break;
        }

        case SRV_CLD_NVRAM_EF_VCRD_IS_CHANGE_LID:
        {
            result = NVRAM_EF_VCRD_IS_CHANGE_LID;
            break;
        }
    #endif

        default:
        {
            // Would not go to here
            MMI_ASSERT(0);
            break;
        }
    }
    
    return result; 
}

/*
 * Used to prevent res ID shifting when re-config feature options.
 */
kal_uint16 g_SMS_PHONE_ENTRY = SMS_PHONE_ENTRY;
kal_uint16 g_MAX_PHB_PHONE_ENTRY = MAX_PHB_PHONE_ENTRY;

#endif /* __CLOUD_SUPPORT__ */
