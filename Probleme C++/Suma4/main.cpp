#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
#define NM 60
using namespace std;
ifstream in("suma4.in");
ofstream out("suma4.out");
int s,niv,indcam;
int cost[NM][NM][NM],dp[NM][NM][NM],par[NM*NM*NM];
int cam[NM][NM][NM],minn=(1<<30),camm;
vector<int> sol;
int detniv(int ss)
{
    int s=ss,nivv=0;;
    while(s)
    {
        ++nivv;
        s-=nivv*nivv;
    }
    return nivv;
}


int ok(int n,int i,int j)
{
    return (i>0 && i<=n && j>0 && j<=n && cost[n][i][j]!=0);
}

int dy[]={0,0,-1,-1};
int dx[]={0,-1,0,-1};

int main()
{
    in>>s;
    niv=detniv(s);
    ///determinare nr nivele
    for(int n=1;n<=niv;++n)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dp[n][i][j]=(1<<30);
                in>>cost[n][i][j];
                cam[n][i][j]=(++indcam);
            }
        }
    }
    out<<niv<<' ';
    dp[1][1][1]=cost[1][1][1];
    for(int n=2;n<=niv;++n)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                for(int d=0;d<4;++d)
                {
                    if(ok(n-1,i+dx[d],j+dy[d]) && cost[n][i][j]+dp[n-1][i+dx[d]][j+dy[d]]==dp[n][i][j])
                    {
                        par[cam[n][i][j]]=min(par[cam[n][i][j]],cam[n-1][i+dx[d]][j+dy[d]]);
                        if(n==niv && dp[n][i][j]<minn)
                        {
                            minn=min(minn,dp[n][i][j]);
                            camm=cam[n][i][j];
                        }
                    }
                    if(ok(n-1,i+dx[d],j+dy[d]) && cost[n][i][j]+dp[n-1][i+dx[d]][j+dy[d]]<dp[n][i][j])
                    {
                        dp[n][i][j]=(cost[n][i][j]+dp[n-1][i+dx[d]][j+dy[d]]);
                        par[cam[n][i][j]]=cam[n-1][i+dx[d]][j+dy[d]];
                        if(n==niv && dp[n][i][j]<minn)
                        {
                            minn=min(minn,dp[n][i][j]);
                            camm=cam[n][i][j];
                        }
                    }
                }
            }
        }
    }
    out<<minn<<'\n';
    while(camm!=1)
    {
        sol.pb(camm);
        camm=par[camm];
    }
    sol.pb(1);
    for(int i=niv-1;i>=0;--i)out<<sol[i]<<" ";
    return 0;
}
