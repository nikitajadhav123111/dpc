#include<iostream>
using namespace std;
int* sort(int arr[],int size)
{
  int i,j,count=0,temp;
  for(i=0;i<size;i++)
  {
    for(j=0;j<size-i-1;j++)
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
int duplicate_element(int arr[],int size)  
{
  int i,j,count;
  arr=sort(arr,size);
  for(i=0;i<size-1;i++)
  {
    count=0;
    if(arr[i]==arr[i+1])
    {
      count++;
    }
    if(count>0)
    {
      i++;
      return arr[i];
    }
  }
  return 0;
}
int main()
{
  int i,j;
  cout<<"Enter size";
  cin>>i;
  int a[i];
  for(j=0;j<i;j++)
  {
    cin>>a[j];
  }
  cout<<duplicate_element(a,i);
  return 0;
}
