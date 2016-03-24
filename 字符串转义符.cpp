#include <stdio.h>
int main()
{
    int i;
    char *S="a\045+045\'b";
    for(i=0;*S;i++)
    {
        printf("%d:%c\n",i,*S);
        *S++;
    }
    printf("\ntotal:%d\n",i);
}
