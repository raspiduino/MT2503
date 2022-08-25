#if defined(__MMI_VECTOR_FONT_SUPPORT__)

#include "MMI_features.h"
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
#define MMI_FE_EXT_RESOURCE_NUM 14
#else
#define MMI_FE_EXT_RESOURCE_NUM 0
#endif

#else
#define MMI_FE_EXT_RESOURCE_NUM 0
#endif
