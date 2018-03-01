#include <iostream>
#include <bits/stdc++.h>
#define NM 2005
#define inf 2000000000
using namespace std;
ifstream in("summax.in");
ofstream out("summax.out");
int st,dr,n,p,dp[NM][NM],c[NM];
void gen(int i,int j,int ind)
{
    out<<j<<" ";
    if(i==n)return;
    if(dp[i+1][j+1]<=dp[i+1][j] && ind<=dp[n-i][n-j+2])gen(i+1,j,ind);
    else
    {
        if(dp[i+1][j]==dp[i+1][j+1])gen(i+1,j+1,ind-dp[n-i][n-j+2]);
        else gen(i+1,j+1,ind);
    }
}
int main()
{
    in>>p>>n>>st>>dr;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            in>>dp[i][j];
    for(int i=1;i<=n;++i)
        dp[1][n-i+2]=1;
    for(int i=n-1;i>0;--i)
    {
        for(int j=1;j<=i;++j)
            c[j]=dp[i][j];
        for(int j=1;j<=i;++j)
        {
            dp[i][j]=dp[i+1][j]+c[j];///suma maxima
            dp[n-i+1][n-j+2]=dp[n-i][n-j+2];///numarul de drumuri
            if(dp[i+1][j+1]+c[j]==dp[i][j])///obtin aceasi valoare maxima pentru drum din (i+1,j+1)
            if(dp[i][j]==dp[i+1][j+1]+c[j])///se aduna drumurile pt suma egala
            {
                long long aux=1LL*dp[n-i+1][n-j+2]+1LL*dp[n-i][n-j+1];
                if(aux>inf)aux=inf+1;
                dp[n-i+1][n-j+2]=aux;
            }
            if(dp[i][j]<dp[i+1][j+1]+c[j])///suma mai mare de pe celalalt drum
            {
                dp[i][j]=dp[i+1][j+1]+c[j];
                dp[n-i+1][n-j+2]=dp[n-i][n-j+1];
            }
        }
    }
    if(p==1)out<<dp[n][n+1];
    else
    {
        for(int i=st;i<=dr;++i)
        {
            gen(1,1,i);
            out<<'\n';
        }
    }
    return 0;
}
