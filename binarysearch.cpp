#include <stdio.h>
int binarysearch(int array[],int n,int v)
{
    int low=0,high=n;
    int mid=(low+high)/2;
    while(low<high)
    {
        if(array[mid]==v)
            return mid;
        else if(v>array[mid]){
            low=mid+1;
        }else{
            high=mid;
        }
        mid=(low+high)/2;
    }
    return -1;
}
int main()
{
    int A[]={1,2,3,4,5};
    int v=0;
    while(v!=-1)
    {
        scanf("%d",&v);
        printf("%d\n",binarysearch(A,5,v));
    }
}
