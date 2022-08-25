#include "MMI_features.h"

#ifdef __MMI_MEDIA_PLAYER__
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_MEDPLY_SINGLE" name = "STR_ID_MEDPLY_SINGLE_APP" type="pluto">

		<STRING id="STR_ID_MEDPLY_SINGLE_APP"/>
    <MEMORY heap= "0" extra_base="max3(base(SRV_MDI_AUDPLY)+base(SRV_MDI_AUD_INFO), base(SRV_MDI_VDOPLY_SUBTITLE), base(SRV_MDI_STREAMING))" fg="MEDPLY_MAIN_SCREEN_SCR_MEM_SIZE + max3(fg(SRV_MDI_AUDPLY), fg(SRV_MDI_VDOPLY_SUBTITLE), fg(SRV_MDI_STREAMING))" inc="MediaplayerGprot.h"/> 

</APP>

#endif