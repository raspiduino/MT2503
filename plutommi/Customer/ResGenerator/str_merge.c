/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * str_merge.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Merge multi-language string table, and generate string resource files.
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
 *             HISTORY
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
 *
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <tchar.h>
#include <unistd.h>

#include "MMI_features.h"
#include "MMIDataType.h"
#include "FontRes.h"
#include "CustDataRes.h"
#include "CustResDef.h"

#include "FontDcl.h"
#include "str_merge_public.h"
#include "ResgenLogCAPI.h"
#include "ResgenCatUtilCAPI.h"
// Global Configuration of MMIResource Compression
// You can config the compression in this header file
#include "ResCompressConfig.h"


/*
To define the following macro variable to enable/disable function as following:
(1) MEM_REF_LIST_OPT: To reduce the REF LIST buffer memory requirement 
(2) STR_MERGE_DEBUG: Show extra debuging infomation
(3) DEBUG_REF_LIST_DUMP: dump ref list processed to the following path :
     debug\ref_all_dump.txt: ref_all loaded in memory
     debug\ref_all_merged_dump.txt : processing result of ref_all in memory
(4) MEM_LIST_INFO_STATS: Show length statistic information of string lines in REF LIST file
*/


/* Memory optimization for loading ref list */
#define MEM_REF_LIST_OPT


/* Statistic of memory usage of string lines in ref lists */
/* #define MEM_LIST_INFO_STATS */

/* Show debug message and dump processed ref list to files*/
#define STR_MERGE_DEBUG

#define STRMERG_TAG       "STR_MERGE"
#define STRMERG_SUB_TAG_MEM     "[MEM]"

#define STRMERG_LOG_D(format, args...) RES_LOG_D((STRMERG_TAG), (format) , ##args)
#define STRMERG_LOG_V(format, args...) RES_LOG_V((STRMERG_TAG), (format) , ##args)
#define STRMERG_LOG_W(format, args...) RES_LOG_W((STRMERG_TAG), (format) , ##args)
#define STRMERG_LOG_E(format, args...) RES_LOG_E((STRMERG_TAG), (format) , ##args)

#define STRMERG_WLOG_D(format, args...) RES_WLOG_D((STRMERG_TAG), (format) , ##args)
#define STRMERG_WLOG_V(format, args...) RES_WLOG_V((STRMERG_TAG), (format) , ##args)
#define STRMERG_WLOG_W(format, args...) RES_WLOG_W((STRMERG_TAG), (format) , ##args)
#define STRMERG_WLOG_E(format, args...) RES_WLOG_E((STRMERG_TAG), (format) , ##args)

#ifdef MEM_REF_LIST_OPT
#define REF_LIST_SIZE_INCREMENT 500
#define REF_LIST_DEFAULT_SIZE 15000
#endif /*MEM_REF_LIST_OPT*/

#ifdef MEM_LIST_INFO_STATS
#define MEM_STATS_ITEM_MAX 5
#define MEM_STATS_ITEM_LENGTH 5000
#endif /*MEM_LIST_INFO_STATS*/

#ifdef DEBUG_REF_LIST_DUMP
#define REFLISST_DUMP_FILE_BEFOR_MERGE   "..\\..\\Customer\\ResGenerator\\debug\\ref_all_dump.txt"
#define REFLISST_DUMP_FILE_AFTER_MERGE   "..\\..\\Customer\\ResGenerator\\debug\\ref_all_merged_dump.txt"
#endif /* DEBUG_REF_LIST_DUMP */


#ifdef DEVELOPER_BUILD_FIRST_PASS
#define ASSERT(expr) {if(!(expr)) {while(1);}else {}}
#endif

#define STR_RESOURCE_MAX_SYMBOL_LEN 128

#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
#include "Zlib.h"
#include "StringCompressionBufferCAPI.h"
#endif

/* #define __TIME_CONSUME for calculating execution time */
#ifdef __TIME_CONSUME
#include <time.h>
#endif

/* max string length for each language */
#define MAX_LENGTH      512
/* string length for temp buffer */
#define TMP_BUF_LENGTH  1024

#ifdef __IOT__
    #define ref_file        "..\\custresource\\ref_list_empty.txt"
#else /*__IOT__*/
#define ref_file        "..\\custresource\\ref_list.txt"
#endif /*__IOT__*/

#ifndef __OPTR_NONE__
/* max SSC length */
#define SSC_LENGTH      16
/* ref_list.txt customized for operator */
#ifdef __OP_TECH_REL__
/* under construction !*/
#else
#define optr_ref_file   "operator_ref_list.txt"
#endif
#endif

/* this marker indicates using English as string translation */
#define NO_TRANSLATION_MARKER   19


/* Retry count of memory allocation */
#define MEM_RETRY_COUNT_MAX 15

/* Time interval of memory allocation retry*/
#define MEM_RETRY_TIME_INTERVAL_SEC 60


#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
#define ENFB_STRING_DATA_FILENAME  "..\\..\\Customer\\CustResource\\CustENFBStrData"
#define ENFB_STRING_HEADER_FILENAME  "..\\..\\Customer\\CustResource\\CustENFBStr.h"
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */



#ifdef MEM_REF_LIST_OPT

typedef struct RefListItem
{
    /* String line */
    wchar_t *ItemData;
    /* Data Length in bytes */
    int ItemSize;
} RefListItem;

typedef struct RefList
{
    /* List items */
    RefListItem** ListItems;
    /* Length of List items in elements*/
    int ListLength;
    /* Capacity of List items in elements*/
    int Size;
    /* Allocated memory for the content in bytes*/
    unsigned long AllocatedSize;
} RefList;

#endif /*MEM_REF_LIST_OPT*/

typedef struct StrRes
{
    wchar_t **Str;      /* pointer array of lists to store Strings */
    int *StrRef;        /* pointers of Reference id in hash table of each string */
    int MaxID;          /* Maximum number of string ids */
    int MaxNum;         /* Maximum number of strings */
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    char *is_dup;       /* flag to specify whether this string is duplicated */    
#endif
    int TotalLength;
} StrRes;

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
typedef struct DupStrRes
{
    wchar_t **Str;      /* pointer array of lists to store Strings */
    int MaxNum;         /* Maximum number of duplicated strings in different language */        
} DupStrRes;
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

typedef struct StrResSet
{
    struct StrRes *strres;
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    struct DupStrRes *strres_dup;    /* field for duplicated string resource */
#endif
    int iLang;
} StrResSet;

typedef struct HashItem
{
    int pointer;        /* index in string array */
    struct HashItem *next;
} HashItem;

extern const U8 mmi_res_zip_language[MAX_LANGUAGES+1];
extern U8 StrIsPopulate[MAX_STRING_MAP_SIZE];
extern U8 *StrEnum[MAX_STRING_MAP_SIZE];
extern U8 *Str[MAX_STRING_MAP_SIZE];
extern U16 CurrMaxStringId;

typedef struct StrIDNode{
    wchar_t *str; /* we will not malloc for this string */
    U16 id;
    struct StrIDNode *next;
}StrIDNode;

typedef struct StrHashTable{
    int table_size;
    StrIDNode **table;
}StrHashTable;


#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
#define FIXED_INVALID_FLAG    0
#define NO_TRANSLATE_FLAG     1
#define TRANSLATE_FLAG        2

/* fixed string log file */
#define FIXED_STRING_LOG    "..\\..\\Customer\\ResGenerator\\debug\\no_translate_string.txt"

typedef struct FixedID{
    U16 id_count;                          /* fixed id count */
    U8 *fixed_id_flag; /* flag to indicate if id is fixed language or not */
    StrHashTable *enum_id_tb;               /* ID_Enum & ID pair */
    StrHashTable *str_id_tb;                /* str & ID pair */
}FixedID;

typedef struct FixedResult{
    U16 nTotalStrRes;
    MMI_BOOL is16bit;
#ifdef __MMI_RESOURCE_STR_ZLIB_COMPRESS__
    U32 nResSize;
    U32 nResZipSize;
    U32 nMapSize;
    U32 nMapZipSize;
#endif /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
}FixedResult; /* result data structure */

/* extern U16 CurrMaxStringId */
U16 CurrMaxTransStrId = 0; /* total count of populated string id with translation */

/* fixed id data */
FixedID fixed_id;

/* fixed id parse result */
FixedResult fixed_result;

/* record string merge result */

static int str_merge_err_code = STRMERGE_NO_ERR;
static wchar_t str_merge_err_msg[STRMERGE_ERR_MSG_LEN_MAX+1] = L"";

void str_merge_set_err(int err_code, wchar_t * msg){
	str_merge_err_code = err_code;
	wcsncpy(str_merge_err_msg,msg, STRMERGE_ERR_MSG_LEN_MAX);
}

int str_merge_get_err(wchar_t ** msg){
	if(str_merge_err_code != STRMERGE_NO_ERR){
		*msg = str_merge_err_msg;
	}
	return str_merge_err_code;
}

#ifdef MEM_REF_LIST_OPT
/*****************************************************************************
 * FUNCTION
 *  CreateRefList
 * DESCRIPTION
 *  Create RefList to save variable size items in a ref list 
 * PARAMETERS
 *  listSize: the list size in elements 
 * RETURNS
 *  return RefList object with size listSize
 *****************************************************************************/
 
static RefList* CreateRefList(int listSize);

/*****************************************************************************
 * FUNCTION
 *  DeleteRefList
 * DESCRIPTION
 *  To delete a RefList obecjt. This operator will free all the list items and
 *  their datas automatically, 
 * PARAMETERS
 *  list: the Ref List to be destroyed
 * RETURNS
 *   NA
 *****************************************************************************/
static void DeleteRefList(RefList * list);


/*****************************************************************************
 * FUNCTION
 *  CreateListItemFromStr
 * DESCRIPTION
 *  Create a ref item object with a string line with cloning approach.
 * PARAMETERS
 *  str: the string content used to create the ref list item object.
 * RETURNS
 *   A created RefListItem object, return NULL if the object creation failed
 *****************************************************************************/
/* Create a ref item object with a string line */
static RefListItem* CreateListItemFromStr(wchar_t * str);

/*****************************************************************************
 * FUNCTION
 *  AddRefListItem
 * DESCRIPTION
 *  Add an item form a ref list
 * PARAMETERS
 *  list: ref list object
 *  item: the ref list item to be added to ref list
 * RETURNS
 *   An int value indicated the position of the item in the ref list. Return
 *   -1 indicate that the operation is failed
 *****************************************************************************/
static int AddRefListItem(RefList * list, RefListItem* item);

/*****************************************************************************
 * FUNCTION
 *  GetRefListItem
 * DESCRIPTION
 *  Get an item from a ref list
 * PARAMETERS
 *  list: ref list object
 *  index: the posotion of the item in this ref list
 * RETURNS
 *   Return the item obecjt in the position assigned; return NULL if it is 
 *   not found
 *****************************************************************************/
static RefListItem* GetRefListItem(RefList * list, int index);

/*****************************************************************************
 * FUNCTION
 *  SetRefListItem
 * DESCRIPTION
 *  Set a list item, the old item is free by this function automatically
 * PARAMETERS
 *  list: ref list object
 *  index: the specified posotion of the item in this ref list
 *  item: the item to be set to the specified position
 * RETURNS
 *   0 means that the set operation is successful or the operation is 
 *   failed
 *****************************************************************************/
#endif /*MEM_REF_LIST_OPT*/


#ifdef STR_MERGE_DEBUG
#ifndef MEM_REF_LIST_OPT
/*****************************************************************************
 * FUNCTION
 *  DumpRefList
 * DESCRIPTION
 *  Dump the old style ref list (array style) to a speficied file
 * PARAMETERS
 *  filename: the file name of the ref list dump
 *  list: ref list array
 *  ItemSize: the array element size in bytes
 *  count: the total count of the elements
 * RETURNS
 *   NA
 *****************************************************************************/

static void DumpRefList(const char* filename, wchar_t *list,const int ItemSize, int count);

#else /*MEM_REF_LIST_OPT*/

/*****************************************************************************
 * FUNCTION
 *  DumpRefList
 * DESCRIPTION
 *  Dump the ref list to a speficied file
 * PARAMETERS
 *  filename: the file name of the ref list dump
 *  list: ref list object
 * RETURNS
 *   NA
 *****************************************************************************/
static void DumpRefList(const char* filename, RefList *list);

#endif /*MEM_REF_LIST_OPT*/
#endif /* STR_MERGE_DEBUG */



/* fixed string main function */
static int generate_fixed_str(FILE *res, FILE *map, FILE * resMeta, FILE * mapMeta,FixedID *fixed);

static int init_fixed_id(FixedID *fixed, int table_size);
static int generate_enum_hash(StrHashTable *table, U8 *isPop, wchar_t *str[]);
static int write_fixed_str(FILE *res, FILE *map, FILE *resMeta, FILE *mapMeta,U8 *s, int pos, int *offs, int id);
static int write_fixed_str_offset(FILE *res, FILE *map, FILE *resMeta, FILE *mapMeta, U8 *s, int pos, int *offs, int id);
static int write_fixed_offset(FILE *res, FILE *map, FILE* resMeta, FILE *mapMeta, int pos, int *offs, int id);
static MMI_BOOL write_fixed_string_log(FILE *log, U16 id, U16 dup_id);
static int set_fixed_str_flag(FixedID *fixed, wchar_t* id);
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

static int generate_strmap_search(FILE *res, FILE *resMeta);

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
static MMI_BOOL generate_language_list_array(FILE *res, StrRes *strres, DupStrRes *strres_dup, int num_map_search, int max_total_len, U32 *res_size, U32 *map_size, U32 *reszip_size, U32 *mapzip_size);
#else
static MMI_BOOL generate_language_list_array(FILE *res, StrRes *strres, int num_map_search,U32 *res_size, U32 *map_size, U32 *reszip_size, U32 *mapzip_size);
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
/* get fontres data */
extern const U16 mtk_gMaxDeployedLangs;
extern const sLanguageDetails mtk_gLanguageArray[];

static const wchar_t *DELIMETER = L"\t";
static const wchar_t *EOS = L"\n";

static int *mtk_gLanguageFlag;

static MMI_BOOL *is16bit;
static U16 StrLine[MAX_STRING_MAP_SIZE];
static U16 StrSize[MAX_STRING_MAP_SIZE];
static U16 *StrID = NULL;
static U32 g_line_buf_length = 0;
/*only include populate languages length*/
static U32 g_line_buf_act_length = 0;

#ifndef MEM_REF_LIST_OPT
static wchar_t *ref_all = NULL;
#else  /*MEM_REF_LIST_OPT*/
/* Use vector to reduce the memory size of ref list buffer*/
static RefList *ref_all_list = NULL;
#endif /*MEM_REF_LIST_OPT*/

static wchar_t *ref_ssc = NULL;
static wchar_t *ref_tmp = NULL;
static int nLang = 0;

/*filtered ref ssc*/
static wchar_t *filter_ref_ssc = NULL; 
#ifndef __OPTR_NONE__
static wchar_t *optr_filter_ref_ssc = NULL;
#endif /*__OPTR_NONE__*/


/*deployed language*/
static U16 nUsedLang = 0;
static U16 *line_offset = NULL;



static int ifLanguageUsed(wchar_t *ssc_ref);



#ifdef __MMI_RESOURCE_STR_ZLIB_COMPRESS__

static void launchStrDeCompressionBufferCreator(StrRes *strres, DupStrRes *strres_dup,U32 *res_size, U32 *map_size){
    int i = 0;
    for (i = 0; i < mtk_gMaxDeployedLangs; i++)
    {
        int old_i = i;
        if (mtk_gLanguageFlag[i] == 0)
        {
            i = 0;
        }
        if(mmi_res_zip_language[i] == 1){
            StrDeCompressBufAddStrBuf(res_size[i], map_size[i], is16bit[i]);
        }
        i = old_i;
    }

    if (mmi_res_zip_language[MAX_LANGUAGES] == 1){
        // StrDeCompressionSetDupBuffer(int resSize);
        if (strres_dup->MaxNum > 0)
        {

            StrDeCompressBufSetDupStrBuf(res_size[511]);
        }
        else
        {
            StrDeCompressBufSetDupStrBuf(0);
        }
    }
    /* fixed string information */
    if(fixed_id.id_count > 0)
    {
        StrDeCompressBufSetFixedStrBuf(fixed_result.nResSize,
            fixed_result.nMapSize,
            fixed_result.is16bit);
    }else{

        StrDeCompressBufSetFixedStrBuf(0, 0, 0);
    }



}
#endif

/* This is simple hash operation for string merge application, in order to reduce memory and improve speed */
/*****************************************************************************
 * FUNCTION
 *  CreateHashTable
 * DESCRIPTION
 *  create a size hash table
 * PARAMETERS
 *  size    [IN] table size
 * RETURNS
 *  hash table pointer
 *****************************************************************************/
static StrHashTable* CreateHashTable(int size)
{
    if(size <= 0)
    {
        return 0;
    }

    StrHashTable *table = (StrHashTable *)malloc(sizeof(StrHashTable));
    if(table == 0)
    {
        return 0;
    }

    table->table_size = size;
    table->table = (StrIDNode **)malloc(sizeof(StrIDNode *) * size);
    if(table->table == 0)
    {
        return 0;
    }

    memset(table->table, 0, sizeof(StrIDNode *)*size);

    return table;
}


/*****************************************************************************
 * FUNCTION
 *  DJBHash
 *
 * DESCRIPTION
 *  DJB hash algrithom
 *
 * PARAMETERS
 *  key    [IN] key of hash algrithm input, here is special for wchar_t type
 *
 * RETURNS
 *  hash table pointer
 *****************************************************************************/
static int DJBHash(wchar_t* key) /* DJB hash */
{
    unsigned int hash = 5381;
    int i = 0;

    int len = wcslen(key);

    for(i = 0; i < len; ++i)
    {
        hash = ((hash << 5) + hash) + key[i];
    }

    return 0x7fffffff & hash;
}


/*****************************************************************************
 * FUNCTION
 *  hash_add
 * DESCRIPTION
 *  add node to hash table
 * PARAMETERS
 *  hash    [IN/OUT] : hash table
 *  node    [IN] : node to be added into hash table
 * RETURNS
 *  int       0 means duplicate node, 1 means add success, 
 *           -1 means allocate memory fail, -2 means invalid input
 *****************************************************************************/
static int hash_add(StrHashTable* hash, StrIDNode *node)
{
    int hv = -1;
    if(hash == NULL || node == NULL || node->str == NULL)
    {
        return -2; /* invalid input */
    }

    hv = DJBHash(node->str) % hash->table_size;

    if(hash->table[hv] == 0) /* hash node not exist */
    {
        StrIDNode *new_node = (StrIDNode *)malloc(sizeof(StrIDNode));
        if(new_node == 0)
        {
            return -1; /* invalid memory malloc */
        }
        /* initialize new node */
        new_node->next = NULL;
        new_node->id = node->id;
        new_node->str = node->str;

        /* add new node to hash table */
        hash->table[hv] = new_node;
    }
    else /* hash node exist */
    {
        StrIDNode *tmp = hash->table[hv];
        StrIDNode *prev = 0;
        while(tmp != NULL) /* here is hash search function */
        {
            prev = tmp;
            if(!wcscmp(node->str, prev->str))
            {
                break;
            }
            tmp = tmp->next;
        }
        /* does not found the same string node */
        if(tmp == NULL)
        {
            StrIDNode *new_node = (StrIDNode *)malloc(sizeof(StrIDNode));
            if(new_node == 0)
            {
                return -1; /* invalid malloc */
            }
            new_node->next = NULL;
            new_node->id = node->id;
            new_node->str = node->str;
            /* add new node to the chain list */
            prev->next = new_node;
        }
        else
        {
            return 0; /* duplicate string */
        }
    }
    return 1; /* add successfully */
}


/*****************************************************************************
 * FUNCTION
 *  hash_search
 * DESCRIPTION
 *  search if key exist in hash table
 * PARAMETERS
 *  hash    [IN] : hash table
 *  key      [IN] : key will be search
 * RETURNS
 *  int       true: find key in hash table, false:not found key in hash table
 *****************************************************************************/
static StrIDNode* hash_search(const StrHashTable* hash, const wchar_t *key)
{
    int hv = -1;
    int i = 0;
    StrIDNode *tmp = 0;

    if(key == 0 || hash == 0)
    {
        return 0;
    }

    hv = DJBHash(key) % hash->table_size; /* caculate hash value */

    tmp = hash->table[hv];
    while(tmp)
    {
        if(!wcscmp(key, tmp->str))
            return tmp;
        tmp = tmp->next;
    }

    return 0;    
}


/*****************************************************************************
 * FUNCTION
 *  hash_free
 * DESCRIPTION
 *  free hash table
 * PARAMETERS
 *  hash    [IN] : hash table
 * RETURNS
 *  void
 *****************************************************************************/
static void hash_free(StrHashTable* hash)
{
    int i = 0;
    StrIDNode *node = 0, *next = 0;;
    
    if(hash == NULL)
        return;

    /* free each node in hash table */
    for(i = 0; i < hash->table_size; ++i)
    {
        node = hash->table[i];
        while(node)
        {
            next = node->next;
            free(node);
            node = next;
        }
    }

    /* free hash table itself */
    free(hash);
}


