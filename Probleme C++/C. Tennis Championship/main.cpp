#include <iostream>

using namespace std;
long long p,n,dp[100005],i;
int main()
{
    p=2;
    cin>>n;
    dp[0]=1;
    dp[1]=2;
    dp[2]=3;
    for(i=3;dp[i-1]+dp[i-2]<=n;++i)dp[i]=dp[i-1]+dp[i-2];
    if(n==1)cout<<"0";
    else
    {
        if(n==2)cout<<"1";
        else cout<<i-1;
    }
    return 0;
}
///dp[i]---nr minim de participanti care tb sa participe pentru ca un jucator sa joaca i runde
