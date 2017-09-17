#include <iostream>
#include <fstream>
using namespace std;
ifstream in("partii.in");
ofstream out("partii.out");
int a[1005][1005],sum[1005][1005],n,m,c,maxx;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)in>>a[i][j];
    }
    for(int i=1;i<=n;++i)
    {
        c=0;
        for(int j=2;j<=m;++j)
        {
            if(a[i][j]>a[i][j-1])++c;
            else c=0;
            sum[i][j]+=c;
        }
    }
    for(int j=1;j<=m;++j)
    {
        c=0;
        for(int i=2;i<=n;++i)
        {
            if(a[i][j]>a[i-1][j])++c;
            else c=0;
            sum[i][j]+=c;
        }
    }
    for(int i=1;i<=n;++i)
    {
        c=0;
        for(int j=m-1;j>=1;--j)
        {
            if(a[i][j]>a[i][j+1])++c;
            else c=0;
            sum[i][j]+=c;
        }
    }
    for(int j=1;j<=m;++j)
    {
        c=0;
        for(int i=n-1;i>=1;--i)
        {
            if(a[i][j]>a[i+1][j])++c;
            else c=0;
            sum[i][j]+=c;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)maxx=max(maxx,sum[i][j]);
    }
    out<<maxx+1;
    return 0;
}
