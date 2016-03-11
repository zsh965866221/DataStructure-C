#ifndef _AVLTREE_H_
#define _AVLTREE_H_

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef struct AVLNode
{
    int data;
    AVLNode *lchild,*rchild;

    int height;
}AVLNode,*AVLTree;
void init_AVL(AVLTree &T)
{
    T=NULL;
}
int height_AVL(AVLTree &T)
{
    if(T==NULL)
    {
        return 0;
    }else{
        return T->height;
    }
}

int _max(int a,int b)
{
    return a>b? a:b;
}
void singleRotateWithRight_AVL(AVLTree &T)
{
    AVLNode *p=T->rchild;
    T->rchild=p->lchild;
    p->lchild=T;
    T=p;
    T->height=_max(height_AVL(T->lchild),height_AVL(T->rchild))+1;
    p->height=_max(height_AVL(p->lchild),height_AVL(p->rchild))+1;
}
void singleRotateWithLeft_AVL(AVLTree &T)
{
    AVLNode *p=T->lchild;
    T->lchild=p->rchild;
    p->rchild=T;
    T=p;
    T->height=_max(height_AVL(T->lchild),height_AVL(T->rchild))+1;
    p->height=_max(height_AVL(p->lchild),height_AVL(p->rchild))+1;
}
void doubleRotateWithRight_AVL(AVLTree &T)
{
    singleRotateWithLeft_AVL(T->rchild);
    singleRotateWithRight_AVL(T);
}
void doubleRotateWithLeft_AVL(AVLTree &T)
{
    singleRotateWithRight_AVL(T->lchild);
    singleRotateWithLeft_AVL(T);
}
void insert_AVL(AVLTree &T,int i)
{
    if(T==NULL)
    {
        T=(AVLTree)malloc(sizeof(AVLNode));
        T->data=i;
        T->height=0;
        T->lchild=NULL;
        T->rchild=NULL;
    }
    else{
        int temp=T->data;
        if(i==T->data)  return;
        else if(i>T->data)
        {
            insert_AVL(T->rchild,i);
            //debug
            int k=T->data;
            int a=height_AVL(T->rchild);
            int b=height_AVL(T->lchild);
            //
            if(height_AVL(T->rchild)-height_AVL(T->lchild)>=2)
            {
                if(i>T->rchild->data)
                    singleRotateWithRight_AVL(T);
                else
                    doubleRotateWithRight_AVL(T);
            }
        }else{
            insert_AVL(T->lchild,i);
            //debug
            int k=T->data;
            int a=height_AVL(T->rchild);
            int b=height_AVL(T->lchild);
            //
            if(height_AVL(T->lchild)-height_AVL(T->rchild)>=2)
            {
                if(i<T->lchild->data)
                    singleRotateWithLeft_AVL(T);
                else{
                    doubleRotateWithLeft_AVL(T);
                }
            }
        }
    }
    T->height=_max(height_AVL(T->lchild),height_AVL(T->rchild))+1;

}
AVLNode *search_AVL(AVLTree &T,int i)
{
    if(T==NULL)
        return NULL;
    else{
        if(i==T->data)
            return T;
        else if(i<T->data)
            search_AVL(T->lchild,i);
        else if(i>T->data)
            search_AVL(T->rchild,i);
    }
}

#endif // _AVLTREE_H_
