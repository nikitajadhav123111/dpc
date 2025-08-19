#include<iostream>
using namespace std;
void leaders(int arr[],int size)
{
  int i,j,arr1[3],k=0;
  for(i=0;i<=size;i++)
  {
    for(j=i+1;j<=size;j++)
    {
      if(arr[i]<arr[j])
      {
        break;
      }
    }
    if(j==size)
    {
      arr1[k]=arr[i];
      cout<<arr1[k];
      k++;
    }
  }
}
int main()
{
  int arr[6]={16,17,4,3,5,2};
  leaders(arr,6);
  return 0; 
}
