#include <iostream>
#include <fstream>
#define NM 5005
#define m 666013
using namespace std;
ifstream in("100m.in");
ofstream out("100m.out");
int dp[3][NM],n,s=1;
int main()
{
    in>>n;
    dp[1][1]=1;
    for(int i=2;i<=n;++i)
    {
        dp[2][i]=s;
        s=0;
        for(int j=i-1;j>0;--j)
            dp[2][j]=(dp[2][j+1]+dp[1][j])%m;
        for(int j=i;j>0;--j)
        {
            s+=dp[2][j];
            s%=m;
            dp[1][j]=dp[2][j];
            dp[2][j]=0;
        }
    }
    out<<s;
    return 0;
}
