#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#define x first
#define y second
using namespace std;
ifstream in("rj.in");
ofstream out("rj.out");
string v;
int dx[]={0,-1,0,1,-1,1,1,-1,},dy[]={-1,0,1,0,1,1,-1,-1};
int n,m,x,y,a[101][101],b[101][101],fi,fj,p,is,js,timp,minn=100000,fini,finj;
int ii,jj,sem=1;
queue <pair <int,int>  > c;
int main()
{
    in>>n>>m;
    getline(in,v);
    for(int i=0;i<n;++i)
    {
        getline(in,v);
        for(int j=0;j<m;++j)
        {
            if(v[j]=='R')is=i+1,js=j+1;
            if(v[j]=='J')fi=i+1,fj=j+1;
            if(v[j]=='X')
            {
                a[i+1][j+1]=-1;
                b[i+1][j+1]=-1;
            }
        }
    }
    a[is][js]=1;
    c.push(make_pair(is,js));
    while(!c.empty())
    {
        pair <int,int> fr=c.front();
        c.pop();
        for(int d=0;d<8;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ii>0 && ii<=n && jj>0 && jj<=m && a[ii][jj]==0)
            {
                a[ii][jj]=a[fr.x][fr.y]+1;
                c.push(make_pair(ii,jj));
            }
        }
    }
    b[fi][fj]=1;
    c.push(make_pair(fi,fj));
    while(!c.empty())
    {
        pair <int,int> fr=c.front();
        c.pop();
        for(int d=0;d<8;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ii>0 && ii<=n && jj>0 && jj<=m && b[ii][jj]==0)
            {
                b[ii][jj]=b[fr.x][fr.y]+1;
                c.push(make_pair(ii,jj));
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]==b[i][j] && minn>a[i][j] && a[i][j]>0)
            {
                minn=a[i][j];
                fini=i;
                finj=j;
            }
        }
    }
    out<<minn<<" "<<fini<<" "<<finj;
    return 0;
}
