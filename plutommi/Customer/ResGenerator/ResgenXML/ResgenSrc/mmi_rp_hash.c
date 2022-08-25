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
 *  mmi_rp_hash.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  XML resgen parser hash usage for strings
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMIDataType.h"
#include "mmi_rp_hash.h"
#include "mmi_rp_xml.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_hash_raw_hash
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [?]         
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
__inline U32 mmi_rp_hash_raw_hash(U8 *s, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i++)
    {
        i = 31 * i + *s;
        s++;
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_hash_raw_cmp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s1          [?]         
 *  s1_len      [IN]        
 *  s2          [?]         
 *  s2_len      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
__inline S32 mmi_rp_hash_raw_cmp(U8 *s1, U32 s1_len, U8 *s2, U32 s2_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, cmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmp = s1_len - s2_len;
    if (cmp)
    {
        return cmp;
    }

    i = s1_len;
    while (i--)
    {
        cmp = *s1 - *s2;
        if (cmp)
        {
            return cmp;
        }
        s1++, s2++;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_hash_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  table_size      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_rp_hash_struct *mmi_rp_hash_create(U32 table_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_hash_struct *hash = (mmi_rp_hash_struct*) malloc(sizeof(mmi_rp_hash_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hash)
    {
        /* Memory not available */
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE); 
    }

    hash->table_size = table_size;
    hash->table = (mmi_rp_hash_node_struct **) malloc(sizeof(mmi_rp_hash_node_struct*) * table_size);
    if (!hash->table)
    {
        /* Memory not available */
        MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE); 
    }

    memset(hash->table, 0, sizeof(mmi_rp_hash_node_struct*) * table_size);

    return hash;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_hash_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rp_hash_free(mmi_rp_hash_struct *hash)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < hash->table_size; i++)
        if (hash->table[i])
        {
            mmi_rp_hash_node_struct *node, *next;

            next = hash->table[i];
            do
            {
                node = next;
                next = node->next;

                if (node->key)
                {
                    free(node->key);
                }
                free(node);
            } while (next);
        }
    free(hash->table);
    free(hash);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_hash_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash        [?]         
 *  key         [?]         
 *  data        [?]         
 *  ret_key     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void *mmi_rp_hash_add(mmi_rp_hash_struct *hash, U8 *key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len = strlen(key) + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_rp_hash_add_raw(hash, key, len);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_hash_add_raw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash            [?]         
 *  key             [?]         
 *  key_len         [IN]        
 *  data            [?]         
 *  ret_key         [IN]        
 *  ret_key_len     [?]         
 * RETURNS
 *  
 *****************************************************************************/
void *mmi_rp_hash_add_raw(mmi_rp_hash_struct *hash, U8 *key, U32 key_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rp_hash_node_struct *node, *parent;
    U32 index = mmi_rp_hash_raw_hash(key, key_len) % hash->table_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent = NULL;
    if (hash->table[index])
    {
        node = hash->table[index];
        while (node)
        {
            S32 cmp;

            cmp = mmi_rp_hash_raw_cmp(node->key, node->key_len, key, key_len);
            if (cmp < 0)
            {
                parent = node;
                node = node->next;
            }
            else if (cmp == 0)
            {
                /* String found in hash. Just return the pointer */
                MMI_RP_PARSE_WARNING(RP_WARN_HASH_SAME_STRING);
                return node->key;
            }
            else
            {
                break;
            }
        }
    }

    /* insert new node */
    {
        mmi_rp_hash_node_struct *new_node = (mmi_rp_hash_node_struct*) malloc(sizeof(mmi_rp_hash_node_struct));

        if (!new_node)
        {
            /* Memory not available */
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE); 
        }

        new_node->key = malloc(key_len);
        if (!new_node->key)
        {
            /* Memory not available */
            MMI_RP_FATAL_ERROR(RP_ERR_MEMORY_NOT_AVAILABLE); 
        }

        memcpy(new_node->key, key, key_len);
        new_node->key_len = key_len;

        /* insert to current position */
        if (parent == NULL)
        {
            new_node->next = hash->table[index];
            hash->table[index] = new_node;
        }
        else
        {
            new_node->next = parent->next;
            parent->next = new_node;
        }

        /* return key */
        return new_node->key;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_hash_find
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash        [?]         
 *  key         [?]         
 *  ret_key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_rp_hash_find(mmi_rp_hash_struct *hash, U8 *key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len = strlen(key) + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_rp_hash_find_raw(hash, key, len);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rp_hash_find_raw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash            [?]         
 *  key             [?]         
 *  key_len         [IN]        
 *  ret_key         [IN]        
 *  ret_key_len     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_rp_hash_find_raw(mmi_rp_hash_struct *hash, U8 *key, U32 key_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = mmi_rp_hash_raw_hash(key, key_len) % hash->table_size;
    mmi_rp_hash_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hash->table[index])
    {
        node = hash->table[index];
        while (node)
        {
            S32 cmp;

            cmp = mmi_rp_hash_raw_cmp(node->key, node->key_len, key, key_len);
            if (cmp < 0)
            {
                node = node->next;
            }
            else if (cmp == 0)
            {
                return node->key;
            }
            else
            {
                break;
            }
        }
    }
    return NULL;
}

