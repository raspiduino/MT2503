#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "mmi_features.h"

#define PLMN_MIN_LENGTH                    5
#define PLMN_MAX_LENGTH                    6
#define PLMN_CREATOR_MAX_SUPPORT_LANGUAGES 120
#define PLMN_CREATOR_MAX_SUPPORT_RECORDS   700
#define PLMN_CREATOR_MAX_OPNAME_LENGTH     512
#define PLMN_CREATOR_MAX_MCCMNC_LENGTH     512

#define MAX_LENGTH_DISPLAY_NAME            24 /* need to sync with the target definition */

#define PLMNLIST_FILE_PATH    "..\\CustResource\\plmnlist.txt"
#define REF_LIST_FILE_PATH    "..\\CustResource\\Ref_list.txt"
#define RES_FILE_PATH         "..\\Res_MMI\\Res_MiscFramework.c"
#define PLMN_ENUM_FILE_PATH   "..\\..\\MMI\\MiscFramework\\MiscFrameworkInc\\PlmnEnum.h"
#define PLMN_NAME_FILE_PATH   "..\\..\\Service\\NetSetSrv\\PlmnName.c"

#define PLMN_NAME_TABLE_KEYWORD "plmncreate.exe:"
#define PLMN_BCD_TABLE_KEYWORD "PLMN BCD"
#define PLMN_INDEX_TABLE_KEYWORD "PLMN INDEX"
#define PLMN_GROUP_TABLE_KEYWORD "PLMN GROUP"
#define PLMN_NAME_ENDING_KEYWORD "/* DONE */"

#define EMPTY_INIT (0xFFFF)
#define LANGUAGE_IDX_ENABLE (0)

#define PLMN_ASCII_TABLE_BASE (0x1000)

typedef struct
{
    char *opname;
    char *mccmnc;
    char *extname[PLMN_CREATOR_MAX_SUPPORT_LANGUAGES];
    char is_single_language;
    unsigned int lang_string_idx;
} plmn_record_in_unicode;

unsigned char *res_buffer;
unsigned int plmn_num = 0;
unsigned int actual_lang_count = 0;
unsigned int total_language = 0;
unsigned char language_title[PLMN_CREATOR_MAX_SUPPORT_LANGUAGES][40];   /* 120 languages, 20 words */
plmn_record_in_unicode plmn_array[PLMN_CREATOR_MAX_SUPPORT_RECORDS];


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_unicode_2_ansii
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pOutBuffer      [OUT]     
 *  pInBuffer       [IN]     
 * RETURNS
 *  
 *****************************************************************************/
unsigned short plmn_creator_unicode_2_ansii(unsigned char *pOutBuffer, unsigned char *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned short count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!((*pInBuffer == 0) && (*(pInBuffer + 1) == 0)))
    {
        *pOutBuffer = *(pInBuffer);
        pInBuffer += 2;
        pOutBuffer++;
        count++;
    }
    *pOutBuffer = 0;
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_find_keyword
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_buffer     [IN]         
 *  buffer_size     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
