#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#include <stdlib.h>
using namespace std;
ifstream in("ai.in");
ofstream out("ai.out");
const long double inf=1e9;
int a[1005][1005],b[1005][1005];
queue<pair<int,int> > q;///b1-blocaj1
vector<pair<int,int> > b1,b2;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
pair<int,int> fr;
int ii,jj,xs1,ys1,xs2,ys2,xt,yt,xr1,yr1,xr2,yr2,k,l,c,lng,lngmax,n,d,cost,minn1,minn2;
long double tg1,tg2;
long double tg(int j,int i)
{
    if(i==0)return 0;
    return (1.0*j)/(1.0*i);
}
int ok(int i,int j)
{
    return (i>0 && i<=n && j>0 && j<=n);
}
int colinare(int a1,int a2,int a3,int a4,int a5,int a6)
{
    if((a5<=a3 && a5>=a1 && a6>=a2 && a6<=a4) || (a5>=a3 && a5<=a1 && a6<=a2 && a6>=a4) || (a5>=a1 && a5<=a3 && a6<=a2 && a6>=a4)  || (a5>=a3 && a5<=a1 && a6<=a4 && a6>=a2))
    {
        if(tg(abs(a5-a3),abs(a6-a4))==tg(abs(a3-a1),abs(a2-a4)))return 1;
    }
    return 0;
}
int main()
{
    in>>n;
    in>>xt>>yt>>xs1>>ys1>>xs2>>ys2>>xr1>>yr1>>xr2>>yr2;
    in>>k;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)a[i][j]=inf;
    for(int i=1;i<=k;++i)
    {
        in>>l>>c;
        a[l][c]=-1;
    }
    for(int i=1;i<=n;++i)
    {
        lng=0;
        for(int j=1;j<=n;++j)
        {
            if(a[i][j]==-1)++lng;
            else lng=0;
            lngmax=max(lng,lngmax);
        }
    }
    for(int i=1;i<=n;++i)
    {
        lng=0;
        for(int j=1;j<=n;++j)
        {
            if(a[j][i]==-1)++lng;
            else lng=0;
            lngmax=max(lng,lngmax);
        }
    }
    out<<lngmax<<'\n';
    ///bine
    a[xt][yt]=-1;
    /*
    tg1=tg(abs(xt-xs1),abs(yt-ys1));
    for(int i=min(xt,xs1);i<=max(xt,xs1);++i)
        for(int j=min(yt,ys1);j<=max(yt,ys1);++j)
            if(a[i][j]!=-1)if(tg(abs(xt-i),abs(xt-j))==tg1)b1.pb(mp(i,j));
    ///bine
    tg2=tg(abs(xt-xs2),abs(yt-ys2));
    for(int i=min(xt,xs2);i<=max(xt,xs2);++i)
        for(int j=min(yt,ys2);j<=max(yt,ys2);++j)
            if(a[i][j]!=-1)if(tg(abs(xt-i),abs(xt-j))==tg2)b2.pb(mp(i,j));
                */
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i][j]!=-1)
            {
                if(colinare(xs1,ys1,xt,yt,i,j))b1.pb(mp(i,j));
                else if(colinare(xs2,ys2,xt,yt,i,j))b2.pb(mp(i,j));
            }
        }
    }
    ///bine
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)b[i][j]=a[i][j];

    ///ok
    q.push(mp(xr1,yr1));
    a[xr1][yr1]=0;
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        for(d=0;d<=3;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ok(ii,jj) && a[ii][jj]!=-1 && a[ii][jj]>a[fr.x][fr.y]+1)
            {
                a[ii][jj]=a[fr.x][fr.y]+1;
                q.push(mp(ii,jj));
            }
        }
    }
    ///ar tb sa fie bine
    q.push(mp(xr2,yr2));
    b[xr2][yr2]=0;
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        for(d=0;d<=3;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ok(ii,jj) && b[ii][jj]!=-1 && b[ii][jj]>b[fr.x][fr.y]+1)
            {
                b[ii][jj]=b[fr.x][fr.y]+1;
                q.push(mp(ii,jj));
            }
        }
    }
    ///ar tb sa fie bine
    minn1=inf;
    minn2=inf;
    for(int i=0;i<b1.size();++i)
        if(a[b1[i].x][b1[i].y]!=-1)minn1=min(minn1,a[b1[i].x][b1[i].y]);
    for(int i=0;i<b2.size();++i)
        if(b[b2[i].x][b2[i].y]!=-1)minn2=min(minn2,b[b2[i].x][b2[i].y]);
    cost=max(minn1,minn2);
    ///verif 2
    minn1=inf;
    minn2=inf;
    for(int i=0;i<b1.size();++i)
        if(b[b1[i].x][b1[i].y]!=-1)minn1=min(minn1,b[b1[i].x][b1[i].y]);
    for(int i=0;i<b2.size();++i)
        if(a[b2[i].x][b2[i].y]!=-1)minn2=min(minn2,a[b2[i].x][b2[i].y]);
    cost=min(cost,max(minn1,minn2));
    out<<cost;
    return 0;
}
