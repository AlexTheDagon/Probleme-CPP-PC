#include <iostream>
#define NM 505
#define inf -1000000000
using namespace std;
int a[NM][NM],people[NM][NM],dp[NM][NM],n,k,parinte[NM][NM],maxx=inf,ind;
void reconstruct(int kk,int act)
{
    if(kk==0)return;
    reconstruct(kk-1,parinte[kk][act]);
    cout<<act-1<<" ";
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<n;++i)
        for(int j=1;j<=n-i;++j)
            cin>>a[i][i+j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            dp[i][j]=people[i][j]=inf;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            people[i][j]=a[j-1][n]-a[i-1][n]-a[j-1][j-1]+a[i-1][j-1];///calcul people[i][j]--cate persoane urca in i,i+1,...,j-1 si se dau jos in statiile j,j+1,...,n
    for(int i=1;i<=k;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int jj=1;jj<j;++jj)
            {
                if(dp[i][j]<dp[i-1][jj]+people[jj][j])
                {
                    dp[i][j]=dp[i-1][jj]+people[jj][j];
                    if(dp[i][j]>=maxx)
                    {
                        maxx=dp[i][j];
                        ind=j;
                    }
                    parinte[i][j]=jj;
                }
            }
        }
    }
    cout<<maxx<<'\n';
    if(maxx!=inf)reconstruct(k,ind);
    else for(int i=1;i<=k;++i)cout<<i<<" ";
    return 0;
}