unsigned long plmn_creator_find_keyword(unsigned char *file_buffer, unsigned long buffer_size, const char *keyword, const char *end_keyword)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned long i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < buffer_size - strlen(keyword); i++)
    {
        if (memcmp(file_buffer + i, keyword, strlen(keyword)) == 0)
        {
            for (j = 0;; j++)
            {
                if (*(file_buffer + i + j) == 0x0D && *(file_buffer + i + j + 1) == 0x0A)
                {
                    break;
                }
            }

            /* Avoid to re-add resources */
            if (memcmp(file_buffer + i + j + 2, end_keyword, strlen(end_keyword)) == 0)
            {
                return 0;
            }
            else
            {
                return i + j + 2;
            }
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_plmn_str_2_bcd_short
 * DESCRIPTION
 *  
 * PARAMETERS
 *  plmn        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
unsigned long mmi_netset_plmn_str_2_bcd_short(unsigned char *plmn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned long b1 = 0, b2 = 0, b3 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b1 = (*plmn - 0x30) + ((*(plmn + 1) - 0x30) << 4);
    b2 = (*(plmn + 2) - 0x30) + (*(plmn + 5) == 0 ? 0xF0 : ((*(plmn + 5) - 0x30) << 4));
    b3 = (*(plmn + 3) - 0x30) + ((*(plmn + 4) - 0x30) << 4);
    return b1 + (b2 << 8) + (b3 << 16);
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_unicode_strlen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  unicode_string      [IN]     
 * RETURNS
 *  
 *****************************************************************************/
unsigned short plmn_creator_unicode_strlen(unsigned char *unicode_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned short i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!(*(unicode_string + i) == 0 && *(unicode_string + i + 1) == 0))
    {
        i += 2;
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_modify_plmn_enum_h
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_modify_plmn_enum_h(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fptr;
    unsigned char *read_file;
    unsigned long i = 0, read_size, insert_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file */
    /* if( (fptr = fopen("..\\CustomerInc\\CustResDef.h", "rb")) == NULL) */
    if ((fptr = fopen(PLMN_ENUM_FILE_PATH, "rb")) == NULL)
    {
        return;
    }

    /* get file size */
    fseek(fptr, 0, SEEK_END);
    read_size = ftell(fptr);
    read_file = malloc(read_size);

    /* read it to the buffer */
    fseek(fptr, 0, SEEK_SET);
    fread(read_file, 1, read_size, fptr);
    fclose(fptr);

    /* find keyword to insert strings in next line */
    insert_pos = plmn_creator_find_keyword(read_file, read_size, PLMN_NAME_TABLE_KEYWORD, PLMN_NAME_ENDING_KEYWORD);

    if (insert_pos == 0)
    {
        free(read_file);
        return;
    }

    /* update file */
    /* fptr = fopen("..\\CustomerInc\\CustResDef.h", "wb"); */
    fptr = fopen(PLMN_ENUM_FILE_PATH, "wb");
    fwrite(read_file, 1, insert_pos, fptr);

    fprintf(fptr, "/* DONE */\n");

    for (i = 0; i < actual_lang_count; i++)
    {
        if (i == 0)
        {
            fprintf(fptr, "   STR_PLMN_NAME_%d = NETSET_SRV_BASE + 50,\n", i + 1);
        }
        else if (i == actual_lang_count - 1)
        {
            fprintf(fptr, "   STR_PLMN_NAME_%d\n", i + 1);
        }
        else
        {
            fprintf(fptr, "   STR_PLMN_NAME_%d,\n", i + 1);
        }
    }

    fwrite(read_file + insert_pos, 1, read_size - insert_pos, fptr);
    fclose(fptr);

    free(read_file);
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_modify_Res_MiscFramework_c
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_modify_Res_MiscFramework_c(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fptr;
    unsigned char *read_file;
    unsigned long i = 0, j= 0, read_size, insert_pos;
    unsigned char des_opname[PLMN_CREATOR_MAX_OPNAME_LENGTH], des_mccmnc[PLMN_CREATOR_MAX_MCCMNC_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file */
    if ((fptr = fopen(RES_FILE_PATH, "rb")) == NULL)
    {
        return;
    }

    /* get file size */
    fseek(fptr, 0, SEEK_END);
    read_size = ftell(fptr);
    read_file = malloc(read_size);

    /* read it to the buffer */
    fseek(fptr, 0, SEEK_SET);
    fread(read_file, 1, read_size, fptr);
    fclose(fptr);

    /* find keyword to insert strings in next line */
    insert_pos = plmn_creator_find_keyword(read_file, read_size, PLMN_NAME_TABLE_KEYWORD, PLMN_NAME_ENDING_KEYWORD);

    if (insert_pos == 0)
    {
        return;
    }

    /* update file */
    fptr = fopen(RES_FILE_PATH, "wb");
    fwrite(read_file, 1, insert_pos, fptr);

    fprintf(fptr, "/* DONE */\n");

    for (i = 0; i < actual_lang_count; i++)
    {
        for (j = 0; j < plmn_num; j++)
    	{
    		if(plmn_array[j].lang_string_idx == i)
    		{
                break;
    		}
    	}
        if (j == plmn_num)
    	{
    	    printf("Do not find string for STR_PLMN_NAME_%d", i);
            continue;
    	}
        plmn_creator_unicode_2_ansii(des_opname, plmn_array[j].opname);
        plmn_creator_unicode_2_ansii(des_mccmnc, plmn_array[j].mccmnc);
        fprintf(
            fptr,
            "   ADD_APPLICATION_STRING2(STR_PLMN_NAME_%d,\"%s\",\"PLMN Name %s.\");\n",
            i + 1,
            des_opname,
            des_mccmnc);
    }

    fwrite(read_file + insert_pos, 1, read_size - insert_pos, fptr);
    fclose(fptr);

    free(read_file);
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_modify_plmn_name_c
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_modify_plmn_name_c(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fptr;
    unsigned char *read_file;
    unsigned long i = 0, j = 0, k = 0, read_size, insert_pos, index_table_insert_pos, string_table_insert_pos;
    unsigned char des_mccmnc[PLMN_CREATOR_MAX_MCCMNC_LENGTH];
    unsigned short separator_template[] = {0x002C, 0x0020};
    unsigned short ending_template[] = {0x0000};
    unsigned char tmp_mccmnc[PLMN_CREATOR_MAX_MCCMNC_LENGTH * 2];
    unsigned long string_id = 0;
    unsigned char des_opname[PLMN_CREATOR_MAX_MCCMNC_LENGTH];
    unsigned long opname_count = 0;
	unsigned int opname_string_zero_is_init = 0;
    char is_add_group_id;
    unsigned int group_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file */
    /* if( (fptr = fopen("..\\CustResource\\CustMiscData.c", "rb")) == NULL) */
    if ((fptr = fopen(PLMN_NAME_FILE_PATH, "rb")) == NULL)
    {
        return;
    }

    /* get file size */
    fseek(fptr, 0, SEEK_END);
    read_size = ftell(fptr);
    read_file = malloc(read_size);

    /* read it to the buffer */
    fseek(fptr, 0, SEEK_SET);
    fread(read_file, 1, read_size, fptr);
    fclose(fptr);

    /* find keyword to insert strings in next line */
    insert_pos = plmn_creator_find_keyword(read_file, read_size, PLMN_BCD_TABLE_KEYWORD, PLMN_NAME_ENDING_KEYWORD);

    if (insert_pos == 0)
    {
        return;
    }

    /* update file */
    /* fptr = fopen("..\\CustResource\\CustMiscData.c", "wb"); */
    fptr = fopen(PLMN_NAME_FILE_PATH, "wb");
    fwrite(read_file, 1, insert_pos, fptr);

    fprintf(fptr, "/* DONE */\n");

    /* Output MCC/MNC and string index */
    for (i = 0; i < plmn_num; i++)
    {
        /* i = group ID */
        for (j = 0;; j += 2)
        {
            if (memcmp((void*)ending_template, plmn_array[i].mccmnc + j, 2) == 0)
            {
                break;
            }
            if (memcmp((void*)separator_template, plmn_array[i].mccmnc + j, 4) != 0)
            {
                tmp_mccmnc[k] = plmn_array[i].mccmnc[j];
                tmp_mccmnc[k + 1] = plmn_array[i].mccmnc[j + 1];
                k += 2;
            }
            else
            {
                tmp_mccmnc[k] = 0;
                tmp_mccmnc[k + 1] = 0;
                plmn_creator_unicode_2_ansii(des_mccmnc, tmp_mccmnc);
                fprintf(fptr, "   0x%06x,\n", mmi_netset_plmn_str_2_bcd_short(des_mccmnc));
                k = 0;
                j += 2;
            }
        }
        tmp_mccmnc[k] = 0;
        tmp_mccmnc[k + 1] = 0;
        plmn_creator_unicode_2_ansii(des_mccmnc, tmp_mccmnc);
        fprintf(fptr, "   0x%06x,\n", mmi_netset_plmn_str_2_bcd_short(des_mccmnc));
        k = 0;
    }

    index_table_insert_pos = plmn_creator_find_keyword(read_file, read_size, PLMN_INDEX_TABLE_KEYWORD, PLMN_NAME_ENDING_KEYWORD);

    /* Insert the text between PLMN index table and string table */
    fwrite(read_file + insert_pos, 1, index_table_insert_pos - insert_pos, fptr);

    insert_pos = index_table_insert_pos;

    if (index_table_insert_pos == 0)
    {
        return;
    }

    for (i = 0; i < plmn_num; i++)
    {
        /* i = group ID */
        for (j = 0;; j += 2)
        {
            if (memcmp((void*)ending_template, plmn_array[i].mccmnc + j, 2) == 0)
            {
                break;
            }
            if (memcmp((void*)separator_template, plmn_array[i].mccmnc + j, 4) != 0)
            {
                tmp_mccmnc[k] = plmn_array[i].mccmnc[j];
                tmp_mccmnc[k + 1] = plmn_array[i].mccmnc[j + 1];
                k += 2;
            }
            else
            {
           	    string_id = plmn_array[i].lang_string_idx;
                fprintf(fptr, "   %d,\n", string_id);
                k = 0;
                j += 2;
            }
        }
  	    string_id = plmn_array[i].lang_string_idx;
        fprintf(fptr, "   %d,\n", string_id);
        k = 0;
    }
    
    index_table_insert_pos = plmn_creator_find_keyword(read_file, read_size, PLMN_GROUP_TABLE_KEYWORD, PLMN_NAME_ENDING_KEYWORD);


    /* Insert the text between PLMN index table and string table */
    fwrite(read_file + insert_pos, 1, index_table_insert_pos - insert_pos, fptr);

    insert_pos = index_table_insert_pos;


    /* Output MCC/MNC and string index */
    for (i = 0; i < plmn_num; i++)
    {
        /* i = group ID */
        is_add_group_id = 0;
        for (j = 0;; j += 2)
        {
            /* If there are two or more MCC/MNC put in mccmnc, add group ID data */
            if (memcmp((void*)ending_template, plmn_array[i].mccmnc + j, 2) == 0)
            {
                break;
            }
            
            if (memcmp((void*)separator_template, plmn_array[i].mccmnc + j, 4) == 0)
            {
                is_add_group_id = 1;
                break;
            }
        }
        if (!is_add_group_id)
    	{
    	    continue;
    	}
        /* Add group ID */
        for (j = 0;; j += 2)
        {
            if (memcmp((void*)ending_template, plmn_array[i].mccmnc + j, 2) == 0)
            {
                break;
            }
            if (memcmp((void*)separator_template, plmn_array[i].mccmnc + j, 4) != 0)
            {
                tmp_mccmnc[k] = plmn_array[i].mccmnc[j];
                tmp_mccmnc[k + 1] = plmn_array[i].mccmnc[j + 1];
                k += 2;
            }
            else
            {
                tmp_mccmnc[k] = 0;
                tmp_mccmnc[k + 1] = 0;
                plmn_creator_unicode_2_ansii(des_mccmnc, tmp_mccmnc);
                fprintf(fptr, "   {0x%06x, %d},\n", mmi_netset_plmn_str_2_bcd_short(des_mccmnc), group_id);
                k = 0;
                j += 2;
            }
        }
        tmp_mccmnc[k] = 0;
        tmp_mccmnc[k + 1] = 0;
        plmn_creator_unicode_2_ansii(des_mccmnc, tmp_mccmnc);
        fprintf(fptr, "   {0x%06x, %d},\n", mmi_netset_plmn_str_2_bcd_short(des_mccmnc), group_id);
        k = 0;
        group_id++;
    }
   
    fwrite(read_file + index_table_insert_pos, 1, read_size - index_table_insert_pos, fptr);

    fclose(fptr);

    free(read_file);
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_modify_Ref_list_txt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_modify_Ref_list_txt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fptr;
    unsigned char *read_file;
    unsigned long i = 0, j = 0, read_size, insert_pos;
    char *keyword = (char*)L"##number";
    unsigned short tab_template[] = {0x0009};
    unsigned short new_line_template[] = {0x000D, 0x000A};
    unsigned short max_display_lenght = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file */
    if ((fptr = fopen(REF_LIST_FILE_PATH, "rb")) == NULL)
    {
        return;
    }

    /* get file size */
    fseek(fptr, 0, SEEK_END);
    read_size = ftell(fptr);
    read_file = malloc(read_size);

    /* read it to the buffer */
    fseek(fptr, 0, SEEK_SET);
    fread(read_file, 1, read_size, fptr);
    fclose(fptr);

    /* find keyword to insert strings in next line */
    /* insert_pos = plmn_creator_find_keyword(read_file, read_size); */
    for (i = 0; i < read_size - strlen("##number") * 2; i++)
    {
        if (memcmp(read_file + i, keyword, strlen("##number") * 2) == 0)
        {
            insert_pos = i;
            break;
        }
    }

    /* update file */
    fptr = fopen(REF_LIST_FILE_PATH, "wb");
    fwrite(read_file, 1, insert_pos, fptr);

    for (i = 0; i < plmn_num; i++)
    {
        /* fwprintf(fptr, L"STR_PLMN_NAME_%d    Undefined       %d      PLMN Name %s    ", i+1, plmn_creator_unicode_strlen(plmn_array[i].opname)/2, plmn_array[i].mccmnc); */
        if (plmn_array[i].is_single_language == 1)
    	{
            /* only add the multi language PLMN data for resgen */
    	    continue;
    	}
        
        fwprintf(
            fptr,
            L"STR_PLMN_NAME_%d	Undefined	%d	PLMN Name %c%c%c%c%c	",
            plmn_array[i].lang_string_idx + 1,
            plmn_creator_unicode_strlen(plmn_array[i].opname) / 2,
            *plmn_array[i].mccmnc,
            *(plmn_array[i].mccmnc + 2),
            *(plmn_array[i].mccmnc + 4),
            *(plmn_array[i].mccmnc + 6),
            *(plmn_array[i].mccmnc + 8));

        max_display_lenght =
            (plmn_creator_unicode_strlen(plmn_array[i].opname) / 2 >= MAX_LENGTH_DISPLAY_NAME)
            ? MAX_LENGTH_DISPLAY_NAME - 1
            : plmn_creator_unicode_strlen(plmn_array[i].opname) / 2;
        fwrite((void*)plmn_array[i].opname, 1, max_display_lenght * 2, fptr);

        for (j = 0; j < total_language; j++)
        {
            fwrite((void*)tab_template, 1, sizeof(tab_template), fptr);
            if (plmn_array[i].extname[j] == NULL)
            {
                max_display_lenght =
                    (plmn_creator_unicode_strlen(plmn_array[i].opname) / 2 >= MAX_LENGTH_DISPLAY_NAME)
                    ? MAX_LENGTH_DISPLAY_NAME - 1
                    : plmn_creator_unicode_strlen(plmn_array[i].opname) / 2;
                fwrite((void*)plmn_array[i].opname, 1, max_display_lenght * 2, fptr);
            }
            else
            {
                max_display_lenght =
                    (plmn_creator_unicode_strlen(plmn_array[i].extname[j]) / 2 >= MAX_LENGTH_DISPLAY_NAME) 
                    ? MAX_LENGTH_DISPLAY_NAME - 1
                    : plmn_creator_unicode_strlen(plmn_array[i].extname[j]) / 2;
                fwrite((void*)plmn_array[i].extname[j], 1, max_display_lenght * 2, fptr);
            }
        }
        fwrite((void*)tab_template, 1, sizeof(tab_template), fptr);
        fwrite((void*)new_line_template, 1, sizeof(new_line_template), fptr);
    }

    fwrite(read_file + insert_pos, 1, read_size - insert_pos, fptr);
    fclose(fptr);

    free(read_file);
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_check_mccmnc_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  char * : a point to one mccmnc item
 * RETURNS
 *  int
 *****************************************************************************/
int plmn_creator_check_mccmnc_item(char *str)
{
    char mccmnc[(PLMN_MAX_LENGTH + 1) * 2];
    int i = 0;

    memset(mccmnc, 0x00, ((PLMN_MAX_LENGTH + 1) * 2));
    memcpy(mccmnc, str, plmn_creator_unicode_strlen(str));
    
    if ((plmn_creator_unicode_strlen(mccmnc) < (PLMN_MIN_LENGTH * 2)) || 
        (plmn_creator_unicode_strlen(mccmnc) > (PLMN_MAX_LENGTH * 2)))
    {
        char error_mccmnc[PLMN_CREATOR_MAX_MCCMNC_LENGTH];
        
        memset(error_mccmnc, 0x00, PLMN_CREATOR_MAX_MCCMNC_LENGTH);
        plmn_creator_unicode_2_ansii(error_mccmnc, str);
        printf("Invalid mccmnc : %s \n", error_mccmnc);
        return 0;
    }
        
    for (i = 0; i < ((PLMN_MAX_LENGTH + 1) * 2); i++)
    {
        if (i%2 == 0)
        {
            if ((mccmnc[i] <= '9') && (mccmnc[i] >= '0'))
                continue;

            if ((mccmnc[i] == 0) && (mccmnc[i+1] == 0))
                return 1;
        }
        else
        {
            if (mccmnc[i] == 0)
                continue;
        }

        if (mccmnc[i] == 0X20)
        {
            continue;
        }

        {
            char error_str[PLMN_MAX_LENGTH + 1];
        
            memset(error_str, 0x00, (PLMN_MAX_LENGTH + 1));
            plmn_creator_unicode_2_ansii(error_str, str);
            printf("Invalid mccmnc : %s \n", error_str);
            return 0;
        }
    }
    
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_check_mccmnc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  char * : a point to one mccmnc string
 * RETURNS
 *  int
 *****************************************************************************/
int plmn_creator_check_mccmnc(char *mccmnc)
{
    unsigned short mccmnc_template[] = {0x006D, 0x0063, 0x0063, 0x006D, 0x006E, 0x0063, 0x003D}; /* "mccmnc" */
    unsigned short separator_template[] = {0x002C, 0x0020}; /* ", " */
    unsigned short ending_template[] = {0x0000};
    unsigned short tab_template[] = {0x0009};   /* "\t" */
    unsigned short blank_template[] = {0x0020}; /* ' ' */
    char tmp_buffer[PLMN_CREATOR_MAX_MCCMNC_LENGTH];
    char tmp_buffer2[PLMN_CREATOR_MAX_MCCMNC_LENGTH];
    int i = 0;
    int j = 0;
    
    memset(tmp_buffer, 0x00, PLMN_CREATOR_MAX_MCCMNC_LENGTH);
    memset(tmp_buffer2, 0x00, PLMN_CREATOR_MAX_MCCMNC_LENGTH);
    
    memcpy(tmp_buffer, mccmnc, plmn_creator_unicode_strlen(mccmnc));
    
    if (plmn_creator_unicode_strlen(tmp_buffer) < (PLMN_MIN_LENGTH * 2))
    {
        plmn_creator_check_mccmnc_item(tmp_buffer);        
        return 0;
    }

    else if (plmn_creator_unicode_strlen(tmp_buffer) > (PLMN_MAX_LENGTH * 2))
    {
        if (plmn_creator_unicode_strlen(tmp_buffer) > PLMN_CREATOR_MAX_MCCMNC_LENGTH)
        {
            plmn_creator_unicode_2_ansii(tmp_buffer2, tmp_buffer);
            printf("so long mccmnc : %s", tmp_buffer2);
            return 0;
        }

        while (i < ((PLMN_MAX_LENGTH + 1) * 2))
        {
            if (memcmp((void*)ending_template, &tmp_buffer[j], 2) == 0)
            {
                if (plmn_creator_check_mccmnc_item(tmp_buffer2))
                    break;
                else
                    return 0;
            }

            if (memcmp((void*)tab_template, &tmp_buffer[j], 2) == 0)
            {
                j += 2;
            }

            if (memcmp((void*)blank_template, &tmp_buffer[j], 2) == 0)
            {
                j += 2;
            }
                
            if (memcmp((void*)separator_template, &tmp_buffer[j], 4) == 0)
            {
                j += 4;
                i = 0;
                
                if (plmn_creator_check_mccmnc_item(tmp_buffer2))
                {
                    memset(tmp_buffer2, 0x00, PLMN_CREATOR_MAX_MCCMNC_LENGTH);
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            
            tmp_buffer2[i] = tmp_buffer[j];
            i++;
            j++;
        }
    }
    else
    {
        if (plmn_creator_check_mccmnc_item(tmp_buffer))
            return 1;
        else
            return 0;
    }
    
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_read_op_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_read_op_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fptr;
    unsigned char tmp_buffer[PLMN_CREATOR_MAX_OPNAME_LENGTH];
    unsigned long res_size, count = 0, i, j, search_idx;
    unsigned short opname_template[] = {0x006F, 0x0070, 0x006E, 0x0061, 0x006D, 0x0065, 0x003D}; /* opname */
    unsigned short mccmnc_template[] = {0x006D, 0x0063, 0x0063, 0x006D, 0x006E, 0x0063, 0x003D}; /* mccmnc */
    unsigned short area_template[] = {0x0061, 0x0072, 0x0065, 0x0061, 0x003D}; /* area */
    unsigned short new_line_template[] = {0x000D, 0x000A};
    unsigned int multi_lang_count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file */
    if ((fptr = fopen(PLMNLIST_FILE_PATH, "rb")) == NULL)
    {
        return;
    }

    /* get file size */
    fseek(fptr, 0, SEEK_END);
    res_size = ftell(fptr);
    res_buffer = malloc(res_size);

    /* read it to the buffer */
    fseek(fptr, 0, SEEK_SET);
    fread(res_buffer, 1, res_size, fptr);
    fclose(fptr);

    /* skip unicode file header */
    res_buffer += 2;
    res_size -= 2;

    multi_lang_count = 0;
    
    do
    {
        /* read one line */
        for (i = 0;; i++)
        {
            if (memcmp((void*)new_line_template, res_buffer + count + i, 4) != 0)
            {
                *(tmp_buffer + i) = *(res_buffer + count + i);
            }
            else
            {
                memset(res_buffer + count + i, 0, 4);
                break;
            }
        }

        if (i == 0)
        {
            /* empty line, move to the next line */
            count += 4;
            continue;
        }

        if (memcmp(area_template, tmp_buffer, sizeof(area_template)) == 0)
        {
            /* area data, will not be generated to data, move to the next line */
            count += (i + 4);
            continue;
        }
        if (memcmp(opname_template, tmp_buffer, sizeof(opname_template)) == 0)
        {
            /* operator name */
            plmn_num++;
            plmn_array[plmn_num - 1].opname = res_buffer + count + sizeof(opname_template);
        }
        else if (memcmp(mccmnc_template, tmp_buffer, sizeof(mccmnc_template)) == 0)
        {
            /* mcc/mnc , multiple mcc/mnc will be saved, they will be save seperatly later */
            plmn_array[plmn_num - 1].mccmnc = res_buffer + count + sizeof(mccmnc_template);
            
            plmn_creator_check_mccmnc(plmn_array[plmn_num - 1].mccmnc);
        }
        else
        {
            /* multi-language */
            for (j = 0; j < total_language; j++)
            {
                if (memcmp(language_title[j], tmp_buffer, plmn_creator_unicode_strlen(language_title[j])) == 0)
                {
                    plmn_array[plmn_num - 1].extname[j] =
                    res_buffer + count + plmn_creator_unicode_strlen(language_title[j]) + 2;
                    plmn_array[plmn_num - 1].is_single_language = 0;
                    break;
                }
            }
        }
        count += (i + 4);
    } while (count < res_size);
    /* Prepare the language string index */
    for (i = 0; i < plmn_num; i++)
	{
        if (plmn_array[i].is_single_language == 1)
	    {
            /* no multi language check if there is duplicate language*/
            
            for (search_idx = 0; search_idx < i; search_idx++)
        	{
                /* Check if there is duplicate operator name */
                if (plmn_creator_unicode_strlen(plmn_array[i].opname) == plmn_creator_unicode_strlen(plmn_array[search_idx].opname))
            	{
            		if (memcmp(plmn_array[i].opname, plmn_array[search_idx].opname, plmn_creator_unicode_strlen(plmn_array[i].opname)) == 0)
                	{
                        plmn_array[i].lang_string_idx = plmn_array[search_idx].lang_string_idx;
                        break;
                	}            	
            	}
        	}
            if (search_idx == i)
        	{
        	    /* No duplicate operator name, assign a new index */
                plmn_array[i].lang_string_idx = actual_lang_count;
                actual_lang_count ++;
        	}
    	}
		else
		{
            plmn_array[i].lang_string_idx = actual_lang_count;
            actual_lang_count ++;
            multi_lang_count++;
		}
	}
  
    printf("\nTotal PLMN: %d, multi language: %d\n", plmn_num, multi_lang_count);
    
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_get_supported_languages
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_get_supported_languages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fptr;
    unsigned char *read_file;
    unsigned long i = 0, j = 0, k = 0, read_size;
    unsigned short new_line_template[] = {0x000D, 0x000A};
    unsigned short tab_template[] = {0x0009};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file */
    if ((fptr = fopen(REF_LIST_FILE_PATH, "rb")) == NULL)
    {
        return;
    }

    /* get file size */
    fseek(fptr, 0, SEEK_END);
    read_size = ftell(fptr);
    read_file = malloc(read_size);

    /* read it to the buffer */
    fseek(fptr, 0, SEEK_SET);
    fread(read_file, 1, read_size, fptr);
    fclose(fptr);

    /* get total languages */
    for (i = 0;; i++)
    {
        if (memcmp((void*)new_line_template, read_file + i, 4) == 0)
        {
            i += 4;
            break;
        }
    }

    do
    {
        if (memcmp((void*)tab_template, read_file + i, 2) == 0)
        {
            j++;
        }
        /* else */
        i++;
    }
    while (j < 5);  /* skip Enum Value, Module Name, Max String Length, Description, English */

    i += 1;
    j = 0;

    do
    {
        if (memcmp((void*)tab_template, read_file + i, 2) == 0)
        {
            memset(language_title[j] + k, 0, 2);
            j++;
            k = 0;
            total_language++;
        }
        else
        {
            memcpy(language_title[j] + k, read_file + i, 2);
            k += 2;
        }
        i += 2;
    }
    while (memcmp((void*)new_line_template, read_file + i, 4) != 0);

    free(read_file);
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned short i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < PLMN_CREATOR_MAX_SUPPORT_RECORDS; i++)
    {
        for (j = 0; j < PLMN_CREATOR_MAX_SUPPORT_LANGUAGES; j++)
        {
            plmn_array[i].extname[j] = NULL;
        }
        plmn_array[i].lang_string_idx = 0;
        plmn_array[i].is_single_language = 1;
    }
}

static int g_error = -1;


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
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set program exit */
    atexit(resgen_on_exit);  
      
    printf("plmn create\n");

    plmn_creator_init();
    plmn_creator_get_supported_languages();
    plmn_creator_read_op_resource();

    /* Add string enum and resource for multiple language string */
    printf("Preparing PlmnEnum.h\n");
    plmn_creator_modify_plmn_enum_h();
    /* Gsm related */
    /* If modem is undefined, plmn code & string should not be populated.*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    printf("Preparing Res_MiscFramework.c\n");
    plmn_creator_modify_Res_MiscFramework_c();
    printf("Preparing Ref_list.txt\n");
    plmn_creator_modify_Ref_list_txt();

    printf("Preparing PlmnName.c\n");
    plmn_creator_modify_plmn_name_c();
    #endif
    free(res_buffer - 2);
    printf("done!\n");
    g_error = 1;
}

