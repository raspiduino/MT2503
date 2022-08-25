/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "ThemeResProt.h"

<?xml version = "1.0" encoding = "UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id = "SRV_VENUS_THEME" name="Venus_Theme">

#if defined(__MMI_RES_THEME_CACHE_FROM_ASM__)
    <MEMORY extra_base = "MMI_RES_THEME_DLT_POOL" inc="ThemeResProt.h"/>
#endif /* defined(__MMI_RES_THEME_CACHE_FROM_ASM__) */

</APP>

