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
*  Liblist.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This is a very simple implementation of a linked list.
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
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

//#ifdef __MRE_AM__
#include "mmi_features.h"
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)

#include "AMSwitch.h"
#include "AMUtil.h"
#include "liblist.h"
#include <string.h>


/*****************************************************************************
* FUNCTION
*  mre_single_list_new
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
mre_list_t *mre_single_list_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mre_list_t *list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list = (mre_list_t*) mmi_am_malloc(sizeof(mre_list_t));
    if (NULL == list)
    {
        return 0;
    }

    memset(list, 0, sizeof(mre_list_t));
    return list;
}


/*****************************************************************************
* FUNCTION
*  mre_single_list_free
* DESCRIPTION
*  
* PARAMETERS
*  list      [IN]        
* RETURNS
*  void
*****************************************************************************/
void mre_single_list_free(mre_list_t *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int 	pos = 0;
    void*	element;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == list)
    {
        return;
    }

    while (!mre_single_list_is_end(list, pos))
    {
        element = (void*)mre_single_list_get_element(list, pos);
        mre_single_list_remove(list, pos);
    }
    mmi_am_free(list);
}


/*****************************************************************************
* FUNCTION
*  mre_single_list_special_free
* DESCRIPTION
*  
* PARAMETERS
*  list              [IN]        
*  free_func       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mre_single_list_special_free(mre_list_t *list, void *(*free_func) (void *))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int 	pos = 0;
    void*	element;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == list)
    {
        return;
    }

    while (!mre_single_list_is_end(list, pos))
    {
        element = (void*)mre_single_list_get_element(list, pos);
        mre_single_list_remove(list, pos);
        if (free_func != NULL)
        {
            free_func(element);
        }
    }
    mmi_am_free(list);
}


/*****************************************************************************
* FUNCTION
*  mre_single_list_ofchar_free
* DESCRIPTION
*  
* PARAMETERS
*  list      [IN]        
* RETURNS
*  void
*****************************************************************************/
void mre_single_list_ofchar_free(mre_list_t *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int 	pos = 0;
    char*	chain;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == list)
    {
        return;
    }

    while (!mre_single_list_is_end(list, pos))
    {
        chain = (char*)mre_single_list_get_element(list, pos);
        mre_single_list_remove(list, pos);
        mmi_am_free(chain);
    }
    mmi_am_free(list);
}


/*****************************************************************************
* FUNCTION
*  mre_single_list_get_size
* DESCRIPTION
*  
* PARAMETERS
*  list      [IN]        
* RETURNS
*  
*****************************************************************************/
int mre_single_list_get_size(const mre_list_t *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (NULL != list)
    {
        return list->nb_elt;
    }
    else
    {
        return -1;
    }
}


/*****************************************************************************
* FUNCTION
*  mre_single_list_is_end
* DESCRIPTION
*  
* PARAMETERS
*  list      [IN]        
*  i       [IN]        
* RETURNS
*  
*****************************************************************************/
int mre_single_list_is_end(const mre_list_t *list, int i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == list)
    {
        return -1;
    }	
    if (i < list->nb_elt)
    {
        return 0;    /* not end of list */
    }		
    return 1;        /* end of list */
}

/* index starts from 0; */


/*****************************************************************************
* FUNCTION
*  mre_single_list_add
* DESCRIPTION
*  
* PARAMETERS
*  list      [IN]        
*  el      [IN]        
*  pos     [IN]        
* RETURNS
*  
*****************************************************************************/
int mre_single_list_add(mre_list_t *list, void *el, int pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    __mre_node_t*		ntmp;
    int 				i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == list)
    {
        return -1;
    }

    if (0 == list->nb_elt)
    {
        list->node = (__mre_node_t*) mmi_am_malloc(sizeof(__mre_node_t));
        if (list->node == NULL)
        {
            return -1;
        }
        list->node->element = el;
        list->node->next = NULL;
        list->nb_elt++;
        return list->nb_elt;
    }

    if (-1 == pos || pos >= list->nb_elt)
    {   /* insert at the end  */
        pos = list->nb_elt;
    }

    ntmp = list->node;    /* exist because nb_elt>0  */

    if (0 == pos)   	   /* pos = 0 insert before first elt  */
    {
        list->node = (__mre_node_t*) mmi_am_malloc(sizeof(__mre_node_t));
        if (NULL == list->node)
        {
            /* leave the list unchanged */
            list->node = ntmp;
            return -1;
        }
        list->node->element = el;
        list->node->next = ntmp;
        list->nb_elt++;
        return list->nb_elt;
    }

    while (pos > i + 1)
    {
        i++;
        /* when pos>i next node exist  */
        ntmp = (__mre_node_t*) ntmp->next;
    }

    /* if pos==nb_elt next node does not exist  */
    if (pos == list->nb_elt)
    {
        ntmp->next = (__mre_node_t*) mmi_am_malloc(sizeof(__mre_node_t));
        if (NULL == ntmp->next)
        {
            return -1;  /* leave the list unchanged */
        }
        ntmp = (__mre_node_t*) ntmp->next;
        ntmp->element = el;
        ntmp->next = NULL;
        list->nb_elt++;
        return list->nb_elt;
    }

    /* here pos==i so next node is where we want to insert new node */
    {
        __mre_node_t *nextnode = (__mre_node_t*) ntmp->next;

        ntmp->next = (__mre_node_t*) mmi_am_malloc(sizeof(__mre_node_t));
        if (NULL == ntmp->next)
        {
            /* leave the list unchanged */
            ntmp->next = nextnode;
            return -1;
        }
        ntmp = (__mre_node_t*) ntmp->next;
        ntmp->element = el;
        ntmp->next = nextnode;
        list->nb_elt++;
    }
    return list->nb_elt;
}

