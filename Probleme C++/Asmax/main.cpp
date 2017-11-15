#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define NM 16005
#define pb push_back
using namespace std;
ifstream in("asmax.in");
ofstream out("asmax.out");
vector<int> vec[NM];
int n,viz[NM],a,b,sol=-10000,dp[NM];
int dfsdp(int nod)
{
    if(!viz[nod])
    {
        viz[nod]=1;
        for(auto i:vec[nod])
        {
            if(!viz[i])
            {
                dp[nod]=max(dp[nod],dp[nod]+dfsdp(i));
            }
        }
    }
  sol=max(sol,dp[nod]);
  return dp[nod];
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>dp[i];
    for(int i=1;i<n;++i)
    {
        in>>a>>b;
        vec[a].pb(b);
        vec[b].pb(a);
    }
    dfsdp(1);
    out<<sol;
    return 0;
}
