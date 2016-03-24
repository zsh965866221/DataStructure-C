#include <stdio.h>
union U
{
    int intA;
    char charB;
    char charArrayC[10];
};
struct S
{
    int intA;
    char charB;
    char charArrayC[10];
};

int _add(int a,int b)
{
    return a+b;
}
int main()
{
    U u;
    u.intA=1000;
    u.charB='B';
    S s;
    printf("size of U:%d\n",sizeof(U));
    printf("size of S:%d\n",sizeof(S));
    printf("size of int:%d\n",sizeof(int));
    printf("size of char:%d\n",sizeof(char));
    printf("size of char*:%d\n",sizeof(char*));printf("size of int*:%d\n",sizeof(int *));

    printf("size of char[10]:%d\n",sizeof(char[10]));
    typedef int (*pp)(int,int);
    pp ppp;
    ppp=_add;
    printf("%d\n",ppp(1,2));
}
