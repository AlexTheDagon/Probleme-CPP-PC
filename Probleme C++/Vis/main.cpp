#include <iostream>
#include <fstream>
#define x first
#define y second
#define mp make_pair
#include <queue>
#define NM 1005
using namespace std;
ifstream in("vis.in");
ofstream out("vis.out");
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
queue <pair<int,int> > q;
pair <int,int> fr,spec1,spec2;
int n,a[NM][NM],s1[NM][NM],s2[NM][NM],s1s2[NM][NM],s2s1[NM][NM],k1,k2,ii,jj,d1=1<<30,d2=1<<30,d12=1<<30,d21=1<<30,dd=1<<30;
bool va[NM][NM],vs1[NM][NM],vs2[NM][NM],vs1s2[NM][NM],vs2s1[NM][NM];
int ok(int i,int j)
{
    return (i>0 && i<=n && j>0 && j<=n);
}
int main()
{
    in>>n>>k1>>k2>>spec1.x>>spec1.y>>spec2.x>>spec2.y;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)in>>a[i][j];
    ///parcurgerea de la special 1 la special 2 si la final
    q.push(spec1);
    vs1[spec1.x][spec1.y]=1;
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        for(int d=0;d<4;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ok(ii,jj) && a[ii][jj]<=k1 && vs1[ii][jj]==0)
            {
                vs1[ii][jj]=1;
                s1[ii][jj]=s1[fr.x][fr.y]+1;
                q.push(mp(ii,jj));
            }
        }
    }
    ///parcurgerea de la special 2 la special 1 si la final
    q.push(spec2);
    vs2[spec2.x][spec2.y]=1;
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        for(int d=0;d<4;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ok(ii,jj) && (a[ii][jj]>=k2 || a[ii][jj]==0) && vs2[ii][jj]==0)
            {
                vs2[ii][jj]=1;
                s2[ii][jj]=s2[fr.x][fr.y]+1;
                q.push(mp(ii,jj));
            }
        }
    }
    ///parcurgerea de la special 2 la special 1 si apoi la final
    q.push(spec1);
    vs2s1[spec1.x][spec1.y]=1;
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        for(int d=0;d<4;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ok(ii,jj) && (a[ii][jj]<=k1 || a[ii][jj]>=k2) && vs2s1[ii][jj]==0)
            {
                vs2s1[ii][jj]=1;
                s2s1[ii][jj]=s2s1[fr.x][fr.y]+1;
                q.push(mp(ii,jj));
            }
        }
    }
    ///parcurgerea de la special 1 la special 2 si apoi la final
    q.push(spec2);
    vs1s2[spec2.x][spec2.y]=1;
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        for(int d=0;d<4;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ok(ii,jj) && (a[ii][jj]<=k1 || a[ii][jj]>=k2) && vs1s2[ii][jj]==0)
            {
                vs1s2[ii][jj]=1;
                s1s2[ii][jj]=s1s2[fr.x][fr.y]+1;
                q.push(mp(ii,jj));
            }
        }
    }
    ///parcurgere de la inceput la sfarsit
    q.push(mp(1,1));
    va[1][1]=1;
    a[1][1]=1;
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        for(int d=0;d<4;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ok(ii,jj) && a[ii][jj]==0 && va[ii][jj]==0)
            {
                va[ii][jj]=1;
                a[ii][jj]=a[fr.x][fr.y]+1;
                q.push(mp(ii,jj));
            }
        }
    }
    ///calcul distante
    if(va[spec1.x][spec1.y] && vs1[n][n])d1=a[spec1.x][spec1.y]+s1[n][n];///1--->spec1--->final
    if(va[spec2.x][spec2.y] && vs2[n][n])d2=a[spec2.x][spec2.y]+s2[n][n];///1--->spec2--->final
    if(va[spec1.x][spec1.y] && vs1[spec2.x][spec2.y] && vs1s2[n][n])d12=a[spec1.x][spec1.y]+s1[spec2.x][spec2.y]+s1s2[n][n];
    if(va[spec2.x][spec2.y] && vs2[spec1.x][spec1.y] && vs2s1[n][n])d21=a[spec2.x][spec2.y]+s2[spec1.x][spec1.y]+s2s1[n][n];
    if(va[n][n])dd=a[n][n];
    out<<min(dd,min(d1,min(d2,min(d12,d21))));
    return 0;
}