/*****************************************************************************
 * FUNCTION
 *  UCS2ASCII
 * DESCRIPTION
 *  Convert wide character to ASCII character
 * PARAMETERS
 *  w_in    [IN]
 *  a_out   [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void UCS2ASCII(char *w_in, char *a_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (w_in[i * 2] != '\0' || w_in[i * 2 + 1] != '\0')
    {
        a_out[i] = w_in[i * 2];
        i += 1;
    }
    a_out[i] = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  GetItem
 * DESCRIPTION
 *  Get token between index and index+1 DELIMETER
 * PARAMETERS
 *  string  [IN]
 *  index   [IN]
 *  buf     [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void GetItem(wchar_t *string, int index, wchar_t *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wchar_t *p1 = string;
    wchar_t *p2 = wcsstr(string, DELIMETER);
    int n = p2 - p1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(p2 != NULL);
    
    while (index > 0)
    {
        p1 = p2 + 1;
        p2 = wcsstr(p1, DELIMETER);
        index--;
        if (p2 == NULL)
            break;
        n = p2 - p1;
    }

    if (index > 0)
    {
        buf[0] = L'\0';
    }
    else if (p2 == NULL)
    {
        if (p1 == NULL)
        {
            STRMERG_LOG_E("GetItem p1 == NULL");
            exit(2);
        }
        wcscpy(buf, p1);
        n = wcsstr(p1, EOS) - p1;
        buf[n] = L'\0';
        buf[n - 1] = L'\0';
    }
    else
    {
        ASSERT(p1 != NULL);
        wcsncpy(buf, p1, n);
        buf[n] = L'\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  OutputFixColumns
 * DESCRIPTION
 *  Output content of fix columns to temp buffer
 * PARAMETERS
 *  linebuf     [IN]
 *  token_id    [IN OUT]
 *  itembuf     [IN]
 *  log_output  [OUT]
 *  ref_output  [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void OutputFixColumns(wchar_t *linebuf, int *token_id, wchar_t *itembuf, 
                             wchar_t *log_output, wchar_t *ref_output)
{
    GetItem(linebuf, (*token_id)++, itembuf);
    wcscat(log_output, L"\t");
    wcscat(log_output, itembuf);            /* print out Module Name */

    GetItem(linebuf, (*token_id)++, itembuf);
    wcscat(log_output, L"\t");
    wcscat(log_output, itembuf);            /* print out Max String Length */

    /* will copy back to reference string table */
    wcscpy(ref_output, log_output);

    GetItem(linebuf, (*token_id)++, itembuf);
    wcscat(log_output, L"\t");
    wcscat(log_output, L"No Translation");  /* print out description */

    /* will copy back to reference string table */
    wcscat(ref_output, L"\t");
    wcscat(ref_output, itembuf);
}


/*****************************************************************************
 * FUNCTION
 *  GetLineBufLength
 * DESCRIPTION
 *  Find the max chars(including NULL char) of each line in ref_list, in order to reduce memory consumption
 * PARAMETERS
 *  void
 * RETURNS
 *  Max chars of each line in ref_list
 *****************************************************************************/
static int GetLineBufLength(FILE *ref_list_file, int lang_count)
{
    wchar_t *temp_buf = NULL; /* line buffer */
    int max_line_char_count; /* including NULL char */
    int max_line_buf_length = 0;
    int tmp;
    
#ifdef MEM_LIST_INFO_STATS
    int length_stats[MEM_STATS_ITEM_LENGTH] = {0};
    int length_index = 0;
#endif /*MEM_LIST_INFO_STATS*/

    /* 
     * calculate line buffer size 
     * here +2 for Description, and (Max String Length, MODULE, ENUM)
     */    
    max_line_char_count = (lang_count + 2) * MAX_LENGTH;
    temp_buf = (wchar_t *)malloc(max_line_char_count * sizeof(wchar_t));
    if (temp_buf == NULL)
    {
        STRMERG_LOG_E("memory not available!! GetLineBufLength");
        exit(2);
    }
    while (!feof(ref_list_file))
    {
        /* get a line of string */
        fgetws(temp_buf, max_line_char_count, ref_list_file);  
        tmp = wcslen(temp_buf) + 1;
        if (max_line_buf_length < tmp)
        {
            max_line_buf_length = tmp;    
        }

#ifdef MEM_LIST_INFO_STATS
    	/* Memory usage statistics of each language string line 
            in ref_list loaded
        */
	length_index = (int)(tmp/MEM_STATS_ITEM_LENGTH);
	if(length_index >= MEM_STATS_ITEM_MAX)
        {
	    length_index = MEM_STATS_ITEM_MAX-1;
        }
	length_stats[length_index]++;

        if(tmp > MEM_STATS_ITEM_LENGTH)
        {
            STRMERG_LOG_V("\n[%d]: %d\t", length_index * MEM_STATS_ITEM_LENGTH, tmp);
            STRMERG_WLOG_V(L"%ls",temp_buf);
        }
#endif /*MEM_LIST_INFO_STATS*/
    } 
	
#ifdef MEM_LIST_INFO_STATS
    /* Show the memory usage statistics of string lines in ref_list */
    STRMERG_LOG_V("\nSummary of String line length:");
  
    for(length_index = 0; length_index < MEM_STATS_ITEM_MAX; length_index++)
    {
        STRMERG_LOG_V("[%d]: %d", length_index * MEM_STATS_ITEM_LENGTH, length_stats[length_index]);
      
     }
#endif /*MEM_LIST_INFO_STATS*/
  
    free(temp_buf);
    return max_line_buf_length;
}


/*****************************************************************************
 * FUNCTION
 *  en_language_is_open
 * DESCRIPTION
 *  check if english language is open or not 
 * PARAMETERS
 *  svoid
 * RETURNS
 *  Return TRUE if english is open, otherwise, return FALSE
 *****************************************************************************/
static BOOL en_language_is_open(void)
{
    int i = 0;
    char *en = "*#0044#";

    for(i = 0; i < mtk_gMaxDeployedLangs; ++i)
    {
        if(strcmp(mtk_gLanguageArray[i].aLangSSC, en) == 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  get_language_in_ssc_index
 * DESCRIPTION
 *  get the column index that deployed language in ref list 
 * PARAMETERS
 *  ssc         :[IN]  ssc string of ref list
 *  index       :[OUT] column index that deployed language in ref list
 *  lang_count  :[IN] language total count
 * RETURNS
 *  Return 0 on success, otherwise, return -1
 *****************************************************************************/
static void get_language_in_ssc_index(const wchar_t* ssc, int **index, int lang_count)
{
    int j = 0, k = 0;
    wchar_t *tok = NULL;
    wchar_t *en = L"*#0044#";
    int LangIndex = 0;
    int en_index = -1;
    int count = 0;
    /*g_line_buf_length has been initialized here*/
    wchar_t *rssc = NULL;

    rssc = (wchar_t*)malloc(g_line_buf_length * sizeof(wchar_t));

    if(ssc == NULL || index == NULL || rssc == NULL)
    {
        return;
    }

    /*skip the fist 4 column header*/
    wcscpy(rssc, ssc);
    tok = wcstok(rssc, DELIMETER);	 /* ENUM */
    tok = wcstok(NULL, DELIMETER);		/* MODULE NAME */
    tok = wcstok(NULL, DELIMETER);		/* MAX LENGTH */
    tok = wcstok(NULL, DELIMETER);		/* DESCRIPTION */

    for (j = 4; j < lang_count + 4; j++) /*a little tricky*/
    {
        /* change to corresponding language column according to j */
        tok = wcstok(NULL, DELIMETER);

        ASSERT(tok != NULL);
        LangIndex = ifLanguageUsed(tok);

        if (LangIndex < 0) /* the language is not used in font resource */
            continue;

        index[count++] = j;

        /*if all language has been searched, we will return*/
        if(count == mtk_gMaxDeployedLangs)
            break;
    }

    /*if english is not opened, insert english order into index*/
    if(!en_language_is_open())
    {
        /*find english index in ssc*/
        wcscpy(rssc, ssc);
        tok = wcstok(rssc, DELIMETER);	 /* ENUM */
        tok = wcstok(NULL, DELIMETER);		/* MODULE NAME */
        tok = wcstok(NULL, DELIMETER);		/* MAX LENGTH */
        tok = wcstok(NULL, DELIMETER);		/* DESCRIPTION */

        /*get the index of english in ssc*/
        for(j = 4; j < lang_count + 4; j++)
        {
            tok = wcstok(NULL, DELIMETER);

            ASSERT(tok != NULL);
            if(wcscmp(tok, en) == 0)
            {
                en_index = j;
                break;
            }
        }

        /*insert en_index into index and keep increase order*/
        for(j = mtk_gMaxDeployedLangs; j > 0; --j)
        {
            if(en_index < index[j - 1])
                index[j] = index[j - 1];
            else
                break;
        }
        index[j] = en_index;
    }

    free(rssc);
}


/*****************************************************************************
 * FUNCTION
 *  filter_raw_string
 * DESCRIPTION
 *  filter not used fieled, only reserve the first 5 column and opened language
 *
 * PARAMETERS
 *  in_data      :[IN]  one line of ref_list.txt
 *  out_data    :[OUT] column index that deployed language in ref list
 *  index         :[IN] index array that open language in ssc
 *  total_lang   :[IN] total language count
 * RETURNS
 *  void
 *****************************************************************************/
static void filter_raw_string(const wchar_t* in_data, wchar_t* out_data, const int *index, int total_lang)
{
    int i = 0;
    int token = 0;
    wchar_t itembuf[TMP_BUF_LENGTH];
    wchar_t tmp[g_line_buf_length * sizeof(wchar_t)];
    wchar_t marker[2] = {NO_TRANSLATION_MARKER, 0};

    if(in_data == NULL || out_data == NULL || index == NULL)
    {
        return;
    }

    /*put it in the tmp buffer*/
    wcscpy(tmp, in_data);

    /*copy the first 4 column*/	
    GetItem(tmp, token++, itembuf);
    wcscpy(out_data, itembuf);
    wcscat(out_data, L"\t");

    for(i = 1; i < 4; ++i)
    {
        GetItem(in_data, token++, itembuf);
        /* wcscat(out_data, itembuf); */    
        if(itembuf[0] == '\0'){
            wcscat(out_data, marker);
        }
        else{
            wcscat(out_data, itembuf);
        }

        wcscat(out_data, L"\t");
    }

    /*copy the needed column*/
    for(i = 0; i < total_lang; ++i)
    {
        if(index[i] != -1) /*we have this language in ref_list*/
        {
            GetItem(in_data, index[i], itembuf);
		
            if(itembuf[0] == '\0'){
                wcscat(out_data, marker);
            }
            else{
                wcscat(out_data, itembuf);
            }
        }
        else{ /*in ref_list, we do not have this language*/
            wcscat(out_data, marker);
        }
        wcscat(out_data, L"\t");
    }
    /*in order to reduce memory but will increase process time*/
    wcscat(out_data, L"\r\n\0");
}

/*****************************************************************************
 * FUNCTION
 *  check_ref_list_item
 * DESCRIPTION
 *  Check if the format of the ref list line is invalid or not
 *
 * PARAMETERS
 *  ref_line      :[IN] one line of ref list to be check
 * RETURNS
 *  0              : Valid format
 * -1            : Invalid format
 *****************************************************************************/
int check_ref_list_item(wchar_t * ref_line, int buf_size)
{ 
    int str_length = 0;
    // NULL pointer check
    if(ref_line == NULL)
    {
                STRMERG_LOG_E("REF LIST ITEM is NULL");
                return -1;
    }
    // Empty check
    str_length= wcslen(ref_line);

    if(str_length <= 2){
        STRMERG_LOG_E("REF LIST ITEM format error!! It can be an empty line. ");
        return -1;
    }

    // Check for overflow
    if(str_length >= buf_size){
        STRMERG_LOG_E("REF LIST item overflow: %d, buffer size = %d", str_length, buf_size);
        return -1;
    }

    return 0;
}

#ifndef MEM_REF_LIST_OPT /* MEM_REF_LIST_OPT */

/*****************************************************************************
 * FUNCTION
 *  load_ref_list_to_mem
 * DESCRIPTION
 *  load the ref list's information to memory
 *
 * PARAMETERS
 *  out_buff     :[OUT]  the buffer used to store the content of ref list
 *  end_line     :[OUT] the end line of ref list
 *  ref          :[IN] file handle point to ref list
 *  index        :[IN] the column index that populated language in ref list
 *  ref_cnt      :[IN] the item count in ref list
 * RETURNS
 *  void
 *****************************************************************************/
static void load_ref_list_to_mem(wchar_t *out_buff, wchar_t **end_line, FILE* ref, const int* index, const int ref_cnt, const int deployed_lang)
{
    int j = 0;
    wchar_t *tmp = out_buff;
    wchar_t *ref_line = NULL;
    wchar_t *last_valid_ref_line = NULL;	
    wchar_t *ref_result = NULL;
    wchar_t itembuf[MAX_LENGTH];

    if(out_buff == NULL)
        return;

    /*mallco memory for tmp buffer*/
    ref_line = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
    last_valid_ref_line = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
    if(ref_line == NULL || last_valid_ref_line == NULL)
    {
        ASSERT(0);
    }

    /*malloc  memory for return result*/
    ref_result = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));

    if(ref_result == NULL)
    {
        free(ref_line);
        ASSERT(0);
    }

    // Init last_valid_ref_line
    wcscpy(last_valid_ref_line,L"");

    rewind(ref);
    fgetws(ref_line, g_line_buf_length, ref);
    fgetws(ref_line, g_line_buf_length, ref);
    fgetws(ref_line, g_line_buf_length, ref);

    for(j = 0; j < ref_cnt; j++)
    {
        fgetws(ref_line, g_line_buf_length, ref);

        if(check_ref_list_item(ref_line, g_line_buf_length)< 0)
        {
            // The format is invalid!!
            STRMERG_WLOG_E(L"Invalid REF item after: %ls", last_valid_ref_line);
            fflush(stdout);
         }
         else
         {


#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
        /* set fixed string id flag */
        GetItem(ref_line, 0, itembuf);
        set_fixed_str_flag(&fixed_id, itembuf);
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
        
        filter_raw_string(ref_line, ref_result, index, deployed_lang);

        wcscpy(tmp, ref_result);
        wcscpy(last_valid_ref_line, ref_line);		
        tmp += g_line_buf_act_length;

        }
    }

    *end_line = tmp - g_line_buf_act_length;

    free(ref_line);
    free(ref_result);
}
#else /* MEM_REF_LIST_OPT */
/*****************************************************************************
 * FUNCTION
 *  load_ref_list_to_mem
 * DESCRIPTION
 *  Load the ref list's information to memory; storing the ref list data with 
 *   a vector (dynamic array) instead of a large continuous array
 *
 * PARAMETERS
 *  out_buff     :[OUT]  the buffer used to store the content of ref list
 *  ref          :[IN] file handle point to ref list
 *  index        :[IN] the column index that populated language in ref list
 *  ref_cnt      :[IN] the item count in ref list
 * RETURNS
 *  void
 *****************************************************************************/
static void load_ref_list_to_mem(RefList *out_buff, FILE* ref, const int* index, const int ref_cnt, const int deployed_lang)
{
    int j = 0;
    wchar_t *tmp = out_buff;
    wchar_t *ref_line = NULL;
    wchar_t *last_valid_ref_line = NULL;
    wchar_t *ref_result = NULL;
    wchar_t itembuf[MAX_LENGTH];

    if(out_buff == NULL)
        return;

    /*mallco memory for tmp buffer (str line of all languages)*/
    ref_line = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
	
    last_valid_ref_line = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
    if(ref_line == NULL || last_valid_ref_line == NULL)
    {
        ASSERT(0);
    }

    /* malloc  memory for return result (str line of deployed languages)*/
    ref_result = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
    if(ref_result == NULL)
    {
        free(ref_line);
        ASSERT(0);
    }

    // Initialize last_valid_ref_line
    wcscpy(last_valid_ref_line,L"");

    rewind(ref);
    fgetws(ref_line, g_line_buf_length, ref);
    fgetws(ref_line, g_line_buf_length, ref);
    fgetws(ref_line, g_line_buf_length, ref);

    for(j = 0; j < ref_cnt; j++)
    {
        fgetws(ref_line, g_line_buf_length, ref);
#ifdef STR_MERGE_DEBUG
        STRMERG_WLOG_D(L"Parsing: %ls", ref_line);
        fflush(stdout);
#endif
        if(check_ref_list_item(ref_line, g_line_buf_length)< 0)
        {
        // The format is invalid!!
            wchar_t * err_msg = malloc((STRMERGE_ERR_MSG_LEN_MAX+1) * sizeof(wchar_t));
            swprintf(err_msg,L"Invalid REF item after: %ls", last_valid_ref_line);
            // Use RES_WLOG_PENDING_FATAL to notify error. It will cause mtk_resgenerator.exe to return error code
            RES_WLOG_PENDING_FATAL(STRMERG_TAG, L"Fatal error in load_ref_list_to_mem()", err_msg,L"Pleae check the REF item in plutommi\\Customer\\CustResource\\ref_list.txt, empty line and extra tab are not allowed.");
            STRMERG_WLOG_E(L"Please check plutommi\\Customer\\CustResource\\ref_list.txt for this error ! MSG=[ %ls ]\n",err_msg);
            free(err_msg);
        }
        else
        {

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
            /* set fixed string id flag */
            GetItem(ref_line, 0, itembuf);
            set_fixed_str_flag(&fixed_id, itembuf);
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
    
            /* Load the string of deployed language only */
            filter_raw_string(ref_line, ref_result, index, deployed_lang);
            /* Create a ref list item object and store the str line to it */
            RefListItem *lineItem = CreateListItemFromStr(ref_result);
            /* Add the new ref list item to ref list*/
            AddRefListItem(out_buff,lineItem);
            /* Record the last success one for debug */			
            wcscpy(last_valid_ref_line, ref_line);
        }
    }
    free(ref_line);
    free(ref_result);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  get_ref_count
 * DESCRIPTION
 *  get the ref list item count
 *
 * PARAMETERS
 *  fp            :[IN]  file handle of ref list
 *  line_len      :[IN] line length of each item
 *  buff          :[IN] buffer to restore a item content
 * RETURNS
 *  int           : item count 
 *****************************************************************************/
int get_ref_count(FILE *fp, U32 line_len, wchar_t* buff)
{
    int count = 0;

    if(fp == NULL || line_len <= 0)
    {
        return 0;
    }

    /* calculate the number of entries and read them to the buffer */
    fgetws(buff, line_len, fp);
    while (!feof(fp))
    {
        count++;
        fgetws(buff, line_len, fp);
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  get_filter_used_language_count
 * DESCRIPTION
 *  get the filter language count
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  int          : filtered total language count
 *****************************************************************************/
int get_filter_used_language_count(void)
{
    int count = 0;
	
    if(en_language_is_open()){
        count = mtk_gMaxDeployedLangs;
    }
    else{
        /*if english is not open, we still need to process it, so total language count will add 1*/
        count = mtk_gMaxDeployedLangs + 1;
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  MergeStrRes
 * DESCRIPTION
 *  Find string ID in ref_list.txt, generate string content table
 * PARAMETERS
 *  void
 * RETURNS
 *  Return 0 on success, otherwise, return -1
 *****************************************************************************/
int MergeStrRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *ref = NULL;
    FILE *fail = NULL;
    wchar_t *tmp_line;
    wchar_t *end_line;

#ifdef MEM_REF_LIST_OPT
    /* Record the scanning string line index of ref list */
    int tmp_line_indx = 0;
    /* temp variable to read/wirte data from/to a ref list item*/
    RefListItem *tmp_list_item = NULL;
#endif /* MEM_REF_LIST_OPT */

    wchar_t buf_src[TMP_BUF_LENGTH];
    wchar_t buf_ref[TMP_BUF_LENGTH];
    wchar_t tmp_buf[TMP_BUF_LENGTH];
    int token_id = 0, gIndex = 0;
    char buf_asc[512];
    int found = 0, i = 0, StrNotTranslated = 1, missLanguage = 0;

    int ret = 0;
    U16 nStrId = 0;
    U16 total_id = CurrMaxStringId;

    wchar_t marker[2] = {NO_TRANSLATION_MARKER, 0};
    // record the times of memory allocation retry
    int mem_retry_count = 0;

    /* operator support */
#ifndef __OPTR_NONE__
    FILE *optr_ref = NULL;
    char *optr_path;
    int optr_lang;
    U32 optr_line_buf_length;
    U16 *optr_lang_mask = NULL;
    wchar_t (*ref_ssc_list)[SSC_LENGTH] = NULL;


#ifndef MEM_REF_LIST_OPT
    wchar_t *optr_ref_all = NULL;
#else /* MEM_REF_LIST_OPT */
    /* Load optr ref list lines to a vector with variable 
       size elememts instead of a lare array with fixed
       size elementsn */
    RefList *optr_ref_all_list = NULL;
    /* Record the scanning string line index of operator ref list */
    int optr_tmp_line_indx = 0;
#endif /*MEM_REF_LIST_OPT*/

    wchar_t *optr_ref_ssc = NULL;
    wchar_t *optr_tmp_line;
    wchar_t *optr_end_line;
    int optr_found;
    int optr_ref_cnt = 0;
    int optr_new_cnt = 0;
    int optr_search_cnt = 0;
    int optr_search_index = 0;
#endif /* __OPTR_NONE__ */

#ifdef __TIME_CONSUME
    time_t start_time, end_time;
#endif
    int ref_cnt = 0;
    int search_cnt = 0;
    int search_index = 0;
    int j;
    /*column index that deployed language in ref list*/
    int deployed_lang_index[mtk_gMaxDeployedLangs + 1];
#ifndef __OPTR_NONE__
    int optr_deployed_lang_index[mtk_gMaxDeployedLangs + 1];
#endif /*__OPTR_NONE__*/

    int count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    STRMERG_LOG_V("MergeStrRes(): Start to merge string translation data");
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    CurrMaxTransStrId = 0;
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
    /*it will be used to caculate string size*/
    memset(StrSize, 0, sizeof(U16) * MAX_STRING_MAP_SIZE);
    memset(deployed_lang_index, -1, sizeof(int) * (mtk_gMaxDeployedLangs + 1));
#ifndef __OPTR_NONE__
    memset(optr_deployed_lang_index, -1, sizeof(int) * (mtk_gMaxDeployedLangs + 1));
#endif /*__OPTR_NONE__*/

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    ret = init_fixed_id(&fixed_id, CurrMaxStringId);
    if(ret != 0){
        STRMERG_LOG_E("init_fixed_id() error: LINE:%d,\tFILE%s", __LINE__, __FILE__);
        fprintf(stderr, "failed error: LINE:%d,\tFILE%s\n", __LINE__, __FILE__);
        return -1;
    }

    ret = generate_enum_hash(fixed_id.enum_id_tb, StrIsPopulate, StrEnum);
    if(ret < 0){
        STRMERG_LOG_E("generate_enum_hash() error: LINE:%d,\tFILE%s", __LINE__, __FILE__);
        fprintf(stderr, "failed error: LINE:%d,\tFILE%s\n", __LINE__, __FILE__);
        return -1;
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */


    nUsedLang = get_filter_used_language_count();

    ref = fopen(ref_file, "rb");
    if (ref == NULL)
    {
        STRMERG_LOG_E("Invalid reference filename: %s",ref_file);
        return -1;
    }
    /* operator support */
#ifndef __OPTR_NONE__
    optr_path = (char *)tmp_buf;
    strcpy(tmp_buf, CUST_OPERATOR_STR_PATH);
    strcat(tmp_buf, "\\");
    strcat(tmp_buf, optr_ref_file);

    optr_ref = fopen(optr_path, "rb");
    if (optr_ref == NULL)
    {
        STRMERG_LOG_E("Invalid operator reference filename");
        goto ERR_RET;
    }
#endif /* __OPTR_NONE__ */
    fail = fopen(".\\\\debug\\\\NoTranslation.txt", "w");
    if (fail == NULL)
    {
        STRMERG_LOG_E(".\\\\debug\\\\NoTranslation.txt Open Fail!!");
        goto ERR_RET;
    }
    fclose(fail);
    fail = fopen(".\\\\debug\\\\NoTranslation.txt", "a");
    if (fail == NULL)
    {
        STRMERG_LOG_E("NoTranslation.txt Open Fail!!");
        goto ERR_RET;        
    }

#ifdef __TIME_CONSUME
    start_time = time(NULL);
#endif

    fgetws(tmp_buf, TMP_BUF_LENGTH, ref); /* Number of Language */
    GetItem(tmp_buf, 1, buf_ref);
    nLang = _wtoi(buf_ref);
    rewind(ref);
    g_line_buf_length = GetLineBufLength(ref, nLang);
    /* need additional buffer for NO_TRANSLATION_MARKER to avoid buffer overruns */
    g_line_buf_length += wcslen(marker) * nLang;
    /* actually line length */
    g_line_buf_act_length = g_line_buf_length;

    rewind(ref);
    fgetws(tmp_buf, TMP_BUF_LENGTH, ref); /* Skip Number of Language */


#ifdef MEM_REF_LIST_OPT
    /* Allocate tmp_line buffer. tmp_line will be write back to RefList
            strcuture indexed by corrosponding tmp_line_index. */
    tmp_line = (wchar_t *)malloc(g_line_buf_act_length * sizeof(wchar_t));
    memset(tmp_line, 0, g_line_buf_act_length * sizeof(wchar_t));
#endif /*MEM_REF_LIST_OPT*/

    /* operator support */
#ifndef __OPTR_NONE__
    fgetws(tmp_buf, TMP_BUF_LENGTH, optr_ref);
    GetItem(tmp_buf, 1, buf_ref);
    optr_lang = _wtoi(buf_ref);
    rewind(optr_ref);
    optr_line_buf_length = GetLineBufLength(optr_ref, optr_lang); 
    /* need additional buffer for NO_TRANSLATION_MARKER to avoid buffer overruns */
    optr_line_buf_length += wcslen(marker) * optr_lang;    
    rewind(optr_ref);
    fgetws(tmp_buf, TMP_BUF_LENGTH, optr_ref); /* Skip Number of Language */
	
#ifdef MEM_REF_LIST_OPT
    /* Allocate tmp_line buffer. optr_tmp_line will be write back to RefList 
            strcuture indexed by corrosponding optr_tmp_line_index. */
    optr_tmp_line = (wchar_t *)malloc(g_line_buf_act_length * sizeof(wchar_t));
    memset(optr_tmp_line, 0, g_line_buf_act_length * sizeof(wchar_t));
#endif /*MEM_REF_LIST_OPT*/

#endif /* __OPTR_NONE__ */

    /* 
     * calculate line buffer size 
     * here +2 for Description, and (Max String Length, MODULE, ENUM)
     */
    /* Makr this line for reduce string memory, use GetLineBufLength */
    /*  g_line_buf_length = (nLang + 2) * MAX_LENGTH; */
    ref_tmp = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
    if (ref_tmp == NULL)
    {
        STRMERG_LOG_E("memory is not available step.1 size=[%d]", g_line_buf_length * sizeof(wchar_t));
        goto ERR_RET;
    }

    token_id = 0;
    fgetws(ref_tmp, TMP_BUF_LENGTH, ref);   /* Title list */
    GetItem(ref_tmp, token_id++, buf_src);
    UCS2ASCII((char*)buf_src, buf_asc);     /* Enum Value */
    fprintf(fail, "%s", buf_asc);           /* print out to NoTranslation.txt */

    GetItem(ref_tmp, token_id++, buf_src);
    UCS2ASCII((char*)buf_src, buf_asc);     /* MODULE NAME */
    fprintf(fail, "\t%s", buf_asc);         /* print out to NoTranslation.txt */

    GetItem(ref_tmp, token_id++, buf_src);
    UCS2ASCII((char*)buf_src, buf_asc);     /* Max String Length */
    fprintf(fail, "\t%s", buf_asc);         /* print out to NoTranslation.txt */

    GetItem(ref_tmp, token_id++, buf_src);
    UCS2ASCII((char*)buf_src, buf_asc);     /* Description */
    fprintf(fail, "\t%s", buf_asc);         /* print out to NoTranslation.txt */

    for (i = 0; i < nLang; i++)
    {
        GetItem(ref_tmp, token_id + i, buf_ref);
        UCS2ASCII((char*)buf_ref, buf_asc); /* Language */
        fprintf(fail, "\t%s", buf_asc);     /* print out to NoTranslation.txt */
    }
    fprintf(fail, "\n");

    ref_ssc = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
    if (ref_ssc == NULL)
    {
        STRMERG_LOG_E("memory is not available step.2 size=[%d]", g_line_buf_length * sizeof(wchar_t));
        goto ERR_RET;
    }
    fgetws(ref_ssc, g_line_buf_length, ref); /* SSC STRING */

    filter_ref_ssc = (wchar_t *)malloc(g_line_buf_act_length * sizeof(wchar_t));
    if (filter_ref_ssc == NULL)
    {
        STRMERG_LOG_E("memory is not available step.2 size=[%d]", g_line_buf_act_length * sizeof(wchar_t));
        goto ERR_RET;
    }

    ref_cnt = get_ref_count(ref, g_line_buf_length, ref_tmp);

    /*get index of language in ref list*/
    get_language_in_ssc_index(ref_ssc, &deployed_lang_index, nLang);
    filter_raw_string(ref_ssc, filter_ref_ssc, deployed_lang_index, nUsedLang);

    /* operator support */
#ifndef __OPTR_NONE__
    /* Makr this line for reduce string memory, use GetLineBufLength */
    /* optr_line_buf_length = (optr_lang + 2) * MAX_LENGTH; */
    optr_ref_ssc = (wchar_t *)malloc(optr_line_buf_length * sizeof(wchar_t));
    if (optr_ref_ssc == NULL)
    {
        STRMERG_LOG_E("memory is not available step.3 size=[%d]", optr_line_buf_length * sizeof(wchar_t));
        goto ERR_RET;
    }

    optr_filter_ref_ssc =  (wchar_t *)malloc(g_line_buf_act_length * sizeof(wchar_t));
    if (optr_filter_ref_ssc == NULL)
    {
        STRMERG_LOG_E("memory is not available step.3 size=[%d]", g_line_buf_act_length * sizeof(wchar_t));
        goto ERR_RET;
    }

    fgetws(ref_tmp, optr_line_buf_length, optr_ref);
    fgetws(optr_ref_ssc, optr_line_buf_length, optr_ref);

    /*get index of language in operator ref list and filter ssc*/
    get_language_in_ssc_index(optr_ref_ssc, &optr_deployed_lang_index, optr_lang);
    filter_raw_string(optr_ref_ssc, optr_filter_ref_ssc, optr_deployed_lang_index, nUsedLang);

    /* allocate mask for languages in operator_ref_list.txt */
    optr_lang_mask = (U16 *)malloc(nUsedLang* sizeof(U16));
    if (optr_lang_mask == NULL)
    {
        STRMERG_LOG_E("memory is not available step.4 size=[%d]", nUsedLang * sizeof(U16));
        goto ERR_RET;
    }
    memset(optr_lang_mask, 0, nUsedLang * sizeof(U16));
    ref_ssc_list = (wchar_t (*)[SSC_LENGTH])malloc(sizeof(wchar_t[SSC_LENGTH]) * nUsedLang);
    if (ref_ssc_list == NULL)
    {
        STRMERG_LOG_E("memory is not available step.5 size=[%d]", sizeof(wchar_t[SSC_LENGTH]) * nUsedLang);
        goto ERR_RET;
    }

    /* read each SSC into ref_ssc_list */
    token_id = 4; /* skip the first 4 column header information */
    for (i = 0; i < nUsedLang; i++)
    {
        GetItem(filter_ref_ssc, token_id++, buf_ref);
        wcscpy(ref_ssc_list[i], buf_ref);
    }
    /* 
     * try to match each SSC in operator_ref_list.txt 
     * within ref_ssc_list
     */
    token_id = 4; /* skip the first 4 column header information */
    for (i = 0; i < nUsedLang; i++)
    {
        GetItem(optr_filter_ref_ssc, token_id++, buf_ref);
        for (j = 0; j < nUsedLang; j++)
        {
            if (!wcscmp(buf_ref, ref_ssc_list[j]))
            {
                /* 
                 * language column j is found in operator_ref_list.txt, 
                 * and matching to language column i
                 */
                optr_lang_mask[j] = i + 1;
                break;
            }
        }
    }
    free(ref_ssc_list);
    ref_ssc_list = NULL;


    optr_ref_cnt = get_ref_count(optr_ref, g_line_buf_length, ref_tmp);

    if (optr_ref_cnt != 0)
    {

#ifndef MEM_REF_LIST_OPT
        optr_ref_all = (wchar_t *)malloc(g_line_buf_act_length * sizeof(wchar_t) * optr_ref_cnt);

        if (optr_ref_all == NULL)
        {
            STRMERG_LOG_E("memory is not available step.6 size=[%d]", g_line_buf_act_length * sizeof(wchar_t) * optr_ref_cnt);
            goto ERR_RET;
        }
        /*load optr ref list to optr_ref_all, this is used to instead the following old part*/
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "Load optr ref list to memory");
        load_ref_list_to_mem(optr_ref_all, &optr_end_line, optr_ref, optr_deployed_lang_index, optr_ref_cnt, nUsedLang);
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "optr ref list: count= %d , size = %d", optr_ref_cnt, g_line_buf_act_length * sizeof(wchar_t) * optr_ref_cnt);
#else / *MEM_REF_LIST_OPT */
        /* Create a Vector-like structure to load operator ref list */
        optr_ref_all_list = CreateRefList(optr_ref_cnt);
        
        if (optr_ref_all_list == NULL)
        {
            STRMERG_LOG_E("memory is not available step.6 length=[%d]",optr_ref_cnt);
            goto ERR_RET;
        }
        
        /*load optr ref list to ref_all, this is used to instead the following old part*/
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "Load optr ref list to memory");
        load_ref_list_to_mem(optr_ref_all_list, optr_ref, optr_deployed_lang_index, optr_ref_cnt, nUsedLang);
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "optr_ref_all_list length = %d, size = %d", optr_ref_all_list->ListLength, optr_ref_all_list->Size);
#endif /*MEM_REF_LIST_OPT*/
    }
#endif /* __OPTR_NONE__ */

    /* operator support */
#ifndef __OPTR_NONE__
    count = ref_cnt + optr_ref_cnt;
#else /*__OPTR_NONE__*/
    count = ref_cnt; 
#endif /*__OPTR_NONE__*/

#ifndef MEM_REF_LIST_OPT
    ref_all = (wchar_t *)malloc(g_line_buf_act_length * sizeof(wchar_t) * (count));
    STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "memory usage in step.7 size=[%d], buf_length: %d, count: %d", g_line_buf_act_length * sizeof(wchar_t) * (count),g_line_buf_act_length,count);
    fflush(stdout);
	
    //Retry if the memory is not available
    while(ref_all == NULL && mem_retry_count < MEM_RETRY_COUNT_MAX)
    {
        /* Retry count of memory allocation */
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "memory is unavailable step.7, retry after %d sec", MEM_RETRY_TIME_INTERVAL_SEC);
        sleep(MEM_RETRY_TIME_INTERVAL_SEC);
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "retry: %d", mem_retry_count);
        ref_all = (wchar_t *)malloc(g_line_buf_act_length * sizeof(wchar_t) * (count));
        mem_retry_count++;
    }
	  
    if (ref_all == NULL)
    {
        STRMERG_LOG_E("memory is not available step.7 size=[%d]", g_line_buf_act_length * sizeof(wchar_t) * (count));
        goto ERR_RET;
    }    
    /*load ref list to ref_all, this is used to instead the following old part*/
    load_ref_list_to_mem(ref_all, &end_line, ref, deployed_lang_index, ref_cnt, nUsedLang);
