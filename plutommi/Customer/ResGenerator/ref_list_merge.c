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
 *  ref_list_merge.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Merge multi-language string table.
 *
 * Author:
 * -------
 * -------
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
#include <sys/stat.h>

#define _POPULATE_RES_C

#include "MMI_features.h"
#include "MMIDataType.h"
#include "CustDataRes.h"

#define WIN32_LEAN_AND_MEAN
#include "windows.h"

/* max string length for each language */
#define MAX_LENGTH      512
/* string length for temp buffer */
#define TMP_BUF_LENGTH  1024

#define FILENAME_REF_LIST_ONLY_TRANS    "ref_list_translation.txt"
#define FILENAME_REF_LIST_ONLY_OTHER    "ref_list_other.txt"
#define FILENAME_REF_LIST_TRANSLATE     "..\\CustResource\\PLUTO_MMI\\ref_list\\ref_list_translation.txt"
#define FILENAME_REF_LIST_SEARCH_PATH   "..\\CustResource\\PLUTO_MMI\\ref_list\\"
#define FILENAME_REF_LIST_SEARCH        "..\\CustResource\\PLUTO_MMI\\ref_list\\*.txt"
#define FILENAME_REF_LIST_OTHER         "..\\CustResource\\PLUTO_MMI\\ref_list\\ref_list_other.txt"
#define FILENAME_REF_LIST               "..\\CustResource\\PLUTO_MMI\\ref_list.txt"
#define FILENAME_REF_LIST_DUPLICATE_ID  ".\\debug\\ref_list_dupicate_id.txt"
#define FILENAME_REF_LIST_NOT_USED_ID   ".\\debug\\ref_list_not_used_in_translation.txt"

#define MMI_RLM_TEMP_FOLDER_SEARCH      ".\\temp\\ref_list\\*.txt"
#define MMI_RLM_TEMP_FOLDER             ".\\temp\\ref_list\\"
#define MMI_RLM_TO_MCU_MMI_PATH             "..\\..\\..\\plutommi\\"

typedef struct HashItem
{
    int pointer;        /* index in string array */
    struct HashItem *next;
} HashItem;



const wchar_t *DELIMETER = L"\t";
const wchar_t *EOS = L"\n";

U32 g_line_buf_length = 0;
wchar_t *g_all_string_table[MAX_STRING_MAP_SIZE];
int g_hash_range = 0;
struct HashItem *g_ht = NULL;

FILE *g_ref_dup = NULL;
//FILE *g_ref_not_used = NULL;


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
 *  ASCII2UCS2
 * DESCRIPTION
 *  Convert ASCII character to wide character
 * PARAMETERS
 *  w_in    [IN]
 *  a_out   [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void ASCII2UCS2(U8* src, WCHAR* dest)
{
    U8 index = 0;

    while(src[index] != '\0')
    {
		 dest[index] = src[index];
        index++;
    }
   dest[index]=0 ;

   return;
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
    if (p1 == NULL || p2 == NULL)
    {
        printf("GetItem p1 == NULL || p2 == NULL \n");
    }
    while (index > 0)
    {
        p1 = p2 + 1;
        p2 = wcsstr(p1, DELIMETER);
        n = p2 - p1;
        index--;
        if (p2 == NULL)
            break;
    }

    if (index > 0)
    {
        buf[0] = L'\0';
    }
    else if (p2 == NULL)
    {
        wcscpy(buf, p1);
        n = wcsstr(p1, EOS) - p1;
        buf[n] = L'\0';
        buf[n - 1] = L'\0';
    }
    else
    {
        wcsncpy(buf, p1, n);
        buf[n] = L'\0';
    }
}

/*****************************************************************************
 * FUNCTION
 *  GotoItem
 * DESCRIPTION
 *  direct the pointer to the item of index.
 * PARAMETERS
 *  string    [IN]  buffer of string
 *  index     [IN]  index of item
 * RETURNS
 *  wchar_t         pointer of item
 *****************************************************************************/
static wchar_t *GotoItem(wchar_t *string, int index)
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
    while (index > 0)
    {
        p1 = p2 + 1;
        p2 = wcsstr(p1, DELIMETER);
        n = p2 - p1;
        index--;
        if (p2 == NULL)
            break;
    }
    
    if (index > 0)
    {
        return NULL;
    }
    else
    {
        return p1;
    }
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
 *  GetHashValueBeforeDelimeter
 * DESCRIPTION
 *  Calculate the hash value of input string before the Delimeter
 * PARAMETERS
 *  string      [IN]
 *  hash_range  [IN]
 * RETURNS
 *  Return the hash value
 *****************************************************************************/
static int GetHashValueBeforeDelimeter(wchar_t *string, int hash_range)
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
    for (i = 0; i < (int)(wcsstr(string, DELIMETER) - string); i++)
    {
        val += ((string[i] + val * 37) & mask);
    }
    val = fmod(val, hash_range);
    return (int)val;
}


