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

#ifndef MMI_RP_CALLBACK_MGR_H
#define MMI_RP_CALLBACK_MGR_H

/* Define your Tag here */
#define MMI_RP_CB_MGR_SENDER_TAG   "SENDER"
#define MMI_RP_CB_MGR_RECIEVER_TAG "RECEIVER"
#define MMI_RP_CB_MGR_RECIEVER_TAG_OLD "RECIEVER"

///TODO: define your tag here

extern int mmi_rp_callback_mgr_sender_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_callback_mgr_sender_end_handler(void *data, const kal_char *el);
extern int mmi_rp_callback_mgr_reciever_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_callback_mgr_reciever_end_handler(void *data, const kal_char *el);
extern void mmi_rp_callback_mgr_init(void);
extern void mmi_rp_callback_mgr_set_app_range(void);
extern void mmi_rp_callback_mgr_filter(void);
extern void mmi_rp_callback_mgr_output_phase1(void);
extern void mmi_rp_callback_mgr_output_phase2(void);
#endif /* MMI_RP_CUST_TEMPLATE_H */
