//============================================================================
// Name        : test.cpp
// Author      : zsh_o
// Version     :
// Copyright   : --zsh_o
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>

enum Color
{
    RED,BLACK
};

typedef struct RBTNode
{
    RBTNode *parent,*lchild,*rchild;
    int data;
    Color color;
}RBTNode,*RBTree;
void init_RBTree(RBTree &T)
{
    T=NULL;
}
void leftRotate_RBTree(RBTree &T)
{
	RBTNode *p=T->rchild;
	if(T->parent!=NULL){
		if(T==T->parent->lchild){
			T->parent->lchild=p;
		}else{
			T->parent->rchild=p;
		}
	}
    p->parent=T->parent;
    if(p->lchild!=NULL)
        p->lchild->parent=T;
    T->rchild=p->lchild;
    T->parent=p;
    p->lchild=T;

    T=p;
}
void rightRotate_RBTree(RBTree &T)
{
    RBTNode *p=T->lchild;
    if(T->parent!=NULL){
    	if(T==T->parent->lchild){
    		T->parent->lchild=p;
    	}else{
    		T->parent->rchild=p;
    	}
    }
    p->parent=T->parent;
    if(p->rchild!=NULL)
    	p->rchild->parent=T;
    T->lchild=p->rchild;
    T->parent=p;
    p->rchild=T;

    T=p;
}

RBTNode *getParent_RBTree(RBTree &T)
{
    return T->parent;
}
RBTNode *getGrandParent_RBTree(RBTree &T)
{
    return T->parent->parent;
}
RBTNode *getUncle_RBTree(RBTree &T)
{
    if(getParent_RBTree(T)==getGrandParent_RBTree(T)->lchild)
        return getGrandParent_RBTree(T)->rchild;
    else
        return getGrandParent_RBTree(T)->lchild;
}
void llFixUp_RBTree(RBTree &T)
{
    getParent_RBTree(T)->color=BLACK;
    getGrandParent_RBTree(T)->color=RED;
    T=getGrandParent_RBTree(T);
    rightRotate_RBTree(T);
}
void lrFixUp_RBTree(RBTree &T)
{
    T=T->parent;
    leftRotate_RBTree(T);
    T=T->lchild;
    llFixUp_RBTree(T);

}
void rrFixUp_RBTree(RBTree &T)
{
    getParent_RBTree(T)->color=BLACK;
    getGrandParent_RBTree(T)->color=RED;
    T=getGrandParent_RBTree(T);
    leftRotate_RBTree(T);
}
void rlFixUp_RBTree(RBTree &T)
{
    T=T->parent;
    rightRotate_RBTree(T);
    T=T->rchild;
    rrFixUp_RBTree(T);
}
void insertFixUp_RBTree(RBTree &root,RBTree &T)
{
    if(T->parent==NULL){
    	T->color=BLACK;
    	root=T;
    }
    else{
        if(T->color==RED&&T->parent->color==RED)
        {
            if(getUncle_RBTree(T)!=NULL&&getUncle_RBTree(T)->color==RED)
            {
                getParent_RBTree(T)->color=BLACK;
                getUncle_RBTree(T)->color=BLACK;
                T=getGrandParent_RBTree(T);
                if(T->parent!=NULL)//ȷ�����ڵ�Ϊ��ɫ
                    T->color=RED;
                else
                    T->color=BLACK;
            }else{
                if(getParent_RBTree(T)==getGrandParent_RBTree(T)->lchild)
                {
                    if(T==getParent_RBTree(T)->lchild)//ll
                    {
                        llFixUp_RBTree(T);
                    }else{//lr
                        lrFixUp_RBTree(T);
                    }
                }else{
                    if(T==getParent_RBTree(T)->rchild)
                        rrFixUp_RBTree(T);
                    else
                        rlFixUp_RBTree(T);
                }
            }
            if(T->parent==NULL){
            	root=T;
            }
            insertFixUp_RBTree(root,T);
        }
    }
}
RBTNode* _insert_RBTree(RBTree &T,int i,RBTree &K)//���ز���Ľڵ�-->Ȼ����ݴ˽ڵ���������
{
	RBTNode *temp;//���ڱ������Ľڵ�������
    if(T==NULL)
    {
        T=(RBTree)malloc(sizeof(RBTNode));
        T->color=RED;
        T->lchild=NULL;
        T->rchild=NULL;
        T->parent=NULL;
        T->data=i;
        temp=T;
    }else{
        if(i<T->data)
        {
        	RBTNode *p;
        	temp=_insert_RBTree(T->lchild,i,p);
        	p->parent=T;
        }else if(i>T->data){
        	RBTNode *p;
        	temp=_insert_RBTree(T->rchild,i,p);
        	p->parent=T;
        }
    }
    K=T;
    return temp;
}
void insert_RBTree(RBTree &T,int i){
	RBTNode *K;
	RBTNode *p=_insert_RBTree(T,i,K);
	insertFixUp_RBTree(T,p);//ȷ��TΪ���ڵ�
}

void preOrderTravel_RBTree(RBTree &T)
{
    if(T!=NULL)
    {
    	printf("%d\n",T->data);
        preOrderTravel_RBTree(T->lchild);
        preOrderTravel_RBTree(T->rchild);
    }
}

RBTNode* getLeftest_RBTree(RBTree &T){
	RBTNode *p=T;
	while(p->lchild!=NULL){
		p=p->lchild;
	}
	return p;
}
RBTNode* getRightest_RBTree(RBTree &T){
	RBTNode *p=T;
	while(p->rchild!=NULL)
		p=p->rchild;
	return p;
}
int main()
{
    RBTree T;
    init_RBTree(T);

    int a[20]={12,1,9,2,0,11,7,19,4,15,18,5,14,13,10,16,6,3,8,17};
    for(int i=0;i<20;i++)
        insert_RBTree(T,a[i]);
    preOrderTravel_RBTree(T);
    printf("pause\n");
    int i=getLeftest_RBTree(T)->data;
    printf("%d",i);
}

//2016-3-3:���󣺷��������ڲ�������е����ڵ㣺AVL�����ڲ�������е����ڵ�����Ϊ�ڵݹ���û�и��Ľڵ�ĸ��ڵ㣬������������˸��ڵ㣬β�ݹ��иı��˸��ڵ㵱���ص����ڵ�ʱ���ص���֮ǰ�ĸ��ڵ�������¸ĳɵĸ��ڵ㣬���Է�������
