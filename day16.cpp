#include<iostream>
using namespace std;
int LCM(int a,int b)
{
    int L,i;
    for(L=a>b?a:b;L<=a*b;L++)
    {
        if(L%a==0&&L%b==0)
        {
            return L;
        }
    }
};
