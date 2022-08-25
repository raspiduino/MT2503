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
*  mmi_rp_mem_config.h
*
* Project:
* --------
*   Resgen XML header file of memory config resource
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef RESXML_MEM_CONFIG_H
#define RESXML_MEM_CONFIG_H


#include "MMIDataType.h"


#define MMI_RP_MEM_CONFIG_FILE_NAME_DATA_H   "mmi_rp_app_data.h" 
#define MMI_RP_MEM_CONFIG_HEADER_GUARD_DATA_H   "_MMI_RP_APP_DATA_H" 
#define MMI_RP_MEM_CONFIG_FILE_NAME_DATA_C   "mmi_rp_app_data.c"
#define MMI_RP_MEM_CONFIG_FILE_NAME_MEM_CONFIG_H   "mmi_rp_app_mem_config.h"
#define MMI_RP_MEM_CONFIG_HEADER_GUARD_MEM_CONFIG_H   "_MMI_RP_APP_MEM_CONFIG_H" 

#define MMI_RP_MEM_CONFIG_FILE_LOG   "resgen_xml_app_heap_size.log"

#define MMI_RP_MEM_CONFIG_CONC_APP_DELIM    '#'

typedef struct
{
    U32 count;
    U8 **str_apps;
    U8 **str_apps_converted;
}mmi_rp_mem_config_concurrent_apps_struct;

typedef struct
{
    U8 *str_heap_size;
    U8 *str_cuidep;
    MMI_BOOL is_cui;
    MMI_BOOL filter;                    /* filter-out -> MMI_FALSE, filter-in -> MMI_TRUE */
}mmi_rp_mem_config_data_struct;

typedef struct
{
    mmi_rp_mem_config_data_struct *app_mem_config_data;
    mmi_rp_mem_config_concurrent_apps_struct concurrent_apps;
    mmi_rp_hash_struct *hash;
}mmi_rp_mem_config_cntx_struct;

extern void mmi_rp_mem_config_init(void);

extern int mmi_rp_mem_config_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mem_config_end_handler(void *data, const kal_char *el);

extern int mmi_rp_appconcurrent_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_appconcurrent_end_handler(void *data, const kal_char *el);

extern void mmi_rp_mem_config_output_phase(void);

#endif /* RESXML_MEM_CONFIG_H */
