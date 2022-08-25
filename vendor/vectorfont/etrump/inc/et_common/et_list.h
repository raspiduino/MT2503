///////////////////////////////////////////////////////////////////////
/// \file       et_list.h
/// \brief      bi-direction list
/// \details    thread unsafe
/// <br><br>
/// Chang Log: <br>
///   0.1       Zheng Xu     Initialize <br>
///
/// \author     Zheng Xu<zxu@etrump.net>
/// \version    0.1
/// \date       December 2010
///
///////////////////////////////////////////////////////////////////////
#ifndef __ET_LIST_H__
#define __ET_LIST_H__

#include "et_types.h"

/// list node
/// usually it should be inherited by other structures with more data fields included
typedef struct ET_Node_Str
{
    struct ET_Node_Str  *pPrev; ///< previous node
    struct ET_Node_Str  *pNext; ///< next node
}ET_Node;

/// list
typedef struct
{
    ET_Node* pHead; /// list head
    ET_Node* pTail; /// list tail
}ET_List;

////////////////////////////////////////////////////////////////////////
/// \brief create a list
/// \details 
/// \param[out] ppList
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_List_Create(ET_List** OUT ppList);

////////////////////////////////////////////////////////////////////////
/// \brief destroy a list
/// \details the input list should be empty
/// \param[in] pList
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_List_Destroy(ET_List* IN pList);

////////////////////////////////////////////////////////////////////////
/// \brief insert a node to list
/// \details the new node will be insert after reference node <br>
/// the new node will be add to the head of the list if reference node is NULL
/// \param[in] pList
/// \param[in] pRefNode
/// \param[in] pNewNode
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_List_Insert_After(ET_List* IN pList,
                                     ET_Node* IN pRefNode,
                                     ET_Node* IN pNewNode);

////////////////////////////////////////////////////////////////////////
/// \brief remove a node from list
/// \details 
/// \param[in] pList
/// \param[in] pNode
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_List_Remove(ET_List* IN pList,
                               ET_Node* IN pNode);

#endif
