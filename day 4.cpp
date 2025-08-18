#include<iostream>
#include<stdio.h>
using namespace std;
void merge(int a[],int size1,int b[],int size2)
{
  int i,j,m[10],k;
  for(i=0,j=0,k=0;i<size1&&j<size2;k++)
  {
    if(a[i]<b[j])
    {
      m[k]=a[i];
      i++;
    }
    else
    {
      m[k]=b[j];
      j++;
    }
  }
  while(i<size1)
  {
    m[k]=a[i];
    i++;
    k++;
  }
  while(j<size2)
  {
    m[k]=b[j];
    j++;
    k++;
  }
  for(i=0;i<size1+size2;i++)
  {
    cout<<m[i];
  }
}
int main()
{
  int arr1[4]={1,3,5,7},arr2[4]={2,4,6,8};
  merge(arr1,4,arr2,4);
  return 0;
}
