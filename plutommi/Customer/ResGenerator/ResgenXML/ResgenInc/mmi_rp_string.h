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
*  mmi_rp_string.h
*
* Project:
* --------
*   Resgen XML header file of string resource
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef RESXML_STRING_H
#define RESXML_STRING_H


#include "MMIDataType.h"


#define MMI_RP_STR_MAX_STRING_LEN   512

typedef struct
{
    U8 *string_id_str;
    U8 *string_data_str;
    mmi_rp_scope_enum scope;
    MMI_BOOL filter;                    /* filter-out -> MMI_FALSE, filter-in -> MMI_TRUE */
}mmi_rp_str_id_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_str_id_struct *strings;
}mmi_rp_str_data_struct;

typedef struct
{
    mmi_rp_str_data_struct *app_str_data;
    mmi_rp_hash_struct *hash;
}mmi_rp_str_cntx_struct;

extern void mmi_rp_str_init(void);
extern void mmi_rp_str_set_app_range(void);

extern int mmi_rp_str_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_str_end_handler(void *data, const kal_char *el);
extern int mmi_rp_str_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern U8* mmi_rp_str_add_app_name_str_id(const U8* str_name_id);

extern void mmi_rp_str_filter(void);

extern void mmi_rp_str_output_phase1(void);
extern void mmi_rp_str_output_phase2(void);

#endif /* RESXML_STRING_H */
