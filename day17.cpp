void Prime_factor(int n)
{
    int i,j,c=0,p[10];
    for(i=2;n!=1;i++)
    {
        for(j=i;n%j==0;)
        {
           p[c]=j;
           n=n/j;
           c++;
        }
    }
    cout<<"[";
    for(i=0;i<c;i++)
    {
       cout<<p[i];
       if(i<c-1)
            cout<<",";
    }
    cout<<"]";
};
