#include <iostream>
#include <fstream>
using namespace std;
ifstream in("homm.in");
ofstream out("homm.out");
long long n,m,a[25][105][105],is,js,iff,jff,ii,jj,k,s;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int main()
{
    in>>n>>m>>k;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[0][i][j];
        }
    }
    in>>is>>js>>iff>>jff;
    a[0][is][js]=1;
    for(int t=1;t<=k;++t)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(!a[0][i][j] || (i==is && j==js))
                {
                    for(int d=0;d<4;++d)
                    {
                        ii=i+dx[d];
                        jj=j+dy[d];
                        if(!a[0][ii][jj] || (ii==is && jj==js))a[t][i][j]+=a[t-1][ii][jj];
                    }
                }
            }
        }
        s+=a[t][iff][jff];
    }
    out<<s+a[0][iff][jff];
    return 0;
}