/* index starts from 0 */


/*****************************************************************************
* FUNCTION
*  mre_single_list_get_element
* DESCRIPTION
*  
* PARAMETERS
*  list      [IN]        
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
void *mre_single_list_get_element(const mre_list_t *list, int pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    __mre_node_t*	ntmp;
    int 			i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == list)
    {
        return NULL;
    }

    if (pos < 0 || pos >= list->nb_elt)
    {
        return NULL; /* element does not exist */
    }

    ntmp = list->node;    /* exist because nb_elt>0 */

    while (pos > i)
    {
        i++;
        ntmp = (__mre_node_t*) ntmp->next;
    }
    return ntmp->element;
}

/* added by bennewit@cs.tu-berlin.de */


/*****************************************************************************
* FUNCTION
*  mre_single_list_get_first
* DESCRIPTION
*  
* PARAMETERS
*  list              [IN]        
*  iterator        [IN]        
* RETURNS
*  void
*****************************************************************************/
void *mre_single_list_get_first(mre_list_t *list, mre_list_iterator_t *iterator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 >= list->nb_elt)
    {
        iterator->actual = 0;
        return 0;
    }

    iterator->actual 	= list->node;
    iterator->prev 		= &list->node;
    iterator->list 		= list;
    iterator->position 		= 0;

    return list->node->element;
}

/* added by bennewit@cs.tu-berlin.de */


/*****************************************************************************
* FUNCTION
*  mre_single_list_get_next
* DESCRIPTION
*  
* PARAMETERS
*  iterator        [IN]        
* RETURNS
*  void 
*****************************************************************************/
void *mre_single_list_get_next(mre_list_iterator_t *iterator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iterator->prev 		= (__mre_node_t **) & (iterator->actual->next);
    iterator->actual 		= iterator->actual->next;
    ++(iterator->position);

    if (sml_list_iterator_has_elem(*iterator))
    {
        return iterator->actual->element;
    }

    iterator->actual = 0;

    return 0;
}

/* added by bennewit@cs.tu-berlin.de */


/*****************************************************************************
* FUNCTION
*  mre_single_list_iterator_remove
* DESCRIPTION
*  
* PARAMETERS
*  iterator        [IN]        
* RETURNS
*  void
*****************************************************************************/
void *mre_single_list_iterator_remove(mre_list_iterator_t *iterator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sml_list_iterator_has_elem(*iterator))
    {
        --(iterator->list->nb_elt);

        *(iterator->prev) = iterator->actual->next;

        mmi_am_free(iterator->actual);

        iterator->actual = *(iterator->prev);
    }

    if (sml_list_iterator_has_elem(*iterator))
    {
        return iterator->actual->element;
    }

    return 0;
}

/* return -1 if failed */


/*****************************************************************************
* FUNCTION
*  mre_single_list_remove
* DESCRIPTION
*  
* PARAMETERS
*  list      [IN]        
*  pos     [IN]        
* RETURNS
*  
*****************************************************************************/
int mre_single_list_remove(mre_list_t *list, int position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    __mre_node_t*	ntmp;
    int 			i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == list)
    {
        return -1;
    }	
    /* element does not exist */
    if (position < 0 || position >= list->nb_elt)
    {
        return -1;
    }

    ntmp = list->node;    /* exist because nb_elt>0 */

    /* special case  */
    if ((0 == position ))
    {   
        list->node = (__mre_node_t*) ntmp->next;
        list->nb_elt--;
        mmi_am_free(ntmp);
        return list->nb_elt;
    }

    while (position > i + 1)
    {
        i++;
        ntmp = (__mre_node_t*) ntmp->next;
    }

    /* insert new node */
    {
        __mre_node_t*	rem_node;

        rem_node 		= (__mre_node_t*) ntmp->next;
        ntmp->next  	= ((__mre_node_t*) ntmp->next)->next;

        mmi_am_free(rem_node);

        list->nb_elt--;
    }
    return list->nb_elt;
}

#endif /* __MRE_AM__ */ 

