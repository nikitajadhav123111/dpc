void HCF(int N)
{
    int H,c=0;
    for(H=1;H<=N;H++)
    {
        if(N%H==0)
        {
            c++;
        }
    }
    cout<<c;
}