#else /*MEM_REF_LIST_OPT*/
    /* Create a ref list vector to store ref list lines in ref_list.txt */
	STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "CreateRefList : create data structure to store ref list lines");
    fflush(stdout);
    ref_all_list = CreateRefList(count);
    if (ref_all_list == NULL)
    {
        STRMERG_LOG_E("memory is not available step.7 length=[%d]", count);
        goto ERR_RET;
    }
	
    /* load ref list items to ref_all vector*/
	STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "load_ref_list_to_mem: load ref list items to ref_all vector");	
    fflush(stdout);
    load_ref_list_to_mem(ref_all_list, ref, deployed_lang_index, ref_cnt, nUsedLang);

	/* Update ref_cnt based to the loaded items */
    ref_cnt = ref_all_list->ListLength;
#endif /*MEM_REF_LIST_OPT*/

#ifdef DEBUG_REF_LIST_DUMP
/* Dump the ref list loaded in memory to log file REFLISST_DUMP_FILE_BEFOR_MERGE */
#ifndef MEM_REF_LIST_OPT
    DumpRefList(REFLISST_DUMP_FILE_BEFOR_MERGE, ref_all, g_line_buf_act_length, count);
#else /* MEM_REF_LIST_OPT */
    DumpRefList(REFLISST_DUMP_FILE_BEFOR_MERGE, ref_all_list);
#endif /* MEM_REF_LIST_OPT */
#endif /* DEBUG_REF_LIST_DUMP */


#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    total_id = CurrMaxTransStrId;
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    /* String ID array without empty slot */
    StrID = (U16 *)malloc(sizeof(U16) * total_id);
    if (StrID == NULL)
    {
        STRMERG_LOG_E("memory is not available step.8 size=[%d]", sizeof(U16) * total_id);
        goto ERR_RET;
    }

    nStrId = 0;
    while (nStrId < MAX_STRING_MAP_SIZE)
    {
#ifdef STR_MERGE_DEBUG
        STRMERG_LOG_D("Check String ID %d", nStrId);
#endif /* STR_MERGE_DEBUG */
        if (StrIsPopulate[nStrId] == 0)
        {
            nStrId++;
            continue;
        }

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
        /* skip no translated string id */
        if(fixed_id.fixed_id_flag[nStrId] == NO_TRANSLATE_FLAG)
        {
            nStrId++;
            continue;
        }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

        *(StrID + gIndex) = nStrId;

        /* operator support */
#ifndef __OPTR_NONE__
        optr_found = 0;
        if (optr_ref_cnt != 0) /* 查看是否能从operator ref list中找到该string id */
        {
#ifdef STR_MERGE_DEBUG
            STRMERG_LOG_D("OP ref list item idx = %d",optr_search_index );
#endif /* STR_MERGE_DEBUG */

#ifndef MEM_REF_LIST_OPT
            optr_tmp_line = optr_ref_all + optr_search_index * g_line_buf_act_length;
#else
            /* Read a list item from optr_ref_all_list*/
            tmp_list_item = GetRefListItem(optr_ref_all_list,optr_search_index);
            /* NULL pointer check*/
            if(tmp_list_item != NULL)
            {
                wcscpy(optr_tmp_line,tmp_list_item->ItemData);
            }
            else
            {
                STRMERG_LOG_E("tmp_list_item in op list is NULL, idx = %d", optr_search_index);
            }
            /* Record the current scaning line in the op ref list */
            optr_tmp_line_indx = optr_search_index;
#endif  /*MEM_REF_LIST_OPT*/
            while (optr_search_cnt < optr_ref_cnt)
            {
                token_id = 0;
                GetItem(optr_tmp_line, token_id++, buf_ref);
                /* Check if it is a new string*/
                if (!wcscmp((wchar_t *)StrEnum[nStrId], buf_ref))
                {
                    optr_found = 1;
                    break;
                }
                optr_search_cnt++;
                optr_search_index++;
                if (optr_search_index >= optr_ref_cnt)
                    optr_search_index = 0;

#ifndef MEM_REF_LIST_OPT
                optr_tmp_line += g_line_buf_act_length;
                if (optr_tmp_line > optr_end_line)
                    optr_tmp_line = optr_ref_all;
#else
                tmp_list_item = GetRefListItem(optr_ref_all_list,optr_search_index);
                /* Read the next string line in optr ref list */
                if(tmp_list_item!=NULL)
                {
                    wcscpy(optr_tmp_line, tmp_list_item->ItemData);
                }
                else
                {
                    wcscpy(optr_tmp_line,L"");
                }
                /* Record the current scanning line in optr ref list */
                optr_tmp_line_indx = optr_search_index;
#endif  /*MEM_REF_LIST_OPT*/
            }

#ifdef STR_MERGE_DEBUG
            STRMERG_LOG_D("Finished check opfound= %d", optr_found);
#endif /* STR_MERGE_DEBUG */
        }

#endif /* __OPTR_NONE__ */
#ifdef STR_MERGE_DEBUG
        STRMERG_LOG_D("Process ref_all_list!! search_index = %d",search_index);
#endif /* STR_MERGE_DEBUG */
        found = 0;
#ifndef MEM_REF_LIST_OPT
        tmp_line = ref_all + search_index * g_line_buf_act_length;
#else
        tmp_list_item = GetRefListItem(ref_all_list, search_index);
        if(tmp_list_item!=NULL)
        {
            /* Copy string line to temp line buffer */
            wcscpy(tmp_line,tmp_list_item->ItemData);
        }
        else{
                wcscpy(tmp_line,L"");
        }
        /* Record scanning line index of ref list */
        tmp_line_indx = search_index;
#endif /* MEM_REF_LIST_OPT */


        while ((search_cnt < ref_cnt) && !found)
        {
            token_id = 0;
            GetItem(tmp_line, token_id++, buf_ref);
            if (!wcscmp((wchar_t *)StrEnum[nStrId], buf_ref))
            {
                found = 1;
                StrLine[nStrId] = search_index + 1;

                wcscpy(tmp_buf, (wchar_t *)StrEnum[nStrId]); /* print out Enum Values */

                /* output content of fix columns */
                OutputFixColumns(tmp_line, &token_id, buf_src, tmp_buf, ref_tmp);

                missLanguage = 0;
                for (i = 0; i < nUsedLang; i++)
                {
                    GetItem(tmp_line, i + token_id, buf_ref);

                    /* operator support */
#ifndef __OPTR_NONE__
                    if (optr_found == 1 && optr_lang_mask[i])
                    {
                        GetItem(optr_tmp_line, 3 + optr_lang_mask[i], buf_ref);
                    }
#endif /* __OPTR_NONE__ */

                    if (buf_ref[0] == '\0')
                    {
                        /* if there is no corresponding string translation, use English */
                        missLanguage = 1;
                        wcscat(tmp_buf, L"\tV");

                        wcscat(ref_tmp, L"\t");
                        wcscat(ref_tmp, marker);
                    }
                    else
                    {
                        wcscat(tmp_buf, L"\t");

                        /* for possible missing language translation */
                        wcscat(ref_tmp, L"\t");
                        wcscat(ref_tmp, buf_ref);
                    }
                }
                if (missLanguage == 1)
                {
                    wcscat(tmp_buf, L"\n");
                    UCS2ASCII((char*)tmp_buf, buf_asc);
                    fprintf(fail, "%s", buf_asc);
#ifdef STR_MERGE_DEBUG
                    STRMERG_LOG_V("missLanguage found!! search_index = %d",search_index);     
#endif /* STR_MERGE_DEBUG */

                    /* replace string content */
                    wcscpy(tmp_line, ref_tmp);
                }
#ifndef __OPTR_NONE__
                else if (optr_found == 1)
                {
#ifdef STR_MERGE_DEBUG
                    STRMERG_LOG_D("OPTR found!! search_index = %d",search_index);     
#endif /* STR_MERGE_DEBUG */
                    /* replace string content */
#ifndef MEM_REF_LIST_OPT
                    wcscpy(tmp_line, ref_tmp);
#else
                    tmp_list_item = CreateListItemFromStr(ref_tmp);
                    SetRefListItem(ref_all_list, tmp_line_indx,tmp_list_item );
#endif /* MEM_REF_LIST_OPT */
                }
#endif /* __OPTR_NONE__ */
            }
            if (!found)
            {
                search_cnt++;
            }
            search_index++;
            if (search_index >= ref_cnt)
                search_index = 0;
#ifndef MEM_REF_LIST_OPT
            tmp_line += g_line_buf_act_length;
            if (tmp_line > end_line)
                tmp_line = ref_all;
#else
            tmp_list_item = GetRefListItem(ref_all_list, search_index);
            if(tmp_list_item!=NULL)
            {
                /* read scanning line to buffer */
                wcscpy(tmp_line,tmp_list_item->ItemData);
            }
            else
            {
                STRMERG_LOG_D("item in ref list is NULL: %d ",search_index);
                wcscpy(tmp_line,L"");
            }
            tmp_line_indx = search_index;
#endif /* MEM_REF_LIST_OPT */
        }
        if (!found)
        {
#ifndef __OPTR_NONE__
            if (optr_found == 1)
            {
                /* for strings only in operator_ref_list.txt */
                int optr_token_id = 0;

                GetItem(optr_tmp_line, optr_token_id++, buf_src);
                wcscpy(tmp_buf, (wchar_t *)buf_src); /* print out Enum Values */

                /* output content of fix columns */
                OutputFixColumns(optr_tmp_line, &optr_token_id, buf_src, tmp_buf, ref_tmp);

                missLanguage = 0;
                for (i = 0; i < nUsedLang; i++)
                {
                    buf_ref[0] = '\0';

                    if (optr_lang_mask[i])
                    {
                        GetItem(optr_tmp_line, 3 + optr_lang_mask[i], buf_ref);
                    }

                    if (buf_ref[0] == '\0')
                    {
                        /* if there is no corresponding string translation, use English */
                        missLanguage = 1;
                        wcscat(tmp_buf, L"\tV");

                        wcscat(ref_tmp, L"\t");
                        wcscat(ref_tmp, marker);
                    }
                    else
                    {
                        wcscat(tmp_buf, L"\t");

                        /* will copy back to reference string table */
                        wcscat(ref_tmp, L"\t");
                        wcscat(ref_tmp, buf_ref);
                    }
                }

                if (missLanguage == 1)
                {
                    wcscat(tmp_buf, L"\n");
                    UCS2ASCII((char*)tmp_buf, buf_asc);
                    fprintf(fail, "%s", buf_asc);
                }

                /* copy back to reference string table */
                optr_new_cnt++;
                StrLine[nStrId] = ref_cnt + optr_new_cnt;
#ifdef STR_MERGE_DEBUG
                STRMERG_LOG_E("Copy Back nStrId = %d",nStrId);
#endif /* STR_MERGE_DEBUG */

#ifndef MEM_REF_LIST_OPT
                wcscpy((end_line + optr_new_cnt * g_line_buf_act_length), ref_tmp);
#else
                tmp_list_item = CreateListItemFromStr(ref_tmp);
                if(tmp_list_item!=NULL)
                {
                    AddRefListItem(ref_all_list,tmp_list_item);
                }
                else
                {
                    STRMERG_LOG_V("Copy back from an empty item in ref list, index = %d", optr_new_cnt);
                }
#endif /*MEM_REF_LIST_OPT*/
            }
            else
#endif /*__OPTR_NONE__*/
            {
                /* didn't find any match */
                StrNotTranslated = 0;
                UCS2ASCII((char*)StrEnum[nStrId], buf_asc);
                fprintf(fail, "%s\t\t\tEmpty\n", buf_asc);
            }
        }

        gIndex++;
        nStrId++;
        search_cnt = 0;
        /* operator support */
#ifndef __OPTR_NONE__
        optr_search_cnt = 0;
#endif
    }

