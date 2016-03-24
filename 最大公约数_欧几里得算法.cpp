//gcd(a,b)=gcd(b,a%b)

#include <stdio.h>
int gcd(int a,int b)
{
    int temp;
    while(b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int gcd_1(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd_1(b,a%b);
}
int main()
{
    printf("%d\n",gcd(54,21));
}