/*****************************************************************************
 * FUNCTION
 *  CompareHashNodeStringID
 * DESCRIPTION
 *  Compare First item in a line buffer, it's the ID of the string.
 * PARAMETERS
 *  node_string    [IN]  buffer of string1
 *  new_string     [IN]  buffer of string2
 * RETURNS
 *  int                  1:They are same. 0:They are different.
 *****************************************************************************/
static int CompareHashNodeStringID(wchar_t *node_string, wchar_t *new_string)
{
    wchar_t *p1 = node_string;
    wchar_t *p2 = new_string;

    while ((p1[0] != DELIMETER[0]) && (p2[0] != DELIMETER[0]))
    {
        if (p1[0] != p2[0])
        {
            return 0;
        }
        p1++;
        p2++;
    }

    if ((p1[0] == DELIMETER[0]) && (p2[0] == DELIMETER[0]))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CustomerMergeReflist
 * DESCRIPTION
 *  When ref_list.txt exist, do some thing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void CustomerMergeReflist(void)
{
    return;
}


/*****************************************************************************
 * FUNCTION
 *  WriteDupIDtoFile
 * DESCRIPTION
 *  direct the pointer to the item of index.
 * PARAMETERS
 *  string    [IN]  buffer of string
 *  index     [IN]  index of item
 * RETURNS
 *  wchar_t         pointer of item
 *****************************************************************************/
static void WriteDupIDtoFile(wchar_t *string)
{
    fputws(string, g_ref_dup);
}

/*****************************************************************************
 * FUNCTION
 *  CheckEndingTABForEachLine
 * DESCRIPTION
 *  To check if each line in ref_list file has the ending TAB.
 *   The TAB will be auto added If the TAB is missing
 * PARAMETERS
 *  string     [IN/OUT]  buffer of string (represent a line in ref_list file).
 *                       If the line is missing TAB at the end.The function will
 *                       create a new line that contains the TAB, and let *string points
 *                       to it
 * RETURNS
 *  TRUE: the line is has TAB at the end; FALSE: the line is missing TAB
 *****************************************************************************/
static BOOL CheckEndingTABForEachLine(wchar_t** string)
{
    wchar_t* find = NULL;
    int find_index = 0;
    wchar_t* ref_tmp_has_TAB = NULL;
    
    find = wcschr((*string),L'\n');
    find_index = (int)(find - (*string));

    // the correct format should be \t\r\n 
    if(((*string)[find_index-2])!= L'\t')
    {       
        // +2 for adding '\t' and '\0'
        ref_tmp_has_TAB = (wchar_t*)malloc( sizeof(wchar_t) * (wcslen(*string) + 2) );
        if (ref_tmp_has_TAB == NULL)
        {
            printf("memory is not available 01\n");
            
            if ((*string) != NULL) free(*string);//free ref_tmp
            if (ref_tmp_has_TAB != NULL) free(ref_tmp_has_TAB);
            exit(2);
        }
        //rewrite the end of this line
        wcscpy(ref_tmp_has_TAB,(*string));            
        ref_tmp_has_TAB[wcslen((*string))-2] = L'\t';
        ref_tmp_has_TAB[wcslen((*string))-1] = L'\r';
        ref_tmp_has_TAB[wcslen((*string))]   = L'\n';
        ref_tmp_has_TAB[wcslen((*string))+1] = L'\0';
        //free ref_tmp
        free(*string);
        //ref tmp now points to a line with TAB
        (*string) = ref_tmp_has_TAB;
        
        return FALSE;
    }
    else
    {        
        return TRUE;
    }
}
/*****************************************************************************
 * FUNCTION
 *  ReadLineToHashList
 * DESCRIPTION
 *  Read one line of ref_list_xxx.txt to hash table
 * PARAMETERS
 *  line_buf    [IN]  buffer of line
 * RETURNS
 *  BOOL              TRUE: Save the line to hash table successful
 *****************************************************************************/
static BOOL ReadLineToHashList(wchar_t *line_buf)
{
    static U32 string_count = 0;
    int hash_value;
    int ret;
    struct HashItem *cur_node = NULL;
    struct HashItem *new_node = NULL;
    
    /* Get Hash code and set string to hash table */
    hash_value = GetHashValueBeforeDelimeter(line_buf, g_hash_range);
    cur_node = &(g_ht[hash_value]);

    while (cur_node->next != NULL)
    {
        ret = CompareHashNodeStringID(g_all_string_table[cur_node->next->pointer], line_buf);
        if (ret)
        {
            /* Write to duplicate ID file */
            WriteDupIDtoFile(line_buf);
            return FALSE;
        }
        cur_node = cur_node->next;
    }

    new_node = (struct HashItem *)malloc(sizeof(struct HashItem));
    if (new_node == NULL)
    {
        printf("memory is not available ReadLineToHashList\n");
        return FALSE;
    }
    new_node->next = NULL;
    new_node->pointer = string_count;
    cur_node->next = new_node;
    
    /* Set String to string table */
    g_all_string_table[string_count] = line_buf;
    string_count++;
    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  ReadReflistFile
 * DESCRIPTION
 *  Read a ref_list_xxx.txt to hash table.
 * PARAMETERS
 *  sFileName       [IN]    File name of ref_list_xxx.txt
 * RETURNS
 *  void
 *****************************************************************************/
static void ReadReflistFile(char * sFileName)
{
    FILE *ref_list_xxx = NULL;
    BOOL ret = FALSE,format_ret = FALSE;
    wchar_t *ref_tmp = NULL;
    wchar_t s1[TMP_BUF_LENGTH];

    ref_list_xxx = fopen((char *)sFileName, "rb");
    if (ref_list_xxx == NULL)
    {
        printf("[%s] can't open\n", sFileName);
        goto ERR_READ_REFLIST_FILE;
    }
    printf("[Dependency] %s\n", sFileName);
    ref_tmp = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
    if (ref_tmp == NULL)
    {
        printf("memory is not available 01\n");
        goto ERR_READ_REFLIST_FILE;
    }
    
    ref_tmp[0] = 0;
    
    fgetws(ref_tmp, TMP_BUF_LENGTH, ref_list_xxx);  /* Jump language count */
    if (ref_tmp[0] != 0xFEFF && ref_tmp[0] != 0)
    {
        printf("[%s][%d] is not an unicode file, please check!!!\n", sFileName, ref_tmp[0]);
        goto ERR_READ_REFLIST_FILE;        
    }

    fgetws(ref_tmp, TMP_BUF_LENGTH, ref_list_xxx);  /* Jump Title */
    fgetws(ref_tmp, TMP_BUF_LENGTH, ref_list_xxx);  /* Jump SSC */

    fgetws(ref_tmp, TMP_BUF_LENGTH, ref_list_xxx);  /* Get the first line */
    while (!feof(ref_list_xxx))
    {
        GetItem(ref_tmp, 0, s1);
        if (wcscmp(s1, L"##number") == 0)
        {
            /* if found ##number, exit */
            break;
        }

        format_ret = CheckEndingTABForEachLine(&ref_tmp);
        ret = ReadLineToHashList(ref_tmp);
        if (ret)
        {
            ref_tmp = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
            if (ref_tmp == NULL)
            {
                printf("memory is not available readreflistfile\n");
                goto ERR_READ_REFLIST_FILE;
            }
        }
        fgetws(ref_tmp, g_line_buf_length, ref_list_xxx);
    }

    fclose(ref_list_xxx);
    free(ref_tmp);  /* Last malloc will not used.*/
    return;

ERR_READ_REFLIST_FILE:
    if (ref_tmp != NULL) free(ref_tmp);
    if (ref_list_xxx != NULL) fclose(ref_list_xxx);    
    exit(2);
    
}


/*****************************************************************************
 * FUNCTION
 *  GetTranFileIDCount
 * DESCRIPTION
 *  Calculate ID count of ref_list_translation.txt
 * PARAMETERS
 *  tran_list    [IN]  File handle of ref_list_translation.txt
 * RETURNS
 *  int                ID count of that file.
 *****************************************************************************/
static int GetTranFileIDCount(FILE *tran_list)
{
    wchar_t buf_ref[TMP_BUF_LENGTH];
    wchar_t tmp_buf[TMP_BUF_LENGTH];
    wchar_t *ref_tmp = NULL;
    int ref_cnt = 0;
    int nLang = 0;


    fgetws(tmp_buf, TMP_BUF_LENGTH, tran_list); /* Number of Language */
    GetItem(tmp_buf, 1, buf_ref);
    nLang = _wtoi(buf_ref);
    /* 
    * calculate line buffer size 
    * here +2 for Description, and (Max String Length, MODULE, ENUM) and 3 languages
    */
    g_line_buf_length = (nLang + 5) * MAX_LENGTH;
    ref_tmp = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
    if (ref_tmp == NULL)
    {
        printf("memory is not available 01\n");
        return -1;
    }
    fgetws(ref_tmp, TMP_BUF_LENGTH, tran_list);   /* Title list */
    fgetws(ref_tmp, g_line_buf_length, tran_list); /* SSC STRING */
    
    /* calculate the number of entries and read them to the buffer */
    fgetws(ref_tmp, g_line_buf_length, tran_list);
    while (!feof(tran_list))
    {
        ref_cnt++;
        fgetws(ref_tmp, g_line_buf_length, tran_list);
    }
    printf("ref_cnt=[%d]\n", ref_cnt);
    free(ref_tmp);
    return ref_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  FindAndWriteToRefList
 * DESCRIPTION
 *  direct the pointer to the item of index.
 * PARAMETERS
 *  string_line    [IN]  Buffer of line.
 *  ref_dest       [IN]  Destination file
 * RETURNS
 *  BOOL                 TRUE:Write line successful
 *****************************************************************************/
static BOOL FindAndWriteToRefList(wchar_t *string_line, FILE *ref_dest)
{
    struct HashItem *cur_node = NULL;
    struct HashItem *del_node = NULL;
    int hash_value;
    int string_length;
    wchar_t * ref_tran_start = NULL;
    wchar_t * ref_line_all = NULL;
    BOOL ret;

    hash_value = GetHashValueBeforeDelimeter(string_line, g_hash_range);
    cur_node = &(g_ht[hash_value]);

    while (cur_node->next != NULL && !CompareHashNodeStringID(g_all_string_table[cur_node->next->pointer], string_line))
    {
        cur_node = cur_node->next;
    }
    
    ref_line_all = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
    if (ref_line_all == NULL)
    {
        printf("memory is not available 01\n");
        return FALSE;
    }
    
    /* cur_node->next is NULL if not found, otherwise cur_node->next is the result */
    if (cur_node->next != NULL)
    {
        ref_tran_start = GotoItem(string_line, 4);

        if (ref_tran_start != NULL)
        {
            wcscpy(ref_line_all, g_all_string_table[cur_node->next->pointer]);
            free(g_all_string_table[cur_node->next->pointer]);
            g_all_string_table[cur_node->next->pointer] = NULL;
            string_length = wcslen(ref_line_all);
            memset((ref_line_all+(string_length-2)), 0, 4); 
            wcscat(ref_line_all, ref_tran_start);
            fputws(ref_line_all, ref_dest);
            del_node = cur_node->next;
            cur_node->next = del_node->next;
            free(del_node);
            ret = TRUE;
        }
        else
        {
            ret = FALSE;
        }
    }
    else
    {
        /* WriteToNotUsedInTran */
        //fputws(string_line, g_ref_not_used);
        ret = FALSE;
    }
    free(ref_line_all);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  MergeNotTransString
 * DESCRIPTION
 *  Merge not translated string.
 * PARAMETERS
 *  ref_dest       [IN]  Destination file
 * RETURNS
 *  int            Merged string count
 *****************************************************************************/
static int MergeNotTransString(FILE *ref_dest)
{
    struct HashItem *cur_node = NULL;
    struct HashItem *del_node = NULL;
    int total_count = 0;
    int i;
    
    for (i = 0; i < MAX_STRING_MAP_SIZE; i++)
    {
        if (g_all_string_table[i] != NULL)
        {
            /* Merge string to ref_list.txt */
            fputws(g_all_string_table[i], ref_dest);
            free(g_all_string_table[i]);
            g_all_string_table[i] = NULL;
            total_count++;
        }
    }
    
    /* Free hash table */
    for (i = 0; i < g_hash_range; i++)
    {
        cur_node = &(g_ht[i]);
        while (cur_node->next != NULL)
        {
            del_node = cur_node->next;
            cur_node->next = del_node->next;
            free(del_node);
        }
    }
    return total_count;
}


/*****************************************************************************
 * FUNCTION
 *  MergeToRefList
 * DESCRIPTION
 *  After read all ref_list_xxx.txt, read ref_list_translation.txt and merge them
 *  to new ref_list.txt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void MergeToRefList(void)
{
    int totol_string = 0;
    int string_length;
    wchar_t *ref_tmp = NULL;
    wchar_t *ref_line_all = NULL;
    wchar_t * ref_tran_start;
    FILE *ref_tran = NULL;
    FILE *ref_other = NULL;
    FILE *ref_dest = NULL;

    wchar_t s1[TMP_BUF_LENGTH];
    wchar_t s2[TMP_BUF_LENGTH];
    wchar_t s3[TMP_BUF_LENGTH];

    /* Open translation file */
    ref_tran = fopen(FILENAME_REF_LIST_TRANSLATE, "rb");
    if (ref_tran == NULL)
    {
        printf("ref_list_translation.txt not exist\n");
        goto END_MERGE_TO_REF_LIST;
    }
    printf("[Dependency] %s\n", FILENAME_REF_LIST_TRANSLATE);
    ref_other = fopen(FILENAME_REF_LIST_OTHER, "rb");
    if (ref_other == NULL)
    {
        printf("ref_list_others.txt not exist\n");
        goto END_MERGE_TO_REF_LIST;
    }
    printf("[Dependency] %s\n", FILENAME_REF_LIST_OTHER);

    ref_tmp = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
    if (ref_tmp == NULL)
    {
        printf("memory is not available 01\n");
        goto END_MERGE_TO_REF_LIST;
    }
    ref_line_all = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
    if (ref_line_all == NULL)
    {
        printf("memory is not available 02\n");
        goto END_MERGE_TO_REF_LIST;
    }

    /* Open destination  file */
    ref_dest = fopen(FILENAME_REF_LIST, "wb");
    if (ref_dest == NULL)
    {
        printf("ref_list.txt not exist\n");
        goto END_MERGE_TO_REF_LIST;
    }

    fgetws(ref_tmp, g_line_buf_length, ref_tran);   /* Language Number */
    fgetws(s1, TMP_BUF_LENGTH, ref_other);          /* Language Number */
    /* Write the first line, language count */
    GetItem(ref_tmp, 0, s1);
    GetItem(ref_tmp, 1, s2);
    GetItem(ref_tmp, 2, s3);
    swprintf(ref_tmp, L"%s\t%d\t%s\r\n", s1, (_wtoi(s2) + 3), s3);
    fputws(ref_tmp, ref_dest);

    /* Write the 2nd line, title */
    fgetws(ref_tmp, g_line_buf_length, ref_tran);   /* Title */
    fgetws(s2, TMP_BUF_LENGTH, ref_other);          /* Title */
    ref_tran_start = GotoItem(ref_tmp, 4);
    if (ref_tran_start != NULL)
    {
        wcscpy(ref_line_all, s2);
        string_length = wcslen(ref_line_all);
        memset((ref_line_all+(string_length-2)), 0, 4); 
        wcscat(ref_line_all, ref_tran_start);
        fputws(ref_line_all, ref_dest);
    }

    /* Write the third line, ssc */
    fgetws(ref_tmp, g_line_buf_length, ref_tran);   /* SSC number */
    fgetws(s3, TMP_BUF_LENGTH, ref_other);          /* SSC number */
    ref_tran_start = GotoItem(ref_tmp, 4);
    if (ref_tran_start != NULL)
    {
        wcscpy(ref_line_all, s3);
        string_length = wcslen(ref_line_all);
        memset((ref_line_all+(string_length-2)), 0, 4); 
        wcscat(ref_line_all, ref_tran_start);
        fputws(ref_line_all, ref_dest);
    }
    

    /* read one line, find it in hash table, found->merge to new file->clean hash node, not found->find next */

    /* Write contents */
    fgetws(ref_tmp, g_line_buf_length, ref_tran);
    while (!feof(ref_tran))
    {
        /* Handle the line */
        if (FindAndWriteToRefList(ref_tmp, ref_dest))
        {
            totol_string++;
        }
        fgetws(ref_tmp, g_line_buf_length, ref_tran);
    }
    /* traverse Hash table and write strings that not include in ref_list_translation.txt */
    totol_string  += MergeNotTransString(ref_dest);
    
    /* Write the last line, ID count */
    GetItem(ref_tmp, 0, s1);
    swprintf(ref_tmp, L"%s\t%d\r\n", s1, totol_string-2); /* Include title and ssc */
    fputws(ref_tmp, ref_dest);

    /* Free and close file */
    free(ref_tmp);
    fclose(ref_tran);
    fclose(ref_dest);
    fclose(ref_other);
    return;

END_MERGE_TO_REF_LIST:
    if (ref_tmp != NULL) free(ref_tmp);
    if (ref_line_all != NULL) free(ref_line_all);
    if (ref_tran != NULL) fclose(ref_tran);
    if (ref_dest != NULL) fclose(ref_dest);
    if (ref_other != NULL) fclose(ref_other);   
    exit(2);
}

static S32 g_error = -1;
/*****************************************************************************
 * FUNCTION
 *  on_exit
 * DESCRIPTION
 *  program exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void resgen_on_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_error != -1)  // normal exit
    {
        _exit(1);
    }
    else                // abnormal exit
    {
        _exit(2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  main
 * DESCRIPTION
 *  main function of ref_list merge
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int main(int argc, char *argv[])
{
    FILE *ref_tran = NULL;
    wchar_t tmp_buf[TMP_BUF_LENGTH];
    U8 tmpbuf[TMP_BUF_LENGTH];
    U8 tmpbuf2[TMP_BUF_LENGTH];

    FILE *fref_list = NULL;
    WIN32_FIND_DATA file_data;
    HANDLE search = NULL;
    BOOL fFinished = FALSE; 
    U32 ret = 0;
    unsigned long ref_list_time = 0;
    struct stat ref_list_stat;

    int token_id = 0, gIndex = 0;
    int i;
    int ref_count = 0;
    S32 index = 0;

    /* Set program exit */
    atexit(resgen_on_exit);

    printf("\n---------- MergeRefList Start ----------\n");

    fref_list = fopen(FILENAME_REF_LIST, "rb");
    if (fref_list != NULL)
    {
        printf("ref_list.txt exist\n");
        /* ref_list.txt exist, so just do customer merge */
        fclose(fref_list);
        /* CustomerMergeReflist(); */
    }

    ref_tran = fopen(FILENAME_REF_LIST_TRANSLATE, "rb");
    if (ref_tran == NULL)
    {
        printf("ref_list_translation.txt not exist\n");
        g_error = 1;
        return 1; 
    }
    printf("[Dependency] %s\n", FILENAME_REF_LIST_TRANSLATE);
    ref_count = GetTranFileIDCount(ref_tran);
    if (ref_count == 0)
    {
        printf("ref_list_translation.txt is empty\n");
    }
    fclose(ref_tran);
  
    /* ref_list.txt is not exist, merge all ref_list_xxx.txt */
    search = FindFirstFile(FILENAME_REF_LIST_SEARCH, &file_data);  
    if (search == INVALID_HANDLE_VALUE)
    {
        printf("Didn't find any ref_list_xxx.txt file ret=[%d]\n", GetLastError());
        g_error = 1;
        return 1; 
    }
    else
    {
        printf("FindFirstFile[%s]\n", file_data.cFileName);
    }    
    
    /* set g_hash_range as maximum id times 1.1(Can be changed) */
    g_hash_range = (int)(ref_count * 1.1);
    
    /* initialize hash table */
    g_ht = (struct HashItem *)malloc(sizeof(struct HashItem) * g_hash_range);
    if (g_ht  == NULL)
    {
        printf("Memory not available when alloc hash tabel\n");
        goto END_REF;        
    }
    
    for (i = 0; i < g_hash_range; i++)
    {
        g_ht[i].next = NULL;
        g_ht[i].pointer = -1;
    }
    
    /* Open Log files */
    g_ref_dup = fopen(FILENAME_REF_LIST_DUPLICATE_ID, "wb");
/*    g_ref_not_used = fopen(FILENAME_REF_LIST_NOT_USED_ID, "wb");

    if (g_ref_dup == NULL || g_ref_not_used == NULL)
    {
        printf("Can't open log file\n");
        goto END_REF;        
    }
*/
    while (!fFinished) 
    {
        if ((strcmp(FILENAME_REF_LIST_ONLY_OTHER, file_data.cFileName) != 0) && 
            (strcmp(FILENAME_REF_LIST_ONLY_TRANS, file_data.cFileName) != 0))
        {
            /* write header of file to duplicate file */
            ASCII2UCS2((U8*)file_data.cFileName, tmp_buf);
            wcscat(tmp_buf, L"\r\n");
            fputws(L"-------------------------------------------------------------------\r\n", g_ref_dup);
            fputws(tmp_buf, g_ref_dup);

            strcpy((char*)tmp_buf, FILENAME_REF_LIST_SEARCH_PATH);
            strcat((char*)tmp_buf, file_data.cFileName);
        
            /* Handle current found file */
            ReadReflistFile((char *)(tmp_buf));
        }
        
        if (!FindNextFile(search, &file_data)) 
        {
            printf("No more .TXT files. Search completed.\n");
            fFinished = TRUE; 
        }
        else
        {
            printf("FindNextFile[%s]\n", file_data.cFileName);
        }
    } 

    /* Close the search handle. */
    if (!FindClose(search)) 
    {
        printf("Couldn't close search handle.");
    }

    
    /* Copy all ref_list files in app folder to temp\ref_list\ */
    while (strcmp(g_mmi_resource_base_table[index].appname, "END") != 0)
    {
        /* If found folder, copy all files */
        if (g_mmi_resource_base_table[index].res_path[0] != '\0')
        {
            //strcpy((S8*)tmpbuf, "xcopy ");
            //strcat((S8*)tmpbuf, MMI_RLM_TO_MCU_MMI_PATH);
            //strcat((S8*)tmpbuf, g_mmi_resource_base_table[index].res_path);
            //strcat((S8*)tmpbuf, "ref_list*.txt ");
            //strcat((S8*)tmpbuf, MMI_RLM_TEMP_FOLDER);
            //strcat((S8*)tmpbuf, " /y/D 1>nul 2>nul");
            printf("Copy ref_list*.txt from [%s]\n",g_mmi_resource_base_table[index].res_path);
            //system(tmpbuf);
            ////////////////////////////////////////////////////
            fFinished = FALSE;
            strcpy((S8*)tmpbuf, MMI_RLM_TO_MCU_MMI_PATH);
            strcat((S8*)tmpbuf, g_mmi_resource_base_table[index].res_path);
            strcat((S8*)tmpbuf, "ref_list*.txt ");
            search = FindFirstFile(tmpbuf, &file_data);
            if (search != INVALID_HANDLE_VALUE)
            {
                strcpy((S8*)tmpbuf, MMI_RLM_TO_MCU_MMI_PATH);
                strcat((S8*)tmpbuf, g_mmi_resource_base_table[index].res_path);
                strcat((S8*)tmpbuf, file_data.cFileName);
                strcpy((S8*)tmpbuf2, MMI_RLM_TEMP_FOLDER);
                strcat((S8*)tmpbuf2, file_data.cFileName);
                if (0 == stat(tmpbuf2, &ref_list_stat))
                {
                    ref_list_time = ref_list_stat.st_mtime;
                }
                else
                {
                    ref_list_time = 0;
                }
                if (0 == stat(tmpbuf, &ref_list_stat))
                {
                    printf("[Dependency] %s\n", tmpbuf);
                    if (ref_list_stat.st_mtime > ref_list_time)
                    {
                        if (0 == CopyFile(tmpbuf, tmpbuf2, FALSE))
                        {
                            printf("[Error] Fail to copy %s to %s\n", tmpbuf, tmpbuf2);
                        }
                    }
                }
                else
                {
                    printf("[Error] Fail to stat %s\n", tmpbuf);
                }
                while (!fFinished) 
                {
                    if (!FindNextFile(search, &file_data))
                    {
                        fFinished = TRUE; 
                    }
                    else
                    {
                        strcpy((S8*)tmpbuf, MMI_RLM_TO_MCU_MMI_PATH);
                        strcat((S8*)tmpbuf, g_mmi_resource_base_table[index].res_path);
                        strcat((S8*)tmpbuf, file_data.cFileName);
                        strcpy((S8*)tmpbuf2, MMI_RLM_TEMP_FOLDER);
                        strcat((S8*)tmpbuf2, file_data.cFileName);
                        if (0 == stat(tmpbuf2, &ref_list_stat))
                        {
                            ref_list_time = ref_list_stat.st_mtime;
                        }
                        else
                        {
                            ref_list_time = 0;
                        }
                        if (0 == stat(tmpbuf, &ref_list_stat))
                        {
                            printf("[Dependency] %s\n", tmpbuf);
                            if (ref_list_stat.st_mtime > ref_list_time)
                            {
                                if (0 == CopyFile(tmpbuf, tmpbuf2, FALSE))
                                {
                                    printf("[Error] Fail to copy %s to %s\n", tmpbuf, tmpbuf2);
                                }
                            }
                        }
                        else
                        {
                            printf("[Error] Fail to stat %s\n", tmpbuf);
                        }
                    }
                }
                if (!FindClose(search)) 
                {
                    printf("Couldn't close search handle.");
                }
            }
            ////////////////////////////////////////////////////
        }
        index++;
    }

    /* Read all files in temp\ref_list\ */
    fFinished = FALSE;
    search = FindFirstFile(MMI_RLM_TEMP_FOLDER_SEARCH, &file_data);  
    if (search == INVALID_HANDLE_VALUE)
    {
        printf("Didn't find any ref_list_xxx.txt file in temp\\ref_list\\ ret=[%d]\n", GetLastError());
    }
    else
    {
        printf("FindFirstFile[%s]\n", file_data.cFileName);
    
        while (!fFinished) 
        {
            if ((strcmp(FILENAME_REF_LIST_ONLY_OTHER, file_data.cFileName) != 0) && 
                (strcmp(FILENAME_REF_LIST_ONLY_TRANS, file_data.cFileName) != 0))
            {
                /* write header of file to duplicate file */
                ASCII2UCS2((U8*)file_data.cFileName, tmp_buf);
                wcscat(tmp_buf, L"\r\n");
                fputws(L"-------------------------------------------------------------------\r\n", g_ref_dup);
                fputws(tmp_buf, g_ref_dup);

                strcpy((char*)tmp_buf, MMI_RLM_TEMP_FOLDER);
                strcat((char*)tmp_buf, file_data.cFileName);
            
                /* Handle current found file */
                ReadReflistFile((char *)(tmp_buf));
            }
            
            if (!FindNextFile(search, &file_data)) 
            {
                printf("No more .TXT files in temp\\ref_list\\. Search completed.\n");
                fFinished = TRUE; 
            }
            else
            {
                printf("FindNextFile[%s]\n", file_data.cFileName);
            }
        } 

        /* Close the search handle. */
        if (!FindClose(search)) 
        {
            printf("Couldn't close search handle.");
        }    
            
    }


    /* Write header of file to duplicate file */
    ASCII2UCS2((U8*)FILENAME_REF_LIST_ONLY_OTHER, tmp_buf);
    wcscat(tmp_buf, L"\r\n");
    fputws(L"-------------------------------------------------------------------\r\n", g_ref_dup);
    fputws(tmp_buf, g_ref_dup);
    
    /* Handle current found file */
    ReadReflistFile((char *)FILENAME_REF_LIST_OTHER);

    /* DEBUG: Output Hash table result */
    if (0)
    {
        struct HashItem *cur_node;
        int count;
        int totalcount;

        totalcount = 0;

        for (i = 0; i < g_hash_range; i++)
        {
            cur_node = &(g_ht[i]);
            count = 0;

            while (cur_node->next != NULL)
            {
                count++;
                totalcount++;
                cur_node = cur_node->next;
            }
            if (count > 0)
            {
                printf("HashTable Multi node [%05d][%d]\n", i, count);
            }
        }
        printf("HashTable total node [%d]\n", totalcount);
    }

    /* Merge new file. */
    MergeToRefList();

    /* Close Log files */
    fclose(g_ref_dup);
    //fclose(g_ref_not_used);
    
    printf("---------- MergeRefList End ----------\n");
    /* End of ref_list merge */
    printf("ref_list success\n");
    
    g_error = 1;
    return 1;    
END_REF:
    return 0;
}