#ifdef __TIME_CONSUME
    end_time = time(NULL);
    STRMERG_LOG_V("elapsed time = %d", end_time - start_time);
#endif /* __TIME_CONSUME */

    /* operator support */
#ifndef __OPTR_NONE__
    if (optr_lang_mask)
        free(optr_lang_mask);
    if (optr_ref_ssc)
        free(optr_ref_ssc);
    if(optr_filter_ref_ssc)
        free(optr_filter_ref_ssc);
/* Release ref list buffer memory*/
#ifndef MEM_REF_LIST_OPT
    if (optr_ref_all)
        free(optr_ref_all);
#else
    if(optr_tmp_line)
        free(optr_tmp_line);
    if(optr_ref_all_list)
        DeleteRefList(optr_ref_all_list);
#endif /* MEM_REF_LIST_OPT*/
    if (optr_ref)
        fclose(optr_ref);
#endif /* __OPTR_NONE__ */

#ifdef MEM_REF_LIST_OPT
    if(tmp_line)
        free(tmp_line);
#endif /* MEM_REF_LIST_OPT*/

#ifdef DEBUG_REF_LIST_DUMP
#ifndef MEM_REF_LIST_OPT
    DumpRefList(REFLISST_DUMP_FILE_AFTER_MERGE, ref_all, g_line_buf_act_length, count);
#else
    DumpRefList(REFLISST_DUMP_FILE_AFTER_MERGE, ref_all_list);
#endif /* MEM_REF_LIST_OPT*/
#endif /* DEBUG_REF_LIST_DUMP */

    fclose(ref);
    fclose(fail);
    if (StrNotTranslated == 0)
    {
        STRMERG_LOG_V("Please see NoTranslation.txt to see the result...");
    }
	
	fflush(stdout); // flush log message
    return 0;

ERR_RET:
	fflush(stdout); // flush log message
    if (ref_tmp)
        free(ref_tmp);
    if (ref_ssc)
        free(ref_ssc);

/* Release ref list buffer memory*/
#ifndef MEM_REF_LIST_OPT
    if (ref_all)
        free(ref_all);
#else
    if(tmp_line)
        free(tmp_line);
    if(ref_all_list)
        DeleteRefList(ref_all_list);
#endif /*MEM_REF_LIST_OPT*/

    if(filter_ref_ssc)
        free(filter_ref_ssc);
    /* operator support */
#ifndef __OPTR_NONE__
    if (optr_lang_mask)
        free(optr_lang_mask);
    if (ref_ssc_list)
        free(ref_ssc_list);
    if (optr_ref_ssc)
        free(optr_ref_ssc);

/* Release OPTR ref list buffer memory*/
#ifndef MEM_REF_LIST_OPT
    if (optr_ref_all)
        free(optr_ref_all);
#else
    if(optr_ref_all_list)
        DeleteRefList(optr_ref_all_list);
    if(optr_tmp_line)
        free(optr_tmp_line);
#endif /*#ifndef MEM_REF_LIST_OPT*/
    if (optr_ref)
        fclose(optr_ref);
#endif /* __OPTR_NONE__ */

    if (ref)
        fclose(ref);
    if (fail)
        fclose(fail);
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mask_length
 * DESCRIPTION
 *  Get token between index and index+1 DELIMETER
 * PARAMETERS
 *  val     [IN]
 * RETURNS
 *  Return the mask bit count
 *****************************************************************************/
static int mask_length(int val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int l = 0, v;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v = val / 2;
    while (v >= 1)
    {
        l++;
        v = v / 2;
    }
    return l;
}


/*****************************************************************************
 * FUNCTION
 *  pow
 * DESCRIPTION
 *  Calculate base raised to the power of index
 * PARAMETERS
 *  base    [IN]
 *  index   [IN]
 * RETURNS
 *  Return the value: base raised to the power of index
 *****************************************************************************/
static int pow(int base, int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, ret = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < index; i++)
        ret = ret * base;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  fmod
 * DESCRIPTION
 *  Calculate the remainder
 * PARAMETERS
 *  denominator [IN]
 *  numerator   [IN]
 * RETURNS
 *  Return the remainder of denominator / numerator
 *****************************************************************************/
static int fmod(int denominator, int numerator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = denominator;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (ret >= numerator)
        ret = ret - numerator;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  GetHashValue
 * DESCRIPTION
 *  Calculate the hash value of input string
 * PARAMETERS
 *  string      [IN]
 *  hash_range  [IN]
 * RETURNS
 *  Return the hash value
 *****************************************************************************/
static int GetHashValue(wchar_t *string, int hash_range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int length = mask_length(hash_range);
    int mask = (int)pow(2, length) - 1;
    int i = 0;
    long val = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (int)wcslen(string); i++)
    {
        val += ((string[i] + val * 37) & mask);
    }
    val = fmod(val, hash_range);
    return (int)val;
}


/*****************************************************************************
 * FUNCTION
 *  Trans
 * DESCRIPTION
 *  Transform UCS2-encoding "\","n" to "\n"
 * PARAMETERS
 *  string  [IN]
 *  buf     [OUT]
 * RETURNS
 *  Return 1 if transformed, otherwise, return 0
 *****************************************************************************/
static int Trans(wchar_t *string, wchar_t *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    int l = 0, ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < wcslen(string); i++)
    {
        if (string[i] == L'\\' && string[i + 1] == L'n')
        {
            buf[l] = '\n';
            i++;
            ret = 1;
        }
        else
            buf[l] = string[i];
        l++;
    }
    buf[l] = L'\0';
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  UCS2ASCII_CR
 * DESCRIPTION
 *  Convert wide character to ASCII character, removing charcters after CR
 * PARAMETERS
 *  w_in    [IN]
 *  a_out   [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void UCS2ASCII_CR(char *w_in, char *a_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (w_in[i] != '\0' || w_in[i + 1] != '\0')
    {
        a_out[i >> 1] = w_in[i];
        i += 2;
    }
    a_out[i >> 1] = '\0';
    i = i >> 1;
    i--;
    while (i >= 0)
    {
        if (a_out[i] == 0x0D)
        {
            a_out[i] = '\0';
            break;
        }
        else
            i--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ifLanguageUsed
 * DESCRIPTION
 *  Decide if the translated language should be used for string resource, 
 *  according to SSC string
 * PARAMETERS
 *  ssc_ref [IN]
 * RETURNS
 *  Return -1 if the language is not used, otherwise, return non-negative index
 *****************************************************************************/
static int ifLanguageUsed(wchar_t *ssc_ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    char ascii_ssc[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UCS2ASCII_CR((char *)ssc_ref, ascii_ssc);
    for (i = 0; i < mtk_gMaxDeployedLangs; i++)
    {
        if (strcmp(mtk_gLanguageArray[i].aLangSSC, ascii_ssc) == 0)
        {
            return i;
        }
    }
    return -1;
}

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  GetStrByRef
 * DESCRIPTION
 *  Get string content according to reference index
 *  The string content depends on whether it is duplicated or not
 * PARAMETERS
 *  strres     [IN] string resource
 *  strres_dup [IN] duplicated string resource
 *  lang_idx   [IN] language index in process
 *  id_count   [IN] string id in current language
 *  ref_idx    [IN] string reference index in current language
 * RETURNS
 *  Return the string content
 *****************************************************************************/
static wchar_t* GetStrByRef(StrRes *strres, DupStrRes *strres_dup, int lang_idx, int id_count, int ref_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!strres[lang_idx].is_dup[id_count])
    {
        return strres[lang_idx].Str[ref_idx];
    }
    else
    {
        return strres_dup->Str[ref_idx];
    }    
}

/*****************************************************************************
 * FUNCTION
 *  LookupDupStr
 * DESCRIPTION
 *  Look up potential duplicated strings in languages excluding the current language
 *  If found :
 *  1. turn on dup flag 
 *  2. assign string reference index
 *  If found first time :
 *  1. put the string into duplicated string resource
 *  2. traverse the linked list for the duplicated string in the same language, 
 *     turn on dup flags and re-assign the correct string reference index in duplicated string resource
 * PARAMETERS
 *  strres     [INOUT] string resource
 *  strres_dup [INOUT] duplicated string resource
 *  cur_lang   [IN] current language index in process
 *  id_count   [IN] string id in current language
 *  ht         [IN] hash table
 *  hash_value [IN] hash value of the string in process
 *  tok        [IN] the string in process
 * RETURNS
 *  Return 1 if any duplicated string is found, otherwise return 0
 *****************************************************************************/
static int LookupDupStr(StrRes *strres, DupStrRes *strres_dup, int cur_lang, int id_count, struct HashItem **ht, int hash_value, wchar_t *tok)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct HashItem *temp = NULL;   
    wchar_t *str; 
    int lang_idx, ref_idx;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (lang_idx = 0; lang_idx < mtk_gMaxDeployedLangs; lang_idx++)
    {
        if (lang_idx != cur_lang && mtk_gLanguageFlag[lang_idx])
        {
            if (ht[lang_idx][hash_value].pointer != -1)
            {
                /* there is a string with the same hash value in another language */
                temp = &ht[lang_idx][hash_value];
                while (temp != NULL)
                {
                    ref_idx = strres[lang_idx].StrRef[temp->pointer];
                    str = GetStrByRef(strres, strres_dup, lang_idx, temp->pointer, ref_idx);
                    if (wcscmp(tok, str) == 0)
                    {
                        /* they are duplicated strings */
                        strres[cur_lang].is_dup[id_count] = 1;
                        strres[cur_lang].StrRef[id_count] = ref_idx;
                        /* check if this duplicated string has already been found before */
                        if (!strres[lang_idx].is_dup[temp->pointer])
                        {
                            /* first time found */
                            strres[lang_idx].is_dup[temp->pointer] = 1;
                            strres[lang_idx].StrRef[temp->pointer] = strres_dup->MaxNum;
                            strres[lang_idx].TotalLength -= wcslen(tok) * 2 + 2;
                            strres[cur_lang].StrRef[id_count] = strres_dup->MaxNum;
                            strres_dup->Str[strres_dup->MaxNum] = strres[lang_idx].Str[ref_idx];
                            strres[lang_idx].Str[ref_idx] = NULL;
                            /* traverse the linked list, turn on dup flags and 
                             * change string reference index for the dup strings in the same lang
                             */
                            while (temp->next != NULL)
                            {
                                temp = temp->next;
                                if ((!strres[lang_idx].is_dup[temp->pointer])
                                    && (strres[lang_idx].StrRef[temp->pointer] == ref_idx))
                                {
                                    strres[lang_idx].is_dup[temp->pointer] = 1;
                                    strres[lang_idx].StrRef[temp->pointer] = strres_dup->MaxNum;           
                                }
                            }
                            strres_dup->MaxNum++;
                        }
                        return 1;
                    }
                    temp = temp->next;
                }
            }
        }
    }   
    return 0;      
}


/*****************************************************************************
 * FUNCTION
 *  GetStrResList
 * DESCRIPTION
 *  Generate a non-duplicate string list from input file, using hash table
 * PARAMETERS
 *  result  [OUT]
 * RETURNS
 *  Return number of all populated string IDs
 *****************************************************************************/
static int GetStrResList(StrResSet *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct HashItem **ht = NULL, *extra = NULL, *temp = NULL;
    struct StrRes *strres = NULL;
    wchar_t *tok = NULL;
    wchar_t *tok_eng = NULL;    
    int i = 0, j = 0, k = 0, h = 0, l = 0;
    int LangIndex = 0;
    int hash_range = 0;
    int ref_item_found = 0;

  #ifdef MEM_REF_LIST_OPT
      RefListItem * tmp_list_item = NULL; /* temp buffer of ref list item */
  #endif /*MEM_REF_LIST_OPT*/

    /* add a data structure to record duplicated strings in different language */
    struct DupStrRes *strres_dup;

    U16 nStrId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strres = malloc(sizeof(struct StrRes) * mtk_gMaxDeployedLangs);
    if (strres == NULL) {STRMERG_LOG_E("malloc fail strres "); exit(2);}
    ht = malloc(sizeof(struct HashItem *) * mtk_gMaxDeployedLangs);
    if (ht == NULL) {STRMERG_LOG_E("malloc fail ht "); exit(2);}
    /* allocate memory */
    strres_dup = malloc(sizeof(struct DupStrRes));
    if (strres_dup == NULL) {STRMERG_LOG_E("malloc fail strres_dup "); exit(2);}
    strres_dup->Str = (wchar_t **)malloc(sizeof(wchar_t *) * CurrMaxTransStrId * 3);
    if (strres_dup->Str == NULL) {STRMERG_LOG_E("malloc fail strres_dup->Str "); exit(2);}
    /* init */
    strres_dup->MaxNum = 0;

    mtk_gLanguageFlag = malloc(sizeof(int) * mtk_gMaxDeployedLangs);
    if (mtk_gLanguageFlag == NULL) {STRMERG_LOG_E("malloc fail mtk_gLanguageFlag "); exit(2);}
    for (h = 0; h < mtk_gMaxDeployedLangs; h++)
    {
        mtk_gLanguageFlag[h] = 0;
    }

    for (j = 0; j < nUsedLang; j++)
    {
        wcscpy(ref_tmp, filter_ref_ssc);
        tok = wcstok(ref_tmp, DELIMETER);   /* ENUM */
        tok = wcstok(NULL, DELIMETER);      /* MODULE NAME */
        tok = wcstok(NULL, DELIMETER);      /* MAX LENGTH */
        tok = wcstok(NULL, DELIMETER);      /* DESCRIPTION */

        /* change to corresponding language column according to j */
        for (k = 0; k < j + 1; k++)
        {
            tok = wcstok(NULL, DELIMETER);
        }
        ASSERT(tok != NULL);
        LangIndex = ifLanguageUsed(tok);

        if (LangIndex < 0) /* the language is not used in font resource */
            continue;

        mtk_gLanguageFlag[LangIndex] = 1;

        strres[LangIndex].Str = (wchar_t **)malloc(sizeof(wchar_t *) * CurrMaxTransStrId);
        if (strres[LangIndex].Str == NULL) {STRMERG_LOG_E("malloc fail strres[LangIndex].Str "); exit(2);}
        strres[LangIndex].StrRef = (int *)malloc(sizeof(int) * CurrMaxTransStrId);
        if (strres[LangIndex].StrRef == NULL) {STRMERG_LOG_E("malloc fail strres[LangIndex].StrRef "); exit(2);}
        /* allocate memory */
        strres[LangIndex].is_dup= (char *)malloc(sizeof(char) * CurrMaxTransStrId);
        if (strres[LangIndex].is_dup == NULL) {STRMERG_LOG_E("malloc fail strres[LangIndex].is_dup "); exit(2);}
        /* set default value */
        for (l = 0; l < CurrMaxTransStrId; l++)
        {
            strres[LangIndex].StrRef[l] = -1;
            strres[LangIndex].TotalLength = 0;
            /* set default value */
            strres[LangIndex].is_dup[l] = 0;
        }

        /* set hash_range as maximum id times 1.1(Can be changed) */
        hash_range = (int)(CurrMaxTransStrId * 1.1);

        /* initialize hash table */
        ht[LangIndex] = (struct HashItem *)malloc(sizeof(struct HashItem) * hash_range);
        if (ht[LangIndex] == NULL) {STRMERG_LOG_E("malloc fail ht[LangIndex] "); exit(2);}
        for (k = 0; k < hash_range; k++)
        {
            ht[LangIndex][k].next = NULL;
            ht[LangIndex][k].pointer = -1;
        }

        k = 0;
        i = 0;  /* number of Ref(non-duplicate strings, excluding NULL) */
        l = -1; /* number of ID (all strings) */

        while (l < CurrMaxTransStrId - 1)
        {
            l++;
            nStrId = StrID[l];

            /* check if ID already found in ref_list.txt, save the result in ref_item_found */
            if (StrLine[nStrId] != 0)
            {
#ifndef MEM_REF_LIST_OPT
                wcscpy(ref_tmp, ref_all + (StrLine[nStrId] - 1) * g_line_buf_act_length);
#else
                tmp_list_item = GetRefListItem(ref_all_list,(StrLine[nStrId] - 1));
                if(tmp_list_item!=NULL)
                {
                    wcscpy(ref_tmp,tmp_list_item->ItemData );
                    ref_item_found = 1;
                }
                else
                {
                    // Reset the buffer
                    wcscpy(ref_tmp,L"");
                    STRMERG_LOG_E("No REF item found for String: %d", nStrId);
                    ref_item_found = 0;
                }
#endif
            }

                if(ref_item_found == 1){
                tok = wcstok(ref_tmp, DELIMETER);
                tok = wcstok(NULL, DELIMETER);  /* skip originally existing Module Name */
                tok = wcstok(NULL, DELIMETER);  /* skip originally existing Max String Length */
                tok = wcstok(NULL, DELIMETER);  /* skip originally existing Description */
                /* change to corresponding language column according to j */
                for (k = 0; k < j + 1; k++)
                {
                    tok = wcstok(NULL, DELIMETER);
                    if (k == 0)
                    {
                        tok_eng = tok;
                    }
                    /* here possible case for tok to be NULL? */

                    if (tok != NULL && tok[wcslen(tok) - 1] == (wchar_t)'\n')
                    {
                        /* remove carriage-return */
                        tok[wcslen(tok) - 2] = '\0';
                    }
                }
            }
            else
            {
                /* no corresponding line in ref_list.txt */
                // TODO: maybe we do not need to do this because processed this part in MergeStrRes
                if(fixed_id.fixed_id_flag[nStrId] == TRANSLATE_FLAG)
                {
                    strres[LangIndex].MaxID = strres[LangIndex].MaxID - 1;
                    fixed_id.fixed_id_flag[nStrId] = NO_TRANSLATE_FLAG;
                }
                continue;
            }

            /* decise if the read-in string is " " (blank) */
            if (tok != NULL && tok[0] == 20 && tok[1] == 0)
                tok = NULL;
            /* handling NULL read-in string, it's Ref is default value -1 */
            if (tok == NULL)
            {
                /* nothing to be done */
            }
            else if (tok[0] == NO_TRANSLATION_MARKER && tok[1] == 0)
            {
                /* Use English translation in ref_list */
                if (LangIndex == 0)
                {
                /* no translation for current language */
                tok = (wchar_t *)Str[nStrId];
            }
                else
                {
                    tok = (wchar_t *)tok_eng;
                }
            }

            if (tok != NULL)
            {
                /* transform "\""n" */
                Trans(tok, tok);

                /* calculate hash value */
                h = GetHashValue(tok, hash_range);
                if (ht[LangIndex][h].pointer == -1)
                {
                    /* no duplicate hash value */
                    ht[LangIndex][h].pointer = l;
                    ht[LangIndex][h].next = NULL;
                    /* check if this is a duplicated string already in other languages */
                    if (!LookupDupStr(strres, strres_dup, LangIndex, l, ht, h, tok))
                    {
                        /* record max offset of each language in byte */
                    strres[LangIndex].Str[i] = (wchar_t *)malloc(wcslen(tok) * 2 + 2);
                    if (strres[LangIndex].Str[i] == NULL) {STRMERG_LOG_E("malloc fail strres[LangIndex].Str[i] "); exit(2);}
                    wcscpy(strres[LangIndex].Str[i], tok);
                    /* insert the string into the list */
                    strres[LangIndex].StrRef[l] = i;
                        strres[LangIndex].TotalLength += wcslen(tok) * 2 + 2;                            
                    i++;
                }
                }
                else
                {
                    /* 
                     * there are duplicate hash value, check if the string 
                     * is really the same with that has the same hash value
                     */
                    int found = 0, ref_idx;
                    wchar_t *str;
                    ref_idx = strres[LangIndex].StrRef[ht[LangIndex][h].pointer];
                    str = GetStrByRef(strres, strres_dup, LangIndex, ht[LangIndex][h].pointer, ref_idx);
                    if (wcscmp(tok, str) == 0)
                    {
                        /* the two string is the same */
                        strres[LangIndex].StrRef[l] = ref_idx;
                        strres[LangIndex].is_dup[l] = strres[LangIndex].is_dup[ht[LangIndex][h].pointer];
                        /* put it into linked list anyway */
                        extra = (struct HashItem *)malloc(sizeof(struct HashItem));
                        if (extra == NULL) {STRMERG_LOG_E("malloc fail extra "); exit(2);}
                        temp = &ht[LangIndex][h];
                        extra->next = temp->next;
                        extra->pointer = l;
                        temp->next = extra;                                                
                        /* read in next string */
                        continue;
                    }

                    /* 
                     * although the two strings have the same hash value, 
                     * but they are different
                     * compare the strings in linked list...
                     */
                    temp = &ht[LangIndex][h];
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                        ref_idx = strres[LangIndex].StrRef[temp->pointer];
                        str = GetStrByRef(strres, strres_dup, LangIndex, temp->pointer, ref_idx);
                        if (wcscmp(tok, str) == 0)
                        {
                            /* find a identical string in linked list, set the flag on */
                            found = 1;
                            strres[LangIndex].StrRef[l] = ref_idx;
                            strres[LangIndex].is_dup[l] = strres[LangIndex].is_dup[temp->pointer];
                            /* put it into linked list anyway */
                            extra = (struct HashItem *)malloc(sizeof(struct HashItem));                            
                            if (extra == NULL) {STRMERG_LOG_E("malloc fail extra "); exit(2);}
                            extra->next = temp->next;
                            extra->pointer = l;
                            temp->next = extra;                                                                            
                            break;
                        }
                    }
                    if (found == 0)
                    {
                        /* 
                         * the input string is different with all other 
                         * strings in hash table, add the string in linked 
                         * list
                         */
                        extra = (struct HashItem *)malloc(sizeof(struct HashItem));
                        if (extra == NULL) {STRMERG_LOG_E("malloc fail extra "); exit(2);}
                        extra->next = NULL;
                        extra->pointer = l;
                        temp->next = extra;
                        if (!LookupDupStr(strres, strres_dup, LangIndex, l, ht, h, tok))
                        { 
                        strres[LangIndex].Str[i] = malloc(wcslen(tok) * 2 + 2);
                        if (strres[LangIndex].Str[i] == NULL) {STRMERG_LOG_E("malloc fail strres[LangIndex].Str[i] "); exit(2);}
                        wcscpy(strres[LangIndex].Str[i], tok);
                        strres[LangIndex].StrRef[l] = i;
                            strres[LangIndex].TotalLength += wcslen(tok) * 2 + 2;
                        i++;
                    }
                    }
                    else
                        found = 0; /* reset the flag */
                }
            }
        }

        strres[LangIndex].MaxID = l + 1;
        strres[LangIndex].MaxNum = i;
    }
    result->iLang = mtk_gMaxDeployedLangs;
    result->strres = strres;
    /* record duplicated string resource */
    result->strres_dup = strres_dup;

    return CurrMaxTransStrId;
}
#else /* __MMI_RESOURCE_ENFB_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  GetStrResList
 * DESCRIPTION
 *  Generate a non-duplicate string list from input file, using hash table
 * PARAMETERS
 *  result  [OUT]
 * RETURNS
 *  Return number of all populated string IDs
 *****************************************************************************/
static int GetStrResList(StrResSet *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct HashItem **ht = NULL, *extra = NULL, *temp = NULL;
    struct StrRes *strres = NULL;
    wchar_t *tok = NULL;
    wchar_t *tok_eng = NULL;  
    int i = 0, j = 0, k = 0, h = 0, l = 0;
    int LangIndex = 0;
    int hash_range = 0;
    int ref_item_found = 0;
#ifdef MEM_REF_LIST_OPT
    RefListItem * tmp_list_item = NULL;
#endif

    U16 nStrId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strres = malloc(sizeof(struct StrRes) * mtk_gMaxDeployedLangs);
    ht = malloc(sizeof(struct HashItem *) * mtk_gMaxDeployedLangs);

    mtk_gLanguageFlag = malloc(sizeof(int) * mtk_gMaxDeployedLangs);
    for (h = 0; h < mtk_gMaxDeployedLangs; h++)
    {
        mtk_gLanguageFlag[h] = 0;
    }

    for (j = 0; j < nUsedLang; j++)
    {
        wcscpy(ref_tmp, filter_ref_ssc);
        tok = wcstok(ref_tmp, DELIMETER);   /* ENUM */
        tok = wcstok(NULL, DELIMETER);      /* MODULE NAME */
        tok = wcstok(NULL, DELIMETER);      /* MAX LENGTH */
        tok = wcstok(NULL, DELIMETER);      /* DESCRIPTION */

        /* change to corresponding language column according to j */
        for (k = 0; k < j + 1; k++)
        {
            tok = wcstok(NULL, DELIMETER);
        }
        ASSERT(tok != NULL);
        LangIndex = ifLanguageUsed(tok);

        if (LangIndex < 0) /* the language is not used in font resource */
            continue;

        mtk_gLanguageFlag[LangIndex] = 1;

        strres[LangIndex].Str = (wchar_t **)malloc(sizeof(wchar_t *) * CurrMaxStringId);
        strres[LangIndex].StrRef = (int *)malloc(sizeof(int) * CurrMaxStringId);
        /* set default value */
        for (l = 0; l < CurrMaxStringId; l++)
        {
            strres[LangIndex].StrRef[l] = -1;
            strres[LangIndex].TotalLength = 0;
        }

        /* set hash_range as maximum id times 1.1(Can be changed) */
        hash_range = (int)(CurrMaxStringId * 1.1);

        /* initialize hash table */
        ht[LangIndex] = (struct HashItem *)malloc(sizeof(struct HashItem) * hash_range);
        for (k = 0; k < hash_range; k++)
        {
            ht[LangIndex][k].next = NULL;
            ht[LangIndex][k].pointer = -1;
        }

        k = 0;
        i = 0;  /* number of Ref(non-duplicate strings, excluding NULL) */
        l = -1; /* number of ID (all strings) */

        while (l < CurrMaxStringId - 1)
        {
            l++;
            nStrId = StrID[l];

            /* check if ID already found in ref_list.txt */
            if (StrLine[nStrId] != 0)
            {
#ifndef MEM_REF_LIST_OPT
                wcscpy(ref_tmp, ref_all + (StrLine[nStrId] - 1) * g_line_buf_act_length);
#else
                tmp_list_item = GetRefListItem(ref_all_list,(StrLine[nStrId] - 1));
                if(tmp_list_item != NULL)
                {
                    ref_item_found = 1;
                    wcscpy(ref_tmp,tmp_list_item->ItemData );  
                }else
                {
                    ref_item_found = 0;
                    STRMERG_LOG_E("No Ref List item for %d: ",nStrId);
                    fflush(stdout);
                    wcscpy(ref_tmp,L""); 
                }
#endif
            }

            if(ref_item_found == 1)
            {
                tok = wcstok(ref_tmp, DELIMETER);
                tok = wcstok(NULL, DELIMETER);  /* skip originally existing Module Name */
                tok = wcstok(NULL, DELIMETER);  /* skip originally existing Max String Length */
                tok = wcstok(NULL, DELIMETER);  /* skip originally existing Description */
                /* change to corresponding language column according to j */
                for (k = 0; k < j + 1; k++)
                {
                    tok = wcstok(NULL, DELIMETER);
                    if (k == 0)
                    {
                        tok_eng = tok;
                    }

                    /* here possible case for tok to be NULL? */

                    if (tok != NULL && tok[wcslen(tok) - 1] == (wchar_t)'\n')
                    {
                        /* remove carriage-return */
                        tok[wcslen(tok) - 2] = '\0';
                    }
                }
            }
            else
            {
                /* no corresponding line in ref_list.txt */
                tok = (wchar_t *)Str[nStrId];
            }

            /* decise if the read-in string is " " (blank) */
            if (tok != NULL && tok[0] == 20 && tok[1] == 0)
                tok = NULL;
            /* handling NULL read-in string, it's Ref is default value -1 */
            if (tok == NULL)
            {
                /* nothing to be done */
            }
            else if (tok[0] == NO_TRANSLATION_MARKER && tok[1] == 0)
            {
                /* Use English translation in ref_list */
                if (LangIndex == 0)
                {
                /* no translation for current language */
                tok = (wchar_t *)Str[nStrId];
                }
                else
                {
                    tok = (wchar_t *)tok_eng;
                }

            }

            if (tok != NULL)
            {
                /* transform "\""n" */
                Trans(tok, tok);

                /* calculate hash value */
                h = GetHashValue(tok, hash_range);
                if (ht[LangIndex][h].pointer == -1)
                {
                    /* no duplicate hash value */
                    ht[LangIndex][h].pointer = i;
                    ht[LangIndex][h].next = NULL;
                    strres[LangIndex].Str[i] = (wchar_t *)malloc(wcslen(tok) * 2 + 2);
                    wcscpy(strres[LangIndex].Str[i], tok);
                    /* insert the string into the list */
                    strres[LangIndex].StrRef[l] = i;
                    strres[LangIndex].TotalLength += wcslen(tok) + 1;
                    i++;
                }
                else
                {
                    /* 
                     * there are duplicate hash value, check if the string 
                     * is really the same with that has the same hash value
                     */
                    int found = 0;
                    if (wcscmp(tok, strres[LangIndex].Str[ht[LangIndex][h].pointer]) == 0)
                    {
                        /* the two string is the same */
                        strres[LangIndex].StrRef[l] = ht[LangIndex][h].pointer;
                        /* read in next string */
                        continue;
                    }

                    /* 
                     * although the two strings have the same hash value, 
                     * but they are different
                     * compare the strings in linked list...
                     */
                    temp = &ht[LangIndex][h];
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                        if (wcscmp(tok, strres[LangIndex].Str[temp->pointer]) == 0)
                        {
                            /* find a identical string in linked list, set the flag on */
                            found = 1;
                            strres[LangIndex].StrRef[l] = temp->pointer;
                            break;
                        }
                    }
                    if (found == 0)
                    {
                        /* 
                         * the input string is different with all other 
                         * strings in hash table, add the string in linked 
                         * list
                         */
                        extra = (struct HashItem *)malloc(sizeof(struct HashItem));
                        extra->next = NULL;
                        extra->pointer = i;
                        temp->next = extra;
                        strres[LangIndex].Str[i] = malloc(wcslen(tok) * 2 + 2);
                        wcscpy(strres[LangIndex].Str[i], tok);
                        strres[LangIndex].StrRef[l] = i;
                        strres[LangIndex].TotalLength += wcslen(tok) + 1;
                        i++;
                    }
                    else
                        found = 0; /* reset the flag */
                }
            }
        }

        strres[LangIndex].MaxID = l + 1;
        strres[LangIndex].MaxNum = i;
    }
    result->iLang = mtk_gMaxDeployedLangs;
    result->strres = strres;

    return CurrMaxStringId;
}
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  print_language_usage
 * DESCRIPTION
 *  dump mtk_gLanguageArray to language_usage.txt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void print_language_usage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp = fopen(".\\\\debug\\\\language_usage.txt", "wb");
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fp != NULL)
    {
        fwprintf(fp, L"%ls\t%ls\t%ls\n", L"Name", L"SSC", L"LCC");
        for (i = 0 ; i < mtk_gMaxDeployedLangs ; i++)
        {
            S8 ssc[SSC_SIZE*2] = {0}, lcc[LCC_SIZE*2] = {0};
            S32 j;

            for (j = 0 ; j < strlen(mtk_gLanguageArray[i].aLangSSC) ; j++)
                ssc[2*j] = (mtk_gLanguageArray[i].aLangSSC[j]), ssc[2*j + 1] = 0;
            for (j = 0 ; j < strlen(mtk_gLanguageArray[i].aLangCountryCode) ; j++)
                lcc[2*j] = (mtk_gLanguageArray[i].aLangCountryCode[j]), lcc[2*j + 1] = 0;
			#ifdef __IOT__
			fwprintf(fp, L"%ls\t%ls\n",ssc, lcc);
			#else
            fwprintf(fp, L"%ls\t%ls\t%ls\n", mtk_gLanguageArray[i].aName, ssc, lcc);
			#endif
        }
        fclose(fp);

        fprintf(stderr, "output language_usage.txt done.\n");
    }
}


