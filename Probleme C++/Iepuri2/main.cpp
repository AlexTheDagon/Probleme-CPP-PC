#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
#define NM 105
#define m 30011
using namespace std;
ifstream in("iepuri2.in");
ofstream out("iepuri2.out");
vector<int> v[NM];
int dp[NM][NM],n,k,a,b,u[NM],st,urm[NM];
int dfs2(int nod)
{
    if(v[nod].size()==0)return 1;
    for(auto i:v[nod])
    {
        urm[nod]=max(urm[nod],dfs2(i));
    }
    return urm[nod]+1;
}
void dfs(int nod)
{
    for(auto i:v[nod])
    {
        dfs(i);
        for(int j=k-urm[nod];j>0;--j)
        {
            dp[nod][j]=(dp[nod][j]*dp[i][j+1])%m;
        }
    }
    for(int j=k-urm[nod]-1;j>0;--j)
        dp[nod][j]=(dp[nod][j]+dp[nod][j+1])%m;
}
int main()
{
    in>>n>>k;
    for(int i=1;i<n;++i)
    {
        in>>a>>b;
        v[a].pb(b);
        u[b]=1;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=k;++j)dp[i][j]=1;
    for(int i=1;i<=n;++i)
        if(u[i]==0)st=i;
    dfs2(st);
    dfs(st);
    cout<<urm[st]<<endl;
    if(urm[st]<k)out<<dp[st][1];
    else out<<"0";
    return 0;
}
