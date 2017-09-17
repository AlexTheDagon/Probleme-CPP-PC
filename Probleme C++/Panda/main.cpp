#include <iostream>
#include <fstream>
#include <queue>
#define x first
#define y second
using namespace std;
ifstream in("panda.in");
ofstream out("panda.out");
int a[505][505],n,m,p,s,t,is,js,z,cat,accesibile,k,tarcuri,tmin;
queue <pair<int,int> > q;
int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int ii,jj;
pair<int,int> pr,b[250005];
int ok(int i,int j)
{
    return (i>0 && i<=n && j>0 && j<=m);
}///bine
int main()
{
    in>>p;
    in>>n>>m>>t;
    in>>is>>js>>k>>s;
    cat=1<<s;
    for(int i=1;i<=t;++i)in>>b[i].x>>b[i].y;
    ///citire pana la coordonate tarcuri cu mancare
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>z;
            if(((z%cat)^(k%cat))==(cat-1))
            {
                if(i!=is || j!=js)++accesibile;
            }
            else a[i][j]=-1;
        }
    }
    a[is][js]=0;
    if(p==1)out<<accesibile;///ok
    else
    {
        q.push(make_pair(is,js));
        while(!q.empty())
        {
            pr=q.front();
            q.pop();
            for(int d=0;d<4;++d)
            {
                ii=pr.x+dx[d];
                jj=pr.y+dy[d];
                if(ok(ii,jj) && a[ii][jj]==0)
                {
                    a[ii][jj]=a[pr.x][pr.y]+1;
                    q.push(make_pair(ii,jj));
                }
            }
        }
        a[is][js]=0;
        tmin=1000000;
        for(int i=1;i<=t;++i)
        {
            if(a[b[i].x][b[i].y]<tmin && (a[b[i].x][b[i].y]>0 || (b[i].x==is && b[i].y==js)))
            {
                tmin=a[b[i].x][b[i].y];
                tarcuri=1;
            }
            else
            {
                if(a[b[i].x][b[i].y]==tmin)++tarcuri;
            }
        }
        out<<tmin<<" "<<tarcuri;
    }
    return 0;
}