/*****************************************************************************
 * FUNCTION
*  GetItemAsc
* DESCRIPTION
*  Get token between index and index+1 DELIMETER
* PARAMETERS
*  string  [IN]
*  index   [IN]
*  buf     [OUT]
* RETURNS
*  void
*****************************************************************************/
static void GetItemAsc(char *string, int index, char *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *p1 = string;
    char *p2 = strstr(string, "\t");
    int n = p2 - p1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(p2 != NULL);

    while (index > 0)
    {
        p1 = p2 + 1;
        p2 = strstr(p1, "\t");
        n = p2 - p1;
        index--;
        if (p2 == NULL)
            break;
    }
    
    if (index > 0)
    {
        buf[0] = '\0';
    }
    else if (p2 == NULL)
    {
        /*
        strcpy(buf, p1);
        n = strstr(p1, "\n") - p1;
        buf[n] = '\0';
        */
    }
    else
    {
        ASSERT(p1 != NULL);
        strncpy(buf, p1, n);
        buf[n] = '\0';
    }
}

// Add margin size only when __CAT_SUPPORT__ is defined
static void append_cat_padding_bytes(FILE * file, long originalElementNumber){
#if defined(__CAT_SUPPORT__) && defined (MMIRESOURCE_CAT_STR_COMPRESS_RESERVED_MARGIN_SIZE_BYTE) && ( MMIRESOURCE_CAT_STR_COMPRESS_RESERVED_MARGIN_SIZE_BYTE > 0 )
    str_add_pedding_bytes(file, 0xFF, MMIRESOURCE_CAT_STR_COMPRESS_RESERVED_MARGIN_SIZE_BYTE, originalElementNumber);
#endif //CAT_STR_COMPRESS_MARGIN_SIZE
}

void str_add_pedding_bytes(FILE * file, int peddingValue, int peddingSize, long originalElementNumber){
    int z = 0;
    int formattingOffset = originalElementNumber %16;
    fprintf(file, "\n");
    for (z = 0; z < peddingSize; z++)
    {
      fprintf(file, "0x%02X, ", peddingValue);
      if ((z+1)%16 == 0)
      {
        fprintf(file, "\n");
      }
    }

}


/*****************************************************************************
 * FUNCTION
 *  GenerateStrResFile
 * DESCRIPTION
 *  Generate string resource C files
 * PARAMETERS
 *  void
 * RETURNS
 *  Return 0 on success, otherwise, return -1
 *****************************************************************************/
int GenerateStrResFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fout_res = NULL;
    FILE *fout_map = NULL;
    FILE *fout_meta_res = NULL;
    FILE *fout_meta_map = NULL;
	
    int i = 0, MaxID = 0, str_res_id = 0;
    unsigned short z = 0;
    int start = 0, index_map = 0, index = 0, num_map_search = 0;
    int min_id = 0, max_id = 0;
    struct StrRes *strres = NULL;
    struct StrResSet Strresset;

    U32 res_size[512];
    U32 map_size[512];
    U32 reszip_size[512];
    U32 mapzip_size[512];
    FILE *pFile;

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    /* add DupStrRes and max_total_len */
    struct DupStrRes *strres_dup = NULL;
    int max_total_len = 0;
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
    int max_zip_len = 0;

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    FILE *fout_enfb = NULL;
    U32 enfb_size = 0, enfb_offset = 0;
    U32 enfb_str_mem_size, enfb_max_mem_size = 0;
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    print_language_usage();

    memset(StrSize, 0, sizeof(U16) * MAX_STRING_MAP_SIZE);

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    memset(&fixed_result, 0, sizeof(FixedResult));
    /* init */
    Strresset.strres_dup = NULL;
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    /* get string table */
    MaxID = GetStrResList(&Strresset);

#ifndef MEM_REF_LIST_OPT
    if (ref_all)
        free(ref_all);
#else
    if(ref_all_list){
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "Free ref_all_list: (%lu) bytes ",ref_all_list->AllocatedSize);
        DeleteRefList(ref_all_list);
  }
#endif

    /* open output file */
    fout_res = fopen(STR_DATA_FILENAME, "wb");
    fout_map = fopen(STR_MAP_FILENAME, "wb");
    /* Meta file for string compression */
    fout_meta_res = fopen(STR_DATA_META_FILENAME, "wb");
    fout_meta_map = fopen(STR_MAP_META_FILENAME, "wb");
	
    if (fout_res == NULL || fout_map == NULL ||fout_meta_res == NULL || fout_meta_map == NULL)
    {
        STRMERG_LOG_E("fout_res or fout_map open error (%d)(%d) ...!", fout_res, fout_map);
        goto GEN_STR_ERR_RET;
    }
    strres = Strresset.strres;
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    /* assign */
    strres_dup = Strresset.strres_dup;
