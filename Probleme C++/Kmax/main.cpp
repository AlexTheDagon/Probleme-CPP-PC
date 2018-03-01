#include <iostream>
#include <fstream>
#define NM 305
using namespace std;
ifstream in("kmax.in");
ofstream out("kmax.out");
int comb[NM][NM],dp[NM][NM];
int n,k,r;
int main()
{
    in>>n>>k>>r;
    comb[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        comb[i][0]=1;
        for(int j=1;j<=n;++j)
            comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%r;
    }
    for(int i=1;i<=k;++i)dp[1][i]=1;
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=k;++j)
        {
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%r;
            for(int q=1;q<i;++q)
            {
                int aux=(dp[q][k-1]*dp[i-q-1][j])%r;
                aux=(aux*comb[i-1][q]);
                dp[i][j]=(aux+dp[i][j])%r;
            }
        }
    }
    out<<dp[n][k]<<'\n';
    return 0;
}
