#include <stdio.h>
#define MAXSIZE 100

struct Stack
{
    char data[MAXSIZE];
    int top;
};
void initStack(Stack &S)
{
    S.top=0;
}
void push(Stack &S,char c)
{
    S.data[S.top]=c;
    S.top++;
}
char pop(Stack &S)
{
    return S.data[--S.top];
}
bool isEmpty(Stack &S)
{
    return S.top==0;
}
char getTop(Stack &S)
{
    return S.data[S.top-1];
}
