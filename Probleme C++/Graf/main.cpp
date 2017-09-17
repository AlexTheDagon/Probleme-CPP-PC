#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#define pb push_back
#define NM 7505
#define inf 1000000000;
using namespace std;
ifstream in("graf.in");
ofstream out("graf.out");
queue <int> q;
vector <int> sol,v[NM],dist[NM];
int dmin[NM],viz[NM],n,m,x,y,a,b,nod,inq[NM];
int main()
{
    in>>n>>m>>x>>y;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b;
        v[b].pb(a);
        v[a].pb(b);
    }
    for(int i=1;i<=n;++i)dmin[i]=inf;
    dmin[x]=1;
    q.push(x);
    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        for(auto i:v[nod])
        {
            if(viz[i]==0 && dmin[i]>dmin[nod]+1)
            {
                q.push(i);
                viz[i]=1;
                dmin[i]=dmin[nod]+1;
            }
        }
    }
    q.push(y);
    sol.pb(y);
    while(!q.empty())
    {
        nod=q.front();
        q.pop();
        for(auto i:v[nod])
        {
            if(dmin[i]==dmin[nod]-1 && !inq[i])
            {
                inq[i]=1;
                q.push(i);
                dist[dmin[i]].pb(i);
            }
        }
    }
    for(int i=1;i<=dmin[y];++i)
    {
        if(dist[i].size()==1)sol.pb(dist[i][0]);
    }
    out<<sol.size()<<'\n';
    sort(sol.begin(),sol.end());
    for(auto i:sol)out<<i<<" ";
    return 0;
}
