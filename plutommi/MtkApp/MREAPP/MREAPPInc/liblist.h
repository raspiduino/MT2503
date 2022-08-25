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
*  Liblist.h
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
#ifndef _H_MRE_LIBLIST_INCLUDED_
#define _H_MRE_LIBLIST_INCLUDED_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Structure for referencing a node in a mre_list_t element. */
    typedef struct __mre_node_ __mre_node_t;

    /* Structure for referencing a node in a mre_list_t element.*/
    struct __mre_node_
    {
        void*				next;		/**< next __mre_node_t containing element */
        void*				element;	/**< element in Current node */
    };
    /* Structure for referencing a list of elements.*/
    typedef struct mre_list mre_list_t;

    typedef struct
    {
        __mre_node_t*		actual;
        __mre_node_t**		prev;
        mre_list_t*		list;
        int 				position;
    } mre_list_iterator_t;

    /* Structure for referencing a list of elements.*/
    struct mre_list
    {
        int 				nb_elt;    /* Number of element in the list   */
        __mre_node_t*		node;		/* Next node containing element  */
    };
    /*****************************************************************************
    * FUNCTION
    *     mre_single_list_new
    * DESCRIPTION
    *     Initialise a mre_list_t element.
    *     NOTE: this element will be allocated in mre_single_list_new,
    *     then you must free the *ll by mre_single_list_free/mre_single_list_special_free/
    *	mre_single_list_ofchar_free param list The element to initialise.
    * PARAMETERS
    *     void
    * RETURNS
    *    	
    *****************************************************************************/
    mre_list_t *mre_single_list_new(void);

    /*****************************************************************************
    * FUNCTION
    *     mre_single_list_free
    * DESCRIPTION
    *     free all  mre_list_t element.
    * PARAMETERS
    *     list which will work on
    * RETURNS
    *     void
    *****************************************************************************/
    void mre_single_list_free(mre_list_t *list);

    /*****************************************************************************
    * FUNCTION
    *     mre_single_list_special_free
    * DESCRIPTION
    *     Free a list of element.
    *     Each element will be free with the method given as the second parameter.
    *     param list The element to work on.
    *     param free_func The method that is able to release one element of the list.
    * PARAMETERS
    *     list which will work on
    * RETURNS
    *     void
    *****************************************************************************/
    void mre_single_list_special_free(mre_list_t *list, void *(*free_func) (void *));

    /*****************************************************************************
    * FUNCTION
    *	  mre_single_list_ofchar_free
    * DESCRIPTION
    * 	  Free a list of element where elements are pointer to 'char'.
    * 	  param list The element to work on.
    * PARAMETERS
    *	 
    * RETURNS
    *	 
    *****************************************************************************/
    void mre_single_list_ofchar_free(mre_list_t *list);

    /*****************************************************************************
    * FUNCTION
    *	  mre_single_list_ofchar_free
    * DESCRIPTION
    * 	  Get the size of a list of element.param list The element to work on.
    * PARAMETERS
    *	 
    * RETURNS
    *	 
    *****************************************************************************/
    int mre_single_list_get_size(const mre_list_t *list);

    /*****************************************************************************
    * FUNCTION
    *	  mre_single_list_is_end
    * DESCRIPTION
    * 	  Check if the end of list is detected .param list The element to work on.
    * PARAMETERS
    *	 
    * RETURNS
    *	 
    *****************************************************************************/
    int mre_single_list_is_end(const mre_list_t *list, int position);

    /*****************************************************************************
    * FUNCTION
    *	  mre_single_list_add
    * DESCRIPTION
    * 	  Add an element in a list.
    * 	  param list The element to work on.
    *	  param element The pointer on the element to add.
    *	  param position the index of the element to add. (or -1 to append the element at the end)
    * PARAMETERS
    *	 
    * RETURNS
    *	 
    *****************************************************************************/
    int mre_single_list_add(mre_list_t *list, void *element, int position);

    /*****************************************************************************
    * FUNCTION
    *	  mre_single_list_get_element
    * DESCRIPTION
    * 	  Get an element from a list.
    * 	  @param list The element to work on.
    * 	  @param position the index of the element to get.
    * PARAMETERS
    *	 
    * RETURNS
    *	 
    *****************************************************************************/
    void *mre_single_list_get_element(const mre_list_t *list, int position);

    /*****************************************************************************
    * FUNCTION
    *	  mre_single_list_remove
    * DESCRIPTION
    * 	  Remove an element from a list.
    * 	  @param list The element to work on.
    * 	  @param position the index of the element to remove.
    * PARAMETERS
    *	 
    * RETURNS
    *	 
    *****************************************************************************/
    int mre_single_list_remove(mre_list_t *list, int position);

    /*****************************************************************************
    * FUNCTION
    *	  sml_list_iterator_has_elem
    * DESCRIPTION
    *	  
    * PARAMETERS
    *	 
    * RETURNS
    *	 
    *****************************************************************************/
#define sml_list_iterator_has_elem( it ) ( 0 != (it).actual && (it).position < (it).list->nb_elt )

    /*****************************************************************************
    * FUNCTION
    *	  mre_single_list_get_first
    * DESCRIPTION
    *	  
    * PARAMETERS
    *	 
    * RETURNS
    *	 void*
    *****************************************************************************/	
    void *mre_single_list_get_first(mre_list_t *list, mre_list_iterator_t *it);

    /*****************************************************************************
    * FUNCTION
    *	  mre_single_list_get_next
    * DESCRIPTION
    *	  
    * PARAMETERS
    *	 
    * RETURNS
    *	 void*
    *****************************************************************************/
    void *mre_single_list_get_next(mre_list_iterator_t *it);

    /*****************************************************************************
    * FUNCTION
    *	  mre_single_list_iterator_remove
    * DESCRIPTION
    *	  
    * PARAMETERS
    *	 
    * RETURNS
    *	 
    *****************************************************************************/
    void *mre_single_list_iterator_remove(mre_list_iterator_t *it);


#ifdef __cplusplus
}
#endif 

#endif /* _H_MRE_LIBLIST_INCLUDED_ */ 

