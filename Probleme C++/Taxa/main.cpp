#include <iostream>
#include <fstream>
#define mp make_pair
#define NM 1005
#define x first
#define y second
#include <deque>
#define inf 1000000000
#define pb push_back
#define pf push_front
using namespace std;
ifstream in("taxa.in");
ofstream out("taxa.out");
int is,js,ifin,jfin,n,m;
int ii,jj;
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
deque <pair<int,int> > q;
pair<int,int> fr;
int a[NM][NM],viz[NM][NM];
int cost[NM][NM];
int nr;
int ok(int i,int j)
{
    return (i<=n && i>0 && j<=m && j>0);
}
int main()
{
    in>>n>>m>>is>>js>>ifin>>jfin;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
            cost[i][j]=inf;
        }
    }
    cost[is][js]=0;
    q.pf(mp(is,js));
    while(!q.empty())
    {
        fr=q.front();
        q.pop_front();
        for(int d=0;d<8;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ok(ii,jj))
            {
                if(a[fr.x][fr.y]==a[ii][jj])
                {
                    if(cost[ii][jj]>cost[fr.x][fr.y])
                    {
                        q.pf(mp(ii,jj));
                        cost[ii][jj]=cost[fr.x][fr.y];
                    }
                }
                else
                {
                    nr=a[fr.x][fr.y]*a[ii][jj];
                    if(cost[ii][jj]>cost[fr.x][fr.y]+nr)
                    {
                        q.pb(mp(ii,jj));
                        cost[ii][jj]=cost[fr.x][fr.y]+nr;
                    }
                }
            }
        }
    }
    out<<cost[ifin][jfin];

    return 0;
}
