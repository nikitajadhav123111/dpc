#include<iostream>
using namespace std;
int leaders(int arr[],int size)
{
    int i,k=0,b[k],l;
    for(i=0;i<size-2;i++)
    {
        b[k]=arr[i]+arr[i+1];
        l=b[k]+arr[i+2];
        if(l==0)
        {
            cout<<i<<i+2<<endl;
            k++;
        }

    }
}
int main()
{
    int arr[6]={1,2,-3,3,1,2};
    leaders(arr,6);
    return 0;
}
