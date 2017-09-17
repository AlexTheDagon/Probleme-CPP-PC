#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define pb push_back
#define mp make_pair
#define NMAX 50005
#define MMAX 250005
#define inf (1<<30)
#define x first
#define y second
using namespace std;
ifstream in("dijkstra.in");
ofstream out("dijkstra.out");
int a,b,c;
int n,m;
int dmin[NMAX],fol[NMAX],inq[NMAX],dist,sem;
int minn;
vector <pair<int,int> > v[NMAX];
pair<int,int> fr;
struct cmp
{
   bool operator()(pair<int,int> i,pair<int,int> j){return i.x>j.x;};
};
///bool cmp(pair<int,int> i,pair<int,int> j){return i.x>j.x;};
priority_queue<int,vector<pair<int,int> >,cmp> q;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)dmin[i]=inf;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b>>c;
        v[a].pb(mp(b,c));
    }
    ///citire
    int nod;
    q.push(mp(0,1));
    dmin[1]=0;
    sem=1;
    for(int i=1;i<=n&& sem;++i)
    {
        while(!q.empty() && fol[q.top().y])q.pop();
        if(!q.empty())
        {
            fr=q.top();
            q.pop();
            nod=fr.y;
            fol[nod]=1;
            dist=fr.x;
            for(auto j:v[nod])
            {
                dmin[j.x]=min(dmin[j.x],dist+j.y);
                if(fol[j.x]<n)q.push(mp(dmin[j.x],j.x));
                else sem=0;
            }
        }
    }
    for(int i=2;i<=n;++i)
    {
        if(dmin[i]==inf)out<<"0 ";
        else out<<dmin[i]<<" ";
    }
    return 0;
}
