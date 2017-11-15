#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <functional>
#define pii pair<long long,long long>
#define y second
#define x first
#define pb push_back
#define NM 36005
#define mp make_pair
using namespace std;
ifstream in("catun.in");
ofstream out("catun.out");
priority_queue<pii,vector<pii>,greater<pii> > q;
long long n,a,b,c,dmin[NM],tip[NM],k,fol[NM],m;
vector<pii> v[NM];
pii fr;
int main()
{
    in>>n>>m>>k;
    for(int i=1;i<=n;++i)
    {
        dmin[i]=1000000000;
    }
    for(int i=1;i<=k;++i)
    {
        in>>a;
        tip[a]=a;
        dmin[a]=0;
        q.push(make_pair(0,a));
    }
    for(int i=1;i<=m;++i)
    {
        in>>a>>b>>c;
        v[a].pb(mp(b,c));
        v[b].pb(mp(a,c));
    }
    while(!q.empty())
    {
        while(!q.empty() && fol[q.top().y])q.pop();
        if(!q.empty())
        {
            fr=q.top();
            fol[fr.y]=1;
            for(auto i:v[fr.y])
            {
                if(dmin[i.x]>dmin[fr.y]+i.y)
                {
                    tip[i.x]=tip[fr.y];
                    dmin[i.x]=dmin[fr.y]+i.y;
                    q.push(mp(dmin[i.x],i.x));
                }
                else
                {
                    if(dmin[i.x]==dmin[fr.y]+i.y)tip[i.x]=min(tip[i.x],tip[fr.y]);
                }
            }
        }
    }
    for(int i=1;i<=n;++i)if(tip[i]==i || tip[i]==10000000)tip[i]=0;
    for(int i=1;i<=n;++i)out<<tip[i]<<" ";

    return 0;
}
