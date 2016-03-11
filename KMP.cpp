#include <stdio.h>
#include <string.h>

void getNext(char S[],int next[])
{
    int n=strlen(S);
    next[0]=-1;
    next[1]=0;
    for(int i=2;i<n;i++)
    {
        int j=next[i-1];
        while(j>=0)
        {
            if(S[i-1]!=S[j])
                j=next[j];
            else
                break;
        }

        next[i]=j+1;
    }
}
int KMP(char SS[],char S[],int next[],int pos=0)
{
    int i=pos,j=0;
    int lenth=strlen(SS);
    while(i<strlen(SS))
    {
        if(j==-1||SS[i]==S[j])
        {
            i++;
            j++;
        }else{
            j=next[j];
        }
        if(j==strlen(S))//只找第一个匹配点
            break;
    }
    return i-strlen(S);
}
int main()
{
    char *S="abaabcac";
    int next[strlen(S)];
    char SS[100];
    scanf("%s",SS);
    getNext(S,next);
    int k=KMP(SS,S,next);
    printf("%d\n",k);
}
//abcabaabcacabcabaaabaabcacabaaabaabcac
