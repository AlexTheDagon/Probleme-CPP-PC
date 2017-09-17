#include <iostream>
#define NM 1005
using namespace std;
string s1,s2,ss;
int dp[NM][NM][3],n,dif,pdif,ii,jj,sol[2*NM],kk,pas;
int main()
{
    cin>>n>>s1>>s2;
    ss='s'+s1;
    s1=ss;
    ss='s'+s2;
    s2=ss;
    dif=1;
    for(int i=1;i<=n && dif>-1 && dif<3;++i)
    {
        if(s1[i]=='1')++dif;
        else --dif;
        if(dif>-1 && dif<3)
            dp[i][0][dif]=1;
    }
    dif=1;
    for(int i=1;i<=n && dif>-1 && dif<3;++i)
    {
        if(s2[i]=='1')++dif;
        else --dif;
        if(dif>-1 && dif<3)
            dp[0][i][dif]=2;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            ///am luat carte din pachetul 1
            if(s1[i]=='1')dif=1;
            else dif=-1;
            for(int k=0;k<=2;++k)
            {
                if(k-dif>-1 && k-dif<3 && dp[i-1][j][k-dif])dp[i][j][k]=1;
            }
            ///am lut cartea din pachetul 2
            if(s2[j]=='1')dif=1;
            else dif=-1;
            for(int k=0;k<=2;++k)
            {
                if(k-dif>-1 && k-dif<3 && dp[i][j-1][k-dif])dp[i][j][k]=2;
            }
        }
    }
    if(!dp[n][n][1])cout<<"Impossible";
    else
    {
        pas=n+n;
        ii=n;
        jj=n;
        kk=1;
        while(pas>0)
        {
            sol[pas]=dp[ii][jj][kk];
            if(sol[pas]==1)
            {
                if(s1[ii]=='1')--kk;
                else ++kk;
                --ii;
            }
            else
            {
                if(s2[jj]=='1')--kk;
                else ++kk;
                --jj;
            }
            --pas;
        }
        for(int i=1;i<=2*n;++i)cout<<sol[i];
    }
    return 0;
}
