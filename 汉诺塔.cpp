#include <stdio.h>

void _move(char from,char to)
{
    printf("%c->%c\n",from,to);
}
void hanoi(int n,char one,char two,char three)
{
    if(n==1)
        _move(one,three);
    else{
        hanoi(n-1,one,three,two);
        _move(one,three);
        hanoi(n-1,two,one,three);
    }
}
int main()
{
    hanoi(3,'A','B','C');
}
