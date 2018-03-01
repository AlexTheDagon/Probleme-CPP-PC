#include <iostream>
#include <bits/stdc++.h>
#define NM 1000005
using namespace std;
int n,a,b,fra,frb,poz=1;
int gen(int st,int lng)
{
    for(int i=1;i<lng;++i)cout<<st+i<<" ";
    cout<<st<<" ";
}
int main()
{
    cin>>n>>a>>b;
    while(n>0)
    {
        if(!(n%b))
        {
            frb=n/b;
            n=0;
        }
        else
        {
            n-=a;
            ++fra;
        }
    }
    if(n<0)
    {
        cout<<"-1";
        return 0;
    }
    for(int i=1;i<=fra;++i)
    {
        gen(poz,a);
        poz+=a;
    }
    for(int i=1;i<=frb;++i)
    {
        gen(poz,b);
        poz+=b;
    }
    return 0;
}
