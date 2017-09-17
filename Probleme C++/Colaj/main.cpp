#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#define mp make_pair
#define f first
#define s second
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
using namespace std;
ifstream in("colaj.in");
ofstream out("colaj.out");
int x,y,n,xmax,ymax,a[310],b[310],nr,m,p,xnou[8010],ynou[8010],ufol,umod,mat[250][250],zone,d;
pair<pair<int,int>,pair<int,int> > coord[105];
int ii,jj;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
pair<int,int> fr;
queue<pair<int,int> > q;
int ok(int i,int j)
{
    return(i>0 && i<xmax && j>0 && j<ymax);
}
int main()
{
    in>>n;
    in>>m>>p;
    for(int i=1;i<=n;++i)
    {
        in>>x>>y;
        a[++nr]=x+1;
        b[nr]=y+1;
        coord[(nr+1)/2].ff=x+1;
        coord[(nr+1)/2].fs=y+1;
        in>>x>>y;
        a[++nr]=x+1;
        b[nr]=y+1;
        coord[nr/2].sf=x+1;
        coord[nr/2].ss=y+1;
    }
    sort(a+1,a+nr+1);
    sort(b+1,b+nr+1);
    ufol=1;
    umod=a[1];
    xnou[a[1]]=ufol;
    for(int i=2;i<=nr;++i)
    {
        if(a[i]==umod)xnou[a[i]]=ufol;
        else
        {
            if(a[i]==umod+1)
            {
                ++ufol;
                xnou[a[i]]=ufol;
                umod=a[i];
            }
            else
            {
                ufol=ufol+2;
                xnou[a[i]]=ufol;
                umod=a[i];
            }
        }
    }
    xmax=ufol+1;
    ufol=1;
    umod=b[1];
    ynou[b[1]]=ufol;
    for(int i=2;i<=nr;++i)
    {
        if(b[i]==umod)ynou[b[i]]=ufol;
        else
        {
            if(b[i]==umod+1)
            {
                ++ufol;
                ynou[b[i]]=ufol;
                umod=b[i];
            }
            else
            {
                ufol=ufol+2;
                ynou[b[i]]=ufol;
                umod=b[i];
            }
        }
    }
    ymax=ufol+1;
    for(int i=1;i<=n;++i)
    {
        mat[xnou[coord[i].ff]][ynou[coord[i].fs]]++;
        mat[xnou[coord[i].sf]+1][ynou[coord[i].ss]+1]++;
        mat[xnou[coord[i].sf]+1][ynou[coord[i].fs]]--;
        mat[xnou[coord[i].ff]][ynou[coord[i].ss]+1]--;
    }
    for(int i=0;i<xmax;++i)
        for(int j=0;j<ymax;++j)mat[i][j]=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
    for(int i=1;i<xmax;++i)
    {
        for(int j=1;j<ymax;++j)
        {
            if(mat[i][j]==0)
            {
                ++zone;
                q.push(mp(i,j));
                mat[i][j]=1;
                while(!q.empty())
                {
                    fr=q.front();
                    q.pop();
                    for(d=0;d<=3;++d)
                    {
                        ii=fr.f+dx[d];
                        jj=fr.s+dy[d];
                        if(ok(ii,jj) && mat[ii][jj]==0)
                        {
                            mat[ii][jj]=1;
                            q.push(mp(ii,jj));
                        }
                    }
                }
            }
        }
    }
    out<<zone;
    return 0;
}
