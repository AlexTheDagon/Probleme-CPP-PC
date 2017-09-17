#include <iostream>
#include <fstream>
#include <vector>
#define NM 105
#define pb push_back
#define inf 10000000;
using namespace std;
ifstream in("pm2.in");
ofstream out("pm2.out");
vector <int> v[NM],inv[NM];
int n,dp[NM],viz[NM],t[NM],a,m,tmax,stmin[NM],stmax[NM],minn,vizz[NM],solnod,init;
int dfs(int nod)
{
    if(viz[nod]==1)return dp[nod];
    viz[nod]=1;
    int maxx=0;
    for(auto i:v[nod])
        maxx=max(maxx,dfs(i));
    dp[nod]=maxx+t[nod];
    return dp[nod];
}
int dfsinv(int nod)
{
    if(vizz[nod]==1)return stmax[nod];
    vizz[nod]=1;
    int minn=tmax;
    for(auto i:inv[nod])
        minn=min(minn,dfsinv(i));
    stmax[nod]=minn-t[nod];
    return stmax[nod];
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>t[i];
    for(int i=1;i<=n;++i)
    {
        dp[i]=inf;
        in>>m;
        for(int j=1;j<=m;++j)
        {
            in>>a;
            inv[a].pb(i);
            v[i].pb(a);
        }
    }
    for(int i=1;i<=n;++i)
        if(!viz[i])
        {
            if(dfs(i)>tmax)
            {
                tmax=dfs(i);
                solnod=i;
            }
        }
    out<<tmax<<'\n';
    init=tmax-t[solnod];
    for(int i=1;i<=n;++i)
    {
        stmin[i]=dp[i]-t[i];///bine
        if(!vizz[i])dfsinv(i);
    }
    for(int i=1;i<=n;++i)
    {
        out<<stmin[i]<<" "<<stmax[i]<<'\n';
    }
    return 0;
}
