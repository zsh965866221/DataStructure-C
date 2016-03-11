//最大公共子串=>连续
//A:bacadbe
//B:cabcade
//形成一个二位矩阵LC:if(B[i]==A[j]) LC[i][j]=LC[i-1][j-1]+1
//  b a c a d b e
//c 0 0 1 0 0 0 0
//a 0 1 0 2 0 0 0
//b 1 0 0 0 0 1 0
//c 0 0 1 0 0 0 0
//a 0 1 0 2 0 0 0
//d 0 0 0 0 3 0 0
//e 0 0 0 0 0 0 1
#include <stdio.h>
#include <string.h>

int main()
{
    char A[100],B[100];
    int LC[100];
    scanf("%s",A);
    scanf("%s",B);
    int la=strlen(A);
    int lb=strlen(B);
    int lp=0,lmax=0;
    for(int i=0;i<100;i++)
        LC[i]=0;
    for(int i=0;i<la;i++)
    {
        for(int j=lb-1;j>=0;j--)
        {
            if(B[i]!=A[j])
                LC[j]=0;
            else{
                if(j==0)
                    LC[j]=1;
                else{
                    LC[j]=LC[j-1]+1;
                }
                if(LC[j]>lmax)
                {
                    lp=j;
                    lmax=LC[j];
                }
            }
        }
    }
    char result[100];
    for(int i=0;i<lmax;i++)
    {
        result[i]=A[lp-lmax+1+i];
    }
    printf("%d,%d\n",lp,lmax);
    printf("%s",result);
}
