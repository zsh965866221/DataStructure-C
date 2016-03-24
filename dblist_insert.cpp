#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *pre,*next;
    int k;
};
typedef node *dblist_root;

void insert_dblist(dblist_root &root,int position,int k)
{
    node *t=(node*)malloc(sizeof(node));
    node *p=t;
    t->next=root;
    if(root!=NULL){
        root->pre=t;
    }
    if(position<1)return;
    for(int i=1;i<position;i++)
    {
        if(p->next==NULL)//链表长度不够position
        {
            return;
        }else{
            p=p->next;
        }
    }
    node *kp=(node*)malloc(sizeof(node));
    kp->k=k;
    kp->pre=NULL;
    kp->next=NULL;
    if(p->next!=NULL)
    {
        p->next->pre=kp;
        kp->pre=p;
        kp->next=p->next;
        p->next=kp;
    }else{
        p->next=kp;
        kp->pre=p;
    }
    root=t->next;
    free(t);
}
void _print(dblist_root &root)
{
    printf("\n");
    node *p=root;
    while(p!=NULL)
    {
        printf("%d,",p->k);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    int A[]={1,2,3,4,5,};
    dblist_root root;
    root=NULL;
    for(int i=0;i<5;i++)
    {
        insert_dblist(root,i+1,A[i]);
        _print(root);
    }
    insert_dblist(root,3,10);
    _print(root);
    insert_dblist(root,-1,10);
    _print(root);
    insert_dblist(root,7,10);
    _print(root);
    insert_dblist(root,9,19);
    _print(root);
}
