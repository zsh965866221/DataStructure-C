#include <stdio.h>

void _swap(int &a,int &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)     _swap(a,b);
    if(a>c)     _swap(a,c);
    if(b>c)     _swap(b,c);
    printf("%d,%d,%d",a,b,c);
}
