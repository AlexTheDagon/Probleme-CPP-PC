#include <iostream>
#define m 1000000007
using namespace std;
long long dp[100005],n,k,a,b;
int main()
{
    cin>>n>>k;
    for(int i=0;i<k;++i)dp[i]=1;
    for(int i=k;i<=100000;++i)dp[i]=(dp[i-1]+dp[i-k])%m;
    for(int i=1;i<=100000;++i)dp[i]=(dp[i]+dp[i-1])%m;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>b;
        cout<<(dp[b]-dp[a-1]+m)%m<<'\n';
    }
    return 0;
}
