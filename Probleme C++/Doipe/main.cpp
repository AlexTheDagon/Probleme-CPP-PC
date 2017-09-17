#include <iostream>
#include <fstream>
#define NM 2005
#define m 29997
using namespace std;
ifstream in("doipe.in");
ofstream out("doipe.out");
int n,t,dp[3][NM];
string s,ss;
int main()
{
    in>>t;
    while(t)
    {
        --t;
        in>>n>>ss;
        s="0";
        s+=ss;
        dp[1][1]=1;
        for(int i=2;i<=n;++i)
        {
            if(s[i-1]=='<')
            {
                for(int j=1;j<=i;++j)
                {
                    dp[2][j]=dp[1][j-1];
                }
            }
            if(s[i-1]=='>')
            {
                for(int j=1;j<i;++j)
                {
                    dp[2][j]=(dp[1][i-1]-dp[1][j-1]+m)%m;
                }
            }
            for(int j=1;j<=i;++j)
            {
                dp[2][j]+=dp[2][j-1];
                dp[2][j]%=m;
            }
            for(int j=1;j<=i;++j)
            {
                dp[1][j]=dp[2][j];
                dp[2][j]=0;
            }
        }
        out<<dp[1][n]<<'\n';
    }

    return 0;
}
