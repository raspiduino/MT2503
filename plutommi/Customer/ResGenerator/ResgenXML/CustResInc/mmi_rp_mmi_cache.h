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
*  mmi_rp_mmi_cache.h
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
 * removed!
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/

#ifndef MMI_RP_MMI_CACHE_H
#define MMI_RP_MMI_CACHE_H

#define MMI_CACHE_SIZE   504  /* should be sync with NVRAM_MMI_CACHE_SIZE  in nvram_common_defs.h */

typedef enum
{
    MMI_RP_MMI_CACHE_TYPE_BYTE,
    MMI_RP_MMI_CACHE_TYPE_SHORT,
    MMI_RP_MMI_CACHE_TYPE_DOUBLE,
    MMI_RP_MMI_CACHE_TYPE_MAX
} mmi_rp_mmi_cache_type;

typedef enum
{
    MMI_RP_MMI_CACHE_REPLACE_LEVEL_NORMAL,
    MMI_RP_MMI_CACHE_REPLACE_LEVEL_CUSTOM,
    MMI_RP_MMI_CACHE_REPLACE_LEVEL_MAX
} mmi_rp_mmi_cache_replace_level;

typedef struct _mmi_rp_mmi_cache_option_struct
{
    kal_char                *hint;
    kal_uint8               value[8];
    struct _mmi_rp_mmi_cache_option_struct *next;
} mmi_rp_mmi_cache_option_struct;

#define MMI_RP_MMI_CACHE_MIN_DEFAULT 0x80000000
#define MMI_RP_MMI_CACHE_MAX_DEFAULT 0x7FFFFFFF

typedef struct _mmi_rp_mmi_cache_field_struct
{
    kal_char *name;
    kal_int32 size;
    kal_int32 min;
    kal_int32 max;
    kal_uint8 min_array[8];
    kal_uint8 max_array[8];
    mmi_rp_mmi_cache_option_struct *option_list_head;
    mmi_rp_mmi_cache_option_struct *option_list_tail;
    struct _mmi_rp_mmi_cache_field_struct *next;
} mmi_rp_mmi_cache_field_struct;

typedef struct _mmi_rp_mmi_cache_data_struct
{
    mmi_rp_mmi_cache_type   type;
    kal_uint16              id;
    kal_uint16              sorted_id;
    kal_uint32              unique_key;
    kal_char                *id_str;
    kal_char                *restore_id_str;
    kal_char                *description;
    kal_bool                restore_flag;
    kal_uint8               default_value[8];
    struct _mmi_rp_mmi_cache_data_struct *restore_data;
    struct _mmi_rp_mmi_cache_data_struct *next;
    kal_uint32 total_field_size;
    mmi_rp_mmi_cache_field_struct *field_list_head;
    mmi_rp_mmi_cache_field_struct *field_list_tail;
    mmi_rp_mmi_cache_replace_level replace_level;
} mmi_rp_mmi_cache_data_struct;

typedef struct
{
    kal_uint32                      total_count;
    kal_uint16                      max_enum_id;
    mmi_resource_base_struct        *app;
    mmi_rp_mmi_cache_data_struct    *cache_data_head;
    mmi_rp_mmi_cache_data_struct    *cache_data_tail;
} mmi_rp_mmi_cache_app_struct;

typedef struct
{
    mmi_rp_mmi_cache_app_struct *app_cache_data;
    mmi_rp_hash_struct *str_id_hash;
    mmi_rp_hash_struct *replace_str_id_hash;
    kal_int32 cache_number[MMI_RP_MMI_CACHE_TYPE_MAX];
    mmi_rp_mmi_cache_data_struct *sort_table[MMI_RP_MMI_CACHE_TYPE_MAX][MMI_CACHE_SIZE];
    mmi_rp_mmi_cache_app_struct *curr_app_cntx;
} mmi_rp_mmi_cache_cntx_struct;

