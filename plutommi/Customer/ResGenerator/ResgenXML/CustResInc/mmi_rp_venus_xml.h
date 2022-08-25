/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
*
*****************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  mmi_rp_venux_xml.h
*
* Project:
* --------
*   "Venux XML Tags" of Resgen XML header file
*
* Description:
* ------------
*
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef MMI_RP_VENUX_XML_H
#define MMI_RP_VENUS_XML_H

/* Define your Tag here */
#define MMI_RP_MGR_TAG_VENUS_LAYOUT "LAYOUT"

#define MMI_RP_MGR_ATTR_VENUS_NAME  "file"

extern void mmi_rp_vxml_init(void);
extern void mmi_rp_vxml_set_app_range(void);

extern void mmi_rp_vxml_filter(void);

extern void mmi_rp_vxml_output_phase1(void);
extern void mmi_rp_vxml_output_phase2(void);

extern int mmi_rp_venus_layout_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_venus_layout_end_handler(void *data, const kal_char *el);

#endif /* MMI_RP_CUST_TEMPLATE_H */
