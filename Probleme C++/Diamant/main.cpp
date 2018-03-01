#include <iostream>
#include <fstream>
#include <string.h>
#define prim 10000
#define NM 50000
using namespace std;
ifstream in("diamant.in");
ofstream out("diamant.out");
int n,m,x,dp[2][2*NM+5];
int main()
{
    in>>n>>m>>x;
    if(x+10>NM || x-10<-NM)
    {
        out<<0;
        return 0;
    }
    dp[0][NM]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            for(int v=i*j;v<2*NM-i*j;++v)
            {
                dp[1][v]=dp[0][v]+dp[0][v-i*j]+dp[0][v+i*j];
                dp[1][v]%=prim;
            }
            for(int v=1;v<2*NM;++v)
            {
                dp[0][v]=dp[1][v];
                dp[1][v]=0;
            }
        }
    }
    out<<dp[0][x+NM];
    return 0;
}