#endif

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    fout_enfb = fopen(ENFB_STRING_DATA_FILENAME, "wb");
    if (fout_enfb == NULL)
    {
        STRMERG_LOG_E("File open error (%s) ...!", ENFB_STRING_DATA_FILENAME);
        goto GEN_STR_ERR_RET;
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    /* print output file header */
    fprintf(fout_res, "#include \"mmi_features.h\"\n");
    fprintf(fout_res, "#include \"CompressResUtil.h\"\n\n\n");
    fprintf(fout_res, "#include \"CustDataRes.h\"\n");
    fprintf(fout_res, "#include \"FontDCl.h\"\n\n\n");
    fprintf(fout_res, "#if (!defined (__MTK_TARGET__))\n\t#define __align(x)\n#endif\n\n\n");
    fprintf(fout_res, "#if !defined(__MMI_RESOURCE_STR_LZMA_COMPRESS__) && !defined(__MMI_RESOURCE_STR_THIRD_ROM__)\n");
    fprintf(fout_map, "#include \"mmi_features.h\"\n");
    fprintf(fout_map, "#include \"CompressResUtil.h\"\n\n\n");
    fprintf(fout_map, "#if !defined(__MMI_RESOURCE_STR_LZMA_COMPRESS__) && !defined(__MMI_RESOURCE_STR_THIRD_ROM__)\n");
    fprintf(fout_map, "#include \"CustDataRes.h\"\n");
    fprintf(fout_map, "#if (!defined (__MTK_TARGET__))\n\t#define __align(x)\n#endif\n\n\n");
#ifdef __CAT_SUPPORT__
    fprintf(fout_map, ResgenCATGetRegionStartStatment(MMIRESOURCE_CAT_RES_TYPE_ID_STR));
    fprintf(fout_res, ResgenCATGetRegionStartStatment(MMIRESOURCE_CAT_RES_TYPE_ID_STR));
#endif //__CAT_SUPPORT__

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    /* generate duplicated string resource */
    if (strres_dup->MaxNum > 0)
    {

#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
    if (mmi_res_zip_language[MAX_LANGUAGES] == 1)
    {
        /* The len for compresss2 function must be unsigned long*/
        unsigned long array_size = 0, dest_size = 0, input_buf_size = 0;
        U8 *buffer = NULL;
        U8 *dest_buf = NULL;
        U8 *p = NULL;
        U16 strsize = 0;

        array_size = 2; /* for  buffer[0] and buffer[1] */
        for (str_res_id = 0; str_res_id < strres_dup->MaxNum; str_res_id++)
        {
            array_size += ((wcslen(strres_dup->Str[str_res_id])+1)*2);
        }
        dest_size = compressBound(array_size);

        buffer = malloc(array_size);
        dest_buf = malloc(dest_size);
        buffer[0] = '\0';
        buffer[1] = '\0';

        p = buffer+2;
        /* copy string to buffer */
        for (str_res_id = 0; str_res_id < strres_dup->MaxNum; str_res_id++)
        {
            strsize = (wcslen(strres_dup->Str[str_res_id]) + 1) * 2;
            memcpy(p, strres_dup->Str[str_res_id], strsize);
            p += strsize;
        }

        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrRes_zip_Dup: compress2 input: dest_size=%lu, array_size =%lu, level = %d",dest_size,array_size, Z_BEST_COMPRESSION);
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "Total size of compressing data= %d bytes (p-buffer), size calculated =%d ",p-buffer,array_size);

        compress2(dest_buf, &dest_size, buffer, array_size, Z_BEST_COMPRESSION);

        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrRes_zip_Dup: compress2 output: dest_size=%lu, array_size =%lu",dest_size,array_size);

        /* output CustStrRes.c */
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrRes_zip_Dup: Start to fout_res output");
        fprintf(fout_res, "//__align(4) CUSTOM_STRING StrRes_Dup[%lu];\n", array_size);
        fprintf(fout_res, "// StrRes_zip_Dup, DATA SIZE = %lu\n", dest_size);
        fprintf(fout_res, "__align(4) const CUSTOM_STRING StrRes_zip_Dup[] = {\n");

        for (z = 0; z < dest_size-1; ++z)
        {
            if (z%16 == 0)
            {
                fprintf(fout_res, "\n");
            }
            fprintf(fout_res, "0x%02X, ", dest_buf[z]);

        }
        fprintf(fout_res, "0x%02X, ", dest_buf[z]);
        
        append_cat_padding_bytes(fout_res, dest_size);
        
        fprintf(fout_res, "};\n");

        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrRes_zip_Dup: Finish fout_res output");

        res_size[511] = array_size;
        reszip_size[511] = dest_size;

        free(buffer);
        free(dest_buf);  

        array_size = 0;
        dest_size = 0;
           
    }
    else
#endif /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
    {
        /* output language structure title */
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrRes_Dup: Started fout_res output");

        fprintf(fout_res, "__align(4) const CUSTOM_STRING StrRes_Dup[] = {\n");
        fprintf(fout_meta_res, "########################################################\n");
        fprintf(fout_meta_res, "TYPE: RES\n");
        fprintf(fout_meta_res, "LANG: DUP\n");
        fprintf(fout_meta_res, "MAXNUM: %d\n",strres_dup->MaxNum -1);
        fprintf(fout_meta_res, "MAXID: %d\n", 1);
        fprintf(fout_meta_res, "DATA:\n__align(4) const CUSTOM_STRING StrRes_Dup[] = {\n");

        fputs("0x00, 0x00,\n", fout_res);
        fputs("0x00, 0x00,\n", fout_meta_res);
    
        for (str_res_id = 0; str_res_id < strres_dup->MaxNum; str_res_id++)
        {
            unsigned short nStringLen = 0;
            
        #ifndef __UCS2_ENCODING
            fprintf(fout_res, "\"%s\",\n", strres_dup.Str[str_res_id]);
            fprintf(fout_meta_res, "\"%s\",\n", strres_dup.Str[str_res_id]);
        #else /* __UCS2_ENCODING */
            nStringLen = wcslen(strres_dup->Str[str_res_id]);

            for (z = 0; z < nStringLen * 2; ++z)
            {
                unsigned char *abc = (unsigned char*)strres_dup->Str[str_res_id];

                fprintf(fout_res, "0x%X, ", abc[z]);
                fprintf(fout_meta_res, "0x%X, ", abc[z]);
            }

            fputs("0x00, 0x00,\n", fout_res);
            fputs("0x00, 0x00,\n", fout_meta_res);

         #endif /* __UCS2_ENCODING */
        }
        fprintf(fout_res, "};\n");
        fprintf(fout_meta_res, "};\n");

        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrRes_Dup: Finished fout_res output");
    }

        /* look for a max value of TotalLength in each language */
        for (i = 0; i < mtk_gMaxDeployedLangs; i++)
        {
            if (mtk_gLanguageFlag[i])
            {
                if (strres[i].TotalLength > max_total_len)
                {
                    max_total_len = strres[i].TotalLength;
                }
            }
        }
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "MAX Total length of each language: %d ", max_total_len);
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    is16bit = malloc(sizeof(MMI_BOOL) * mtk_gMaxDeployedLangs);
    ASSERT(is16bit != NULL);
    /* output string resource file */
    for (i = 0; i < mtk_gMaxDeployedLangs; i++)
    {
        int old_i = i;
        unsigned long nTotalLen = 0;

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        is16bit[i] = MMI_FALSE;
#else
        is16bit[i] = MMI_TRUE;
#endif

        if (mtk_gLanguageFlag[i] == 0)
        {
            wchar_t * err_msg = malloc((STRMERGE_ERR_MSG_LEN_MAX+1) * sizeof(wchar_t));
            swprintf(err_msg,L"Deployed languages not found in ref_list_translation.txt!\n");
            str_merge_set_err(STRMERGE_LOAD_SSC_ERR, err_msg);
            STRMERG_LOG_E(STRMERG_SUB_TAG_MEM "Please provide translated strings of %s in ref_list.txt !!!", mtk_gLanguageArray[i].aLangSSC);
            free(err_msg);
            i = 0;
        }



#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
    if (mmi_res_zip_language[i] == 1)
    {
        // The parameter for compress 2 must be type of ulong
        unsigned long array_size = 0, dest_size = 0;
        U8 *buffer = NULL;
        U8 *dest_buf = NULL;
        U8 *p = NULL;
        U16 strsize = 0;

        
        /*------ output CustStrRes.c ------*/
        array_size = 2;
        /* Calculate Size of Current string */
        for (str_res_id = 0; str_res_id < strres[i].MaxNum; str_res_id++)
        {
            /* check if it is a dup str */
            if (strres[i].Str[str_res_id] == NULL) 
                continue;

            array_size += ((wcslen(strres[i].Str[str_res_id])+1)*2);
        }
        if(max_zip_len < array_size)
        {
            max_zip_len = array_size;
        }

        // Calculate the dest_size, since the dest_size is in-out parameter
        // The size must be large enough. (ulong)
        dest_size = compressBound(array_size);

        buffer = malloc(array_size);
        dest_buf = malloc(dest_size);
        buffer[0] = '\0';
        buffer[1] = '\0';

        p = buffer+2;
        /* copy string to buffer */
        for (str_res_id = 0; str_res_id < strres[i].MaxNum; str_res_id++)
        {
            /* check if it is a dup str */
            if (strres[i].Str[str_res_id] == NULL) continue;
            
            strsize = (wcslen(strres[i].Str[str_res_id]) + 1) * 2;
            memcpy(p, strres[i].Str[str_res_id], strsize);
            p += strsize;
        }
        
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrRes_zip_%d[%lu]: compress2 input: dest_size=%lu, array_size =%lu, level = %d",old_i + 1, array_size,dest_size,array_size, Z_BEST_COMPRESSION);
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "Total size of compressing data= %lu bytes (p-buffer), size calculated =%lu ",p-buffer,array_size);
        
        compress2(dest_buf, &dest_size, buffer, array_size, Z_BEST_COMPRESSION);

        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrRes_zip_%d[%lu]: compress2 output: dest_size=%lu, array_size =%lu ",old_i + 1, array_size,dest_size,array_size);

        //fprintf(fout_res, "__align(4) CUSTOM_STRING StrRes_%d[%d];\n", old_i + 1, array_size);
        fprintf(fout_res, "// StrRes_zip_%d, DATA SIZE = %d \n", old_i + 1, dest_size);
        fprintf(fout_res, "__align(4) const U8 StrRes_zip_%d[] = {\n", old_i + 1);
        

        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrRes_zip_%d[%lu]: Started fout_res output",old_i + 1, dest_size);

        for (z = 0; z < dest_size-1; ++z)
        {
            if (z %16 == 0)
            {
                fprintf(fout_res, "\n");
            }
            fprintf(fout_res, "0x%02X, ", dest_buf[z]);
        }
        
        fprintf(fout_res, "0x%02X, ", dest_buf[z]);

        append_cat_padding_bytes(fout_res, dest_size);

        
        fprintf(fout_res, "};\n");

        fprintf(fout_res, "extern const U8 StrMap_zip_%d[];\n\n", old_i + 1);

        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrRes_zip_%d[%lu]: Finished fout_res output",old_i + 1, dest_size);

        res_size[i] = array_size;
        reszip_size[i] = dest_size;

        free(buffer);
        free(dest_buf);  

        array_size = 0;
        dest_size = 0;

        /*------ output CustStrMap.c ------*/

        /* Get 16bit or 32 bit ----Start */
        for (str_res_id = 0; str_res_id < strres[i].MaxID; str_res_id++)
        {
            unsigned int nStringLen = 0;
            int iterator = 0;
            wchar_t *wcString;

            if (strres[i].StrRef[str_res_id] == -1)
            {
                nTotalLen = 0;
            }
            else
            {
                nTotalLen = 2;
            }
            /* check if it is duplicated */ 
            if (strres[i].is_dup[str_res_id])
            {
                for (iterator = 0; iterator < strres[i].StrRef[str_res_id]; iterator++)
                {
                    nStringLen = 0;
                    nStringLen = wcslen(strres_dup->Str[iterator]);
                    wcString = NULL;
                    nTotalLen += ((nStringLen + 1) * 2);
                }
                /* add max_total_len offset to nTotalLen */
                nTotalLen += max_total_len;
            }
            else
            {
                for (iterator = 0; iterator < strres[i].StrRef[str_res_id]; iterator++)
                {
                    /* ignore dup str */
                    if (strres[i].Str[iterator])
                    {
                        nStringLen = 0;
                        nStringLen = wcslen(strres[i].Str[iterator]);
                        wcString = NULL;
                        nTotalLen += ((nStringLen + 1) * 2);
                    }
                }
            }

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
            if (nTotalLen/2 > 0xFFFF)
            {
                is16bit[i] = MMI_FALSE;
            }
#endif
        }
        /* Get 16bit or 32 bit -----END*/
        
        if (is16bit[i])        
        {
#if !defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
            fprintf(fout_res, "extern const CUSTOM_STRING_MAP_16 StrMap_%d[];\n\n", old_i + 1);
#else
            fprintf(fout_res, "//extern const CUSTOM_STRING_MAP_16 StrMap_%d[];\n\n", old_i + 1);
#endif //__MMI_RESOURCE_STR_ZLIB_COMPRESS__
            array_size = strres[i].MaxID * sizeof(U16);
        }
        else
        {
#if !defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
            fprintf(fout_res, "extern const CUSTOM_STRING_MAP StrMap_%d[];\n\n", old_i + 1);
#else
            fprintf(fout_res, "//extern const CUSTOM_STRING_MAP StrMap_%d[];\n\n", old_i + 1);
#endif //__MMI_RESOURCE_STR_ZLIB_COMPRESS__
            array_size = strres[i].MaxID * sizeof(U32);
        }             
        
        dest_size = compressBound(array_size);
        buffer = malloc(array_size);
        dest_buf = malloc(dest_size);
        
        p = buffer;

        /* Write data to buffer */
        for (str_res_id = 0; str_res_id < strres[i].MaxID; str_res_id++)
        {
            unsigned int nStringLen = 0;
            int iterator = 0;
            wchar_t *wcString;
            U32 res;
            U16 res_u16;

            if (strres[i].StrRef[str_res_id] == -1)
            {
                nTotalLen = 0;
            }
            else
            {
                nTotalLen = 2;
            }

            /* check if it is duplicated */ 
            if (strres[i].is_dup[str_res_id])
            {
                for (iterator = 0; iterator < strres[i].StrRef[str_res_id]; iterator++)
                {
                    nStringLen = 0;
                    nStringLen = wcslen(strres_dup->Str[iterator]);
                    wcString = NULL;
                    nTotalLen += ((nStringLen + 1) * 2);
                }
                /* add max_total_len offset to nTotalLen */
                nTotalLen += max_total_len;
            }
            else
            {
                for (iterator = 0; iterator < strres[i].StrRef[str_res_id]; iterator++)
                {
                    /* ignore dup str */
                    if (strres[i].Str[iterator])
                    {
                        nStringLen = 0;
                        nStringLen = wcslen(strres[i].Str[iterator]);
                        wcString = NULL;
                        nTotalLen += ((nStringLen + 1) * 2);
                    }
                }
            }

            
            if (is16bit[i])        
            {            
                res_u16 = nTotalLen / 2;
                memcpy(p, &res_u16, sizeof(U16));
                p+=sizeof(U16);
            }
            else
            {
                res = nTotalLen / 2;
                memcpy(p, &res, sizeof(U32));
                p+=sizeof(U32);                
            }
        }

        /* compresss data to dest_buf */
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrMap_zip_%d: compress2 input: dest_size=%lu, array_size =%lu, level = %d",old_i + 1,dest_size,array_size, Z_BEST_COMPRESSION);
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "Total size of compressing data= %lu bytes (p-buffer), size calculated =%lu ",p-buffer,array_size);

        compress2(dest_buf, &dest_size, buffer, array_size, Z_BEST_COMPRESSION);
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrMap_zip_%d compress2 output: dest_size=%lu, array_size =%lu ",old_i + 1,dest_size,array_size);

        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrMap_%d[%lu]: Started fout_res output",old_i + 1, array_size);

        /* Write compressed data to file */
        if (is16bit[i])        
        {
            fprintf(fout_map, "//__align(4) CUSTOM_STRING_MAP_16 StrMap_%d[%d];\n", old_i + 1, array_size/sizeof(U16));
        }
        else
        {
            fprintf(fout_map, "//CUSTOM_STRING_MAP StrMap_%d[%d];\n", old_i + 1, array_size/sizeof(U32));
        }

        fprintf(fout_map, "// StrMap_zip_%d, DATA SIZE = %d\n", old_i + 1, dest_size);        
        fprintf(fout_map, "__align(4) const U8 StrMap_zip_%d[] = {\n", old_i + 1);

        for (z = 0; z < dest_size-1; ++z)
        {

            if ((z+1)%16 == 0)
            {
                fprintf(fout_map, "\n");
            }
            fprintf(fout_map, "0x%02X, ", dest_buf[z]);
        }
        fprintf(fout_map, "0x%02X, ", dest_buf[z]);

        append_cat_padding_bytes(fout_map, dest_size);

        fprintf(fout_map, "};\n");
        
        
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrMap_%d[%lu]: Finished fout_res output",old_i + 1, array_size);
        
        map_size[i] = array_size;
        mapzip_size[i] = dest_size;   
        
        free(buffer);
        free(dest_buf);     

        array_size = 0;
        dest_size = 0;        
    }
    else
#endif /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
    {
        for (str_res_id = 0; str_res_id < strres[i].MaxID; str_res_id++)
        {
            unsigned int nStringLen = 0;
            int iterator = 0;
            wchar_t *wcString;

            if (strres[i].StrRef[str_res_id] == -1)
            {
                nTotalLen = 0;
            }
            else
            {
                nTotalLen = 2;
            }
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
            /* check if it is duplicated */ 
            if (strres[i].is_dup[str_res_id])
            {
                for (iterator = 0; iterator < strres[i].StrRef[str_res_id]; iterator++)
                {
                    nStringLen = 0;
                    nStringLen = wcslen(strres_dup->Str[iterator]);
                    wcString = NULL;
                    nTotalLen += ((nStringLen + 1) * 2);
                }
                /* add max_total_len offset to nTotalLen */
                nTotalLen += max_total_len;
            }
            else
            {
                for (iterator = 0; iterator < strres[i].StrRef[str_res_id]; iterator++)
                {
                    /* ignore dup str */
                    if (strres[i].Str[iterator])
                    {
                        nStringLen = 0;
                        nStringLen = wcslen(strres[i].Str[iterator]);
                        wcString = NULL;
                        nTotalLen += ((nStringLen + 1) * 2);
                    }
                }
            }

            if (nTotalLen/2 > 0xFFFF)
            {
                is16bit[i] = MMI_FALSE;
            }
#else /* __MMI_RESOURCE_ENFB_SUPPORT__ */
            for (iterator = 0; iterator < strres[i].StrRef[str_res_id]; iterator++)
            {
                nStringLen = 0;
                nStringLen = wcslen(strres[i].Str[iterator]);
                wcString = NULL;
                nTotalLen += ((nStringLen + 1) * 2);
            }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

        }

        /* output language structure title */
        fprintf(fout_res, "__align(4) const CUSTOM_STRING StrRes_%d[] = {\n", old_i + 1);
        fprintf(fout_meta_res,  "########################################################\n");
        fprintf(fout_meta_res,  "TYPE: RES\n");
        fprintf(fout_meta_res,  "LANG: %d\n", old_i + 1);
        fprintf(fout_meta_res,  "MAXNUM: %d\n",strres[old_i].MaxNum);
        fprintf(fout_meta_res,  "MAXID: %d\n", strres[old_i].MaxID);
        fprintf(fout_meta_res,  "DATA:\n");
        fprintf(fout_meta_res,  "__align(4) const CUSTOM_STRING StrRes_%d[] = {\n", old_i + 1);
				

        /* output language map meta file*/
        fprintf(fout_meta_map,  "########################################################\n");
        fprintf(fout_meta_map,  "TYPE: MAP\n"); 
		fprintf(fout_meta_map,  "LANG: %d\n", old_i + 1);           
        if (is16bit[i])        
        {
            fprintf(fout_map, "__align(4) const CUSTOM_STRING_MAP_16 StrMap_%d[] = {\n", old_i + 1);
           fprintf(fout_meta_map, "BIT_MODE: 16\n");
           fprintf(fout_meta_map, "DATA:\n");
           fprintf(fout_meta_map, "__align(4) const CUSTOM_STRING_MAP_16 StrMap_%d[] = {\n", old_i + 1);
           
        }
        else
        {
            fprintf(fout_map, "const CUSTOM_STRING_MAP StrMap_%d[] = {\n", old_i + 1);
            fprintf(fout_meta_map, "BIT_MODE: 32\n");			
            fprintf(fout_meta_map, "DATA:\n");			
            fprintf(fout_meta_map, "const CUSTOM_STRING_MAP StrMap_%d[] = {\n", old_i + 1);
        }

    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        enfb_size = 0;
        enfb_str_mem_size = 0;
    #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

        /* output string resource header */
    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        fputc(0, fout_enfb);
        fputc(0, fout_enfb);
        enfb_size += 2;
    #else /* __MMI_RESOURCE_ENFB_SUPPORT__ */
        fputs("0x00, 0x00,\n", fout_res);
        fputs("0x00, 0x00,\n", fout_meta_res);
        
    #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

        /* output CustStrRes.c */
        for (str_res_id = 0; str_res_id < strres[i].MaxNum; str_res_id++)
        {
            unsigned short nStringLen = 0;

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__            
            /* check if it is a dup str */
            if (strres[i].Str[str_res_id] == NULL) continue;
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
        #ifndef __UCS2_ENCODING
            fprintf(fout_res, "\"%s\",\n", strres[i].Str[str_res_id]);
            fprintf(fout_meta_res, "\"%s\",\n", strres[i].Str[str_res_id]);
        #else /* __UCS2_ENCODING */
            nStringLen = wcslen(strres[i].Str[str_res_id]);

            for (z = 0; z < nStringLen * 2; ++z)
            {
                unsigned char *abc = (unsigned char*)strres[i].Str[str_res_id];

            #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
                fputc(abc[z], fout_enfb);
                enfb_size++;
            #else /* __MMI_RESOURCE_ENFB_SUPPORT__ */
                fprintf(fout_res, "0x%X, ", abc[z]);
                fprintf(fout_meta_res, "0x%X, ", abc[z]);                
            #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
            }

        #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
            fputc(0, fout_enfb);
            fputc(0, fout_enfb);
            enfb_size += 2;
        #else /* __MMI_RESOURCE_ENFB_SUPPORT__ */
            fputs("0x00, 0x00,\n", fout_res);
            fputs("0x00, 0x00,\n", fout_meta_res);
        #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
    #endif /* __UCS2_ENCODING */
        }

        /* output ENFB string resource header */
    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        fprintf(fout_res,
                "\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\n",
                (U8)255,    /* type */
                (U8)0,      /* reserved */
                (U8)0,      /* reserved */
                (U8)0,      /* reserved */
                (U8)(enfb_offset & 0xFF),
                (U8)((enfb_offset >> 8) & 0xFF),
                (U8)((enfb_offset >> 16) & 0xFF),
                (U8)((enfb_offset >> 24) & 0xFF),
                (U8)(enfb_size & 0xFF),
                (U8)((enfb_size >> 8) & 0xFF),
                (U8)((enfb_size >> 16) & 0xFF),
                (U8)((enfb_size >> 24) & 0xFF));
        enfb_offset += enfb_size;
        enfb_str_mem_size += enfb_size;
    #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        enfb_size = 0;
    #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

        /* output CustStrMap.c */
        for (str_res_id = 0; str_res_id < strres[i].MaxID; str_res_id++)
        {
            unsigned int nStringLen = 0;
            int iterator = 0;
            wchar_t *wcString;

            if (strres[i].StrRef[str_res_id] == -1)
            {
                nTotalLen = 0;
            }
            else
            {
                nTotalLen = 2;
            }
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
            /* check if it is duplicated */ 
            if (strres[i].is_dup[str_res_id])
            {
                for (iterator = 0; iterator < strres[i].StrRef[str_res_id]; iterator++)
                {
                    nStringLen = 0;
                    nStringLen = wcslen(strres_dup->Str[iterator]);
                    wcString = NULL;
                    nTotalLen += ((nStringLen + 1) * 2);
                }
                /* add max_total_len offset to nTotalLen */
                nTotalLen += max_total_len;
            }
            else
            {
                for (iterator = 0; iterator < strres[i].StrRef[str_res_id]; iterator++)
                {
                    /* ignore dup str */
                    if (strres[i].Str[iterator])
                    {
                    nStringLen = 0;
                    nStringLen = wcslen(strres[i].Str[iterator]);
                    wcString = NULL;
                    nTotalLen += ((nStringLen + 1) * 2);
                    }
                }
            }
#else /* __MMI_RESOURCE_ENFB_SUPPORT__ */

            for (iterator = 0; iterator < strres[i].StrRef[str_res_id]; iterator++)
            {
                nStringLen = 0;
                nStringLen = wcslen(strres[i].Str[iterator]);
                wcString = NULL;
                nTotalLen += ((nStringLen + 1) * 2);
            }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
        StrSize[StrID[str_res_id]] += ((nStringLen + 1) * 2);

        #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
            fputc(((nTotalLen / 2) & 0xFF), fout_enfb);
            fputc((((nTotalLen / 2) >> 8) & 0xFF), fout_enfb);
            fputc((((nTotalLen / 2) >> 16) & 0xFF), fout_enfb);
            fputc((((nTotalLen / 2) >> 24) & 0xFF), fout_enfb);
            enfb_size += 4;
        #else /* __MMI_RESOURCE_ENFB_SUPPORT__ */
            fprintf(fout_map, "\t%ld,\n", nTotalLen / 2);
            fprintf(fout_meta_map, "\t%ld,\n", nTotalLen / 2);
        #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
        }

    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        fprintf(fout_map, "\t%d, %d\n", enfb_offset, enfb_size);
        enfb_offset += enfb_size;
        enfb_str_mem_size += enfb_size;
        if (enfb_str_mem_size > enfb_max_mem_size)
        {
            enfb_max_mem_size = enfb_str_mem_size;
        }
    #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

        fprintf(fout_res, "};\n");
        fprintf(fout_meta_res, "};\n");
        fprintf(fout_map, "};\n");
        fprintf(fout_meta_map, "};\n");
        
        if (is16bit[i])        
        {
        #if !defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
            fprintf(fout_res, "extern const CUSTOM_STRING_MAP_16 StrMap_%d[];\n\n", old_i + 1);
        #else
            fprintf(fout_res, "//extern const CUSTOM_STRING_MAP_16 StrMap_%d[];\n\n", old_i + 1);
        #endif // __MMI_RESOURCE_STR_ZLIB_COMPRESS__
        }
        else
        {
      	#if !defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
            fprintf(fout_res, "extern const CUSTOM_STRING_MAP StrMap_%d[];\n\n", old_i + 1);
        #else
            fprintf(fout_res, "//extern const CUSTOM_STRING_MAP StrMap_%d[];\n\n", old_i + 1);
        #endif
        }        
        }
        i = old_i;
    }
#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
    fprintf(fout_res, "//__align(4) CUSTOM_STRING StrRes[%d];\n", max_zip_len);
#endif /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    {   /* output ENFB string resource header for RESMEM */
        FILE *fp = fopen(ENFB_STRING_HEADER_FILENAME, "w");

        if (fp == NULL)
        {
            STRMERG_LOG_E("File open error (%s) ...!", ENFB_STRING_HEADER_FILENAME);
            goto GEN_STR_ERR_RET;
        }
        fprintf(fp, "\n#ifdef __MMI_RESOURCE_ENFB_SUPPORT__\n");
        fprintf(fp, "#define MaxENFBStringSize\t%d\n", enfb_max_mem_size);
        fprintf(fp, "#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */\n\n");
        fclose(fp);
    }
#else /* __MMI_RESOURCE_ENFB_SUPPORT__ */
    /* here we generate strings that not support multi-language */
    if(generate_fixed_str(fout_res, fout_map,fout_meta_res, fout_meta_map, &fixed_id) < 0)
    {
        goto GEN_STR_ERR_RET;
    }
    
    fprintf(fout_meta_map,"########################################################\n");
    fprintf(fout_meta_map,"TYPE: VALUE\n");
    fprintf(fout_meta_map,"NAME: mtk_gTrans_string_count\n");
    fprintf(fout_meta_map,"VALUE: %d\n", CurrMaxStringId - fixed_id.id_count);

    fprintf(fout_meta_map,"########################################################\n");
    fprintf(fout_meta_map,"TYPE: VALUE\n");
    fprintf(fout_meta_map,"NAME: mtk_gMaxDeployedLangs\n");
    fprintf(fout_meta_map,"VALUE: %d\n", mtk_gMaxDeployedLangs);


    fprintf(fout_meta_map,"########################################################\n");
    fprintf(fout_meta_map,"TYPE: VALUE\n");
    fprintf(fout_meta_map,"NAME: max_total_len\n");
    fprintf(fout_meta_map,"VALUE: %d\n", max_total_len);


#ifdef __CAT_SUPPORT__    
    fprintf(fout_map, ResgenCATGetRegionEndStatment());
