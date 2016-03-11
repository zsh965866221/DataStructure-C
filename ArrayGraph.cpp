#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100

typedef char VertexType;
typedef int EdgeType;

struct ArrayGraph{
    VertexType vertexes[MAXSIZE];
    EdgeType edges[MAXSIZE][MAXSIZE];
    int numVertex,numEdge;
    bool visted[MAXSIZE];
};
void init_ArrayGraph(ArrayGraph &G){
    G.numVertex=0;
    G.numEdge=0;
}
void insertVertex_ArrayGraph(ArrayGraph &G,VertexType e){
    bool exit=false;//防止插入统一元素
    for(int i=0;i<G.numVertex;i++){
        if(G.vertexes[i]==e){
            exit=true;
            break;
        }
    }
    if(!exit)
        G.vertexes[G.numVertex++]=e;
}
void insertEdge_ArrayGraph(ArrayGraph &G,int vertexA,int vertexB,int weight){
    G.edges[vertexA][vertexB]=weight;
    G.numEdge++;
}
int locate_ArrayGraph(ArrayGraph &G,VertexType e){
    for(int i=0;i<G.numVertex;i++){
        if(G.vertexes[i]==e)
            return i;
    }
    return -1;
}

int outDegree_ArrayGraph(ArrayGraph &G,int n){
    int sum=0;
    for(int i=0;i<G.numVertex;i++){
        if(G.edges[n][i]>0)
            sum++;
    }
    return sum;
}
int inDegree_ArrayGraph(ArrayGraph &G,int n){
    int sum=0;
    for(int i=0;i<G.numVertex;i++){
        if(G.edges[i][n]>0)
            sum++;
    }
    return sum;
}

void _clearVisted(ArrayGraph &G){
    for(int i=0;i<MAXSIZE;i++)
        G.visted[i]=false;
}
void _dfs(ArrayGraph &G,int n){
    G.visted[n]=true;
    printf("%c",G.vertexes[n]);
    for(int i=0;i<G.numVertex;i++){
        if(!G.visted[i]&&G.edges[n][i]>0)
            _dfs(G,i);
    }
}
void dfsTraverse_ArrayGraph(ArrayGraph &G){
    _clearVisted(G);
    for(int i=0;i<G.numVertex;i++){
        if(!G.visted[i])
            _dfs(G,i);
    }
    printf("\n");
}

//BFS需要用到队列----队列定义
typedef int QType;
#define QMAXSIZE 100
struct Queue{
    QType data[QMAXSIZE];
    int rear,front;
};
void init_Queue(Queue &Q){
    Q.rear=Q.front=0;
}
bool empty_Queue(Queue &Q){
    return Q.rear==Q.front;
}
bool full_Queue(Queue &Q){
    return (Q.rear+1)%QMAXSIZE==Q.front;
}
void enQueue(Queue &Q,QType e){
    Q.data[Q.rear]=e;
    Q.rear=(Q.rear+1)%QMAXSIZE;
}
QType deQueue(Queue &Q){
    QType temp=Q.data[Q.front];
    Q.front=(Q.front+1)%QMAXSIZE;
    return temp;
}
//
typedef void (*_pFun)(ArrayGraph &G,int a,int b);
void bfsTraverse_ArrayGraph(ArrayGraph &G,_pFun fun=NULL){
    _clearVisted(G);
    Queue Q;
    init_Queue(Q);
    for(int i=0;i<G.numVertex;i++){
        if(!G.visted[i]){
            enQueue(Q,i);
            G.visted[i]=true;
            while(!empty_Queue(Q)){
                int k=deQueue(Q);
                //do something
                if(fun!=NULL){
                    printf("%c",G.vertexes[k]);
                }else{
                    fun(G,i,k);
                }
                //
                for(int j=0;j<G.numVertex;j++){
                    if(!G.visted[j]&&G.edges[k][j]>0) {
                        enQueue(Q, j);
                        G.visted[j] = true;
                    }
                }
            }
        }
    }
    printf("\n");
}
//

void singleSourceShortestPath_ArrayGraph(ArrayGraph &G,int n,int pathList[]){//从单源n到其他节点的最短路径
    for(int i=0;i<G.numVertex;i++){
        pathList[i]=-1;
    }
    _clearVisted(G);
    Queue Q;
    init_Queue(Q);
    enQueue(Q,n);
    G.visted[n]=true;
    pathList[n]=0;
    while(!empty_Queue(Q)){
        int k=deQueue(Q);
        for(int i=0;i<G.numVertex;i++){
            if(!G.visted[i]&&G.edges[k,i]>0){
                enQueue(Q,i);
                G.visted[i]=true;
                pathList[i]=pathList[k]+G.edges[k][i];
            }
        }
    }

}
void print_ArrayGraph(ArrayGraph &G){
    for(int i=0;i<G.numVertex;i++) {
        for (int j = 0; j < G.numVertex;j++)
            printf("%d", G.edges[i][j]);
        printf("\n");
    }
}

int randInt(int a,int b){
    return rand()%(b-a+1)+a;
}
int main(){
    ArrayGraph G;
    init_ArrayGraph(G);
    int lv[]={'a','b','c','d','e'};
    for(int i=0;i<sizeof(lv)/sizeof(lv[0]);i++)
        insertVertex_ArrayGraph(G,lv[i]);
    srand(time(NULL));
//    for(int i=0;i<6;i++){//插入20条边
//        insertEdge_ArrayGraph(G,randInt(0,4),randInt(0,4),randInt(1,9));
//    }
    insertEdge_ArrayGraph(G,0,1,5);
    insertEdge_ArrayGraph(G,0,3,5);
    insertEdge_ArrayGraph(G,0,4,5);
    insertEdge_ArrayGraph(G,1,3,5);
    insertEdge_ArrayGraph(G,1,2,5);
    insertEdge_ArrayGraph(G,2,3,5);
    insertEdge_ArrayGraph(G,3,4,5);
    print_ArrayGraph(G);
    dfsTraverse_ArrayGraph(G);//a,b,c,d,e
    bfsTraverse_ArrayGraph(G);//a,b,d,e,c
    printf("pause");
}