#include<iostream>
using namespace std;
int* sort(int arr[],int size)
{
  int i,j,temp;
  for(i=0;i<size;i++)
  {
    for(j=0;j<size-1-i;j++)
    {
      if(arr[j]>arr[j+1])
      {
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
  return arr;
}
int main()
{
  int p,i;
  cout<<"Enter size";
  cin>>p;
  int a[p],*m;
  for(i=0;i<p;i++)
  {
    cin>>a[i];
  }
  m=sort(a,p);
  for(i=0;i<p;i++)
  {
    cout<<m[i];
  }
  return 0;
}
