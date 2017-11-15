#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define ff first.first
#define fs first.second
#define x first
#define y second
#define mp make_pair
#define NM 55
#define pb push_back
using namespace std;
ifstream in("lanterna.in");
ofstream out("lanterna.out");
queue<pair<int,int> > q;
vector<pair<pair<int,int>,int> > v[NM];
pair<int,int> fr;
int inq[NM][1005],m,s[NM],a,b,t,w,k,dmin[NM][1005],act,mid,aux,n,hi,low,sem,minim=1000000000,minn,tmin;
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)in>>s[i];
    in>>m;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b>>t>>w;
        v[b].pb(mp(mp(a,t),w));
        v[a].pb(mp(mp(b,t),w));
    }
    ///citirea e bine
    minim=1000000000;
    for(int i=0;i<=n;++i)
            for(int j=0;j<=k;++j)
            {
                inq[i][j]=0;
                dmin[i][j]=1000000000;
            }
    for(int ii=1;ii<=k;++ii)
    {
        mid=ii;
        q.push(mp(1,mid));
 
        inq[1][mid]=1;
        dmin[1][mid]=0;
        while(!q.empty())
        {
            fr=q.front();
            if(fr.x==n)
            {
                if(dmin[fr.x][fr.y]<minim)
                {
                    minim=dmin[fr.x][fr.y];
                    tmin=mid;
                }
            }
            q.pop();
            inq[fr.x][fr.y]=0;
            for(auto i:v[fr.x])
            {
                if(s[i.ff])
                {
                    if(fr.y-i.y>=0 && dmin[i.ff][mid]>dmin[fr.x][fr.y]+i.fs)
                    {
                        if(!inq[i.ff][mid])
                        {
                            q.push(mp(i.ff,mid));
                            inq[i.ff][mid]=1;
                        }
                        dmin[i.ff][mid]=dmin[fr.x][fr.y]+i.fs;
                    }
                }
                else
                {
 
                    if(fr.y-i.y>=0 && dmin[i.ff][fr.y-i.y]>dmin[fr.x][fr.y]+i.fs)
                    {
                        if(!inq[i.ff][fr.y-i.y])
                        {
                            q.push(mp(i.ff,fr.y-i.y));
                            inq[i.ff][fr.y-i.y]=1;
                        }
                        dmin[i.ff][fr.y-i.y]=dmin[fr.x][fr.y]+i.fs;
                    }
                }
            }
        }
    }
    out<<minim<<" "<<tmin;
    return 0;
}
///fr.x-nodul curent
///fr.y-nr de wati ramasi in lanterna