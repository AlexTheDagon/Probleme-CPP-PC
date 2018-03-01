#include <iostream>
#include <bits/stdc++.h>
#define m 1000000007
#define pb push_back
using namespace std;
long long x,y;
long long lgpow(long long b,long long e)
{
    long long p=b,sol=1;
    while(e)
    {
        if(e&1)sol=(sol*p)%m;
        p=p*p;
        p%=m;
        e>>=1;
    }
    return sol;
}
long long gen(long long s)
{
    long long cs=s;
    vector<long long> dd;
    for(long long d=2;d*d<=cs;++d)
    {
        if(cs%d==0)
        {
            dd.pb(d);
            while(cs%d==0)cs/=d;
        }
    }
    if(cs!=1)dd.pb(cs);
    long long sol=0,add;
    for(int conf=0;conf<(1<<dd.size());++conf)
    {
        long long ex=1,sgn=1;
        for(int i=0;i<dd.size();++i)
        {
            if((conf>>i)&1)
            {
                sgn*=(-1LL);
                ex*=dd[i];
            }
        }
        add=lgpow(2,s/ex-1);
        sol+=sgn*add;
        sol=(sol+m)%m;
    }
    return sol;
}
int a[15];
int main()
{
    cin>>x>>y;
    if(y%x)
    {
        cout<<0;
        return 0;
    }
    y/=x;
    ///de aici facem lgput
    cout<<gen(y);
    return 0;
}
