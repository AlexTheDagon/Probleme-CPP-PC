#include <iostream>
#include <vector>
#include <set>
#define NM 300005
#define pb push_back
using namespace std;
vector<int> v[NM];
set<int> s;
int n,m,g[NM],viz[NM],vv[NM];
char P[NM];
int a,b,fr[30],maxx=1,sem=1,ram;
void dfs(int nod)
{
    viz[nod]=1;
    ++fr[P[nod]];
    if(fr[P[nod]]>maxx)maxx=fr[P[nod]];
    s.insert(nod);
    for(auto i:v[nod])
    {
        if(s.find(i)!=s.end())
        {
            sem=0;
            return;
        }
        if(sem==0)return;
        dfs(i);
    }
    s.erase(nod);
    --fr[P[nod]];
}
int main()
{
    cin>>n>>m;
    ram=n;
    for(int i=1;i<=n;++i)cin>>P[i];
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        if(a==b)
        {
            cout<<"-1";
            return 0;
        }
        ++g[b];
        v[a].pb(b);
        if(g[b]==1)--ram;
    }
    if(ram==0)sem=0;
    for(int i=1;i<=n && sem;++i)
        if(g[i]==0 && v[i].size()!=0)dfs(i);
    for(int i=1;i<=n && sem;++i)
        if(!viz[i] && v[i].size()!=0)dfs(i);
    if(sem==0)cout<<"-1";
    else cout<<maxx;
    return 0;
}
