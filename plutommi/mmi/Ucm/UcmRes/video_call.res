#include "MMI_features.h"

#if defined(__MMI_VIDEO_TELEPHONY__)
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_VT_CALL" name = "STR_ID_VIDEO_CALL" type="pluto">

		<STRING id="STR_ID_VIDEO_CALL"/>
    <MEMORY heap= "0" extra_base="$(MMI_VTCS_ENCODE_BUF_SIZE)+ base(SRV_MDI_VT)" fg="$(MMI_VTCS_APP_MEMORY_POOL)+ fg(SRV_MDI_VT)" inc="UcmVtCallScrGProt.h"/>

</APP>

#endif