#define MMI_RP_MMI_CACHE_TAG_CACHEDATA "CACHEDATA"
    #define MMI_RP_MMI_CACHE_ATTR_TYPE "type"
        #define MMI_RP_MMI_CACHE_VAL_BYTE "byte"
        #define MMI_RP_MMI_CACHE_VAL_SHORT "short"
        #define MMI_RP_MMI_CACHE_VAL_DOUBLE "double"
    #define MMI_RP_MMI_CACHE_ATTR_ID "id"
    #define MMI_RP_MMI_CACHE_ATTR_RESTORE_FLAG "restore_flag"
        #define MMI_RP_MMI_CACHE_VAL_TRUE "true"
        #define MMI_RP_MMI_CACHE_VAL_FALSE "false"
    #define MMI_RP_MMI_CACHE_ATTR_RESTORE_ID "restore_id"
    #define MMI_RP_MMI_CACHE_ATTR_REPLACE_LEVEL "replace_level"
        #define MMI_RP_MMI_CACHE_VAL_CUSTOM "custom"
#define MMI_RP_MMI_CACHE_TAG_DEFAULT_VALUE "DEFAULT_VALUE"
#define MMI_RP_MMI_CACHE_TAG_DESCRIPTION "DESCRIPTION"
#define MMI_RP_MMI_CACHE_TAG_FIELD "FIELD"
    #define MMI_RP_MMI_CACHE_ATTR_NAME "name"
    #define MMI_RP_MMI_CACHE_ATTR_SIZE "size"
    #define MMI_RP_MMI_CACHE_ATTR_MAX "max"
    #define MMI_RP_MMI_CACHE_ATTR_MIN "min"
#define MMI_RP_MMI_CACHE_TAG_MINIMUM "MINIMUM"
#define MMI_RP_MMI_CACHE_TAG_MAXIMUM "MAXIMUM"
#define MMI_RP_MMI_CACHE_TAG_LESSTHAN "LESSTHAN"
#define MMI_RP_MMI_CACHE_TAG_MORETHAN "MORETHAN"
#define MMI_RP_MMI_CACHE_TAG_OPTION "OPTION"
    #define MMI_RP_MMI_CACHE_ATTR_HINT "hint"


extern void mmi_rp_mmi_cache_init(void);
extern void mmi_rp_mmi_cache_set_app_range(void);

extern int mmi_rp_mmi_cache_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mmi_cache_end_handler(void *data, const kal_char *el);
extern int mmi_rp_mmi_cache_default_value_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mmi_cache_default_value_end_handler(void *data, const kal_char *el);
extern int mmi_rp_mmi_cache_default_value_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);
extern int mmi_rp_mmi_cache_description_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mmi_cache_description_end_handler(void *data, const kal_char *el);
extern int mmi_rp_mmi_cache_description_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);
extern int mmi_rp_mmi_cache_field_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mmi_cache_field_end_handler(void *data, const kal_char *el);
extern int mmi_rp_mmi_cache_field_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);
extern int mmi_rp_mmi_cache_option_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mmi_cache_option_end_handler(void *data, const kal_char *el);
extern int mmi_rp_mmi_cache_option_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern int mmi_rp_mmi_cache_minimum_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mmi_cache_minimum_end_handler(void *data, const kal_char *el);
extern int mmi_rp_mmi_cache_minimum_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern int mmi_rp_mmi_cache_maximum_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mmi_cache_maximum_end_handler(void *data, const kal_char *el);
extern int mmi_rp_mmi_cache_maximum_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern int mmi_rp_mmi_cache_lessthan_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mmi_cache_lessthan_end_handler(void *data, const kal_char *el);
extern int mmi_rp_mmi_cache_lessthan_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern int mmi_rp_mmi_cache_morethan_start_handler(void *data, const kal_char *el, const kal_char **attr);
extern int mmi_rp_mmi_cache_morethan_end_handler(void *data, const kal_char *el);
extern int mmi_rp_mmi_cache_morethan_data_handler(void *resv, const kal_char *el, const kal_char *data, kal_int32 len);

extern void mmi_rp_mmi_cache_filter(void);

extern void mmi_rp_mmi_cache_output_phase1(void);
extern void mmi_rp_mmi_cache_output_phase2(void);

#endif /* MMI_RP_MMI_CACHE_H */
