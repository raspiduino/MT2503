#ifdef __EMAIL__

#include "customer_ps_inc.h"
#include "kal_general_types.h"
#include "MMI_features.h"

#ifdef __MMI_EMAIL_IMAP_PUSH__
#define EMAIL_PS_MEM_FOR_IMAP_PUSH (25 * 1024)
#else
#define EMAIL_PS_MEM_FOR_IMAP_PUSH (0)
#endif 

#ifdef __COSMOS_MMI_PACKAGE__
#define EMAIL_PS_MEM_BASE     (55 * 1024)
#else
#define EMAIL_PS_MEM_BASE     (30 * 1024)
#endif

#define EMAIL_MEM_POOL_SIZE (EMAIL_PS_MEM_BASE + EMAIL_PS_MEM_FOR_IMAP_PUSH)

/* the email pool array for PS */
kal_uint32 g_email_mem_pool[(EMAIL_MEM_POOL_SIZE + 3) / 4]; 

kal_bool email_get_mem_pool(void **mem_addr, kal_uint32 *size)
{
    if (mem_addr == NULL || size == NULL)
    {
        return KAL_FALSE;
    }
    
    *mem_addr = (void*)g_email_mem_pool;
    *size = sizeof(g_email_mem_pool);
    return KAL_TRUE;
}


kal_bool custom_email_using_card_memory(void)
{
#if (defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__))
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}


#endif /* __EMAIL__ */

