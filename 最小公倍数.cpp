//�������ĳ˻�=��С������*���Լ��

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
