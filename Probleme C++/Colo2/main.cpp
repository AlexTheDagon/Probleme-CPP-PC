#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
#define NM 16005
using namespace std;
ifstream in("color2.in");
ofstream out("color2.out");
int n,x,y,cnt;
vector<int> v[NM];
int ok1[NM],ok2[NM];
void dfs(int nod)
{
    ok1[nod]=1;
    for(int i=0;i<v[nod].size();++i)
    {
        int vecin=v[nod][i];
        dfs(vecin);
        if(ok1[vecin]==1)
            ok1[nod]=0;
    }
}
void dfs2(int nod)
{
    for(int i=0;i<v[nod].size();++i)
    {
        int v1=v[nod][i];
        int v2=v[nod][1-i];
        if(ok2[nod]==0 || ok1[v2]==1)
            ok2[v1]=1;
        dfs2(v1);
    }
}
int main()
{
    in>>n;
    for(int i=1;i<n;++i)
    {
        in>>x>>y;
        v[x].pb(y);
    }
    dfs(1);
    ok2[1]=1;
    dfs2(1);
    for(int i=1;i<=n;++i)
        if(ok1[i]&&ok2[i])++cnt;
    out<<cnt<<'\n';
    for(int i=1;i<=n;++i)
        if(ok1[i]==1 && ok2[i]==1)out<<i<<' ';
    return 0;
}
