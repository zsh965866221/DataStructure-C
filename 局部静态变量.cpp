#include <stdio.h>

int f()
{
    static int i=0;
    int s=1;
    s+=i;
    i++;
    return s;
}

int main()

{
    int i,a=0;
    int k;
    for(i=0;i<5;i++)
    {
        k=f();
        a=a+k;
    }
    printf("%d\n",a);
}
