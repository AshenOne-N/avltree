/************************************************************************!
* \file .c
* \brief
*
*
*
* \author Vincent, vicentcj@163.com
* \version V
* \date /2014
*
*
*************************************************************************/
#include "avltree.h"
static S16 height(position p)
{
    if(NULL == p)
        return -1;
    else
        return p->height;
}
extern avltree make_empty(avltree t)
{
        if(NULL != t) {
                if(NULL != t->LEFT)
                        make_empty(t->LEFT);
                if (NULL != t->RIGHT)
                        make_empty(t->RIGHT);
                free(t);
        }
        return NULL;
}
extern position find_node(element_type x, avltree t)
{
if(NULL != t)
{
    if(x < t->value)
        return find_node(x, t->LEFT);
    else if(x > t->value)
        return find_node(x, t->RIGHT);
    else
        return t;
}
else
    return NULL;
}
extern position find_min(avltree t)
{
        if(NULL != t) {
                if(NULL != t->LEFT)
                        return find_min(t->LEFT);
                else
                        return t;
        } else
                return NULL;
}
extern position find_max(avltree t)
{
        if(NULL != t) {
                while(NULL != t->RIGHT)
                        t = t->RIGHT;
        }
        return t;
}
extern avltree insert_node(element_type x, avltree t)
{
    if(NULL == t)
    {
        t = (avltree)malloc(sizeof(AVLNODE));
        if(NULL == t)
            printf("failed to create node!!\n");
        else
            {
            t->value = x;
            t->height = 0;
            t->LEFT = NULL;
            t->RIGHT = NULL;
            }
    }
    else if(x < t->value)
    {
         t->LEFT = insert_node(x,t->LEFT);
         if(height(t->LEFT) - height(t->RIGHT) == 2)
            if(x < t->LEFT->value)
            t = single_rotate_left(t);
            else
                t = double_rotate_left(t);
    }
    else if(x > t->value)
    {
        t->RIGHT = insert_node(x,t->RIGHT);
        if(height(t->RIGHT) - height(t->LEFT) == 2)
            if( x > t->RIGHT->value)
            t = single_rotate_right(t);
        else
            t = double_rotate_right(t);
    }
    t->height = Max(height(t->LEFT),height(t->RIGHT) +1)
}
extern avltree delete_node(element_type x, avltree t);
