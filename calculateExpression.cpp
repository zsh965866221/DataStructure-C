#include <stdio.h>
#include <string.h>

#include "Stack.h"

bool isDigit(char c)
{
    if('9'-c>=0&&c-'0'>=0)
        return true;
    else
        return false;
}

int charToDigit(char c)
{
    return c-'0';
}

int operatorLevel(char c)
{
    switch(c)
    {
        case '+':   return 1;
        case '-':   return 1;
        case '*':   return 2;
        case '/':   return 2;
        default:    return 0;
    }
}
float cal(char c,float a,float b)
{
    switch(c)
    {
        case '+':   return a+b;
        case '-':   return a-b;
        case '*':   return a*b;
        case '/':   return a/b;
        default:    return 0;
    }
}

int main()
{
    char ss[100];
    float S2[100];
    int i2=0;
    Stack S1;
    initStack(S1);
    scanf("%s",ss);
    int size=strlen(ss);
    for(int i=0;i<size;i++)
    {
        if(isDigit(ss[i]))
        {
            S2[i2]=charToDigit(ss[i]);
            i2++;
        }
        else{
            if(isEmpty(S1))
                push(S1,ss[i]);
            else{
                if(ss[i]=='(')
                {
                    push(S1,ss[i]);
                }
                else if(ss[i]==')')
                {
                    char c=pop(S1);
                    while(c!='(')
                    {
                        float b=S2[--i2];
                        float a=S2[--i2];
                        S2[i2++]=cal(c,a,b);
                        c=pop(S1);
                    }
                }
                else{
                    char c=getTop(S1);
                    while(operatorLevel(ss[i])<=operatorLevel(c)&&c!='(')
                    {
                        pop(S1);
                        float b=S2[--i2];
                        float a=S2[--i2];
                        S2[i2++]=cal(c,a,b);
                        c=getTop(S1);
                    }
                    push(S1,ss[i]);
                }
            }
        }
    }

    while(!isEmpty(S1))
    {
        char c=pop(S1);
        float b=S2[--i2];
        float a=S2[--i2];
        S2[i2++]=cal(c,a,b);
    }
    printf("%.1f",S2[0]);
}
