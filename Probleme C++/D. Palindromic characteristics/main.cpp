#include <iostream>

using namespace std;
string s;
int dp[5005][5005],r,m,sol[5005];
int main()
{
    cin>>s;
    for(int len=1;len<=s.size();++len)
    {
        for(int l=0;l<s.size()-len+1;++l)
        {
            r=l+len;
            if(len==1)
            {
                dp[l][r]=1;
                continue;
            }
            else
            {
                if(len==2)
                {
                    if(s[l]==s[r-1])dp[l][r]=2;
                    else dp[l][r]=0;
                    continue;
                }
            }
            if(s[l]!=s[r-1] || !dp[l+1][r-1])continue;
            dp[l][r]=1;
            m=(l+r)/2;
            if(len%2)
            {
                if(dp[l][m] && dp[m+1][r])
                {
                    dp[l][r]=dp[l][m]+1;
                }
            }
            else
            {
                if(dp[l][m] && dp[m][r])
                {
                    dp[l][r]=dp[l][m]+1;
                }
            }
        }
    }
    for(int i=0;i<=s.size();++i)
        for(int j=0;j<=s.size();++j)++sol[dp[i][j]];
    for(int i=s.size();i>=0;--i)sol[i]+=sol[i+1];
    for(int i=1;i<=s.size();++i)cout<<sol[i]<<" ";
    return 0;
}
