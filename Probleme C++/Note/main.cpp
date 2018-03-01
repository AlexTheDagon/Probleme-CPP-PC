#include <bits/stdc++.h>
#define NM 1050
using namespace std;
ifstream in("note.in");
ofstream out("note.out");
int n,v,dp[NM][NM],s[NM],m,x,ap[NM][105];
int main()
{
    in>>v>>n;
    for(int i=1;i<=v;++i)
    {
        for(int j=1;j<=n;++j)
        {
            in>>x;
            ap[j][x]=1;
        }
    }
    in>>m;
    for(int i=1;i<=m;++i)in>>s[i];
    for(int i=1;i<=1025;++i)
    {
        dp[0][i]=i;
        dp[i][0]=i;
    }///bine
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            dp[i][j]=min(min(dp[i-1][j],dp[i][j-1])+1,dp[i-1][j-1]+!ap[i][s[j]]);
    out<<dp[n][m];
    return 0;
}
