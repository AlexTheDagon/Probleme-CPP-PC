#include <iostream>
#include <bits/stdc++.h>
#define NM 1000050
#define pb push_back
#define m 9973
using namespace std;
ifstream in("ssnd.in");
ofstream out("ssnd.out");
int ciur[NM];
vector<long long> prim,divv;
long long t,n,s,nrdiv,sdiv,auxnr,auxs;
int main()
{
    in>>t;
    for(int i=2;i<=1000010;++i)ciur[i]=1;
    for(long long i=2;i<=1000010;++i)
        if(ciur[i])
        {
            prim.pb(i);
            for(long long j=i*i;j<=1000010;j+=i)
                ciur[j]=0;
        }
    while(t)
    {
        --t;
        in>>n;
        sdiv=1;
        nrdiv=1;
        for(int i=0;n>1 && prim[i]*prim[i]<=n;++i)
        {
            auxnr=0;
            auxs=prim[i];
            while(n%prim[i]==0)
            {
                n/=prim[i];
                auxs*=prim[i];
                ++auxnr;
            }
            if(auxnr)
            {
                sdiv=(sdiv*(((auxs-1)/(prim[i]-1))%m)%m);
                nrdiv=(nrdiv*(auxnr+1))%m;
            }
        }
        if(n>1)
        {
            nrdiv*=2;
            sdiv*=(n+1);
        }
        out<<nrdiv%m<<" "<<sdiv%m<<'\n';
    }
    return 0;
}
