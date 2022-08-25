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
*  mmi_rp_cust_template.h
*
* Project:
* --------
*   Template of Resgen XML header file
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
 * removed!
 *
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef MMI_RP_CUST_TEMPLATE_H
#define MMI_RP_CUST_TEMPLATE_H

/* Define your Tag here */
#define MMI_RP_MGR_TAG_TEMPLATE "TEMPLATE"
///TODO: define your tag here

extern void mmi_rp_template_init(void);
extern void mmi_rp_template_set_app_range(void);

extern int mmi_rp_template_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_template_end_handler(void *data, const kal_char *el);
extern int mmi_rp_template_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern void mmi_rp_template_filter(void);

extern void mmi_rp_template_output_phase1(void);
extern void mmi_rp_template_output_phase2(void);

#endif /* MMI_RP_CUST_TEMPLATE_H */
