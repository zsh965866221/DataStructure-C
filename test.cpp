#include <iostream>
using namespace std;
int main()
{
    int a[5]={0,1,2,3,4};
    int i=0;
    cout<<i;
    cout<<":"<<a[i++]<<":"<<i<<endl;
    i=0;
    cout<<i;
    cout<<":"<<a[++i]<<":"<<i<<endl;
}
