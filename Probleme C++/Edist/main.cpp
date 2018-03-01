#include <iostream>
#include <bits/stdc++.h>
#define NM 2005
using namespace std;
ifstream in("edist.in");
ofstream out("edist.out");
int dp[NM][NM],n,m,k;
string s1,s2;
int main()
{
    in>>n>>m>>k;
    in>>s1>>s2;
    for(int i=1;i<=2000;++i)
    {
        dp[0][i]=i;
        dp[i][0]=i;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s1[i-1]!=s2[j-1]));
        }
    }
    out<<dp[n][m];
    return 0;
}
