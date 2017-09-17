#include <iostream>
#include <fstream>
#include <queue>
#define x first
#define y second
#define NM 1005
#define mm make_pair
using namespace std;
ifstream in("mz.in");
ofstream out("mz.out");
queue <pair<int,int> > q,r;
pair<int,int> fr;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int n,m,viz[NM][NM],sursa,a[NM][NM],ii,jj,vecini,vec0,z,nrcirc,s,arie[NM][NM],capete[NM][NM],zmax1,zmax2,c1,c2,d;
char c;
int ok(int i,int j)
{
    return (i<=n && i>0 && j>0 && j<=m);
}
int capat(int i,int j)
{
    vecini=0;
    vec0=0;
    for(z=0;z<4;++z)
    {
        if(a[i+dx[z]][j+dy[z]]==a[i][j])++vecini;
        if(a[i+dx[z]][j+dy[z]]==0)++vec0;
    }
    if(vecini<2 && vec0)return 1;
    return 0;
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        a[i][0]=-1;
        a[i][m+1]=-1;
    }
    for(int i=0;i<=m+1;++i)
    {
        a[0][i]=-1;
        a[n+1][i]=-1;
    }///intializari
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>c;
            a[i][j]=c-'0';
        }
    }///citire
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(viz[i][j]==0 && a[i][j])
            {
                ++nrcirc;
                s=0;
                q.push(mm(i,j));
                while(!q.empty())
                {
                    ++s;
                    r.push(q.front());
                    fr=q.front();
                    q.pop();
                    viz[fr.x][fr.y]=nrcirc;
                    if(capat(fr.x,fr.y))
                    {
                        capete[fr.x][fr.y]=nrcirc;
                    }
                    for(d=0;d<4;++d)
                    {
                        ii=fr.x+dx[d];
                        jj=fr.y+dy[d];
                        if(ok(ii,jj) && viz[ii][jj]==0 && a[ii][jj]==a[fr.x][fr.y])
                        {
                            q.push(mm(ii,jj));
                        }
                    }
                }
                if(s>zmax2)zmax2=s;
                if(s>=zmax1)
                {
                    zmax2=zmax1;
                    zmax1=s;
                }
                while(!r.empty())
                {
                    fr=r.front();
                    r.pop();
                    arie[fr.x][fr.y]=s;
                }
            }
        }
    }
    out<<nrcirc<<'\n';///pana aici e bine
    out<<zmax1+zmax2<<'\n';
    return 0;
}
