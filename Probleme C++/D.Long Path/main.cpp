#include <iostream>
#define NM 1005
#define m 1000000007
using namespace std;
long long dp[NM],n,p[NM],sum;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>p[i];
    for(int i=1;i<=n;++i)
    {
        dp[i]=1;
        for(int j=p[i];j<i;++j)
        {
            dp[i]+=(dp[j]+1);
            dp[i]%=m;
        }
        sum=(sum+dp[i])%m;
    }
    cout<<(sum+n)%m;
    return 0;
}
///dp[i]---nr de miscari ca sa incep din i si sa termin in i
