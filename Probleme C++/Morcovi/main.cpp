#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define NM 1001
#define pb push_back
using namespace std;
ifstream in("morcovi.in");
ofstream out("morcovi.out");
int dp[(1<<12)+5][NM],n,en[NM],p,pas[15],viz[(1<<12)+5];
vector <int> config;
int ok(int i)
{
    return (i>0 && i<=n);
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>en[i];
    in>>p;
    for(int i=0;i<p;++i)in>>pas[i];
    ///citire
    config.pb(0);
    for(int i=0;i<(1<<p);++i)
    {
        int c=config[i];
        for(int pp=0;pp<p;++pp)
        {
            if(!viz[c|(1<<pp)])
            {
                config.pb(c|(1<<pp));
                viz[c|(1<<pp)]=1;
            }
        }
    }
    for(int i=1;i<=n;++i)dp[0][i]=en[i];
    for(auto i:config)
    {
        for(int cas=1;cas<=n;++cas)
        {
            for(int pp=0;pp<p;++pp)
            {
                if(!((1<<pp)&i))
                {
                    if(ok(cas+pas[pp]))
                        dp[i|(1<<pp)][cas+pas[pp]]=max(dp[i|(1<<pp)][cas+pas[pp]],dp[i][cas]+en[cas+pas[pp]]);
                    if(ok(cas-pas[pp]))
                        dp[i|(1<<pp)][cas-pas[pp]]=max(dp[i|(1<<pp)][cas-pas[pp]],dp[i][cas]+en[cas-pas[pp]]);
                }
            }
        }
    }
    int maxx=0;
    for(int i=1;i<=n;++i)
        maxx=max(maxx,dp[(1<<p)-1][i]);
    out<<maxx;
    return 0;
}
