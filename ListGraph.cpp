//
// Created by Administrator on 2016/3/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100

typedef int EdgeType;
typedef char VertexType;

struct EdgeNode{
    int vertex;
    EdgeType weight;
    EdgeNode *next;
};
struct VertexNode{
    VertexType data;
    EdgeNode *first;
};
struct ListGraph{
    VertexNode vertexList[MAXSIZE];
    int size;
};
void init_ListGraph(ListGraph &G){
    G.size=0;
}
void insertVertex_ListGraph(ListGraph &G,VertexType e){
    VertexNode *p=(VertexNode*)malloc(sizeof(VertexNode));
    p->first=NULL;
    p->data=e;
    G.vertexList[G.size++]=*p;
}
void insertEdge_ListGraph(ListGraph &G,int a,int b,EdgeType weight){
    EdgeNode *p=G.vertexList[a].first;
    if(p==NULL){//由于没有头结点，要考虑为空的时候
        p=(EdgeNode*)malloc(sizeof(EdgeNode));
        p->next=NULL;
        p->vertex=b;
        p->weight=weight;
        G.vertexList[a].first=p;
    }else{
        bool exist=false;
        while(p->next!=NULL){
            if(p->vertex==b){//存在a->b的边，更新边//因为要检测存在存在的边所以进行O(n)链表尾插入而不是O(1)的链表头插入
                p->weight=weight;
                exist=true;
            }
            p=p->next;
        }
        if(p->vertex==b){
            p->weight=weight;
            exist=true;
        }
        if(!exist){
            EdgeNode *temp=(EdgeNode*)malloc(sizeof(EdgeNode));
            temp->next=NULL;
            temp->vertex=b;
            temp->weight=weight;
            p->next=temp;
        }
    }
}
int locate_ListGraph(ListGraph &G,VertexType e){
    for(int i=0;i<G.size;i++){
        if(G.vertexList[i].data==e)
            return i;
    }
    return -1;
}

void print_ListGraph(ListGraph &G){
    for(int i=0;i<G.size;i++){
        EdgeNode *p=G.vertexList[i].first;
        printf("%d-%c:",i,G.vertexList[i].data);
        while(p){
            printf("%c(%d)-",G.vertexList[p->vertex].data,p->weight);
            p=p->next;
        }
        printf("\n");
    }
}

int randInt(int a,int b){
    return rand()%(b-a+1)+a;
}
int main(){
    ListGraph G;
    init_ListGraph(G);
    int lv[]={'a','b','c','d','e'};
    for(int i=0;i<sizeof(lv)/sizeof(lv[0]);i++)
        insertVertex_ListGraph(G,lv[i]);
    srand(time(NULL));
    for(int i=0;i<20;i++){//插入20条边
        insertEdge_ListGraph(G,randInt(0,4),randInt(0,4),randInt(1,9));
    }
    print_ListGraph(G);
    printf("pause");
}