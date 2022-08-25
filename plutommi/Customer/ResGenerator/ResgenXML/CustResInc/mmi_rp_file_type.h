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
*  mmi_rp_cust_file_type.h
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
 *
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef MMI_RP_FILE_TYPE_H
#define MMI_RP_FILE_TYPE_H

/* Define your Tag here */
#define MMI_RP_MGR_TAG_FILE_TYPE_BASE   "FILE_TYPES"
#define MMI_RP_MGR_TAG_FILE_TYPE_INC    "FILE_TYPE_INC"
#define MMI_RP_MGR_TAG_FILE_TYPE        "FILE_TYPE"
#define MMI_RP_MGR_TAG_FILE_GROUP_TYPE  "FILE_GROUP_TYPE"
#define MMI_RP_MGR_TAG_FILE_OPTION_HDLR "FILE_OPTION_HDLR"
#define MMI_RP_MGR_TAG_FILE_TYPE_DEC    "FILE_TYPE_DEC"

extern void mmi_rp_file_type_init(void);
extern void mmi_rp_file_type_set_app_range(void);

extern void mmi_rp_file_type_filter(void);

extern void mmi_rp_file_type_output_phase1(void);
extern void mmi_rp_file_type_output_phase2(void);

/* FILE_TYPES */
extern int mmi_rp_fts_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_fts_end_handler(void *data, const kal_char *el);

/* FILE_TYPE_INC */
extern int mmi_rp_file_type_inc_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_file_type_inc_end_handler(void *data, const kal_char *el);

/* FILE_TYPE */
extern int mmi_rp_file_type_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_file_type_end_handler(void *data, const kal_char *el);

/* FILE_GROUP_TYPE */
extern int mmi_rp_file_group_type_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_file_group_type_end_handler(void *data, const kal_char *el);

/* FILE_TYPE_DEC */
extern int mmi_rp_file_type_dec_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_file_type_dec_end_handler(void *data, const kal_char *el);

/* FILE_OPTION_HDLR */
extern int mmi_rp_file_opt_hdlr_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_file_opt_hdlr_end_handler(void *data, const kal_char *el);

#endif /* MMI_RP_CUST_TEMPLATE_H */
