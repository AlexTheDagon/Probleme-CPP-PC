#include <iostream>
#define NM 10000005
using namespace std;
long long dp[2*NM],x,y,n;
int main()
{
    cin>>n>>x>>y;
    for(int i=1;i<=n;++i)dp[i]=i*x;
    for(int i=1;i<n;++i)
    {
        dp[2*i]=min(dp[2*i],dp[i]+y);
        dp[2*i+1]=min(dp[2*i+1],dp[i]+y+x);
        dp[2*i-1]=min(dp[2*i-1],dp[i]+y+x);
    }
    cout<<dp[n];
    return 0;
}
