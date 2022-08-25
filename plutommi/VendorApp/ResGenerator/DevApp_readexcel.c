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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <tchar.h>
#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalMenuItems.h"
//#include "SSCStringHandle.h"
#include "CustResDef.h"
#include "FontRes.h"
#include "CustDataRes.h"
#include "DevAppDef.h"
#ifdef __FLAVOR_VENDOR_SDK__
#include "mmi_rp_app_avk_def.h"
#endif
//#include "mmi_rp_app_devapp_def.h"
#include "mmi_rp_all_defs.h"
#include "enum_list.h"

/* get fontres data */
extern const U16 mtk_gMaxDeployedLangs;
extern const sLanguageDetails mtk_gLanguageArray[];

int *mtk_gLanguageFlag;

const wchar_t *DELIMETER = L"\t\0";

typedef struct StrRes
{
    wchar_t **Str;  /* pointer array of lists to store Strings */
    int *StrID;     /* id pointers  of each string */
    int *StrRef;    /* pointers of Reference id in hash table of each string */
    int MaxID;      /* Maximum number of string ids */
    int MaxNum;     /* Maximum number of strings */
    int TotalLength;
} StrRes;

typedef struct StrResSet
{
    struct StrRes *strres;
    int iLang;
} StrResSet;

typedef struct HashItem
{
    int pointer;    /* index in string array */
    struct HashItem *next;
} HashItem;


/*****************************************************************************
 * FUNCTION
 *  mask_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  val     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int mask_length(int val)
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
 *  
 * PARAMETERS
 *  base        [IN]        
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int pow(int base, int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, ret = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < index; i++)
    {
        ret = ret * base;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  fmod
 * DESCRIPTION
 *  
 * PARAMETERS
 *  denominator     [IN]        
 *  numerator       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int fmod(int denominator, int numerator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = denominator;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (ret >= numerator)
    {
        ret = ret - numerator;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  GetHashValue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string          [?]         [?]
 *  hash_range      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int GetHashValue(wchar_t *string, int hash_range)
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
    val = (int)fmod(val, hash_range);
    return (int)val;
}

/*********************************************************************
Function Name:       Trans
Function Description:   Transform UCS2-encoding "\","n" to "\n"
Return Value:        
                  0:       no transformation is done.
                  1:       transformation is done.
Function Input:
                  string:     input string
                  buf:     output string
*********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  Trans
 * DESCRIPTION
 *  Transform UCS2-encoding "\","n" to "\n"
 * PARAMETERS
 *  string      [?]     [?]
 *  buf         [?]     [?]
 * RETURNS
 *  0:       no transformation is done.
 *  1:       transformation is done.
 *****************************************************************************/
