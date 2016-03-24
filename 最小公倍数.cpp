//两个数的乘积=最小公倍数*最大公约数

#include <stdio.h>
int gcd(int a,int b)
{
    int temp;
    while(b!=0)
    {
        temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
int main()
{
    printf("%d\n",lcm(10,8));
}
