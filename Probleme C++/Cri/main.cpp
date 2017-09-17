#include <iostream>
#include <fstream>
#include <algorithm>
#define p first
#define u second
using namespace std;
ifstream in("cri.in");
ofstream out("cri.out");
long long n,m,x,y,a[505][505],maxx,cam,z,minn[10];
pair<long long,long long> p[10];
int main()
{
    in>>n>>m>>x>>y;
    for(int i=1;i<=5;++i)minn[i]=(1<<29);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
            if(i<=x && j<=y && (i!=x || j!=y) && i!=1 && j!=1)minn[1]=min(minn[1],a[i][j]);
            if(i<=x && j>=y && (i!=x || j!=y) && i!=1 && j!=m)minn[2]=min(minn[2],a[i][j]);
            if(i>=x && j<=y && (i!=x || j!=y) && i!=n && j!=1)minn[3]=min(minn[3],a[i][j]);
            if(i>=x && j>=y && (i!=x || j!=y) && i!=n && j!=m)minn[4]=min(minn[4],a[i][j]);
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    p[1].p=a[x][y];
    p[2].p=a[x][m]-a[x][y-1];
    p[3].p=a[n][y]-a[x-1][y];
    p[4].p=a[n][m]-a[x-1][m]-a[n][y-1]+a[x-1][y-1];

    p[4].u=(n-x+1)*(m-y+1);
    if((n-x+1)%2==0 && (m-y+1)%2==0)
    {
        p[4].u--;
        p[4].p-=minn[4];
    }
    p[2].u=x*(m-y+1);
    if(x%2==0 && (m-y+1)%2==0)
    {
        --p[2].u;
        p[2].p-=minn[2];
    }
    p[3].u=y*(n-x+1);
    if(y%2==0 && (n-x+1)%2==0)
    {
        --p[3].u;
        p[3].p-=minn[3];
    }
    p[1].u=x*y;
    if(x%2==0 && y%2==0)
    {
        --p[1].u;
        p[1].p-=minn[1];
    }
    for(int i=1;i<=4;++i)
    {
        if(p[i].p>maxx)
        {
            maxx=p[i].p;
            cam=p[i].u;
            z=i;
        }
        if(p[i].p==maxx && p[i].u<cam)
        {
            cam=p[i].u;
            z=i;
        }
    }

    out<<z<<" "<<maxx<<" "<<cam;
    return 0;
}
