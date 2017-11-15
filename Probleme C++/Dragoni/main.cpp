#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define pb push_back
#define NM 805
#define MM 6005
using namespace std;
ifstream in("dragoni.in");
ofstream out("dragoni.out");
struct eee
{
    int nod,cost,drag;
    bool operator < (const eee &a) const
    {
        return cost>a.cost;
    }
} fr ;
eee ms(int nn,int cc,int dd)
{
    eee fr;
    fr.nod=nn;
    fr.cost=cc;
    fr.drag=dd;
    return fr;
}
vector<eee> v[NM];
int a,b,c,n,m,d[NM],caz,maxx,drc,viz[NM],dist[NM][NM],minn=(1<<30);
queue<int> q;
queue<eee> qq;
int main()
{
    in>>caz;
    in>>n>>m;
    for(int i=1;i<=n;++i)in>>d[i];
    for(int i=1;i<=m;++i)
    {
        in>>a>>b>>c;
        v[a].pb(ms(b,c,0));
        v[b].pb(ms(a,c,0));
    }
    if(caz==1)
    {
        q.push(1);
        drc=maxx=d[1];
        while(!q.empty())
        {
            viz[q.front()]=1;
            int nod=q.front();
            q.pop();
            viz[nod]=1;
            maxx=max(maxx,d[nod]);
            for(auto s:v[nod])
                if(s.cost<=drc && !viz[s.nod])
                    q.push(s.nod);
        }
        out<<maxx;
    }///bine
    else
    {
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)if(!dist[i][j])dist[i][j]=(1<<30);
        dist[1][1]=0;
        qq.push(ms(1,0,1));
        while(!qq.empty())
        {
            fr=qq.front();
            qq.pop();
            for(auto i:v[fr.nod])
            {
                if(d[fr.nod]>=i.cost && dist[fr.nod][fr.drag]+i.cost<dist[i.nod][fr.nod])
                {
                    qq.push(ms(i.nod,0,fr.nod));
                    dist[i.nod][fr.nod]=dist[fr.nod][fr.drag]+i.cost;
                }///schimb
                if(d[fr.drag]>=i.cost && dist[fr.nod][fr.drag]+i.cost<dist[i.nod][fr.drag])
                {
                    qq.push(ms(i.nod,0,fr.drag));
                    dist[i.nod][fr.drag]=dist[fr.nod][fr.drag]+i.cost;
                }///las
                if(i.nod==n)minn=min(minn,min(dist[n][fr.drag],dist[n][fr.nod]));
            }
        }
        out<<minn;
    }
    return 0;
}
