#include<iostream>
using namespace std;
int missing_number(int arr[],int size)
{
  int i,j;
  for(i=0,j=1;i<=size;i++)
  {
    if(j==arr[i])
    {
      j++;
    }
    else
      return j;
  }
}
int main()
{
  int i,p;
  cout<<"Enter size of an array";
  cin>>p;
  int a[p];
  for(i=0;i<p;i++)
  {
    cin>>a[i];
  }
  cout<<missing_number(a,p);
  return 0;
}
