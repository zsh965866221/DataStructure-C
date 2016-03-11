//最大公共子序列=>不连续
//A:bacadbe
//B:cabcade
//形成一个二位矩阵LC
//    b a c a d b e
//  0 0 0 0 0 0 0 0
//c 0 0 0 1 1 1 1 1
//a 0 0 1 1 2 2 2 2
//b 0 1 1 1 2 2 3 3
//c 0 1 1 2 2 2 3 3
//a 0 1 2 2 3 3 3 3
//d 0 1 2 2 3 4 4 4
//e 0 1 2 2 3 4 4 5
#include <stdio.h>
#include <string.h>

int _max(int a,int b)
{
    return a>b? a:b;
}

int main()
{
    char A[100],B[100];
    int LC[100+1][100+1];
    scanf("%s",A);
    scanf("%s",B);
    int la=strlen(A);
    int lb=strlen(B);
    for(int i=0;i<100+1;i++)
    {
        LC[0][i]=0;
        LC[i][0]=0;
    }
    for(int i=0;i<la;i++)
    {
        for(int j=0;j<lb;j++)
        {
            if(B[i]!=A[j])
                LC[i+1][j+1]=_max(LC[i+1][j],LC[i][j+1]);
            else
                LC[i+1][j+1]=LC[i][j]+1;
        }
    }
    char result[100];
    int p=LC[lb][la];
    int pla=la,plb=lb;
    printf("%d\n",p);
    while(p>0)
    {
        if(LC[plb-1][pla]==p)
        {
            plb=plb-1;
            p=LC[plb][pla];
        }else if(LC[plb][pla-1]==p){
            pla=pla-1;
            p=LC[plb][pla];
        }else if(LC[plb-1][pla-1]==p){
            pla=pla-1;
            plb=plb-1;
            p=LC[plb][pla];
        }else{
            result[p-1]=A[pla-1];
            pla=pla-1;
            plb=plb-1;
            p=LC[plb][pla];
        }
    }
    printf("%s",result);
}

