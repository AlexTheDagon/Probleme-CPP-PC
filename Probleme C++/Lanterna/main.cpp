#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define z second
#define pb push_back
#define mp make_pair
#define NM 55
using namespace std;
ifstream in("lanterna.in");
ofstream out("lanterna.out");
int n,k,tmin[NM],wmin[NM],m,a,b,t,w,s[NM],viz[NM][NM];
vector<pair<pair<int,int>,int> > v[NM];
pair<pair<int,int>,pair<int,int> > fr;
priority_queue<pair<pair<int,int>,pair<int,int> >,vector<pair<pair<int,int>,pair<int,int> > >,greater <pair<pair<int,int>,pair<int,int> > > > q;
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
    {
        in>>s[i];
    }
    tmin[1]=0;
    in>>m;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b>>t>>w;
        v[a].pb(mp(mp(b,t),w));
        v[b].pb(mp(mp(a,t),w));
    }
    q.push(mp(mp(0,0),mp(0,1)));
    while(q.top().ss!=n || q.top().fs>k)
    {
        fr=q.top();
        q.pop();
        for(auto i:v[fr.ss])
        {
            if(viz[fr.ss][i.ff]<n)
            {
                ++viz[fr.ss][i.ff];
                if(s[i.ff])
                {
                    q.push(mp(mp(fr.ff+i.fs,max(fr.fs,fr.sf+i.z)),mp(0,i.ff)));
                }
                else
                {
                    q.push(mp(mp(fr.ff+i.fs,max(fr.fs,fr.sf+i.z)),mp(fr.sf+i.z,i.ff)));
                }
            }
        }
    }
    out<<q.top().ff<<" "<<q.top().fs;
    return 0;
}