int Trans(wchar_t *string, wchar_t *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wchar_t *p = NULL;
    const wchar_t cr[] = L"\\n";
    unsigned int i = 0;
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
        {
            buf[l] = string[i];
        }
        l++;
    }
    buf[l] = L'\0';
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  UCS2ASCII
 * DESCRIPTION
 *  
 * PARAMETERS
 *  w_in        [?]     [?]
 *  a_out       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void UCS2ASCII(char *w_in, char *a_out)
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
        {
            i--;
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  ifLanguageUsed
 * DESCRIPTION
 *  Decide if the translated language should be used for
 *  string resource, according to SSC string.
 * PARAMETERS
 *  ssc_ref     [IN]        SSC string defined in ref_list.txt
 * RETURNS
 *  -1: The language is not used.
 *  >=0: The index in FontRes
 *****************************************************************************/
int ifLanguageUsed(wchar_t *ssc_ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    char ascii_ssc[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UCS2ASCII((char*)ssc_ref, ascii_ssc);
    for (i = 0; i < mtk_gMaxDeployedLangs; i++)
    {
        if (strcmp(mtk_gLanguageArray[i].aLangSSC, ascii_ssc) == 0)
        {
            return i;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  GetStrResList
 * DESCRIPTION
 *  Generate a non-duplicate string list from input file, using hash table
 * PARAMETERS
 *  file        [IN]        Input file contains string lists
 *  result      [IN]        Non-duplicate string list
 * RETURNS
 *  Number of all strings
 *****************************************************************************/
int GetStrResList(FILE *file, StrResSet *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *f = file;
    struct HashItem **ht = NULL, *extra = NULL, *temp = NULL;
    struct StrRes *strres = NULL;
    wchar_t tmp0[1024], *tmp = NULL, *tok = NULL, *buf = NULL;
    int i = 0, j = 0, k = 0, h = 0, iMaxID = -2, l = 0, STRID = 0;      /* ;,*iMaxNum=NULL; */
    int iLang = 0;      /* number of languages */
    int LangIndex = 0;  /* Language index in mtk_gLanguageArray */
    int hash_range = 0; /* the value-range of hash function */
    int num = 0;        /* number of distinct strings */
    int nStringLen = 0; /* String Length for UCS2 ENCODING */
    int order = 0;
    int position = 0;   /* the position to insert a new string */
    int buffer_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read in number of languages in the file */
    fgetws(tmp0, 1024, f);
    tok = wcstok(tmp0, DELIMETER);
    tok = wcstok(NULL, DELIMETER);
    iLang = _wtoi(tok);
    /* number language should be from FontRes.c */

    buffer_size = 512 * iLang;
    tmp = malloc(sizeof(wchar_t) * buffer_size);
    memset(tmp, buffer_size, '0');
    /* Read maximum string number defined at the end of file. */
    while (tmp[0] != (wchar_t) '#' && tmp[1] != (wchar_t) '#')
    {
        fgetws(tmp, buffer_size, f);
        iMaxID++;
    }
    tok = wcstok(tmp, DELIMETER);
    tok = wcstok(NULL, DELIMETER);
    /*
     * Number of Languages used should be referenced from FontRes.c
     * strres = malloc (sizeof(struct StrRes)*iLang);
     * ht = malloc(sizeof(struct HashItem*)*iLang);
     */
    strres = malloc(sizeof(struct StrRes) * mtk_gMaxDeployedLangs);
    ht = malloc(sizeof(struct HashItem*) * mtk_gMaxDeployedLangs);

    mtk_gLanguageFlag = malloc(sizeof(int) * mtk_gMaxDeployedLangs);    /* 010405 Calvin added */
    for (h = 0; h < mtk_gMaxDeployedLangs; h++)
    {
        mtk_gLanguageFlag[h] = 0;
    }

    for (j = 0; j < iLang; j++)
    {
        rewind(f);                      /* reset to the start of file */
        num = 0;
        /* skip first two row (number of languages and language description), and start from third row to read in SSC String. */
        fgetws(tmp, buffer_size, f);
        fgetws(tmp, buffer_size, f);
        fgetws(tmp, buffer_size, f);
        /* printf ("\n"); */
        tok = wcstok(tmp, DELIMETER);   /* INDEX */
        tok = wcstok(NULL, DELIMETER);  /* ENUM */
        tok = wcstok(NULL, DELIMETER);  /* MODULE NAME */
        tok = wcstok(NULL, DELIMETER);  /* MAX LENGTH */
        tok = wcstok(NULL, DELIMETER);  /* DESCRIPTION */
        /* change to corresponding language column according to j */
        for (k = 0; k < j + 1; k++)
        {
            tok = wcstok(NULL, DELIMETER);
        }
        LangIndex = ifLanguageUsed(tok);

        if (LangIndex < 0)  /* The language is not used in font resource. */
        {
            continue;
        }
        rewind(f);

        mtk_gLanguageFlag[LangIndex] = 1;   /* 010405 Calvin added */

        strres[LangIndex].Str = (wchar_t **) malloc(sizeof(wchar_t*) * iMaxID);
        strres[LangIndex].StrID = (int*)malloc(sizeof(int) * iMaxID + 1);
        strres[LangIndex].StrRef = (int*)malloc(sizeof(int) * iMaxID);
        /* Set default value */
        for (l = 0; l < iMaxID; l++)
        {
            strres[LangIndex].StrID[l] = -1;
            strres[LangIndex].StrRef[l] = -1;
            strres[LangIndex].TotalLength = 0;
        }

        /* set hash_range as maximum id times 1.1(Can be changed) */
        hash_range = (int)(iMaxID * 1.1);

        /* initialize hash table */
        ht[LangIndex] = (struct HashItem*)malloc(sizeof(struct HashItem) * hash_range);
        for (k = 0; k < hash_range; k++)
        {
            ht[LangIndex][k].next = NULL;
            ht[LangIndex][k].pointer = -1;
        }
        /* skip first two row (number of languages and language description), and start from third row. */
        fgetws(tmp, buffer_size, f);
        fgetws(tmp, buffer_size, f);
        fgetws(tmp, buffer_size, f);
        fgetws(tmp, buffer_size, f);

        k = 0;
        i = 0;  /* number of Ref(non-duplicate strings, excluding NULL) */
        l = -1; /* number of ID (all strings) */
        /* start to read file */
        while (!feof(f))
        {
            /* Clear the tempopary buffer */
            if (buf != NULL)
            {
                tok = NULL;
                free(buf);
                buf = NULL;
            }
            /* The last line of file */
            if (tmp[0] == (wchar_t) '#')
            {
                break;
            }

            l++;
            /* Read in ID of the string */
            tok = wcstok(tmp, DELIMETER);
            tok = wcstok(NULL, DELIMETER);  /* skip INDEX */
            tok = wcstok(NULL, DELIMETER);  /* skip originally existing Module Name, JL */
            tok = wcstok(NULL, DELIMETER);  /* skip originally existing Max String Length, JL */
            /* STRID=_wtoi(tok); */
            STRID = ENUM_VALUE_MAP[l];
            /* string description */
            tok = wcstok(NULL, DELIMETER);
            /* change to corresponding language column according to j */
            for (k = 0; k < j + 1; k++)
            {
                tok = wcstok(NULL, DELIMETER);
                if (tok != NULL && tok[wcslen(tok) - 1] == (wchar_t) '\n')
                {   /* Remove carriage-return */
                    tok[wcslen(tok) - 2] = '\0';
                }
            }
            /* decise if the read-in string is " " (blank) */
            if (tok != NULL && wcslen(tok) == 1 && tok[0] == 20)
            {
                tok = NULL;
            }
            /* Handling NULL read-in string. Insert its id into id list, it's Ref is default value -1; */
            if (tok == NULL)
            {
                order = 0;
                /* sorting on id ascendant */
                while (order < l)
                {
                    if (STRID > strres[LangIndex].StrID[order])
                    {
                        order++;
                    }
                    else
                    {
                        break;
                    }
                }
                /* insert the string into the list */
                position = order;
                order = l;
                while (order > position)
                {
                    strres[LangIndex].StrRef[order] = strres[LangIndex].StrRef[order - 1];
                    strres[LangIndex].StrID[order] = strres[LangIndex].StrID[order - 1];
                    order--;
                }
                strres[LangIndex].StrID[position] = STRID;
            }
            /* End of handling NULL string */

            if (tok != NULL)
            {
                /* change \n to 0X0A */
                buf = malloc((wcslen(tok) + 1) * 2);
                /* Transform "\""n", if no transformation is done, free the memory used. */
                if (Trans(tok, buf) == 0)
                {
                    free(buf);
                    buf = NULL;
                }
                else
                {
                    tok = buf;
                }
                /* calculate hash value */
                h = GetHashValue(tok, hash_range);
                if (ht[LangIndex][h].pointer == -1)
                {   /* no duplicate hash value */
                    /* int z=0; */
                    ht[LangIndex][h].pointer = i;
                    ht[LangIndex][h].next = NULL;
                    /* z=wcslen(tok); */
                    strres[LangIndex].Str[i] = (wchar_t*) malloc(wcslen(tok) * 2 + 2);
                    wcscpy(strres[LangIndex].Str[i], tok);
                    /* insert the string into the list */
                    order = 0;
                    while (order < l)
                    {
                        if (STRID > strres[LangIndex].StrID[order])
                        {
                            order++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    position = order;
                    order = l;
                    while (order > position)
                    {
                        strres[LangIndex].StrRef[order] = strres[LangIndex].StrRef[order - 1];
                        strres[LangIndex].StrID[order] = strres[LangIndex].StrID[order - 1];
                        order--;
                    }
                    strres[LangIndex].StrRef[position] = i;
                    strres[LangIndex].StrID[position] = STRID;
                    strres[LangIndex].TotalLength += wcslen(tok) + 1;
                    i++;
                    /* end of insert string into the list */
                }
                else
                {
                    /* there are duplicate hash value, check if the string is really the same with that has the same hash value */
                    int found = 0;

                    if (wcscmp(tok, strres[LangIndex].Str[ht[LangIndex][h].pointer]) == 0)
                    {
                        /* The two string is the same */
                        order = 0;
                        while (order < l)
                        {
                            if (STRID > strres[LangIndex].StrID[order])
                            {
                                order++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        position = order;
                        order = l;
                        while (order > position)
                        {
                            strres[LangIndex].StrRef[order] = strres[LangIndex].StrRef[order - 1];
                            strres[LangIndex].StrID[order] = strres[LangIndex].StrID[order - 1];
                            order--;
                        }
                        strres[LangIndex].StrRef[position] = ht[LangIndex][h].pointer;
                        strres[LangIndex].StrID[position] = STRID;
                        /* read in next line */
                        fgetws(tmp, buffer_size, f);
                        continue;
                    }
                    /*
                     * Although the two strings have the same hash value, but they are different
                     * Compare the strings in linked list...
                     */
                    temp = &ht[LangIndex][h];
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                        if (wcscmp(tok, strres[LangIndex].Str[temp->pointer]) == 0)
                        {
                            /* find a identical string in linked list, set the flag on */
                            found = 1;
                            order = 0;
                            while (order < l)
                            {
                                if (STRID > strres[LangIndex].StrID[order])
                                {
                                    order++;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            position = order;
                            order = l;
                            while (order > position)
                            {
                                strres[LangIndex].StrRef[order] = strres[LangIndex].StrRef[order - 1];
                                strres[LangIndex].StrID[order] = strres[LangIndex].StrID[order - 1];
                                order--;
                            }
                            strres[LangIndex].StrRef[position] = temp->pointer;
                            strres[LangIndex].StrID[position] = STRID;
                            break;
                        }
                    }
                    if (found == 0)
                    {
                        /*
                         * The input string is different with all other strings in hash table.
                         * Add the string in linked list.
                         */
                        extra = (struct HashItem*)malloc(sizeof(struct HashItem));
                        extra->next = NULL;
                        extra->pointer = i;
                        temp->next = extra;
                        strres[LangIndex].Str[i] = malloc(wcslen(tok) * 2 + 2);
                        wcscpy(strres[LangIndex].Str[i], tok);
                        order = 0;
                        while (order < l)
                        {
                            if (STRID > strres[LangIndex].StrID[order])
                            {
                                order++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        position = order;
                        order = l;
                        while (order > position)
                        {
                            strres[LangIndex].StrRef[order] = strres[LangIndex].StrRef[order - 1];
                            strres[LangIndex].StrID[order] = strres[LangIndex].StrID[order - 1];
                            order--;
                        }
                        strres[LangIndex].StrRef[position] = i;
                        strres[LangIndex].StrID[position] = STRID;
                        strres[LangIndex].TotalLength += wcslen(tok) + 1;
                        i++;
                    }
                    else
                    {
                        found = 0;  /* reset the flag */
                    }
                }
            }
            fgetws(tmp, buffer_size, f);
        }
        strres[LangIndex].MaxID = l + 1;
        strres[LangIndex].MaxNum = i;
    }
    result->iLang = mtk_gMaxDeployedLangs;
    result->strres = strres;
    free(tmp);
    return iMaxID;
}


/*****************************************************************************
 * FUNCTION
 *  main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  argc        [IN]        
 *  argv        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int main(int argc, char **argv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *f = NULL;
    FILE *fout_res = NULL;
    FILE *fout_map = NULL;
    int i = 0, iLang = 0, str_id = 0, MaxID = 0, str_res_id = 0;
    unsigned short z = 0;
    int *MaxNum = NULL;
    int *duplate = NULL;
    int start = 0, index_map = 0, index = 0, num_map_search = 0;
    int min_id = 0, max_id = 0;
    struct StrRes *strres = NULL;
    struct StrResSet Strresset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (argc == 1)
    {
        f = fopen("CustStrList.txt", "rb");
        if (f == NULL)
        {
            printf("File Open Error (CustStrList.txt) ...!\n");
            exit(1);
        }
    }
    else
    {
        f = fopen(argv[1], "rb");
        if (f == NULL)
        {
            printf("File Open Error (%s) ...!\n", argv[1]);
            exit(1);
        }
    }
    MaxID = GetStrResList(f, &Strresset);
    iLang = Strresset.iLang;
    /* if (iLang==1) return 0; */
    fout_res = fopen(STR_DATA_FILENAME, "wb");
    fout_map = fopen(STR_MAP_FILENAME, "wb");
    strres = Strresset.strres;
    /* print out file header */
    fprintf(fout_res, "#include \"CustDataRes.h\"\n\n\n");
    fprintf(fout_res, "#include \"FontDCl.h\"\n\n\n");
    fprintf(fout_map, "#include \"CustDataRes.h\"\n");

    for (i = 0; i < mtk_gMaxDeployedLangs; i++)
    {
        /* 010405 Calvin added */
        int old_i = i;

        if (mtk_gLanguageFlag[i] == 0)
        {
            printf("!!! Please provide translated strings of %s in ref_list.txt !!!\n", mtk_gLanguageArray[i].aLangSSC);
            i = 0;
        }
        /* Calvin end */

        unsigned long nTotalLen = 0;

        /* print out language structure header, including NULL string */
        fprintf(fout_res, "const CUSTOM_STRING DevApp_StrRes_%d[]={\n0x00,0x00,\n", old_i + 1); /* 010405 Calvin added */
        fprintf(fout_map, "const CUSTOM_STRING_MAP	DevApp_StrMap_%d[]={\n", old_i + 1);    /* 010405 Calvin added */

        /* print out CustStrRes.c */
        for (str_res_id = 0; str_res_id < strres[i].MaxNum; str_res_id++)
        {
            unsigned short nStringLen = 0;

        #ifndef __UCS2_ENCODING
            fprintf(fout_res, "\"%s\",\n", strres[i].Str[str_res_id]);
        #else /* __UCS2_ENCODING */ 
            nStringLen = wcslen(strres[i].Str[str_res_id]);
            for (z = 0; z < nStringLen * 2; ++z)
            {
                unsigned char *abc = (unsigned char*)strres[i].Str[str_res_id];

                fprintf(fout_res, "0x%X,", abc[z]);
            }
            fputs("0x00,0x00,\n", fout_res);
        #endif /* __UCS2_ENCODING */ 
        }
        /* print out CustStrMap.c */
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
            for (iterator = 0; iterator < strres[i].StrRef[str_res_id]; iterator++)
            {
                nStringLen = 0;
                nStringLen = wcslen(strres[i].Str[iterator]);
                wcString = NULL;
                nTotalLen += ((nStringLen + 1) * 2);
            }
            fprintf(fout_map, "\t%d,\n", nTotalLen / 2);
        }

        fprintf(fout_res, "};\n");
        fprintf(fout_map, "};\n");
        fprintf(fout_res, "extern const CUSTOM_STRING_MAP	DevApp_StrMap_%d[];\n", old_i + 1);     /* 010405 Calvin changed */

        i = old_i;
    }
    /* print out STRMAP_SEARCH array */
    fprintf(fout_res, "const CUSTOM_STRMAP_SEARCH	DevApp_StrMapSearch[]={\n");
    for (str_res_id = 0; str_res_id < MAX_STRING_MAP_SIZE; str_res_id++)
    {
        if (start == 1)
        {
            if (strres[0].StrID[index_map + 1] == strres[0].StrID[index_map] + 1)
            {
                max_id += 1;
                index_map += 1;
            }
            else
            {
                start = 0;
                fprintf(fout_res, "\t{%d,%d,%d},\n", min_id, max_id, index);
                index_map += 1;
                index = index_map;
            }
        }
        else if (start == 0)
        {
            if (str_res_id == strres[0].StrID[index_map])
            {
                start = 1;
                num_map_search += 1;
                min_id = str_res_id;
                max_id = str_res_id;
            }
        }
        else if (start == -1)
        {
            if (str_res_id == strres[0].StrID[index_map])
            {
                start = 1;
                num_map_search += 1;
                min_id = str_res_id;
                max_id = str_res_id;
            }
        }
    }
    fprintf(fout_res, "};\n");

    fprintf(
        fout_res,
        "const StringResList	DevApp_gStringList[]={\n");
    /* print out language list array */
    for (i = 0; i < mtk_gMaxDeployedLangs; i++)
    {
        /* 010405 Calvin added */
        int old_i = i;

        if (mtk_gLanguageFlag[i] == 0)
        {
            i = 0;
        }
        fprintf(fout_res, "{(CUSTOM_STRING*)DevApp_StrRes_%d,%d,(CUSTOM_STRING_MAP*)DevApp_StrMap_%d,%d,(CUSTOM_STRMAP_SEARCH *)DevApp_StrMapSearch,%d},\n", old_i + 1, strres[i].MaxNum + 1, old_i + 1, strres[i].MaxID + 1, num_map_search);  /* 010405 Calvin changed */

        i = old_i;
    }
    fprintf(fout_res, "};\n");

    fclose(f);
    fclose(fout_res);
    fclose(fout_map);
    return 0;
}

