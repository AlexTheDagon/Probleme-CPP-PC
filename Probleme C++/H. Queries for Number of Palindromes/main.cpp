#include <iostream>
#define NM 5005
using namespace std;
int dp[NM][NM];
bool ispal[NM][NM];
string s;
int n,m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;++i)
    {
        ispal[i][i]=1;
        ispal[i+1][i]=1;
        dp[i][i]=1;
    }
    for(int l=2;l<=n;++l)
    {
        for(int i=0;i<=n-l;++i)
        {
            ispal[i][i+l-1]=(ispal[i+1][i+l-2]&(s[i]==s[i+l-1]));
            dp[i][i+l-1]=dp[i][i+l-2]+dp[i+1][i+l-1]-dp[i+1][i+l-2]+ispal[i][i+l-1];
        }
    }
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int st,dr;
        cin>>st>>dr;
        --st;
        --dr;
        cout<<dp[st][dr]<<'\n';
    }
    return 0;
}
