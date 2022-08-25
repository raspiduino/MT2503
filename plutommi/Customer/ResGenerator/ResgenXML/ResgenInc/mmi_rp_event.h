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
*  mmi_rp_event.h
*
* Project:
* --------
*   Resgen XML header file of event resource
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef RESXML_EVENT_H
#define RESXML_EVENT_H


#include "MMIDataType.h"


#define MMI_RP_EVENT_TYPE_LOGE_FILE_NAME "resgen_xml_event_type.log"

typedef enum 
{
    MMI_RP_EVENT_TYPE_NONE,
    MMI_RP_EVENT_TYPE_SENDER,
    MMI_RP_EVENT_TYPE_TOTAL,
}mmi_rp_event_type_enum;

typedef struct
{
    U8 *event_id_str;
    MMI_BOOL filter;                    /* filter-out -> MMI_FALSE, filter-in -> MMI_TRUE */
}mmi_rp_event_id_struct;

typedef struct
{
    U32 total_count;
    mmi_rp_event_id_struct *events;
}mmi_rp_event_data_struct;

typedef struct
{
    mmi_rp_event_data_struct *app_event_data;
    mmi_rp_hash_struct *hash;
}mmi_rp_event_cntx_struct;

typedef struct _mmi_rp_event_type_list_node_struct
{
    U8 *id_str;
    U8 *filename;
    struct _mmi_rp_event_type_list_node_struct *next;
    mmi_rp_event_type_enum type;
}mmi_rp_event_type_list_node_struct;


extern void mmi_rp_event_init(void);
extern void mmi_rp_event_set_app_range(void);

extern int mmi_rp_event_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_event_end_handler(void *data, const kal_char *el);
extern int mmi_rp_event_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern void mmi_rp_event_filter(void);

extern void mmi_rp_event_output_phase1(void);
extern void mmi_rp_event_output_phase2(void);

#endif /* RESXML_EVENT_H */
