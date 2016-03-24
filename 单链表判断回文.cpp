#include <stdio.h>
#include <stdlib.h>

typedef struct SLNode
{
    SLNode *next;
    int k;
}SLNode,*SList;
void init_SList(SList &L)
{
    L=NULL;
}
int length_SList(SList &L)
{
    SLNode *p=L;
    int i;
    for(i=0;p!=NULL;p=p->next,i++);
    return i;
}
void print_SList(SList &L)
{
    SLNode *p=L;
    while(p!=NULL)
    {
        printf("%d,",p->k);
        p=p->next;
    }
    printf("\n");
}
void insert_SList(SList &L,int k)
{
    SLNode *t=L;
    L=(SLNode*)malloc(sizeof(SLNode));
    L->next=t;
    L->k=k;
}
int getElem_SList(SList &L,int n)
{
    int i;
    SLNode *p=L;
    for(i=1;i<n&&p!=NULL;p=p->next,i++);
    if(i<n||p==NULL) return -1;
    return p->k;
}
bool huiwen_SList(SList &L)
{
    int n=length_SList(L);
    for(int i=1;i<=n/2;i++)
    {
        if(getElem_SList(L,i)!=getElem_SList(L,n-i+1))
            return false;
    }
    return true;
}
int main()
{
    SList L;
    init_SList(L);
    int A[]={1,2,3,1,1};
    for(int i=0;i<sizeof(A)/sizeof(A[0]);i++)
        insert_SList(L,A[i]);
    print_SList(L);

    printf("%d\n",huiwen_SList(L));
}