#endif //__CAT_SUPPORT__
    /* record translated string id count for no-translate string */
    fprintf(fout_map, "#ifndef __MMI_RESOURCE_ENFB_SUPPORT__\n\tconst U16 mtk_gTrans_string_count = %d;\n#endif\n\n", CurrMaxStringId - fixed_id.id_count);
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

#ifdef __CAT_SUPPORT__    
    fprintf(fout_res, ResgenCATGetRegionEndStatment());
#endif //__CAT_SUPPORT__

    /* output STRMAP_SEARCH array */
    num_map_search = generate_strmap_search(fout_res, fout_meta_res);
    if(num_map_search <= 0)
    {
        goto GEN_STR_ERR_RET;
    }

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    /* output language list array */
    STRMERG_LOG_V("output language list array (strres, strres_dup, num_map_search) ");
    if(!generate_language_list_array(fout_res, strres, strres_dup, num_map_search, max_total_len, res_size, map_size, reszip_size, mapzip_size))
    {
        STRMERG_LOG_E("Failed to output generate_language_list_array: \
                num_map_search = %d, max_total_len = %d, map_size=%lu ,reszip_size = %lu, mapzip_size = %lu", \
	        num_map_search, max_total_len, map_size, reszip_size,mapzip_size);
        goto GEN_STR_ERR_RET;
    }
#else
    if(!generate_language_list_array(fout_res, strres, num_map_search, res_size, map_size, reszip_size, mapzip_size))    
    {
        STRMERG_LOG_E("Failed to output generate_language_list_array: \
                       num_map_search = %d, map_size=%lu ,reszip_size = %lu, mapzip_size = %lu", \
                       num_map_search, map_size, reszip_size,mapzip_size);
        goto GEN_STR_ERR_RET;
    }
#endif

    fprintf(fout_res, "\n#endif //!(__MMI_RESOURCE_STR_LZMA_COMPRESS__) && !(__MMI_RESOURCE_STR_THIRD_ROM__)");
    fprintf(fout_map, "\n#endif //!(__MMI_RESOURCE_STR_LZMA_COMPRESS__) && !(__MMI_RESOURCE_STR_THIRD_ROM__)");
    fclose(fout_res);
    fclose(fout_meta_res);
    fclose(fout_map);
    fclose(fout_meta_map);
    
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    fclose(fout_enfb);
#endif


#if 0  /* Add size to usage for debug */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    STRMERG_LOG_V("GenerateStrResFile succeeded");
    return 0;

GEN_STR_ERR_RET:
    STRMERG_LOG_E("GEN_STR_ERR_RET handling");
    if (fout_res)fclose(fout_res);
    if (fout_map)fclose(fout_map);
    if (fout_meta_res)fclose(fout_map);
    if (fout_meta_map)fclose(fout_map);
    
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    if (fout_enfb)fclose(fout_enfb);
#endif    
    return -1;
}


#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
int generate_map(FILE *map, U16 *arr, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int s = 0;
    int map_count = 0;
    int i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(map == 0 || arr == 0 || len <= 0)
    {
        return -1;
    }

    for(i = 0; i < len - 1; ++i)
    {
        if(arr[i] + 1 != arr[i+1])
        {
            fprintf(map, "\t{%d, %d, %d},\n", arr[s], arr[i], s);
            s = i + 1;
            map_count++;
        }
    }

    fprintf(map, "\t{%d, %d, %d},\n", arr[s], arr[i], s);
    map_count++;

    return map_count;
}
#else /* __MMI_RESOURCE_ENFB_SUPPORT__ */
int generate_map2(FILE *map,FILE *mapMeta, U8 *ispop, FixedID *fixed, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int mapIndex = 0; /* offset */
    int new_flag = 0; /* new item or not */
    int minId = 0;    /* minmum id */
    int map_count = 0;
    int i = 0;
    U16 trans_count = CurrMaxStringId - fixed->id_count; /* translated string count */
    U16 curr_trans = 0;
    U16 curr_no_trans = 0;
    U16 curr_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(map == 0 || ispop == 0 || fixed == 0 || len <= 0)
    {
        return -1;
    }
    
    for(i = 0; i < len; ++i)
    {
        if(new_flag == 0)
        {
            if(ispop[i])
            {
                new_flag = 1;
                if(fixed->fixed_id_flag[i] == TRANSLATE_FLAG)
                {
                    mapIndex = curr_trans;
                    curr_type = TRANSLATE_FLAG;
                }
                else
                {
                    mapIndex = curr_no_trans + trans_count;
                    curr_type = NO_TRANSLATE_FLAG;
                }
                minId = i;
            }
        }
        else
        {
            if(ispop[i] == 0 || fixed->fixed_id_flag[i - 1] != fixed->fixed_id_flag[i])
            {
                fprintf(map, "\t{%d, %d, %d},\n", minId, i - 1, mapIndex);
		fprintf(mapMeta, "\t{%d, %d, %d},\n", minId, i - 1, mapIndex);
                if(ispop[i] == 0)
                {
                    new_flag = 0;
            }
            else
            {
                    minId = i;
                    if(fixed->fixed_id_flag[i] == TRANSLATE_FLAG)
                    {
                        mapIndex = curr_trans;
                        curr_type = TRANSLATE_FLAG;
                    }
                    else
                    {
                        mapIndex = curr_no_trans + trans_count;
                        curr_type = NO_TRANSLATE_FLAG;
                    }
                }
                map_count++;
            }
        }

        if(ispop[i])
        {
            if(curr_type == TRANSLATE_FLAG)
            {
                curr_trans++;
            }
            else
            {
                curr_no_trans++;
            }
        }
    }

    if(ispop[i - 1])
    {
        fprintf(map, "\t{%d, %d, %d},\n", minId, i - 1, mapIndex);
	fprintf(mapMeta, "\t{%d, %d, %d},\n", minId, i - 1, mapIndex);
        map_count++;
    }

    return map_count;
}
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */


static int generate_strmap_search(FILE *res, FILE *resMeta)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(res == 0)
    {
        return -1; /* invalid input */
    }

    fprintf(res, "const CUSTOM_STRMAP_SEARCH StrMapSearch[] = {\n");
    fprintf(resMeta, "########################################################\n");
    fprintf(resMeta, "TYPE: SEARCH_MAP\n");
    fprintf(resMeta, "DATA:\n");
    fprintf(resMeta, "const CUSTOM_STRMAP_SEARCH StrMapSearch[] = {\n");
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    ret = generate_map(res, StrID, CurrMaxStringId);
#else
    ret = generate_map2(res, resMeta, StrIsPopulate, &fixed_id, MAX_STRING_MAP_SIZE);
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
    fprintf(res, "};\n");
    fprintf(resMeta, "};\n");


    return ret;
}

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
static MMI_BOOL generate_language_list_array(FILE *res, StrRes *strres, DupStrRes *strres_dup, int num_map_search, int max_total_len, U32 *res_size, U32 *map_size, U32 *reszip_size, U32 *mapzip_size)
#else
static MMI_BOOL generate_language_list_array(FILE *res, StrRes *strres, int num_map_search, U32 *res_size, U32 *map_size, U32 *reszip_size, U32 *mapzip_size)
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
{
    FILE *pFile = 0;
    int i = 0;
    char strResZiSymbol[STR_RESOURCE_MAX_SYMBOL_LEN] = "";
    char strMapZiSymbol[STR_RESOURCE_MAX_SYMBOL_LEN] = "";
    char * statementStr = NULL ;
   
    if(res == 0)
    {
        return MMI_FALSE;
    }

#ifdef __MMI_RESOURCE_STR_ZLIB_COMPRESS__
    InitStrDeCompressionBufferCreator();
    launchStrDeCompressionBufferCreator(strres, strres_dup, res_size, map_size);
    statementStr = StrDeCompressBufGetDefinitionStatements(MMIRESORUCE_CAT_STR_COMPRESS_RESERVED_ZI_SIZE);
    fprintf(res, "%s\n", statementStr);
    statementStr = StrDeCompressBufGetDeclartionStatements();
    fprintf(res, "%s\n", statementStr);
#endif// __MMI_RESOURCE_STR_ZLIB_COMPRESS__

    fprintf(res, "const StringResList mtk_gStringList[] = {\n");
    for (i = 0; i < mtk_gMaxDeployedLangs; i++)
    {
        int old_i = i;

        if (mtk_gLanguageFlag[i] == 0)
        {
            i = 0;
        }
#ifdef __MMI_RESOURCE_STR_ZLIB_COMPRESS__
        if (mmi_res_zip_language[i] == 1)
        {
            if(pFile = fopen(ZIP_OUTPUT_FILE, "a"))
            {
                fprintf(pFile, "StrRes_%d,%d,%d,%d,Yes\n", old_i + 1, res_size[i], reszip_size[i], res_size[i]-reszip_size[i]);
                fprintf(pFile, "StrMap_%d,%d,%d,%d,Yes\n", old_i + 1, map_size[i], mapzip_size[i], map_size[i]-mapzip_size[i]);
                fprintf(pFile, "Language_%d_Total,%d,%d,%d,Yes\n", old_i + 1, res_size[i] + map_size[i], reszip_size[i] + mapzip_size[i], (res_size[i] + map_size[i])-(reszip_size[i] + mapzip_size[i]));
                fclose(pFile);
            }
            StrDeCompressBufGetStrResSymbol(old_i, strResZiSymbol, STR_RESOURCE_MAX_SYMBOL_LEN);
            StrDeCompressBufGetStrMapSymbol(old_i, strMapZiSymbol, STR_RESOURCE_MAX_SYMBOL_LEN);

            fprintf(res, "{%s, %d, %s, %d, (CUSTOM_STRMAP_SEARCH *)StrMapSearch, %d, %d, (U8*)StrRes_zip_%d, %d, %d, (U8*)StrMap_zip_%d, %d, %d},\n", 
                strResZiSymbol, strres[i].MaxNum + 1,strMapZiSymbol, strres[i].MaxID + 1, num_map_search, is16bit[i], old_i + 1, res_size[i], reszip_size[i], old_i + 1, map_size[i], mapzip_size[i]);
        }
        else
        {
            fprintf(res, "{(CUSTOM_STRING*)StrRes_%d, %d, (void*)StrMap_%d, %d, (CUSTOM_STRMAP_SEARCH *)StrMapSearch, %d, %d, (U8*)NULL, 0, 0, (U8*)NULL, 0, 0},\n", 
                    old_i + 1, strres[i].MaxNum + 1, old_i + 1, strres[i].MaxID + 1, num_map_search, is16bit[i]);
        }
#else
        fprintf(res, "{(CUSTOM_STRING*)StrRes_%d, %d, (void*)StrMap_%d, %d, (CUSTOM_STRMAP_SEARCH *)StrMapSearch, %d, (MMI_BOOL)%d},\n", 
                old_i + 1, strres[i].MaxNum + 1, old_i + 1, strres[i].MaxID + 1, num_map_search, is16bit[i]);
#endif

        i = old_i;
    }

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__

#ifdef __MMI_RESOURCE_STR_ZLIB_COMPRESS__

    if (strres_dup->MaxNum > 0)
    {
        if (mmi_res_zip_language[MAX_LANGUAGES] == 1)
        {            
            if(pFile = fopen(ZIP_OUTPUT_FILE, "a"))
            {
                fprintf(pFile, "StrRes_Dup,%d,%d,%d,Yes\n", res_size[511], reszip_size[511], res_size[511]-reszip_size[511]);
                fclose(pFile);
            }
                        
            StrDeCompressBufGetDupStrResSymbol(strResZiSymbol, STR_RESOURCE_MAX_SYMBOL_LEN);

            fprintf(res, "{%s, %d, (void*)NULL, %d, (CUSTOM_STRMAP_SEARCH *)NULL, %d, 0, (U8*)StrRes_zip_Dup, %d, %d, (U8*)NULL, 0, 0},\n", 
                strResZiSymbol, strres_dup->MaxNum, (U16)((max_total_len >> 16) & 0xFFFF), (U16)(max_total_len & 0xFFFF), res_size[511], reszip_size[511]);
        }
        else
        {
            fprintf(res, "{(CUSTOM_STRING*)StrRes_Dup, %d, (void*)NULL, %d, (CUSTOM_STRMAP_SEARCH *)NULL, %d, 0, (U8*)NULL, 0, 0, (U8*)NULL, 0, 0},\n", 
                    strres_dup->MaxNum, (U16)((max_total_len >> 16) & 0xFFFF), (U16)(max_total_len & 0xFFFF));
        }            
    }
    else
    {
        fprintf(res, "{(CUSTOM_STRING*)NULL, 0, (void*)NULL, 0, (CUSTOM_STRMAP_SEARCH *)NULL, 0, 0, NULL, 0, 0, NULL, 0, 0},\n");
    }

    /* fixed string information */
    if(fixed_id.id_count > 0)
    {

        StrDeCompressBufGetFixedStrResSymbol(strResZiSymbol, STR_RESOURCE_MAX_SYMBOL_LEN);
        StrDeCompressBufGetFixedStrMapSymbol(strMapZiSymbol, STR_RESOURCE_MAX_SYMBOL_LEN);
        fprintf(res, "{%s, %d, %s, %d, (CUSTOM_STRMAP_SEARCH *)StrMapSearch, %d, %d, (U8*)StrRes_zip_fixed, %d, %d, (U8*)StrMap_zip_fixed, %d, %d},\n", 
            strResZiSymbol,fixed_result.nTotalStrRes,strMapZiSymbol, fixed_id.id_count, num_map_search, fixed_result.is16bit, fixed_result.nResSize, fixed_result.nResZipSize, fixed_result.nMapSize, fixed_result.nMapZipSize);
    }
    else
    {
        fprintf(res, "{(CUSTOM_STRING*)NULL, 0, (void*)NULL, 0, (CUSTOM_STRMAP_SEARCH *)NULL, 0, 0, NULL, 0, 0, NULL, 0, 0},\n");
    }
#else /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
    /* duplicate string information */
    if (strres_dup->MaxNum > 0)
    {
        fprintf(res, "{(CUSTOM_STRING*)StrRes_Dup, %d, (void*)NULL, %d, (CUSTOM_STRMAP_SEARCH *)NULL, %d, (MMI_BOOL)0},\n", strres_dup->MaxNum, (U16)((max_total_len >> 16) & 0xFFFF), (U16)(max_total_len & 0xFFFF));
    }
    else
    {
        fprintf(res, "{(CUSTOM_STRING*)NULL, 0, (void*)NULL, 0, (CUSTOM_STRMAP_SEARCH *)NULL, 0, 0},\n");
    }

    /* fixed string id information */
    if(fixed_id.id_count > 0)
    {
        fprintf(res, "{(CUSTOM_STRING*)StrRes_Fixed, %d, (void*)StrMap_Fixed, %d, (CUSTOM_STRMAP_SEARCH *)StrMapSearch, %d, (MMI_BOOL)%d},\n",
        fixed_result.nTotalStrRes, fixed_id.id_count, num_map_search, fixed_result.is16bit ? 1 : 0);
    }
    else
    {
        fprintf(res, "{(CUSTOM_STRING*)NULL, 0, (void*)NULL, 0, (CUSTOM_STRMAP_SEARCH *)NULL, 0, 0},\n");
    }
#endif /* #ifdef __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
    
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    fprintf(res, "};\n");

#ifdef __MMI_RESOURCE_STR_ZLIB_COMPRESS__
    DenitStrDeCompressionBufferCreator();
#endif// __MMI_RESOURCE_STR_ZLIB_COMPRESS__

    return MMI_TRUE;
}


#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  init_fixed_id
 * DESCRIPTION
 *  initialize fixed id
 * PARAMETERS
 *  fixed           :[IN/OUT] fixed id will be initialized
 *  table_size    :[IN] hash table size
 * RETURNS
 *   0 if initialize success
 *****************************************************************************/
int init_fixed_id(FixedID *fixed, int table_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(fixed == 0)
    {
        return -1; /* invalid input */
    }

    memset(fixed, 0, sizeof(FixedID));

    fixed->fixed_id_flag = (U8*)malloc(sizeof(U8) * MAX_STRING_MAP_SIZE);
    if(fixed->fixed_id_flag == 0)
    {
        return -2; /* malloc failed */
    }
    for(i = 0; i < MAX_STRING_MAP_SIZE; ++i)
        fixed->fixed_id_flag[i] = NO_TRANSLATE_FLAG;

    fixed->enum_id_tb = CreateHashTable(table_size);
    if(fixed->enum_id_tb == 0)
    {
        fprintf(stderr, "create hash table fixed->enum_id_tb failed.\n");
        return -3;
    }

    fixed->str_id_tb = CreateHashTable(table_size);
    if(fixed->str_id_tb == 0)
    {
        fprintf(stderr, "create hash table fixed->str_id_tb failed.\n");
        return -3;
    }

    return 0;
}


int set_fixed_str_flag(FixedID *fixed, wchar_t* id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    StrIDNode *node = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(fixed == 0 || id == 0 || id[0] == '\0')
    {
        return -1; /* invalid input */
    }

    node = hash_search(fixed->enum_id_tb, id);
    if(node != 0)
    {
    	if(fixed->fixed_id_flag[node->id] != TRANSLATE_FLAG)
        {
            ++CurrMaxTransStrId;
            fixed->fixed_id_flag[node->id] = TRANSLATE_FLAG;
        }
    }

    return 0;
}


int generate_enum_hash(StrHashTable *table, U8 *isPop, wchar_t *str[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, ret = 0;
    StrIDNode node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(table == 0 || isPop == 0 || str == 0)
    {
        return -1; /* invalid input */
    }

    for(i = 0; i < MAX_STRING_MAP_SIZE; ++i)
    {
        if(isPop[i])
        {
            node.id = i;
            node.str = str[i];
            node.next = 0;
            
            ret = hash_add(table, &node);
            if(ret < 0)
            {
                return -2; /* hash add failed */
            }
        }
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  get_fixed_string_total_len
 * DESCRIPTION
 *  get the total length of fixed string
 * PARAMETERS
 *  void
 * RETURNS
 *   length of all the fixed string
 *****************************************************************************/
int get_fixed_string_total_len(FixedID *fixed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, len = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < MAX_STRING_MAP_SIZE; ++i)
    {
        if(StrIsPopulate[i] && fixed->fixed_id_flag[i] == NO_TRANSLATE_FLAG)
        {
            if(Str[i][0] != '\0')
            {
                int l = wcslen((wchar_t*)Str[i]);
                if(l > 0)
                {
                    len += (l + 1)*2;
                }
            }
        }
    }

    return len;
}


/*****************************************************************************
 * FUNCTION
 *  generate_fixed_str
 * DESCRIPTION
 *  fixed string id populate function
 * PARAMETERS
 *  res      :[IN] CustStrRes.c file handle
 *  map    :[IN] CustStrMap.c file handle
 *  fixed    :[IN] fixed string id information
 * RETURNS
 *  Return 1 on success, return -1 if input is invalid, return-2 if malloc faileds
 *****************************************************************************/
static int generate_fixed_str(FILE *res, FILE *map, FILE *resMeta, FILE *mapMeta ,FixedID *fixed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 did = 0;
    int i = 0, total_len = 0;
    FILE *log = 0;
    int str_count = 0; /* total string count */
    int *offset = 0; /* offset array for each ID */
    int curr_pos = 2; /* current max offset value */
    StrIDNode *node = 0, tmp;
#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
    U8 *data = 0, *p = 0;
#endif /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fprintf(stderr, "********start run generate_fixed_str1************\n");
    if(res == 0 || map == 0 || resMeta==0 || fixed == 0 || mapMeta ==0 || fixed->enum_id_tb == 0 || fixed->str_id_tb == 0)
    {
        return -1; /* invalid input */
    }
    fprintf(stderr, "********start run generate_fixed_str2************\n");

    /* get the total length of fixed string id */
    total_len = get_fixed_string_total_len(fixed);
    if(total_len/2 > 0xFFFF)
    {
        fixed_result.is16bit = MMI_FALSE;
    }
    else
    {
        fixed_result.is16bit = MMI_TRUE;
    }

    /* open log file */
    log = fopen(FIXED_STRING_LOG, "w");
    if(log == NULL)
    {
        STRMERG_LOG_E("open ResGenerator\\debug\\fixed_string.txt failed!");
        fprintf(stderr, "ERROR:open ResGenerator\\debug\\fixed_string.txt failed!!\n");
    }
    else
    {
        fprintf(log, "ENUM_ID\tID_VALUE\tID_STR\tSTR LENGTH\tduplicate ID\n");
    }
    
    /* initialize offset */
    offset = (int*)malloc(sizeof(int) * MAX_STRING_MAP_SIZE);
    if(offset == 0)
    {
        fclose(log);
        return -2; /* malloc memory failed */
    }
    for(i = 0; i < MAX_STRING_MAP_SIZE; ++i)
    {
        offset[i] = -1;
    }
    
#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
    data = (U8*)malloc((total_len + 4) * sizeof(U8));
    if(data == 0)
    {
        fclose(log);
        free(offset);
        return -2; 
    }
    data[0] = '\0';
    data[1] = '\0';
    p = data + 2;
#else /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
    /* write the head of the data and map array */
    fprintf(res, "__align(4) const CUSTOM_STRING StrRes_Fixed[] = {\n");
    fprintf(res, "0x00, 0x00,\n");
    
    
    /* output language map meta file*/
    fprintf(resMeta, "########################################################\n");
    fprintf(resMeta, "TYPE: RES\n");    
    fprintf(resMeta, "LANG: FIXED\n"); 
    fprintf(resMeta, "DATA:\n__align(4) const CUSTOM_STRING StrRes_Fixed[] = {\n");
    fprintf(resMeta, "0x00, 0x00,\n");
    
    fprintf(mapMeta, "########################################################\n");
    fprintf(mapMeta, "TYPE: MAP\n");
    fprintf(mapMeta, "LANG: FIXED\n");
    if(fixed_result.is16bit)
    {
        fprintf(map, "const CUSTOM_STRING_MAP_16 StrMap_Fixed[] = {\n");
        fprintf(mapMeta, "BIT_MODE: 16\n");
        fprintf(mapMeta, "DATA:\n");
        fprintf(mapMeta, "const CUSTOM_STRING_MAP_16 StrMap_Fixed[] = {\n");
    }
    else
    {
        fprintf(map, "const CUSTOM_STRING_MAP StrMap_Fixed[] = {\n");
        fprintf(mapMeta, "BIT_MODE: 32\n");
        fprintf(mapMeta, "DATA:\n");
        fprintf(mapMeta, "const CUSTOM_STRING_MAP StrMap_Fixed[] = {\n");
    }
#endif /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */

    for(i = 0; i < MAX_STRING_MAP_SIZE; ++i)
    {
        if(StrIsPopulate[i] && fixed->fixed_id_flag[i] == NO_TRANSLATE_FLAG)
        {
            fixed->id_count += 1;
            node = hash_search(fixed->str_id_tb, Str[i]);
            if(node == 0)
            {        
                if(Str[i][0] != '\0') /* string has default value */
                {
                    //str_count++;
                    fixed_result.nTotalStrRes += 1;

                    /* initialize node */
                    tmp.str = Str[i];
                    tmp.id = i;
                    tmp.next = 0;

                    /* add new node into hash table */
                    hash_add(fixed->str_id_tb, &tmp);
                    
                #if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
                    curr_pos += write_fixed_str_mem(&p, Str[i], curr_pos, offset, i);
                #else /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
                    /* write StrRes & StrMap into file */
                    curr_pos += write_fixed_str_offset(res, map, resMeta, mapMeta, Str[i], curr_pos, offset, i);
                #endif /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
                }
                else /* string has not default value */
                {
                #if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
                    offset[i] = 0;
                #else /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
                    write_fixed_offset(res, map, resMeta, mapMeta, 0, offset, i);
                #endif /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
                }
            }
            else /* duplicate string */
            {
                did = node->id;
            #if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
                offset[i] = offset[node->id];
            #else /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
                /* only need to update StrMap */
                write_fixed_offset(res, map, resMeta, mapMeta, offset[node->id], offset, i);
            #endif /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
            }

            /* record log */
            write_fixed_string_log(log, i, did);
            did = 0;
        }
    }
    
#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
    write_compressed_fixed_data(res, map, data, curr_pos, offset, fixed);
#else /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
    /* write the tail of the data and map array */
    fprintf(res, "};\n\n");
    fprintf(map, "};\n\n");
    fprintf(resMeta, "};\n\n");
    fprintf(mapMeta, "};\n\n");
    
    if(fixed_result.is16bit){
        fprintf(res, "extern const CUSTOM_STRING_MAP_16 StrMap_Fixed[];\n");
    }
    else{
        fprintf(res, "extern const CUSTOM_STRING_MAP StrMap_Fixed[];\n");
    }
#endif /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */
    fprintf(resMeta, "MAXNUM: %d\n", fixed_result.nTotalStrRes -1);
    fprintf(resMeta, "MAXID: %d\n", fixed_id.id_count -1);

    /* free hash table */
    hash_free(fixed->enum_id_tb);
    hash_free(fixed->str_id_tb);
    fclose(log);
    free(offset);
    
    return 1;
}


#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
/*****************************************************************************
 * FUNCTION
 *  write_fixed_str_mem
 * DESCRIPTION
 *  write fixed string id's data into memory
 * PARAMETERS
 *  mem    :[IN/OUT] CustStrRes.c file handle
 *  map   :[IN] CustStrMap.c file handle
 *  data  :[IN] string data will be write to CustStrRes.c
 *  len    :[IN] data total length
 *  offs   :[IN]  offset array of all string ids
 *  fixed  :[IN]  the id will be processed
 * RETURNS
 *   return 1 means success, return -1 if input is invalid, return-2 if malloc faileds, return -3 if compress failed
 *****************************************************************************/
static int write_fixed_str_mem(U8** mem, U8* s, int pos, int *offs, int id)
{
    int i = 0;
    int len = 0;

    if(mem == 0 || s == 0 || pos < 0 || offs == 0 || id < 0 || id >= MAX_STRING_MAP_SIZE)
    {
        return -1;
    }

    /* record offset */
    offs[id] = pos;

    /* record data */
    if(s[0] != '\0')
    {
        len = (wcslen((wchar_t*)s) + 1) * 2;
        memcpy(*mem, s, len);

        *mem += len;
    }

    return len;
}


/*****************************************************************************
 * FUNCTION
 *  write_fixed_str
 * DESCRIPTION
 *  write compressed data into CustStrRes & CustStrmap.c
 * PARAMETERS
 *  res    :[IN] CustStrRes.c file handle
 *  map   :[IN] CustStrMap.c file handle
 *  data  :[IN] string data will be write to CustStrRes.c
 *  len    :[IN] data total length
 *  offs   :[IN]  offset array of all string ids
 *  fixed  :[IN]  the id will be processed
 * RETURNS
 *   return 1 means success, return -1 if input is invalid, return-2 if malloc faileds, return -3 if compress failed
 *****************************************************************************/
static int write_compressed_fixed_data(FILE *res, FILE *map, U8 *data, int len, int *offs, FixedID *fixed)
{
    // The dest parameter of compress2 must be ulong type
    unsigned long res_len = 0, map_len = 0;
    U8 *res_buff = 0, *map_buff = 0;
    U8 *p = 0;
    int ret = Z_OK, i = 0, j = 0;
    int map_arr_len = 0;
    U32 *offst = 0;

    if(res == 0 || map == 0 || data == 0 || offs == 0 || len <= 0 || fixed == 0)
    {
        return -1; /* invalid input */
    }

    /* caculate and malloc StrRes_zip size */
    res_len = compressBound(len);
    res_buff = (U8*) malloc(sizeof(U8) * res_len);
    if(res_buff == 0)
    {
        fprintf(stderr, "ERROR: malloc compress buffer failed, LINE:%d;\tFILE:%s\n", __LINE__, __FILE__);
        return -2; /* memry malloc failed */
    }

    /* caculate string map size  and malloc buffer */
    map_len = compressBound(fixed->id_count * sizeof(U32));
    map_buff = (U8*)malloc(sizeof(U8) * map_len);
    if(fixed_result.is16bit){
        map_arr_len = fixed->id_count * sizeof(U16);
    }
    else{
        map_arr_len = fixed->id_count * sizeof(U32);
    }
    offst = (U32*)malloc(fixed->id_count * sizeof(U32));
    if(map_buff == 0 || offst == 0)
    {
        free(res_buff);
        if(map_buff != 0)
            free(map_buff);
        if(offst != 0)
            free(offst);

        fprintf(stderr, "ERROR: malloc compress buffer failed, LINE:%d;\tFILE:%s\n", __LINE__, __FILE__);
        return -2;
    }

    /* compress string data */
    STRMERG_LOG_V("StrMap_Fixed compress2 input: res_len=%lu, len =%d, level = %d",res_len, len, Z_BEST_COMPRESSION);
    ret = compress2(res_buff, &res_len, data, len, Z_BEST_COMPRESSION);
    STRMERG_LOG_V("StrMap_Fixed compress2 output: res_len=%lu, len =%lu ",res_len, len);

    if(ret != Z_OK)
    {
        free(res_buff);
        free(map_buff);
        free(offst);
        fprintf(stderr, "fatel error: compress failed, LINE:%d;\tFILE:%s\n", __LINE__, __FILE__);
        return -3; /* compress failed */
    }
    // TODO:it seems not good
    fixed_result.nResSize = len;
    fixed_result.nResZipSize = res_len;

    /* write CustStrRes.c */
    STRMERG_LOG_V("StrRes_zip_fixed[%lu]: Started res output",res_len);
    fprintf(res, "//__align(4) CUSTOM_STRING StrRes_Fixed[%d];\n", len);
    fprintf(res, "// StrRes_zip_fixed, DATA SIZE = %lu \n", res_len);
    fprintf(res, "__align(4) const CUSTOM_STRING StrRes_zip_fixed[] = {\n");
    for(i = 0; i < res_len; ++i)
    {
        fprintf(res, "0x%02X, ", res_buff[i]);
        if(i % 16 == 0)
        {
            fprintf(res, "\n");
        }
    }
    
    append_cat_padding_bytes(res, res_len);
    
    fprintf(res, "};\n");
    STRMERG_LOG_V("StrRes_zip_fixed[%lu]: Finished res output",res_len);
    
    fprintf(res, "extern const U8 StrMap_zip_fixed[];\n");
    if(fixed_result.is16bit)
    {
        fprintf(res, "//extern CUSTOM_STRING_MAP_16 StrMap_Fixed[];\n");
    }
    else
    {
        fprintf(res, "//extern CUSTOM_STRING_MAP StrMap_Fixed[];\n");
    }
    
    /* compress string map */
    /* here we need to record log information of offset */
    j = 0;
    if(fixed_result.is16bit)
    {
        U16 *mp = (U16*)offst;
        for(i = 0; i < MAX_STRING_MAP_SIZE; ++i)
        {
            if(StrIsPopulate[i] && fixed->fixed_id_flag[i] == NO_TRANSLATE_FLAG)
            {
                mp[j++] = (U16)offs[i]/2;
            }
        }            
        STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "StrMap_Fixed: Total size of compressing data= %d bytes, size calculated =%lu", j* sizeof(U16), map_arr_len);

    }
    else
    {
        U32 *mp = (U32*)offst;
        for(i = 0; i < MAX_STRING_MAP_SIZE; ++i)
        {
            if(StrIsPopulate[i] && fixed->fixed_id_flag[i] == NO_TRANSLATE_FLAG)
            {
                mp[j++] = (U32)offs[i]/2;
            }
        }    
        STRMERG_LOG_D("[MEM] StrMap_Fixed: Total size of compressing data= %d bytes, size calculated =%lu", j* sizeof(U32), map_arr_len);
    }

    STRMERG_LOG_V("StrMap_Fixed compress2 input: map_len=%lu, map_arr_len =%d, level = %d",map_len, map_arr_len, Z_BEST_COMPRESSION);
    ret = compress2(map_buff, &map_len, (U8*)offst, map_arr_len, Z_BEST_COMPRESSION);
    STRMERG_LOG_V("StrMap_Fixed compress2 output: map_len=%lu, map_arr_len =%d",map_len, map_arr_len);

    if(ret != Z_OK)
    {
        free(res_buff);
        free(map_buff);
        free(offst);
        fprintf(stderr, "fatel error: compress failed, LINE:%d;\tFILE:%s\n", __LINE__, __FILE__);
        return -3; /* compress failed */
    }
    //TODO:it seems not good
    fixed_result.nMapSize = map_arr_len;
    fixed_result.nMapZipSize = map_len;
    
    /* write CustStrMap.c */
    if(fixed_result.is16bit)
    {
        fprintf(map, "//__align(4) CUSTOM_STRING_MAP_16 StrMap_Fixed[%d];\n", map_arr_len);
    }
    else
    {
        fprintf(map, "//__align(4) CUSTOM_STRING_MAP StrMap_Fixed[%d];\n", map_arr_len);
    }

    STRMERG_LOG_V("StrMap_zip_fixed[%lu]: Started fout_res output",map_len);
    fprintf(map, "//StrMap_zip_fixed, DATA SIZE = %lu\n", map_len);
    fprintf(map, "__align(4) const U8 StrMap_zip_fixed[] = {\n");
    
    for(i = 0; i < map_len; ++i)
    {
        if(i % 16 == 0)
        {
            fprintf(map, "\n");
        }
        fprintf(map, "0x%02X, ", map_buff[i]);

    }
    
    append_cat_padding_bytes(map, map_len);
    
    fprintf(map, "};\n");
    
    STRMERG_LOG_V("StrMap_zip_fixed[%lu]: Finished fout_res output",map_len);
    
    free(res_buff);
    free(map_buff);
    free(offst);

    return 1; /* success */
}
#endif /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ */


/*****************************************************************************
 * FUNCTION
 *  write_fixed_str
 * DESCRIPTION
 *  write CustStrRes & CustStrmap.c
 * PARAMETERS
 *  res    :[IN] CustStrRes.c file handle
 *  map   :[IN] CustStrMap.c file handle
 *  s       :[IN] string data will be write to CustStrRes.c
 *  pos    :[IN] offset of duplicate string
 *  offs   :[IN]  offset array of all string ids
 *  id      :[IN]  the id will be processed
 * RETURNS
 *   return -1 if input is invalid, return-2 if malloc faileds, else returen string lenth
 *****************************************************************************/
static int write_fixed_str(FILE *res, FILE *map, FILE *resMeta, FILE *mapMeta,  U8 *s, int pos, int *offs, int id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    int len = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(res == 0 || map == 0)
    {
        return -1;
    }

    /* write custstrmap.c */
    offs[id] = pos;
    fprintf(map, "\t%ld,\n", pos/2);
    fprintf(mapMeta, "\t%ld,\n", pos/2);

    if(s != 0) /* write_fixed_str_offset case */
    {
        len = wcslen((wchar_t*)s);

        for(i = 0; i < len*2; ++i)
        {
            fprintf(res, "0x%X, ", s[i]);
            fprintf(resMeta, "0x%X, ", s[i]);
        }
        fprintf(res, "0x00, 0x00,\n");
        fprintf(resMeta, "0x00, 0x00,\n");

        len = (len + 1)*2;
    }

    return len;
}


/*****************************************************************************
 * FUNCTION
 *  write_fixed_str_offset
 * DESCRIPTION
 *  write CustStrRes & CustStrmap.c, for parameter check
 * PARAMETERS
 *  pease refer write_fixed_str's description
 * RETURNS
 *  return -1 if input is invalid, return-2 if malloc faileds, else return string length
 *****************************************************************************/
static int write_fixed_str_offset(FILE *res, FILE *map, FILE *resMeta, FILE *mapMeta,U8 *s, int pos, int *offs, int id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    if(s == 0 || offs == 0 || id < 0 || id >= MAX_STRING_MAP_SIZE)
    {
        return -1; /* invalid input */
    }

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return write_fixed_str(res, map,resMeta, mapMeta, s, pos, offs, id);
}


/*****************************************************************************
 * FUNCTION
 *  write_fixed_offset
 * DESCRIPTION
 *  write CustStrmap.c, for parameter check
 * PARAMETERS
 *  pease refer write_fixed_str's description
 * RETURNS
 *  return -1 if input is invalid, return-2 if malloc faileds, else return string length
 *****************************************************************************/
static int write_fixed_offset(FILE *res, FILE *map, FILE *resMeta, FILE *mapMeta,int pos, int *offs, int id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    if(pos < 0 || offs == 0 || id < 0 || id >= MAX_STRING_MAP_SIZE)
    {
        return -1; /* invalid input */
    }

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return write_fixed_str(res, map, resMeta, mapMeta, 0, pos, offs, id);
}

/*****************************************************************************
 * FUNCTION
 *  ucs2toasc
 * DESCRIPTION
 *  simple ucs2 to asc
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
int ucs2toasc(U8* pOutBuff, U8 *pInBuff)
{
    int count = 0;

    if(pInBuff != 0)
    {
        while(!(*pInBuff == 0 && *(pInBuff + 1) == 0))
        {
            *pOutBuff = *pInBuff;
            pOutBuff += 1;
            pInBuff += 2;
            count++;
        }
    }

    *pOutBuff = '\0';

    return count;
}

/*****************************************************************************
 * FUNCTION
 *  write_fixed_string_log
 * DESCRIPTION
 *  write fixed string id's log into fixed_string.txt
 * PARAMETERS
 *  pease refer write_fixed_str's description
 * RETURNS
 *  return -1 if input is invalid, return-2 if malloc faileds, else return string length
 *****************************************************************************/
/* id_enum | id_value | data | len | duplicate id */
static MMI_BOOL write_fixed_string_log(FILE *log, U16 id, U16 dup_id)
{
    char *id_enum = "", *did_enum = "", *id_str = "";
    int len = 0;
    U8 enum_buff[MAX_LENGTH]; /* ascii data out buffer */
    U8 str_buff[MAX_LENGTH]; /* default string data bffer */
    U8 denum_buff[MAX_LENGTH]; /* duplicate id enum */
    enum_buff[0] = '\0';
    str_buff[0] = '\0';
    denum_buff[0] = '\0';
    
    if(log == 0 || id <= 0 || id > MAX_STRING_MAP_SIZE)
    {
        return MMI_FALSE;
    }

    ucs2toasc(enum_buff, StrEnum[id]);
    ucs2toasc(str_buff, Str[id]);
    
    if(str_buff[0] != '\0')
        len = (strlen(str_buff) + 1) * 2;
    
    if(dup_id != 0 && dup_id < MAX_STRING_MAP_SIZE)
    {
        ucs2toasc(denum_buff, StrEnum[dup_id]);
    }

    fprintf(log, "%s\t%d\t%s\t%d\t%s\n", enum_buff, id, str_buff, len, denum_buff);

    return MMI_TRUE;
}
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

#ifdef MEM_REF_LIST_OPT
/* Create RefList */
static RefList* CreateRefList(int listSize)
{
    STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "Create list of size %d in CreateRefList()",listSize);
    RefList* newList = (RefList*) malloc( sizeof(RefList) );
    memset(newList,0,sizeof(RefList));
    newList->ListItems = (RefListItem**) malloc( sizeof(RefListItem*) * listSize);
    if(newList->ListItems == NULL)
    {
        STRMERG_LOG_E("Can't create list of size %d", listSize); 
    }
  
    memset(newList->ListItems,0,sizeof(RefListItem*) * listSize);
    newList->ListLength = 0;
    newList->Size = listSize;
    newList->AllocatedSize =0;
    return newList;
}

/* Delete RefList */
static void DeleteRefList(RefList * list)
{
  STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "Free list of size %d, %d items in CreateRefList()", list->ListLength, list->Size);
  int i=0;
  RefListItem * item = NULL;
  for(i=0;i< list->ListLength;i++)
  {
    item = *(list->ListItems+i);
    if(item!=NULL)
    {
      if(item->ItemData !=NULL){
        free(item->ItemData);
      }
      free(item);
    }
  }
  free(list);
  STRMERG_LOG_V(STRMERG_SUB_TAG_MEM "DeleteRefList Finished ... %d items have been free",i);
}


/* Create a ref item object with a string line */
static RefListItem* CreateListItemFromStr(wchar_t * str)
{
    RefListItem* newItem = NULL;
    newItem = malloc(sizeof(RefListItem));
    /* Allocate list item */
    if(newItem == NULL)
    {
        STRMERG_LOG_E("Can't allocate item for %s",str);
        free(newItem);
        return NULL;
    }
    memset(newItem,sizeof(RefListItem),0);
    newItem->ItemSize = (wcslen(str)+1) * sizeof(wchar_t) ;
    newItem->ItemData = malloc(newItem->ItemSize);
    /* Allocate string data */
    if(newItem->ItemData == NULL)
    {
        STRMERG_LOG_E("Can't allocate item ItemData for %s",newItem->ItemData);
        free(newItem->ItemData);
        return NULL;
    }
    memset(newItem->ItemData,newItem->ItemSize,0);
    wcscpy(newItem->ItemData,str);
    return newItem;
}

/* Add an item form a ref list */
static int AddRefListItem(RefList * list, RefListItem* item)
{
    int newSize = 0;
    int indx = 0;
    RefListItem* tmpItem = NULL;
    RefListItem** tmpItemList = NULL;
  
    /* Null pointer check */
    if(list == NULL)
    {
        STRMERG_LOG_E("List can't not be null in AddRefListItem()");
        return -1;
    }
    /* Size check */
    /* If the size is not enough, adjust it. */
    if( (list->ListLength)+1 > list->Size )
    {
        newSize =  list->Size + REF_LIST_SIZE_INCREMENT;
        STRMERG_LOG_E("Resize list from %d to %d in AddRefListItem()",list->Size, newSize);
        /* Allocated items*/
        RefListItem **newList =  (RefList**)malloc( sizeof(RefListItem*) * newSize);
        if(newList==NULL)
        {
            STRMERG_LOG_E("Out of memory. Can't resize list in AddRefListItem().");
            return -1;
        }
        tmpItemList = list->ListItems;
        memset(newList, 0, sizeof(RefListItem*) * newSize);
        memcpy(newList ,list->ListItems, sizeof(RefListItem*) * list->Size) ;
        list->Size = newSize;
        list->ListItems = newList;
        /* Release the original items*/
        free(tmpItemList);
    }
    indx = list->ListLength;
    *(list->ListItems + indx) = item;
    list->ListLength++;
    list->AllocatedSize += item->ItemSize;
}

/* Get an item from a ref list */
static RefListItem* GetRefListItem(RefList * list, int index)
{
    /* size check */
    RefListItem** tmp = NULL;
    if(index >= list->ListLength){
        STRMERG_LOG_E("[MEM]GetRefListItem overflow: idx =%d, len = %d", index, list->ListLength);
        return NULL;
    }
    else
    {
        tmp = list->ListItems + index;
        if(tmp==NULL)
        {
            STRMERG_LOG_E("\nERROR, tmp == NULL");
            return NULL;
	}
	return *(tmp);
    }
}

/* Set a list item, the old item is free by this function automatically */
static int SetRefListItem(RefList * list,int index,RefListItem* item)
{
    RefListItem* oldItem = GetRefListItem(list,index);
    if(oldItem!=NULL)
    {
        STRMERG_LOG_V("Free old item%d", index);
        if(oldItem->ItemData != NULL)
        {
            free(oldItem->ItemData);
        }
        free(oldItem);
    }
    if( list!=NULL && list->ListItems !=NULL)
    {
        *(list->ListItems + index) = item;
    }
	else
	{
        return -1;
	}
    
    return 0;
}
#endif /* MEM_REF_LIST_OPT*/

#ifdef STR_MERGE_DEBUG
#ifndef MEM_REF_LIST_OPT
static void DumpRefList(const char* filename, wchar_t *list,const int itemSize, int count)
{
    int i=0;
    wchar_t *tmp = list;	
    FILE * outputfile;
    outputfile = fopen(filename,"w");
    for(i=0;i< count;i++)
    {
        fputws(tmp,outputfile);
        fputws(L"\r\n", outputfile);
        tmp += itemSize;
    }
    fclose(outputfile);
}


#else /*MEM_REF_LIST_OPT*/

static void DumpRefList(const char* filename, RefList *list)
{
    int i = 0;
    FILE * outputfile;
    int length =0;
    STRMERG_LOG_V("DUMP REF LIST to %s", filename);
    outputfile = fopen(filename,"w");
    STRMERG_LOG_V("Open file suceess!!");
    for(i=0;i< list->ListLength;i++)
    {
        length= wcslen((*(list->ListItems+i))->ItemData);
        if(length >0 )
        {
            fputws((*(list->ListItems+i))->ItemData, outputfile);
            fputws(L"\r\n", outputfile);
        }
    }
    fclose(outputfile);
}


#endif /*MEM_REF_LIST_OPT*/
#endif /* STR_MERGE_DEBUG */

