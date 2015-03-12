#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

/************************************************************************!
* \file .h
* \brief
*
*
*
* \author Vincent, vicentcj@163.com
* \version V
* \date /2014
*************************************************************************/
#include "stdafx.h"
#include "typedefine.h"
#include "malloc.h"
typedef U16 element_type;
typedef struct avl_node
{
    S16 height;
    element_type value;
    avl_node *LEFT;
    avl_node *RIGHT;

}AVLNODE,*PTR_TO_NODE;
typedef PTR_TO_NODE position;
typedef PTR_TO_NODE avltree;
extern avltree make_empty(avltree t);
extern position find_node(element_type x, avltree t);
extern position find_min(avltree t);
extern position find_max(avltree t);
extern avltree insert_node(element_type x, avltree t);
extern avltree delete_node(element_type x, avltree t);

#endif // AVLTREE_H_INCLUDED
