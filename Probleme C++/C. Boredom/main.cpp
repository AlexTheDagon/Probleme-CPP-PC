#include <iostream>
#define NM 100005
using namespace std;
long long n,a[NM],dp[NM],fr[NM];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        ++fr[a[i]];
    }
    dp[1]=fr[1];
    for(int i=2;i<=NM-2;++i)
        dp[i]=max(dp[i-1],dp[i-2]+fr[i]*i);
    cout<<dp[NM-2];
    return 0;
}
