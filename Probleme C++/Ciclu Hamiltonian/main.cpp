#include <iostream>
#include <bits/stdc++.h>
#define NM 18
#define inf 1000000000
#define pb push_back
using namespace std;
ifstream in("hamilton.in");
ofstream out("hamilton.out");
int dp[(1<<NM)+5][NM],cst[NM][NM],a,b,c,n,m,minn=inf;
vector<int> v[NM],pos;
int main()
{
    in>>n>>m;
    if(n==0)
    {
        out<<"0";
        return 0;
    }
    for(int i=1;i<=m;++i)
    {
        in>>a>>b>>c;
        cst[a][b]=c;
        if(b==0)pos.pb(a);
        v[a].pb(b);
    }
    for(int mask=0;mask<(1<<n);++mask)
        for(int j=0;j<n;++j)dp[mask][j]=inf;
    dp[1][0]=0;
    for(int mask=1;mask<(1<<n);++mask)
        for(int nod=0;nod<n;++nod)
            for(auto vecin:v[nod])
                if(dp[mask][nod]!=inf && !(mask&(1<<vecin)))
                    dp[mask+(1<<vecin)][vecin]=min(dp[mask+(1<<vecin)][vecin],dp[mask][nod]+cst[nod][vecin]);
    for(auto i:pos)minn=min(minn,dp[(1<<n)-1][i]+cst[i][0]);
    if(minn==inf)out<<"Nu exista solutie";
    else out<<minn;
    return 0;
}
