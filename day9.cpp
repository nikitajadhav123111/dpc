#include <iostream>
#include<string.h>
using namespace std;
void commanprefix(char b[3][20],int size)
{
    int i,j,k=0;
    char c[10];
    for(i=0;i<size;i++)
    {
     
        for(j=0,k=0;j<strlen(b[i])&&j<strlen(b[i+1]);j++,k++)
        {
           if(b[i][j]==b[i+1][j])
           {
               c[k]=b[i][j];
           }
        }
    }
    for(i=0;i<=k;i++)
        cout<<c[i];
}
int main()
{
    char a[3][20]={"flower","flow","flight"};
    commanprefix(a,3);
    return 0;
}
