#include <iostream>

using namespace std;
bool ep[4005][4005];
int venit[4005],dp[4005];
int cur;
string s,aux;;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();++i)
    {
        for(int j=0;i-j>=0 && i+j<s.size() && s[i-j]==s[i+j];++j)ep[i-j+1][i+j+1]=1;
        for(int j=0;i-j>=0 && i+j+1<s.size() && s[i-j]==s[i+j+1];++j)ep[i-j+1][i+j+2]=1;
    }
    for(int i=1;i<=s.size();++i)
    {
        dp[i]=4500;
        for(int j=1;j<=i;++j)
        {
            if(ep[j][i] && dp[j-1]+1<dp[i])
            {
                dp[i]=dp[j-1]+1;
                venit[i]=j-1;
            }
        }
    }
    cout<<dp[s.size()]<<'\n';
    cur=s.size();
    while(cur)
    {
        for(int i=venit[cur];i<cur;++i)aux+=s[i];
        cur=venit[cur];
        if(cur)aux+=' ';
    }
    for(int i=aux.size()-1;i>=0;--i)cout<<aux[i];
    return 0;
}
