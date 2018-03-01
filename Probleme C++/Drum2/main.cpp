#include <iostream>
#include <fstream>
#define NM 31
using namespace std;
ifstream in("drum2.in");
ofstream out("drum2.out");
int dp[NM][NM][NM],p[NM][NM][NM],n,maxx,ind[NM][NM][NM],act,x,y,z;
int dx[]={1,1,1};
int dy[]={0,1,1};
int dz[]={1,0,1};
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            for(int k=1;k<=i;++k)
            {
                in>>dp[i][j][k];
                ind[i][j][k]=++act;
            }
    for(int i=n-1;i>0;--i)
    {
        for(int j=i;j>0;--j)
        {
            for(int k=i;k>0;--k)
            {
                maxx=0;
                for(int d=0;d<3;++d)
                {
                    int ii=i+dx[d];
                    int jj=j+dy[d];
                    int kk=k+dz[d];
                    if(dp[ii][jj][kk]>maxx)
                    {
                        p[i][j][k]=d;
                        maxx=dp[ii][jj][kk];
                    }
                }
                dp[i][j][k]+=maxx;
            }
        }
    }
    x=y=z=1;
    out<<dp[1][1][1]<<'\n';
    while(x<=n)
    {
        out<<ind[x][y][z]<<" ";
        int d=p[x][y][z];
        x+=dx[d];
        y+=dy[d];
        z+=dz[d];
    }
    return 0;
}
