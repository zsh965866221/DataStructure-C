#include <stdio.h>
#include <stdlib.h>

#include "AVLTree.h"

#define MAXSIZE 100

//begin of BTree_T
typedef struct TNode
{
    int date;
    TNode *lchild,*rchild;
}TNode,*BTree;
//end of BTree_T

//begin of Queue_T
typedef TNode *TypeName;
struct Queue
{
    TypeName data[MAXSIZE];
    int front,rear;
};
//end of Queue_T

//begin of Queue_H
void init_Queue(Queue &Q)
{
    Q.front=Q.rear=0;
}
void enQueue(Queue &Q,TypeName i)
{
    Q.data[Q.rear]=i;
    Q.rear=(Q.rear+1)%MAXSIZE;
}
TypeName deQueue(Queue &Q)
{
    int k=Q.front;
    Q.front=(Q.front+1)%MAXSIZE;
    return Q.data[k];
}
bool isFull_Queue(Queue &Q)
{
    if((Q.rear+1)%MAXSIZE)
    {
        return true;
    }else{
        return false;
    }
}
bool isEmpty_Queue(Queue &Q)
{
    if(Q.front==Q.rear)
        return true;
    else
        return false;
}
//end of Queue
//begin of BTree_H
void init_btree(BTree &T)
{
    T=NULL;
}
void insert_btree(BTree &T,int i)
{
    if(T==NULL)
    {
        T=(BTree)malloc(sizeof(TNode));
        T->lchild=NULL;
        T->rchild=NULL;
        T->date=i;
    }else{
        if(i>T->date)
            insert_btree(T->rchild,i);
        if(i<T->date)
            insert_btree(T->lchild,i);
    }

}
TNode* search_btree(BTree &T,int i)
{
    TNode *p=NULL;
    if(T==NULL)
        return NULL;
    else{
        int k=T->date;
        if(i>T->date)
            p=search_btree(T->rchild,i);
        if(i<T->date)
            p=search_btree(T->lchild,i);
        if(i==T->date)
            p=T;
    }
    return p;

}

bool same_btree(BTree &T1,BTree &T2)
{
    bool result=true;
    if(T1!=NULL&&T2!=NULL)
    {
        if(T1->date==T2->date)
        {
            result=same_btree(T1->lchild,T2->lchild);
            result=same_btree(T1->rchild,T2->rchild);
        }else
            return false;
    }else{
        if(T1==NULL&&T2==NULL);
        else{
            result=false;
        }
    }
    return result;
}
bool same_btree1(BTree T1,BTree T2)
{
    if(T1==NULL&&T2==NULL)
        return true;
    else {
        if(T1->date==T2->date)
            return true;
        else
            return false;
        bool a=same_btree1(T1->lchild,T2->lchild);
        bool b=same_btree1(T1->rchild,T2->rchild);
        return a&&b;
    }
}

int getDeep_btree(BTree &T)
{
    int deep=0;
    if(T!=NULL)
    {
        int a=getDeep_btree(T->lchild);
        int b=getDeep_btree(T->rchild);
        deep = a>b? a+1:b+1;
    }
    return deep;
}
int getDeep_btree1(BTree &T)
{
    if(T==NULL)
        return 0;
    else{
        int a=getDeep_btree1(T->lchild);
        int b=getDeep_btree1(T->rchild);
        return a>b? a+1:b+1;
    }
}
int getWith_btree1(BTree &T)
{
    Queue Q;
    init_Queue(Q);
    int n=1,max=1;
    enQueue(Q,T);
    while(!isEmpty_Queue(Q))
    {
        int tempMax=0;
        for(int i=0;i<n;i++)
        {
            BTree p=deQueue(Q);
            if(p->lchild!=NULL)
            {
                tempMax++;
                enQueue(Q,p->lchild);
            }
            if(p->rchild!=NULL)
            {
                tempMax++;
                enQueue(Q,p->rchild);
            }

        }
        if(tempMax>max)
            max=tempMax;
        n=tempMax;
    }
    return max;
}
//end of BTree_H
int main()
{
    BTree T1;
    BTree T2;
    init_btree(T1);
    init_btree(T2);
    //
    AVLTree AT;
    init_AVL(AT);
    int a1[7]={5,3,2,4,8,7,9};
    int a2[7]={2,3,4,5,1,9,8};
    for(int i=0;i<7;i++)
    {
        insert_btree(T1,a1[i]);
        insert_btree(T2,a2[i]);
        insert_AVL(AT,a1[i]);
    }
    bool r=same_btree1(T1,T2);
    if(r>0)
        printf("true\n");
    else
        printf("false\n");
    printf("%d\n",getWith_btree1(T2));
    printf("%d\n",search_AVL(AT,7)->data);
}
