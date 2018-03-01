#include <iostream>
#include <bits/stdc++.h>
#define NM 2005
#define M 100003
using namespace std;
ifstream in("fractii2.in");
ofstream out("fractii2.out");
int n,dp[NM][NM],p,sol,st,dr;
int main()
{
    in>>p>>n;
    if(p==1)
    {
        for(int i=1;i<=n;++i)
            out<<min(i,n-1)<<" ";
        return 0;
    }
    dp[2][1]=1;
    for(int lng=3;lng<=n;++lng)
    {
        for(int i=1;2*i<=lng;++i)
        {
            st=(i+1)/2-1;
            dr=(lng-i)/2;
            dp[lng][i]=(dp[lng][i-1]+dp[lng-i][dr]-dp[lng-i][st]+M)%M;
        }
    }
    out<<dp[n][n/2];
    return 0;
}
